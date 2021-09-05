/*---------------------------------------------------------------------------*
  Project:  Host I/O API for DI-USB
  File:     dusb.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/revolution/dusb.h,v 1.1 2006-03-09 12:25:39 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__DUSB_H__
#define	__DUSB_H__

#ifdef	WIN32	// PC include here

#   include <windows.h>
#   include <win32/dolphin.types.h>

#	ifdef DUSBAPI_DLL_EXPORTS
#		define DUSB_API __declspec(dllexport)
#	else
#		define DUSB_API __declspec(dllimport)
#endif

#else	// WIN32

#   include <dolphin/types.h>

#	define	DUSBAPI

#endif	// WIN32

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// define


//-----------------------------------------------------------------------------
// type definition

//----- error code
typedef enum
{
	DUSB_ERROR_NONE = 0,			// no error
	DUSB_ERROR_UNINITIALIZED,		// DUSB is not initialized
	DUSB_ERROR_BUSY,				// former async process is not finished
	DUSB_ERROR_CANNOT_USE,			// this console cannot use DUSB
	DUSB_ERROR_DISK,				// device error - disk
	DUSB_ERROR_TIMEOUT,				// device error - timeout
	DUSB_ERROR_DEVICE_NOT_FIND,		// device not find
	DUSB_ERROR_DEVICE_OPEN,			// device open error
	DUSB_ERROR_DEVICE_LOST,			// device was lost
	DUSB_ERROR_EXECUTE,				// program can not execute
	DUSB_ERROR_INVALID_FILE			// invalid file ( !=.elf & !=.dlf )
} DUSBError;

//---- callback prototypes
#ifdef	WIN32
// NNGC called DUSBNotify
typedef s32		(*DUSBNotifyCallback)	( u32 notify );
#else	// WIN32
// NotifyAsync done
typedef void	(*DUSBNotifyCallback)	( s32 result );
#endif	// WIN32
// NNGC called DUSBRead   (PC only)
typedef void	(*DUSBReadCallback)		( void* buffer, s32 length ); 
// NNGC called DUSBWrite  (PC only)
typedef void	(*DUSBWriteCallback)	( void* buffer, s32 length ); 
// ReadAsync/WriteAsync done (NNGC only)
typedef void	(*DUSBDmaCallback)		( s32 result );

#ifdef	WIN32

//-----------------------------------------------------------------------------
// function prototypes

DUSB_API BOOL		DUSBInit			( DUSBNotifyCallback notifyCallback, DUSBReadCallback readCallback, DUSBWriteCallback writeCallback );
DUSB_API BOOL		DUSBLoadFromFile	( LPCSTR filename, BOOL reset );
DUSB_API BOOL		DUSBReset			( void );
DUSB_API void		DUSBExit			( void );
DUSB_API DUSBError	DUSBGetLastError	( void );

//-----------------------------------------------------------------------------
// EXPORT function (for dusb[D].dll)

//---- type definition
typedef BOOL		(*DUSBInitType)			( DUSBNotifyCallback notifyCallback, DUSBReadCallback readCallback, DUSBWriteCallback writeCallback );
typedef BOOL		(*DUSBLoadFromFileType)	( LPCSTR filename, BOOL reset );
typedef BOOL		(*DUSBResetType)		( void );
typedef void		(*DUSBExitType)			( void );
typedef DUSBError	(*DUSBGetLastErrorType)	( void );

//---- string (EXPORT function name) definition
#define	DUSBInitStr			"DUSBInit"
#define	DUSBLoadFromFileStr	"DUSBLoadFromFile"
#define	DUSBResetStr		"DUSBReset"
#define	DUSBExitStr			"DUSBExit"
#define	DUSBGetLastErrorStr	"DUSBGetLastError"

#else	// WIN32

//-----------------------------------------------------------------------------
// function prototypes

BOOL		DUSBInit			( void );
s32			DUSBNotify			( u32 notify );
s32			DUSBRead			( void* buffer, s32 length );
BOOL		DUSBReadAsync		( void* buffer, s32 length, DUSBDmaCallback callback );
s32			DUSBWrite			( void* buffer, s32 length );
BOOL		DUSBWriteAsync		( void* buffer, s32 length, DUSBDmaCallback callback );
void		DUSBExit			( void );
DUSBError	DUSBGetLastError	( void );
void		DUSBCoverOpen		( void );
void		DUSBCoverClose		( void );

#endif	// WIN32

#ifdef __cplusplus
}
#endif

#endif	// __DUSB_H__

