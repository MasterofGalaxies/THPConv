/*****************************************************************************
**
**  Name:           opp_clnt_int.h
**
**  Description:    This is the private header file for the Object Push
**                  Client (OPP).
**
**  Copyright (c) 2003-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef OPP_CLNT_INT_H
#define OPP_CLNT_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/opp_api.h>
#include <private/bte/stack/goep_fs.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/
#define OPP_CLNT_MAX_TYPE_HDR   48

#define OPP_CLNT_DEF_NAME       "default.vcf"

/* Constants used for "to_do" list */
#define OPP_CLNT_PUSH_MASK      0x01
#define OPP_CLNT_PULL_MASK      0x02

/* state machine events */
enum
{
    /* these events are handled by the state machine */
    OPP_CLNT_API_SEARCH_EVT = BT_EVT_TO_OPP_CLNT_CMDS, /* Searches for OPP service on a peer device */
    OPP_CLNT_API_ABORT_EVT,          /* Abort Push API event */
    OPP_CLNT_API_PUSH_EVT,           /* Push Object request */
    OPP_CLNT_API_PULL_EVT,           /* Pull Object request */
    OPP_CLNT_API_EXCH_EVT,           /* Exchange business Cards */
    OPP_CLNT_SDP_OK_EVT,             /* Service search was successful */
    OPP_CLNT_SDP_FAIL_EVT,           /* Service search failed */
    OPP_CLNT_SDP_CMPL_EVT,           /* Service search-only finished */
    OPP_CLNT_CI_WRITE_EVT,           /* Call-in response to Write request */
    OPP_CLNT_CI_READ_EVT,            /* Call-in response to Read request */
    OPP_CLNT_CI_OPEN_EVT,            /* Call-in response to File Open request */
    OPP_CLNT_OBX_CONN_RSP_EVT,       /* OBX Channel Connect Request */
    OPP_CLNT_OBX_ABORT_RSP_EVT,      /* OBX_operation aborted */
    OPP_CLNT_OBX_TOUT_EVT,           /* OBX Operation Timeout */
    OPP_CLNT_OBX_PASSWORD_EVT,       /* OBX password requested */
    OPP_CLNT_OBX_CLOSE_EVT,          /* OBX Channel Disconnected (Link Lost) */
    OPP_CLNT_OBX_PUT_RSP_EVT,        /* Write file data or delete */
    OPP_CLNT_OBX_GET_RSP_EVT,        /* Read file data or folder listing */
    OPP_CLNT_OBX_CMPL_EVT,           /* operation has completed */
    OPP_CLNT_CLOSE_CMPL_EVT          /* Finish the closing of the channel */
};

typedef UINT16 tOPP_CLNT_INT_EVT;

typedef UINT8 tOPP_CLNT_STATE;

/* data type for OPP_CLNT_API_SEARCH_EVT */
typedef struct
{
    BT_HDR          hdr;
    BD_ADDR         bd_addr;
    tOPP_CLNT_CBACK *p_cback;
} tOPP_CLNT_API_SEARCH;

/* data type for OPP_CLNT_API_PUSH_EVT */
typedef struct
{
    BT_HDR          hdr;
    tOPP_CLNT_PUSH  data;
    char            typehdr[OPP_CLNT_MAX_TYPE_HDR];
    char            name[GOEP_MAX_PATH_SIZE + 1];
} tOPP_CLNT_API_PUSH;

/* data type for OPP_CLNT_API_PULL_EVT */
typedef struct
{
    BT_HDR          hdr;
    tOPP_CLNT_PULL  data;
} tOPP_CLNT_API_PULL;

/* data type for OPP_CLNT_API_EXCH_EVT */
typedef struct
{
    BT_HDR          hdr;
    tOPP_CLNT_EXCH  data;
} tOPP_CLNT_API_EXCH;

/* data type for OPP_CLNT_SDP_OK_EVT, OPP_CLNT_SDP_FAIL_EVT, and OPP_CLNT_SDP_CMPL_EVT */
typedef struct
{
    BT_HDR          hdr;
    UINT16          status;
    BOOLEAN         found;
    UINT8           scn;
    tOPP_FMT_MASK   formats;
    UINT8           name[BT_MAX_SERVICE_NAME_LEN+1]; /* Name of the service (NULL if not in service record) */
    UINT16          name_len;  /* Length in bytes of name */
    UINT16          lang_code; /* Language encoding: ISO 639:1988 (E/F) */
    UINT16          char_code; /* Character encoding: MIBEnum value */
    UINT16          base_id;   /* Base attribute ID */
    UINT16          version;   /* Profile Version (0 if not returned) */
} tOPP_CLNT_SDP_COMPLETE;

/* data type for all obex events
    hdr.event contains the OPP Client event
*/
typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVT_PARAM      param;
    BT_HDR             *p_pkt;
    tOBX_EVENT          obx_event;
    UINT8               rsp_code;
} tOPP_CLNT_OBX_EVT;

