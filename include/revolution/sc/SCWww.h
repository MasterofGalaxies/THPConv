/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     SCWww.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/06/21 11:28:45  kawaset
  Supported DVD movie region, WWW parental control, and product information file emulation.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCWWW_H__
#define __SCWWW_H__

#include <revolution/sc.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL SCGetWwwRestriction(void);
BOOL SCRemoveWwwRestrictionTemporarily(int code);

#ifdef __cplusplus
}
#endif

#endif // __SCWWW_H__
