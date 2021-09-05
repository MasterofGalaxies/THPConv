/*****************************************************************************
**
**  Name:       bip_int.h
**
**  File:       BIP internal common definitions
**
**  Copyright (c) 2000-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BIP_INT_H
#define BIP_INT_H

#include <private/bte/common/target.h>
#include <private/bte/gki.h>
#include <private/bte/stack/xml_pars_api.h>
#include <private/bte/stack/goep_fs.h>
#include <private/bte/stack/bip_api.h>
#include <private/bte/stack/obx_api.h>
#include <private/bte/stack/goep_util.h>

#if ( BIP_INITR_INCLUDED == TRUE && \
      ((BIP_ARCHIVE_INCLUDED == TRUE) || (BIP_PRINTING_INCLUDED == TRUE)) )
#define BIP_INITR_REF_INCLUDED     TRUE
#else
#define BIP_INITR_REF_INCLUDED     FALSE
#endif

#if ( BIP_RSPDR_INCLUDED == TRUE && \
       ((BIP_ARCHIVE_INCLUDED == TRUE) || (BIP_PRINTING_INCLUDED == TRUE)) )
#define BIP_RSPDR_REF_INCLUDED     TRUE
#else
#define BIP_RSPDR_REF_INCLUDED     FALSE
#endif

#if ( (BIP_RSPDR_INCLUDED == TRUE) || (BIP_INITR_REF_INCLUDED == TRUE) )
#define BIP_OBX_SERVER_INCLUDED     TRUE
#else
#define BIP_OBX_SERVER_INCLUDED     FALSE
#endif

#if ( (BIP_INITR_INCLUDED == TRUE) || (BIP_RSPDR_REF_INCLUDED == TRUE) )
#define BIP_OBX_CLIENT_INCLUDED     TRUE
#else
#define BIP_OBX_CLIENT_INCLUDED     FALSE
#endif


#define BIP_OP_INVALID_SIZE     0xFFF
/* move to target.h */
#define BIP_PUT_REQ_MAX_SIZE    (BIP_IMG_NAME_SIZE + BIP_IMG_ENCODE_SIZE + BIP_TYPE_SIZE + 60)
#define BIP_GET_REQ_MAX_SIZE    (BIP_IMG_NAME_SIZE + BIP_IMG_ENCODE_SIZE + 60)

/* BIP range checking */
#define BIP_MIN_GEN_FEATURE_FLAGS   0x001F /* at least one of the PUSH or PULL needs to be supported */
#define BIP_HANDLE_INVALID     0
#define BIP_HANDLE_ROLE_BIT    2   /* SET=responder, CLEAR=initiator */
#define BIP_HANDLE_CHNL_BIT    1   /* SET=OBX server, CLEAR=OBX client */
#define BIP_HANDLE_IP          4
#define BIP_HANDLE_IS          5
#define BIP_HANDLE_RS          6
#define BIP_HANDLE_RP          7
#define BIP_HANDLE_VALID_MASK  4
#define BIP_HANDLE_BIT_MASK    3



#define BIP_IR_CMD_MASK         0x0080
#define BIP_RR_CMD_MASK         0x0000
#define BIP_IR_CMDS             (BT_EVT_TO_BIP_CMDS|BIP_IR_CMD_MASK)
#define BIP_RR_CMDS             (BT_EVT_TO_BIP_CMDS|BIP_RR_CMD_MASK)
#define BIP_PRIMARY_CMD_MASK    0x0000
#define BIP_SECONDARY_CMD_MASK  0x0040
#define BIP_INT_CMD_MASK        0x001F
#define BIP_INT_BIPR_MASK       0x0080  /* BIP role: responder or initiator */
#define BIP_INT_OBXR_MASK       0x0040  /* OBX role: server or client */
#define BIP_HANDLE_2_INT_EVT(b_h)           (((b_h)&BIP_HANDLE_BIT_MASK) << 6)

#define BIP_INT_CI_OPEN         (0x0001 | BT_EVT_TO_BIP_CMDS) /* file is opened */
#define BIP_INT_CI_READ         (0x0002 | BT_EVT_TO_BIP_CMDS) /* read from file is done */
#define BIP_INT_CI_WRITE        (0x0003 | BT_EVT_TO_BIP_CMDS) /* write file is done */
#define BIP_INT_OBX_CONN        (0x0004 | BT_EVT_TO_BIP_CMDS) /* OBX connect response */
#define BIP_INT_OBX_PASSWORD    (0x0005 | BT_EVT_TO_BIP_CMDS) /* OBX password event */
#define BIP_INT_OBX_CLOSE       (0x0006 | BT_EVT_TO_BIP_CMDS) /* OBX close event */
#define BIP_INT_OBX_EVT         (0x0007 | BT_EVT_TO_BIP_CMDS) /* other OBX events */
#define BIP_INT_CLOSE_CMPL      (0x0008 | BT_EVT_TO_BIP_CMDS) /* close complete */
#define BIP_INT_API_START       (0x0009 | BT_EVT_TO_BIP_CMDS) /* BIP_StartInitiator() is called. */
#define BIP_INT_API_STOP        (0x000A | BT_EVT_TO_BIP_CMDS) /* BIP_StopInitiator() is called */
#define BIP_INT_API_AUTH_RSP    (0x000B | BT_EVT_TO_BIP_CMDS) /* BIP_AuthRsp() is called */
#define BIP_INT_API_GET_OP      (0x000C | BT_EVT_TO_BIP_CMDS) /* BIP_GetRequest() is called */
#define BIP_INT_API_PUT_OP      (0x000D | BT_EVT_TO_BIP_CMDS) /* BIP_PutRequest() is called */
#define BIP_INT_API_ABORT_REQ   (0x000E | BT_EVT_TO_BIP_CMDS) /* BIP_AbortRequest()is called */
#define BIP_INT_INT_SND_ABORT   (0x000F | BT_EVT_TO_BIP_CMDS) /* time to call GOEP_AbortRequest() */
#define BIP_INT_SDP_RESULT      (0x0010 | BT_EVT_TO_BIP_CMDS) /* SDP result */

