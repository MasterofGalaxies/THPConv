/*---------------------------------------------------------------------------*
  Project:      NAND flash secret library
  File:         nandsecret.h
  Programmer:   HIRATSU Daisuke

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/10/07 08:55:03  hiratsu
  Added macro for user area.

  Revision 1.3  2006/09/21 09:38:07  hiratsu
  Added NANDSecretShutdown().

  Revision 1.2  2006/09/01 13:42:28  hiratsu
  Implemented NANDSecretGetUserUsage[Async]().

  Revision 1.1  2006/08/16 09:33:24  hiratsu
  Initial check-in.

 *---------------------------------------------------------------------------*/

#ifndef __NANDSECRET_H__
#define __NANDSECRET_H__


#include <revolution/types.h>
#include <revolution/nand.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NAND_MAX_USER_CAPACITY (272*1024*1024)
#define NAND_MAX_USER_INODES    4000


typedef struct NANDFileSystemStatus
{
    u32     blockSize;      /* File system block size */
    u32     freeBlocks;     /* Free FS blocks */
    u32     occupiedBlocks; /* FS blocks in use */
    u32     badBlocks;      /* Bad FS blocks */
    u32     reservedBlocks; /* Reserved FS blocks */
    u32     freeInodes;     /* Free inodes */
    u32     occupiedInodes; /* Inodes in use */
} NANDFileSystemStatus;

s32 NANDSecretGetUsage     (const char *path, u32 *fsBlock, u32 *inode);
s32 NANDSecretGetUsageAsync(const char *path, u32 *fsBlock, u32 *inode, NANDCallback cb, NANDCommandBlock *block);
s32 NANDSecretGetUserUsage     (u32 *fsBlock, u32 *inode);
s32 NANDSecretGetUserUsageAsync(u32 *fsBlock, u32 *inode, NANDCallback cb, NANDCommandBlock *block);
s32 NANDSecretGetSystemAvailableArea(const NANDFileSystemStatus *stat, u32 userOccupiedFSblocks, u32 userOccupiedInodes, u32 *fsBlocks, u32 *inodes);
s32 NANDSecretGetFileSystemStatus(NANDFileSystemStatus *stat);
s32 NANDSecretFormat(void);
s32 NANDSecretShutdown(void);

#ifdef __cplusplus
}
#endif


#endif // end of __NANDSECRET_H__
