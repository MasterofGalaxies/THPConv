/* $Id: iosctypes.h,v 1.5 2006-06-28 18:23:24 tong Exp $ */

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

/*
 * Types to be exposed to user of iosc 
 */

#ifndef __IOSCTYPES_H__
#define __IOSCTYPES_H__
/* Enums
 */

#include <csltypes.h>
/*
 * errors in crypto 
 */

#define IOSC_ERROR_OK                     0
#define IOSC_ERROR_ACCESS                -2000
#define IOSC_ERROR_EXISTS                -2001
#define IOSC_ERROR_INVALID               -2002
#define IOSC_ERROR_MAX                   -2003
#define IOSC_ERROR_NOEXISTS              -2004

#define IOSC_ERROR_INVALID_OBJTYPE       -2005
#define IOSC_ERROR_INVALID_RNG           -2006
#define IOSC_ERROR_INVALID_FLAG          -2007
#define IOSC_ERROR_INVALID_FORMAT        -2008
#define IOSC_ERROR_INVALID_VERSION       -2009
#define IOSC_ERROR_INVALID_SIGNER        -2010
#define IOSC_ERROR_FAIL_CHECKVALUE       -2011
#define IOSC_ERROR_FAIL_INTERNAL         -2012
#define IOSC_ERROR_FAIL_ALLOC            -2013
#define IOSC_ERROR_INVALID_SIZE          -2014
#define IOSC_ERROR_INVALID_ADDR          -2015
#define IOSC_ERROR_INVALID_ALIGN         -2016


typedef s32 IOSCError;
/*
 * hash related defines 
 */
#define IOSC_HASH_FIRST 0
#define IOSC_HASH_MIDDLE 1
#define IOSC_HASH_LAST 2

#define IOSC_MAC_FIRST 0
#define IOSC_MAC_MIDDLE 1
#define IOSC_MAC_LAST 2

typedef enum 
{
    IOSC_SECRETKEY_TYPE = 0,
    IOSC_PUBLICKEY_TYPE,
    IOSC_KEYPAIR_TYPE, 
    IOSC_DATA_TYPE
} IOSCObjectType;


typedef enum 
{
    IOSC_ENC_SUBTYPE = 0,
    IOSC_MAC_SUBTYPE,
    IOSC_RSA2048_SUBTYPE,
    IOSC_RSA4096_SUBTYPE, 
    IOSC_ECC233_SUBTYPE,
    IOSC_CONSTANT_SUBTYPE,
    IOSC_VERSION_SUBTYPE
} IOSCObjectSubType;

typedef enum
{
    IOSC_NOSIGN_NOENC = 0,
    IOSC_NOSIGN_ENC,
    IOSC_SIGN_NOENC,
    IOSC_SIGN_ENC
}IOSCSecretKeySecurity;

/* Handles available by default : available to use */
#define IOSC_DEV_SIGNING_KEY_HANDLE 0
#define IOSC_DEV_ID_HANDLE          1
#define IOSC_FS_ENC_HANDLE          2
#define IOSC_FS_MAC_HANDLE          3
#define IOSC_COMMON_ENC_HANDLE      4
#define IOSC_BACKUP_ENC_HANDLE      5
#define IOSC_APP_ENC_HANDLE         6
#define IOSC_ROOT_KEY_HANDLE        (0xfffffff) /* picked a large number */

/* writeable data */
#define IOSC_BOOTOSVER_HANDLE       7
#define IOSC_CACRLVER_HANDLE        8
#define IOSC_SIGNERCRLVER_HANDLE    9
#define IOSC_FSVER_HANDLE           10

/* Max bytes through GenerateRand */
#define IOSC_MAX_RAND_BYTES         128


/* Handles to state or context */

typedef u32 IOSCSecretKeyHandle;
typedef u32 IOSCKeyHandle; 
typedef u32 IOSCDataHandle;
typedef u32 IOSCPublicKeyHandle;
typedef u8  IOSCHashContext[96];
typedef u8  IOSCHash[20];
typedef u8  IOSCCertName[64];

/* not exposing actual cert defns */

typedef u8 IOSCGenericCert[1024]; /* largest cert size */
typedef u8 IOSCEccSignedCert[384]; /* for device certs */

/* cert types exposed to application */
typedef enum {
    IOSC_SIG_RSA4096 = 0x00010000,  /* RSA 4096 bit signature */
    IOSC_SIG_RSA2048,  /* RSA 2048 bit signature */
    IOSC_SIG_ECC       /* ECC signature 512 bits*/
} IOSCCertSigType;

typedef enum {
    IOSC_PUBKEY_RSA4096,  /* RSA 4096 bit key */
    IOSC_PUBKEY_RSA2048,  /* RSA 2048 bit key */
    IOSC_PUBKEY_ECC       /* ECC pub key 512 bits*/
} IOSCCertPubKeyType;

/* 
 * defines exposed pertaining to CSL
 */

typedef CSLOSEccPublicKey IOSCEccPublicKey;
typedef CSLOSEccPrivateKey IOSCEccPrivateKey;
typedef CSLOSEccSig IOSCEccSig;

typedef CSLOSRsaPublicKey2048 IOSCRsaPublicKey2048 ;
typedef CSLOSRsaPublicKey4096 IOSCRsaPublicKey4096;
typedef CSLOSRsaExponent IOSCRsaExponent;
typedef CSLOSRsaSig2048 IOSCRsaSig2048;
typedef CSLOSRsaSig4096 IOSCRsaSig4096;

typedef CSLOSSha1Hash IOSCSha1Hash;
typedef CSLOSAesKey  IOSCAesKey ;
typedef CSLOSAesIv  IOSCAesIv  ;
typedef CSLOSHMACKey IOSCHmacKey;

/* padding to do word size alignment */
typedef u8   IOSCEccPrivatePad[2];
typedef u8   IOSCEccPublicPad[4];

#endif 
