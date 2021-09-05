/*****************************************************************************
**
**  Name:           avdt_int.h
**
**  Description:    This file contains interfaces which are internal to AVDTP.
**                  
**
**  Copyright (c) 2002-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef AVDT_INT_H
#define AVDT_INT_H

#include <private/bte/gki.h>
#include <private/bte/stack/avdt_api.h>
#include <private/bte/stack/avdtc_api.h>
#include <private/bte/stack/avdt_defs.h>
#include <private/bte/stack/l2c_api.h>

/*****************************************************************************
** constants
*****************************************************************************/

/* channel types */
enum {
    AVDT_CHAN_SIG,                  /* signaling channel */
    AVDT_CHAN_MEDIA,                /* media channel */
#if AVDT_REPORTING == TRUE
    AVDT_CHAN_REPORT,               /* reporting channel */
#endif
    AVDT_CHAN_NUM_TYPES
};

/* protocol service capabilities of this AVDTP implementation */
/* for now multiplexing will be used only for fragmentation */
#if ((AVDT_MULTIPLEXING == TRUE) && (AVDT_REPORTING == TRUE))
#define AVDT_PSC                (AVDT_PSC_TRANS | AVDT_PSC_MUX | AVDT_PSC_REPORT)
#else /* AVDT_MULTIPLEXING && AVDT_REPORTING  */

#if (AVDT_MULTIPLEXING == TRUE)
#define AVDT_PSC                (AVDT_PSC_TRANS | AVDT_PSC_MUX)
#else /* AVDT_MULTIPLEXING */

#if (AVDT_REPORTING == TRUE)
#define AVDT_PSC                (AVDT_PSC_TRANS | AVDT_PSC_REPORT)
#else /* AVDT_REPORTING  */
#define AVDT_PSC                (AVDT_PSC_TRANS)
#endif /* AVDT_REPORTING  */

#endif /* AVDT_MULTIPLEXING */

#endif /* AVDT_MULTIPLEXING && AVDT_REPORTING  */
            
/* initiator/acceptor role for adaption */
#define AVDT_INT                0       /* initiator */
#define AVDT_ACP                1       /* acceptor */

/* initiator/acceptor signaling roles */
#define AVDT_CLOSE_ACP          0
#define AVDT_CLOSE_INT          1
#define AVDT_OPEN_ACP           2
#define AVDT_OPEN_INT           3

/* states for avdt_scb_verify */
#define AVDT_VERIFY_OPEN        0
#define AVDT_VERIFY_STREAMING   1
#define AVDT_VERIFY_SUSPEND     2
#define AVDT_VERIFY_START       3

/* to distinguish CCB events from SCB events */
#define AVDT_CCB_MKR            0x80    

/* offset where AVDTP signaling message header starts in message  */
#define AVDT_HDR_OFFSET         (L2CAP_MIN_OFFSET + AVDT_NUM_SEPS)

/* offset where AVDTP signaling message content starts;
** use the size of a start header since it's the largest possible
** layout of signaling message in a buffer is:
**
** |  BT_HDR  | SCB handles | L2CAP + HCI header | AVDTP header | data ... |
**
** Note that we "hide" the scb handles at the top of the message buffer.
*/
#define AVDT_MSG_OFFSET         (L2CAP_MIN_OFFSET + AVDT_NUM_SEPS + AVDT_LEN_TYPE_START)

/* scb transport channel connect timeout value */
#define AVDT_SCB_TC_CONN_TOUT   10

/* scb transport channel disconnect timeout value */
#define AVDT_SCB_TC_DISC_TOUT   10

/* maximum number of command retransmissions */
#ifndef AVDT_RET_MAX
#define AVDT_RET_MAX            1
#endif

