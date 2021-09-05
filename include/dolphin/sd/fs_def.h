/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	fs_def.h
$Version	3.03a
$Author		MSE M.O, DNC T.M
$Checker	DNC T.M, MSE M.O, Y.K
$Log		�ύX����
$ 2001. 3.29	:V.2.00 
$ 2001. 6. 8	:V.2.10 
$ 2001.11. 7	:V.2.20
$ 2002. 2.13	:V.2.80 �d���f�Ή�												MSE
$ 2002. 3.15	:V.2.90 VFAT�Ή�												MSE
$ 2002. 3.25	:V.3.00 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive�EFlashROM�Ή�����							MSE M.O
$ 2002. 6. 3	:V.3.02 MultiDrive�EFlashROM�Ή���2��							MSE M.O
$ 2002. 7. 5	:V.3.03 MultiDrive�EFlashROM�Ή���3��							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin�Ή���							MSE M.O
$=======================================================================================*/
#ifndef __FS_DEF_H__
#define __FS_DEF_H__

/****	�\�[�X�R���p�C���p�萔		****/
#define FS_MN10200		 						/* MN10200�̂Ƃ��ɒ�`					*/
/****	���f�B�A���				****/
#define	FS_SD_CLASS					1			/* SD�J�[�h								*/
#define	FS_MMC_CLASS				2			/* MMC�J�[�h							*/
#define	FS_FLASH_CLASS				4			/* Flash ROM							*/
/*****	FDC���						****/
#define	FS_FAT16					1			/* FAT�̎��(FAT16:1,FAT12=2)			*/
#define	FS_FAT12					2			/* FAT�̎��(FAT16:1,FAT12=2)			*/
#define	FS_UNKNOWN					8			/* FAT12,FAT16�ȊO						*/
/****	MOUNT���					****/
#define	FS_UNMOUNTSTATE				1			/* unmount���							*/
#define	FS_MOUNTSTATE				2			/* mount���							*/
/****	�̈�敪					****/
#define	FS_NORMAL_AREA				1			/* �ʏ�̈�								*/
#define FS_EXTRA_AREA				2			/* �F�ؗ̈�								*/
#define FS_NOTUSE_AREA				3			/* FAT�L���b�V�����g�p�̈�p			*/
/****	�f�[�^�L���敪				****/
#define	FS_DataOfMBR				1			/* MBR�����݂���						*/
#define	FS_DataOfFDC				2			/* FDC�����݂���						*/
#define	FS_DataOfExtendedFDC		4			/* Extended FDC�����݂���				*/
/****	FAT�������Ǘ�				****/
#define FS_FAT_ONMEMORY				1			/* FAT�����ׂă������ɕێ�				*/
#define FS_FAT_OFFMEMORY			2			/* FAT�L���b�V���g�p					*/
/****	FAT�e�[�u��					****/
#define	FS_FAT1						1			/* FAT1�f�[�^							*/
#define	FS_FAT2						2			/* FAT2�f�[�^							*/
/****	FAT�L���b�V�����[�h			****/
#define FS_FAT_CACHE_NECESSARY_BLOCK	0x0004	/* FATcache�����ׂ̈ɕK�v��BLOCK��		*/
#define FS_FAT_CACHE					0x0001	/* FAT is cache							*/
#define FS_FAT_NOCACHE					0x0002	/* FAT is no cache						*/
#define	FS_FAT_READ_MASK				0x0f00	/* FAT�Ǎ��ݗp�}�X�N					*/
#define	FS_FAT_NOREAD					0x0000	/* FAT�Ǎ��ݗv���Ȃ�					*/
#define	FS_FAT_READ						0x0100	/* FAT�Ǎ��ݗv������			 �@		*/
/****	���f�B�A�T�C�Y				****/
#define	FS_FAT12_FAT16_BORDER_CLUSTERS	4085	/* FAT12�ő�f�[�^�G���A�T�C�Y(�N���X�^)*/
#define	FS_FAT12_BORDER_SECTORPERFAT	  12	/* FAT12:�N���X�^4085��SectorPerFAT		*/
#define	FS_FAT16_BORDER_SECTORPERFAT	  16	/* FAT16:�N���X�^4085��SectorPerFAT		*/
/****	�T�|�[�g�N���X�^			****/
#define	FS_SUPPORT_SECTORPERCLUSTER_1	 1		/* �T�|�[�g�N���X�^ 512B 				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_2	 2		/* �T�|�[�g�N���X�^  1KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_3	 4		/* �T�|�[�g�N���X�^  2KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_4	 8		/* �T�|�[�g�N���X�^  4KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_5	16		/* �T�|�[�g�N���X�^  8KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_6	32		/* �T�|�[�g�N���X�^ 16KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_7	64		/* �T�|�[�g�N���X�^ 32KB				*/
/****	�t�@�C���V�X�e�����\����	****/
#define FS_SECTOR_SIZE					512		/* �Z�N�^�T�C�Y							*/
#define FS_NUMBER_OF_FAT				2		/* FAT��								*/
#define	FS_ROOTDIR_ITEM_SIZE			32		/* ���[�g�f�B���N�g�����ڃT�C�YB		*/
#define FS_START_NUMBER_OF_CLUSTER		2		/* �N���X�^�擪�ԍ�						*/
#define FS_LOGICAL_SECTORPERCLUSTER	(FS_LOGICAL_CLUSTER_SIZE/FS_SECTOR_SIZE)
												/* �_���N���X�^�T�C�Y :�Z�N�^��			*/
/****	�f�B���N�g���֘A			****/
#if FS_FAT_TYPE == FS_SET_VFAT
#define	FS_MAX_PATHNAME_LEN				259		/* LFN�t�@�C���p�X��					*/
#else
#define	FS_MAX_PATHNAME_LEN				63		/* �t�@�C���p�X��						*/
#endif