#define BIP_INT_FIRST_OBX       BIP_INT_OBX_CONN
#define BIP_INT_LAST_OBX        BIP_INT_OBX_EVT
#define BIP_INT_FIRST_CI        BIP_INT_CI_OPEN
#define BIP_INT_LAST_CI         BIP_INT_CI_WRITE

/******************************************************************
 * BIP API Event Definitions 
 ******************************************************************/
/* for initiator primary channel */
#define BIP_IIP_CI_OPEN         (BIP_INT_IP_EVT | BIP_INT_CI_OPEN     ) /* file is opened */
#define BIP_IIP_CI_READ         (BIP_INT_IP_EVT | BIP_INT_CI_READ     ) /* read from file is done */
#define BIP_IIP_CI_WRITE        (BIP_INT_IP_EVT | BIP_INT_CI_WRITE    ) /* write file is done */
#define BIP_IIP_OBX_CONN        (BIP_INT_IP_EVT | BIP_INT_OBX_CONN    ) /* OBX connect response */
#define BIP_IIP_OBX_PASSWORD    (BIP_INT_IP_EVT | BIP_INT_OBX_PASSWORD) /* OBX password event */
#define BIP_IIP_OBX_CLOSE       (BIP_INT_IP_EVT | BIP_INT_OBX_CLOSE   ) /* OBX close event */
#define BIP_IIP_OBX_EVT         (BIP_INT_IP_EVT | BIP_INT_OBX_EVT     ) /* other OBX events */
#define BIP_IIP_CLOSE_CMPL      (BIP_INT_IP_EVT | BIP_INT_CLOSE_CMPL  ) /* close complete */
#define BIP_IIP_API_START       (BIP_INT_IP_EVT | BIP_INT_API_START   ) /* BIP_StartInitiator() is called. */
#define BIP_IIP_API_STOP        (BIP_INT_IP_EVT | BIP_INT_API_STOP    ) /* BIP_StopInitiator() is called */
#define BIP_IIP_API_AUTH_RSP    (BIP_INT_IP_EVT | BIP_INT_API_AUTH_RSP) /* BIP_AuthRsp() is called */
#define BIP_IIP_API_GET_OP      (BIP_INT_IP_EVT | BIP_INT_API_GET_OP  ) /* BIP_GetRequest() is called */
#define BIP_IIP_API_PUT_OP      (BIP_INT_IP_EVT | BIP_INT_API_PUT_OP  ) /* BIP_PutRequest() is called */
#define BIP_IIP_API_ABORT_REQ   (BIP_INT_IP_EVT | BIP_INT_API_ABORT_REQ)/* BIP_AbortRequest()is called */
#define BIP_IIP_INT_SND_ABORT   (BIP_INT_IP_EVT | BIP_INT_INT_SND_ABORT)/* time to call GOEP_AbortRequest() */
#define BIP_IIP_SDP_RESULT      (BIP_INT_IP_EVT | BIP_INT_SDP_RESULT)   /* SDP result */

/* for initiator secondary channel */
#define BIP_IIS_CI_OPEN         (BIP_INT_IS_EVT | BIP_INT_CI_OPEN     ) /* file is opened */
#define BIP_IIS_CI_READ         (BIP_INT_IS_EVT | BIP_INT_CI_READ     ) /* read from file is done */
#define BIP_IIS_CI_WRITE        (BIP_INT_IS_EVT | BIP_INT_CI_WRITE    ) /* write file is done */
#define BIP_IIS_OBX_CONN        (BIP_INT_IS_EVT | BIP_INT_OBX_CONN    ) /* OBX connect request */
#define BIP_IIS_OBX_PASSWORD    (BIP_INT_IS_EVT | BIP_INT_OBX_PASSWORD) /* OBX password event */
#define BIP_IIS_OBX_CLOSE       (BIP_INT_IS_EVT | BIP_INT_OBX_CLOSE   ) /* OBX close event */
#define BIP_IIS_OBX_EVT         (BIP_INT_IS_EVT | BIP_INT_OBX_EVT     ) /* other OBX events */
#define BIP_IIS_CLOSE_CMPL      (BIP_INT_IS_EVT | BIP_INT_CLOSE_CMPL  ) /* close complete */
#define BIP_IIS_API_START       (BIP_INT_IS_EVT | BIP_INT_API_START   ) /* BIP_StartRefService() is called. */
#define BIP_IIS_API_STOP        (BIP_INT_IS_EVT | BIP_INT_API_STOP    ) /* BIP_StopRefService() is called */
#define BIP_IIS_API_PASSWORD    (BIP_INT_IS_EVT | BIP_INT_API_AUTH_RSP) /* BIP_Password() is called */
#define BIP_IIS_API_GET_OP      (BIP_INT_IS_EVT | BIP_INT_API_GET_OP  ) /* BIP_GetResponse() is called  */
#define BIP_IIS_API_PUT_OP      (BIP_INT_IS_EVT | BIP_INT_API_PUT_OP  ) /* BIP_PutResponse() is called  */

