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
$Log		�ύX����
$ 2002. 6.27	:V.3.02a �O���p���ʃw�b�_
$ 2002. 7.18	:V.3.03a �O���p���ʃw�b�_
$=======================================================================================*/
#ifndef __SD_COM_H__
#define __SD_COM_H__

/* ------------------------------------------------------------------------------------ */
/*  Define																				*/
/* ------------------------------------------------------------------------------------ */

/****	�f�B���N�g���֘A			****/
#define	SD_MAX_PATHNAME_LEN			FS_MAX_PATHNAME_LEN		/* �t�@�C���p�X��				*/

/****	�f�B���N�g�����\����		****/			/* ����									*/
#define	SD_ATR_NOR					FS_ATR_NOR		/* �m�[�}���E�t�@�C��					*/
#define	SD_ATR_ROL					FS_ATR_ROL		/* �ǂݏo����p�t�@�C��					*/
#define	SD_ATR_HID					FS_ATR_HID		/* �B���ꂽ�t�@�C��						*/
#define	SD_ATR_SYS					FS_ATR_SYS		/* �V�X�e���E�t�@�C��					*/
#define	SD_ATR_VOL					FS_ATR_VOL		/* �{�����[���E���x��					*/
#define	SD_ATR_DIR					FS_ATR_DIR		/* �T�u�E�f�B���N�g��					*/
#define	SD_ATR_ARC					FS_ATR_ARC		/* �A�[�J�C�u����						*/
#define	SD_ATR_LNG					FS_ATR_LNG		/* �����O�t�@�C����						*/

/****	�t�@�C�����\����			****/
/****	�J�[�h�萔					****/
#define	SD_READ_ACCESS				FS_READ_ACCESS	/* read									*/
#define	SD_WRITE_ACCESS				FS_WRITE_ACCESS	/* write								*/

/****	�t�@�C���������			****/
#define	SD_A_CLEAR					FS_A_CLEAR		/* �����̃N���A							*/
#define	SD_A_RDONLY					FS_A_RDONLY		/* �������ǂݎ���p					*/
#define	SD_A_HIDDEN					FS_A_HIDDEN		/* �������B���t�@�C��					*/
#define SD_A_SYSTEM					FS_A_SYSTEM		/* �������V�X�e���t�@�C��				*/
#define SD_A_ARCHIVE				FS_A_ARCHIVE	/* �������A�[�J�C�u����					*/
#define SD_A_DIR					FS_A_DIR		/* �������f�B���N�g��					*/

/****	�I�[�v������				****/
#define	SD_O_RDONLY					FS_O_RDONLY		/* �ǂݍ��ݐ�p							*/
#define	SD_O_WRONLY					FS_O_WRONLY		/* �������ݐ�p							*/
#define	SD_O_RDWR					FS_O_RDWR		/* �ǂݏ�������							*/
#define	SD_O_APPEND					FS_O_APPEND		/* �ǋL									*/
#define	SD_O_CREAT					FS_O_CREAT		/* �V�K�쐬								*/
#define	SD_O_EXCL					FS_O_EXCL		/* �V�K�쐬�i�������G���[�j				*/
#define	SD_O_TRUNC					FS_O_TRUNC		/* �����t�@�C���̍�蒼��				*/

/****	�V�[�N�萔					****/
#define	SD_S_SET					FS_S_SET		/* �I�t�Z�b�g���t�@�C���擪				*/
#define	SD_S_CUR					FS_S_CUR		/* �I�t�Z�b�g�����݃|�C���^				*/
#define	SD_S_END					FS_S_END		/* �I�t�Z�b�g���t�@�C���I���			*/

/****	�t�H�[�}�b�g�萔			****/
#define	SD_F_ALL					FS_F_ALL		/* �ʏ�t�H�[�}�b�g						*/
#define	SD_F_QUICK					FS_F_QUICK		/* �N�C�b�N�t�H�[�}�b�g					*/

