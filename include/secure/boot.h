/*---------------------------------------------------------------------------*
  Project:  Dolphin/Revolution Bootstrap
  File:     boot.h

  Copyright (C)1998-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/02/27 03:48:25  ooizumi
  Modified boot-IRD to boot on normal mode.

  Revision 1.3  2006/02/04 13:05:46  hashida
  (none)

  Revision 1.2  2006/01/30 04:46:05  hirose
  Changed application start address. Deleted obsoleted definitions.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    19    04/04/16 22:12 Hashida
    recreated some definitions for Triforce apploader for backward
    compatibility.
    
    18    04/01/30 16:39 Hashida
    Added OSExec.
    Converted the reboot module to dol.
    
    17    02/11/08 10:33 Naka
    extern C >> extern "C" (syntax error)
    
    16    11/21/01 19:56 Shiki
    Added BOOT_DIAG_*.

    15    9/07/01 5:28a Hashida
    Added several definitions.

    14    5/30/01 12:55a Hashida
    Added a definition for production bootrom location.

    13    10/23/00 3:24p Shiki
    Fixed BS2_ROM_SIZE for production systems.

    12    6/27/00 6:03p Carl
    Removed BI2_EXISTS for SPRUCE builds.

    11    5/26/00 5:51p Hashida
    Changed so that SUPPORT_AUDIO_BUF_CFG becomes default.

    10    5/10/00 3:58p Shiki
    Added DRIP config.

    9     5/10/00 12:03p Shiki
    Added BS2_ROM_SIZE which is the # of bytes to be copied from ROM by
    BS1.

    8     4/18/00 10:47a Hashida
    Added SUPPORT_AUDIO_BUF_CFG and defaulted to 0

    7     4/07/00 3:29p Shiki
    Set BI2_EXISTS to 1 by default.

    6     4/04/00 10:58a Hashida
    Added BI2_EXISTS

    5     2/23/00 12:03p Tian
    Unwrapped ORCA #defines so they can be used.  Excluded header files for
    BS1

    4     2/02/00 4:53p Tian
    Halved the size of FST for MINNOW_MARLIN, increasing room available to
    BS2

    3     1/21/00 5:20p Shiki
    Revised MINNOW settings.

    2     12/02/99 5:35p Shiki
    Fixed Minnow memory size.

    3     11/15/99 2:23p Tian
    Added BOOT_VERBOSE flag to control Apploader/BS2 verbosity

    2     11/03/99 4:34p Hashida
    temporary solution: removed SPRUCE_MARLIN definitions.

    1     11/03/99 2:15p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*
 *        +-------------------+
 *  HIGH  | Disk Image        |
 *        +-------------------+
 *        | FST               |
 *        +-------------------+
 *        | BS2               |
 *        +-------------------+
 *        | Apploader         |
 *        +-------------------+
 *  LOW   : Application load  :
 *        +-------------------+
 */


#ifndef __BOOT_H__
#define __BOOT_H__

#ifdef  __cplusplus
extern "C" {
#endif  // __cplusplus

#if !defined(LCF) && !defined(BS1)
#include <revolution/types.h>
#include <revolution/dvd.h>
#include <secure/Apploader.h>
#else
#define DVD_FST_MAX_SIZE        0x00100000
#endif  // LCF

// If BOOT_VERBOSE is nonzero, lots of OSReports will be generated
// during boot process (affects BS2 and Apploader)
#define BOOT_VERBOSE            0

// If BI2_EXISTS is nonzero, boot rom assumes there's BI2.
// Needs to synchronize it with AMC's tools.
#define BI2_EXISTS              1

// If Marlin supports audio buffer config command, define this
// as nonzero. That causes bootrom to configure audio buffer
// according as diskid->streaming.
#define SUPPORT_AUDIO_BUF_CFG   1
#define BUG_NAPA_RETENTION

#define ROM_IMAGE_BASE          0xFFF00000

// REALCODE
#define BOOT_SYSTEM_MEMORY      0x01800000  // or 0x03000000    XXX
#define BS2_ROM_SIZE            0x001FF800  // 0x200000 - sizeof(BS1.img)
#define BS2_MAX_SIZE            0x00400000
#define BS2_APPLOADER_MAX_SIZE  0x00100000
#define BOOT_DISK_IMAGE_SIZE    0x00000000
#define BOOT_APPLICATION_BASE   0x80004000

#define BOOT_DISK_IMAGE         0x81800000
#define BOOT_FST_BASE           0x81700000
#define BOOT_FATAL_WORK_BASE    0x81400000
#ifdef BUG_NAPA_RETENTION
#define BOOT_BS2_BASE           0x81330000
#else
#define BOOT_BS2_BASE           0x81300000
#endif
#define BOOT_APPLOADER_BASE     0x81200000
#define BOOT_DIAG_END           0x81130000  // diag mem size
#define BOOT_DIAG_BASE          0x81100000  // diag base address
#ifdef EXTEND_PRODBOOT_START_ADDR
#define BOOT_PRODBOOT_START_ADDR 0x80900000
#else
#define BOOT_PRODBOOT_START_ADDR 0x80700000
#endif

// Definitions for data area used by restart to pass data

// used by old exec (see secure/OSExec.h for new exec)
#define BOOT_ARGV_WORK          0x812ff000
#define BOOT_BI2_WORK           0x812fe000
#define BOOT_DOL_ENTRY_NUM      0x812fdffc
#define BOOT_DOL_START_ADDR     0x812fdff8
#define BOOT_APPL2_START_ADDR   0x812fdff4

// used by Triforce apploader for backward compatibility
#define BOOT_REGION_START       0x812fdff0
#define BOOT_REGION_END         0x812fdfec

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __BOOT_H__
