/*---------------------------------------------------------------------------*
  Project:  Revolution THP Audio Library
  File:     wave.c

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    7     03/09/15 6:12p Akagi
    Changed error output function from printf to THPPrintError.
    
    6     03/07/07 10:49a Akagi
    Moved from build/tools/THPUtilities/src.
    
    5     03/07/01 2:34p Akagi
    Modified to divide old THPConv.exe into 2 LIBs and 1 EXE by
    Ohki-san@NTSC.
    
    4     03/07/01 2:26p Akagi
    Moved from build/tools/THPConv/src.
    
    3     03/07/01 9:54a Akagi
    Moved from securebuild/tools.
    
    2     02/10/16 11:28a Akagi
    JPEG & WAV file Name bug fixed. (by iRD  tsuji)
    
    1     02/01/16 4:59p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#include <stdio.h>

#include <revolution/types.h>
#include <win32/thpcore.h>
#include <win32/thpaudio.h>

#include "audiofile.h"
#include "wave.h"

s32 __THPWaveReadHeader(THPAudioFileInfo *fileInfo)
{
    u32  getFlag = 0, offset, dataSize;
    RiffHeader  riff;
    ChunkHeader chunk;
    WaveFormat  format;
    
    if(fread(&riff, sizeof(RiffHeader), 1, fileInfo->fileHandle) != 1)
    {
        THPPrintError("Fail to read the riff header of the wave\n");
        return FALSE;
    }
    
    if(riff.riffName != RIFF_CHUNK || riff.kindOfRiff != WAVE_CHUNK)
    {
        THPPrintError("This file is not wave file\n");
        return FALSE;
    }
    
    while(fread(&chunk, sizeof(ChunkHeader), 1, fileInfo->fileHandle) == 1)
    {
        switch(chunk.chunkName)
        {
            case FMT_CHUNK:
            {
                if(fread(&format, sizeof(WaveFormat), 1, fileInfo->fileHandle) != 1)
                {
                    THPPrintError("Fail to read the fmt chunk\n");
                    return FALSE;
                }
                
                if(chunk.chunkSize - sizeof(WaveFormat) > 0)
                {
                    if(fseek(fileInfo->fileHandle, (s32)(chunk.chunkSize - sizeof(WaveFormat)), SEEK_CUR) != 0)
                    {
                        THPPrintError("Fail to seek next chunk\n");
                        return FALSE;
                    }
                }
                
                getFlag |= 1;
                
                break;
            }
            case DATA_CHUNK:
            {
                offset   = ftell(fileInfo->fileHandle);
                dataSize = chunk.chunkSize;
                
                getFlag |= (1 << 1);
            }
            default:
            {
                if(fseek(fileInfo->fileHandle, chunk.chunkSize, SEEK_CUR) != 0)
                {
                    THPPrintError("Fail to seek next chunk\n");
                    return FALSE;
                }
            }
        }
    }
    
    if(getFlag == 0x3)
    {
        fileInfo->frequency       = format.frequency;
        fileInfo->channel         = format.channel;
        fileInfo->bitPerSample    = format.perBit;
        fileInfo->totalSampleSize = dataSize / format.blockSize;
        fileInfo->dataBlockOffset = offset;
        fileInfo->formatType      = format.fmtId;
        
        if(__THPAudioMoveDataBlock(fileInfo) == FALSE)
        {
            THPPrintError("ERROR : Audio FIle is Not WAVE_FILE.(in WaveReadHeader)\n");
            return FALSE;
        }
        
        return TRUE;
    }
    else
    {
        THPPrintError("ERROR : [getFlag] != 0x3\n");
        return FALSE;
    }
}

s32 __THPWaveWriteHeader(THPAudioFileInfo *fileInfo)
{
    RiffHeader  riff;
    ChunkHeader chunk;
    WaveFormat  format;
    
    format.blockSize = (u16)(fileInfo->bitPerSample * fileInfo->channel / 8);
    format.frequency = fileInfo->frequency;
    format.channel   = (u16)(fileInfo->channel);
    format.perBit    = (u16)(fileInfo->bitPerSample);
    format.aveSpeed  = fileInfo->frequency * format.blockSize;
    format.fmtId     = 1;
    
    riff.kindOfRiff = WAVE_CHUNK;
    riff.riffName = RIFF_CHUNK;
    riff.riffSize = format.blockSize * fileInfo->totalSampleSize + 44;
    
    if(fwrite(&riff, sizeof(RiffHeader), 1, fileInfo->fileHandle) != 1)
    {
        THPPrintError("Fail to write riff header\n");
        return FALSE;
    }
    
    chunk.chunkName = FMT_CHUNK;
    chunk.chunkSize = sizeof(WaveFormat);
    
    if(fwrite(&chunk, sizeof(ChunkHeader), 1, fileInfo->fileHandle) != 1)
    {
        THPPrintError("Fail to write chunk header\n");
        return FALSE;
    }
    if(fwrite(&format, sizeof(WaveFormat), 1, fileInfo->fileHandle) != 1)
    {
        THPPrintError("Fail to write format chunk\n");
        return FALSE;
    }
    
    chunk.chunkName = DATA_CHUNK;
    chunk.chunkSize = format.blockSize * fileInfo->totalSampleSize;
    if(fwrite(&chunk, sizeof(ChunkHeader), 1, fileInfo->fileHandle) != 1)
    {
        THPPrintError("Fail to write chunk header\n");
        return FALSE;
    }
    
    return TRUE;
}

s32 __THPWaveMoveDataBlockOffset(THPAudioFileInfo * fileInfo, u32 sampleOffset)
{
    u32 offsetByte;
    
    offsetByte = fileInfo->bitPerSample * fileInfo->channel * sampleOffset / 8;
    
    if(fseek(fileInfo->fileHandle, fileInfo->dataBlockOffset + offsetByte, SEEK_SET) != 0)
    {
        THPPrintError("Fail to seek to specified point in wave file\n");
        return FALSE;
    }
    
    return TRUE;
}

u32 __THPWaveReadSample(THPAudioFileInfo *fileInfo, s16 *left, s16 *right, u32 sampleSize)
{
    u32 i;
    u32 bytePerSample;
    
    bytePerSample = fileInfo->bitPerSample / 8;
    
    if(fileInfo->channel == 1)
    {
        for(i = 0 ; i < sampleSize ; i++)
        {
            if(fread(left, bytePerSample, 1, fileInfo->fileHandle) != 1)
            {
                THPPrintError("Fail to read the left channel data\n");
                return i;
            }
            left++;
        }
        return sampleSize;
    }
    else
    {
        for(i = 0 ; i < sampleSize ; i++)
        {
            if(fread(left, bytePerSample, 1, fileInfo->fileHandle) != 1)
            {
                THPPrintError("Fail to read the left channel data\n");
                return i;
            }
            if(fread(right, bytePerSample, 1, fileInfo->fileHandle) != 1)
            {
                THPPrintError("Fail to read the right channel data\n");
                return i;
            }
            left++;
            right++;
        }
        return sampleSize;
    }
}
