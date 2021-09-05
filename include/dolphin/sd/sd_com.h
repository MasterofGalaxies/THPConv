/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	sd_com.h
$Version	3.03a
$Author		
$Checker	
$Log		変更履歴
$ 2002. 6.27	:V.3.02a 外部用共通ヘッダ
$ 2002. 7.18	:V.3.03a 外部用共通ヘッダ
$=======================================================================================*/
#ifndef __SD_COM_H__
#define __SD_COM_H__

/* ------------------------------------------------------------------------------------ */
/*  Define																				*/
/* ------------------------------------------------------------------------------------ */

/****	ディレクトリ関連			****/
#define	SD_MAX_PATHNAME_LEN			FS_MAX_PATHNAME_LEN		/* ファイルパス名				*/

/****	ディレクトリ情報構造体		****/			/* 属性									*/
#define	SD_ATR_NOR					FS_ATR_NOR		/* ノーマル・ファイル					*/
#define	SD_ATR_ROL					FS_ATR_ROL		/* 読み出し専用ファイル					*/
#define	SD_ATR_HID					FS_ATR_HID		/* 隠されたファイル						*/
#define	SD_ATR_SYS					FS_ATR_SYS		/* システム・ファイル					*/
#define	SD_ATR_VOL					FS_ATR_VOL		/* ボリューム・ラベル					*/
#define	SD_ATR_DIR					FS_ATR_DIR		/* サブ・ディレクトリ					*/
#define	SD_ATR_ARC					FS_ATR_ARC		/* アーカイブ属性						*/
#define	SD_ATR_LNG					FS_ATR_LNG		/* ロングファイル名						*/

/****	ファイル情報構造体			****/
/****	カード定数					****/
#define	SD_READ_ACCESS				FS_READ_ACCESS	/* read									*/
#define	SD_WRITE_ACCESS				FS_WRITE_ACCESS	/* write								*/

/****	ファイル属性情報			****/
#define	SD_A_CLEAR					FS_A_CLEAR		/* 属性のクリア							*/
#define	SD_A_RDONLY					FS_A_RDONLY		/* 属性＝読み取り専用					*/
#define	SD_A_HIDDEN					FS_A_HIDDEN		/* 属性＝隠しファイル					*/
#define SD_A_SYSTEM					FS_A_SYSTEM		/* 属性＝システムファイル				*/
#define SD_A_ARCHIVE				FS_A_ARCHIVE	/* 属性＝アーカイブ属性					*/
#define SD_A_DIR					FS_A_DIR		/* 属性＝ディレクトリ					*/

/****	オープン属性				****/
#define	SD_O_RDONLY					FS_O_RDONLY		/* 読み込み専用							*/
#define	SD_O_WRONLY					FS_O_WRONLY		/* 書き込み専用							*/
#define	SD_O_RDWR					FS_O_RDWR		/* 読み書き両方							*/
#define	SD_O_APPEND					FS_O_APPEND		/* 追記									*/
#define	SD_O_CREAT					FS_O_CREAT		/* 新規作成								*/
#define	SD_O_EXCL					FS_O_EXCL		/* 新規作成（既存時エラー）				*/
#define	SD_O_TRUNC					FS_O_TRUNC		/* 既存ファイルの作り直し				*/

/****	シーク定数					****/
#define	SD_S_SET					FS_S_SET		/* オフセットをファイル先頭				*/
#define	SD_S_CUR					FS_S_CUR		/* オフセットを現在ポインタ				*/
#define	SD_S_END					FS_S_END		/* オフセットをファイル終わり			*/

/****	フォーマット定数			****/
#define	SD_F_ALL					FS_F_ALL		/* 通常フォーマット						*/
#define	SD_F_QUICK					FS_F_QUICK		/* クイックフォーマット					*/

