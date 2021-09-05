/*---------------------------------------------------------------------------*
  Project:  Revolution OS - WPAD 
  File:     wpadBalance.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2007/05/31 09:30:12  tojo
  Added WPAD_BLCMD_BAT.

  Revision 1.3  2007/05/30 08:01:43  tojo
  Changed the api spec of WPADSet/GetBLCalibration().

  Revision 1.2  2007/05/30 02:03:52  tojo
  Redesigned the whole balance checker code according to changing the spec.

  Revision 1.1  2007/03/30 06:42:20  tojo
  initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WPAD_BALANCE_H__
#define __WPAD_BALANCE_H__

#include <revolution/wpad.h> 

#ifdef __cplusplus
extern "C" {
#endif

#define WPAD_PRESS_UNITS            4
#define WPAD_DEV_BALANCE_CHECKER    3
#define WPAD_FMT_BALANCE_CHECKER    12      // buttons + balance checker

typedef struct WPADBLStatus
{
    u16       button;                       // Or-ed WPAD_BUTTON_* bits
    s16       accX;                         // -WPAD_ACC_RESO/2 <= accX < WPAD_ACC_RESO/2
    s16       accY;                         // -WPAD_ACC_RESO/2 <= accY < WPAD_ACC_RESO/2
    s16       accZ;                         // -WPAD_ACC_RESO/2 <= accZ < WPAD_ACC_RESO/2
    DPDObject obj[WPAD_DPD_MAX_OBJECTS];

    u8        dev;                          // one of WPAD_DEV_* number
    s8        err;                          // one of WPAD_ERR_* number

    u16       press[WPAD_PRESS_UNITS];
    s8        temp;                         // temperature
    u8        battery;                      // battery

} WPADBLStatus;

#define WPAD_BLCMD_ON               0xaa
#define WPAD_BLCMD_OFF              0x55
#define WPAD_BLCMD_UPDATE_TEMP      0x00

extern s32  WPADControlBLC( s32 chan, u8  command, WPADCallback callback );

#define WPAD_BLCLB_BLK1_ADDR        0x0024
#define WPAD_BLCLB_BLK1_LEN         16
#define WPAD_BLCLB_BLK2_ADDR        0x0034
#define WPAD_BLCLB_BLK2_LEN         8
#define WPAD_BLCLB_BLK3_ADDR        0x003c
#define WPAD_BLCLB_BLK3_LEN         4
#define WPAD_BLCLB_BLK4_ADDR        0x0050
#define WPAD_BLCLB_BLK4_LEN         16
#define WPAD_BLCLB_BLK5_ADDR        0x0060
#define WPAD_BLCLB_BLK5_LEN         16

extern s32  WPADGetBLCalibration( s32 chan, u8 *data, u16 addr, u16 len, WPADCallback callback );

#ifndef WPAD_DEVDB_API
#define WPAD_DEVDB_API

#define WPAD_DEV_KEY_LEN        16
#define WPAD_DEV_NAME_LEN       64

extern void WPADGetDeviceKey  ( s32 chan, u8 *key  );
extern void WPADGetDeviceName ( s32 chan, u8 *name );
extern BOOL WPADRegisterDevice( u8 *addr, u8 *key, u8 *name );
#endif // WPAD_DEVDB_API

#ifdef __cplusplus
}
#endif
#endif // __WPAD_BALANCE_H__