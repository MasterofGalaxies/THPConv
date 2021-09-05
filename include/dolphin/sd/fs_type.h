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
$Log		変更履歴
$ 2001. 3.29	:V.2.00 
$ 2001. 6. 8	:V.2.10 
$ 2001.11. 7	:V.2.20	
$ 2002. 2.13	:V.2.80 電源断対応												MSE
$ 2002. 3.15	:V.2.90 VFAT対応												MSE
$ 2002. 3.25	:V.3.00 MultiDrive・FlashROM対応α版							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive・FlashROM対応β版							MSE M.O
$ 2002. 6. 4	:V.3.02 MultiDrive・FlashROM対応β2版							MSE M.O
$ 2002. 7. 5	:V.3.03	MultiDrive・FlashROM対応β3版							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin対応版						
========================================================================================*/

#ifndef __FS_TYPE_H__
#define __FS_TYPE_H__

/****
	データ構造体定義
						****/

#ifdef TYPE_32BIT	/* 環境移行  */
#define __packed

/* Partition Table情報 */
typedef __packed struct _fs_partition_table_t {
	UCHAR	bootIndicator;							/* ブートインジケータ				*/
	UCHAR	startHead;								/* 開始ヘッド						*/
	UINT16	startSectorCylinder;					/* 開始セクタ	:bit15-10			*/
													/* 開始シリンダ :bit 9-0			*/
	UCHAR	systemID;								/* SystemID							*/
	UCHAR	endHead;								/* 終了ヘッド						*/
	UINT16	endSectorCylinder;						/* 終了セクタ	:bit15-10			*/
													/* 終了シリンダ	:bit 9-0			*/
	UINT32	relativeSector;							/* 相対セクタ数						*/
	UINT32	totalSector;							/* 総セクタ数						*/
} FS_PT;


/* Master Boot Record情報 */
typedef __packed struct _fs_mbr_pt_t {
	UCHAR	masterBootRecode[446];					/* マスターブートレコード			*/
	FS_PT	partitionTable1;						/* パーティションテーブル１			*/
	FS_PT	partitionTable2;						/* パーティションテーブル２			*/
	FS_PT	partitionTable3;						/* パーティションテーブル３			*/
	FS_PT	partitionTable4;						/* パーティションテーブル４			*/
	UINT16	signifyWord;							/* シグニチャワード					*/
} FS_MBR_PT;

#else

/* Partition Table情報 */
typedef struct _fs_partition_table_t {
	UCHAR	bootIndicator;							/* ブートインジケータ				*/
	UCHAR	startHead;								/* 開始ヘッド						*/
	UINT16	startSectorCylinder;					/* 開始セクタ	:bit15-10			*/
													/* 開始シリンダ :bit 9-0			*/
	UCHAR	systemID;								/* SystemID							*/
	UCHAR	endHead;								/* 終了ヘッド						*/
	UINT16	endSectorCylinder;						/* 終了セクタ	:bit15-10			*/
													/* 終了シリンダ	:bit 9-0			*/
	UINT32	relativeSector;							/* 相対セクタ数						*/
	UINT32	totalSector;							/* 総セクタ数						*/
} FS_PT;


/* Master Boot Record情報 */
typedef struct _fs_mbr_pt_t {
	UCHAR	masterBootRecode[446];					/* マスターブートレコード			*/
	FS_PT	partitionTable1;						/* パーティションテーブル１			*/
	FS_PT	partitionTable2;						/* パーティションテーブル２			*/
	FS_PT	partitionTable3;						/* パーティションテーブル３			*/
	FS_PT	partitionTable4;						/* パーティションテーブル４			*/
	UINT16	signifyWord;							/* シグニチャワード					*/
} FS_MBR_PT;
#endif


