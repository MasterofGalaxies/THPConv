/*****************************************************************************
**
**  Name:           bta_dm_int.h
**
**  Description:    This is the private interface file for the BTA device
**                  manager.
**
**  Copyright (c) 2003, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_DM_INT_H
#define BTA_DM_INT_H




/*****************************************************************************
**  Constants and data types
*****************************************************************************/


#define BTA_COPY_DEVICE_CLASS(coddst, codsrc)   {((UINT8 *)(coddst))[0] = ((UINT8 *)(codsrc))[0]; \
                                                 ((UINT8 *)(coddst))[1] = ((UINT8 *)(codsrc))[1];  \
                                                 ((UINT8 *)(coddst))[2] = ((UINT8 *)(codsrc))[2];}


#define BTA_DM_MSG_LEN 50

#ifndef BTA_DM_REMOTE_DEVICE_NAME_LENGTH
#define BTA_DM_REMOTE_DEVICE_NAME_LENGTH 32
#endif

#define BTA_SERVICE_ID_TO_SERVICE_MASK(id)       (1 << (id))


/* DM events */
enum
{
    /* device manager local device API events */
    BTA_DM_API_ENABLE_EVT = BTA_SYS_EVT_START(BTA_ID_DM),
    BTA_DM_API_DISABLE_EVT,
    BTA_DM_API_SET_NAME_EVT,
    BTA_DM_API_SET_VISIBILITY_EVT,
    BTA_API_DM_SIG_STRENGTH_EVT,
    BTA_DM_ACL_CHANGE_EVT,

    /* security API events */
    BTA_DM_API_BOND_EVT,
    BTA_DM_API_PIN_REPLY_EVT,
    BTA_DM_API_AUTH_REPLY_EVT,

    /* power manger events */
    BTA_DM_PM_BTM_STATUS_EVT,
    BTA_DM_PM_TIMER_EVT,

    /* Nintendo specific event */
    BTA_DM_API_KEEP_ACL_EVT,
    BTA_DM_API_SEND_HCI_RESET_EVT
};


/* DM search events */
enum
{
    /* DM search API events */
    BTA_DM_API_SEARCH_EVT = BTA_SYS_EVT_START(BTA_ID_DM_SEARCH),
    BTA_DM_API_SEARCH_CANCEL_EVT,
    BTA_DM_API_DISCOVER_EVT,
    BTA_DM_INQUIRY_CMPL_EVT,
    BTA_DM_REMT_NAME_EVT,
    BTA_DM_REMT_NAME_TOUT_EVT,
    BTA_DM_SDP_RESULT_EVT,
    BTA_DM_SEARCH_CMPL_EVT,
    BTA_DM_DISCOVERY_RESULT_EVT


};

/* data type for BTA_DM_API_ENABLE_EVT */
typedef struct
{
    BT_HDR              hdr;      
    tBTA_DM_SEC_CBACK *p_sec_cback;
} tBTA_DM_API_ENABLE;

/* data type for BTA_DM_API_SET_NAME_EVT */
typedef struct
{
    BT_HDR              hdr;      
    char    name[BTA_DM_REMOTE_DEVICE_NAME_LENGTH];
} tBTA_DM_API_SET_NAME;

/* data type for BTA_DM_API_SET_VISIBILITY_EVT */
typedef struct
{
    BT_HDR              hdr;      
    tBTA_DM_DISC    disc_mode;
    tBTA_DM_CONN    conn_mode;
} tBTA_DM_API_SET_VISIBILITY;
 
/* data type for BTA_DM_API_SEARCH_EVT */
typedef struct
{
    BT_HDR      hdr;  
    tBTA_DM_INQ inq_params;
    tBTA_SERVICE_MASK services;
    tBTA_DM_SEARCH_CBACK * p_cback;

} tBTA_DM_API_SEARCH;

/* data type for BTA_DM_API_DISCOVER_EVT */
typedef struct
{
    BT_HDR      hdr;  
    BD_ADDR bd_addr;
    tBTA_SERVICE_MASK services;
    tBTA_DM_SEARCH_CBACK * p_cback;

} tBTA_DM_API_DISCOVER;

/* data type for BTA_DM_API_BOND_EVT */
typedef struct
{
    BT_HDR      hdr;  
    BD_ADDR bd_addr;
    UINT8 pin_len;
    UINT8 p_pin[PIN_CODE_LEN];
} tBTA_DM_API_BOND;

