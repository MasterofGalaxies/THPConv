/*---------------------------------------------------------------------------*
  Project:  Dolphin SD Card API
  File:     sd.h

  Copyright 2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    1     03/11/10 16:05 Mitu

 *---------------------------------------------------------------------------*/
/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/

#ifndef __SD_H__
#define __SD_H__

//#include <dolphin/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DOLPHIN_SDFS

/*
 * 型宣言
 */
typedef char CHAR;					/* キャラクタ型 				*/
typedef int INT16;					/* 16ビット						*/
typedef long INT32;					/* 32ビット						*/
typedef unsigned char UCHAR;		/* 符号無しキャラクタ型 		*/
typedef unsigned short UINT16;		/* 符号無し16ビット				*/
typedef unsigned long UINT32;		/* 符号無し32ビット				*/

#include <dolphin/sd/fs_confdef.h>
#include <dolphin/sd/fs_config.h>
#include <dolphin/sd/fs_def.h>
#include <dolphin/sd/fs_type.h>
#include <dolphin/sd/fs_fsio.h>
#include <dolphin/sd/sd_com.h>					// For dolphin SD*

/*-------------------------------------
カードエラーコード
-------------------------------------*/
#define	CARD_NORMAL				0		//	正常終了
#define	CARD_ERR_COMMAND		0x0001	//	CMDエラー
#define	CARD_ERR_CRC			0x0002	//	CRCエラー
#define	CARD_ERR_END			0x0004	//	実行エラー
#define	CARD_ERR_R2_STATUS		0x0008	//	R2 Status Error
#define	CARD_ERR_EXI_ATTACH		0x0090	//	外部拡張デバイス接続エラー
#define	CARD_ERR_EXI_LOCK		0x00A0	//	EXI device lock error
#define	CARD_ERR_EXI_SELECT		0x00B0	//	EXI device select error
#define	CARD_ERR_EXI_DETACH		0x00C0	//	EXI device detach error
#define	CARD_ERR_EXI_UNLOCK		0x00D0	//	EXI device unlock error
#define	CARD_ERR_EXI_DESELECT	0x00E0	//	EXI device deselect error
#define	CARD_ERR_EXI_TRANS		0x00F0	//	EXI転送エラー
#define	CARD_ERR_ADDRESS		0x0100	//	アドレスエラー
#define	CARD_ERR_WRITE			0x0200	//	Data Rejected due to a Write Error
#define	CARD_ERR_WP				0x0400	//	WriteProtectによる書き込みエラー
#define	CARD_ERR_PARAM			0x1000	//	コマンドパラメータエラー
#define	CARD_ERR_TIMEOUT		0x4000	//	カードアクセス Timeout エラー
#define	CARD_ERR_RESET			0x8000	//	初期化カードリセットコマンド時1.5秒タイムアウトエラー

/*
 * SD Low level error code
 */
#define	SD_LOW_NORMAL			CARD_NORMAL			//	正常終了
#define	SD_LOW_ERR_COMMAND		CARD_ERR_COMMAND	//	CMDエラー
#define	SD_LOW_ERR_CRC			CARD_ERR_CRC		//	CRCエラー
#define	SD_LOW_ERR_END			CARD_ERR_END		//	実行エラー
#define	SD_LOW_ERR_R2_STATUS	CARD_ERR_R2_STATUS	//	R2 Status Error
#define	SD_LOW_ERR_EXI_ATTACH	CARD_ERR_EXI_ATTACH	//	外部拡張デバイス接続エラー
#define	SD_LOW_ERR_EXI_LOCK		CARD_ERR_EXI_LOCK	//	EXI device lock error
#define	SD_LOW_ERR_EXI_SELECT	CARD_ERR_EXI_SELECT	//	EXI device select error
#define	SD_LOW_ERR_EXI_DETACH	CARD_ERR_EXI_DETACH	//	EXI device detach error
#define	SD_LOW_ERR_EXI_UNLOCK	CARD_ERR_EXI_UNLOCK	//	EXI device unlock error
#define	SD_LOW_ERR_EXI_DESELECT	CARD_ERR_EXI_DESELECT	//	EXI device deselect error
#define	SD_LOW_ERR_EXI_TRANS	CARD_ERR_EXI_TRANS	//	EXI転送エラー
#define	SD_LOW_ERR_ADDRESS		CARD_ERR_ADDRESS	//	アドレスエラー
#define	SD_LOW_ERR_WRITE		CARD_ERR_WRITE		//	Data Rejected due to a Write Error
#define	SD_LOW_ERR_WP			CARD_ERR_WP			//	WriteProtectによる書き込みエラー
#define	SD_LOW_ERR_PARAM		CARD_ERR_PARAM		//	コマンドパラメータエラー
#define	SD_LOW_ERR_TIMEOUT		CARD_ERR_TIMEOUT	//	カードアクセス Timeout エラー
#define	SD_LOW_ERR_RESET		CARD_ERR_RESET		//	初期化カードリセットコマンド時1.5秒タイムアウトエラー

/*
 * SD_*** に定義しなおし
 */

/* デバイス情報 */
#define SDDrive 			FS_DRIVE
/* ファイルシステム情報 */
#define SDFs				FS_FS
/* ファイル情報 */
#define SDFile				FS_FILE
/* ディレクトリ情報 */
#define SDDir				FS_DIR
/* ディレクトリエントリ情報 */
#define SDEntry				FS_ENTRY
/* 実行結果通知情報 */
#define SDInfo				FS_INFO
/* ディレクトリエントリ情報 */
#define SDDirent			FS_DIRENT



#ifdef __cplusplus
}
#endif

#endif  // __SD_H__

