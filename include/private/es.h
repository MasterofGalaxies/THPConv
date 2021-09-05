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

#ifndef __ES_H__
#define __ES_H__

#if defined(BROADWAY_REV)
#pragma ppc_no_fp_blockmove on
#endif 

#if defined(__cplusplus)
extern "C" {
#endif

#include <iosccert.h>
#include <estypes.h>

#define ES_CMD_IMP_SERVER_TICKET                1
#define ES_CMD_IMP_SERVER_TITLE_INIT            2
#define ES_CMD_IMP_CONTENT_BEGIN                3
#define ES_CMD_IMP_CONTENT_DATA                 4
#define ES_CMD_IMP_CONTENT_END                  5
#define ES_CMD_IMP_TITLE_DONE                   6
#define ES_CMD_GET_DEVICE_ID                    7 
#define ES_CMD_LAUNCH_TITLE                     8
#define ES_CMD_OPEN_CONTENT_FILE                9
#define ES_CMD_READ_CONTENT_FILE                10
#define ES_CMD_CLOSE_CONTENT_FILE               11
#define ES_CMD_LIST_OWNED_TITLES_CNT            12
#define ES_CMD_LIST_OWNED_TITLES                13
#define ES_CMD_LIST_TITLES_ON_CARD_CNT          14
#define ES_CMD_LIST_TITLES_ON_CARD              15
#define ES_CMD_LIST_TITLE_CONTENTS_CNT          16
#define ES_CMD_LIST_TITLE_CONTENTS              17
#define ES_CMD_GET_TICKET_VIEW_CNT              18 
#define ES_CMD_GET_TICKET_VIEWS                 19
#define ES_CMD_GET_TMD_VIEW_SIZE                20
#define ES_CMD_GET_TMD_VIEW                     21
#define ES_CMD_GET_CONSUMPTION                  22
#define ES_CMD_DELETE_TITLE                     23
#define ES_CMD_DELETE_TICKET                    24
#define ES_CMD_DI_GET_TMD_VIEW_SIZE             25
#define ES_CMD_DI_GET_TMD_VIEW                  26
#define ES_CMD_DI_GET_TICKET_VIEW               27
#define ES_CMD_DI_VERIFY                        28
#define ES_CMD_GET_DATA_DIR                     29 
#define ES_CMD_GET_DEVICE_CERT                  30 
#define ES_CMD_IMP_BOOT                         31
#define ES_CMD_GET_TITLE_ID                     32
#define ES_CMD_SET_UID                          33
#define ES_CMD_DELETE_TITLE_CONTENT             34
#define ES_CMD_SEEK_CONTENT_FILE                35
#define ES_CMD_OPEN_TITLE_CONTENT_FILE          36
#define ES_CMD_SWITCH_MODE                      37
#define ES_CMD_EXP_BACKUP_TITLE_INIT            38
#define ES_CMD_EXP_CONTENT_BEGIN                39
#define ES_CMD_EXP_CONTENT_DATA                 40
#define ES_CMD_EXP_CONTENT_END                  41
#define ES_CMD_EXP_TITLE_DONE                   42
#define ES_CMD_IMP_BACKUP_TITLE_INIT            43
#define ES_CMD_ENCRYPT                          44
#define ES_CMD_DECRYPT                          45
#define ES_CMD_GET_BOOT2_VERSION                46
#define ES_CMD_IMP_TITLE_CANCEL                 47
#define ES_CMD_SIGN                             48
#define ES_CMD_VERIFY_SIGN                      49
#define ES_CMD_LIST_TMD_CONTENTS_CNT            50
#define ES_CMD_LIST_TMD_CONTENTS                51
#define ES_CMD_GET_TMD_SIZE                     52
#define ES_CMD_GET_TMD                          53
#define ES_CMD_LIST_SHARED_CONTENTS_CNT         54
#define ES_CMD_LIST_SHARED_CONTENTS             55
#define ES_CMD_DELETE_SHARED_CONTENT            56
#define ES_CMD_DI_GET_TMD_SIZE                  57
#define ES_CMD_DI_GET_TMD                       58
#define ES_CMD_DI_VERIFY_WITH_TICKET_VIEW       59
#define ES_CMD_SETUP_STREAM_KEY                 60
#define ES_CMD_DELETE_STREAM_KEY                61
#define ES_CMD_DELETE_CONTENT                   62

// NET_CARD is defined when compiling kernel code,
// NITRO is defined when compiling library code
#if defined(NET_CARD) || defined (NITRO)
#define ES_CMD_GET_ACCESS_RIGHTS                63
#endif

ESError ES_InitLib(void);
ESError ES_CloseLib(void);
ESError ES_ImportTicket(const void* ticket, 
        const void* certList, u32 certSizeInBytes, 
        const void* crlList, u32 crlSizeInBytes, 
        ESTransferType source);
ESError ES_ImportTitleInit(const void* tmd, u32 tmdSize, 
        const void* certList, u32 certSizeInBytes, 
        const void* crlList, u32 crlSizeInBytes, 
        ESTransferType source, int safeUpdate);
s32     ES_ImportContentBegin(ESTitleId titleId, ESContentId cid);
ESError ES_ImportContentData(s32 fd, const void* inBuf, u32 inBufSize);
ESError ES_ImportContentEnd(s32 fd);
ESError ES_ImportTitleDone();
ESError ES_ImportTitleCancel();

ESError ES_ImportBoot(const void* ticket, 
        const void* ticketCertList, u32 ticketCertSizeInBytes, 
        const void* tmd, u32 tmdSize, 
        const void* tmdCertList, u32 tmdCertSizeInBytes, 
        const void* crlList, u32 crlSizeInBytes, 
        const void* bootApp, u32 bootAppSize);

ESError ES_LaunchTitle(ESTitleId titleId, ESTicketView* ticketView);
ESError ES_SwitchMode(void);
s32     ES_OpenContentFile(u32 contentIdx);
s32     ES_OpenTitleContentFile(ESTitleId titleId, 
        const ESTicketView* ticketView, u32 contentIdx);
ESError ES_ReadContentFile(s32 fd, void* buf, u32 size);
ESError ES_SeekContentFile(s32 fd, s32 offset, u32 whence);
ESError ES_CloseContentFile(s32 fd);

ESError ES_ListOwnedTitles(ESTitleId* titleIds, u32* numTitles);
ESError ES_ListTitlesOnCard(ESTitleId* titleIds, u32* numTitles);
ESError ES_ListTitleContentsOnCard(ESTitleId titleId, ESContentId* cids, 
        u32* numContents);
ESError ES_ListTmdContentsOnCard(const void* tmd, u32 tmdSize, 
        ESContentId* cids, u32* numContents);
ESError ES_ListSharedContents(u32* numContents, IOSCHash* hashes);

ESError ES_GetTicketViews(ESTitleId titleId,  ESTicketView* ticketViewList, 
        u32* ticketViewCnt);
ESError ES_GetTmd(ESTitleId titleId, ESTitleMeta* tmd, u32* tmdSize);
ESError ES_GetTmdView(ESTitleId titleId, ESTmdView* tmdView, u32* size);
ESError ES_GetTmdSize(void* tmd, u32* size);
ESError ES_GetTmdSizeFromView(ESTmdView *tmdView, u32* size);
ESError ES_DiGetTicketView(const void* ticket, ESTicketView* ticketView);
ESError ES_DiGetTmdView(const void* tmd, u32 tmdSize, ESTmdView* tmdView, 
        u32* tmdViewSize);
ESError ES_DiGetTmd(ESTitleMeta* tmd, u32* tmdSize);

ESError ES_DeleteTitleContent(ESTitleId titleId);
ESError ES_DeleteContent(ESTitleId titleId, ESContentId cid);
ESError ES_DeleteTitle(ESTitleId titleId);
ESError ES_DeleteTicket(const ESTicketView* ticketView); 
ESError ES_DeleteSharedContent(IOSCHash hash);

ESError ES_GetTitleId(ESTitleId* titleId);
ESError ES_SetUid(ESTitleId titleId);
ESError ES_GetDataDir(ESTitleId titleId, char* dataDir);

ESError ES_GetDeviceId(ESId* devId);
ESError ES_GetDeviceCert(void* deviceCert);
ESError ES_GetBoot2Version(u32 *version);
ESError ES_GetConsumption(ESTicketId ticketId, ESLpEntry* ccEntry, u32* nEntries);

ESError ES_Sign(const void* data, u32 numOfBytes, IOSCEccSig sig, 
        IOSCEccEccCert* signerKeyCert);
ESError ES_VerifySign(const void* data, u32 numOfBytes, const IOSCEccSig sig, 
        const void* certList, u32 certListInBytes);

#if defined(NEXT_GEN) || defined(BROADWAY_REV)
#include <iosctypes.h>
ESError ES_DiVerify(const void *certList, u32 certSizeInBytes, 
        const void* crlList, u32 crlListInBytes, 
        const void* ticket, const void* tmd, u32 tmdSize, 
        IOSCSecretKeyHandle* hTitleKey, IOSCHash* hashes);
ESError ES_DiVerifyWithTicketView(const void *certList, u32 certSizeInBytes, 
        const void* crlList, u32 crlListInBytes, 
        const ESTicketView* ticketView, const ESTitleMeta* tmd, u32 tmdSize, 
        IOSCSecretKeyHandle* hTitleKey, IOSCHash* hashes);

ESError ES_GetExportCertSize(u32* size);
ESError ES_ExportCerts(void* certList);
ESError ES_GetExportCrlSize(u32* size);
ESError ES_ExportCrls(void* crlList);

ESError ES_ExportTitleInit(ESTitleId titleId, ESId deviceId, 
        ESTicketId ticketId, const void* certList, u32 certSizeInBytes, 
        const void* crlList, u32 crlSizeInBytes, ESTransferType dest, 
                           void* ticket, void* tmd, u32 tmdSizeInBytes);
s32     ES_ExportContentBegin(ESTitleId titleId, ESContentId cid);
s32     ES_ExportContentData(s32 fd, void* outBuf, u32 size);
ESError ES_ExportContentEnd(s32 fd);
ESError ES_ExportTitleDone();
ESError ES_Encrypt(u32 keyHandle, u8* iv, u8* input, u32 inputSize, u8* output);
ESError ES_Decrypt(u32 keyHandle, u8* iv, u8* input, u32 inputSize, u8* output);
ESError ES_SetupStreamKey(const ESTicketView* ticketView, const ESTitleMeta* tmd, u32 tmdSize, IOSCSecretKeyHandle* hStreamKey);
ESError ES_SetupStreamIv(u16 contentIdx, IOSCAesIv iv);
ESError ES_DeleteStreamKey(IOSCSecretKeyHandle hStreamKey);
#endif

#if defined(NITRO)
ESError ES_GetAccessRights(u32* accessRights);
#endif

#if defined(NEXT_GEN) || defined(BROADWAY_REV) 

#define ntohs(x) (x)
#define ntohl(x) (x)
#define htonll(x) (x)
#define ntohll(x) (x)
#define htonl(x) (x)

#else

#define ntohs(x) ((((x)&0xff)<<8) | (((x)&0xff00)>>8))
#define ntohl(x) ( (((x)&0xff)<<24) | (((x)&0xff00)<<8) | (((x)&0xff0000)>>8) | (((x)&0xff000000)>>24) ) 
#define htonll(x) ((u64)( ((u64)((htonl((u32)(x)))) << 32) | (htonl((u32)(((u64)(x))>>32))) ))
#define ntohll(x) ((u64)( ((u64)((ntohl((u32)(x)))) << 32) | (ntohl((u32)(((u64)(x))>>32))) ))
#define htonl ntohl

#endif

#if defined(__cplusplus)
}
#endif

#endif /*__ES_H__*/
