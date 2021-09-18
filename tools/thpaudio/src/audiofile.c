/*---------------------------------------------------------------------------*
  Project:  Revolution THP Audio Library
  File:     audiofile.c

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    10    03/07/07 10:49a Akagi
    Moved from build/tools/THPUtilities/src.
    
    9     03/07/01 2:34p Akagi
    Modified to divide old THPConv.exe into 2 DLLs and 1 EXE by
    Ohki-san@NTSC.
    
    8     03/07/01 2:25p Akagi
    Moved from build/tools/THPConv/src.
    
    7     03/07/01 9:54a Akagi
    Moved from securebuild/tools.
    
    6     02/10/16 11:28a Akagi
    JPEG & WAV file Name bug fixed. (by iRD  tsuji)
    
    5     02/05/08 2:30p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    1     02/01/16 4:57p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <revolution/types.h>
#include <win32/thpcore.h>
#include <win32/thpaudio.h>

#include "audiofile.h"
#include "wave.h"

s32 __THPAudioOpenFile(char *fileName, THPAudioFileInfo *fileInfo)
{
    
    if( (fileInfo->fileHandle = fopen(fileName, "r")) == NULL )
    {
        THPPrintError("Can't open [%s]\n", fileName);
        return FALSE;
    }
    
    strcpy(fileInfo->fileName, fileName);
    
    fileInfo->bitPerSample    = 0;
    fileInfo->channel         = 0;
    fileInfo->curFileOffset   = 0;
    fileInfo->dataBlockOffset = 0;
    fileInfo->frequency       = 0;
    fileInfo->totalSampleSize = 0;
    
    if (strcmp("__tmp_AD", fileName) == 0)
    {
        fileInfo->type = WAVE_FILE;
    }
    else
    {
        size_t extOffset = strlen(fileName);

        if(extOffset >= 4 && strcasecmp(fileName + extOffset - 4, ".wav") == 0){
            fileInfo->type = WAVE_FILE;
        } else {
            THPPrintError("ERROR : This file name is Not [*.wav].\n");
            fclose(fileInfo->fileHandle);
            return FALSE;
        }
        
        
#if 0
        char  tmp_name[256];
        int char_len = strlen(fileName);
        char *c;
        
        // è¨ï∂éöÇ…ïœä∑
        {
            u16  i;
            for(i = 0; i < 256; i++){
                tmp_name[i] = tolower(fileName[i]);
            }
        }
        
        c =  tmp_name;
        c += (char_len -4);
        
        if(*c == '.')
        {
            c++;
            if(strncmp(c, "wav", 3) == 0)
            {
                fileInfo->type = WAVE_FILE;
            }
            else
            {
                THPPrintError("ERROR : This file name is Not [*.wav].\n");
                fclose(fileInfo->fileHandle);
                return FALSE;
            }
        }
        else
        {
            THPPrintError("ERROR : This file name is Not [*.wav].\n");
            fclose(fileInfo->fileHandle);
            return FALSE;
        }
#endif
        
    }
    
    if(fileInfo->type != WAVE_FILE)
    {
        THPPrintError("ERROR : Audio File is Not WAVE_FILE.\n");
        return FALSE;
    }
    
    
    return TRUE;
}

s32 __THPAudioCreateFile(char *fileName, THPAudioFileInfo *fileInfo)
{
    if( (fileInfo->fileHandle = fopen(fileName, "w")) == NULL )
    {
        THPPrintError("Can't create %s\n", fileName);
        return FALSE;
    }
    
    strcpy(fileInfo->fileName, fileName);
    
    fileInfo->bitPerSample    = 0;
    fileInfo->channel         = 0;
    fileInfo->curFileOffset   = 0;
    fileInfo->dataBlockOffset = 0;
    fileInfo->frequency       = 0;
    fileInfo->totalSampleSize = 0;
    
    return TRUE;
}

s32 __THPAudioCloseFile(THPAudioFileInfo *fileInfo)
{
    fileInfo->bitPerSample    = 0;
    fileInfo->channel         = 0;
    fileInfo->curFileOffset   = 0;
    fileInfo->dataBlockOffset = 0;
    fileInfo->frequency       = 0;
    fileInfo->totalSampleSize = 0;
    
    memset(fileInfo->fileName, 0, 256);
    
    if(fclose(fileInfo->fileHandle) != 0)
    {
        THPPrintError("Fail to close the audio file\n");
        return FALSE;
    }
    
    return TRUE;
}

s32 __THPAudioReadFileInfo(THPAudioFileInfo *fileInfo)
{
    switch(fileInfo->type)
    {
        case WAVE_FILE:
        {
            if(__THPWaveReadHeader(fileInfo) == FALSE)
            {
                THPPrintError("ERROR : in __THPWaveReadHeader()\n");
                return FALSE;
            }
            break;
        }
        default:
            break;
    }
    
    return TRUE;
}

s32 __THPAudioWriteFileInfo(THPAudioFileInfo *fileInfo)
{
    switch(fileInfo->type)
    {
        case WAVE_FILE:
        {
            if(__THPWaveWriteHeader(fileInfo) == FALSE)
            {
                return FALSE;
            }
            break;
        }
        default:
            break;
    }
    
    return TRUE;
}

s32 __THPAudioCheckFormat(THPAudioFileInfo *fileInfo)
{
#if 0
    if(!(fileInfo->frequency == 32000 || fileInfo->frequency == 48000))
    {
        THPPrintError("The frequency of the audio file must be 32000 or 48000\n");
        return FALSE;
    }
#endif
    if(!(fileInfo->channel == 1 || fileInfo->channel == 2))
    {
        THPPrintError("The channel of the audio file must be 1 or 2\n");
        return FALSE;
    }
    if(fileInfo->bitPerSample != 16)
    {
        THPPrintError("The sample bit of the audio file must be 16\n");
        return FALSE;
    }
    
    if(fileInfo->formatType != PCM)
    {
        THPPrintError("The audio file format must be PCM\n");
        return FALSE;
    }
    
    return TRUE;
}

void *__THPAudioAllocateSampleBuffer(THPAudioFileInfo *fileInfo, u32 sampleSize)
{
    void *ptr;
    
    ptr = THPMalloc(fileInfo->bitPerSample * sampleSize / 8);
    if(ptr == NULL)
    {
        THPPrintError("Can't allocate the memory for sample buffer\n");
    }
    
    return ptr;
}

void __THPAudioFreeSampleBuffer(void *ptr)
{
    if(ptr != NULL)
    {
        free(ptr);
    }
    
    return;
}

s32 __THPAudioMoveDataBlock(THPAudioFileInfo *fileInfo)
{
    if(__THPAudioMoveDataBlockOffset(fileInfo, 0) == FALSE)
    {
        return FALSE;
    }
    
    return TRUE;
}

s32 __THPAudioMoveDataBlockOffset(THPAudioFileInfo *fileInfo, u32 sampleOffset)
{
    if(fileInfo->type == WAVE_FILE)
    {
        if(__THPWaveMoveDataBlockOffset(fileInfo, sampleOffset) == FALSE)
            return FALSE;
    }
    else
        return FALSE;
    
    return TRUE;
}

s32 __THPAudioReadSample(THPAudioFileInfo *fileInfo, void *left, void *right, u32 sampleSize)
{
    if(fileInfo->type == WAVE_FILE)
    {
        if(__THPWaveReadSample(fileInfo, (s16 *)left, (s16 *)right, sampleSize) != sampleSize)
        {
            return FALSE;
        }
    }
    
    return TRUE;
}
