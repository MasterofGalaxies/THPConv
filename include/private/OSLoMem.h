/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Locore Map
  File:     OSLoMem.h

  Copyright 1998 - 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.28  2007/07/25 01:08:24  ooizumi
  Added OS_DEVICECHECKCODE_OFFSET.

  Revision 1.27  2007/05/23 12:25:48  ooizumi
  Added OS_APP_LOCKED_FLAG.
  Added OS_LAUNCH_PARTITION_OFFSET.

  Revision 1.26  2007/04/13 11:11:40  ooizumi
  Added OS_LAUNCH_PARTITION_TYPE for maltiple partition disc.

  Revision 1.25  2007/03/22 08:22:32  wada_jumpei
  Moved APP_TYPEs definition

  Revision 1.24  2007/03/14 09:34:59  wada_jumpei
  Added OS_NANDBOOTINFO_FLAG to decide valid or not

  Revision 1.23  2006/11/29 01:51:48  wada_jumpei
  Added OS_RETURN_CODE and OS_LAUNCH_CODE

  Revision 1.22  2006/10/22 10:10:59  hirose
  Reserved OS_NWC_INFO block on LoMem.

  Revision 1.21  2006/09/14 13:01:01  sakamaki
  Add OS_SDKIOS_VER.

  Revision 1.20  2006/09/06 16:11:57  ooizumi
  Added OS_DRIVESAVING_MODE.

  Revision 1.19  2006/09/06 00:45:36  hirose
  Added OS_APP_TYPE_IPL.

  Revision 1.18  2006/09/04 12:15:14  ooizumi
  Added OS_SHUTDOWNMENU_FLAG.

  Revision 1.17  2006/08/24 09:11:19  hirose
  Added OS_WIRELESS_INFO.

  Revision 1.16  2006/08/09 07:52:18  wada_jumpei
  Change OS_APP_TYPE_NAND and OS_APP_TYPE_DVD values

  Revision 1.15  2006/08/09 07:49:49  wada_jumpei
  Add getting application's information functions

  Revision 1.14  2006/08/08 08:37:04  hiratsu
  Added NAND usage area (FS block and i-node)

  Revision 1.13  2006/06/28 13:26:28  ooizumi
  Added OS_BOOT_IRD_VERSION.

  Revision 1.12  2006/06/28 06:19:42  ooizumi
  Added OS_RSO_MODULE_LIST_ADDR.

  Revision 1.11  2006/06/20 09:14:13  ooizumi
  Added OS_SYNCHRONIZE_AHB_PI.

  Revision 1.10  2006/06/16 05:25:37  kawaset
  Added OS_PRODUCT_INFO_SIZE.

  Revision 1.9  2006/06/07 07:39:33  ooizumi
  Added several difinitions.
  - OS_BOOTROM_TARGET
  - OS_APPLOADER_TARGET
  - OS_PRODUCT_INFO

  Revision 1.8  2006/05/08 07:33:53  hirose
  Added OS_GDDR_VENDOR_ID.

  Revision 1.7  2006/04/18 01:39:38  hirose
  Added information for DI/SC buffers.

  Revision 1.6  2006/03/14 23:03:52  ooizumi
  Added lo mem definitions for IOS version and IOS build number.

  Revision 1.5  2006/01/28 08:47:53  hirose
  Fixed mismatches on macro names.

  Revision 1.4  2006/01/28 05:23:43  hirose
  Small arrangement.

  Revision 1.3  2006/01/28 05:08:40  hirose
  Initial version of RVL lomem mapping.

  Revision 1.2  2006/01/23 11:13:37  hirose
  Deleted flag check for OS_BUS_CLOCK_SPEED and OS_CORE_CLOCK_SPEED.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    26    04/02/23 11:03 Hashida
    Updated to support old apploader.
    
    25    04/02/19 0:41 Hashida
    Added OS_CURRENT_TGC_OFFSET.
    
    24    04/01/30 18:19 Hashida
    Deleted OS_IS_REBOOTED and OS_RESTART_CODE.
    Added OS_EXEC_PARAMS_ADDR.
    
    23    11/13/03 14:20 Shiki
    Added support for OSGetRestartCode().

    22    7/22/03 10:05 Shiki
    Defined OS_GAMECHOICE bit definitions.

    21    3/07/03 14:41 Shiki
    Added comment about Uji reserved area.

    20    03/03/04 13:09 Hashida
    Added OS_DOL_OFFSET_TO_BOOT (4 bytes).

    19    11/22/01 14:40 Shiki
    Added OS_GAMECHOICE2.

    18    9/15/01 3:33a Hashida
    Added OS_RESET_SHUTDOWN

    17    8/27/01 10:35 Shiki
    Added OS_GAMECHOICE.

    16    8/21/01 3:44p Hashida
    Added devicecode.

    15    7/16/01 13:51 Shiki
    Modified to define OS_*_CLOCK_SPEED for HW2 too.

    14    01/07/09 16:23 Shiki
    Added OS_PAD3_BUTTON.

    13    7/06/01 1:26p Hashida
    Added OS_IS_REBOOTED.

    12    01/03/21 14:50 Shiki
    Added OS_WIRELESS_PAD_FIX_MODE.

    11    2/21/01 4:49p Hashida
    Added system time base.

    10    1/15/01 6:52p Hashida
    Added BS2GetBytesLeft function support.

    9     10/31/00 4:41p Shiki
    Reserved DLL control block.

    8     9/12/00 10:43p Shiki
    Added OS_EXIn_PROBE_START_TIME.

    7     6/15/00 12:09a Shiki
    Added OS_*_CLOCK_SPEED.

    6     3/23/00 6:26p Hashida
    Added console simulated memory size, debug monitor size, debug monitor
    address and bootinfo2 address.

    5     3/21/00 6:47p Shiki
    Updated.

    4     3/21/00 6:25p Shiki
    Reserved thread control structures in low-mem.

    3     3/10/00 5:36p Eugene
    Added 4 bytes for storage of ARAM size. Located at 0xd0-0xd3.

    2     2/17/00 4:20p Hashida
    Added OS_TVTYPES_ADDR

    2     9/01/99 1:01p Tian
    Added field for OSDBIntegrator to save link register to.

    1     8/23/99 2:18p Tian
    Moved to include/private from include/dolphin/os.

    8     8/17/99 2:18a Shiki
    Added OS_UINTERRUPTMASK_ADDR.

    7     8/16/99 10:23p Shiki
    Added OS_INTERRUPTMASK_ADDR.

    6     7/20/99 5:14p Tian
    Fixed addition mistakes in comments.

    5     7/16/99 1:27p Tian
    Added a region for the code that performs the jump to the well known
    debugger breakpoint location.

    4     7/08/99 8:08p Tian
    mods for new debugger/kernel integration

    3     5/11/99 4:43p Shiki
    Refreshed include tree.

    1     4/30/99 12:49p Tianli01

    4     4/21/99 4:13p Tianli01
    updated comments, added console type information.

    3     3/31/99 6:07p Tianli01
    Added DBInterface field offsets.

    2     3/26/99 2:09p Tianli01
    Created.  PPC low memory map.

    1     3/26/99 2:08p Tianli01
    Broken up from previous OS.h.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSLOMEM_H__