/* ccb state machine events */
enum {
    AVDT_CCB_API_DISCOVER_REQ_EVT,
    AVDT_CCB_API_GETCAP_REQ_EVT,
    AVDT_CCB_API_START_REQ_EVT,
    AVDT_CCB_API_SUSPEND_REQ_EVT,
    AVDT_CCB_API_DISCOVER_RSP_EVT,
    AVDT_CCB_API_GETCAP_RSP_EVT,
    AVDT_CCB_API_START_RSP_EVT,
    AVDT_CCB_API_SUSPEND_RSP_EVT,
    AVDT_CCB_API_CONNECT_REQ_EVT,
    AVDT_CCB_API_DISCONNECT_REQ_EVT,
    AVDT_CCB_MSG_DISCOVER_CMD_EVT,
    AVDT_CCB_MSG_GETCAP_CMD_EVT,
    AVDT_CCB_MSG_START_CMD_EVT,
    AVDT_CCB_MSG_SUSPEND_CMD_EVT,
    AVDT_CCB_MSG_DISCOVER_RSP_EVT,
    AVDT_CCB_MSG_GETCAP_RSP_EVT,
    AVDT_CCB_MSG_START_RSP_EVT,
    AVDT_CCB_MSG_SUSPEND_RSP_EVT,
    AVDT_CCB_RCVRSP_EVT,
    AVDT_CCB_SENDMSG_EVT,
    AVDT_CCB_RET_TOUT_EVT,
    AVDT_CCB_RSP_TOUT_EVT,
    AVDT_CCB_IDLE_TOUT_EVT,
    AVDT_CCB_UL_OPEN_EVT,
    AVDT_CCB_UL_CLOSE_EVT,
    AVDT_CCB_LL_OPEN_EVT,
    AVDT_CCB_LL_CLOSE_EVT,
    AVDT_CCB_LL_CONG_EVT
};

/* scb state machine events */
enum {
    AVDT_SCB_API_REMOVE_EVT,
    AVDT_SCB_API_WRITE_REQ_EVT,
    AVDT_SCB_API_GETCONFIG_REQ_EVT,
    AVDT_SCB_API_SETCONFIG_REQ_EVT,
    AVDT_SCB_API_OPEN_REQ_EVT,
    AVDT_SCB_API_CLOSE_REQ_EVT,
    AVDT_SCB_API_RECONFIG_REQ_EVT,
    AVDT_SCB_API_SECURITY_REQ_EVT,
    AVDT_SCB_API_ABORT_REQ_EVT,
    AVDT_SCB_API_GETCONFIG_RSP_EVT,
    AVDT_SCB_API_SETCONFIG_RSP_EVT,
    AVDT_SCB_API_SETCONFIG_REJ_EVT,
    AVDT_SCB_API_OPEN_RSP_EVT,
    AVDT_SCB_API_CLOSE_RSP_EVT,
    AVDT_SCB_API_RECONFIG_RSP_EVT,
    AVDT_SCB_API_SECURITY_RSP_EVT,
    AVDT_SCB_API_ABORT_RSP_EVT,
    AVDT_SCB_MSG_SETCONFIG_CMD_EVT,
    AVDT_SCB_MSG_GETCONFIG_CMD_EVT,
    AVDT_SCB_MSG_OPEN_CMD_EVT,
    AVDT_SCB_MSG_START_CMD_EVT,
    AVDT_SCB_MSG_SUSPEND_CMD_EVT,
    AVDT_SCB_MSG_CLOSE_CMD_EVT,
    AVDT_SCB_MSG_ABORT_CMD_EVT,
    AVDT_SCB_MSG_RECONFIG_CMD_EVT,
    AVDT_SCB_MSG_SECURITY_CMD_EVT,
    AVDT_SCB_MSG_SETCONFIG_RSP_EVT,
    AVDT_SCB_MSG_GETCONFIG_RSP_EVT,
    AVDT_SCB_MSG_OPEN_RSP_EVT,
    AVDT_SCB_MSG_START_RSP_EVT,
    AVDT_SCB_MSG_SUSPEND_RSP_EVT,
    AVDT_SCB_MSG_CLOSE_RSP_EVT,
    AVDT_SCB_MSG_ABORT_RSP_EVT,
    AVDT_SCB_MSG_RECONFIG_RSP_EVT,
    AVDT_SCB_MSG_SECURITY_RSP_EVT,
    AVDT_SCB_MSG_SETCONFIG_REJ_EVT,
    AVDT_SCB_MSG_OPEN_REJ_EVT,
    AVDT_SCB_MSG_START_REJ_EVT,
    AVDT_SCB_MSG_SUSPEND_REJ_EVT,
    AVDT_SCB_TC_TOUT_EVT,
    AVDT_SCB_TC_OPEN_EVT,
    AVDT_SCB_TC_CLOSE_EVT,
    AVDT_SCB_TC_CONG_EVT,
    AVDT_SCB_TC_DATA_EVT,
    AVDT_SCB_CC_CLOSE_EVT
};

