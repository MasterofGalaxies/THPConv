/*****************************************************************************
** 
**    File Name:   hsp2_int.h
**
**  Description:   This file contains the HSP Profile's internal interface.
**
**
**  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/

#ifndef HSP2_INT_H
#define HSP2_INT_H

#include <private/bte/stack/hsp2_api.h>

#if (HFP_INCLUDED == TRUE)  
#include <private/bte/stack/hfp_api.h>
#endif

#include <private/bte/stack/hsp2_fsm.h>
#include <private/bte/gki.h>
#include <private/bte/stack/port_api.h>
#include <private/bte/stack/btm_api.h>

/* Service Record Definitions */
#define HSP2_NUM_SRV_CLASS_ELEMS     2
#define HSP2_NUM_PROTO_ELEMS         2

/***************** Device Specific Control Block Structures *****************/

/* Discovery Record Definitions */
#define HSP2_NUM_RET_ATTRIB          4
#define HSP2_NUM_UUID_LIST           2

/* Inquiry Record Definitions */
#define tHSP2_INQ_DB                 tBTM_INQ_RESULTS
#define HSP2_INQ_REC_SIZE            sizeof(tGAP_INQ_RESULTS)
#define HSP2_MAX_INQ_RECS            HSP2_INQ_MAX_NUM_RESPS
#define HSP2_INQ_DB_SIZE             HSP2_MAX_INQ_RECS * HSP2_INQ_REC_SIZE

/* Inquiry Control Block */
typedef struct {

    tHSP2_INQ_DB   p_inq_db[HSP2_MAX_INQ_RECS]; /* Inquiry database */
    tHSP2_STATUS   prev_status;                 /* Last inquiry status */
    UINT8          num_results;                 /* Number of deviced found */
    UINT8          cur_inq_index;               /* Current device being saved or searched */

    BOOLEAN         dirty;
#if HSP2_INQUIRY_INCLUDED == TRUE
    void           (*inq_cback)(UINT16 event, void *p);
#endif

}tHSP2_INQUIRY_CB;

/* define local class-of-device structure if GAP not included */
typedef struct {
    UINT8       minor;
    UINT8       major;
    UINT16      service;
} tHSP2_COD;

/* Discovery Control Block */
typedef struct {

    tSDP_DISCOVERY_DB   *p_sdp_db;                  /* Discovery database */
    UINT8               sdp_rec[HSP2_SDP_DB_SIZE];

    UINT16              peer_uuid;
    UINT16              local_uuid;
    UINT16              serv_class;
    UINT16              support_attr_id;
    UINT8               support_attr_type;
    char                *default_name;
    UINT8               serv_id ;
    BOOLEAN             dirty;
    BOOLEAN             cod_set_or_filter; /* Flag indicating usage of the COD */

#if (GAP_INCLUDED == TRUE)
    tGAP_COD            cod;
#else
    tHSP2_COD           cod;
#endif

    tHSP2_STATUS        (*add_attributes) (UINT32 sdp_handle );
    void                (*sdp_cback)(UINT16 sdp_status) ; /* SDP Callback */
} tHSP2_DISCOVERY_CB;

/**** Control Block Structures for AT Command and Result Code Management *****/
/* AT Command and Result Code Parser States */
enum {
    HSP2_AT_NULL_ST,
    HSP2_AT_T_ST,
    HSP2_AT_CMD_ST,
    HSP2_AT_VAL_ST,
    HSP2_AT_RES_LF1_ST,
    HSP2_AT_RES_ST,
    HSP2_AT_RES_LF2_ST,
    HSP2_AT_PROC_ST,
    HSP2_AT_ERROR_ST
}; typedef UINT8 tHSP2_AT_STATE;

 
#define HSP2_AT_CMD_TYPE             1
#define HSP2_RES_CODE_TYPE           0

/* Index into AT Command and Result Code Message Table (hsp2_msg_txt_tbl)
 * The order of these indices must match the order of the messages in
 * hsp2_msg_txt_tbl, and the order of the application events in the
 * tHSP2_APP_CALLBACK_EVENT enum in hsp2_api.h */

#define HSP2_OK_MSG_IDX              0
#define HSP2_RING_MSG_IDX            1
#define HSP2_ERROR_MSG_IDX           2
#define HSP2_CKPD_MSG_IDX            3
#define HSP2_VGM_MSG_IDX             4
#define HSP2_VGS_MSG_IDX             5

