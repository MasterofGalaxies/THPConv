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
$Log		変更履歴
$ 2001. 3.29	:V.2.00 
$ 2001. 6. 8	:V.2.10 
$ 2001.11. 7	:V.2.20
$ 2002. 2.13	:V.2.80 電源断対応												MSE
$ 2002. 3.15	:V.2.90 VFAT対応												MSE
$ 2002. 3.25	:V.3.00 MultiDrive・FlashROM対応α版							MSE M.O
$ 2002. 4.26	:V.3.01 MultiDrive・FlashROM対応β版							MSE M.O
$ 2002. 6. 3	:V.3.02 MultiDrive・FlashROM対応β2版							MSE M.O
$ 2002. 7. 5	:V.3.03 MultiDrive・FlashROM対応β3版							MSE M.O
$ 2002. 7.22	:V.3.03a Dolphin対応版							MSE M.O
$=======================================================================================*/
#ifndef __FS_DEF_H__
#define __FS_DEF_H__

/****	ソースコンパイル用定数		****/
#define FS_MN10200		 						/* MN10200のときに定義					*/
/****	メディア種別				****/
#define	FS_SD_CLASS					1			/* SDカード								*/
#define	FS_MMC_CLASS				2			/* MMCカード							*/
#define	FS_FLASH_CLASS				4			/* Flash ROM							*/
/*****	FDC情報						****/
#define	FS_FAT16					1			/* FATの種別(FAT16:1,FAT12=2)			*/
#define	FS_FAT12					2			/* FATの種別(FAT16:1,FAT12=2)			*/
#define	FS_UNKNOWN					8			/* FAT12,FAT16以外						*/
/****	MOUNT情報					****/
#define	FS_UNMOUNTSTATE				1			/* unmount状態							*/
#define	FS_MOUNTSTATE				2			/* mount状態							*/
/****	領域区分					****/
#define	FS_NORMAL_AREA				1			/* 通常領域								*/
#define FS_EXTRA_AREA				2			/* 認証領域								*/
#define FS_NOTUSE_AREA				3			/* FATキャッシュ未使用領域用			*/
/****	データ有無区分				****/
#define	FS_DataOfMBR				1			/* MBRが存在する						*/
#define	FS_DataOfFDC				2			/* FDCが存在する						*/
#define	FS_DataOfExtendedFDC		4			/* Extended FDCが存在する				*/
/****	FATメモリ管理				****/
#define FS_FAT_ONMEMORY				1			/* FATをすべてメモリに保持				*/
#define FS_FAT_OFFMEMORY			2			/* FATキャッシュ使用					*/
/****	FATテーブル					****/
#define	FS_FAT1						1			/* FAT1データ							*/
#define	FS_FAT2						2			/* FAT2データ							*/
/****	FATキャッシュモード			****/
#define FS_FAT_CACHE_NECESSARY_BLOCK	0x0004	/* FATcache実現の為に必要なBLOCK数		*/
#define FS_FAT_CACHE					0x0001	/* FAT is cache							*/
#define FS_FAT_NOCACHE					0x0002	/* FAT is no cache						*/
#define	FS_FAT_READ_MASK				0x0f00	/* FAT読込み用マスク					*/
#define	FS_FAT_NOREAD					0x0000	/* FAT読込み要求なし					*/
#define	FS_FAT_READ						0x0100	/* FAT読込み要求あり			 　		*/
/****	メディアサイズ				****/
#define	FS_FAT12_FAT16_BORDER_CLUSTERS	4085	/* FAT12最大データエリアサイズ(クラスタ)*/
#define	FS_FAT12_BORDER_SECTORPERFAT	  12	/* FAT12:クラスタ4085のSectorPerFAT		*/
#define	FS_FAT16_BORDER_SECTORPERFAT	  16	/* FAT16:クラスタ4085のSectorPerFAT		*/
/****	サポートクラスタ			****/
#define	FS_SUPPORT_SECTORPERCLUSTER_1	 1		/* サポートクラスタ 512B 				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_2	 2		/* サポートクラスタ  1KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_3	 4		/* サポートクラスタ  2KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_4	 8		/* サポートクラスタ  4KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_5	16		/* サポートクラスタ  8KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_6	32		/* サポートクラスタ 16KB				*/
#define	FS_SUPPORT_SECTORPERCLUSTER_7	64		/* サポートクラスタ 32KB				*/
/****	ファイルシステム情報構造体	****/
#define FS_SECTOR_SIZE					512		/* セクタサイズ							*/
#define FS_NUMBER_OF_FAT				2		/* FAT数								*/
#define	FS_ROOTDIR_ITEM_SIZE			32		/* ルートディレクトリ項目サイズB		*/
#define FS_START_NUMBER_OF_CLUSTER		2		/* クラスタ先頭番号						*/
#define FS_LOGICAL_SECTORPERCLUSTER	(FS_LOGICAL_CLUSTER_SIZE/FS_SECTOR_SIZE)
												/* 論理クラスタサイズ :セクタ数			*/
