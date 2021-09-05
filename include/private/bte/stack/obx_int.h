/*****************************************************************************
**
**  Name:         obx_int.h
**
**  File:         OBEX Internal header file
**
**  Copyright (c) 2003-2005, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef OBX_INT_H
#define OBX_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/gki.h>

#define OBX_DEFAULT_TARGET_LEN      0xFF
#define OBX_INITIAL_CONN_ID         0x1

#define OBX_CL_HANDLE_MASK          0x80
#define OBX_HANDLE_RX_MTU_MASK      0x40


#define OBX_NONCE_SIZE              16  /* fixed size per IrOBEX spec */
#define OBX_DIGEST_SIZE             16  /* fixed size per IrOBEX spec */
#define OBX_MAX_AUTH_KEY_SIZE       16
#define OBX_MAX_AUTH_USER_SIZE      20

#define OBX_PORT_EVENT_MASK  (PORT_EV_RXCHAR | PORT_EV_TXEMPTY | \
                              PORT_EV_FC | PORT_EV_FCS)


#define OBX_BAD_SM_EVT              0xFF

/* for wait_auth flag */
#define OBX_WAIT_AUTH_FAIL          2

enum
{
    OBX_CS_NULL,
    OBX_CS_NOT_CONNECTED,
    OBX_CS_CONNECT_REQ_SENT,
    OBX_CS_UNAUTH,
    OBX_CS_CONNECTED,
    OBX_CS_DISCNT_REQ_SENT,
    OBX_CS_OP_UNAUTH,
    OBX_CS_SETPATH_REQ_SENT,
    OBX_CS_ABORT_REQ_SENT,
    OBX_CS_PUT_REQ_SENT,
    OBX_CS_GET_REQ_SENT,
    OBX_CS_PUT_TRANSACTION,
    OBX_CS_GET_TRANSACTION,
    OBX_CS_PARTIAL_SENT,
    OBX_CS_MAX
};

typedef UINT8 tOBX_CL_STATE;

enum
{
    OBX_CONNECT_REQ_CEVT,   /* API call to send a CONNECT request. */
    OBX_DISCNT_REQ_CEVT,    /* API call to send a DISCONNECT request. */
    OBX_PUT_REQ_CEVT,       /* API call to send a PUT request. */
    OBX_GET_REQ_CEVT,       /* API call to send a GET request.*/
    OBX_SETPATH_REQ_CEVT,   /* API call to send a SETPATH request. */
    OBX_ABORT_REQ_CEVT,     /* API call to send an ABORT request. */
    OBX_OK_CFM_CEVT,        /* Received success response from server. */
    OBX_CONT_CFM_CEVT,      /* Received continue response from server.  */
    OBX_FAIL_CFM_CEVT,      /* Received failure response from server. */
    OBX_PORT_CLOSE_CEVT,    /* Transport is closed. */
    OBX_TX_EMPTY_CEVT,      /* Transmit Queue Empty */
    OBX_FCS_SET_CEVT,       /* Data flow enable */
    OBX_STATE_CEVT,         /* Change state. */
    OBX_TIMEOUT_CEVT,       /* Timeout occurred. */
    OBX_MAX_CEVT
};
typedef UINT8 tOBX_CL_EVENT;


enum
{
    OBX_CONNECT_REQ_SEVT,   /* Received CONNECT request from client. */
    OBX_DISCNT_REQ_SEVT,    /* Received DISCONNECT request from client. */
    OBX_PUT_REQ_SEVT,       /* Received PUT request from client. */
    OBX_GET_REQ_SEVT,       /* Received GET request from client. */
    OBX_SETPATH_REQ_SEVT,   /* Received SETPATH request from client. */
    OBX_ABORT_REQ_SEVT,     /* Received ABORT request from client. */
    OBX_CONNECT_CFM_SEVT,   /* API call to send a CONNECT response. */
    OBX_DISCNT_CFM_SEVT,    /* API call to send a DISCONNECT response or close the connection to the client. */
    OBX_PUT_CFM_SEVT,       /* API call to send a PUT response. */
    OBX_GET_CFM_SEVT,       /* API call to send a GET response. */
    OBX_SETPATH_CFM_SEVT,   /* API call to send a SETPATH response. */
    OBX_ABORT_CFM_SEVT,     /* API call to send an ABORT response. */
    OBX_PORT_CLOSE_SEVT,    /* Transport is closed. */
    OBX_FCS_SET_SEVT,       /* Data flow enable */
    OBX_STATE_SEVT,         /* Change state. */
    OBX_TIMEOUT_SEVT,       /* Timeout has occurred. */
    OBX_BAD_REQ_SEVT,       /* Received a bad request from client. */
    OBX_TX_EMPTY_SEVT,      /* Transmit Queue Empty */
    OBX_MAX_SEVT
};
typedef UINT8 tOBX_SR_EVENT;
#define OBX_SEVT_DIFF_REQ_CFM       6 /* the index difference between *REQ_SEVT and *CFM_SEVT */
#define OBX_SEVT_MAX_REQ            OBX_ABORT_REQ_SEVT /* last *REQ_SEVT */