#if HFP_INCLUDED == TRUE 
#if CCAP_COMPLIANCE==TRUE
#define HSP2_NUM_CMD_IDX             24 /* For BTRH & CNUM*/
#else   
#define HSP2_NUM_CMD_IDX             22
#endif   
#else
#define HSP2_NUM_CMD_IDX             6   /* If more commands are added, this macro
                                         * must stay last in list */
#endif

/* Element in AT Command and Result Code Buffer Pool */
typedef struct {
    char     *at_string;
    BOOLEAN  is_cmd;
    BOOLEAN  in_use;
} tHSP2_CMD_MSG;

#define HSP2_CMD_POOL_SIZE           24
#define HSP2_MAX_AT_SCRATCH_PAD_LEN  640
#define HSP2_MAX_AT_CMD_END_CHARS    5      /* place holder for CR, LF and NULL characters */


/* Control Block managing At Commands and Result Code messages */
typedef struct {
    /*  Control Block data for parsing of AT Commands and Result Codes */
    UINT8   state;                  /* Parser's state */
    char    cmd[HSP2_MAX_AT_CMD_LENGTH];
    char    val[HSP2_MAX_AT_VAL_LENGTH];
    UINT8   type;                   /* AT Command or Response Code */
    UINT16   cmd_pos;                /* Current position in cmd char array */
    UINT16   val_pos;                /* Current position in val char array */

    /* Control Block data for sending AT Commands */
    UINT8   pool_pos;               /* Next message command pool */
    BOOLEAN ok_pending;             /* HSP is waiting for OK or ERROR */
    BOOLEAN parse_err;

    tHSP2_CMD_MSG hsp2_at_cmd_pool[HSP2_CMD_POOL_SIZE];

    char scratch_pad[HSP2_MAX_AT_SCRATCH_PAD_LEN];
} tHSP2_AT_CB;


enum {
    HSP2_LINK_STATE_CLOSED,
    HSP2_LINK_STATE_LISTEN,
    HSP2_LINK_STATE_OPENING,
    HSP2_LINK_STATE_OPEN,
    HSP2_LINK_STATE_CLOSE_LSTN,
    HSP2_LINK_STATE_CLOSE_OPN
}; typedef UINT8 tHSP2_LINK_STATE;


typedef struct {
    UINT16           handle;        /* Handle of link */
    tHSP2_LINK_STATE state;         /* State of link (see tHSP2_LINK_STATE) */ 
    BOOLEAN          server;        /* TRUE - Link open as server (listen mode) */
    UINT16           disc_res;      /* Reason for disconnection */
} tHSP2_LINK_INFO;

/* HSP FSM Queue Control Block */

#define HSP2_MAX_Q_EVTS  24

typedef struct {
    UINT8    q[HSP2_MAX_Q_EVTS];
    UINT8    cur_evt;
    UINT8    last_evt;
    BOOLEAN  empty;
} tHSP2_EVT_Q;


#define RETURN                      '\r'    /* hopefully this is always 0x0d as per K6 */
#define LINEFEED                    '\n'    /* 0x0a as per V.250 default value */

#if (HFP_INCLUDED == TRUE)  
typedef struct {
    UINT8 code;
    union {
    tHFP_IND_INCALL_PARAMS ind_incall;
    } params;
} tHFP_ACT_PARAMS ;

#define HFP_MAX_DTMF_STR 24

typedef struct {
	BOOLEAN in_use;

	char	dtmf_str[HFP_MAX_DTMF_STR+1];
	UINT8   curr_inx;
} tHFP_DTMF_CB;
#endif

