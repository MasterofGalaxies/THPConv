/*****************************************************************************
**
**  Name:           opp_srvr_int.h
**
**  Description:    This is the private file for the object transfer
**                  server (OPP).
**
**  Copyright (c) 2003-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef OPP_SRVR_INT_H
#define OPP_SRVR_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/opp_api.h>
#include <private/bte/stack/goep_fs.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/

/* Mask for handle inside event code */
#define OPP_EVENT_MASK          0xFF1F  /* Maximum number of events is 32 */
#define OPP_HANDLE_MASK         0x00E0  /* Maximum number of handles is 7 */
#define OPP_HANDLE_SHIFT        5       /* Handle is shifted 5 bits */

/* Macros to insert and extract handle in call-out and call-in events */
#define OPP_INSERT_HANDLE(hnd)  ((hnd) << OPP_HANDLE_SHIFT)
#define OPP_EXTRACT_HANDLE(hnd) (((hnd) & OPP_HANDLE_MASK) >> OPP_HANDLE_SHIFT)

#define OPP_SRVR_NUM_FMTS        7
#define OPP_SRVR_ALL_FMTS_MASK   0x7f

/* state machine events */
enum
{
    /* these events are handled by the state machine */
    OPP_SRVR_API_DISABLE_EVT = BT_EVT_TO_OPP_SRVR_CMDS,

    OPP_SRVR_API_ACCESSRSP_EVT,      /* Response to an access request */
    OPP_SRVR_API_CLOSE_EVT,          /* Close API */
    OPP_SRVR_CI_OPEN_EVT,            /* Response to File Open request */
    OPP_SRVR_CI_WRITE_EVT,           /* Response to Write request */
    OPP_SRVR_CI_READ_EVT,            /* Response to Read request */
    OPP_SRVR_OBX_CONN_EVT,           /* OBX Channel Connect Request */
    OPP_SRVR_OBX_DISC_EVT,           /* OBX Channel Disconnect */
    OPP_SRVR_OBX_ABORT_EVT,          /* OBX_operation aborted */
    OPP_SRVR_OBX_CLOSE_EVT,          /* OBX Channel Disconnected (Link Lost) */
    OPP_SRVR_OBX_PUT_EVT,            /* Write file data or delete */
    OPP_SRVR_OBX_GET_EVT,            /* Read file data or folder listing */
    OPP_SRVR_OBX_TOUT_EVT,           /* OBX Connection Timeout */
    OPP_SRVR_CLOSE_CMPL_EVT,         /* Finished closing channel */

    /* these events are handled outside the state machine */
    OPP_SRVR_API_SDP_EVT,            /* Register SDP API */
    OPP_SRVR_API_ENABLE_EVT
};

typedef UINT16 tOPP_SRVR_INT_EVT;

/* state machine states */
enum
{
  OPP_SRVR_LISTEN_ST = 0,   /* Listen - waiting for OBX/RFC connection */
  OPP_SRVR_CONN_ST,         /* Connected - OPP Session is active */
  OPP_SRVR_CLOSING_ST       /* Closing is in progress */
};
typedef UINT8 tOPP_SRVR_STATE;

/* data type for OPP_SRVR_API_ENABLE_EVT */
typedef struct
{
    BT_HDR              hdr;
    tOPP_SRVR_ENABLE    data;
} tOPP_SRVR_API_ENABLE;

/* data type for OPP_SRVR_API_SDP_EVT */
typedef struct
{
    BT_HDR  hdr;
    UINT16  name_len;
    UINT8   servicename[BT_MAX_SERVICE_NAME_LEN];
} tOPP_SRVR_API_SDP;

/* data type for OPP_SRVR_API_ACCESSRSP_EVT */
typedef struct
{
    BT_HDR      hdr;
    char        *p_name;
    tOPP_OPER   oper;
    tOPP_ACCESS flag;
} tOPP_SRVR_API_ACCESSRSP;

/* data type for all obex events
    hdr.event contains the OPP event
*/
typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVT_PARAM      param;
    BT_HDR             *p_pkt;
    tOBX_EVENT          obx_event;
    UINT8               rsp_code;
} tOPP_SRVR_OBX_EVENT;

/* union of all event data types */
typedef union
{
    BT_HDR                  hdr;
    tOPP_SRVR_API_ENABLE    api_enable;
    tOPP_SRVR_API_SDP       api_sdp;
    tOPP_SRVR_API_ACCESSRSP api_access;
    tOPP_SRVR_OBX_EVENT     obx_evt;
    tGOEP_OPEN_RSP          open_evt;
    tGOEP_READ_RSP          read_evt;
    tGOEP_WRITE_RSP         write_evt;
} tOPP_SRVR_DATA;

