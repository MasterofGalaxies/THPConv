/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/
/*=======================================================================================
$System	   	SD Embedded System
$Subsystem	File System
$Filename	fs_fsio.h
$Version	3.03
$Author		MSE M.O, DNC T.M
$Checker	MSE M.O, Y.K
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
$ 2002. 7.30	:V.3.03	SDTerm 追加												MSR
========================================================================================*/

#ifndef __FS_FSIO_H__
#define __FS_FSIO_H__


/******** 関数プロトタイプ宣言 ********/
/**** ファイルシステム操作関数 ****/
extern UINT16	FS_Init( void(*func1)(void), void(*func2)(void), UINT16 fsDriveNo );
extern UINT16	FS_Mount( FS_DRIVE **dp, UINT16 fsDriveNo );
extern UINT16	FS_ExtMount( FS_DRIVE **dp, UINT16 MKB_ID, UINT16 fsDriveNo );
extern UINT16	FS_Umount( FS_DRIVE *dp );
extern UINT16	FS_ExtUmount( FS_DRIVE *dp, UINT16 MKB_ID );
extern UINT16	FS_Getfs( FS_DRIVE *dp, FS_FS *fsp );
extern UINT16	FS_ExtGetfs( FS_DRIVE *dp, FS_FS *fsp, UINT16 MKB_ID );
extern UINT32	FS_GetR1Status( UINT16 fsDriveNo );
extern UINT16	FS_ChangeSA( UINT32 ext_size, UINT16 MKB_ID, UINT16 fsDriveNo );

#ifndef FS_DEBUG
extern UINT16	FS_Format( void *volumename, UINT16 mode, UINT16 fsDriveNo );
extern UINT16	FS_ExtFormat( void *volumename, UINT16 mode, UINT16 MKB_ID, UINT16 fsDriveNo );
#else
extern UINT16	FS_Format( void *volumename, UINT16 mode, UINT16 cluster_size,
				 UINT32 volume_size, UINT16 card_size, UINT16 fat_mode, UINT16 fsDriveNo );
extern UINT16	FS_ExtFormat
				( void *volumename, UINT16 mode, UINT16 cluster_size,
				 UINT32 volume_size, UINT16 card_size, UINT16 fat_mode, UINT16 MKB_ID,
				 UINT16 fsDriveNo );
#endif
extern UINT16	FS_Sync( FS_DRIVE *dp );
extern UINT16	FS_ExtSync( FS_DRIVE *dp, UINT16 MKB_ID );

/**** ファイルI/O関数 ****/
extern UINT16	FS_Open
				( FS_DRIVE *dp, FS_FILE **fp, void *filename, UINT16 open_flag );
extern UINT16	FS_ExtOpen
				( FS_DRIVE *dp, FS_FILE **fp, void *filename, UINT16 open_flag,
				  UINT16 MKB_ID );
extern UINT16	FS_Close( FS_FILE *fp );
extern UINT16	FS_ExtClose( FS_FILE *fp );
extern UINT16	FS_Read
				( FS_FILE *fp, void *buf, UINT32 bufsize, void (*func)(), FS_INFO *info );
extern UINT16	FS_ExtRead
				( FS_FILE *fp, void *buf, UINT32 bufsize, void (*func)(), FS_INFO *info );
extern UINT16	FS_Write
				( FS_FILE *fp, void *buf, UINT32 bufsize, void (*func)(), FS_INFO *info );
extern UINT16	FS_ExtWrite
				( FS_FILE *fp, void *buf, UINT32 bufsize, void (*func)(), FS_INFO *info );
extern UINT16	FS_Seek( FS_FILE *fp, INT32 offset, UINT16 origin );
extern UINT16	FS_ExtSeek( FS_FILE *fp, INT32 offset, UINT16 origin );
extern UINT16	FS_Getpos( FS_FILE *fp, UINT32 *offset );
extern UINT16	FS_ExtGetpos( FS_FILE *fp, UINT32 *offset );
extern UINT16	FS_Seteof( FS_DRIVE *dp, void *filename, UINT32 size );
extern UINT16	FS_ExtSeteof( FS_DRIVE *dp, void *filename, UINT32 size, UINT16 MKB_ID );
extern UINT16	FS_Modify( FS_FILE *fp, void *buf, UINT32 bufsize );
extern UINT16	FS_ExtModify( FS_FILE *fp, void *buf, UINT32 bufsize );

/**** ファイル属性関数 ****/
extern UINT16	FS_Setfa( FS_DRIVE *dp, void *filename, UINT16 fileattr );
extern UINT16	FS_ExtSetfa
				( FS_DRIVE *dp, void *filename, UINT16 fileattr, UINT16 MKB_ID );
extern UINT16	FS_Getfa( FS_DRIVE *dp, void *filename, UINT16 *fileattr );
extern UINT16	FS_ExtGetfa
				( FS_DRIVE *dp, void *filename, UINT16 *fileattr, UINT16 MKB_ID );

/**** ファイル操作関数 ****/
extern UINT16	FS_Delete( FS_DRIVE *dp, void *filename );
extern UINT16	FS_ExtDelete( FS_DRIVE *dp, void *filename, UINT16 MKB_ID );
extern UINT16	FS_Rename( FS_DRIVE *dp, void *oldname, void *newname );
extern UINT16	FS_ExtRename
				( FS_DRIVE *dp, void *oldname, void *newname, UINT16 MKB_ID );
