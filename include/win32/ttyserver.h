/*---------------------------------------------------------------------------*
  Project:  TTY server API for MCC
  File:     ttyserver.h

  Copyright 2000 - 2001 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    3     02/09/30 15:10 Hashida
    Source sync with Hudson.
    
    3     02/09/18 23:01 Hashida
    Added static version of fio/tty by Hudson.
    
    2     6/18/01 4:34p Hashida
    Changed copyright informaiton.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __MCC_TTY_SERVER_H__
#define __MCC_TTY_SERVER_H__

// HEADER INCLUDE
// ====================
#include <win32/dolphin.types.h>
#include <dolphin/mcc.h>

#define TTY_SERVER_API

#ifdef __cplusplus
extern "C" {
#endif

	// CALLBACK PROTOTYPES 
	// ====================
	typedef void(WINAPI* TTYServerCallback)( char* string );

	// FUNCTION PROTOTYPES 
	// ====================
	TTY_SERVER_API BOOL TTYServerStart( MCCChannel chID, TTYServerCallback callback );
	TTY_SERVER_API void TTYServerStop( void );

#ifdef __cplusplus
}
#endif

#endif __MCC_TTY_SERVER_H__
