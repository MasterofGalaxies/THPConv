/*****************************************************************************
**
**  Name:           ftp_clnt_int.h
**
**  Description:    This is the private file for the file transfer
**                  client (FTC).
**
**  Copyright (c) 2003-2005, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef FTP_CLNT_INT_H
#define FTP_CLNT_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/goep_fs.h>
#include <private/bte/stack/ftp_api.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/
/* Stopping action */
#define FTP_CLNT_ACTION_NORMAL  0
#define FTP_CLNT_ACTION_ABORT   1

/* state machine events */
enum
{
    /* these events are handled by the state machine */
    FTP_CLNT_API_SEARCH_EVT = BT_EVT_TO_FTP_CLNT_CMDS, /* Searches for FTP service on a peer device */

    FTP_CLNT_API_OPEN_EVT,           /* Open a connection request */
    FTP_CLNT_API_CLOSE_EVT,          /* Close an open connection request */
    FTP_CLNT_API_PUTFILE_EVT,        /* Put File request */
    FTP_CLNT_API_GETFILE_EVT,        /* Get File request */
    FTP_CLNT_API_LIST_EVT,           /* Get a directory listing */
    FTP_CLNT_API_CHDIR_EVT,          /* Change Directory request */
    FTP_CLNT_API_MKDIR_EVT,          /* Create a Directory request */
    FTP_CLNT_API_REMOVE_EVT,         /* Remove a file/directory request */
    FTP_CLNT_API_AUTHRSP_EVT,        /* Response to password request */
    FTP_CLNT_API_ABORT_EVT,          /* Response to an abort request */
    FTP_CLNT_SDP_OK_EVT,             /* Service search was successful */
    FTP_CLNT_SDP_FAIL_EVT,           /* Service search failed */
    FTP_CLNT_SDP_CMPL_EVT,           /* Service search-only finished */
    FTP_CLNT_CI_WRITE_EVT,           /* Call-in response to Write request */
    FTP_CLNT_CI_READ_EVT,            /* Call-in response to Read request */
    FTP_CLNT_CI_OPEN_EVT,            /* Call-in response to File Open request */
    FTP_CLNT_OBX_CONN_RSP_EVT,       /* OBX Channel Connect Request */
    FTP_CLNT_OBX_ABORT_RSP_EVT,      /* OBX_operation aborted */
    FTP_CLNT_OBX_TOUT_EVT,           /* OBX Operation Timeout */
    FTP_CLNT_OBX_PASSWORD_EVT,       /* OBX password requested */
    FTP_CLNT_OBX_CLOSE_EVT,          /* OBX Channel Disconnected (Link Lost) */
    FTP_CLNT_OBX_PUT_RSP_EVT,        /* Write file data or delete */
    FTP_CLNT_OBX_GET_RSP_EVT,        /* Read file data or folder listing */
    FTP_CLNT_OBX_SETPATH_RSP_EVT,    /* Make or Change Directory */
    FTP_CLNT_OBX_CMPL_EVT,           /* operation has completed */
    FTP_CLNT_CLOSE_CMPL_EVT          /* Finish the closing of the channel */
};

typedef UINT16 tFTP_CLNT_INT_EVT;

typedef UINT8 tFTP_CLNT_STATE;

/* data type for FTP_CLNT_API_SEARCH_EVT */
typedef struct
{
    BT_HDR              hdr;
    BD_ADDR             bd_addr;
    tFTP_CLNT_CBACK    *p_cback;
} tFTP_CLNT_API_SEARCH;

/* data type for FTP_CLNT_API_OPEN_EVT */
typedef struct
{
    BT_HDR              hdr;
    tFTP_CLNT_CBACK    *p_cback;
    BD_ADDR             bd_addr;
    UINT8               sec_mask;
    UINT8               app_id;
} tFTP_CLNT_API_OPEN;

