/*****************************************************************************
**
**  Name:           ftp_srvr_int.h
**
**  Description:    This is the private file for the file transfer
**                  server (FTS).
**
**  Copyright (c) 2003-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef FTP_SRVR_INT_H
#define FTP_SRVR_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/ftp_api.h>
#include <private/bte/stack/goep_fs.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/


/* state machine events */
enum
{
    /* these events are handled by the state machine */
    FTP_SRVR_API_DISABLE_EVT = BT_EVT_TO_FTP_SRVR_CMDS,

    FTP_SRVR_API_AUTHRSP_EVT,        /* Response to password request */
    FTP_SRVR_API_ACCESSRSP_EVT,      /* Response to an access request */
    FTP_SRVR_API_CLOSE_EVT,          /* Close an open connection */
    FTP_SRVR_CI_WRITE_EVT,           /* Response to Write request */
    FTP_SRVR_CI_READ_EVT,            /* Response to Read request */
    FTP_SRVR_CI_OPEN_EVT,            /* Response to File Open request */
    FTP_SRVR_CI_DIRENTRY_EVT,        /* Response to a directory entry request */
    FTP_SRVR_OBX_CONN_EVT,           /* OBX Channel Connect Request */
    FTP_SRVR_OBX_DISC_EVT,           /* OBX Channel Disconnect */
    FTP_SRVR_OBX_ABORT_EVT,          /* OBX_operation aborted */
    FTP_SRVR_OBX_PASSWORD_EVT,       /* OBX password requested */
    FTP_SRVR_OBX_CLOSE_EVT,          /* OBX Channel Disconnected (Link Lost) */
    FTP_SRVR_OBX_PUT_EVT,            /* Write file data or delete */
    FTP_SRVR_OBX_GET_EVT,            /* Read file data or folder listing */
    FTP_SRVR_OBX_SETPATH_EVT,        /* Make or Change Directory */
    FTP_SRVR_CLOSE_CMPL_EVT,         /* Finished closing channel */

    /* these events are handled outside the state machine */
    FTP_SRVR_API_ENABLE_EVT
};

typedef UINT16 tFTP_SRVR_INT_EVT;

typedef UINT8 tFTP_SRVR_STATE;

/* data type for FTP_SRVR_API_ENABLE_EVT */
typedef struct
{
    BT_HDR           hdr;
    tFTP_SRVR_ENABLE info;
} tFTP_SRVR_API_ENABLE;

/* data type for FTP_SRVR_API_AUTHRSP_EVT */
typedef struct
{
    BT_HDR  hdr;
    UINT8   key [GOEP_MAX_AUTH_KEY_SIZE];      /* The authentication key.*/
    UINT8   key_len;
    UINT8   userid [OBX_MAX_REALM_LEN];      /* The authentication user id.*/
    UINT8   userid_len;
} tFTP_SRVR_API_AUTHRSP;

/* data type for FTP_SRVR_API_ACCESSRSP_EVT */
typedef struct
{
    BT_HDR          hdr;
    tFTP_OPER       oper;
    tFTP_ACCESS     flag;
} tFTP_SRVR_API_ACCESSRSP;

/* data type for all obex events
    hdr.event contains the FTS event
*/
typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVT_PARAM      param;
    BT_HDR             *p_pkt;
    tOBX_EVENT          obx_event;
    UINT8               rsp_code;
} tFTP_SRVR_OBX_EVENT;

/* union of all event data types */
typedef union
{
    BT_HDR                  hdr;
    tFTP_SRVR_API_ENABLE    api_enable;
    tFTP_SRVR_API_AUTHRSP   auth_rsp;
    tFTP_SRVR_API_ACCESSRSP access_rsp;
    tFTP_SRVR_OBX_EVENT     obx_evt;
    tGOEP_DIRENTRY_RSP      getdir_evt;
    tGOEP_OPEN_RSP          open_evt;
    tGOEP_READ_RSP          read_evt;
    tGOEP_WRITE_RSP         write_evt;
} tFTP_SRVR_DATA;


/* OBX Response Packet Structure - Holds current response packet info */
typedef struct
{
    BT_HDR  *p_pkt;             /* (Get/Put) Holds the current OBX header for Put or Get */
    UINT8   *p_start;           /* (Get/Put) Start of the Body of the packet */
    UINT16   offset;            /* (Get/Put) Contains the current offset into the Body (p_start) */
    UINT16   bytes_left;        /* (Get/Put) Holds bytes available left in Obx packet */
    BOOLEAN  final_pkt;         /* (Put)     Holds the final bit of the Put packet */
} tFTP_SRVR_OBX_PKT;

