/*****************************************************************************
**
**  Name:       bpp_int.h
**
**  File:       BPP internal common definitions
**
**  Copyright (c) 2000-2005, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BPP_INT_H
#define BPP_INT_H

#include <private/bte/common/target.h>
#include <private/bte/gki.h>
#include <private/bte/stack/bpp_api.h>
#include <private/bte/stack/xml_pars_api.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/sdp_api.h>
#include <private/bte/stack/goep_util.h>
   

/****************************************************************************
**   Constants
*****************************************************************************/
#define BPP_ENUM_MAX_BITS           4

#define BPP_SETUP_HANDLE        (BPP_PR_MAX_CON + 1)
#define BPP_INVALID_HANDLE      0
#define BPP_MAX_CHANNEL_IND     BPP_OBJECT_CHANNEL
#define BPP_INVALID_CHANNEL     0

#define BPP_PR_MAX_SDP          3   /* maximum number of SDP search allowed at a time */

#define BPP_PR_FIRST_SOAP_OP    BPP_PR_GET_PR_ATTRS_EVT
#define BPP_SND_FIRST_SOAP_OP   BPP_SND_GET_PR_ATTR_EVT

#ifndef BPP_MAX_FILE_NAME_LEN
#define BPP_MAX_FILE_NAME_LEN       200
#endif

/* #define BPP_NUM_GOEP_TARGETS           3 each group server contains 3 target UUIDs: 16-bit, 32-bit & 128-bit forms */
enum
{
    BPP_CS_NULL,
    BPP_CS_IDLE,
    BPP_CS_W4_CONN,
    BPP_CS_CONN,
    BPP_CS_CLOSING
};
/* OBEX client states */
typedef UINT8   tBPP_CL_STATE;

enum
{
    BPP_SS_NULL,
    BPP_SS_LISTEN,
    BPP_SS_W4_CONN,
    BPP_SS_CONN,
    BPP_SS_CLOSING
};
/* OBEX server states */
typedef UINT8   tBPP_SR_STATE;

#define BPP_PR_ROLE         1
#define BPP_SND_ROLE        2
typedef UINT8   tBPP_ROLE;

/* Tags for application parameter obex headers */
/* application parameter len: number of bytes + 2 (tag&len) */
#define BPP_TAG_OFFSET_ID          1    /* UINT32 */
#define BPP_TAG_COUNT_ID           2    /*  INT32 */
#define BPP_TAG_JOB_ID             3    /* UINT32 */
#define BPP_TAG_FILE_SIZE          4    /*  INT32 */
#define BPP_APP_PARAM_SIZE         4    /*  INT32 or UINT32 */

/* OBEX type header for get ref obj operation */
#define BPP_PR_REF_OBJ_TYPE_HDR "x-obex/referencedobject"

/* Printer SOAP Parser Constants */
#define BPP_PSP_MAX_TID   0x1A
#define BPP_PSP_TTBL_SIZE (BPP_PSP_MAX_TID + 1)


/* Sender SOAP Parser Constants */
#define BPP_SSP_MAX_TID   0x2F
#define BPP_SSP_TTBL_SIZE (BPP_SSP_MAX_TID + 1)

/* OBEX type header for SOAP operations */
#define BPP_SOAP_TYPE_HEADER            "x-obex/bt-SOAP"
#define BPP_SOAP_REF_OBJ_TYPE_HEADER    "x-obex/referencedobject"

/* the estimated SOAP element length (30 is the longest tag, 7 is (<\>LF) */
#define BPP_SOAP_ELM_LEN            70      /* 30*2 + 7 */


/* SOAP builder used */
#define BPP_SB_ATTR_DONE           0xFF

#define BPP_PSB_INVALID_OP_STAT     0xFFFF

/*
** BPP SOAP General Names
*/
extern const char bpp_int_xmlns[];     /* "xmlns" */
extern const char bpp_int_enc_style[]; /* "encodingStyle" */
extern const char bpp_int_soap_ns[];   /* name space for soap envelope */
extern const char bpp_int_bpp_ns[];    /* name space for bpp profile */
extern const char bpp_int_enc_ns[];    /* name schema for soap encoding" */
extern const char bpp_int_true[];      /* "true" */
extern const char bpp_int_false[];     /* "false" */
extern const char bpp_int_envelope[];  /* "Envelope" */
extern const char bpp_int_body[];      /* "Body" */

/*
** BPP SOAP Tag Names
*/

/* Printer Message names */
extern const char bpp_int_gpar[]; /* "GetPrinterAttributesResponse" */
extern const char bpp_int_crjr[]; /* "CreateJobResponse" */
extern const char bpp_int_cpjr[]; /* "CreatePreciseJobResponse" */
extern const char bpp_int_gjar[]; /* "GetJobAttributesResponse" */
extern const char bpp_int_cljr[]; /* "CancelJobResponse" */
extern const char bpp_int_ger[];  /* "GetEventResponse" */
extern const char bpp_int_gmr[];  /* "GetMarginsResponse" */

/* Sender Message names */
extern const char bpp_int_gpa[];  /* "GetPrinterAttributes" */
extern const char bpp_int_crj[];  /* "CreateJob" */
extern const char bpp_int_gja[];  /* "GetJobAttributes" */
extern const char bpp_int_clj[];  /* "CancelJob" */
extern const char bpp_int_ge[];   /* "GetEvent" */
extern const char bpp_int_cpj[];  /* "CreatePreciseJob" */
extern const char bpp_int_gm[];   /* "GetMargins" */

