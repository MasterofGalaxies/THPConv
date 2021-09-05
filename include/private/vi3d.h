/*---------------------------------------------------------------------------*
  Project:  Dolphin VI 3D private API
  File:     vi3d.h

  Copyright 2000 Nintendo.  All rights reserved.

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

    
    1     01/11/10 12:39 Hashida
    3D mode.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VI3D_H__
#define __VI3D_H__

#include <revolution/vi.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VI_3D                       3

#define VI_TVMODE_NTSC_3D 		((VITVMode)VI_TVMODE(VI_NTSC, VI_3D))

void VISetNextRightFrameBuffer(void *fb);

#ifdef __cplusplus
}
#endif

#endif  // __VI3D_H__
