/*---------------------------------------------------------------------------*
  Project:  Revolution WFS abstraction layer library
  File:     wfa.h

  Copyright 2007-2008 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.14  2008/01/10 11:59:10  ooizumi
  Added result definitions.

  Revision 1.13  2007/12/28 05:40:00  ooizumi
  Added directory search APIs.

  Revision 1.12  2007/12/27 02:44:08  ooizumi
  Changed WFA_PERM_* values.

  Revision 1.11  2007/12/26 09:31:29  ooizumi
  Added WFAGetHomeDir.

  Revision 1.10  2007/12/26 00:08:32  ooizumi
  Added WFA_RESULT_MAX_HANDLES.

  Revision 1.9  2007/12/18 10:36:15  ooizumi
  Added WFA[Set|Get]UserData.

  Revision 1.8  2007/12/13 01:19:38  ooizumi
  Changed WFAGetLength spec.

  Revision 1.7  2007/12/10 23:37:17  ooizumi
  Modified WFADirEntryIsDir. *This is workaround. Finaly it should be fixed.

  Revision 1.6  2007/12/08 03:15:40  ooizumi
  Added new members to WFACommandBlock.
  Changed WFSDirEntryIsDir to macro.

  Revision 1.5  2007/12/07 04:05:28  ooizumi
  Added synchronous API's definitions.

  Revision 1.4  2007/12/07 02:10:31  ooizumi
  Added several definitions.

  Revision 1.3  2007/11/30 07:55:00  ooizumi
  Added WFADir API difinitions.

  Revision 1.2  2007/11/28 09:44:57  ooizumi
  Changed WFACreateAndOpenEx.

  Revision 1.1  2007/11/28 06:51:04  ooizumi
  Initial check-in.

  $NoKeywords: $
*---------------------------------------------------------------------------*/

#ifndef __WFA_H__
#define __WFA_H__

#include <revolution.h>
#include <revolution/wfstypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WFA_MIN_WORK_SPACE_SIZE  WFS_MIN_WORK_SPACE_SIZE

typedef u32 WFAState;
typedef u8  WFAAccess;

typedef struct WFACommandBlock WFACommandBlock;
typedef struct WFAFileInfo     WFAFileInfo;
typedef struct WFADir          WFADir;
typedef struct WFADirEntry     WFADirEntry;
typedef struct WFAStatus       WFAStatus;

/*---------------------------------------------------------------------------*
  Name:         WFACallback

  Description:  WFA callback function

  Arguments:    result      If the function that set the callback succeeds,
                            it is the number of bytes transferred. If that
                            function fails, it is -1.
                block       command block address.

  Returns:      None.
 *---------------------------------------------------------------------------*/
typedef void (*WFACallback)(s32 result, WFACommandBlock* block);

struct WFACommandBlock
{
    WFACommandBlock* next;
    WFACommandBlock* prev;

    u32              command;
    s32              state;
    const utf8*      path;
    void*            addr;
    u32              length;
    u32              offset;

    u32              currTransferSize;
    u32              transferredSize;

    void*            info;

    WFACallback      callback;

    void*            userData;
};

struct WFAFileInfo
{
    u32        handle;      // file handle
    WFAAccess  accType;
};

struct WFADir
{
    u32                handle;      // directory handle
    WFSFileAttributes  attr;
    utf8               path[WFS_MAX_PATH_NAME_SIZE+1];
    u32                location;
};

struct WFADirEntry
{
    WFSFileInfo  info;
};

struct WFAStatus
{
    WFSFileAttributes  attr;
};

#define WFA_STATE_FATAL_ERROR       -1
#define WFA_STATE_END               0
#define WFA_STATE_BUSY              1
#define WFA_STATE_WAITING           2
#define WFA_STATE_DEVICE_ATTACHED   3
#define WFA_STATE_NO_DEVICE         4

#define WFA_RESULT_OK               0
#define WFA_RESULT_ACCESS           -1
#define WFA_RESULT_PERMISSION       -2
#define WFA_RESULT_CORRUPTION       -3
#define WFA_RESULT_AREA_FULL        -4
#define WFA_RESULT_MAX_HANDLES      -5
#define WFA_RESULT_ALREADY_EXISTS   -6
#define WFA_RESULT_NOT_FOUND        -7
#define WFA_RESULT_NOT_EMPTY        -8
#define WFA_RESULT_FILE_OPEN        -9
#define WFA_RESULT_FATAL_ERROR      -128

