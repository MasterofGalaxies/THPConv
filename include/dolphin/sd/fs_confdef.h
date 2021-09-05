/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	fs_confdef.h
$Version	3.03
$Author		MSE M.O
$Checker	DNC T.M, MSE M.O
$Log		変更履歴
$ 2002. 3.25	:V.3.00 MultiDrive・FlashROM対応α版							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive・FlashROM対応β版							MSE M.O
$ 2002. 6. 4	:V.3.02 MultiDrive・FlashROM対応β2版							MSE M.O
$ 2002. 7. 5	:V.3.03	MultiDrive・FlashROM対応β3版							MSE M.O
========================================================================================*/
#ifndef __FS_CONFDEF_H__
#define __FS_CONFDEF_H__


/****	製品種別				****/
#define	FS_PLAYER				1							/* SD Audio Player			*/
#define	FS_RECODER				2							/* SD Audio Recoder			*/
/****	電源断対応の設定		*****/
#define	FS_POWREC				1							/* 電源断対応機種			*/
#define	FS_NOPOWREC				2							/* 電源断未対応機種			*/
/****	FLASH ROM対応の設定		****/	
#define	FS_FLASH				1							/* FLASH ROM対応			*/
#define	FS_NOFLASH				2							/* FLASH ROM未対応			*/
/****	FATタイプ指定			****/
#define	FS_SET_FAT				1							/* FAT12/16機種				*/
#define	FS_SET_VFAT				2							/* VFAT/FAT32対応機種		*/
/****	Multi Drive対応の設定	****/
#define	FS_MULTI_DRIVE			1							/* Multi Drive対応			*/
#define FS_SINGLE_DRIVE			2							/* Multi Drive未対応		*/
/****	マウント動作モード		****/
#define	FS_MOUNT_CHECK_ALL		1							/* FATAL、規格違反を確認	*/
#define	FS_MOUNT_CHECK_FATAL	2							/* FATALエラーのみを確認	*/
/**** 取得フルパス形式種別　	****/
#define	FS_DOS_TYPE				1							/* DOS(8.3)形式				*/
#define	FS_LFN_TYPE				2							/* LFN形式					*/
/**** Multi Drive関連定義　****/
#define	FS_DRIVE_0				0							/* ドライブ０指定値			*/
#define	FS_DRIVE_1				1							/* ドライブ１指定値			*/
#define	FS_DRIVE_2				2							/* ドライブ２指定値			*/
#define	FS_SD_DRIVE				0x0100						/* SD Memory Card Drive		*/
#define	FS_SD_DRIVE_0			FS_SD_DRIVE		+ 0x0000	/* SD Memory Card Drive 0	*/
#define	FS_SD_DRIVE_1			FS_SD_DRIVE		+ 0x0001	/* SD Memory Card Drive 1	*/
#define	FS_SD_DRIVE_2			FS_SD_DRIVE		+ 0x0002	/* SD Memory Card Drive 2	*/
#define	FS_SD_DRIVE_3			FS_SD_DRIVE		+ 0x0003	/* SD Memory Card Drive 3	*/
#define	FS_FLASH_DRIVE			0x0200						/* Flash ROM Drive			*/
#define	FS_FLASH_DRIVE_0		FS_FLASH_DRIVE	+ 0x0000	/* Flash ROM Drive 0		*/
#define	FS_FLASH_DRIVE_1		FS_FLASH_DRIVE	+ 0x0001	/* Flash ROM Drive 1		*/
#define	FS_FLASH_DRIVE_2		FS_FLASH_DRIVE	+ 0x0002	/* Flash ROM Drive 2		*/
#define	FS_FLASH_DRIVE_3		FS_FLASH_DRIVE	+ 0x0003	/* Flash ROM Drive 3		*/


#endif
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/