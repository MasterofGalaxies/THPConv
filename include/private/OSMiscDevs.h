/*---------------------------------------------------------------------------*
  Project:  Dolphin OS miscellaneous device control API
  File:     OSMiscDevs.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/08/24 12:37:09  hirose
  Changed return type of VI dimming functions.

  Revision 1.1  2006/08/11 09:36:39  hirose
  Initial check in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSMISCDEVS_H__
#define __OSMISCDEVS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/

// Slot LED.
extern void __OSSetSlotLED( BOOL enable );

// VI auto-dimming feature control.
extern int __OSSetVIAutoDimming( BOOL enable, u32 shift_y, u32 shift_cx, u32 count );
extern int __OSSetVIForceDimming( BOOL enable, u32 shift_y, u32 shift_cx);
extern int __OSSetRFIdleForAutoDimming( BOOL active );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __OSMISCDEVS_H__
