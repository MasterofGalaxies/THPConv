/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	fs_type.h
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
$ 2002. 6. 4	:V.3.02 MultiDrive�EFlashROM�Ή���2��							MSE M.O
$ 2002. 7. 5	:V.3.03	MultiDrive�EFlashROM�Ή���3��							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin�Ή���						
========================================================================================*/

#ifndef __FS_TYPE_H__
#define __FS_TYPE_H__

/****
	�f�[�^�\���̒�`
						****/

#ifdef TYPE_32BIT	/* ���ڍs  */
#define __packed

/* Partition Table��� */
typedef __packed struct _fs_partition_table_t {
	UCHAR	bootIndicator;							/* �u�[�g�C���W�P�[�^				*/
	UCHAR	startHead;								/* �J�n�w�b�h						*/
	UINT16	startSectorCylinder;					/* �J�n�Z�N�^	:bit15-10			*/
													/* �J�n�V�����_ :bit 9-0			*/
	UCHAR	systemID;								/* SystemID							*/
	UCHAR	endHead;								/* �I���w�b�h						*/
	UINT16	endSectorCylinder;						/* �I���Z�N�^	:bit15-10			*/
													/* �I���V�����_	:bit 9-0			*/
	UINT32	relativeSector;							/* ���΃Z�N�^��						*/
	UINT32	totalSector;							/* ���Z�N�^��						*/
} FS_PT;


/* Master Boot Record��� */
typedef __packed struct _fs_mbr_pt_t {
	UCHAR	masterBootRecode[446];					/* �}�X�^�[�u�[�g���R�[�h			*/
	FS_PT	partitionTable1;						/* �p�[�e�B�V�����e�[�u���P			*/
	FS_PT	partitionTable2;						/* �p�[�e�B�V�����e�[�u���Q			*/
	FS_PT	partitionTable3;						/* �p�[�e�B�V�����e�[�u���R			*/
	FS_PT	partitionTable4;						/* �p�[�e�B�V�����e�[�u���S			*/
	UINT16	signifyWord;							/* �V�O�j�`�����[�h					*/
} FS_MBR_PT;

#else

/* Partition Table��� */
typedef struct _fs_partition_table_t {
	UCHAR	bootIndicator;							/* �u�[�g�C���W�P�[�^				*/
	UCHAR	startHead;								/* �J�n�w�b�h						*/
	UINT16	startSectorCylinder;					/* �J�n�Z�N�^	:bit15-10			*/
													/* �J�n�V�����_ :bit 9-0			*/
	UCHAR	systemID;								/* SystemID							*/
	UCHAR	endHead;								/* �I���w�b�h						*/
	UINT16	endSectorCylinder;						/* �I���Z�N�^	:bit15-10			*/
													/* �I���V�����_	:bit 9-0			*/
	UINT32	relativeSector;							/* ���΃Z�N�^��						*/
	UINT32	totalSector;							/* ���Z�N�^��						*/
} FS_PT;


/* Master Boot Record��� */
typedef struct _fs_mbr_pt_t {
	UCHAR	masterBootRecode[446];					/* �}�X�^�[�u�[�g���R�[�h			*/
	FS_PT	partitionTable1;						/* �p�[�e�B�V�����e�[�u���P			*/
	FS_PT	partitionTable2;						/* �p�[�e�B�V�����e�[�u���Q			*/
	FS_PT	partitionTable3;						/* �p�[�e�B�V�����e�[�u���R			*/
	FS_PT	partitionTable4;						/* �p�[�e�B�V�����e�[�u���S			*/
	UINT16	signifyWord;							/* �V�O�j�`�����[�h					*/
} FS_MBR_PT;
#endif


/* Master Boot Record�f�[�^�m�F��� */
typedef struct _check_cluster_boundary_t {
	UINT32	targetAreaSize;							/* Card Capacity/Protected Area		*/
	UINT16	sectorsPerCluster;						/* Sectors per Clusterin FDC		*/
	UINT16	boundaryUnit;							/*Boundary Unit at User Data Offset	*/
} CHK_CLUSTER_BOUNDARY_T;


/* CHS Recommendation�f�[�^�m�F��� */
typedef struct _check_chs_recommendation_t {
	UINT32	targetAreaSize;							/* Card Capacity					*/
	UINT16	numberOfHeads;							/* Number of Heads					*/
	UINT16	sectorsPerTrack;						/* Sectors per track				*/
} CHK_CHS_RECOMMENDATION_T;


