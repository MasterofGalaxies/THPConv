/*---------------------------------------------------------------------------*
  Project:  Dolphin CARD API private routines
  File:     CARDCompany.h

  Copyright 2003 Nintendo.  All rights reserved.

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

    
    1     4/02/03 15:22 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CARDCOMPANY_H__
#define __CARDCOMPANY_H__

#include <revolution/card.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL __CARDEnableCompany(BOOL enable);

#ifdef __cplusplus
}
#endif

#endif  // __CARDCOMPANY_H__
