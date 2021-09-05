/******************************************************************************
**
**  File Name:   $RCSfile: sbc_decoder.h,v $
**
**  Description: This file has the BitAlloc function declaration
**
**  Revision :   $Id: sbc_decoder.h,v 1.7 2007-10-17 00:26:08 tojo Exp $
**
**  Copyright (c) 1999-2002, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/
#ifndef SBC_DECODER_H
#define SBC_DECODER_H

#ifdef BUILDCFG
#include <private/bte/common/target.h>
#endif

#include <private/bte/stack/sbc_types.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/*DEFINES*/
#define SBC_CRC_FAILURE -1
#define SBC_SYNC_FAILURE -2
#define SBC_EMPTY_FAILURE -3
#define SBC_MEM_FAILURE -4
#define SBC_FAILURE 0
#define SBC_SUCCESS 1

#define SBC_NULL 0

#define SBC_MAX_NUM_OF_SUBBANDS	8
#define	SBC_MAX_NUM_OF_CHANNELS	2
#define SBC_MAX_NUM_OF_BLOCKS	16

#define SBC_LOUDNESS	0
#define SBC_SNR	1

#define SBC_SUB_BANDS_8	8
#define SBC_SUB_BANDS_4	4

#define SBC_sf16000	0
#define SBC_sf32000	1
#define SBC_sf44100	2
#define SBC_sf48000	3

#define SBC_MONO	0
#define SBC_DUAL	1
#define SBC_STEREO	2
#define SBC_JOINT_STEREO	3

#define SBC_BLOCK_0	4
#define SBC_BLOCK_1	8
#define SBC_BLOCK_2	12
#define SBC_BLOCK_3	16

#ifndef SBC_MAX_PACKET_LENGTH
#define SBC_MAX_PACKET_LENGTH 1000
#endif
/*constants used for index calculation*/
#define CHL	SBC_MAX_NUM_OF_SUBBANDS
#define BLK	(SBC_MAX_NUM_OF_CHANNELS*CHL)

#define DEC_VX_MINIMUM_BUFFER_SIZE (SBC_MAX_NUM_OF_SUBBANDS*SBC_MAX_NUM_OF_CHANNELS*20)

#ifndef DEC_VX_BUFFER_SIZE
#define DEC_VX_BUFFER_SIZE (DEC_VX_MINIMUM_BUFFER_SIZE+8*SBC_SUB_BANDS_8)
/*#define DEC_VX_BUFFER_SIZE DEC_VX_MINIMUM_BUFFER_SIZE*/
#endif

#ifndef SBC_ARM_OPT
#define SBC_ARM_OPT FALSE
#endif 

#ifndef SBC_C5402_OPT
#define SBC_C5402_OPT FALSE
#endif

#ifndef SBC_OPTIMIZATION
#define SBC_OPTIMIZATION TRUE
#endif 

#ifndef SBC_IPAQ_OPT
#define SBC_IPAQ_OPT FALSE
#endif 

#if (SBC_IPAQ_OPT == TRUE)
typedef __int64 SINT64;
#endif


#ifndef SBC_GKI_BUFFERBASED
#define SBC_GKI_BUFFERBASED FALSE
#endif /* SBC_GKI_BUFFERBASED */

#ifndef SBC_MINIMUM_BUFFER_COPIES
#define SBC_MINIMUM_BUFFER_COPIES FALSE
#endif

typedef struct
{
	SINT16 *scaleFactor;
	SINT16 samplingFreq;        /*16k, 32k, 44.1k or 48k*/
	SINT16 channelMode;         /*mono, dual, streo or joint streo*/
	SINT16 numOfSubBands;       /*4 or 8*/
	SINT16 numOfChannels;
	SINT16 numOfBlocks;         /*4, 8, 12 or 16*/
	SINT16 allocationMethod;    /*loudness or SNR*/
	SINT16 bitPool;             /* 16*numOfSb for mono & dual; 32*numOfSb for stereo & joint stereo */
	UINT8 join[SBC_MAX_NUM_OF_SUBBANDS];       /*0 if not joint stereo*/

	SINT16 *pcmBuffer;
#if (SBC_ARM_OPT==TRUE)
    SINT16 *sbBuffer;
#else
	SINT32 *sbBuffer;
#endif

	SINT16 *VX;
#if (SBC_ARM_OPT==FALSE && SBC_IPAQ_OPT==FALSE && SBC_OPTIMIZATION==FALSE) 
	SINT32 *scartchMemForFilter;
#endif
	SINT16 *scartchMemForBitAlloc;
    /*SINT16 *s16SecondaryPcmBuff;*/
	UINT8  *packet;
	UINT16 u16PrevPacLen;
	UINT16 u16ReaminingBytes;

	SINT32 *s32ScartchMem;
	SINT32 *s32StaticMem;

	SINT16 *bits;
    /*SINT16 s16PresentBit;*/

	UINT16 (*AllocBufferFP)(SINT16 **, UINT16); 
	UINT16 (*FillBufferFP)(UINT8 *, UINT16); 
	UINT16 (*EmptyBufferFP)(SINT16 *, UINT16);
}SBC_DEC_PARAMS;

/*FUNCTION DECLARATIONS*/
extern const SINT16 DCTcoeff4[];
extern const SINT16 DCTcoeff8[];
void SbcSynthesisFilter(SBC_DEC_PARAMS *);

#ifdef __cplusplus
extern "C"
{
#endif
SBC_API extern SINT16 SBC_Decoder(SBC_DEC_PARAMS *strDecParams);
SBC_API extern SINT16 SBC_Decoder_Init(SBC_DEC_PARAMS *strDecParams);
#ifdef __cplusplus
}
#endif


SINT16 DecUnPacking(SBC_DEC_PARAMS *strDecParams);

#if (SBC_C5402_OPT==TRUE)
    void SBC_Multiply_32_16_Simplified(SINT16 s32In2Temp,SINT32  s32In1Temp ,SINT32 *s32OutLow);
    void SBC_Multiply_64(SINT32 s32In1Temp,SINT32 s32In2Temp,SINT32 *s32OutLow,SINT32 *s32OutHi);
    void SBC_Multiply_32_32(SINT32 s32In2Temp,SINT32 s32In1Temp,SINT32 *s32OutLow);
    void SBC_Multiply_32_32_Simplified(SINT32 s32In2Temp,SINT32 s32In1Temp,SINT32 *s32OutLow);
#endif
#endif