/* for responder primary channel */
#define BIP_IRP_CI_OPEN         (BIP_INT_RP_EVT | BIP_INT_CI_OPEN     ) /* file is opened */
#define BIP_IRP_CI_READ         (BIP_INT_RP_EVT | BIP_INT_CI_READ     ) /* read from file is done */
#define BIP_IRP_CI_WRITE        (BIP_INT_RP_EVT | BIP_INT_CI_WRITE    ) /* write file is done */
#define BIP_IRP_OBX_CONN        (BIP_INT_RP_EVT | BIP_INT_OBX_CONN    ) /* OBX connect request */
#define BIP_IRP_OBX_PASSWORD    (BIP_INT_RP_EVT | BIP_INT_OBX_PASSWORD) /* OBX password event */
#define BIP_IRP_OBX_CLOSE       (BIP_INT_RP_EVT | BIP_INT_OBX_CLOSE   ) /* OBX close event */
#define BIP_IRP_OBX_EVT         (BIP_INT_RP_EVT | BIP_INT_OBX_EVT     ) /* other OBX events */
#define BIP_IRP_CLOSE_CMPL      (BIP_INT_RP_EVT | BIP_INT_CLOSE_CMPL  ) /* close complete */
#define BIP_IRP_API_START       (BIP_INT_RP_EVT | BIP_INT_API_START   ) /* BIP_StartResponder() is called. */
#define BIP_IRP_API_STOP        (BIP_INT_RP_EVT | BIP_INT_API_STOP    ) /* BIP_StopResponder () is called */
#define BIP_IRP_API_PASSWORD    (BIP_INT_RP_EVT | BIP_INT_API_AUTH_RSP) /* BIP_Password() is called */
#define BIP_IRP_API_GET_OP      (BIP_INT_RP_EVT | BIP_INT_API_GET_OP  ) /* BIP_GetResponse() is called */
#define BIP_IRP_API_PUT_OP      (BIP_INT_RP_EVT | BIP_INT_API_PUT_OP  ) /* BIP_PutResponse() is called. */

/* for responder secondary channel */
#define BIP_IRS_CI_OPEN         (BIP_INT_RS_EVT | BIP_INT_CI_OPEN     ) /* file is opened */
#define BIP_IRS_CI_READ         (BIP_INT_RS_EVT | BIP_INT_CI_READ     ) /* read from file is done */
#define BIP_IRS_CI_WRITE        (BIP_INT_RS_EVT | BIP_INT_CI_WRITE    ) /* write file is done */
#define BIP_IRS_OBX_CONN        (BIP_INT_RS_EVT | BIP_INT_OBX_CONN    ) /* OBX connect response */
#define BIP_IRS_OBX_PASSWORD    (BIP_INT_RS_EVT | BIP_INT_OBX_PASSWORD) /* OBX password event */
#define BIP_IRS_OBX_CLOSE       (BIP_INT_RS_EVT | BIP_INT_OBX_CLOSE   ) /* OBX close event */
#define BIP_IRS_OBX_EVT         (BIP_INT_RS_EVT | BIP_INT_OBX_EVT     ) /* other OBX events */
#define BIP_IRS_CLOSE_CMPL      (BIP_INT_RS_EVT | BIP_INT_CLOSE_CMPL  ) /* close complete */
#define BIP_IRS_API_START       (BIP_INT_RS_EVT | BIP_INT_API_START   ) /* BIP_ConRefService () is called. */
#define BIP_IRS_API_STOP        (BIP_INT_RS_EVT | BIP_INT_API_STOP    ) /* BIP_DisconRefService () is called */
#define BIP_IRS_API_AUTH_RSP    (BIP_INT_RS_EVT | BIP_INT_API_AUTH_RSP) /* BIP_AuthRsp() is called */
#define BIP_IRS_API_GET_OP      (BIP_INT_RS_EVT | BIP_INT_API_GET_OP  ) /* BIP_GetRequest() is called  */
#define BIP_IRS_API_PUT_OP      (BIP_INT_RS_EVT | BIP_INT_API_PUT_OP  ) /* BIP_PutRequest() is called  */
#define BIP_IRS_API_ABORT_REQ   (BIP_INT_RS_EVT | BIP_INT_API_ABORT_REQ)/* BIP_AbortRequest()is called */
#define BIP_IRS_INT_SND_ABORT   (BIP_INT_RS_EVT | BIP_INT_INT_SND_ABORT)/* time to call GOEP_AbortRequest() */
#define BIP_IRS_SDP_RESULT      (BIP_INT_RS_EVT | BIP_INT_SDP_RESULT)   /* SDP result */

typedef struct
{
    const UINT8 *   type;
    tBIP_FUNCTION_FLAGS fn;
    UINT16          req_size;   /* the size of API data for the BIP request */
    UINT16          rsp_size;   /* the size of API data for the BIP response */
    UINT16          cevt_size;  /* the size of event data for the OBEX client channel (ip, rs) */
    UINT16          sevt_size;  /* the size of event data for the OBEX server channel (is, rp) */
    tBIP_IP_EVENT   ip_evt;
    tBIP_IS_EVENT   is_evt;
    tBIP_RP_EVENT   rp_evt;
    tBIP_RS_EVENT   rs_evt;
} tBIP_GET_OP_MAP;

