/*---------------------------------------------------------------------*
  Project:  Revolution: VI definitions for HD mode
  File:     viHD.h

  Copyright 2006-2007 Nintendo.  All rights reserved.

  These coded instructions, statements and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2007/06/16 00:19:02  carlmu
  Initial version.

  $NoKeywords: $
-----------------------------------------------------------------------*/

#ifndef __VIHD_H__
#define __VIHD_H__

#ifdef __cplusplus
extern "C" {
#endif

#define VI_HD720                8
#define VI_HD1080                9

#define VI_TVMODE_HD720_PROG    ((VITVMode)VI_TVMODE(VI_HD720, VI_PROGRESSIVE))
#define VI_TVMODE_HD1080_INT    ((VITVMode)VI_TVMODE(VI_HD1080, VI_INTERLACE))

void VIInitHD(VITVMode mode);

#ifdef __cplusplus
}
#endif

#endif  // __VIHD_H__
