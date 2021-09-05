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
$Log		�ύX����
$ 2001. 3.29	:V.2.00	
$ 2001. 6. 8	:V.2.10 ���f�B�A�T�C�Y�̃f�t�H���g�l��2GB�ɕύX					MSE M.O
$ 2001.11. 7	:V.2.20 
$ 2001.12. 7	:V.2.21 FAT�������T�C�Y�̃f�t�H���g�l��ύX						MSE M.O
$ 2002. 2.13	:V.2.80 �d���f�Ή�												MSE
$ 2002. 3.15	:V.2.90 VFAT�Ή�												MSE
$ 2002. 3.25	:V.3.00 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 6. 4	:V.3.02 MultiDrive�EFlashROM�Ή���2��							MSE M.O
$ 2002. 7. 5	:V.3.03 MultiDrive�EFlashROM�Ή���3��							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin�Ή���
========================================================================================*/
#ifndef __FS_CONF_H__
#define __FS_CONF_H__

/**** �P�D���i��� ****/
/* ���i��ʂ�ݒ�																		*/
/* �@�E�Đ��@�pFS�̏ꍇ			�FFS_PRODUCT_TYPE��[ FS_PLAYER  ]��ݒ�					*/
/* �@�E�^�ċ@�pFS�̏ꍇ			�FFS_PRODUCT_TYPE��[ FS_RECODER ]��ݒ�					*/
/* �d���f�Ή��̐ݒ�																		*/
/* �@�E�d���f�Ή�FS�̏ꍇ		�FFS_POWREC_SUPPORT��[ FS_POWREC   ]��ݒ�				*/
/* �@�E�d���f���Ή�FS�̏ꍇ		�FFS_POWREC_SUPPORT��[ FS_NOPOWREC ]��ݒ�				*/
/* FLASH ROM�Ή��̐ݒ�																	*/
/* �@�EFLASH ROM�Ή�FS�̏ꍇ	�FFS_FLASH_SUPPORT��[ FS_FLASH   ]���`				*/
/* �@�EFLASH ROM���Ή�FS�̏ꍇ	�FFS_FLASH_SUPPORT��[ FS_NOFLASH ]���`				*/
/* FAT�^�C�v�w��																		*/
/* �@�EFAT12/FAT16�Ή�FS�̏ꍇ	�FFS_FAT_TYPE��[ FS_SET_FAT  ]���`					*/
/* �@�EVFAT�Ή�FS�̏ꍇ			�FFS_FAT_TYPE��[ FS_SET_VFAT ]���`					*/
/*																						*/
/* Multi Drive�Ή��̐ݒ�																*/
/*�@ �EMulti Drive�Ή�FS�̏ꍇ	�FFS_SD_MULTI_TYPE��[ FS_MULTI_DRIVE  ]��ݒ�			/*
/*�@ �EMulti Drive���Ή�FS�̏ꍇ�FFS_SD_MULTI_TYPE��[ FS_SINGLE_DRIVE ]��ݒ�			/*
/*																						*/
#define FS_PRODUCT_TYPE				FS_RECODER							/* �f�t�H���g�l	*/
#define FS_POWREC_SUPPORT			FS_NOPOWREC							/* �f�t�H���g�l	*/
#define FS_FLASH_SUPPORT			FS_NOFLASH							/* Dolphin�Ή�	*/
#define FS_FAT_TYPE					FS_SET_FAT							/* �f�t�H���g�l	*/
#define FS_SD_MULTI_TYPE			FS_MULTI_DRIVE						/* Dolphin�Ή�	*/


/**** �Q�D���f�B�A�T�C�Y ****/
/* ���f�B�A�̃Z�N�^�T�C�Y��ݒ�															*/
/* �@( FS_MAX_TOTALSECTORS ) =< 4194304(2GB)											*/
/* ��64MB(131072�Z�N�^)�ȉ��w��ł̎g�p�𐄏��I���̐ݒ�l�ł̓���͖��m�F				*/
#define	FS_MAX_TOTALSECTORS			4194304								/* �f�t�H���g�l	*/


/**** �R�D�I�[�v���t�@�C���� ****/
/* �ő哯���I�[�v���ł���t�@�C������ݒ�												*/
/* �@1 =< ( FS_MAX_OF_NOR_OPEN ) =< 5													*/
/* �@1 =< ( FS_MAX_OF_EXT_OPEN ) =< 5													*/
/*																						*/
#define	FS_MAX_OF_NOR_OPEN			5									/* �f�t�H���g�l	*/
#define	FS_MAX_OF_EXT_OPEN			3									/* �f�t�H���g�l	*/

