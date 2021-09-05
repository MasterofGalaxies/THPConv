/*---------------------------------------------------------------------------*
  Project:  Revolution 3in1
  File:     vidvd.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2006/04/18 10:39:05  urata
  Defined a value to some defines.

  Revision 1.4  2006/04/07 12:32:46  urata
  Modified __VISetMacrovisionImm.

  Revision 1.3  2006/03/10 13:19:14  urata
  Changed argument format of VISetClosedCaption.

  Revision 1.2  2006/02/25 13:12:48  urata
  Changed the argument format of "VISetClosedCaption".

  Revision 1.1  2006/02/10 11:24:05  urata
  Moved from /include/revolution/vi/ to here.

  Revision 1.1  2006/02/09 03:01:57  urata
  Initial checkin.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VIDVD_H__
#define __VIDVD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <private/macrovision_reg.h>

typedef enum _VIACPType
{
    VI_ACP_OFF      = 1,
    VI_ACP_TYPE1    = 2,
    VI_ACP_TYPE2    = 3,
    VI_ACP_TYPE3    = 4
} VIACPType;


// For DVD Player
void VISetCGMS            ( u8 wd0, u8 wd1, u8 wd2 );
void VISetWSS             ( u8 gp1, u8 gp2, u8 gp3, u8 gp4 );
void VISetClosedCaption   ( u8 cc21_1, u8 cc21_2, u8 cc284_1, u8 cc284_2 );
void VISetMacrovision     ( VIACPType type );
void __VISetMacrovisionImm( VIMacroVisionObj *mparam );

BOOL VIGetCGMS            ( u8 *wd0, u8 *wd1, u8 *wd2 );
BOOL VIGetWSS             ( u8 *gp1, u8 *gp2, u8 *gp3, u8 *gp4 );

#ifdef __cplusplus
}
#endif

#endif  // __VIDVD_H__
