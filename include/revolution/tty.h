/*---------------------------------------------------------------------------*
  Project:  TTY protocol API for MCC
  File:     tty.h

  Copyright 2000 - 2001 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/02/25 08:23:05  mitu
  1st version

    
    4     03/09/12 15:18 Shogo
    Corrected #endif comment.
    
    3     6/18/01 4:29p Hashida
    Changed copyright informaiton.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __MCC_TTY_H__
#define __MCC_TTY_H__

// HEADER INCLUDE
// ================
#ifdef WIN32//host incluide here
#	include <win32/dolphin.types.h>
#else
#	include <revolution/types.h>

#ifndef MCC_TARGET
#	define MCC_TARGET
#endif

#endif
#include <revolution/mcc.h>

#ifdef __cplusplus
extern "C" {
#endif

	// FUNCTION PROTOTYPES
	// ================
	BOOL TTYInit( MCCExiChannel exiChannel, MCCChannel chID );
	void TTYExit( void );
	BOOL TTYQuery( void );

	BOOL TTYPrintf( const char* format, ... );
	BOOL TTYFlush( void );

#ifdef __cplusplus
}
#endif

#endif // __MCC_TTY_H__
