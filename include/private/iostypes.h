#ident "$Id: iostypes.h,v 1.7 2006-04-20 22:05:51 orest Exp $"
/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __IOSTYPES_H__
#define __IOSTYPES_H__
#include <private/ioserrno.h>

#define IOS_MESSAGE_BLOCK        0
#define IOS_MESSAGE_NOBLOCK      1

#define IOS_EVENT_AES      0
#define IOS_EVENT_SHA      1
#define IOS_EVENT_USB      2
#define IOS_EVENT_FLASH    3
#define IOS_EVENT_IPC_MSG  4
#define IOS_EVENT_IPC_ACK  5
#define IOS_EVENT_ADC      6
#define IOS_EVENT_DAC      7
#define IOS_EVENT_DI_COVER 8
#define IOS_EVENT_DI_TC    9
#define IOS_EVENT_DI_ERR   10

/* Emulation only signal definitions */
/* Should match values in /usr/include/asm/signal.h */
#define IOS_EVENT_MIN   SIGRTMIN
#define IOS_EVENT_MAX   SIGRTMAX

#define IOS_NUM_EVENTS  32 

#define IOS_SEEK_SET     0
#define IOS_SEEK_CURRENT 1
#define IOS_SEEK_END     2

#define IOS_DDR_PAGES_MAX 64
#define IOS_DDR_PAGE_SIZE 4096 /* 1k words */

#define IOS_MESSAGE_QUEUE_MAX   32

#define IOS_THREAD_MAX    32
#define IOS_PROCESS_MAX   32
#define IOS_PID_MAX       32
#define IOS_PRIORITY_MAX 127

#define IOS_TIMER_MAX 16

#define IOS_FD_MAX 128

// IPC shared memory need to be multiple of 32 bytes
#define IPC_MEM_SIZE_MULT 32


typedef s32 IOSError;                   /* Values are defined in ioserrno.h */
typedef s32 IOSThreadId;
typedef s32 IOSProcessId;

typedef s32 IOSMessageQueueId;
typedef s32 IOSMessage;
typedef s32 IOSTimerId;
typedef s32 IOSHeapId;

typedef s32 IOSInterfaceId;

typedef s32 IOSCid;
typedef s32 IOSFd;

typedef u32 IOSTime;

typedef void (*IOSEntryProc)(u32);

typedef u32 IOSEvent;

#include <private/iosrestypes.h> /* For types related to resource management */

#ifndef NULL
#define NULL 0
#endif 

#endif /*__IOSTYPES_H__*/
