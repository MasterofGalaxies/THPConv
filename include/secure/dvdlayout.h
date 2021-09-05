/*---------------------------------------------------------------------------*
  Project:  Dolphin dvd layout definition
  File:     dvdlayout.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2007/03/14 06:51:52  ooizumi
  Added several definitions.

  Revision 1.4  2006/07/21 13:01:05  ooizumi
  Added OSBootInfo3 structure.

  Revision 1.3  2006/02/08 06:04:55  ooizumi
  Added RVL disk magic number difinition.

  Revision 1.2  2006/02/04 13:05:46  hashida
  (none)

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    4     4/12/00 1:30p Hashida
    Moved DVD magic number from dvd.h to here.
    
    3     4/06/00 10:01p Shiki
    Added padding to DVDBB2.

    2     4/04/00 11:29a Hashida
    Added BI2 support.

    1     7/09/99 9:59p Hashida
    initial revision

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DVDLAYOUT_H__
#define __DVDLAYOUT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <secure/boot.h>

/*
 *
 * 0x0000_0000 +-------------------+
 *             |      Disk ID      |
 * 0x0000_0020 +-------------------+
 *             | Disk Information  |
 * 0x0000_0400 +-------------------+
 *             |        BB1        |
 * 0x0000_0420 +-------------------+
 *             |        BB2        |
 * 0x0000_0440 +-------------------+
 *             |    App Loader     |
 *             +-------------------+
 *             |   Padding(0's)    |
 * 0xXXXX_XXXX +-------------------+
 *             |        FST        |
 *             +-------------------+
 *             |   Padding(0's)    |
 * 0xYYYY_YYYY +-------------------+
 *             |     User Area     |
 * 0xZZZZ_ZZZZ +-------------------+
 *             |   Padding(0's)    |
 *    Disk end +-------------------+
 *
 *
 *  Disk id ..... Data to distinguish disks.
 *  Disk info ... Contain some useful info for the disk.
 *  BB1 ......... Boot Block 1. Used by BS2.
 *  BB2 ......... Boot Block 2. Used by app loader.
 *  App Loader .. Loader of application's boot file.
 *  FST ......... File Symbol Table. Conversion table from file name to
 *                the file's location and length.
 *  User area ... Application lives here. Includes boot file.
 *
 * It's up to developers where to locate FST and the game so there's no
 * fixed location for FST and User Area.
 *
 */

/*
 * DVDDiskID is defined in dvd.h
 */
#define DVD_MAGIC       0xc2339f3d
#define DVD_MAGIC_OFF   28

#define RVL_DVD_MAGIC       0x5d1c9ea3
#define RVL_DVD_MAGIC_OFF   24

typedef struct DVDDiskInfo DVDDiskInfo;

struct DVDDiskInfo
{
    char      gameNameLong[64];

};

typedef struct DVDBB1 DVDBB1;

struct DVDBB1
{
    u32       appLoaderLength;
    void*     appLoaderFunc1;
    void*     appLoaderFunc2;
    void*     appLoaderFunc3;

};

typedef struct DVDBB2 DVDBB2;

struct DVDBB2
{
    u32       bootFilePosition;
    u32       FSTPosition;
    u32       FSTLength;
    u32       FSTMaxLength;
    void*     FSTAddress;
    u32       userPosition;
    u32       userLength;

    u32       padding0;
};


/*
 * Definitions for those located in a known location
 */
#define DVDLAYOUT_ID_POSITION         0x00000000
#define DVDLAYOUT_INFO_POSITION       0x00000020
#define DVDLAYOUT_BB1_POSITION        0x00000400
#define DVDLAYOUT_BB2_POSITION        0x00000420
#if BI2_EXISTS
#define DVDLAYOUT_BI2_POSITION        0x00000440
#define DVDLAYOUT_APPLOADER_POSITION  0x00002440
#else
#define DVDLAYOUT_APPLOADER_POSITION  0x00000440
#endif
#define DVDLAYOUT_GAMETOC_POSITION    0x00040000
#define DVDLAYOUT_BI3_POSITION        0x0004E000

#define DVDPART_TYPE_BOOTGAME         0x00000000
#define DVDPART_TYPE_UPDATE           0x00000001
#define DVDPART_TYPE_INSTALLER        0x00000002

/*
 * Definitions for title id of partitions in DVD
 */
#define DVDPART_TITLEID_HIGH            0x00010000 // dvd game's title id high

#define DVDPART_TITLEID_LOW_UPDATE      0x00555000
#define DVDPART_TITLEID_LOW_UPDATE_CMN  (DVDPART_TITLEID_LOW_UPDATE | 0x00000044) // (NUL)UPD
#define DVDPART_TITLEID_LOW_UPDATE_JPN  (DVDPART_TITLEID_LOW_UPDATE | 0x0000004A) // (NUL)UPJ
#define DVDPART_TITLEID_LOW_UPDATE_USA  (DVDPART_TITLEID_LOW_UPDATE | 0x00000045) // (NUL)UPE
#define DVDPART_TITLEID_LOW_UPDATE_EUR  (DVDPART_TITLEID_LOW_UPDATE | 0x00000050) // (NUL)UPP

#define DVDPART_TITLEID_LOW_LOCKED      0x004C4F43 // (NUL)LOC - title id low of locked disc's banner partition

#ifdef __cplusplus
}
#endif

#endif  // __DVDLAYOUT_H__