/* Generic Element names */
extern const char bpp_int_m[];    /* "Margins" */
extern const char bpp_int_rpa[];  /* "RequestedPrinterAttributes" */
extern const char bpp_int_pa[];   /* "PrinterAttribute" */
extern const char bpp_int_rja[];  /* "RequestedJobAttributes" */
extern const char bpp_int_ja[];   /* "JobAttribute" */
extern const char bpp_int_ms[];   /* "MediaSize" */
extern const char bpp_int_mt[];   /* "MediaType" */
extern const char bpp_int_lmd[];  /* "LoadedMediumDetails" */
extern const char bpp_int_lms[];  /* "LoadedMediumSize" */
extern const char bpp_int_lmt[];  /* "LoadedMediumType" */
extern const char bpp_int_df[];   /* "DocumentFormat" */
extern const char bpp_int_cp[];   /* "Copies" */
extern const char bpp_int_sd[];   /* "Sides" */
extern const char bpp_int_nu[];   /* "NumberUp" */
extern const char bpp_int_or[];   /* "OrientationRequested" */
extern const char bpp_int_o[];    /* "Orientation" */ 
extern const char bpp_int_pq[];   /* "PrintQuality" */
extern const char bpp_int_if[];   /* "ImageFormat" */
extern const char bpp_int_cll[];  /* "CancelOnLostLink" */
extern const char bpp_int_ops[];  /* "OperationStatus" */

/* Printer attributes */
extern const char bpp_int_un[];   /* "undefined" */
extern const char bpp_int_pn[];   /* "PrinterName" */
extern const char bpp_int_pl[];   /* "PrinterLocation" */
extern const char bpp_int_ps[];   /* "PrinterState" */
extern const char bpp_int_psr[];  /* "PrinterStateReasons" */
extern const char bpp_int_dfs[];  /* "DocumentFormatsSupported" */
extern const char bpp_int_cs[];   /* "ColorSupported" */
extern const char bpp_int_mcs[];  /* "MaxCopiesSupported" */
extern const char bpp_int_ss[];   /* "SidesSupported" */
extern const char bpp_int_nus[];  /* "NumberUpSupported" */
extern const char bpp_int_ors[];  /* "OrientationsSupported" */
extern const char bpp_int_mss[];  /* "MediaSizesSupported" */
extern const char bpp_int_mts[];  /* "MediaTypesSupported" */
extern const char bpp_int_ml[];   /* "MediaLoaded" */
extern const char bpp_int_pqs[];  /* "PrintQualitySupported" */
extern const char bpp_int_qjc[];  /* "QueuedJobCount" */
extern const char bpp_int_ifs[];  /* "ImageFormatsSupported" */
extern const char bpp_int_btpw[]; /* "BasicTextPageWidth" */
extern const char bpp_int_btph[]; /* "BasicTextPageHeight" */
extern const char bpp_int_ggco[]; /* "PrinterGeneralCurrentOperator" */

/* Job Attributes */
extern const char bpp_int_jid[];  /* "JobId" */
extern const char bpp_int_js[];   /* "JobState" */
extern const char bpp_int_jn[];   /* "JobName" */
extern const char bpp_int_joun[]; /* "JobOriginatingUserName" */
extern const char bpp_int_jmsc[]; /* "JobMediaSheetsCompleted" */
extern const char bpp_int_nij[];  /* "NumberOfInterveningJobs" */

/* Arrays of strings used in SOAP message responses */
extern const char * const bpp_attr_req_tag[];
extern const char * const bpp_int_pr_attr[];
extern const char * const bpp_int_job_attr[];
extern const char * const bpp_int_pr_st[]; 
extern const char * const bpp_int_sides[]; 
extern const char * const bpp_int_orien[]; 
extern const char * const bpp_int_quality[]; 
extern const char * const bpp_int_md_type[]; 
extern const char * const bpp_int_job_st[]; 
extern const char * const bpp_int_pr_st_rsn[]; 


/****************************************************************************
**   Type Definitions
*****************************************************************************/



/****************************************************************************
**   Type Definitions for internal soap parser, bpp_isp
*****************************************************************************/

/* tBPP_ISP_HNDL represents a parsing (transparent) "handle". It can be  
** used in BPP_ISP_TAG_ACTION implementations when issuing bpp calls.
*/
struct t_bpp_isp_state;
typedef struct t_bpp_isp_state *tBPP_ISP_HNDL;

/* Action function which is called by the general SOAP parser
** for XML_TAG, XML_ATTRIBUTE and XML_CHARDATA events only.
*/
typedef void (*BPP_ISP_TAG_ACTION)(tBPP_ISP_HNDL hndl, tXML_EVENT event,
                                   tXML_MEVT_DATA *p_event_data);


/* Definition of the tBPP_ISP_TTBL tag table.
** It should be initialised using an initializer ({}).
** Each element holds a tag name and a tag action (function ptr).
** The table index, identifies a tag and serves as an tag id.
** Index 0 is special - e.g. used for the start state - 
** and therefore the first element must have an empty name
** and null values.  All tags that can have child tags must preceede
** tags without child tags in the tag table.
*/
typedef struct
{
    const char        *p_tname;
    BPP_ISP_TAG_ACTION t_act;
} tBPP_ISP_TTBL_ELEM;


/* The tBPP_ISP_PTBL parsing table holds allowed sequences of sub-tags
** (child tags). It should be initialised using an initializer ({}).
** Each sub-tag sequence is in a string literal and the tBPP_ISP_PTBL is
** an array of pointers to these string literals. Literals 
** must be whithin "" but inside, each character (one byte integer)
** represents the id of an allowed sub-tag. Use \x<hex digits> when
** setting a sub-tag id inside a literal. The literal behind index n 
** in tBPP_ISP_TTBL shall hold the allowed sub-tags of tag n. Only
** tags which can have sub-tags are in the tBPP_ISP_PTBL.
*/
typedef UINT8 *tBPP_ISP_PTBL_ELEM;


