/*---------------------------------------------------------------------------*
  Project:    SD Card adaptor wrapper API
  File:       sdwp.h
  Programmer: HIRATSU Daisuke

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/02/08 12:45:05  hiratsu
  Added new error code.
  Implemented SDWPGetAttribute().  But it is not tested well.

  Revision 1.3  2006/02/07 06:58:12  hiratsu
  Fixed typedef-related bug.

  Revision 1.2  2006/02/03 12:49:41  hiratsu
  Added seek function.
  Removed seek operation from Read/Write API.

  Revision 1.1  2006/01/20 08:53:19  hiratsu
  SD Card adaptor wrapper API.

 *---------------------------------------------------------------------------*/


#ifndef __SDWP_H__
#define __SDWP_H__

#include <dolphin.h>
#include <dolphin/sd.h>

#ifdef __cplusplus
extern "C" {
#endif


#define SDWP_SLOT_A        0
#define SDWP_SLOT_B        1

#define SDWP_FILENAME_MAX 11
#define SDWP_DIRNAME_MAX  10


#define SDWP_RESULT_OK               0         // [FS_ERROR_OK]
#define SDWP_RESULT_NOT_EXIST       -1         // [FS_ERROR_NOEXISTS]
#define SDWP_RESULT_EXIST           -2         // [FS_ERROR_EXISTS]
#define SDWP_RESULT_NOENT           -3         // [FS_ERROR_MAXFILES]
#define SDWP_RESULT_INSSPACE        -4         // [FS_ERROR_MAXBLOCKS]
#define SDWP_RESULT_NOPERM          -5         // [FS_ERROR_ACCESS]
#define SDWP_RESULT_NAMETOOLONG     -6         // ??
#define SDWP_RESULT_NOT_EMPTY       -7         // [FS_ERROR_NOTEMPTY]
#define SDWP_RESULT_DESC_INVALID    -8         // [FS_ERROR_BADFD]
#define SDWP_RESULT_CORRUPT         -9         // [FS_ERROR_CORRUPT]
#define SDWP_RESULT_ARG_INVALID    -10         // [FS_ERROR_INVALID]
#define SDWP_RESULT_NOTFORMATTED   -11         // [FS_ERROR_NOTREADY]
#define SDWP_RESULT_TYPE_MISMATCH  -30         // file type is different / mismatching
#define SDWP_RESULT_SD_ERROR       -64         // only for NAND emulator library.
#define SDWP_RESULT_FATAL_ERROR   -128

#define SDWP_PERM_OWNER_R   0x80000000
#define SDWP_PERM_OWNER_W   0x40000000
#define SDWP_PERM_GROUP_R   0x20000000
#define SDWP_PERM_GROUP_W   0x10000000
#define SDWP_PERM_OTHER_R   0x08000000
#define SDWP_PERM_OTHER_W   0x04000000

#define SDWP_ATTR_NO_COPY   0x00000001
#define SDWP_ATTR_NO_RENAME 0x00000002

#define SDWP_SEEK_SET       0
#define SDWP_SEEK_CUR       1
#define SDWP_SEEK_END       2

typedef struct SDWPFileInfo{
    SD_FILE *fp;
} SDWPFileInfo;

typedef struct SDWPDirInfo{
    SD_DIR *dir;
} SDWPDirInfo;

typedef struct SDWPDirEntry{
    SD_ENTRY ent;
} SDWPDirEntry;


s32 SDWPInit         (int slot);
s32 SDWPFinalize     (void);
s32 SDWPCreate       (const char *filename, u32 perm, u32 attr);
s32 SDWPDelete       (const char *filename);
s32 SDWPOpen         (SDWPFileInfo *info, const char *filename, u32 perm);
s32 SDWPClose        (SDWPFileInfo *info);
s32 SDWPSeek         (SDWPFileInfo *info, s32  offset, s32 whence);
s32 SDWPTell         (SDWPFileInfo *info, u32 *offset            );
s32 SDWPRead         (SDWPFileInfo *info, void *buf, u32 length);
s32 SDWPWrite        (SDWPFileInfo *info, void *buf, u32 length);
s32 SDWPRename       (const char *oldname, const char *newname);
s32 SDWPGetSize      (SDWPFileInfo *info, u32 *size);
s32 SDWPGetAttribute (const char *path, u16 *attr);
s32 SDWPSetAttribute (const char *path, u16  attr);
s32 SDWPGetPermision (SDWPFileInfo *info, u32 *perm);
s32 SDWPSetSize      (SDWPFileInfo *info, u32  size);
s32 SDWPSetPermision (SDWPFileInfo *info, u32  perm);

s32 SDWPCreateDir    (const char *dirname, u32 perm, u32 attr);
s32 SDWPDeleteDir    (const char *dirname);
s32 SDWPCountDir     (char *dirname, u32 *files);                 // Count number of contents under "dirname"
s32 SDWPReadDir      (char *dirname, char *nameList, u32 *len);
s32 SDWPChangeDir    (const char *dirname);
s32 SDWPGetCurrentDir(char *dirname);

s32 SDWPFormat        (void); 
s32 SDWPGetFreeSpace  (u32 *bytes);
s32 SDWPGetVacantFiles(u32 *files);

s32 SDWPReadFileInfo  (const SDWPFileInfo *info, u32 *size, u16 *attr);
s32 SDWPReadDirEntry  (const SDWPDirEntry *dirent, char *dirname, u16 *attr);


#ifdef __cplusplus
}
#endif

#endif  // __SDWP_H__
