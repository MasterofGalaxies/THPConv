/*---------------------------------------------------------------------------*
  Project: WAD library (packaging certs/crls/eTicket/TMD/contents/meta)
  File:    wad.h

  THIS LIBRARY IS FOR INTERNAL USE ONLY

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.31  2007/05/21 23:18:19  johnc
  Added WADBackupResign to convert prod save to dev save.

  Revision 1.30  2007/05/02 20:42:45  johnc
  Added CNT library support to WAD library.  So wad files can be imported when using WAD/CNT library as a NAND application.

  Revision 1.29  2007/03/29 01:05:44  wada_jumpei
  Added WAD_IMPORT_BACKUP_ONLY option and fixed some bugs

  Revision 1.28  2007/02/21 04:29:34  wada_jumpei
  Added WAD_IMPORT_OLD_META.
  This is for systemmenu1 installing tools.

  Revision 1.27  2007/02/15 02:43:06  johnc
  Added option WAD_IMPORT_NO_TMD.
  Should always use this option during game save restore for
  correct size calculation, speed, and same behavior as old WADImportEx.
  This is necessary since backing up TMD in game save backup file.

  Revision 1.26  2007/02/15 01:26:23  johnc
  Added WAD_IMPORT_TMD_ONLY option for WADImportEx
    to allow game save restore if game never played/installed before.

  Revision 1.25  2007/02/09 01:06:28  wada_jumpei
  Added asynchronous WAD*BackupAsync.
  Added WADBackupEx and changed WADBackup for define.
  Modified backup functions' memory allocation (fixed bug).

  Revision 1.24  2007/01/29 22:58:25  johnc
  Added WADImportOption to allow signature verification ignore during game save restore.

  Revision 1.23  2007/01/27 01:29:14  johnc
  Added asynchronous WAD*ImportAsync.
  Added callback argument to WADImportEx.
  Added WAD_RESULT_FATAL_ERROR for thread errors.
  Wada added early code for optimizing import.

  Revision 1.22  2006/11/22 22:42:00  johnc
  Repair version now 1.1
  Added ability to save and transfer user-set time/date during repair disc.
  New backup format incompatible with wdb or bak format.
  So changed suffix for backup files to to rbk in repair disc code.

  Revision 1.21  2006/11/14 02:21:30  johnc
  Modifications for repair disc (#ifdef REPAIR_APP):
  -Does not impact previous WAD library functionality
  -Added WAD_BACKUP_TMD option to backup only TMD
  -First repair disc requires IOS 16 (with ES rm TMD import fix)
  -Added copyWiiC24Config setting so user-selectable.

  Revision 1.20  2006/11/02 14:15:05  johnc
  Removed calculating installed blocks/inodes since unnecessary and errors if contents are deleted.

  Revision 1.19  2006/11/01 10:33:22  johnc
  Returned more information from WADImportGetBlocks about wad file and installed TMD/contents.

  Revision 1.18  2006/10/31 10:17:45  johnc
  Added support for calculating absolute blocks for wad file import
       (depends on /shared2/succession/transfer.id)
  Added support for /notransfer directory

  Revision 1.17  2006/10/29 22:26:39  johnc
  Renamed WADSource to WADStream.
  Exposed WAD*Stream functions for general use with memory/DVD/NAND/SD
  Added WADVerify function.
  Modified WADBackupHeader to add totalSize and gameSaveTitleId.

  Revision 1.16  2006/10/24 13:42:47  johnc
  Changed WADMeta structure to include buildstamp in name, tool version, and creator.

  Revision 1.15  2006/10/19 23:00:37  johnc
  -Consolidated WADImport* type functions into WADImportEx (except for WADImportDVD*ForBS)
  -Supports all wad, bwf, wdb imports (including multiple contents, and backup)
  -Supports import from SD, NAND, DVD, and memory
  -Requires use of MEMAllocator, but uses minimal memory (normally ~64KB buffer + ~6K for certs/ticket/tmd; worst case is ~150KB)
  -WADGetTitleVersionEx supports SD, NAND, DVD, and memory with all formats.
  -WAD library now depends on FA library (for SD card).
  -More detailed error reports, showing function/line numbers.

  Revision 1.14  2006/10/14 17:15:47  wada_jumpei
  Added WADBackupNANDEx, WADImportNANDEx, _WADBackupGetFIlesEx
  for backup management with saving memory space.

  Revision 1.13  2006/09/17 06:22:39  ooizumi
  Added WADImportDVD[Ex]ForBS.

  Revision 1.12  2006/09/16 17:37:45  wada_jumpei
  Added WADImportDVDEx for big size wad file import

  Revision 1.11  2006/07/25 09:50:19  johnc
  Added WAD_RESULT_* error codes.  Error codes will still return for es, fs, ios, cert, etc.

  Revision 1.10  2006/07/20 14:41:00  johnc
  Now backs up using cidx instead of relying on TMD.
  Changed backup version to 1.
  Added WADHeader1, which uses cidx to import.
  Changed WADImport to use cidx to import if version is >= 1.

  Revision 1.9  2006/07/18 14:14:29  johnc
  Added WADMeta.  All title.met files under /meta must use this 64B header.
  WADCheckImport will check titleId and titleVersion in this meta file for proper import
  Changed some WAD_BACKUP_* defines to be more clear.

  Revision 1.8  2006/07/17 08:11:24  johnc
  Added per-file initialization vector.
  Added random padding with Mersenne Twister rng.
  Added backup options (recurse dir, relative path)
  Added recursive backup of NAND directories

  Revision 1.7  2006/07/13 10:40:20  johnc
  WADGetTitleVersion(DVD) works with backup wads as well.

  Revision 1.6  2006/07/13 07:19:05  johnc
  Added initial backup of NAND files (for game saves)
  Removed MEMAllocator from several functions (use stack)
  Fixed bug with WADCheckImport if title is not installed.

  Revision 1.5  2006/07/06 11:06:44  johnc
  Added WADGetTitleVersionDVD.
  Changed return value of WADGetTitleVersion.
  Added cidx to backup header (backed up contents indices).

  Revision 1.4  2006/06/30 13:41:31  johnc
  Integrated tmd/content backup to WADBackupHeader.
  Note that backup wad has ".wdb" suffix.

  Revision 1.3  2006/06/09 12:56:19  johnc
  Removed WADSetMetaImport.
  Will only import meta if System Menu is calling this function
  and if it is not a system application

  Revision 1.2  2006/06/08 08:13:08  johnc
  Added ES_ImportBoot (to import boot2.xxx.wad during swupdateIRD)
  Added WADSetMetaImport (to disable meta importing)
  Using estypes.h structures rather than u64 and u16

  Revision 1.1  2006/05/19 07:59:54  johnc
  Initial checkin

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WAD_H__
#define __WAD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <secure/estypes.h>
#include <revolution/mem.h>
#include <revolution/nand.h>
#include <private/nandprivate.h>
#include <revolution/fa.h>
#include <revolution/cnt.h>

#define WAD_ALIGN			64	// Please load wads to this alignment in memory

#define WAD_VERSION 		0	// contents in wad file are exactly same as TMD's contents
#define WAD_VERSION_1		1	// contents in wad file are not same as TMD's contents (use cidx)
#define WAD_VERSION_BACKUP	1	// There is no version 0 (we start with 1 so cidx is used)

#define WAD_SUFFIX_SERVER	"wad"
#define WAD_SUFFIX_BACKUP	"wdb"
#define WAD_SUFFIX_PEER		"wdp"

// Error codes (use #define instead of enum since s32 can return IOP error codes)
#define WAD_RESULT_OK					0			// Same as ES_ERR_OK, ISFS_ERROR_OK
#define WAD_RESULT_INVALID				(-3000)
#define WAD_RESULT_UNKNOWN_FORMAT		(-3001)
#define WAD_RESULT_NOEXISTS 			(-3002)
#define WAD_RESULT_OUT_OF_MEMORY 		(-3003)
#define WAD_RESULT_FILE_OPEN_FAILED 	(-3004)
#define WAD_RESULT_FILE_READ_FAILED 	(-3005)
#define WAD_RESULT_FILE_WRITE_FAILED	(-3006)
#define WAD_RESULT_INCORRECT_ALIGNMENT	(-3007)
#define WAD_RESULT_INCORRECT_DEVICEID	(-3008)
#define WAD_RESULT_FATAL_ERROR			(-3009)

// Import/Export WAD (.wad)
// Components are packed in the same order.
// Padding for each component is done to WAD_ALIGN, except the end of the file
typedef struct
{
    u32 hdrSize;        // Size of WADHeader 32
    u8  wadType[2];		// Type is "Is" or "Xd" (import server or export device)
    u16 wadVersion;		// WAD_VERSION
    u32 certSize;
    u32 crlSize;
    u32 ticketSize;
    u32 tmdSize;
    u32 contentSize;
    u32 metaSize;

} WADHeader;	// Version 0 (contents in wad file are exactly same as TMD's contents)

typedef struct
{
    u32 hdrSize;        // Size of WADHeader1 96
    u8  wadType[2];
    u16 wadVersion;		// WAD_VERSION_1
    u32 certSize;
    u32 crlSize;
    u32 ticketSize;
    u32 tmdSize;
    u32 contentSize;
    u32 metaSize;
    u8	cidx[64];

} WADHeader1;	// Version 1 (contents in wad file are not same as TMD's contents (use cidx))
				// This is for including system shared contents in TMD, but not in the wad file.

#define WAD_FLAG_MAKEWAD	   0x0001	// bit 0: if set, wad created by makeWad.exe, otherwise by publishWad.py

typedef struct
{
	char			name[44];
	u8				toolMajorVer;
	u8				toolMinorVer;
	u16				flags;
	char			username[16];

} WADMeta;

// Backup WAD (.wdb)
// Used the retail systems to backup title contents and/or NAND files and recover free space on NAND
// Components are packed in order of TMD, contents, WADFile, file content, WADFile, file content, etc.
// Padding for each component is done to WAD_ALIGN, except the end of the file
typedef struct
{
    u32 hdrSize;			// Size of WADBackupheader 110
    u8  wadType[2];			// Type is "Bk" (backup)
    u16 wadVersion;			// WAD_VERSION_BACKUP.  Up to here, same as WADHeader
   	u32 deviceId;			// Device Id of the device that created the backup
    u32 numFiles;			// Includes directories
    u32 fileSize;			// Size of all WADFile and files together, with padding
    u32 tmdSize;			// Same location as WADHeader, for use with WADGetTitleVersionEx/WADGetImportBlocks
    u32 contentSize;		// Size of all the contents together, with padding
    u32 totalSize;     		// Total size of the entire backup in bytes (must be accurate to verify wad)
  	u8	cidx[64];			// Bit-field of content indices in the wad file
  	u64 gameSaveTitleId;	// TitleId at the time this wad was created (0 if source is not from /title/00000000/00000000)
  	u8	backupTransferId[6];// Saves the transferId from device that created backup (currently 6B original MAC address)
#ifdef REPAIR_APP
	u32 osRTC;				// Only set when gamesaveTitleId is System Menu
#endif

} WADBackupHeader;

typedef enum
{
	WAD_BACKUP_CONTENT  	 = 0x01,	// Backs up a title's private and shared content (can only import to this device)
	WAD_BACKUP_CURRENT_DIR 	 = 0x02,	// Backs up files in NANDCurrentDir	(can be imported to any device)
	WAD_BACKUP_RELATIVE_PATH = 0x04,	// If not an option, will use absolute path.  This is good so you can restore to /tmp first then move
	WAD_BACKUP_RECURSE_DIR	 = 0x08,	// If not an option, will not recurse subdirectories
    WAD_BACKUP_ALLCOPY       = 0x10,    // If not an option, will not backup "/nocopy" dir and "banner.bin" file
    WAD_BACKUP_TMD			 = 0x20,	// Backs up a title's TMD only (without contents).  Needed for repair disc.
	WAD_BACKUP_DEFAULT		 = WAD_BACKUP_CONTENT | WAD_BACKUP_CURRENT_DIR | WAD_BACKUP_RELATIVE_PATH | WAD_BACKUP_RECURSE_DIR

} WADBackupOption;

typedef enum
{
	WAD_IMPORT_NO_OPTION	 = 0x00,
	WAD_IMPORT_NO_VERIFY	 = 0x01,	// For development only: Skip verification to allow game save restore to any Wii development or production
	WAD_IMPORT_TMD_ONLY		 = 0x02,	// Imports only the TMD to allow game save restore if game never played/installed before
	WAD_IMPORT_NO_TMD 		 = 0x04,  	// Should always be used during real game save restore: ignore TMD during size calculation and import
    WAD_IMPORT_BACKUP_ONLY   = 0x08,    // Allow importing backed up WAD file

    WAD_IMPORT_OLD_META      = 0x80     // For development only: Import old meta (Note that we need a compile option INSTALL_APP also)

} WADImportOption;

#define WAD_MAX_PATH		64			// NAND_MAX_PATH is 64, including NULL
#define WAD_FILE_MAGIC		0x03adf17e

typedef struct
{
	u32  magic;
	u32  size;
	u8   perm;					// NAND_PERM_*
	u8   attr;					// NAND file system attributes
	u8	 type;					// NAND_TYPE_FILE or NAND_TYPE_DIR
	char name[WAD_MAX_PATH];	// Absolute path if starts with '/'.
	u8	 padIv[5];				// Pad iv to 32B alignment.
	u8   iv[16];				// Initialization vector
	u8   pad[32];				// Pad to 64B alignment.

} WADFile;

typedef struct
{
	u32	 size;
	u8   perm;
	u8   attr;
	u8   type;
	u8	 pad;
	char name[WAD_MAX_PATH];

} WADFileInfo;

typedef enum
{
	WAD_STREAM_MEMORY,
	WAD_STREAM_DVD,
	WAD_STREAM_NAND,
	WAD_STREAM_SD,
	WAD_STREAM_CNT_DVD,
	WAD_STREAM_CNT_NAND

} WADStream;

#ifdef NANDAPP
  #define WAD_STREAM_CNT WAD_STREAM_CNT_NAND
#else
  #define WAD_STREAM_CNT WAD_STREAM_CNT_DVD
#endif

typedef struct
{
	WADStream 		    source;
	union
	{
		void  	   	   *memPtr;
		DVDFileInfo	    dvdFileInfo;
		NANDFileInfo    nandFileInfo;
		FAFile*      	sdFileInfo;
		CNTFileInfoDVD	cntFileInfoDVD;
		CNTFileInfoNAND cntFileInfoNAND;

	} file;

} WADStreamInfo;

typedef struct
{
	char	          *name;
	union
	{
		CNTHandleNAND *cntHandleNAND;
		CNTHandleDVD  *cntHandleDVD;

	} handle;

} WADCNTFile;

typedef struct
{
	u16 wadTmdBlocks; // in extremely rare case, it is possible this value is 2
	u16 wadTmdInodes;
	u16 wadPrivateContentBlocks;
	u16 wadPrivateContentInodes;
	u16 wadSharedContentBlocks;
	u16 wadSharedContentInodes;
	/*
	u16 installedTmdBlocks;
	u16 installedTmdInodes;
	u16 installedPrivateContentBlocks;
	u16 installedPrivateContentInodes;
	u16 installedSharedContentBlocks;
	u16 installedSharedContentInodes;
	*/
	u16 wadFileBlocks; // including directories (only files which can be restored)
	u16 wadFileInodes;

} WADInfo;