typedef struct
{
    const UINT8 *   type;
    tBIP_FUNCTION_FLAGS fn;
    UINT16          req_size;   /* the size of API data for the BIP request */
    UINT16          rsp_size;   /* the size of API data for the BIP response */
    UINT16          evt_size;   /* the size of event data for the OBEX server channel (is, rp) */
    tBIP_RP_EVENT   rp_evt;
} tBIP_PUT_OP_MAP;


/******************************************************************
 * state machine for GOEP interface
 ******************************************************************/

enum
{
    BIP_CS_NULL,
    BIP_CS_IDLE,
    BIP_CS_W4_CONN,
    BIP_CS_CONN,
    BIP_CS_CLOSING
};
/* OBEX client states */
typedef UINT8   tBIP_CL_STATE;

enum
{
    BIP_SS_NULL,
    BIP_SS_LISTEN,
    BIP_SS_W4_CONN,
    BIP_SS_CONN,
    BIP_SS_CLOSING
};
/* OBEX server states */
typedef UINT8   tBIP_SR_STATE;

typedef struct
{
    const UINT8 * const target;
    tBIP_FEATURE_FLAGS  feature;
} tBIP_FEATURE;

/******************************************************************
 * XML definition & data types
 ******************************************************************/
/* extern constant vars. */
/*
 * BIP OBEX type header
 */
extern const UINT8 bip_type_ar[];    /* "x-bt/img-archive" */
extern const UINT8 bip_type_att[];   /* "x-bt/img-attachment" */
extern const UINT8 bip_type_cap[];   /* "x-bt/img-capabilities" */
extern const UINT8 bip_type_dsp[];   /* "x-bt/img-display" */
extern const UINT8 bip_type_img[];   /* "x-bt/img-img" */
extern const UINT8 bip_type_list[];  /* "x-bt/img-listing" */
extern const UINT8 bip_type_mon[];   /* "x-bt/img-monitoring" */
extern const UINT8 bip_type_part[];  /* "x-bt/img-partial" */
extern const UINT8 bip_type_pr[];    /* "x-bt/img-print" */
extern const UINT8 bip_type_prop[];  /* "x-bt/img-properties" */
extern const UINT8 bip_type_sts[];   /* "x-bt/img-status" */
extern const UINT8 bip_type_thm[];   /* "x-bt/img-thm" */

/* BIP XML element name */
extern const UINT8 bip_elm_atch[];     /* "attachment" */
extern const UINT8 bip_elm_atch_dsc[]; /* "attachment-descriptor" */
extern const UINT8 bip_elm_atch_fmt[]; /* "attachment-formats" */
extern const UINT8 bip_elm_dpof[];     /* "DPOF-options" */
extern const UINT8 bip_elm_flt_prm[];  /* "filtering-parameters" */
extern const UINT8 bip_elm_img[];      /* "image" */
extern const UINT8 bip_elm_img_cap[];  /* "image-capabilities" */
extern const UINT8 bip_elm_img_dsc[];  /* "image-descriptor" */
extern const UINT8 bip_elm_img_fmt[];  /* "image-formats" */
extern const UINT8 bip_elm_img_hdl[];  /* "image-handles-descriptor" */
extern const UINT8 bip_elm_img_prop[]; /* "image-properties" */
extern const UINT8 bip_elm_img_lst[];  /* "images-listing" */
extern const UINT8 bip_elm_native[];   /* "native" */
extern const UINT8 bip_elm_prf_fmt[];  /* "preferred-format" */
extern const UINT8 bip_elm_var[];      /* "variant" */

/* BIP XML attribute name */
extern const UINT8 bip_atr_ch_stmp[];  /* "character-stamp" */
extern const UINT8 bip_atr_char[];     /* "charset" */
extern const UINT8 bip_atr_cont[];     /* "content-type" */
extern const UINT8 bip_atr_create[];   /* "created" */
extern const UINT8 bip_atr_enc[];      /* "encoding" */
extern const UINT8 bip_atr_fnm[];      /* "friendly-name" */
extern const UINT8 bip_atr_hdl[];      /* "handle" */
extern const UINT8 bip_atr_ind_pr[];   /* "index-print" */
extern const UINT8 bip_atr_mxsize[];   /* "maxsize" */
extern const UINT8 bip_atr_mod[];      /* "modified" */
extern const UINT8 bip_atr_mul_pr[];   /* "multiple-image-print" */
extern const UINT8 bip_atr_name[];     /* "name" */
extern const UINT8 bip_atr_no_set[];   /* "number-sets" */
extern const UINT8 bip_atr_pix[];      /* "pixel" */
extern const UINT8 bip_atr_size[];     /* "size" */
extern const UINT8 bip_atr_ss_pr[];    /* "specific-size-print" */
extern const UINT8 bip_atr_std_pr[];   /* "standard-print" */
extern const UINT8 bip_atr_trans[];    /* "transformation" */
extern const UINT8 bip_atr_trim[];     /* "trimming" */
extern const UINT8 bip_atr_type[];     /* "type" */
extern const UINT8 bip_atr_ver[];      /* "version" */
extern const UINT8 bip_atr_unknown[];  /* "unknown" */
extern const UINT8 * const bip_trns_array[];

/* BIP XML fixed attribute value */
extern const UINT8 bip_atr_val_ver[];

