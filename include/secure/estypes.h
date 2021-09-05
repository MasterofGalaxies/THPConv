/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */

#ifndef __ES_TYPES_H__
#define __ES_TYPES_H__

#if !defined(NEXT_GEN) && !defined(BROADWAY_REV)
#include <types.h>
#endif
#include <iosccert.h>

/* This needs to be synced up with kernel -- not sure how,
 * so I am just making a note here!
 */
#define ES_APP_ENC_HANDLE       6

#define ES_ROOT_NAME            "Root"
#define ES_CA_PREFIX            "CA"
#define ES_XS_PREFIX            "XS"
#define ES_MS_PREFIX            "MS"
#define ES_CP_PREFIX            "CP"
#define ES_NC_PREFIX            "NC"
#define ES_NG_PREFIX            "NG"
#define ES_APP_CERT_PREFIX      "AP"

#define ES_BUF_SIZE             256

typedef u32  ESId;                 /* 32-bit device identity */
typedef u32  ESContentId;          /* 32-bit content identity */
typedef u64  ESTitleId;            /* 64-bit title identity */
typedef u64  ESTicketId;           /* 64-bit ticket id */
typedef u8   ESVersion;            /* 8-bit data structure version */
typedef u16  ESTitleVersion;       /* 16-bit title version */
typedef ESTitleId ESSysVersion;    /* 64-bit system software version */
typedef u32  ESTitleType;          /* title type */
typedef u16  ESContentType;        /* content type */
typedef u8   ESTmdReserved[62];    /* reserved field in TMD structure */
typedef u8   ESTicketReserved[48]; /* reserved field in eTicket structure */
typedef u8   ESSysAccessMask[2];   /* 16 bit cidx Mask to indicate which 
                                      content can be accessed by sys app */

#define ES_TMD_VERSION             0
#define ES_TICKET_VERSION          0
#define ES_DEFAULT_GID             1

/* TMD View */
#define ES_MAX_CONTENT             512

#define ES_TITLE_TYPE_NC_TITLE     0         /* NC title */
#define ES_TITLE_TYPE_NG_TITLE     1         /* NG title */
#define ES_TITLE_TYPE_DS_TITLE     2         /* DS title for NC */
#define ES_TITLE_TYPE_STREAM       4         /* stream title */
#define ES_TITLE_TYPE_DATA         8         /* data title */
#define ES_CONTENT_TYPE_SHARED     (1<<15)   /* shared content */
#define ES_CONTENT_TYPE_OPTIONAL   (1<<14)   /* optional content */
#define ES_CONTENT_TYPE_DISC       (1<< 1)   /* disc content */
#define ES_CONTENT_TYPE_NC_EXE     0         /* NC merged elf */
#define ES_CONTENT_TYPE_NG_EXE     1         /* NG content */

#define ES_LICENSE_MASK      0x0f /*  allow 16 licensing types */
#define ES_LICENSE_PERMANENT 0x00 /* e.g.,  regular game with permanent rights */
#define ES_LICENSE_DEMO      0x01 /* e.g.,  demo game with permanent rights */
#define ES_LICENSE_TRIAL     0x02 /* e.g.,  regular game with limited rights */
#define ES_LICENSE_RENTAL    0x03 /* TBD */
#define ES_LICENSE_SUBSCRIPTION 0x04 /* TBD */    
#define ES_LICENSE_GIFT_MASK 0x80 /* this is a gift */

#if defined(LINUX) || defined(BROADWAY_REV)
#pragma pack(push, 4) 
#endif
typedef struct {
    ESVersion        version;           /* TMD data structure version */
    ESSysVersion     sysVersion;        /* required system software 
                                           version number */
    ESTitleId        titleId;           /* 64 bit title id */
    ESTitleType      type;              /* 32 bit title type */
    u16              groupId;
    ESTmdReserved    reserved;          /* 62 bytes reserved info */
    ESTitleVersion   titleVersion;      /* 16 bit title version */
    u16              numContents;       /* number of contents in the title */
} ESTmdViewHeader;

typedef struct {
    ESContentId      cid;               /* 32 bit content id */
    u16              index;             /* 16 bit content index */
    ESContentType    type;              /* 16 bit content type */
    u64              size;              /* 64 bit content size */
} ESCmdView;

typedef struct {
    ESTmdViewHeader head;
    ESCmdView       contents[ES_MAX_CONTENT];
} ESTmdView;

/* TMD */
typedef struct {
    ESContentId    cid;    /* 32 bit content id */
    u16            index;  /* content index, unique per title */
    ESContentType  type;   /* content type*/
    u64            size;   /* unencrypted content size in bytes */
    IOSCHash       hash;   /* 160-bit SHA1 hash of the content */
} ESContentMeta;