#define __OSLOMEM_H__

/*
    Low memory map

    0x0000 0000 - 0x0000 003F   BootInfo structure          (64 bytes, 64 used)
    ------------- bootInfo structure -----------------
           0000 : DVDDiskID  DVDDiskID;
           0020 : u32        magic;
           0024 : u32        version;
           0028 : u32        memorySize;
           002C : u32        consoleType;
           0030 : void*      arenaLo;
           0034 : void*      arenaHi;
           0038 : void*      FSTLocation;
           003C : u32        FSTMaxLength;
    ---------------------------------------------------

    ---------------------------------------------------
    // DBG
    0x0000 0040 - 0x0000 00BF   debugger related structures (128 bytes)

    ---------------------------------------------------
    // OS
    0x0000 00C0 - 0x0000 00C3   __OSCurrentContextPA        (4 bytes)
    0x0000 00C4 - 0x0000 00C7   Global interrupt mask bits  (4 bytes)
    0x0000 00C8 - 0x0000 00CB   User interrupt mask bits    (4 bytes)
    0x0000 00CC - 0x0000 00CF   TV type                     (4 bytes)
    0x0000 00D0 - 0x0000 00D3   ARAM size                   (4 bytes)
    0x0000 00D4 - 0x0000 00E7   Thread control structures   (20 bytes)

    ---------------------------------------------------
    // DBG
    0x0000 00E8 - 0x0000 00EB   debug monitor size          (4 bytes)
    0x0000 00EC - 0x0000 00EF   free debug monitor addr     (4 bytes)
    0x0000 00F0 - 0x0000 00F3   simulated memory size       (4 bytes)
    0x0000 00F4 - 0x0000 00F7   boot info2 addr             (4 bytes)

    ---------------------------------------------------
    // System Clock
    0x0000 00F8 - 0x0000 00FB   bus clock speed (Hz)        (4 bytes)
    0x0000 00FC - 0x0000 00FF   core clock speed (Hz)       (4 bytes)

    ---------------------------------------------------
    0x0000 0100 - 0x0000 2FFF   Exception Table
           0100 -        01FF   : System Reset
           0200 -        02FF   : Machine Check
           0300 -        03FF   : DSI
           0400 -        04FF   : ISI
           0500 -        05FF   : External
           0600 -        06FF   : Alignment
           0700 -        07FF   : Program
           0800 -        08FF   : FP Unavailable
           0900 -        09FF   : Decrementer
           0A00 -        0BFF   : (Reserved)
           0C00 -        0CFF   : System Call
           0D00 -        0DFF   : Trace
           0E00 -        0EFF   : FP Assist (Not Supported)
           0F00 -        0FFF   : Performance Monitor
           1300 -        13FF   : IAB
           1400 -        2FFF   : (Reserved)
    // (Overlapped)
    0x0000 2000 - 0x0000 20FF   Reserved by Uji             (256 bytes)
    
    ---------------------------------------------------
    // Exception/Interrupt handler
    0x0000 3000 - 0x0000 303F   OS Exception Handler Table  (64 bytes, 60 used)
    0x0000 3040 - 0x0000 30BF   OS Interrupt Handler Table  (128 bytes)
    
    ---------------------------------------------------
    // System Misc.
    0x0000 30C0 - 0x0000 30C3   EXI 0 probe start time      (4 bytes)
    0x0000 30C4 - 0x0000 30C7   EXI 1 probe start time      (4 bytes)
    0x0000 30C8 - 0x0000 30D3   DLL control block           (12 bytes)
    0x0000 30D4 - 0x0000 30D7   Information used by bootrom (4 bytes)
    0x0000 30D8 - 0x0000 30DF   System time base            (8 bytes)
    0x0000 30E0 - 0x0000 30E1   Wireless pad fix mode       (2 bytes - 0x3fff)
    0x0000 30E2                 Flag for reboot             (1 byte)
    0x0000 30E3                 multi game disk             (1 byte)
    0x0000 30E4 - 0x0000 30E5   pads[4].button              (2 bytes)
    0x0000 30E6 - 0x0000 30E7   dvd device code             (2 bytes)
    0x0000 30E8 - 0x0000 30E9   BI2 copy                    (2 bytes)
    0x0000 30EA - 0x0000 30EB   multi game disk             (2 bytes)
    0x0000 30EC - 0x0000 30EF   dol file execution          (4 bytes)
    0x0000 30F0 - 0x0000 30F3   parameters for exec         (4 bytes)
    0x0000 30F4 - 0x0000 30F7   tgc offset                  (4 bytes)
    0x0000 30F8 - 0x0000 30FF   RESERVED                    (8 bytes)
    
    ---------------------------------------------------
    // RVL-BootInfo
    0x0000 3100 - 0x0000 3103   Napa System Memory Size (Physical)  (4 bytes)
    0x0000 3104 - 0x0000 3107   Napa System Memory Size (Simulated) (4 bytes)
    0x0000 3108 - 0x0000 310B   Napa Protection Boundary            (4 bytes)
    0x0000 310C - 0x0000 310F   Napa Arena Lo                       (4 bytes)
    0x0000 3110 - 0x0000 3113   Napa Arena Hi                       (4 bytes)
    0x0000 3114 - 0x0000 3117   (Reserved)
    0x0000 3118 - 0x0000 311B   GDDR System Memory Size (Physical)  (4 bytes)
    0x0000 311C - 0x0000 311F   GDDR System Memory Size (Simulated) (4 bytes)
    0x0000 3120 - 0x0000 3123   GDDR Protection Boundary            (4 bytes)
    0x0000 3124 - 0x0000 3127   GDDR Arena Lo                       (4 bytes)
    0x0000 3128 - 0x0000 312B   GDDR Arena Hi                       (4 bytes)
    0x0000 312C - 0x0000 312F   (Reserved)
    0x0000 3130 - 0x0000 3133   IPC Comm. buffer Lo                 (4 bytes)
    0x0000 3134 - 0x0000 3137   IPC Comm. buffer Hi                 (4 bytes)
    0x0000 3138 - 0x0000 313B   Hollywood chip revision bnumber     (4 bytes)
    0x0000 313C - 0x0000 313F   Product Region Code (for reference) (4 bytes)
    0x0000 3140 - 0x0000 3143   IOS version                         (4 bytes)
    0x0000 3144 - 0x0000 3147   IOS build number                    (4 bytes)

    0x0000 3160 - 0x0000 3167   AHB/IO synchronization buffer       (8 bytes)
    0x0000 3168 - 0x0000 316F   RSO module list addr                (8 bytes)

    0x0000 3170 - 0x0000 3173   NAND FS block usage of system files (4 bytes)
    0x0000 3174 - 0x0000 3177   NAND i-node usage of system files   (4 bytes)
    0x0000 3178 - 0x0000 317B   NAND FS block usage of user files   (4 bytes)
    0x0000 317C - 0x0000 317F   NAND i-node usage of user files     (4 bytes)

    0x0000 3180 - 0x0000 3183   Application game name               (4 bytes)
    0x0000 3184 - 0x0000 3184   Application type (DVD or NAND)      (1 byte)
    0x0000 3185 - 0x0000 3185   drive saving flag                   (1 byte)
    0x0000 3186 - 0x0000 3186   NANDBOOTINFO valid flag             (1 byte)
    
    0x0000 3188 - 0x0000 318B   Need IOS version by SDK             (4 bytes)

    0x0000 318C - 0x0000 318F   Launch Code                         (4 bytes)
    0x0000 3190 - 0x0000 3193   Return Code                         (4 bytes)

    0x0000 31A0 - 0x0000 31BF   Wireless info                       (32 bytes)

    0x0000 31C0 - 0x0000 31FF   NWC info                            (64 bytes)

    0x0000 3200 - 0x0000 3207   title ID of the last application    (8 bytes)
 
    ---------------------------------------------------
    // Bootstrap
    0x0000 3400 - 0x0000 37FF   BS1  (1024 bytes)

    ---------------------------------------------------
    0x0000 3800 - 0x0000 3FFF   D Code (2048 bytes)

    ---------------------------------------------------
    0x0000 4000 -               Game

 */

