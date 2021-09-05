/*---------------------------------------------------------------------------*
  Project:  Dolphin OS PPC prefix header, Release version 
  File:     PPCprefix.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    2     5/03/99 5:25p Tianli01
    PPC->EPPC
    
    1     4/30/99 12:49p Tianli01
    
    1     3/09/99 11:36a Tianli01
    Initial checkin.  PPC/X86 prefix header files

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#define NDEBUG
#include "ansi_prefix.PPCEABI.bare.h"
#define EPPC