/****	エラーコード				****/	
#define SD_E_SUCCESS				FS_E_SUCCESS				/* 成功								*/
#define	SD_E_CHECK_MASK				FS_E_CHECK_MASK				/* エラーベースマスク用データ		*/
#define	SD_E_BASE					FS_E_BASE					/* FS エラーベースコード			*/
#define SD_E_DRIVE_NOT_AVAILABLE	FS_E_DRIVE_NOT_AVAILABLE	/* 未：利用可能なドライブがない		*/
#define SD_E_DEVICE_ALREADY_MOUNTED	FS_E_DEVICE_ALREADY_MOUNTED	/* 既にマウント状態である　			*/
#define SD_E_DEVICE_NOT_MOUNTED		FS_E_DEVICE_NOT_MOUNTED		/* マウントされていない				*/
#define SD_E_TOO_MANY_OPEN_FILES	FS_E_TOO_MANY_OPEN_FILES	/* ファイルをオープンしすぎ			*/
#define SD_E_DEVICE_NON				FS_E_DEVICE_NON				/* 未：デバイスが見つからない		*/
#define SD_E_FILE_NOT_TYPE			FS_E_FILE_NOT_TYPE			/* ファイルタイプが異なる/不適合	*/
#define SD_E_FILE_NOT_FOUND			FS_E_FILE_NOT_FOUND			/* ファイルが見つからない			*/
#define SD_E_FILE_NOT_OPENED		FS_E_FILE_NOT_OPENED		/* ファイルがオープンしていない		*/
#define SD_E_FILE_OPENED			FS_E_FILE_OPENED			/* ファイルがオープンしている		*/
#define SD_E_BAD_FILE_TYPE			FS_E_BAD_FILE_TYPE			/* 未：Openファイルと種類が違う		*/
#define SD_E_BAD_OPEN_FLAG			FS_E_BAD_OPEN_FLAG			/* Openの方法が実行を妨げている		*/
#define	SD_E_BAD_VARIABLES			FS_E_BAD_VARIABLES			/* 変数/引数の値がおかしい			*/
#define SD_E_NOT_ENOUGH_MEMORY		FS_E_NOT_ENOUGH_MEMORY		/* メモリ不足						*/
#define SD_E_CANNOT_ACCESS_DEVICE	FS_E_CANNOT_ACCESS_DEVICE	/* デバイスにローアクセス不可		*/
#define SD_E_DIR_NOT_FOUND			FS_E_DIR_NOT_FOUND			/* ディレクトリが見つからない		*/
#define SD_E_CHILD_FILE_FOUND		FS_E_CHILD_FILE_FOUND		/* ディレクトリの中身が空でない		*/
#define SD_E_SAME_FILENAME			FS_E_SAME_FILENAME			/* 同一ファイル名が存在する			*/
#define SD_E_DEVICE_CAPACITY_FULL	FS_E_DEVICE_CAPACITY_FULL	/* デバイスの容量がFull Busy		*/
#define SD_E_OVER_MAX_DEPTH			FS_E_OVER_MAX_DEPTH			/* ディレクトリ深さが最大値Over		*/
#define SD_E_DETECTED_EOF			FS_E_DETECTED_EOF			/* EOFの検出						*/
#define SD_E_ALREADY_EOF			FS_E_ALREADY_EOF			/* 既にEOFを検出					*/
#define SD_E_DEVICE_TYPE			FS_E_DEVICE_TYPE			/* デバイス領域が間違っている		*/
#define SD_E_PATHNAME_LEN			FS_E_PATHNAME_LEN			/* パス名サイズオーバー				*/
#define SD_E_SAME_FILE_OPEN			FS_E_SAME_FILE_OPEN			/* 排他オープンエラー				*/
#define SD_E_END_OF_FILE			FS_E_END_OF_FILE			/* 未：ファイルの終端を検出			*/
#define SD_E_DISC_NOT_FORMAT		FS_E_DISC_NOT_FORMAT		/* フォーマットされていない			*/
#define SD_E_DISC_RW_FATAL			FS_E_DISC_RW_FATAL			/* 未：録再不可メディア				*/
#define SD_E_DISC_VIOLATION_ISO		FS_E_DISC_VIOLATION_ISO		/* ISD規格違反						*/
#define SD_E_DISC_VIOLATION_SD		FS_E_DISC_VIOLATION_SD		/* SD規格違反						*/
#define SD_E_PARAMETER_CANNOT_FIX	FS_E_PARAMETER_CANNOT_FIX	/* Format時のパラメータ計算失敗		*/
#define SD_E_FAT_WRITE_ERROR		FS_E_FAT_WRITE_ERROR		/* 未：Format時のFAT書込み計算ミス	*/
#define SD_E_BAD_NORMAL_AREA		FS_E_BAD_NORMAL_AREA		/* 未：通常領域がMCAP用でない		*/
#define	SD_E_ASYNC					FS_E_ASYNC					/* 非同期I/O 要求エラー				*/
#define SD_E_ACROSS_EOF				FS_E_ACROSS_EOF				/* 未：アクセス領域がEOFを含む		*/
#define SD_E_OVEROFFS				FS_E_OVEROFFS				/* アクセス領域がサイズ以上(EOF)	*/
#define SD_E_FDCTBL					FS_E_FDCTBL					/* 未：FDC Table異常				*/
#define SD_E_FATTBL					FS_E_FATTBL					/* 未：FAT Table異常				*/
#define SD_E_FATTBLFULL				FS_E_FATTBLFULL				/* 未：FAT Table Full				*/
#define SD_E_ATTRIBUTE				FS_E_ATTRIBUTE				/* ファイル属性エラー			
												 				    ファイルとディレクトリの種別エラー	*/