#define OS_BOOTINFO_ADDR            0x0000  // 64 bytes, 64 used
#define OS_DBINTERFACE_ADDR         0x0040  // 32 bytes, 16 used
#define OS_DBJUMPPOINT_ADDR         0x0060  // 96 bytes, 36 used
#define OS_CURRENTCONTEXT_PADDR     0x00C0  // PA of __OSCurrentContext
#define OS_INTERRUPTMASK_ADDR       0x00C4  // Global interrupt mask bits
#define OS_UINTERRUPTMASK_ADDR      0x00C8  // User interrupt mask bits
#define OS_VITVTYPE_ADDR            0x00CC  // TV type
#define OS_ARAMSIZE_ADDR            0x00D0  // ARAM size (4 bytes)

// Thread control structure addresses (20 bytes, 20 used)
#define OS_CURRENTCONTEXT_ADDR      0x00D4  // 4 bytes
#define OS_FPUCONTEXT_ADDR          0x00D8  // 4 bytes
#define OS_ACTIVETHREADQUEUE_ADDR   0x00DC  // 8 bytes
#define OS_CURRENTTHREAD_ADDR       0x00E4  // 4 bytes

#define OS_DEBUGMONITOR_SIZE        0x00E8  // 4 bytes
#define OS_FREEDEBUGMONITOR_ADDR    0x00EC  // 4 bytes
#define OS_SIMULATEDMEM_SIZE        0x00F0  // 4 bytes
#define OS_BOOTINFO2_ADDR           0x00F4  // 4 bytes