/*****	FAT�ŗL�l�p�萔				****/
/*****	MBR-PT�I�t�Z�b�g			****/
#define	FS_OFFSET_MBR_RELATIVE_SECTORS	454		/* ���΃Z�N�^���I�t�Z�b�g				*/
#define	FS_OFFSET_MBR_TOTAL_SECTORS		458		/* ���Z�N�^���I�t�Z�b�g					*/
/****	FDC�I�t�Z�b�g				****/
#define	FS_OFFSET_TOTALSECTORS			19		/* �f�B�X�N���Z�N�^���I�t�Z�b�g			*/
#define	FS_OFFSET_SECTORSPERFAT			22		/* 1FAT������̃Z�N�^��					*/
#define	FS_OFFSET_EXTTOTALSECTORS		32		/* ��e�ʃf�B�X�N���Z�N�^���I�t�Z�b�g	*/
/****	FAT���						****/
#define	FS_FAT12D				"FAT12   "		/* FAT12 FDC.�\��(8byte�܂�)			*/
#define	FS_FAT16D				"FAT16   "		/* FAT12 FDC.�\��(8byte�܂�)			*/
#define	FS_FAT32D				"FAT32   "		/* FAT32 FDC.�\��(8byte�܂�)			*/
/****	�f�B���N�g�����\����		****/		/* ����									*/
#define	FS_ATR_NOR					0x00		/* �m�[�}���E�t�@�C��					*/
#define	FS_ATR_ROL					0x01		/* �ǂݏo����p�t�@�C��					*/
#define	FS_ATR_HID					0x02		/* �B���ꂽ�t�@�C��						*/
#define	FS_ATR_SYS					0x04		/* �V�X�e���E�t�@�C��					*/
#define	FS_ATR_VOL					0x08		/* �{�����[���E���x��					*/
#define	FS_ATR_DIR					0x10		/* �T�u�E�f�B���N�g��					*/
#define	FS_ATR_ARC					0x20		/* �A�[�J�C�u����						*/
#define	FS_ATR_LNG					0x0F		/* �����O�t�@�C����						*/
/****	FAT���\����				****/		/* �N���X�^�ԍ�							*/
#define	FS_FAT16_FUTURE_CLU			0xFFF6		/* FAT16:�����ׂ̈̊m�ۃN���X�^			*/
#define	FS_FAT12_FUTURE_CLU			0x0FF6		/* FAT12:�����ׂ̈̊m�ۃN���X�^			*/
#define	FS_FAT16_ERR_CLUSTER		0xFFF7		/* FAT16:���׃N���X�^					*/
#define	FS_FAT12_ERR_CLUSTER		0x0FF7		/* FAT12:���׃N���X�^					*/
#define	FS_FAT16_LAST_FILE_CLU		0xFFF8		/* FAT16:�t�@�C���ŏI�N���X�^			*/
#define	FS_FAT12_LAST_FILE_CLU		0x0FF8		/* FAT12:�t�@�C���ŏI�N���X�^			*/
#define	FS_FAT16_LAST_CLUSTER		0xFFFF		/* FAT16:�ŏI�N���X�^					*/	
#define	FS_FAT12_LAST_CLUSTER		0x0FFF		/* FAT12:�ŏI�N���X�^					*/
#define	FS_E_FAT_ERR_CLUSTER		0xFFF7		/* FAT:���׃N���X�^						*/
#define	FS_E_FAT_NG_IN_CLUSTER		0xFFFD		/* FAT:�w��N���X�^������				*/
#define	FS_E_FAT_NG_GET_CLUSTER		0xFFFE		/* FAT:�l���N���X�^������				*/
#define	FS_E_FAT_LAST_CLUSTER		0xFFFF		/* FAT:�ŏI�N���X�^						*/
/****	�t�@�C�����\����			****/
/****	�I�[�v������	�@�@�@		****/
#define	FS_FILE_NON					0x00		/* ���g�p								*/
#define	FS_FILE_DEL					0xE5		/* ����									*/
#define	FS_FILE_DIR					0x2E		/* �u.�v or �u..�v						*/
/****	�֐��̈����p�萔			****/
/****	�ҏW�@�\�p�萔				****/
#define	FS_SP_NO_COPY				1			/* �R�s�[�N���X�^����炸�ɕ�������		*/
#define	FS_SP_COPY					2			/* �R�s�[�N���X�^���쐬���ĕ�������		*/
#define	FS_M_NORMAL					1			/* �f�[�^�̔�r�`�F�b�N�Ȃ�				*/
#define	FS_M_COMPARE				2			/* �f�[�^�̔�r�`�F�b�N����				*/
/****	Chdir�p�萔					****/
#define	FS_CUR_NO_RELATION			1			/* �J�����g�ʒu�͒T���G���g���Ɩ��֌W	*/
#define	FS_CUR_OWN					2			/* �J�����g�ʒu���T���G���g�����g		*/
#define	FS_CUR_ANCESTOR				3			/* �J�����g�ʒu���T���G���g���̑c��		*/
/****	�J�[�h�萔					****/
#define	FS_READ_ACCESS				0x1000		/* read									*/
#define	FS_WRITE_ACCESS				0x2000		/* write								*/
/****	�t�@�C���������			****/
#define	FS_A_CLEAR					FS_ATR_NOR	/* �����̃N���A							*/
#define	FS_A_RDONLY					FS_ATR_ROL	/* �������ǂݎ���p					*/
#define	FS_A_HIDDEN					FS_ATR_HID	/* �������B���t�@�C��					*/
#define FS_A_SYSTEM					FS_ATR_SYS	/* �������V�X�e���t�@�C��				*/
#define FS_A_ARCHIVE				FS_ATR_ARC	/* �������A�[�J�C�u����					*/
#define FS_A_DIR					FS_ATR_DIR	/* �������f�B���N�g��					*/
/****	�I�[�v������				****/
#define	FS_O_RDONLY					0x0001		/* �ǂݍ��ݐ�p							*/
#define	FS_O_WRONLY					0x0002		/* �������ݐ�p							*/
#define	FS_O_RDWR					0x0004		/* �ǂݏ�������							*/
#define	FS_O_APPEND					0x0100		/* �ǋL									*/
#define	FS_O_CREAT					0x0200		/* �V�K�쐬								*/
#define	FS_O_EXCL					0x0400		/* �V�K�쐬�i�������G���[�j				*/
#define	FS_O_TRUNC					0x0800		/* �����t�@�C���̍�蒼��				*/
/**** �d���f��Open�O�߂�������ǉ����邽�ߕύX ****/
#if FS_POWREC_SUPPORT == FS_POWREC
#define	FS_O_NOT_USE				0xE0F8		/* ���g�popen����						*/	
#else
#define	FS_O_NOT_USE				0xF0F8		/* ���g�popen����						*/
#endif
/****	�V�[�N�萔					****/
#define	FS_S_SET					1			/* �I�t�Z�b�g���t�@�C���擪				*/
#define	FS_S_CUR					2			/* �I�t�Z�b�g�����݃|�C���^				*/
#define	FS_S_END					4			/* �I�t�Z�b�g���t�@�C���I���			*/
/****	�t�H�[�}�b�g�萔			****/
#define	FS_F_ALL					0x01		/* �ʏ�t�H�[�}�b�g						*/
#define	FS_F_QUICK					0x02		/* �N�C�b�N�t�H�[�}�b�g					*/
/****	���̑��t���O				****/
#define	FS_GET_CLUSTER				0x00		/*  �t�@�C���擪�N���X�^�̊l���v��		*/
/****	���f�B�A�ւ̏��X�V�v��	****/		/* to close								*/
#define	FS_SET_MODIFYFLAG			0x01		/* ���X�V�v���̐ݒ�					*/
#define	FS_CLR_MODIFYFLAG			0x00		/* ���X�V�v���̏�����					*/
/****	���N���X�^�̊l���֘A�f�[�^	****/
#define	FS_CLUSTER_NG				0x01		/* �s���ȃN���X�^�l						*/
#define	FS_CLUSTER_NOT_USED			0x00		/* �󂫃N���X�^�l						*/
/****	mount�`�F�b�N�R�[�h			****/
/****	�t�H�[�}�b�g�m�F���x��		****/
#define	CHECK_LEVEL_FATAL			1			/* �^�ĕs�`�F�b�N���x��				*/
#define	CHECK_LEVEL_SD				2			/* SD�K�i�`�F�b�N���x��					*/
#define	CHECK_LEVEL_ISO				4			/* ISO�K�i�`�F�b�N���x��				*/
/****	�t�H�[�}�b�g�G���[�敪		****/
#define	FS_RW_FATAL					1			/* �^�ĕs��								*/
#define	FS_VIOLATION_SD				2			/* SD Card Specification�ᔽ			*/
#define	FS_VIOLATION_ISO			4			/* ISO�ᔽ								*/
#define	FS_FAT_CACHE_MODE			8			/* FAT Cache���[�h�L�����				*/
/****	���f�B�A�L������			****/
#define FS_MEDIA_INFO_INIT			0xFFFF		/* ���W�X�^�̏����l						*/
#define	FS_MEDIA_INFO_EXIST			0xE000		/* �J�[�h���ʃr�b�g(���o������1)		*/
#define	FS_MEDIA_SD					0x8000		/* SD�J�[�h���ʃr�b�g(���o������1)		*/
#define	FS_MEDIA_MMC				0x4000		/* MMC�J�[�h���ʃr�b�g(���o������1)		*/
#define	FS_MEDIA_FLASH				0x2000		/* FLASH���ʃr�b�g(���o������1)			*/
#define FS_MEDIA_NOEXIST			0x0400		/* ���f�B�A�����݂��Ȃ����Ƃ�����		*/
/****	mount�`�F�b�N�R�[�h			****/
#define FS_MBR_BOOT_INDICATOR1		0x80		/* �u�[�g�C���W�P�[�^	 				*/
#define FS_MBR_BOOT_INDICATOR2		0x00		/* �u�[�g�C���W�P�[�^ 					*/
#define FS_MBR_PARTITION_TABLE		0x00		/* �p�[�e�B�V�����e�[�u��				*/
#define FS_MBR_TOTAL_SECTORS1		32680		/* ���Z�N�^�� 32680 					*/
#define FS_MBR_TOTAL_SECTORS2		65536		/* ���Z�N�^�� 65536 					*/
#define FS_MBR_SYSTEM_ID1			1			/* System ID 							*/
#define FS_MBR_SYSTEM_ID2			4			/* System ID 							*/
#define FS_MBR_SYSTEM_ID3			6			/* System ID 							*/
#define FS_SIGNATURE_WORD1			0x55		/* �V�O�j�`�����[�h1 					*/
#define FS_SIGNATURE_WORD2			0xaa		/* �V�O�j�`�����[�h2 					*/
#define FS_FDC_JUMP_EB				0xeb		/* Jump Command 0xeb					*/
#define FS_FDC_JUMP_E9				0xe9		/* Jump Command 0xe9		 			*/
#define FS_FDC_JUMP_90				0x90		/* Jump Command 0x90 					*/
#define FS_FDC_RESERVED_SECTOR_COUNT	1		/* �\��Z�N�^�� 						*/
#define FS_FDC_NUMBER_OF_ROOT_ENTRIES	512		/* ���[�g�f�B���N�g���G���g���̐�		*/
#define FS_FDC_MEDIUM_IDENTIFIER		0xf8	/* ���f�B�A�f�B�X�N���v�^ 				*/
#define FS_FDC_PHYSICAL_DISK_NUMBER		0x80	/* �����h���C�u�ԍ� 					*/
#define FS_FDC_RESERVED					0x00	/* Reserved 							*/
#define FS_FDC_EXTENDED_BOOT_RECORD_SIGNATURE	0x29	/* �g���u�[�g���R�[�h�L��		*/
#define FS_FDC_RESERVED_FUTURE			0x0000	/* �\�� 								*/
#define FS_FAT_FARST_BYTE				0xF8	/* FAT�̐擪�f�[�^ 						*/
#define FS_FAT_SECOND_BYTE				0xFF	/* FAT��2byte�ڃf�[�^ 					*/
/* Sectors per Cluster and Boundary Unit Recommendation 
												and CHS Recommendation�`�F�b�N�f�[�^	*/