/****	�G���[�R�[�h				****/	
#define SD_E_SUCCESS				FS_E_SUCCESS				/* ����								*/
#define	SD_E_CHECK_MASK				FS_E_CHECK_MASK				/* �G���[�x�[�X�}�X�N�p�f�[�^		*/
#define	SD_E_BASE					FS_E_BASE					/* FS �G���[�x�[�X�R�[�h			*/
#define SD_E_DRIVE_NOT_AVAILABLE	FS_E_DRIVE_NOT_AVAILABLE	/* ���F���p�\�ȃh���C�u���Ȃ�		*/
#define SD_E_DEVICE_ALREADY_MOUNTED	FS_E_DEVICE_ALREADY_MOUNTED	/* ���Ƀ}�E���g��Ԃł���@			*/
#define SD_E_DEVICE_NOT_MOUNTED		FS_E_DEVICE_NOT_MOUNTED		/* �}�E���g����Ă��Ȃ�				*/
#define SD_E_TOO_MANY_OPEN_FILES	FS_E_TOO_MANY_OPEN_FILES	/* �t�@�C�����I�[�v��������			*/
#define SD_E_DEVICE_NON				FS_E_DEVICE_NON				/* ���F�f�o�C�X��������Ȃ�		*/
#define SD_E_FILE_NOT_TYPE			FS_E_FILE_NOT_TYPE			/* �t�@�C���^�C�v���قȂ�/�s�K��	*/
#define SD_E_FILE_NOT_FOUND			FS_E_FILE_NOT_FOUND			/* �t�@�C����������Ȃ�			*/
#define SD_E_FILE_NOT_OPENED		FS_E_FILE_NOT_OPENED		/* �t�@�C�����I�[�v�����Ă��Ȃ�		*/
#define SD_E_FILE_OPENED			FS_E_FILE_OPENED			/* �t�@�C�����I�[�v�����Ă���		*/
#define SD_E_BAD_FILE_TYPE			FS_E_BAD_FILE_TYPE			/* ���FOpen�t�@�C���Ǝ�ނ��Ⴄ		*/
#define SD_E_BAD_OPEN_FLAG			FS_E_BAD_OPEN_FLAG			/* Open�̕��@�����s��W���Ă���		*/
#define	SD_E_BAD_VARIABLES			FS_E_BAD_VARIABLES			/* �ϐ�/�����̒l����������			*/
#define SD_E_NOT_ENOUGH_MEMORY		FS_E_NOT_ENOUGH_MEMORY		/* �������s��						*/
#define SD_E_CANNOT_ACCESS_DEVICE	FS_E_CANNOT_ACCESS_DEVICE	/* �f�o�C�X�Ƀ��[�A�N�Z�X�s��		*/
#define SD_E_DIR_NOT_FOUND			FS_E_DIR_NOT_FOUND			/* �f�B���N�g����������Ȃ�		*/
#define SD_E_CHILD_FILE_FOUND		FS_E_CHILD_FILE_FOUND		/* �f�B���N�g���̒��g����łȂ�		*/
#define SD_E_SAME_FILENAME			FS_E_SAME_FILENAME			/* ����t�@�C���������݂���			*/
#define SD_E_DEVICE_CAPACITY_FULL	FS_E_DEVICE_CAPACITY_FULL	/* �f�o�C�X�̗e�ʂ�Full Busy		*/
#define SD_E_OVER_MAX_DEPTH			FS_E_OVER_MAX_DEPTH			/* �f�B���N�g���[�����ő�lOver		*/
#define SD_E_DETECTED_EOF			FS_E_DETECTED_EOF			/* EOF�̌��o						*/
#define SD_E_ALREADY_EOF			FS_E_ALREADY_EOF			/* ����EOF�����o					*/
#define SD_E_DEVICE_TYPE			FS_E_DEVICE_TYPE			/* �f�o�C�X�̈悪�Ԉ���Ă���		*/
#define SD_E_PATHNAME_LEN			FS_E_PATHNAME_LEN			/* �p�X���T�C�Y�I�[�o�[				*/
#define SD_E_SAME_FILE_OPEN			FS_E_SAME_FILE_OPEN			/* �r���I�[�v���G���[				*/
#define SD_E_END_OF_FILE			FS_E_END_OF_FILE			/* ���F�t�@�C���̏I�[�����o			*/
#define SD_E_DISC_NOT_FORMAT		FS_E_DISC_NOT_FORMAT		/* �t�H�[�}�b�g����Ă��Ȃ�			*/
#define SD_E_DISC_RW_FATAL			FS_E_DISC_RW_FATAL			/* ���F�^�ĕs���f�B�A				*/
#define SD_E_DISC_VIOLATION_ISO		FS_E_DISC_VIOLATION_ISO		/* ISD�K�i�ᔽ						*/
#define SD_E_DISC_VIOLATION_SD		FS_E_DISC_VIOLATION_SD		/* SD�K�i�ᔽ						*/
#define SD_E_PARAMETER_CANNOT_FIX	FS_E_PARAMETER_CANNOT_FIX	/* Format���̃p�����[�^�v�Z���s		*/
#define SD_E_FAT_WRITE_ERROR		FS_E_FAT_WRITE_ERROR		/* ���FFormat����FAT�����݌v�Z�~�X	*/
#define SD_E_BAD_NORMAL_AREA		FS_E_BAD_NORMAL_AREA		/* ���F�ʏ�̈悪MCAP�p�łȂ�		*/
#define	SD_E_ASYNC					FS_E_ASYNC					/* �񓯊�I/O �v���G���[				*/
#define SD_E_ACROSS_EOF				FS_E_ACROSS_EOF				/* ���F�A�N�Z�X�̈悪EOF���܂�		*/
#define SD_E_OVEROFFS				FS_E_OVEROFFS				/* �A�N�Z�X�̈悪�T�C�Y�ȏ�(EOF)	*/
#define SD_E_FDCTBL					FS_E_FDCTBL					/* ���FFDC Table�ُ�				*/
#define SD_E_FATTBL					FS_E_FATTBL					/* ���FFAT Table�ُ�				*/
#define SD_E_FATTBLFULL				FS_E_FATTBLFULL				/* ���FFAT Table Full				*/
#define SD_E_ATTRIBUTE				FS_E_ATTRIBUTE				/* �t�@�C�������G���[			
												 				    �t�@�C���ƃf�B���N�g���̎�ʃG���[	*/
#define SD_E_BAD_OFFSET				FS_E_BAD_OFFSET				/* �I�t�Z�b�g�l���ُ�				*/
#define SD_E_BROKEN_FAT				FS_E_BROKEN_FAT				/* FAT�����Ă���					*/
#define SD_E_CANNOT_FIND_ENTRY		FS_E_CANNOT_FIND_ENTRY		/* �G���g���̊l�����s				*/
#define SD_E_NOT_MATCH				FS_E_NOT_MATCH				/* ���O����v���Ȃ�					*/
#define	SD_E_BAD_FILENAME			FS_E_BAD_FILENAME			/* �s���ȃt�@�C����					*/
#define	SD_E_FS_ERROR				FS_E_FS_ERROR				/* FS�̓����I�ȃG���[				*/
#define	SD_E_DIR_NOT_OPENED			FS_E_DIR_NOT_OPENED			/* directory�̓I�[�v�����Ă��Ȃ�	*/
#define	SD_E_DIR_OPENED				FS_E_DIR_OPENED				/* directory�̓I�[�v�����Ă���		*/
#define	SD_E_END_OF_DIR				FS_E_END_OF_DIR				/* directory�̏I�[�ł���			*/
#define	SD_E_CANNOT_SEEK_DIR		FS_E_CANNOT_SEEK_DIR		/* ���Fdirectory�̃V�[�N�Ɏ��s		*/
#define SD_E_BROKEN_ENTRY			FS_E_BROKEN_ENTRY			/* �G���g�������Ă���				*/
#define SD_E_CANNOT_RESIZE_FILE		FS_E_CANNOT_RESIZE_FILE		/* �t�@�C���T�C�Y�̕ύX�s�\		*/
#define	SD_E_BAD_PARTITION_SIZE		FS_E_BAD_PARTITION_SIZE		/* �p�[�e�B�V���������s�K��			*/
#define SD_E_INVALID_ID_DEV_INFO	FS_E_INVALID_ID_DEV_INFO	/* ���FIdentifyDrive�p�����[�^�ُ�	*/
#define SD_E_SEM_ERROR				FS_E_SEM_ERROR				/* �Z�}�t�H�G���[					*/
#define SD_E_NO_CARD				FS_E_NO_CARD				/* ���f�B�A�����݂��Ȃ�				*/
#define	SD_E_TOO_MANY_E_OPEN_FILES	FS_E_TOO_MANY_E_OPEN_FILES	/* �ҏW:�t�@�C���I�[�v�����̊m�ەs��*/
#define SD_E_BOUNDARY				FS_E_BOUNDARY				/* �N���X�^�T�C�Y�̔{�����łȂ�		*/
#define SD_E_NO_MERGE				FS_E_NO_MERGE				/* �������ꂽ����t�@�C���łȂ�		*/
#define SD_E_INVALID_DATE			FS_E_INVALID_DATE			/* ���t��񂪕s��					*/
#define SD_E_CONFIG_ERROR			FS_E_CONFIG_ERROR			/* FS_config.h�ݒ�l�G���[			*/
#define SD_E_DRIVER_IO_ERROR		FS_E_DRIVER_IO_ERROR		/* �h���C�oI/O�G���[				*/
#define SD_E_DISC_V_ISO_FAT_CACHE	FS_E_DISC_V_ISO_FAT_CACHE	/* ISD�K�i�ᔽ + FAT CACHE MODE		*/
#define SD_E_DISC_V_SD_FAT_CACHE	FS_E_DISC_V_SD_FAT_CACHE	/* SD�K�i�ᔽ  + FAT CACHE MODE		*/
#define SD_E_DISC_FAT_CACHE			FS_E_DISC_FAT_CACHE			/* FAT CACHE MODE					*/

/**** Multi Drive�֘A��`�@****/
#define	SD_DRIVE_0					FS_DRIVE_0					/* �h���C�u�O�w��l			*/
#define	SD_DRIVE_1					FS_DRIVE_1					/* �h���C�u�P�w��l			*/

/**** �R�D�I�[�v���t�@�C���� ****/
/* �ő哯���I�[�v���ł���t�@�C������ݒ�												*/
#define	SD_MAX_OF_OPEN				FS_MAX_OF_OPEN

/**** �S�D�I�[�v���f�B���N�g���� ****/
/* �ő哯���I�[�v���ł���f�B���N�g������ݒ�											*/
#define SD_MAX_OF_OPEN_DIR			FS_MAX_OF_OPEN_DIR			/* �f�t�H���g�l	*/

/**** �T�D�f�B���N�g���̍ő�K�w���@****/
/* �f�B���N�g���̍ő�K�w����ݒ�														*/
#define	SD_MAX_DEPTH 				FS_MAX_DEPTH
																/* �T�|�[�g�h���C�u�ő吔	*/
#define	SD_MAX_DRIVE_NO				FS_MAX_DRIVE_NO				/* �ő�Drive No.			*/


/* ------------------------------------------------------------------------------------ */
/*  �f�[�^�\���̒�`																	*/
/* ------------------------------------------------------------------------------------ */

/* �f�o�C�X��� */
#define SD_DRIVE 			FS_DRIVE
/* �t�@�C���V�X�e����� */
#define SD_FS				FS_FS
/* �t�@�C����� */
#define SD_FILE				FS_FILE
/* �f�B���N�g����� */
#define SD_DIR				FS_DIR
/* �f�B���N�g���G���g����� */
#define SD_ENTRY			FS_ENTRY
/* ���s���ʒʒm��� */
#define SD_INFO				FS_INFO
/* �f�B���N�g���G���g����� */
#define SD_DIRENT			FS_DIRENT

/* ------------------------------------------------------------------------------------ */
/*  �֐��v���g�^�C�v�錾																*/
/* ------------------------------------------------------------------------------------ */

/**** �t�@�C���V�X�e������֐� ****/
#define SDInit				FS_Init	
#define SDMount				FS_Mount
#define SDUmount			FS_Umount
#define SDGetfs				FS_Getfs
#define SDFormat	 		FS_Format
#define SDSync		 		FS_Sync

/**** �t�@�C��I/O�֐� ****/
#define SDOpen				FS_Open
#define SDClose	 			FS_Close
#define SDRead				FS_Read
#define SDWrite				FS_Write

#define SDSeek				FS_Seek
#define SDGetpos	 		FS_Getpos
#define SDSeteof	 		FS_Seteof

/**** �t�@�C�������֐� ****/
#define SDSetfa				FS_Setfa
#define SDGetfa				FS_Getfa

/**** �t�@�C������֐� ****/
#define SDDelete 			FS_Delete
#define SDRename	 		FS_Rename

/**** �f�B���N�g������֐� ****/
#define SDMkdir 			FS_Mkdir
#define SDRmdir 			FS_Rmdir
#define SDOpendir 			FS_Opendir
#define SDClosedir 			FS_Closedir
#define SDReaddir 			FS_Readdir
#define SDSeekdir 			FS_Seekdir
#define SDChdir 			FS_Chdir
#define SDGetwd   			FS_Getwd

/**** MultiDrive�p�O���֐��錾 ****/
#define SDCardIFReset		FS_CardIFReset

#endif

/***** EOF *****************************************************************************/