enum
{
    OBX_SS_NULL,
    OBX_SS_NOT_CONNECTED,
    OBX_SS_CONN_INDICATED,
    OBX_SS_WAIT_AUTH,
    OBX_SS_AUTH_INDICATED,
    OBX_SS_CONNECTED,
    OBX_SS_DISCNT_INDICATED,
    OBX_SS_SETPATH_INDICATED,
    OBX_SS_ABORT_INDICATED,
    OBX_SS_PUT_INDICATED,
    OBX_SS_GET_INDICATED,
    OBX_SS_PUT_TRANSACTION,
    OBX_SS_GET_TRANSACTION,
    OBX_SS_PARTIAL_SENT,
    OBX_SS_MAX
};
typedef UINT8 tOBX_SR_STATE;

typedef UINT8 tOBX_STATE;   /* this must be the same type as tOBX_SR_STATE and tOBX_CL_STATE */

typedef struct
{
    UINT16  pkt_len;/* the packet length */
    UINT8   code;   /* the response/request code without the final bit */
    UINT8   final;  /* TRUE, if the final bit is set */
    UINT8   sm_evt; /* The state machine event*/
} tOBX_RX_HDR;

/* port control block */
typedef struct
{
    BT_HDR          *p_txmsg;           /* The message to send to peer */
    BT_HDR          *p_rxmsg;           /* The message received from peer */
    TIMER_LIST_ENT  tle;                /* This session's Timer List Entry */
    UINT16          port_handle;        /* Port handle of connection       */
    tOBX_HANDLE     handle;             /* The handle of the client or server */
    tOBX_STATE      next_state;         /* Use by PART state to return to regular states */
    UINT16          tx_mtu;             /* The MTU of the connected peer */
    UINT16          rx_mtu;             /* The MTU of this instance */
} tOBX_PORT_CB;

typedef struct
{
    tOBX_PORT_CB   *p_pcb;              /* the port control block */
    UINT32          code;               /* the event code from RFCOMM */
} tOBX_PORT_EVT;

/* client control block */
typedef struct
{
    tOBX_CL_CBACK   *p_cback;           /* Application callback function to receive events */
    BT_HDR          *p_next_req;        /* This is used when the session is flow controlled by peer
                                         * and a DISCONNECT or ABORT request is sent.*/
#if OBX_MD5_INCLUDED == TRUE
    BT_HDR          *p_saved_req;       /* Client saves a copy of the request sent to the server
                                         * Just in case the operation is challenged by the server */
    BT_HDR          *p_auth;            /* The request-digest string, if challenging the server.
                                         * The received OBEX packet, if waiting for password */
#endif
    tOBX_PORT_CB    port;               /* Port control block for this client */
    UINT32          conn_id;            /* Connection ID for this connection */
    tOBX_EVT_PARAM  param;              /* The event parameter. */
    tOBX_EVENT      api_evt;            /* Set the API event, if need to notify user outside of action function. */
    tOBX_CL_STATE   state;              /* The current state */
    tOBX_CL_STATE   prev_state;         /* The previous state */
    UINT8           rsp_code;           /* The response code of the response packet */
    BOOLEAN         final;              /* The final bit status of last request */
#if OBX_MD5_INCLUDED == TRUE
    BOOLEAN         wait_auth;          /* TRUE, if challenges the server and is waiting for the response */
#endif
} tOBX_CL_CB;