/* The tBPP_ISP_NSTBL is a map table between tags that are allowed to
** change name space and a name space name (e.g an URL).
** A table entry may contain a Soap operation code associated with
** the tag. (All Soap operation tags must define a name space.)
** It should be initialised using an initializer ({}).
** The tBPP_ISP_NSTBL_ELEM must be initialised in increasing tag order.
*/
typedef struct
{
    UINT8       t_id;
    INT16       soap_op;    /* set -1 for no soap op */
    const char *p_ns;
} tBPP_ISP_NSTBL_ELEM;

/* The tBPP_ISP_ETBL is a map table between tags and which enum type
** the tag corresponds to in the BPP API.
** It should be initialised using an initializer ({}).
** The tBPP_ISP_ETBL_ELEM can be initialised in any order.
*/
typedef struct
{
    UINT8           t_id;
    tBPP_ATTR_TYPE  type;
    const char * const *p_str_table;
} tBPP_ISP_ETBL_ELEM;


/* A structure to keep all table data together */
/* All sizes are in nr of elements */
typedef struct
{
    const tBPP_ISP_TTBL_ELEM  *p_ttbl;  /* Tag Table */
    const tBPP_ISP_PTBL_ELEM  *p_ptbl;  /* Parsing Table */
    const tBPP_ISP_NSTBL_ELEM *p_nstbl; /* Name Space Table */
    const tBPP_ISP_ETBL_ELEM  *p_etbl;  /* Enum Table */

          UINT8               ttbl_size;
          UINT8               ptbl_size;
          UINT8               nstbl_size;
          UINT8               etbl_size;
} tBPP_ISP_TBLS;

/****************************************************************************
**   Constants
*****************************************************************************/

/* Must allocate a tag stack size that can hold the xml tag depth plus 1
** for an initial guard stack element (with tag id 0)
*/
#define BPP_ISP_STACK_SIZE     7
#define BPP_ISP_NSP_STACK_SIZE 2

#define BPP_ISP_MAND_SIZE      2

/****************************************************************************
**   Type Definitions
*****************************************************************************/
#define BPP_NS_STR_SIZE     2
typedef UINT8 tBPP_NS_STR[BPP_NS_STR_SIZE];

/* These go into the control block of the sender (bpp_snd_cb ??) */
typedef struct
{
    tBPP_ATTR_STR_LIST *p_cur_ptr;       /* location where next list item and string stored */
    BUFFER_Q            attrstr_q;       /* Queue containing extra gki buffers used (if any) */
    INT32               bytes_remaining; /* Number of free bytes left in current buffer */
} tBPP_ATTR_MEM;


/* The following struct stores state during the bpp_isp_parse call not 
** between bpp_isp_parse calls.
*/

typedef struct
{
    UINT8           curr;
    tXML_EVENT      event;
    tXML_MEVT_DATA  ed;
}tBPP_ISP_DAT;


typedef struct t_bpp_isp_state
{
    const tBPP_ISP_TBLS *p_ts;    /* ptr to table set */
    tBPP_PR       *p_evt;   /* event data/parsed result */
    tBPP_SND      *p_snd_evt; /* parsed result dta associated with sender call back event */
    BT_HDR        **p_buf;  /* address for the extra buffer for event data */
    tBPP_ATTR     mand[BPP_ISP_MAND_SIZE];

    tXML_RESULT   res;
    UINT16        op; /* only used by action functions */

    /* name space prefix (nsp) stack */
    tBPP_NS_STR   nsp_stack[BPP_ISP_NSP_STACK_SIZE];
    BOOLEAN       ns_pend;
    int           nsp_top;
    BOOLEAN       op_found;
    BOOLEAN       ended;
    BOOLEAN       obx_ended;
    BOOLEAN       fst_ln_done;
    UINT8         skip_lev;
    UINT8         last_stm_top;
    tBPP_ISP_DAT  last_dat;
} tBPP_ISP_STATE;
#define BPP_ISP_PART_FLAG   0x04

/****************************************************************************
**   BPP Internal message Structures
*****************************************************************************/
/* Printer Internal Event Definitions */
enum
{
    BPP_PR_EVT_CI_OPEN     =   (0x0001 | BT_EVT_TO_BPP_PR_CMDS), /* Open file operation is finished. */
    BPP_PR_EVT_CI_READ,
    BPP_PR_EVT_CI_WRITE,        /* write file operation is finished. */
    BPP_PR_EVT_OBX_CONN,        /* OBX connect request event */
    BPP_PR_EVT_OBX_PASSWORD,    /* OBX password event */
    BPP_PR_EVT_OBX_CLOSE,       /* OBX disconnect event */
    BPP_PR_EVT_OBX_EVT,         /* other OBX events */
    BPP_PR_EVT_CLOSE_CMPL,      /* close complete */
    BPP_PR_EVT_API_START,       /* BPP_StartPrinter() is called. */
    BPP_PR_EVT_API_STOP,        /* BPP_StopPrinter () is called */
    BPP_PR_EVT_API_PASSWORD,    /* BPP_Password() is called */
    BPP_PR_EVT_API_GET,         /* SOAP response APIs is called */
    BPP_PR_EVT_API_PUT,         /* BPP_NameRsp() is called. */
    BPP_PR_EVT_MAX
};

#define BPP_PR_EVT_MASK         0x001F

/* Object channel does not handle OBEX authentication */
#define BPP_PR_EVT_INT_SND_ABORT    BPP_PR_EVT_API_PASSWORD /* it's time to send abort */
/* Object channel does not issue PUT requests */
#define BPP_PR_EVT_SDP_RESULT       BPP_PR_EVT_API_PUT      /* report SD result */

