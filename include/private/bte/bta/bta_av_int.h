/*****************************************************************************
**
**  Name:           bta_av_int.h
**
**  Description:    This is the private interface file for the BTA advanced
**                  audio/video.
**
**  Copyright (c) 2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_AV_INT_H
#define BTA_AV_INT_H

#include <private/bte/bta/bta_sys.h>
#include <private/bte/bta/bta_api.h>
#include <private/bte/bta/bta_av_api.h>
#include <private/bte/stack/avdt_api.h>

/*****************************************************************************
**  Constants
*****************************************************************************/

enum
{
    /* these events are handled by the AV main state machine */
    BTA_AV_API_DISABLE_EVT = BTA_SYS_EVT_START(BTA_ID_AA),
    BTA_AV_API_REMOTE_CMD_EVT,
    BTA_AV_API_VENDOR_CMD_EVT,
    BTA_AV_API_VENDOR_RSP_EVT,
    BTA_AV_SDP_AVRC_DISC_EVT,
    BTA_AV_AVRC_OPEN_EVT,
    BTA_AV_AVRC_CLOSE_EVT,
    BTA_AV_AVRC_OPEN_REQ_EVT,
    BTA_AV_AVRC_MSG_EVT,
    BTA_AV_AVRC_NONE_EVT,
    BTA_AV_CONN_CHG_EVT,
    BTA_AV_DEREG_COMP_EVT,

    /* these events are handled by the AV stream state machine */
    BTA_AV_API_OPEN_EVT,
    BTA_AV_API_CLOSE_EVT,
    BTA_AV_AP_START_EVT,        /* the following 2 events must be in the same order as the *API_*EVT */
    BTA_AV_AP_STOP_EVT,
    BTA_AV_API_RECONFIG_EVT,
    BTA_AV_API_PROTECT_REQ_EVT,
    BTA_AV_API_PROTECT_RSP_EVT,
    BTA_AV_SRC_DATA_READY_EVT,
    BTA_AV_CI_SETCONFIG_OK_EVT,
    BTA_AV_CI_SETCONFIG_FAIL_EVT,
    BTA_AV_SDP_DISC_OK_EVT,  
    BTA_AV_SDP_DISC_FAIL_EVT,
    BTA_AV_STR_DISC_OK_EVT,  
    BTA_AV_STR_DISC_FAIL_EVT,
    BTA_AV_STR_GETCAP_OK_EVT,
    BTA_AV_STR_GETCAP_FAIL_EVT,
    BTA_AV_STR_OPEN_OK_EVT,  
    BTA_AV_STR_OPEN_FAIL_EVT,
    BTA_AV_STR_START_OK_EVT, 
    BTA_AV_STR_START_FAIL_EVT,
    BTA_AV_STR_CLOSE_EVT,    
    BTA_AV_STR_CONFIG_IND_EVT,
    BTA_AV_STR_SECURITY_IND_EVT,
    BTA_AV_STR_SECURITY_CFM_EVT,
    BTA_AV_STR_WRITE_CFM_EVT,
    BTA_AV_STR_SUSPEND_CFM_EVT,
    BTA_AV_STR_RECONFIG_CFM_EVT,
    BTA_AV_AVRC_TIMER_EVT,
    BTA_AV_AVDT_CONNECT_EVT, 
    BTA_AV_AVDT_DISCONNECT_EVT,

    /* these events are handled outside of the state machine */
    BTA_AV_API_ENABLE_EVT,
    BTA_AV_API_REGISTER_EVT,
    BTA_AV_API_DEREGISTER_EVT,
    BTA_AV_CI_SRC_DATA_READY_EVT,
    BTA_AV_AVDT_RPT_CONN_EVT, 
    BTA_AV_API_START_EVT,       /* the following 2 events must be in the same order as the *AP_*EVT */
    BTA_AV_API_STOP_EVT
};

/* events for AV control block state machine */
#define BTA_AV_FIRST_SM_EVT     BTA_AV_API_DISABLE_EVT
#define BTA_AV_LAST_SM_EVT      BTA_AV_DEREG_COMP_EVT

/* events for AV stream control block state machine */
#define BTA_AV_FIRST_SSM_EVT    BTA_AV_API_OPEN_EVT
#define BTA_AV_LAST_SSM_EVT     BTA_AV_AVDT_DISCONNECT_EVT

