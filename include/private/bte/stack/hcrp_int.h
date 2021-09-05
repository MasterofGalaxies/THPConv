/*****************************************************************************
** 
**    File Name:   hcrp_int.h
**
**  Description:   This file contains the HCRP internal interfaces.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HCRP_INT_H
#define HCRP_INT_H

#include <private/bte/gki.h>
#include <private/bte/stack/btu.h>
#include <private/bte/stack/hcrp_api.h>
#include <private/bte/stack/hcrp_fsm.h>
#include <private/bte/stack/hcrp_notif.h>
#include <private/bte/stack/gap_api.h>

#if HCRP_FSM_DEBUG == TRUE
#include <private/bte/stack/wcassert.h>
#endif

/************************ Protocol Constants used internally *************************/

#define HCRP_CREDIT_GRANT_UPDATES   1    /*  seconds between successive credit grant
                                             retries (0 - turns off interval updates) */
#define HCRP_PROFILE_VERSION    ((UINT16) 0x0100)

#define HCRP_PDU_HDR_ID_LEN     2   /* PDU ID length (2 bytes) */
#define HCRP_PDU_HDR_TID_LEN    2   /* PDU Transaction ID length (2 bytes) */
#define HCRP_PDU_HDR_PARAM_LEN  2   /* PDU parameter length (2 bytes) */
#define HCRP_PDU_RSP_STATUS_LEN 2   /* PDU return status length (2 bytes) */

#define HCRP_PDU_HDR_SIZE       (HCRP_PDU_HDR_ID_LEN + HCRP_PDU_HDR_TID_LEN + \
                                 HCRP_PDU_HDR_PARAM_LEN)

#define HCRP_PDU_RSP_HDR_SIZE   (HCRP_PDU_HDR_ID_LEN + HCRP_PDU_HDR_TID_LEN + \
                                 HCRP_PDU_HDR_PARAM_LEN + HCRP_PDU_RSP_STATUS_LEN)

#define HCRP_MAX_CTRL_PDU_LEN   (HCRP_CMD_POOL_SIZE - L2CAP_MIN_OFFSET)
#define HCRP_MAX_DATA_PDU_LEN   (L2CAP_MTU_SIZE - L2CAP_MIN_OFFSET)

#define HCRP_MAX_CTRL_PARAM_LEN (HCRP_MAX_CTRL_PDU_LEN - HCRP_PDU_RSP_HDR_SIZE) /* max param length of ctrl channel */

#define HCRP_DEF_SERVICE_NAME   "HCRP"

/* Vendor Specific */
#define HCRP_MIN_VS_CMD     ((UINT16)0x8000)    /* Minimum value a vendor specific command can have */

/* PDU ID definitions */
#define HCRP_PDU_RESERVED_ID    ((UINT16) 0x0000)   /* reserved */
#define HCRP_PDU_CR_GRANT_ID    ((UINT16) 0x0001)   /* credit grant */
#define HCRP_PDU_CR_REQUEST_ID  ((UINT16) 0x0002)   /* credit request */
#define HCRP_PDU_CR_RETURN_ID   ((UINT16) 0x0003)   /* credit return */
#define HCRP_PDU_CR_QUERY_ID    ((UINT16) 0x0004)   /* credit query */
#define HCRP_PDU_LPT_STATUS_ID  ((UINT16) 0x0005)   /* get LPT status */
#define HCRP_PDU_1284_ID        ((UINT16) 0x0006)   /* get 1284 ID string */
#define HCRP_PDU_SOFT_RESET_ID  ((UINT16) 0x0007)   /* soft reset */
#define HCRP_PDU_HARD_RESET_ID  ((UINT16) 0x0008)   /* hard reset */
#define HCRP_PDU_REG_NOTIF_ID   ((UINT16) 0x0009)   /* register for notifications */
#define HCRP_PDU_NCONN_ALIVE_ID ((UINT16) 0x000a)   /* notification connection alive */

/* PDU command and response parameter lengths */
#define HCRP_PDU_NO_PARMS_CMD_LEN       (0)  /* Used for all commands void of parameters */
#define HCRP_PDU_CREDIT_CMD_LEN         (4)  /* credit grant, return, and query */
#define HCRP_PDU_1284_ID_CMD_LEN        (4)  /* get 1284 ID string command */
#define HCRP_PDU_REG_NOTIF_CMD_LEN      (9)  /* register for notifications */

typedef struct
{
    UINT16  pdu_id;     /* PDU ID */
    UINT16  tid;        /* Transaction ID */
    UINT16  param_len;  /* Length of parameters to follow (status is first 2 bytes of parameters) */
    UINT16  status;     /* Return status */
} tHCRP_PROTO_RSP_HDR;


/***********************************************************************************
***************************** HCRP Client Control Blocks ***************************
************************************************************************************/

