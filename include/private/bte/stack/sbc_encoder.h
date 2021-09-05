/******************************************************************************
**
**  File Name:   $RCSfile: sbc_encoder.h,v $
**
**  Description: This file contains constants and structures used by Encoder.
**
**  Revision :   $Id: sbc_encoder.h,v 1.7 2007-10-17 00:26:08 tojo Exp $
**
**  Copyright (c) 1999-2002, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/

#ifndef SBC_ENCODER_H
#define SBC_ENCODER_H

#define ENCODER_VERSION "0021"

#ifdef BUILDCFG 
    #include <private/bte/common/target.h>
#endif

/*DEFINES*/
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#define SBC_MAX_NUM_OF_SUBBANDS 8
#define SBC_MAX_NUM_OF_CHANNELS 2
#define SBC_MAX_NUM_OF_BLOCKS   16

#define SBC_LOUDNESS    0
#define SBC_SNR 1

#define SUB_BANDS_8 8
#define SUB_BANDS_4 4

#define SBC_sf16000 0
#define SBC_sf32000 1
#define SBC_sf44100 2
#define SBC_sf48000 3

#define SBC_MONO    0
#define SBC_DUAL    1
#define SBC_STEREO  2
#define SBC_JOINT_STEREO    3

#define SBC_BLOCK_0 4
#define SBC_BLOCK_1 8
#define SBC_BLOCK_2 12
#define SBC_BLOCK_3 16

#define SBC_NULL    0

#ifndef SBC_MAX_NUM_FRAME
#define SBC_MAX_NUM_FRAME 1
#endif

#ifndef SBC_DSP_OPT 
#define SBC_DSP_OPT FALSE
#endif

/* Set SBC_USE_ARM_PRAGMA to TRUE to use "#pragma arm section zidata" */
#ifndef SBC_USE_ARM_PRAGMA
#define SBC_USE_ARM_PRAGMA FALSE
#endif

/* Set SBC_ARM_ASM_OPT to TRUE in case the target is an ARM */
/* this will replace all the 32 and 64 bit mult by in line assembly code */
#ifndef SBC_ARM_ASM_OPT
#define SBC_ARM_ASM_OPT FALSE
#endif

/* Set SBC_IPAQ_OPT to TRUE in case the target is an ARM */
/* 32 and 64 bit mult will be performed using SINT16 ( usualy __int64 ) cast that usualy give optimal performance if supported */
#ifndef SBC_IPAQ_OPT
#define SBC_IPAQ_OPT TRUE
#endif

/* Debug only: set SBC_IS_64_MULT_IN_WINDOW_ACCU to TRUE to use 64 bit multiplication in the windowing */
/* -> not recomended, more MIPS for the same restitution.  */
#ifndef SBC_IS_64_MULT_IN_WINDOW_ACCU
#define SBC_IS_64_MULT_IN_WINDOW_ACCU  FALSE
#endif /*SBC_IS_64_MULT_IN_WINDOW_ACCU */

/* Set SBC_IS_64_MULT_IN_IDCT to TRUE to use 64 bits multiplication in the DCT of Matrixing */
/* -> more MIPS required for a better audio quality. comparasion with the SIG utilities shows a division by 10 of the RMS */
/* CAUTION: It only apply in the if SBC_FAST_DCT is set to TRUE */
#ifndef SBC_IS_64_MULT_IN_IDCT
#define SBC_IS_64_MULT_IN_IDCT  FALSE			
#endif /*SBC_IS_64_MULT_IN_IDCT */

/* set SBC_IS_64_MULT_IN_QUANTIZER to TRUE to use 64 bits multiplication in the quantizer */
/* setting this flag to FALSE add whistling noise at 5.5 and 11 KHz usualy not perceptible by human's hears. */
#ifndef SBC_IS_64_MULT_IN_QUANTIZER
#define SBC_IS_64_MULT_IN_QUANTIZER  TRUE
#endif /*SBC_IS_64_MULT_IN_IDCT */

