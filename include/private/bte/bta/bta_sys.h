/*****************************************************************************
**
**  Name:           bta_sys.h
**
**  Description:    This is the public interface file for the BTA system
**                  manager.
**
**  Copyright (c) 2003-2005, Broadcom Corp., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_SYS_H
#define BTA_SYS_H

#include <private/bte/gki.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/

/* event handler function type */
typedef BOOLEAN (tBTA_SYS_EVT_HDLR)(BT_HDR *p_msg);

/* disable function type */
typedef void (tBTA_SYS_DISABLE)(void);



#define BTA_ID_SYS          0            /* system manager */
#define BTA_ID_DM           1            /* device manager */
#define BTA_ID_DM_SEARCH    2            /* device manager search */
#define BTA_ID_DM_SEC       3            /* device manager security */
#define BTA_ID_DG           4            /* data gateway */
#define BTA_ID_AG           5            /* audio gateway */
#define BTA_ID_OPC          6            /* object push client */
#define BTA_ID_OPS          7            /* object push server */
#define BTA_ID_FTS          8            /* file transfer server */
#define BTA_ID_CT           9            /* cordless telephony terminal */
#define BTA_ID_FTC          10           /* file transfer client */
#define BTA_ID_SS           11           /* synchronization server */
#define BTA_ID_PR           12           /* Printer client */
#define BTA_ID_BIC          13           /* Basic Imaging Client */
#define BTA_ID_PAN          14           /* Personal Area Networking */
#define BTA_ID_BIS          15           /* Basic Imaging Server */
#define BTA_ID_ACC          16           /* Advanced Camera Client */
#define BTA_ID_SC           17           /* SIM Card Access server */
#define BTA_ID_AA           18           /* Advanced audio */
#define BTA_ID_HD           19           /* HID Device */
#define BTA_ID_CG           20           /* Cordless Gateway */
#define BTA_ID_BP           21           /* Basic Printing Client */
#define BTA_ID_PRM          22
#define BTA_ID_HH           23           /* Human Interface Device Host */
#define BTA_ID_PBS          24           /* Phone Book Access Server */
#define BTA_ID_PBC          25           /* Phone Book Access Client */
#define BTA_ID_MAX          26

typedef UINT8 tBTA_SYS_ID;


#define BTA_SYS_CONN_OPEN           0
#define BTA_SYS_CONN_CLOSE          1
#define BTA_SYS_APP_OPEN            2
#define BTA_SYS_APP_CLOSE           3
#define BTA_SYS_SCO_OPEN            4
#define BTA_SYS_SCO_CLOSE           5
#define BTA_SYS_CONN_IDLE           6
#define BTA_SYS_CONN_BUSY           7


typedef UINT8 tBTA_SYS_CONN_STATUS;

/* tBTA_PREF_ROLES */
typedef UINT8 tBTA_SYS_PREF_ROLES;

/* conn callback for role / low power manager*/
typedef void (tBTA_SYS_CONN_CBACK)(tBTA_SYS_CONN_STATUS status,UINT8 id, UINT8 app_id, BD_ADDR peer_addr);


/* registration structure */
typedef struct
{
    tBTA_SYS_EVT_HDLR   *evt_hdlr;
    tBTA_SYS_DISABLE    *disable;
} tBTA_SYS_REG;

/* system manager configuration structure */
typedef struct
{
    UINT16          mbox_evt;                       /* GKI mailbox event */
    UINT8           mbox;                           /* GKI mailbox id */
    UINT8           timer;                          /* GKI timer id */
    UINT8           trace_level;                    /* initial trace level */
} tBTA_SYS_CFG;

/*****************************************************************************
**  Global data
*****************************************************************************/

/* trace level */
extern UINT8 appl_trace_level;

/*****************************************************************************
**  Macros
*****************************************************************************/

/* Calculate start of event enumeration; id is top 8 bits of event */
#define BTA_SYS_EVT_START(id)       ((id) << 8)

/*****************************************************************************
**  Function declarations
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

BTA_API extern void bta_sys_init(void);
BTA_API extern void bta_sys_event(BT_HDR *p_msg);
BTA_API extern void bta_sys_timer_update(void);
BTA_API extern void bta_sys_disable_timers(void);
BTA_API extern void bta_sys_set_trace_level(UINT8 level);
extern void bta_sys_register(UINT8 id, const tBTA_SYS_REG *p_reg);
extern void bta_sys_sendmsg(void *p_msg);
extern void bta_sys_start_timer(TIMER_LIST_ENT *p_tle, UINT16 type, INT32 timeout);
extern void bta_sys_stop_timer(TIMER_LIST_ENT *p_tle);
extern void bta_sys_disable(void);



extern void bta_sys_rm_register(tBTA_SYS_CONN_CBACK * p_cback);
extern void bta_sys_pm_register(tBTA_SYS_CONN_CBACK * p_cback);
extern void bta_sys_compress_register(tBTA_SYS_CONN_CBACK * p_cback);
extern BOOLEAN bta_sys_check_compress(tBTA_SYS_ID id, UINT8 app_id, BD_ADDR peer_addr);

extern void bta_sys_conn_open(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_conn_close(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_app_open(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_app_close(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_sco_open(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_sco_close(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_idle(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);
extern void bta_sys_busy(UINT8 id, UINT8 app_id, BD_ADDR peer_addr);


#ifdef __cplusplus
}
#endif

#endif /* BTA_SYS_H */