/* Master Boot Recordデータ確認情報 */
typedef struct _check_cluster_boundary_t {
	UINT32	targetAreaSize;							/* Card Capacity/Protected Area		*/
	UINT16	sectorsPerCluster;						/* Sectors per Clusterin FDC		*/
	UINT16	boundaryUnit;							/*Boundary Unit at User Data Offset	*/
} CHK_CLUSTER_BOUNDARY_T;


/* CHS Recommendationデータ確認情報 */
typedef struct _check_chs_recommendation_t {
	UINT32	targetAreaSize;							/* Card Capacity					*/
	UINT16	numberOfHeads;							/* Number of Heads					*/
	UINT16	sectorsPerTrack;						/* Sectors per track				*/
} CHK_CHS_RECOMMENDATION_T;


/* Minimum Protected Area Aizeデータ確認情報 */
typedef struct _check_min_p_area_size_t {
	UINT32	targetAreaSize;							/* Card Capacity					*/
	UINT32	minProtectedAreaSize;					/* Min.Protected Area Size			*/
} CHK_MIN_P_AREA_SIZE_T;


/* FDC情報 */
typedef struct _fs_fdc_t {
	UINT16	bytesPerSector;							/* バイト / セクタ					*/
	UINT16	sectorsPerCluster;						/* セクタ / クラスタ				*/
	UINT16	sectorsPerTrack;						/* セクタ / トラック				*/
	UINT16	numberOfSides;							/* 面数								*/
	UINT16	reservedSectors;						/* 予約セクタ数 					*/
	UINT16	numberOfFATs;							/* FATの数    						*/
	UINT16	rootEntries;							/* ルート・ディレクトリのエントリ数	*/
	UINT16	totalSectors;							/* ディスクの総セクタ数				*/
	UINT16	mediaDescriptor;						/* メディア・ディスクリプタ			*/
	UINT16	sectorsPerFAT;							/* セクタ / FAT						*/
	UINT32	hidedSectors;							/* 隠されたセクタ数					*/
	UINT32	extentTotalSectors;						/* 大容量ディスクの総セクタ数		*/
	UINT32	volumeSerialNumber;						/* ボリューム・シリアル番号			*/
	UINT16	kindOfFAT;								/* FATの種別(FAT16/FAT12)			*/
	UCHAR	volumeLabel[12];						/* ボリューム・ラベル 				*/
	UCHAR	sysAtr[9];								/* 作成システム識別子 				*/
	UCHAR	extBootRecordSignature;					/* 拡張ブートレコードシグネチャ		*/
} FS_FDC;


/* セクタ番号情報 */
typedef struct _fs_sec_no_t {						/* 物理セクタ値						*/
	UINT32	boot;									/* ブート・セクタ番号 				*/
	UINT32	fat1;									/* FAT1開始セクタ番号				*/
	UINT32	fat2;									/* FAT2開始セクタ番号 				*/
	UINT32 	dir;									/* ROOTDIR開始セクタ番号			*/
	UINT32	data;									/* DATA開始セクタ番号				*/
	UINT32	eov;									/* 最終セクタ番号+1					*/
} FS_SECNO;


/* カレント位置情報 */
typedef struct _fs_current_t {						/* カレント位置						*/
	UINT32	dirEntSecNo;							/* DirectoryEntryのセクタ位置		*/
	UINT16	dirEntOffset;							/* DirectoryEntryのセクタ内位置(B)	*/
	UINT16	pFATEnt;								/* 親ディレクトリ開始クラスタ番号	*/
	UINT16	startCluster;							/* カレント領域開始クラスタ番号		*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	pathName[ FS_MAX_PATHNAME_LEN + 1 ];	/* フルパスネーム					*/
#else
	UCHAR	pathName[ FS_DOS_PATH_LEN_MIN() + 1 ];	/* フルパスネーム					*/
	UCHAR	lfnPathName[ FS_MAX_PATHNAME_LEN + 1 ]; /* LFNフルパス(260:SJIS英小文字あり)*/
#endif
} FS_CURRENT;