/* adaption layer number of stream routing table entries */
#if AVDT_REPORTING == TRUE
/* 2 channels(1 media, 1 report) for each SEP and one for signalling */
#define AVDT_NUM_RT_TBL     ((AVDT_NUM_SEPS<<1) + 1)
#else
#define AVDT_NUM_RT_TBL     (AVDT_NUM_SEPS + 1)
#endif

/* adaption layer number of transport channel table entries - moved to target.h
#define AVDT_NUM_TC_TBL     (AVDT_NUM_SEPS + AVDT_NUM_LINKS) */

/* "states" used in transport channel table */
#define AVDT_AD_ST_UNUSED   0       /* Unused - unallocated */
#define AVDT_AD_ST_IDLE     1       /* No connection */
#define AVDT_AD_ST_ACP      2       /* Waiting to accept a connection */
#define AVDT_AD_ST_INT      3       /* Initiating a connection */
#define AVDT_AD_ST_CONN     4       /* Waiting for connection confirm */
#define AVDT_AD_ST_CFG      5       /* Waiting for configuration complete */
#define AVDT_AD_ST_OPEN     6       /* Channel opened */
#define AVDT_AD_ST_SEC_INT  7       /* Security process as INT */
#define AVDT_AD_ST_SEC_ACP  8       /* Security process as ACP */


/* result code for avdt_ad_write_req() (L2CA_DataWrite()) */
#define AVDT_AD_FAILED       L2CAP_DW_FAILED        /* FALSE */
#define AVDT_AD_SUCCESS      L2CAP_DW_SUCCESS       /* TRUE */
#define AVDT_AD_CONGESTED    L2CAP_DW_CONGESTED     /* 2 */

/*****************************************************************************
** data types
*****************************************************************************/

/* msg union of all message parameter types */
typedef union {
    tAVDT_EVT_HDR           hdr;
    tAVDT_EVT_HDR           single;
    tAVDT_SETCONFIG         config_cmd;
    tAVDT_CONFIG            reconfig_cmd;
    tAVDT_MULTI             multi;
    tAVDT_SECURITY          security_cmd;
    tAVDT_DISCOVER          discover_rsp;
    tAVDT_CONFIG            svccap;
    tAVDT_SECURITY          security_rsp;
} tAVDT_MSG;

/* data type for AVDT_CCB_API_DISCOVER_REQ_EVT */
typedef struct {
    tAVDT_CTRL_CBACK    *p_cback;
    tAVDT_SEP_INFO      *p_sep_info;
    UINT8               num_seps;
} tAVDT_CCB_API_DISCOVER;

/* data type for AVDT_CCB_API_GETCAP_REQ_EVT */
typedef struct {
    tAVDT_EVT_HDR       single;
    tAVDT_CTRL_CBACK    *p_cback;
    tAVDT_CFG           *p_cfg;
} tAVDT_CCB_API_GETCAP;

/* data type for AVDT_CCB_API_CONNECT_REQ_EVT */
typedef struct {
    tAVDT_CTRL_CBACK    *p_cback;
    UINT8               sec_mask;
} tAVDT_CCB_API_CONNECT;

/* data type for AVDT_CCB_API_DISCONNECT_REQ_EVT */
typedef struct {
    tAVDT_CTRL_CBACK    *p_cback;
} tAVDT_CCB_API_DISCONNECT;

/* union associated with ccb state machine events */
typedef union {
    tAVDT_CCB_API_DISCOVER      discover;
    tAVDT_CCB_API_GETCAP        getcap;
    tAVDT_CCB_API_CONNECT       connect;
    tAVDT_CCB_API_DISCONNECT    disconnect;
    tAVDT_MSG                   msg;
    BOOLEAN                     llcong;
    UINT8                       err_code;
} tAVDT_CCB_EVT;

