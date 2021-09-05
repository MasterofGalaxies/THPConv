/*****************************************************************************
** 
**    File Name:   hcrpm_int.h
**
**  Description:   This file contains the HCRP internal interfaces.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HCRPM_INT_H
#define HCRPM_INT_H

#include <private/bte/stack/hcrpm_api.h>
#include <private/bte/stack/hcrpm_fsm.h>
#include <private/bte/stack/hcrpm_notif.h>
#include <private/bte/stack/gap_api.h>
#include <private/bte/gki.h>

/************************ Protocol Constants used internally *************************/

#define HCRPM_PROFILE_VERSION    ((UINT16) 0x0100)

#define HCRPM_PDU_HDR_ID_LEN     2   /* PDU ID length (2 bytes) */
#define HCRPM_PDU_HDR_TID_LEN    2   /* PDU Transaction ID length (2 bytes) */
#define HCRPM_PDU_HDR_PARAM_LEN  2   /* PDU parameter length (2 bytes) */
#define HCRPM_PDU_RSP_STATUS_LEN 2   /* PDU return status length (2 bytes) */

#define HCRPM_PDU_RSP_HDR_SIZE   (HCRPM_PDU_HDR_ID_LEN + HCRPM_PDU_HDR_TID_LEN + \
                                  HCRPM_PDU_HDR_PARAM_LEN + HCRPM_PDU_RSP_STATUS_LEN)

#define HCRPM_MAX_CTRL_PDU_LEN   (HCRP_CMD_POOL_SIZE - L2CAP_MIN_OFFSET)
#define HCRPM_MAX_DATA_PDU_LEN   (L2CAP_MTU_SIZE - L2CAP_MIN_OFFSET)

#define HCRPM_MAX_CTRL_PARAM_LEN (HCRPM_MAX_CTRL_PDU_LEN - HCRPM_PDU_RSP_HDR_SIZE) /* max param length of ctrl channel */

#define HCRPM_DEF_SERVICE_NAME   "HCRP"

/* Vendor Specific */
#define HCRPM_MIN_VS_CMD     ((UINT16)0x8000)    /* Minimum value a vendor specific command can have */

/* PDU ID definitions */
#define HCRPM_PDU_RESERVED_ID    ((UINT16) 0x0000)   /* reserved */
#define HCRPM_PDU_CR_GRANT_ID    ((UINT16) 0x0001)   /* credit grant */
#define HCRPM_PDU_CR_REQUEST_ID  ((UINT16) 0x0002)   /* credit request */
#define HCRPM_PDU_CR_RETURN_ID   ((UINT16) 0x0003)   /* credit return */
#define HCRPM_PDU_CR_QUERY_ID    ((UINT16) 0x0004)   /* credit query */
#define HCRPM_PDU_LPT_STATUS_ID  ((UINT16) 0x0005)   /* get LPT status */
#define HCRPM_PDU_1284_ID        ((UINT16) 0x0006)   /* get 1284 ID string */
#define HCRPM_PDU_SOFT_RESET_ID  ((UINT16) 0x0007)   /* soft reset */
#define HCRPM_PDU_HARD_RESET_ID  ((UINT16) 0x0008)   /* hard reset */
#define HCRPM_PDU_REG_NOTIF_ID   ((UINT16) 0x0009)   /* register for notifications */
#define HCRPM_PDU_NCONN_ALIVE_ID ((UINT16) 0x000a)   /* notification connection alive */

/* PDU Response lengths */
#define HCRPM_PDU_NO_PARMS_RSP_LEN       (2)  /* Contains only the return status */
#define HCRPM_PDU_CREDIT_RSP_LEN         (6)  /* credit grant, request, return, and query */
#define HCRPM_PDU_LPT_STATUS_RSP_LEN     (3)  /* get LPT status response + return status */
#define HCRPM_PDU_REG_NOTIF_RSP_LEN      (10) /* register for notifications response + return status */
#define HCRPM_PDU_NCONN_ALIVE_RSP_LEN    (6)

#define HCRPM_DCHAN_PSM_OFFSET  2       /* Offset from control channel PSM */

/**********************************************
** Send Data control block information
***********************************************/
typedef struct
{
    UINT32   rem_peer_credits;  /* Remaining number of credits the peer has granted us */
    UINT16   tot_bytes;         /* Total number of bytes to send out when credits are granted */
    UINT16   rem_bytes;         /* Remaining bytes to send out when credits are granted */
    BT_HDR  *p_cur_buf;         /* Pointer to current write buffer */
    BOOLEAN  is_active;         /* Is data currently being sent */
} tHCRPM_SND_DATA_CB;


/**********************************************
** Data Credits control block information
***********************************************/
typedef struct
{
    UINT32   rem_peer_credits;  /* Remaining credits available to peer (already granted) */
    UINT32   appl_granted;      /* Number of credits application has granted HCRP */
    UINT32   low_wmark;         /* credit watermark used to signal appl or client to grant more credits */
} tHCRPM_RCV_DATA_CB;


