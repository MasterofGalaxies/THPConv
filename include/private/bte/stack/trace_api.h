/******************************************************************************
**
** File:         trace_api.h
**
** Description:  Contains API for BTE Test Tool trace related functions.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/


#ifndef TRACE_API_H
#define TRACE_API_H

#include <private/bte/common/target.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Trace API Function External Declarations */
BT_API extern void DispRFCOMMFrame (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispL2CCmd(BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispSdp (BT_HDR *p_msg, BOOLEAN is_rcv, BOOLEAN is_segment);
BT_API extern void DispSdpFullList (UINT8 *p, UINT16 list_len, BOOLEAN is_rcv);
BT_API extern void DispTcsMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispHciEvt (BT_HDR *p_buf);
BT_API extern void DispHciAclData (BT_HDR *p_buf, BOOLEAN is_rcvd);
BT_API extern void DispHciCmd (BT_HDR *p_buf);
BT_API extern void DispBnep (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispAvdtMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispAvct (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispObxMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void DispLMDiagEvent (BT_HDR *p_buf);
BT_API extern void DispHidFrame (BT_HDR *p_buf, BOOLEAN is_recv, BOOLEAN is_control);
BT_API extern void DispRawFrame(UINT8 *p, UINT16 len, BOOLEAN is_rcv);


BT_API extern void RPC_DispRFCOMMFrame (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispL2CCmd(BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispSdp (BT_HDR *p_msg, BOOLEAN is_rcv, BOOLEAN is_segment);
BT_API extern void RPC_DispSdpFullList (UINT8 *p, UINT16 list_len, BOOLEAN is_rcv);
BT_API extern void RPC_DispTcsMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispHciEvt (BT_HDR *p_buf);
BT_API extern void RPC_DispHciAclData (BT_HDR *p_buf, BOOLEAN is_rcvd);
BT_API extern void RPC_DispHciCmd (BT_HDR *p_buf);
BT_API extern void RPC_DispBnep (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispAvdtMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispAvct (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispObxMsg (BT_HDR *p_buf, BOOLEAN is_recv);
BT_API extern void RPC_DispLMDiagEvent (BT_HDR *p_buf);
BT_API extern void LogMsg (UINT32 trace_set_mask, const char *fmt_str, ...);
BT_API extern void RPC_DispHidFrame (BT_HDR *p_buf, BOOLEAN is_recv, BOOLEAN is_control);

#ifdef __cplusplus
}
#endif

#endif /* TRACE_API_H */
