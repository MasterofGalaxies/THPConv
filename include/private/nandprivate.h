/*---------------------------------------------------------------------------*
  Project:      NAND flash private library
  File:         nandprivate.h
  Programmer:   HIRATSU Daisuke

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/08/16 09:32:16  hiratsu
  Some APIs are moved.

  Revision 1.3  2006/08/03 12:56:16  hiratsu
  NANDPrivateSafe* series are available.

  Revision 1.2  2006/06/26 11:42:29  hiratsu
  Added NANDPrivateChangeDir[Async]() and  NANDPrivateGetType[Async]().

  Revision 1.1  2006/05/19 08:20:39  hiratsu
  Secret NAND API.

 *---------------------------------------------------------------------------*/

#ifndef __NANDPRIVATE_H__
#define __NANDPRIVATE_H__


#include <revolution/types.h>
#include <revolution/nand.h>

#ifdef __cplusplus
extern "C" {
#endif


//    File access API
s32   NANDPrivateCreate        (const char *path, u8 perm, u8 attr);
s32   NANDPrivateCreateAsync   (const char *path, u8 perm, u8 attr, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateOpen          (const char *path, NANDFileInfo *info, u8 accType);
s32   NANDPrivateOpenAsync     (const char *path, NANDFileInfo *info, u8 accType, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateSafeOpen      (const char *path, NANDFileInfo *info, u8 accType, void *buf, u32 length);
s32   NANDPrivateSafeOpenAsync (const char *path, NANDFileInfo *info, u8 accType, void *buf, u32 length, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateSimpleSafeOpen     (const char *path, NANDFileInfo *info, const u8 accType, void *buf, const u32 length);
s32   NANDPrivateSimpleSafeOpenAsync(const char *path, NANDFileInfo *info, const u8 accType, void *buf, const u32 length, NANDCallback cb, NANDCommandBlock *block);

//    Directory access API
s32   NANDPrivateReadDir       (const char *path, char *nameList, u32 *num);
s32   NANDPrivateReadDirAsync  (const char *path, char *nameList, u32 *num, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateCreateDir     (const char *path, u8 perm, u8 attr);
s32   NANDPrivateCreateDirAsync(const char *path, u8 perm, u8 attr, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateChangeDir     (const char *path);
s32   NANDPrivateChangeDirAsync(const char *path, NANDCallback cb, NANDCommandBlock *block);

//    File or Directory access API
s32   NANDPrivateDelete        (const char *path);
s32   NANDPrivateDeleteAsync   (const char *path, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateMove          (const char *path, const char *destDir);
s32   NANDPrivateMoveAsync     (const char *path, const char *destDir, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateGetStatus     (const char *path,       NANDStatus *stat);
s32   NANDPrivateGetStatusAsync(const char *path,       NANDStatus *stat, NANDCallback cb, NANDCommandBlock *block);
s32   NANDPrivateSetStatus     (const char *path, const NANDStatus *stat);
s32   NANDPrivateSetStatusAsync(const char *path, const NANDStatus *stat, NANDCallback cb, NANDCommandBlock *block); 
s32   NANDPrivateGetType       (const char *path, u8 *type);
s32   NANDPrivateGetTypeAsync  (const char *path, u8 *type, NANDCallback cb, NANDCommandBlock *block);


#ifdef __cplusplus
}
#endif


#endif // end of __NANDPRIVATE_H__