/* Authentication Control block */
typedef struct
{
    UINT32          nonce;              /* Timestamp used as nonce */
    tOBX_AUTH_OPT   auth_option;        /* Authentication option */
    UINT8           realm_len;          /* The length of p_realm */
    UINT8           realm[1];           /* The realm of this server. Charset is the first byte */
} tOBX_AUTH_PARAMS;

/* server control block */
typedef struct
{
    tOBX_SR_CBACK   *p_cback;           /* Application callback function to receive events */
#if OBX_MD5_INCLUDED == TRUE
    BT_HDR          *p_saved_msg;       /* This is a message saved for authentication purposes */
    tOBX_AUTH_PARAMS *p_auth;           /* A GKI buffer that holds the authentication related parameters */
#endif
    BT_HDR          *p_next_req;        /* This is a message saved for flow control reasons */
    tOBX_PORT_CB    port;               /* Port control block */
    tOBX_SR_STATE   state;              /* The current state */
    tOBX_TARGET     target;             /* target header of this server */
    UINT32          conn_id;            /* Connection ID for this connection */
    tOBX_EVENT      api_evt;            /* The event to notify the API user. */
    tOBX_EVT_PARAM  param;              /* The event parameter. */
    UINT8           scn;                /* SCN for this server         */
    UINT8           cur_op;             /* The op code for the current transaction (keep this for Abort reasons) */
                                        /* set to the current OP (non-abort) in rfc.c, set it to abort when a response is sent */
} tOBX_SR_CB;

typedef struct
{
#if (OBX_SERVER_INCLUDED == TRUE)
    tOBX_SR_CB      server[OBX_NUM_SERVERS];/* The server control blocks */
    UINT32          next_cid;               /* Next OBEX connection ID for server */
#endif

#if (OBX_CLIENT_INCLUDED == TRUE)
    tOBX_CL_CB      client[OBX_NUM_CLIENTS];/* The client control blocks */
    tOBX_PORT_CB   *p_temp_pcb;         /* Valid only during client RFCOMM_CreateConnection call */
    UINT8           next_ind;           /* The index to the next client control block */
#endif

    tOBX_HANDLE     hdl_map[MAX_PORTS]; /* index of thos array is the port_handle,
                                         * the value is the OBX handle */
    UINT32          timeout_val;        /* The timeout value to wait for activity from peer */
    UINT8           trace_level;        /* The default trace level */
    UINT8           num_client;         /* Number of client control blocks */
    UINT8           num_server;         /* Number of server control blocks */
} tOBX_CB;

/*****************************************************************************
**  Definition for State Machine
*****************************************************************************/

/* Client Action functions are of this type */
typedef tOBX_CL_STATE (*tOBX_CL_ACT)(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);

/* Server Action functions are of this type */
typedef tOBX_SR_STATE (*tOBX_SR_ACT)(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);

#define OBX_SM_IGNORE           0
#define OBX_SM_NO_ACTION        0xFF
#define OBX_SM_ALL              0x80 /* for events like close confirm, abort request, close request where event handling is the same for most of the states */
#define OBX_SM_ENTRY_MASK       0x7F /* state machine entry mask */

#define OBX_SME_ACTION          0
#define OBX_SME_NEXT_STATE      1
#define OBX_SM_NUM_COLS         2

typedef const UINT8 (*tOBX_SM_TBL)[OBX_SM_NUM_COLS];

/*****************************************************************************
**  External global data
*****************************************************************************/
#if OBX_DYNAMIC_MEMORY == FALSE
OBX_API extern tOBX_CB  obx_cb;
#else
OBX_API extern tOBX_CB *obx_cb_ptr;
#define obx_cb (*obx_cb_ptr)
#endif
extern const tOBX_EVENT obx_sm_evt_to_api_evt[];
extern const UINT8 obx_hdr_start_offset[];

/*****************************************************************************
**  External Function Declarations
*****************************************************************************/
/* from obx_main.c */

#if (defined (BT_USE_TRACES) && BT_USE_TRACES == TRUE && OBX_CLIENT_INCLUDED == TRUE)
extern const char * obx_cl_get_state_name(tOBX_CL_STATE state);
extern const char * obx_cl_get_event_name(tOBX_CL_EVENT event);
#else
#define obx_cl_get_state_name(state_num)    ""
#define obx_cl_get_event_name(event_num)    ""
#endif