//------------

typedef void (*WADProgressCallbackFunc)(u32 bytesProcessed, u32 bytesTotal, BOOL done);

typedef enum
{
	WAD_THREAD_NOTREADY = 0,
	WAD_THREAD_READY,
	WAD_THREAD_RUNNING,
	WAD_THREAD_SUCCESS,
	WAD_THREAD_ERROR

} WADThreadStatus;

typedef struct
{
	WADThreadStatus	status;
	OSThread 		thread;
	void   		   *stack;
	u32				stackSize;
	MEMAllocator   *mem;
	OSPriority		priority;

} WADThreadInfo;

typedef struct
{
	void 		            *file;
	MEMAllocator            *mem;
	WADStream 		         source;
	u32 		 	         startOffset;
	WADImportOption          option;
	WADProgressCallbackFunc  callback;

} WADImportArgs;

typedef struct
{
	WADThreadInfo   threadInfo;
	WADImportArgs	wadArgs;

} WADImportInfo;

typedef struct
{
    ESTitleId                title;
    WADBackupOption          option;
    MEMAllocator            *mem;
    const char*              filename;
    u32                     *size;
    WADStream                dest;
    u32                      startOffset;
    WADProgressCallbackFunc  callback;
} WADBackupArgs;

typedef struct
{
    WADThreadInfo   threadInfo;
    WADBackupArgs   wadArgs;
} WADBackupInfo;

