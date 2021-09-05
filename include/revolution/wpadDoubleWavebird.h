/*---------------------------------------------------------------------------*
  Project:     WPAD library (Wavebird-based)
  File:        wpadDoubleWavebird.h
  Programmers: TOKUNAGA, Yasuhiro
               HIRATSU Daisuke
               FUKUDA Takahiro

  Copyright (C) 2005-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/03/31 04:53:32  hiratsu
  Initial check-in.
  This WPAD library is designed for Wavebird-based UI tool.

 *---------------------------------------------------------------------------*/

#ifndef __WPAD_H__
#define __WPAD_H__

#include <revolution/types.h>
#include <revolution/os.h>

#ifdef __cplusplus
extern "C" {
#endif


#define WPAD_CHAN0                0
#define WPAD_CHAN1                1

#define WPAD_MAX_CONTROLLERS      2

#define WPAD_MOTOR_STOP           0
#define WPAD_MOTOR_RUMBLE         1

#define WPAD_BUTTON_HOME     0x0001
#define WPAD_BUTTON_SELECT   0x0002
#define WPAD_BUTTON_A        0x0004
#define WPAD_BUTTON_B        0x0008
#define WPAD_BUTTON_SMALL_A  0x0010
#define WPAD_BUTTON_SMALL_B  0x0020
#define WPAD_BUTTON_START    0x0100
#define WPAD_BUTTON_UP       0x0200
#define WPAD_BUTTON_DOWN     0x0400
#define WPAD_BUTTON_RIGHT    0x0800
#define WPAD_BUTTON_LEFT     0x1000
#define WPAD_BUTTON_Z1       0x2000
#define WPAD_BUTTON_Z2       0x4000
#define WPAD_BUTTON_X        WPAD_BUTTON_SMALL_A
#define WPAD_BUTTON_Y        WPAD_BUTTON_SMALL_B
#define WPAD_TRIGGER_Z       WPAD_BUTTON_Z1
#define WPAD_TRIGGER_R       WPAD_BUTTON_Z2
#define WPAD_TRIGGER_L       0x8000


#define WPAD_DPD_MAX_OBJECTS      4
#define WPAD_DPD_ANGLE           42.0f  // viewing angle
#define WPAD_DPD_IMG_RESO_WX   1024     // DPD image resolution 
#define WPAD_DPD_IMG_RESO_WY    768

#define WPAD_ACC_RESO          1024     // accelerometer resolution
#define WPAD_ACC_1G_VALUE       205     // gravity value

#define WPAD_FS_STICK_RESO      256     // stick resolution of FreeStyle unit
#define WPAD_FS_ACC_RESO        256     // accelerometer resolution of FreeStyle unit
#define WPAD_FS_ACC_1G_VALUE     51     // gravity value of FreeStyle unit

#define WPAD_DEV_CORE             0
#define WPAD_DEV_FREESTYLE        1
#define WPAD_DEV_DOLPHIN        254
#define WPAD_DEV_UNKNOWN        255
#define WPAD_DEV_NOT_FOUND      253     // For backwards compatibility. Don't use.

#define WPAD_FMT_CORE             0     // data format of Core controller 
#define WPAD_FMT_FREESTYLE        1     // data format of FreeStyle controller 
#define WPAD_FMT_DOLPHIN        255     // data format of Dolphin controller(for debug) 


#define WPAD_ERR_NONE             0
#define WPAD_ERR_NO_CONTROLLER   -1
#define WPAD_ERR_BUSY            -2
#define WPAD_ERR_TRANSFER        -3
#define WPAD_ERR_INVALID         -4

typedef struct DPDObject
{
    s16       x;                    // 0 <=  x   < WPAD_DPD_IMG_RESO_WX
    s16       y;                    // 0 <=  y   < WPAD_DPD_IMG_RESO_WY
    u16       size;
    u8        traceId;
} DPDObject;

typedef struct WPADStatus
{
    u16       button;               // Or-ed WPAD_BUTTON_* bits
    s16       accX;                 // -WPAD_ACC_RESO/2 <= accX < WPAD_ACC_RESO/2
    s16       accY;                 // -WPAD_ACC_RESO/2 <= accY < WPAD_ACC_RESO/2
    s16       accZ;                 // -WPAD_ACC_RESO/2 <= accZ < WPAD_ACC_RESO/2
    DPDObject obj[WPAD_DPD_MAX_OBJECTS];

    u8        dev;                  // one of WPAD_DEV_* number
    s8        err;                  // one of WPAD_ERR_* number
} WPADStatus;

typedef struct WPADFSStatus
{
    u16       button;               // Or-ed WPAD_BUTTON_* bits
    s16       accX;                 // -WPAD_ACC_RESO/2 <= accX < WPAD_ACC_RESO/2
    s16       accY;                 // -WPAD_ACC_RESO/2 <= accY < WPAD_ACC_RESO/2
    s16       accZ;                 // -WPAD_ACC_RESO/2 <= accZ < WPAD_ACC_RESO/2
    DPDObject obj[WPAD_DPD_MAX_OBJECTS];

    s16       fsAccX;               // -WPAD_FS_ACC_RESO/2 <= fsAccX < WPAD_ACC_RESO/2
    s16       fsAccY;               // -WPAD_FS_ACC_RESO/2 <= fsAccY < WPAD_ACC_RESO/2
    s16       fsAccZ;               // -WPAD_FS_ACC_RESO/2 <= fsAccZ < WPAD_ACC_RESO/2
    s8        fsStickX;             // -WPAD_FS_STICK_RESO/2 <= fsStickX < WPAD_FS_STICK_RESO/2
    s8        fsStickY;             // -WPAD_FS_STICK_RESO/2 <= fsStickY < WPAD_FS_STICK_RESO/2

    u8        dev;                  // one of WPAD_DEV_* number
    s8        err;                  // one of WPAD_ERR_* number
} WPADFSStatus;

typedef void   ( *WPADSamplingCallback )( s32 chan );


#define WPADButtonDown( buttonLast, button )   \
    ( (u16) (((buttonLast) ^ (button)) & (button)) )

#define WPADButtonUp( buttonLast, button )   \
    ( (u16) (((buttonLast) ^ (button)) & (buttonLast)) )

#define WPADStartMotor( chan )  WPADControlMotor( ( chan ), WPAD_MOTOR_RUMBLE )
#define WPADStopMotor( chan )   WPADControlMotor( ( chan ), WPAD_MOTOR_STOP   )

void WPADInit                ( void );
s32  WPADProbe               ( s32 chan, u32 *type );
BOOL WPADAttach              ( s32 chan );
void WPADSetDataFormat       ( s32 chan, u32 fmt );
u32  WPADGetDataFormat       ( s32 chan );
void WPADRead                ( s32 chan, void *status );
void WPADSetAutoSamplingBuf  ( s32 chan, void *buf, u32 length);
void WPADControlMotor        ( s32 chan, u32 command );
u32  WPADGetLatestIndexInBuf ( s32 chan );
void WPADClampStick          ( u32 fmt, void *status );
BOOL WPADRecalibrate         ( s32 chan );
WPADSamplingCallback WPADSetSamplingCallback( s32 chan, WPADSamplingCallback callback );

#ifdef __cplusplus
}
#endif


#endif // __WPAD_H__
