/*****************************************************************************
**
**  Name:           avct_int.h
**
**  Description:    This file contains interfaces which are internal to AVCTP.
**                  
**
**  Copyright (c) 2003-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef AVCT_INT_H
#define AVCT_INT_H

#include <private/bte/gki.h>
#include <private/bte/stack/avct_api.h>
#include <private/bte/stack/avct_defs.h>
#include <private/bte/stack/l2c_api.h>

/*****************************************************************************
** constants
*****************************************************************************/

/* lcb state machine events */
enum {
    AVCT_LCB_UL_BIND_EVT,
    AVCT_LCB_UL_UNBIND_EVT,
    AVCT_LCB_UL_MSG_EVT,
    AVCT_LCB_INT_CLOSE_EVT,
    AVCT_LCB_LL_OPEN_EVT,
    AVCT_LCB_LL_CLOSE_EVT,
    AVCT_LCB_LL_MSG_EVT,
    AVCT_LCB_LL_CONG_EVT
};


/* "states" used for L2CAP channel */
#define AVCT_CH_IDLE    0       /* No connection */
#define AVCT_CH_CONN    1       /* Waiting for connection confirm */
#define AVCT_CH_CFG     2       /* Waiting for configuration complete */
#define AVCT_CH_OPEN    3       /* Channel opened */

/* "no event" indicator used by ccb dealloc */
#define AVCT_NO_EVT     0xFF

/*****************************************************************************
** data types
*****************************************************************************/

/* link control block type */
typedef struct {
    BD_ADDR             peer_addr;      /* BD address of peer */
    BT_HDR              *p_rx_msg;      /* Message being reassembled */
    UINT16              peer_mtu;	    /* peer l2c mtu */
    UINT16              ch_result;      /* L2CAP connection result value */
    UINT16              ch_lcid;        /* L2CAP channel LCID */
    BOOLEAN             allocated;      /* Whether lcb is allocated */
    UINT8               state;          /* The state machine state */
    UINT8               ch_state;       /* L2CAP channel state */
    UINT8               ch_flags;       /* L2CAP configuration flags */
} tAVCT_LCB;

/* connection control block */
typedef struct {
    tAVCT_CC            cc;                 /* parameters from connection creation */
    tAVCT_LCB           *p_lcb;             /* Associated LCB */
    BOOLEAN             ch_close;           /* Whether CCB initiated channel close */
    BOOLEAN             allocated;          /* Whether LCB is allocated */
} tAVCT_CCB;

/* data type associated with UL_MSG_EVT */
typedef struct {
    BT_HDR                  *p_buf;
    tAVCT_CCB               *p_ccb;
    UINT8                   label;
    UINT8                   cr;
} tAVCT_UL_MSG;
    
/* union associated with lcb state machine events */
typedef union {
    tAVCT_UL_MSG            ul_msg;
    BT_HDR                  *p_buf;
    tAVCT_CCB               *p_ccb;
    UINT16                  result;
    BOOLEAN                 cong;
    UINT8                   err_code;
} tAVCT_LCB_EVT;

/* Control block for AVCT */
typedef struct {
    tAVCT_LCB       lcb[AVCT_NUM_LINKS];    /* channel control blocks */
    tAVCT_CCB       ccb[AVCT_NUM_CONN];     /* stream control blocks */
    UINT16          mtu;                    /* our L2CAP MTU */
    UINT8           trace_level;            /* trace level */
} tAVCT_CB;

/*****************************************************************************
** function declarations
*****************************************************************************/

/* LCB function declarations */
extern void avct_lcb_event(tAVCT_LCB *p_lcb, UINT8 event, tAVCT_LCB_EVT *p_data);
extern tAVCT_LCB *avct_lcb_by_bd(BD_ADDR bd_addr);
extern tAVCT_LCB *avct_lcb_alloc(BD_ADDR bd_addr);
extern void avct_lcb_dealloc(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern UINT8 avct_lcb_to_idx(tAVCT_LCB *p_lcb);
extern tAVCT_LCB *avct_lcb_by_lcid(UINT16 lcid);
extern tAVCT_CCB *avct_lcb_has_pid(tAVCT_LCB *p_lcb, UINT16 pid);
extern BOOLEAN avct_lcb_last_ccb(tAVCT_LCB *p_lcb, tAVCT_CCB *p_ccb_last);

/* LCB action functions */
extern void avct_lcb_chnl_open(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_unbind_disc(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_open_ind(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_open_fail(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_close_ind(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_close_cfm(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_bind_conn(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_chk_disc(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_chnl_disc(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_bind_fail(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_cong_ind(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_discard_msg(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_send_msg(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_msg_ind(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);
extern void avct_lcb_free_msg_ind(tAVCT_LCB *p_lcb, tAVCT_LCB_EVT *p_data);

/* CCB function declarations */
extern tAVCT_CCB *avct_ccb_alloc(tAVCT_CC *p_cc);
extern void avct_ccb_dealloc(tAVCT_CCB *p_ccb, UINT8 event, UINT16 result, BD_ADDR bd_addr);
extern UINT8 avct_ccb_to_idx(tAVCT_CCB *p_ccb);
extern tAVCT_CCB *avct_ccb_by_idx(UINT8 idx);

/*****************************************************************************
** global data
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/* Main control block */
#if AVCT_DYNAMIC_MEMORY == FALSE
AVCT_API extern tAVCT_CB avct_cb;
#else
AVCT_API extern tAVCT_CB *avct_cb_ptr;
#define avct_cb (*avct_cb_ptr)
#endif

/* L2CAP callback registration structure */
extern const tL2CAP_APPL_INFO avct_l2c_appl;

#ifdef __cplusplus
}
#endif

#endif /* AVCT_INT_H */