/***************************** HSP Control Block *****************************/
typedef struct {

    tHSP2_PEER_INFO  local_cb;      /* Data specific to local device */
    tHSP2_PEER_INFO  peer_cb;       /* Data specific to peer device */
    tHSP2_AT_CB      at_cb;         /* Data used by AT Command Parser */

    tHSP2_DISCOVERY_CB   disc_cb;
#if HSP2_INQUIRY_INCLUDED == TRUE
    tHSP2_INQUIRY_CB     inq_cb;
#endif

    tHSP2_FSM_STATE fsm_state;      /* State of HSP's State Machine */
    UINT16          inq_repeats;
    UINT16          conn_repeats;

    UINT16          role;           /* Device role (Audio Gateway/Headset) */
    BOOLEAN         bdaddr_specified;

    UINT16          conn_options;   /* Options specified at Establish Connection */
    UINT16          reg_options;    /* Options specified at Registration */

    UINT32          sdp_handle;     /* Record handle in SDP server */

    tHSP2_LINK_INFO rfc;            /* RFCOMM port handle */
    tHSP2_LINK_INFO sco;            /* SCO port handle */

    TIMER_LIST_ENT  cmd_wait_te;    /* AT Command wait timer callback info */
    TIMER_LIST_ENT  cmd_wait_ok;    /* AT Command wait response timer */
    TIMER_LIST_ENT  ring_repeat_te; /* Ring repeat timer callback info */
    TIMER_LIST_ENT  sdp_rtry_to;    /* SDP retry timer callback info */

    BOOLEAN         parked;         /* True if a parked connection exists */

    tHSP2_CALLBACK  *hsp2_cback;    /* Application's status callback function */
    tPORT_CALLBACK  *rfc_mgmt_cback; /* RFCOMM Management callback */
    tPORT_CALLBACK  *rfc_port_cback; /* RFCOMM port/event call back */
    tBTM_SCO_CB     *sco_connect_callbk;
    tBTM_SCO_CB     *sco_disconnect_callbk;

    tHSP2_REG_INFO  api_reg_info;
    BOOLEAN         reg_info_in_use;/* Remembers if application has already registered */
    BOOLEAN         close_only_sco;
    BOOLEAN         hsp2_in_call;   /* Used to decide whether to RING the HS or not in case of IB */

    tHSP2_EVT_Q     evt_q;
    UINT16          ev_id;
    void            (*process_peer_command)
                        (UINT8 index, BOOLEAN at_cmd, tHSP2_AT_QUERY_TYPE qtype, char *value);

#define HSP2_FSM_INVALID_ST 0xFF
    UINT8           modified_state; /* Next State of HSP's State Machine modified in the action function */
    BOOLEAN         ib_ckpd_rcvd;   /* Remembers if application has already received CKPD while in IN BAND RING */

#if ((HFP_INCLUDED == TRUE) && (HFP_AG_INCLUDED==TRUE))
    tHFP_AG_INFO    ag_info;
#endif

#if ((HFP_INCLUDED == TRUE) && (HFP_HF_INCLUDED==TRUE))
    const char      (*init_at_cmds)[24];
#endif

#if (HFP_INCLUDED == TRUE)
    tHFP_ACT_PARAMS act_params;
#endif

#if ((HFP_INCLUDED == TRUE) && (HFP_HF_INCLUDED==TRUE)) 
		tHFP_DTMF_CB dtmf_cb;
#endif

    UINT8           trace_level;
} tHSP2_CB;



typedef tHSP2_STATUS (tHSP2_ACTION) (tHSP2_CB *p_hcb);
typedef tHSP2_STATUS (*tHSP2_ACTIONPTR)(tHSP2_CB *p_hcb);


#if HSP2_INCLUDED == TRUE
/* HSP Control Block external declaration */
#ifdef __cplusplus
extern "C"
{
#endif

#if HSP2_DYNAMIC_MEMORY == FALSE
HSP2_API extern tHSP2_CB  hsp2_cb;
#else
HSP2_API extern tHSP2_CB *hsp2_cb_ptr;
#define hsp2_cb (*hsp2_cb_ptr)
#endif

#ifdef __cplusplus
}
#endif

extern tHSP2_STATUS hsp2_add_support_attr_id(UINT32 handle);

#endif /* HSP2_INCLUDED == TRUE */

extern const tHSP2_ACTIONPTR hsp2_action_tbl[];

/* HSP external function declarations */
extern tHSP2_CMD_MSG *HSP2_getNextCmdMsg(tHSP2_CB *p_hcb);
extern tHSP2_CMD_MSG *HSP2_getFreeCmdMsg(tHSP2_CB *p_hcb);
extern void hsp2_start_timer(TIMER_LIST_ENT *p_timer_entry, UINT16 event, UINT16 interval, tHSP2_CB *p_hcb);
extern void hsp2_sco_connect_callbk(UINT16 sco_inx);
extern void hsp2_sco_disconnect_callbk(UINT16 sco_inx);

extern void hsp2_rfc_mgmt_cb(UINT32 port_status, UINT16 port_handle);
extern void hsp2_rfc_port_cback(UINT32 event, UINT16 port_handle);
extern void hsp2_rfc_mgmt_cb_common(UINT32 port_status, UINT16 port_handle, tHSP2_CB *p_hcb);
extern void hsp2_rfc_port_cback_common(UINT32 event, UINT16 port_handle, tHSP2_CB *p_hcb);

extern void hsp2_sco_connect_callbk_common(UINT16 sco_inx, tHSP2_CB *p_hcb);
extern void hsp2_sco_disconnect_callbk_common(UINT16 sco_inx, tHSP2_CB *p_hcb);

extern void hsp2_init_base( void );