#define	CHECK_DP_TBL_COUNT		 	 5			/* Count for Data/Protected Area	    */
#define	CHECK_PM_TBL_COUNT		 	10			/* Count for Min.ProtectedArea			*/
#define	CHECK_C_TBL_COUNT		 	 9			/* Count for CHS Recommendation			*/
#define	TABLE_END				0xffff			/* Table End							*/
#define	TARGET_AREA_SIZE1		   512			/* Size   256KB(sector)					*/
#define	TARGET_AREA_SIZE2		  2048			/*			1MB							*/
#define	TARGET_AREA_SIZE3		  4096			/*		    2MB							*/
#define	TARGET_AREA_SIZE4		  8192			/*		    4MB							*/
#define	TARGET_AREA_SIZE5		 16384			/*		    8MB							*/
#define	TARGET_AREA_SIZE6		 32768			/*		   16MB							*/
#define	TARGET_AREA_SIZE7		 65536			/*		   32MB							*/
#define	TARGET_AREA_SIZE8		131072			/*		   64MB							*/
#define	TARGET_AREA_SIZE9		262144			/*		  128MB							*/
#define	TARGET_AREA_SIZE10		524288			/*		  256MB							*/
#define	TARGET_AREA_SIZE11	   1032192			/*		  504MB							*/
#define	TARGET_AREA_SIZE12	   1048576			/*		  512MB							*/
#define	TARGET_AREA_SIZE13	   2064384			/*		 1008MB							*/
#define	TARGET_AREA_SIZE14	   2097152			/*		 1024MB							*/
#define	TARGET_AREA_SIZE15	   4128768			/*		 2016MB							*/
#define	TARGET_AREA_SIZE16	   4194304			/*		 2048MB							*/
#define	SECTOR_PER_CLUSTER1	    	 1			/* Sectors Per Cluster(Sector)			*/
#define	SECTOR_PER_CLUSTER2	    	 2			/* 	  									*/
#define	SECTOR_PER_CLUSTER3			 8			/* 	  									*/
#define	SECTOR_PER_CLUSTER4			16			/* 	 									*/
#define	SECTOR_PER_CLUSTER5			32			/* 	 									*/
#define	SECTOR_PER_CLUSTER6			64			/* 	 									*/
#define	BOUNDARY_UINT1				 1			/* Boundary Unit						*/
#define	BOUNDARY_UINT2				 2			/*    									*/
#define	BOUNDARY_UINT3				 8			/*    									*/
#define	BOUNDARY_UINT4				16			/*   									*/
#define	BOUNDARY_UINT5				32			/*   									*/
#define	BOUNDARY_UINT6			    64			/*   									*/
#define	BOUNDARY_UINT7			   128			/*  									*/
#define	NUMBER_OF_HEADS1			 2			/* Number Of Heads(sides)				*/
#define	NUMBER_OF_HEADS2			 4			/*	  									*/
#define	NUMBER_OF_HEADS3			 8			/*	  									*/
#define	NUMBER_OF_HEADS4			16			/*	 									*/
#define	NUMBER_OF_HEADS5			32			/*	 									*/
#define	NUMBER_OF_HEADS6			64			/*	 									*/
#define	NUMBER_OF_HEADS7		   128			/*										*/
#define	SECTOR_PER_TRACK1			16			/* Sectors Per Track(tracks)			*/
#define	SECTOR_PER_TRACK2			32			/*	 									*/
#define	SECTOR_PER_TRACK3			63			/*	 									*/
#define	MIN_P_AREA_SIZE1		   160			/* Min.Protected Area Size(sector)		*/
#define	MIN_P_AREA_SIZE2		   320			/*										*/
#define	MIN_P_AREA_SIZE3		   640			/*										*/
#define	MIN_P_AREA_SIZE4		  1280			/*										*/
#define	MIN_P_AREA_SIZE5		  2560			/*										*/
#define	MIN_P_AREA_SIZE6		  5120			/*										*/
#define	MIN_P_AREA_SIZE7		 10240			/*										*/
#define	MIN_P_AREA_SIZE8		 20480			/*										*/
#define	MIN_P_AREA_SIZE9		 40960			/*										*/
/* [ Check Table for Protected Area (P_TBL) ]
				Protected Area, Sectors per Cluster, Boundary Unit
	- 256KB		P_SIZE1,	P_CLUSTER1,		P_BOUNDARY1,
 	-   1MB		P_SIZE2,	P_CLUSTER2,		P_BOUNDARY2,
	-   4MB		P_SIZE3,	P_CLUSTER3,		P_BOUNDARY3,
	-1024MB		P_SIZE4,	P_CLUSTER4,		P_BOUNDARY4,
	-2048MB		P_SIZE5,	P_CLUSTER5,		P_BOUNDARY5	*/
