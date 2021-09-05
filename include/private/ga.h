/*---------------------------------------------------------------------------*
  Project:  Revolution general abstraction layer
  File:     ga.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2007/11/15 10:32:40  ooizumi
  Changed several APIs prototypes.
  Supported queueing (optional).

  Revision 1.1  2007/11/02 00:30:59  ooizumi
  Initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __GA_H__
#define __GA_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef s32          GAHandle;
typedef u32          GAState;

/*---------------------------------------------------------------------------*
  Name:         GAStateFunction

  Description:  

  Arguments:    block

  Returns:      Next state.
 *---------------------------------------------------------------------------*/
typedef void  ( * GAStateFunction )( void* block );

typedef struct GAStateObject GAStateObject;
struct GAStateObject
{
    GAStateFunction stateFunc;
};

typedef struct GAQueueObject GAQueueObject;
struct GAQueueObject
{
    GAQueueObject*  next;
    GAQueueObject*  prev;
};

typedef struct GAObject GAObject;
struct GAObject
{
    GAObject*        next;
    GAObject*        prev;

    // for state transition manager
    u32              stateNum;
    GAStateObject*   stateObj;
    GAState          current;

    // for queuing
    u32              queueNum;
    GAQueueObject*   queueObj;

    // ...

};

void      GAInit(void);

GAHandle  GARegisterObject(GAObject* obj);
GAObject* GAGetObjectFromHandle(GAHandle handle);

BOOL      GARegisterStateObject(GAHandle handle, GAStateObject* stateObj, u32 stateNum);
void      GATransitState(GAHandle handle, GAState state, void* block);
GAState   GAGetState(GAHandle handle);

BOOL           GARegisterQueueObject(GAHandle handle, GAQueueObject* queueObj, u32 queueNum);
void           GAClearWaitingQueue(GAHandle handle, u32 index);
BOOL           GAPushWaitingQueue(GAHandle handle, u32 index, GAQueueObject* obj);
GAQueueObject* GAPopWaitingQueue(GAHandle handle, u32 index);
BOOL           GACheckWaitingQueue(GAHandle handle, u32 index);
GAQueueObject* GAGetNextWaitingQueue(GAHandle handle, u32 index);
BOOL           GADequeueWaitingQueue(GAHandle handle, GAQueueObject* obj);
BOOL           GAIsBlockInWaitingQueue(GAHandle handle, u32 index, GAQueueObject* obj);
void           GADumpWaitingQueue(GAHandle handle); // for debug

#ifdef __cplusplus
}
#endif

#endif // __GA_H__
