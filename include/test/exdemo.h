/*---------------------------------------------------------------------------*
  Project:  ExDEMO library for NNGC test
  File:     exdemo.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/test/exdemo.h,v 1.1.2.1 2008-10-29 05:39:20 kinuwaki_shinichi Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

// RVL SDK - DEMOライブラリのラッパー関数
//
// - ROMフォント、パッドをまとめて初期化
// - DEMORFPuts/DEMORFPrintfの座標指定をフォント単位で行う為の細工
// - DEMOBefoerRendor/DEMOPadReadをまとめて処理 
//
// *1 GCコントローラ1のみ対応
// *2 コントローラ入力等、その他の処理は、DEMO or その他APIを直接呼ぶこと
//


#ifndef	__EXDEMO_H__
#define	__EXDEMO_H__

#include <demo.h>

#ifdef	__cplusplus
extern "C" {
#endif	// __cplusplus

	//-------------------------------------------------------------------------
	// type definition

	// パッド入力情報 : 十字キー、ボタンのみ対応
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

	// メニュー情報用コールバック関数
	//
	//	return TRUE:メニュー表示継続、FALSE:メニュー表示停止
	//
	typedef BOOL	(*EXDEMOMenuCallback)( void );

	// メニュー情報
	//
	//- メニューアイテム
	typedef struct
	{
		const char*	itemString;				// アイテム文字列
		int	itemPosX,	itemPosY;			// アイテム表示座標
		int	cursorPosX,	cursorPosY;			// カーソル表示座標
		EXDEMOMenuCallback	selectCallback;	// メニュー選択時に呼ばれる
		EXDEMOMenuCallback	buttonCallback;	// ボタン押下時に呼ばれる
		void*	data;						// ユーザーデータ
	} EXDEMOMenuItem;
	//
	//- メニュー
	typedef struct _EXDEMOMenu
	{
	// アプリケーションで設定するメンバ（初期化必要）
		const char*	titleString;			// タイトル
		int	titlePosX,	titlePosY;			// タイトル表示座標

		EXDEMOMenuItem**	items;			// メニューアイテム
		int	itemCount;						// メニューアイテム数

		EXDEMOMenuCallback	callback;		// 常に呼ばれる

	// ExDEMOMenuXXXX関数が設定するメンバ（初期化不要）
		int	curItem;						// 選択中のアイテム番号
		int	cursor;							// カーソル（ASCIIコード）
		struct _EXDEMOMenu*	preMenu;		// 事前に操作していたメニュー
	} EXDEMOMenu;

	//-------------------------------------------------------------------------
	// global sumbol declared

	// パッド入力情報
	extern EXDEMOPadButtonStatus
	ExDEMOButton, ExDEMOButtonUp, ExDEMOButtonDown;

	// メニュー情報
	extern EXDEMOMenu*	ExDEMOMenu;

	//-------------------------------------------------------------------------
	// function prototypes

	// 初期化
	void	ExDEMOInit		( void );

	// カラー設定関数
	//
	//- BG
	void	EXDEMOSetBgColor	( GXColor* col );
	//- Font
	void	EXDEMOSetFontColor	( GXColor* foreCol, GXColor* backCol );

	// ROMフォント表示関数
	//
	//- puts
	void	ExDEMOPuts		( int x, int y, char* string );
	//- printf
	void	ExDEMOPrintf	( int x, int y, const char* format, ... );

	// メニュー操作関数
	//
	//- 表示開始、設定
	void	ExDEMOMenuStart	( EXDEMOMenu* menu, int cursor );
	//- メニュー処理
	BOOL	ExDEMOMenuProc	( void );

	// アプリケーションの処理前に実行が必要な関数
	void	ExDEMOPreProc	( void );

	// その他
	void	ExDEMOFatal		( const char* format, ... );

	//-------------------------------------------------------------------------
	// inline function definition

	// アプリケーションの処理後に実行が必要な関数
	static inline
	void	ExDEMOPostProc	( void )
	{
		DEMODoneRender();
	}

	// メニュー操作関数
	//
	//- 初期化
	static inline
	void	ExDEMOMenuInit	( void )
	{
		ExDEMOMenu = NULL;
	}
	//- 表示終了
	static inline
	void	ExDEMOMenuEnd	( EXDEMOMenu* menu )
	{
		ExDEMOMenu = menu->preMenu;
	}
	//- 選択中のメニューアイテムを取得
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