/* Debug only: set this flag to FALSE to disable fast DCT algorithm */
#ifndef SBC_FAST_DCT
#define SBC_FAST_DCT  TRUE
#endif /*SBC_FAST_DCT */

/* In case we do not use joint stereo mode the flag save some RAM and ROM in case it is set to FALSE */
#ifndef SBC_JOINT_STE_INCLUDED
#define SBC_JOINT_STE_INCLUDED TRUE
#endif

/* TRUE -> application should provide PCM buffer, FALSE PCM buffer reside in SBC_ENC_PARAMS */
#ifndef SBC_NO_PCM_CPY_OPTION
#define SBC_NO_PCM_CPY_OPTION FALSE
#endif

#define MINIMUM_ENC_VX_BUFFER_SIZE (8*10*2)
#ifndef ENC_VX_BUFFER_SIZE 
#define ENC_VX_BUFFER_SIZE (MINIMUM_ENC_VX_BUFFER_SIZE + 64)
/*#define ENC_VX_BUFFER_SIZE MINIMUM_ENC_VX_BUFFER_SIZE + 1024*/
#endif
/*constants used for index calculation*/
#define SBC_BLK (SBC_MAX_NUM_OF_CHANNELS * SBC_MAX_NUM_OF_SUBBANDS)

#include "sbc_types.h"

typedef struct SBC_ENC_PARAMS_TAG
{
    SINT16 s16SamplingFreq;                         /* 16k, 32k, 44.1k or 48k*/
    SINT16 s16ChannelMode;                          /* mono, dual, streo or joint streo*/
    SINT16 s16NumOfSubBands;                        /* 4 or 8 */
    SINT16 s16NumOfChannels;
    SINT16 s16NumOfBlocks;                          /* 4, 8, 12 or 16*/
    SINT16 s16AllocationMethod;                     /* loudness or SNR*/
    SINT16 s16BitPool;                              /* 16*numOfSb for mono & dual; 
                                                       32*numOfSb for stereo & joint stereo */
    UINT16 u16BitRate;
    UINT8   u8NumPacketToEncode;                    /* number of sbc frame to encode. Default is 1 */
#if (SBC_JOINT_STE_INCLUDED == TRUE)
    SINT16 as16Join[SBC_MAX_NUM_OF_SUBBANDS];       /*1 if JS, 0 otherwise*/
#endif

    SINT16 s16MaxBitNeed;
    SINT16 as16ScaleFactor[SBC_MAX_NUM_OF_CHANNELS*SBC_MAX_NUM_OF_SUBBANDS];

    SINT16 *ps16NextPcmBuffer;
#if (SBC_NO_PCM_CPY_OPTION == TRUE)
    SINT16 *ps16PcmBuffer;
#else
    SINT16 as16PcmBuffer[SBC_MAX_NUM_FRAME*SBC_MAX_NUM_OF_BLOCKS * SBC_MAX_NUM_OF_CHANNELS * SBC_MAX_NUM_OF_SUBBANDS];
#endif

    SINT16  s16ScartchMemForBitAlloc[16];

    SINT32  s32SbBuffer[SBC_MAX_NUM_OF_CHANNELS * SBC_MAX_NUM_OF_SUBBANDS * SBC_MAX_NUM_OF_BLOCKS];

    SINT16 as16Bits[SBC_MAX_NUM_OF_CHANNELS*SBC_MAX_NUM_OF_SUBBANDS];

    UINT8  *pu8Packet;
    UINT8  *pu8NextPacket;
    UINT16 FrameHeader;
    UINT16 u16PacketLength;

}SBC_ENC_PARAMS;

#ifdef __cplusplus
extern "C"
{
#endif
SBC_API extern void SBC_Encoder(SBC_ENC_PARAMS *strEncParams);
SBC_API extern void SBC_Encoder_Init(SBC_ENC_PARAMS *strEncParams);
#ifdef __cplusplus
}
#endif
#endif
