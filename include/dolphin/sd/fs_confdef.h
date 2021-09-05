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
$Log		�ύX����
$ 2002. 3.25	:V.3.00 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 6. 4	:V.3.02 MultiDrive�EFlashROM�Ή���2��							MSE M.O
$ 2002. 7. 5	:V.3.03	MultiDrive�EFlashROM�Ή���3��							MSE M.O
========================================================================================*/
#ifndef __FS_CONFDEF_H__
#define __FS_CONFDEF_H__


/****	���i���				****/
#define	FS_PLAYER				1							/* SD Audio Player			*/
#define	FS_RECODER				2							/* SD Audio Recoder			*/
/****	�d���f�Ή��̐ݒ�		*****/
#define	FS_POWREC				1							/* �d���f�Ή��@��			*/
#define	FS_NOPOWREC				2							/* �d���f���Ή��@��			*/
/****	FLASH ROM�Ή��̐ݒ�		****/	
#define	FS_FLASH				1							/* FLASH ROM�Ή�			*/
#define	FS_NOFLASH				2							/* FLASH ROM���Ή�			*/
/****	FAT�^�C�v�w��			****/
#define	FS_SET_FAT				1							/* FAT12/16�@��				*/
#define	FS_SET_VFAT				2							/* VFAT/FAT32�Ή��@��		*/
/****	Multi Drive�Ή��̐ݒ�	****/
#define	FS_MULTI_DRIVE			1							/* Multi Drive�Ή�			*/
#define FS_SINGLE_DRIVE			2							/* Multi Drive���Ή�		*/
/****	�}�E���g���샂�[�h		****/
#define	FS_MOUNT_CHECK_ALL		1							/* FATAL�A�K�i�ᔽ���m�F	*/
#define	FS_MOUNT_CHECK_FATAL	2							/* FATAL�G���[�݂̂��m�F	*/
/**** �擾�t���p�X�`����ʁ@	****/
#define	FS_DOS_TYPE				1							/* DOS(8.3)�`��				*/
#define	FS_LFN_TYPE				2							/* LFN�`��					*/
/**** Multi Drive�֘A��`�@****/
#define	FS_DRIVE_0				0							/* �h���C�u�O�w��l			*/
#define	FS_DRIVE_1				1							/* �h���C�u�P�w��l			*/
#define	FS_DRIVE_2				2							/* �h���C�u�Q�w��l			*/
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