/* data type for BTA_DM_API_PIN_REPLY_EVT */
typedef struct
{
    BT_HDR      hdr;  
    BD_ADDR bd_addr;
    BOOLEAN accept;
    UINT8 pin_len;
    UINT8 p_pin[PIN_CODE_LEN];
} tBTA_DM_API_PIN_REPLY;


/* data type for BTA_DM_API_AUTH_REPLY_EVT */
typedef struct
{
    BT_HDR      hdr;  
    BD_ADDR bd_addr;
    tBTA_SERVICE_ID service;
    tBTA_AUTH_RESP response;
} tBTA_DM_API_AUTH_REPLY;

/* data type for BTA_DM_REMT_NAME_EVT */
typedef struct
{
    BT_HDR      hdr;  
    tBTA_DM_SEARCH  result;
} tBTA_DM_REM_NAME;

/* data type for tBTA_DM_DISC_RESULT */
typedef struct
{
    BT_HDR      hdr;  
    tBTA_DM_SEARCH  result;
} tBTA_DM_DISC_RESULT;


/* data type for BTA_DM_INQUIRY_CMPL_EVT */
typedef struct
{
    BT_HDR      hdr;  
    UINT8       num;
} tBTA_DM_INQUIRY_CMPL;

/* data type for BTA_DM_SDP_RESULT_EVT */
typedef struct
{
    BT_HDR      hdr;  
    UINT16 sdp_result;
} tBTA_DM_SDP_RESULT;

/* data type for BTA_API_DM_SIG_STRENGTH_EVT */
typedef struct
{
    BT_HDR      hdr;  
    tBTA_SIG_STRENGTH_MASK mask; 
    UINT16 period;
    BOOLEAN start;
} tBTA_API_DM_SIG_STRENGTH;

/* data type for BTA_DM_ACL_CHANGE_EVT */
typedef struct
{
    BT_HDR      hdr;  
    tBTM_BL_EVENT       event;
    UINT8               busy_level;
    BOOLEAN is_new;
    BD_ADDR bd_addr;
} tBTA_DM_ACL_CHANGE;

/* data type for BTA_DM_PM_BTM_STATUS_EVT */
typedef struct
{

    BT_HDR          hdr;
    BD_ADDR         bd_addr;
    tBTM_PM_STATUS  status;
    UINT16          value;
    UINT8           hci_status;

} tBTA_DM_PM_BTM_STATUS;

/* data type for BTA_DM_PM_TIMER_EVT */
typedef struct
{
    BT_HDR          hdr;
    BD_ADDR         bd_addr;

} tBTA_DM_PM_TIMER;


/* union of all data types */
typedef union
{
    /* GKI event buffer header */
    BT_HDR              hdr;      
    tBTA_DM_API_ENABLE  enable;
    
    tBTA_DM_API_SET_NAME set_name;

    tBTA_DM_API_SET_VISIBILITY set_visibility;

    tBTA_DM_API_SEARCH search;

    tBTA_DM_API_DISCOVER discover;

    tBTA_DM_API_BOND bond;

    tBTA_DM_API_PIN_REPLY pin_reply;

    tBTA_DM_API_AUTH_REPLY auth_reply;

    tBTA_DM_REM_NAME rem_name;

    tBTA_DM_DISC_RESULT disc_result;

    tBTA_DM_INQUIRY_CMPL inq_cmpl;

    tBTA_DM_SDP_RESULT sdp_event;

    tBTA_API_DM_SIG_STRENGTH sig_strength;

    tBTA_DM_ACL_CHANGE  acl_change;

    tBTA_DM_PM_BTM_STATUS pm_status;

    tBTA_DM_PM_TIMER pm_timer;


} tBTA_DM_MSG;


#define BTA_DM_NUM_PEER_DEVICE 7

#define BTA_DM_NOT_CONNECTED  0
#define BTA_DM_CONNECTED      1

typedef UINT8 tBTA_DM_CONN_STATE;




typedef struct
{
    BD_ADDR                     peer_bdaddr;
    tBTA_DM_CONN_STATE          conn_state;
    tBTA_PREF_ROLES             pref_role;
    BOOLEAN                     in_use;
    tBTA_DM_PM_ACTTION          pm_mode_attempted;
    tBTA_DM_PM_ACTTION          pm_mode_failed;

} tBTA_DM_PEER_DEVICE;



/* structure to store list of
  active connections */
typedef struct
{
    tBTA_DM_PEER_DEVICE    peer_device[BTA_DM_NUM_PEER_DEVICE];
    UINT8                  count;

} tBTA_DM_ACTIVE_LINK;


