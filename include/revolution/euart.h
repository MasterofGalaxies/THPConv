/*---------------------------------------------------------------------------*
  Project:  Host I/O API for EXI-UART
  File:     euart.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/revolution/euart.h,v 1.1 2006-03-09 12:25:39 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__EUART_H__
#define	__EUART_H__

#ifdef	WIN32	// PC include here

#   include <windows.h>
#   include <win32/dolphin.types.h>

#	ifdef EUARTAPI_DLL_EXPORTS
#		define	EUARTAPI __declspec(dllexport)
#	else
#		define	EUARTAPI __declspec(dllimport)
#	endif

#else	// WIN32

#   include <dolphin/types.h>

#	define	EUARTAPI 

#endif	// WIN32

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// define

//---- invalid handle (PC only)
#define	EUART_INVALID_HANDLE_VALUE	((EUARTHandle)-1)

//-----------------------------------------------------------------------------
// type difinition

//---- EUART handle (PC only)
#ifdef	WIN32
typedef LPVOID	EUARTHandle;
#endif	// WIN32

//----- error code
typedef enum
{
	EUART_ERROR_NONE = 0,			// no error
	EUART_ERROR_UNINITIALIZED,		// EUART is not initialized
	EUART_ERROR_CANNOT_USE,			// this console cannot use EUART
	EUART_ERROR_CHANNEL_FULL,		// all channels are used
	EUART_ERROR_NOT_FIND,			// EXI-UART not find
	EUART_ERROR_INTERNAL,			// internal error (EXI error)

	EUART_ERROR_INVALID_PARAMETER,	// invalid function parametr
	EUART_ERROR_INVALID_HANDLE,		// invalid EUART handle
	EUART_ERROR_COM_OPEN,			// COM port open error
	EUART_ERROR_COMM				// communication error 
} EUARTError;

//---- callback prototypes
// receive data (PC only)
typedef void	(*EUARTReceiveCallback)( int size );

#ifdef	WIN32

//-----------------------------------------------------------------------------
// function prototypes

EUARTAPI EUARTHandle	EUARTInit			( int comPort, EUARTReceiveCallback callback );
EUARTAPI BOOL			EUARTExit			( EUARTHandle h );
EUARTAPI int			EUARTRead			( EUARTHandle h, LPBYTE buffer, int size );
EUARTAPI EUARTError		EUARTGetLastError	( void );

//-----------------------------------------------------------------------------
// EXPORT function (for euart[D].dll)

//---- type difinition
typedef EUARTHandle	(*EUARTInitType)		( int comPort, EUARTReceiveCallback callback );
typedef BOOL		(*EUARTExitType)		( EUARTHandle h );
typedef int			(*EUARTReadType)		( EUARTHandle h, LPBYTE buffer, int size );
typedef EUARTError	(*EUARTGetLastErrorType)( void );

//---- string (EXPORT function name) difinition
#define	EUARTInitStr			"EUARTInit"
#define	EUARTExitStr			"EUARTExit"
#define	EUARTReadStr			"EUARTRead"
#define	EUARTGetLastErrorStr	"EUARTGetLastError"

#else	// WIN32

//-----------------------------------------------------------------------------
// function prototypes

BOOL		EUARTInit			( void );
void		EUARTExit			( void );
s32			EUARTPrintf			( const char* msg, ... );
BOOL		EUARTSetStatus		( BOOL sendStop );
EUARTError	EUARTGetLastError	( void );

//-----------------------------------------------------------------------------
// inline function definition

static inline
BOOL	EUARTStop( void )	{ return EUARTSetStatus(TRUE);	}

static inline
BOOL	EUARTStart( void )	{ return EUARTSetStatus(FALSE);	}

#endif	// WIN32

#ifdef __cplusplus
}
#endif

#endif	// __EUART_H__