/* data type for FTP_CLNT_API_PUTFILE_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_name;
} tFTP_CLNT_API_PUT;

/* data type for FTP_CLNT_API_GETFILE_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_rem_name; /* UTF-8 name from listing */
    char               *p_name;
} tFTP_CLNT_API_GET;

/* data type for FTP_CLNT_API_LIST_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_dir;      /* UTF-8 name from listing */
} tFTP_CLNT_API_LIST;

/* data type for FTP_CLNT_API_CHDIR_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_dir;      /* UTF-8 name of directory */
    BOOLEAN             backup_flag;
} tFTP_CLNT_API_CHDIR;

/* data type for FTP_CLNT_API_MKDIR_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_dir;      /* UTF-8 name directory */
} tFTP_CLNT_API_MKDIR;

/* data type for FTP_CLNT_API_REMOVE_EVT */
typedef struct
{
    BT_HDR              hdr;
    char               *p_name;     /* UTF-8 name of file or directory */
} tFTP_CLNT_API_REMOVE;

/* data type for FTP_CLNT_API_AUTHRSP_EVT */
typedef struct
{
    BT_HDR  hdr;
    UINT8   key [GOEP_MAX_AUTH_KEY_SIZE];      /* The authentication key.*/
    UINT8   key_len;
    UINT8   userid [OBX_MAX_REALM_LEN];      /* The authentication user id.*/
    UINT8   userid_len;
} tFTP_CLNT_API_AUTHRSP;

/* data type for FTP_CLNT_SDP_OK_EVT, FTP_CLNT_SDP_FAIL_EVT, and FTP_CLNT_SDP_CMPL_EVT */
typedef struct
{
    BT_HDR  hdr;
    UINT16  status;
    BOOLEAN found;
    UINT8   scn;
    UINT8   name[BT_MAX_SERVICE_NAME_LEN+1]; /* Name of the service (NULL if not in service record) */
    UINT16  name_len;  /* Length in bytes of name */
    UINT16  lang_code; /* Language encoding: ISO 639:1988 (E/F) */
    UINT16  char_code; /* Character encoding: MIBEnum value */
    UINT16  base_id;   /* Base attribute ID */
    UINT16  version;   /* Profile Version (0 if not returned) */
} tFTP_CLNT_SDP_COMPLETE;

/* data type for all obex events
    hdr.event contains the FTC event
*/
typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVT_PARAM      param;
    BT_HDR             *p_pkt;
    tOBX_EVENT          obx_event;
    UINT8               rsp_code;
} tFTP_CLNT_OBX_EVT;

/* union of all event data types */
typedef union
{
    BT_HDR                  hdr;
    tFTP_CLNT_API_SEARCH    api_search;
    tFTP_CLNT_API_OPEN      api_open;
    tFTP_CLNT_API_PUT       api_put;
    tFTP_CLNT_API_GET       api_get;
    tFTP_CLNT_API_LIST      api_list;
    tFTP_CLNT_API_CHDIR     api_chdir;
    tFTP_CLNT_API_MKDIR     api_mkdir;
    tFTP_CLNT_API_REMOVE    api_remove;
    tFTP_CLNT_API_AUTHRSP   auth_rsp;
    tFTP_CLNT_SDP_COMPLETE  sdp;
    tFTP_CLNT_OBX_EVT       obx_evt;
    tGOEP_OPEN_RSP          open_evt;
    tGOEP_READ_RSP          read_evt;
    tGOEP_WRITE_RSP         write_evt;
} tFTP_CLNT_DATA;


/* OBX Response Packet Structure - Holds current command/response packet info */
typedef struct
{
    BT_HDR  *p_pkt;             /* (Get/Put) Holds the current OBX header for Put or Get */
    UINT8   *p_start;           /* (Get/Put) Start of the Body of the packet */
    UINT16   offset;            /* (Get/Put) Contains the current offset into the Body (p_start) */
    UINT16   bytes_left;        /* (Get/Put) Holds bytes available left in Obx packet */
    BOOLEAN  final_pkt;         /* (Get)     Holds the final bit of the Put packet */
} tFTP_CLNT_OBX_PKT;