struct t_bip_xp_state;
typedef struct t_bip_xp_state tBIP_XP_HNDL;

/* Action function which is called by the general SOAP parser
** for XML_TAG, XML_ATTRIBUTE and XML_CHARDATA events only.
*/
typedef void (*BIP_XP_TAG_ACTION)(tBIP_XP_HNDL * hndl, tXML_EVENT event,
                                   tXML_MEVT_DATA *p_event_data);

typedef struct
{
    const UINT8 *p_name;
    UINT8       len;
} tBIP_XP_TTBL_ELEM;
typedef tBIP_XP_TTBL_ELEM tBIP_XP_TTBL[];              /* Tag Table */

typedef UINT8 *tBIP_XP_PTBL_ELEM;
typedef tBIP_XP_PTBL_ELEM tBIP_XP_PTBL[];          /* Parsing Table */

/* index to bip_xp_ttbl[] */
/* BIP XML element (TAG) name */
#define BIP_XP_ATCH_DSC_ID      0x01
#define BIP_XP_IMG_CAP_ID       0x02
#define BIP_XP_IMG_DSC_ID       0x03
#define BIP_XP_IMG_HDL_ID       0x04
#define BIP_XP_IMG_PROP_ID      0x05
#define BIP_XP_IMG_LST_ID       0x06
#define BIP_XP_MAX_OBJ_TAG_ID   BIP_XP_IMG_LST_ID
/* sub tags */
#define BIP_XP_ATCH_ID          0x07
#define BIP_XP_ATCH_FMT_ID      0x08
#define BIP_XP_IMG_ID           0x09
#define BIP_XP_IMG_FMT_ID       0x0A
#define BIP_XP_NATIVE_ID        0x0B
#define BIP_XP_VARTANT_ID       0x0C

#define BIP_XP_DPOF_ID          0x0D
#define BIP_XP_FLT_PRM_ID       0x0E
#define BIP_XP_PRF_FMT_ID       0x0F
/* BIP XML attribute name */
#define BIP_XP_CHAR_SET_ID      0x10
#define BIP_XP_CONT_TYPE_ID     0x11
#define BIP_XP_CREATED_ID       0x12
#define BIP_XP_ENCODING_ID      0x13
#define BIP_XP_MODIFIED_ID      0x14
#define BIP_XP_MAXSIZE_ID       0x15
#define BIP_XP_NAME_ID          0x16
#define BIP_XP_PIXEL_ID         0x17
#define BIP_XP_SIZE_ID          0x18
#define BIP_XP_TRANS_ID         0x19
#define BIP_XP_HANDLE_ID        0x1A
#define BIP_XP_FNAME_ID         0x1B
#define BIP_XP_TYPE_ID          0x1C

#define BIP_XP_DSC_ID           0x1D
#define BIP_XP_IDX_ID           0x1E
#define BIP_XP_MUL_ID           0x1F
#define BIP_XP_QTY_ID           0x20
#define BIP_XP_SIZ_ID           0x21
#define BIP_XP_STD_ID           0x22
#define BIP_XP_TRM_ID           0x23
#define BIP_XP_VERSION_ID       0x24
#define BIP_XP_UNKNOWN_ID       0x25 /* unknown */
#define BIP_XP_PRES_ID          0x26 /* presence bit - BIP_XP_MAX_TID */
#define BIP_XP_TAG_END_ID       0x27 /* XML_TAG_END is detected, and end is TRUE */
#define BIP_XP_PAUSE_ID         0x28 /* XML_TAG_END is detected, yet end is not TRUE */
#define BIP_XP_ETAG_ID          0x29 /* XML_ETAG is detected */

#ifndef BIP_DEBUG_XML
#define BIP_DEBUG_XML   FALSE
/*
#define BIP_DEBUG_XML   TRUE
*/
#endif

#ifndef BIP_TRACE_XML
#define BIP_TRACE_XML   FALSE
/*
#define BIP_TRACE_XML   TRUE
*/
#endif

#if (BIP_DEBUG_XML == TRUE)
#define BIP_XP_MAX_TID          0x29
#else
#define BIP_XP_MAX_TID          0x26
#endif
#define BIP_XP_TTBL_SIZE        (BIP_XP_MAX_TID + 1)


/* XML stuff*/
typedef struct t_bip_xp_state
{

    tXML_PROP     *p_prop;
    UINT8         prop_ind;
    UINT8         max_num_prop;
    UINT8         obj;           /* the XML object - (tBIP_XML_OBJ + 1)*/

    /* status */
    BOOLEAN       ended;
    UINT8         sub_dm; /* bitwise OR  of tBIP_PRES_DATA_MEMBER */
} tBIP_XP_STATE;

/* for XML builder */
enum
{
    BIP_IDO_PIXEL_REQUIRED  = 0x1, /* pixel is required */
    BIP_IDO_PIXEL_RANGE     = 0x2, /* pixel range is allowed */
    BIP_IDO_GET_IMAGE_REQ   = 0x4, /* is GetImage Request */
    BIP_IDO_SIZE_STR        = 0x8 /* use "size", if this bit is set. use "maxsize", otherwise */
};
typedef UINT8 tBIP_IMG_DESC_OPTS;

/******************************************************************
 * BIP internal control blocks
 ******************************************************************/

typedef UINT8  tBIP_OP; /* tBIP_GET_OP or tBIP_PUT_OP for control block use */

