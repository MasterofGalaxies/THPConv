/*---------------------------------------------------------------------------*
  Project:  FA library
  File:     fa_types.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

 /****************************************************************************
 [fa_types.h] - Header file of FA types
 ****************************************************************************/
#ifndef __FA_TYPES_H__
#define __FA_TYPES_H__

#include    <string.h>

/* define -------------------------------------------------------------------*/
/* NAND file name max */
#define FA_NAND_MAX_FILENAME_LENGTH    (64+12+1) /* 64(maxPATH)+filename(8.3)+null(1) */

/* For thread safe */
#define FA_NOT_DONE         0x00
#define FA_DONE             0x01

#define FA_SECTOR_BUF_SIZE  512
#define FA_MAX_FILE_NUM     5

/*
 * Async data size for Async API
 * !! Note !!
 *  This is size of the area that is necessary when using Async API.
 *  Do not lower than this size!
 */
#define FA_ASYNC_DATA_SIZE  70

/*-- Types --*/
#define FASemId     int
#define FAError     s32
#define FASizeT     size_t

typedef void        FAFile;
typedef void        FADir;
typedef void        FAVolume;


/*-- Error Code / Return Value --*/
#define FA_OK                   0
#define FA_ERR                  -1
#define FA_ERR_INVALID_PARAM    -2      /* Invalid Parameter            */
#define FA_ERR_MESSAGE_FAIL     -3      /* Fail to Send message         */
#define FA_RET_DERRNUM_ERR      1       /* Fail to Get driver error     */
#define FA_RET_FORCE            1       /* FAUnmount()                  */
#define FA_RET_END_OF_FILE      1       /* FAFeof()                     */
#define FA_RET_NOT_END_OF_FILE  0       /* FAFeof()                     */
#define FA_NULL                 NULL

/* Error Code for API : FAErrnum() */
#define FA_ERR_EPERM            1       /* Operation is not possible    */
#define FA_ERR_ENOENT           2       /* No such file or directory    */
#define FA_ERR_EIO              5       /* I/O Error(Driver Error)      */
#define FA_ERR_ENOEXEC          8       /* Not Executable by internal   */
#define FA_ERR_EBADF            9       /* Bad file descriptor          */
#define FA_ERR_ENOMEM           12      /* Not enough system memory     */
#define FA_ERR_EACCES           13      /* Permission denied            */
#define FA_ERR_EBUSY            16      /* Can not use system resouces  */
#define FA_ERR_EEXIST           17      /* File already exists          */
#define FA_ERR_EISDIR           21      /* find directory when file req */
#define FA_ERR_EINVAL           22      /* Invalid argument             */
#define FA_ERR_ENFILE           23      /* Too many open files(system)  */
#define FA_ERR_EMFILE           24      /* Too many open files(user)    */
#define FA_ERR_EFBIG            27      /* Over file size limit(4GB-1)  */
#define FA_ERR_ENOSPC           28      /* Device out of space          */
#define FA_ERR_ENOLCK           46      /* Can not lock the file        */
#define FA_ERR_ENOSYS           88      /* Not implement function       */
#define FA_ERR_ENOTEMPTY        90      /* Directory is not empty       */
#define FA_ERR_EWPROTECT        201     /* Write protect                */
#define FA_ERR_DFNC             0x1000  /* Driver Error                 */
#define FA_ERR_SYSTEM           (-1)    /* system error(general error)  */

/* NAND Driver Error : FADerrnum()   2006/11/22 add */
#define FA_NANDDRV_OK                         0  /* Success                            */
#define FA_NANDDRV_ERR_INVALID_PARAMETER    -20  /* Invalid Parameter                  */
#define FA_NANDDRV_ERR_INVALID_FORMAT       -21  /* Invalid Format                     */
#define FA_NANDDRV_ERR_ACCESS_OUT_OF_VOLUME -22  /* Access out of volume               */

