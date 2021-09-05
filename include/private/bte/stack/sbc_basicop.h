/******************************************************************************
**
**  File Name:   $RCSfile: sbc_basicop.h,v $
**
**  Description: This is the interface file for sbc_basicop.c services.
**
**  Revision :   $Id: sbc_basicop.h,v 1.7 2007-10-17 00:26:08 tojo Exp $
**
**  Copyright (c) 1999-2002, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/
#ifndef SBC_BASICOP_H
#define SBC_BASICOP_H

#include <private/bte/stack/sbc_decoder.h>

#if (SBC_ARM_OPT==TRUE)
    void SBC_FastDCT8(SINT16 *x0, SINT16 *pOutVect);
    void SBC_FastDCT4(SINT16 *x0, SINT16 *pOutVect);
#else
    void SBC_FastDCT8(SINT32 *x0, SINT16 *pOutVect);
    void SBC_FastDCT4(SINT32 *x0, SINT16 *pOutVect);
#endif

#if (SBC_ARM_OPT==TRUE)
#define SBC_MULT_16_16_SIMPLIFIED(s16In2,s32In1,s32outLow) \
{\
    __asm\
    {\
        MUL s32outLow,s16In2,s32In1;\
        MOV s32outLow,s32outLow,asr 15;\
    }\
}																								
#else
#if (SBC_C5402_OPT==TRUE)
#define SBC_MULT_64(s32In1, s32In2, s32OutLow, s32OutHi) SBC_Multiply_64(s32In1,s32In2,&s32OutLow,&s32OutHi);

#define SBC_MULT_32_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow) SBC_Multiply_32_16_Simplified(s16In2,s32In1,&s32OutLow);
/*#define SBC_MULT_32_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow) s32OutLow=s16In2*s32In1;*/

#define SBC_MULT_32_32(s32In2, s32In1, s32OutLow) SBC_Multiply_32_32(s32In2,s32In1,&s32OutLow);

#define SBC_MULT_32_32_SIMPLIFIED(s32In2, s32In1, s32OutLow) SBC_Multiply_32_32(s32In2,s32In1,&s32OutLow)

#else

