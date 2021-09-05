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


#ifndef __ES_INT_H__
#define __ES_INT_H__

#include <iosccert.h>
#include <estypes.h>

/*
 * eTicket services library types
 * Common types for modules using security/DRM primitives
 */

#define ES_RSA_ROOT_KEY_SIZE    4096
#define ES_RSA_SIGNER_KEY_SIZE  2048

#define ES_SYS_DIR              "/sys"
#define ES_TICKET_DIR           "/ticket"
#define ES_TITLE_DIR            "/title"
#define ES_TMP_DIR              "/tmp"
#define ES_TMP_IMP_DIR          "/import"
#define ES_SHARE_CONTENT_DIR    "/shared1"
#define CERT_SYS_FILE           "/sys/cert.sys"
#define CRL_SYS_FILE            "/sys/crl.sys"
#define CC_SYS_FILE             "/sys/cc.sys"
#define LAUNCH_SYS_FILE         "/sys/launch.sys"
#define DISC_SYS_FILE           "/sys/disc.sys"
#define UID_MAP_FILE            "/sys/uid.sys"

#define ES_TICKET_TITLE_DIR     "/ticket/00000000/"
#define ES_TICKET_FILE          "/ticket/00000000/00000000.tik"
#define ES_TITLE_ID_DIR         "/title/00000000/00000000"
#define ES_TITLE_CONTENT_DIR    "/title/00000000/00000000/content"
#define ES_TMD_FILE             "/title/00000000/00000000/content/title.tmd"
#define ES_APP_FILE             "/title/00000000/00000000/content/00000000.app"
#define ES_LEGACY_STATE_FILE    "/title/00000000/00000000/data/legacy.sta"
#define ES_IMP_TITLE_DIR        "/import/00000000/00000000/"
#define ES_IMP_CONTENT_DIR      "/import/00000000/00000000/content"
#define ES_IMP_DATA_DIR         "/import/00000000/00000000/data"
#define ES_IMP_TMD_FILE         "/import/00000000/00000000/content/title.tmd"
#define ES_IMP_APP_FILE         "/import/00000000/00000000/content/00000000.app"
#define ES_TMP_TMD_FILE         "/tmp/title.tmd"
#define ES_SHARE_MAP_FILE       "/shared1/content.map"
#define ES_TMP_SHARE_MAP_FILE   "/tmp/content.map"
#define ES_SHARE_CONTENT_FILE   "/shared1/00000000.app"
#define ES_TMP_SHARE_FILE       "/tmp/00000000.app"
#define ES_TMP_UID_MAP_FILE     "/tmp/uid.sys"

#define ES_SYS_APP_UID          0x1000
#define ES_SYS_APP_GID          1

typedef IOSCName       ESCrlEntry;

#if defined(LINUX) || defined(BROADWAY_REV)
#pragma pack(push, 4)
#endif

/*
 * This structure is used for ES_ImportBoot, and in devmon.
 * It's in Big Endian format. 
 */
typedef struct {
    u32 hdrSize;        /* Size of ESWadHeader, may increase in the future */
    u32 contentOffset;  /* Offset to the real content */
    u32 certSize;
    u32 ticketSize;
    u32 tmdSize;
    u32 metaSize;
    u32 metaCid;
    u32 crlSize;
} ESWadHeader;

typedef struct {
    IOSCSigRsa2048   sig;       /* RSA 2048bit sign of the ticket bundle */ 
    IOSCEccPublicKey serverPubKey; /* ticketing server public key */
    ESVersion      version;     /* ticket data structure version number */
    ESVersion      caCrlVersion; /* CA CRL version number */
    ESVersion      signerCrlVersion; /* signer CRL version number */
    IOSCAesKey     titleKey;  /* published title key. encrypted using a 
                                 common AES key when published, then at 
                                 ticketing time, it's signed by the ticketing
                                 server and re-encrypted using the 
                                 shared key between the server and the 
                                 device */
    ESTicketId     ticketId;  /* unique 64bit ticket id */
    ESId           deviceId;  /* unique 32bit device id */
    ESTitleId      titleId;   /* unique 64bit title id */
    ESSysAccessMask sysAccessMask;  /* 16 bit cidx mask to indicate which 
                                       of the first 16 pieces of contents 
                                       can be accessed by the system app*/
    u16            ticketVersion; /* 16bit ticket version */
    u32            accessTitleId;   /* 32bit title id for access control */
    u32            accessTitleMask; /* 32bit title id mask */
    u8             licenseType;
    ESTicketReserved reserved;  /* 48 bytes reserved info for Nintendo */
    u8             audit;
    ESCidxMask     cidxMask;    /* bit mask of the content index to 
                                   indicate which content is consumable */
    ESLpEntry      limits[ES_MAX_LIMIT_TYPE];  /* limited play entries */
} ESTicket;

#if defined(LINUX) || defined(BROADWAY_REV)
#pragma pack(pop)
#endif

#if defined(NET_CARD)
#define ES_LEGACY_STATE_BIT_MASK  0x7
#define ES_RTC_BIT_MASK           0x8
#elif defined(NEXT_GEN) || defined(BROADWAY_REV)
#define ES_ACR_BIT_MASK           0x1
#define ES_DVD_BIT_MASK           0x2
#endif

#define ES_BLOCK_SIZE        (16*1024)
#define ES_APP_FILE_SUFFIX   "app"

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#endif /*__ES_INT_H__*/
