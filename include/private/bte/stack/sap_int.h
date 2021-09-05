/*****************************************************************************/
/*                                                                           */
/*  Name:          sap_int.h                                                 */
/*                                                                           */
/*  Description:   This file contains the SIM Access Profile internal        */
/*                 function prototypes, constants, data type definitions     */
/*                                                                           */
/*  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.              */
/*  WIDCOMM Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/
#ifndef SAP_INT_H
#define SAP_INT_H

#include <private/bte/gki.h>
#include <private/bte/stack/sap_api.h>
#include <private/bte/stack/btu.h>
#include <string.h>

/* Message ID definitions (defined by SIM Access Profile specs) */
#define SAP_MSGID_CONNECT_REQ                       0x00
#define SAP_MSGID_CONNECT_RESP                      0x01
#define SAP_MSGID_DISCONNECT_REQ                    0x02
#define SAP_MSGID_DISCONNECT_RESP                   0x03
#define SAP_MSGID_DISCONNECT_IND                    0x04
#define SAP_MSGID_TRANSFER_APDU_REQ                 0x05
#define SAP_MSGID_TRANSFER_APDU_RESP                0x06
#define SAP_MSGID_TRANSFER_ATR_REQ                  0x07
#define SAP_MSGID_TRANSFER_ATR_RESP                 0x08
#define SAP_MSGID_POWER_SIM_OFF_REQ                 0x09
#define SAP_MSGID_POWER_SIM_OFF_RESP                0x0A
#define SAP_MSGID_POWER_SIM_ON_REQ                  0x0B
#define SAP_MSGID_POWER_SIM_ON_RESP                 0x0C
#define SAP_MSGID_RESET_SIM_REQ                     0x0D
#define SAP_MSGID_RESET_SIM_RESP                    0x0E
#define SAP_MSGID_TRANSFER_CARD_READER_STATUS_REQ   0x0F
#define SAP_MSGID_TRANSFER_CARD_READER_STATUS_RESP  0x10
#define SAP_MSGID_STATUS_IND                        0x11
#define SAP_MSGID_ERROR_RESP                        0x12

#define SAP_MSGID_MAX                               0x12
typedef UINT8 tSAP_MSGID;

/* Parameter ID definitions (defined by SIM Access Profile specs) */
#define SAP_PARAMID_MAXMSGSIZE                      0x00
#define SAP_PARAMID_CONNECTIONSTATUS                0x01
#define SAP_PARAMID_RESULTCODE                      0x02
#define SAP_PARAMID_DISCONNECTIONTYPE               0x03
#define SAP_PARAMID_COMMANDAPDU                     0x04
#define SAP_PARAMID_RESPONSEAPDU                    0x05
#define SAP_PARAMID_ATR                             0x06
#define SAP_PARAMID_CARDREADERSTATUS                0x07
#define SAP_PARAMID_STATUSCHANGE                    0x08

#define SAP_PARAMID_MAX                             0x08
typedef UINT8 tSAP_PARAMID;



/* Overhead for SIM Access Profile message header */
#define SAP_MSGHDR_LEN      4           /* 1 byte MsgID + 1 byte NumParams + 2 bytes reserved */
#define SAP_PARAM_OVERHEAD  4           /* 1 byte ParamID + 1 byte reserved + 2 bytes ParamLen */
#define SAP_MSG_MAX_PARAM   2           /* Maximum number of parameters in SIM Access messages */
#define SAP_MSG_OVERHEAD    16          /* Maximum overhead bytes preceding ATR, APDU_RESP (message header + result code param) */
#define SAP_MSG_MAX_LEN     20          /* Maximum length of SIM access messages (for fix-lengthed msgs only) */

#define SAP_INVALID_EVT     0xFF

/* Enumeration of ssm states */
enum
{
    SAP_SSM_ST_NOT_CONN,            /* connection with client opened. */
    SAP_SSM_ST_IDLE,                /* connection opened.Waiting for commands from client, or API calls from application. */
    SAP_SSM_ST_BUSY,                /* Processing SIM access request from client (TRANSFER_APDU_REQ, TRANSFER_ATR_REQ, POWER_SIM_ON_REQ, or TRANSFER_CARD_READER_STATUS_REQ)  */

    SAP_SSM_ST_MAX
};
typedef UINT8 tSAP_SSM_STATE;


