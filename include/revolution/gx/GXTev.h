/*---------------------------------------------------------------------------*
  Project:  Dolphin GX library
  File:     GXTev.h

  Copyright 1998 - 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphin�V�[�X�c���[����ڐA

    
    4     02/07/24 9:07 Hirose
    Resolved version conflicts.
    
    3     10/18/00 4:05p Carl
    Latest round of HW2 modifications and minor updates.
    
    2     10/03/00 7:55p Hirose
    Update for HW2(Rev.B) GX API extensions
    
    9     10/29/99 3:33p Hirose
    changed GXSetTevStages(GXTevStageID) to GXSetNumTevStages(u8)
    
    8     10/26/99 8:04p Alligator
    added s10-bit color
    
    7     10/13/99 5:20p Alligator
    remove GXSetTevClrSwap
    
    6     9/30/99 10:40p Yasu
    Renamed some GX functions and enums
    
    5     9/29/99 10:10a Alligator
    changed TEV api, separate input selection from ops
    
    4     9/01/99 3:33p Ryan
    
    3     8/17/99 1:02p Alligator
    updated commented functions to match current api
    
    2     7/28/99 4:07p Alligator
    update header files and emulator for hw changes
    
    1     7/14/99 4:20p Alligator
    split gx.h into individual header files for each major section of API
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __GXTEV_H__
#define __GXTEV_H__

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/
#include <revolution/types.h>
#include <revolution/gx/GXEnum.h>
#include <revolution/gx/GXStruct.h>

/*---------------------------------------------------------------------------*/
void GXSetTevOp(GXTevStageID id, GXTevMode mode);

void GXSetTevColorIn(
    GXTevStageID    stage,
    GXTevColorArg   a,
    GXTevColorArg   b,
    GXTevColorArg   c,
    GXTevColorArg   d );

void GXSetTevAlphaIn(
    GXTevStageID    stage,
    GXTevAlphaArg   a,
    GXTevAlphaArg   b,
    GXTevAlphaArg   c,
    GXTevAlphaArg   d );

void GXSetTevColorOp(
    GXTevStageID    stage,
    GXTevOp         op,
    GXTevBias       bias,
    GXTevScale      scale,
    GXBool          clamp,
    GXTevRegID      out_reg );

void GXSetTevAlphaOp(
    GXTevStageID    stage,
    GXTevOp         op,
    GXTevBias       bias,
    GXTevScale      scale,
    GXBool          clamp,
    GXTevRegID      out_reg );

void GXSetTevColor( GXTevRegID id, GXColor color );
void GXSetTevColorS10( GXTevRegID id, GXColorS10 color );

// Feature available in GX chip revision 1 only
// Revision 2 version is defined, but only prints error msg
void GXSetTevClampMode ( GXTevStageID stage, GXTevClampMode mode );

void GXSetAlphaCompare(
    GXCompare       comp0,
    u8              ref0,
    GXAlphaOp       op,
    GXCompare       comp1,
    u8              ref1 );

void GXSetTevOrder(
    GXTevStageID    stage, 
    GXTexCoordID    coord,
    GXTexMapID      map,
    GXChannelID     color );

void GXSetZTexture ( GXZTexOp op, GXTexFmt fmt, u32 bias );
void GXSetNumTevStages( u8 nStages );

#if ( GX_REV != 1 )
// Features available in GX chip revision 2 or later only
void GXSetTevKColor( GXTevKColorID id, GXColor color );
void GXSetTevKColorSel( GXTevStageID stage, GXTevKColorSel sel );
void GXSetTevKAlphaSel( GXTevStageID stage, GXTevKAlphaSel sel );

void GXSetTevSwapMode(
    GXTevStageID    stage,
    GXTevSwapSel    ras_sel,
    GXTevSwapSel    tex_sel );

void GXSetTevSwapModeTable(
    GXTevSwapSel    table,
    GXTevColorChan  red,
    GXTevColorChan  green,
    GXTevColorChan  blue,
    GXTevColorChan  alpha );

#endif // ( GX_REV != 1 )

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // __GXTEV_H__
