/*****************************************************************************
**
**  Name:           rpct_int.h
**
**  Description:    This interface file contains constants and data which
**                  are shared between RPCT modules.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_INT_H
#define RPCT_INT_H


/*****************************************************************************
**  Global data
*****************************************************************************/

/* circular buffer */
extern tUCBUF_CB        rpct_main_ucbuf;

/* pointer to link layer interface functions */
extern tRPCT_LINK_IF   *p_rpct_l_if;

/* pointer to link layer control block */
extern tRPCT_LINK_CB   rpct_l_cb;

/* buffer queue for RPC messages received by task executing RPCGEN */
extern BUFFER_Q        rpct_rpcgen_q;

/* trace level */
extern UINT8           rpc_trace_level;

#endif /* RPCT_INT_H */
