/*---------------------------------------------------------------------------*
  Project:    Secure Flash File System emulation API
  File:       isfsEmu.h
  Programmer: HIRATSU Daisuke

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/01/30 08:31:02  hiratsu
  Invalidated entire this file using #if 0 - #endif.
  Please include "isfs.h" instead of this file.

  Revision 1.1  2006/01/20 08:57:59  hiratsu
  Secure Flash File System emulation API. (ISFS_*)

 *---------------------------------------------------------------------------*/
#if 0  // in order to invalidate this header file.

#ifndef ISFSEMU_H__
#define ISFSEMU_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ISFS_SLOT_A   0         // Emulation system only.
#define ISFS_SLOT_B   1         // Emulation system only.

// Below FS_ERROR_* definition is temporary.
// Perhaps BroadOn will define another value.
#define FS_ERROR_OK           0 
#define FS_ERROR_ACCESS    ( -1)
#define FS_ERROR_BADFD     ( -2)
#define FS_ERROR_BUSY      ( -3)
#define FS_ERROR_CORRUPT   ( -4)
#define FS_ERROR_ECC_CRIT  ( -5)
#define FS_ERROR_EXISTS    ( -6)
#define FS_ERROR_INVALID   ( -7)
#define FS_ERROR_MAXBLOCKS ( -8)
#define FS_ERROR_MAXFD     ( -9)
#define FS_ERROR_MAXFILES  (-10)
#define FS_ERROR_NOEXISTS  (-11)
#define FS_ERROR_NOTEMPTY  (-12)
#define FS_ERROR_NOTREADY  (-13)
#define FS_ERROR_UNKNOWN   (-14)

// Below FS_ACCESS_* definition is temporary.
// Perhaps BroadOn will define another value.
#define FS_ACCESS_READ     0x02
#define FS_ACCESS_WRITE    0x01

typedef u32 FSError;
typedef u32 SKOwnerId;
typedef u16 SKGroupId;

typedef struct {
    u32 blockSize;       /* File system block size */
    u16 freeBlocks;      /* Free FS blocks */
    u16 occupiedBlocks;  /* Occupied FS blocks */
    u16 badBlocks;       /* Bad FS blocks */
    u16 reservedBlocks;  /* Reserved FS blocks */
    u16 freeInodes;      /* Free inodes */
    u16 occupiedInodes;  /* Occupied inodes */
} FSStats;

#define FS_PATH_MAXLEN 128

typedef struct {
    u8 path1[FS_PATH_MAXLEN]; /* NULL terminated string */
    u8 path2[FS_PATH_MAXLEN]; /* NULL terminated string */
} FSPathsInput;

typedef struct {
    SKOwnerId ownerId;        /* File or directory owner */
    SKGroupId groupId;        /* Group ID of the owner */
    u8 path[FS_PATH_MAXLEN];  /* NULL terminated string */
    u8 ownerAccess;           /* The least significant 2 bits are used */
    u8 othersAccess;          /* The least significant 2 bits are used */
    u8 groupAccess;           /* The lease significant 2 bits are used */
    u8 attr;                  /* Attribute bits */
} /*__attribute__((packed)) */ FSPathAttrInput;

typedef struct {
    u32 size;    /* Size of file in bytes */
    u32 offset;  /* Current position indicator */
} FSFileStats;

typedef void (*ISFSCallBack)( FSError err );  /* 仮のコールバック型。 */

// Implemented APIs.
FSError ISFS_Init(int slot);   // Emulation system only.
FSError ISFS_Finalize(void);   // Emulation system only.
FSError ISFS_CreateFile(const u8 *fname, SKOwnerId ownerId, SKGroupId groupId, u32 fileAttr, u32 ownerAcc, u32 groupAcc, u32 othersAcc);
FSError ISFS_Delete(const u8 *name);
s32     ISFS_Open(const u8 *fname, u32 access);
FSError ISFS_Close(s32 fd);
FSError ISFS_Read(s32 fd, u8 *buf, u32 size);
FSError ISFS_Write(s32 fd, const u8 *buf, u32 size);
FSError ISFS_ReadDir(const u8 *dname, u8 *nameList, u32 *len);


// Below APIs are not implemented yet.
FSError ISFS_GetStats(FSStats *stats);
FSError ISFS_CreateDir(const u8 *dname, SKOwnerId ownerId, SKGroupId groupId, u32 dirAttr, u32 ownerAcc, u32 groupAcc, u32 othersAcc);
FSError ISFS_CreateDirAsync(const u8 *dname, SKOwnerId ownerId, SKGroupId groupId, u32 dirAttr, u32 ownerAcc, u32 groupAcc, u32 othersAcc, ISFSCallBack cb);
FSError ISFS_SetAttr(const u8 *name, SKGroupId groupID, u32 attr, u32 ownerAcc, u32 groupAcc, u32 othersAcc);
FSError ISFS_SetAttrAsync(const u8 *name, SKGroupId groupID, u32 attr, u32 ownerAcc, u32 groupAcc, u32 othersAcc, ISFSCallBack cb);
FSError ISFS_GetAttr(const u8 *name, SKOwnerId *ownerId, SKGroupId *groupId, u32 *attr, u32 *ownerAcc, u32 *groupAcc, u32 *othersAcc);
FSError ISFS_DeleteAsync(const u8 *name, ISFSCallBack cb);
FSError ISFS_Rename(const u8 *oldName, const u8 *newName);
FSError ISFS_RenameAsync(const u8 *oldName, const u8 *newName, ISFSCallBack cb);
FSError ISFS_CreateFileAsync(const u8 *fname, SKOwnerId ownerId, SKGroupId groupId, u32 fileAttr, u32 ownerAcc, u32 groupAcc, u32 othersAcc, ISFSCallBack cb);
FSError ISFS_GetFileStats(s32 fd, FSFileStats *stats);
FSError ISFS_Seek(s32 fd, s32 offset, s32 whence);
FSError ISFS_ReadAsync(s32 fd, u8 *buf, u32 size, ISFSCallBack cb);
FSError ISFS_WriteAsync(s32 fd, const u8 *buf, u32 size, ISFSCallBack cb);
FSError ISFS_CloseAsync(s32 fd, ISFSCallBack cb);

// ?
FSError ISFS_SetFileVersionControl(const u8 *fname, u32 enable);
FSError ISFS_SetFileVersionControlAsync(const u8 *fname, u32 enable, ISFSCallBack cb);

// For Nintendo use
FSError ISFS_Format(void);
FSError ISFS_FormatAsync(ISFSCallBack cb);


#ifdef __cplusplus
}
#endif

#endif // end of ISFSEMU_H__


#endif  // in order to invalidate this header file.
