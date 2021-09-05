/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	fs_config.h
$Version	3.03a
$Author		MSE M.O
$Checker	DNC T.M, MSE M.O, Y.K
$Log		変更履歴
$ 2001. 3.29	:V.2.00	
$ 2001. 6. 8	:V.2.10 メディアサイズのデフォルト値を2GBに変更					MSE M.O
$ 2001.11. 7	:V.2.20 
$ 2001.12. 7	:V.2.21 FATメモリサイズのデフォルト値を変更						MSE M.O
$ 2002. 2.13	:V.2.80 電源断対応												MSE
$ 2002. 3.15	:V.2.90 VFAT対応												MSE
$ 2002. 3.25	:V.3.00 MultiDrive・FlashROM対応α版							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive・FlashROM対応β版							MSE M.O
$ 2002. 6. 4	:V.3.02 MultiDrive・FlashROM対応β2版							MSE M.O
$ 2002. 7. 5	:V.3.03 MultiDrive・FlashROM対応β3版							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin対応版
========================================================================================*/
#ifndef __FS_CONF_H__
#define __FS_CONF_H__

/**** １．製品種別 ****/
/* 製品種別を設定																		*/
/* 　・再生機用FSの場合			：FS_PRODUCT_TYPEに[ FS_PLAYER  ]を設定					*/
/* 　・録再機用FSの場合			：FS_PRODUCT_TYPEに[ FS_RECODER ]を設定					*/
/* 電源断対応の設定																		*/
/* 　・電源断対応FSの場合		：FS_POWREC_SUPPORTに[ FS_POWREC   ]を設定				*/
/* 　・電源断未対応FSの場合		：FS_POWREC_SUPPORTに[ FS_NOPOWREC ]を設定				*/
/* FLASH ROM対応の設定																	*/
/* 　・FLASH ROM対応FSの場合	：FS_FLASH_SUPPORTに[ FS_FLASH   ]を定義				*/
/* 　・FLASH ROM未対応FSの場合	：FS_FLASH_SUPPORTに[ FS_NOFLASH ]を定義				*/
/* FATタイプ指定																		*/
/* 　・FAT12/FAT16対応FSの場合	：FS_FAT_TYPEに[ FS_SET_FAT  ]を定義					*/
/* 　・VFAT対応FSの場合			：FS_FAT_TYPEに[ FS_SET_VFAT ]を定義					*/
/*																						*/
/* Multi Drive対応の設定																*/
/*　 ・Multi Drive対応FSの場合	：FS_SD_MULTI_TYPEに[ FS_MULTI_DRIVE  ]を設定			/*
/*　 ・Multi Drive未対応FSの場合：FS_SD_MULTI_TYPEに[ FS_SINGLE_DRIVE ]を設定			/*
/*																						*/
#define FS_PRODUCT_TYPE				FS_RECODER							/* デフォルト値	*/
#define FS_POWREC_SUPPORT			FS_NOPOWREC							/* デフォルト値	*/
#define FS_FLASH_SUPPORT			FS_NOFLASH							/* Dolphin対応	*/
#define FS_FAT_TYPE					FS_SET_FAT							/* デフォルト値	*/
#define FS_SD_MULTI_TYPE			FS_MULTI_DRIVE						/* Dolphin対応	*/


/**** ２．メディアサイズ ****/
/* メディアのセクタサイズを設定															*/
/* 　( FS_MAX_TOTALSECTORS ) =< 4194304(2GB)											*/
/* ＠64MB(131072セクタ)以下指定での使用を推奨！他の設定値での動作は未確認				*/
#define	FS_MAX_TOTALSECTORS			4194304								/* デフォルト値	*/


/**** ３．オープンファイル数 ****/
/* 最大同時オープンできるファイル数を設定												*/
/* 　1 =< ( FS_MAX_OF_NOR_OPEN ) =< 5													*/
/* 　1 =< ( FS_MAX_OF_EXT_OPEN ) =< 5													*/
/*																						*/
#define	FS_MAX_OF_NOR_OPEN			5									/* デフォルト値	*/
#define	FS_MAX_OF_EXT_OPEN			3									/* デフォルト値	*/

/**** ４．オープンディレクトリ数 ****/
/* 最大同時オープンできるディレクトリ数を設定											*/
/* 　通常領域：1 =< ( FS_MAX_NOR_OPEN_DIR ) =< 3										*/
/* 　認証領域：1 =< ( FS_MAX_EXT_OPEN_DIR ) =< 3										*/
/*																						*/
#define FS_MAX_OF_NOR_OPEN_DIR		3									/* デフォルト値	*/
#define FS_MAX_OF_EXT_OPEN_DIR		2									/* デフォルト値	*/


