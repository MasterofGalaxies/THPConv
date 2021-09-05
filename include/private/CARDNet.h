/*---------------------------------------------------------------------------*
  Project:  Dolphin CARD API private routines
  File:     CARDNet.h

  Copyright 2001-2003 Nintendo.  All rights reserved.

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

    
    5     4/02/03 15:23 Shiki
    Clean up.

    4     4/02/03 11:41 Shiki
    Declared __CARDEnableGlobal() and __CARDEnableCompany.

    3     8/27/02 11:29 Shiki
    Added __CARDGetFontEncode() and __CARDSetFontEncode().

    2     8/05/02 15:49 Shiki
    Added const keywords to relevant function prototypes.

    1     10/18/01 14:14 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CARDNET_H__
#define __CARDNET_H__

#include <revolution/card.h>
#include <private/CARDCompany.h>
#include <private/CARDGlobal.h>

#ifdef __cplusplus
extern "C" {
#endif

// For GC-AM
u16 __CARDGetFontEncode   ( void );
u16 __CARDSetFontEncode   ( u16 encode );

// For Net card
u16 CARDSetVendorID       ( u16 vendorID );
u16 CARDGetVendorID       ( void );

s32 CARDGetUniqueCode     ( s32 chan, u64* uniqueCode );

const DVDDiskID* CARDGetDiskID( s32 chan );
s32              CARDSetDiskID( s32 chan, const DVDDiskID* diskID );

#ifdef __cplusplus
}
#endif

#endif  // __CARDNET_H__
