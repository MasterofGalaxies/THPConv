/*---------------------------------------------------------------------------*
  Project:      APIs for channel install sequence
  File:         OSInstall.h

  Copyright (C) 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2007/07/19 06:05:07  wada_jumpei
  Added OSGetLaunchCode.

  Revision 1.3  2007/04/23 00:22:27  ooizumi
  Changed struct name.

  Revision 1.2  2007/04/17 08:06:55  ooizumi
  Added return code from channel installer.

  Revision 1.1  2007/04/13 12:55:52  ooizumi
  Initial check-in.

 *---------------------------------------------------------------------------*/

#ifndef __OSINSTALL_H__
#define __OSINSTALL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/nand.h>
#include <private/OSTitle.h>

typedef struct OSInstallInfo
{
    char*   fileName;  // channel application's file name to install
    u16*    titleName; // channel application's title name to draw on scree
} OSInstallInfo;

#define OSINSTALL_CHECK_SYS_INSSPACE     0x00000001
#define OSINSTALL_CHECK_SYS_INSINODE     0x00000002
#define OSINSTALL_CHECK_SYS_INSCHAN      0x00000004

#define OSINSTALL_RESULT_OK                0 
#define OSINSTALL_RESULT_NOINFO         ( -1)
#define OSINSTALL_RESULT_ALLOC_FAILED   ( -2)
#define OSINSTALL_RESULT_BUSY           ( -3)
#define OSINSTALL_RESULT_INVALID        ( -4)
#define OSINSTALL_RESULT_UNKNOWN        (-64)
#define OSINSTALL_RESULT_FATAL_ERROR   (-128)

#define OSINSTALL_RETURN_OK             0x00000000 // No error
#define OSINSTALL_RETURN_INVALID        0x00000001 // Invalid parameters
#define OSINSTALL_RETURN_INIT_FAILED    0x00000002 // Failed to initialize
#define OSINSTALL_RETURN_NOEXISTS       0x00000004 // Wad file does not exist in disc
#define OSINSTALL_RETURN_EXISTS         0x00000008 // All files are already installed
#define OSINSTALL_RETURN_MAXBLOCKS      0x00000010 // Ran out of FS blocks
#define OSINSTALL_RETURN_MAXFILES       0x00000020 // Ran out of inode entries 
#define OSINSTALL_RETURN_MAXCHANNELS    0x00000040 // Ran out of channel entries
#define OSINSTALL_RETURN_IMPORT_FAILED  0x00000080 // Failed to import
#define OSINSTALL_RETURN_UNKNOWN        0x40000000 // Uknown error
#define OSINSTALL_RETURN_FATAL_ERROR    0x80000000 // Fatal error (never return to app)

typedef struct OSInstallCommandBlock
{
    void             *userData;

    // Do not access below members.
    void             *callback;
    u32              *answer;
    u32               nandAnswer;
    NANDCommandBlock  nandCb;
} OSInstallCommandBlock;

typedef void (*OSInstallCallback)( s32 result, OSInstallCommandBlock *block );

void OSLaunchInstaller(u32 launchCode, u16* gameTitleName, OSInstallInfo* info);

s32  OSCheckInstall(u32 num, u32 fsBlock, u32 inode, u32* answer);
s32  OSCheckInstallAsync(u32 num, u32 fsBlock, u32 inode, u32* answer, OSInstallCallback cb, OSInstallCommandBlock *block);
u32  OSGetLaunchCode(void);

#ifdef __cplusplus
}
#endif

#endif // __OSINSTALL_H__
