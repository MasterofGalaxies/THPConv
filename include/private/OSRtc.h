/*---------------------------------------------------------------------------*
  Project:  Dolphin OS RTC API
  File:     OSRtc.h

  Copyright 1998-2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/09/11 12:02:55  ooizumi
  Added RTC flags APIs.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    25    4/16/03 14:53 Shiki
    Implemented OSGetGbsMode() and OSSetGbsMode().

    24    10/29/02 9:38 Shiki
    Added gbs field to OSSramEx.

    23    11/21/01 20:41 Shiki
    Added __OSEnableBarnacle().

    22    11/12/01 12:55 Shiki
    Added OS_SRAM_EURGB60_FLAG.

    21    8/27/01 11:31 Shiki
    Added __OSSetResetButtonTimer().

    20    8/24/01 11:44 Shiki
    Added __OSTimeToSystemTime().

    19    8/06/01 9:51 Shiki
    Added OSGetWirelessID and OSSetWirelessID.

    18    01/07/06 17:43 Shiki
    Added OS_SRAM_PROGRESSIVE_FLAG.

    17    6/15/01 8:45p Hashida
    Created an area to store DVD error code.

    16    5/11/01 2:20p Shiki
    Removed OSSram.displayOffsetV.
    Added OSSram.ntd.

    15    01/03/21 17:20 Shiki
    Added OS_SRAM_FORCEMENU_FLAG.
    Removed OSSramEx.wirelessPadFixMode.

    14    01/03/09 15:05 Shiki
    Added OS_SRAM_CLOCKADJUST_FLAG.

    13    01/03/01 17:45 Shiki
    Added flashIDCheckSum in OSSramEx.

    12    2/21/01 3:43a Hashida
    Added __OSGetSystemTime

    11    01/02/13 20:16 Shiki
    Updated.

    10    01/01/30 9:26 Shiki
    displayOffsetV reverted to OSSram.

    9     12/19/00 1:10p Shiki
    Added OSSramEx.

    8     11/14/00 3:56p Shiki
    Added __OSReadROMAsync().

    7     11/14/00 2:42p Shiki
    Revised OSSram. Added __OSReadROM().

    6     9/28/00 2:39p Tian
    From Shiki : Added __OSCheckSram(), sram typedef changed.

    5     9/15/00 10:55p Hashida
    Changed the type of displayOffset* from u16 to s16.

    4     9/08/00 2:43p Shiki
    Added wirelessPadFixMode.

    3     8/23/00 6:22p Shiki
    Implemented new SRAM interface.

    2     8/21/00 4:42p Shiki
    Added typedef for OSSram.

    1     8/18/00 6:52p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSRTC_H__
#define __OSRTC_H__

#ifdef __cplusplus
extern "C" {
#endif

// OSSram.flags bits
#define OS_SRAM_VIDEO_MODE          0x03u   // 0:NTSC  1:PAL  2:MPAL (always 0 in production version)
#define OS_SRAM_SOUND_MODE          0x04u   // 0:mono  1:stereo
#define OS_SRAM_SOUND_MODE_SHIFT    2
#define OS_SRAM_BIAS_FLAG           0x08u   // 0:invalid counterBias  1: valid counterBias
#define OS_SRAM_INIT_FLAG           0x10u   // 0:not-initialized  1:initialized
#define OS_SRAM_CLOCKADJUST_FLAG    0x20u   // 0:not-adjusted  1:adjusted
#define OS_SRAM_FORCEMENU_FLAG      0x40u   // 0:normal  1:force menu
#define OS_SRAM_PROGRESSIVE_FLAG    0x80u   // 0:non-progressive  1:progressive
#define OS_SRAM_PROGRESSIVE_SHIFT   7

// OSSram.ntd bits
#define OS_SRAM_BOOT_FLAG           0x80u   // 0:NTD boot  1:EAD boot
#define OS_SRAM_EURGB60_FLAG        0x40u   // 0: 50Hz     1: 60Hz
#define OS_SRAM_EURGB60_SHIFT       6

// OSSramEx.gbs bits
#define OS_SRAMEX_GBS_PARITY        0x8000u
#define OS_SRAMEX_GBS_FRAME         0x7c00u
#define OS_SRAMEX_GBS_SIZE          0x0200u
#define OS_SRAMEX_GBS_CONTROLLER    0x0100u
#define OS_SRAMEX_GBS_PICTURE       0x00c0u
#define OS_SRAMEX_GBS_TIMER         0x003fu

#define OS_SOUND_MODE_MONO          0u
#define OS_SOUND_MODE_STEREO        1u

u32     OSGetSoundMode( void );
void    OSSetSoundMode( u32 mode );

#define OS_PROGRESSIVE_MODE_OFF     0u
#define OS_PROGRESSIVE_MODE_ON      1u

u32     OSGetProgressiveMode( void );
void    OSSetProgressiveMode( u32 on );

#define OS_LANG_ENGLISH         0u
#define OS_LANG_GERMAN          1u
#define OS_LANG_FRENCH          2u
#define OS_LANG_SPANISH         3u
#define OS_LANG_ITALIAN         4u
#define OS_LANG_DUTCH           5u

u8      OSGetLanguage( void );
void    OSSetLanguage( u8 language );

#define OS_EURGB60_OFF          0u
#define OS_EURGB60_ON           1u

u32     OSGetEuRgb60Mode( void );
void    OSSetEuRgb60Mode( u32 on );

u8      __OSGetBootMode(void);
void    __OSSetBootMode(u8 ntd);

#define OS_VIDEO_MODE_NTSC      0u
#define OS_VIDEO_MODE_PAL       1u
#define OS_VIDEO_MODE_MPAL      2u

u32  OSGetVideoMode ( void );
void OSSetVideoMode ( u32 mode );

u16  OSGetWirelessID( s32 chan );
void OSSetWirelessID( s32 chan, u16 id );

u16 OSGetGbsMode    ( void );
void OSSetGbsMode   ( u16 mode );

typedef struct OSSram
{
    u16 checkSum;           //  0:
    u16 checkSumInv;        //  2:
    u32 ead0;               //  4: EAD 0
    u32 ead1;               //  8: EAD 1
    u32 counterBias;        // 12: Bias for RTC counter.
    s8  displayOffsetH;     // 16: horizontal offset for VI.
    u8  ntd;                // 17: reserved by NTD
    u8  language;           // 18: This value is effective in only Europe version
                            //     In Japanese and American versions it is always 0.
    u8  flags;              // 19: various flags
} OSSram;   // 20 bytes

typedef struct OSSramEx
{
    u8  flashID[2][12];     // Flash security ID information.
    u32 wirelessKeyboardID; // Wireless keyboard ID information.
    u16 wirelessPadID[4];   // Wireless game pad ID information.
    u8  dvdErrorCode;       // dvd error code if dvd hits fatal error
    u8  _padding0;
    u8  flashIDCheckSum[2]; // for flashID
    u16 gbs;                // for GameBoy Player
    u8  _padding1[2];
} OSSramEx; // 44 bytes (24+4+8+2+2+4)

// Gekko Time Base
void __OSSetTick  ( OSTick newTick );
void __OSSetTime  ( OSTime newTime );

OSTime __OSGetSystemTime   ( void );
OSTime __OSTimeToSystemTime( OSTime time );

// RTC
BOOL __OSGetRTC   ( u32* rtc );
BOOL __OSSetRTC   ( u32  rtc );

BOOL __OSReadROM     ( void* buffer, s32 length, s32 offset );
BOOL __OSReadROMAsync( void* buffer, s32 length, s32 offset, void (*callback)(void) );

// RTC Flags
#define OS_RTCFLG_EJECT_MASK  0x00000001
#define OS_RTCFLG_DISCIN_MASK 0x00000002

BOOL __OSGetRTCFlags  ( u32* flags );
BOOL __OSClearRTCFlags( void );

// SRAM
void      __OSInitSram    ( void );
OSSram*   __OSLockSram    ( void );
BOOL      __OSUnlockSram  ( BOOL commit );
OSSramEx* __OSLockSramEx  ( void );
BOOL      __OSUnlockSramEx( BOOL commit );
BOOL      __OSSyncSram    ( void );
BOOL      __OSCheckSram   ( OSSram* );

void __OSSetResetButtonTimer( u8 min );

void __OSEnableBarnacle( s32 chan, u32 dev );

#ifdef __cplusplus
}
#endif

#endif  // __OSRTC_H__