/* events that do not go through state machine */
#define BTA_AV_FIRST_NSM_EVT    BTA_AV_API_ENABLE_EVT
#define BTA_AV_LAST_NSM_EVT     BTA_AV_API_STOP_EVT

/* API events passed to both SSMs (by bta_av_api_to_ssm) */
#define BTA_AV_FIRST_A2S_API_EVT    BTA_AV_API_START_EVT
#define BTA_AV_FIRST_A2S_SSM_EVT    BTA_AV_AP_START_EVT

#define BTA_AV_LAST_EVT             BTA_AV_API_STOP_EVT

/* maximum number of SEPS in stream discovery results */
#define BTA_AV_NUM_SEPS         8

/* initialization value for AVRC handle */
#define BTA_AV_RC_HANDLE_NONE   0xFF

/* size of database for service discovery */
#define BTA_AV_DISC_BUF_SIZE        450

/* offset of media type in codec info byte array */
#define BTA_AV_MEDIA_TYPE_IDX       1

/* maximum length of AVDTP security data */
#define BTA_AV_SECURITY_MAX_LEN     400

/* check number of buffers queued at L2CAP when this amount of buffers are queued to L2CAP */
#define BTA_AV_QUEUE_DATA_CHK_NUM   5

/*****************************************************************************
**  Data types
*****************************************************************************/

/* function types for call-out functions */
typedef BOOLEAN (*tBTA_AV_CO_INIT) (UINT8 *p_codec_type, UINT8 *p_codec_info,
                                   UINT8 *p_num_protect, UINT8 *p_protect_info, UINT8 index);

typedef void (*tBTA_AV_CO_DISC_RES) (tBTA_AV_HNDL hndl, UINT8 num_seps,
                                     UINT8 num_snk, BD_ADDR addr);

typedef UINT8 (*tBTA_AV_CO_GETCFG) (tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                     UINT8 *p_codec_info, UINT8 *p_sep_info_idx, UINT8 seid,
                                     UINT8 *p_num_protect, UINT8 *p_protect_info);
typedef void (*tBTA_AV_CO_SETCFG) (tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                    UINT8 *p_codec_info, UINT8 seid, BD_ADDR addr,
                                    UINT8 num_protect, UINT8 *p_protect_info);
typedef void (*tBTA_AV_CO_OPEN) (tBTA_AV_HNDL hndl, 
                                 tBTA_AV_CODEC codec_type, UINT8 *p_codec_info, 
                                   UINT16 mtu);
typedef void (*tBTA_AV_CO_CLOSE) (tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);
typedef void (*tBTA_AV_CO_START) (tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);
typedef void (*tBTA_AV_CO_STOP) (tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);
typedef void * (*tBTA_AV_CO_DATAPATH) (tBTA_AV_CODEC codec_type,
                                       UINT32 *p_len, UINT32 *p_timestamp);

/* the call-out functions for one stream */
typedef struct
{
    tBTA_AV_CO_INIT     init;
    tBTA_AV_CO_DISC_RES disc_res;
    tBTA_AV_CO_GETCFG   getcfg;
    tBTA_AV_CO_SETCFG   setcfg;
    tBTA_AV_CO_OPEN     open;
    tBTA_AV_CO_CLOSE    close;
    tBTA_AV_CO_START    start;
    tBTA_AV_CO_STOP     stop;
    tBTA_AV_CO_DATAPATH data;
} tBTA_AV_CO_FUNCTS;

/* data type for BTA_AV_API_ENABLE_EVT */
typedef struct
{
    BT_HDR              hdr;
    tBTA_AV_CBACK       *p_cback;
    tBTA_AV_FEAT        features;
    tBTA_SEC            sec_mask;
} tBTA_AV_API_ENABLE;

/* data type for BTA_AV_API_REG_EVT */
typedef struct
{
    BT_HDR              hdr;
    char                p_service_name[BTA_SERVICE_NAME_LEN+1];
    UINT8               app_id;
} tBTA_AV_API_REG;

/* data type for BTA_AV_API_OPEN_EVT */
typedef struct
{
    BT_HDR              hdr;
    BD_ADDR             bd_addr;
    tBTA_SEC            sec_mask;
} tBTA_AV_API_OPEN;

/* data type for BTA_AV_API_STOP_EVT */
typedef struct
{
    BT_HDR              hdr;
    BOOLEAN             suspend;
    BOOLEAN             flush;
} tBTA_AV_API_STOP;