/**** ５．ディレクトリの最大階層数　****/
/* ディレクトリの最大階層数を設定														*/
/*　通常領域：1 =< ( FS_MAX_NOR_DEPTH ) =< 8											*/
/*　認証領域：1 =< ( FS_MAX_EXT_DEPTH ) =< 8											*/
/* ＠ルートは階層１																		*/
#define	FS_MAX_NOR_DEPTH			8									/* デフォルト値	*/
#define FS_MAX_EXT_DEPTH			5									/* デフォルト値	*/


/**** ６．マウントモード ****/
/* マウントの動作モードを設定															*/
/* 　メディアフォーマットを確認し														*/
/*	・FATALエラー、SD規格違反、ISO規格違反を判断する時、[1:FS_MOUNT_CHECK_ALL ]を設定	*/
/*  ・FATALエラーを判断する時、　　　　　　　　　　 　  [2:FS_MOUNT_CHECK_FATAL]を設定	*/
/*																						*/
#define	FS_MOUNT_RET_MODE		FS_MOUNT_CHECK_FATAL					/* デフォルト値	*/

/**** ７．FATメモリサイズ ****/
/* FATに使用するメモリサイズをバイト数で設定											*/
/*　( FS_ALL_FAT_MEM_SIZE )																*/
/*	 >= (2048B(2KB:キャッシュ4BLOCK) + 2048B(2KB:待避用認証FAT))						*/
/* ＠FATが指定したFATメモリサイズより大きい場合、キャッシュ機能が有効となる				*/
/* 　メディアサイズ2GB(FAT16,クラスタ32KB)の時、オンメモリに全FATを持つには[ 129KB ]必要*/
/* 　メディアサイズ2GB(FAT16,クラスタ32KB)の時、退避用認証FATサイズは[ 2KB ]必要		*/
/* 　つまり、電源断対応機能が有効の時、退避用認証FATサイズ分が無効時に比べて必要となる　*/
#if FS_POWREC_SUPPORT == FS_POWREC
#define FS_ALL_FAT_MEM_SIZE				134144							/* デフォルト値	*/
#else
#define FS_ALL_FAT_MEM_SIZE				132096							/* デフォルト値	*/
#endif


/**** ８．FATキャッシュサイズ ****/
/* FATをキャッシュとして使用した場合のメモリ１ブロックのサイズを設定					*/
/* 　( FS_FAT_CACHE_SIZE ) = (セクタ倍数長) = 512(B) * n								*/
/*										 ( n = 1,2,3,...((FA_FAT_MEM_SIZE/4)/512) )		*/
/* 　512 =< ( FS_FAT_CACHE_SIZE ) =< ( FS_FAT_MEM_SIZE/4 )								*/
/* ＠キャッシュ有効時、指定サイズでFATのread/writeを実施								*/
#define FS_FAT_CACHE_SIZE			512									/* デフォルト値	*/


/**** ９．FAT最大更新クラスタ数　****/
/* FATの最大更新クラスタ数を設定。データ保護の一環として、FAT更新クラスタ数に上限値		*/
/* を設け、設定値以上の更新が行われる場合には、FAT、ディレクトリエントリなどの管理		*/
/* 情報をメディアへ書き込む。これにより、一度にメディアに書き込みを行うクラスタ数に		*/
/* 上限が設けられることになり、データ保護機能をハードウェアで実装する指標となる。		*/
/* ここで設定するブロック数はFAT1、FAT2のブロック数の合計となるので、最低は2になる		*/
/* 　2 =< ( FS_MAX_FAT_MODIFY_CLUSTER ) =< 512											*/
/* ＠FAT12の場合でクラスタ境界にまたがる場合、2に設定しても1クラスタ余分に書き込み		*/
/*   が発生する																			*/
#define	FS_MAX_FAT_MODIFY_CLUSTER		512								/* デフォルト値	*/


/**** １０．取得フルパス形式種別　****/
/* 	VFAT対応時にGetwd,Readdir,Getwiで取得するフルパスの形式を設定。						*/
/* 　・DOS形式取得FSの場合、FS_PATHNAME_TYPEに[ FS_DOS_TYPE  ]を設定					*/
/* 　・LFN形式取得FSの場合、FS_PATHNAME_TYPEに[ FS_LFN_TYPE  ]を設定					*/
/*																						*/
#if FS_FAT_TYPE == FS_SET_VFAT
#define	FS_PATHNAME_TYPE			FS_DOS_TYPE							/* デフォルト値	*/
#endif


