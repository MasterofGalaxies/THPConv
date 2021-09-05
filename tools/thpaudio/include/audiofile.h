/*---------------------------------------------------------------------------*
  Project:  Revolution THP Audio Library
  File:     audiofile.h

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    8     03/07/07 10:46a Akagi
    Moved from build/tools/THPUtilities/include.
    
    7     03/07/01 2:04p Akagi
    Moved from build/tools/THPConv/include.
    
    6     03/07/01 9:19a Akagi
    Moved from securebuild/tools.
    
    5     02/05/08 2:30p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    1     02/01/16 4:53p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#ifndef __AUDIOFILE_H__
#define __AUDIOFILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <win32/thpaudio.h>
    
#define WAVE_FILE 0
        
#define PCM 0x1
        
s32   __THPAudioOpenFile(char *fileName, THPAudioFileInfo *fileInfo);
s32   __THPAudioCreateFile(char *fileName, THPAudioFileInfo *fileInfo);
s32   __THPAudioCloseFile(THPAudioFileInfo *fileInfo);
s32   __THPAudioReadFileInfo(THPAudioFileInfo *fileInfo);
s32   __THPAudioWriteFileInfo(THPAudioFileInfo *fileInfo);
s32   __THPAudioCheckFormat(THPAudioFileInfo *fileInfo);
void* __THPAudioAllocateSampleBuffer(THPAudioFileInfo *fileInfo, u32 sampleSize);
void  __THPAudioFreeSampleBuffer(void *ptr);
s32   __THPAudioMoveDataBlock(THPAudioFileInfo *fileInfo);
s32   __THPAudioMoveDataBlockOffset(THPAudioFileInfo *fileInfo, u32 sampleOffset);
s32   __THPAudioReadSample(THPAudioFileInfo *fileInfo, void *left, void *right, u32 sampleSize);
        
#ifdef __cplusplus
}
#endif

#endif // __AUDIOFILE_H__
