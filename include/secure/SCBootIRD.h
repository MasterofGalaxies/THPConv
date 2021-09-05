/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     SCBootIRD.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2007/01/26 04:35:00  ooizumi
  Changed SC_BOOT_MODE_DEFAULT.

  Revision 1.1  2007/01/23 02:41:42  ooizumi
  Moved functions used by boot-IRD from <private/scprivate.h>.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCBOOTIRD_H__
#define __SCBOOTIRD_H__

#include <private/scprivate.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SC_BOOT_MODE_DEVELOPMENT 0u
#define SC_BOOT_MODE_PRODUCTION  1u
#define SC_BOOT_MODE_DEFAULT     SC_BOOT_MODE_PRODUCTION

extern u8 SCGetBootMode(void);
extern BOOL SCSetBootMode(u8 mode);

#define SC_VIDEO_MODE_NTSC       0u
#define SC_VIDEO_MODE_PAL        1u
#define SC_VIDEO_MODE_DEFAULT    SC_VIDEO_MODE_NTSC

extern u8 SCGetBootIRDVMode(void);
extern BOOL SCSetBootIRDVMode(u8 mode);

#define SC_COUNTRY_CODE_JP       0u
#define SC_COUNTRY_CODE_US       1u
#define SC_COUNTRY_CODE_EU       2u
//#define SC_COUNTRY_CODE_ALL      3u
#define SC_COUNTRY_CODE_KR       4u
#define SC_COUNTRY_CODE_CN       5u
#define SC_COUNTRY_CODE_DEFAULT  SC_PRODUCT_AREA_USA

extern u8 SCGetBootIRDCCode(void);
extern BOOL SCSetBootIRDCCode(u8 mode);

#define SC_DRIVESAVING_MODE_ENABLE   0u
#define SC_DRIVESAVING_MODE_DISABLE  1u
#define SC_DRIVESAVING_MODE_DEBUG    2u
#define SC_DRIVESAVING_MODE_DEFAULT  SC_DRIVESAVING_MODE_ENABLE

extern u8 SCGetDriveSavingMode(void);
extern BOOL SCSetDriveSavingMode(u8 mode);

#ifdef __cplusplus
}
#endif

#endif // __SCBOOTIRD_H__
