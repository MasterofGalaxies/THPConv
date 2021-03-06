/*****************************************************************************
**
**  Name:           bta_ag_int.h
**
**  Description:    This is the private interface file for the BTA audio
**                  gateway.
**
**  Copyright (c) 2003-2005, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_AG_INT_H
#define BTA_AG_INT_H

#include <private/bte/bta/bta_sys.h>
#include <private/bte/bta/bta_api.h>
#include <private/bte/bta/bta_ag_api.h>
#include <private/bte/bta/bta_ag_at.h>

/*****************************************************************************
**  Constants
*****************************************************************************/
#define HFP_VERSION_1_1         0x0101
#define HFP_VERSION_1_5         0x0105

/* Number of SCBs (AG service instances that can be registered) */
#ifndef BTA_AG_NUM_SCB
#define BTA_AG_NUM_SCB          2
#endif


/* RFCOMM MTU SIZE */
#define BTA_AG_MTU              256

/* Internal profile indexes */
#define BTA_AG_HSP              0       /* index for HSP */
#define BTA_AG_HFP              1       /* index for HFP */
#define BTA_AG_NUM_IDX          2       /* number of profile indexes */

/* profile role for connection */
#define BTA_AG_ACP              0       /* accepted connection */
#define BTA_AG_INT              1       /* initiating connection */

/* feature mask that matches spec */
#define BTA_AG_BSRF_FEAT_SPEC        (BTA_AG_FEAT_3WAY | BTA_AG_FEAT_ECNR    | \
                                      BTA_AG_FEAT_VREC | BTA_AG_FEAT_INBAND  | \
                                      BTA_AG_FEAT_VTAG | BTA_AG_FEAT_REJECT  | \
                                      BTA_AG_FEAT_ECS  | BTA_AG_FEAT_ECC     | \
                                      BTA_AG_FEAT_EXTERR)

#define BTA_AG_SDP_FEAT_SPEC         (BTA_AG_FEAT_3WAY | BTA_AG_FEAT_ECNR    | \
                                      BTA_AG_FEAT_VREC | BTA_AG_FEAT_INBAND  | \
                                      BTA_AG_FEAT_VTAG)
enum
{
    /* these events are handled by the state machine */
    BTA_AG_API_REGISTER_EVT = BTA_SYS_EVT_START(BTA_ID_AG),
    BTA_AG_API_DEREGISTER_EVT,
    BTA_AG_API_OPEN_EVT,
    BTA_AG_API_CLOSE_EVT,
    BTA_AG_API_AUDIO_OPEN_EVT,
    BTA_AG_API_AUDIO_CLOSE_EVT,
    BTA_AG_API_RESULT_EVT,
    BTA_AG_RFC_OPEN_EVT,
    BTA_AG_RFC_CLOSE_EVT,
    BTA_AG_RFC_SRV_CLOSE_EVT,
    BTA_AG_RFC_DATA_EVT,
    BTA_AG_SCO_OPEN_EVT,
    BTA_AG_SCO_CLOSE_EVT,
    BTA_AG_DISC_ACP_RES_EVT,
    BTA_AG_DISC_INT_RES_EVT,
    BTA_AG_DISC_OK_EVT,
    BTA_AG_DISC_FAIL_EVT,
    BTA_AG_CI_RX_WRITE_EVT,
    BTA_AG_RING_TOUT_EVT,
    BTA_AG_SVC_TOUT_EVT,

    /* these events are handled outside of the state machine */
    BTA_AG_API_ENABLE_EVT,
    BTA_AG_API_DISABLE_EVT
};

/* Actions to perform after a SCO event */
enum
{
    BTA_AG_POST_SCO_NONE,       /* no action */
    BTA_AG_POST_SCO_CLOSE_RFC,  /* close RFCOMM channel after SCO closes */
    BTA_AG_POST_SCO_RING,       /* send RING result code after SCO opens */
    BTA_AG_POST_SCO_CALL_CONN,  /* send call indicators after SCO opens/closes */
    BTA_AG_POST_SCO_CALL_ORIG,  /* send call indicators after SCO closes */
    BTA_AG_POST_SCO_CALL_END    /* send call indicators after SCO closes */
};

/*****************************************************************************
**  Data types
*****************************************************************************/

/* data type for BTA_AG_API_ENABLE_EVT */
typedef struct
{
    BT_HDR              hdr;
    tBTA_AG_PARSE_MODE  parse_mode;
    tBTA_AG_CBACK      *p_cback;
} tBTA_AG_API_ENABLE;

