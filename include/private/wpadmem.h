/*---------------------------------------------------------------------------*
  Project:  Revolution OS - WPAD 
  File:     wpadmem.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.7  2006/08/21 02:54:50  tojo
  (none)

  Revision 1.6  2006/08/16 09:37:25  tojo
  Hiden face apis.

  Revision 1.5  2006/08/11 09:38:08  tojo
  (none)

  Revision 1.2  2006/08/01 06:04:01  tojo
  (none)

  Revision 1.1  2006/06/28 08:32:37  tojo
  Renamed file name.

  Revision 1.1  2006/06/22 00:31:46  tojo
  Initial version. FOR INTERNAL USE ONLY. DO NOT RELEASE UNTIL FURTHER NOTICE.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WPAD_MEM_H__
#define __WPAD_MEM_H__

#include <revolution/wpad.h> 

#ifdef __cplusplus
extern "C" {
#endif

extern s32 WPADReadFaceData    ( s32 chan, void *p_buf, u16 len, u16 offset, WPADCallback callback );
extern s32 WPADWriteFaceData   ( s32 chan, void *p_buf, u16 len, u16 offset, WPADCallback callback );

extern s32 WPADWriteExtReg     ( s32 chan, void *p_buf, u16 len, u16 offset, WPADCallback callback );
extern s32 WPADReadExtReg      ( s32 chan, void *p_buf, u16 len, u16 offset, WPADCallback callback );

extern s32 WPADReadMemoryAsync ( s32 chan, void *p_buf, u16 len, u32 addr, WPADCallback callback );
extern s32 WPADWriteMemoryAsync( s32 chan, void *p_buf, u16 len, u32 addr, WPADCallback callback );


#ifdef __cplusplus
}
#endif
#endif // __WPAD_MEM_H__