/****	ディレクトリ関連			****/
#if FS_FAT_TYPE == FS_SET_VFAT
#define	FS_MAX_PATHNAME_LEN				259		/* LFNファイルパス名					*/
#else
#define	FS_MAX_PATHNAME_LEN				63		/* ファイルパス名						*/
#endif


/*****	FAT固有値用定数				****/
/*****	MBR-PTオフセット			****/
#define	FS_OFFSET_MBR_RELATIVE_SECTORS	454		/* 相対セクタ数オフセット				*/
#define	FS_OFFSET_MBR_TOTAL_SECTORS		458		/* 総セクタ数オフセット					*/
/****	FDCオフセット				****/
#define	FS_OFFSET_TOTALSECTORS			19		/* ディスク総セクタ数オフセット			*/
#define	FS_OFFSET_SECTORSPERFAT			22		/* 1FAT当たりのセクタ数					*/
#define	FS_OFFSET_EXTTOTALSECTORS		32		/* 大容量ディスク総セクタ数オフセット	*/
/****	FAT種別						****/
#define	FS_FAT12D				"FAT12   "		/* FAT12 FDC.予約(8byteまで)			*/
#define	FS_FAT16D				"FAT16   "		/* FAT12 FDC.予約(8byteまで)			*/
#define	FS_FAT32D				"FAT32   "		/* FAT32 FDC.予約(8byteまで)			*/
/****	ディレクトリ情報構造体		****/		/* 属性									*/
#define	FS_ATR_NOR					0x00		/* ノーマル・ファイル					*/
#define	FS_ATR_ROL					0x01		/* 読み出し専用ファイル					*/
#define	FS_ATR_HID					0x02		/* 隠されたファイル						*/
#define	FS_ATR_SYS					0x04		/* システム・ファイル					*/
#define	FS_ATR_VOL					0x08		/* ボリューム・ラベル					*/
#define	FS_ATR_DIR					0x10		/* サブ・ディレクトリ					*/
#define	FS_ATR_ARC					0x20		/* アーカイブ属性						*/
#define	FS_ATR_LNG					0x0F		/* ロングファイル名						*/
/****	FAT情報構造体				****/		/* クラスタ番号							*/
#define	FS_FAT16_FUTURE_CLU			0xFFF6		/* FAT16:将来の為の確保クラスタ			*/
#define	FS_FAT12_FUTURE_CLU			0x0FF6		/* FAT12:将来の為の確保クラスタ			*/
#define	FS_FAT16_ERR_CLUSTER		0xFFF7		/* FAT16:欠陥クラスタ					*/
#define	FS_FAT12_ERR_CLUSTER		0x0FF7		/* FAT12:欠陥クラスタ					*/
#define	FS_FAT16_LAST_FILE_CLU		0xFFF8		/* FAT16:ファイル最終クラスタ			*/
#define	FS_FAT12_LAST_FILE_CLU		0x0FF8		/* FAT12:ファイル最終クラスタ			*/
#define	FS_FAT16_LAST_CLUSTER		0xFFFF		/* FAT16:最終クラスタ					*/	
#define	FS_FAT12_LAST_CLUSTER		0x0FFF		/* FAT12:最終クラスタ					*/
#define	FS_E_FAT_ERR_CLUSTER		0xFFF7		/* FAT:欠陥クラスタ						*/
#define	FS_E_FAT_NG_IN_CLUSTER		0xFFFD		/* FAT:指定クラスタが無効				*/
#define	FS_E_FAT_NG_GET_CLUSTER		0xFFFE		/* FAT:獲得クラスタが無効				*/
#define	FS_E_FAT_LAST_CLUSTER		0xFFFF		/* FAT:最終クラスタ						*/
/****	ファイル情報構造体			****/
/****	オープン属性	　　　		****/
#define	FS_FILE_NON					0x00		/* 未使用								*/
#define	FS_FILE_DEL					0xE5		/* 消去									*/
#define	FS_FILE_DIR					0x2E		/* 「.」 or 「..」						*/
/****	関数の引数用定数			****/
/****	編集機能用定数				****/
#define	FS_SP_NO_COPY				1			/* コピークラスタを作らずに分割する		*/
#define	FS_SP_COPY					2			/* コピークラスタを作成して分割する		*/
#define	FS_M_NORMAL					1			/* データの比較チェックなし				*/
#define	FS_M_COMPARE				2			/* データの比較チェックあり				*/
/****	Chdir用定数					****/
#define	FS_CUR_NO_RELATION			1			/* カレント位置は探索エントリと無関係	*/
#define	FS_CUR_OWN					2			/* カレント位置が探索エントリ自身		*/
#define	FS_CUR_ANCESTOR				3			/* カレント位置が探索エントリの祖先		*/
/****	カード定数					****/
#define	FS_READ_ACCESS				0x1000		/* read									*/
#define	FS_WRITE_ACCESS				0x2000		/* write								*/
/****	ファイル属性情報			****/
#define	FS_A_CLEAR					FS_ATR_NOR	/* 属性のクリア							*/
#define	FS_A_RDONLY					FS_ATR_ROL	/* 属性＝読み取り専用					*/
#define	FS_A_HIDDEN					FS_ATR_HID	/* 属性＝隠しファイル					*/
#define FS_A_SYSTEM					FS_ATR_SYS	/* 属性＝システムファイル				*/
#define FS_A_ARCHIVE				FS_ATR_ARC	/* 属性＝アーカイブ属性					*/
#define FS_A_DIR					FS_ATR_DIR	/* 属性＝ディレクトリ					*/
/****	オープン属性				****/
#define	FS_O_RDONLY					0x0001		/* 読み込み専用							*/
#define	FS_O_WRONLY					0x0002		/* 書き込み専用							*/
#define	FS_O_RDWR					0x0004		/* 読み書き両方							*/
#define	FS_O_APPEND					0x0100		/* 追記									*/
#define	FS_O_CREAT					0x0200		/* 新規作成								*/
#define	FS_O_EXCL					0x0400		/* 新規作成（既存時エラー）				*/
#define	FS_O_TRUNC					0x0800		/* 既存ファイルの作り直し				*/
/**** 電源断時Open前戻す属性を追加するため変更 ****/
#if FS_POWREC_SUPPORT == FS_POWREC
#define	FS_O_NOT_USE				0xE0F8		/* 未使用open属性						*/	
#else
#define	FS_O_NOT_USE				0xF0F8		/* 未使用open属性						*/
#endif
/****	シーク定数					****/
#define	FS_S_SET					1			/* オフセットをファイル先頭				*/
#define	FS_S_CUR					2			/* オフセットを現在ポインタ				*/
#define	FS_S_END					4			/* オフセットをファイル終わり			*/
/****	フォーマット定数			****/
#define	FS_F_ALL					0x01		/* 通常フォーマット						*/
#define	FS_F_QUICK					0x02		/* クイックフォーマット					*/
/****	その他フラグ				****/
#define	FS_GET_CLUSTER				0x00		/*  ファイル先頭クラスタの獲得要求		*/
/****	メディアへの情報更新要求	****/		/* to close								*/
#define	FS_SET_MODIFYFLAG			0x01		/* 情報更新要求の設定					*/
#define	FS_CLR_MODIFYFLAG			0x00		/* 情報更新要求の初期化					*/
/****	次クラスタの獲得関連データ	****/
#define	FS_CLUSTER_NG				0x01		/* 不当なクラスタ値						*/
#define	FS_CLUSTER_NOT_USED			0x00		/* 空きクラスタ値						*/
/****	mountチェックコード			****/
/****	フォーマット確認レベル		****/
#define	CHECK_LEVEL_FATAL			1			/* 録再不可チェックレベル				*/
#define	CHECK_LEVEL_SD				2			/* SD規格チェックレベル					*/
#define	CHECK_LEVEL_ISO				4			/* ISO規格チェックレベル				*/
/****	フォーマットエラー区分		****/
#define	FS_RW_FATAL					1			/* 録再不可								*/
#define	FS_VIOLATION_SD				2			/* SD Card Specification違反			*/
#define	FS_VIOLATION_ISO			4			/* ISO違反								*/
#define	FS_FAT_CACHE_MODE			8			/* FAT Cacheモード有効状態				*/
/****	メディア有無判定			****/
#define FS_MEDIA_INFO_INIT			0xFFFF		/* レジスタの初期値						*/
#define	FS_MEDIA_INFO_EXIST			0xE000		/* カード判別ビット(検出したら1)		*/
#define	FS_MEDIA_SD					0x8000		/* SDカード判別ビット(検出したら1)		*/
#define	FS_MEDIA_MMC				0x4000		/* MMCカード判別ビット(検出したら1)		*/
#define	FS_MEDIA_FLASH				0x2000		/* FLASH判別ビット(検出したら1)			*/
#define FS_MEDIA_NOEXIST			0x0400		/* メディアが存在しないことを示す		*/
/****	mountチェックコード			****/
#define FS_MBR_BOOT_INDICATOR1		0x80		/* ブートインジケータ	 				*/
#define FS_MBR_BOOT_INDICATOR2		0x00		/* ブートインジケータ 					*/
#define FS_MBR_PARTITION_TABLE		0x00		/* パーティションテーブル				*/
#define FS_MBR_TOTAL_SECTORS1		32680		/* 総セクタ数 32680 					*/
#define FS_MBR_TOTAL_SECTORS2		65536		/* 総セクタ数 65536 					*/
#define FS_MBR_SYSTEM_ID1			1			/* System ID 							*/
#define FS_MBR_SYSTEM_ID2			4			/* System ID 							*/
#define FS_MBR_SYSTEM_ID3			6			/* System ID 							*/
#define FS_SIGNATURE_WORD1			0x55		/* シグニチャワード1 					*/
#define FS_SIGNATURE_WORD2			0xaa		/* シグニチャワード2 					*/
#define FS_FDC_JUMP_EB				0xeb		/* Jump Command 0xeb					*/
#define FS_FDC_JUMP_E9				0xe9		/* Jump Command 0xe9		 			*/
#define FS_FDC_JUMP_90				0x90		/* Jump Command 0x90 					*/
#define FS_FDC_RESERVED_SECTOR_COUNT	1		/* 予約セクタ数 						*/
#define FS_FDC_NUMBER_OF_ROOT_ENTRIES	512		/* ルートディレクトリエントリの数		*/
#define FS_FDC_MEDIUM_IDENTIFIER		0xf8	/* メディアディスクリプタ 				*/
#define FS_FDC_PHYSICAL_DISK_NUMBER		0x80	/* 物理ドライブ番号 					*/
#define FS_FDC_RESERVED					0x00	/* Reserved 							*/
#define FS_FDC_EXTENDED_BOOT_RECORD_SIGNATURE	0x29	/* 拡張ブートレコード記号		*/
#define FS_FDC_RESERVED_FUTURE			0x0000	/* 予約 								*/
#define FS_FAT_FARST_BYTE				0xF8	/* FATの先頭データ 						*/
#define FS_FAT_SECOND_BYTE				0xFF	/* FATの2byte目データ 					*/
/* Sectors per Cluster and Boundary Unit Recommendation 
												and CHS Recommendationチェックデータ	*/
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
/****	エラーコード				****/	
#define FS_E_SUCCESS				0				/* 成功								*/
#define	FS_E_CHECK_MASK				0xFF00			/* エラーベースマスク用データ		*/
#define	FS_E_BASE					0xA000			/* FS エラーベースコード			*/
#define FS_E_DRIVE_NOT_AVAILABLE	FS_E_BASE+0x01	/* 未：利用可能なドライブがない		*/
#define FS_E_DEVICE_ALREADY_MOUNTED	FS_E_BASE+0x02	/* 既にマウント状態である　			*/
#define FS_E_DEVICE_NOT_MOUNTED		FS_E_BASE+0x03	/* マウントされていない				*/
#define FS_E_TOO_MANY_OPEN_FILES	FS_E_BASE+0x04	/* ファイルをオープンしすぎ			*/
#define FS_E_DEVICE_NON				FS_E_BASE+0x05	/* 未：デバイスが見つからない		*/
#define FS_E_FILE_NOT_TYPE			FS_E_BASE+0x06	/* ファイルタイプが異なる/不適合	*/
#define FS_E_FILE_NOT_FOUND			FS_E_BASE+0x07	/* ファイルが見つからない			*/
#define FS_E_FILE_NOT_OPENED		FS_E_BASE+0x08	/* ファイルがオープンしていない		*/
#define FS_E_FILE_OPENED			FS_E_BASE+0x09	/* ファイルがオープンしている		*/
#define FS_E_BAD_FILE_TYPE			FS_E_BASE+0x0a	/* 未：Openファイルと種類が違う		*/
#define FS_E_BAD_OPEN_FLAG			FS_E_BASE+0x0b	/* Openの方法が実行を妨げている		*/
#define	FS_E_BAD_VARIABLES			FS_E_BASE+0x0c	/* 変数/引数の値がおかしい			*/
#define FS_E_NOT_ENOUGH_MEMORY		FS_E_BASE+0x0d	/* メモリ不足						*/
#define FS_E_CANNOT_ACCESS_DEVICE	FS_E_BASE+0x0e	/* デバイスにローアクセス不可		*/
#define FS_E_DIR_NOT_FOUND			FS_E_BASE+0x0f	/* ディレクトリが見つからない		*/
#define FS_E_CHILD_FILE_FOUND		FS_E_BASE+0x10	/* ディレクトリの中身が空でない		*/
#define FS_E_SAME_FILENAME			FS_E_BASE+0x11	/* 同一ファイル名が存在する			*/
#define FS_E_DEVICE_CAPACITY_FULL	FS_E_BASE+0x12	/* デバイスの容量がFull Busy		*/
#define FS_E_OVER_MAX_DEPTH			FS_E_BASE+0x13	/* ディレクトリ深さが最大値Over		*/
#define FS_E_DETECTED_EOF			FS_E_BASE+0x14	/* EOFの検出						*/
#define FS_E_ALREADY_EOF			FS_E_BASE+0x15	/* 既にEOFを検出					*/
#define FS_E_DEVICE_TYPE			FS_E_BASE+0x16	/* デバイス領域が間違っている		*/
#define FS_E_PATHNAME_LEN			FS_E_BASE+0x17	/* パス名サイズオーバー				*/
#define FS_E_SAME_FILE_OPEN			FS_E_BASE+0x18	/* 排他オープンエラー				*/
#define FS_E_END_OF_FILE			FS_E_BASE+0x19	/* 未：ファイルの終端を検出			*/
#define FS_E_DISC_NOT_FORMAT		FS_E_BASE+0x1a	/* フォーマットされていない			*/
#define FS_E_DISC_RW_FATAL			FS_E_BASE+0x1b	/* 未：録再不可メディア				*/
#define FS_E_DISC_VIOLATION_ISO		FS_E_BASE+0x1c	/* ISD規格違反						*/
#define FS_E_DISC_VIOLATION_SD		FS_E_BASE+0x1d	/* SD規格違反						*/
#define FS_E_PARAMETER_CANNOT_FIX	FS_E_BASE+0x1e	/* Format時のパラメータ計算失敗		*/
#define FS_E_FAT_WRITE_ERROR		FS_E_BASE+0x1f	/* 未：Format時のFAT書込み計算ミス	*/
#define FS_E_BAD_NORMAL_AREA		FS_E_BASE+0x20	/* 未：通常領域がMCAP用でない		*/
#define	FS_E_ASYNC					FS_E_BASE+0x21	/* 非同期I/O 要求エラー				*/
#define FS_E_ACROSS_EOF				FS_E_BASE+0x22	/* 未：アクセス領域がEOFを含む		*/
#define FS_E_OVEROFFS				FS_E_BASE+0x23	/* アクセス領域がサイズ以上(EOF)	*/
#define FS_E_FDCTBL					FS_E_BASE+0x24	/* 未：FDC Table異常				*/
#define FS_E_FATTBL					FS_E_BASE+0x25	/* 未：FAT Table異常				*/
#define FS_E_FATTBLFULL				FS_E_BASE+0x26	/* 未：FAT Table Full				*/
#define FS_E_ATTRIBUTE				FS_E_BASE+0x27	/* ファイル属性エラー			
												     ファイルとディレクトリの種別エラー	*/