s32		WADInitImportAsync(WADImportInfo *wadImportInfo, void *file, MEMAllocator* mem, WADStream source,
                           u32 startOffset, WADImportOption option, WADProgressCallbackFunc callback);
s32		WADStartImportAsync(WADImportInfo *wadImportInfo);
s32		WADFinishImportAsync(WADImportInfo *wadImportInfo);

s32     WADInitBackupAsync(WADBackupInfo *wadBackupInfo, ESTitleId title, WADBackupOption option, MEMAllocator *mem,
                           const char *filename, u32 *size, WADStream dest, u32 startOffset, WADProgressCallbackFunc callback);
s32     WADStartBackupAsync(WADBackupInfo *wadBackupInfo);
s32     WADFinishBackupAsync(WADBackupInfo *wadBackupInfo);

//------------

// For more information on how to use these functions, please refer to wad.c's function comments

s32  	WADGetTitleVersionEx(void *file, ESTitleId *titleId, ESTitleVersion *titleVersion, WADStream source, u32 startOffset);
#define WADGetTitleVersion(f, tI, tV)		 WADGetTitleVersionEx(f, tI, tV, WAD_STREAM_MEMORY, 0)
#define WADGetTitleVersionDVD(f, tI, tV)	 WADGetTitleVersionEx(f, tI, tV, WAD_STREAM_DVD, 0)