/**** �S�D�I�[�v���f�B���N�g���� ****/
/* �ő哯���I�[�v���ł���f�B���N�g������ݒ�											*/
/* �@�ʏ�̈�F1 =< ( FS_MAX_NOR_OPEN_DIR ) =< 3										*/
/* �@�F�ؗ̈�F1 =< ( FS_MAX_EXT_OPEN_DIR ) =< 3										*/
/*																						*/
#define FS_MAX_OF_NOR_OPEN_DIR		3									/* �f�t�H���g�l	*/
#define FS_MAX_OF_EXT_OPEN_DIR		2									/* �f�t�H���g�l	*/


/**** �T�D�f�B���N�g���̍ő�K�w���@****/
/* �f�B���N�g���̍ő�K�w����ݒ�														*/
/*�@�ʏ�̈�F1 =< ( FS_MAX_NOR_DEPTH ) =< 8											*/
/*�@�F�ؗ̈�F1 =< ( FS_MAX_EXT_DEPTH ) =< 8											*/
/* �����[�g�͊K�w�P																		*/
#define	FS_MAX_NOR_DEPTH			8									/* �f�t�H���g�l	*/
#define FS_MAX_EXT_DEPTH			5									/* �f�t�H���g�l	*/


/**** �U�D�}�E���g���[�h ****/
/* �}�E���g�̓��샂�[�h��ݒ�															*/
/* �@���f�B�A�t�H�[�}�b�g���m�F��														*/
/*	�EFATAL�G���[�ASD�K�i�ᔽ�AISO�K�i�ᔽ�𔻒f���鎞�A[1:FS_MOUNT_CHECK_ALL ]��ݒ�	*/
/*  �EFATAL�G���[�𔻒f���鎞�A�@�@�@�@�@�@�@�@�@�@ �@  [2:FS_MOUNT_CHECK_FATAL]��ݒ�	*/
/*																						*/
#define	FS_MOUNT_RET_MODE		FS_MOUNT_CHECK_FATAL					/* �f�t�H���g�l	*/

/**** �V�DFAT�������T�C�Y ****/
/* FAT�Ɏg�p���郁�����T�C�Y���o�C�g���Őݒ�											*/
/*�@( FS_ALL_FAT_MEM_SIZE )																*/
/*	 >= (2048B(2KB:�L���b�V��4BLOCK) + 2048B(2KB:�Ҕ�p�F��FAT))						*/
/* ��FAT���w�肵��FAT�������T�C�Y���傫���ꍇ�A�L���b�V���@�\���L���ƂȂ�				*/
/* �@���f�B�A�T�C�Y2GB(FAT16,�N���X�^32KB)�̎��A�I���������ɑSFAT�����ɂ�[ 129KB ]�K�v*/
/* �@���f�B�A�T�C�Y2GB(FAT16,�N���X�^32KB)�̎��A�ޔ�p�F��FAT�T�C�Y��[ 2KB ]�K�v		*/
/* �@�܂�A�d���f�Ή��@�\���L���̎��A�ޔ�p�F��FAT�T�C�Y�����������ɔ�ׂĕK�v�ƂȂ�@*/
#if FS_POWREC_SUPPORT == FS_POWREC
#define FS_ALL_FAT_MEM_SIZE				134144							/* �f�t�H���g�l	*/
#else
#define FS_ALL_FAT_MEM_SIZE				132096							/* �f�t�H���g�l	*/
#endif


/**** �W�DFAT�L���b�V���T�C�Y ****/
/* FAT���L���b�V���Ƃ��Ďg�p�����ꍇ�̃������P�u���b�N�̃T�C�Y��ݒ�					*/
/* �@( FS_FAT_CACHE_SIZE ) = (�Z�N�^�{����) = 512(B) * n								*/
/*										 ( n = 1,2,3,...((FA_FAT_MEM_SIZE/4)/512) )		*/
/* �@512 =< ( FS_FAT_CACHE_SIZE ) =< ( FS_FAT_MEM_SIZE/4 )								*/
/* ���L���b�V���L�����A�w��T�C�Y��FAT��read/write�����{								*/
#define FS_FAT_CACHE_SIZE			512									/* �f�t�H���g�l	*/