extern void hsp2_format_at_string( UINT8 type, UINT8 msg_idx, UINT16 value, tHSP2_CMD_MSG *p_val, tHSP2_CB *p_hcb );
extern void hsp2_core_send_response_code(UINT8 idx, tHSP2_CB *p_hcb);
extern void hsp2_process_peer_command(UINT8 index, BOOLEAN at_cmd, tHSP2_AT_QUERY_TYPE qtype, char *value);    

extern void hsp2_sdp_cback(UINT16 sdp_status);
extern void hsp2_inquiry_cback(UINT16 event, void *p);
extern void hsp2_inquiry_cback_common(UINT16 event, void *p, tHSP2_CB *p_hcb);
extern void hsp2_sdp_cback_common(UINT16 sdp_status, tHSP2_CB *p_hcb);


extern void HSP2_initInternals(tHSP2_CB *p_hcb);
extern void hsp2_itoacat(const UINT16 val, char * str);
extern UINT16  hsp2_atoi(char* str);
extern tHSP2_STATUS hsp2_core_prfm_discovery(tHSP2_CB *p_hcb);

/* External FSM Declarations */
extern tHSP2_STATUS hsp2_fsm_enqueue_evt(UINT8 event, tHSP2_CB *p_hcb);

/* RFCOMM event mask */
#define HSP2_RFC_PORT_MASK   (PORT_EV_RXCHAR | PORT_EV_CONNECTED | PORT_EV_CONNECT_ERR)

/* Utilities */
#define HSP2_BDADDR_CMP(bd1, bd2)    ( memcmp((void *)(bd1), (void *)(bd2), BD_ADDR_LEN) )


#if (HSP2_AG_INCLUDED == TRUE) || ((HFP_AG_INCLUDED == TRUE) && (HFP_INCLUDED==TRUE)) 
#if (HSP2_HS_INCLUDED == TRUE) || ((HFP_HF_INCLUDED == TRUE) && (HFP_INCLUDED==TRUE))
/************ Both HS and AG included -- Check role at runtime ***********/
#define HSP2_ROLE_HS_TRUE(r1)      ((((r1)->role == HSP2_ROLE_IS_HS)||((r1)->role == HSP2_ROLE_IS_HS15)) ? TRUE : FALSE)
#define HSP2_ROLE_AG_TRUE(r1)      (((r1)->role == HSP2_ROLE_IS_AG) ? TRUE : FALSE)

#else  /* HS_INCLUDED */ 
/***************************** Only AG included ******************************/
#define HSP2_ROLE_HS_TRUE(r1)  (FALSE)
#define HSP2_ROLE_AG_TRUE(r1)  (TRUE)

#endif /* HS_INCLUDED */
#else  /* AG_INCLUDED */

/****************************** Only HS included *****************************/
#define HSP2_ROLE_HS_TRUE(r1)  (TRUE)
#define HSP2_ROLE_AG_TRUE(r1)  (FALSE)

#endif /* AG_INCLUDED */

#if HSP2_AG_INCLUDED == TRUE
#if HSP2_HS_INCLUDED == TRUE

#define HSP2_PEER_UUID         ((UINT16) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? UUID_SERVCLASS_HEADSET_AUDIO_GATEWAY : UUID_SERVCLASS_HEADSET))
#define HSP2_LOCAL_UUID        ((UINT16) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? UUID_SERVCLASS_HEADSET : UUID_SERVCLASS_HEADSET_AUDIO_GATEWAY))
#define HSP2_DEFAULT_NAME      ((char *) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_HS_DEFAULT_NAME : HSP2_AG_DEFAULT_NAME ) )
#define HSP2_SEC_SERVICE       ((UINT8) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? BTM_SEC_SERVICE_HEADSET : BTM_SEC_SERVICE_HEADSET_AG))
#define HSP2_SEC_PEER_SERVICE  ((UINT8) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? BTM_SEC_SERVICE_HEADSET_AG : BTM_SEC_SERVICE_HEADSET))

#define HSP2_FSM_SCO_CLOSE_EVT ((UINT8 ) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_FSM_HS_SCO_CLOSE_EVT : HSP2_FSM_AG_SCO_CLOSE_EVT))
#define HSP2_FSM_DISCONN_EVT   ((UINT8 ) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_FSM_HS_DISCONN_EVT : HSP2_FSM_AG_DISCONN_EVT))

