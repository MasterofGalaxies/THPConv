/******************************************************************************
**                                                                            
**  Name:          rsi_api.h                                                  
**                                                                            
**                                                                            
**  Description:   This file contains the RPC Serial Interface API definitions
**                                                                            
**                                                                            
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.               
**  WIDCOMM Bluetooth Core. Proprietary and confidential.                     
******************************************************************************/
#ifndef RSI_H
#define RSI_H

#include <private/bte/stack/userial.h>
#include <private/bte/common/target.h>


/* Type of RSI operation in progress */
enum {
    RSI_NO_GET,
    RSI_GETC,
    RSI_GETS
}; typedef UINT8 tRSI_get_type;

/* RSI Control Block Structure */
typedef struct {
    UINT8           task;
    UINT8           mbox;
    tRSI_get_type   gtype;
    UINT32          timer;
    BOOLEAN         segmented;
    UINT16          seg_len;
    UINT8           *seg_buf;
    UINT16          max_buf_len;
} tRSI_CB;


/*******************************************************************************
** Function Prototypes
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

BT_API extern void   RSI_Init(void);
BT_API extern void   RSI_SerialInit(UINT16 id, UINT8 baud);
BT_API extern void   RSI_SerialSetCB(UINT16 id, tUSERIAL_CBACK rcvHandler);
BT_API extern UINT16 RSI_SerialReadBlock(UINT16 id, UINT8 *data, UINT16 len);
BT_API extern UINT16 RSI_SerialWriteBlock(UINT16 id, UINT8 *data, UINT16 len);
BT_API extern void   RSI_SerialClose(UINT16 id);
BT_API extern void   RSI_SerialCallback(tUSERIAL_PORT port, tUSERIAL_EVT event);
BT_API extern void   RSI_SetConsoleTimer(UINT32 ticks);
BT_API extern void   RSI_putc(UINT8 ch);
BT_API extern UINT8  RSI_getc(void);
BT_API extern void   RSI_puts(const char *str);
BT_API extern char  *RSI_gets(char *str, int max);
BT_API extern tRSI_CB *RSI_GetControlBlock(void);
BT_API extern void   RSI_cls(void);

#ifdef __cplusplus
}
#endif

#endif