/* data type for BTA_AG_API_REGISTER_EVT */
typedef struct
{
    BT_HDR              hdr;
    char                p_name[2][BTA_SERVICE_NAME_LEN+1];
    tBTA_SERVICE_MASK   services;
    tBTA_SEC            sec_mask;
    tBTA_AG_FEAT        features;
    UINT8               app_id;
} tBTA_AG_API_REGISTER;

/* data type for BTA_AG_API_OPEN_EVT */
typedef struct
{
    BT_HDR              hdr;
    BD_ADDR             bd_addr;
    tBTA_SERVICE_MASK   services;
    tBTA_SEC            sec_mask;
} tBTA_AG_API_OPEN;

/* data type for BTA_AG_API_RESULT_EVT */
typedef struct
{
    BT_HDR            hdr;
    tBTA_AG_RES       result;
    tBTA_AG_RES_DATA  data;
} tBTA_AG_API_RESULT;

/* data type for BTA_AG_DISC_RESULT_EVT */
typedef struct
{
    BT_HDR          hdr;
    UINT16          status;
} tBTA_AG_DISC_RESULT;

/* data type for RFCOMM events */
typedef struct
{
    BT_HDR          hdr;
    UINT16          port_handle;
} tBTA_AG_RFC;

/* data type for BTA_AG_CI_RX_WRITE_EVT */
typedef struct
{
    BT_HDR          hdr;
    char            p_data[BTA_AG_MTU+1];
} tBTA_AG_CI_RX_WRITE;

/* union of all event datatypes */
typedef union
{
    BT_HDR                  hdr;
    tBTA_AG_API_ENABLE      api_enable;
    tBTA_AG_API_REGISTER    api_register;
    tBTA_AG_API_OPEN        api_open;
    tBTA_AG_API_RESULT      api_result;
    tBTA_AG_DISC_RESULT     disc_result;
    tBTA_AG_RFC             rfc;
    tBTA_AG_CI_RX_WRITE     ci_rx_write;
} tBTA_AG_DATA;

/* type for each profile */
typedef struct
{
    UINT32          sdp_handle;
    UINT8           scn;
} tBTA_AG_PROFILE;

/* type for each service control block */
typedef struct
{
    char                clip[BTA_AG_AT_MAX_LEN+1]; /* number string used for CLIP */
    UINT16              serv_handle[BTA_AG_NUM_IDX]; /* RFCOMM server handles */
    tBTA_AG_AT_CB       at_cb;          /* AT command interpreter */
    TIMER_LIST_ENT      act_timer;     /* ring timer */
    BD_ADDR             peer_addr;      /* peer bd address */
    tSDP_DISCOVERY_DB   *p_disc_db;     /* pointer to discovery database */
    tBTA_SERVICE_MASK   reg_services;   /* services specified in register API */
    tBTA_SERVICE_MASK   open_services;  /* services specified in open API */
    UINT16              conn_handle;    /* RFCOMM handle of connected service */
    tBTA_SEC            serv_sec_mask;  /* server security mask */
    tBTA_SEC            cli_sec_mask;   /* client security mask */
    tBTA_AG_FEAT        features;       /* features registered by application */
    tBTA_AG_FEAT        peer_features;  /* peer device features */
    UINT16              peer_version;   /* profile version of peer device */
    UINT16              sco_idx;        /* SCO handle */
    BOOLEAN             in_use;         /* scb in use */
    BOOLEAN             dealloc;        /* TRUE if service shutting down */
    BOOLEAN             clip_enabled;   /* set to TRUE if HF enables CLIP reporting */
    BOOLEAN             ccwa_enabled;   /* set to TRUE if HF enables CCWA reporting */
    BOOLEAN             cmer_enabled;   /* set to TRUE if HF enables CMER reporting */
    BOOLEAN             cmee_enabled;   /* set to TRUE if HF enables CME ERROR reporting */
    BOOLEAN             inband_enabled; /* set to TRUE if inband ring enabled */
    BOOLEAN             svc_conn;       /* set to TRUE when service level connection up */
    UINT8               state;          /* state machine state */
    UINT8               conn_service;   /* connected service */
    UINT8               peer_scn;       /* peer scn */
    UINT8               app_id;         /* application id */
    UINT8               role;           /* initiator/acceptor role */
    UINT8               post_sco;       /* action to perform after sco event */
    UINT8               call_ind;       /* CIEV call indicator value */
    UINT8               callsetup_ind;  /* CIEV callsetup indicator value */
    UINT8               callheld_ind;   /* CIEV call held indicator value */
} tBTA_AG_SCB;