/* GAP Control Block information */
#define HCRPM_GAP_HANDLE_UNUSED  ((UINT16)0xffff)

typedef struct
{
    UINT16  ctrl_handle;    /* handle of the GAP control channel */
    UINT16  rem_ctrl_mtu;   /* remote device MTU for the GAP control channel */
    UINT16  data_handle;    /* handle of the GAP data channel */
    UINT16  rem_data_mtu;   /* remote device MTU for the GAP data channel */
    BD_ADDR remote_bd_addr; /* Device address of peer connected to */
    BOOLEAN ctrl_chan_open;
    BOOLEAN ctrl_chan_cong; /* TRUE if control channel is congested */
    BOOLEAN data_chan_open;
    BOOLEAN data_chan_cong; /* TRUE if data channel is congested */
} tHCRPM_GAP_CB;

/***************************************************
** Client-specific Server control block information
****************************************************/
typedef struct
{
    TIMER_LIST_ENT      apprsp_te;      /* Timer waiting for a reply from application */
    TIMER_LIST_ENT      w4open_te;      /* Timer waiting for 2nd GAP channel to open */
    TIMER_LIST_ENT      w4close_te;     /* Timer waiting for 2nd channel to close */
    tHCRPM_RCV_DATA_CB  rcv;            /* Holds current receive credit information */
    tHCRPM_SND_DATA_CB  snd;            /* Contains the current send data credit information */
    tHCRPM_GAP_CB       gap_cb;         /* Contains the data relating to the GAP connection */
    UINT32              rcv_low_wmark;  /* credit watermark used to signal appl to grant more credits */
    UINT16              trans_id;       /* Transaction id of active command */
    tHCRPM_PROTO_CMD_ID api_cmd_pend;   /* ID of currently active API protocol command (0 - none) */
    tHCRPM_FSM_STATE    fsm_state;      /* State of HCRP's State Machine */
    BOOLEAN             rcvrdy_active;  /* True if low credit issued */
    BOOLEAN             is_registered;  /* This client instance is registered? */
    UINT8               chandle;        /* Handle number for this  control block */
} tHCRPM_SERVER_INFO;

/***********************************************************************************
****************************** HCRP Main Control Block *****************************
************************************************************************************/
typedef struct
{
    tHCRPM_CMD_CBACK    *cmd_cback;     /* Callback notifies application of command responses/results */
    tHCRPM_RCV_CBACK    *rcv_cback;     /* Callback notifies application of received data */
    UINT32               sdp_handle;    /* control/Data channel handle */
    tHCRPM_SERVER_INFO   info[HCRPM_MAX_CLIENTS];/* Server specific registration information */
    UINT16               function;      /* Supported functions UUID (print or scan) [see sdpdefs.h] */
    UINT16               base_psm;      /* Used in determining the control and data PSMs for the server */
    UINT8                options;       /* HCRPM_REG_OPT_NOTIFICATION |  HCRPM_REG_OPT_VENDOR_SPEC  |
                                           HCRPM_REG_OPT_LIMITED_DISC */
    UINT8                security;      /* Security requirements for HCRPM (see options above) */
    UINT8                max_clients;   /* Desired clients (from application) */
    UINT8                trace_level;
    tHCRPM_SERVER_MODE   mode;          /* offline, private online, or public online */
    BOOLEAN              is_registered; /* Is the server registered? */
    UINT8                saved_l2c_role; /* Saved role; restored when deregistering */
    UINT8                service_name_len;
    UINT8                service_name[HCRP_MAX_SERVICE_NAME_LEN + 1];
#if HCRP_NOTIFICATION_INCLUDED == TRUE
    tHCRPM_NOTIF_CB      notif_cb;      /* Notification control block */
#endif
} tHCRPM_CB;

typedef tHCRPM_STATUS (tHCRPM_ACTION) (UINT8 handle, void *);
typedef tHCRPM_STATUS (*tHCRPM_ACTIONPTR)(UINT8 handle, void *);


/**********************************************************
************** HCRP Queued Event Definitions **************
***********************************************************/

/******************* PROTOCOL MSGS *************************/
/* Credit grant, request, query, or return message
** Used for command and response messages
*/
typedef struct
{
    tHCRPM_RSP_HDR   hdr;
    UINT32          credits;
    UINT8           handle;
} tHCRPM_CREDIT_MSG;


/*********************** End of protocol definitions *****************************/

/* Send Data Msg */
typedef struct
{
    BT_HDR *p_buf;
    UINT8   handle;
} tHCRPM_SEND_DATA_MSG;

/* Receive Ready Credits Msg */
typedef struct
{
    UINT32  credits;
    UINT8   handle;
} tHCRPM_RCV_READY_MSG;

/**************** I n t e r n a l   E v e n t s *******************/
/* Message used between GAP control channel and state machine */
typedef struct
{
    UINT16   handle;
    BT_HDR  *p_buf;
} tHCRPM_GAP_CCHAN_DATA;
/******************************************************************/

