/*---------------------------------------------------------------------------*
  Project:  header file for Dolphin OS exec
  File:     OSExec.h

  Copyright 2004 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    1     04/01/30 16:39 Hashida
    Added OSExec.
    Converted the reboot module to dol.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/
#ifndef __OSEXEC_H__
#define __OSEXEC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <secure/boot.h>

#define OS_EXEC_WORK_START              0x81280000
#define OS_EXEC_WORK_END                0x812f0000

// for __OSExecDol
#define OS_EXEC_EXEC_DEFAULTDOL         0
#define OS_EXEC_EXEC_REBOOTDOL          0xffffffff

typedef struct
{
    BOOL        valid;
    u32         restartCode;
    u32         bootDol;
    void*       regionStart;
    void*       regionEnd;
    BOOL        argsUseDefault;
    void*       argsAddr;       // valid only when argsUseDefault = FALSE
    
} OSExecParams;

void __OSBootDol(u32 doloffset, u32 restartCode, char* const argv[]);
void __OSBootDolSimple(u32 doloffset, u32 restartCode,
                       void* regionStart, void* regionEnd,
                       BOOL argsUseDefault, s32 argc, char* argv[]);

void __OSGetExecParams(OSExecParams* params);
void __OSSetExecParams(const OSExecParams* params, OSExecParams* addr);


#ifdef __cplusplus
}
#endif

#endif  // __OSEXEC_H__
