/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished proprietary information of BroadOn Communications Corp.,
 *  and are protected by federal copyright law. They may not be disclosed
 *  to third parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 *  Description:
 *      This file contains the public declarations for the SCFS
 *
 */


#ifndef __FS_H__
#define __FS_H__


#ifdef __cplusplus
extern "C" {
#endif


/* File system return type */
typedef s32 ISFSError;

/* File system statistics */
typedef struct {
    u32     blockSize;      /* File system block size */
    u32     freeBlocks;     /* Free FS blocks */
    u32     occupiedBlocks; /* FS blocks in use */
    u32     badBlocks;      /* Bad FS blocks */
    u32     reservedBlocks; /* Reserved FS blocks */
    u32     freeInodes;     /* Free inodes */
    u32     occupiedInodes; /* Inodes in use */
} ISFSStats;

/* File statistics */
typedef struct {
    u32     size;           /* Size of file in bytes */
    u32     offset;         /* Current position indicator */
} ISFSFileStats;

/* Note that ISFS api's can also return IOSError values */

/* File system error codes */
#define ISFS_ERROR_OK               0       /* Success */
#define ISFS_ERROR_INVALID          -101    /* Invalid parameters */
#define ISFS_ERROR_ACCESS           -102    /* Access denied */
#define ISFS_ERROR_CORRUPT          -103    /* File system corrupted */
#define ISFS_ERROR_NOTREADY         -104    /* File system not ready */
#define ISFS_ERROR_EXISTS           -105    /* Already exists */
#define ISFS_ERROR_NOEXISTS         -106    /* Does not exist */
#define ISFS_ERROR_MAXFILES         -107    /* Ran out of inode entries */
#define ISFS_ERROR_MAXBLOCKS        -108    /* Ran out of FS blocks */
#define ISFS_ERROR_MAXFD            -109    /* Ran out of file descriptors */
#define ISFS_ERROR_MAXDEPTH         -110    /* Maximum directory tree depth */
#define ISFS_ERROR_OPENFD           -111    /* Invalid file descriptor */
#define ISFS_ERROR_BADBLOCK         -112    /* Bad block */
#define ISFS_ERROR_ECC              -113    /* ECC error */
#define ISFS_ERROR_ECC_CRIT         -114    /* Critical ECC error */
#define ISFS_ERROR_NOTEMPTY         -115    /* File is not empty */
#define ISFS_ERROR_HMAC             -116    /* HMAC verification failed */
#define ISFS_ERROR_UNKNOWN          -117    /* Unknown error */
#define ISFS_ERROR_BUSY             -118    /* Async call in progress */
#define ISFS_ERROR_SHUTDOWN         -119    /* File system has shut down */

/* File system block size - 16KB */
#define ISFS_BLOCK_SIZE             (16 * 1024)
#define ISFS_BLOCK_SIZE_SHIFT       14

/* TODO: System area size (determine exact value for NC and NextGen) */
#define ISFS_SYSAREA_SIZE             (1024 * 1024)

/*
 * Max # of characters in a directory name, not including the NULL
 * character
 */
#define ISFS_INODE_NAMELEN            12

/* Max # of characters in a path name including the NULL character */
#define ISFS_PATH_MAXLEN              64

/* Max # of open file descriptors */
#define ISFS_FD_ENTRIES               16

/* Max directory tree depth */
#define ISFS_MAX_DIRTREE_DEPTH        8

/* max number of outstanding ISFS calls at a time */
#define ISFS_MAX_OUTST_CALLS          16

/*
 * Access control permission bits
 */
#define ISFS_READ_ACCESS            0x1
#define ISFS_WRITE_ACCESS           0x2
#define ISFS_RW_ACCESS              (ISFS_READ_ACCESS | ISFS_WRITE_ACCESS)


/* Structures used by the FS resource manager */
typedef struct {
    u8          path1[ISFS_PATH_MAXLEN];    /* NULL terminated string */
    u8          path2[ISFS_PATH_MAXLEN];    /* NULL terminated string */
} ISFSPathsArgs;

#ifdef  __MWERKS__
#pragma warn_padding off
#endif
typedef struct {
    IOSUid      ownerId;                    /* File or directory owner */
    IOSGid      groupId;                    /* Group ID of the owner */
#if 0
    u32         path[ISFS_PATH_MAXLEN];     /* NULL terminated string */
    u32         ownerAccess;                /* Least significant 2 bits */
    u32         groupAccess;                /* Least significant 2 bits */
    u32         othersAccess;               /* Least significant 2 bits */
    u32         attr;                       /* Attribute bits */
#endif
    u8          path[ISFS_PATH_MAXLEN];     /* NULL terminated string */
    u8          ownerAccess;                /* Least significant 2 bits */
    u8          groupAccess;                /* Least significant 2 bits */
    u8          othersAccess;               /* Least significant 2 bits */
    u8          attr;                       /* Attribute bits */
} /*__attribute__ ((packed))*/ ISFSPathAttrArgs;
#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

/* FS resource manager IOCTL commands */
#define ISFS_FORMAT                 1
#define ISFS_STATS                  2
#define ISFS_DCREATE                3
#define ISFS_DREAD                  4
#define ISFS_SETATTR                5
#define ISFS_GETATTR                6
#define ISFS_DEL                    7
#define ISFS_RENAME                 8
#define ISFS_FCREATE                9
#define ISFS_FSETVCTRL              10
#define ISFS_FSTATS                 11
#define ISFS_GETUSAGE               12
#define ISFS_SHUTDOWN               13

/* ISFS_InitLib buffer size */
#define ISFS_INITLIB_BUFSIZE        256

typedef void (*ISFSCallback) (ISFSError, void *ctxt);

/* File system APIs */

ISFSError ISFS_OpenLib(void);
ISFSError ISFS_CloseLib(void);

ISFSError ISFS_Format(void);
ISFSError ISFS_FormatAsync(ISFSCallback cb, void *ctxt);

ISFSError ISFS_GetStats(ISFSStats *stats);
ISFSError ISFS_GetStatsAsync(ISFSStats *stats, ISFSCallback cb, void *ctxt);

ISFSError ISFS_CreateDir(const u8 *dname, u32 dirAttr, u32 ownerAcc, 
                         u32 groupAcc, u32 othersAcc);
ISFSError ISFS_CreateDirAsync(const u8 *dname, u32 dirAttr, u32 ownerAcc, 
                              u32 groupAcc, u32 othersAcc, ISFSCallback cb, 
                              void *ctxt);
/*
 *  nameList argument needs to be allocated in GDDR3
 */

ISFSError ISFS_ReadDir(const u8 *dname, u8 *nameList, u32 *num);
ISFSError ISFS_ReadDirAsync(const u8 *dname, u8 *nameList, u32 *num, 
    ISFSCallback cb, void *ctxt);

ISFSError ISFS_SetAttr(const u8 *name, IOSUid ownerId, IOSGid groupId, 
    u32 attr, u32 ownerAcc, u32 groupAcc, u32 othersAcc);
ISFSError ISFS_SetAttrAsync(const u8 *name, IOSUid ownerId, IOSGid groupId, 
    u32 attr, u32 ownerAcc, u32 groupAcc, 
    u32 othersAcc, ISFSCallback cb, void *ctxt);

ISFSError ISFS_GetAttr(const u8 *name, IOSUid *ownerId, IOSGid *groupId,
    u32 *attr, u32 *ownerAcc, u32 *groupAcc, u32 *othersAcc);
ISFSError ISFS_GetAttrAsync(const u8 *name, IOSUid *ownerId, IOSGid *groupId,
    u32 *attr, u32 *ownerAcc, u32 *groupAcc, 
    u32 *othersAcc, ISFSCallback cb, void *ctxt);

ISFSError ISFS_Delete(const u8 *name);
ISFSError ISFS_DeleteAsync(const u8 *name, ISFSCallback cb, void *ctxt);

ISFSError ISFS_Rename(const u8 *oldName, const u8 *newName);
ISFSError ISFS_RenameAsync(const u8 *oldName, const u8 *newName, 
    ISFSCallback cb, void *ctxt);

ISFSError ISFS_GetUsage(const u8 *dname, u32 *nblocks, u32 *ninodes);
ISFSError ISFS_GetUsageAsync(const u8 *dname, u32 *nblocks, u32 *ninodes,
    ISFSCallback cb, void *ctxt);

ISFSError ISFS_CreateFile(const u8 *fname, u32 fileAttr, u32 ownerAcc, 
    u32 groupAcc, u32 othersAcc);
ISFSError ISFS_CreateFileAsync(const u8 *fname, u32 fileAttr, u32 ownerAcc, 
    u32 groupAcc, u32 othersAcc, ISFSCallback cb, void *ctxt);

ISFSError ISFS_SetFileVersionControl(const u8 *fname, u32 enable); 
ISFSError ISFS_SetFileVersionControlAsync(const u8 *fname, u32 enable, 
    ISFSCallback cb, void *ctxt);

IOSFd ISFS_Open(const u8 *fname, u32 access);
IOSFd ISFS_OpenAsync(const u8 *fname, u32 access, ISFSCallback cb, void *ctxt);

/*
 *  stats argument needs to be allocated in GDDR3
 */

ISFSError ISFS_GetFileStats(IOSFd fd, ISFSFileStats *stats);
ISFSError ISFS_GetFileStatsAsync(IOSFd fd, ISFSFileStats *stats, 
    ISFSCallback cb, void *ctxt);

ISFSError ISFS_Seek(IOSFd fd, s32 offset, u32 whence);
ISFSError ISFS_SeekAsync(IOSFd fd, s32 offset, u32 whence, ISFSCallback cb, 
    void *ctxt);

/*
 *  buf argument needs to be allocated in GDDR3
 */

ISFSError ISFS_Read(IOSFd fd, u8 *buf, u32 size);
ISFSError ISFS_ReadAsync(IOSFd fd, u8 *buf, u32 size, ISFSCallback cb, void *ctxt);

/*
 *  buf argument needs to be allocated in GDDR3
 */

ISFSError ISFS_Write(IOSFd fd, const u8 *buf, u32 size);
ISFSError ISFS_WriteAsync(IOSFd fd, const u8 *buf, u32 size, ISFSCallback cb, 
    void *ctxt);

ISFSError ISFS_Close(IOSFd fd);
ISFSError ISFS_CloseAsync(IOSFd fd, ISFSCallback cb, void *ctxt);

ISFSError ISFS_Shutdown(void);
ISFSError ISFS_ShutdownAsync(ISFSCallback cb, void *fsCtxt);


#ifdef __cplusplus
}
#endif


#endif /* __FS_H__ */
