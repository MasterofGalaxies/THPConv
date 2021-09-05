/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     SCDvd.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/06/06 07:23:46  kawaset
  Initial check-in.



  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCDVD_H__
#define __SCDVD_H__

#include <revolution/sc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SC_DVD_VIDEO_MODE_LETTERBOX 0u
#define SC_DVD_VIDEO_MODE_PAN_SCAN  1u

#define SC_DVD_PARENTAL_CONTROL_LEVEL_MIN 1
#define SC_DVD_PARENTAL_CONTROL_LEVEL_MAX 8

typedef struct {
    u8  videoMode;
    u8  parentalControlLevel;
    u16 parentalControlCountry;
} SCDvdConfig;

extern BOOL SCGetDvdConfig(SCDvdConfig *info);
extern BOOL SCSetDvdConfig(const SCDvdConfig *info);

#define SC_DVD_MOVIE_DISABLED       0
#define SC_DVD_MOVIE_REGION_1       1
#define SC_DVD_MOVIE_REGION_2       2
#define SC_DVD_MOVIE_REGION_3       3
#define SC_DVD_MOVIE_REGION_4       4
#define SC_DVD_MOVIE_REGION_5       5
#define SC_DVD_MOVIE_REGION_6       6
#define SC_DVD_MOVIE_REGION_7       7
#define SC_DVD_MOVIE_REGION_8       8
#define SC_DVD_MOVIE_REGION_MAX     SC_DVD_MOVIE_REGION_8

extern u8 SCGetDvdMovieRegion(void);

#ifdef __cplusplus
}
#endif

#endif // __SCDVD_H__