#define	P_SIZE1			TARGET_AREA_SIZE1
#define	P_SIZE2			TARGET_AREA_SIZE2
#define	P_SIZE3			TARGET_AREA_SIZE4
#define	P_SIZE4			TARGET_AREA_SIZE14
#define	P_SIZE5			TARGET_AREA_SIZE16
#define	P_CLUSTER1		SECTOR_PER_CLUSTER1
#define	P_CLUSTER2		SECTOR_PER_CLUSTER2
#define	P_CLUSTER3		SECTOR_PER_CLUSTER3
#define	P_CLUSTER4		SECTOR_PER_CLUSTER5
#define	P_CLUSTER5		SECTOR_PER_CLUSTER6
#define	P_BOUNDARY1		BOUNDARY_UINT1
#define	P_BOUNDARY2		BOUNDARY_UINT2
#define	P_BOUNDARY3		BOUNDARY_UINT3
#define	P_BOUNDARY4		BOUNDARY_UINT5
#define	P_BOUNDARY5		BOUNDARY_UINT6
/* [ Check Table for Min.Protected Area Size (PM_TBL) ]
				Protected Area, Min.Protected Area Size
	-   4MB		P_MIN_C_SIZE1,	P_MIN_P_AREA_SIZE1,
 	-   8MB		P_MIN_C_SIZE2,	P_MIN_P_AREA_SIZE2,
 	-  16MB		P_MIN_C_SIZE3,	P_MIN_P_AREA_SIZE3,
 	-  32MB		P_MIN_C_SIZE4,	P_MIN_P_AREA_SIZE4,
 	-  64MB		P_MIN_C_SIZE5,	P_MIN_P_AREA_SIZE5,
 	- 128MB		P_MIN_C_SIZE6,	P_MIN_P_AREA_SIZE6,
 	- 256MB		P_MIN_C_SIZE7,	P_MIN_P_AREA_SIZE7,
	- 512MB		P_MIN_C_SIZE8,	P_MIN_P_AREA_SIZE8,
	-1024MB		P_MIN_C_SIZE9,	P_MIN_P_AREA_SIZE9,
	-2048MB		P_MIN_C_SIZE10,	P_MIN_P_AREA_SIZE10	*/
#define	P_MIN_C_SIZE1			TARGET_AREA_SIZE4
#define	P_MIN_C_SIZE2			TARGET_AREA_SIZE5
#define	P_MIN_C_SIZE3			TARGET_AREA_SIZE6
#define	P_MIN_C_SIZE4			TARGET_AREA_SIZE7
#define	P_MIN_C_SIZE5			TARGET_AREA_SIZE8
#define	P_MIN_C_SIZE6			TARGET_AREA_SIZE9
#define	P_MIN_C_SIZE7			TARGET_AREA_SIZE10
#define	P_MIN_C_SIZE8			TARGET_AREA_SIZE12
#define	P_MIN_C_SIZE9			TARGET_AREA_SIZE14
#define	P_MIN_C_SIZE10		TARGET_AREA_SIZE16
#define	P_MIN_P_AREA_SIZE1	MIN_P_AREA_SIZE1
#define	P_MIN_P_AREA_SIZE2	MIN_P_AREA_SIZE1
#define	P_MIN_P_AREA_SIZE3	MIN_P_AREA_SIZE2
#define	P_MIN_P_AREA_SIZE4	MIN_P_AREA_SIZE3
#define	P_MIN_P_AREA_SIZE5	MIN_P_AREA_SIZE4
#define	P_MIN_P_AREA_SIZE6	MIN_P_AREA_SIZE5
#define	P_MIN_P_AREA_SIZE7	MIN_P_AREA_SIZE6
#define	P_MIN_P_AREA_SIZE8	MIN_P_AREA_SIZE7
#define	P_MIN_P_AREA_SIZE9	MIN_P_AREA_SIZE8
#define	P_MIN_P_AREA_SIZE10	MIN_P_AREA_SIZE9
/* [ Check Table for Data Area(D_TBL) ]
				Card Capacity,	Sectors per Cluster, Boundary Unit
	-   8MB		D_SIZE1,		D_CLUSTER1,		D_BOUNDARY1
 	-  64MB		D_SIZE2,		D_CLUSTER2,		D_BOUNDARY2
	- 256MB		D_SIZE3,		D_CLUSTER3,		D_BOUNDARY3
	-1024MB		D_SIZE4,		D_CLUSTER4,		D_BOUNDARY4
	-2048MB		D_SIZE5,		D_CLUSTER5,		D_BOUNDARY5 */
