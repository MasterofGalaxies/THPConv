/*---------------------------------------------------------------------------*
  Project:  Serial Interface API
  File:     si.h

  Copyright (C) 1998-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

    10    10/25/01 18:25 Shiki
    To support multiple auto mode serial devices, modified SIGetStatus() to
    check just a single channel at a time.

    9     9/07/01 22:10 Shiki
    Added SIIsChanBusy().

    8     9/03/01 17:02 Shiki
    Added SIGetType(), etc.
    7     5/21/01 1:13p Shiki
    Added SIBusy().

    6     01/03/22 11:42 Shiki
    Added SIGetCommand().

    5     01/01/30 14:11 Shiki
    Changed SITransfer() interface.

    4     3/21/00 5:39p Shiki
    Added SI_CHAN* defines.

    3     3/10/00 3:34p Shiki
    Added SITransferCommands().

    2     2/09/00 7:23p Shiki
    Changed SITransfer param order.

    4     9/23/99 4:58p Shiki
    Changed type of chan from u32 to s32.

    3     9/14/99 7:03p Shiki
    Revised.

    2     9/08/99 4:06p Shiki
    Revised SISetCommand() interface.

    1     9/07/99 7:59p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SI_H__
#define __SI_H__

#include <revolution/types.h>
#include <revolution/os.h>
#include <revolution/os/OSSerial.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (* SICallback )(s32 chan, u32 sr, OSContext* context);
typedef void (* SITypeAndStatusCallback )(s32 chan, u32 type);

typedef struct SIPacket
{
    s32        chan;
    void*      output;
    u32        outputBytes;
    void*      input;
    u32        inputBytes;
    SICallback callback;
    OSTime     fire;
} SIPacket;

void SIInit      ( void );
u32  SIGetStatus ( s32 chan );

BOOL SIBusy      ( void );
BOOL SIIsChanBusy( s32 chan );

BOOL SITransfer  ( s32        chan,
                   void*      output,
                   u32        outputBytes,
                   void*      input,
                   u32        inputBytes,
                   SICallback callback,
                   OSTime     delay);
u32  SISync      ( void );

void SISetCommand            ( s32 chan, u32 command );
u32  SIGetCommand            ( s32 chan );
void SITransferCommands      ( void );
u32  SISetXY                 ( u32 x, u32 y );
u32  SIEnablePolling         ( u32 poll );
u32  SIDisablePolling        ( u32 poll );
BOOL SIGetResponse           ( s32 chan, void* data );

BOOL SIRegisterPollingHandler  ( __OSInterruptHandler handler );
BOOL SIUnregisterPollingHandler( __OSInterruptHandler handler );

u32   SIGetType     ( s32 chan );
u32   SIGetTypeAsync( s32 chan, SITypeAndStatusCallback callback );
u32   SIDecodeType  ( u32 type );

#ifdef __cplusplus
}
#endif

#endif  // __SI_H__