/**** �X�DFAT�ő�X�V�N���X�^���@****/
/* FAT�̍ő�X�V�N���X�^����ݒ�B�f�[�^�ی�̈�Ƃ��āAFAT�X�V�N���X�^���ɏ���l		*/
/* ��݂��A�ݒ�l�ȏ�̍X�V���s����ꍇ�ɂ́AFAT�A�f�B���N�g���G���g���Ȃǂ̊Ǘ�		*/
/* �������f�B�A�֏������ށB����ɂ��A��x�Ƀ��f�B�A�ɏ������݂��s���N���X�^����		*/
/* ������݂����邱�ƂɂȂ�A�f�[�^�ی�@�\���n�[�h�E�F�A�Ŏ�������w�W�ƂȂ�B		*/
/* �����Őݒ肷��u���b�N����FAT1�AFAT2�̃u���b�N���̍��v�ƂȂ�̂ŁA�Œ��2�ɂȂ�		*/
/* �@2 =< ( FS_MAX_FAT_MODIFY_CLUSTER ) =< 512											*/
/* ��FAT12�̏ꍇ�ŃN���X�^���E�ɂ܂�����ꍇ�A2�ɐݒ肵�Ă�1�N���X�^�]���ɏ�������		*/
/*   ����������																			*/
#define	FS_MAX_FAT_MODIFY_CLUSTER		512								/* �f�t�H���g�l	*/


/**** �P�O�D�擾�t���p�X�`����ʁ@****/
/* 	VFAT�Ή�����Getwd,Readdir,Getwi�Ŏ擾����t���p�X�̌`����ݒ�B						*/
/* �@�EDOS�`���擾FS�̏ꍇ�AFS_PATHNAME_TYPE��[ FS_DOS_TYPE  ]��ݒ�					*/
/* �@�ELFN�`���擾FS�̏ꍇ�AFS_PATHNAME_TYPE��[ FS_LFN_TYPE  ]��ݒ�					*/
/*																						*/
#if FS_FAT_TYPE == FS_SET_VFAT
#define	FS_PATHNAME_TYPE			FS_DOS_TYPE							/* �f�t�H���g�l	*/
#endif