/**********************************************
** Send Data control block information
***********************************************/
typedef struct
{
    UINT32   rem_peer_credits;  /* Remaining number of credits the peer has granted us */
    UINT32   low_wmark;         /* credit watermark used to signal requesting more credits */
    UINT16   tot_bytes;         /* Total number of bytes to send out when credits are granted */
    UINT16   rem_bytes;         /* Remaining bytes to send out when credits are granted */
    BT_HDR  *p_cur_buf;         /* Pointer to current write buffer */
    BOOLEAN  is_active;         /* Is data currently being sent */
} tHCRP_SND_DATA_CB;


/**********************************************
** Data Credits control block information
***********************************************/
typedef struct
{
    UINT32   rem_peer_credits;  /* Remaining credits available to peer (already granted) */
    UINT32   appl_granted;      /* Number of credits application has granted HCRP */
    UINT32   low_wmark;         /* credit watermark used to signal appl or client to grant more credits */
} tHCRP_RCV_DATA_CB;


/* Discovery Control Block */
typedef struct
{
    tSDP_DISCOVERY_DB   *p_db;      /* Discovery database */
    UINT32               db_len;
    BD_ADDR              last_addr_used; /* cached BD_ADDR */
    UINT8                function;
} tHCRP_DISCOVERY_CB;


/* GAP Control Block information */
#define HCRP_GAP_HANDLE_UNUSED  ((UINT16)0xffff)

typedef struct
{
    UINT16  ctrl_handle;    /* handle of the GAP control channel */
    UINT16  ctrl_psm;
    UINT16  rem_ctrl_mtu;   /* remote device MTU for the GAP control channel */
    UINT16  data_handle;    /* handle of the GAP data channel */
    UINT16  data_psm;
    UINT16  rem_data_mtu;   /* remote device MTU for the GAP data channel */
#if HCRP_NOTIFICATION_INCLUDED == TRUE
    tHCRP_NOTIF_GCB notif_info; /* Notification - GAP channel related information */
#endif
    BD_ADDR remote_bd_addr; /* Device address of peer connected to */
    BOOLEAN ctrl_chan_open;
    BOOLEAN ctrl_chan_cong; /* TRUE if control channel is congested */
    BOOLEAN data_chan_open;
    BOOLEAN data_chan_cong; /* TRUE if data channel is congested */
} tHCRP_GAP_CB;

/***********************************************************************************
****************************** HCRP Main Control Block *****************************
************************************************************************************/

typedef struct
{
    tHCRP_RCV_DATA_CB    rcv;                   /* Holds current receive credit information */
    tHCRP_SND_DATA_CB    snd;                   /* Contains the current send data credit information */
    tHCRP_DISCOVERY_CB   disc_cb;               /* Contains the control block for discovery */
    tHCRP_GAP_CB         gap_cb;                /* Contains the data relating to the GAP connection */
    BUFFER_Q             cmd_q;                 /* Queue of buffers waiting to be sent */
    TIMER_LIST_ENT       w4close_te;            /* Timer waiting for 2nd channel to close */
    TIMER_LIST_ENT       protorsp_te;           /* Time to give up waiting for response from peer */
    TIMER_LIST_ENT       cr_request_te;         /* Is it time to send credit request? */
    TIMER_LIST_ENT       cr_grant_te;           /* Is it time to send credit grant? */
    tHCRP_CMD_CBACK     *cmd_cback;             /* Callback notifies application of command responses/results */
    tHCRP_RCV_CBACK     *rcv_cback;             /* Callback notifies application of received data */
    UINT32               snd_low_wmark;         /* credit watermark used to signal requesting more credits */
    UINT32               rcv_low_wmark;         /* credit watermark used to signal appl or client to grant more credits */
    UINT16               function;              /* Supported functions UUID (print or scan) [see sdpdefs.h] */
    UINT16               trans_id;              /* Transaction id of active command */
    UINT16               new_trans_id;          /* transaction id of next loaded message */
    UINT16               int_cmd_pend;          /* ID of currently active command (0 - means none active) */
    UINT8                options;               /* HCRP_REG_OPT_NOTIFICATION |  HCRP_REG_OPT_VENDOR_SPEC  |
                                                   HCRP_REG_OPT_LIMITED_DISC */
    UINT8                security;              /* Security requirements for HCRP (see options above) */
    tHCRP_PROTO_CMD_ID   api_cmd_pend;          /* ID of currently active API protocol command (0 - none) */
    tHCRP_CFSM_STATE     fsm_state;             /* State of HCRP's State Machine */
    BOOLEAN              in_use;                /* Control block is in use? */
    BOOLEAN              notif_in_use;          /* Notification Control block is in use? */
    BOOLEAN              credit_pending;        /* credit request pending */
    UINT8                zero_cr_retry_count;   /* how many times to send credit request before using timer */
    UINT8                trace_level;

#if HCRP_NOTIFICATION_INCLUDED == TRUE
    tHCRP_NOTIF_CCB      cncb;          /* notification control block information */
#endif

} tHCRP_CB;


typedef tHCRP_STATUS (tHCRP_ACTION) (void *);
typedef tHCRP_STATUS (*tHCRP_ACTIONPTR)(void *);