enum
{
    BPP_PR_INT_CI_OPEN     =   0x0001, /* file is opened */
    BPP_PR_INT_CI_WRITE         /* write file is done */
};

#define BPP_PR_INVALID_EVT      0
#define BPP_PR_FIRST_SM_EVT     BPP_PR_EVT_CI_OPEN
#define BPP_PR_LAST_CSM_EVT     BPP_PR_EVT_API_ABORT
#define BPP_PR_LAST_SSM_EVT     BPP_PR_EVT_API_PUT
#define BPP_PR_FIRST_CI_EVT     BPP_PR_EVT_CI_OPEN
#define BPP_PR_LAST_CI_EVT      BPP_PR_EVT_CI_WRITE
#define BPP_FIRST_OBX_EVT    BPP_PR_EVT_OBX_CONN
#define BPP_LAST_OBX_EVT     BPP_PR_EVT_OBX_EVT

/* state machine events */
enum
{
    /* these events are handled by the state machine */
    BPP_SND_EVT_CI_OPEN = (0x0001 | BT_EVT_TO_BPP_SND_CMDS),  /* 0x01 Call-in response to File Open request */
    BPP_SND_EVT_CI_READ,                /* 0x02 Call-in response to Read request */
    BPP_SND_EVT_CI_WRITE,               /* 0x03 Call-in response to Write request */
    BPP_SND_EVT_OBX_CONN,               /* 0x04 OBX Channel Connect Request */
    BPP_SND_EVT_OBX_PASSWORD,           /* 0x05 OBX password requested */
    BPP_SND_EVT_OBX_CLOSE,              /* 0x06 OBX Channel Disconnected (Link Lost) */
    BPP_SND_EVT_OBX_EVT,                /* 0x07 other OBX events */
    BPP_SND_EVT_CLOSE_CMPL,             /* 0x08 operation has completed */
    BPP_SND_EVT_API_START,              /* 0x09 Start BPP sender, Searches for BPP service on a peer device */
    BPP_SND_EVT_API_STOP,               /* 0x0a Stop Sender API event */
    BPP_SND_EVT_API_AUTH_RSP,           /* 0x0b Authorization response */
    BPP_SND_EVT_API_PUT,                /* 0x0c Push Object request */
    BPP_SND_EVT_API_GET,                /* 0x0d Pull Object request */
    BPP_SND_EVT_API_ABORT,              /* 0x0e Abort request */
    BPP_SND_EVT_SDP_RESULT,             /* 0x0f Service search finished */
    BPP_SND_EVT_INT_SND_ABORT,          /* 0x10 time to call OBX_AbortReq() */
    BPP_SND_EVT_API_FREE_MEM,           /* 0x11 Free the buffer queue holding the unused printer attribute */     
    BPP_SND_EVT_MAX
};
typedef UINT16 BPP_SND_EVT;

#define BPP_SND_FIRST_SM_EVT      BPP_SND_EVT_CI_OPEN
#define BPP_SND_LAST_CSM_EVT      BPP_SND_EVT_API_FREE_MEM
#define BPP_SND_EVT_MASK          0x001F
#define BPP_SND_FIRST_OBX_EVT    BPP_SND_EVT_OBX_CONN
#define BPP_SND_LAST_OBX_EVT     BPP_SND_EVT_OBX_EVT


#define BPP_CHANNEL_SHIFT       6   /* to work around goep fs, bit 7,8 for channel in lower byte of event */
#define BPP_HANDLE_SHIFT        3   /* to work around goep fs, bit 4-6 for handle in lower byte of event */

#define BPP_EVT_CI_MASK      0x0007
#define BPP_EVT_CHNL_MASK    0x00C0 /* 0000 0000 1100 0000 validate 7,8 bit of lower byte of event */
#define BPP_EVT_HANDLE_MASK  0x0038 /* 0000 0000 0011 1000 validate 4,5,6 bit of lower byte of event */

/* Printer API request Definitions */
enum
{
    BPP_PR_API_START,
    BPP_PR_API_STOP,
    BPP_PR_API_CLOSE
};

enum
{
    BPP_SOAP_REQ,
    BPP_SOAP_RSP
};
typedef UINT8 tBPP_SOAP_ACTION;

/* internal data type for BPP_PR_API_PASSWORD */
typedef struct
{
    BT_HDR          hdr;
    UINT16          req;
    UINT8           key [GOEP_MAX_AUTH_KEY_SIZE];      /* The authentication key.*/
    UINT8           key_len;
    UINT8           userid [OBX_MAX_REALM_LEN];      /* The authentication user id.*/
    UINT8           userid_len;
} tBPP_API_PASSWORD;

typedef union
{
    tBPP_START_INFO     start;
    char                *p_name;
} tBPP_API_ARG;

/* internal data type for BPP_PR_API_START, BPP_PR_API_STOP,
 *      BPP_PR_API_CLOSE,   */
typedef struct
{
    BT_HDR              hdr;
    UINT16              req;
    tOBX_RSP_CODE       obx_rsp;
    tBPP_API_ARG        args;
} tBPP_API_MSG;

/* internal data type for BPP_PR_EVT_API_GET on server (job/status) channel
 * (not BPP_PR_GET_MARGINS_EVT) */
typedef struct
{
    BT_HDR              hdr;
    UINT16              req;
    tBPP_OPER_STATUS    op_stat;
    tBPP_SOAP_RSP       *p_attr;        
    tBPP_JOB_ID         job_id;
    UINT32              attr_mask;          /* GetPrAttr/GetJobAttr attr_mask; or GetMargin() mediatype */
    UINT8               *p_media_size;
} tBPP_API_SOAP;

