/*****************************************************************************
 *                                                                           *
 *  Name:          ctp_int.h                                                 *
 *                                                                           *
 *  Description:   this file contains internal definitions for CTP & ICP     *
 *                                                                           *
 *  Copyright (c) 2000-2004, WIDCOMM Inc., All Rights Reserved.              *
 *  WIDCOMM Bluetooth Core. Proprietary and confidential.                    *
 *****************************************************************************/
#ifndef CTP_INT_H
#define CTP_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/btm_api.h>
#include <private/bte/stack/ctp_api.h>
#include <private/bte/stack/sdp_api.h>

#define CTP_L2C_CONN_TIMEOUT    60                  /* for L2CAP connection */

#define CTP_NUM_EXTENDED_CHS    CTP_MAX_LINES + 2   /* GWTL_intercom + data exchange */
#define CTP_NUM_CHINFOS         CTP_NUM_EXTENDED_CHS + 2 /* allow 2 additional intercom */
#define CTP_INIT_TIMEOUT        3                   /* to read local bd_addr */
#define CTP_T400_TIMEOUT        604800              /* 1 week = 7 * 24 * 60 * 60 = 604800 sec */
#define CTP_TIMEOUT_T_IC            10              /* Incoming call timeout      */

/* status for wait for local bd_addr */
#define CTP_STATUS_FAILED  -1
#define CTP_STATUS_INIT     0
#define CTP_STATUS_SUCCESS  1
#define CTP_STATUS_WAITING  2

#define CTP_IS_GATEWAY      1
#define CTP_IS_TERMINAL     2

/* TL State machine events */
enum {
    CTP_GW_FOUND_TEVT,
    CTP_L2CAP_CONN_EST_TEVT,
    CTP_L2CAP_CONN_FAIL_TEVT,
#if TCS_WUG_MEMBER_INCLUDED == TRUE
    CTP_FIMA_CBACK_TEVT,
#endif
    CTP_CC_IND_TEVT,
    CTP_CONN_IND_TEVT,
    CTP_GW_NOT_FOUND_TEVT,
    CTP_NUM_TL_EVENTS
};
typedef UINT8 tCTP_TSM_EVENT;

/* TL State machine states */
enum {
    CTP_TST_NULL,
    CTP_TST_DISCOVERING_GW,
    CTP_TST_CONNECTING_TO_GW,
    CTP_TST_CONNECTED_LMTD_MODE,
    CTP_TST_CONNECTED_FULL_MODE,
#if TCS_WUG_MEMBER_INCLUDED == TRUE
    CTP_TST_WAIT_DETACH,
    CTP_TST_WAIT_INTERCOM,
    CTP_TST_INTERCOM_MODE,
#endif
    CTP_SM_RETURNED_TST
};
typedef UINT8 tCTP_TSM_STATE;

/* GW State machine events */
enum {
    CTP_L2CAP_CONN_EST_GEVT,
    CTP_L2CAP_CONN_FAIL_GEVT,
    CTP_L2CAP_CONN_DISC_GEVT,
    CTP_LINK_LOST_GEVT,
    CTP_LINK_ACT_TIMEOUT_GEVT,
    CTP_LINK_ACTIVITY_GEVT,
    CTP_NUM_GW_EVENTS
};
typedef UINT8 tCTP_GSM_EVENT;

/* GW State machine states */
enum {
    CTP_GST_CONNECTING,
    CTP_GST_CONNECTED_LMTD_MODE,
    CTP_GST_CONNECTED_FULL_MODE,
    CTP_GST_LOW_POWER_MODE,
    CTP_SM_RETURNED_GST
};
typedef UINT8 tCTP_GSM_STATE;

typedef struct
{
    UINT16           l2c_cid;
    UINT16           psm;
    BD_ADDR          remote_bda;
    UINT8            l2c_id;
} tCTP_CONN_IND;

typedef struct
{
    UINT16 tcs_cc_handle;
    UINT8 event_code;
    void * message;
} tCTP_CC_IND_INFO;

typedef struct
{
    UINT8 code;
    void *p_data;
} tCTP_FIMA_CB_INFO;