/* Directory Listing Information */
typedef struct
{
    tGOEP_DIRENTRY *p_entry;    /* Holds current directory entry */
    BOOLEAN         is_root;    /* TRUE if path is root directory */
} tFTP_SRVR_DIRLIST;

/* FTS control block */
typedef struct
{
    tFTP_SRVR_CBACK  *p_cback;       /* pointer to application callback function */
    char             *p_name;        /* Holds name of current operation */
    char             *p_path;        /* Holds path of current operation */
    char             *p_rootpath;
    char             *p_workdir;     /* Current working directory */
    tFTP_SRVR_OBX_PKT obx;           /* Holds the current OBX packet information */
    tFTP_SRVR_DIRLIST dir;           /* Holds current directory list information */
    UINT32            sdp_handle;    /* SDP record handle */
    UINT32            file_length;   /* length of file being PUT/GET */
    tGOEP_FD          fd;            /* File Descriptor of opened file */
    BD_ADDR           bd_addr;       /* Device currently connected to */
    tOBX_HANDLE       obx_handle;
    UINT16            peer_mtu;
    UINT8             scn;           /* SCN of the FTP server */
    tFTP_SRVR_STATE   state;         /* state machine state */
    UINT8             obx_oper;      /* current active OBX operation PUT FILE, GET FILE, LISTING, etc */
    BOOLEAN           auth_enabled;  /* Is OBEX authentication enabled */
    BOOLEAN           cout_active;   /* TRUE when waiting for a call-in function */
    tFTP_OPER         acc_active;    /* op code when waiting for an access rsp (API) (0 not active) */
    UINT8             app_id;
} tFTP_SRVR_CB;

/*****************************************************************************
**  Global data
*****************************************************************************/

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

extern void     ftp_srvr_hdl_event(BT_HDR *p_msg);
extern void     ftp_srvr_sm_execute(tFTP_SRVR_CB *p_cb, UINT16 event, tFTP_SRVR_DATA *p_data);
extern void     ftp_srvr_sdp_register (tFTP_SRVR_CB *p_cb, char *p_service_name);
extern void     ftp_srvr_obx_cback (tOBX_HANDLE handle, tOBX_EVENT event,
                                   tOBX_EVT_PARAM param, BT_HDR *p_pkt);

/* action functions */
extern void ftp_srvr_api_disable(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_api_close(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_api_authrsp(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_api_accessrsp(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_ci_write(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_ci_read(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_ci_open(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_ci_direntry(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_connect(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_disc(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_close(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_abort(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_password(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_put(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_get(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_obx_setpath(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_conn_err_rsp(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);
extern void ftp_srvr_close_complete(tFTP_SRVR_CB *p_cb, tFTP_SRVR_DATA *p_data);

/* object store */
extern UINT8 ftp_srvr_mkdir(BT_HDR *p_pkt, BOOLEAN backup_flag);
extern UINT8 ftp_srvr_chdir(BT_HDR *p_pkt, BOOLEAN backup_flag);
extern void  ftp_srvr_getdirlist(char *p_name);
extern void  ftp_srvr_proc_get_file(char *p_name);
extern void  ftp_srvr_proc_put_file(BT_HDR *p_pkt, char *p_name, BOOLEAN final_pkt);
extern void  ftp_srvr_delete(tFTP_SRVR_OBX_EVENT *p_evt, const char *p);

/* miscellaneous functions */
extern void    ftp_srvr_get_file_rsp(UINT8 rsp_code, UINT16 num_read);
extern void    ftp_srvr_put_file_rsp(UINT8 rsp_code);
extern void    ftp_srvr_end_of_list(UINT8 rsp_code);
extern UINT8   ftp_srvr_add_list_entry(void);
extern void    ftp_srvr_clean_list(tFTP_SRVR_CB *p_cb);
extern void    ftp_srvr_clean_getput(tFTP_SRVR_CB *p_cb, BOOLEAN is_aborted);
extern BOOLEAN ftp_srvr_read_name_hdr(BT_HDR *p_pkt, char *p_name, UINT16 max_len);
extern void    ftp_srv_init(tFTP_SRVR_CB *p_cb);

#endif /* FTP_SRVR_INT_H */