/**** １１．ドライブ情報  ****/
/*	ドライブ情報は、ドライブ毎にドライブ種別とポート番号を設定する。					*/
/*																						*/
/* 11.1. １台目のドライブ情報設定（FS_DRIVE_NO_0）										*/
/*	１台目にはSDドライブポート０あるいはFlashROMドライブポート０を設定することが可能	*/
/*	・SDドライブポート０を設定															*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	・ FlashROMドライブポート０を設定													*/
/*	#define		FS_DRIVE_NO_0		FS_FLASH_DRIVE_0									*/
/*																						*/
/* 11.2. ２台目のドライブ情報設定（FS_DRIVE_NO_1）										*/
/* 11.2.1.１台目にSDドライブポート０を設定した場合、２台目にはSDドライブポート１、		*/
/*	あるいはFlashROMドライブポート０、あるいはサポートドライブなしを設定することが可能　*/
/*	・SDドライブポート１を設定															*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_1										*/
/*	・FlashROMドライブポート０を設定													*/
/*	#define		FS_DRIVE_NO_1		FS_FLASH_DRIVE_0									*/
/*	・サポートドライブなしを設定														*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/*																						*/
/* 11.2.2.１台目にFlashROMドライブポート０を設定した場合、２台目にはSDドライブポート０、*/
/*	あるいはサポートドライブなしを設定することが可能									*/
/*	・SDドライブポート０を設定															*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_0										*/
/*	・サポートドライブなしを設定														*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/*																						*/
/* 11.3.ドライブ情報の詳細																*/	
/*	ドライブ番号により、実デバイスとドライブ指定値をリンクする。						*/
/* ＠ サポート可能な最大ドライブ数が２台である為、ドライブ番号には０と１を用いる。		*/
/*	　(ドライブ番号０)			：	FS_DRIVE_NO_0										*/
/*	　(ドライブ番号１)			：	FS_DRIVE_NO_1										*/
/*																						*/
/*	ドライブ指定値は、ドライブ毎に一意に決まる値である。								*/
/*	　(ドライブ０指定値)		：	 FS_DRIVE_0											*/
/*	　(ドライブ１指定値)		：	 FS_DRIVE_1											*/
/* ＠ ドライブ指定値をFS APIの引数 fsDriveNoに設定することで、該当ドライブ番号を持つ	*/
/*	実デバイスに処理を要求することができる。											*/
/*																						*/
/*	ドライブ種別により、サポートするドライブの種類を設定する。							*/
/*	ドライブの種類は、SDドライブとFlash ROMドライバ、及びサポートドライブなしである。	*/
/*	　(SDドライブ)				：	FS_SD_DRIVE_(Port_No)								*/
/*	　(Flash ROMドライブ)		：	FS_FLASH_DRIVE_(Port_No)							*/
/*																						*/
/*	ポート番号(Port_No)により、同種別ドライブの選択を設定する。							*/
/*	SDドライバは、ポート０とポート１を用いて２台のドライブをサポートする。				*/
/*	Flash ROMドライブは、ポート０を用いて１台のドライバをサポートする。					*/
/*	　(SDドライブポート０)		：	FS_SD_DRIVE_0										*/	
/*	　(SDドライブポート１)		：	FS_SD_DRIVE_1										*/
/*	　(Flashドライブポート０)	：	FS_FLASH_DRIVE_0									*/
/*	　																					*/
/*	fs_config.hで、ドライバ番号にドライブ種別とポート番号を設定する。					*/
/*	  #define	(ドライブ番号)		(ドライブ種別)										*/
/*	　(ドライブ番号)			：	FS_DRIVE_NO_(No)				(No=0,1)			*/
/*	　(ドライブ種別)			：	FS_SD_DRIVE_(Port_No)			(Port_No=0,1)		*/
/*								：	FS_FLASH_DRIVE_(Port_No)		(Port_No=0)			*/
/*								： 	FS_NONE_DRIVE										*/
/*																						*/
/*	設定例																				*/
/*	・SDドライブ１台とFlashドライブ１台をサポートする場合の設定例						*/
/*	  ドライブ番号０のドライブにポート番号0のSD Driveを割り付ける。						*/
/*	　ドライブ番号１のドライブにポート番号0のFlash Driveを割り付ける。					*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_FLASH_DRIVE_0									*/
/*																						*/
/*	・SDドライブ２台をサポートする場合の設定例											*/
/*	　ドライブ番号０のドライブにポート番号０のSD Driveを割り付ける。					*/
/*	　ドライブ番号１のドライブにポート番号１のSD Driveを割り付ける。					*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_1										*/
/*																						*/
/*	・SDドライブ１台をサポートする場合の設定例											*/
/*	　ドライブ番号０のドライブにポート番号0のSD Driveを割り付ける。						*/
/*	　ドライブ番号１にサポートドライブなしを割り付ける。								*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/* ＠ FS_NONE_DRIVEは、有効ドライブ番号より小さいドライブ番号に設定できない。			*/
#define	FS_DRIVE_NO_0		FS_SD_DRIVE_0								/* デフォルト値	*/
#define	FS_DRIVE_NO_1		FS_SD_DRIVE_1								/* Dolphin対応	*/


#endif
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/