#define FS_E_BAD_OFFSET				FS_E_BASE+0x28	/* オフセット値が異常				*/
#define FS_E_BROKEN_FAT				FS_E_BASE+0x29	/* FATが壊れている					*/
#define FS_E_CANNOT_FIND_ENTRY		FS_E_BASE+0x2a	/* エントリの獲得失敗				*/
#define FS_E_NOT_MATCH				FS_E_BASE+0x2b	/* 名前が一致しない					*/
#define	FS_E_BAD_FILENAME			FS_E_BASE+0x2c	/* 不当なファイル名					*/
#define	FS_E_FS_ERROR				FS_E_BASE+0x2d	/* FSの内部的なエラー				*/
#define	FS_E_DIR_NOT_OPENED			FS_E_BASE+0x2e	/* directoryはオープンしていない	*/
#define	FS_E_DIR_OPENED				FS_E_BASE+0x2f	/* directoryはオープンしている		*/
#define	FS_E_END_OF_DIR				FS_E_BASE+0x30	/* directoryの終端である			*/
#define	FS_E_CANNOT_SEEK_DIR		FS_E_BASE+0x31	/* 未：directoryのシークに失敗		*/
#define FS_E_BROKEN_ENTRY			FS_E_BASE+0x32	/* エントリが壊れている				*/
#define FS_E_CANNOT_RESIZE_FILE		FS_E_BASE+0x33	/* ファイルサイズの変更不可能		*/
#define	FS_E_BAD_PARTITION_SIZE		FS_E_BASE+0x34	/* パーティション長が不適切			*/
#define FS_E_INVALID_ID_DEV_INFO	FS_E_BASE+0x35  /* 未：IdentifyDriveパラメータ異常	*/
#define FS_E_SEM_ERROR				FS_E_BASE+0x36  /* セマフォエラー					*/
#define FS_E_NO_CARD				FS_E_BASE+0x37  /* メディアが存在しない				*/
#define	FS_E_TOO_MANY_E_OPEN_FILES	FS_E_BASE+0x38  /* 編集:ファイルオープン数の確保不可*/
#define FS_E_BOUNDARY				FS_E_BASE+0x39  /* クラスタサイズの倍数長でない		*/
#define FS_E_NO_MERGE				FS_E_BASE+0x40  /* 分割された同一ファイルでない		*/
#define FS_E_INVALID_DATE			FS_E_BASE+0x41  /* 日付情報が不正					*/
#define FS_E_CONFIG_ERROR			FS_E_BASE+0x42  /* FS_config.h設定値エラー			*/
#define FS_E_DRIVER_IO_ERROR		FS_E_BASE+0x43  /* ドライバI/Oエラー				*/
#define FS_E_DISC_V_ISO_FAT_CACHE	FS_E_BASE+0x44	/* ISD規格違反 + FAT CACHE MODE		*/
#define FS_E_DISC_V_SD_FAT_CACHE	FS_E_BASE+0x45	/* SD規格違反  + FAT CACHE MODE		*/
#define FS_E_DISC_FAT_CACHE			FS_E_BASE+0x46	/* FAT CACHE MODE					*/
/* <Dolphin> Add for Dolphin */
#ifdef DOLPHIN_SDFS
#define FS_E_SOFTERR				FS_E_BASE+0x47 	/* SOFT Error 			*/ 
#endif
/* <Dolphin> Add End */
/* 電源断関連エラーコード		*/
#define	FS_E_REQ_CHK_RECOVERY		FS_E_BASE+0x50	/* リカバリ情報あり								*/
#define	FS_E_REQ_NOR_RECOVERY		FS_E_BASE+0x51	/* 通常リカバリ情報あり、SDカード一致			*/
#define	FS_E_REQ_EXT_RECOVERY		FS_E_BASE+0x52	/* 認証リカバリ情報あり、SDカード一致			*/
#define	FS_E_REQ_BOTH_RECOVERY		FS_E_BASE+0x53	/* 通常・認証リカバリ情報あり、SDカード一致		*/
#define	FS_E_REQ_NOR_CHANGE_SD		FS_E_BASE+0x54	/* 通常リカバリ情報あり、SDカード不一致			*/
#define	FS_E_REQ_EXT_CHANGE_SD		FS_E_BASE+0x55	/* 認証リカバリ情報あり、SDカード不一致			*/
#define	FS_E_REQ_BOTH_CHANGE_SD		FS_E_BASE+0x56	/* 通常・認証リカバリ情報あり、SDカード不一致	*/
#define	FS_E_REQ_NOR_INSERT_SD		FS_E_BASE+0x57	/* 通常リカバリ情報あり、SDカードなし			*/
#define	FS_E_REQ_EXT_INSERT_SD		FS_E_BASE+0x58	/* 認証リカバリ情報あり、SDカードなし			*/
#define	FS_E_REQ_BOTH_INSERT_SD		FS_E_BASE+0x59	/* 通常・認証リカバリ情報あり、SDカードなし		*/
/* VFAT関連エラーコード			*/
#define	FS_E_NO_OPEN				FS_E_BASE+0x70	/* オープンなし						*/
#define	FS_E_SAME_OPEN				FS_E_BASE+0x71	/* 自分自身がオープン状態			*/
#define	FS_E_PARENT_OPEN			FS_E_BASE+0x72	/* 直親ディレクトリがオープン状態	*/
#define	FS_E_OLD_OPEN				FS_E_BASE+0x73	/* 祖先ディレクトリがオープン状態	*/
#define	FS_E_NEW_OPEN				FS_E_BASE+0x74	/* 子孫ディレクトリがオープン状態	*/
/* FLASH関連エラーコード */
#define	FS_E_F_BASE					0xA100				/* フラッシュ エラーベースコード*/
#define	FS_E_FLASH_INIT_FALSE		FS_E_F_BASE+0x01	/* フラッシュ初期化失敗			*/
#define	FS_E_FLASH_NO_DEVICE		FS_E_F_BASE+0x02	/* メディアを認識できない		*/
#define	FS_E_FLASH_OVER_POOL_SIZE	FS_E_F_BASE+0x03	/* フラッシュPOOLサイズオーバー	*/
#define	FS_E_FLASH_NOT_VBF_FORMAT	FS_E_F_BASE+0x04	/* VBF未フォーマット			*/
#define	FS_E_FLASH_VBF_FORMAT_FALSE	FS_E_F_BASE+0x05	/* VBFフォーマット実行失敗		*/
#define	FS_E_FLASH_VBF_MOUNT_FALSE	FS_E_F_BASE+0x06	/* VBFマウント失敗				*/
#define	FS_E_FLASH_IO_ERROR			FS_E_F_BASE+0x07	/* 読み込み/書き込みに失敗		*/
#define	FS_E_FLASH_GARBAGE_FALSE	FS_E_F_BASE+0x08	/* ガーベジコレクト実行失敗		*/


