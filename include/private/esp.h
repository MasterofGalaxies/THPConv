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

#ifndef __ESP_H__
#define __ESP_H__

#if defined(BROADWAY_REV)
#pragma ppc_no_fp_blockmove on
#endif

#include <private/es.h>

#if defined(__cplusplus)
extern "C" {
#endif

// device initialize/finalize
ESError ESP_InitLib(void);
ESError ESP_CloseLib(void);

// title launch
ESError ESP_LaunchTitle(ESTitleId titleId, ESTicketView* ticketView);

// access to content file
s32     ESP_OpenContentFile(u32 contentIdx);
s32     ESP_OpenTitleContentFile(ESTitleId titleId, const ESTicketView* ticketView, u32 contentIdx);
ESError ESP_ReadContentFile(s32 fd, void* buf, u32 size);
ESError ESP_SeekContentFile(s32 fd, s32 offset, u32 whence);
ESError ESP_CloseContentFile(s32 fd);

// list function
ESError ESP_ListOwnedTitles(ESTitleId* titleIds, u32* numTitles);
ESError ESP_ListTitlesOnCard(ESTitleId* titleIds, u32* numTitles);
ESError ESP_ListTitleContentsOnCard(ESTitleId titleId, ESContentId* cids, u32* numContents);
ESError ESP_ListTmdContentsOnCard(const void* tmd, u32 tmdSize, ESContentId* cids, u32* numContents);

// get title's information
// NOTE: ticketViewList buffer must be 32B aligned AND a 32B size multiple (ESTicketView is not a 32B size structure)
ESError ESP_GetTicketViews(ESTitleId titleId,  ESTicketView* ticketViewList,
        u32* ticketViewCnt);
ESError ESP_DiGetTicketView(const void* ticket, ESTicketView* ticketView);
ESError ESP_DiGetTmd(ESTitleMeta* tmd, u32* tmdSize);
ESError ESP_GetTmd(ESTitleId titleId,  ESTitleMeta* tmd, u32* tmdSize);
ESError ESP_GetTmdSize(void* tmd, u32* size);
ESError ESP_GetTmdView(ESTitleId titleId, ESTmdView* tmdView, u32* size);
ESError ESP_GetTitleId(ESTitleId* titleId);
ESError ESP_GetDataDir(ESTitleId titleId, char* dataDir);

// get device information
ESError ESP_GetDeviceId(ESId* devId);
ESError ESP_GetDeviceCert(void* deviceCert);

// for limited play
ESError ESP_GetConsumption(ESTicketId ticketId, ESLpEntry* ccEntry, u32* nEntries);

// for encryption/verification
ESError ESP_Encrypt(u32 keyHandle, u8* iv, u8* input, u32 inputSize, u8* output);
ESError ESP_Decrypt(u32 keyHandle, u8* iv, u8* input, u32 inputSize, u8* output);
ESError ESP_Sign(const void* data, u32 numOfBytes, IOSCEccSig sig,
        IOSCEccEccCert* signerKeyCert);
ESError ESP_VerifySign(const void* data, u32 numOfBytes, const IOSCEccSig sig,
        const void* certList, u32 certListInBytes);

// for import
ESError ESP_ImportTicket(const void* ticket, const void* certList, u32 certSizeInBytes, const void* crlList, u32 crlSizeInBytes, ESTransferType source);
ESError ESP_ImportTitleInit(const void* tmd, u32 tmdSize, const void* certList, u32 certSizeInBytes, const void* crlList, u32 crlSizeInBytes, ESTransferType source, int safeUpdate);
s32     ESP_ImportContentBegin(ESTitleId titleId, ESContentId cid);
ESError ESP_ImportContentData(s32 fd, const void* inBuf, u32 inBufSize);
ESError ESP_ImportContentEnd(s32 fd);
ESError ESP_ImportTitleDone();
ESError ESP_ImportTitleCancel();

// for maintenance
ESError ESP_DeleteTitleContent(ESTitleId titleId);
ESError ESP_DeleteContent(ESTitleId titleId, ESContentId cid);

#if defined(__cplusplus)
}
#endif

#endif /*__ESP_H__*/
