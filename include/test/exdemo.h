/*---------------------------------------------------------------------------*
  Project:  ExDEMO library for NNGC test
  File:     exdemo.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/test/exdemo.h,v 1.1.2.1 2008-10-29 05:39:20 kinuwaki_shinichi Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

// RVL SDK - DEMO���C�u�����̃��b�p�[�֐�
//
// - ROM�t�H���g�A�p�b�h���܂Ƃ߂ď�����
// - DEMORFPuts/DEMORFPrintf�̍��W�w����t�H���g�P�ʂōs���ׂ̍׍H
// - DEMOBefoerRendor/DEMOPadRead���܂Ƃ߂ď��� 
//
// *1 GC�R���g���[��1�̂ݑΉ�
// *2 �R���g���[�����͓��A���̑��̏����́ADEMO or ���̑�API�𒼐ڌĂԂ���
//


#ifndef	__EXDEMO_H__
#define	__EXDEMO_H__

#include <demo.h>

#ifdef	__cplusplus
extern "C" {
#endif	// __cplusplus

	//-------------------------------------------------------------------------
	// type definition

	// �p�b�h���͏�� : �\���L�[�A�{�^���̂ݑΉ�
	typedef union
	{
		u16	button;
		struct
		{
			unsigned	Align1	:3;
			unsigned	Start	:1;
			unsigned	Y		:1;
			unsigned	X		:1;
			unsigned	B		:1;
			unsigned	A		:1;
			unsigned	Align2	:1;
			unsigned	L		:1;
			unsigned	R		:1;
			unsigned	Z		:1;
			unsigned	Up		:1;
			unsigned	Down	:1;
			unsigned	Right	:1;
			unsigned	Left	:1;
		};
	} EXDEMOPadButtonStatus;

	// ���j���[���p�R�[���o�b�N�֐�
	//
	//	return TRUE:���j���[�\���p���AFALSE:���j���[�\����~
	//
	typedef BOOL	(*EXDEMOMenuCallback)( void );

	// ���j���[���
	//
	//- ���j���[�A�C�e��
	typedef struct
	{
		const char*	itemString;				// �A�C�e��������
		int	itemPosX,	itemPosY;			// �A�C�e���\�����W
		int	cursorPosX,	cursorPosY;			// �J�[�\���\�����W
		EXDEMOMenuCallback	selectCallback;	// ���j���[�I�����ɌĂ΂��
		EXDEMOMenuCallback	buttonCallback;	// �{�^���������ɌĂ΂��
		void*	data;						// ���[�U�[�f�[�^
	} EXDEMOMenuItem;
	//
	//- ���j���[
	typedef struct _EXDEMOMenu
	{
	// �A�v���P�[�V�����Őݒ肷�郁���o�i�������K�v�j
		const char*	titleString;			// �^�C�g��
		int	titlePosX,	titlePosY;			// �^�C�g���\�����W

		EXDEMOMenuItem**	items;			// ���j���[�A�C�e��
		int	itemCount;						// ���j���[�A�C�e����

		EXDEMOMenuCallback	callback;		// ��ɌĂ΂��

	// ExDEMOMenuXXXX�֐����ݒ肷�郁���o�i�������s�v�j
		int	curItem;						// �I�𒆂̃A�C�e���ԍ�
		int	cursor;							// �J�[�\���iASCII�R�[�h�j
		struct _EXDEMOMenu*	preMenu;		// ���O�ɑ��삵�Ă������j���[
	} EXDEMOMenu;

	//-------------------------------------------------------------------------
	// global sumbol declared

	// �p�b�h���͏��
	extern EXDEMOPadButtonStatus
	ExDEMOButton, ExDEMOButtonUp, ExDEMOButtonDown;

	// ���j���[���
	extern EXDEMOMenu*	ExDEMOMenu;

	//-------------------------------------------------------------------------
	// function prototypes

	// ������
	void	ExDEMOInit		( void );

	// �J���[�ݒ�֐�
	//
	//- BG
	void	EXDEMOSetBgColor	( GXColor* col );
	//- Font
	void	EXDEMOSetFontColor	( GXColor* foreCol, GXColor* backCol );

	// ROM�t�H���g�\���֐�
	//
	//- puts
	void	ExDEMOPuts		( int x, int y, char* string );
	//- printf
	void	ExDEMOPrintf	( int x, int y, const char* format, ... );

	// ���j���[����֐�
	//
	//- �\���J�n�A�ݒ�
	void	ExDEMOMenuStart	( EXDEMOMenu* menu, int cursor );
	//- ���j���[����
	BOOL	ExDEMOMenuProc	( void );

	// �A�v���P�[�V�����̏����O�Ɏ��s���K�v�Ȋ֐�
	void	ExDEMOPreProc	( void );

	// ���̑�
	void	ExDEMOFatal		( const char* format, ... );

	//-------------------------------------------------------------------------
	// inline function definition

	// �A�v���P�[�V�����̏�����Ɏ��s���K�v�Ȋ֐�
	static inline
	void	ExDEMOPostProc	( void )
	{
		DEMODoneRender();
	}

	// ���j���[����֐�
	//
	//- ������
	static inline
	void	ExDEMOMenuInit	( void )
	{
		ExDEMOMenu = NULL;
	}
	//- �\���I��
	static inline
	void	ExDEMOMenuEnd	( EXDEMOMenu* menu )
	{
		ExDEMOMenu = menu->preMenu;
	}
	//- �I�𒆂̃��j���[�A�C�e�����擾
	static inline
	EXDEMOMenuItem*	ExDEMOMenuGetItem	( void )
	{
		return ((ExDEMOMenu != NULL) && (ExDEMOMenu->itemCount > 0))
			? ExDEMOMenu->items[ExDEMOMenu->curItem] : NULL;
	}

#ifdef	__cplusplus
}
#endif	// __cplusplus
#endif	// __EXDEMO_H__
