/*---------------------------------------------------------------------------*
  Project:      System state flags
  File:         OSStateFlags.h

  Copyright (C) 2006-2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2007/02/28 04:04:18  ooizumi
  Added menuMode to OSStateFlags for OSReturnToDataManager.

  Revision 1.4  2006/11/01 07:09:03  ooizumi
  Added OS_STATE_FLAGS_BOOTAPP_CACHED.

  Revision 1.3  2006/11/01 05:21:24  ooizumi
  Added OS_STATE_FLAGS_BOOTAPP_MENU.

  Revision 1.2  2006/09/19 08:31:01  ooizumi
  Added OS_STATE_FLAGS_RETURN_TO_IDLE.

  Revision 1.1  2006/09/14 00:12:14  ooizumi
  Initial check-in.


 *---------------------------------------------------------------------------*/

#ifndef __OSSTATEFLAGS_H__
#define __OSSTATEFLAGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>

#define OS_STATE_FLAGS_PATH   "/title/00000001/00000002/data/state.dat"
#define OS_STATE_FLAGS_PERM \
    (NAND_PERM_OWNER_READ | NAND_PERM_OWNER_WRITE | \
     NAND_PERM_GROUP_READ | NAND_PERM_GROUP_WRITE | \
     NAND_PERM_OTHER_READ | NAND_PERM_OTHER_WRITE)
#define OS_STATE_FLAGS_ATTR   0x00

#define OS_STATE_FLAGS_BOOTAPP_NONE          0x00
#define OS_STATE_FLAGS_BOOTAPP_EXIST         0x80
#define OS_STATE_FLAGS_BOOTAPP_CACHED        0x40
#define OS_STATE_FLAGS_BOOTAPP_RVL           0x01
#define OS_STATE_FLAGS_BOOTAPP_GC            0x02
#define OS_STATE_FLAGS_BOOTAPP_MENU          0x04

#define OS_STATE_FLAGS_DIRTY                 0xFF
#define OS_STATE_FLAGS_SHUTDOWN              0x01
#define OS_STATE_FLAGS_REBOOT                0x02
#define OS_STATE_FLAGS_RETURN                0x03
#define OS_STATE_FLAGS_IDLE                  0x04
#define OS_STATE_FLAGS_RETURN_TO_IDLE        0x05

#define OS_STATE_FLAGS_MENUMODE_DEFAULT      0x00
#define OS_STATE_FLAGS_MENUMODE_DATAMANAGER  0x01
#define OS_STATE_FLAGS_MENUMODE_ARGS         0x02

#define OS_STATE_FLAGS_DISC_CHECKED          0x01
#define OS_STATE_FLAGS_DISC_CHANGED          0x02
#define OS_STATE_FLAGS_DISC_NODISK           0x03

typedef struct
{
    u32     checkSum;
    u8      lastBootApp;
    u8      lastShutdown;
    u8      lastDiscState;
    u8      menuMode;
    u8      reserved[24];
} OSStateFlags;

BOOL __OSCreateStateFlags(void);
BOOL __OSWriteStateFlags(OSStateFlags *flags);
BOOL __OSReadStateFlags (OSStateFlags *flags);

#ifdef __cplusplus
}
#endif

#endif // __OSSTATEFLAGS_H__
