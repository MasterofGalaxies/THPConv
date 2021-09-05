/*****************************************************************************
**
**  Name:          tcs_int.h
**
**  Description:   this file contains TCS internal definitions
**
**  Copyright (c) 2000-2005, Broadcom., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
******************************************************************************/


#ifndef TCS_INT_H
#define TCS_INT_H

#include <private/bte/stack/tcs_api.h>
#include <private/bte/stack/tcs_defs.h>

#define TCSU_DEV_NOT_FOUND    TCS_MAX_NUM_ACL_CONNS
#define TCSU_NO_DEV_RES       TCS_MAX_NUM_ACL_CONNS
#define TCSU_RES_NOT_FOUND    0xffff

#define TCSU_NO_CCSM_INST     TCS_MAX_NUM_SIMUL_CALLS

#define TCS_MAX_NUM_CC_RES        TCS_MAX_NUM_SIMUL_CALLS
#define TCSU_NO_BCSM_RES      TCS_MAX_NUM_SIMUL_CALLS

#define TCS_INVALID_CC_HANDLE TCS_MAX_NUM_SIMUL_CALLS
#define TCS_INVALID_BC_HANDLE TCS_MAX_NUM_SIMUL_CALLS
#define TCS_INVALID_BINX      TCS_MAX_NUM_SIMUL_CALLS

#define TCS_INVALID_DINX      TCS_MAX_NUM_ACL_CONNS

#define TCS_INVALID_SCO_INX   0xffff

#define TCSB_NEW_BEARER_SET 1

#define TCS_TCTP_400_TIMEOUT TCS_T406_TIMEOUT+1
#define TCS_FIMA_GUARD_TIMEOUT TCS_TCTP_400_TIMEOUT+1

#define TCS_WUG_T401 8
#define TCS_WUG_T402 8
#define TCS_WUG_T403 4
#define TCS_WUG_T404 3
#define TCS_WUG_T405 3
#define TCS_WUG_T406 20

#define TCS_WUG_TCTP_400 604800
#define TCS_WUG_FIMA_GUARD 1

/* Macro that checks link type; returns TRUE if SCO or eSCO type */
#define TCS_IS_SCO_LTYPE(ltype) (((ltype) == TCS_BC_LINK_TYPE_SCO ||                \
                                  (ltype) == TCS_BC_LINK_TYPE_ESCO) ? TRUE : FALSE)

/* Call control states */
enum {
    TCS_ST_CALL_INITIATED,
    TCS_ST_CALL_PRESENT,
    TCS_ST_CONNECT_REQ,
    TCS_ST_ACTIVE,
    TCS_ST_DISCONNECT_REQ,
    TCS_ST_DISCONNECT_IND,
    TCS_ST_RELEASE_REQ,
#if TCS_LEAN == FALSE
    TCS_ST_CALL_RECEIVED,
    TCS_ST_CALL_DELIVERED,
    TCS_ST_OVERLAP_SENDING,
    TCS_ST_OVERLAP_RECEIVING,
    TCS_ST_OUT_CALL_PROCEED,
    TCS_ST_IN_CALL_PROCEED,
#endif
    SM_RETURNEDs
};

#define sNULL 0xff

/* Timers related to TCS Call Control */
enum
{
    TCS_T303,
#if TCS_LEAN == FALSE
    TCS_T304,
    TCS_T310,
    TCS_T301,
    TCS_T302,
#endif
    TCS_T313,
    TCS_T305,
    TCS_T308,
    SM_NUM_TIMERS
};

/* Events to the TCS CC state machine */
enum
{
    TCS_EVT_END_CALL,
#if TCS_LEAN == FALSE        
    TCS_EVT_SETUP_ACK,
    TCS_EVT_CALL_PROC,
    TCS_EVT_ALERTING,
#endif
    TCS_EVT_CONNECT,
    TCS_EVT_REL_COMP,
    TCS_EVT_SEND_INFO,  
    TCS_EVT_DISCONNECT,
    TCS_EVT_INFORMATION,
    TCS_EVT_CONN_ACK,
    TCS_EVT_RELEASE,

    TCS_EVT_T303_TO,
#if TCS_LEAN == FALSE
    TCS_EVT_T304_TO,
    TCS_EVT_T310_TO,
    TCS_EVT_T301_TO,
    TCS_EVT_T302_TO,
#endif
    TCS_EVT_T313_TO,
    TCS_EVT_T305_TO,
    TCS_EVT_T308_TO,
    TCS_EVT_MAX_CC_STATE_EVT,
    TCS_EVT_PROGRESS = TCS_EVT_MAX_CC_STATE_EVT, /* TCS_CC_MSG_PROGRESS     (TCS_PROTO_CC + 0x04) */
    TCS_EVT_SETUP,                     /* TCS_CC_MSG_SETUP        (TCS_PROTO_CC + 0x05) */

