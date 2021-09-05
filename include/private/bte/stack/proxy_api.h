/******************************************************************************
**
** File:         proxy_api.h
**
** Description:  Contains API for BTE Test Tool Proxy related functions.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/

#ifndef PROXY_API_C
#define PROXY_API_C


#include <private/bte/common/target.h>
//#include "rpc_defs.h"
//#include "tgtrpc_int.h"

/* Proxy API Function external declarations */

extern void TGTRPC_GetTargetInfo(tRPC_INFO *pProxyInfo);
extern void TGTRPC_InitStack(void);
extern void TGTRPC_HciSendToLower(BT_HDR *p_msg, UINT16 event);
extern void TGTRPC_SetTraceLevel(tTGTRPC_TRACE_LEVEL *p_trace_level, UINT32 protocol_trace_flag);

#endif /* PROXY_API_C */
