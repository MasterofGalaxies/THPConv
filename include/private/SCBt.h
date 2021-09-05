/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     SCBt.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/10/23 12:55:59  kawaset
  Added EULA, ConfigDone2. Moved SetSoundMode, SetProgressiveMode, SetEuRgb60Mode, GetWpad*, and SetWpad* to private.

  Revision 1.1  2006/08/22 00:58:59  kawaset
  Initial check-in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCBT_H__
#define __SCBT_H__

#include <private/scprivate.h>
#include <private/bte/common/buildcfg.h>
#include <private/bte/data_types.h>
#include <private/bte/bta/bd.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    BD_ADDR bd_addr;
    u8      bd_name[BTM_MAX_REM_BD_NAME_LEN];
    u8      link_key[16];
} SCBtCmpDevInfoSingle;

typedef struct {
    BD_ADDR bd_addr;
    u8      bd_name[BTM_MAX_REM_BD_NAME_LEN];
} SCBtDeviceInfoSingle;

#define SC_BT_CMPDEV_INFO_MAX 6
#define SC_BT_DEVICE_INFO_MAX 16

typedef struct {
    u8                   num;
    SCBtCmpDevInfoSingle info[SC_BT_CMPDEV_INFO_MAX];
} SCBtCmpDevInfoArray;

typedef struct {
    u8                   num;
    SCBtDeviceInfoSingle info[SC_BT_DEVICE_INFO_MAX];
} SCBtDeviceInfoArray;

extern BOOL SCGetBtCmpDevInfoArray(SCBtCmpDevInfoArray *array);
extern BOOL SCSetBtCmpDevInfoArray(const SCBtCmpDevInfoArray *array);
extern BOOL SCGetBtDeviceInfoArray(SCBtDeviceInfoArray *array);
extern BOOL SCSetBtDeviceInfoArray(const SCBtDeviceInfoArray *array);

#define SC_BT_DPD_SENSIBILITY_MIN 1
#define SC_BT_DPD_SENSIBILITY_MAX 5
extern u32 SCGetBtDpdSensibility(void);
extern BOOL SCSetBtDpdSensibility(u32 sensibility);

#define SC_WPAD_MOTOR_MODE_OFF        0u
#define SC_WPAD_MOTOR_MODE_ON         1u
#define SC_WPAD_MOTOR_MODE_DEFAULT    SC_WPAD_MOTOR_MODE_ON

extern u8 SCGetWpadMotorMode(void);
extern BOOL SCSetWpadMotorMode(u8 mode);

#define SC_WPAD_SENSOR_BAR_POSITION_LOWER   0u
#define SC_WPAD_SENSOR_BAR_POSITION_UPPER   1u
#define SC_WPAD_SENSOR_BAR_POSITION_DEFAULT SC_WPAD_SENSOR_BAR_POSITION_LOWER

extern u8 SCGetWpadSensorBarPosition(void);
extern BOOL SCSetWpadSensorBarPosition(u8 position);

#define SC_WPAD_SPEAKER_VOLUME_MIN     0u
#define SC_WPAD_SPEAKER_VOLUME_MAX     127u
#define SC_WPAD_SPEAKER_VOLUME_DEFAULT 89u

extern u8 SCGetWpadSpeakerVolume(void);
extern BOOL SCSetWpadSpeakerVolume(u8 volume);

#ifdef __cplusplus
}
#endif

#endif // __SCBT_H__