    TCS_EVT_START_DTMF,             /* TCS_CC_MSG_START_DTMF   (TCS_PROTO_CC + 0x10) */
    TCS_EVT_START_DTMF_ACK,         /* TCS_CC_MSG_START_DTMF_ACK(TCS_PROTO_CC + 0x11)*/
    TCS_EVT_START_DTMF_REJ,         /* TCS_CC_MSG_START_DTMF_REJ(TCS_PROTO_CC + 0x12)*/
    TCS_EVT_STOP_DTMF,              /* TCS_CC_MSG_STOP_DTMF    (TCS_PROTO_CC + 0x13) */
    TCS_EVT_STOP_DTMF_ACK,           /* TCS_CC_MSG_STOP_DTMF_ACK (TCS_PROTO_CC + 0x14)*/
    TCS_EVT_BCST_T303_TO,
    TCS_EVT_INVALID
};

/* Action codes on a call once the bearer is complete */
enum {
    TCS_NO_ACT,
    TCS_END_CALL_ACT,
    TCS_PROCEED_CALL_ACT
};

/* Storage for post bearer-setup action information */ 
typedef struct {

    UINT8 post_act; /* Action code TCS_NO_ACT, TCS_END_CALL_ACT or TCS_PROCEED_CALL_ACT */
	UINT8 act_data; /* Holds clear reason for end call or proc code for proceed call */

	tTCS_CALL_ACT_OPTS action_info; /* Action Info for end call or proceed call */
	tTCS_IE_CO_SPEC  cs; /* Company spec IE to go with the action */

} tTCS_CC_ACT_OPTS;

/* Codes for current usage of a signaling channel */
enum {
    TCS_RES_FREE, 
    TCS_RES_CC, 
    TCS_RES_BCST
} ;

/* Per l2cap channel info */
typedef struct {
    BOOLEAN is_free;
    UINT8   dev_inx;

#define CHANNEL_ID_UNKNOWN 0xffff
    UINT8   curr_use; /* One of RES_FREE, RES_CC, RES_BCST */
    UINT16  cc_handle;
    UINT16  bc_handle;
    UINT16  ch_id;

} tTCS_CC_RES;  /* An l2cap channel resource */

/* Per ACL link info */
typedef struct {
    BOOLEAN is_free;

    UINT8   num_res;
    BD_ADDR addr;

    tTCS_CC_RES resources[TCS_MAX_NUM_CC_RES];

} tTCS_CC_RESOURCES; 

/* Call Control Block */
typedef struct {
    BOOLEAN is_free;
    BOOLEAN call_responded; /* For bearer negotiation */

    UINT8  cc_state;   /* Current state of the state machine instance. */
    UINT8  bearer_inx; /* Index to the Bearer control block for the call. */
    UINT8  dev_inx;    /* CC-resource deviced index */
    UINT8  res_inx;    /* CC-resource ch resource index */
    UINT16 cc_hdl;

    tTCS_CC_PARSED_MSG  *p_msg;   /* Pointer to the data associated with current event. */

    tTCS_CC_ACT_OPTS saved_opts;  /*  Actions to be carried out after the bearer is set */

    TIMER_LIST_ENT cc_timer; /* Timer related to the call. */

} tTCS_CC_CTB;

/* Codes to track broadcasts */
enum {
    TCS_BCST_NULL,
    TCS_BCST_ACTIVE,
    TCS_BCST_COMPLETE,
    TCS_BCST_ABORTED
};

/* Broadcast Control Block */
typedef struct {
    BOOLEAN is_free;

    UINT8   bc_state;
    UINT8   link_type;
    UINT8   pkt_type;
    UINT16  res_inx[TCS_MAX_NUM_ACL_CONNS]; /* Stores the resource-inx for the device responded */
    UINT16  sco_inx[TCS_MAX_NUM_ACL_CONNS]; /* Stores inx bearer channel index */
    UINT32  dev_mask; /* Stores which devices responded */

    TIMER_LIST_ENT bc_timer; /* Timer related to the brodcast. */
} tTCS_BCST_CTB;

/* Storage for callbacks */
typedef struct {
    tTCS_CC_CB *cc_cback;
    tTCS_L2C_CBACKS l2c_cbacks;
    tTCS_PAGE_RESP_CB *page_resp_cback;
} tTCS_CC_REG_PARAMS;

