/*---------------------------------------------------------------------------*
  Project:  Revolution 3in1
  File:     macrovision_reg.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/02/10 11:24:05  urata
  Moved from /include/revolution/vi/ to here.

  Revision 1.1  2006/02/09 03:01:57  urata
  Initial checkin.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef _MACROVISION_REG_H_
#define _MACROVISION_REG_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct VIMacroVisionObj{
    u8 m[26];
} VIMacroVisionObj;


/*---------------------------------------------------------------------------*/
/*  Macrovidion Modes                                                        */
/*---------------------------------------------------------------------------*/
extern VIMacroVisionObj VINtscACPType1;
extern VIMacroVisionObj VINtscACPType2;
extern VIMacroVisionObj VINtscACPType3;
extern VIMacroVisionObj VIPalACPType1;
extern VIMacroVisionObj VIPalACPType2;
extern VIMacroVisionObj VIPalACPType3;
extern VIMacroVisionObj VIEurgb60ACPType1;
extern VIMacroVisionObj VIEurgb60ACPType2;
extern VIMacroVisionObj VIEurgb60ACPType3;
extern VIMacroVisionObj VIMpalACPType1;
extern VIMacroVisionObj VIMpalACPType2;
extern VIMacroVisionObj VIMpalACPType3;
extern VIMacroVisionObj VIProgressiveACPType;
extern VIMacroVisionObj VIZeroACPType;

#ifdef __cplusplus
}
#endif

#endif // _MACROVISION_REG_H_
