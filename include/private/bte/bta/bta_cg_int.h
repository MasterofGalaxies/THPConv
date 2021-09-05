/*****************************************************************************
**
**  Name:           bta_cg_int.h
**
**  Description:    This is the private interface file for the BTA cordless
**                  gateway
**
**  Copyright (c) 2005, Broadcom, All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_CG_INT_H
#define BTA_CG_INT_H

#include <private/bte/bta/bta_sys.h>
#include <private/bte/bta/bta_cg_api.h>


/*****************************************************************************
**  Constants
*****************************************************************************/


enum
{
    /* CG events from CTP layer */
    BTA_CG_CONNECTED_FULL_IND =BTA_SYS_EVT_START(BTA_ID_CG) ,
    BTA_CG_DISCONNECT_IND,

	/* Event for CG control channel from CTP layer */
    BTA_CG_CC_INCOMING_ALERT_IND,
    BTA_CG_CC_CONNECT_IND,
    BTA_CG_CC_DISCONNECT_IND,
    BTA_CG_CC_OUTGOING_IND,
	BTA_CG_CC_OUTGOING_INFO_IND,
    BTA_CG_CC_TCS_IND,          /* other tcs event which will not change the call state */

	/* Event for CG control channel from App layer */
    BTA_CG_CC_API_INCOMING_EVT,
	BTA_CG_CC_API_ANSWER_OUTGOING_EVT,
	BTA_CG_CC_API_DISCONNECT_EVT,
    BTA_CG_CC_API_DTMF_EVT,
    BTA_CG_CC_API_FLASH_EVT,
    
    /* handled outside the state machine */
    BTA_CG_API_ENABLE_EVT,
    BTA_CG_API_DISABLE_EVT,
    BTA_CG_API_REG_EVT,
    BTA_CG_API_DEREG_EVT
};



/*****************************************************************************
**  Data types
*****************************************************************************/

/* data type for BTA_CG_API_ENABLE_EVT */
typedef struct
{
    BT_HDR              hdr;                /* Event header */
    UINT8               sec_mask;
    tBTA_CG_CBACK      *p_cback;

} tBTA_CG_API_ENABLE;


/* data type for BTA_CG_API_REG_EVT */
typedef struct
{
    BT_HDR              hdr;                /* Event header */
    UINT8               app_id;
    tBTA_CG_INFO        *gw_info;
    tBTA_CG_WUG_PARAMS  *wug_params;
} tBTA_CG_API_REG;

/* data type for BTA_CG_API_DEREG_EVT */
typedef struct
{
    BT_HDR              hdr;                /* Event header */
    UINT8               app_id;
} tBTA_CG_API_DEREG;


/* data type for BTA_CG_CC_API_INCOMING_EVT */
typedef struct
{
    BT_HDR                      hdr;                /* Event header */
    tBTA_CG_IE_CALLED_NUM       cld_ie;
    BOOLEAN                     cld_ie_present;
    tBTA_CG_IE_CALLING_NUM      clg_ie;
    BOOLEAN                     clg_ie_present;
    tBTA_CG_CALL_CLASS          call_class;
    tBTA_CG_IE_CO_SPEC          cs;
    BOOLEAN                     cs_present;
    UINT8                       index;              /* Index for TL */
} tBTA_CG_CC_API_INCOMING;


/* data type for BTA_CG_CC_API_ANSWER_OUTGOING_EVT */
typedef struct
{
    BT_HDR                      hdr;                /* Event header */
    tBTA_CG_IE_CO_SPEC          cs;
    BOOLEAN                     cs_present;
    UINT8                       cc_handle;
} tBTA_CG_CC_API_ANSWER_OUTGOING;


/* data type for BTA_CG_CC_API_DISCONNECT_EVT */
typedef struct
{
    BT_HDR                      hdr;                /* Event header */
    tBTA_CG_IE_CO_SPEC          cs;
    BOOLEAN                     cs_present;
    tBTA_CG_CLEAR_REASON        clear_reason;
    UINT8                       cc_handle;
} tBTA_CG_CC_API_DISCONNECT;


/* data type for BTA_CG_CONNECTED_FULL_IND */
typedef struct
{
    BT_HDR                      hdr;
    UINT8                       index;              /* Index assoicated with TL */
    BD_ADDR                     bd_addr;
} tBTA_CG_CONNECTED_FULL_IND;