/* union of all event data types */
typedef union
{
    BT_HDR                  hdr;
    tOPP_CLNT_API_SEARCH    api_search;
    tOPP_CLNT_API_PUSH      api_push;
    tOPP_CLNT_API_PULL      api_pull;
    tOPP_CLNT_API_EXCH      api_exch;
    tOPP_CLNT_SDP_COMPLETE  sdp;
    tOPP_CLNT_OBX_EVT       obx_evt;
    tGOEP_OPEN_RSP          open_evt;
    tGOEP_READ_RSP          read_evt;
    tGOEP_WRITE_RSP         write_evt;
} tOPP_CLNT_DATA;


/* OBX Response Packet Structure - Holds current command/response packet info */
typedef struct
{
    BT_HDR  *p_pkt;             /* (Get/Put) Holds the current OBX header for Put or Get */
    UINT8   *p_start;           /* (Get/Put) Start of the Body of the packet */
    UINT16   offset;            /* (Get/Put) Contains the current offset into the Body (p_start) */
    UINT16   bytes_left;        /* (Get/Put) Holds bytes available leop in Obx packet */
    BOOLEAN  final_pkt;         /* (Get)     Holds the final bit of the Put packet */
    UINT8    rsp_code;
} tOPP_CLNT_OBX_PKT;

/* Service Discovery Control Block */
typedef struct
{
    tSDP_DISCOVERY_DB *p_db;          /* pointer to discovery database */
    tOPP_CLNT_CBACK   *p_cback;       /* pointer to application callback function */
    BOOLEAN            sdp_only;      /* TRUE if only doing search (not part of connection) */
} tOPP_CLNT_SDP;

/* OPP Client control block */
typedef struct
{
    tOPP_CLNT_CBACK     *p_cback;       /* pointer to application callback function */
    char                *p_name;        /* Holds the local path and file name of pushed item */
    char                *p_type_hdr;    /* type header of a push operation, or NULL if not used */
    char                *p_rcv_path;    /* Holds the local path and file name of received item (card exch only) */
    tOPP_CLNT_OBX_PKT   obx;            /* Holds the current OBX packet information */
    int                 fd;             /* File Descriptor of opened file */
    UINT32              obj_size;       /* (Push/Pull) file length */
    tOBX_HANDLE         obx_handle;
    UINT16              peer_mtu;
    BD_ADDR             bd_addr;
    UINT8               sec_mask;
    tOPP_CLNT_STATE     state;          /* state machine state */
    tOPP_FMT            format;
    UINT8               obx_oper;       /* current active OBX operation PUT FILE or GET FILE */
    UINT8               to_do;          /* actions to be done (push,pull) */
    UINT8               app_id;
    tOPP_STATUS         final_status;
    tOPP_STATUS         exch_status;
    BOOLEAN             first_get_pkt;  /* TRUE if retrieving the first packet of GET object */
    BOOLEAN             cout_active;    /* TRUE if call-out is currently active */
    BOOLEAN             req_pending;    /* TRUE if an obx request to peer is in progress */
    BOOLEAN             aborting;       /* TRUE if the application is aborting the operation */
} tOPP_CLNT_CB;

/*****************************************************************************
**  Global data
*****************************************************************************/

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

extern BOOLEAN  opp_clnt_hdl_event(BT_HDR *p_msg);
extern void     opp_clnt_sm_execute(tOPP_CLNT_CB *p_cb, UINT16 event,
                                   tOPP_CLNT_DATA *p_data);
extern void     opp_clnt_obx_cback (tOBX_HANDLE handle, tOBX_EVENT event,
                                   UINT8 rsp_code, tOBX_EVT_PARAM param,
                                   BT_HDR *p_pkt);

/* action functions */
extern void opp_clnt_init_close(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_init_push(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_init_pull(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_init_exch(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_send_authrsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_ci_write(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_ci_read(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_ci_open(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_obx_conn_rsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_obx_abort_rsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_obx_timeout(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_obx_put_rsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_obx_get_rsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_trans_cmpl(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_stop_client(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_start_client(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_free_db(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_ignore_obx(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_close(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_close_complete(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_start_sdp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_sdp_cmpl(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void opp_clnt_abort(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);

/* miscellaneous functions */
extern UINT8    opp_clnt_send_get_req(tOPP_CLNT_CB *p_cb);
extern BOOLEAN  opp_clnt_proc_get_rsp(tOPP_CLNT_CB *p_cb, tOPP_CLNT_DATA *p_data);
extern void     opp_clnt_cont_get_rsp(tOPP_CLNT_CB *p_cb);
extern UINT8    opp_clnt_send_put_req(tOPP_CLNT_CB *p_cb, BOOLEAN first_pkt);
extern void     opp_clnt_start_push(tOPP_CLNT_CB *p_cb);
extern void     opp_clnt_listing_err(BT_HDR **p_pkt, tOPP_STATUS status);

#endif /* OPP_CLNT_INT_H */