/* channel control block type */
typedef struct {
    BD_ADDR             peer_addr;      /* BD address of peer */
    TIMER_LIST_ENT      timer_entry;    /* CCB timer list entry */
    BUFFER_Q            cmd_q;          /* Queue for outgoing command messages */
    BUFFER_Q            rsp_q;          /* Queue for outgoing response and reject messages */
    tAVDT_CTRL_CBACK    *proc_cback;    /* Procedure callback function */
    tAVDT_CTRL_CBACK    *p_conn_cback;  /* Connection/disconnection callback function */
    void                *p_proc_data;   /* Pointer to data storage for procedure */
    BT_HDR              *p_curr_cmd;    /* Current command being sent awaiting response */
    BT_HDR              *p_curr_msg;    /* Current message being sent */
    BT_HDR              *p_rx_msg;      /* Current message being received */
    BOOLEAN             allocated;      /* Whether ccb is allocated */
    UINT8               state;          /* The CCB state machine state */
    BOOLEAN             proc_busy;      /* TRUE when a discover or get capabilities procedure in progress */
    UINT8               proc_param;     /* Procedure parameter; either SEID for get capabilities or number of SEPS for discover */
    BOOLEAN             cong;           /* Whether signaling channel is congested */
    UINT8               label;          /* Message header "label" (sequence number) */
    BOOLEAN             reconn;         /* If TRUE, reinitiate connection after transitioning from CLOSING to IDLE state */
    UINT8               ret_count;      /* Command retransmission count */
} tAVDT_CCB;

/* type for action functions */
typedef void (*tAVDT_CCB_ACTION)(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);

/* type for AVDT_SCB_API_WRITE_REQ_EVT */
typedef struct {
    BT_HDR      *p_buf;
    UINT32      time_stamp;
#if AVDT_MULTIPLEXING == TRUE
    BUFFER_Q    frag_q;          /* Queue for outgoing media fragments. p_buf should be 0 */
    UINT8       *p_data;
    UINT32      data_len;
#endif
    UINT8       m_pt;
} tAVDT_SCB_APIWRITE;

/* type for AVDT_SCB_TC_CLOSE_EVT */
typedef struct {
    UINT8           old_tc_state;       /* channel state before closed */
    UINT8           tcid;               /* TCID  */
    UINT8           type;               /* channel type */
} tAVDT_SCB_TC_CLOSE;

/* type for scb event data */
typedef union {
    tAVDT_MSG           msg;
    tAVDT_SCB_APIWRITE  apiwrite;
    tAVDT_OPEN          open;
    tAVDT_SCB_TC_CLOSE  close;
    BOOLEAN             llcong;
    BT_HDR              *p_pkt;
} tAVDT_SCB_EVT;

/* stream control block type */
typedef struct {
    tAVDT_CS        cs;             /* stream creation struct */
    tAVDT_CFG       curr_cfg;       /* current configuration */
    tAVDT_CFG       req_cfg;        /* requested configuration */
    TIMER_LIST_ENT  timer_entry;    /* timer entry */
    BT_HDR          *p_pkt;         /* packet waiting to be sent */
    tAVDT_CCB       *p_ccb;         /* ccb associated with this scb */
    UINT16          media_seq;      /* media packet sequence number */
    BOOLEAN         allocated;      /* whether scb is allocated or unused */
    BOOLEAN         in_use;         /* whether stream being used by peer */
    UINT8           role;           /* initiator/acceptor role in current procedure */
    BOOLEAN         remove;         /* whether CB is marked for removal */
    UINT8           state;          /* state machine state */
    UINT8           peer_seid;      /* SEID of peer stream */
    UINT8           curr_evt;       /* current event; set only by state machine */
    BOOLEAN         cong;           /* Whether media transport channel is congested */
    UINT8           close_code;     /* Error code received in close response */
#if AVDT_MULTIPLEXING == TRUE
    BUFFER_Q        frag_q;         /* Queue for outgoing media fragments */
    UINT32          frag_off;       /* length of already received media fragments */
    UINT32          frag_org_len;   /* original length before fragmentation of receiving media packet */
    UINT8           *p_next_frag;   /* next fragment to send */
    UINT8           *p_media_buf;   /* buffer for media packet assigned by AVDT_SetMediaBuf */
    UINT32          media_buf_len;  /* length of buffer for media packet assigned by AVDT_SetMediaBuf */
#endif
} tAVDT_SCB;

/* type for action functions */
typedef void (*tAVDT_SCB_ACTION)(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);

/* adaption layer type for transport channel table */
typedef struct {
    UINT16  peer_mtu;       /* L2CAP mtu of the peer device */
    UINT16  my_mtu;         /* Our MTU for this channel */
    UINT16  my_flush_to;    /* Our flush timeout for this channel */
    UINT16  lcid;
    UINT8   tcid;           /* transport channel id */
    UINT8   ccb_idx;        /* channel control block associated with this tc */
    UINT8   state;          /* transport channel state */
    UINT8   cfg_flags;      /* L2CAP configuration flags */
    UINT8   id;
} tAVDT_TC_TBL;

