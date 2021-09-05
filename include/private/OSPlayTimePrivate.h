/*---------------------------------------------------------------------------*
  Project:  OS Limited Ticket API
  File:     OSPlayTimePrivate.h

  Copyright 1998-2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2007/06/14 01:28:24  wada_jumpei
  Modified to set the expired flag when ticket is expired during restart

  Revision 1.3  2007/04/25 22:43:28  johnc
  Added OSPLAYTIME_LIMITED_LAUNCH.
  Note: __OSGetPlayTime does not work properly with multiple limits.

  Revision 1.2  2007/04/14 00:28:42  johnc
  Added OSPLAYTIME_OTHER for unsupported limit codes in ticket.

  Revision 1.1  2007/02/13 22:23:58  johnc
  Initial checkin.


 *---------------------------------------------------------------------------*/

#ifndef __OSPLAYTIMEPRIVATE_H__
#define __OSPLAYTIMEPRIVATE_H__

#include <revolution/types.h>
#include <secure/estypes.h>

#define __OSPLAYTIME_EXPIRED_FILE "/shared2/expired"

typedef enum
{
    OSPLAYTIME_PERMANENT        = 0,
    OSPLAYTIME_LIMITED          = 1,
    OSPLAYTIME_LIMITED_LAUNCH   = 4,
    OSPLAYTIME_OTHER            = 9

} __OSPlayTimeType;

#ifdef __cplusplus
extern "C" {
#endif

// Limited play ticket initialization
void    __OSInitPlayTime            ( void );
s32     __OSGetPlayTime	            ( ESTicketView *ticketView, __OSPlayTimeType *type, u32 *playTime );
s32 	__OSGetPlayTimeCurrent      ( __OSPlayTimeType *type, u32 *playTime );
BOOL    __OSWriteExpiredFlag        ( void );
BOOL    __OSWriteExpiredFlagIfSet   ( void );

#ifdef __cplusplus
}
#endif

#endif  // __OSPLAYTIMEPRIVATE_H__