typedef struct {
    ESVersion      version;  /* TMD version number */
    ESVersion      caCrlVersion;  /* CA CRL version number */
    ESVersion      signerCrlVersion; /* signer CRL version number */
    ESSysVersion   sysVersion;  /* required system software version number */

    ESTitleId      titleId;      /* 64 bit title id */
    ESTitleType    type;         /* 32 bit title type */
    u16            groupId;
    ESTmdReserved  reserved;     /* 62 bytes reserved info for Nintendo */
    u32            accessRights; /* title's access rights to use 
                                    system resources */
    ESTitleVersion titleVersion; /* 16 bit title version */
    u16            numContents;  /* number of contents per title */
    u16            bootIndex;    /* boot content index */
} ESTitleMetaHeader;

typedef struct {
    IOSCSigRsa2048     sig;      /* RSA 2048bit sign of all the data in 
                                    the TMD file */
    ESTitleMetaHeader  head;
    ESContentMeta      contents[ES_MAX_CONTENT];
} ESTitleMeta;

/* eTicket View */
#define ES_MAX_LIMIT_TYPE       8
#define ES_LC_DURATION_TIME     1
#define ES_LC_ABSOLUTE_TIME     2
#define ES_LC_NUM_TITLES        3
#define ES_LC_NUM_LAUNCH        4

typedef u8   ESCidxMask[64];

typedef struct {
    u32        code;               /* limited play algorithm */
    u32        limit;              /* limited play limit */
} ESLpEntry;

typedef struct {
    ESVersion        version;            /* eTicket data structure version */
    ESTicketId       ticketId;           /* eTicket ID */
    ESId             deviceId;           /* device ID */
    ESTitleId        titleId;            /* title ID */
    ESSysAccessMask  sysAccessMask;      /* 16 bit cidx mask */
    u16              ticketVersion;      /* 16 bit ticket version */
    u32              accessTitleId;      /* 32 bit title id for access control*/
    u32              accessTitleMask;    /* 32 bit title id mask */
    u8               licenseType;        /* for infrastructure use */
    ESTicketReserved reserved;           /* 48 bytes reserved info */
    u8               audit;              /* for infrastructure use */
    ESCidxMask       cidxMask;           /* 512 bits of cidx mask */
    ESLpEntry        limits[ES_MAX_LIMIT_TYPE];  /* limit algorithm and limit */
} ESTicketView;

/* Consumption Counter */
typedef struct {
    u32        revision;
    u32        numCcs; 
} ESCcHeader;

typedef struct {
    ESTicketId ticketId;
    ESLpEntry  consumption[ES_MAX_LIMIT_TYPE];
} ESCc;

#if defined(LINUX) || defined(BROADWAY_REV)
#pragma pack(pop)
#endif

#define ES_SHA_ALIGN_SIZE    64
#define ES_SHA_ALIGN    __attribute__ ((aligned(ES_SHA_ALIGN_SIZE)))
#define IOS_AllocShaAlign(a, b) IOS_AllocAligned(a, b, ES_SHA_ALIGN_SIZE)
#define ES_AES_LINE_SIZE     16
#define ES_CACHE_ALIGN_SIZE  32 
#define ES_AES_ALIGN    __attribute__ ((aligned(ES_CACHE_ALIGN_SIZE)))
#define IOS_AllocAesAlign(a, b) IOS_AllocAligned(a, b, ES_CACHE_ALIGN_SIZE)

typedef s32 ESError;
typedef enum {
    ES_TRANSFER_SERVER,
    ES_TRANSFER_PEER_DEVICE,
    ES_TRANSFER_BACKUP
} ESTransferType;

#define ES_CHANNEL_MASK       (0xffffffff00000000ULL)
#define ES_SYS_CHANNEL_BB     0
#define ES_SYS_CHANNEL_RVL    1 
#define ES_SYS_CHANNEL_NC     2 
#define ES_TITLE_ID_BOOT      1
#define ES_TITLE_ID_SYS_APP   2
#define ES_TITLE_ID_BOOT_DIAG 3
#define ES_TITLE_ID_DS_VIEWER 4
#define ES_TITLE_ID_GBA_SWITCHER  5
#define ES_TICKET_ID_GBA_SWITCHER 5

#define ES_PARTNER_ID_SHIFT   48
#define ES_CHANNEL_ID_SHIFT   32

/* These things are defined on the Title ID assignment Wiki page */
#define NINTENDO_PARTNER_ID   0x0001
#define NINTENDO_PERM_TITLE_CHANNEL     0x0000
#define NINTENDO_DISC_NAND_CHANNEL      0x0004