/* internal data type for BPP_PR_EVT_API_GET on server (job/status) channel
 * when req is BPP_PR_GET_MARGINS_EVT */
typedef struct
{
    BT_HDR              hdr;
    UINT16              req;
    tBPP_OPER_STATUS    op_stat;
    char                *p_margins;
} tBPP_API_MARGINS;

/* internal data type for BPP_PR_API_GET_OBJ */
typedef struct
{
    BT_HDR              hdr;
    UINT16              req;
    char                *p_name;
    char                *p_obj_id;
    UINT32              offset;
    INT32               count;
    BOOLEAN             size;
} tBPP_API_GET_OBJ;

typedef struct
{
    BT_HDR              hdr;
    UINT16              sdp_status;
    UINT8               scn;
} tBPP_SDP_RESULT_EVT;

typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVENT          event;
    tOBX_EVT_PARAM      param;
    BT_HDR              *p_pkt;
    tOBX_RSP_CODE       rsp_code;
} tBPP_OBX_EVENT;

typedef struct
{
    BT_HDR              hdr;
    UINT32              job_id;
    BOOLEAN             req_ref_chnl;
    UINT8               *p_file_name; /* Fully qualified path containing name of object to put */
    UINT8               *p_mime_type; /* OBEX Type Header String NULL terminated */
}tBPP_API_SEND_DOC;

typedef struct
{
    BT_HDR              hdr;
    tBPP_SERVICE        service;
} tBPP_START_CLIENT;

typedef struct
{
    BT_HDR                  hdr;
    tBPP_START_REF_INFO     ref;
} tBPP_START_API_REF;

typedef struct
{
    BT_HDR              hdr;
    void                *args;
} tBPP_SND_API_MSG;

typedef union
{
    /* hdr.layer_specific   = tBPP_HANDLE */
    /* hdr.offset           = tBPP_CHANNEL */
    BT_HDR              hdr;
    tBPP_API_MSG        api;
    tBPP_API_SOAP       soap;
    tBPP_API_PASSWORD   pswd;
    tBPP_API_MARGINS    marg;
    tBPP_API_GET_OBJ    obj;
    tBPP_OBX_EVENT      obx;
    tGOEP_OPEN_RSP      open;
    tGOEP_READ_RSP      read;
    tGOEP_WRITE_RSP     write;
    tBPP_SND_API_MSG    snd_api;
 
    tBPP_START_API_REF  start_ref;
    tBPP_API_SEND_DOC   put;
    tBPP_SDP_RESULT_EVT sdp;
    tBPP_START_CLIENT   start_clnt;
} tBPP_EVT_MSG;

/****************************************************************************
**   BPP Internal Control Block Structures
*****************************************************************************/

typedef UINT8  tBPP_OP; /* tBPP_GET_OP or tBPP_PUT_OP for control block use */

#define BPP_OP_MASK         0x8F
#define BPP_OP_TYPE_MASK    0x80
#define BPP_OP_RSP_MASK     0x40  /* SET this bit if request sent and response not received yet
                                     - for client abort purposes */
#define BPP_OP_PUT          0x80
#define BPP_OP_GET          0

#define BPP_IGNORE_STATUS   0xFFFF

/* OBX Response Packet Structure - Holds current response packet info */
typedef struct
{
    BT_HDR         *p_pkt;      /* (Get/Put) Holds the current OBX header for Put or Get */
    UINT8          *p_start;    /* (Get/Put) Start of the Body of the packet */
    UINT16          offset;     /* (Get/Put) Contains the current offset into the Body (p_start) */
    UINT16          bytes_left; /* (Get/Put) Holds bytes available left in Obx packet */
    BOOLEAN         final_pkt;  /* (Put)     Holds the final bit of the Put packet */
    tOBX_RSP_CODE   rsp_code;   /* (Get)(client) */
} tBPP_OBX_PKT;


/************************************************************************************
* Internal Data Types and Constants just for reference object channel
*************************************************************************************/

/* Application Parameters Header
Tag IDs used in the Application Parameters header:
*/
                                        /*  Tag ID                 Length  Possible Values */
#define BPP_APH_PART_FILE_STOFF 0x01    /* Offset                4 bytes 0x00000000 to 0xFFFFFFFF */
#define BPP_APH_PART_FILE_LEN   0x02    /* Count                 4 bytes 0x00000000 to 0xFFFFFFFF */
#define BPP_APH_JOBID           0x03    /* JobID                 4 bytes 0x00000000 to 0xFFFFFFFF */
#define BPP_APH_TOTAL_FILE_SZ   0x04    /* FileSize              4 bytes 0x00000000 to 0xFFFFFFFF */
#define BPP_APH_MAX_TAG         0x05

/*************************************************************************
** stored state and other data for BPP Printer
** control block (cb) to store state and other data per channel
**************************************************************************/
    /* J-job, S-status, O-object channel */
#define BPP_STS_OBX_RSP          0x01  /* O   set this bit when waiting for response,
                                        *     clear this bit when response is received */
#define BPP_STS_GET_REQUEST      0x01  /* S/J set this bit if the get req was not completely received */
#define BPP_STS_START            0x02  /* O   set this bit when connected */
#define BPP_STS_GET_CONTINUE     0x02  /* S/J set this bit if the get rsp was not completely sent */
#define BPP_STS_EVT_ON           0x04  /* S   set this bit if the received put req has final set */
#define BPP_STS_JOB_DISALLOW     0x04  /* J   set this bit if the received put req has final set */
#define BPP_STS_WAIT_BODY_END    0x04  /* J/S in BPP Sender, when SOAP content is sent and waiting End of Body to be sent */
#define BPP_STS_WAIT_CLOSE       0x08  /* S/J set this bit when waiting for close event  */
#define BPP_STS_WAIT_ABORT       0x10  /* J   set this bit when abort is received, but waiting for FS to clear  */
#define BPP_STS_PUT_FINAL        0x20  /* J   printer job channel set this bit if the received put req has final set */
#define BPP_STS_WAIT_GET_REQ     0x20  /* J   sender Job channel set this bit if SOAP get request received
                                              in between a PUT transaction */