/* data type for BTA_AV_API_PROTECT_REQ_EVT */
typedef struct
{
    BT_HDR              hdr;
    UINT8               *p_data;
    UINT16              len;
} tBTA_AV_API_PROTECT_REQ;

/* data type for BTA_AV_API_PROTECT_RSP_EVT */
typedef struct
{
    BT_HDR              hdr;
    UINT8               *p_data;
    UINT16              len;
    UINT8               error_code;
} tBTA_AV_API_PROTECT_RSP;

/* data type for BTA_AV_API_REMOTE_CMD_EVT */
typedef struct
{
    BT_HDR              hdr;
    tAVRC_MSG_PASS      msg;
    UINT8               label;
} tBTA_AV_API_REMOTE_CMD;

/* data type for BTA_AV_API_VENDOR_CMD_EVT and RSP */
typedef struct
{
    BT_HDR              hdr;
    tAVRC_MSG_VENDOR    msg;
    UINT8               label;
} tBTA_AV_API_VENDOR;

/* data type for BTA_AV_API_RECONFIG_EVT */
typedef struct
{
    BT_HDR              hdr;
    UINT8               codec_info[AVDT_CODEC_SIZE];    /* codec configuration */
    UINT8               *p_protect_info;
    UINT8               num_protect;
    BOOLEAN             suspend;
    UINT8               sep_info_idx;
} tBTA_AV_API_RCFG;

/* data type for BTA_AV_CI_SETCONFIG_OK_EVT and BTA_AV_CI_SETCONFIG_FAIL_EVT */
typedef struct
{
    BT_HDR              hdr;
    tBTA_AV_HNDL        hndl;
    UINT8               err_code;
    UINT8               category;
    UINT8               num_seid;
    UINT8               *p_seid;
} tBTA_AV_CI_SETCONFIG;

/* data type for all stream events from AVDTP */
typedef struct {
    BT_HDR              hdr;
    tAVDT_CFG           cfg;        /* configuration/capabilities parameters */
    tAVDT_CTRL          msg;        /* AVDTP callback message parameters */
    BD_ADDR             bd_addr;    /* bd address */
    UINT8               handle;
} tBTA_AV_STR_MSG;

/* data type for BTA_AV_AVRC_MSG_EVT */
typedef struct
{
    BT_HDR              hdr;
    tAVRC_MSG           msg;
    UINT8               handle;
    UINT8               label;
    UINT8               opcode;
} tBTA_AV_RC_MSG;

/* data type for BTA_AV_CONN_CHG_EVT */
typedef struct
{
    BT_HDR              hdr;
    BD_ADDR             peer_addr;
    UINT8               handle;
} tBTA_AV_RC_CONN_CHG;

/* data type for BTA_AV_CONN_CHG_EVT */
typedef struct
{
    BT_HDR              hdr;
    BOOLEAN             is_up;
} tBTA_AV_CONN_CHG;

/* type for SEP control block */
typedef struct
{
    UINT8               av_handle;      /* AVDTP handle */
    tBTA_AV_CODEC       codec_type;     /* codec type */
} tBTA_AV_SEP;

/* initiator/acceptor role for adaption */
#define BTA_AV_ROLE_AD_INT          0x00       /* initiator */
#define BTA_AV_ROLE_AD_ACP          0x01       /* acceptor */

/* initiator/acceptor signaling roles */
#define BTA_AV_ROLE_START_ACP       0x00
#define BTA_AV_ROLE_START_INT       0x10    /* do not change this value */

#define BTA_AV_ROLE_SUSPEND         0x20    /* suspending on start */
#define BTA_AV_ROLE_SUSPEND_OPT     0x40    /* Suspend on Start option is set */

/* union of all event datatypes */
typedef union
{
    BT_HDR                  hdr;
    tBTA_AV_API_ENABLE      api_enable;
    tBTA_AV_API_REG         api_reg;
    tBTA_AV_API_OPEN        api_open;
    tBTA_AV_API_STOP        api_stop;
    tBTA_AV_API_PROTECT_REQ api_protect_req;
    tBTA_AV_API_PROTECT_RSP api_protect_rsp;
    tBTA_AV_API_REMOTE_CMD  api_remote_cmd;
    tBTA_AV_API_VENDOR      api_vendor;
    tBTA_AV_API_RCFG        api_reconfig;
    tBTA_AV_CI_SETCONFIG    ci_setconfig;
    tBTA_AV_STR_MSG         str_msg;
    tBTA_AV_RC_MSG          rc_msg;
    tBTA_AV_RC_CONN_CHG     rc_conn_chg;
    tBTA_AV_CONN_CHG        conn_chg;
} tBTA_AV_DATA;

