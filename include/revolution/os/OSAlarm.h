/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Alarm API
  File:     OSAlarm.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2006/08/11 06:56:29  yasumoto_yoshitaka
  suppress padding warning

  Revision 1.4  2006/07/04 08:57:52  hiratsu
  Added OSSet/GetAlarmUserData() API.

  Revision 1.3  2006/02/14 05:29:34  hirose
  Deleted OSInitAlarm() -- now initialized in OSInit().

  Revision 1.2  2006/02/04 11:56:47  hashida
  (none)

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    8     04/02/16 10:18 Ueno_kyu
    Removed OSAlarmQueue{}.
    
    7     04/02/04 11:17 Ueno_kyu
    Modified OSAlarm{} to keep an alarm queue (for Windows).
    Added OSAlarmQueue{} (for Windows).
    
    6     8/08/02 10:33 Shiki
    Changed OSCancelAlarms() interface.

    5     8/07/02 22:03 Shiki
    Added OSSetAlarmTag() and OSCancelAlarms().

    4     01/02/05 11:20 Shiki
    Added OSCreateAlarm().

    3     01/01/30 10:06 Shiki
    Added OSSetAbsAlarm().

    2     3/16/00 7:03p Shiki
    Revised to include OSContext.h.

    4     8/30/99 4:20p Shiki
    Added OSCheckAlarmQueue().

    3     99/07/29 2:36p Shiki
    Revised to use absolute ticks instead of delta between alarms.

    2     99/07/28 9:26p Shiki
    Added OSSetPeriodicAlarm() stuff.

    1     99/07/28 6:06p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSALARM_H__
#define __OSALARM_H__

#include <revolution/types.h>
#include <revolution/os/OSContext.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSAlarm  OSAlarm;
typedef void          (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);

#ifdef  __MWERKS__
#pragma warn_padding off
#endif
struct OSAlarm
{
    OSAlarmHandler  handler;
    u32             tag;
    OSTime          fire;
    OSAlarm*        prev;
    OSAlarm*        next;

    // Periodic alarm
    OSTime          period;
    OSTime          start;

    // User data
    void*           userData;
#ifdef WIN32
    void*           queue;
#endif
};
#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

void OSSetAlarm         ( OSAlarm* alarm, OSTime tick, OSAlarmHandler handler );
void OSSetAlarmTag      ( OSAlarm* alarm, u32 tag );
void OSSetAbsAlarm      ( OSAlarm* alarm, OSTime time, OSAlarmHandler handler );
void OSSetPeriodicAlarm ( OSAlarm* alarm, OSTime start, OSTime period,
                          OSAlarmHandler handler );
void OSCreateAlarm      ( OSAlarm* alarm );
void OSCancelAlarm      ( OSAlarm* alarm );
void OSCancelAlarms     ( u32 tag );

BOOL OSCheckAlarmQueue  ( void );

void  OSSetAlarmUserData( OSAlarm* alarm, void* data );
void *OSGetAlarmUserData( const OSAlarm* alarm );


#ifdef __cplusplus
}
#endif

#endif  // __OSALARM_H__