/* FATキャッシュ */
typedef struct fs_cache_t {
	union{
		UINT16	*pFAT16[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* FAT16用データ			*/
		UCHAR	*pFAT12[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* FAT12用データ			*/
	} fs_cacheD;
	UINT16	kindOfArea[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* 領域の種別				*/
	UINT16	cacheOffset[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* CacheFAT内セクタ位置0～	*/
	UINT16	cacheSize[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];	/* 1Cacheのサイズ(セクタ数) */
	UINT16	newest[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];		/* 最新更新順格納用			*/
	UINT16	modify[FS_ALL_FAT_MEM_SIZE/FS_FAT_CACHE_SIZE];		/* 更新判定					*/
} FS_CACHE;


/* FAT情報 */
typedef struct fs_fat_t {
	UINT16	fatAtr;						/* FATテーブル識別子(FAT1/FAT2)					*/
	UINT16	fatOffset;					/* FAToffset (セクタ)(論理)						*/
	UINT16	fatAreaTCount;				/* FATエントリ数
												(FAT1全体のMAX値+2,最大クラスタ番号+1)	*/
	UINT16	fatSerch;					/* FAT空き情報開始ポイント(単位数)				*/
	UINT16	modifyFlag;					/* FAT情報更新フラグ(0:更新なし)				*/
	UCHAR	modifySectorBit[32];		/* FAT情報更新セクタ管理ビット
										   (先頭バイトの先頭ビット=FAT先頭セクタ～
										   最終バイトの最終ビット=FAT最終セクタに対応)	*/
	UINT16	modifyClusterCount;			/* FAT情報更新クラスタ数カウンタ(クラスタ数)	*/
	UINT16	maxModifyCluster;			/* 最大FAT情報更新クラスタ数					*/
	union{
		UINT16	*pFAT16;				/* FAT16データ用		 						*/
		UCHAR	*pFAT12;				/* FAT12データ用		 						*/
	} fs_pFATD;
	FS_CACHE	*cacheP;				/* キャッシュポインタ							*/
	UINT16		fatCacheMode;			/* 1:FAT is cache, 2:FAT is On Memory			*/
} FS_FAT;


/* デバイス情報 */
typedef struct _fs_drive_t {
	UINT16	fsDriveNo;							/* Drive指定値							*/
	UINT16	driveNum;							/* ドライブ番号							*/
	UINT16	kindOfArea;							/* 1:通常領域、2:認証領域				*/
	UINT16	mountFlag;							/* マウント状態							*/
	UINT32	startFDCsec;						/* FDC先頭セクタ番号(物理)				*/
	FS_PT	mbrPartitionTable1;					/* MBR Partition Table1情報				*/
	FS_FDC	fdc;								/* FDC情報								*/
	FS_SECNO	sn;								/* セクタ番号情報						*/
	FS_CURRENT	cr;								/* カレント位置情報						*/
	FS_FAT	fatInfo;							/* 保持FATデータ情報					*/
	UINT16	openFileCnt;						/* オープン中のファイル数				*/
	UINT16	acsSecPerCluster;					/* アクセス用クラスタサイズ(セクタ)		*/
	UINT16	kindOfHeadData;						/* セクタ0種類(MBR/FDC/ExtenedFDC)		*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
	UINT32	mediaSize;							/* アクセス可能サイズ(セクタ) 			*/
	UINT16	mediaClass;							/* メディアの種類(1:SD,2:MMC)			*/
	UINT16	mediaInfo;							/* フォーマットエラーレベル				*/
												/* 1:FATALエラー,2:SD規格違反,4;ISO違反	*/
} FS_DRIVE;


/* ファイルシステム情報 */
typedef struct fs_filesystem_t {
	UINT32	totalSecSize;						/* 総容量(セクタ:クラスタ倍数)			*/
	UINT32	spaceSecSize;						/* 空き容量(セクタ:クラスタ倍数)		*/
	UINT16	clusterBSize;						/* クラスタサイズ (バイト)				*/
	UINT16	sectorBSize;						/* セクタサイズ  （バイト)				*/
} FS_FS;


/* ディレクトリエントリ情報 */
typedef struct fs_dirent_t {
	UCHAR  	fName[11];							/* ファイル名(名前8文字+拡張子3文字)	*/
	UCHAR  	atr;								/* 属性									*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR  	rev[10];							/* リザーブ								*/
#else
	UCHAR	rev[1];								/* リザーブ								*/
	UCHAR	ctime_ms;							/* 作成時刻(10ミリ秒)					*/
	UINT16	ctime;								/* 作成時刻								*/
	UINT16	cdate;								/* 作成日付								*/
	UINT16	adate;								/* 最終アクセス日付						*/
	UINT16	hiclust;							/* FATエントリ上位(FAT32のみ)			*/
#endif
	UINT16 	upTime;								/* 変更時刻								*/
	UINT16 	upDate;								/* 変更日付								*/
	UINT16 	fatEnt;								/* FATエントリ							*/
	UINT32 	fSize;								/* ファイル・サイズ						*/
} FS_DIRENT;


/* ファイル情報 */
typedef struct fs_file_t {
	UINT16	id;									/* FS_FILE識別番号						*/
	UINT16	modifyFlag;							/* メディア情報更新FLAG(close時)		*/
	FS_DRIVE	*fsDrive;						/* デバイス情報へのポインタ				*/
	FS_DIRENT	fsDirEntry;						/* ディレクトリ情報へのポインタ 		*/
	UINT32	offset;								/* オフセット(バイト数)（論理)			*/
	UINT16	openAtr;							/* オープン属性 						*/
	UINT16	acsPt;								/* FAT アクセス ポインタ(クラスタ)		*/
	UINT16	newCluster;							/* 新規に獲得したクラスタ(クラスタ)		*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
	UINT32	dirEntSecNo;						/* ディレクトリエントリセクタ位置		*/
	UINT16	dirEntOffset;						/* ディレクトリエントリセクタ内位置(B)	*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	pathName[FS_MAX_PATHNAME_LEN+1];	/* フルパスネーム						*/
#else
	UCHAR	pathName[FS_DOS_PATH_LEN_MIN()+1];	/* フルパスネーム						*/
	UCHAR	lfnPathName[FS_MAX_PATHNAME_LEN+1];	/* LFNフルパス(260)(SJIS英小文字あり)	*/
#endif
} FS_FILE;


/* Temp Buffer */
typedef union	fs_tmpbuffer_t {
	UCHAR		FS_CharBuf[FS_LOGICAL_CLUSTER_SIZE];
	FS_DIRENT	FS_DirBuf[FS_LOGICAL_CLUSTER_SIZE/FS_ROOTDIR_ITEM_SIZE];
} FS_TMPBUF;


/* ディレクトリ情報 */
typedef struct fs_dir_t {
	FS_DRIVE	*fsDrive;						/* デバイス情報へのポインタ				*/
	UINT32	pos;								/* ディレクトリ開始セクタ番号			*/
	UINT32	offset;								/* シーク位置(実バイト数)				*/
	UINT32	current;							/* シーク位置(クラスタ開始セクタ番号)	*/
	UINT16	entNum;								/* シーク位置(有効エントリ数)			*/
	UINT16	mkbId;								/* MKB_ID(0-15)							*/
#if FS_FAT_TYPE != FS_SET_VFAT
	UCHAR	dirName[ FS_MAX_PATHNAME_LEN + 1 ];	/* ディレクトリ名(フルパス)				*/
#else
	UCHAR	dirName[ FS_DOS_PATH_LEN_MIN() + 1 ];	/* ディレクトリ名(フルパス)				*/
	UCHAR	lfnDirName[ FS_MAX_PATHNAME_LEN + 1 ];/* LFNフルパス(260)(SJIS英小文字あり)	*/
#endif
} FS_DIR;


/* ディレクトリエントリ情報 */
typedef struct fs_entry_t {
	UCHAR	pathname[FS_MAX_PATHNAME_LEN+1];
	UINT32	filesize;							/* ファイルサイズ(バイト数)				*/
	UINT16	atr;								/* 属性									*/
	UINT16	year;								/* 更新日付(年)							*/
	UINT16	month;								/* 更新日付(月)							*/
	UINT16	date;								/* 更新日付(日)							*/
	UINT16	hour;								/* 更新時刻(時)							*/
	UINT16	minute;								/* 更新時刻(分)							*/
	UINT16	second;								/* 更新時刻(秒)							*/
/* <Dolphin> Add for Dolphin */
#ifdef DOLPHIN_SDFS
	UINT16		fatent;					// Debug用 ファイルエントリ
#endif
} FS_ENTRY;
/* Add for END */

/* 実行結果通知情報 */
typedef struct __fs_info_t {
	UINT16	b_flags;							/* 処理内容								*/
	UINT16	result;								/* 実行結果								*/
	UINT32	resid;								/* 読み(書き)サイズ						*/
} FS_INFO;


/* 日付時刻格納構造体 */
typedef struct __calendar{						/* 時刻未設定時は All 0					*/
	UINT16	 Year;								/* 年(0 or 2000-2099)					*/
	UCHAR	 Month;								/* 月(0 or 1-12)						*/
	UCHAR	 Day;								/* 日(0 or 1-31)						*/
	UCHAR	 Hour;								/* 時(0-23)								*/
	UCHAR	 Minute;							/* 分(0-59)								*/
	UCHAR	 Second;							/* 秒(0-59)								*/
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

/******** Format Check用構造体定義 ********/
/* FAT用メモリ(FC用) */
typedef struct fs_fc_fat_t {
	UINT32		 offset;						/* オフセット(セクタ数)					*/
	UINT32		 used_size;						/* 現在使用バッファサイズ(セクタ数)		*/
	UINT32		 max_size;						/* 最大バッファサイズ(セクタ数)			*/
	UCHAR		*buf;							/* バッファポインタ						*/
} FS_FC_FAT;


/* ツリー構造探索情報(FC用) */
typedef struct fs_fc_tree_t {
	UINT32		 ent_sec[FS_FC_MAX_LEVEL];		/* エントリセクタ位置(セクタ数)			*/
	UINT16		 ent_num[FS_FC_MAX_LEVEL];		/* セクタ内エントリ位置(エントリ数)		*/
	UINT16		 start_clu[FS_FC_MAX_LEVEL];	/* ディレクトリ開始クラスタ番号			*/
												/* ルート直下は0						*/
} FS_FC_TREE;


/* フォーマットパラメータ(FC用) */
typedef struct fs_fc_param_t {
	UINT16		 numOfClusters;					/* クラスタ数							*/
	UINT16		 sectorsPerCluster;				/* クラスタサイズ(セクタ数)				*/
	UINT16		 sectorsPerFAT;					/* FATサイズ：必要サイズ(セクタ数)		*/
	UINT16		 kindOfFAT;						/* FAT種別(FAT12/FAT16)					*/
	UINT16		 numOfRde;						/* Root Directory Entry数				*/
} FS_FC_PARAM;


/* FC用デバイス情報 */
typedef struct fs_fc_drive_t {
	UINT32		 cardSize;						/* カード容量(セクタ数)					*/
	UINT32		 areaSize;						/* アクセス可能サイズ      (セクタ)		*/
	UINT32		 accessBufSize;					/* アクセスバッファサイズ  (セクタ)		*/
	UINT32		 w_offset;						/* 新規FAT書き込みオフセット(セクタ)	*/
	UINT32		 form_err;						/* フォーマットエラー					*/
	UINT16		 mode;							/* FC動作モード							*/
	UINT16		 kindOfArea;					/* FS_NORMAL_AREA,FS_EXTRA_AREA			*/
	UINT16		 mediaClass;					/* FS_SD_CLASS,FS_MMC_CLASS				*/
	UINT16		 modifyFlag;					/* 書きこみ判定フラグ					*/
	UINT16		 volFlag;						/* ボリュームラベルフラグ				*/
	UINT16		 lfnFlag;						/* LFN削除フラグ						*/
	FS_FC_TREE	 tree;							/* ツリー構造探索情報　					*/
	FS_FC_PARAM	 param;							/* フォーマットパラメータ				*/
	FS_SECNO	 sn;							/* セクタ番号情報						*/
	FS_FC_FAT	 fatReadBuf;					/* FAT探索用Readバッファ				*/
	FS_FC_FAT	 fatWriteBuf;					/* FAT再構築用Writeバッファ				*/
} FS_FC_DRIVE;


/****************************************************************************************
	電源断対応機能の特有のデータ構造体定義
 ****************************************************************************************/
#if FS_POWREC_SUPPORT == FS_POWREC

/* リカバリ情報(SRAM領域) */
typedef		struct	recovery_info_t
{
	UCHAR		status;						/* アクセス状態								*/
	FS_DRIVE	*fsDrive;					/* デバイス情報へのポインタ 				*/
	UINT16		acsPt;						/* FAT アクセス ポインタ(クラスタ)			*/
	UINT32		dirEntSecNo;				/* ディレクトリエントリセクタ位置 			*/
	UINT16		dirEntOffset;				/* ディレクトリエントリセクタ内位置(バイト)	*/
	UINT32		dirEntSecNo_sub;			/* ディレクトリエントリセクタ位置			*/
	UINT16		dirEntOffset_sub;			/* ディレクトリエントリセクタ内位置(バイト)	*/
	FS_DIRENT	DirEntry;					/* ディレクトリエントリ情報					*/
	UINT16		p_fatent;					/* 親テ゛ィレクトリエントリ					*/
	UINT16		nextPt;						/* 次のFAT アクセス ポインタ(クラスタ)		*/
	UINT16		endPt;						/* 終端のFAT アクセス ポインタ(クラスタ)	*/
	UINT32		blockWriteSize;				/* 1ブロック書込みデータサイズ(セクタ)		*/
	UINT32		blockWriteOffset;			/* 1ブロック書込みデータオフセット(セクタ)	*/
	UCHAR		flags;						/* ステータスフラグ							*/
											/* 	b0:一時ファイル情報要求、b1:通常破棄	*/
											/*	b2:認証破棄、b3:一時ファイル削除要求	*/
	UINT16		tmpMKB;						/* MKBIDテンポラリデータ 					*/
											/* 	b15:書込みモード,b0～3:MKB_ID(0～15)	*/
} RECOVERY_INFO;


/* SD書込み中情報(SRAM領域) */
typedef		struct	sd_writing_info_t
{
	UINT32		writesize;					/* SD書込み実サイズ(バイト)					*/
	UINT32		writedsize;					/* SD書込み済み実サイズ(バイト)				*/
	UINT16		id;							/* Write中ファイルID
												(オープン情報ファイルテーブル配列添字)	*/
	UINT16		nor_ext;					/* Write中ファイルの種別(通常=0／認証=1)	*/
}SD_WRITING_INFO ;


/* SD書込み中情報(RAM領域) リカバリ時SRAMからSRAMへコピー */
/* FS_Getwi(),FS_ExtGetwi()で応答するデータ 			 */
typedef		struct	sd_writeing_info_ram_t
{
	UINT32		writesize;							/* SD書込み実サイズ(バイト)			*/
	UCHAR		pathName[FS_MAX_PATHNAME_LEN+1];	/* フルパスネーム					*/
	UINT16		nor_ext;							/* Write中ファイル種別(通=0／認=1)	*/
}SD_WRITING_INFO_RAM ;

#endif	/* FS_POWREC_SUPPORT == FS_POWREC */



/****************************************************************************************
	VFAT用のデータ構造体定義
 ****************************************************************************************/
#if	FS_FAT_TYPE == FS_SET_VFAT

/* LFN検索ワークテーブル */
typedef		struct	fs_lfn_search_t
{
	UCHAR		uni_len;						/* Unicode検索エントリの文字数(254以下) */
	UCHAR		slot_num;						/* LFN使用スロット数（１ならDOS名のみ）	*/
	UCHAR		dos_exist;						/* DOS名が存在							*/
	UCHAR		lfn_search;						/* LFNでエントリ検索時は１				*/
	UINT32		start_slot_sec;					/* 検索エントリ先頭位置情報				*/
	UINT16		start_slot_byte;				/* 										*/
	UINT16		tilde_num;						/* ~#の番号（新規登録時に1をセット）	*/
	UCHAR		create_name[FS_MAX_PATHNAME_LEN+1];
												/* 登録エントリのSJISコードName格納		*/
	UINT16		open_lfn_pathName[FS_MAX_PATHNAME_LEN+1];
												/* 作成LFNフルパス格納(UNICODE)			*/
	UCHAR		open_dos_pathName[FS_DOS_PATH_LEN_MIN()+1];
												/* 作成DOSフルパス格納					*/
	UCHAR		dosname[13];					/* 検索エントリのDOS名変換Name格納 		*/
} FS_LFN_SEARCH;
/*
	DOS名フルパス open_dos_pathNameのサイズは、13×階層(最大階層数)＋１(NULL)に算出値とする。
	算出値が最大サイズの260を超える場合は260固定とする。
	dosname[13]は書き込み形式でなく、識別子と拡張子の間に'.'を持ち、スペースはない形式で、
	NULLまで設定しておく。
*/

/* LFN名格納用ディレクトリエントリ情報 */
typedef		struct	fs_dirent_lfn_t
{
	UCHAR		id;							/* LFNエントリid降順を設定、先頭は0x40がOR 	*/
	UCHAR		name0[10];					/* LFN名0～4文字目(Unicode)					*/
	UCHAR		atr;						/* 属性(0x0F固定)							*/
	UCHAR		rev[1];						/* リザーブ									*/
	UCHAR		checksum;					/* CheckSum､DOS名のビットローテンション和	*/
	UCHAR		name5[12];					/* LFN名5～10文字目(Unicode)				*/
	UINT16		fatEnt;						/* FATエントリ(0x00固定)					*/
	UCHAR		name11[4];					/* LFN名11～12文字目(Unicode)				*/
} FS_DIRENT_LFN;


#endif	/* FS_FAT_TYPE == FS_SET_VFAT */



/****************************************************************************************
	共通のデータ構造体定義
 ****************************************************************************************/

/* Drive管理情報(SRAM/RAM) */
typedef struct fs_drive_control_info_t {
	/* Drive情報 */
	UINT16		fsDriveNo;							/* Drive指定値						*/
	UINT16		driveNum;							/* ドライブ番号						*/
	UINT16		statusOfDrive;						/* ドライブ初期化状態				*/
	/* デバイス情報  */
	FS_DRIVE	FS_nor_drvinfo;						/* 通常領域用 						*/
	FS_DRIVE	FS_ext_drvinfo;						/* 認証領域用 						*/
	/*  ファイル情報構造体 */
	FS_FILE		FS_nor_file[FS_MAX_OF_NOR_OPEN];	/* 通常領域用						*/
	FS_FILE		FS_ext_file[FS_MAX_OF_EXT_OPEN];	/* 認証領域用						*/
	/* FS_FILE		FS_nor_file_temp;				/* 通常領域用temp					*/
	/* FS_FILE		FS_ext_file_temp;				/* 認証領域用temp					*/
	/* FAT情報構造体 */
	UINT32		fatMemSize;							/* FATサイズ(通常用FAT+認証用FAT）	*/
	UINT32		fatExtMemSize;						/* 待避用認証用FATサイズ			*/
	UCHAR		FS_fat[FS_ALL_FAT_MEM_SIZE];		/* FAT領域							*/
	UCHAR		*FS_nor_fat;						/* 通常用FAT						*/
	UCHAR		*FS_ext_fat;						/* 認証用FAT						*/
	/* ディレクトリ情報構造体 */
	FS_DIR		FS_nor_dir[FS_MAX_OF_NOR_OPEN_DIR];	/* 通常領域用						*/
	FS_DIR		FS_ext_dir[FS_MAX_OF_EXT_OPEN_DIR];	/* 認証領域用						*/
	/* FS_DIR		FS_nor_dir_temp;				/* 通常領域用temp					*/
	/* FS_DIR		FS_ext_dir_temp;				/* 認証領域用temp					*/
	/* Read/Write Buffer */
	FS_TMPBUF	FS_TmpBuf;							/* Buffer							*/
	/* コールバック関数用構造体 */
	FS_INFO		FS_TmpInfo;							/* FS_INFO							*/
	/* 空き領域格納用変数 */
	UINT32		FS_gl_start_sec;					/* 探索開始位置						*/
	UINT32		FS_gl_empty_sec;					/* 空きエントリ位置					*/
	UINT16		FS_gl_empty_byte;					/* 空きエントリ位置					*/
	/* FATキャッシュ */
	FS_CACHE	FS_cache;							/* FATキャッシュ					*/
	UINT32		FS_fat_now_cache_mem;				/* FATキャッシュメモリサイズ		*/
	/* 乱数種格納用変数 */
	UINT32		FS_random_seed;						/* 乱数種							*/
	UINT16		FS_random_flag;						/* 乱数種設定フラグ(0:未設定､1:設定)*/
	/* Format Check用グローバル変数 */
	FS_FC_DRIVE	FS_FC_dp;							/* FormatCheck用デバイス情報		*/
	UINT16		FS_FC_depth;						/* 現在着目階層(root=0)				*/

#if FS_POWREC_SUPPORT == FS_POWREC
	
	/* リカバリ情報(SRAM領域) */
	RECOVERY_INFO	Recovery_Info;					/* リカバリ情報						*/
	/* 一時ファイル情報(SRAM領域) */
	UINT32	delSecNo;								/* Directory Entryセクタ位置		*/
	UINT16	delOffset;								/* Directory Entryセクタ内位置(B)	*/
	UINT16	delpent;								/* 親ディレクトリエントリ開始位置	*/
	/* CID退避領域(SRAM領域) */
	UCHAR	CID_diffbuf[16];						/* CID保存領域						*/
	/* 認証Write(Open前に戻す)用FATエントリ(SRAM) */
	UINT16	ExtFatent[FS_MAX_OF_EXT_OPEN];			/* 認証Open時、既存ファイルの
															FATエントリを保持する領域	*/
	/* SD書込み中情報 */
	SD_WRITING_INFO		SD_Writing_Info;				/* SD書込み中情報				*/
	SD_WRITING_INFO_RAM	SD_Writing_Info_Ram;			/* SD書込み中情報				*/

#endif

#if FS_FAT_TYPE == FS_SET_VFAT

	/* LFN検索関連データ */
	FS_LFN_SEARCH	FS_lfn_Search;					/* LFN検索テーブル					*/
	UINT16	FS_lfn_uniname[FS_MAX_PATHNAME_LEN+1];	/* 検索エントリUnicode変換Name格納 	*/
	UCHAR	FS_FC_lfn_checksum;						/* Format Check用CheckSum保存領域	*/
	UCHAR	FS_FC_lfn_flag;							/* LFNエントリ検出フラグ			*/

#endif

} FS_DRIVE_CONTROL;




#endif
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