/* type for AV stream control block */
typedef struct
{
    const tBTA_AV_ACT   *p_act_tbl;     /* the action table for stream state machine */
    const tBTA_AV_CO_FUNCTS *p_cos;     /* the associated callout functions */
    tSDP_DISCOVERY_DB   *p_disc_db;     /* pointer to discovery database */
    tBTA_AV_SEP         seps[BTA_AV_MAX_SEPS];
    tAVDT_CTRL_CBACK    *p_dt_cback;    /* the callback function to receive events from AVDT control channel */
    tAVDT_CFG           *p_cap;         /* buffer used for get capabilities */
    BUFFER_Q            out_q;          /* used for audio channels only */
    tAVDT_SEP_INFO      sep_info[BTA_AV_NUM_SEPS];      /* stream discovery results */
    tAVDT_CFG           cfg;            /* local SEP configuration */
    TIMER_LIST_ENT      timer;          /* delay timer for AVRC CT */
    BD_ADDR             peer_addr;      /* peer BD address */
    UINT16              l2c_cid;        /* L2CAP channel ID */
    UINT16              stream_mtu;     /* MTU of stream */
    tBTA_SEC            sec_mask;       /* security mask */
    tBTA_AV_CODEC       codec_type;     /* codec type */
    UINT8               media_type;     /* Media type */
    BOOLEAN             cong;           /* TRUE if AVDTP congested */
    tBTA_AV_STATUS      open_status;    /* open failure status */
    tBTA_AV_CHNL        chnl;           /* the channel: audio/video */
    tBTA_AV_HNDL        hndl;           /* the handle: ((hdi + 1)|chnl) */
    UINT8               cur_psc_mask;   /* Protocol service capabilities mask for current connection */
    UINT8               avdt_handle;    /* AVDTP handle */
    UINT8               hdi;            /* the index to SCB[] */
    UINT8               num_seps;       /* number of seps returned by stream discovery */
    UINT8               sep_info_idx;   /* current index into sep_info */
    UINT8               sep_idx;        /* current index into local seps[] */
    UINT8               rcfg_idx;       /* reconfig requested index into sep_info */
    UINT8               state;          /* state machine state */
    UINT8               avdt_label;     /* AVDTP label */
    UINT8               app_id;         /* application id */
    UINT8               num_recfg;      /* number of reconfigure sent */
    UINT8               role;
    UINT8               l2c_bufs;       /* the number of buffers queued to L2CAP */
    UINT8               rc_handle;      /* connected AVRCP handle */
    BOOLEAN             started;        /* TRUE if stream started */
    BOOLEAN             co_started;     /* TRUE if stream started from call-out perspective */
    BOOLEAN             recfg_sup;      /* TRUE if the first attempt to reconfigure the stream was successfull, else False if command fails */
    BOOLEAN             suspend_sup;    /* TRUE if Suspend stream is supported, else FALSE if suspend command fails */
    BOOLEAN             deregistring;   /* TRUE if deregistering */
} tBTA_AV_SCB;

#define BTA_AV_RC_ROLE_MASK     0x10
#define BTA_AV_RC_ROLE_INT      0x00
#define BTA_AV_RC_ROLE_ACP      0x10

#define BTA_AV_RC_CONN_MASK     0x20

/* type for AV RCP control block */
/* index to this control block is the rc handle */
typedef struct
{
    UINT8   status;
    UINT8   handle;
    UINT8   shdl;	/* stream handle (hdi + 1) */
} tBTA_AV_RCB;
#define BTA_AV_NUM_RCB      (BTA_AV_NUM_STRS  + 1)

