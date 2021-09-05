/*---------------------------------------------------------------------------*
  Project:      APIs for title status
  File:         OSTitle.h

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2007/07/19 02:25:06  wada_jumpei
  Initial check in.

 *---------------------------------------------------------------------------*/

#ifndef __OSTITLE_H__
#define __OSTITLE_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef u64 OSTitleId;

// Title status
#define OSTITLE_STATUS_UNKNOWN      0
#define OSTITLE_STATUS_INSTALLED    1
#define OSTITLE_STATUS_NOEXISTS     2
#define OSTITLE_STATUS_DELETED      3
#define OSTITLE_STATUS_SAVEONLY     4
#define OSTITLE_STATUS_NORIGHTS     5
#define OSTITLE_STATUS_PARTIAL      6
#define OSTITLE_STATUS_FATAL        7

// Error status
#define OSTITLE_RESULT_OK               0
#define OSTITLE_RESULT_OPERATION      (-1)
#define OSTITLE_RESULT_ALLOC_FAILED   (-2)

// For OSIsTitleInstalled
#define OSTITLE_STACK_SIZE  2048

s32  OSGetTitleStatus(OSTitleId titleId, u32* status, void* tmpBuffer, u32* bufSize);
BOOL OSIsTitleInstalled(OSTitleId titleId);

u32  OSGetLaunchCode(void);
u32  OSGetReturnCode(void);

#ifdef __cplusplus
}
#endif

#endif // __OSTITLE_H__