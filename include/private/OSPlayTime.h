/*---------------------------------------------------------------------------*
  Project:  OS Limited Ticket API
  File:     OSPlayTime.h

  Copyright 1998-2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2007/05/07 01:17:33  wada_jumpei
  Moved OSPlayTime.h to private

  Revision 1.2  2007/04/09 20:38:44  johnc
  Added OSPlayTimeSetExpiredThread to set an
       application-controlled ticket expiration message.
  Added OSPlayTimeSetExpiredFlag so that System Menu will
       not show ticket expiration message after reboot.
  Now, if application sets an expired ticket thread handler, then
  OSPlayTime API will allow the application to run for 4 extra minutes
       to handle ticket expiration message until forced reboot.
  Added OSPlayTimeReboot so that reboot can be called
       before the end of 4 extra minutes.

  Revision 1.1  2007/02/13 00:28:39  johnc
  Initial checkin.  OS support for limited tickets.


 *---------------------------------------------------------------------------*/

#ifndef __OSPLAYTIME_H__
#define __OSPLAYTIME_H__

#include <revolution/types.h>
#include <revolution/os/OSThread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OSPlayTimeCallbackFunc)(void);

BOOL OSPlayTimeIsLimited		    ( void );
u32  OSPlayTimeRemaining		    ( void );
void OSPlayTimeSetExpiredCallback   ( OSPlayTimeCallbackFunc expiredFunc );
BOOL OSPlayTimeSetExpiredFlag	    ( BOOL enabled );

#ifdef __cplusplus
}
#endif

#endif  // __OSPLAYTIME_H__