#define OS_BUS_CLOCK_SPEED          0x00F8  // 4 bytes
#define OS_CORE_CLOCK_SPEED         0x00FC  // 4 bytes

#define OS_EXCEPTIONTABLE_ADDR      0x3000  // 64 bytes, 60 used
#define OS_INTERRUPTTABLE_ADDR      0x3040  // 128 bytes

#define OS_EXI0_PROBE_START_TIME    0x30C0  // 4 bytes
#define OS_EXI1_PROBE_START_TIME    0x30C4  // 4 bytes

// DLL control block (12 bytes)
#define OS_MODULE_LIST_ADDR         0x30C8  // 8 bytes
#define OS_STRING_TABLE_ADDR        0x30D0  // 4 bytes

// Information used by bootrom
#define OS_BOOT_TOTAL_BYTES         0x30D4  // 4 bytes

// System time base
#define OS_SYSTEMTIME_BASE          0x30D8  // 8 bytes

// Wireless pad fix mode
#define OS_WIRELESS_PAD_FIX_MODE    0x30E0  // 2 bytes

#define OS_IS_REBOOTED              0x30E2  // 1 bytes

#define OS_GAMECHOICE               0x30E3  // 1 bytes
#define   OS_GAMECHOICE_TIMER           0x1f    // Set to fake reset button timer in min.
#define   OS_GAMECHOICE_PAD_RUMBLE      0x20    // Set to disable rumble.
#define   OS_GAMECHOICE_PAD_ORIGIN      0x40    // Set to disable recalibration.
#define   OS_GAMECHOICE_CARD_MOUNT      0x80    // Set to disable mount operation.