/**** I/Oバッファサイズ ****/
/* read/write等のファイルI/Oに使用するバッファのバイトサイズを設定						*/
/*  ( FS_LOGICAL_CLUSTER_SIZE ) = 2KB * n      ( n = 1,2,3,...8)						*/
/* ＠16KB指定を推奨、他の設定値での動作は未確認											*/
#define FS_LOGICAL_CLUSTER_SIZE		16384							/* デフォルト値		*/


/**** ３．オープンファイル数 ****/
/* 最大同時オープンできるファイル数を設定												*/
/* 　1 =< ( FS_MAX_OF_NOR_OPEN ) =< 5													*/
/* 　1 =< ( FS_MAX_OF_EXT_OPEN ) =< 5													*/
/* 　FS_MAX_OF_OPEN  = MAX(FS_MAX_OF_NOR_OPEN,FS_MAX_OF_EXT_OPEN)						*/
/*																						*/
#define	FS_MAX_OF_OPEN	((FS_MAX_OF_NOR_OPEN>FS_MAX_OF_EXT_OPEN)? FS_MAX_OF_NOR_OPEN:FS_MAX_OF_EXT_OPEN)


/**** ４．オープンディレクトリ数 ****/
/* 最大同時オープンできるディレクトリ数を設定											*/
/* 　通常領域：1 =< ( FS_MAX_NOR_OPEN_DIR ) =< 3										*/
/* 　認証領域：1 =< ( FS_MAX_EXT_OPEN_DIR ) =< 3										*/
/*	 FS_MAX_OPEN_DIR  = MAX(FS_MAX_NOR_OPEN_DIR,FS_MAX_EXT_OPEN_DIR)					*/
/*																						*/
#define FS_MAX_OF_OPEN_DIR	((FS_MAX_OF_NOR_OPEN_DIR>FS_MAX_OF_EXT_OPEN_DIR)? FS_MAX_OF_NOR_OPEN_DIR:FS_MAX_OF_EXT_OPEN_DIR)												/* デフォルト値	*/