/* SD Driver Error   : FADerrnum()   2006/11/22 add */
#define FA_SDDRV_OK                           0  /* Success                            */
#define FA_SDDRV_ERR_INVALID_PARAMETER      -30  /* Invalid Parameter                  */
#define FA_SDDRV_ERR_FULL_FORMAT            -31  /* Fail to full format                */
#define FA_SDDRV_ERR_WRITE_PROTECTED        -32  /* Media is write protected           */
#define FA_SDDRV_ERR_MEDIA_EJECTED          -33  /* Media is ejected                   */
#define FA_SDDRV_ERR_MEDIA_SIZE_OVER        -34  /* Media size is too large to format  */
#define FA_SDDRV_ERR_NOT_MEMORY_CARD        -35  /* Media is not Memory Card           */
#define FA_SDDRV_ERR_DRIVER_WRITE           -36  /* Fail to driver write               */
#define FA_SDDRV_ERR_DRIVER_READ            -37  /* Fail to driver read                */
#define FA_SDDRV_ERR_RESET_DEVICE           -38  /* Fail to reset device               */
#define FA_SDDRV_ERR_GET_DEVICE_STAT        -39  /* Fail to get device status          */
#define FA_SDDRV_ERR_INIT_CARD              -40  /* Fail to Initialize card            */
#define FA_SDDRV_ERR_MOUNT_CARD             -41  /* Fail to Mount card                 */
#define FA_SDDRV_ERR_REGIST_INTR_HANDLER    -42  /* Fail to register interrupt handler */
#define FA_SDDRV_ERR_READ_CARD_REGISTER     -43  /* Fail to read card register         */
#define FA_SDDRV_ERR_ALREADY_ATTACHED       -44  /* Media is already attached          */
#define FA_SDDRV_ERR_STATE_OF_UNMOUNTED     -45  /* Media status is unmount            */

/*-------------------------*
/*   define for each API   */
/*-------------------------*
/* Media type : FAAttach() */
#define FA_DEVKND_SD        0x00
#define FA_DEVKND_USB       0x01
#define FA_DEVKND_NAND      0x02
#define FA_DEVKND_OTHER     0x03
#define FA_DEVKND_MAX       0x04

/* Drive status : FAAttach() */
#define FA_ATTACHED         0x1     /* Attached       */
#define FA_MOUNTED          0x2     /* Mounted        */
#define FA_INSERTED         0x10    /* media inserted */

/* Unmount mode : FAUnmount() */
#define FA_UNMOUNT_NORMAL   0x00    /* Normal mode  */
#define FA_UNMOUNT_FORCE    0x01    /* Forcing mode */

/* Format type : FAFormat()  2006/11/22 add */
#define FA_SDDRV_FULL_FORMAT    "FULL_FORMAT"    /* Full format mode */

/* Reference point : FAFseek() */
#define FA_SEEK_CUR         0x01    /* Current      */
#define FA_SEEK_SET         0x00    /* Start        */
#define FA_SEEK_END         0x02    /* End          */

/* File attribute : FAFsfirst() */
#define FA_ATTR_RDONLY      0x01    /* Read only    */
#define FA_ATTR_HIDDEN      0x02    /* Hidden file  */
#define FA_ATTR_SYSTEM      0x04    /* System file  */
#define FA_ATTR_VOLUME      0x08    /* Volume label */
#define FA_ATTR_DIR         0x10    /* Subdirectory */
#define FA_ATTR_ARCH        0x20    /* Archive      */
#define FA_ATTR_NONE        0x40    /* No attribute */
#define FA_ATTR_ALL         0x7f    /* All files    */

/* Search mode : FAFsfirst() */
#define FA_ATTR_CAND    0x80        /* AND mode     */

