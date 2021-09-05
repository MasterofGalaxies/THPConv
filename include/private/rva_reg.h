/*---------------------------------------------------------------------------*
  Project:  RVA board register definition
  File:     rva_reg.h

  (C)2007 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/private/rva_reg.h,v 1.1.2.1 2008-10-29 05:32:10 kinuwaki_shinichi Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__RVA_REG_H__
#define	__RVA_REG_H__

#ifdef __cplusplus
extern "C" {
#endif

	//-------------------------------------------------------------------------
	// define

	// レジスタアドレス

	// BACKUP
#define	RVA_REG_BRAM			0x00A00000

	// WATCH DOC TIMER
#define	RVA_REG_WDR				0x00800000

	// JVS-SW : SW
#define	RVA_REG_JVS_SW			0x00900000

	// RS485 : JVS(IO)
#define	RVA_REG_RS485_CSR		0x00B00000
#define	RVA_REG_RS485_TxD		0x00B00004
#define	RVA_REG_RS485_TxCNT		0x00B00004
#define	RVA_REG_RS485_RxD		0x00B00008
#define	RVA_REG_RS485_RxCNT		0x00B0000C
#define	RVA_REG_RS485_TXLEN		0x00B00010
#define	RVA_REG_RS485_RXLEN		0x00B00014
#define	RVA_REG_RS485_DCSR		0x00B00018

	// UART1 : SI0
#define	RVA_REG_UART1_CSR		0x00C00000
#define	RVA_REG_UART1_TxD		0x00C00004
#define	RVA_REG_UART1_TxCNT		0x00C00004
#define	RVA_REG_UART1_RxD		0x00C00008
#define	RVA_REG_UART1_RxCNT		0x00C0000C
#define	RVA_REG_UART1_TxRAT		0x00C00010
#define	RVA_REG_UART1_RxRAT		0x00C00014

	// UART2 : SI1
#define	RVA_REG_UART2_CSR		0x00D00000
#define	RVA_REG_UART2_TxD		0x00D00004
#define	RVA_REG_UART2_TxCNT		0x00D00004
#define	RVA_REG_UART2_RxD		0x00D00008
#define	RVA_REG_UART2_RxCNT		0x00D0000C
#define	RVA_REG_UART2_TxRAT		0x00D00010
#define	RVA_REG_UART2_RxRAT		0x00D00014

	// RS485/UART1/UART2 CSR
#define	RVA_REG_RS485_UART12_CSR	0x00B0001C

	// レジスタフィールド(ビット値)

	// JVS-SW : SW
#define	RVA_JVS_SW_SYNC_SHIFT	7
#define	RVA_JVS_SW_SYNC_MASK	0x80
#define	RVA_JVS_SW_PSW_SHIFT	4
#define	RVA_JVS_SW_PSW_MASK		0x30
#define	RVA_JVS_SW_DSW_SHIFT	0
#define	RVA_JVS_SW_DSW_MASK		0x0F

	// RS485 : JVS(IO)
	//
	//- RS485_CSR
	//
	//	RX_INT
#define	RVA_RS485_CSR_RX_INT_SHIFT			7
#define	RVA_RS485_CSR_RX_INT_MASK			0x80
#define	RVA_RS485_CSR_RX_INT_NOT_OCCUR		1	// R
#define	RVA_RS485_CSR_RX_INT_OCCURRED		0	// R
#define	RVA_RS485_CSR_RX_INT_CLEAR			1	// W
	//	TX_INT
#define	RVA_RS485_CSR_TX_INT_SHIFT			6
#define	RVA_RS485_CSR_TX_INT_MASK			0x40
#define	RVA_RS485_CSR_TX_INT_NOT_OCCUR		1	// R
#define	RVA_RS485_CSR_TX_INT_OCCURRED		0	// R
#define	RVA_RS485_CSR_TX_INT_CLEAR			1	// W
	//	RX_INT_EN
#define	RVA_RS485_CSR_RX_INT_EN_SHIFT		5
#define	RVA_RS485_CSR_RX_INT_EN_MASK		0x20
#define	RVA_RS485_CSR_RX_INT_EN_DISABLE		1	// W
#define	RVA_RS485_CSR_RX_INT_EN_ENABLE		0	// W
	//	TX_INT_EN
#define	RVA_RS485_CSR_TX_INT_EN_SHIFT		4
#define	RVA_RS485_CSR_TX_INT_EN_MASK		0x10
#define	RVA_RS485_CSR_TX_INT_EN_DISABLE		1	// W
#define	RVA_RS485_CSR_TX_INT_EN_ENABLE		0	// W
	//	RESET
#define	RVA_RS485_CSR_RESET_SHIFT			0
#define	RVA_RS485_CSR_RESET_MASK			0x01
#define	RVA_RS485_CSR_RESET_REQUEST			0	// W
#define	RVA_RS485_CSR_RESET_CLEAR			1	// W
#define	RVA_RS485_CSR_RESET_END				1	// R
#define	RVA_RS485_CSR_RESET_NOW				0	// R
#define	RVA_RS485_CSR_RESET_NONE			1	// W
	//
	//- RS485_TxCNT
#define	RVA_RS485_TxCNT_MASK				0xFFF
	//
	//- RS485_RxCNT
#define	RVA_RS485_RxCNT_MASK				0xFFF
	//
	//- RS485_DCSR
	//
	//	SENSE
#define	RVA_RS485_DCSR_SENSE_MASK			0x80
#define	RVA_RS485_DCSR_SENSE_ENABLE			0
#define	RVA_RS485_DCSR_SENSE_DISABLE		1
	//	DCSR
#define	RVA_RS485_DCSR_DCSR_MASK			0x01
#define	RVA_RS485_DCSR_DCSR_READ			0
#define	RVA_RS485_DCSR_DCSR_WRITE			1

	// UART1/UART2 : SI0/SI1
	//
	//- UART_CSR
	//
	//	RX_INT
#define	RVA_UART_CSR_RX_INT_SHIFT			7
#define	RVA_UART_CSR_RX_INT_MASK			0x80
#define	RVA_UART_CSR_RX_INT_NOT_OCCUR		1	// R
#define	RVA_UART_CSR_RX_INT_OCCURRED		0	// R
#define	RVA_UART_CSR_RX_INT_CLEAR			1	// W
	//	TX_INT
#define	RVA_UART_CSR_TX_INT_SHIFT			6
#define	RVA_UART_CSR_TX_INT_MASK			0x40
#define	RVA_UART_CSR_TX_INT_NOT_OCCUR		1	// R
#define	RVA_UART_CSR_TX_INT_OCCURRED		0	// R
#define	RVA_UART_CSR_TX_INT_CLEAR			1	// W
	//	RX_INT_EN
#define	RVA_UART_CSR_RX_INT_EN_SHIFT		5
#define	RVA_UART_CSR_RX_INT_EN_MASK			0x20
#define	RVA_UART_CSR_RX_INT_EN_DISABLE		1	// W
#define	RVA_UART_CSR_RX_INT_EN_ENABLE		0	// W
	//	TX_INT_EN
#define	RVA_UART_CSR_TX_INT_EN_SHIFT		4
#define	RVA_UART_CSR_TX_INT_EN_MASK			0x10
#define	RVA_UART_CSR_TX_INT_EN_DISABLE		1	// W
#define	RVA_UART_CSR_TX_INT_EN_ENABLE		0	// W
	//	HW_FLOW
#define	RVA_UART_CSR_HW_FLOW_SHIFT			1
#define	RVA_UART_CSR_HW_FLOW_MASK			0x02
#define	RVA_UART_CSR_HW_FLOW_INVALID		1	// W
#define	RVA_UART_CSR_HW_FLOW_VALID			0	// W
	//	RESET
#define	RVA_UART_CSR_RESET_SHIFT			0
#define	RVA_UART_CSR_RESET_MASK				0x01
#define	RVA_UART_CSR_RESET_REQUEST			0	// W
#define	RVA_UART_CSR_RESET_CLEAR			1	// W
#define	RVA_UART_CSR_RESET_END				1	// R
#define	RVA_UART_CSR_RESET_NOW				0	// R
#define	RVA_UART_CSR_RESET_NONE				1	// W
	//
	//- UART_TxCNT
#define	RVA_UART_TxCNT_MASK					0xFFF
	//
	//- UART_RxCNT
#define	RVA_UART_RxCNT_MASK					0xFFF

	// RS485/UART1/UART2 CSR
#define	RVA_RS485_UART12_CSR_RSRX_INT_MASK		0x80
#define	RVA_RS485_UART12_CSR_RSTX_INT_MASK		0x40
#define	RVA_RS485_UART12_CSR_UART1RX_INT_MASK	0x20
#define	RVA_RS485_UART12_CSR_UART1TX_INT_MASK	0x10
#define	RVA_RS485_UART12_CSR_UART2RX_INT_MASK	0x08
#define	RVA_RS485_UART12_CSR_UART2TX_INT_MASK	0x04
#define	RVA_RS485_UART12_CSR_NOT_OCCUR			1	// R
#define	RVA_RS485_UART12_CSR_OCCURRED			0	// R

	//-------------------------------------------------------------------------
	// macro definition

	// JVS-SW : SW
	//
	//- JVS-SWのレジスタ値生成
#define	RVA_JVS_SW_VALUE(sync, psw, dsw)								\
	(u8)(																\
		 (((sync) << RVA_JVS_SW_SYNC_SHIFT) & RVA_JVS_SW_SYNC_MASK)		\
		|(((psw)  << RVA_JVS_SW_PSW_SHIFT)  & RVA_JVS_SW_PSW_MASK)		\
		|(((dsw)  << RVA_JVS_SW_DSW_SHIFT)  & RVA_JVS_SW_DSW_MASK)		\
		)
	//
	//- JVS-SWからSYNC値を取得
#define	RVA_JVS_SW_SYNC(reg)	\
	(u8)(((reg) & RVA_JVS_SW_SYNC_MASK) >> RVA_JVS_SW_SYNC_SHIFT)
	//
	//- JVS-SWからPUSH SW/DIP SW値を取得(ON=0なので、ビット反転させる)
#define	RVA_JVS_SW_SW(reg)	\
	(u8)(~(reg) & (RVA_JVS_SW_PSW_MASK | RVA_JVS_SW_DSW_MASK))

	// RS485 : JVS(IO)
	//
	//- RS485_CSR
	//
	//	RS485_CSRのレジスタ値生成
#define	RVA_RS485_CSR_VALUE(ri, ti, rie, tie, rst)									\
	(u8)(																			\
		 (((ri)  << RVA_RS485_CSR_RX_INT_SHIFT)    & RVA_RS485_CSR_RX_INT_MASK)		\
		|(((ti)  << RVA_RS485_CSR_TX_INT_SHIFT)    & RVA_RS485_CSR_TX_INT_MASK)		\
		|(((rie) << RVA_RS485_CSR_RX_INT_EN_SHIFT) & RVA_RS485_CSR_RX_INT_EN_MASK)	\
		|(((tie) << RVA_RS485_CSR_TX_INT_EN_SHIFT) & RVA_RS485_CSR_TX_INT_EN_MASK)	\
		|(((rst) << RVA_RS485_CSR_RESET_SHIFT)     & RVA_RS485_CSR_RESET_MASK)		\
		)
	//
	//	RS485_CSRからRX_INT値(をBOOLで)取得
#define	RVA_RS485_CSR_RX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_CSR_RX_INT_MASK))
	//
	//	RS485_CSRからTX_INT値(をBOOLで)取得
#define	RVA_RS485_CSR_TX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_CSR_TX_INT_MASK))
	//
	//-	RS485_TxCNT
#define	RVA_RS485_TxCNT_VALUE(cnt)		(u8)((cnt) & RVA_RS485_TxCNT_MASK)
	//
	//-	RS485_RxCNT
#define	RVA_RS485_RxCNT_VALUE(cnt)		(u8)((cnt) & RVA_RS485_RxCNT_MASK)
	//
	//- RS485_DCSR
	//
	//	RS485_DCSRのレジスタ値生成
#define	RVA_RS485_DCSR_VALUE(dcsr)		\
	(u8)((dcsr) & (RVA_RS485_DCSR_SENSE_MASK | RVA_RS485_DCSR_DCSR_MASK))
	//
	//	RS485_DCSRからSENSE値取得
#define	RVA_RS485_DCSR_SENSE(dcsr)		(u8)((dcsr) & RVA_RS485_DCSR_SENSE_MASK)
	//	RS485_DCSRからDCSR値取得
#define	RVA_RS485_DCSR_DCSR(dcsr)		(u8)((dcsr) & RVA_RS485_DCSR_DCSR_MASK)

	// UART1/UART2 : SI0/SI1
	//
	//- UART_CSR
	//
	//	UART_CSRのレジスタ値生成
#define	RVA_UART_CSR_VALUE(ri, ti, rie, tie, hf, rst)								\
	(u8)(																			\
		 (((ri)  << RVA_UART_CSR_RX_INT_SHIFT)    & RVA_UART_CSR_RX_INT_MASK)		\
		|(((ti)  << RVA_UART_CSR_TX_INT_SHIFT)    & RVA_UART_CSR_TX_INT_MASK)		\
		|(((rie) << RVA_UART_CSR_RX_INT_EN_SHIFT) & RVA_UART_CSR_RX_INT_EN_MASK)	\
		|(((tie) << RVA_UART_CSR_TX_INT_EN_SHIFT) & RVA_UART_CSR_TX_INT_EN_MASK)	\
		|(((hf)  << RVA_UART_CSR_HW_FLOW_SHIFT)   & RVA_UART_CSR_HW_FLOW_MASK)		\
		|(((rst) << RVA_UART_CSR_RESET_SHIFT)     & RVA_UART_CSR_RESET_MASK)		\
		)
	//
	//	UART_CSRからRX_INT値(をBOOLで)取得
#define	RVA_UART_CSR_RX_INT(reg)	\
	(BOOL)(!((reg) & RVA_UART_CSR_RX_INT_MASK))
	//
	//	UART_CSRからTX_INT値(をBOOLで)取得
#define	RVA_UART_CSR_TX_INT(reg)	\
	(BOOL)(!((reg) & RVA_UART_CSR_TX_INT_MASK))
	//
	//- UART_TxCNT
#define	RVA_UART_TxCNT_VALUE(cnt)		(u16)((cnt) & RVA_UART_TxCNT_MASK)
	//
	//- UART_RxCNT
#define	RVA_UART_RxCNT_VALUE(cnt)		(u16)((cnt) & RVA_UART_RxCNT_MASK)

	// RS485/UART1/UART2 CSR
	//
	//	RS485_UART12_CSRからRSRX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_RSRX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_RSRX_INT_MASK))
	//
	//	RS485_UART12_CSRからRSTX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_RSTX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_RSTX_INT_MASK))
	//
	//	RS485_UART12_CSRからUART1RX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_UART1RX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_UART1RX_INT_MASK))
	//
	//	RS485_UART12_CSRからUART1TX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_UART1TX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_UART1TX_INT_MASK))
	//
	//	RS485_UART12_CSRからUART2RX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_UART2RX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_UART2RX_INT_MASK))
	//
	//	RS485_UART12_CSRからUART2TX_INT(をBOOLで)取得
#define	RVA_RS485_UART12_CSR_UART2TX_INT(reg)	\
	(BOOL)(!((reg) & RVA_RS485_UART12_CSR_UART2TX_INT_MASK))

#ifdef __cplusplus
}
#endif
#endif	// __RVA_REG_H__
