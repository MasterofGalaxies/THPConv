/*---------------------------------------------------------------------------*
  Project:  Revolution OS - WPAD 
  File:     wpadsys.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.18  2007/04/12 07:59:29  tojo
  (none)

  Revision 1.17  2007/04/11 00:59:43  tojo
  (none)

  Revision 1.16  2007/04/10 10:13:43  tojo
  Implemented WPADEnableClCompatOnWiiMenu().

  Revision 1.15  2007/02/22 05:21:44  tojo
  Changed the shutdown API to send the flag of calling OSExec.

  Revision 1.14  2006/10/24 08:29:50  tojo
  Changed __Shutdown  to __WPADShutdown
              __Reconnect to __WPADReconnect.

  Revision 1.13  2006/10/24 01:57:53  tojo
  Added shutdown apis.

  Revision 1.12  2006/09/15 05:42:00  tojo
  (none)

  Revision 1.11  2006/09/14 15:57:54  tojo
  Got the stack queue status.

  Revision 1.10  2006/09/12 04:14:23  tojo
  Added debug msg declaration.

  Revision 1.9  2006/09/04 01:53:26  tojo
  Moved WPADSetDpdSensitivity to public

  Revision 1.8  2006/08/28 13:07:33  tojo
  Made WPADGetDpdSensitivity public.

  Revision 1.7  2006/08/21 04:13:05  tojo
  (none)

  Revision 1.6  2006/08/18 11:26:46  tojo
  Used SC libs.

  Revision 1.5  2006/08/14 17:44:32  tojo
  Hiden WPADSwapControllerPort

  Revision 1.4  2006/08/14 16:58:49  tojo
  Added WPADSetSonsorBarPower
           WPADGetCalibratedDPDObject

  Revision 1.3  2006/08/11 07:55:04  tojo
  Added dpd sensitivity apis.

  Revision 1.2  2006/08/10 01:33:27  tojo
  (none)

  Revision 1.1  2006/08/03 13:10:02  tojo
  Initial check in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WPAD_SYS_H__
#define __WPAD_SYS_H__

#include <revolution/wpad.h> 

#ifdef __cplusplus
extern "C" {
#endif

#define ENABLE_SC_FOR_WPAD              1

extern BOOL WPADSaveDpdSensitivity     ( WPADFlushCallback callback );
extern void WPADGetDpdCornerPoints     ( s32 chan, DPDObject *corners );
extern BOOL WPADSetSensorBarPower      ( BOOL on );
extern void WPADGetCalibratedDPDObject ( DPDObject* dst, const DPDObject* src );
extern BOOL WPADSwapControllerPort     ( s32 port1, s32 port2 );
extern void WPADRecalibrate            ( s32 chan );

extern void _WPADEnableDebugMsgs       ( void );
extern void _WPADDisableDebugMsgs      ( void );

extern u16  _WPADGetStackBufferStatus  ( s32 chan );
extern u16  _WPADGetModuleBufferStatus ( s32 chan );

// shutdown function
extern void __WPADShutdown             ( void );
extern void __WPADReconnect            ( BOOL exec );

extern s32  _WPADConnect               ( u8 *addr, u8 *key, u8 *name );

#ifdef __cplusplus
}
#endif
#endif // __WPAD_SYS_H__
