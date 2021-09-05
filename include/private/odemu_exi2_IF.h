/*---------------------------------------------------------------------------*
  Project:  NNGC Debugger Interface for NNGC/PC module
  File:     odemu_exi2_IF.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/private/odemu_exi2_IF.h,v 1.1 2006-03-09 12:23:12 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

// OdemuExi2[D].a/odemu_exi2_comm[D].dll‹¤’Êƒwƒbƒ_

#ifndef	__ODEMU_EXI2_IF_H__
#define	__ODEMU_EXI2_IF_H__

//#define	SINGLE_BUFFER

#ifdef WIN32	// host include here
#   include <win32/dolphin.types.h>
#else	// WIN32
#   include <dolphin/types.h>
#endif	// WIN32

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// define

#ifdef HW0

// shared memory address

// NNGC->PC:4Kx32, PC->NNGC:4Kx2 version ( GC compatibility )
#	define	ODEMU_ADDR_NNGC2PC		0x0001C000
#	define	ODEMU_ADDR_PC2NNGC		0x0001E000
#	define	ODEMU_OFFSET_NNGC2PC	0x00001000
#	define	ODEMU_OFFSET_PC2NNGC	0x00001000

#else	// HW0

// NNGC->PC:2Kx2, PC->NNGC:2Kx2 version
#	define	ODEMU_ADDR_NNGC2PC		0x00000000
#	define	ODEMU_ADDR_PC2NNGC		0x00001000
#	define	ODEMU_OFFSET_NNGC2PC	0x00000800
#	define	ODEMU_OFFSET_PC2NNGC	0x00000800

#endif	// HW0

// mailbox - data
#define	ODEMU_MAIL_MAGIC		0x1F000000
#define ODEMU_MAIL_ACK			0x00008000

// mailbox - mask
#define	ODEMU_MAIL_MAGIC_MASK	0x1F000000
#define ODEMU_MAIL_PAGE_MASK	0x00FF0000
#define ODEMU_MAIL_ACK_MASK		0x00008000
#define	ODEMU_MAIL_SIZE_MASK	0x00001FFF
#define	ODEMU_MAIL_MASK			0x1FFFFFFF

// mailbox - shift
#define ODEMU_MAIL_PAGE_SHIFT	16

//-----------------------------------------------------------------------------
// inline function difinition

// generate mailbox data
static inline
u32	ODEMUGenMailData	( u32 page, u32 size )
{
	return
		(
			ODEMU_MAIL_MAGIC
			| ((page << ODEMU_MAIL_PAGE_SHIFT) & ODEMU_MAIL_PAGE_MASK)
			| (size & ODEMU_MAIL_SIZE_MASK)
		);
}

// get page from mailbox data
static inline
u32	ODEMUGetPage	( u32 mail )
{
	return ((mail & ODEMU_MAIL_PAGE_MASK) >> ODEMU_MAIL_PAGE_SHIFT);
}

// get offset from mailbox data
static inline
u32	ODEMUGetNngc2PcOffset	( u32 mail )
{
	return (u32)((ODEMUGetPage(mail) & 1) ? ODEMU_OFFSET_NNGC2PC : 0);
}

static inline
u32	ODEMUGetPc2NngcOffset	( u32 mail )
{
	return (u32)((ODEMUGetPage(mail) & 1) ? ODEMU_OFFSET_PC2NNGC : 0);
}

// get size from mailbox data
static inline
u32	ODEMUGetSize	( u32 mail )
{
	return (mail & ODEMU_MAIL_SIZE_MASK);
}

// valid mail?
static inline
BOOL	ODEMUIsValidMail	( u32 mail )
{
	return ((mail & ODEMU_MAIL_MAGIC_MASK) == ODEMU_MAIL_MAGIC);
}

#ifdef __cplusplus
}
#endif

#endif	// __ODEMU_EXI2_IF_H__
