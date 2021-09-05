/*---------------------------------------------------------------------------*
  Project:  Revolution OS Hardware Revision API
  File:     OSHW.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5.34.1  2008/04/18 01:25:37  ooizumi
  Added Bollywood defines.

  Revision 1.5  2006/06/15 12:29:40  hirose
  Added OS_BROADWAY_DD1_3 and OS_HOLLYWOOD_ES2_1.

  Revision 1.4  2006/06/05 00:56:46  hirose
  Added __OSGetGDDRVendorCode().

  Revision 1.3  2006/03/28 02:08:41  hirose
  Added __OSGetIOSRev().

  Revision 1.2  2006/02/28 12:18:14  hirose
  Added __OSGetBroadwayRev(). / Added OS_HOLLYWOOD_ES1_2.

  Revision 1.1  2006/02/15 07:55:45  hirose
  Initial check in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSHW_H__
#define __OSHW_H__

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*
    Broadway revisions
 *---------------------------------------------------------------------------*/

#define     OS_BROADWAY_DD1_01      0x00087110      // DD1.01
#define     OS_BROADWAY_DD1_2       0x00087102      // DD1.2
#define     OS_BROADWAY_DD1_3       0x00087103      // DD1.3
#define     OS_BROADWAY_DD2_0       0x00087200      // DD2.0 (Broadway-1)
#define     OS_NO_BROADWAY          0x80000000

u32     __OSGetBroadwayRev( void );


/*---------------------------------------------------------------------------*
    Hollywood revisions
 *---------------------------------------------------------------------------*/

#define     OS_HOLLYWOOD_ES1_0      0x00000000      // ES1.00
#define     OS_HOLLYWOOD_ES1_1      0x00000001      // ES1.10
#define     OS_HOLLYWOOD_ES1_2      0x00000002      // ES1.21
#define     OS_HOLLYWOOD_ES2_0      0x00000010      // ES2.01
#define     OS_HOLLYWOOD_ES2_1      0x00000011      // ES2.11
#define     OS_HOLLYWOOD_ES3_0      0x00000020      // ES3.0
#define     OS_HOLLYWOOD_ES3_1      0x00000021      // ES3.1
#define     OS_NO_HOLLYWOOD         0x80000000

u32     __OSGetHollywoodRev( void );


/*---------------------------------------------------------------------------*
    GDDR vendor code
 *---------------------------------------------------------------------------*/

u32     __OSGetGDDRVendorCode( void );

/*---------------------------------------------------------------------------*
    IOS firmware revisions
 *---------------------------------------------------------------------------*/

typedef struct OSIOSRev
{
    u8      reserved;
    u8      major;
    u8      minor;
    u8      micro;
    u8      month;
    u8      date;
    u16     year;
} OSIOSRev;

void    __OSGetIOSRev( OSIOSRev* rev );




#ifdef __cplusplus
}
#endif

#endif  // __OSHW_H__

