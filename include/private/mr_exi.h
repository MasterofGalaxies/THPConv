/*---------------------------------------------------------------------------*
  Project:  NNGC EXI-USB/Mr.EXI API
  File:     mr_exi.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/private/mr_exi.h,v 1.2 2006-03-09 12:28:41 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__MR_EXI_H__
#define	__MR_EXI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <private/exi.h>

//-----------------------------------------------------------------------------
// define

//----- register definition
//
// UART
#define	EXI_REG_UART_CSR	0x00C00000
#define	EXI_REG_UART_TxD	0x00C00004
#define	EXI_REG_UART_TxCNT	0x00C00004
#define	EXI_REG_UART_RxD	0x00C00008
#define	EXI_REG_UART_RxCNT	0x00C0000C
// USB
#define	EXI_REG_USB_CSR		0x00D00000
#define	EXI_REG_USB_TxD		0x00D00004
#define	EXI_REG_USB_RxD		0x00D00008
#define	EXI_REG_USB_RAM		0x00D10000
// LED
#define	EXI_REG_GPIO_PO		0x00E00000
// DIP SW
#define	EXI_REG_GPIO_PI		0x00E00004
// SYSTEM
#define	EXI_REG_SYS_CSR		0x00F00000
#define	EXI_REG_SYS_VER		0x00F00004

//---- register constitution definition
//
// UART
//
// UART_CSR
//
//- size
#define	EXI_UART_CSR_SIZE					1	// byte
//- RX_INT
#define	EXI_UART_CSR_RX_INT_SHIFT			7
#define	EXI_UART_CSR_RX_INT_MASK			0x80
#define	EXI_UART_CSR_RX_INT_NOT_OCCUR		1	// R
#define	EXI_UART_CSR_RX_INT_OCCURRED		0	// R
#define	EXI_UART_CSR_RX_INT_CLEAR			1	// W
//- TX_INT
#define	EXI_UART_CSR_TX_INT_SHIFT			6
#define	EXI_UART_CSR_TX_INT_MASK			0x40
#define	EXI_UART_CSR_TX_INT_NOT_OCCUR		1	// R
#define	EXI_UART_CSR_TX_INT_OCCURRED		0	// R
#define	EXI_UART_CSR_TX_INT_CLEAR			1	// W
//- RX_INT_EN
#define	EXI_UART_CSR_RX_INT_EN_SHIFT		5
#define	EXI_UART_CSR_RX_INT_EN_MASK			0x20
#define	EXI_UART_CSR_RX_INT_EN_DISABLE		1	// W
#define	EXI_UART_CSR_RX_INT_EN_ENABLE		0	// W
//- TX_INT_EN
#define	EXI_UART_CSR_TX_INT_EN_SHIFT		4
#define	EXI_UART_CSR_TX_INT_EN_MASK			0x10
#define	EXI_UART_CSR_TX_INT_EN_DISABLE		1	// W
#define	EXI_UART_CSR_TX_INT_EN_ENABLE		0	// W
//- HW_FLOW
#define	EXI_UART_CSR_HW_FLOW_SHIFT			1
#define	EXI_UART_CSR_HW_FLOW_MASK			0x02
#define	EXI_UART_CSR_HW_FLOW_INVALID		1	// W
#define	EXI_UART_CSR_HW_FLOW_VALID			0	// W
//- RESET
#define	EXI_UART_CSR_RESET_SHIFT			0
#define	EXI_UART_CSR_RESET_MASK				0x01
#define	EXI_UART_CSR_RESET_REQUEST			0	// W
#define	EXI_UART_CSR_RESET_CLEAR			1	// W
#define	EXI_UART_CSR_RESET_END				1	// R
#define	EXI_UART_CSR_RESET_NOW				0	// R
#define	EXI_UART_CSR_RESET_NONE				1	// W
//
// UART_TxD
//
//- size
#define	EXI_UART_TxD_SIZE					1	// byte
//
#define	EXI_UART_TxD_MASK					0xFF
//
// UART_TxCNT
//
//- size
#define	EXI_UART_TxCNT_SIZE					1	// byte
//- cnt
#define	EXI_UART_TxCNT_MASK					0x3F
//
// UART_RxD
//
//- size
#define	EXI_UART_RxD_SIZE					1	// byte
//
#define	EXI_UART_RxD_MASK					0xFF
//
// UART_RxCNT
//
//- size
#define	EXI_UART_RxCNT_SIZE					1	// byte
//- cnt
#define	EXI_UART_RxCNT_MASK					0x3F

// USB
//
// USB_CSR
//
//- size
#define	EXI_USB_CSR_SIZE					1	// byte
//- RX_INT
#define	EXI_USB_CSR_RX_INT_SHIFT			7
#define	EXI_USB_CSR_RX_INT_MASK				0x80
#define	EXI_USB_CSR_RX_INT_NOT_OCCUR		1	// R
#define	EXI_USB_CSR_RX_INT_OCCURRED			0	// R
#define	EXI_USB_CSR_RX_INT_CLEAR			1	// W
//- TX_INT
#define	EXI_USB_CSR_TX_INT_SHIFT			6
#define	EXI_USB_CSR_TX_INT_MASK				0x40
#define	EXI_USB_CSR_TX_INT_NOT_OCCUR		1	// R
#define	EXI_USB_CSR_TX_INT_OCCURRED			0	// R
#define	EXI_USB_CSR_TX_INT_CLEAR			1	// W
//- RX_INT_EN
#define	EXI_USB_CSR_RX_INT_EN_SHIFT			5
#define	EXI_USB_CSR_RX_INT_EN_MASK			0x20
#define	EXI_USB_CSR_RX_INT_EN_DISABLE		1	// W
#define	EXI_USB_CSR_RX_INT_EN_ENABLE		0	// W
//- TX_INT_EN
#define	EXI_USB_CSR_TX_INT_EN_SHIFT			4
#define	EXI_USB_CSR_TX_INT_EN_MASK			0x10
#define	EXI_USB_CSR_TX_INT_EN_DISABLE		1	// W
#define	EXI_USB_CSR_TX_INT_EN_ENABLE		0	// W
//- RX_RDY
#define	EXI_USB_CSR_RX_RDY_SHIFT			3
#define	EXI_USB_CSR_RX_RDY_MASK				0x08
#define	EXI_USB_CSR_RX_RDY_NONE				1	// R
#define	EXI_USB_CSR_RX_RDY_RECEIVED			0	// R
//- TX_RDY
#define	EXI_USB_CSR_TX_RDY_SHIFT			2
#define	EXI_USB_CSR_TX_RDY_MASK				0x04
#define	EXI_USB_CSR_TX_RDY_IMPOSSIBILE		1	// R
#define	EXI_USB_CSR_TX_RDY_POSSIBLE			0	// R
//
// USB_TxD
//
//- size
#define	EXI_USB_TxD_SIZE					4	// byte
//
// USB_RxD
//
//- size
#define	EXI_USB_RxD_SIZE					4	// byte

// GPIO
//
// GPIO_PO
//
//- size
#define	EXI_GPIO_PO_SIZE					1	// byte
//
#define	EXI_GPIO_PO_MASK					0xFF
//
// GPIO_PI
//
//- size
#define	EXI_GPIO_PI_SIZE					1	// byte
//
#define	EXI_GPIO_PI_MASK					0xFF

// SYS
//
// SYS_CSR
//
//- size
#define	EXI_SYS_CSR_SIZE					1	// byte
//- UART_INT
#define	EXI_SYS_CSR_UART_INT_SHIFT			1
#define	EXI_SYS_CSR_UART_INT_MASK			0x02
#define	EXI_SYS_CSR_UART_INT_NOT_OCCUR		1	// R
#define	EXI_SYS_CSR_UART_INT_OCCURRED		0	// R
//- USB_INT
#define	EXI_SYS_CSR_USB_INT_SHIFT			0
#define	EXI_SYS_CSR_USB_INT_MASK			0x01
#define	EXI_SYS_CSR_USB_INT_NOT_OCCUR		1	// R
#define	EXI_SYS_CSR_USB_INT_OCCURRED		0	// R
//
#define	EXI_SYS_CSR_MASK					( EXI_SYS_CSR_UART_INT_MASK \
											| EXI_SYS_CSR_USB_INT_MASK )
//
// SYS_VER
//
//- size
#define	EXI_SYS_VER_SIZE					1	// byte
//
#define	EXI_SYS_VER_MASK					0xFF

//---- register macro definition
//
// UART
//
// UART_CSR
#define	EXI_UART_CSR_VALUE(ri, ti, rie, tie, hf, rst)						\
(u8)(																		\
	(((ri)  << EXI_UART_CSR_RX_INT_SHIFT)    & EXI_UART_CSR_RX_INT_MASK)	\
|	(((ti)  << EXI_UART_CSR_TX_INT_SHIFT)    & EXI_UART_CSR_TX_INT_MASK)	\
|	(((rie) << EXI_UART_CSR_RX_INT_EN_SHIFT) & EXI_UART_CSR_RX_INT_EN_MASK)	\
|	(((tie) << EXI_UART_CSR_TX_INT_EN_SHIFT) & EXI_UART_CSR_TX_INT_EN_MASK)	\
|	(((hf)  << EXI_UART_CSR_HW_FLOW_SHIFT)   & EXI_UART_CSR_HW_FLOW_MASK)	\
|	(((rst) << EXI_UART_CSR_RESET_SHIFT)     & EXI_UART_CSR_RESET_MASK)		\
)
//
// UART_TxCNT
#define	EXI_UART_TxCNT_VALUE(cnt)		(u8)((cnt) & EXI_UART_TxCNT_MASK)
//
// UART_RxCNT
#define	EXI_UART_RxCNT_VALUE(cnt)		(u8)((cnt) & EXI_UART_RxCNT_MASK)

// USB
//
// USB_CSR
#define	EXI_USB_CSR_VALUE(ri, ti, rie, tie, rr, tr)							\
(u8)(																		\
	(((ri)  << EXI_USB_CSR_RX_INT_SHIFT)    & EXI_USB_CSR_RX_INT_MASK)		\
|	(((ti)  << EXI_USB_CSR_TX_INT_SHIFT)    & EXI_USB_CSR_TX_INT_MASK)		\
|	(((rie) << EXI_USB_CSR_RX_INT_EN_SHIFT) & EXI_USB_CSR_RX_INT_EN_MASK)	\
|	(((tie) << EXI_USB_CSR_TX_INT_EN_SHIFT) & EXI_USB_CSR_TX_INT_EN_MASK)	\
|	(((rr)  << EXI_USB_CSR_RX_RDY_SHIFT)    & EXI_USB_CSR_RX_RDY_MASK)		\
|	(((tr)  << EXI_USB_CSR_TX_RDY_SHIFT)    & EXI_USB_CSR_TX_RDY_MASK)		\
)

// SYS
//
// SYS_CSR
#define	EXI_SYS_CSR_VALUE(uart_int, usb_int)					\
(u8)(															\
	(((uart_int) << EXI_UART_INT_SHIFT) & EXI_UART_INT_MASK)	\
|	(((usb_int)  << EXI_USB_INT_SHIFT)  & EXI_USB_INT_MASK)		\
)

//---- device ID
#ifndef	HW0
#	define	EXI_DEVID_EXI2USB	0x00000000	// EXI-USB
#	define	EXI_DEVID_MrEXI		0x00000000	// Mr.EXI - USB
#else	// HW0
#	define	EXI_DEVID_EXI2USB	0x01010000	// USB-ADAPTER
#endif	// HW0

//---- EXI channel for MrEXI
#ifdef	HW1
#	define	EXI_MrEXI_CHAN	1
#else	// HW1
#	define	EXI_MrEXI_CHAN	0
#endif	// HW1

//---- device number
#define	EXI_DEV_EXI2USB		0	// EXI00 / EXI10
#ifdef	HW1
#	define	EXI_DEV_MrEXI		0	// EXI10
#else	// HW1
#	define	EXI_DEV_MrEXI		1	// EXI01
#endif	// HW1

//---- console type
#define	EXI_CONSOLE_NDEV		0x00000001	// NDEV
#define	EXI_CONSOLE_NHC			0x00000002	// NHC
#define	EXI_CONSOLE_NNR			0x00000004	// NNR

//---- EXI command
//
// address ( AD2-AD23 )
#define	EXI_CMD_ADDR(reg)			(((reg) << 6) & 0x3FFFFF00)
#define	EXI_CMD_RAM_ADDR(offs)		(EXI_CMD_ADDR((offs) + EXI_REG_USB_RAM))
//
// EXI Read/Write command
#define	EXI_CMD_WRITE_BIT			0x80000000
//
#define	EXI_READ_CMD(reg)			EXI_CMD_ADDR(reg)
#define	EXI_WRITE_CMD(reg)			(EXI_CMD_ADDR(reg) | EXI_CMD_WRITE_BIT)

//-----------------------------------------------------------------------------
// external symbol declared

// clock frequency ( NNGC:EXI_FREQ_32, HW0:EXI_FREQ_16 )
extern const u32	__EXIFreq;	// build/libraries/exi/src/EXICommon.c

//-----------------------------------------------------------------------------
// function prototypes

// build/libraries/exi/src/EXICommon.c

u32		EXIGetConsoleType	( void );
void	EXIWait				( void );
BOOL	EXIReadReg			( s32 chan, u32 dev, u32 exiCmd, void* reg, s32 size );
BOOL	EXIWriteReg			( s32 chan, u32 dev, u32 exiCmd, void* reg, s32 size );
BOOL	EXIReadRam			( s32 chan, u32 dev, u32 exiCmd, void* buffer, s32 size, EXICallback callback );
BOOL	EXIWriteRam			( s32 chan, u32 dev, u32 exiCmd, const void* buffer, s32 size, EXICallback callback );
BOOL	EXIReadRamImm		( s32 chan, u32 dev, u32 exiCmd, void* buffer, s32 size );
BOOL	EXIWriteRamImm		( s32 chan, u32 dev, u32 exiCmd, const void* buffer, s32 size );

//-----------------------------------------------------------------------------
// inline function definition

static inline
u32	__EXISwap32( u32 val )
{
	return 
		((val >> 24) & 0x000000FF) |
		((val >>  8) & 0x0000FF00) |
		((val <<  8) & 0x00FF0000) |
		((val << 24) & 0xFF000000);
}

//-----------------------------------------------------------------------------
// EXI command for EXI-USB (special)

#ifndef	HW0

#define EXI_CMD_USB_READ_MAILBOX		EXI_READ_CMD(EXI_REG_USB_RxD)
#define EXI_CMD_USB_WRITE_MAILBOX(mail)	EXI_WRITE_CMD(EXI_REG_USB_TxD)
#define EXI_CMD_USB_READ_RAM(addr)		EXI_CMD_RAM_ADDR(addr)
#define EXI_CMD_USB_WRITE_RAM(addr)		(EXI_CMD_RAM_ADDR(addr) \
										| EXI_CMD_WRITE_BIT)
#define EXI_CMD_USB_READ_STATUS			EXI_READ_CMD(EXI_REG_USB_CSR)

#else	// HW0

// HW0 : USB-ADAPTER (for test) EXI command
#define EXI_CMD_USB_READ_MAILBOX		0x60000000
#define EXI_CMD_USB_WRITE_MAILBOX(mail)	(0xC0000000 | ((mail) & 0x1FFFFFFF))
#define EXI_CMD_USB_READ_RAM(addr)		(0x20000000 | \
										((addr << 8) & 0x01FFFC00))
#define EXI_CMD_USB_WRITE_RAM(addr)		(0xA0000000 | \
										((addr << 8) & 0x01FFFC00))
#define EXI_CMD_USB_READ_STATUS			0x40000000

#endif	// HW0

#ifdef __cplusplus
}
#endif

#endif	// __MR_EXI_H__