extern UINT16	FS_Split( FS_DRIVE *dp, UINT32 addr, void *filename1, 
								void *filename2, UINT16 split_mode );
extern UINT16	FS_ExtSplit( FS_DRIVE *dp, UINT32 addr, void *filename1,
								void *filename2, UINT16 split_mode, UINT16 MKB_ID );
extern UINT16	FS_Merge( FS_DRIVE *dp, void *filename1, 
												void *filename2 , UINT16 merge_mode );
extern UINT16	FS_ExtMerge( FS_DRIVE *dp, void *filename1,
								void *filename2, UINT16 merge_mode, UINT16 MKB_ID );

/**** ディレクトリ操作関数 ****/
extern UINT16	FS_Mkdir( FS_DRIVE *dp, void *dirname );
extern UINT16	FS_ExtMkdir( FS_DRIVE *dp, void *dirname, UINT16 MKB_ID );
extern UINT16	FS_Rmdir( FS_DRIVE *dp, void *dirname );
extern UINT16	FS_ExtRmdir( FS_DRIVE *dp, void *dirname, UINT16 MKB_ID );
extern UINT16	FS_Opendir( FS_DRIVE *dp, FS_DIR **dir, void *dirname );
extern UINT16	FS_ExtOpendir
				( FS_DRIVE *dp, FS_DIR **dir, void *dirname, UINT16 MKB_ID );
extern UINT16	FS_Closedir( FS_DIR *dir );
extern UINT16	FS_ExtClosedir( FS_DIR *dir );
extern UINT16	FS_Readdir( FS_DIR *dir, FS_ENTRY *ent );
extern UINT16	FS_ExtReaddir( FS_DIR *dir, FS_ENTRY *ent );
extern UINT16	FS_Seekdir( FS_DIR *dir, INT16 count, UINT16 mode );
extern UINT16	FS_ExtSeekdir( FS_DIR *dir, INT16 count, UINT16 mode );
extern UINT16	FS_Chdir( FS_DRIVE *dp, void *dirname );
extern UINT16	FS_ExtChdir( FS_DRIVE *dp, void *dirname, UINT16 MKB_ID );
extern UINT16	FS_Getwd( FS_DRIVE *dp, void *dirname );
extern UINT16	FS_ExtGetwd( FS_DRIVE *dp, void *dirname );

/**** メンテナンスコマンド関数 ****/
extern UINT16	FS_FormatCheck( UINT32 *result, UCHAR *work, UINT16 mode,
				 UINT16 size, UINT16 fsDriveNo );
extern UINT16	FS_ExtFormatCheck
				( UINT32 *result, UCHAR *work, UINT16 mode, UINT16 size,
				 UINT16 MKB_ID, UINT16 fsDriveNo );
extern UINT16	FS_GetFATSize( UINT16 *size, UINT16 fsDriveNo );
extern UINT16	FS_ExtGetFATSize( UINT16 *size, UINT16 MKB_ID, UINT16 fsDriveNo );
extern UINT16	FS_GetFCMode( void );
extern UINT16	FS_ExtGetFCMode( void );


/**** 電源断用外部関数宣言 ****/
/* リカバリチェック関連 */
extern	UINT16	FS_CheckMem( UINT16 *MKB_ID, UINT16	fsDriveNo );
/* リカバリ関連 */
extern	UINT16	FS_Recovery( UINT16 MKB_ID, UINT16 fsDriveNo );
extern	UINT16	FS_ClearRecovery( UINT16 fsDriveNo );
/* GETWI関連 */
extern	UINT16	FS_Getwi( void *filename, UINT32 *size, UINT16 fsDriveNo );
extern	UINT16	FS_ExtGetwi( void *filename, UINT32 *size, UINT16 fsDriveNo );


/**** VFAT用外部関数宣言 ****/
extern	UINT16	FS_Getdos( FS_DRIVE *dp, void *lfname, void *dname, UINT16 size );
extern	UINT16	FS_ExtGetdos
		( FS_DRIVE *dp, void *lfname, void *dname, UINT16 size, UINT16 MKB_ID );
extern	UINT16	FS_Getlfn( FS_DRIVE *dp, void *dname, void *lfname, UINT16 size );
extern	UINT16	FS_ExtGetlfn
		( FS_DRIVE *dp, void *dname, void *lfname, UINT16 size, UINT16 MKB_ID );

/**** FLASH FX用外部関数宣言 ****/
extern	UINT16	FS_Discard( UINT32 startOffset, UINT16 length, UINT16 fsDriveNo );
extern	UINT16	FS_GarbageCollect( UINT16 fsDriveNo );
extern	UINT16	FS_VBFFormat( UINT32 serialnum, UINT32 newcushin, UINT32 mediasize,
						UINT32 partitionstart, UINT32 *spareunits, UINT16 fsDriveNo );

/**** MultiDrive用外部関数宣言 ****/
extern	UINT16	FS_CardIFReset( void );

/**** Term 用外部関数宣言 ****/
extern UINT16 SDTerm( UINT16 fsDriveNo );


#endif
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/
/***** EOF *****************************************************************************/