#define	D_SIZE1			TARGET_AREA_SIZE5
#define	D_SIZE2			TARGET_AREA_SIZE8
#define	D_SIZE3			TARGET_AREA_SIZE10
#define	D_SIZE4			TARGET_AREA_SIZE14
#define	D_SIZE5			TARGET_AREA_SIZE16
#define	D_CLUSTER1		SECTOR_PER_CLUSTER4
#define	D_CLUSTER2		SECTOR_PER_CLUSTER5
#define	D_CLUSTER3		SECTOR_PER_CLUSTER5
#define	D_CLUSTER4		SECTOR_PER_CLUSTER5
#define	D_CLUSTER5		SECTOR_PER_CLUSTER6
#define	D_BOUNDARY1		BOUNDARY_UINT4
#define	D_BOUNDARY2		BOUNDARY_UINT5
#define	D_BOUNDARY3		BOUNDARY_UINT6
#define	D_BOUNDARY4		BOUNDARY_UINT7
#define	D_BOUNDARY5		BOUNDARY_UINT7
/* [ Check Table for CHS Recommendation(C_TBL) ]
				Card Capacity,	number of Heads,	Sector per Track
	-   2MB		C_SIZE1,		C_HEADS1,		C_TRACK1
 	-  16MB		C_SIZE2,		C_HEADS2,		C_TRACK2
	-  32MB		C_SIZE3,		C_HEADS3,		C_TRACK3
	- 128MB		C_SIZE4,		C_HEADS4,		C_TRACK4
	- 256MB		C_SIZE5,		C_HEADS5,		C_TRACK5
	- 504MB		C_SIZE6,		C_HEADS6,		C_TRACK6
	-1008MB		C_SIZE7,		C_HEADS7,		C_TRACK7
	-2016MB		C_SIZE8,		C_HEADS8,		C_TRACK8
	-2048MB		C_SIZE9,		C_HEADS9,		C_TRACK9 */