#define BPP_STS_WAIT_FS          0x40  /* O/J set this bit when waiting for GOEP_xxxRsp()  */
#define BPP_STS_WAIT_STOP        0x80  /* O/J set this bit when stop API is issued and waiting... */
#define BPP_STS_SOAP_HDR         0x80  /* Sender Job/Status Channel, SOAP message header is not sent completely */

#define BPP_STS_GET_RESPONSE     BPP_STS_GET_REQUEST /*  S/J set this bit if the get rsp was not completely received */

typedef struct
{
    tBPP_ISP_STATE  soap;           /* soap parser state machine */
    tXML_MUL_STATE  xml;            /* XML parser state machine */
    tBPP_OBX_PKT    obx_pkt;        /* Holds the current OBX packet information */
    tBPP_SOAP_RSP   soaprsp;        /* the soap response to be sent */
    tBPP_EVT_MSG    event_data;
    tBPP_OPER_STATUS op_stat;
    UINT8           sts;            /* event is on - status. job allowed - job */
    UINT8           attrsnt;        /* the index of attributes sent */
    UINT8           mlsnt;          /* the index of media_loaded sent */
    UINT16          hdr_mask;
    UINT32          attr_mask;
    UINT8           *p_left_data;
} tBPP_SOAP_CB;

typedef struct
{
    tGOEP_FD        fd;             /* File Descriptor of opened file */
    char            *p_name;        /* current file name */
    BD_ADDR         snd_addr;       /* sender BD address               */
    tOBX_HANDLE     obx_handle;
    tBPP_HANDLE     handle;
    UINT8           index;          /* the index of the other server channel */
    UINT8           scn;            /* Job/Status/referenced object channel SCN (Server Channel Number). */
    tBPP_CHANNEL    channel;
    tBPP_SR_STATE   state;          /* channel state       */

    UINT32          obj_size;
    UINT32          offset;
    UINT32          req_len;
    tBPP_SOAP_CB    soap_cb;
    tBPP_FS_CBACKS  *p_fs_cback;
    tBPP_CBACK      *p_cback;
    UINT8           *p_app_id;

} tBPP_PR_SR_CB;

typedef struct
{
    tSDP_DISCOVERY_DB   *p_sdp_db;  /* Discovery database */
    tGOEP_FD        fd;             /* File Descriptor of opened file */
    UINT32          obj_size;
    char            *p_name;        /* current file name */
    tOBX_HANDLE     obx_handle;
    tBPP_CHANNEL    channel;
    tBPP_HANDLE     handle;
    tBPP_OP         b_op;
    BD_ADDR         peer_addr;
    UINT8           rsp_code;
    tBPP_CL_STATE   state;
    UINT8           scn;            /* Job/Status/referenced object channel SCN (Server Channel Number). */
    UINT8           service;
    UINT8           sec_level;      /* The security level to set on the OBX client channel */

    tBPP_SOAP_CB    soap_cb;
    tBPP_FS_CBACKS  *p_fs_cback;
    tBPP_CBACK      *p_cback;
    UINT8           *p_app_id;
} tBPP_CH_CLNT_CB;

typedef tBPP_CH_CLNT_CB tBPP_PR_OBJ_CB;
/* data per client session */
typedef struct
{
    tBPP_PR_SR_CB   job;            /* job channel                     */
    tBPP_CH_CLNT_CB  obj;            /* object channel                   */   
} tBPP_PR_SESS_CB;

/* data per client session in sender side */
typedef struct
{
    tBPP_CH_CLNT_CB   job;            /* job channel                     */
    tBPP_PR_SR_CB     obj;            /* object channel                  */   
} tBPP_SND_SESS_CB;

typedef tBPP_STATUS (tBPP_SB_ACTION) (tBPP_SOAP_CB *p_cb, tBPP_EVT_MSG *p_evt);

typedef struct
{
    tBPP_SB_ACTION      *p_act;
    const char          *p_str;
} tBPP_SB_ELEM;

/****************************************************************************
**   Server Control Structure
*****************************************************************************/
typedef struct
{
    tBPP_FS_CBACKS      fs_cbacks;
    tBPP_PR_CBACK       *p_cback;

    tBPP_PR_SESS_CB     sess[BPP_PR_MAX_CON];   /* client session (job and object channel) */
    tBPP_PR_SR_CB       stat[BPP_PR_MAX_CON];   /* status channel                  */

    /* SDP attributes */
    tBPP_HANDLE         sdp_con[BPP_PR_MAX_SDP];    /* The handle of the object channel using SDP callback*/
    UINT8               scn_print;  /* Job channel SCN (Server Channel Number). */
    UINT8               scn_status; /* Status channel SCN. */

    UINT16              uuid16;      /* The UUID in the SDP search when starting reference object channel client */
    UINT8               wait;       /* waiting for "stop" printer to complete */
    UINT8               max_con;    /* number of connections registered to OBX */
    UINT8               app_id;     /* for file system */
    UINT8               trace_level;
} tBPP_CB;