#define WFA_PERM_OTHER_READ        WFS_PERM_OTHER_READ
#define WFA_PERM_OTHER_WRITE       WFS_PERM_OTHER_WRITE
#define WFA_PERM_OTHER_RW          (WFA_PERM_OTHER_READ | WFA_PERM_OTHER_WRITE)
#define WFA_PERM_GROUP_READ        WFS_PERM_GROUP_READ
#define WFA_PERM_GROUP_WRITE       WFS_PERM_GROUP_WRITE
#define WFA_PERM_GROUP_RW          (WFA_PERM_GROUP_READ | WFA_PERM_GROUP_WRITE)
#define WFA_PERM_OWNER_READ        WFS_PERM_OWNER_READ 
#define WFA_PERM_OWNER_WRITE       WFS_PERM_OWNER_WRITE
#define WFA_PERM_OWNER_RW          (WFA_PERM_OWNER_READ | WFA_PERM_OWNER_WRITE)
#define WFA_PERM_ALL_RW_MASK       (WFA_PERM_OTHER_RW | WFA_PERM_GROUP_RW | WFA_PERM_OWNER_RW)
#define WFA_PERM_RESERVED          ~WFA_PERM_ALL_RW_MASK

#define WFA_ACCESS_READ  WFS_ACCESS_READ
#define WFA_ACCESS_WRITE WFS_ACCESS_WRITE
#define WFA_ACCESS_RW    (WFA_ACCESS_READ | WFA_ACCESS_WRITE)

void WFAInit(void *workBuffer, u32 workBufferSize);


s32 WFAGetCommandBlockStatus(const WFACommandBlock* block);

s32 WFAGetDeviceStatus(void);


s32  WFAOpen     (WFACommandBlock* block, const utf8* path, WFAAccess accType, WFAFileInfo* info);
BOOL WFAOpenAsync(WFACommandBlock* block, const utf8* path, WFAAccess accType, WFAFileInfo* info, WFACallback callback);

s32  WFACreateAndOpenEx     (WFACommandBlock* block, const utf8* path, u32 perm, u32 size, WFAFileInfo* info);
BOOL WFACreateAndOpenExAsync(WFACommandBlock* block, const utf8* path, u32 perm, u32 size, WFAFileInfo* info, WFACallback callback);

#define WFACreateAndOpen(block, path, perm, info)  \
    WFACreateAndOpenEx((block), (path), (perm), 0, (info))
#define WFACreateAndOpenAsync(block, path, perm, info, callback)  \
    WFACreateAndOpenExAsync((block), (path), (perm), 0, (info), (callback))

s32  WFARead     (WFACommandBlock* block, WFAFileInfo* info, void* addr, s32 length, u32 offset);
BOOL WFAReadAsync(WFACommandBlock* block, WFAFileInfo* info, void* addr, s32 length, u32 offset, WFACallback callback);

s32  WFAWrite     (WFACommandBlock* block, WFAFileInfo* info, const void* addr, s32 length, u32 offset);
BOOL WFAWriteAsync(WFACommandBlock* block, WFAFileInfo* info, const void* addr, s32 length, u32 offset, WFACallback callback);

s32  WFACloseEx     (WFACommandBlock* block, WFAFileInfo* info, u32 size);
BOOL WFACloseExAsync(WFACommandBlock* block, WFAFileInfo* info, u32 size, WFACallback callback);

s32  WFAClose     (WFACommandBlock* block, WFAFileInfo* info);
BOOL WFACloseAsync(WFACommandBlock* block, WFAFileInfo* info, WFACallback callback);

s32  WFAGetLength     (WFACommandBlock* block, WFAFileInfo *info, u32 *length);
BOOL WFAGetLengthAsync(WFACommandBlock* block, WFAFileInfo *info, u32 *length, WFACallback callback);


s32  WFAOpenDir     (WFACommandBlock *block, const utf8 *path, WFADir *dir);
BOOL WFAOpenDirAsync(WFACommandBlock *block, const utf8 *path, WFADir *dir, WFACallback callback);