#define BIP_OP_MASK         0x8F
#define BIP_OP_TYPE_MASK    0x80
#define BIP_OP_RSP_MASK     0x40  /* SET this bit if request sent and response not received yet
                                     - for client abort purposes */
#define BIP_OP_PUT          0x80
#define BIP_OP_GET          0

/* OBX Packet Structure - Holds current response packet info */
typedef struct
{
    BT_HDR  *p_pkt;             /* Holds the current OBX header for Put or Get */
    UINT8   *p_start;           /* Start of the Body of the packet */
    UINT32   file_size;         /* length of file (LEN_UNKNOWN if not available) */
    UINT16   offset;            /* Contains the current offset into the Body (p_start) */
    UINT16   bytes_left;        /* Holds bytes available left in Obx packet */
} tBIP_OBX_PKT;

typedef struct
{
    tBIP_XP_STATE   xud;      /* XML parser user data */
    tXML_MUL_STATE  xml;      /* XML parser state machine */
} tBIP_XP_INFO;

/* some constants for XML builder */
/* images-listing object */
#define BIP_XB_MIN_LIST_ELM_SIZE    26
#define BIP_XB_CREATED_SIZE         27
#define BIP_XB_MODIFIED_SIZE        28
#define BIP_XB_LIST_END_SIZE        17
/* image-properties object */
#define BIP_XB_MAX_VARIANT_SIZE     (100+BIP_IMG_ENCODE_SIZE)
#define BIP_XB_MAX_PROP_ATT_SIZE    (120+BIP_TYPE_SIZE+BIP_CHARSET_SIZE+BIP_ATT_NAME_SIZE)
/* imaging-capabilities object */
#define BIP_XB_MAX_CAPS_FMT_SIZE    (70+BIP_IMG_ENCODE_SIZE)
#define BIP_XB_MAX_CAPS_ATT_SIZE    (50+BIP_TYPE_SIZE+BIP_CHARSET_SIZE)
#define BIP_XB_MAX_CAPS_FILTER_SIZE (75)
#define BIP_XB_MAX_CAPS_DPOF_SIZE   (150)

typedef struct
{
    void            *p_obj;     /* the XML object data tsruct */
    UINT8           progress;   /* keep track of the members of the XML object to be build */
    UINT8           xml_ind;    /* if the next member of the XML object is an array, this is the next index */
} tBIP_XB_INFO;

typedef struct
{
    tBIP_GET_PART_REQ_EVT   evt;
    UINT32                  len;    /* len read so far */
} tBIP_PART_INFO;

typedef struct
{
    union
    {
        tBIP_XP_INFO    parse;
        tBIP_XB_INFO    build;
        tBIP_PART_INFO  part;
    } u;
} tBIP_OBJ_INFO;

typedef struct
{
    tBIP_APP_CBACK  *p_cback;    /* pointer to application callback function */
    tBIP_OBJ_INFO   *p_obj;      /* extra infor for the corrent object */
    UINT8           *p_file;     /* the file for the current operation */
    tBIP_OBX_PKT    o_pkt;       /* pointer to OBX packet */
    tBIP_HANDLE     b_hdl;       /* BIP handle */
    tOBX_HANDLE     o_hdl;       /* OBX handle */
    tBIP_OP         b_op;        /* current BIP op */
    UINT8           state;       /* The channel state (FSM) */
} tBIP_CH_SUB_CBLK;


typedef struct
{
    tBIP_APP_CBACK      *p_cback;   /* pointer to application callback function */
    tBIP_OBJ_INFO       *p_obj;     /* extra infor for the current object */
    UINT8               *p_file;    /* the file for the current operation */
    tBIP_OBX_PKT        o_pkt;      /* pointer to OBX packet */
    tBIP_HANDLE         b_hdl;      /* BIP handle */
    tOBX_HANDLE         o_hdl;      /* OBX handle */
    tBIP_OP             b_op;       /* current BIP op (evt id) */
    UINT8               state;      /* The channel state (FSM) */
    /* the above is in tBIP_CH_SUB_CBLK */

    tGOEP_FD            fd;         /* handle to file system */
    tBIP_FUNCTION_FLAGS fns;        /* Supported BIP functions */
    UINT32              sdp_handle; /* SDP record handle for this channel */
    UINT16              sme_mask;   /* SM event mask */
    tBIP_SERVICE        service;    /* The active BIP feature */
    BOOLEAN             use_auth;   /* Use OBEX authentication for incoming OBEX connections */
    UINT8               rsp_code;   /* OBX response code frpm API */
    UINT8               op_sts;     /* use BIP_OP_STS_* to keep track of b_op status */
    UINT8               app_id;     /* the application ID for file system */
} tBIP_CH_SRVR_CBLK;

#define BIP_OP_STS_1ST_GET_RSP      1     /* C   set this bit when waiting for first GET response */
#define BIP_OP_STS_BODY_FILE        2     /* C/S set this bit if the BODY header goes to a file */
#define BIP_OP_STS_PUT_FINAL        0x10  /* S   set this bit if the received put req has final set */
#define BIP_OP_STS_WAIT_ABORT       0x20  /* C   set this bit when abort is requested and not sent  */
#define BIP_OP_STS_WAIT_STOP        0x20  /* S   set this bit when stop API is issued and waiting... */
#define BIP_OP_STS_WAIT_FS          0x40  /* C/S set this bit when waiting for GOEP_xxxRsp()  */
#define BIP_OP_STS_OBX_RSP          0x80  /* C   set this bit when waiting for response,
                                           *     clear this bit when response is received */