typedef struct
{
    BD_ADDR                 peer_bdaddr;
    tBTA_SYS_ID             id;
    UINT8                   app_id;
    tBTA_SYS_CONN_STATUS    state;


} tBTA_DM_SRVCS;

#define BTA_DM_NUM_CONN_SRVS   5

typedef struct
{

    UINT8 count;
    tBTA_DM_SRVCS  conn_srvc[BTA_DM_NUM_CONN_SRVS];

}  tBTA_DM_CONNECTED_SRVCS;

typedef struct 
{
    TIMER_LIST_ENT          timer; 
    BD_ADDR                 peer_bdaddr;
    BOOLEAN                 in_use;

} tBTA_PM_TIMER;

extern tBTA_DM_CONNECTED_SRVCS bta_dm_conn_srvcs;

#define BTA_DM_NUM_PM_TIMER 3

/* DM control block */
typedef struct
{

    tBTA_DM_ACTIVE_LINK         device_list;
    tBTA_DM_SEC_CBACK           *p_sec_cback;
    TIMER_LIST_ENT              signal_strength_timer;
    tBTA_SIG_STRENGTH_MASK      signal_strength_mask;
    UINT16                      state;
    UINT16                      signal_strength_period;
    BOOLEAN                     disabling;
    TIMER_LIST_ENT              disable_timer;
    UINT8                       num_master_only;
    UINT32                      wbt_sdp_handle;          /* WIDCOMM Extensions SDP record handle */
    UINT8                       wbt_scn;                 /* WIDCOMM Extensions SCN */
    UINT8                       pm_id;
    tBTA_PM_TIMER               pm_timer[BTA_DM_NUM_PM_TIMER];

    /* Storage for pin code request parameters */
    BD_ADDR                     pin_bd_addr;
    DEV_CLASS                   pin_dev_class;
    BOOLEAN                     keep_acl_on_shut_down;

} tBTA_DM_CB;

#ifndef BTA_DM_SDP_DB_SIZE
#define BTA_DM_SDP_DB_SIZE 250
#endif

/* DM search control block */
typedef struct
{

    tBTA_DM_SEARCH_CBACK * p_search_cback;
    tBTM_INQ_INFO        * p_btm_inq_info;
    tBTA_SERVICE_MASK      services;
    tBTA_SERVICE_MASK      services_to_search;
    tBTA_SERVICE_MASK      services_found;
    tSDP_DISCOVERY_DB    * p_sdp_db;
    UINT16                 state;
    BD_ADDR                peer_bdaddr;
    char                   peer_name[BTA_DM_REMOTE_DEVICE_NAME_LENGTH];
    TIMER_LIST_ENT         search_timer;
    TIMER_LIST_ENT         rnr_timer;
    UINT8                  service_index;
    tBTA_DM_MSG          * p_search_queue;   /* search or discover commands during search cancel stored here */
    BOOLEAN                wait_disc;
    BOOLEAN                sdp_results;


} tBTA_DM_SEARCH_CB;

/* DM search state */
enum
{

    BTA_DM_SEARCH_IDLE,
    BTA_DM_SEARCH_ACTIVE,
    BTA_DM_SEARCH_CANCELLING,
    BTA_DM_DISCOVER_ACTIVE

};



typedef struct
{
    DEV_CLASS      dev_class;          /* local device class */
    UINT16         policy_settings;    /* link policy setting hold, sniff, park, MS switch */
    UINT16         page_timeout;       /* timeout for page in slots */
    UINT16         link_timeout;       /* link supervision timeout in slots */

} tBTA_DM_CFG;

extern const UINT32 bta_service_id_to_btm_srv_id_lkup_tbl[];

extern const tBTA_DM_CFG bta_dm_cfg;



#define BTA_ALL_APP_ID 0xff

typedef struct
{
    UINT8   id;
    UINT8   app_id;
    UINT8   cfg;

} tBTA_DM_RM ;

extern tBTA_DM_CFG *p_bta_dm_cfg;
extern tBTA_DM_RM *p_bta_dm_rm_cfg;

#define BTA_DM_NUM_COMPRESS_ENTRY    5
#define BTA_DM_COMPRESS_ENABLE        0x01      
#define BTA_DM_COMPRESS_DISALLOW      0x02

/*
 * indicate which BTA SYS can be compressed 
 */
typedef struct
{
    UINT8   id;
    UINT8   app_id;
    UINT8   mask;  /* enable or disallow */

} tBTA_DM_COMPRESS;

extern tBTA_DM_COMPRESS *p_bta_dm_compress_cfg;

/* 
 * Runtime BTA SYS compress state 
 */