#define ES_TITLE_ID_SYS_COMPATBOOT1  0x100 
#define ES_TITLE_ID_SYS_COMPATAPP    0x101

#if defined(NEXT_GEN) || defined(BROADWAY_REV)
#define ES_SYS_CHANNEL   ES_SYS_CHANNEL_RVL
#else
#define ES_SYS_CHANNEL   ES_SYS_CHANNEL_NC
#endif

#define ES_TITLE_ID_BOOT_64    ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_BOOT))
#define ES_TITLE_ID_BOOT_DIAG_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_BOOT_DIAG))
#define ES_TITLE_ID_SYS_APP_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_SYS_APP))
#define ES_TITLE_ID_SYS_COMPATBOOT1_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_SYS_COMPATBOOT1))
#define ES_TITLE_ID_SYS_COMPATAPP_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_SYS_COMPATAPP))
#define ES_TITLE_ID_DS_VIEWER_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_DS_VIEWER))
#define ES_TITLE_ID_GBA_SWITCHER_64 ((((u64)ES_SYS_CHANNEL)<<32) | (ES_TITLE_ID_GBA_SWITCHER))

#define ES_TITLE_DATA_DIR   "/title/00000000/00000000/data"
#define ES_SHARE_DATA_DIR   "/shared2"
#define ES_META_DIR         "/meta"
#define ES_META_TITLE_DIR   "/meta/00000000/00000000"
#define ES_META_FILE        "/meta/00000000/00000000/title.met"
/* ES_GBA_LAUNCH_PATH must be writable by the viewer */
#define ES_GBA_LAUNCH_PATH  "/tmp/gba_launch"

#define ES_DEVICE_CERT_SIZE   384
#define ES_TICKET_SIZE        676
#define ES_MAX_TMD_SIZE       18916

#define ES_ERR_OK                                   0
#define ES_ERR_INCORRECT_CERT_TYPE                  -1001
#define ES_ERR_GENKEY_FAILED                        -1002
#define ES_ERR_VERIFY_SIG_FAILED                    -1003
#define ES_ERR_CANNOT_OPEN_FILE                     -1004
#define ES_ERR_INCORRECT_PUBKEY_TYPE                -1005
#define ES_ERR_CERT_ISSUER_MISMATCH                 -1006
#define ES_ERR_ENCRYPTION_FAILED                    -1007
#define ES_ERR_FILE_OPEN_FAILED                     -1008
#define ES_ERR_FILE_READ_FAILED                     -1009
#define ES_ERR_FILE_WRITE_FAILED                    -1010
#define ES_ERR_TMD_NUM_CONTENTS                     -1011
#define ES_ERR_INCORRECT_SIG_TYPE                   -1012
#define ES_ERR_INCORRECT_SIG_LENGTH                 -1013
#define ES_ERR_INCORRECT_CERT_LENGTH                -1014
#define ES_ERR_DEV                                  -1015
#define ES_ERR_MAXFD                                -1016
#define ES_ERR_INVALID                              -1017
#define ES_ERR_FS_CONNECTION_FAILED                 -1018
#define ES_ERR_UNSUPPORTED_TRANSFER_SOURCE          -1019
#define ES_ERR_DEVICE_ID_MISMATCH                   -1020
#define ES_ERR_INCORRECT_CONTENT_SIZE               -1021
#define ES_ERR_HASH_MISMATCH                        -1022
#define ES_ERR_INCORRECT_CONTENT_COUNT              -1023
#define ES_ERR_OUT_OF_MEMORY                        -1024
#define ES_ERR_NO_TMD_FILE                          -1025
#define ES_ERR_NO_RIGHT                             -1026
#define ES_ERR_ISSUER_NOT_FOUND                     -1027
#define ES_ERR_NO_TICKET                            -1028
#define ES_ERR_INCORRECT_TICKET                     -1029
#define ES_ERR_NOT_ENOUGH_SPACE                     -1030
#define ES_ERR_INCORRECT_BOOT_VERSION               -1031
#define ES_ERR_UNKNOWN                              -1032
#define ES_ERR_EXPIRED                              -1033
#define ES_ERR_UNUSED                               -1034
#define ES_ERR_INCORRECT_TITLE_VERSION              -1035
#define ES_ERR_OS_TICKET_NOEXISTS                   -1036
#define ES_ERR_OS_CONTENT_NOEXISTS                  -1037
#define ES_ERR_NOT_EMPTY                            -1038
// Game is a disc/nand game, but a tmd was not supplied by caller
#define ES_ERR_DISC_NAND_NO_TMD                     -1039

#define ES_ERR_NOEXISTS                             -106    /* Does not exist ISFS_ERROR_NOEXISTS */

#endif /*__ES_TYPES_H__*/