#define SD_E_BAD_OFFSET				FS_E_BAD_OFFSET				/* オフセット値が異常				*/
#define SD_E_BROKEN_FAT				FS_E_BROKEN_FAT				/* FATが壊れている					*/
#define SD_E_CANNOT_FIND_ENTRY		FS_E_CANNOT_FIND_ENTRY		/* エントリの獲得失敗				*/
#define SD_E_NOT_MATCH				FS_E_NOT_MATCH				/* 名前が一致しない					*/
#define	SD_E_BAD_FILENAME			FS_E_BAD_FILENAME			/* 不当なファイル名					*/
#define	SD_E_FS_ERROR				FS_E_FS_ERROR				/* FSの内部的なエラー				*/
#define	SD_E_DIR_NOT_OPENED			FS_E_DIR_NOT_OPENED			/* directoryはオープンしていない	*/
#define	SD_E_DIR_OPENED				FS_E_DIR_OPENED				/* directoryはオープンしている		*/
#define	SD_E_END_OF_DIR				FS_E_END_OF_DIR				/* directoryの終端である			*/
#define	SD_E_CANNOT_SEEK_DIR		FS_E_CANNOT_SEEK_DIR		/* 未：directoryのシークに失敗		*/
#define SD_E_BROKEN_ENTRY			FS_E_BROKEN_ENTRY			/* エントリが壊れている				*/
#define SD_E_CANNOT_RESIZE_FILE		FS_E_CANNOT_RESIZE_FILE		/* ファイルサイズの変更不可能		*/
#define	SD_E_BAD_PARTITION_SIZE		FS_E_BAD_PARTITION_SIZE		/* パーティション長が不適切			*/
#define SD_E_INVALID_ID_DEV_INFO	FS_E_INVALID_ID_DEV_INFO	/* 未：IdentifyDriveパラメータ異常	*/
#define SD_E_SEM_ERROR				FS_E_SEM_ERROR				/* セマフォエラー					*/
#define SD_E_NO_CARD				FS_E_NO_CARD				/* メディアが存在しない				*/
#define	SD_E_TOO_MANY_E_OPEN_FILES	FS_E_TOO_MANY_E_OPEN_FILES	/* 編集:ファイルオープン数の確保不可*/
#define SD_E_BOUNDARY				FS_E_BOUNDARY				/* クラスタサイズの倍数長でない		*/
#define SD_E_NO_MERGE				FS_E_NO_MERGE				/* 分割された同一ファイルでない		*/
#define SD_E_INVALID_DATE			FS_E_INVALID_DATE			/* 日付情報が不正					*/
#define SD_E_CONFIG_ERROR			FS_E_CONFIG_ERROR			/* FS_config.h設定値エラー			*/
#define SD_E_DRIVER_IO_ERROR		FS_E_DRIVER_IO_ERROR		/* ドライバI/Oエラー				*/
#define SD_E_DISC_V_ISO_FAT_CACHE	FS_E_DISC_V_ISO_FAT_CACHE	/* ISD規格違反 + FAT CACHE MODE		*/
#define SD_E_DISC_V_SD_FAT_CACHE	FS_E_DISC_V_SD_FAT_CACHE	/* SD規格違反  + FAT CACHE MODE		*/
#define SD_E_DISC_FAT_CACHE			FS_E_DISC_FAT_CACHE			/* FAT CACHE MODE					*/

