/******************************************************************************
**
** File:         tgt_api.h
**
** Description:  Contains API for test tool "target" related functions.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/

#ifndef TGT_API_H
#define TGT_API_H

#include <private/bte/common/target.h>
#include <private/bte/stack/btm_api.h>

#define RPC_VER_MAJOR   1
#define RPC_VER_MINOR   0

#define RPC_VERSION_STRING_MAXLEN   32

typedef struct
{
    UINT16    ver_major;
    UINT16    ver_minor;
    char      ver_string[RPC_VERSION_STRING_MAXLEN];
}tRPC_INFO;

typedef struct
{

    UINT8   lc_trace_level;
    UINT8   lm_trace_level;
    UINT8   hci_trace_level;
    UINT8   l2c_trace_level;
    UINT8   rfc_trace_level;
    UINT8   sdp_trace_level;
    UINT8   tcs_trace_level;
    UINT8   obex_trace_level;
    UINT8   btm_trace_level;
    UINT8   gap_trace_level;
    UINT8   dun_trace_level;
    UINT8   bnep_trace_level;
    UINT8   goep_trace_level;
    UINT8   icp_trace_level;
    UINT8   hsp2_trace_level;
    UINT8   spp_trace_level;
    UINT8   ctp_trace_level;
    UINT8   bpp_trace_level;
    UINT8   hcrp_trace_level;
    UINT8   ipudp_trace_lavel;
    UINT8   ftp_trace_level;
    UINT8   opp_trace_level;
    UINT8   btu_trace_level;
    UINT8   gki_trace_level;
    UINT8   pan_trace_level;
    UINT8   sap_trace_level;
    UINT8   hfp_trace_level;
    UINT8   hid_trace_level;
    UINT8   bip_trace_level;
    UINT8   avp_trace_level;

}tSTACKDLL_TRACE_LEVEL;

#ifdef __cplusplus
extern "C" {
#endif

BT_API extern void STACKDLL_SetTraceLevel(tSTACKDLL_TRACE_LEVEL *p_trace_level, UINT32 proto_trace_mask);
BT_API extern void RPC_HciSendToLower(BT_HDR *p_msg, UINT16 event);
BT_API extern void RPC_GetTargetInfo(tRPC_INFO *p_info);
BT_API extern UINT32 RPC_GetInqDBSize(void);
BT_API extern void RPC_PrintGKIBufferUsage(void);
BT_API extern tBTM_STATUS RPC_ReadLocalDeviceAddr (tBTM_CMPL_CB *p_cb);
BT_API extern BOOLEAN RPC_IsDeviceUp (void);
BT_API extern tBTM_STATUS RPC_VendorSpecificCommand(UINT16 opcode, UINT8 param_len,
                                      UINT8 *p_param_buf, tBTM_CMPL_CB *p_cb);

#ifdef __cplusplus
}
#endif

#endif /* TGT_API_H */