/* Utilities */
#define HCRPM_BDADDR_CMP(bd1, bd2)    ( memcmp((void *)(bd1), (void *)(bd2), BD_ADDR_LEN) )

#ifdef __cplusplus
extern "C" 
{
#endif

/* HCRPM Control Block external declarations (within HCRP modules) */
#if HCRP_DYNAMIC_MEMORY == FALSE
HCRP_API extern tHCRPM_CB  hcrpm_cb;
#else
HCRP_API extern tHCRPM_CB *hcrpm_cb_ptr;
#define hcrpm_cb (*hcrpm_cb_ptr)
#endif

extern const tHCRPM_ACTIONPTR hcrpm_action_tbl[];

/*************** HCRPM Core Utility and Action Functions Externs *****************/
extern tHCRPM_STATUS hcrpm_enqueue_evt(UINT8 chandle, UINT8 event, void *p_evt_data,
                                       UINT16 len);
extern tHCRPM_STATUS hcrpm_core_register(tHCRPM_SERVER_REG_INFO *p_reg);
extern void          hcrpm_core_deregister(void);
extern void          hcrpm_flush_data(UINT8 chandle, tHCRPM_CB *p_cb);
extern void          hcrpm_reg_update(tHCRPM_REG_UPDATE_INFO *p_reg);
extern void          hcrpm_core_set_mode(tHCRPM_SERVER_MODE *p_mode);

/*************** HCRP GAP Utility Functions Externs *****************/
extern void          hcrpm_gap_init(tHCRPM_GAP_CB *p_gap);
extern void          hcrpm_gap_set_mode(UINT16, UINT16);
extern void          hcrpm_gap_close_chans(UINT8 chandle, tHCRPM_CB *p_cb);
extern tHCRPM_STATUS hcrpm_gap_listen_mode(tHCRPM_SERVER_INFO *p_scb, tHCRPM_CB *p_cb);
extern void          hcrpm_gap_set_cod (UINT8 cmd, UINT16 function);

/*************** HCRP SDP Utility Functions Externs *****************/
extern tHCRPM_STATUS hcrpm_sdp_register_service(tHCRPM_CB *p_cb,
                                                tHCRPM_SERVER_REG_INFO *p_reg,
                                                UINT32 *p_handle);
extern void          hcrpm_sdp_deregister_service(tHCRPM_CB *p_cb);
extern tHCRPM_STATUS hcrpm_sdp_update(UINT8 dev_name_len, UINT8 *p_dev_name,
                                      UINT8 dev_loc_len, UINT8 *p_dev_loc);

#if HCRP_NOTIFICATION_INCLUDED == TRUE
/*************** HCRP Notification Action and Utility Function Externs *****************/
extern void             hcrpm_notif_deregister_all(tHCRPM_NOTIF_CB *p_ncb);
extern void             hcrpm_notif_server_init(void);
extern tHCRPM_NOTIF_CCB *hcrpm_notif_alloc_cb (UINT8 chandle, tHCRPM_CB *p_cb,
                                               UINT32 context_id);
extern tHCRPM_NOTIF_CCB *hcrpm_notif_find_cb (tHCRPM_CB *p_cb, BD_ADDR bd_addr);
extern void             hcrpm_notif_server_dereg_single_client(tHCRPM_NOTIF_CCB *p_server_cb);
extern void             hcrpm_notif_send_notif(UINT16 *p_handle);
extern tHCRPM_STATUS    hcrpm_notif_deregister(UINT8 chandle, tHCRPM_SERVER_INFO *p_scb);
extern void             hcrpm_start_notif(tHCRPM_NOTIF_CMD_MSG *p_msg);
extern tHCRPM_STATUS    hcrpm_gap_init_notif_chan(void);
extern tHCRPM_STATUS    hcrpm_sdp_prfm_notif_discovery(tHCRPM_NOTIF_CB *p_ncb);
extern tHCRPM_STATUS    hcrpm_sdp_find_notif_service (void);
extern void             hcrpm_sdp_complete(UINT16 sdp_status);
extern void             hcrpm_notif_close (void);
extern tHCRPM_NOTIF_CCB *hcrpm_notif_find_cb_by_cid (UINT32 context_id, BD_ADDR rbd);
extern void             hcrpm_notif_start_keep_alive_timer(tHCRPM_NOTIF_CCB *p_ccb);

#else   /* Insert stubs because the modules are not linked in */
#define hcrpm_notif_server_init()
#define hcrpm_gap_init_notif_chan HCRPM_NOTIF_FAILED
#define hcrpm_notif_deregister_all(p_ncb)
#define hcrpm_notif_find_cb(p_cb, bd_addr)   NULL
#define hcrpm_notif_deregister   NULL

#endif  /* HCRP_NOTIFICATION_INCLUDED */

#ifdef __cplusplus
}
#endif

#endif /* HCRP_INT_H */