/**** ５．ディレクトリの最大階層数　****/
/* ディレクトリの最大階層数を設定														*/
/*　通常領域：1 =< ( FS_MAX_NOR_DEPTH ) =< 8											*/
/*　認証領域：1 =< ( FS_MAX_EXT_DEPTH ) =< 8											*/
/*	FS_MAX_DEPTH  = MAX(FS_MAX_NOR_DEPTH,FS_MAX_EXT_DEPTH)								*/
/* ＠ルートは階層１																		*/
#define	FS_MAX_DEPTH ((FS_MAX_NOR_DEPTH>FS_MAX_EXT_DEPTH)? FS_MAX_NOR_DEPTH:FS_MAX_EXT_DEPTH)
																		/* デフォルト値	*/

/**** DOS名フルパスサイズ用マクロ ****/
/* DOS名フルパスサイズ(13×階層(最大階層数))を返す 但し、259を超える場合は259固定 */
#define	FS_DOS_PATH_LEN_MIN()	(((FS_MAX_DEPTH*13)>259)? 259:(FS_MAX_DEPTH*13))



/*
 *	メンテナンスコマンド用定義
 */

/******** サポート動作モード ********/
#define FS_FC_CHECK			0x0001					/* フォーマットのチェックのみ行う	*/
#define FS_FC_ENT_RESTORE	0x0002					/* FAT,ディレクトリエントリ異常個所の
																		修復のみ行う	*/
