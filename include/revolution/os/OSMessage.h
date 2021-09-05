/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Message API
  File:     OSMessage.h

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

    
    4     2/08/00 3:32p Shiki
    Fixed OSSendMessage/OSJamMessage interface.

    2     1/25/00 6:29p Shiki
    Renamed flag defines.

    1     1/18/00 3:25p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSMESSAGE_H__
#define __OSMESSAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/os/OSThread.h>

typedef struct OSMessageQueue   OSMessageQueue;
typedef void*                   OSMessage;

struct OSMessageQueue
{
    OSThreadQueue   queueSend;
    OSThreadQueue   queueReceive;
    OSMessage*      msgArray;
    s32             msgCount;
    s32             firstIndex;
    s32             usedCount;
};

// Flags to turn blocking on/off when sending/receiving message
#define OS_MESSAGE_NOBLOCK  0
#define OS_MESSAGE_BLOCK    1

void OSInitMessageQueue( OSMessageQueue* mq, OSMessage* msgArray, s32 msgCount );
BOOL OSSendMessage     ( OSMessageQueue* mq, OSMessage msg, s32 flags );
BOOL OSJamMessage      ( OSMessageQueue* mq, OSMessage msg, s32 flags );
BOOL OSReceiveMessage  ( OSMessageQueue* mq, OSMessage* msg, s32 flags );

#ifdef __cplusplus
}
#endif

#endif  // __OSMESSAGE_H__