/* Service Discovery Control Block */
typedef struct
{
    tSDP_DISCOVERY_DB *p_db;          /* pointer to discovery database */
    tFTP_CLNT_CBACK   *p_cback;       /* pointer to application callback function */
    BOOLEAN            sdp_only;      /* TRUE if only doing search (not part of connection) */
} tFTP_CLNT_SDP;

/* FTC control block */
typedef struct
{
    tFTP_CLNT_CBACK   *p_cback;       /* pointer to application callback function */
    char              *p_remote_name; /* Holds Get file name */
    char              *p_name;        /* Holds the local file name */
    tFTP_CLNT_OBX_PKT  obx;           /* Holds the current OBX packet information */
    tGOEP_FD           fd;            /* File Descriptor of opened file */
    UINT32             file_size;     /* (Put/Get) length of file */
    tOBX_HANDLE        obx_handle;
    UINT16             peer_mtu;
    BD_ADDR            bd_addr;       /* device addr used for FTP connection */
    UINT8              sec_mask;
    tFTP_CLNT_STATE    state;         /* state machine state */
    UINT8              obx_oper;      /* current active OBX operation PUT FILE or GET FILE, etc. */
    tFTP_CLNT_STATUS   status;
    BOOLEAN            first_get_pkt; /* TRUE if retrieving the first packet of GET file */
    BOOLEAN            cout_active;   /* TRUE if call-out is currently active */
    UINT8              close_action;  /* Action client is taking (abort, normal */
    UINT8              app_id;
} tFTP_CLNT_CB;

/*****************************************************************************
**  Global data
*****************************************************************************/

/*****************************************************************************
**  Function prototypes
*****************************************************************************/
extern void     ftp_clnt_hdl_event(BT_HDR *p_msg);
extern void     ftp_clnt_sm_execute(tFTP_CLNT_CB *p_cb, UINT16 event,
                                   tFTP_CLNT_DATA *p_data);
extern void     ftp_clnt_obx_cback (tOBX_HANDLE handle, tOBX_EVENT event,
                                   UINT8 rsp_code, tOBX_EVT_PARAM param,
                                   BT_HDR *p_pkt);

/* action functions */
extern void ftp_clnt_init_open(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_init_close(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_init_putfile(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_init_getfile(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_send_authrsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_ci_write(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_ci_read(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_ci_open(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_conn_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_abort_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_password(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_timeout(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_put_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_get_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_obx_setpath_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_initialize(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_trans_cmpl(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_stop_client(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_start_client(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_free_db(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_ignore_obx(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_close(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_close_complete(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_start_sdp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_sdp_cmpl(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_abort(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_listdir(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_remove(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_mkdir(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern void ftp_clnt_chdir(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);

/* miscellaneous functions */
extern UINT8 ftp_clnt_send_get_req(tFTP_CLNT_CB *p_cb);
extern void  ftp_clnt_proc_get_rsp(tFTP_CLNT_CB *p_cb, tFTP_CLNT_DATA *p_data);
extern UINT8 ftp_clnt_cont_put_file(tFTP_CLNT_CB *p_cb, BOOLEAN first_pkt);
extern void  ftp_clnt_proc_list_data(tFTP_CLNT_CB *p_cb, tFTP_CLNT_OBX_EVT *p_evt);
extern void  ftp_clnt_get_listing(tFTP_CLNT_CB *p_cb, char *p_dir, BOOLEAN first_pkt);
extern void  ftp_clnt_listing_err(BT_HDR **p_pkt, tFTP_CLNT_STATUS status);
extern void  ftp_clnt_init(tFTP_CLNT_CB *cb);

extern tFTP_CLNT_STATUS ftp_clnt_convert_obx_to_ftc_status(tOBX_STATUS obx_status);

#endif /* FTP_CLNT_INT_H */