#define FS_FC_ISO_RESTORE	0x0004					/* ISO規格違反部分をすべて修復する	*/
#define FS_FC_SD_RESTORE	0x0008					/* SD規格違反部分をすべて修復する	*/

/******** 修復可否判定ビット ********/
#define FS_FC_ENT_BIT		0x0001					/* エントリ異常修復BIT				*/
#define FS_FC_ISO_BIT		0x0002					/* ISO規格違反修復BIT				*/
#define FS_FC_SD_BIT		0x0004					/* SD規格違反修復BIT				*/

/******** フォーマット異常通知用エラーコード ********/
/**** システム領域エラーレベル1(重度のエラー：フォーマット推奨) ****/
/* 修復不能な重度のエラー(formatを推奨) */
#define FS_FC_MBR_FATAL_E	0x00000001				/* MBRが壊れている					*/
#define FS_FC_FDC_FATAL_E	0x00000002				/* FDCが壊れている					*/

/**** システム領域エラーレベル2(中度のエラー：修復しないが使用可能) ****/
/** FS_FC_SD_RESTORE,FS_FC_ISO_RESATOREで修正しない軽度のエラー **/
#define FS_FC_MBR_ISO1_E	0x00000010				/* MBRが壊れている					*/
#define FS_FC_FDC_ISO1_E	0x00000020				/* FDCが壊れている					*/
/** FS_FC_SD_RESTOREで修正しない軽度のエラー **/
#define FS_FC_MBR_SD1_E		0x00000040				/* MBRがSD規格に違反している		*/
#define FS_FC_FDC_SD1_E		0x00000080				/* FDCがSD規格に違反している		*/

