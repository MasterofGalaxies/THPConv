/*---------------------------------------------------------------------------*
  Project:  Revolution WFS library
  File:     wfstypes.h

  Copyright 2008 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $

*---------------------------------------------------------------------------*/

#ifndef __WFSTYPES_H__
#define __WFSTYPES_H__

// ---------------------------------------------------------------------
// wfstypes.h - Wii File System (WFS) API
// ---------------------------------------------------------------------

// Provides a standard interface to the Wii file system

#include <revolution.h>

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
// WFS attributes
// ---------------------------------------------------------------------
#define WFS_MAX_FILE_SIZE        4294967295
#define WFS_MAX_PATH_DEPTH       31   // (ToDo: Directories must keep track of their deepest sub-path, so we can validate directory move requests)

// The following represent the maximum size of string fields in Bytes, not including the terminating NULL character.
#define WFS_MAX_FILE_NAME_SIZE   255  // Does not include the path, just the file name.
#define WFS_MAX_PATH_NAME_SIZE   511  // (ToDo: Directories must keep track of their longest sub-path, so we can validate directory move/rename requests)
#define WFS_MAX_DEVICE_NAME_SIZE 15   // maximum size of a device name
#define WFS_MAX_VOLUME_ID_SIZE   7    // maximum size of WFS Volume Id string (This is a randomly assigned string of characters, e.g., 1a2b3c4)

#define WFS_MIN_WORK_SPACE_SIZE  (40 * 1024)  // Used for async thread stack, and queueing async parameters


typedef char utf8;           // ToDo: Perhaps utf8 should be changed to WFSChar?
typedef u32  WFSFileTime;    // Time in seconds since 00:00, 1st January, 2000
typedef u32  WFSFileSize;    // Size of file
typedef u32  WFSContentIdx;  // Used to identify files which belong to the same unit of purchased content, and control access to them
typedef u8   WFSBool;

//------------------------------------------------------------------------------------------------------
//  WFS Path Names
//------------------------------------------------------------------------------------------------------
//  Throughout the WFS API, path names can be absolute, or relative to the CurrentDirectory.
//
//  The following conventions are used:
//  File names are read and written case-sensitively, but compared case-insensitively.
//  File names can use any characters except * ? /
//  WFS uses forwards slashes / as directory separators.
//  * and ? are used to specify wild card patterns to directory search.
//  Non-ascii file names are supported using the multi-byte utf-8 format.
//  Path names must be NULL terminated.
//
//  File names including . or ~ are possible, except:
//  The following names have special meanings, and cannot be used as file names: "~", ".", ".."
//  "" or "." refers to the current directory.
//  ".." refers to the parent directory.
//  "~" refers to a title's home directory.
//
//  Path names starting with "/" are absolute.
//  Path names starting with "~/" are relative to the title's home directory,
//  otherwise they are relative to CurrentDirectory.
//
//  All devices have a device name entry in "/dev". If the WFSDevType (obtained via WFSGetDeviceInfo)
//  of the device is WFS_DEVTYPE_SD or WFS_DEVTYPE_USB_MSC, the device may or may not have
//  a WFS volume. A WFS volume can be created on the device with WFSInitializeDevice. At volume
//  creation time, the volume is assigned a (relatively) unique Volume Id.  The device's WFS volume 
//  is made accessible by mounting it.  After a volume is mounted, it is accessible as
//  "/vol/VolumeId" where VolumeId is the volume's unique Id.  The "/vol" directory has an entry for
//  each mounted WFS volume. Even with mounted devices, a device name entry for mounted volumes 
//  remains in "/dev" for that device.
//------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------
// WFSFileHandle, WFSSearchDirectoryHandle
// ---------------------------------------------------------------------

typedef u32 WFSFileHandle;
typedef u32 WFSSearchDirectoryHandle;

// ---------------------------------------------------------------------
// WFSFileInfo
// ---------------------------------------------------------------------

typedef struct {
    union {
        WFSFileSize nFileSize;    // Assuming this is a file
        u32         nNumEntries;  // Assuming this is a directory
    };
    u32           nFlags;
    WFSContentIdx nCidx;
    WFSFileTime   timeCreated;
    WFSFileTime   timeUpdated;
} WFSFileAttributes;

typedef struct {
    WFSFileAttributes attr;
    utf8              sFileName[WFS_MAX_FILE_NAME_SIZE+1];
} WFSFileInfo;

// ---------------------------------------------------------------------
// WFS File Attributes
// ---------------------------------------------------------------------
#define WFS_PERM_OWNER_READ        0x00000001     // Note: OWNER_READ permission should always be on
#define WFS_PERM_OWNER_WRITE       0x00000002     // Note: this is not a valid value by itself (cannot be owner write only)
#define WFS_PERM_OWNER_RW          (WFS_PERM_OWNER_READ | WFS_PERM_OWNER_WRITE)  // owner read+write
#define WFS_PERM_GROUP_READ        0x00000004
#define WFS_PERM_GROUP_WRITE       0x00000008
#define WFS_PERM_GROUP_RW          (WFS_PERM_GROUP_READ | WFS_PERM_GROUP_WRITE)  // group read+write
#define WFS_PERM_OTHER_READ        0x00000010
#define WFS_PERM_OTHER_WRITE       0x00000020
#define WFS_PERM_OTHER_RW          (WFS_PERM_OTHER_READ | WFS_PERM_OTHER_WRITE)  // world read+write
#define WFS_PERM_ALL_RW_MASK       0x0000003f
#define WFS_PERM_NO_CHANGE_SIZE    0x00000040     // File size cannot be changed after creation. (Owner can still change size after clearing this flag)
#define WFS_PERM_NO_MOVE_OR_DELETE 0x00000080     // File cannot be moved, renamed, or deleted. (Owner can still move, rename, or delete after clearing this flag. SYSTEM can always move, rename, or delete)
#define WFS_FLAG_IS_A_DIRECTORY    0x00000100     // This flag can not be changed after creation.
#define WFS_FLAG_CONTENT_DIRECTORY 0x00000200     // This flag must be set on directories that will contain purchased content. If it is set, then it is automatically inherited by sub-directories. This flag can not be changed after creation.

// ---------------------------------------------------------------------
// WFSAccess
// ---------------------------------------------------------------------
typedef enum {
    WFS_ACCESS_READ = 1,
    WFS_ACCESS_WRITE,
    WFS_ACCESS_RW
} WFSAccess;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //define __WFSTYPES_H__