#if (defined (BT_USE_TRACES) && BT_USE_TRACES == TRUE && OBX_SERVER_INCLUDED == TRUE)
extern const char * obx_sr_get_state_name(tOBX_SR_STATE state);
extern const char * obx_sr_get_event_name(tOBX_SR_EVENT event);
#else
#define obx_sr_get_state_name(state_num)    ""
#define obx_sr_get_event_name(event_num)    ""
#endif
/* client functions in obx_main.c */
extern void obx_cl_timeout(TIMER_LIST_ENT *p_tle);
extern tOBX_CL_CB * obx_cl_alloc_cb(void);
extern tOBX_CL_CB * obx_cl_get_cb(tOBX_HANDLE handle);
extern void obx_cl_free_cb(tOBX_HANDLE handle);
/* server functions in obx_main.c */
extern void obx_sr_timeout(TIMER_LIST_ENT *p_tle);
extern tOBX_SR_CB * obx_sr_alloc_cb(void);
extern tOBX_SR_CB * obx_sr_get_cb(tOBX_HANDLE handle);
extern void obx_sr_free_cb(tOBX_HANDLE handle, BOOLEAN free_cb);
extern UINT32 obx_sr_get_next_conn_id(void);
/* common functions in obx_main.c */
extern tOBX_PORT_CB * obx_port_handle_2cb(UINT16 port_handle);
extern void obx_start_timer(tOBX_PORT_CB *p_pcb);
extern void obx_stop_timer(TIMER_LIST_ENT *p_tle);

/* from obx_rfc.c */
extern void obx_cl_proc_evt(tOBX_PORT_EVT *p_evt);
extern BT_HDR * obx_build_dummy_rsp(tOBX_SR_CB  *p_cb, UINT8 rsp_code);
extern void obx_sr_proc_evt(tOBX_PORT_EVT *p_evt);
extern BOOLEAN obx_snd_msg(tOBX_PORT_CB *p_pcb);
extern tOBX_STATUS obx_open_port(tOBX_PORT_CB *p_pcb, const BD_ADDR bd_addr, UINT8 scn);
extern void obx_close_port(UINT16 port_handle);

/* from obx_capi.c */
extern tOBX_STATUS obx_prepend_req_msg(tOBX_HANDLE handle, tOBX_CL_EVENT event, UINT8 req_code, BT_HDR *p_pkt);

/* from obx_csm.c */
extern void obx_csm_event(tOBX_CL_CB *p_cb, tOBX_EVENT event, BT_HDR *p_msg);

/* from obx_cact.c */
extern tOBX_CL_STATE obx_ca_snd_req(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_close_port(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_snd_part(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_connect_error(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_connect_fail(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_discnt_req(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_notify(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_fail_rsp(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_state(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_start_timer(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_CL_STATE obx_ca_save_req(tOBX_CL_CB *p_cb, BT_HDR *p_pkt);

/* from obx_ssm.c */
extern void obx_ssm_event(tOBX_SR_CB *p_cb, tOBX_SR_EVENT event, BT_HDR *p_msg);

/* from obx_sact.c */
extern tOBX_SR_STATE obx_sa_snd_rsp(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_snd_part(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_abort_rsp(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_op_rsp(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern BT_HDR * obx_conn_rsp(tOBX_SR_CB *p_cb, UINT8 rsp_code, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_connect_ind(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_auth_ind(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_connect_rsp(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_connection_error(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_close_port(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_state(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_nc_to(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_save_req(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
extern tOBX_SR_STATE obx_sa_rej_req(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);

/* from obx_gen.c */
extern void obx_access_rsp_code(BT_HDR *p_pkt, UINT8 *p_rsp_code);
extern BT_HDR * obx_prepend_msg(BT_HDR *p_pkt, UINT8 * p_data, UINT16 data_len);
extern void obx_adjust_packet_len(BT_HDR *p_pkt);
extern UINT16 obx_read_header_len(UINT8 *ph);
extern BT_HDR * obx_dup_pkt(BT_HDR *p_pkt);

/* from obx_md5 */
#if OBX_MD5_INCLUDED == TRUE
extern BT_HDR * obx_unauthorize_rsp(tOBX_SR_CB *p_cb, BT_HDR *p_pkt);
#else
#define obx_unauthorize_rsp(p_cb, p_pkt) NULL
#endif

extern void DispObxMsg (BT_HDR *p_buf, BOOLEAN is_recv);

#endif /* OBX_INT_H */
