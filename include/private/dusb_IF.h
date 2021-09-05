/*---------------------------------------------------------------------------*
  Project:  Host I/O API for DI-USB PC/NNGC module
  File:     dusb_IF.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/private/dusb_IF.h,v 1.1 2006-03-09 12:24:51 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

//
// HW0 : GDEV + ODIFによる検証
//		 GDEV + ODIFには、Tagret -> PCへのDMA機能がない為、DIコマンドで擬似的
//		 に実装

#ifndef	__DUSB_IF_H__
#define	__DUSB_IF_H__

#ifdef	WIN32	// PC include here

#   include <windows.h>
#   include <win32/dolphin.types.h>

#else	// WIN32

#	include <private/dvdlow.h>
#	include <private/direg.h>

#endif	// WIN32

#ifdef __cplusplus
extern "C" {
#endif

//#define	DUSB_DEBUG

//-----------------------------------------------------------------------------
// define

// Write DMA max size
#define	DUSB_WRITE_BLOCK_SIZE	(2 * 1024 * 1024)

// Write DMA end of block
#define	DUSB_WRITE_EOB			0x80000000

// DUSB DI command
#define	DRIVE_CMD_DUSB			0xF0
// Write DMA mask
#define DRIVE_REG_CR_RW_MASK	0x00000004

// DUSB magic
#define	DUSB_MAGIC	'DUSB'

// error
#define	DUSB_ERROR	-1

// DI command ID
enum
{
	DUSB_DICMD_ID_INIT,			// initialize
	DUSB_DICMD_ID_NOTIFY,		// notify
	DUSB_DICMD_ID_READ,			// read
	DUSB_DICMD_ID_WRITE,		// write
	DUSB_DICMD_ID_EXIT,			// exit
	DUSB_DICMD_ID_COVER = 0xFF	// cover open/close
};

// result of having transmitted a DI command with an IMM mode
enum
{
	DUSB_DICMD_RESULT_INIT	= DUSB_MAGIC,
	DUSB_DICMD_RESULT_EXIT	= 0
};

#ifdef	HW0
#	define	DUSB_HW0_WRITE_DMA_MAX	8	// DI command (12bytes) - 4
#endif	// HW0

//-----------------------------------------------------------------------------
// macro definition

// DI command for DUSB API
//
//	cmd_id_data1_data2	->  cmd:8bits		0xAA or 0xF0
//							id:8bits		DUSB_DICMD_ID_XXXX
//							data1:8bits		use are different by operation
//							data2:8bits		use are different by operation
//
#define	DUSB_GEN_DICMD(cmd, id, data1, data2)	\
(u32)											\
(												\
	(((cmd)   & 0xFF)	<< 24)					\
|	(((id)    & 0xFF)	<< 16)					\
|	(((data1) & 0xFF)	<< 8)					\
|	((data2)  & 0xFF)							\
)

#ifdef	WIN32
#define	DVD_ALIGN_SIZE	32
#endif	// WIN32

#define	DUSB_DMA_ALIGN(len)	\
	(((len) + (DVD_ALIGN_SIZE - 1)) & ~(DVD_ALIGN_SIZE - 1))

//-----------------------------------------------------------------------------
// type definition

// DI command format
typedef struct
{
	union					// DICMDBUF0
	{
		struct
		{
			u8	cmd;		// DI command
			u8	id;			// command ID
			u8	data1;		// use are different by operation
			u8	data2;		// use are different by operation
		};
		u32	cmdbuf0;
	};
	u32	cmdbuf1;		// DICMDBUF1
	u32	cmdbuf2;		// DICMDBUF1
} DUSBCommand;

//-----------------------------------------------------------------------------
// internal function prototypes

#ifdef	WIN32

static inline
DWORD	DUSBSwap32( DWORD val )
{
	return 
		((val >> 24) & 0x000000FF) |
		((val >>  8) & 0x0000FF00) |
		((val <<  8) & 0x00FF0000) |
		((val << 24) & 0xFF000000);
}

#endif	// WIN32

#ifdef __cplusplus
}
#endif

#endif	// __DUSB_IF_H__
