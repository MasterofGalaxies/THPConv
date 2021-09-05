/*---------------------------------------------------------------------------*
  Project:  Dolphin OS EXI_AD16 Interface API
  File:     ad16.h

  Copyright 2000, 2001  Nintendo.  All rights reserved.

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

    
    2     9/21/01 17:50 Shiki
    Added AD16Probe().

    1     10/26/00 4:50p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __AD16_H__
#define __AD16_H__

#include <revolution/os.h>
#include <private/flipper.h>
#include <private/exi.h>

BOOL AD16Init    ( void );
BOOL AD16WriteReg( u32  word );
BOOL AD16ReadReg ( u32* word );
BOOL AD16Probe   ( void );

#endif  // __AD16_H__
