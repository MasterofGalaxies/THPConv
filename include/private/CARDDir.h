/*---------------------------------------------------------------------------*
  Project:  Dolphin CARD API private routines
  File:     CARDDir.h

  Copyright 2000-2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    13    4/02/03 15:23 Shiki
    Clean up.

    12    2/12/03 16:27 Shiki
    Defined CARD_DIR_PERM_GLOBAL and CARD_DIR_PERM_COMPANY.

    11    8/05/02 15:49 Shiki
    Added const keywords to relevant function prototypes.

    10    2/01/02 15:18 Shiki
    Added __CARDFreq.

    9     10/25/01 21:05 Shiki
    Added  __CARDFormatRegion[Async].

    8     10/22/01 11:16 Shiki
    Added __CARDRawErase[Async]().

    7     8/27/01 11:27 Shiki
    Added __CARDDisable().

    6     01/04/23 14:45 Shiki
    Removed CARDStat.gameVersion.

    5     01/02/22 9:38 Shiki
    Added support for multiple sector sizes.

    4     01/01/25 10:02 Shiki
    Inserted
        #ifdef __cplusplus
        }
        #endif

    3     12/11/00 11:04p Shiki
    Revised icon info.

    2     11/01/00 5:26p Shiki
    Fixed the type of 'length' in CARDDir from u8 to u16.

    1     10/25/00 8:12p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CARDDIR_H__
#define __CARDDIR_H__

#include <revolution/card.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CARDDir
{
    u8      gameName[4];
    u8      company[2];
    u8      _padding0;
    u8      bannerFormat;
    u8      fileName[CARD_FILENAME_MAX];
    u32     time;           // seconds since 01/01/2000 midnight

    u32     iconAddr;       // 0xffffffff if not used
    u16     iconFormat;
    u16     iconSpeed;

    u8      permission;
    u8      copyTimes;
    u16     startBlock;
    u16     length;
    u8      _padding1[2];

    u32     commentAddr;    // 0xffffffff if not used
} CARDDir;                  // total size 64 bytes

#define CARD_DIR_PERM_BOOT_DEMO         0x01u
#define CARD_DIR_PERM_SYSTEM_FILE       0x02u
#define CARD_DIR_PERM_PUBLIC            0x04u
#define CARD_DIR_PERM_NO_COPY           0x08u
#define CARD_DIR_PERM_NO_MOVE           0x10u
#define CARD_DIR_PERM_GLOBAL            0x20u
#define CARD_DIR_PERM_COMPANY           0x40u

//
// Private API
//
void __CARDSetDiskID        ( const DVDDiskID* diskID );
s32  __CARDGetStatusEx      ( s32 chan, s32 fileNo, CARDDir* dirent );
s32  __CARDSetStatusExAsync ( s32 chan, s32 fileNo, CARDDir* dirent, CARDCallback callback );
s32  __CARDSetStatusEx      ( s32 chan, s32 fileNo, CARDDir* dirent );
s32  __CARDRawEraseAsync    ( s32 chan, s32 offset, CARDCallback callback );
s32  __CARDRawErase         ( s32 chan, s32 offset );
s32  __CARDRawReadAsync     ( s32 chan, void* buf, s32 length, s32 offset, CARDCallback callback );
s32  __CARDRawRead          ( s32 chan, void* buf, s32 length, s32 offset );

s32  __CARDFormatRegionAsync( s32 chan, u16 encode, CARDCallback callback );
s32  __CARDFormatRegion     ( s32 chan, u16 encode );

void __CARDDisable          ( BOOL disable );

// Set EXI_FREQ_2M, ... *before* CARDInit()
extern u32 __CARDFreq;

#ifdef __cplusplus
}
#endif

#endif  // __CARDDIR_H__
