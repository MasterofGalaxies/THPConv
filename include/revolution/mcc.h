/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Multi channel communication API
  File:     mcc.h

  Copyright 2000 - 2001 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/02/25 08:23:05  mitu
  1st version

    
    6     8/05/02 18:22 Shiki
    Added const keywords to relevant function prototypes.

    5     5/29/02 13:13 Shiki
    Added MCC_SYSEVENT_DISCONNECT.

    4     6/18/01 4:29p Hashida
    Changed copyright informaiton.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __MCC_H__
#define __MCC_H__

// HEADER INCLUDE
// ================
#ifdef WIN32//host incluide here
#   include <windows.h>
#   include <win32/dolphin.types.h>
#else
#   include <revolution/types.h>

#ifndef MCC_TARGET
#   define MCC_TARGET
#endif

#ifndef WINAPI
#   define WINAPI
#endif

#endif

#   include <revolution/hio.h>

#ifdef __cplusplus
extern "C" {
#endif

// DEFINES
// ================
#define MCC_MAX_CHANNELS    (16)
#define MCC_BLOCK_SIZE      (8192)

// ERROR CODES
typedef enum{
    MCC_ERR_NOERR=0,
    MCC_ERR_UNINITIALIZED,      // MCC is no initialize.
    MCC_ERR_TIMEOUT,            // No responce, specified time branch.
    MCC_ERR_PING,               // PING error.
    MCC_ERR_HIO_INIT,           // Could not initialize HIO
    MCC_ERR_HIO_MAILBOX_READ,   // Could not read HIO mailbox.
    MCC_ERR_HIO_MAILBOX_WRITE,  // Could not write HIO mailbox.
    MCC_ERR_HIO_READ,           // Could not read HIO memory.
    MCC_ERR_HIO_WRITE,          // Could not write HIO memory.
    MCC_ERR_HIO_STATUS_READ,    // Could not read HIO status.

    MCC_ERR_INFO_FLUSH,         // Could not flush channelInfo.
    MCC_ERR_INFO_LOAD,          // Could not load channelInfo

    MCC_ERR_BLOCK_IS_NOT_ENOUGH,// Not enough memory block.

    MCC_ERR_INVALID_PARAMETER,  // Invarid function parameter
    MCC_ERR_INVALID_CHANNEL,    // Invalid channel parameter
    MCC_ERR_INVALID_SIZE,       // Invalid data size
    MCC_ERR_INVALID_OFFSET,       // Invalid offset parameter

    MCC_ERR_CHANNEL_OPENED,     // Channel was (already) opened.
    MCC_ERR_CHANNEL_CLOSED,     // Channel was (already) closed.
    MCC_ERR_CHANNEL_LOCKED,     // Channel was (already) locked.
    MCC_ERR_CHANNEL_UNLOCKED,   // Channel was (already) unlocked.
    MCC_ERR_CHANNEL_BUSY,       // Channel (read/write) busy.

    MCC_ERR_LAST                // Last of error index.
} MCCError;

// EXI CHANNEL
typedef enum{
    MCC_EXI_0=0,
    MCC_EXI_1,
    MCC_EXI_2
} MCCExiChannel;

// CHANNEL ID
typedef enum{
    MCC_CHANNEL_SYSTEM=0,
    MCC_CHANNEL_1,
    MCC_CHANNEL_2,
    MCC_CHANNEL_3,
    MCC_CHANNEL_4,
    MCC_CHANNEL_5,
    MCC_CHANNEL_6,
    MCC_CHANNEL_7,
    MCC_CHANNEL_8,
    MCC_CHANNEL_9,
    MCC_CHANNEL_10,
    MCC_CHANNEL_11,
    MCC_CHANNEL_12,
    MCC_CHANNEL_13,
    MCC_CHANNEL_14,
    MCC_CHANNEL_15
} MCCChannel;

// SYSTEM EVENTS
typedef enum{
    MCC_SYSEVENT_UNKNOWN=0,     // unknown event
    MCC_SYSEVENT_REBOOT,        // peer side reboot
    MCC_SYSEVENT_INITIALIZED,   // MCC initialize done
    MCC_SYSEVENT_PING,          // ping received
    MCC_SYSEVENT_PING_RESULT,   // ping result received
    MCC_SYSEVENT_FLUSH,          // update channel info
    MCC_SYSEVENT_DISCONNECT // disconnect device
} MCCSysEvent;

// CHANNEL EVENT & MASK
typedef u32 MCCEvent;
#define MCC_EVENT_UNKNOWN           0x0000 // unknown event
#define MCC_EVENT_CONNECTED         0x0001 // channel connected to peer
#define MCC_EVENT_DISCONNECTED      0x0002 // channel disconnected
#define MCC_EVENT_LOCKED            0x0004 // memory block was locked
#define MCC_EVENT_UNLOCKED          0x0008 // unlock the memory block
#define MCC_EVENT_READ_DONE         0x0010 // read data from channel was completed
#define MCC_EVENT_WRITE_DONE        0x0020 // write data from channel was completed
#define MCC_EVENT_READ_DONE_INSIDE  0x0040 // read data from channel was completed(internal)
#define MCC_EVENT_WRITE_DONE_INSIDE 0x0080 // write data from channel was completed(internal)
#define MCC_EVENT_USER              0x0100 // receive user event

// ENUM CONTROL
typedef enum{
    MCC_ENUM_STOP,      // stop enumlation devices
    MCC_ENUM_CONTINUE   // continue enumlation devices
} MCCEnum;

// MODE FOR GET FREE MEMORY BLOCKS
typedef enum{
    MCC_MODE_MIN=0,     // shortest length of free blocks
    MCC_MODE_MAX,       // longest length of free blocks
    MCC_MODE_ALL        // all number of free blocks
} MCCMode;

// WRITE PROTECT LOCK STATUS
typedef enum{
    MCC_LOCK_UNLOCKED=0,// channel write protect lock is unlocked.
    MCC_LOCK_LOCKED     // channel write protect lock is locked.
} MCCLockState;

// CHANNEL CONNECTION STATUS
typedef enum{
    MCC_CONNECT_DISCONNECT=0,   // no open each side
    MCC_CONNECT_HOST_OPEN,      // host side opend
    MCC_CONNECT_TARGET_OPEN,    // target side opend
    MCC_CONNECT_CONNECTED       // channel is connected
} MCCConnectState;

// TRANSFER MODE
typedef enum{
    MCC_SYNC=0,
    MCC_ASYNC
} MCCAsync;

// CALLBACK FUNCTION PROTOTYPES
typedef HIOEnumCallback MCCCallbackEnum;
typedef void(WINAPI* MCCCallbackSysEvent)( MCCSysEvent event );
typedef void(WINAPI* MCCCallbackEvent)( MCCChannel chID, MCCEvent event, u32 value );

// CHANNEL INFORMATION
typedef struct {
    u8  firstBlock;     // top of memory block
    u8  blockLength;    // number of memory blocks
    u8  connect;        // connection status(MCCConnectState)
    u8  isLocked;       // write protect
} MCCChannelInfo;

// PUBLIC FUNCTION PROTOTYPES
// ================
BOOL WINAPI MCCInit        ( MCCExiChannel exiChannel, u8 timeout, MCCCallbackSysEvent callbackSysEvent );
void WINAPI MCCExit        ( void );
BOOL WINAPI MCCPing        ( void );
BOOL WINAPI MCCEnumDevices ( MCCCallbackEnum callbackEnumDevices );

u8   WINAPI MCCGetFreeBlocks            ( MCCMode mode );
u8   WINAPI MCCGetLastError            ( void );
BOOL WINAPI MCCNotify                  ( MCCChannel chID, u32 notify );
MCCEvent WINAPI MCCSetChannelEventMask ( MCCChannel chID, MCCEvent event );
BOOL WINAPI MCCGetChannelInfo          ( MCCChannel chID, MCCChannelInfo *info );
BOOL WINAPI MCCGetConnectionStatus     ( MCCChannel chID, MCCConnectState *connect );

BOOL WINAPI MCCOpen            ( MCCChannel chID, u8 blockSize, MCCCallbackEvent callbackEvent );
BOOL WINAPI MCCClose           ( MCCChannel chID );
BOOL WINAPI MCCLock            ( MCCChannel chID );
BOOL WINAPI MCCUnlock          ( MCCChannel chID );
BOOL WINAPI MCCRead            ( MCCChannel chID, u32 offset, void *data, s32 size, MCCAsync async );
BOOL WINAPI MCCWrite           ( MCCChannel chID, u32 offset, const void *data, s32 size, MCCAsync async );
BOOL WINAPI MCCCheckAsyncDone  ( void );

//  MCC STREAM API
BOOL WINAPI MCCStreamOpen   ( MCCChannel chID, u8 blockSize );
BOOL WINAPI MCCStreamClose  ( MCCChannel chID );
u32  WINAPI MCCStreamRead   ( MCCChannel chID, void *data );
BOOL WINAPI MCCStreamWrite  ( MCCChannel chID, const void *data, u32 dataBlockSize );

#ifdef __cplusplus
}
#endif

#endif  // __MCC_H__
