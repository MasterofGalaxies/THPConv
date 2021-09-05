/*---------------------------------------------------------------------------*
  Project:      Revolution OS private Reset API
  File:         OSResetPrivate.h

  Copyright (C) 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
 *---------------------------------------------------------------------------*/

#ifndef __OSRESETPRIVATE_H__
#define __OSRESETPRIVATE_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OS_SYSLAUNCH_DEFAULT       0x00000000
#define OS_SYSLAUNCH_SETTING       0x00000001

#define OS_SYSLAUNCH_URL_CALENDAR  "Calendar/Calendar_index.html"
#define OS_SYSLAUNCH_URL_DISPLAY   "Display/Display_index.html"
#define OS_SYSLAUNCH_URL_SOUND     "Sound/Sound_index.html"
#define OS_SYSLAUNCH_URL_PARENTAL  "Parental_Control/Parental_Control_index.html"
#define OS_SYSLAUNCH_URL_INTERNET  "Internet/Internet_index.html"
#define OS_SYSLAUNCH_URL_WC24      "WiiConnect24/Wiiconnect24_index.html"
#define OS_SYSLAUNCH_URL_UPDATE    "Update/Update_index.html"

void __OSReturnToMenuv(u32 LaunchCode, char* const argv[]);
void __OSReturnToMenul(u32 LaunchCode, const char* arg0, .../*, (char*)NULL */);

#ifdef __cplusplus
}
#endif

#endif // __OSRESETPRIVATE_H__