/* DTA information entry processes : FAFsexec() */
#define FA_FSEXEC_REMOVE    0x01    /* Deletes the file or directory            */
#define FA_FSEXEC_CHGMOD    0x06    /* Changes the file or directory attributes */
#define FA_FSEXEC_FOPEN     0x10    /* Opens the file                           */
#define FA_FSEXEC_OPENDIR   0x20    /* Opens the directory                      */
#define FA_FSEXEC_DTA_EXEC  0x80000000  /* FADtaExec structure is specified.    */

/* Attribute specified for file or directory : FAFsexec() */
#define FA_FSEXEC_WRITE     0x01     /* Write mode        */
#define FA_FSEXEC_READ      0x02     /* Read mode         */
#define FA_FSEXEC_APPEND    0x04     /* Append write mode */
#define FA_FSEXEC_PLUS      0x08     /* Multi mode        */

/* create macro for FADtaExec */
typedef struct FADtaExec  FADtaExec;

#define FA_DTACPY(a,b)          memcpy((void*)b, (void*)a, sizeof(FADtaExec));

/* Operation mode : FAFlock() */
#define FA_LOCK_SH          0x01    /* Shared lock mode     */
#define FA_LOCK_EX          0x02    /* Exclusive lock mode  */
#define FA_LOCK_UN          0x04    /* Unlock mode          */
#define FA_LOCK_NB          0x08    /* Non-blocking mode    */

/* Mode of writing data in the cache : FASync() */
#define FA_NINVALIDATE      0x00    /* Does not invalidate cache */
#define FA_INVALIDATE       0x01    /* Invalidates cache         */

/* Read/write back mode : FABuffering() */
#define FA_WRTSOON          0x1     /* write soon                    */
#define FA_NWRTSOON         0x0     /* not write soon                */
#define FA_AUTOSYNC         0x2     /* cache is not used effectively */
#define FA_NAUTOSYNC        0x0     /* cache is used effectively     */
#define FA_FAT_WRITE_THRU   0x4
#define FA_FAT_WRITE_BACK   0x0

/* EjectSafe Write through mode */
#define FA_EJECT_SAFE_WITH_WRITE_THRU   FA_WRTSOON
/* EjectSafe Write back mode */
#define FA_EJECT_SAFE_WITH_WRITE_BACK   FA_NWRTSOON | FA_AUTOSYNC | FA_FAT_WRITE_THRU
/* Auto Write back mode */
#define FA_WRITE_BACK_ON_SIGNIF_API     FA_NWRTSOON | FA_AUTOSYNC
/* Write back mode */
#define FA_WRITE_BACK_CACHE             FA_NWRTSOON | FA_NAUTOSYNC

/* Cluster link mode : FASetclstlink() */
#define FA_CLST_LINK_ENABLE             0x01    /* Use the cluster link feature          */
#define FA_CLST_LINK_DISABLE            0x00    /* Does not use the cluster link feature */

/* Mode of reference/update of the FSINFO : FASetupfsi() */
#define FA_FSI_TRUST_ENABLE             0x01    /* Trusts the number of unused clusters          */
#define FA_FSI_TRUST_DISABLE            0x02    /* Does not trust the number of unused clusters  */
#define FA_FSI_REFRESH_ENABLE           0x04    /* Updates the number of unused clusters         */
#define FA_FSI_REFRESH_DISABLE          0x08    /* Does not update the number of unused clusters */

/* Drive specifying : FASetvolcfg() */
#define FA_ALL_VOLUME                   0xFF    /* All volume(drive) */

/* Volume setting : FASetvolcfg() */
#define FA_SET_FAT_CACHE_SIZE           0x1        /* Set number of FAT buffers           */
#define FA_SET_DATA_CACHE_SIZE          0x2        /* Set number of data buffers          */
#define FA_CHAR_CHECK_DISABLE           0x00010000 /* Disables illegal character checking */
#define FA_CHAR_CHECK_ENABLE            0x00020000 /* Enables illegal character checking  */

/* Common file setting : FASetvolcfg() */
#define FA_UPDATE_ACCESS_DATE_DISABLE   0x1     /* Prohibits access date update */
#define FA_UPDATE_ACCESS_DATE_ENABLE    0x2     /* Permits access date update   */

