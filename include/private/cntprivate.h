/*---------------------------------------------------------------------------*
  Project:      content API private library
  File:         cntprivate.h
  Programmer:   WADA Jumpei

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/09/26 14:30:50  wada_jumpei
  CNT Private API for Encryption/Decryption and Sign/Verification

 *---------------------------------------------------------------------------*/

#ifndef __CNTPRIVATE_H__
#define __CNTPRIVATE_H__

#include <revolution/types.h>
#include <revolution/cnt.h>

#ifdef __cplusplus
extern "C" {
#endif


#define CNT_KEY_STRING_LEN   30

typedef u8  CNTEccSig[CNT_KEY_STRING_LEN * 2];
typedef u8  CNTEccPublicKey[CNT_KEY_STRING_LEN * 2];
typedef u8  CNTEccPublicPad[4];
typedef u8  CNTCertPad[52];
typedef u8  CNTEccCertPad[4];
typedef u8  CNTSigDummy[60];
typedef u8  CNTCAName[64];

typedef u8  CNTDeviceId[64];       /* device ID in the form of NCxxxxxxxx */
typedef u8  CNTServerId[64];       /* holds only suffix name for ServerName */

typedef enum {
    CNT_SIG_RSA4096 = 0x00010000,  /* RSA 4096 bit signature */
    CNT_SIG_RSA2048,               /* RSA 2048 bit signature */
    CNT_SIG_ECC                    /* ECC signature 512 bits*/
} CNTCertSigType;

typedef enum {
    CNT_PUBKEY_RSA4096,            /* RSA 4096 bit key */
    CNT_PUBKEY_RSA2048,            /* RSA 2048 bit key */
    CNT_PUBKEY_ECC                 /* ECC pub key 512 bits*/
} CNTCertPubKeyType;

typedef struct {
    CNTCertSigType   sigType;
    CNTEccSig        sig;
    CNTEccPublicPad  eccPad;
    CNTSigDummy      dummy;
    CNTCAName        issuer;       /* Root-CAxxxxxxxx-MSxxxxxxxx-NCxxxxxxxx */
} CNTSigEcc;

typedef struct {
    CNTCertPubKeyType pubKeyType;
    union {
        CNTServerId serverId;
        CNTDeviceId deviceId;
    } name;
    u32 date;
} CNTCertHeader;

typedef struct {
    CNTSigEcc          sig;        /* ECC signature struct */
    CNTCertHeader      head;
    CNTEccPublicKey    pubKey;     /* 60 byte ECC public key */
    CNTEccPublicPad    eccPad;
    CNTCertPad         pad;
    CNTEccCertPad      pad2;
} CNTEccEccCert;


// device initialize function
#define CNTPrivateInit  contentInitNAND

// Encryption/Decription Functions
s32 CNTPrivateEncrypt(u8* iv, u8* input, u32 inputSize, u8* output);
s32 CNTPrivateDecrypt(u8* iv, u8* input, u32 inputSize, u8* output);

// Signature/Verification Functions
s32 CNTPrivateSign(const void* data, u32 numOfBytes, CNTEccSig sig, CNTEccEccCert* signerKeyCert);
s32 CNTPrivateVerify(const void* data, u32 numOfBytes, const CNTEccSig sig, const void* certList, u32 certListInBytes);


#ifdef __cplusplus
}
#endif


#endif // end of __CNTPRIVATE_H__
