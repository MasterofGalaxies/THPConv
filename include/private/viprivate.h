/*---------------------------------------------------------------------------*
  Project:  Dolphin VI private API
  File:     viprivate.h

  Copyright 2000 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.10  2007/05/22 01:55:05  urata
  Added 50Hz progressive functions for DVD test.

  Revision 1.9  2006/11/29 00:16:03  urata
  Added VIResetDimmingCount.

  Revision 1.8  2006/10/27 00:31:31  urata
  Moved VIEnableDimming to "vi/vifuncs.h".

  Revision 1.7  2006/10/24 12:24:22  urata
  Added "VIEnableDimming" from vifuncs.h.

  Revision 1.6  2006/09/14 12:48:14  urata
  Added __VIResetDev*Idle and __VIDisableDimming.

  Revision 1.5  2006/09/14 04:34:26  urata
  Added VIGetDVDStopMotorCount.

  Revision 1.4  2006/09/06 12:15:50  urata
  Added VIEnableDVDStopMotor from vifuncs.h

  Revision 1.3  2006/08/28 23:48:08  urata
  Added __VIReset[SI/RF]Idle.

  Revision 1.2  2006/08/28 12:22:38  urata
  Added some functions for VIDimming and DVDStopMotor.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    5     03/03/07 18:26 Yasu
    Added __VIGetLatchPosition
    
    4     03/03/04 9:57 Yasu
    Added ray-gun control functions
    
    3     03/02/27 16:32 Hashida
    Added hct/vct -> x/y conversion function.
    
    2     03/02/27 11:43 Hashida
    Added position interrupt functions.
    
    1     9/16/00 2:52a Hashida
    Initial revision
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VIPRIVATE_H__
#define __VIPRIVATE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define VI_TVMODE_PAL_PROG   (VITVMode)6

extern GXRenderModeObj GXPal528Prog;
extern GXRenderModeObj GXPal528ProgSoft;
extern GXRenderModeObj GXPal524ProgAa;

void __VISetAdjustingValues( s16 x, s16 y );
void __VIGetAdjustingValues( s16* x, s16* y );


typedef void (*VIPositionCallback)(s16 x, s16 y);
void __VIEnableRawPositionInterrupt                 ( s16 x, s16 y, VIPositionCallback callback );
VIPositionCallback __VIDisableRawPositionInterrupt  ( void );

void __VIDisplayPositionToXY    ( u32 hct, u32 vct, s16 *x, s16 *y );
void __VIGetCurrentPosition     ( s16 *x, s16 *y );
void __VISetLatchMode           ( u32 mode );
BOOL __VIGetLatch0Position      ( s16 *px, s16 *py );
BOOL __VIGetLatch1Position      ( s16 *px, s16 *py );
BOOL __VIGetLatchPosition       ( u32 port, s16 *px, s16 *py );


u32 __VISetDVDStopMotorCountLimit   ( u32 new_limit );
BOOL VIEnableDVDStopMotor           ( BOOL enable );
u32  VIGetDVDStopMotorCount         ( void );
int __VISetAutoDimming              ( BOOL enable );
BOOL VIResetDimmingCount            ( void );
u32 __VISetDimmingCountLimit        ( u32 new_limit );
void __VIDisableDimming             ( void );
BOOL __VIResetSIIdle                ( void );
BOOL __VIResetRFIdle                ( void );
BOOL __VIResetDev0Idle              ( void );
BOOL __VIResetDev1Idle              ( void );
BOOL __VIResetDev2Idle              ( void );
BOOL __VIResetDev3Idle              ( void );
BOOL __VIResetDev4Idle              ( void );
BOOL __VIResetDev5Idle              ( void );
BOOL __VIResetDev6Idle              ( void );
BOOL __VIResetDev7Idle              ( void );
BOOL __VIResetDev8Idle              ( void );
BOOL __VIResetDev9Idle              ( void );
#ifdef __cplusplus
}
#endif

#endif  // __VIPRIVATE_H__