/* data type for BTA_CG_DISCONNECT_IND */
typedef struct
{
    BT_HDR                      hdr;
    UINT8                       index;              /* Index assoicated with TL */
    BD_ADDR                     bd_addr;
} tBTA_CG_DISCONNECT_IND;

/* data type for BTA_CG_CC_TCS_IND */
typedef struct
{
    BT_HDR                      hdr;                /* Event header */
    BD_ADDR                     bd_addr;
    tBTA_CG_CALL_CLASS          call_class;
    tBTA_CG_IE                  ie;
    UINT16                      link_id;
    tBTA_CG_SIGNAL              signal_value;
    UINT8                       line_num;
    UINT8                       cc_event;           /* Use this to indicate different control channel event from CTP */
    tBTA_CG_DTMF_MSGS           dtmf_type;
    UINT8                       dtmf_param;
} tBTA_CG_CC_TCS_IND;

/* union of all event datatypes */
typedef union
{
    BT_HDR                  hdr;
    tBTA_CG_API_ENABLE      api_enable;
    tBTA_CG_API_DEREG       api_dereg;
    tBTA_CG_API_REG         api_reg;

    tBTA_CG_CC_API_INCOMING        api_cc_incoming;
    tBTA_CG_CC_API_ANSWER_OUTGOING api_cc_answer_outgoing;
    tBTA_CG_CC_API_DISCONNECT      api_cc_disconnect;
    
    tBTA_CG_CONNECTED_FULL_IND     connected_full;
    tBTA_CG_DISCONNECT_IND         disconnect;
    tBTA_CG_CC_TCS_IND             cc_tcs;

} tBTA_CG_MSG;


/* typedef for TL state machine control block */
typedef struct
{
    UINT16                      state;
    BD_ADDR                     peer_bd_addr;
    UINT8                       index; /* TL index pass from gw state callback */
    BOOLEAN                     in_use;
    UINT16                      tcs_cc_handle;
    UINT16                      link_id;
    BOOLEAN                     audio_up;
    tBTA_CG_CLEAR_REASON        cause;
} tBTA_CG_SCB;

typedef struct
{
    tBTA_CG_CBACK  *p_cback;                    /* application call back */
    tBTA_CG_SCB     scb[CTP_MAX_NUM_TLS];       /* state machine control blocks */
    UINT8           cg_sec_mask;                /* security mask for CG */
    UINT8           cg_bearer_info;             /* cg SCO settings */
    BOOLEAN         enable;
	UINT8           app_id;

} tBTA_CG_CB;

typedef void (*tBTA_CG_ACTION)(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data);


#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_CG_CB bta_cg_cb;
#else
extern tBTA_CG_CB *bta_cg_cb_ptr;
#define bta_cg_cb (*bta_cg_cb_ptr)
#endif

typedef const tBTA_CG_ACTION  (*tBTA_CG_ACT_TBL);

extern const tBTA_CG_ACTION bta_cg_action[];

typedef struct
{
    tBTA_CG_ACT_TBL         p_cg_action;
    tBTA_CG_LINK_TYPE       desired_link_type; /* Desired SCO type (initiator only) */
} tBTA_CG_CFG;


extern tBTA_CG_CFG *p_bta_cg_cfg;

extern BOOLEAN bta_cg_hdl_event(BT_HDR *p_msg);

extern BOOLEAN bta_cg_sm_execute(tBTA_CG_SCB *p_scb, BT_HDR *p_msg);


extern void bta_cg_enable(tBTA_CG_MSG *p_data);       
extern void bta_cg_disable(tBTA_CG_MSG *p_data); 
extern void bta_cg_register(tBTA_CG_MSG *p_data); 
extern void bta_cg_deregister(tBTA_CG_MSG *p_data); 
extern void bta_cg_orginate(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data); 
extern void bta_cg_answer(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data); 
extern void bta_cg_end(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data); 

extern void bta_cg_tcs_evt(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data); 
extern void bta_cg_l2cap_close(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data);
extern void bta_cg_l2cap_open(tBTA_CG_SCB *p_scb, tBTA_CG_MSG *p_data);

extern void bta_cg_scb_dealloc(tBTA_CG_SCB *p_scb);
extern tBTA_CG_SCB *bta_cg_scb_by_bdaddr(BD_ADDR bd_addr);
extern tBTA_CG_SCB *bta_cg_scb_by_tcs_handle(UINT16 cc_handle);
extern tBTA_CG_SCB *bta_cg_scb_by_index(UINT8 index);


#endif /* BTA_CG_INT_H */