/****************************************************************************
**   Sender Control Structure
*****************************************************************************/
typedef struct
{
    tBPP_FS_CBACKS      fs_cbacks;
    tBPP_SND_CBACK      *p_cback;

    tBPP_SND_SESS_CB    sess;                   /* client session (job and object channel) */
    tBPP_CH_CLNT_CB     stat;                   /* status channel : OBX client             */

    BOOLEAN             ref_chnl_on;
    BOOLEAN             file_sz;                /* used for referenced object channel, if file_size requested */
    UINT8               scn_ref_obj;            /* Referenced object channel SCN. */
    UINT8               wait;                   /* waiting for "stop" printer to complete */
    UINT8               app_id;                 /* for file system */
    UINT8               trace_level;
    UINT16              uuid16;                 /* The UUID in the SDP search */
    UINT32              sdp_handle;

    tBPP_ATTR_MEM       attrstr_data;           /* GKI buffer queue holdig printer attributes */
    tBPP_PR_ATR_RSP     *p_pr_attr;             /* printer attribute parsing result */
    
} tBPP_SND_CB;


#ifdef __cplusplus
extern "C"
{
#endif
/*
** Define prototypes for global data
*/
#if BPP_DYNAMIC_MEMORY == FALSE
BPP_API extern tBPP_CB  bpp_cb;
BPP_API extern tBPP_SND_CB  bpp_snd_cb;
#else
BPP_API extern tBPP_CB *bpp_cb_ptr;
BPP_API extern tBPP_SND_CB *bpp_snd_cb_ptr;
#define bpp_cb (*bpp_cb_ptr)
#define bpp_snd_cb (*bpp_snd_cb_ptr)
#endif

/* type for action functions */
typedef void (*tBPP_ACT_FUNC) (void *p_cb, tBPP_EVT_MSG *p_evt);

extern const tOBX_TARGET bpp_job_target;
extern const tOBX_TARGET bpp_sts_target;
extern const tOBX_TARGET bpp_ref_obj_target;
extern const UINT8 bpp_ref_obj_server128[];
extern const tBPP_ISP_TBLS bpp_psp_tbls;
extern const tBPP_ISP_TBLS bpp_ssp_tbls;
extern const tBPP_SB_ELEM bpp_psb_act_tbl[];
extern const tBPP_SB_ELEM bpp_ssb_act_tbl[];
extern const tOBX_TARGET * target[];

/****************************************************************************
**   BPP Debug Function 
*****************************************************************************/
#if BPP_DEBUG == TRUE
extern char *bpp_evt_code(BPP_SND_EVT evt_code);
extern char * bpp_state_code(tBPP_CL_STATE state);
extern  char * bpp_channel_code(tBPP_CHANNEL channel);
#endif

/****************************************************************************
**   BPP Internal Common Function Prototypes
*****************************************************************************/
/* exported from bpp_int.c */
extern void bpp_pr_proc_event(BT_HDR *p_msg);
extern void bpp_snd_proc_event(BT_HDR *p_msg);
extern void bpp_snd_btu_event(BT_HDR *p_msg);

extern UINT16 bpp_ci_event_id(tBPP_HANDLE hdl, tBPP_CHANNEL chnl);
extern void bpp_close_fd (tGOEP_FD *p_fd, tGOEP_CLOSE_CBACK *p_close, UINT8 app_id);
extern tOBX_STATUS bpp_start_server(tBPP_PR_SR_CB *p_cb, tOBX_TARGET *p_target,
                             BOOLEAN auth, UINT8 scn);
extern tBPP_HANDLE bpp_find_cl_handle(tOBX_HANDLE handle);
extern tBPP_CHANNEL bpp_find_cl_channel(tOBX_HANDLE handle);
extern tBPP_PR_SR_CB * bpp_find_sr_cblk(tOBX_HANDLE handle, UINT8 *p_index);

/*****************************************************************************
** BPP utility function for OBX server
******************************************************************************/
/* exported from bpp_ssm.c */
extern void bpp_sr_sm_execute(tBPP_PR_SR_CB *p_cb, UINT16 event, tBPP_EVT_MSG *p_data);

/* exported from bpp_sact.c */
extern void bpp_obx_sr_cback(tOBX_HANDLE handle, tOBX_EVENT event, 
                      tOBX_EVT_PARAM param, BT_HDR *p_pkt);
/* Server Action Prototypes */
extern void bpp_sa_connect (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_close (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_disable (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_obx_evt (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_stop (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_close_compl (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_ci_compl (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_conn_auth (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);

#if ( BPP_INCLUDED == TRUE )
extern void bpp_sa_pswd_evt (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_pswd_rsp (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_ci_write (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_ci_open (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_get_rsp (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sa_put_rsp (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
#endif

/* action for referenced object channel */
#if ( BPP_SND_INCLUDED == TRUE )
extern void bpp_obj_get_rsp (tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_obj_ci_open(tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_obj_ci_read(tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
#endif

extern void bpp_sr_cleanup_op(tBPP_PR_SR_CB *p_cb);

/*****************************************************************************
** BPP action function for OBX Client
******************************************************************************/
/* exported from bpp_csm.c */
extern void bpp_cl_sm_execute(tBPP_CH_CLNT_CB *p_cb, UINT16 event, tBPP_EVT_MSG *p_data);

/* Client action functions */
extern void bpp_ca_init_sdp (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_start_client (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_stop_client (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_send_authrsp(tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_obx_conn_rsp (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_obx_password (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_close (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_abort (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_send_abort (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_get (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_ci_open (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_obx_evt (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_close_compl (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_ci_compl(tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);

extern void bpp_pr_snd_msg(UINT16 req, void * p_msg, UINT16 msg_size, UINT16 channel );

#if ( BPP_INCLUDED == TRUE )
extern void bpp_ca_ci_write (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
#endif

#if (BPP_SND_INCLUDED == TRUE )
extern void bpp_ca_free_mem(tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_ci_read (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_ca_put (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);

extern void bpp_job_clt_start (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_sts_clt_start (tBPP_CH_CLNT_CB *p_cb, tBPP_EVT_MSG *p_data);
#endif

/*****************************************************************************
**   SOAP Utility functions
******************************************************************************/
/* exported from bpp_int.c */
extern void bpp_int_trace_soap(UINT8 *p_buf, int size);

#if (BPP_INCLUDED == TRUE)
/* exported from bpp_psb.c */
extern void bpp_psb_send_more_soap(tBPP_PR_SR_CB *p_cb);
extern tBPP_STATUS bpp_psb_head_tags(const char *p_mssg, tBPP_OBX_PKT *p_bop, UINT16 * p_mask);
extern void bpp_psb_end_tags (tBPP_SOAP_CB *p_cb, const char *p_mssg, tBPP_OBX_PKT *p_bop);

/* BPP Printer SOAP parser */
extern tOBX_RSP_CODE bpp_psp_parse(tBPP_SOAP_CB *p_cb, tXML_OS *p_os, tBPP_HANDLE handle, tBPP_CHANNEL channel);
#endif

#if (BPP_SND_INCLUDED == TRUE)
/* sender soap builder function from bpp_ssb.c */
extern tBPP_STATUS bpp_ssb_head_tags(const char *p_mssg, tBPP_OBX_PKT *p_bop, UINT16 * p_mask);
extern void bpp_ssb_end_tags (tBPP_SOAP_CB *p_cb, const char *p_mssg, tBPP_OBX_PKT *p_bop);
extern void bpp_ssb_send_more_soap(tBPP_CH_CLNT_CB *p_cb);
extern void bpp_ssb_add_body_end(tBPP_CH_CLNT_CB *p_cb);

/* BPP sender memory management utility function */
extern BOOLEAN bpp_add_attrstr (tBPP_ATTR_STR_LIST **p_list, UINT8 *p_attr, UINT16 attrlen, tBPP_ATTR_MEM   *p_attrstrdata, UINT8 ** p_str);
extern BOOLEAN bpp_init_attr_resp_buffer (void);
extern void bpp_free_attr_resp_buffer (void);
/* utility function for BPP sender referenced object channel*/
extern tBPP_SOAP_RSP bpp_build_soap_req(tBPP_CREATE_REQ *p_create);
extern int bpp_read_app_params(BT_HDR *p_pkt, UINT8 *p_aph, UINT8 **p_vary);
extern void bpp_init_get_obj(tBPP_PR_SR_CB *p_cb, tBPP_EVT_MSG *p_data);
extern void bpp_proc_get_obj(tBPP_PR_SR_CB *p_cb, UINT8* p_path);
extern void bpp_get_obj_rsp(tBPP_PR_SR_CB *p_cb, UINT8 rsp_code, UINT16 num_read);

/* BPP Sender SOAP parser */
extern tOBX_RSP_CODE bpp_ssp_parse(tBPP_SOAP_CB *p_cb, tXML_OS *p_os, tBPP_HANDLE handle, tBPP_CHANNEL channel);
#endif

/*****************************************************************************
**   Internal SOAP Parser/Builder functions
******************************************************************************/
/* Soap builder function shared in printer/sender sides */
extern void bpp_isb_add_op_status (tBPP_OPER_STATUS status, UINT8 **p_cur);
extern void bpp_isb_add_str (const char *p_tag, const char *p_elem, UINT8 **p_cur);
extern void bpp_isb_add_int (const char *p_tag, UINT32 elem, UINT8 **p_cur);
extern tBPP_STATUS bpp_isb_head_tags(const char *p_mssg, tBPP_OBX_PKT *p_bop, tBPP_SOAP_ACTION soap_action, UINT16 *mask);
extern UINT8 bpp_isb_add_attribute(tBPP_SOAP_RSP  *p_rsp, tBPP_OBX_PKT *p_bop, UINT8 *p_ml, UINT8 si, UINT8 **p_data);
extern tBPP_STATUS bpp_isb_chk_end (tBPP_SOAP_CB *p_cb,    UINT8 xx, tBPP_SOAP_RSP *p_rsp,   tBPP_OPER_STATUS op_stat);

/* General table driven SOAP Parsing */
extern void bpp_isp_init_state(tBPP_ISP_STATE *p_st, tXML_MUL_STATE *p_xml, const tBPP_ISP_TBLS *p_tbls);
extern tXML_RESULT bpp_isp_parse(tBPP_ISP_STATE *p_st, tXML_MUL_STATE *p_xml, tXML_OS *p_os,tBPP_ROLE role);
extern void bpp_isp_set_mand_found(tBPP_ISP_HNDL hndl, tBPP_ATTR attr);
extern void bpp_isp_encoding(tBPP_ISP_HNDL hndl, tXML_EVENT event, tXML_MEVT_DATA *p_event_data);

/* Utility functions */
extern BOOLEAN bpp_isp_is_ns_tag(tBPP_ISP_HNDL hndl, UINT8 t_id, INT16 *op);
extern UINT8 bpp_isp_curr_enumtype(tBPP_ISP_HNDL hndl, tBPP_ATTR_TYPE *p_type, tXML_STACK *p_stack);
extern UINT16 bpp_isp_stoe (tBPP_ISP_HNDL hndl, UINT8 index, const tXML_STR *p_str_value);
extern void bpp_isp_incr_res(tBPP_ISP_HNDL hndl, tXML_RESULT new_res);


#ifdef __cplusplus
}
#endif



#endif /* BPP_INT_H */