#define CTP_L2C_FLAGS_IN_USE            0x01
#define CTP_L2C_FLAGS_IS_ORIG           0x02
#define CTP_L2C_FLAGS_HIS_CFG_DONE      0x04
#define CTP_L2C_FLAGS_MY_CFG_DONE       0x08
#define CTP_L2C_FLAGS_RELEASING         0x10
#define CTP_L2C_STATE_CONN_SETUP        1
#define CTP_L2C_STATE_CFG_SETUP         2
#define CTP_L2C_STATE_CONNECTED         3
typedef struct
{
    UINT16           l2c_cid;
    UINT16           psm;
    BD_ADDR          remote_bda;
    UINT8            con_flags;
    UINT8            l2c_state;
    UINT8            index;
#if (TCS_WUG_MEMBER_INCLUDED == TRUE) || (TCS_WUG_MASTER_INCLUDED == TRUE)
    BOOLEAN          is_wug_res;
#endif /* TCS_WUG_MEMBER_INCLUDED == TRUE */
} tCTP_L2CH_CB;

typedef struct
{
    UINT16  cc_handle;
    UINT8   line_num;
    BOOLEAN used;
} tCTP_LINE_INFO;

typedef struct
{
    void          * p_data;         /* data pointer to state machine event handler */
    tCTP_L2CH_CB    l2c_resources[CTP_NUM_CHINFOS];/* L2CAP channel info */
    tCTP_L2CH_CB  * ic_res;         /* the channel for intercom */
    tCTP_L2CH_CB  * data_exchg_res; /* the channel for data exchange feature */
    tCTP_LINE_INFO  ctp_line_info[CTP_NUM_EXTENDED_CHS]; /* associate line number /w TCS CC handle */
    tCTP_GW_INFO    use_gw;         /* info of the connected gateway */
    tCTP_TL_REG_PARAMS reg_info;    /* info to search for the gateway */
    TIMER_LIST_ENT  tl_tle;
    UINT32          icp_sdp_hdl;    /* SDP record handle for ICP service */
    BD_ADDR         fima_bda;       /* the address to page for fima process */
    UINT8           fima_code;      /* the code for TCS fima callback */
    UINT8           fima_detach;    /* detach from GW or not during FIMA */
    UINT8           index;          /* index of this entry */
    UINT8           ctp_state;      /* CTP state */
    UINT8           prev_state;     /* the state before CTP went into intercom mode */
    UINT8           full_resources; /* total number of L2CAP channels possible */
    UINT8           num_active_l2ch;/* number of active L2CAP channel */
    UINT8           num_active_call;/* number of active CALLS */
    BOOLEAN         data_exchg_flag;/* if data exchanges channel is on */
#if (CTP_RETRY_ON_CONN_ERR > 0)
    UINT8           num_retry;
#endif
#if CTP_DISCOVERY_INCLUDED == TRUE
    BOOLEAN         inq_in_progress;/* inquiry is in progress or not */
#endif
} tCTP_TL_CTB;

#define CTP_WUG_NO_LOW_MODE    0x00
#define CTP_WUG_SNIFF_MODE     0x01
#define CTP_WUG_PARK_MODE      0x02
#define CTP_FAILED  -1
#define CTP_WAITING  2
typedef struct
{
    void          * p_data;         /* data pointer to state machine event handler */
    tCTP_L2CH_CB    l2c_resources[CTP_NUM_CHINFOS]; /* L2CAP channel info */
    tCTP_L2CH_CB  * data_exchg_res; /* the channel for data exchange feature */
    tCTP_LINE_INFO  ctp_line_info[CTP_NUM_EXTENDED_CHS]; /* associate line number /w TCS CC handle */
    TIMER_LIST_ENT  link_tle;       /* l2cap timeout & link activity */
    TIMER_LIST_ENT  init_tle;       /* get link policy */
    BD_ADDR         bda;            /* address of connected TL */
    UINT8           index;          /* index of this entry */
    BOOLEAN         used;           /* if this entry is used */
    UINT8           ctp_state;      /* CTP state */
    UINT8           prev_state;     /* the state before CTP went into low power mode */
    UINT8           full_resources; /* total number of L2CAP channels possible */
    BOOLEAN         connected;      /* report connected status */
    UINT8           num_active_l2ch;/* number of active L2CAP channel */
    BOOLEAN         data_exchg_flag;/* if data exchanges channel is on */
    UINT8           low_mode; /* get the supported modes of the ACL link */
    UINT8           use_mode; /* get the low power modes to use: idle - park/sniff, during a call - sniff */
    INT8            got_link_policy;    /* if the link policy for this connection is retrieved */
    INT8            num_sco_bearer; /* number of active SCO bearer */
    INT8            num_acl_bearer; /* number of active ACL bearer */
} tCTP_TL_INFOB;