#define OS_PAD3_BUTTON              0x30E4  // 2 bytes

#define OS_DVD_DEVICECODE           0x30E6  // 2 bytes

// Copy of BI2
#define OS_DEBUG_FLAG               0x30E8  // 1 byte
#define OS_PAD_SPEC                 0x30E9  // 1 byte

// Game Choice
#define OS_GAMECHOICE2              0x30EA  // 2 bytes

// Dol Exec
#define OS_DOL_OFFSET_TO_BOOT       0x30EC  // 4 bytes (for backward comp.)

#define OS_EXEC_PARAMS_ADDR         0x30F0  // 4 bytes

#define OS_CURRENT_TGC_OFFSET       0x30F4  // 4 bytes


// RVL-BootInfo
#define OS_RVL_BOOTINFO             0x3100
#define OS_NAPA_SIZE_PHYSICAL       (OS_RVL_BOOTINFO + 0x0000) // 4 bytes
#define OS_NAPA_SIZE_SIMULATED      (OS_RVL_BOOTINFO + 0x0004) // 4 bytes
#define OS_NAPA_PROT_ADDR           (OS_RVL_BOOTINFO + 0x0008) // 4 bytes
#define OS_NAPA_ARENA_LOW           (OS_RVL_BOOTINFO + 0x000C) // 4 bytes
#define OS_NAPA_ARENA_HIGH          (OS_RVL_BOOTINFO + 0x0010) // 4 bytes

#define OS_GDDR_SIZE_PHYSICAL       (OS_RVL_BOOTINFO + 0x0018) // 4 bytes
#define OS_GDDR_SIZE_SIMULATED      (OS_RVL_BOOTINFO + 0x001C) // 4 bytes
#define OS_GDDR_PROT_ADDR           (OS_RVL_BOOTINFO + 0x0020) // 4 bytes
#define OS_GDDR_ARENA_LOW           (OS_RVL_BOOTINFO + 0x0024) // 4 bytes
#define OS_GDDR_ARENA_HIGH          (OS_RVL_BOOTINFO + 0x0028) // 4 bytes

#define OS_IPC_BUFFER_LOW           (OS_RVL_BOOTINFO + 0x0030) // 4 bytes
#define OS_IPC_BUFFER_HIGH          (OS_RVL_BOOTINFO + 0x0034) // 4 bytes

#define OS_HOLLYWOOD_REV            (OS_RVL_BOOTINFO + 0x0038) // 4 bytes
#define OS_PRODUCT_REGION           (OS_RVL_BOOTINFO + 0x003C) // 4 bytes
#define OS_IOS_VERSION              (OS_RVL_BOOTINFO + 0x0040) // 4 bytes
#define OS_IOS_BUILD_NUMBER         (OS_RVL_BOOTINFO + 0x0044) // 4 bytes

#define OS_DI_BUFFER_LOW            (OS_RVL_BOOTINFO + 0x0048) // 4 bytes
#define OS_DI_BUFFER_HIGH           (OS_RVL_BOOTINFO + 0x004C) // 4 bytes
#define OS_SC_BUFFER_LOW            (OS_RVL_BOOTINFO + 0x0050) // 4 bytes
#define OS_SC_BUFFER_HIGH           (OS_RVL_BOOTINFO + 0x0054) // 4 bytes

#define OS_GDDR_VENDOR_ID           (OS_RVL_BOOTINFO + 0x0058) // 4 bytes