/* Enumeration of ssm sub-states */
enum
{
    SAP_SSM_SUBSTATE_NEGOTIATING,
    SAP_SSM_SUBSTATE_ACTIVE,
    SAP_SSM_SUBSTATE_DISCONNECTING,

    SAP_SSM_SUBSTATE_MAX
};
typedef UINT8 tSAP_SSM_SUBSTATE;


/* Server State Machine internal event definitions */
enum
{
    SAP_SSM_RFC_OPEN_EVT,       /* RFCOMM connection with client opened. */
    SAP_SSM_RFC_CLOSE_EVT,      /* RFCOMM connection with client closed. */
    SAP_SSM_STOP_SERVER_EVT,    /* Server application called SAP_StopServer */
    SAP_SSM_SERVER_IND_EVT,     /* Server application called SAP_DisconnectInd or SAP_StatusInd */
    SAP_SSM_SERVER_RESP_EVT,    /* Server application called a response API function */
    SAP_SSM_CLIENT_REQ_EVT,     /* Received a request from client */
    SAP_SSM_INVALID_REQ_EVT,    /* Received a invalid request from client */
    SAP_SSM_TIMEOUT_EVT,        /* Timeout waiting for client to disconnect */

    SAP_SSM_EVT_MAX,
    SAP_SSM_INVALID_EVT = SAP_SSM_EVT_MAX
};
typedef UINT8 tSAP_SSM_EVT;

/* Timeout for waiting for client to close connection (after server sends */
/* DISCONNECT_IND or DISCONNECT_RESP) in seconds */
#define SAP_W4_DISCONNECT_TIMEOUT       2
/*  */
typedef struct
{
    UINT32 code;                /* RFCOMM callback event code */
    UINT16 handle;              /* Port handle */
} tSAP_PORT_EVT;


/* Data for SAP_SSM_RFC_OPEN_EVT */
typedef struct
{
    BD_ADDR bd_addr;
} tSAP_SSM_RFC_OPEN_DATA;


/* Parameter for a SIM Access message */
typedef struct
{
    tSAP_PARAMID        id;
    UINT32              val;
} tSAP_MSGPARAM;

/* Data for response events from application */
typedef struct
{
    tSAP_MSGID          msg_id;
    UINT8               num_params;
    tSAP_MSGPARAM       param[SAP_MSG_MAX_PARAM];
} tSAP_SSM_MSG_DATA;


/*****************************************************************************/
/* parser definitions                                                        */
typedef union
{
    tSAP_SSM_MSG_DATA           msg_data;
    tSAP_SSM_RFC_OPEN_DATA      rfc_open;
} tSAP_SSM_EVT_DATA;




/* Enumeration of parser states */
enum
{
    SAP_PARSE_ST_MSGID,
    SAP_PARSE_ST_NUM_PARMS,
    SAP_PARSE_ST_MSG_HDR_PAD1,
    SAP_PARSE_ST_MSG_HDR_PAD2,
    SAP_PARSE_ST_PARAMID,
    SAP_PARSE_ST_PARAM_HDR_PAD,
    SAP_PARSE_ST_PARAMLEN1,
    SAP_PARSE_ST_PARAMLEN2,
    SAP_PARSE_ST_PARAMVAL,
    SAP_PARSE_ST_IGNORE
};
typedef UINT8 tSAP_PARSE_STATE;

/* Control Block for SIM Access message parser */
typedef struct
{
    tSAP_PARSE_STATE    state;                      /* Current parser state */
    UINT8               cnt;                        /* Number of bytes received so far of current field */
    UINT8               param_idx;                  /* Parameter currently being parsed */
    UINT8               param_is_buf;               /* TRUE if parameter is a data stream */
    UINT16              param_len;                  /* Length of parameter currently being parsed */
    UINT16              param_len_padded;           /* Padded length of parameter currently being parsed */
    UINT8*              p_parambuf;                 /* Pointer to buffer for storing current param being parsed */

    tSAP_SSM_MSG_DATA   msg;                        /* Parsed message data */
} tSAP_PARSER_CB;

/* Macro for padding lengths to 4 bytes boundary */
#define SAP_PADDED_LEN(len)         ((len + 3) & 0xFFFC)