/* adaption layer type for stream routing table */
typedef struct {
    UINT16  lcid;           /* L2CAP LCID of the associated transport channel */
    UINT8   scb_hdl;        /* stream control block associated with this tc */
} tAVDT_RT_TBL;


/* adaption layer control block */
typedef struct {
    tAVDT_RT_TBL    rt_tbl[AVDT_NUM_LINKS][AVDT_NUM_RT_TBL];
    tAVDT_TC_TBL    tc_tbl[AVDT_NUM_TC_TBL];
    UINT8           lcid_tbl[MAX_L2CAP_CHANNELS];   /* map LCID to tc_tbl index */
} tAVDT_AD;

/* Control block for AVDT */
typedef struct {
    tAVDT_REG           rcb;                    /* registration control block */
    tAVDT_CCB           ccb[AVDT_NUM_LINKS];    /* channel control blocks */
    tAVDT_SCB           scb[AVDT_NUM_SEPS];     /* stream control blocks */
    tAVDT_AD            ad;                     /* adaption layer control block */
    tAVDTC_CTRL_CBACK   *p_conf_cback;          /* conformance callback function */
    tAVDT_CTRL_CBACK    *p_conn_cback;          /* connection callback function */
    tAVDT_CCB_ACTION    *p_ccb_act;             /* pointer to CCB action functions */
    tAVDT_SCB_ACTION    *p_scb_act;             /* pointer to SCB action functions */
    UINT8               trace_level;            /* trace level */
} tAVDT_CB;


/*****************************************************************************
** function declarations
*****************************************************************************/