BOOL 	WADCheckImport(ESTitleId titleId, ESTitleVersion titleVersion);
s32		WADImportGetBlocks(void *file, MEMAllocator *mem, WADStream source, u32 startOffset, WADImportOption option, WADInfo *wadInfo, WADFileInfo **fileList);

s32  	WADImportEx(void *file, MEMAllocator* mem, WADStream source, u32 startOffset, WADImportOption option, WADProgressCallbackFunc callback);
#define WADImport(head)					     WADImportEx(head, &DemoAllocator2, WAD_STREAM_MEMORY, 0, WAD_IMPORT_NO_OPTION, NULL)
#define WADImportDVD(fileName, mem)		     WADImportEx(fileName, mem, WAD_STREAM_DVD, 0, WAD_IMPORT_NO_OPTION, NULL)
#define WADImportDVDEx(fileName, mem)	     WADImportEx(fileName, mem, WAD_STREAM_DVD, 0, WAD_IMPORT_NO_OPTION, NULL)
#define WADImportNANDEx(fileName, mem)	     WADImportEx(fileName, mem, WAD_STREAM_NAND, 0, WAD_IMPORT_NO_OPTION, NULL)
#define WADImportSDEx(fileName, mem)	     WADImportEx(fileName, mem, WAD_STREAM_SD, 0, WAD_IMPORT_NO_OPTION, NULL)
s32		WADImportDVDForBS(char* fileName, void* addr, u32 length);
s32		WADImportDVDExForBS(char* fileName, void* addr, u32 length);

