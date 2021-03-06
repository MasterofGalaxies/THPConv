/*---------------------------------------------------------------------------*
  Project: OS - Low Level Instruction Cache Operations Library
  File:    OSIC.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    4     99/07/27 5:30p Shiki
    Cleanup.

    3     5/11/99 4:43p Shiki
    Refreshed include tree.

    1     4/30/99 12:49p Tianli01

    2     4/21/99 4:13p Tianli01
    moved ICSync to OSIC.h

    1     3/04/99 2:23p Tianli01
    Initial checkin to new tree

    1     2/04/99 6:02p Tianli01
    Initial checkin

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*
    This header file defines the low level instruction cache operations.
    Most should be macros to the underlying assembly routines, but others
    will manipulate hardware setup registers.
 */

#ifndef __OSIC_H__
#define __OSIC_H__

#ifdef __cplusplus
extern "C" {
#endif

void ICSync             ( void );
void ICFlashInvalidate  ( void );
void ICEnable           ( void );
void ICDisable          ( void );
void ICFreeze           ( void );
void ICUnfreeze         ( void );
void ICBlockInvalidate  ( void* addr );

#ifdef __cplusplus
}
#endif

#endif  // __OSIC_H__