/* To track SCO links */
enum {
    TCS_SCO_NULL,
    TCS_SCO_WAITING,
    TCS_SCO_UP,
    TCS_SCO_DISC
};

typedef struct
{
    UINT8  state;
    UINT8  pkt_type;
    UINT16 btm_inx;
} tTCS_SCO_INFO;

typedef struct
{
    UINT8  state;
    UINT16 cid;

    /* TODO - more elements may be required here */
} tTCS_ACL_INFO;

/* Bearer channel info */
typedef struct
{
    BD_ADDR bd_addr;
    union
    {
        tTCS_SCO_INFO sco;
        tTCS_ACL_INFO acl;
    } bearer ;
}tTCS_BEARER_INFO;

typedef struct {
    BOOLEAN is_free;

    UINT8   curr_use; /* One of NULL, CC or BCST */
    BOOLEAN num_calls; /* Number of calls using the bearer channel */
    UINT16  cc_handles[TCS_MAX_NUM_SIMUL_CALLS]; /* Store TCS_INVALID_CC_HANDLE for enmpty slots */
    UINT16  last_call_hdl;
    UINT16  bc_handle;

    tTCS_BC_LINK_TYPE link_type;
    tTCS_BEARER_INFO binf;
} tTCS_BEARER_RES;

typedef struct
{
    UINT32  cfg_sent_mask;
    TIMER_LIST_ENT tctp400;
} tTCS_WUG_MST_CFG_CTB;

typedef struct
{
    tTCS_WUG_MST_DB db ;
    tTCS_ACCESS_CBACK *ac_cb ;
} tTCS_WUG_MST_REG_PARAMS;

typedef struct
{
    UINT8 num_mmb;

    tTCS_WUG_MMB_DB   db;
    tTCS_WUGCFG_CBACK *cfg_cb;
    tTCS_FIMA_CBACK   *fima_cb;
} tTCS_WUG_MMB_REG_PARAMS;

typedef struct
{
    UINT8 role;
    UINT8 rem_id;
    TIMER_LIST_ENT t405;
} tTCS_WUG_MST_FIMA_CTB ;

typedef struct
{
    BOOLEAN is_free;
    UINT16  ch_id;
    BD_ADDR addr;

    TIMER_LIST_ENT t403;
    tTCS_WUG_MST_FIMA_CTB fima;
} tTCS_WUG_MST_RESOURCES[TCS_MAX_WUG_MEMBERS];


enum {
    TCS_WUG_FIMA_NONE,
    TCS_WUG_FIMA_SUGGESTED,
    TCS_WUG_FIMA_PAGER,
    TCS_WUG_FIMA_SCANNER
};

typedef struct
{
    UINT8    status;
    UINT8    mmb_inx;

    BOOLEAN  detach_flag;
    UINT16   clock_offset;

    tTCS_IE_BEARER_CAP *p_bc_ie;
    tTCS_IE_BEARER_CAP bc_ie;
    TIMER_LIST_ENT timer; /* t404, guard delay or t406 */
} tTCS_WUG_MMB_FIMA_CTB;

typedef struct
{
    BOOLEAN is_connected;
    UINT16  ch_id;
    BD_ADDR mbda;

    tTCS_ACCESS_RES_CBACK *acc_res_cb;
    TIMER_LIST_ENT t401;

    tTCS_WUG_MMB_FIMA_CTB fima;
} tTCS_WUG_MMB_CTB;

typedef struct
{
    UINT8                   msg_type;
    UINT32                  ie_present_bitmap;

    tTCS_IE_CALLED_NUM      called_num;
    UINT8                   cause;
    UINT16                  clock_offset;
    tTCS_IE_CO_SPEC         company_info;

} tTCS_WUG_PARSED_MSG;

/****************************************
** M A I N   C O N T R O L   B L O C K **
*****************************************/
typedef struct
{
    tTCS_CC_REG_PARAMS      cc_reg_params;     /* Storage for callbacks that are registered */
    tTCS_CC_CTB             cc_cbs[TCS_MAX_NUM_SIMUL_CALLS];
    tTCS_BEARER_RES         cc_bchs[TCS_MAX_NUM_SIMUL_CALLS];
    tTCS_CC_RESOURCES       cc_resources[TCS_MAX_NUM_ACL_CONNS];
    tTCS_CC_PARSED_MSG      cc_msg;         /* TCS message gets parsed in this structure */

#if TCS_BCST_SETUP_INCLUDED == TRUE
    tTCS_BCST_CTB           bc_cbs[TCS_MAX_NUM_SIMUL_CALLS]; /* Required only for a GW/Master app */
#endif

#if TCS_WUG_MASTER_INCLUDED == TRUE
    tTCS_WUG_MST_REG_PARAMS wug_mst_params;
    tTCS_WUG_MST_RESOURCES  wug_mst_resources;
    tTCS_WUG_MST_CFG_CTB    wug_mst_cb;
#endif

#if TCS_WUG_MEMBER_INCLUDED == TRUE
    tTCS_WUG_MMB_REG_PARAMS wug_mmb_params;
    tTCS_WUG_MMB_CTB        wug_mmb_cb ;
#endif
    tTCS_WUG_PARSED_MSG     wug_msg;

    UINT8                   trace_level;       /* Trace level */
    BOOLEAN                 is_wug_master;
#if TCS_WUG_MASTER_INCLUDED == TRUE
    tTCS_IE_CO_SPEC         *p_info_sug_co_spec_ie;
#endif
} tTCS_CB;