/**** システム領域エラーレベル3(軽度のエラー：修復可能) ****/
/** FS_FC_SD_RESTORE,FS_FC_ISO_RESATOREで修正する軽度のエラー **/
#define FS_FC_MBR_ISO2_E	0x00000100				/* MBRが壊れている					*/
#define FS_FC_FDC_ISO2_E	0x00000200				/* FDCが壊れている					*/
/** FS_FC_SD_RESTOREで修正する軽度のエラー **/
#define FS_FC_MBR_SD2_E		0x00000400				/* MBRがSD規格に違反している		*/
#define FS_FC_FDC_SD2_E		0x00000800				/* FDCがSD規格に違反している		*/

/**** その他のエラー ****/
#define FS_FC_FAT_E			0x00001000		/* FATテーブルが壊れている(修復可能)		*/
#define FS_FC_ENT_E			0x00002000		/* ディレクトリエントリ壊れている(修復可能)	*/
#define FS_FC_SD_PARAM_E	0x00004000		/* フォーマットパラメータがSD規格に違反している
											(修復しないがシステムによっては使用可能)	*/

/******** FormatCheck用定数 ********/
#define	FS_FC_MAX_LEVEL		128				/* 最大探索階層数(root=0)					*/

/****	オープン属性				****/
#define		FS_O_EXT_MODE		0x1000		/* 認証領域Openモード(電源断時Open前に戻す)	*/