/* Minimum Protected Area Aize�f�[�^�m�F��� */
typedef struct _check_min_p_area_size_t {
	UINT32	targetAreaSize;							/* Card Capacity					*/
	UINT32	minProtectedAreaSize;					/* Min.Protected Area Size			*/
} CHK_MIN_P_AREA_SIZE_T;


/* FDC��� */
typedef struct _fs_fdc_t {
	UINT16	bytesPerSector;							/* �o�C�g / �Z�N�^					*/
	UINT16	sectorsPerCluster;						/* �Z�N�^ / �N���X�^				*/
	UINT16	sectorsPerTrack;						/* �Z�N�^ / �g���b�N				*/
	UINT16	numberOfSides;							/* �ʐ�								*/
	UINT16	reservedSectors;						/* �\��Z�N�^�� 					*/
	UINT16	numberOfFATs;							/* FAT�̐�    						*/
	UINT16	rootEntries;							/* ���[�g�E�f�B���N�g���̃G���g����	*/
	UINT16	totalSectors;							/* �f�B�X�N�̑��Z�N�^��				*/
	UINT16	mediaDescriptor;						/* ���f�B�A�E�f�B�X�N���v�^			*/
	UINT16	sectorsPerFAT;							/* �Z�N�^ / FAT						*/
	UINT32	hidedSectors;							/* �B���ꂽ�Z�N�^��					*/
	UINT32	extentTotalSectors;						/* ��e�ʃf�B�X�N�̑��Z�N�^��		*/
	UINT32	volumeSerialNumber;						/* �{�����[���E�V���A���ԍ�			*/
	UINT16	kindOfFAT;								/* FAT�̎��(FAT16/FAT12)			*/
	UCHAR	volumeLabel[12];						/* �{�����[���E���x�� 				*/
	UCHAR	sysAtr[9];								/* �쐬�V�X�e�����ʎq 				*/
	UCHAR	extBootRecordSignature;					/* �g���u�[�g���R�[�h�V�O�l�`��		*/
} FS_FDC;


/* �Z�N�^�ԍ���� */
typedef struct _fs_sec_no_t {						/* �����Z�N�^�l						*/
	UINT32	boot;									/* �u�[�g�E�Z�N�^�ԍ� 				*/
	UINT32	fat1;									/* FAT1�J�n�Z�N�^�ԍ�				*/
	UINT32	fat2;									/* FAT2�J�n�Z�N�^�ԍ� 				*/
	UINT32 	dir;									/* ROOTDIR�J�n�Z�N�^�ԍ�			*/
	UINT32	data;									/* DATA�J�n�Z�N�^�ԍ�				*/
	UINT32	eov;									/* �ŏI�Z�N�^�ԍ�+1					*/
} FS_SECNO;


/* �J�����g�ʒu��� */
typedef struct _fs_current_t {						/* �J�����g�ʒu						*/
	UINT32	dirEntSecNo;							/* DirectoryEntry�̃Z�N�^�ʒu		*/
	UINT16	dirEntOffset;							/* DirectoryEntry�̃Z�N�^���ʒu(B)	*/
	UINT16	pFATEnt;								/* �e�f�B���N�g���J�n�N���X�^�ԍ�	*/
	UINT16	startCluster;							/* �J�����g�̈�J�n�N���X�^�ԍ�		*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	pathName[ FS_MAX_PATHNAME_LEN + 1 ];	/* �t���p�X�l�[��					*/
#else
	UCHAR	pathName[ FS_DOS_PATH_LEN_MIN() + 1 ];	/* �t���p�X�l�[��					*/
	UCHAR	lfnPathName[ FS_MAX_PATHNAME_LEN + 1 ]; /* LFN�t���p�X(260:SJIS�p����������)*/
#endif
} FS_CURRENT;


