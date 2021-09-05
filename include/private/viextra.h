/*---------------------------------------------------------------------------*
  Project:  Dolphin VIextra private API
  File:     viextra.h

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

    
    1     03/08/06 21:15 Hashida
    Initial revision.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VIEXTRA_H__
#define __VIEXTRA_H__

#include <revolution/vi.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VI_EXTRA                7

#define VI_TVMODE_EXTRA_INT	    ((VITVMode)VI_TVMODE(VI_EXTRA, VI_INTERLACE))
#define VI_TVMODE_EXTRA_DS	    ((VITVMode)VI_TVMODE(VI_EXTRA, VI_NON_INTERLACE))
#define VI_TVMODE_EXTRA_PROG    ((VITVMode)VI_TVMODE(VI_EXTRA, VI_PROGRESSIVE))

#if 0

typedef struct
{
    // Vertical timing
    u8      equ;
    u16     acv;

    u16     prbOdd;
    u16     prbEven;

    u16     psbOdd;
    u16     psbEven;

    u8      bs1;
    u8      bs2;
    u8      bs3;
    u8      bs4;

    u16     be1;
    u16     be2;
    u16     be3;
    u16     be4;

    u16     nhlines;    // # of half lines per field

    // Horizontal timing
    u16     hlw;
    u8      hsy;
    u8      hcs;
    u8      hce;
    u8      hbe640;             // for 640 pixel width
    u16     hbs640;             // for 640 pixel width
    u8      reserved1;
    u16     reserved2;
    
} timing_s;

timing_s *__VISetExtraTiming(timing_s *t);
  
#endif


#ifdef __cplusplus
}
#endif

#endif  // __VIEXTRA_H__