#define OS_BOOTROM_TARGET           (OS_RVL_BOOTINFO + 0x005C) // 1 bytes
#define OS_APPLOADER_TARGET         (OS_RVL_BOOTINFO + 0x005D) // 1 bytes
#define   OS_TARGET_RVL                0x80
#define   OS_TARGET_RVL0               0x81
#define OS_BOOT_IRD_VERSION         (OS_RVL_BOOTINFO + 0x005E) // 2 bytes

#define OS_SYNCHRONIZE_AHB_PI       (OS_RVL_BOOTINFO + 0x0060) // 4 bytes
#define OS_SHUTDOWNMENU_FLAG        (OS_RVL_BOOTINFO + 0x0064) // 4 bytes

// RSO DLL control block (8 bytes)
#define OS_RSO_MODULE_LIST_ADDR     (OS_RVL_BOOTINFO + 0x0068) // 8 bytes

#define OS_NAND_SYS_FSBLOCK_USAGE   (OS_RVL_BOOTINFO + 0x0070) // 4 bytes
#define OS_NAND_SYS_INODE_USAGE     (OS_RVL_BOOTINFO + 0x0074) // 4 bytes
#define OS_NAND_USER_FSBLOCK_USAGE  (OS_RVL_BOOTINFO + 0x0078) // 4 bytes
#define OS_NAND_USER_INODE_USAGE    (OS_RVL_BOOTINFO + 0x007C) // 4 bytes

#define OS_APP_GAMENAME             (OS_RVL_BOOTINFO + 0x0080) // 4 bytes
#define OS_APP_TYPE                 (OS_RVL_BOOTINFO + 0x0084) // 1 bytes
#define OS_DRIVESAVING_MODE         (OS_RVL_BOOTINFO + 0x0085) // 1 bytes
#define OS_NANDBOOTINFO_FLAG        (OS_RVL_BOOTINFO + 0x0086) // 1 bytes
#define OS_APP_LOCKED_FLAG          (OS_RVL_BOOTINFO + 0x0087) // 1 bytes
#define   OS_APP_DEFAULT               0x00
#define   OS_APP_LOCKED                0x80

#define OS_SDKIOS_VER               (OS_RVL_BOOTINFO + 0x0088) // 4 bytes

// For NAND application launch/return code
#define OS_LAUNCH_CODE              (OS_RVL_BOOTINFO + 0x008C) // 4 bytes
#define OS_RETURN_CODE              (OS_RVL_BOOTINFO + 0x0090) // 4 bytes

// For Multiple partition system
#define OS_LAUNCH_PARTITION_TYPE    (OS_RVL_BOOTINFO + 0x0094) // 4 bytes
#define OS_LAUNCH_PARTITION_OFFSET  (OS_RVL_BOOTINFO + 0x0098) // 4 bytes

#define OS_DEVICECHECKCODE_OFFSET   (OS_RVL_BOOTINFO + 0x009C) // 1 bytes
#define   OS_DEVICECHECKCODE_PRESENT   0x80
#define   OS_DEVICECHECKCODE_SL        0x00
#define   OS_DEVICECHECKCODE_DL        0x01

    /* Free area : 0x009D - 0x009F */

#define OS_WIRELESS_INFO            (OS_RVL_BOOTINFO + 0x00A0) // 32 bytes

#define OS_NWC_INFO                 (OS_RVL_BOOTINFO + 0x00C0) // 64 bytes

#define OS_LASTAPP_TITLEID          (OS_RVL_BOOTINFO + 0x0100) // 8 bytes

    /* Free area : 0x0108 - 0x02FF */

// - 0x33FF reserved


// Bootstrap code
#define OS_RVL_BS1                  0x3400  // 1024 bytes

#define OS_PRODUCT_INFO             0x3800  // OS_PRODUCT_INFO_SIZE bytes
#define   OS_PRODUCT_INFO_SIZE       0x100


/*
    These macros should represent the offsets of the DBInterface structure
    members.  These members are fairly stable and should not change.  If
    there are additions to the DBInterface structure definition, they
    should come after these fields.
 */
#define DB_BPRESENT_OFFSET          0x0000
#define DB_EXCEPTIONMASK_OFFSET     0x0004
#define DB_EXCEPTIONDEST_OFFSET     0x0008
#define DB_EXCEPTIONRET_OFFSET      0x000C

#endif  // __OSLOMEM_H__
