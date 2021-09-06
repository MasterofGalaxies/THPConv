/*---------------------------------------------------------------------------*
  Project:  Revolution THP Audio Library
  File:     thpaudio.c

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/12/21 07:04:07  aka
  Removed resampling code.

  Revision 1.1  2006/02/08 02:54:55  aka
  Imported from Dolphin Tree.

    
    16    04/01/09 11:41a Akagi
    Revised GetSampleingData() to fill buffer with 0 when new samples are
    short.
    
    15    03/12/08 3:59p Akagi
    Revised a trivial bug.
    
    14    03/09/15 6:09p Akagi
    Renamed THCONVReverseXXX to THPUtyReverseXXX.
    
    13    03/07/07 10:49a Akagi
    Moved from build/tools/THPUtilities/src.
    
    12    03/07/03 11:04a Akagi
    Renamed some functions.
    
    11    03/07/01 2:34p Akagi
    Modified to divide old THPConv.exe into 2 LIBs and 1 EXE by
    Ohki-san@NTSC.
    
    10    03/07/01 2:25p Akagi
    Moved from build/tools/THPConv/src.
    
    9     03/07/01 9:54a Akagi
    Moved from securebuild/tools.
    
    8     02/10/16 11:28a Akagi
    JPEG & WAV file Name bug fixed. (by iRD  tsuji)
    
    7     02/05/27 9:45a Akagi
    Modified output error messages in English, by Tsuji (IRD)
    
    6     02/05/08 2:31p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    2     02/01/22 10:10a Akagi
    Add error message, when can't load "dsptools.dll" by Tsuji.
    
    1     02/01/16 4:58p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#include <windows.h>
#include <stdio.h>

#include <revolution/types.h>
#include <win32/thpcore.h>
#include <win32/thputilities.h>
#include <win32/thpaudio.h>
#include <win32/dsptool.h>

#include "audiofile.h"
#include "coef.h"

void encode
(
    s16         *src,   // location of source samples (16bit PCM signed little endian)
    u8          *dst,   // location of destination buffer
    ADPCMINFO   *cxt,   // location of adpcm info
    u32         samples // number of samples to encode         
);
#define lpencode encode

void decode
(
    u8          *src,       // location of ADPCM buffer in RAM
    s16         *dst,       // location of destination buffer
    ADPCMINFO   *cxt,       // location of adpcminfo
    u32         samples     // samples to desired context
);
#define lpdecode decode

//-----------------------------------------------------------------------------
//      Function
//-----------------------------------------------------------------------------
static s32 PrepareEncodedData(THPAudioHandle *handle);
static s32 WriteFrame(FILE *output, s32 flag);
static u32 GetFrameSampleSize(THPAudioHandle *handle, u32 frameNum, s32 flag);
static u32 GetNeedSample(THPAudioHandle *handle, u32 frameNum, s32 flag);
static s32 GetSamplingData(THPAudioHandle* handle, s16* leftBuffer, s16* rightBuffer, u32 needSample);

//-----------------------------------------------------------------------------
//      Variable
//-----------------------------------------------------------------------------
static s32 Initialized = 0;

//-----------------------------------------------------------------------------
//      THPAudioInit
//
//      初期化
//
//      IN:     なし
//      RTN:    TRUE            成功
//              FALSE           失敗
//-----------------------------------------------------------------------------
s32 THPAudioInit(void)
{
    if(!Initialized)
    {
        Initialized = 1;
    }
    
    return TRUE;
}


THPAudioHandle *THPAudioCreateHandle(char * fileName, f32 framerate)
{
    THPAudioHandle *handle;
    
    if(Initialized)
    {
        handle = (THPAudioHandle *)THPMalloc(sizeof(THPAudioHandle));
        
        if(__THPAudioOpenFile(fileName, &handle->audioInfo) == FALSE)
        {
            THPFree(handle);
            THPPrintError("ERROR : Fail to open AudioFile.\n");
            return NULL;
        }
        
        if(__THPAudioReadFileInfo(&handle->audioInfo) == FALSE)
        {
            __THPAudioCloseFile(&handle->audioInfo);
            THPPrintError("ERROR : Fail to read AudioFile Info.\n");
            THPFree(handle);
            return NULL;
        }
        
        if(__THPAudioCheckFormat(&handle->audioInfo) == FALSE)
        {
            __THPAudioCloseFile(&handle->audioInfo);
            THPFree(handle);
            return NULL;
        }
        
        memset(&handle->recordHeader, 0, sizeof(THPAudioRecordHeader));
        
        if(__THPAudioMoveDataBlock(&handle->audioInfo) == FALSE)
        {
            __THPAudioCloseFile(&handle->audioInfo);
            THPFree(handle);
            THPPrintError("ERROR : Fail to seek AudioFile.\n");
            return NULL;
        }
    
        handle->restEncodedSample  = 0;
        handle->currentFrameNumber = 0;
        handle->readSample         = 0;
        
        if(framerate <= 59.94f && framerate >= 1.0f)
        {
            handle->frameRate = framerate;
        }
        else
        {
            __THPAudioCloseFile(&handle->audioInfo);
            THPFree(handle);
            THPPrintError("ERROR : Bad FrameRate.\n");
            return NULL;
        }
        
        return handle;
    }
    else
    {
        THPPrintError("ERROR : Please call THPAudioInit().\n");
        return NULL;
    }
}

void THPAudioFreeHandle(THPAudioHandle *handle)
{
    __THPAudioCloseFile(&handle->audioInfo);
    free(handle);
    
    return;
}

s32 THPAudioQuit(void)
{
    if(Initialized)
    {
        Initialized = 0;
    }
    
    return TRUE;
}

s32 THPAudioGetInfo(THPAudioHandle *handle, THPAudioInfo *info)
{
    if(Initialized)
    {
        info->sndChannels   = handle->audioInfo.channel;
        info->sndFrequency  = handle->audioInfo.frequency;
        info->sndNumSamples = 0;
        
        return TRUE;
    }
    
    return FALSE;
}

u32 THPAudioGetTotalSamples(THPAudioHandle *handle, s32 frame)
{
    if(Initialized)
    {
        if(frame > 0)
            return (GetNeedSample(handle, frame, 1));
    }
    
    return 0;
}

u32 THPAudioGetMaxFrameSize(THPAudioHandle *handle, s32 frame)
{
    u32 size, max;
    s32 i;
    
    if(Initialized)
    {
        max = 0;
        for(i = 0 ; i < frame - 1; i++)
        {
            size = THPADPCMSampleToByte(GetFrameSampleSize(handle, i + 1, 0));
            
            if(max < size)
            {
                max = size;
            }
        }
        
        size = THPADPCMSampleToByte(GetFrameSampleSize(handle, frame + 1, 1));
        
        if(max < size)
        {
            max = size;
        }
        
        if(handle->audioInfo.channel == 2)
        {
            return sizeof(THPAudioRecordHeader) + max * 2;
        }
        else
        {
            return sizeof(THPAudioRecordHeader) + max;
        }
    }
    
    return 0;
}

u32 THPAudioGetMaxFrameSamples(THPAudioHandle *handle, s32 frame)
{
    u32 size, max;
    s32 i;
    
    if(Initialized)
    {
        max = 0;
        for(i = 0 ; i < frame - 1; i++)
        {
            size = GetFrameSampleSize(handle, i + 1, 0);
            
            if(max < size)
            {
                max = size;
            }
        }
        
        size = GetFrameSampleSize(handle, frame + 1, 1);
        
        if(max < size)
        {
            max = size;
        }
        
        return max;
    }
    
    return 0;
}

u32 THPAudioGetFrameSize(THPAudioHandle *handle, u32 frame)
{
    u32 size;
    
    if(Initialized)
    {
        if(handle->audioInfo.channel == 2)      
        {
            size = sizeof(THPAudioRecordHeader)
                + THPADPCMSampleToByte(GetFrameSampleSize(handle, frame + 1, 0)) * 2;
        }
        else
        {
            size = sizeof(THPAudioRecordHeader)
                + THPADPCMSampleToByte(GetFrameSampleSize(handle, frame + 1, 0));
        }
        
        return size;
    }
    
    return 0;
}

// output audio frame.
// The sample in the frame is multiple of 14 commonly.
// 
s32 THPAudioWriteFrame(THPAudioHandle *handle, FILE *output, s32 flag)
{
    u32 needSample, needSample14, adpcmSize;
    
    if(Initialized)
    {
        needSample   = GetFrameSampleSize(handle, handle->currentFrameNumber + 1, 1);
        needSample14 = GetFrameSampleSize(handle, handle->currentFrameNumber + 1, 0);
        adpcmSize    = THPADPCMSampleToByte(needSample14);
        
        if(handle->restEncodedSample < needSample14)
        {
            if( PrepareEncodedData(handle) == FALSE )
            {
                return FALSE;
            }
        }
        
        if(flag)
        {
            handle->recordHeader.sampleSize =THPUtyReverseEndianU32(needSample);
        }
        else
        {
            handle->recordHeader.sampleSize = THPUtyReverseEndianU32(needSample14);
        }
        
        if(handle->currentFrameNumber)
        {
            handle->recordHeader.lYn1 = THPUtyReverseEndianU16(*(handle->leftDecodedPtr - 1));
            handle->recordHeader.lYn2 = THPUtyReverseEndianU16(*(handle->leftDecodedPtr - 2));
        }
        else
        {
            handle->recordHeader.lYn1 = 0;
            handle->recordHeader.lYn2 = 0;
        }
        
        handle->leftDecodedPtr = handle->leftDecodedPtr + needSample14;
        
        if(handle->audioInfo.channel == 2)
        {
            if(handle->currentFrameNumber)
            {
                handle->recordHeader.rYn1 = THPUtyReverseEndianU16(*(handle->rightDecodedPtr - 1));
                handle->recordHeader.rYn2 = THPUtyReverseEndianU16(*(handle->rightDecodedPtr - 2));
            }
            else
            {
                handle->recordHeader.rYn1 = 0;
                handle->recordHeader.rYn2 = 0;
            }
            
            handle->recordHeader.offsetNextChannel = THPUtyReverseEndianU32(adpcmSize);
            
            handle->rightDecodedPtr = handle->rightDecodedPtr + needSample14;
        }
        else
        {
            handle->recordHeader.offsetNextChannel = 0;
        }
        
        if(fwrite(&handle->recordHeader, sizeof(THPAudioRecordHeader), 1, output) != 1 )
        {
            THPPrintError("ERROR : Fail to write the audio record header to output file\n");
            return FALSE;
        }
        
        if(fwrite(handle->leftADPCMPtr, adpcmSize, 1, output) != 1)
        {
            THPPrintError("ERROR : Fail to write the left channel data to output file\n");
            return FALSE;
        }
        
        handle->leftADPCMPtr += adpcmSize;
        
        if(handle->audioInfo.channel == 2)
        {
            if(fwrite(handle->rightADPCMPtr, adpcmSize, 1, output) != 1)
            {
                THPPrintError("ERROR : Fail to write the left channel data to output file\n");
                return FALSE;
            }
            
            handle->rightADPCMPtr += adpcmSize;
        }
        
        handle->restEncodedSample -= needSample14;
        handle->currentFrameNumber++;
    }
    
    return TRUE;
}

static s32 PrepareEncodedData(THPAudioHandle *handle)
{
    u32 needNewSample, copySample;
    s16 *leftBufferPtr, *rightBufferPtr;
    s16 *src;
    
    if (handle->currentFrameNumber)
    {
        copySample = handle->restEncodedSample + THP_OVERLAP_SAMPLE;
        
        src = handle->leftSampleBuffer + (THP_SAMPLE_BUFFER_SIZE - copySample);
        memcpy(handle->leftSampleBuffer, src, copySample * 2);
        
        if (handle->audioInfo.channel == 2)
        {
            src = handle->rightSampleBuffer + (THP_SAMPLE_BUFFER_SIZE - copySample);
            memcpy(handle->rightSampleBuffer, src, copySample * 2);
        }
        
        leftBufferPtr  = handle->leftSampleBuffer  + copySample;
        rightBufferPtr = handle->rightSampleBuffer + copySample;
        
        needNewSample = THP_SAMPLE_BUFFER_SIZE - copySample;
        
        handle->restEncodedSample = THP_ENCODE_SAMPLE;
    }
    else
    {
        leftBufferPtr  = handle->leftSampleBuffer;
        rightBufferPtr = handle->rightSampleBuffer;
        
        needNewSample  = THP_SAMPLE_BUFFER_SIZE;
        
        handle->restEncodedSample = THP_SAMPLE_BUFFER_SIZE;
    }

    if(GetSamplingData(handle,  leftBufferPtr, rightBufferPtr, needNewSample) == FALSE)
    {
        return FALSE;
    }

    lpencode(handle->leftSampleBuffer,
             handle->leftADPCMBuffer,
             &handle->leftADPCMInfo,
             THP_SAMPLE_BUFFER_SIZE);
    
    lpdecode(handle->leftADPCMBuffer,
             handle->leftDecodedBuffer,
             &handle->leftADPCMInfo,
             THP_SAMPLE_BUFFER_SIZE);
    
    if(handle->currentFrameNumber)
    {
        handle->leftADPCMPtr   = THPGetEncDataPtr(handle->leftADPCMBuffer, THP_OVERLAP_SAMPLE);
        handle->leftDecodedPtr = THPGetDecDataPtr(handle->leftDecodedBuffer, THP_OVERLAP_SAMPLE);
    }
    else
    {
        handle->leftADPCMPtr   = handle->leftADPCMBuffer;
        handle->leftDecodedPtr = handle->leftDecodedBuffer;
    }
    
    handle->recordHeader.lCoef[0]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[0]);
    handle->recordHeader.lCoef[1]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[1]);
    handle->recordHeader.lCoef[2]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[2]);
    handle->recordHeader.lCoef[3]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[3]);
    handle->recordHeader.lCoef[4]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[4]);
    handle->recordHeader.lCoef[5]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[5]);
    handle->recordHeader.lCoef[6]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[6]);
    handle->recordHeader.lCoef[7]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[7]);
    handle->recordHeader.lCoef[8]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[8]);
    handle->recordHeader.lCoef[9]  = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[9]);
    handle->recordHeader.lCoef[10] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[10]);
    handle->recordHeader.lCoef[11] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[11]);
    handle->recordHeader.lCoef[12] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[12]);
    handle->recordHeader.lCoef[13] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[13]);
    handle->recordHeader.lCoef[14] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[14]);
    handle->recordHeader.lCoef[15] = THPUtyReverseEndianU16(handle->leftADPCMInfo.coef[15]);
    
    if(handle->audioInfo.channel == 2)
    {
        lpencode(handle->rightSampleBuffer,
                 handle->rightADPCMBuffer,
                 &handle->rightADPCMInfo,
                 THP_SAMPLE_BUFFER_SIZE);
        
        lpdecode(handle->rightADPCMBuffer,
                 handle->rightDecodedBuffer,
                 &handle->rightADPCMInfo,
                 THP_SAMPLE_BUFFER_SIZE);
        
        if(handle->currentFrameNumber)
        {
            handle->rightADPCMPtr   = THPGetEncDataPtr(handle->rightADPCMBuffer, THP_OVERLAP_SAMPLE);
            handle->rightDecodedPtr = THPGetDecDataPtr(handle->rightDecodedBuffer, THP_OVERLAP_SAMPLE);
        }
        else
        {
            handle->rightADPCMPtr   = handle->rightADPCMBuffer;
            handle->rightDecodedPtr = handle->rightDecodedBuffer;
        }
        
        handle->recordHeader.rCoef[0]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[0]);
        handle->recordHeader.rCoef[1]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[1]);
        handle->recordHeader.rCoef[2]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[2]);
        handle->recordHeader.rCoef[3]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[3]);
        handle->recordHeader.rCoef[4]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[4]);
        handle->recordHeader.rCoef[5]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[5]);
        handle->recordHeader.rCoef[6]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[6]);
        handle->recordHeader.rCoef[7]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[7]);
        handle->recordHeader.rCoef[8]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[8]);
        handle->recordHeader.rCoef[9]  = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[9]);
        handle->recordHeader.rCoef[10] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[10]);
        handle->recordHeader.rCoef[11] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[11]);
        handle->recordHeader.rCoef[12] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[12]);
        handle->recordHeader.rCoef[13] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[13]);
        handle->recordHeader.rCoef[14] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[14]);
        handle->recordHeader.rCoef[15] = THPUtyReverseEndianU16(handle->rightADPCMInfo.coef[15]);
    }
    
    return TRUE;
}

static u32 GetFrameSampleSize(THPAudioHandle *handle, u32 frameNumber, s32 flag)
{
    if(frameNumber > 0)
        return (GetNeedSample(handle, frameNumber, flag) - GetNeedSample(handle, frameNumber - 1, 0));
    else
        return 0;
}

// Return the needed sample size.
// flag : 1 real size | 0 14 multiple
static u32 GetNeedSample(THPAudioHandle *handle, u32 frameNumber, s32 flag)
{
    u32 needSample;
    f64 needSampleF;
    
    needSampleF = (frameNumber) * (handle->audioInfo.frequency) / handle->frameRate;
    needSample  = (u32)needSampleF;
    
    if (needSampleF > (f64)needSample)
    {
        needSample++;
    }
    
    if(!flag)
    {
        if(needSample % 14)
            needSample = 14 * ( (needSample / 14) + 1 );
    }
    
    return needSample;
}

//-----------------------------------------------------------------------------
//      サンプリングデータの読み込み（周波数変換無)
//-----------------------------------------------------------------------------
static s32 GetSamplingData(THPAudioHandle* handle, s16* leftBuffer, s16* rightBuffer, u32 needSample)
{
    THPAudioFileInfo* audioInfo;
    u32               readSize;
    u32               i;
    
    audioInfo = &handle->audioInfo;
    
    if(audioInfo->totalSampleSize > handle->readSample + needSample)
    {
        readSize = needSample;
    } else {
        readSize = audioInfo->totalSampleSize - handle->readSample;
    }
    
    if(audioInfo->channel == 1)
    {
        for(i = 0; i < readSize; i++){
            if(fread(&leftBuffer[i] , sizeof(s16), 1, audioInfo->fileHandle) != 1)
            {
                THPPrintError("ERROR : Fail to read the left channel data to input wave file\n");
                return FALSE;
            }
            rightBuffer[i] = 0;
        }
        
        for (; i < needSample; i++)
        {
            leftBuffer[i] = rightBuffer[i] = 0;
        }
        
        handle->readSample += readSize;
    }
    else
    {
        for(i = 0; i < readSize; i++){
            if(fread(&leftBuffer[i] , sizeof(s16), 1, audioInfo->fileHandle) != 1)
            {
                THPPrintError("ERROR : Fail to read the left channel data to input wave file\n");
                return FALSE;
            }
            if(fread(&rightBuffer[i] , sizeof(s16), 1, audioInfo->fileHandle) != 1)
            {
                THPPrintError("ERROR : Fail to read the right channel data to input wave file\n");
                return FALSE;
            }
        }
        
        for (; i < needSample; i++)
        {
            leftBuffer[i] = rightBuffer[i] = 0;
        }
        
        handle->readSample += readSize;
    }
    
    return TRUE;
    
}