typedef struct
{
    tCTP_TL_INFOB   tl_info[CTP_MAX_NUM_TLS]; /* information for TLs */
    tCTP_GW_REG_PARAMS reg_info;    /* registration info from application */
    UINT32          ctp_sdp_hdl;    /* SDP record handle for CTP service */
    UINT8           num_active_call;/* number of active calls */
    UINT8           num_tl;         /* number of connected TL */
#if BTM_PWR_MGR_INCLUDED == TRUE
    UINT8           pm_id;
#endif
} tCTP_GW_CTB;

typedef struct
{
    tSDP_DISCOVERY_DB   *p_sdp_db;  /* Pointer to the discovery database */
    tBTM_INQ_RESULTS    *p_inq_db;  /* Pointer to the inquiry results database */
    UINT8                num_results; /* Points to the current device being saved or searched */
    UINT8                cur_inq_index; /* Index into current device being saved or retrieved */
} tCTP_Discovery;

typedef struct
{
#if CTP_TL_INCLUDED == TRUE
    tCTP_TL_CTB     tl;     /* TL control block */

#if CTP_DISCOVERY_INCLUDED == TRUE
    tCTP_Discovery  disc;
#endif
#endif  /* CTP_TL_INCLUDED */

#if CTP_GW_INCLUDED == TRUE
    tCTP_GW_CTB     gw;     /* GW control block */
#endif
    UINT8           trace_level;
} tCTP_CB;

/* for BTU mbox message */
typedef struct
{
    UINT16          event;
    UINT16          len;
    tCTP_TL_CTB    *cb;
    BD_ADDR         bda;
    UINT16          psm;
} tCTP_RETRY_DATA;