/* Charcode kind : FASetcode() */
#define FA_CHARCODE_SJIS                0x00    /* Shift-JIS          */
#define FA_CHARCODE_LATIN1              0x01    /* Latin1             */
#define FA_CHARCODE_ASCII               0x02    /* Ascii              */
#define FA_CHARCODE_OTHER               0x03    /* Other              */

/* Encoding mode : FASetencode() */
#define FA_ENCODE_MODE_UTF16            0x1     /* UTF-16 mode        */
#define FA_ENCODE_MODE_UTF16_EXT        0x2     /* UTF-16 extend mode */

/* Maximum length of Short/Long File Name in characters */
#define FA_SHORT_NAME_CHARS            11       /* = 8 + 3            */
#define FA_SHORT_DOT_NAME_CHARS        12       /* = 8 + 1 + 3        */
#define FA_LONG_NAME_CHARS             255

/* Maximum size of Short/Long File Name in bytes */
#define FA_SHORT_NAME_SIZE             11       /* = SHORT_NAME_CHARS          */
#define FA_SHORT_DOT_NAME_SIZE         12       /* = FA_SHORT_DOT_NAME_CHARS   */
#define FA_LONG_NAME_SIZE              510      /* = FA_LONG_NAME_CHARS * 2    */

#define FA_VOLUME_LABEL_SIZE           FA_SHORT_NAME_SIZE

/* Buffer size for Short/Long File Name in bytes */
#define FA_SHORT_NAME_BUF_SIZE         (FA_SHORT_DOT_NAME_SIZE+1)     /* Including NUL */
#define FA_LONG_NAME_BUF_SIZE          (FA_LONG_NAME_SIZE+2)          /* Including NUL */

#define FA_NAME_BUF_SIZE               FA_LONG_NAME_BUF_SIZE

/* Maximum path length of Short/Long File Name in characters */
#define FA_SHORT_NAME_PATH_CHARS       (80-1)                         /* Without NUL   */
#define FA_LONG_NAME_PATH_CHARS        (260-1)                        /* Without NUL   */

/* Maximum path size of Short/Long File Name in bytes */
#define FA_SHORT_NAME_PATH_SIZE        FA_SHORT_NAME_PATH_CHARS       /* Without NUL   */
#define FA_LONG_NAME_PATH_SIZE         (FA_LONG_NAME_PATH_CHARS*2)    /* Without NUL   */

/* Buffer size for path of Short/Long File Name in bytes */
#define FA_SHORT_NAME_PATH_BUF_SIZE    (FA_SHORT_NAME_PATH_SIZE+1)    /* Including NUL */
#define FA_LONG_NAME_PATH_BUF_SIZE     (FA_LONG_NAME_PATH_SIZE+2)     /* Including NUL */

#define FA_PATH_BUF_SIZE               FA_LONG_NAME_PATH_BUF_SIZE

/* Media state flags(Attribute) : disk manager API */
#define FA_MEDIA_ATTR_WRITE_PROTECT            ((u32)0x00000001)
#define FA_MEDIA_ATTR_VOLATILE_MEMORY          ((u32)0x00000002)
#define FA_MEDIA_ATTR_REMOVABLE                ((u32)0x00000004)
#define FA_MEDIA_ATTR_NOT_EXE_LOGICAL_FORMAT   ((u32)0x00000008)

/* Drive status (Write Protected) : FAIsWriteProtected() */
#define FA_NOT_WRITE_PROTECTED         0x00    /* Not Write Protected        */
#define FA_WRITE_PROTECTED             0x01    /* Write Protected            */

/*---------------------------------------------------------------------------*/


/* Variables ----------------------------------------------------------------*/
/* extern */
extern s32 FAInInitializing;
extern s32 FADiskInitialized;
extern s32 FAUsbMscInitialized;         /*2006/12/01/terminate*/
/*---------------------------------------------------------------------------*/