/* FAT�L���b�V�� */
typedef struct fs_cache_t {
	union{
		UINT16	*pFAT16[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* FAT16�p�f�[�^			*/
		UCHAR	*pFAT12[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* FAT12�p�f�[�^			*/
	} fs_cacheD;
	UINT16	kindOfArea[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* �̈�̎��				*/
	UINT16	cacheOffset[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* CacheFAT���Z�N�^�ʒu0�`	*/
	UINT16	cacheSize[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* 1Cache�̃T�C�Y(�Z�N�^��) */
	UINT16	newest[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];		/* �ŐV�X�V���i�[�p			*/
	UINT16	modify[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];		/* �X�V����					*/
} FS_CACHE;


/* FAT��� */
typedef struct fs_fat_t {
	UINT16	fatAtr;						/* FAT�e�[�u�����ʎq(FAT1/FAT2)					*/
	UINT16	fatOffset;					/* FAToffset (�Z�N�^)(�_��)						*/
	UINT16	fatAreaTCount;				/* FAT�G���g����
												(FAT1�S�̂�MAX�l+2,�ő�N���X�^�ԍ�+1)	*/
	UINT16	fatSerch;					/* FAT�󂫏��J�n�|�C���g(�P�ʐ�)				*/
	UINT16	modifyFlag;					/* FAT���X�V�t���O(0:�X�V�Ȃ�)				*/
	UCHAR	modifySectorBit[32];		/* FAT���X�V�Z�N�^�Ǘ��r�b�g
										   (�擪�o�C�g�̐擪�r�b�g=FAT�擪�Z�N�^�`
										   �ŏI�o�C�g�̍ŏI�r�b�g=FAT�ŏI�Z�N�^�ɑΉ�)	*/
	UINT16	modifyClusterCount;			/* FAT���X�V�N���X�^���J�E���^(�N���X�^��)	*/
	UINT16	maxModifyCluster;			/* �ő�FAT���X�V�N���X�^��					*/
	union{
		UINT16	*pFAT16;				/* FAT16�f�[�^�p		 						*/
		UCHAR	*pFAT12;				/* FAT12�f�[�^�p		 						*/
	} fs_pFATD;
	FS_CACHE	*cacheP;				/* �L���b�V���|�C���^							*/
	UINT16		fatCacheMode;			/* 1:FAT is cache, 2:FAT is On Memory			*/
} FS_FAT;


/* �f�o�C�X��� */
typedef struct _fs_drive_t {
	UINT16	fsDriveNo;							/* Drive�w��l							*/
	UINT16	driveNum;							/* �h���C�u�ԍ�							*/
	UINT16	kindOfArea;							/* 1:�ʏ�̈�A2:�F�ؗ̈�				*/
	UINT16	mountFlag;							/* �}�E���g���							*/
	UINT32	startFDCsec;						/* FDC�擪�Z�N�^�ԍ�(����)				*/
	FS_PT	mbrPartitionTable1;					/* MBR Partition Table1���				*/
	FS_FDC	fdc;								/* FDC���								*/
	FS_SECNO	sn;								/* �Z�N�^�ԍ����						*/
	FS_CURRENT	cr;								/* �J�����g�ʒu���						*/
	FS_FAT	fatInfo;							/* �ێ�FAT�f�[�^���					*/
	UINT16	openFileCnt;						/* �I�[�v�����̃t�@�C����				*/
	UINT16	acsSecPerCluster;					/* �A�N�Z�X�p�N���X�^�T�C�Y(�Z�N�^)		*/
	UINT16	kindOfHeadData;						/* �Z�N�^0���(MBR/FDC/ExtenedFDC)		*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
	UINT32	mediaSize;							/* �A�N�Z�X�\�T�C�Y(�Z�N�^) 			*/
	UINT16	mediaClass;							/* ���f�B�A�̎��(1:SD,2:MMC)			*/
	UINT16	mediaInfo;							/* �t�H�[�}�b�g�G���[���x��				*/
												/* 1:FATAL�G���[,2:SD�K�i�ᔽ,4;ISO�ᔽ	*/
} FS_DRIVE;


/* �t�@�C���V�X�e����� */
typedef struct fs_filesystem_t {
	UINT32	totalSecSize;						/* ���e��(�Z�N�^:�N���X�^�{��)			*/
	UINT32	spaceSecSize;						/* �󂫗e��(�Z�N�^:�N���X�^�{��)		*/
	UINT16	clusterBSize;						/* �N���X�^�T�C�Y (�o�C�g)				*/
	UINT16	sectorBSize;						/* �Z�N�^�T�C�Y  �i�o�C�g)				*/
} FS_FS;


/* �f�B���N�g���G���g����� */
typedef struct fs_dirent_t {
	UCHAR  	fName[11];							/* �t�@�C����(���O8����+�g���q3����)	*/
	UCHAR  	atr;								/* ����									*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR  	rev[10];							/* ���U�[�u								*/
#else
	UCHAR	rev[1];								/* ���U�[�u								*/
	UCHAR	ctime_ms;							/* �쐬����(10�~���b)					*/
	UINT16	ctime;								/* �쐬����								*/
	UINT16	cdate;								/* �쐬���t								*/
	UINT16	adate;								/* �ŏI�A�N�Z�X���t						*/
	UINT16	hiclust;							/* FAT�G���g�����(FAT32�̂�)			*/
#endif
	UINT16 	upTime;								/* �ύX����								*/
	UINT16 	upDate;								/* �ύX���t								*/
	UINT16 	fatEnt;								/* FAT�G���g��							*/
	UINT32 	fSize;								/* �t�@�C���E�T�C�Y						*/
} FS_DIRENT;


/* �t�@�C����� */
typedef struct fs_file_t {
	UINT16	id;									/* FS_FILE���ʔԍ�						*/
	UINT16	modifyFlag;							/* ���f�B�A���X�VFLAG(close��)		*/
	FS_DRIVE	*fsDrive;						/* �f�o�C�X���ւ̃|�C���^				*/
	FS_DIRENT	fsDirEntry;						/* �f�B���N�g�����ւ̃|�C���^ 		*/
	UINT32	offset;								/* �I�t�Z�b�g(�o�C�g��)�i�_��)			*/
	UINT16	openAtr;							/* �I�[�v������ 						*/
	UINT16	acsPt;								/* FAT �A�N�Z�X �|�C���^(�N���X�^)		*/
	UINT16	newCluster;							/* �V�K�Ɋl�������N���X�^(�N���X�^)		*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
	UINT32	dirEntSecNo;						/* �f�B���N�g���G���g���Z�N�^�ʒu		*/
	UINT16	dirEntOffset;						/* �f�B���N�g���G���g���Z�N�^���ʒu(B)	*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	pathName[FS_MAX_PATHNAME_LEN+1];	/* �t���p�X�l�[��						*/
#else
	UCHAR	pathName[FS_DOS_PATH_LEN_MIN()+1];	/* �t���p�X�l�[��						*/
	UCHAR	lfnPathName[FS_MAX_PATHNAME_LEN+1];	/* LFN�t���p�X(260)(SJIS�p����������)	*/
#endif
} FS_FILE;


/* Temp Buffer */
typedef union	fs_tmpbuffer_t {
	UCHAR		FS_CharBuf[FS_LOGICAL_CLUSTER_SIZE];
	FS_DIRENT	FS_DirBuf[FS_LOGICAL_CLUSTER_SIZE/FS_ROOTDIR_ITEM_SIZE];
} FS_TMPBUF;


/* �f�B���N�g����� */
typedef struct fs_dir_t {
	FS_DRIVE	*fsDrive;						/* �f�o�C�X���ւ̃|�C���^				*/
	UINT32	pos;								/* �f�B���N�g���J�n�Z�N�^�ԍ�			*/
	UINT32	offset;								/* �V�[�N�ʒu(���o�C�g��)				*/
	UINT32	current;							/* �V�[�N�ʒu(�N���X�^�J�n�Z�N�^�ԍ�)	*/
	UINT16	entNum;								/* �V�[�N�ʒu(�L���G���g����)			*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	dirName[ FS_MAX_PATHNAME_LEN + 1 ];	/* �f�B���N�g����(�t���p�X)				*/
#else
	UCHAR	dirName[ FS_DOS_PATH_LEN_MIN() + 1 ];	/* �f�B���N�g����(�t���p�X)				*/
	UCHAR	lfnDirName[ FS_MAX_PATHNAME_LEN + 1 ];/* LFN�t���p�X(260)(SJIS�p����������)	*/
#endif
} FS_DIR;


/* �f�B���N�g���G���g����� */
typedef struct fs_entry_t {
	UCHAR	pathname[FS_MAX_PATHNAME_LEN+1];
	UINT32	filesize;							/* �t�@�C���T�C�Y(�o�C�g��)				*/
	UINT16	atr;								/* ����									*/
	UINT16	year;								/* �X�V���t(�N)							*/
	UINT16	month;								/* �X�V���t(��)							*/
	UINT16	date;								/* �X�V���t(��)							*/
	UINT16	hour;								/* �X�V����(��)							*/
	UINT16	minute;								/* �X�V����(��)							*/
	UINT16	second;								/* �X�V����(�b)							*/
/* <Dolphin> Add for Dolphin */
#ifdef DOLPHIN_SDFS
	UINT16		fatent;					// Debug�p �t�@�C���G���g��
#endif
} FS_ENTRY;
/* Add for END */

/* ���s���ʒʒm��� */
typedef struct __fs_info_t {
	UINT16	b_flags;							/* �������e								*/
	UINT16	result;								/* ���s����								*/
	UINT32	resid;								/* �ǂ�(����)�T�C�Y						*/
} FS_INFO;


/* ���t�����i�[�\���� */
typedef struct __calendar{						/* �������ݒ莞�� All 0					*/
	UINT16	 Year;								/* �N(0 or 2000-2099)					*/
	UCHAR	 Month;								/* ��(0 or 1-12)						*/
	UCHAR	 Day;								/* ��(0 or 1-31)						*/
	UCHAR	 Hour;								/* ��(0-23)								*/
	UCHAR	 Minute;							/* ��(0-59)								*/
	UCHAR	 Second;							/* �b(0-59)								*/
} CALENDAR;

/* <Dolphin> Add For Dolphin */
#ifdef DOLPHIN_SDFS

typedef struct __cardlog{
	UINT32	acc;
	UINT32	off;
	UINT32	size;
	UINT32	ret;
} FS_CARDLOG;

#endif
/* <Dolphin> Add end */

/******** Format Check�p�\���̒�` ********/
/* FAT�p������(FC�p) */
typedef struct fs_fc_fat_t {
	UINT32		 offset;						/* �I�t�Z�b�g(�Z�N�^��)					*/
	UINT32		 used_size;						/* ���ݎg�p�o�b�t�@�T�C�Y(�Z�N�^��)		*/
	UINT32		 max_size;						/* �ő�o�b�t�@�T�C�Y(�Z�N�^��)			*/
	UCHAR		*buf;							/* �o�b�t�@�|�C���^						*/
} FS_FC_FAT;


/* �c���[�\���T�����(FC�p) */
typedef struct fs_fc_tree_t {
	UINT32		 ent_sec[FS_FC_MAX_LEVEL];		/* �G���g���Z�N�^�ʒu(�Z�N�^��)			*/
	UINT16		 ent_num[FS_FC_MAX_LEVEL];		/* �Z�N�^���G���g���ʒu(�G���g����)		*/
	UINT16		 start_clu[FS_FC_MAX_LEVEL];	/* �f�B���N�g���J�n�N���X�^�ԍ�			*/
												/* ���[�g������0						*/
} FS_FC_TREE;


/* �t�H�[�}�b�g�p�����[�^(FC�p) */
typedef struct fs_fc_param_t {
	UINT16		 numOfClusters;					/* �N���X�^��							*/
	UINT16		 sectorsPerCluster;				/* �N���X�^�T�C�Y(�Z�N�^��)				*/
	UINT16		 sectorsPerFAT;					/* FAT�T�C�Y�F�K�v�T�C�Y(�Z�N�^��)		*/
	UINT16		 kindOfFAT;						/* FAT���(FAT12/FAT16)					*/
	UINT16		 numOfRde;						/* Root Directory Entry��				*/
} FS_FC_PARAM;


/* FC�p�f�o�C�X��� */
typedef struct fs_fc_drive_t {
	UINT32		 cardSize;						/* �J�[�h�e��(�Z�N�^��)					*/
	UINT32		 areaSize;						/* �A�N�Z�X�\�T�C�Y      (�Z�N�^)		*/
	UINT32		 accessBufSize;					/* �A�N�Z�X�o�b�t�@�T�C�Y  (�Z�N�^)		*/
	UINT32		 w_offset;						/* �V�KFAT�������݃I�t�Z�b�g(�Z�N�^)	*/
	UINT32		 form_err;						/* �t�H�[�}�b�g�G���[					*/
	UINT16		 mode;							/* FC���샂�[�h							*/
	UINT16		 kindOfArea;					/* FS_NORMAL_AREA,FS_EXTRA_AREA			*/
	UINT16		 mediaClass;					/* FS_SD_CLASS,FS_MMC_CLASS				*/
	UINT16		 modifyFlag;					/* �������ݔ���t���O					*/
	UINT16		 volFlag;						/* �{�����[�����x���t���O				*/
	UINT16		 lfnFlag;						/* LFN�폜�t���O						*/
	FS_FC_TREE	 tree;							/* �c���[�\���T�����@					*/
	FS_FC_PARAM	 param;							/* �t�H�[�}�b�g�p�����[�^				*/
	FS_SECNO	 sn;							/* �Z�N�^�ԍ����						*/
	FS_FC_FAT	 fatReadBuf;					/* FAT�T���pRead�o�b�t�@				*/
	FS_FC_FAT	 fatWriteBuf;					/* FAT�č\�z�pWrite�o�b�t�@				*/
} FS_FC_DRIVE;


/****************************************************************************************
	�d���f�Ή��@�\�̓��L�̃f�[�^�\���̒�`
 ****************************************************************************************/
#if FS_POWREC_SUPPORT == FS_POWREC

/* ���J�o�����(SRAM�̈�) */
typedef		struct	recovery_info_t
{
	UCHAR		status;						/* �A�N�Z�X���								*/
	FS_DRIVE	*fsDrive;					/* �f�o�C�X���ւ̃|�C���^ 				*/
	UINT16		acsPt;						/* FAT �A�N�Z�X �|�C���^(�N���X�^)			*/
	UINT32		dirEntSecNo;				/* �f�B���N�g���G���g���Z�N�^�ʒu 			*/
	UINT16		dirEntOffset;				/* �f�B���N�g���G���g���Z�N�^���ʒu(�o�C�g)	*/
	UINT32		dirEntSecNo_sub;			/* �f�B���N�g���G���g���Z�N�^�ʒu			*/
	UINT16		dirEntOffset_sub;			/* �f�B���N�g���G���g���Z�N�^���ʒu(�o�C�g)	*/
	FS_DIRENT	DirEntry;					/* �f�B���N�g���G���g�����					*/
	UINT16		p_fatent;					/* �e�e�J�B���N�g���G���g��					*/
	UINT16		nextPt;						/* ����FAT �A�N�Z�X �|�C���^(�N���X�^)		*/
	UINT16		endPt;						/* �I�[��FAT �A�N�Z�X �|�C���^(�N���X�^)	*/
	UINT32		blockWriteSize;				/* 1�u���b�N�����݃f�[�^�T�C�Y(�Z�N�^)		*/
	UINT32		blockWriteOffset;			/* 1�u���b�N�����݃f�[�^�I�t�Z�b�g(�Z�N�^)	*/
	UCHAR		flags;						/* �X�e�[�^�X�t���O							*/
											/* 	b0:�ꎞ�t�@�C�����v���Ab1:�ʏ�j��	*/
											/*	b2:�F�ؔj���Ab3:�ꎞ�t�@�C���폜�v��	*/
	UINT16		tmpMKB;						/* MKBID�e���|�����f�[�^ 					*/
											/* 	b15:�����݃��[�h,b0�`3:MKB_ID(0�`15)	*/
} RECOVERY_INFO;


/* SD�����ݒ����(SRAM�̈�) */
typedef		struct	sd_writing_info_t
{
	UINT32		writesize;					/* SD�����ݎ��T�C�Y(�o�C�g)					*/
	UINT32		writedsize;					/* SD�����ݍςݎ��T�C�Y(�o�C�g)				*/
	UINT16		id;							/* Write���t�@�C��ID
												(�I�[�v�����t�@�C���e�[�u���z��Y��)	*/
	UINT16		nor_ext;					/* Write���t�@�C���̎��(�ʏ�=0�^�F��=1)	*/
}SD_WRITING_INFO ;


/* SD�����ݒ����(RAM�̈�) ���J�o����SRAM����SRAM�փR�s�[ */
/* FS_Getwi(),FS_ExtGetwi()�ŉ�������f�[�^ 			 */
typedef		struct	sd_writeing_info_ram_t
{
	UINT32		writesize;							/* SD�����ݎ��T�C�Y(�o�C�g)			*/
	UCHAR		pathName[FS_MAX_PATHNAME_LEN+1];	/* �t���p�X�l�[��					*/
	UINT16		nor_ext;							/* Write���t�@�C�����(��=0�^�F=1)	*/
}SD_WRITING_INFO_RAM ;

#endif	/* FS_POWREC_SUPPORT == FS_POWREC */



/****************************************************************************************
	VFAT�p�̃f�[�^�\���̒�`
 ****************************************************************************************/
#if	FS_FAT_TYPE == FS_SET_VFAT

/* LFN�������[�N�e�[�u�� */
typedef		struct	fs_lfn_search_t
{
	UCHAR		uni_len;						/* Unicode�����G���g���̕�����(254�ȉ�) */
	UCHAR		slot_num;						/* LFN�g�p�X���b�g���i�P�Ȃ�DOS���̂݁j	*/
	UCHAR		dos_exist;						/* DOS��������							*/
	UCHAR		lfn_search;						/* LFN�ŃG���g���������͂P				*/
	UINT32		start_slot_sec;					/* �����G���g���擪�ʒu���				*/
	UINT16		start_slot_byte;				/* 										*/
	UINT16		tilde_num;						/* ~#�̔ԍ��i�V�K�o�^����1���Z�b�g�j	*/
	UCHAR		create_name[FS_MAX_PATHNAME_LEN+1];
												/* �o�^�G���g����SJIS�R�[�hName�i�[		*/
	UINT16		open_lfn_pathName[FS_MAX_PATHNAME_LEN+1];
												/* �쐬LFN�t���p�X�i�[(UNICODE)			*/
	UCHAR		open_dos_pathName[FS_DOS_PATH_LEN_MIN()+1];
												/* �쐬DOS�t���p�X�i�[					*/
	UCHAR		dosname[13];					/* �����G���g����DOS���ϊ�Name�i�[ 		*/
} FS_LFN_SEARCH;
/*
	DOS���t���p�X open_dos_pathName�̃T�C�Y�́A13�~�K�w(�ő�K�w��)�{�P(NULL)�ɎZ�o�l�Ƃ���B
	�Z�o�l���ő�T�C�Y��260�𒴂���ꍇ��260�Œ�Ƃ���B
	dosname[13]�͏������݌`���łȂ��A���ʎq�Ɗg���q�̊Ԃ�'.'�������A�X�y�[�X�͂Ȃ��`���ŁA
	NULL�܂Őݒ肵�Ă����B
*/

/* LFN���i�[�p�f�B���N�g���G���g����� */
typedef		struct	fs_dirent_lfn_t
{
	UCHAR		id;							/* LFN�G���g��id�~����ݒ�A�擪��0x40��OR 	*/
	UCHAR		name0[10];					/* LFN��0�`4������(Unicode)					*/
	UCHAR		atr;						/* ����(0x0F�Œ�)							*/
	UCHAR		rev[1];						/* ���U�[�u									*/
	UCHAR		checksum;					/* CheckSum�DOS���̃r�b�g���[�e���V�����a	*/
	UCHAR		name5[12];					/* LFN��5�`10������(Unicode)				*/
	UINT16		fatEnt;						/* FAT�G���g��(0x00�Œ�)					*/
	UCHAR		name11[4];					/* LFN��11�`12������(Unicode)				*/
} FS_DIRENT_LFN;


#endif	/* FS_FAT_TYPE == FS_SET_VFAT */



/****************************************************************************************
	���ʂ̃f�[�^�\���̒�`
 ****************************************************************************************/

/* Drive�Ǘ����(SRAM/RAM) */
typedef struct fs_drive_control_info_t {
	/* Drive��� */
	UINT16		fsDriveNo;							/* Drive�w��l						*/
	UINT16		driveNum;							/* �h���C�u�ԍ�						*/
	UINT16		statusOfDrive;						/* �h���C�u���������				*/
	/* �f�o�C�X���  */
	FS_DRIVE	FS_nor_drvinfo;						/* �ʏ�̈�p 						*/
	FS_DRIVE	FS_ext_drvinfo;						/* �F�ؗ̈�p 						*/
	/*  �t�@�C�����\���� */
	FS_FILE		FS_nor_file[FS_MAX_OF_NOR_OPEN];	/* �ʏ�̈�p						*/
	FS_FILE		FS_ext_file[FS_MAX_OF_EXT_OPEN];	/* �F�ؗ̈�p						*/
	/* FS_FILE		FS_nor_file_temp;				/* �ʏ�̈�ptemp					*/
	/* FS_FILE		FS_ext_file_temp;				/* �F�ؗ̈�ptemp					*/
	/* FAT���\���� */
	UINT32		fatMemSize;							/* FAT�T�C�Y(�ʏ�pFAT+�F�ؗpFAT�j	*/
	UINT32		fatExtMemSize;						/* �Ҕ�p�F�ؗpFAT�T�C�Y			*/
	UCHAR		FS_fat[FS_ALL_FAT_MEM_SIZE];		/* FAT�̈�							*/
	UCHAR		*FS_nor_fat;						/* �ʏ�pFAT						*/
	UCHAR		*FS_ext_fat;						/* �F�ؗpFAT						*/
	/* �f�B���N�g�����\���� */
	FS_DIR		FS_nor_dir[FS_MAX_OF_NOR_OPEN_DIR];	/* �ʏ�̈�p						*/
	FS_DIR		FS_ext_dir[FS_MAX_OF_EXT_OPEN_DIR];	/* �F�ؗ̈�p						*/
	/* FS_DIR		FS_nor_dir_temp;				/* �ʏ�̈�ptemp					*/
	/* FS_DIR		FS_ext_dir_temp;				/* �F�ؗ̈�ptemp					*/
	/* Read/Write Buffer */
	FS_TMPBUF	FS_TmpBuf;							/* Buffer							*/
	/* �R�[���o�b�N�֐��p�\���� */
	FS_INFO		FS_TmpInfo;							/* FS_INFO							*/
	/* �󂫗̈�i�[�p�ϐ� */
	UINT32		FS_gl_start_sec;					/* �T���J�n�ʒu						*/
	UINT32		FS_gl_empty_sec;					/* �󂫃G���g���ʒu					*/
	UINT16		FS_gl_empty_byte;					/* �󂫃G���g���ʒu					*/
	/* FAT�L���b�V�� */
	FS_CACHE	FS_cache;							/* FAT�L���b�V��					*/
	UINT32		FS_fat_now_cache_mem;				/* FAT�L���b�V���������T�C�Y		*/
	/* ������i�[�p�ϐ� */
	UINT32		FS_random_seed;						/* ������							*/
	UINT16		FS_random_flag;						/* ������ݒ�t���O(0:���ݒ�1:�ݒ�)*/
	/* Format Check�p�O���[�o���ϐ� */
	FS_FC_DRIVE	FS_FC_dp;							/* FormatCheck�p�f�o�C�X���		*/
	UINT16		FS_FC_depth;						/* ���ݒ��ڊK�w(root=0)				*/

#if FS_POWREC_SUPPORT == FS_POWREC
	
	/* ���J�o�����(SRAM�̈�) */
	RECOVERY_INFO	Recovery_Info;					/* ���J�o�����						*/
	/* �ꎞ�t�@�C�����(SRAM�̈�) */
	UINT32	delSecNo;								/* Directory Entry�Z�N�^�ʒu		*/
	UINT16	delOffset;								/* Directory Entry�Z�N�^���ʒu(B)	*/
	UINT16	delpent;								/* �e�f�B���N�g���G���g���J�n�ʒu	*/
	/* CID�ޔ�̈�(SRAM�̈�) */
	UCHAR	CID_diffbuf[16];						/* CID�ۑ��̈�						*/
	/* �F��Write(Open�O�ɖ߂�)�pFAT�G���g��(SRAM) */
	UINT16	ExtFatent[FS_MAX_OF_EXT_OPEN];			/* �F��Open���A�����t�@�C����
															FAT�G���g����ێ�����̈�	*/
	/* SD�����ݒ���� */
	SD_WRITING_INFO		SD_Writing_Info;				/* SD�����ݒ����				*/
	SD_WRITING_INFO_RAM	SD_Writing_Info_Ram;			/* SD�����ݒ����				*/

#endif

#if FS_FAT_TYPE == FS_SET_VFAT

	/* LFN�����֘A�f�[�^ */
	FS_LFN_SEARCH	FS_lfn_Search;					/* LFN�����e�[�u��					*/
	UINT16	FS_lfn_uniname[FS_MAX_PATHNAME_LEN+1];	/* �����G���g��Unicode�ϊ�Name�i�[ 	*/
	UCHAR	FS_FC_lfn_checksum;						/* Format Check�pCheckSum�ۑ��̈�	*/
	UCHAR	FS_FC_lfn_flag;							/* LFN�G���g�����o�t���O			*/

#endif

} FS_DRIVE_CONTROL;




#endif
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
