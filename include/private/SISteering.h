/*---------------------------------------------------------------------------*
  Project:  SI Steering Wheel API
  File:     SISteering.h

  Copyright (C) 2001-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

    2     8/22/02 11:48 Shiki
    Set #pragma warn_padding off.

    1     4/01/02 16:30 Shiki
    Initial NTD check-in from IRD.

    5     4/01/02 16:18 Shiki
    Reversed the definitions of drive and standby.

    4     2/27/02 13:54 Shiki
    Added SI_STEERING_TRIGGER_Z.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SI_STEERING_H__
#define __SI_STEERING_H__

#include <revolution/os.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (* SISteeringCallback )        (s32 chan, s32 ret);
typedef void (* SISteeringSamplingCallback )(void);

#ifdef  __MWERKS__
#pragma warn_padding off
#endif

typedef struct SISteeringStatus
{
    u16 button;                 // Or-ed SI_STEERING_BUTTON_* bits
    u8  misc;
    s8  steering;
    u8  gas;
    u8  brake;
    u8  left;
    u8  right;
    s8  err;                    // one of SI_STEERING_ERR_* number
} SISteeringStatus;

#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

//
// Steering button bits
//
#define SI_STEERING_BUTTON_LEFT         0x0001
#define SI_STEERING_BUTTON_RIGHT        0x0002
#define SI_STEERING_BUTTON_DOWN         0x0004
#define SI_STEERING_BUTTON_UP           0x0008
#define SI_STEERING_TRIGGER_Z           0x0010
#define SI_STEERING_TRIGGER_R           0x0020
#define SI_STEERING_TRIGGER_L           0x0040
#define SI_STEERING_BUTTON_A            0x0100
#define SI_STEERING_BUTTON_B            0x0200
#define SI_STEERING_BUTTON_X            0x0400
#define SI_STEERING_BUTTON_Y            0x0800
#define SI_STEERING_BUTTON_START        0x1000

#define SI_STEERING_MISC_MTR_EN         0x01
#define SI_STEERING_MISC_MTR_BK         0x02
#define SI_STEERING_MISC_POWER          0x04    // Set when 24V power is available
#define SI_STEERING_MISC_PEDAL          0x08    // Set when pedal unit is connected

//
// Steering function control code
//
#define SI_STEERING_CONTROL_BRAKE       0x000
#define SI_STEERING_CONTROL_STANDBY     0x400
#define SI_STEERING_CONTROL_DRIVE       0x600
#define SI_STEERING_CONTROL_MASK        0x600


//
// Steering function error code
//
#define SI_STEERING_ERR_READY           0
#define SI_STEERING_ERR_NO_CONTROLLER   -1
#define SI_STEERING_ERR_BUSY            -2
#define SI_STEERING_ERR_TRANSFER        -3
#define SI_STEERING_ERR_FATAL           -128

void SIInitSteering            ( void );

s32  SIResetSteering           ( s32 chan );
s32  SIResetSteeringAsync      ( s32 chan, SISteeringCallback callback );

s32  SIReadSteering            ( s32 chan, SISteeringStatus* status );

void SIControlSteering         ( s32 chan, u32 control, s32 level );

SISteeringSamplingCallback
     SISetSteeringSamplingCallback( SISteeringSamplingCallback callback );

#ifdef __cplusplus
}
#endif

#endif  // __SI_STEERING_H__
