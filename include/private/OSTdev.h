/*---------------------------------------------------------------------------*
  Project:  Dolphin OS TDEV API
  File:     OSTdev.h

  Copyright 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    3     1/23/03 9:30 Shiki
    Clean up for new <os.h>.

    2     9/20/02 10:04 Shiki
    Defined OS_CONSOLE_TDEV.

    1     7/05/02 14:13 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSTDEV_H__
#define __OSTDEV_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OS_CONSOLE_TDEV
#define OS_CONSOLE_TDEVHW4          0x20000007
#define OS_CONSOLE_TDEVHW3          0x20000006
#define OS_CONSOLE_TDEVHW2          0x20000005
#define OS_CONSOLE_TDEVHW1          0x20000004
#define OS_CONSOLE_TDEV             0x20000000
#endif

#ifdef __cplusplus
}
#endif

#endif  // __OSTDEV_H__