#if (SBC_IPAQ_OPT==TRUE)
#define SBC_MULT_64(s32In1, s32In2, s32OutLow, s32OutHi)  \
{\
        s32OutLow=(SINT32)((SINT64)s32In1*(SINT64)s32In2);\
        s32OutHi=(SINT32)(((SINT64)s32In1*(SINT64)s32In2)>>32);\
}
#define SBC_MULT_16_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow) s32OutLow=(SINT32)(((SINT32)s32In1*(SINT32)s16In2)>>15)
#define SBC_ACCU_16_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow) s32OutLow+=(SINT32)(((SINT32)s32In1*(SINT32)s16In2))
#define SBC_MULT_32_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow) s32OutLow=(SINT32)(((SINT64)s32In1*(SINT64)s16In2)>>15)
#define SBC_MULT_32_32(s32In2, s32In1, s32OutLow) s32OutLow=(SINT32)(((SINT64)s32In1*(SINT64)s32In2)>>15)
#define SBC_MULT_32_32_SIMPLIFIED(s32In2, s32In1, s32OutLow) s32OutLow=(SINT32)(((SINT64)s32In1*(SINT64)s32In2)>>32)
#else
#define SBC_MULT_64(s32In1, s32In2, s32OutLow, s32OutHi)                                \
{                                                                                       \
    \
    s32In1Temp = s32In1;                                                                \
    s32In2Temp = s32In2;                                                                \
    \
    /*If both the operands are -ve then make them +ve*/                                 \
    if( (s32In1Temp < 0) && (s32In2Temp < 0) )                                          \
{                                                                                   \
    s32In1Temp = (s32In1Temp ^ 0xFFFFFFFF) + 1;                                     \
    s32In2Temp = (s32In2Temp ^ 0xFFFFFFFF) + 1;                                     \
}                                                                                   \
    /*Mutiply two +ve numbers*/                                                         \
    if( (s32In1Temp > 0) && (s32In2Temp > 0) )                                          \
{                                                                                   \
    s32OutLow = (s32In1Temp & 0xFFFF) * (s32In2Temp & 0xFFFF);                     \
    s32OutHi = ((s32In1Temp >> 16) & 0xFFFF) * ((s32In2Temp >> 16)  & 0xFFFF);     \
    s32TempVal1 = (s32In1Temp & 0xFFFF) * ((s32In2Temp >> 16) & 0xFFFF);            \
    s32TempVal2 = ((s32In1Temp >> 16) & 0xFFFF) * (s32In2Temp & 0xFFFF);            \
    s32Carry = ( (((UINT32)(s32OutLow)>>16)&0xFFFF) + ((s32TempVal1)&0xFFFF) + ((s32TempVal2)&0xFFFF) ) >> 16;\
    s32OutLow += (s32TempVal1 << 16) + (s32TempVal2 << 16);                        \
    s32OutHi += ((s32TempVal1 >> 16) + (s32TempVal2 >> 16) + s32Carry);            \
}                                                                                   \
    /*Multiply one +ve and the other -ve number*/                                       \
    else                                                                                \
{                                                                                   \
    if(s32In1Temp < 0)                                                              \
    s32In1Temp = (s32In1Temp ^ 0xFFFFFFFF) + 1;                                 \
    else                                                                            \
    s32In2Temp = (s32In2Temp ^ 0xFFFFFFFF) + 1;                                 \
    s32OutLow = (s32In1Temp & 0xFFFF) * (s32In2Temp & 0xFFFF);                     \
    s32OutHi = ((s32In1Temp >> 16) & 0xFFFF) * ((s32In2Temp >> 16)  & 0xFFFF);     \
    s32TempVal1 = (s32In1Temp & 0xFFFF) * ((s32In2Temp >> 16) & 0xFFFF);            \
    s32TempVal2 = ((s32In1Temp >> 16) & 0xFFFF) * (s32In2Temp & 0xFFFF);            \
    s32Carry = ( (((UINT32)(s32OutLow)>>16)&0xFFFF) + ((s32TempVal1)&0xFFFF) + ((s32TempVal2)&0xFFFF) ) >> 16;\
    s32OutLow += (s32TempVal1 << 16) + (s32TempVal2 << 16);                        \
    s32OutHi += ((s32TempVal1 >> 16) + (s32TempVal2 >> 16) + s32Carry);            \
    \
    s32OutLow ^= 0xFFFFFFFF;                                                       \
    s32Carry = 0;                                                                   \
    if( ((s32OutLow & 0x80000000) == 0x80000000) && (((s32OutLow + 1) & 0x80000000) == 0x00000000) ) \
    s32Carry += 1;                                                              \
    s32OutLow += 1;                                                                \
    s32OutHi ^= 0xFFFFFFFF;                                                        \
    s32OutHi += s32Carry;                                                          \
}                                                                                   \
}
#define SBC_MULT_32_32(s32In2, s32In1, s32OutLow)             \
{  \
    s32HiTemp = 0;                                                          \
    SBC_MULT_64(s32In2,s32In1 , s32OutLow, s32HiTemp);           \
    s32OutLow   = (((s32OutLow>>15)&0x1FFFF) | (s32HiTemp << 17));          \
}
#define SBC_MULT_32_32_SIMPLIFIED(s32In2, s32In1, s32OutLow)             \
{  \
    s32In2Temp=s32In2;\
    s32In1Temp=s32In1;\
    if (s32In1Temp<0 && s32In2Temp<0)\
    {\
    s32In1Temp=(s32In1Temp^0xFFFFFFFF)+1;\
    s32In2Temp=(s32In2Temp^0xFFFFFFFF)+1;\
}\
    if (s32In1Temp>0 && s32In2Temp>0)\
    {\
    s32In2Temp=s32In2Temp;\
    s32In1Temp=s32In1Temp;\
    s32OutLow=(s32In1Temp>>16)*(s32In2Temp>>16);\
    s32OutLow+=((s32In1Temp & 0xFFFF)*(s32In2Temp>>16))>>16;\
    s32OutLow+=((s32In2Temp & 0xFFFF)*(s32In1Temp>>16))>>16;\
}\
    else\
    {\
    if(s32In1Temp < 0)\
    s32In1Temp = (s32In1Temp ^ 0xFFFFFFFF) + 1;\
    else\
    s32In2Temp = (s32In2Temp ^ 0xFFFFFFFF) + 1;\
    s32In2Temp=s32In2Temp;\
    s32In1Temp=s32In1Temp;\
    s32OutLow=(s32In1Temp>>16)*(s32In2Temp>>16);\
    s32OutLow+=((s32In1Temp & 0xFFFF)*(s32In2Temp>>16))>>16;\
    s32OutLow+=((s32In2Temp & 0xFFFF)*(s32In1Temp>>16))>>16;\
    s32OutLow=(s32OutLow^0xFFFFFFFF)+1;\
}\
}
#define SBC_MULT_32_16_SIMPLIFIED(s16In2, s32In1 , s32OutLow)												\
{                                                                                           \
    s32In1Temp = s32In1;                                                                    \
    s32In2Temp = (SINT32)s16In2;                                                                    \
    \
    /*Multiply one +ve and the other -ve number*/											\
    if(s32In1Temp < 0)																		\
{																						\
    s32In1Temp ^= 0xFFFFFFFF;															\
    s32In1Temp++;																		\
    s32OutLow= (s32In2Temp * (s32In1Temp >> 16));										\
    s32OutLow += (( s32In2Temp * (s32In1Temp & 0xFFFF)) >> 16);							\
    s32OutLow ^= 0xFFFFFFFF;															\
    s32OutLow++;																		\
}																						\
    else																					\
{																						\
    s32OutLow= (s32In2Temp * (s32In1Temp >> 16));										\
    s32OutLow += (( s32In2Temp * (s32In1Temp & 0xFFFF)) >> 16);							\
}																						\
    s32OutLow=s32OutLow<<1;																\
}
#endif
#endif
#endif
#endif