/* Global SDP data */
#if TCS_DYNAMIC_MEMORY == FALSE
TCS_API extern tTCS_CB  tcs_cb;
#else
TCS_API extern tTCS_CB *tcs_cb_ptr;
#define tcs_cb (*tcs_cb_ptr)
#endif

/* Functions exposed by tcs_cc_util.c
*/
extern void tcsu_init( void );

extern UINT8 tcsu_find_dev_res( BD_ADDR addr );
extern UINT8 tcsu_alloc_free_dev_res( void );
extern tTCS_STATUS tcsu_add_l2c_res( UINT8 res_inx, BD_ADDR addr, UINT16 l2cap_cid );
extern tTCS_STATUS tcsu_rem_l2c_res( UINT8 res_inx, UINT16 l2cap_cid );
extern tTCS_STATUS tcsu_assign_cc_res(BD_ADDR addr, UINT16 *res);
extern UINT16 tcsu_find_cc_hdl_by_cid (UINT16 l2cap_cid);
extern UINT16 tcsu_find_res_by_cid (UINT16 l2cap_cid);
extern void tcsu_release_cc_res(UINT16 cc_hdl);
extern UINT8 tcsu_find_sco_bch_from_addr( BD_ADDR addr );

extern UINT16 tcsu_alloc_ccsm_inst(void);
extern void tcsu_save_action_opts( UINT16 cc_handle, UINT8 pact, UINT8 data, tTCS_CALL_ACT_OPTS *p_acts, 
                            tTCS_IE_CO_SPEC *p_cs);
extern void tcsu_free_ccsm_inst( UINT16 cc_hdl );
extern UINT16 tcsu_init_call( UINT16 res, UINT8 state, UINT8 res_curr_use ) ;

extern UINT8 tcsu_alloc_free_bch( void ) ;
extern void  tcsu_free_bch( UINT8 binx ) ;
extern UINT8 tcsu_find_bch_from_sco_inx( UINT16 sco_inx );
extern UINT8 tcsu_find_bch_from_sco_handle( UINT8 hdl );
extern UINT8 tcsu_find_bch_from_addr( BD_ADDR addr ) ;
extern UINT8 tcsu_find_bch_from_handle( UINT8 type, UINT16 hdl ) ;
extern UINT8 tcsu_alloc_bcst_res( void ) ;
extern void  tcsu_free_bcst_res( UINT8 bc_hdl ) ;
extern UINT8 tcsu_find_unanswered_sco_act_bcst(BD_ADDR addr) ;
extern UINT8 tcsu_find_unanswered_act_bcst(UINT8 dinx);

extern void tcs_bc_start_timer( UINT16 bc_hdl, UINT8 timer ) ;
extern void tcs_bc_stop_timer( UINT16 bc_hdl ) ;
extern void tcs_cc_start_timer(UINT16 cc_hdl, UINT8 timer ) ;
extern void tcs_cc_stop_timer( UINT16 cc_hdl ) ;

#if (BT_TRACE_VERBOSE == TRUE)
extern char *tcsu_get_msg_name (UINT8 msg_id) ;
extern char *tcsu_get_state_name (UINT16 state) ;
extern char *tcsu_cc_sm_evt_name (UINT8 sm_event) ;
#else
#define tcsu_get_msg_name(ff)    ""
#define tcsu_get_state_name(ff)    ""
#define tcsu_cc_sm_evt_name(ff)    ""
#endif

extern BOOLEAN tcsu_cc_check_dev_busy(BD_ADDR addr);

/* Functions exposed by tcs_l2c.c
*/
extern void tcsl_init (void);
extern tTCS_STATUS tcsl_send_msg( UINT16 cc_handle, BT_HDR *pmsg );


