/*---------------------------------------------------------------------------*
  Project:  RVA board APIs
  File:     rva.h

  (C)2007 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/revolution/rva.h,v 1.1.2.1 2008-10-29 05:05:10 kinuwaki_shinichi Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__RVA_H__
#define	__RVA_H__

#ifdef __cplusplus
extern "C" {
#endif

	//-------------------------------------------------------------------------
	// includes

#include <revolution/types.h>

	//-------------------------------------------------------------------------
	// define

	// �ʐM���
#define	RVA_STATUS_TX		0x00000001	// ���M�\���
#define	RVA_STATUS_RX		0x00000002	// ��M�\���

	// JVS(IO)/SI FIFO�T�C�Y
#define	RVA_FIFO_SIZE		(2 * 1024)	// 2K bytes

	// SI�`���l���ԍ�
#define	RVA_SI_CHAN_0		0	// �V���A��1
#define	RVA_SI_CHAN_1		1	// �V���A��2
#define	RVA_SI_CHAN_MAX		2

	// BACKUP RAM�T�C�Y
#define	RVA_BACKUP_SIZE		(32 * 1024)	// 256K bits

	// SW�̏��
	//
	//- DIP SW
#define	RVA_SW_DSW_0		0x01
#define	RVA_SW_DSW_1		0x02
#define	RVA_SW_DSW_2		0x04
#define	RVA_SW_DSW_3		0x08
	//- PUSH SW
#define	RVA_SW_PSW_SEL		0x10
#define	RVA_SW_PSW_SET		0x20

	//-------------------------------------------------------------------------
	// type definition

	// RVA���̃f�o�C�X�̏�Ԃ��ω��������ɒʒm������e
	typedef enum
	{
		RVA_NOTIFY_JVS_SENT = 0,		// JVS(IO)�̐ڑ���փf�[�^���M����
		RVA_NOTIFY_JVS_RECEIVED,		// JVS(IO)�̐ڑ��悩��f�[�^����M
		RVA_NOTIFY_SI0_SENT,			// SI0�̐ڑ���փf�[�^���M����
		RVA_NOTIFY_SI0_RECEIVED,		// SI0�̐ڑ��悩��f�[�^����M
		RVA_NOTIFY_SI1_SENT,			// SI1�̐ڑ���փf�[�^���M����
		RVA_NOTIFY_SI1_RECEIVED,		// SI1�̐ڑ��悩��f�[�^����M
		RVA_NOTIFY_BACKUP_READ_DONE,	// BACKUP�̔񓯊�Read  ����
		RVA_NOTIFY_BACKUP_WRITE_DONE,	// BACKUP�̔񓯊�Write ����
		RVA_NOTIFY_BACKUP_DISCONNECT,	// BACKUP�pEXI�̔������o
		RVA_NOTIFY_OTHERS_DISCONNECT,	// ���f�o�C�X�pEXI�̔������o
		RVA_NOTIFY_MAX
	}	RVANotify;

	//-------------------------------------------------------------------------
	// callback prototypes

	/*------------------------------------------------------------------------*
	  Name:         RVANotifyCallback

	  Description:  RVA���̃f�o�C�X�̏�Ԃ��ω��������ɌĂ΂��R�[���o�b�N
					�֐�

	  Arguments:    notify		��ԕω��̎��
					param		�A�v���P�[�V�������w�肵������
				
	  Returns:      None.
	  *-----------------------------------------------------------------------*/
	typedef void	(* RVANotifyCallback)( RVANotify notify, void* param );

	//-------------------------------------------------------------------------
	// function prototypes

	//- system
	BOOL	RVAInit	( RVANotifyCallback callback, void* param );
	void	RVAExit	( void );

	//- JVS(IO) low level control
	BOOL	RVA_JVSLowInit			( u32 timeout );
	BOOL	RVA_JVSLowTransfer		( void* reqpkt, s32 reqbytes, void* ackpkt, s32 ackbytes, s32* rdackbytes );

	s32		RVA_JVSLowQueryData		( void );
	s32		RVA_JVSLowRead			( void* buffer, s32 nbytes );
	s32		RVA_JVSLowWrite			( void* buffer, s32 nbytes, s32 ackbytes );
	BOOL	RVA_JVSLowGetStatus		( u32* status );
	BOOL	RVA_JVSLowGetSense		( BOOL* sense );
	BOOL	RVA_JVSLowGetDirection	( BOOL* dir );
	BOOL	RVA_JVSLowSetDirection	( BOOL  dir );

	//- SI
	BOOL	RVA_SIInit			( s32 chan, u32 baudrate, BOOL hwflow, u32 timeout );
	s32		RVA_SIQueryData		( s32 chan );
	s32		RVA_SIRead			( s32 chan, void* buffer, s32 nbytes );
	s32		RVA_SIWrite			( s32 chan, void* buffer, s32 nbytes );
	BOOL	RVA_SIGetStatus		( s32 chan, u32* status );

	//- BACKUP RAM
	BOOL	RVA_BACKUPRead	( u32 addr, void* buffer, s32 size, BOOL block );
	BOOL	RVA_BACKUPWrite	( u32 addr, void* buffer, s32 size, BOOL block );

	//- SW
	BOOL	RVA_SWRead		( u8* sw );
	BOOL	RVA_SWReadSync	( BOOL* sync );
	BOOL	RVA_SWWriteSync	( BOOL  sync );

	//- WATCH DOC TIMER
	BOOL	RVA_WATCHStart	( u8  counter );
	BOOL	RVA_WATCHRead	( u8* counter );

	//-------------------------------------------------------------------------
	// inline function definition

	//- WATCH DOC TIMER
	//
	//- ������
	static inline
	BOOL	RVA_WATCHInit	( void )
	{
		return RVA_WATCHStart(0);
	}
	//- ��~
	static inline
	BOOL	RVA_WATCHStop	( void )
	{
		return RVA_WATCHStart(0);
	}

#ifdef __cplusplus
}
#endif
#endif	// __RVA_H__