/* Structure -----------------------------------------------------------------*/
/* NAND info structure */
typedef struct FANandInfo
{
    s8      nandFilePath[FA_NAND_MAX_FILENAME_LENGTH + 1]; /* NAND file path and file name */
    u32     nandFileSize;                                  /* NAND file size               */
} FANandInfo;

/* Command block structure for Async API */
typedef struct FACommandBlock
{
    void          *userData;

    /* Do not access below members. */
    u32           asyncData[FA_ASYNC_DATA_SIZE];   /* Data area for Async API */
    FANandInfo    nandInfo;                        /* Data area for NAND info */
} FACommandBlock;

/* Information of cache page */
typedef struct FACachePage
{
    u16             stat;           /* Cache page status                     */
    u16             option;         /* User area (dose not use cache module) */
    u8*             buffer;         /* the head address in buffer            */
    u8*             pBuf;           /* the current pointer in buffer         */
    u8*             pModSbuf;       /* the start modified pointer in buffer  */
    u8*             pModEbuf;       /* the end modified pointer in buffer    */
    u32             size;           /* number of sector per buffer           */
    u32             sector;         /* the head sector number                */
    void*           signature;
    struct FACachePage*  pNext;
    struct FACachePage*  pPrev;
} FACachePage;

typedef u8  FASectorBuf[FA_SECTOR_BUF_SIZE];

/* Information of cache setting */
typedef struct FACacheSetting
{
    FACachePage  *pages;            /* Pointer to cache management area     */
    FASectorBuf  *buffers;          /* Pointer to cache buffer area         */
    u16          numFatPages;       /* Total number of cache pages for FAT  */
    u16          numDataPages;      /* Total number of cache pages for DATA */
    u32          numFatBufSize;     /* Size of one cache page for FAT       */
    u32          numDataBufSize;    /* Size of one cache page for data      */
} FACacheSetting;


/* Disk manager */
/* Disk */
typedef struct FADisk      FADisk;

/* Information of disk */
typedef struct FADiskInfo {
    u32             totalSectors;     /* Total sector in disk                                  */
    u16             cylinders;        /* Number of cylinder                                    */
    u8              heads;            /* Number of head                                        */
    u8              sectorsPerTrack;  /* Sector per track                                      */
    u16             bytesPerSector;   /* Byte per sector                                       */
    u32             mediaAttr;        /* Write protect. 1: write protect, 0: not write protect */
    void*           formatParam;      /* It used when format after mount.                      */
} FADiskInfo;


/* Table of Driver initialize function */
typedef struct FAFuncTbl {

    FAError   (*init)(FADisk*);               /* Initialize drive for attach */
    FAError   (*finalize)(FADisk*);           /* Finalize drive for detach   */
    FAError   (*mount)(FADisk*);              /* Mount driver to access      */
    FAError   (*unmount)(FADisk*);            /* Un-mount driver             */
    FAError   (*format)(FADisk*, const u8 *); /* Format the volume           */

    /* Read physical sectors */
    FAError   (*physicalRead)( FADisk* pDisk,
                               u8     *buf,
                               u32    block,
                               u32    num,
                               u32*   successNum);

    /* Write physical sectors*/
    FAError   (*physicalWrite)( FADisk* pDisk,
                                const u8* buf,
                                u32   block,
                                u32   num,
                                u32*  successNum);

    /* Get media information */
    FAError   (*getDiskInfo)(FADisk* pDisk, FADiskInfo* pDiskInfo);

} FAFuncTbl;


/* Disk table */
typedef struct FADiskTbl
{
    FAFuncTbl*   pFunc;         /* Driver function pointer */
    u32          uiExt;         /* Extension               */
} FADiskTbl;



/* Partition callback */
typedef struct FAPartition      FAPartition;
typedef struct FAPartFunc {
    void            (*insert)(FAPartition*);  /* Callback function for media insert event */
    void            (*eject)(FAPartition*);   /* Callback function for media eject event  */
} FAPartFunc;


