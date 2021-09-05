/*---------------------------------------------------------------------------*
  Project:  Revolution THP Audio Library
  File:     wave.h

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    8     03/07/07 10:46a Akagi
    Moved from build/tools/THPUtilities/include.
    
    7     03/07/01 2:07p Akagi
    Moved from build/tools/THPConv/include.
    
    6     03/07/01 9:19a Akagi
    Moved from securebuild/tools.
    
    5     02/05/08 2:30p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    1     02/01/16 4:57p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#ifndef __WAVE_H__
#define __WAVE_H__

#include <revolution/types.h>
#include <win32/thpaudio.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#define RIFF_CHUNK 0x46464952
#define WAVE_CHUNK 0x45564157
#define FMT_CHUNK  0x20746D66
#define DATA_CHUNK 0x61746164
	
typedef struct
{
    u32 riffName;
    u32 riffSize;
    u32 kindOfRiff;
} RiffHeader;

typedef struct
{
    u32 chunkName;
    u32 chunkSize;
} ChunkHeader;

typedef struct
{
    u16 fmtId;
    u16 channel;
    u32 frequency;
    u32 aveSpeed;
    u16 blockSize;
    u16 perBit;
} WaveFormat;

s32 __THPWaveReadHeader(THPAudioFileInfo *file);
s32 __THPWaveWriteHeader(THPAudioFileInfo *file);
s32 __THPWaveMoveDataBlockOffset(THPAudioFileInfo * file, u32 sample);
u32 __THPWaveReadSample(THPAudioFileInfo *fileInfo, s16 *left, s16 *right, u32 sampleSize);
	
#ifdef __cplusplus
}
#endif

#endif //__WAVE_H__
