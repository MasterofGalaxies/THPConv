/*---------------------------------------------------------------------------*
  Project:      NAND flash library (emulation version)
  File:         nandEmu.h
  Programmer:   HIRATSU Daisuke

  Copyright (C) 2006 Nintendo  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2006/01/30 09:23:31  hiratsu
  This file is not maintained anymore.
  Please include nand.h instead of this file.

  Revision 1.2  2006/01/25 07:41:04  hiratsu
  Unified argument name.

  Revision 1.1  2006/01/23 11:44:43  hiratsu
  Initial check-in for NAND flash library (emulation version)

 *---------------------------------------------------------------------------*/


#if 0   // To invalidate entire header file.


#ifndef NANDEMU_H__
#define NANDEMU_H__


#include <revolution/types.h>


#ifdef __cplusplus
extern "C" {
#endif


#define NAND_RESULT_OK                0 
#define NAND_RESULT_ACCESS         ( -1)
#define NAND_RESULT_BADFD          ( -2)
#define NAND_RESULT_BUSY           ( -3)
#define NAND_RESULT_CORRUPT        ( -4)
#define NAND_RESULT_ECC_CRIT       ( -5)
#define NAND_RESULT_EXISTS         ( -6)
#define NAND_RESULT_INVALID        ( -7)
#define NAND_RESULT_MAXBLOCKS      ( -8)
#define NAND_RESULT_MAXFD          ( -9)
#define NAND_RESULT_MAXFILES       (-10)
#define NAND_RESULT_NOEXISTS       (-11)
#define NAND_RESULT_NOTEMPTY       (-12)
#define NAND_RESULT_NOTREADY       (-13)
#define NAND_RESULT_UNKNOWN        (-14)
#define NAND_RESULT_FATAL_ERROR   (-128)

#define NAND_PERM_OWNER_READ   0x80
#define NAND_PERM_OWNER_WRITE  0x40
#define NAND_PERM_GROUP_READ   0x20
#define NAND_PERM_GROUP_WRITE  0x10
#define NAND_PERM_OTHER_READ   0x08
#define NAND_PERM_OTHER_WRITE  0x04

#define NAND_PERM_OWNER_MASK   (NAND_PERM_OWNER_READ | NAND_PERM_OWNER_WRITE)
#define NAND_PERM_GROUP_MASK   (NAND_PERM_GROUP_READ | NAND_PERM_GROUP_WRITE)
#define NAND_PERM_OTHER_MASK   (NAND_PERM_OTHER_READ | NAND_PERM_OTHER_WRITE)

#define NAND_ATTR_NO_COPY      0x01
#define NAND_ATTR_NO_RENAME    0x02

#define NAND_SLOT_A               0   // only for NAND emulator library.
#define NAND_SLOT_B               1   // only for NAND emulator library.

#define NAND_ACCESS_READ       0x02
#define NAND_ACCESS_WRITE      0x01


typedef struct NANDFileInfo
{
    s32 fileDescriptor;
} NANDFileInfo;

s32 NANDInit         (int slot);
s32 NANDFinalize     (void);          // only for NAND emulator library.

s32 NANDCreate       (const char *filename, u8 perm, u8 attr);
s32 NANDDelete       (const char *filename);
s32 NANDOpen         (NANDFileInfo *info, const char *filename, u8 accType);
s32 NANDClose        (NANDFileInfo *info);
s32 NANDRead         (NANDFileInfo *info,       void *buf, u32 length);
s32 NANDWrite        (NANDFileInfo *info, const void *buf, u32 length);

s32 NANDReadDir      (const char *dirName, char *nameList, u32 *length);


#ifdef __cplusplus
}
#endif


#endif // end of NANDEMU_H__


#endif // #if 0
