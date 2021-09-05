/*---------------------------------------------------------------------------*
  Project: OS - Low Level L2 Cache Operations Library
  File:    OSL2.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphin�V�[�X�c���[����ڐA

    
    3     5/11/99 4:43p Shiki
    Refreshed include tree.

    1     4/30/99 12:49p Tianli01

    1     3/04/99 2:23p Tianli01
    Initial checkin to new tree
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*
    This header file defines the low level L2 cache operations.
    Most should be macros to the underlying assembly routines, but
    others will manipulate hardware setup registers.
 */

#ifndef __OSL2_H__
#define __OSL2_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void L2Enable           ( void );
void L2Disable          ( void );
void L2GlobalInvalidate ( void );
void L2SetDataOnly      ( BOOL dataOnly );
void L2SetWriteThrough  ( BOOL writeThrough );

#ifdef __cplusplus
}
#endif

#endif  // __OSL2_H__