typedef struct
{
    BD_ADDR                 peer_bdaddr;
    tBTA_SYS_ID             id;
    UINT8                   app_id;
    tBTA_SYS_CONN_STATUS    state;

} tBTA_DM_COMPRESS_SRVCS;
    

typedef struct
{

  UINT8  id;
  UINT8  app_id;
  UINT8  spec_idx;  /* index of spec table to use */

} tBTA_DM_PM_CFG;


typedef struct
{

  tBTA_DM_PM_ACTTION  power_mode;
  UINT16              timeout;

} tBTA_DM_PM_ACTN;

typedef struct
{

  UINT8  allow_mask;         /* mask of sniff/hold/park modes to allow */
  tBTA_DM_PM_ACTN actn_tbl [BTA_DM_PM_NUM_EVTS][2];

} tBTA_DM_PM_SPEC;


extern tBTA_DM_PM_CFG *p_bta_dm_pm_cfg;
extern tBTA_DM_PM_SPEC *p_bta_dm_pm_spec;
extern tBTM_PM_PWR_MD *p_bta_dm_pm_md;

/* DM control block */
#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_DM_CB  bta_dm_cb;
#else
extern tBTA_DM_CB *bta_dm_cb_ptr;
#define bta_dm_cb (*bta_dm_cb_ptr)
#endif

/* DM search control block */
#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_DM_SEARCH_CB  bta_dm_search_cb;
#else
extern tBTA_DM_SEARCH_CB *bta_dm_search_cb_ptr;
#define bta_dm_search_cb (*bta_dm_search_cb_ptr)
#endif

extern BOOLEAN bta_dm_sm_execute(BT_HDR *p_msg);
extern BOOLEAN bta_dm_search_sm_execute(BT_HDR *p_msg);

extern void bta_dm_enable (tBTA_DM_MSG *p_data);
extern void bta_dm_disable (tBTA_DM_MSG *p_data);       
extern void bta_dm_set_dev_name (tBTA_DM_MSG *p_data);
extern void bta_dm_set_visibility (tBTA_DM_MSG *p_data);
extern void bta_dm_bond (tBTA_DM_MSG *p_data);         
extern void bta_dm_pin_reply (tBTA_DM_MSG *p_data);     
extern void bta_dm_auth_reply (tBTA_DM_MSG *p_data);    
extern void bta_dm_signal_strength(tBTA_DM_MSG *p_data);
extern void bta_dm_acl_change(tBTA_DM_MSG *p_data); 
extern void bta_dm_keep_acl(tBTA_DM_MSG *p_data);
extern void bta_dm_send_hci_reset(tBTA_DM_MSG *p_data);

extern void bta_dm_pm_btm_status(tBTA_DM_MSG *p_data);
extern void bta_dm_pm_timer(tBTA_DM_MSG *p_data);
extern void bta_dm_init_pm(void);
extern void bta_dm_disable_pm(void);

extern void bta_dm_search_start (tBTA_DM_MSG *p_data); 
extern void bta_dm_search_cancel (tBTA_DM_MSG *p_data);
extern void bta_dm_discover (tBTA_DM_MSG *p_data);              
extern void bta_dm_inq_cmpl (tBTA_DM_MSG *p_data);
extern void bta_dm_rmt_name (tBTA_DM_MSG *p_data);
extern void bta_dm_sdp_result (tBTA_DM_MSG *p_data);
extern void bta_dm_search_cmpl (tBTA_DM_MSG *p_data);
extern void bta_dm_free_sdp_db (tBTA_DM_MSG *p_data);
extern void bta_dm_disc_result (tBTA_DM_MSG *p_data);
extern void bta_dm_search_result (tBTA_DM_MSG *p_data);
extern void bta_dm_discovery_cmpl (tBTA_DM_MSG *p_data);
extern void bta_dm_queue_search (tBTA_DM_MSG *p_data);
extern void bta_dm_queue_disc (tBTA_DM_MSG *p_data);
extern void bta_dm_search_clear_queue (tBTA_DM_MSG *p_data);
extern void bta_dm_search_cancel_cmpl (tBTA_DM_MSG *p_data);
extern void bta_dm_search_cancel_notify (tBTA_DM_MSG *p_data);
extern void bta_dm_search_cancel_transac_cmpl(tBTA_DM_MSG *p_data);
extern void bta_dm_disc_rmt_name (tBTA_DM_MSG *p_data);
extern void bta_dm_cancel_rmt_name(tBTA_DM_MSG *p_data);

#endif /* BTA_DM_INT_H */