/* OBX Response Packet Structure - Holds current response packet info */
typedef struct
{
    BT_HDR      *p_pkt;         /* (Pull/Push) Holds the current OBX hdr for Push or Pull */
    UINT8       *p_start;       /* (Pull/Push) Start of the Body of the packet */
    UINT16       offset;        /* (Pull/Push) Contains the current offset into the Body (p_start) */
    UINT16       bytes_left;    /* (Pull/Push) Holds bytes available left in Obx packet */
    BOOLEAN      final_pkt;     /* (Push)      Holds the final bit of the Push packet */
} tOPP_SRVR_OBX_PKT;

/* Server Control block for each client instance */
typedef struct
{
    char                *p_name;        /* Holds name of current operation */
    char                *p_path;        /* Holds path of current operation */
    tOPP_SRVR_OBX_PKT   obx;            /* Holds the current OBX packet information */
    UINT32              file_length;    /* length of file being Push/Pull */
    int                 fd;             /* File Descriptor of opened file */
    UINT16              peer_mtu;
    BD_ADDR             bd_addr;        /* Device currently connected to */
    tOBX_HANDLE         obx_handle;
    tOPP_SRVR_HANDLE    handle;
    tOPP_SRVR_STATE     state;          /* state machine state */
    tOPP_FMT            obj_fmt;        /* file format of received object */
    UINT8               obx_oper;       /* current active OBX operation PUSH OBJ, or PULL OBJ */
    tOPP_OPER           acc_active;     /* op code when waiting for an access rsp (API) (0 not active) */
    UINT8               cout_active;    /* Number of instances waiting for a call-in function */
    BOOLEAN             aborting;       /* TRUE when waiting for a call-in function */
    BOOLEAN             in_use;         /* TRUE when control block is in use */
} tOPP_SESS_CB;


/* OPP Server control block */
typedef struct
{
    tOPP_SRVR_CBACK     *p_cback;       /* pointer to application callback function */
    tOPP_SESS_CB        sess[OPP_MAX_SRVR_SESS]; /* client sessions */
    UINT32              sdp_handle;     /* SDP record handle */
    UINT8               scn;            /* SCN of the OPP server */
    tOPP_FMT_MASK       formats;        /* supported object formats */
    UINT8               app_id;
    UINT8               max_sessions;   /* Maximum number of active clients */
    BOOLEAN             enabled;        /* TRUE when OPP is enabled */
    BOOLEAN             disabling;      /* TRUE when OPP is being disabled */
} tOPP_SRVR_CB;

/*****************************************************************************
**  Global data
*****************************************************************************/

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

extern void opp_srvr_hdl_event(BT_HDR *p_msg);
extern void opp_srvr_sm_execute(tOPP_SESS_CB *p_cb, UINT16 event, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_cback (tOBX_HANDLE handle, tOBX_EVENT event,
                                tOBX_EVT_PARAM param, BT_HDR *p_pkt);

/* action functions */
extern void opp_srvr_api_disable(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_api_accessrsp(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_api_close(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_ci_write(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_ci_read(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_ci_open(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_connect(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_disc(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_close(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_abort(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_put(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_get(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_obx_tout(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_close_complete(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_cont_disable(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);

/* object store */
extern void opp_srvr_init_get_obj(tOPP_SESS_CB *p_cb, tOPP_SRVR_DATA *p_data);
extern void opp_srvr_proc_get_obj(tOPP_SESS_CB *p_cb);
extern void opp_srvr_proc_put_obj(tOPP_SESS_CB *p_cb, BT_HDR *p_pkt);

/* miscellaneous functions */
extern void opp_srvr_enable(tOPP_SRVR_CB *p_cb, tOPP_SRVR_ENABLE *p_data);
extern void opp_srvr_api_sdp(tOPP_SRVR_CB *p_cb, tOPP_SRVR_API_SDP *p_data);
extern void opp_srvr_get_obj_rsp(tOPP_SESS_CB *p_cb, UINT8 rsp_code, UINT16 num_read);
extern void opp_srvr_put_obj_rsp(tOPP_SESS_CB *p_cb, UINT8 rsp_code);
extern void opp_srvr_clean_getput(tOPP_SESS_CB *p_cb, BOOLEAN is_aborted);
extern void opp_srvr_req_app_access (tOPP_OPER oper, tOPP_SESS_CB *p_cb, UINT8 *p_typehdr, UINT16 typelen);
extern tOPP_FMT opp_srvr_fmt_supported(char *p, tOPP_FMT_MASK fmt_mask);
extern void opp_srvr_send_event(tOPP_SRVR_HANDLE hdl, BT_HDR *p_msg);
extern tOPP_SESS_CB *opp_srvr_find_sess(tOBX_HANDLE obx_handle);
extern BOOLEAN opp_srvr_are_couts_active(void);

#endif /* OPP_SRVR_INT_H */