/**** Multi Drive関連定義　****/
#define	FS_SD_DRIVE_MAX			2						/* サポートSD Drive最大数	*/
#define	FS_FLASH_DRIVE_MAX		1						/* サポートFlash Drive最大数*/
#define	FS_MAX_OF_DRIVE	((FS_SD_DRIVE_MAX>FS_FLASH_DRIVE_MAX)? FS_SD_DRIVE_MAX:FS_FLASH_DRIVE_MAX)
														/* サポートドライブ最大数	*/
#define	FS_MAX_DRIVE_NO		FS_MAX_OF_DRIVE	- 1			/* 最大Drive No.			*/
#define	FS_NONE_DRIVE		0x0000						/* None Drive				*/
#define	FS_NONE_PATH		"NONE_PATH"					/* None Path				*/
#define	FS_DRIVE_MASK		0x0f00						/* サポートドライブマスク値	*/
/**** Drive初期化情報 ****/
#define	FS_NOTCOMPLETE_INIT			1					/* FS_init未完了状態		*/					
#define	FS_COMPLETE_INIT			2					/* FS_init完了状態			*/
#define	FS_NOTCOMPLETE_CARDINIT		1					/* FS_cardinit未完了状態	*/
#define	FS_COMPLETE_CARDINIT		2					/* FS_cardinit完了状態		*/
#define	FS_NOTCOMPLETE_S2LINIT		1					/* FS_s2linit未完了状態		*/
#define	FS_COMPLETE_S2LINIT			2					/* FS_s2linit完了状態		*/

/**** VFAT関連define ****/
#define	DOUBLE_TO_DOUBLE			1					/* Path名連結モード 2byte code + 2byte code */
#define	DOUBLE_TO_CHAR				2					/*                  2byte code + 1byte code */
#define	CHAR_TO_DOUBLE				3					/*                  1byte code + 2byte code */
#define	CHAR_TO_CHAR				4					/*					1byte code + 1byte code */
#define	FS_MAX_LONGNAME_LEN			255					/* LFN最大ファイル名長(byte)				*/

/**** LFN処理 Unicode→SJIS変換テーブル使用を設定 ****/
/*
 *  Unicode→SJIS変換テーブルを使用する場合、USE_UNI_TO_SJIS_TBLを定義する。
 *  Unicode→SJIS変換テーブルを使用しない場合、USE_UNI_TO_SJIS_TBLを定義しない。
 */
/*
#define	USE_UNI_TO_SJIS_TBL
*/

/**** ドライブ選択関数関連define ****/
#define		MASK_PORT_NO		0x00FF					/* ポート番号抽出マスク 	*/
#define		FS_SHIFT8			8						/* 8bitシフト				*/

/**** FLASH関連define ****/
#define		D_MAX_UINT						0xFFFF
#define		MAX_UINT_ACCESS					( D_MAX_UINT - VBF_BLOCK_SIZE + 1 )

#define		FS_FLASH_BIT					0x2000
#define		FS_NOT_MEDIA_BIT				0x0020

#endif
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