/**** �P�P�D�h���C�u���  ****/
/*	�h���C�u���́A�h���C�u���Ƀh���C�u��ʂƃ|�[�g�ԍ���ݒ肷��B					*/
/*																						*/
/* 11.1. �P��ڂ̃h���C�u���ݒ�iFS_DRIVE_NO_0�j										*/
/*	�P��ڂɂ�SD�h���C�u�|�[�g�O���邢��FlashROM�h���C�u�|�[�g�O��ݒ肷�邱�Ƃ��\	*/
/*	�ESD�h���C�u�|�[�g�O��ݒ�															*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	�E FlashROM�h���C�u�|�[�g�O��ݒ�													*/
/*	#define		FS_DRIVE_NO_0		FS_FLASH_DRIVE_0									*/
/*																						*/
/* 11.2. �Q��ڂ̃h���C�u���ݒ�iFS_DRIVE_NO_1�j										*/
/* 11.2.1.�P��ڂ�SD�h���C�u�|�[�g�O��ݒ肵���ꍇ�A�Q��ڂɂ�SD�h���C�u�|�[�g�P�A		*/
/*	���邢��FlashROM�h���C�u�|�[�g�O�A���邢�̓T�|�[�g�h���C�u�Ȃ���ݒ肷�邱�Ƃ��\�@*/
/*	�ESD�h���C�u�|�[�g�P��ݒ�															*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_1										*/
/*	�EFlashROM�h���C�u�|�[�g�O��ݒ�													*/
/*	#define		FS_DRIVE_NO_1		FS_FLASH_DRIVE_0									*/
/*	�E�T�|�[�g�h���C�u�Ȃ���ݒ�														*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/*																						*/
/* 11.2.2.�P��ڂ�FlashROM�h���C�u�|�[�g�O��ݒ肵���ꍇ�A�Q��ڂɂ�SD�h���C�u�|�[�g�O�A*/
/*	���邢�̓T�|�[�g�h���C�u�Ȃ���ݒ肷�邱�Ƃ��\									*/
/*	�ESD�h���C�u�|�[�g�O��ݒ�															*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_0										*/
/*	�E�T�|�[�g�h���C�u�Ȃ���ݒ�														*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/*																						*/
/* 11.3.�h���C�u���̏ڍ�																*/	
/*	�h���C�u�ԍ��ɂ��A���f�o�C�X�ƃh���C�u�w��l�������N����B						*/
/* �� �T�|�[�g�\�ȍő�h���C�u�����Q��ł���ׁA�h���C�u�ԍ��ɂ͂O�ƂP��p����B		*/
/*	�@(�h���C�u�ԍ��O)			�F	FS_DRIVE_NO_0										*/
/*	�@(�h���C�u�ԍ��P)			�F	FS_DRIVE_NO_1										*/
/*																						*/
/*	�h���C�u�w��l�́A�h���C�u���Ɉ�ӂɌ��܂�l�ł���B								*/
/*	�@(�h���C�u�O�w��l)		�F	 FS_DRIVE_0											*/
/*	�@(�h���C�u�P�w��l)		�F	 FS_DRIVE_1											*/
/* �� �h���C�u�w��l��FS API�̈��� fsDriveNo�ɐݒ肷�邱�ƂŁA�Y���h���C�u�ԍ�������	*/
/*	���f�o�C�X�ɏ�����v�����邱�Ƃ��ł���B											*/
/*																						*/
/*	�h���C�u��ʂɂ��A�T�|�[�g����h���C�u�̎�ނ�ݒ肷��B							*/
/*	�h���C�u�̎�ނ́ASD�h���C�u��Flash ROM�h���C�o�A�y�уT�|�[�g�h���C�u�Ȃ��ł���B	*/
/*	�@(SD�h���C�u)				�F	FS_SD_DRIVE_(Port_No)								*/
/*	�@(Flash ROM�h���C�u)		�F	FS_FLASH_DRIVE_(Port_No)							*/
/*																						*/
/*	�|�[�g�ԍ�(Port_No)�ɂ��A����ʃh���C�u�̑I����ݒ肷��B							*/
/*	SD�h���C�o�́A�|�[�g�O�ƃ|�[�g�P��p���ĂQ��̃h���C�u���T�|�[�g����B				*/
/*	Flash ROM�h���C�u�́A�|�[�g�O��p���ĂP��̃h���C�o���T�|�[�g����B					*/
/*	�@(SD�h���C�u�|�[�g�O)		�F	FS_SD_DRIVE_0										*/	
/*	�@(SD�h���C�u�|�[�g�P)		�F	FS_SD_DRIVE_1										*/
/*	�@(Flash�h���C�u�|�[�g�O)	�F	FS_FLASH_DRIVE_0									*/
/*	�@																					*/
/*	fs_config.h�ŁA�h���C�o�ԍ��Ƀh���C�u��ʂƃ|�[�g�ԍ���ݒ肷��B					*/
/*	  #define	(�h���C�u�ԍ�)		(�h���C�u���)										*/
/*	�@(�h���C�u�ԍ�)			�F	FS_DRIVE_NO_(No)				(No=0,1)			*/
/*	�@(�h���C�u���)			�F	FS_SD_DRIVE_(Port_No)			(Port_No=0,1)		*/
/*								�F	FS_FLASH_DRIVE_(Port_No)		(Port_No=0)			*/
/*								�F 	FS_NONE_DRIVE										*/
/*																						*/
/*	�ݒ��																				*/
/*	�ESD�h���C�u�P���Flash�h���C�u�P����T�|�[�g����ꍇ�̐ݒ��						*/
/*	  �h���C�u�ԍ��O�̃h���C�u�Ƀ|�[�g�ԍ�0��SD Drive������t����B						*/
/*	�@�h���C�u�ԍ��P�̃h���C�u�Ƀ|�[�g�ԍ�0��Flash Drive������t����B					*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_FLASH_DRIVE_0									*/
/*																						*/
/*	�ESD�h���C�u�Q����T�|�[�g����ꍇ�̐ݒ��											*/
/*	�@�h���C�u�ԍ��O�̃h���C�u�Ƀ|�[�g�ԍ��O��SD Drive������t����B					*/
/*	�@�h���C�u�ԍ��P�̃h���C�u�Ƀ|�[�g�ԍ��P��SD Drive������t����B					*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_SD_DRIVE_1										*/
/*																						*/
/*	�ESD�h���C�u�P����T�|�[�g����ꍇ�̐ݒ��											*/
/*	�@�h���C�u�ԍ��O�̃h���C�u�Ƀ|�[�g�ԍ�0��SD Drive������t����B						*/
/*	�@�h���C�u�ԍ��P�ɃT�|�[�g�h���C�u�Ȃ�������t����B								*/
/*	#define		FS_DRIVE_NO_0		FS_SD_DRIVE_0										*/
/*	#define		FS_DRIVE_NO_1		FS_NONE_DRIVE										*/
/* �� FS_NONE_DRIVE�́A�L���h���C�u�ԍ���菬�����h���C�u�ԍ��ɐݒ�ł��Ȃ��B			*/
#define	FS_DRIVE_NO_0		FS_SD_DRIVE_0								/* �f�t�H���g�l	*/
#define	FS_DRIVE_NO_1		FS_SD_DRIVE_1								/* Dolphin�Ή�	*/


#endif
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/
/***** EOF ******************************************************************************/
