/*---------------------------------------------------------------------------*
  Project:    Simple Kit library
  File:       simplekit.h
  Programmer: HIRATSU Daisuke

  Copyright 2005-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef SIMPLEKIT_H__
#define SIMPLEKIT_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void SKITInit(void);

void SKITRenderPoint(int x, int y, int pixel, u32 clr);
void SKITRenderText     (int x, int y, f32 scale, const char *msg);
f32  SKITGetTextWidth   (f32 scale, const char *msg);
void SKITRenderLine     (s16 x1, s16 y1, s16 x2, s16 y2, u32 clr);
void SKITRenderRectangle(s16 x1, s16 y1, s16 x2, s16 y2, u32 clr);
void SKITRenderCircle   (s16 x, s16 y, s16 r, s16 div, u32 clr);
void SKITRenderTime     (int x, int y, f32 scale);
// void SKITRenderTexture  (s16 x, s16 y, const char *path, int idx);  // Not implemented.

void SKITResetHandler(void);

void SKITWaitMilliSec(u32 msec);
void SKITWaitMicroSec(u32 usec);
void SKITWaitNanoSec (u32 nsec);

#ifdef __cplusplus
}
#endif


#endif  // end of SIMPLEKIT_H__
