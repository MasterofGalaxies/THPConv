/*****************************************************************************
 *                                                                           *
 *  Name:          icp_int.h                                                 *
 *                                                                           *
 *  Description:   this file contains internal definitions for ICP           *
 *                                                                           *
 *  Copyright (c) 2000-2005, WIDCOMM Inc., All Rights Reserved.              *
 *  WIDCOMM Bluetooth Core. Proprietary and confidential.                    *
 *****************************************************************************/
#ifndef ICP_INT_H
#define ICP_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/btm_api.h>
#include <private/bte/stack/icp_api.h>

/* from TCS */
#define ICP_L2C_CONN_TIMEOUT        60
#define ICP_TIMEOUT_READ_BDADDR      3
#define ICP_TIMEOUT_T_IC            10         /* Incoming call timeout      */

#define ICP_INVALID_TLCB_INDEX      0xFF
#define ICP_INVALID_HANDLE          0xFFFF
#define ICP_NUM_CHINFOS             1           /* we allow only 1 intercom call in this version */

/* move to target.h */
#define ICP_MAX_NUM_TLS             7
#define ICP_DATA_SEC_SRV_ID         20

/* State machine events */
enum {
    ICP_CC_CALL_ALERT,  /* ConfirmCall  */
    ICP_CC_CALL_DISC,   /* EndCall      */
    ICP_CC_CALL_CONNECT,/* AcceptCall   */
    ICP_CC_CALL_ACTIVE, /* ConfirmConnect */
    ICP_CC_CALL_INIT,   /* InitiateCall */
    ICP_CC_CALL_INFO,   /* sendInfo     */
    ICP_NUM_CC_EVENTS
};
typedef UINT8 tICP_CC_EVENT;

enum {
    ICP_EVT_CC_ALERT,
    ICP_EVT_CC_END,
    ICP_EVT_CC_ACCEPT,
    ICP_EVT_CC_CACK,
    ICP_EVT_CC_INIT,
    ICP_EVT_CC_INFO,
    ICP_EVT_CC_IND,
    ICP_EVT_CONN_EST,
    ICP_EVT_CONN_IND,
    ICP_EVT_LINK_LOST,
    ICP_EVT_TIMEOUT,
    ICP_NUM_EVENTS
};
typedef UINT8 tICP_SM_EVENT;

/* State machine states */
enum
{
    ICP_ST_IDLE,
    ICP_ST_CONNECTING,
    ICP_ST_CONNECTED,
    ICP_ST_ACTIVE,
    ICP_ST_DISC,
    ICP_SM_RETURNED_ST
};
typedef UINT8 tICP_SM_STATE;

typedef struct
{
    UINT16           l2c_cid;
    UINT16           psm;
    BD_ADDR          remote_bda;
    UINT8            l2c_id;
} tICP_CONN_IND;

typedef struct
{
    void *p_data;
    UINT8 event;
} tICP_CC_INFO;

/* 2nd byte of bearer msg type info array (for e(SCO)) overloaded for msg state */
#define ICP_BEAR_NOT_ESTABLISHED        0
#define ICP_BEAR_ESTABLISHING           1
#define ICP_BEAR_ESTABLISHED            2

#define ICP_L2C_FLAGS_IN_USE            0x01
#define ICP_L2C_FLAGS_IS_ORIG           0x02
#define ICP_L2C_FLAGS_HIS_CFG_DONE      0x04
#define ICP_L2C_FLAGS_MY_CFG_DONE       0x08
#define ICP_L2C_STATE_CONN_SETUP        1
#define ICP_L2C_STATE_CFG_SETUP         2
#define ICP_L2C_STATE_CONNECTED         3
typedef struct
{
    UINT16           l2c_cid;
    UINT16           psm;
    void           * p_data;
    BD_ADDR          remote_bda;
    UINT8            index;
    UINT8            con_flags;
    UINT8            l2c_state;
} tICP_L2CH_CB;

#define ICP_SM_DATA_LEN   12      /* 12 is the minumum */

#define ICP_INFO_BEAR       0x01
#define ICP_INFO_CS         0x02

typedef struct
{
    void           *p_data;         /* data pointer to state machine event handler */
    tICP_STS_CBACK *sts_cback;      /* the callback to notify application of ICP events */
    UINT32          sdp_handle;     /* SDP handle */
    TIMER_LIST_ENT  ic_tle;         /* the timer for IC100 */
    tICP_L2CH_CB    l2c_resources[ICP_NUM_CHINFOS]; /* the L2CAP channel info for intercom call */
    tTCS_IE_BEARER_CAP  bear;       /* the bearer capability from ICP_InitiateCall() */
    tTCS_IE_CO_SPEC     cs;         /* the company specific IE from ICP_InitiateCall() */
    UINT16          cc_handle;      /* TCS CC handle */
    tICP_SM_STATE   icp_state;      /* ICP state */
    UINT8           trace_level;    /* debug trace level */
    BOOLEAN         regd;           /* is registered or not */
    BOOLEAN         is_orig;        /* is originator of the intercom call or not */
    UINT8           call_info_mask; /* to indicate which parameters of ICP_InitiateCall() contains valid values */
} tICP_CB;

#ifdef __cplusplus
extern "C"
{
#endif
/*
** Define prototypes for global data
*/
#if ICP_DYNAMIC_MEMORY == FALSE
ICP_API extern tICP_CB  icp_cb;
#else
ICP_API extern tICP_CB *icp_cb_ptr;
#define icp_cb (*icp_cb_ptr)
#endif

extern const tL2CAP_APPL_INFO icp_l2c_cbacks;

/* icp_utils.c */
extern tICP_STATUS icp_reg_sdp_service(UINT8 * service_name,
                                       UINT8  *provider_name,
                                       UINT32 * sdp_handle);
extern void icp_process_timeout (TIMER_LIST_ENT  *p_tle);
extern void icpu_allocate_chcb (BD_ADDR p_bda, UINT16 psm);
extern void icpu_release_chcb (void);
extern void icp_cc_cback(UINT16 tcs_cc_handle, UINT8 event_code, void * message);

/* icp_l2c.c */
extern BOOLEAN icp_l2c_conn_originate (tICP_L2CH_CB *p_chcb);
extern void icp_l2c_conn_resp(tICP_L2CH_CB *p_chcb, tICP_CONN_IND * p_conn_st);
extern void icp_l2c_disconnect (tICP_L2CH_CB  *p_chcb);

/* icp_cm.c */
extern void icp_sm_alloc(tICP_CB *cb);
extern tICP_STATUS icp_sm_handle_event(UINT8 event, void *data);

#ifdef __cplusplus
}
#endif

#endif /* ICP_INT_H */