#ifdef __cplusplus
extern "C"
{
#endif
/*
** Define prototypes for global data
*/
#if CTP_DYNAMIC_MEMORY == FALSE
CTP_API extern tCTP_CB  ctp_cb;
#else
CTP_API extern tCTP_CB *ctp_cb_ptr;
#define ctp_cb (*ctp_cb_ptr)
#endif

extern tL2CAP_CFG_INFO ctp_l2c_icfg;

/* ctp_utils.c */
extern UINT8 ctp_get_full_resources(void);
extern void ctp_process_timeout (TIMER_LIST_ENT  *p_tle);
extern void ctpu_release_chcb (tCTP_L2CH_CB *p_chcb, UINT8 type, void *cb);
extern tCTP_L2CH_CB *ctpu_allocate_chcb (BD_ADDR p_bda, UINT16 psm, tCTP_L2CH_CB *pool, UINT8 *counter);
extern void ctpu_timer_start (TIMER_LIST_ENT *p_tle, UINT16 type, UINT32 timeout);
extern void ctpu_timer_stop (TIMER_LIST_ENT *p_tle);
extern UINT8 ctpu_find_line_by_handle(UINT16 tcs_cc_handle, tCTP_LINE_INFO *pool);
extern void ctp_exec_mbox_evt(tCTP_RETRY_DATA *p_msg);
#if (CTP_RETRY_ON_CONN_ERR > 0)
extern tCTP_STATUS ctp_snd_mbox_retry_evt(tCTP_TL_CTB *cb, BD_ADDR p_bda, UINT16 psm);
#endif

extern tCTP_L2CH_CB *ctpu_find_chcb_by_cid (UINT16 cid, tCTP_L2CH_CB *pool);
#if CTP_TL_INCLUDED == TRUE
extern void ctp_reset_tl(tCTP_TL_CTB *cb);
extern void ctp_add_extended_resources(tCTP_TL_CTB *cb);
extern UINT8 ctpu_tl_l2c_sts(void);
#endif /* CTP_TL_INCLUDED == TRUE */

#if CTP_GW_INCLUDED == TRUE
extern void ctpu_update_idle_timer(tCTP_TL_INFOB *cb);
extern void ctp_init_gw_cb(tCTP_GW_INFO *p_gw_info);
extern void ctp_reset_tl_info(tCTP_TL_INFOB *cb);
extern void ctp_update_num_tls(void);
extern void ctp_link_policy_cb(tBTM_LNK_POLICY_RESULTS *p_result);
extern tCTP_TL_INFOB * ctpu_gw_find_tl_info_by_addr(BD_ADDR bd_addr);
extern tCTP_L2CH_CB * ctpu_gw_find_chcb_by_cid(UINT16 cid, tCTP_TL_INFOB **p_cb);
extern UINT8 ctpu_gw_find_line_by_handle(UINT16 tcs_cc_handle, tCTP_TL_INFOB **p_cb);
extern void ctpu_save_bearer_info(tCTP_TL_INFOB *cb, tTCS_BEARER_ID *p_id);
extern void ctpu_release_bearer_info(tCTP_TL_INFOB *cb, tTCS_BEARER_ID *p_id);
#endif /* CTP_GW_INCLUDED == TRUE */

extern tCTP_STATUS ctpu_alloc_line_info(UINT8 line, UINT16 tcs_cc_handle, tCTP_LINE_INFO *pool);
extern void ctpu_release_line_info(UINT16 tcs_cc_handle, tCTP_LINE_INFO *pool);
extern void ctpu_device_class(BOOLEAN set);


/*  ctp_discovery.c */
#if CTP_DISCOVERY_INCLUDED == TRUE
extern void ctp_init_disc_db(void);
extern void ctp_free_disc_db (void);
extern void ctp_discover_next(void);
extern tCTP_STATUS ctp_initiate_discovery(tCTP_GW_INFO *p_gw_info);
#endif
#if ICP_INCLUDED == FALSE
extern tCTP_STATUS ctp_reg_ic_sdp_service(UINT8 * service_name, UINT8  *provider_name, UINT32 * sdp_handle);
#endif /* ICP_INCLUDED == FALSE */

/* ctp_tsm.c */
extern UINT8 ctp_del_tl_instance( tCTP_TL_CTB *cb );
extern tCTP_TSM_STATE ctp_clean_tl_cblk( tCTP_TL_CTB *cb, tCTP_CBACK_STS sts );
extern void ctp_tlsm_alloc(tCTP_TL_CTB *cb);
extern tCTP_STATUS ctp_tlsm_handle_event(tCTP_TL_CTB *cb, UINT8 event, void *data);
extern tCTP_TSM_STATE ctp_reconnect_to_gw( tCTP_TL_CTB *cb );
extern void ctp_reestab_timeout( tCTP_TL_CTB *cb );
extern void ctp_start_fima(tCTP_TL_CTB *cb);

extern tCTP_STATUS ctp_reg_sdp_db(tCTP_GW_INFO *gw_info);
extern UINT16 icp_reg_sdp_db(UINT8 *service_name);

/* ctp_tl2c.c */
extern BOOLEAN ctp_l2c_conn_originate (tCTP_L2CH_CB *p_tlcb);
extern void ctp_l2c_disconnect (tCTP_L2CH_CB *p_chcb);
extern void ctp_tl_l2c_rej(tCTP_CONN_IND *p_conn_st);
extern void ctp_tl_l2c_conn_resp(tCTP_L2CH_CB *p_chcb, tCTP_CONN_IND * p_conn_st);

/* ctp_gl2c.c */
extern void ctp_gw_l2c_disconnect (tCTP_L2CH_CB *p_chcb, tCTP_TL_INFOB *cb);

/* ctp_gsm.c */
extern UINT8 ctp_free_tl_infob( tCTP_TL_INFOB *cb );
extern void ctp_gwsm_alloc(tCTP_TL_INFOB *cb);
extern void ctp_gwsm_handle_event(tCTP_TL_INFOB *cb, UINT8 event, void *data);

/* ctp_ttcs.c */
extern void ctp_tl_cc_cback(UINT16 tcs_cc_handle, UINT8 event_code, void * message);
#if TCS_WUG_MEMBER_INCLUDED == TRUE
extern void ctp_fima_cback(UINT8 code, void *p_data);
#endif /* TCS_WUG_MEMBER_INCLUDED == TRUE */

/* ctp_gtcs.c */
extern void ctp_gw_cc_cback(UINT16 tcs_cc_handle, UINT8 event_code, void * message);
extern void ctp_access_cback (BD_ADDR addr, tTCS_IE_CO_SPEC *p_cs);

extern const tL2CAP_APPL_INFO ctp_tl_l2c_cbacks;
extern const tL2CAP_APPL_INFO ctp_gw_l2c_cbacks;

#if CTP_DATA_EXCHG_FEATURE == TRUE
extern const tL2CAP_APPL_INFO ctp_td_l2c_cbacks;
extern void ctp_td_l2c_data_ind (UINT16 l2cap_cid, BT_HDR *p_msg);
extern const tL2CAP_APPL_INFO ctp_gd_l2c_cbacks;
extern void ctp_gd_l2c_data_ind (UINT16 l2cap_cid, BT_HDR *p_msg);
#endif

#if (BT_TRACE_VERBOSE == TRUE)
extern char *ctpu_get_tcs_evt_str (UINT8 evt_id);
#else
#define ctpu_get_tcs_evt_str(ff)    ""
#endif

#ifdef __cplusplus
}
#endif

#endif /* CTP_INT_H */
