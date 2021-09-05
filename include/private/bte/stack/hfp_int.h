/*****************************************************************************
** 
**    File Name:   hfp_int.h
**
**  Description:   This file contains the HFP Profile's internal interface.
**
**
**  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HFP_INT_H
#define HFP_INT_H

#include <private/bte/stack/hfp_api.h>
#include <private/bte/stack/hsp2_fsm.h>
#include <private/bte/stack/hsp2_int.h>
#include <private/bte/gki.h>

#define tHFP_CB     tHSP2_CB    /* HFP uses the HSP2 control block type */

#ifdef __cplusplus
extern "C"
{
#endif

#if HFP_DYNAMIC_MEMORY == FALSE
HFP_API extern tHFP_CB  hfp_hcb;
#else
HFP_API extern tHFP_CB *hfp_hcb_ptr;
#define hfp_hcb (*hfp_hcb_ptr)
#endif

/* HFP external function declarations */
extern void hfp_sco_connect_callbk(UINT16 sco_inx);
extern void hfp_sco_disconnect_callbk(UINT16 sco_inx);
extern tHSP2_STATUS hfp_add_support_attr_id(UINT32 handle);
extern void hfp_process_peer_command_base(UINT8 index,
                                          BOOLEAN at_cmd,
                                          tHSP2_AT_QUERY_TYPE qtype,
                                          char *value);
extern const char hfp_init_at_cmds[][24];
#ifdef __cplusplus
}
#endif

extern void hfp_init_hsp2( void );
extern tHSP2_STATUS hfp_send_call_status_ind( BOOLEAN active );
extern void hfp_process_peer_command(UINT8 index, BOOLEAN at_cmd, tHSP2_AT_QUERY_TYPE qtype, 
                                     char *value, tHFP_CB *p_hcb);    
extern void hfp_rfc_mgmt_cb(UINT32 port_status, UINT16 port_handle);
extern void hfp_rfc_port_cback(UINT32 event, UINT16 port_handle);
extern void hfp_sdp_cback(UINT16 sdp_status);
extern void hfp_inquiry_cback(UINT16 event, void *p);
extern void hfp_send_ok( tHFP_CB *p_hcb );
extern void hfp_send_error( tHFP_CB *p_hcb ) ;

extern tHSP2_STATUS hfp_init_at_connection(tHFP_CB *p_hcb) ;
extern tHSP2_STATUS hfp_post_sco_action(tHFP_CB *p_hcb);
extern tHSP2_STATUS hfp_send_clip_action(tHFP_CB *p_hcb);
extern tHSP2_STATUS hfp_sdp_result_action(tHFP_CB *p_hcb);

#if HFP_AG_INCLUDED == TRUE
#if HFP_HF_INCLUDED == TRUE

#define HFP_LOCAL_UUID        ((UINT16) (((hfp_hcb.role == HFP_ROLE_IS_HF)||(hfp_hcb.role == HFP_ROLE_IS_HF15)) ? UUID_SERVCLASS_HF_HANDSFREE : UUID_SERVCLASS_AG_HANDSFREE))
#define HFP_PEER_UUID         ((UINT16) (((hfp_hcb.role == HFP_ROLE_IS_HF)||(hfp_hcb.role == HFP_ROLE_IS_HF15)) ? UUID_SERVCLASS_AG_HANDSFREE : UUID_SERVCLASS_HF_HANDSFREE))
#define HFP_DEFAULT_NAME      ((char *) (((hfp_hcb.role == HFP_ROLE_IS_HF)||(hfp_hcb.role == HFP_ROLE_IS_HF15)) ? HFP_HF_DEFAULT_NAME : HFP_AG_DEFAULT_NAME ) )
#define HFP_SEC_SERVICE       ((UINT8) (((hfp_hcb.role == HFP_ROLE_IS_HF)||(hfp_hcb.role == HFP_ROLE_IS_HF15)) ? BTM_SEC_SERVICE_HF_HANDSFREE : BTM_SEC_SERVICE_AG_HANDSFREE))
#define HFP_SEC_PEER_SERVICE  ((UINT8) (((hfp_hcb.role == HFP_ROLE_IS_HF)||(hfp_hcb.role == HFP_ROLE_IS_HF15)) ? BTM_SEC_SERVICE_AG_HANDSFREE : BTM_SEC_SERVICE_HF_HANDSFREE))

#else  /* HFP_HF_INCLUDED */ 

/***************************** Only AG included ******************************/

#define HFP_LOCAL_UUID        ((UINT16) (UUID_SERVCLASS_AG_HANDSFREE))
#define HFP_PEER_UUID         ((UINT16) (UUID_SERVCLASS_HF_HANDSFREE))
#define HFP_DEFAULT_NAME      ((char *) (HFP_AG_DEFAULT_NAME))
#define HFP_SEC_SERVICE       ((UINT8) (BTM_SEC_SERVICE_AG_HANDSFREE))
#define HFP_SEC_PEER_SERVICE  ((UINT8) (BTM_SEC_SERVICE_HF_HANDSFREE))

#endif /* HFP_HF_INCLUDED */
#else  /* HFP_AG_INCLUDED */

/****************************** Only HS included *****************************/

#define HFP_LOCAL_UUID        ((UINT16) (UUID_SERVCLASS_HF_HANDSFREE))
#define HFP_PEER_UUID         ((UINT16) (UUID_SERVCLASS_AG_HANDSFREE))
#define HFP_DEFAULT_NAME      ((char *) (HFP_HF_DEFAULT_NAME))
#define HFP_SEC_SERVICE       ((UINT8) (BTM_SEC_SERVICE_HF_HANDSFREE))
#define HFP_SEC_PEER_SERVICE  ((UINT8) (BTM_SEC_SERVICE_AG_HANDSFREE))

#endif /* HFP_AG_INCLUDED */

#endif /* HFP_INT_H */