typedef struct
{
    tBIP_APP_CBACK      *p_cback;   /* pointer to application callback function */
    tBIP_OBJ_INFO       *p_obj;     /* extra infor for the corrent object */
    UINT8               *p_file;    /* the file for the current operation */
    tBIP_OBX_PKT        o_pkt;      /* pointer to OBX packet */
    tBIP_HANDLE         b_hdl;      /* BIP handle */
    tOBX_HANDLE         o_hdl;      /* OBX handle */
    tBIP_OP             b_op;       /* current BIP op (get/put op) */
    UINT8               state;      /* The channel state (FSM) */
    /* the above is in tBIP_CH_SUB_CBLK */

    tGOEP_FD            fd;         /* handle to file system */
    tBIP_FUNCTION_FLAGS fns;        /* BIP functions Supported by the connected responder */
    UINT16              sme_mask;   /* SM event mask */
    tBIP_SERVICE        service;    /* The active BIP feature */
    BD_ADDR             peer_addr;
    UINT8               sec_level;  /* The security level to set on the OBX client channel */
    UINT8               rsp_code;   /* OBX response code */
    UINT8               op_sts;     /* use BIP_OP_STS_* to keep track of b_op status */
    UINT8               api_evt;    /* the API event (GET) associated with b_op */
    UINT8               app_id;     /* the application ID for file system */
} tBIP_CH_CLNT_CBLK;

typedef struct
{
    tBIP_CH_CLNT_CBLK   cl_cb;     /* The channel control block for the primary OBEX session (client) */
#if (BIP_ARCHIVE_INCLUDED == TRUE || BIP_PRINTING_INCLUDED == TRUE)
    tBIP_CH_SRVR_CBLK   sr_cb;     /* The channel control block for the secondary OBEX session (server) */
    UINT32              partial_left;/* the partial file still to be sent */
#endif
} tBIP_INITR_CBLK;

enum
{
    BIP_REF_NULL,   /* initial - not requested */
    BIP_REF_RCVD,   /* secondary channel requested */
    BIP_REF_DISCD   /* secondary channel disconnected */
};
typedef UINT8 tBIP_REF_REQD;

typedef struct
{
    tBIP_CH_SRVR_CBLK   sr_cb;    /* The channel control block for the primary OBEX session (server) */
#if (BIP_ARCHIVE_INCLUDED == TRUE || BIP_PRINTING_INCLUDED == TRUE)
    tBIP_CH_CLNT_CBLK   cl_cb;     /* The channel control block for the secondary OBEX session (client) */
    tBIP_SERVICE_ID     service_id; /* The service ID of the reference object SDP record. */
    tBIP_REF_REQD       ref_reqd;   /* the StartArchive or StartPrint request is received */
#endif
    tBIP_FEATURE_FLAGS  sup_ft;     /* Supported BIP features */
    tBIP_FUNCTION_FLAGS sup_fn;     /* Supported BIP functions */
} tBIP_RSPDR_CBLK;



typedef struct
{
    /* file system interface */
    tGOEP_OPEN_CBACK    *p_open_cback;
    tGOEP_CLOSE_CBACK   *p_close_cback;
    tGOEP_READ_CBACK    *p_read_cback;
    tGOEP_WRITE_CBACK   *p_write_cback;
    tGOEP_SEEK_CBACK    *p_seek_cback;

#if (BIP_INITR_INCLUDED == TRUE)
    tBIP_INITR_CBLK     initr;
#endif
#if (BIP_RSPDR_INCLUDED == TRUE)
    tBIP_RSPDR_CBLK     rspdr;
#endif

    tSDP_DISCOVERY_DB   *p_db;          /* pointer to discovery database */
    UINT16              uuid16;         /* The UUID in the SDP search */

    UINT8               trace_level;
} tBIP_CB;

/******************************************************************
 * data types for BIP internal events
 ******************************************************************/
typedef struct
{
    BD_ADDR             bd_addr;    /* The Bluetooth address of the initiator */
    tBIP_CON_REF_MSG    ref;        /* the parameters from API */
} tBIP_CON_REF_INT_MSG;


typedef struct
{
    BT_HDR              hdr;
    void                *args;
} tBIP_API_MSG;

typedef struct
{
    BT_HDR              hdr;
    tBIP_SERVICE        service;
} tBIP_START_SERVER;

typedef struct
{
    BT_HDR              hdr;
    tBIP_SERVICE        service;
} tBIP_START_CLIENT;

typedef struct
{
    BT_HDR              hdr;
    tOBX_HANDLE         handle;
    tOBX_EVT_PARAM      param;
    BT_HDR              *p_pkt;
	tOBX_EVENT			event;
    UINT8               rsp_code;
} tBIP_OBX_EVENT;

typedef union
{
    BT_HDR              hdr;
    tBIP_START_CLIENT   stc;
    tBIP_START_SERVER   sts;
    tBIP_API_MSG        api;
    tBIP_OBX_EVENT      obx;
    tGOEP_OPEN_RSP      open;
    tGOEP_READ_RSP      read;
    tGOEP_WRITE_RSP     write;
    tBIP_SDP_RESULT_EVT sdp;
} tBIP_EVT_MSG;

#ifndef BIP_EVT_MSG_SIZE
#define BIP_EVT_MSG_SIZE   sizeof(tBIP_EVT_MSG)
#endif