s32  WFAOpenDirEx     (WFACommandBlock *block, const utf8 *pattern, WFADir *dir);
BOOL WFAOpenDirExAsync(WFACommandBlock *block, const utf8 *pattern, WFADir *dir, WFACallback callback);

s32  WFAReadDir     (WFACommandBlock *block, WFADir *dir, WFADirEntry *entry);
BOOL WFAReadDirAsync(WFACommandBlock *block, WFADir *dir, WFADirEntry *entry, WFACallback callback);

s32  WFARewindDir     (WFACommandBlock *block, WFADir *dir);
BOOL WFARewindDirAsync(WFACommandBlock *block, WFADir *dir, WFACallback callback);

s32  WFACloseDir     (WFACommandBlock *block, WFADir *dir);
BOOL WFACloseDirAsync(WFACommandBlock *block, WFADir *dir, WFACallback callback);

s32  WFACreateDir     (WFACommandBlock *block, const utf8 * path);
BOOL WFACreateDirAsync(WFACommandBlock *block, const utf8 * path, WFACallback callback);

s32  WFAChangeDir     (WFACommandBlock *block, const utf8 *path);
BOOL WFAChangeDirAsync(WFACommandBlock *block, const utf8 *path, WFACallback callback);

s32  WFAGetFreeSpaceSize     (WFACommandBlock *block, const utf8 *path, u64 *size);
BOOL WFAGetFreeSpaceSizeAsync(WFACommandBlock *block, const utf8 *path, u64 *size, WFACallback callback);

s32 WFAGetCurrentDir(utf8 *buffer, s32 size);
s32 WFAGetHomeDir   (utf8 *buffer, s32 size);


s32  WFADelete     (WFACommandBlock *block, const utf8 *path);
BOOL WFADeleteAsync(WFACommandBlock *block, const utf8 *path, WFACallback callback);

s32  WFAMove     (WFACommandBlock *block, const utf8 *srcPath, const utf8 *dstPath);
BOOL WFAMoveAsync(WFACommandBlock *block, const utf8 *srcPath, const utf8 *dstPath, WFACallback callback);

#define WFADirEntryIsDir(entry) \
  (((entry)->info.attr.nFlags & WFS_FLAG_IS_A_DIRECTORY) ? TRUE : FALSE)

#define WFAStatusIsDir(status) \
  (((status)->attr.nFlags & WFS_FLAG_IS_A_DIRECTORY) ? TRUE : FALSE)

s32  WFAGetStatus     (WFACommandBlock *block, const utf8 *path, WFAStatus* status);
BOOL WFAGetStatusAsync(WFACommandBlock *block, const utf8 *path, WFAStatus* status, WFACallback callback);


#define WFASetUserData(block, data) ((block)->userData = (data))
#define WFAGetUserData(block)       ((block)->userData)

// wfs related error code
#define WFA_ERROR_NONE             0
#define WFA_ERROR_INVALID          1
#define WFA_ERROR_ACCESS           2
#define WFA_ERROR_FILE_TOO_BIG     3
#define WFA_ERROR_NO_CHANGE_FILE   4
#define WFA_ERROR_WRITE_PROTECTED  5
#define WFA_ERROR_PERMISSION       6
#define WFA_ERROR_INHERITANCE      7
#define WFA_ERROR_AUTHENTICATION   8
#define WFA_ERROR_DIRECTORY_FULL   9
#define WFA_ERROR_DIRECTORY_QUOTA  10
#define WFA_ERROR_DEV_FULL         11
#define WFA_ERROR_MAX_HANDLES      12
#define WFA_ERROR_ALREADY_EXISTS   13
#define WFA_ERROR_NOT_FOUND        14
#define WFA_ERROR_NOT_EMPTY        15
#define WFA_ERROR_FILE_OPEN        16

#define WFA_ERROR_UNKNOWN          127
#define WFA_ERROR_FATAL_ERROR      128
// wfa related error code
#define WFA_ERROR_UNEXPECTED       256

s32 WFAGetLastError(void);

const utf8* WFAGetCurrentVolumeId(void);

void WFASetHomeDir(void);

#ifdef __cplusplus
}
#endif

#endif //define __WFA_H__
