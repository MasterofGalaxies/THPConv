/*---------------------------------------------------------------------------*
  Project:  Launch NAND application and handling
  File:     OSNandbootInfo.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2007/06/04 11:16:42  ooizumi
  Defined OS_NANDBOOT_FLAG_WC24.

  Revision 1.4  2007/04/09 06:16:43  wada_jumpei
  Added MEM2 size simulation and IDE debug

  Revision 1.3  2007/03/22 08:21:38  wada_jumpei
  Changed functions to get last applications' information

  Revision 1.2  2007/03/14 09:35:42  wada_jumpei
  Added some functions to get information about last application

  Revision 1.1  2006/11/29 01:50:19  wada_jumpei
  Initial check in

 *---------------------------------------------------------------------------*/

#ifndef __OSNANDBOOTINFO_H__
#define __OSNANDBOOTINFO_H__

#include <revolution/types.h>
#include <private/OSLaunchTitle.h>
#include <secure/OSBootInfo2.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OS_NANDBOOT_INFO_PATH   "/shared2/sys/NANDBOOTINFO"
#define OS_NANDBOOT_INFO_PERM \
    (NAND_PERM_OWNER_READ | NAND_PERM_OWNER_WRITE | \
     NAND_PERM_GROUP_READ | NAND_PERM_GROUP_WRITE | \
     NAND_PERM_OTHER_READ | NAND_PERM_OTHER_WRITE)
#define OS_NANDBOOT_INFO_ATTR   0x00

#define OS_NANDBOOT_FLAG_REBOOT  0x01
#define OS_NANDBOOT_FLAG_LAUNCH  0x02
#define OS_NANDBOOT_FLAG_RETURN  0x04
#define OS_NANDBOOT_FLAG_WC24    0x08
#define OS_NANDBOOT_FLAG_DEBUG   0x80

typedef struct{
  u32 CheckSum;
  u32 ArgOffset;
  u8  reserved[2];
  u8  LastAppType;
  u8  ReturnType;
  u32 ArgValue;
  u8  padding[8];
  u64 LastTitleId;

  u8  args[OS_BI2_ARGSIZE_MAX];
  
}OSNandbootInfo;

typedef struct{
  u32 CheckSum;
  u32 ArgOffset;
  u8  reserved[2];
  u8  LastAppType;
  u8  ReturnType;
  u32 ArgValue;
  u8  padding[8];
  u64 LastTitleId;

}OSNandbootInfoHeader;

BOOL __OSCreateNandbootInfo(void);
BOOL __OSWriteNandbootInfo(OSNandbootInfo *info);
BOOL __OSReadNandbootInfo(OSNandbootInfo *info);

#ifdef __cplusplus
}
#endif

#endif // __OSNANDBOOTINFO_H__