/* type for AV control block */
typedef struct
{
    tBTA_AV_SCB         *p_scb[BTA_AV_NUM_STRS];    /* stream control block */
    tSDP_DISCOVERY_DB   *p_disc_db;     /* pointer to discovery database */
    tBTA_AV_CBACK       *p_cback;       /* application callback function */
    tBTA_AV_RCB         rcb[BTA_AV_NUM_RCB];  /* RCP control block */
    UINT32              sdp_a2d_handle; /* SDP record handle for audio src */
    UINT32              sdp_vdp_handle; /* SDP record handle for video src */
    UINT32              sdp_ct_handle;  /* SDP record handle for rc controller */
    UINT32              sdp_tg_handle;  /* SDP record handle for rc target */
    tBTA_AV_FEAT        features;       /* features mask */
    tBTA_AV_FEAT        peer_features;  /* peer features mask */
    tBTA_SEC            sec_mask;       /* security mask */
    tBTA_AV_HNDL        handle;         /* the handle for SDP activity */
    BOOLEAN             disabling;      /* TRUE if api disabled called */
    UINT8               disc;           /* (hdi+1) if p_disc_db is in use */
    UINT8               state;          /* state machine state */
    UINT8               conn_rc;        /* handle mask of connected RCP channels */
    UINT8               conn_audio;     /* handle mask of connected audio channels */
    UINT8               conn_video;     /* handle mask of connected video channels */
    UINT8               audio_bits;     /* bits set of connected audio channels */
    UINT8               reg_audio;      /* handle mask of registered audio channels */
    UINT8               reg_video;      /* handle mask of registered video channels */
} tBTA_AV_CB;

/* type for stream state machine action functions */
typedef void (*tBTA_AV_SACT)(tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);

/*****************************************************************************
**  Global data
*****************************************************************************/

/* control block declaration */
#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_AV_CB bta_av_cb;
#else
extern tBTA_AV_CB *bta_av_cb_ptr;
#define bta_av_cb (*bta_av_cb_ptr)
#endif

/* config struct */
extern tBTA_AV_CFG *p_bta_av_cfg;

/* rc id config struct */
extern UINT16 *p_bta_av_rc_id;

extern const tBTA_AV_SACT bta_av_a2d_action[];
extern const tBTA_AV_CO_FUNCTS bta_av_a2d_cos;
extern const tBTA_AV_SACT bta_av_vdp_action[];
extern tAVDT_CTRL_CBACK * bta_av_dt_cback[];

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

/* main functions */
extern void bta_av_api_deregister(tBTA_AV_DATA *p_data);
extern void bta_av_dup_audio_buf(tBTA_AV_SCB *p_scb, BT_HDR *p_buf, UINT32 timestamp);
extern void bta_av_sm_execute(tBTA_AV_CB *p_cb, UINT16 event, tBTA_AV_DATA *p_data);
extern void bta_av_ssm_execute(tBTA_AV_SCB *p_scb, UINT16 event, tBTA_AV_DATA *p_data);
extern BOOLEAN bta_av_hdl_event(BT_HDR *p_msg);
#if (defined(BTA_AV_DEBUG) && BTA_AV_DEBUG == TRUE)
extern char *bta_av_evt_code(UINT16 evt_code);
#endif

/* sm action functions */
extern void bta_av_disable (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_dereg_comp (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_conn_chg(tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_listen (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_disc_done (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_opened (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_closed (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_disc (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_remote_cmd (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_vendor_cmd (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_vendor_rsp (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);
extern void bta_av_rc_msg (tBTA_AV_CB *p_cb, tBTA_AV_DATA *p_data);

/* ssm action functions */
extern void bta_av_do_disc_a2d (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_cleanup (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_free_sdb (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_config_ind (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_disconnect_req (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_security_req (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_security_rsp (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_setconfig_rsp (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_snd_rc_listen(tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_str_opened (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_security_ind (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_security_cfm (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_do_close (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_connect_req (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_sdp_failed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_disc_results (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_open_failed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_getcap_results (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_setconfig_rej (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_discover_req (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_conn_failed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_do_start (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_str_stopped (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_reconfig (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_data_path (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_start_ok (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_start_failed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_str_closed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_clr_cong (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_suspend_cfm (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_str_ok (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_failed (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_connect (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_discntd (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_suspend_cont (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_cfm (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rcfg_open (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_security_rej (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_open_rc (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_save_caps (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rej_conn (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_rpt_close (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern BOOLEAN bta_av_chk_start(tBTA_AV_SCB *p_scb);

/* ssm action functions - vdp specific */
extern void bta_av_do_disc_vdp (tBTA_AV_SCB *p_scb, tBTA_AV_DATA *p_data);
extern void bta_av_reg_vdp (tAVDT_CS *p_cs, char *p_service_name, void *p_data);

#endif /* BTA_AV_INT_H */