/*****************************************************************************/
/* Server control block                                                      */
typedef struct 
{
    TIMER_LIST_ENT      tle;                /* Timer for server */
    tSAP_SERVER_CBACK   *p_callback;
    UINT16              port_handle;        /* RFCOMM server port handle */
    BOOLEAN             in_use;             /* TRUE if server is started */
    UINT8               scn;                /* Server SCN */
    UINT16              mtu;                /* RFCOMM mtu size */
    tSAP_SSM_STATE      state;              /* Current server state */
    tSAP_SSM_SUBSTATE   substate;           /* Cuurent substate (only used for RFCOMM UP states) */
    tSAP_CARD_STATUS    card_status;        /* Current status of SIM card */

    tSAP_PARSER_CB      parser;             /* Parser control block */
} tSAP_SCB;

/* Definitions for service record */
#define SAP_SDP_NUM_PROTO_ELEM  2

/*****************************************************************************/
/* Control block                                                             */
typedef struct {
    tSAP_SCB    scb;
    UINT8       trace_level;
} tSAP_CB;
extern tSAP_CB sap_cb;

void sap_ssm_execute(tSAP_SSM_EVT ssm_evt, tSAP_SSM_EVT_DATA *p_evt_data);
void sap_ssm_setstate(tSAP_SSM_STATE new_state);
void sap_ssm_rsp_evt(tSAP_MSGID rsp_id, UINT8 num_params, tSAP_PARAMID param_id0, UINT32 parm_val0, tSAP_PARAMID param_id1, UINT32 parm_val1);
void sap_ssm_req_evt(tSAP_SSM_MSG_DATA *p_msg_data);


/* Server state machine action function prototypes */
typedef void (*tSAP_ACTION)(tSAP_SSM_EVT_DATA *p_data);              /* type for action functions */
void sap_sact_rfc_open(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_rfc_close(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_server_stop(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_ind(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_resp(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_idle_req(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_busy_req(tSAP_SSM_EVT_DATA *p_evt_data);
void sap_sact_timeout(tSAP_SSM_EVT_DATA *p_evt_data);

void sap_sact_error_rsp(tSAP_SSM_EVT_DATA *p_evt_data);

/* State machine action table definitions */
#define SAP_SM_NUM_COLS     2
#define SAP_SR_ST_TBL_COL_ACTION    0
#define SAP_SR_ST_TBL_COL_NXT_STATE 1



/*****************************************************************************/
/* sap_util interface                                                       */

/* Return values for sap_util_parse */
enum {
    SAP_PARSE_STATUS_OK,        /* Parsing was successful; entire message parsed */
    SAP_PARSE_STATUS_PARTIAL,   /* Parsing was successful; partial message parsed */
    SAP_PARSE_STATUS_BAD_PARAM, /* Entire message parsed, but parameter(s) are invalid */
    SAP_PARSE_STATUS_ERROR      /* Parsing was not successful */
};

void sap_util_insert_hdr(tSAP_MSGID msg_id, BT_HDR *p_msg);
BT_HDR *sap_util_fmt_msg(tSAP_SSM_MSG_DATA *p_msg_data);
BOOLEAN sap_util_fmt_and_send_msg(tSAP_SSM_MSG_DATA *p_msg_data);
UINT8 *sap_util_insert_param(UINT8 *p_buf, tSAP_PARAMID param_id, void *p_param_data);
UINT8 sap_util_parse_msg(tSAP_PARSER_CB *p_parser_cb, char buf[], UINT16 buf_len, UINT16 *p_bytes_parsed, tSAP_SSM_MSG_DATA *p_msg_buf);
void sap_util_start_disc_timer(void);
void sap_util_stop_disc_timer(void);

extern const char *sap_util_msgid_str[];        /* Msg ID descriptor stings */

/*****************************************************************************/
/* sap_rfc interface                                                         */

/* RFCOMM interface definitions */
#define SAP_PORT_EVENT_MASK  (PORT_EV_RXCHAR | PORT_EV_CONNECT_ERR | PORT_EV_TXEMPTY | \
                              PORT_EV_FC | PORT_EV_FCS | PORT_EV_CONNECTED)
void sap_rfc_cback(UINT32 code, UINT16 port_handle);
tSAP_STATUS sap_rfc_open(UINT16 *p_handle, BOOLEAN is_server, const BD_ADDR bd_addr, UINT8 scn, UINT16 mtu);
void sap_rfc_close(UINT16 port_handle);
void sap_rfc_send_msg(BT_HDR *p_msg);
void sap_proc_btu_event(BT_HDR *p_msg);
void sap_process_timeout(TIMER_LIST_ENT *p_tle);


#endif  /* SAP_INT_H */