/* Functions exposed by tcs_cc_sm.c
*/
extern void         tcss_cc_handle_event(tTCS_CC_CTB *cb, UINT8 event, tTCS_CC_PARSED_MSG *msg);
extern tTCS_STATUS  tcss_proceed_on_incoming_call(UINT16 cc_handle, 
                                  UINT8 proceed_code, 
                                  tTCS_CALL_ACT_OPTS *action_info, 
                                  tTCS_IE_CO_SPEC *p_cs) ;
extern void         tcss_proc_bcst_resp( UINT16 res, UINT16 bc_hdl, UINT16 event, tTCS_CC_PARSED_MSG *msg ) ;
extern void         tcss_check_if_bcst_resp( UINT8 event, tTCS_CC_PARSED_MSG *cc_msg, UINT16 res ) ;
extern void         tcs_process_timeout( TIMER_LIST_ENT *p_tle ) ;
extern tTCS_STATUS  tcss_send_connect_ack( UINT16 cc_handle, tTCS_IE_CO_SPEC *p_cs ) ;
extern void         tcss_proc_dtmf( UINT16 cc_handle, UINT8 event, tTCS_CC_PARSED_MSG *p_msg ) ;

/* Functions exposed by tcs_cc_msg.c
*/
extern BT_HDR *tcsm_encode_cc_message( UINT8 msg_code );
extern void tcsm_add_info_elem(UINT8 ie_code, void *data, BT_HDR *p_buf );
extern void tcsm_cc_process_peer_msg (UINT16 res, BT_HDR *p_msg);
extern BOOLEAN tcsm_parse_msg (UINT8 msg_id, UINT8 *p, UINT16 len);
extern void tcsm_init_ie_storage (void) ;


/* Functions exposed by tcs_utils.c
*/

extern void tcsu_unsave_opts( tTCS_CC_CTB *cb );


extern void tcsb_init( void );
extern tTCS_STATUS tcsb_setup_bearer( UINT16 cc_handle, tTCS_IE_BEARER_CAP bearer_cap_ie );
extern void tcsb_associate_bearer( tTCS_CC_CTB *cb, tTCS_BEARER_ID bearer_id );
extern void tcsb_release_bearer(UINT16 cc_handle);
extern void tcsb_get_bearer( tTCS_CC_CTB *cb, tTCS_BEARER_ID *bearer );
extern tTCS_STATUS tcsb_check_sco_params( UINT8 pkt_type, tTCS_BC_LINK_TYPE link_type );

extern void tcs_wug_process_timeout( TIMER_LIST_ENT *p_tle ) ;
extern BOOLEAN tcs_wug_send_access_reply( UINT16 ch_id, BOOLEAN result, tTCS_IE_CO_SPEC *p_cs );
extern BOOLEAN tcs_wug_send_listen_sug (UINT16 ch_id, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_send_listen_rej (UINT16 ch_id, UINT8 cause, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_send_info_sug (UINT16 ch_id, UINT8 minx, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_parse_msg (UINT8 msg_id, BT_HDR *p_msg);
extern BOOLEAN tcs_wug_send_access_req( tTCS_IE_CO_SPEC *p_cs );
extern BOOLEAN tcs_wug_send_listen_req (tTCS_WUG_MMB_EXTN extn, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_send_listen_reply (BOOLEAN result, UINT16 clk_offset, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_send_info_acpt( tTCS_IE_CO_SPEC *p_cs );
extern BOOLEAN tcs_wug_send_listen_acpt_ack (UINT16 ch_id, tTCS_IE_CO_SPEC *p_cs);
extern BOOLEAN tcs_wug_fwd_listen_rep (UINT16 ch_id, UINT8 msg_id, UINT16 clk_offset, tTCS_IE_CO_SPEC *p_cs);

extern void tcs_wug_gen_link_key (LINK_KEY key, BD_ADDR addr);
extern UINT8 tcs_wug_get_mmb_inx_from_addr( BD_ADDR mmb_addr );
extern UINT8 tcs_wug_get_res_inx_from_addr( BD_ADDR mmb_addr );
extern void tcs_wug_init_conf_dist( void );

extern UINT8 tcs_wug_get_mmb_from_extn( tTCS_WUG_MMB_EXTN extn );
extern void tcs_wug_mst_proc_gm_msg( UINT16 ch_id, BT_HDR *pmsg );
extern void tcs_wug_mmb_proc_gm_msg( UINT16 ch_id, BT_HDR *pmsg );
extern void tcs_wug_mkey_comp_cback( BD_ADDR addr, UINT8 status, UINT8 key_flag );

extern void l2c_bcst_msg( BT_HDR *p_buf, UINT16 psm ) ;

#endif
