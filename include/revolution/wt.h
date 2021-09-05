/*---------------------------------------------------------------------------*
  Project:  Wavetable definitions for AX synthesizer
  File:     wt.h

  Copyright 1998, 1999, 2000 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphin�V�[�X�c���[����ڐA

    
    3     03/04/08 2:39p Akagi
    Revised comments.
    
    2     02/08/21 6:32p Akagi
    Set #pragma warn_padding off around the WTSAMPLE{} definition.
    
    1     5/09/01 1:28p Billyjack
    created
   
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WT_H__
#define __WT_H__

#ifdef __cplusplus
extern "C" {
#endif
  
typedef struct WTART    // translated DLS articulartion block
{
    // LFO
    s32 lfoFreq;
    s32 lfoDelay;
    s32 lfoAtten;
    s32 lfoPitch;
    s32 lfoMod2Atten;
    s32 lfoMod2Pitch;

    // EG1
    s32 eg1Attack;
    s32 eg1Decay;
    s32 eg1Sustain;
    s32 eg1Release;
    s32 eg1Vel2Attack;
    s32 eg1Key2Decay;

    // EG2
    s32 eg2Attack;
    s32 eg2Decay;
    s32 eg2Sustain;
    s32 eg2Release;
    s32 eg2Vel2Attack;
    s32 eg2Key2Decay;
    s32 eg2Pitch;

    // pan
    s32 pan;

} WTART;

typedef struct WTREGION
{
    u8  unityNote;
    u8  keyGroup;
    
    s16 fineTune;
    s32 attn;
    
    u32 loopStart;
    u32 loopLength;

    u32 articulationIndex;  // articulation index to reference
    u32 sampleIndex;        // sample index to reference

} WTREGION;

#ifdef  __MWERKS__
#pragma warn_padding off
#endif

typedef struct WTSAMPLE
{
    u16 format;     // ADPCM, PCM16, PCM8  
    u16 sampleRate; // Hz
    u32 offset;     // offset in samples from beginning of PCM file
    u32 length;     // length of sample in samples
    u16 adpcmIndex; // ADPCM index to reference if in ADPCM mode 

} WTSAMPLE;

#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

#define WT_FORMAT_ADPCM 0 
#define WT_FORMAT_PCM16 1
#define WT_FORMAT_PCM8  2

typedef struct WTADPCM
{

    // values to program at start
    u16     a[8][2];            //  coef table a1[0],a2[0],a1[1],a2[1]....
    u16     gain;               //  gain to be applied (0 for ADPCM, 0x0800 for PCM8/16)
    u16     pred_scale;         //  predictor / scale combination (nibbles, as in hardware)
    u16     yn1;                //  y[n - 1]
    u16     yn2;                //  y[n - 2]

    // loop context
    u16     loop_pred_scale;    //  predictor / scale combination (nibbles, as in hardware)
    u16     loop_yn1;           //  y[n - 1]
    u16     loop_yn2;           //  y[n - 2]

} WTADPCM;

typedef struct WTINST   // insturment
{

    u16 keyRegion[128];

} WTINST;

typedef struct WTFILEHEADER   // FILE
{

    u32 offsetPercussiveInst;
    u32 offsetMelodicInst;
    u32 offsetRegions;
    u32 offsetArticulations;
    u32 offsetSamples;
    u32 offsetAdpcmContext;

    // data

} WTFILEHEADER;


#ifdef __cplusplus
}
#endif

#endif // __WT_H__ 