/* Partition table */
struct FAPartition
{
    u32         status;              /* Partition status                           */
    FADisk      *pDisk;              /* Pointer to current Disk (Disk information) */
    u32         partId;              /* Partition ID                               */
    u32         startSector;         /* Start sector of current partition          */
    u32         totalSector;         /* Total sector of current partition          */
    FAError     driverLastError;     /* Last error code of driver                  */
    FASemId     partSemId;           /* Semaphore ID for partition                 */
    void        *pVol;               /* A pointer to the Current Volume            */
    FAPartFunc  func;                /* Function table */
};


/* Disk */
struct FADisk{
    u32             status;          /* Disk status                                          */
    FADiskTbl       diskTbl;         /* Driver interface                                     */
    s16             attachPartCnt;   /* Number of attached partition in disk                 */
    s16             mountPartCnt;    /* Number of mounted partition in disk                  */
    FASemId         diskSemId;       /* Semaphore ID for disk                                */
    FASemId         drvSemId;        /* Semaphore ID for driver access                       */
    FADiskInfo      diskInfo;        /* Disk information                                     */
    FAPartition     *pCurPart;       /* Pointer to current partition (Partition information) */
};


/* Disk table to open */
typedef struct FAInitDisk
{
    FAError     (*pFunc)(FADiskTbl *pDiskTbl, u32 uiExt);
    u32          uiExt;             /* Extension of driver */
} FAInitDisk;


/* Driver table */
typedef struct {
    FAPartition         *pPart;     /* Pointer to the partition descriptor */
    FACacheSetting      *pCache;    /* Pointer to the cache information    */
    s8                  drive;      /* Allocated drive letter  (OUT)       */
    u8                  stat;       /* Drive status            (OUT)       */
} FADrvTbl;


/* FADta structure : FAFsfirst() / FAFsnext() */
typedef struct FADta {
    /*-----------------------------------------------------------------------*
      User fields: this is for user area, FAFsexec use this area
     *-----------------------------------------------------------------------*/
    FAFile*     pFile;                     /* File descriptor       */
    FADir*      pDir;                      /* Directory descriptor  */

    /*-----------------------------------------------------------------------*
      Internal fields: do not use these as they will change without notice
     *-----------------------------------------------------------------------*/
    FAVolume*   pVol;                      /* Volume of the parent directory           */
    u32         parentStartCluster;        /* Parent directory start cluster           */
    u32         parentPos;                 /* Next entry position within parent        */
    u32         status;                    /* Status of FADta                          */
    u8          numEntryLFNs;              /* Number of LFNs; If it is zero,
                                              string in 'long_name' field is not valid */
    u8          ordinal;                   /* Ordinal field of LFN entry,
                                              without LAST_LONG_ENTRY flag             */
    u8          checkSum;                  /* Checksum field of LFN entry              */
    u8          attr;                      /* Attributes searched for                  */
    s8          regExp[FA_PATH_BUF_SIZE];  /* Regular expression for file name         */

    /*-----------------------------------------------------------------------*
      Public fields:
     *-----------------------------------------------------------------------*/
    u16         Time;                                  /* Modification time     */
    u16         Date;                                  /* Modification date     */
    u32         FileSize;                              /* File size in bytes    */
    u8          Attribute;                             /* File attributes       */
    s8          FileName[FA_SHORT_NAME_BUF_SIZE];      /* Short file name (8.3) */
    s8          LongName[FA_LONG_NAME_PATH_SIZE + 2];  /* Long file name        */
} FADta;


/* FAStat structure : FAFstat() */
typedef struct FAStat {
    u32     fstfz;         /* file size in bytes                  */
    u16     fstad;         /* Last access date                    */
    u16     fstut;         /* Last modify time                    */
    u16     fstud;         /* Last modify date                    */
    u16     fstct;         /* Create time                         */
    u16     fstcd;         /* Create date                         */
    u16     fstcc;         /* Component of the file creation time */
    u8      fstat;         /* file attributes                     */
} FAStat;