/* type for sco data */
typedef struct
{
    tBTM_ESCO_CONN_REQ_EVT_DATA  conn_data;     /* SCO data for pending conn request */
    tBTA_AG_SCB                 *p_curr_scb;    /* SCB associated with SCO connection */    
    tBTA_AG_SCB                 *p_xfer_scb;    /* SCB associated with SCO transfer */    
    UINT16                      cur_idx;        /* SCO handle */
    UINT8                       state;          /* SCO state variable */
} tBTA_AG_SCO_CB;
    

/* type for AG control block */
typedef struct
{
    tBTA_AG_SCB         scb[BTA_AG_NUM_SCB];        /* service control blocks */
    tBTA_AG_PROFILE     profile[BTA_AG_NUM_IDX];    /* profile-specific data */
    tBTA_AG_SCO_CB      sco;                        /* SCO data */
    tBTA_AG_CBACK       *p_cback;                   /* application callback */
    tBTA_AG_PARSE_MODE  parse_mode;                 /* parse/pass-through mode */
} tBTA_AG_CB;

/*****************************************************************************
**  Global data
*****************************************************************************/

/* constant lookup tables */
extern const UINT16 bta_ag_uuid[BTA_AG_NUM_IDX];
extern const UINT8 bta_ag_sec_id[BTA_AG_NUM_IDX];
extern const tBTA_AG_AT_CMD *bta_ag_at_tbl[BTA_AG_NUM_IDX];

/* control block declaration */
#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_AG_CB bta_ag_cb;
#else
extern tBTA_AG_CB *bta_ag_cb_ptr;
#define bta_ag_cb (*bta_ag_cb_ptr)
#endif

/* config struct */
extern tBTA_AG_CFG *p_bta_ag_cfg;

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

/* main functions */
extern void bta_ag_scb_dealloc(tBTA_AG_SCB *p_scb);
extern UINT16 bta_ag_scb_to_idx(tBTA_AG_SCB *p_scb);
extern tBTA_AG_SCB *bta_ag_scb_by_idx(UINT16 idx);
extern UINT8 bta_ag_service_to_idx(tBTA_SERVICE_MASK services);
extern UINT16 bta_ag_idx_by_bdaddr(BD_ADDR peer_addr);
extern BOOLEAN bta_ag_other_scb_open(tBTA_AG_SCB *p_curr_scb);
extern void bta_ag_sm_execute(tBTA_AG_SCB *p_scb, UINT16 event, tBTA_AG_DATA *p_data);
extern BOOLEAN bta_ag_hdl_event(BT_HDR *p_msg);

/* SDP functions */
extern BOOLEAN bta_ag_add_record(UINT16 service_uuid, char *p_service_name, UINT8 scn,
                                 tBTA_AG_FEAT features, UINT32 sdp_handle);
extern void bta_ag_create_records(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_del_records(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern BOOLEAN bta_ag_sdp_find_attr(tBTA_AG_SCB *p_scb, tBTA_SERVICE_MASK service);
extern void bta_ag_do_disc(tBTA_AG_SCB *p_scb, tBTA_SERVICE_MASK service);
extern void bta_ag_free_db(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);

/* RFCOMM functions */
extern void bta_ag_start_servers(tBTA_AG_SCB *p_scb, tBTA_SERVICE_MASK services);
extern void bta_ag_close_servers(tBTA_AG_SCB *p_scb, tBTA_SERVICE_MASK services);
extern void bta_ag_rfc_do_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_do_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);

/* SCO functions */
extern BOOLEAN bta_ag_sco_is_open(tBTA_AG_SCB *p_scb);
extern void bta_ag_sco_conn_rsp(tBTA_AG_SCB *p_scb, tBTM_ESCO_CONN_REQ_EVT_DATA *p_data);

/* AT command functions */
extern void bta_ag_at_hsp_cback(tBTA_AG_SCB *p_scb, UINT16 cmd, UINT8 arg_type,
                                char *p_arg, INT16 int_arg);
extern void bta_ag_at_hfp_cback(tBTA_AG_SCB *p_scb, UINT16 cmd, UINT8 arg_type,
                                char *p_arg, INT16 int_arg);
extern void bta_ag_at_err_cback(tBTA_AG_SCB *p_scb, BOOLEAN unknown, char *p_arg);
extern void bta_ag_send_call_inds(tBTA_AG_SCB *p_scb, tBTA_AG_RES result);

/* Action functions */
extern void bta_ag_register(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_deregister(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_start_dereg(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_start_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_start_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_disc_int_res(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_disc_acp_res(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_disc_fail(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_fail(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_acp_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_rfc_data(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_listen(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_shutdown(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_conn_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_sco_conn_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_post_sco_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_post_sco_close(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_svc_conn_open(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_result(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);
extern void bta_ag_send_ring(tBTA_AG_SCB *p_scb, tBTA_AG_DATA *p_data);

#endif /* BTA_AG_INT_H */
