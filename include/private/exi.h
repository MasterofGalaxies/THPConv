/*---------------------------------------------------------------------------*
  Project:  Dolphin Expansion Interface API
  File:     exi.h

  Copyright 1998-2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
 * 
 * 1     05/10/11 10:57 Yone
 * Initial check-in by HUDSON.
    
    14    3/10/03 11:34 Shiki
    Defined EXI_BARNACLE_ENABLER.

    13    10/28/02 10:43 Shiki
    Added EXI_NET_CARD_1019 and EXI_NET_CARD_2043.

    12    1/22/02 16:50 Shiki
    Added EXI_ETHER_VIEWER.

    11    10/18/01 13:47 Shiki
    Added exi private device type names.

    10    5/21/01 9:42a Shiki
    Fixed EXI_STATE_BUSY definition.

    9     01/01/25 10:11 Shiki
    Added EXIGetState() and EXIGetID().

    8     11/08/00 5:08p Shiki
    Removed proprietary functions.

    7     10/03/00 9:45a Hashida
    From Shiki: Added EXIProbeEx().

    6     9/12/00 10:44p Shiki
    Added EXIProbeReset().

    5     7/14/00 3:55p Shiki
    Added EXIDetach() and EXIImmEx().

    4     4/26/00 8:50p Shiki
    Revised EXILock interface.

    3     4/21/00 5:31p Shiki
    Added EXILock/EXIUnlock.

    2     1/24/00 2:13p Shiki
    Minor revision.

    2     9/30/99 5:06p Shiki
    EXISync() returns an BOOL value.

    1     9/23/99 3:56p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __EXI_H__
#define __EXI_H__

#include <dolphin/os.h>

#ifdef __cplusplus
extern "C" {
#endif

//
// Private EXI device types
//

#define EXI_ETHER_PROTO0        0x04220000
#define EXI_ETHER_VIEWER        0x04220001
#define EXI_ETHER_PROTO1        0x04020100
#define EXI_ETHER_PROTO2        0x04020200
#define EXI_ETHER_PROTO3        0x04020300

#define EXI_RS232C              0x04040404
#define EXI_MIC                 0x04060000
#define EXI_AD16                0x04120000
#define EXI_STREAM_HANGER       0x04130000
#define EXI_BARNACLE_ENABLER    0x07010000

#define EXI_NET_CARD_59         0x80000004
#define EXI_NET_CARD_123        0x80000008
#define EXI_NET_CARD_251        0x80000010
#define EXI_NET_CARD_507        0x80000020
#define EXI_NET_CARD_1019       0x80000040
#define EXI_NET_CARD_2043       0x80000080

typedef void (*EXICallback)(s32 chan, OSContext* context);

#define EXI_FREQ_1M     0
#define EXI_FREQ_2M     1
#define EXI_FREQ_4M     2
#define EXI_FREQ_8M     3
#define EXI_FREQ_16M    4
#define EXI_FREQ_32M    5

#define EXI_READ        0
#define EXI_WRITE       1
#define EXI_RDWR        2

#define EXI_STATE_IDLE          0x00
#define EXI_STATE_DMA           0x01
#define EXI_STATE_IMM           0x02
#define EXI_STATE_BUSY          (EXI_STATE_DMA | EXI_STATE_IMM)
#define EXI_STATE_SELECTED      0x04
#define EXI_STATE_ATTACHED      0x08    // for dev 0 (CS0B == 1)
#define EXI_STATE_LOCKED        0x10

void        EXIInit           ( void );
BOOL        EXISelect         ( s32 chan, u32 dev, u32 freq );
BOOL        EXIDeselect       ( s32 chan );
EXICallback EXISetExiCallback ( s32 chan, EXICallback exiCallback );
BOOL        EXIProbe          ( s32 chan );
s32         EXIProbeEx        ( s32 chan );
void        EXIProbeReset     ( void );
BOOL        EXIAttach         ( s32 chan, EXICallback extCallback );
BOOL        EXIDetach         ( s32 chan );
BOOL        EXIDma            ( s32 chan, void* buf, s32 len, u32 type,
                                EXICallback callback );
BOOL        EXIImm            ( s32 chan, void* buf, s32 len, u32 type,
                                EXICallback callback );
BOOL        EXIImmEx          ( s32 chan, void* buf, s32 len, u32 mode );
BOOL        EXISync           ( s32 chan );
u32         EXIClearInterrupts( s32 chan, BOOL exi, BOOL tc, BOOL ext );

BOOL        EXILock           ( s32 chan, u32 dev, EXICallback unlockedCallback );
BOOL        EXIUnlock         ( s32 chan );

u32         EXIGetState       ( s32 chan );
s32         EXIGetID          ( s32 chan, u32 dev, u32* id );

#ifdef __cplusplus
}
#endif

#endif  // __EXI_H__