#define WADRestoreSD(fileName, mem)            WADImportEx(fileName, mem, WAD_STREAM_SD, 0, WAD_IMPORT_BACKUP_ONLY, NULL)
#define WADRestoreSDEx(fileName, mem, offset)  WADImportEx(fileName, mem, WAD_STREAM_SD, offset, WAD_IMPORT_BACKUP_ONLY, NULL)

s32  	WADBackupEx(ESTitleId titleId, WADBackupOption option, MEMAllocator *mem, const char *filename, u32 *size, WADStream dest, u32 startOffset, WADProgressCallbackFunc callback);
#define WADBackup(titleId, option, mem, filename, size, dest, startOffset)  WADBackupEx(titleId, option, mem, filename, size, dest, startOffset, NULL)
s32		WADVerify(WADStreamInfo *sInfo, MEMAllocator *mem, u32 startOffset, u32 totalSize);
s32		WADBackupResign(void *file, MEMAllocator* mem, WADStream source, u32 startOffset);

#ifdef _DEBUG
s32     WADDebugBackupGetCerts(void *file, MEMAllocator* mem, WADStream source, u32 startOffset, IOSCEccSig *sig, IOSCEccEccCert *appCert, IOSCEccEccCert *devCert);
#endif

void 	WADPrint(void *head);
s32  	WADGetInstalledVersion(ESTitleId titleId, ESTitleVersion *titleVersion);
s32  	WADGetTicketId(void *file, ESTicketId *ticketId, WADStream source, u32 startOffset);

// Can use memory, DVD, NAND, SD
s32		WADOpenStream(WADStream source, void *file, WADStreamInfo *sInfo, BOOL writeEnabled, u32 startOffset);
s32 	WADReadStream(WADStreamInfo *sInfo, u8 **dst, s32 size, s32 offset);	// This is a very tricky function to use
void	WADCloseStream(WADStreamInfo *sInfo);
s32		WADWriteStream(WADStreamInfo *sInfo, void *buffer, u32 size);
s32		WADSeekStream(WADStreamInfo *sInfo, s32 offset, s32 origin);

// Global variables
extern unsigned char ca_dpki[1024];
extern unsigned char ca_ppki[1024];
extern unsigned char ms_dpki[576];
extern unsigned char ms_ppki[576];

#ifdef REPAIR_APP
extern BOOL copyWiiC24Config;
#endif

#ifdef __cplusplus
}
#endif

#endif // __WAD_H__