/***********************************************************************************
************** HCRP Queued Event Definitions (from APIs and internal) **************
************************************************************************************/

/******************* PROTOCOL MSGS *************************/
/* Credit grant, request, query, or return message
** Used for command and response messages
*/
typedef struct
{
    tHCRP_RSP_HDR   hdr;
    UINT32          credits;
} tHCRP_CREDIT_MSG;

/*********************** End of protocol definitions *****************************/


/* Find Services Message */
typedef struct
{
    tSDP_DISCOVERY_DB   *p_db;
    UINT32               db_len;
    BD_ADDR              bd_addr;
    UINT8                function;
} tHCRP_FIND_SERVICES_MSG;

/* Establish Connection */
typedef struct
{
    UINT16  ctrl_psm;
    UINT16  data_psm;
    BD_ADDR bd_addr;
} tHCRP_EST_CONN_MSG;


/**************** I n t e r n a l   E v e n t s *******************/

/* Message used between GAP control channel and state machine */
typedef struct
{
    UINT16   handle;
    BT_HDR  *p_buf;
} tHCRP_GAP_CCHAN_DATA;


/******************************************************************/


/* Utilities */
#define HCRP_BDADDR_CMP(bd1, bd2)    ( memcmp((void *)(bd1), (void *)(bd2), BD_ADDR_LEN) )


#ifdef __cplusplus
extern "C" 
{
#endif

/* HCRP Control Block external declarations (within HCRP modules) */
#if HCRP_DYNAMIC_MEMORY == FALSE
HCRP_API extern tHCRP_CB  hcrp_cb;
#else
HCRP_API extern tHCRP_CB *hcrp_cb_ptr;
#define hcrp_cb (*hcrp_cb_ptr)
#endif

extern const tHCRP_ACTIONPTR hcrp_action_tbl[];

/*************** HCRP Core Utility and Action Functions Externs *****************/
extern tHCRP_STATUS hcrp_enqueue_evt(UINT8 event, void *p_evt_data, UINT16 len);
extern void         hcrp_flush_data(tHCRP_CB *p_cb);

/*************** HCRP GAP Utility Functions Externs *****************/
extern void         hcrp_gap_init(tHCRP_GAP_CB *p_gap);
extern void         hcrp_gap_set_mode(UINT16, UINT16);
extern void         hcrp_gap_close_chans(tHCRP_CB *p_cb);
extern tHCRP_STATUS hcrp_gap_close_notif_chan(tHCRP_CB *p_cb);

/*************** HCRP GAP Action Functions Externs *****************/
extern tHCRP_STATUS hcrp_gap_init_ctrl_chan(tHCRP_EST_CONN_MSG *p_msg);
extern tHCRP_STATUS hcrp_gap_init_data_chan(UINT16 *p_handle);


/*************** HCRP SDP Utility Functions Externs *****************/
extern void         hcrp_sdp_init(tHCRP_DISCOVERY_CB *p_cb);
extern tHCRP_STATUS hcrp_sdp_register_service(tHCRP_CB *p_cb, tHCRP_CLIENT_REG_INFO *p_reg,
                                              UINT32 **pp_handle);
extern void         hcrp_sdp_deregister_service(tHCRP_CB *p_cb);

/*************** HCRP SDP Action Functions Externs *****************/
extern tHCRP_STATUS hcrp_sdp_prfm_core_discovery(tHCRP_FIND_SERVICES_MSG *p_msg);
extern tHCRP_STATUS hcrp_sdp_find_services(UINT16 *p_sdp_status);

#if HCRP_NOTIFICATION_INCLUDED == TRUE
/*************** HCRP Notification Action and Utility Function Externs *****************/
extern void         hcrp_notif_deregister_all(tHCRP_CB *p_cb);
extern tHCRP_STATUS hcrp_notif_proc_open(UINT16 *p_handle);
extern tHCRP_STATUS hcrp_notif_proc_close(void *p_data);
extern tHCRP_STATUS hcrp_notif_listen_mode(tHCRP_CB *p_cb);
extern tHCRP_STATUS hcrp_notif_proc_notif(BT_HDR **p_buf);
extern void         hcrp_notif_client_init(tHCRP_CB *p_cb,
                                           tHCRP_CLIENT_REG_INFO *p_reg);
extern tHCRP_STATUS hcrp_notif_client_proc_dereg(tHCRP_CB *p_cb, BOOLEAN expired);
extern void         hcrp_notif_set_mode (BOOLEAN enable);

#else   /* Insert stubs because the modules are not linked in */
#define hcrp_notif_client_proc_dereg(p_cb, expired)
#define hcrp_notif_client_init(p_notif_cb, p_reg)
#define hcrp_gap_init_notif_chan(p_data)
#define hcrp_gap_close_notif_chan(p_cb)
#define hcrp_notif_deregister_all(p_cb)
#define hcrp_notif_deregister   NULL

#endif  /* HCRP_NOTIFICATION_INCLUDED */

#ifdef __cplusplus
}
#endif

#endif /* HCRP_INT_H */