/**** Multi Drive関連定義　****/
#define	SD_DRIVE_0					FS_DRIVE_0					/* ドライブ０指定値			*/
#define	SD_DRIVE_1					FS_DRIVE_1					/* ドライブ１指定値			*/

/**** ３．オープンファイル数 ****/
/* 最大同時オープンできるファイル数を設定												*/
#define	SD_MAX_OF_OPEN				FS_MAX_OF_OPEN

/**** ４．オープンディレクトリ数 ****/
/* 最大同時オープンできるディレクトリ数を設定											*/
#define SD_MAX_OF_OPEN_DIR			FS_MAX_OF_OPEN_DIR			/* デフォルト値	*/

/**** ５．ディレクトリの最大階層数　****/
/* ディレクトリの最大階層数を設定														*/
#define	SD_MAX_DEPTH 				FS_MAX_DEPTH
																/* サポートドライブ最大数	*/
#define	SD_MAX_DRIVE_NO				FS_MAX_DRIVE_NO				/* 最大Drive No.			*/


/* ------------------------------------------------------------------------------------ */
/*  データ構造体定義																	*/
/* ------------------------------------------------------------------------------------ */

/* デバイス情報 */
#define SD_DRIVE 			FS_DRIVE
/* ファイルシステム情報 */
#define SD_FS				FS_FS
/* ファイル情報 */
#define SD_FILE				FS_FILE
/* ディレクトリ情報 */
#define SD_DIR				FS_DIR
/* ディレクトリエントリ情報 */
#define SD_ENTRY			FS_ENTRY
/* 実行結果通知情報 */
#define SD_INFO				FS_INFO
/* ディレクトリエントリ情報 */
#define SD_DIRENT			FS_DIRENT

/* ------------------------------------------------------------------------------------ */
/*  関数プロトタイプ宣言																*/
/* ------------------------------------------------------------------------------------ */

/**** ファイルシステム操作関数 ****/
#define SDInit				FS_Init	
#define SDMount				FS_Mount
#define SDUmount			FS_Umount
#define SDGetfs				FS_Getfs
#define SDFormat	 		FS_Format
#define SDSync		 		FS_Sync

/**** ファイルI/O関数 ****/
#define SDOpen				FS_Open
#define SDClose	 			FS_Close
#define SDRead				FS_Read
#define SDWrite				FS_Write

#define SDSeek				FS_Seek
#define SDGetpos	 		FS_Getpos
#define SDSeteof	 		FS_Seteof

/**** ファイル属性関数 ****/
#define SDSetfa				FS_Setfa
#define SDGetfa				FS_Getfa

/**** ファイル操作関数 ****/
#define SDDelete 			FS_Delete
#define SDRename	 		FS_Rename

/**** ディレクトリ操作関数 ****/
#define SDMkdir 			FS_Mkdir
#define SDRmdir 			FS_Rmdir
#define SDOpendir 			FS_Opendir
#define SDClosedir 			FS_Closedir
#define SDReaddir 			FS_Readdir
#define SDSeekdir 			FS_Seekdir
#define SDChdir 			FS_Chdir
#define SDGetwd   			FS_Getwd

/**** MultiDrive用外部関数宣言 ****/
#define SDCardIFReset		FS_CardIFReset

#endif

/***** EOF *****************************************************************************/
