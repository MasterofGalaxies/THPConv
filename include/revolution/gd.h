/*---------------------------------------------------------------------------*
  Project:  Dolphin GD library
  File:     gd.h

  Copyright 2001-2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2006/02/04 11:56:44  hashida
  (none)

  Revision 1.2  2005/08/17 10:56:09  hirose
  Removed definition of sinf/cosf for WIN32.

  Revision 1.1.1.1  2005/05/12 02:41:06  yasuh-to
  dolphinシースツリーから移植

    
    3     03/02/03 14:07 Hirose
    Added "GDIndirect.h".
    
    2     9/19/01 3:55p Carl
    More win32 compatibility defines.
    
    1     9/12/01 1:53p Carl
    Initial revision of GD: Graphics Display List Library.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __GD_H__
#define __GD_H__

/*---------------------------------------------------------------------------*/

#ifdef WIN32
#define inline __inline
#endif

/*---------------------------------------------------------------------------*/
// Defines version related flags if not exists.

#ifndef BUG_CLR_LOAD_DLY
#define BUG_CLR_LOAD_DLY
#endif // BUG_CLR_LOAD_DLY

#ifndef BUG_XF_STALL
#define BUG_XF_STALL
#endif // BUG_XF_STALL

#ifndef BUG_CP_LOAD_DLY
#define BUG_CP_LOAD_DLY
#endif // BUG_CP_LOAD_DLY

/*---------------------------------------------------------------------------*/

#include <revolution/gd/GDBase.h>
#include <revolution/gd/GDFile.h>
#include <revolution/gd/GDGeometry.h>
#include <revolution/gd/GDIndirect.h>
#include <revolution/gd/GDLight.h>
#include <revolution/gd/GDPixel.h>
#include <revolution/gd/GDTev.h>
#include <revolution/gd/GDTexture.h>
#include <revolution/gd/GDTransform.h>
#include <revolution/gd/GDVert.h>

/*---------------------------------------------------------------------------*/

#endif // __GD_H__