#define	C_SIZE1			TARGET_AREA_SIZE3
#define	C_SIZE2			TARGET_AREA_SIZE6
#define	C_SIZE3			TARGET_AREA_SIZE7
#define	C_SIZE4			TARGET_AREA_SIZE9
#define	C_SIZE5			TARGET_AREA_SIZE10
#define	C_SIZE6			TARGET_AREA_SIZE11
#define	C_SIZE7			TARGET_AREA_SIZE13
#define	C_SIZE8			TARGET_AREA_SIZE15
#define	C_SIZE9			TARGET_AREA_SIZE16
#define	C_HEADS1		NUMBER_OF_HEADS1
#define	C_HEADS2		NUMBER_OF_HEADS1
#define	C_HEADS3		NUMBER_OF_HEADS2
#define	C_HEADS4		NUMBER_OF_HEADS3
#define	C_HEADS5		NUMBER_OF_HEADS4
#define	C_HEADS6		NUMBER_OF_HEADS4
#define	C_HEADS7		NUMBER_OF_HEADS5
#define	C_HEADS8		NUMBER_OF_HEADS6
#define	C_HEADS9		NUMBER_OF_HEADS7
#define	C_TRACK1		SECTOR_PER_TRACK1
#define	C_TRACK2		SECTOR_PER_TRACK2
#define	C_TRACK3		SECTOR_PER_TRACK2
#define	C_TRACK4		SECTOR_PER_TRACK2
#define	C_TRACK5		SECTOR_PER_TRACK2
#define	C_TRACK6		SECTOR_PER_TRACK3
#define	C_TRACK7		SECTOR_PER_TRACK3
#define	C_TRACK8		SECTOR_PER_TRACK3
#define	C_TRACK9		SECTOR_PER_TRACK3
/****	�G���[�R�[�h				****/	
#define FS_E_SUCCESS				0				/* ����								*/
#define	FS_E_CHECK_MASK				0xFF00			/* �G���[�x�[�X�}�X�N�p�f�[�^		*/
#define	FS_E_BASE					0xA000			/* FS �G���[�x�[�X�R�[�h			*/
#define FS_E_DRIVE_NOT_AVAILABLE	FS_E_BASE+0x01	/* ���F���p�\�ȃh���C�u���Ȃ�		*/
#define FS_E_DEVICE_ALREADY_MOUNTED	FS_E_BASE+0x02	/* ���Ƀ}�E���g��Ԃł���@			*/
#define FS_E_DEVICE_NOT_MOUNTED		FS_E_BASE+0x03	/* �}�E���g����Ă��Ȃ�				*/
#define FS_E_TOO_MANY_OPEN_FILES	FS_E_BASE+0x04	/* �t�@�C�����I�[�v��������			*/
#define FS_E_DEVICE_NON				FS_E_BASE+0x05	/* ���F�f�o�C�X��������Ȃ�		*/
#define FS_E_FILE_NOT_TYPE			FS_E_BASE+0x06	/* �t�@�C���^�C�v���قȂ�/�s�K��	*/
#define FS_E_FILE_NOT_FOUND			FS_E_BASE+0x07	/* �t�@�C����������Ȃ�			*/
#define FS_E_FILE_NOT_OPENED		FS_E_BASE+0x08	/* �t�@�C�����I�[�v�����Ă��Ȃ�		*/
#define FS_E_FILE_OPENED			FS_E_BASE+0x09	/* �t�@�C�����I�[�v�����Ă���		*/
#define FS_E_BAD_FILE_TYPE			FS_E_BASE+0x0a	/* ���FOpen�t�@�C���Ǝ�ނ��Ⴄ		*/
#define FS_E_BAD_OPEN_FLAG			FS_E_BASE+0x0b	/* Open�̕��@�����s��W���Ă���		*/
#define	FS_E_BAD_VARIABLES			FS_E_BASE+0x0c	/* �ϐ�/�����̒l����������			*/
#define FS_E_NOT_ENOUGH_MEMORY		FS_E_BASE+0x0d	/* �������s��						*/
#define FS_E_CANNOT_ACCESS_DEVICE	FS_E_BASE+0x0e	/* �f�o�C�X�Ƀ��[�A�N�Z�X�s��		*/
#define FS_E_DIR_NOT_FOUND			FS_E_BASE+0x0f	/* �f�B���N�g����������Ȃ�		*/
#define FS_E_CHILD_FILE_FOUND		FS_E_BASE+0x10	/* �f�B���N�g���̒��g����łȂ�		*/
#define FS_E_SAME_FILENAME			FS_E_BASE+0x11	/* ����t�@�C���������݂���			*/
#define FS_E_DEVICE_CAPACITY_FULL	FS_E_BASE+0x12	/* �f�o�C�X�̗e�ʂ�Full Busy		*/
#define FS_E_OVER_MAX_DEPTH			FS_E_BASE+0x13	/* �f�B���N�g���[�����ő�lOver		*/
#define FS_E_DETECTED_EOF			FS_E_BASE+0x14	/* EOF�̌��o						*/
#define FS_E_ALREADY_EOF			FS_E_BASE+0x15	/* ����EOF�����o					*/
#define FS_E_DEVICE_TYPE			FS_E_BASE+0x16	/* �f�o�C�X�̈悪�Ԉ���Ă���		*/
#define FS_E_PATHNAME_LEN			FS_E_BASE+0x17	/* �p�X���T�C�Y�I�[�o�[				*/
#define FS_E_SAME_FILE_OPEN			FS_E_BASE+0x18	/* �r���I�[�v���G���[				*/
#define FS_E_END_OF_FILE			FS_E_BASE+0x19	/* ���F�t�@�C���̏I�[�����o			*/
#define FS_E_DISC_NOT_FORMAT		FS_E_BASE+0x1a	/* �t�H�[�}�b�g����Ă��Ȃ�			*/
#define FS_E_DISC_RW_FATAL			FS_E_BASE+0x1b	/* ���F�^�ĕs���f�B�A				*/
#define FS_E_DISC_VIOLATION_ISO		FS_E_BASE+0x1c	/* ISD�K�i�ᔽ						*/
#define FS_E_DISC_VIOLATION_SD		FS_E_BASE+0x1d	/* SD�K�i�ᔽ						*/
#define FS_E_PARAMETER_CANNOT_FIX	FS_E_BASE+0x1e	/* Format���̃p�����[�^�v�Z���s		*/
#define FS_E_FAT_WRITE_ERROR		FS_E_BASE+0x1f	/* ���FFormat����FAT�����݌v�Z�~�X	*/
#define FS_E_BAD_NORMAL_AREA		FS_E_BASE+0x20	/* ���F�ʏ�̈悪MCAP�p�łȂ�		*/
#define	FS_E_ASYNC					FS_E_BASE+0x21	/* �񓯊�I/O �v���G���[				*/
#define FS_E_ACROSS_EOF				FS_E_BASE+0x22	/* ���F�A�N�Z�X�̈悪EOF���܂�		*/
#define FS_E_OVEROFFS				FS_E_BASE+0x23	/* �A�N�Z�X�̈悪�T�C�Y�ȏ�(EOF)	*/
#define FS_E_FDCTBL					FS_E_BASE+0x24	/* ���FFDC Table�ُ�				*/
#define FS_E_FATTBL					FS_E_BASE+0x25	/* ���FFAT Table�ُ�				*/
#define FS_E_FATTBLFULL				FS_E_BASE+0x26	/* ���FFAT Table Full				*/
#define FS_E_ATTRIBUTE				FS_E_BASE+0x27	/* �t�@�C�������G���[			
												     �t�@�C���ƃf�B���N�g���̎�ʃG���[	*/
#define FS_E_BAD_OFFSET				FS_E_BASE+0x28	/* �I�t�Z�b�g�l���ُ�				*/
#define FS_E_BROKEN_FAT				FS_E_BASE+0x29	/* FAT�����Ă���					*/
#define FS_E_CANNOT_FIND_ENTRY		FS_E_BASE+0x2a	/* �G���g���̊l�����s				*/
#define FS_E_NOT_MATCH				FS_E_BASE+0x2b	/* ���O����v���Ȃ�					*/
#define	FS_E_BAD_FILENAME			FS_E_BASE+0x2c	/* �s���ȃt�@�C����					*/
#define	FS_E_FS_ERROR				FS_E_BASE+0x2d	/* FS�̓����I�ȃG���[				*/
#define	FS_E_DIR_NOT_OPENED			FS_E_BASE+0x2e	/* directory�̓I�[�v�����Ă��Ȃ�	*/
#define	FS_E_DIR_OPENED				FS_E_BASE+0x2f	/* directory�̓I�[�v�����Ă���		*/
#define	FS_E_END_OF_DIR				FS_E_BASE+0x30	/* directory�̏I�[�ł���			*/
#define	FS_E_CANNOT_SEEK_DIR		FS_E_BASE+0x31	/* ���Fdirectory�̃V�[�N�Ɏ��s		*/
#define FS_E_BROKEN_ENTRY			FS_E_BASE+0x32	/* �G���g�������Ă���				*/
#define FS_E_CANNOT_RESIZE_FILE		FS_E_BASE+0x33	/* �t�@�C���T�C�Y�̕ύX�s�\		*/
#define	FS_E_BAD_PARTITION_SIZE		FS_E_BASE+0x34	/* �p�[�e�B�V���������s�K��			*/
#define FS_E_INVALID_ID_DEV_INFO	FS_E_BASE+0x35  /* ���FIdentifyDrive�p�����[�^�ُ�	*/
#define FS_E_SEM_ERROR				FS_E_BASE+0x36  /* �Z�}�t�H�G���[					*/
#define FS_E_NO_CARD				FS_E_BASE+0x37  /* ���f�B�A�����݂��Ȃ�				*/
#define	FS_E_TOO_MANY_E_OPEN_FILES	FS_E_BASE+0x38  /* �ҏW:�t�@�C���I�[�v�����̊m�ەs��*/
#define FS_E_BOUNDARY				FS_E_BASE+0x39  /* �N���X�^�T�C�Y�̔{�����łȂ�		*/
#define FS_E_NO_MERGE				FS_E_BASE+0x40  /* �������ꂽ����t�@�C���łȂ�		*/
#define FS_E_INVALID_DATE			FS_E_BASE+0x41  /* ���t��񂪕s��					*/
#define FS_E_CONFIG_ERROR			FS_E_BASE+0x42  /* FS_config.h�ݒ�l�G���[			*/
#define FS_E_DRIVER_IO_ERROR		FS_E_BASE+0x43  /* �h���C�oI/O�G���[				*/
#define FS_E_DISC_V_ISO_FAT_CACHE	FS_E_BASE+0x44	/* ISD�K�i�ᔽ + FAT CACHE MODE		*/
#define FS_E_DISC_V_SD_FAT_CACHE	FS_E_BASE+0x45	/* SD�K�i�ᔽ  + FAT CACHE MODE		*/
#define FS_E_DISC_FAT_CACHE			FS_E_BASE+0x46	/* FAT CACHE MODE					*/
/* <Dolphin> Add for Dolphin */
#ifdef DOLPHIN_SDFS
#define FS_E_SOFTERR				FS_E_BASE+0x47 	/* SOFT Error 			*/ 
#endif
/* <Dolphin> Add End */
/* �d���f�֘A�G���[�R�[�h		*/
#define	FS_E_REQ_CHK_RECOVERY		FS_E_BASE+0x50	/* ���J�o����񂠂�								*/
#define	FS_E_REQ_NOR_RECOVERY		FS_E_BASE+0x51	/* �ʏ탊�J�o����񂠂�ASD�J�[�h��v			*/
#define	FS_E_REQ_EXT_RECOVERY		FS_E_BASE+0x52	/* �F�؃��J�o����񂠂�ASD�J�[�h��v			*/
#define	FS_E_REQ_BOTH_RECOVERY		FS_E_BASE+0x53	/* �ʏ�E�F�؃��J�o����񂠂�ASD�J�[�h��v		*/
#define	FS_E_REQ_NOR_CHANGE_SD		FS_E_BASE+0x54	/* �ʏ탊�J�o����񂠂�ASD�J�[�h�s��v			*/
#define	FS_E_REQ_EXT_CHANGE_SD		FS_E_BASE+0x55	/* �F�؃��J�o����񂠂�ASD�J�[�h�s��v			*/
#define	FS_E_REQ_BOTH_CHANGE_SD		FS_E_BASE+0x56	/* �ʏ�E�F�؃��J�o����񂠂�ASD�J�[�h�s��v	*/
#define	FS_E_REQ_NOR_INSERT_SD		FS_E_BASE+0x57	/* �ʏ탊�J�o����񂠂�ASD�J�[�h�Ȃ�			*/
#define	FS_E_REQ_EXT_INSERT_SD		FS_E_BASE+0x58	/* �F�؃��J�o����񂠂�ASD�J�[�h�Ȃ�			*/
#define	FS_E_REQ_BOTH_INSERT_SD		FS_E_BASE+0x59	/* �ʏ�E�F�؃��J�o����񂠂�ASD�J�[�h�Ȃ�		*/
/* VFAT�֘A�G���[�R�[�h			*/
#define	FS_E_NO_OPEN				FS_E_BASE+0x70	/* �I�[�v���Ȃ�						*/
#define	FS_E_SAME_OPEN				FS_E_BASE+0x71	/* �������g���I�[�v�����			*/
#define	FS_E_PARENT_OPEN			FS_E_BASE+0x72	/* ���e�f�B���N�g�����I�[�v�����	*/
#define	FS_E_OLD_OPEN				FS_E_BASE+0x73	/* �c��f�B���N�g�����I�[�v�����	*/
#define	FS_E_NEW_OPEN				FS_E_BASE+0x74	/* �q���f�B���N�g�����I�[�v�����	*/
/* FLASH�֘A�G���[�R�[�h */
#define	FS_E_F_BASE					0xA100				/* �t���b�V�� �G���[�x�[�X�R�[�h*/
#define	FS_E_FLASH_INIT_FALSE		FS_E_F_BASE+0x01	/* �t���b�V�����������s			*/
#define	FS_E_FLASH_NO_DEVICE		FS_E_F_BASE+0x02	/* ���f�B�A��F���ł��Ȃ�		*/
#define	FS_E_FLASH_OVER_POOL_SIZE	FS_E_F_BASE+0x03	/* �t���b�V��POOL�T�C�Y�I�[�o�[	*/
#define	FS_E_FLASH_NOT_VBF_FORMAT	FS_E_F_BASE+0x04	/* VBF���t�H�[�}�b�g			*/
#define	FS_E_FLASH_VBF_FORMAT_FALSE	FS_E_F_BASE+0x05	/* VBF�t�H�[�}�b�g���s���s		*/
#define	FS_E_FLASH_VBF_MOUNT_FALSE	FS_E_F_BASE+0x06	/* VBF�}�E���g���s				*/
#define	FS_E_FLASH_IO_ERROR			FS_E_F_BASE+0x07	/* �ǂݍ���/�������݂Ɏ��s		*/
#define	FS_E_FLASH_GARBAGE_FALSE	FS_E_F_BASE+0x08	/* �K�[�x�W�R���N�g���s���s		*/


/**** I/O�o�b�t�@�T�C�Y ****/
/* read/write���̃t�@�C��I/O�Ɏg�p����o�b�t�@�̃o�C�g�T�C�Y��ݒ�						*/
/*  ( FS_LOGICAL_CLUSTER_SIZE ) = 2KB * n      ( n = 1,2,3,...8)						*/
/* ��16KB�w��𐄏��A���̐ݒ�l�ł̓���͖��m�F											*/
#define FS_LOGICAL_CLUSTER_SIZE		16384							/* �f�t�H���g�l		*/


/**** �R�D�I�[�v���t�@�C���� ****/
/* �ő哯���I�[�v���ł���t�@�C������ݒ�												*/
/* �@1 =< ( FS_MAX_OF_NOR_OPEN ) =< 5													*/
/* �@1 =< ( FS_MAX_OF_EXT_OPEN ) =< 5													*/
/* �@FS_MAX_OF_OPEN  = MAX(FS_MAX_OF_NOR_OPEN,FS_MAX_OF_EXT_OPEN)						*/
/*																						*/
#define	FS_MAX_OF_OPEN	((FS_MAX_OF_NOR_OPEN>FS_MAX_OF_EXT_OPEN)? FS_MAX_OF_NOR_OPEN:FS_MAX_OF_EXT_OPEN)


/**** �S�D�I�[�v���f�B���N�g���� ****/
/* �ő哯���I�[�v���ł���f�B���N�g������ݒ�											*/
/* �@�ʏ�̈�F1 =< ( FS_MAX_NOR_OPEN_DIR ) =< 3										*/
/* �@�F�ؗ̈�F1 =< ( FS_MAX_EXT_OPEN_DIR ) =< 3										*/
/*	 FS_MAX_OPEN_DIR  = MAX(FS_MAX_NOR_OPEN_DIR,FS_MAX_EXT_OPEN_DIR)					*/
/*																						*/
#define FS_MAX_OF_OPEN_DIR	((FS_MAX_OF_NOR_OPEN_DIR>FS_MAX_OF_EXT_OPEN_DIR)? FS_MAX_OF_NOR_OPEN_DIR:FS_MAX_OF_EXT_OPEN_DIR)												/* �f�t�H���g�l	*/


/**** �T�D�f�B���N�g���̍ő�K�w���@****/
/* �f�B���N�g���̍ő�K�w����ݒ�														*/
/*�@�ʏ�̈�F1 =< ( FS_MAX_NOR_DEPTH ) =< 8											*/
/*�@�F�ؗ̈�F1 =< ( FS_MAX_EXT_DEPTH ) =< 8											*/
/*	FS_MAX_DEPTH  = MAX(FS_MAX_NOR_DEPTH,FS_MAX_EXT_DEPTH)								*/
/* �����[�g�͊K�w�P																		*/
#define	FS_MAX_DEPTH ((FS_MAX_NOR_DEPTH>FS_MAX_EXT_DEPTH)? FS_MAX_NOR_DEPTH:FS_MAX_EXT_DEPTH)
																		/* �f�t�H���g�l	*/

/**** DOS���t���p�X�T�C�Y�p�}�N�� ****/
/* DOS���t���p�X�T�C�Y(13�~�K�w(�ő�K�w��))��Ԃ� �A���A259�𒴂���ꍇ��259�Œ� */
#define	FS_DOS_PATH_LEN_MIN()	(((FS_MAX_DEPTH*13)>259)? 259:(FS_MAX_DEPTH*13))



/*
 *	�����e�i���X�R�}���h�p��`
 */

/******** �T�|�[�g���샂�[�h ********/
#define FS_FC_CHECK			0x0001					/* �t�H�[�}�b�g�̃`�F�b�N�̂ݍs��	*/
#define FS_FC_ENT_RESTORE	0x0002					/* FAT,�f�B���N�g���G���g���ُ����
																		�C���̂ݍs��	*/
#define FS_FC_ISO_RESTORE	0x0004					/* ISO�K�i�ᔽ���������ׂďC������	*/
#define FS_FC_SD_RESTORE	0x0008					/* SD�K�i�ᔽ���������ׂďC������	*/

/******** �C���۔���r�b�g ********/
#define FS_FC_ENT_BIT		0x0001					/* �G���g���ُ�C��BIT				*/
#define FS_FC_ISO_BIT		0x0002					/* ISO�K�i�ᔽ�C��BIT				*/
#define FS_FC_SD_BIT		0x0004					/* SD�K�i�ᔽ�C��BIT				*/

/******** �t�H�[�}�b�g�ُ�ʒm�p�G���[�R�[�h ********/
/**** �V�X�e���̈�G���[���x��1(�d�x�̃G���[�F�t�H�[�}�b�g����) ****/
/* �C���s�\�ȏd�x�̃G���[(format�𐄏�) */
#define FS_FC_MBR_FATAL_E	0x00000001				/* MBR�����Ă���					*/
#define FS_FC_FDC_FATAL_E	0x00000002				/* FDC�����Ă���					*/

/**** �V�X�e���̈�G���[���x��2(���x�̃G���[�F�C�����Ȃ����g�p�\) ****/
/** FS_FC_SD_RESTORE,FS_FC_ISO_RESATORE�ŏC�����Ȃ��y�x�̃G���[ **/
#define FS_FC_MBR_ISO1_E	0x00000010				/* MBR�����Ă���					*/
#define FS_FC_FDC_ISO1_E	0x00000020				/* FDC�����Ă���					*/
/** FS_FC_SD_RESTORE�ŏC�����Ȃ��y�x�̃G���[ **/
#define FS_FC_MBR_SD1_E		0x00000040				/* MBR��SD�K�i�Ɉᔽ���Ă���		*/
#define FS_FC_FDC_SD1_E		0x00000080				/* FDC��SD�K�i�Ɉᔽ���Ă���		*/

/**** �V�X�e���̈�G���[���x��3(�y�x�̃G���[�F�C���\) ****/
/** FS_FC_SD_RESTORE,FS_FC_ISO_RESATORE�ŏC������y�x�̃G���[ **/
#define FS_FC_MBR_ISO2_E	0x00000100				/* MBR�����Ă���					*/
#define FS_FC_FDC_ISO2_E	0x00000200				/* FDC�����Ă���					*/
/** FS_FC_SD_RESTORE�ŏC������y�x�̃G���[ **/
#define FS_FC_MBR_SD2_E		0x00000400				/* MBR��SD�K�i�Ɉᔽ���Ă���		*/
#define FS_FC_FDC_SD2_E		0x00000800				/* FDC��SD�K�i�Ɉᔽ���Ă���		*/

/**** ���̑��̃G���[ ****/
#define FS_FC_FAT_E			0x00001000		/* FAT�e�[�u�������Ă���(�C���\)		*/
#define FS_FC_ENT_E			0x00002000		/* �f�B���N�g���G���g�����Ă���(�C���\)	*/
#define FS_FC_SD_PARAM_E	0x00004000		/* �t�H�[�}�b�g�p�����[�^��SD�K�i�Ɉᔽ���Ă���
											(�C�����Ȃ����V�X�e���ɂ���Ă͎g�p�\)	*/

/******** FormatCheck�p�萔 ********/
#define	FS_FC_MAX_LEVEL		128				/* �ő�T���K�w��(root=0)					*/

/****	�I�[�v������				****/
#define		FS_O_EXT_MODE		0x1000		/* �F�ؗ̈�Open���[�h(�d���f��Open�O�ɖ߂�)	*/

/**** Multi Drive�֘A��`�@****/
#define	FS_SD_DRIVE_MAX			2						/* �T�|�[�gSD Drive�ő吔	*/
#define	FS_FLASH_DRIVE_MAX		1						/* �T�|�[�gFlash Drive�ő吔*/
#define	FS_MAX_OF_DRIVE	((FS_SD_DRIVE_MAX>FS_FLASH_DRIVE_MAX)? FS_SD_DRIVE_MAX:FS_FLASH_DRIVE_MAX)
														/* �T�|�[�g�h���C�u�ő吔	*/
#define	FS_MAX_DRIVE_NO		FS_MAX_OF_DRIVE	- 1			/* �ő�Drive No.			*/
#define	FS_NONE_DRIVE		0x0000						/* None Drive				*/
#define	FS_NONE_PATH		"NONE_PATH"					/* None Path				*/
#define	FS_DRIVE_MASK		0x0f00						/* �T�|�[�g�h���C�u�}�X�N�l	*/
/**** Drive��������� ****/
#define	FS_NOTCOMPLETE_INIT			1					/* FS_init���������		*/					
#define	FS_COMPLETE_INIT			2					/* FS_init�������			*/
#define	FS_NOTCOMPLETE_CARDINIT		1					/* FS_cardinit���������	*/
#define	FS_COMPLETE_CARDINIT		2					/* FS_cardinit�������		*/
#define	FS_NOTCOMPLETE_S2LINIT		1					/* FS_s2linit���������		*/
#define	FS_COMPLETE_S2LINIT			2					/* FS_s2linit�������		*/

/**** VFAT�֘Adefine ****/
#define	DOUBLE_TO_DOUBLE			1					/* Path���A�����[�h 2byte code + 2byte code */
#define	DOUBLE_TO_CHAR				2					/*                  2byte code + 1byte code */
#define	CHAR_TO_DOUBLE				3					/*                  1byte code + 2byte code */
#define	CHAR_TO_CHAR				4					/*					1byte code + 1byte code */
#define	FS_MAX_LONGNAME_LEN			255					/* LFN�ő�t�@�C������(byte)				*/

/**** LFN���� Unicode��SJIS�ϊ��e�[�u���g�p��ݒ� ****/
/*
 *  Unicode��SJIS�ϊ��e�[�u�����g�p����ꍇ�AUSE_UNI_TO_SJIS_TBL���`����B
 *  Unicode��SJIS�ϊ��e�[�u�����g�p���Ȃ��ꍇ�AUSE_UNI_TO_SJIS_TBL���`���Ȃ��B
 */
/*
#define	USE_UNI_TO_SJIS_TBL
*/

/**** �h���C�u�I���֐��֘Adefine ****/
#define		MASK_PORT_NO		0x00FF					/* �|�[�g�ԍ����o�}�X�N 	*/
#define		FS_SHIFT8			8						/* 8bit�V�t�g				*/

/**** FLASH�֘Adefine ****/
#define		D_MAX_UINT						0xFFFF
#define		MAX_UINT_ACCESS					( D_MAX_UINT - VBF_BLOCK_SIZE + 1 )

#define		FS_FLASH_BIT					0x2000
#define		FS_NOT_MEDIA_BIT				0x0020

#endif
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
