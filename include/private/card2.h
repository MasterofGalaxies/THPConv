/*---------------------------------------------------------------------------*
  Project:  Dolphin CARD extended API
  File:     card2.h

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

    
    1     2/07/03 8:59 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CARD2_H__
#define __CARD2_H__

#include <revolution/card.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CARD_PROGRAM_SIZE   128

s32 CARDErase       ( CARDFileInfo* fileInfo, s32 length, s32 offset );
s32 CARDEraseAsync  ( CARDFileInfo* fileInfo, s32 length, s32 offset,
                      CARDCallback callback );

s32 CARDProgram     ( CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset );
s32 CARDProgramAsync( CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset,
                      CARDCallback callback );

#ifdef __cplusplus
}
#endif

#endif  // __CARD2_H__