/* FAInfo structure : FAFinfo() */
typedef struct FAInfo {
    u32         fileSize;          /* file size in bytes                                    */
    u32         ioPointer;         /* file I/O pointer in bytes                             */
    u32         emptySize;         /* Size of additional writable area of the file in bytes */
    u32         allocatedSize;     /* Size of fileÅfs unused cluster area in bytes          */
    u32         lockMode;          /* file lock mode                                        */
    FAFile*     lockOwner;         /* file lock owner                                       */
    u32         lockCount;         /* lock count by this descriptor                         */
    u32         lockTcount;        /* total lock count by all descriptor                    */
} FAInfo;


/* FADevInf structure : FAGetdev() */
typedef struct FADevInf {
    u32   cls;          /* total number of logical clusters */
    u32   ecl;          /* number of empty clusters         */
    u32   bps;          /* bytes per logical sector         */
    u32   spc;          /* logical sectors per cluster      */
} FADevInf;


/* FACluster structure : FASetclstlink() */
typedef u32  FAClstsetBuf[FA_MAX_FILE_NUM];

typedef struct FACluster {
    FAClstsetBuf*   buffer;         /* Cluster Link Buffer   */
    u32             maxCount;       /* Cluster Link Max      */
    u16             interval;       /* Cluster Link Interval */
} FACluster;


/* FAClusterFile structure : FAFsetclstlink() */
typedef u32  FAClusterBuf;

typedef struct FAClusterFile {
    FAClusterBuf*   buffer;         /* Cluster Link Buffer   */
    u32             maxCount;       /* Cluster Link Max      */
    u16             interval;       /* Cluster Link Interval */
} FAClusterFile;


/*---------------------------------------------------------------------------
  Information for FAFsexec().
 ----------------------------------------------------------------------------*/
struct FADtaExec {
    /*-----------------------------------------------------------------------*
      User fields: this is for user area, _fsexec use this area
     *-----------------------------------------------------------------------*/
    FAFile*    pFile;                   /* File descriptor      */
    FADir*     pDir;                    /* Directory descriptor */

    /*-----------------------------------------------------------------------*
      Internal fields: do not use these as they will change without notice
     *-----------------------------------------------------------------------*/
    FAVolume*   pVol;                   /* Volume of the parent directory           */
    u32         parentStartCluster;     /* Parent directory start cluster           */
    u32         parentPos;              /* Next entry position within parent        */
    u32         status;                 /* Status of FADta                          */
    u8          numEntryLFNs;           /* Number of LFNs; If it is zero,
                                           string in 'long_name' field is not valid */
    u8          ordinal;                /* Ordinal field of LFN entry,
                                           without LAST_LONG_ENTRY flag             */
    u8          checkSum;               /* Checksum field of LFN entry              */
};


/* Pointer to the buffer address : FASettailbuf() */
typedef u32  FATailBuf;


/* FAVolCfg structure : FASetvolcfg() */
typedef struct FAVolCfg {
    u32   volumeConfig;     /* volume configurations  */
    u32   fileConfig;       /* file configurations    */
    u32   fatBuffSize;      /* FAT cache buffer size  */
    u32   dataBuffSize;     /* data cache buffer size */
} FAVolCfg;


/* Character set of Volume : FASetcode() */
typedef struct FACharCode
{
    s32   (*oem2Unicode)(const s8*, u16*);    /* function to transfer OEM code to Unicode      */
    s32   (*unicode2Oem)(const u16*, s8*);    /* function to transfer Unicode to OEM code      */
    s32   (*oemCharWidth)(const s8*);         /* function to get the width of OEM code         */
    BOOL  (*isOemMbChar)(const s8, u32);      /* function to check 1st multiple-byte character */
    s32   (*unicodeCharWidth)(const u16*);    /* function to get the width of Unicode          */
    BOOL  (*isUnicodeMbChar)(const u16, u32); /* function to check 1st multiple-byte character */
} FACharCode;


