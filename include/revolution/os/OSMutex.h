/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Mutex API
  File:     OSMutex.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphin�V�[�X�c���[����ڐA

    
    4     1/27/00 2:57p Shiki
    Added /link/ member in OSMutex for implementing BPI protocol.

    2     1/25/00 6:42p Shiki
    Clean up.

    1     1/18/00 6:16p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSMUTEX_H__
#define __OSMUTEX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/os/OSThread.h>

struct OSMutex
{
    OSThreadQueue   queue;
    OSThread*       thread; // the current owner
    s32             count;  // lock count
    OSMutexLink     link;   // for OSThread.queueMutex
};

struct OSCond
{
    OSThreadQueue   queue;
};

void OSInitMutex   ( OSMutex* mutex );
void OSLockMutex   ( OSMutex* mutex );
void OSUnlockMutex ( OSMutex* mutex );
BOOL OSTryLockMutex( OSMutex* mutex );
void OSInitCond    ( OSCond* cond );
void OSWaitCond    ( OSCond* cond, OSMutex* mutex );
void OSSignalCond  ( OSCond* cond );

#ifdef __cplusplus
}
#endif

#endif  // __OSMUTEX_H__
