/*---------------------------------------------------------------------------*
  Project:  EXI API for RVA board
  File:     rva_exi.h

  (C)2007 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/private/rva_exi.h,v 1.1.2.1 2008-10-29 05:32:09 kinuwaki_shinichi Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__RVA_EXI_H__
#define	__RVA_EXI_H__

#ifdef __cplusplus
extern "C" {
#endif

	//-------------------------------------------------------------------------
	// memo
	//
	// 1) EXIに割り当てるデバイス
	//
	//	- EXI00	: BACKUP(SRAM)
	//
	//	- EXI1	: JVS(IO)/SI0/SI1/DISP SW/PUSH SW/WATCH DOC TIMER
	//
	// 2) EXIの制御
	//
	//	EXIの制御には、exi[D].aの外部非公開APIを使用

	//-------------------------------------------------------------------------
	// includes

#include <private/exi.h>
#include <private/rva_reg.h>

	//-------------------------------------------------------------------------
	// define

	// デバイスが使用するEXIチャネル番号、EXIデバイス番号
	//
	//- チャネル番号
#define	RVA_EXI_CHAN_BACKUP		0
#define	RVA_EXI_CHAN_OTHERS		1
	//- デバイス番号
#define	RVA_EXI_DEV_BACKUP		0
#define	RVA_EXI_DEV_OTHERS		0

	// EXIコマンド
	//
	//- address ( AD2-AD23 )
#define	RVA_EXI_CMD_ADDR(reg)			(((reg) << 6) & 0x3FFFFF00)
#define	RVA_EXI_CMD_BACKUP_ADDR(offs)	(RVA_EXI_CMD_ADDR((offs) + RVA_REG_BRAM))
	//- EXI Read/Write command
#define	RVA_EXI_CMD_WRITE_BIT			0x80000000
#define	RVA_EXI_READ_CMD(reg)			RVA_EXI_CMD_ADDR(reg)
#define	RVA_EXI_WRITE_CMD(reg)			(RVA_EXI_CMD_ADDR(reg) | RVA_EXI_CMD_WRITE_BIT)

	//-------------------------------------------------------------------------
	// type definition

	// EXIに割り当てるデバイスの種類
	typedef enum
	{
		RVA_EXI_DEVICE_BACKUP = 0,	// BACKUP(SRAM)
		RVA_EXI_DEVICE_OTHERS,		// JVS(IO)/SI0/SI1/SW/WATCH DOC TIMER
		RVA_EXI_DEVICE_UNKOWN
	}	RVA_EXIDevice;

	// EXI管理情報
	typedef struct
	{
		const s32			chan;		// EXIチャネル番号
		const u32			dev;		// EXIデバイス番号
		RVANotifyCallback	callback;	// 状態変化通知用コールバック関数
		void*				param;		// コールバック関数用引数
		BOOL				enabled;	// TRUE EXI使用可、FALSE EXI使用不可 
	}	RVA_EXIControl;

	//-------------------------------------------------------------------------
	// global symbol declared

	// EXI管理情報
	extern const RVA_EXIControl*	__RVA_EXIControlBackup;
	extern const RVA_EXIControl*	__RVA_EXIControlOthers;

	// clock frequency
	extern u32	__RVA_EXIFreq;

	//-------------------------------------------------------------------------
	// function prototypes

	BOOL	RVA_EXIOpen			( RVA_EXIDevice dev );
	void	RVA_EXIClose		( RVA_EXIDevice dev );
	BOOL	RVA_EXISetCallback	( RVA_EXIDevice dev, RVANotifyCallback callback, void* param );
	BOOL	RVA_EXIReadReg32	( RVA_EXIDevice dev, u32 exicmd, u32* reg, BOOL lock );
	BOOL	RVA_EXIWriteReg32	( RVA_EXIDevice dev, u32 exicmd, u32  reg, BOOL lock );

	// for RVA_BACKUP API
	void	RVA_EXITxHandler	( s32 chan, OSContext* );
	void	RVA_EXIRxHandler	( s32 chan, OSContext* );

	//-------------------------------------------------------------------------
	// inline function definition

	// Read 8bit register
	//
	static inline
	BOOL	RVA_EXIReadReg		( RVA_EXIDevice dev, u32 exicmd, u8* reg, BOOL lock )
	{
		u32 reg32;
		BOOL result = RVA_EXIReadReg32(dev, exicmd, &reg32, lock);
		*reg = (u8)(reg32 & 0xFF);
		return result;
	}

	// Write 8bit register
	//
	static inline
	BOOL	RVA_EXIWriteReg		( RVA_EXIDevice dev, u32 exicmd, u8  reg, BOOL lock )
	{
		return RVA_EXIWriteReg32(dev, exicmd, (u32)reg, lock);
	}

	// Read 16bit register
	//
	static inline
	BOOL	RVA_EXIReadReg16	( RVA_EXIDevice dev, u32 exicmd, u16* reg, BOOL lock )
	{
		u32 reg32;
		BOOL result = RVA_EXIReadReg32(dev, exicmd, &reg32, lock);
		*reg = (u16)(reg32 & 0xFFFF);
		return result;
	}

	// Write 16bit register
	//
	static inline
	BOOL	RVA_EXIWriteReg16	( RVA_EXIDevice dev, u32 exicmd, u16  reg, BOOL lock )
	{
		return RVA_EXIWriteReg32(dev, exicmd, (u32)reg, lock);
	}

#ifdef __cplusplus
}
#endif
#endif	// __RVA_EXI_H__