#if HSP2_IB_RING_INCLUDED == TRUE
#define HSP2_FSM_RFC_OPEN_EVT  ((UINT8 ) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_FSM_HS_RFC_OPN_EVT : ((hsp2_cb.conn_options & HSP2_CONN_OPT_INBAND_RING) ? HSP2_FSM_IB_RFC_OPN_EVT : HSP2_FSM_AG_RFC_OPN_EVT)))
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) ((hsp2_cb.conn_options & HSP2_CONN_OPT_INBAND_RING) ? \
                              (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_FSM_HS_IBSCO_OPN_EVT : HSP2_FSM_AG_IBSCO_OPN_EVT) : \
                              HSP2_FSM_SCO_OPN_EVT) )
#else
#define HSP2_FSM_RFC_OPEN_EVT  ((UINT8 ) (((hsp2_cb.role == HSP2_ROLE_IS_HS)||(hsp2_cb.role == HSP2_ROLE_IS_HS15)) ? HSP2_FSM_HS_RFC_OPN_EVT : HSP2_FSM_AG_RFC_OPN_EVT))
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) HSP2_FSM_SCO_OPN_EVT)
#endif /* HSP2_IB_RING_INCLUDED */

#else  /* HSP2_HS_INCLUDED */ 
     
#define HSP2_PEER_UUID         ((UINT16) (UUID_SERVCLASS_HEADSET))
#define HSP2_LOCAL_UUID        ((UINT16) (UUID_SERVCLASS_HEADSET_AUDIO_GATEWAY))
#define HSP2_DEFAULT_NAME      ((char *) (HSP2_AG_DEFAULT_NAME))
#define HSP2_SEC_SERVICE       ((UINT8) (BTM_SEC_SERVICE_HEADSET_AG))
#define HSP2_SEC_PEER_SERVICE  ((UINT8) (BTM_SEC_SERVICE_HEADSET))

#define HSP2_FSM_SCO_CLOSE_EVT ((UINT8 ) HSP2_FSM_AG_SCO_CLOSE_EVT)
#define HSP2_FSM_DISCONN_EVT   ((UINT8 ) HSP2_FSM_AG_DISCONN_EVT)

#if HSP2_IB_RING_INCLUDED == TRUE
#define HSP2_FSM_RFC_OPEN_EVT  ((UINT8 ) ((hsp2_cb.conn_options & HSP2_CONN_OPT_INBAND_RING) ? HSP2_FSM_IB_RFC_OPN_EVT : HSP2_FSM_AG_RFC_OPN_EVT))
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) ((hsp2_cb.conn_options & HSP2_CONN_OPT_INBAND_RING) ? HSP2_FSM_AG_IBSCO_OPN_EVT : \
                                        HSP2_FSM_SCO_OPN_EVT) )
#else
#define HSP2_FSM_RFC_OPEN_EVT  ((UINT8 ) HSP2_FSM_AG_RFC_OPN_EVT)
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) HSP2_FSM_SCO_OPN_EVT)
#endif /* HSP2_IB_RING_INCLUDED */

#endif /* HSP2_HS_INCLUDED */
#else  /* HSP2_AG_INCLUDED */

#define HSP2_PEER_UUID         ((UINT16) (UUID_SERVCLASS_HEADSET_AUDIO_GATEWAY))
#define HSP2_LOCAL_UUID        ((UINT16) (UUID_SERVCLASS_HEADSET))
#define HSP2_DEFAULT_NAME      ((char *) (HSP2_HS_DEFAULT_NAME))
#define HSP2_SEC_SERVICE       ((UINT8) (BTM_SEC_SERVICE_HEADSET))
#define HSP2_SEC_PEER_SERVICE  ((UINT8) (BTM_SEC_SERVICE_HEADSET_AG))

#define HSP2_FSM_RFC_OPEN_EVT  ((UINT8 ) HSP2_FSM_HS_RFC_OPN_EVT)
#define HSP2_FSM_SCO_CLOSE_EVT ((UINT8 ) HSP2_FSM_HS_SCO_CLOSE_EVT)
#define HSP2_FSM_DISCONN_EVT   ((UINT8 ) HSP2_FSM_HS_DISCONN_EVT)

#if HSP2_IB_RING_INCLUDED == TRUE
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) ((hsp2_cb.conn_options & HSP2_CONN_OPT_INBAND_RING) ? HSP2_FSM_HS_IBSCO_OPN_EVT : \
                                        HSP2_FSM_SCO_OPN_EVT) )
#else
#define HSP2_FSM_SCO_OPEN_EVT  ((UINT8 ) HSP2_FSM_SCO_OPN_EVT)
#endif /* HSP2_IB_RING_INCLUDED */

#endif /* HSP2_AG_INCLUDED */


#endif /* HSP2_INT_H */