/* type for action functions */
typedef void (*tBIP_ACT_TBL) (void *p_cb, tBIP_EVT_MSG *p_evt);

/* exported from bip_int.c */
#ifdef __cplusplus
extern "C"
{
#endif

#if (defined (BT_USE_TRACES) && BT_USE_TRACES == TRUE)
extern char *bip_cs_state_name (tBIP_CL_STATE state);
extern char *bip_ss_state_name (tBIP_SR_STATE state);
extern char *bip_sm_evt_name (UINT16 event);
#else
#define bip_cs_state_name(_x) ""
#define bip_ss_state_name(_x) ""
#define bip_sm_evt_name(_x) ""
#endif

#if (defined(BIP_TRACE_XML) && BIP_TRACE_XML == TRUE)
extern void bip_int_trace_xml(UINT8 *p_buf, int size);
#else
#define bip_int_trace_xml(x, y)
#endif

/*
** Define prototypes for global data
*/
#if BIP_DYNAMIC_MEMORY == FALSE
BIP_API extern tBIP_CB  bip_cb;
#else
BIP_API extern tBIP_CB *bip_cb_ptr;
#define bip_cb (*bip_cb_ptr)
extern void * bip_cblk_tbl [];
#endif

#ifdef __cplusplus
}
#endif

/* exported from bip_int.c */
extern const UINT8 bip_push_server[];
extern const UINT8 bip_pull_server[];
extern const UINT8 bip_print_server[];
extern const UINT8 bip_archive_server[];
extern const UINT8 bip_camera_server[];
extern const UINT8 bip_display_server[];

extern const UINT8 bip_ref_obj_server[];
extern const UINT8 bip_arch_obj_server[];
extern const UINT32 bip_ir_max_funcs[];
extern const UINT32 bip_rr_max_funcs[];
extern const tBIP_FEATURE bip_target_servers[];
extern const tBIP_GET_OP_MAP bip_get_op_array[];
extern const tBIP_PUT_OP_MAP bip_put_op_array[];

extern void bip_free_obx_pkt(tBIP_OBX_PKT *p_obx);
extern void bip_close_fd (tGOEP_FD *p_fd, UINT8 app_id);
extern void bip_int_add_img_hdl_hdr(BT_HDR  *p_pkt, UINT8 * img_hdl);
extern void bip_int_read_img_hdl_hdr(BT_HDR *p_pkt, UINT8 *p_img_hdl);
extern int bip_int_read_app_params(BT_HDR *p_pkt, UINT8 *p_aph, UINT8 **p_vary);
extern void bip_proc_btu_event(BT_HDR *p_msg);

/* exported from bip_build.c */
extern void bip_bld_att_desc(BT_HDR *p_pkt, tBIP_ATTACH_DESC *p_desc);
extern void bip_bld_img_hdl_desc(BT_HDR *p_pkt, tBIP_IMAGE_HDL_DESC *p_hdl_desc);
extern tOBX_RSP_CODE bip_bld_img_descriptor(BT_HDR *p_pkt, tBIP_IMAGE_DESC *p_desc, tBIP_IMG_DESC_OPTS options);
extern tOBX_RSP_CODE bip_bld_img_caps(tBIP_CH_SRVR_CBLK *p_cb, tBIP_IMAGING_CAPS *p_caps);
extern tOBX_RSP_CODE bip_bld_img_list(tBIP_CH_SRVR_CBLK *p_cb, tBIP_IMG_LIST_RSP *p_list);
extern tOBX_RSP_CODE bip_bld_img_props(tBIP_CH_SRVR_CBLK *p_cb, tBIP_IMAGE_PROPERTIES *p_prop);

/* exported from bip_csm.c */
extern void bip_cl_sm_execute(tBIP_CH_CLNT_CBLK *p_cb,
                              UINT16 event, tBIP_EVT_MSG *p_data);

/* exported from bip_ssm.c */
extern void bip_sr_sm_execute(tBIP_CH_SRVR_CBLK *p_cb, UINT16 event, tBIP_EVT_MSG *p_data);

/* exported from bip_cact.c */
extern void bip_ip_start (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_rs_start (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
/* client action functions */
extern void bip_ca_init_sdp (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_start_client (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_stop_client (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_send_authrsp (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_obx_conn_rsp (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_obx_password (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_close (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_abort (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_send_abort (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_get (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_put (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_ci_write (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_ci_read (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_ci_open (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_obx_rsp (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_close_compl (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_ca_ci_compl (tBIP_CH_CLNT_CBLK *p_cb, tBIP_EVT_MSG *p_evt);

/* exported from bip_sact.c */
extern void bip_rp_start (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_is_start (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
/* Server action functions */
extern void bip_sa_connect (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_pswd_evt (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_close (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_disable (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_obx_evt (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_stop (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_conn_auth (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_pswd_rsp (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_ci_open (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_ci_read (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_ci_write (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_get_rsp (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_put_rsp (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_close_compl (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);
extern void bip_sa_ci_compl (tBIP_CH_SRVR_CBLK *p_cb, tBIP_EVT_MSG *p_evt);


/* exported from bip_parse.c */
extern void bip_xp_init(tBIP_CH_SUB_CBLK *p_cb);
extern void bip_xp_parse(tBIP_CH_SUB_CBLK *p_scb, UINT8 *p_begin, UINT16 len,
                         tXML_PROP *p_prop, UINT8 num_prop, void *p_res);

#endif /* BIP_INT_H */