/* CCB function declarations */
extern void avdt_ccb_init(void);
extern void avdt_ccb_event(tAVDT_CCB *p_ccb, UINT8 event, tAVDT_CCB_EVT *p_data);
extern tAVDT_CCB *avdt_ccb_by_bd(BD_ADDR bd_addr);
extern tAVDT_CCB *avdt_ccb_alloc(BD_ADDR bd_addr);
extern void avdt_ccb_dealloc(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern UINT8 avdt_ccb_to_idx(tAVDT_CCB *p_ccb);
extern tAVDT_CCB *avdt_ccb_by_idx(UINT8 idx);

/* CCB action functions */
extern void avdt_ccb_chan_open(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_chan_close(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_chk_close(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_discover_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_discover_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_getcap_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_getcap_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_start_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_start_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_suspend_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_hdl_suspend_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_discover_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_discover_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_getcap_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_getcap_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_start_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_start_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_suspend_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_suspend_rsp(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_clear_cmds(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_cmd_fail(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_free_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_cong_state(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_ret_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_cmd(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_snd_msg(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_set_reconn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_clr_reconn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_chk_reconn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_chk_timer(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_set_conn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_set_disconn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_do_disconn(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_ll_closed(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);
extern void avdt_ccb_ll_opened(tAVDT_CCB *p_ccb, tAVDT_CCB_EVT *p_data);

/* SCB function prototypes */
extern void avdt_scb_event(tAVDT_SCB *p_scb, UINT8 event, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_init(void);
extern tAVDT_SCB *avdt_scb_alloc(tAVDT_CS *p_cs);
extern void avdt_scb_dealloc(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern UINT8 avdt_scb_to_hdl(tAVDT_SCB *p_scb);
extern tAVDT_SCB *avdt_scb_by_hdl(UINT8 hdl);
extern UINT8 avdt_scb_verify(tAVDT_CCB *p_ccb, UINT8 state, UINT8 *p_seid, UINT16 num_seid, UINT8 *p_err_code);
extern void avdt_scb_peer_seid_list(tAVDT_MULTI *p_multi);
extern UINT32 avdt_scb_gen_ssrc(tAVDT_SCB *p_scb);

/* SCB action functions */
extern void avdt_scb_hdl_abort_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_abort_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_close_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_close_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_getconfig_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_getconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_open_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_open_rej(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_open_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_pkt(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_drop_pkt(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_reconfig_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_reconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_security_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_security_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_setconfig_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_setconfig_rej(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_setconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_start_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_start_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_suspend_cmd(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_suspend_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_tc_close(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_tc_open(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_tc_close_sto(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_tc_open_sto(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_hdl_write_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_abort_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_abort_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_close_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_close_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_getconfig_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_getconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_open_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_open_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_reconfig_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_reconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_security_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_security_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_setconfig_req(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_setconfig_rej(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_setconfig_rsp(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_snd_tc_close(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_cb_err(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_cong_state(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_rej_state(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_rej_in_use(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_rej_not_in_use(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_set_remove(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_free_pkt(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_chk_snd_pkt(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_clr_pkt(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_tc_timer(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_clr_vars(tAVDT_SCB *p_scb, tAVDT_SCB_EVT *p_data);
extern void avdt_scb_queue_frags(tAVDT_SCB *p_scb, UINT8 **pp_data, UINT32 *p_data_len, BUFFER_Q *pq);

/* msg function declarations */
extern BOOLEAN avdt_msg_send(tAVDT_CCB *p_ccb, BT_HDR *p_msg);
extern void avdt_msg_send_cmd(tAVDT_CCB *p_ccb, void *p_scb, UINT8 sig_id, tAVDT_MSG *p_params);
extern void avdt_msg_send_rsp(tAVDT_CCB *p_ccb, UINT8 sig_id, tAVDT_MSG *p_params);
extern void avdt_msg_send_rej(tAVDT_CCB *p_ccb, UINT8 sig_id, tAVDT_MSG *p_params);
extern void avdt_msg_ind(tAVDT_CCB *p_ccb, BT_HDR *p_buf);

/* adaption layer function declarations */
extern void avdt_ad_init(void);
extern UINT8 avdt_ad_type_to_tcid(UINT8 type, tAVDT_SCB *p_scb);
extern tAVDT_TC_TBL *avdt_ad_tc_tbl_by_st(UINT8 type, tAVDT_CCB *p_ccb, UINT8 state);
extern tAVDT_TC_TBL *avdt_ad_tc_tbl_by_lcid(UINT16 lcid);
extern tAVDT_TC_TBL *avdt_ad_tc_tbl_alloc(tAVDT_CCB *p_ccb);
extern UINT8 avdt_ad_tc_tbl_to_idx(tAVDT_TC_TBL *p_tbl);
extern void avdt_ad_tc_close_ind(tAVDT_TC_TBL *p_tbl, UINT16 reason);
extern void avdt_ad_tc_open_ind(tAVDT_TC_TBL *p_tbl);
extern void avdt_ad_tc_cong_ind(tAVDT_TC_TBL *p_tbl, BOOLEAN is_congested);
extern void avdt_ad_tc_data_ind(tAVDT_TC_TBL *p_tbl, BT_HDR *p_buf);
extern tAVDT_TC_TBL *avdt_ad_tc_tbl_by_type(UINT8 type, tAVDT_CCB *p_ccb, tAVDT_SCB *p_scb);
extern UINT8 avdt_ad_write_req(UINT8 type, tAVDT_CCB *p_ccb, tAVDT_SCB *p_scb, BT_HDR *p_buf);
extern void avdt_ad_open_req(UINT8 type, tAVDT_CCB *p_ccb, tAVDT_SCB *p_scb, UINT8 role);
extern void avdt_ad_close_req(UINT8 type, tAVDT_CCB *p_ccb, tAVDT_SCB *p_scb);

extern void avdt_process_timeout(TIMER_LIST_ENT *p_tle);

/*****************************************************************************
** macros
*****************************************************************************/

/* we store the scb and the label in the layer_specific field of the
** current cmd
*/
#define AVDT_BLD_LAYERSPEC(ls, msg, label) \
            ls = (((label) << 4) | (msg))

#define AVDT_LAYERSPEC_LABEL(ls)    ((UINT8)((ls) >> 4))

#define AVDT_LAYERSPEC_MSG(ls)      ((UINT8)((ls) & 0x000F))

/*****************************************************************************
** global data
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
** Main Control Block
*******************************************************************************/
#if AVDT_DYNAMIC_MEMORY == FALSE
AVDT_API extern tAVDT_CB  avdt_cb;
#else
AVDT_API extern tAVDT_CB *avdt_cb_ptr;
#define avdt_cb (*avdt_cb_ptr)
#endif


/* L2CAP callback registration structure */
extern const tL2CAP_APPL_INFO avdt_l2c_appl;

/* reject message event lookup table */
extern const UINT8 avdt_msg_rej_2_evt[];
#ifdef __cplusplus
}
#endif

#endif /* AVDT_INT_H */