/* Volume label table : FAGetvol() */
typedef struct FAVolTab {
    s8      vName[FA_VOLUME_LABEL_SIZE+1];    /* Volume label string (null-terminated)
                                                  NOTE: strlen(vname) is always equal to
                                                  FA_VOLUME_LABEL_SIZE.                   */
    u8      vAttr;                            /* Attributes of the volume label           */
    u32     vDate;                            /* Date                                     */
    u32     vTime;                            /* Time                                     */
} FAVolTab;
/*----------------------------------------------------------------------------*/

/* Callback function ---------------------------------------------------------*/
/* Callback to Notify completion of file access processing for Async API */
typedef void (*FACallback)(s32 result, FACommandBlock *block);

/* Callback to Notify Media inserted and ejected */
typedef void (*FAMediaInOut)(s8 drvLetter);
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/***************/
/*   Unicode   */
/***************/
/* define -------------------------------------------------------------------*/
/* create macro for FADtaExec */
#define FA_W_DTACPY(a,b)        memcpy((void*)b, (void*)a, sizeof(FADtaExec));

/*---------------------------------------------------------------------------*/

/* Structure ----------------------------------------------------------------*/

/* FAWDta structure : FAFsfirstW() / FAFsnextW() */
typedef struct FAWDta {
    /*-----------------------------------------------------------------------*
      User fields: this is for user area, _w_fsexec use this area
     *-----------------------------------------------------------------------*/
    FAFile*     pFile;      /* File descriptor */
    FADir*      pDir;       /* Directory descriptor */

    /*-----------------------------------------------------------------------*
      Internal fields: do not use these as they will change without notice
     *-----------------------------------------------------------------------*/
    FAVolume*   pVol;                /* Volume of the parent directory                           */
    u32         parentStartCluster;  /* Parent directory start cluster                           */
    u32         parentPos;           /* Next entry position within parent                        */
    u32         status;              /* Status of FADta                                          */
    u8          numEntryLFNs;        /* Number of LFNs; If it is zero,
                                        string in 'long_name' field is not valid                 */
    u8          ordinal;             /* Ordinal field of LFN entry, without LAST_LONG_ENTRY flag */
    u8          checkSum;            /* Checksum field of LFN entry                              */
    u8          attr;                /* Attributes searched for                                  */
    s8          regExp[FA_PATH_BUF_SIZE];   /* Regular expression for file name                  */

    /*-----------------------------------------------------------------------*
      Public fields:
     *-----------------------------------------------------------------------*/
    u16         Time;                                       /* Modification time     */
    u16         Date;                                       /* Modification date     */
    u32         FileSize;                                   /* File size in bytes    */
    u8          Attribute;                                  /* File attributes       */
    s8          FileName[FA_SHORT_NAME_BUF_SIZE];           /* Short file name (8.3) */
    s8          LongName[FA_LONG_NAME_PATH_BUF_SIZE + 2];   /* Long file name        */

    /*-----------------------------------------------------------------------*
      Internal fields for UNICODE: do not use these as they will change without notice
     *-----------------------------------------------------------------------*/
    u16         regExpUni[FA_LONG_NAME_PATH_CHARS + 1];     /* Regular expression for file name (Unicode) */

    /*-----------------------------------------------------------------------*
      Public fields for UNICODE:
     *-----------------------------------------------------------------------*/
    u16         FileNameUni[FA_SHORT_DOT_NAME_CHARS + 1];   /* Short file name for Unicode */
    u16         LongNameUni[FA_LONG_NAME_CHARS + 1];        /* Long file name for Unicode  */
} FAWDta;


/*---------------------------------------------------------------------------*/

#endif  // __FA_TYPES_H__
