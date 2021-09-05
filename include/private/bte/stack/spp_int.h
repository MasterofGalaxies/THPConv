/*****************************************************************************/
/*                                                                           */
/*  Name:          spp_int.h                                                 */
/*                                                                           */
/*  Description:   this file contains the SPP API internal interface         */
/*                 definitions.                                              */
/*                                                                           */
/*  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.              */
/*  WIDCOMM Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/
#ifndef SPP_INT_H
#define SPP_INT_H

#include <private/bte/stack/spp_api.h>
#include <private/bte/stack/btm_int.h>
#include <private/bte/stack/l2c_api.h>
#include <private/bte/stack/rfcdefs.h>

/*** Size of the header information for serial data (the extra byte is for a one-byte RFCOMM trailer) ***/
#define SPP_HEADER_SIZE     (L2CAP_MIN_OFFSET + RFCOMM_MIN_OFFSET + 1)

#define SPP_MAX_CHANNELS        MAX_PORTS       /* No use opening any more ports than RFCOMM */
#define SPP_MAX_PORT_NAME_LEN   33              /* Maximum length of the local port name */

#define SPP_NUM_PROTO_ELEMS 2                   /* Number of protocol elements for serial service */


/*** SPP States ***/
typedef enum
{
    SPP_IDLE_STATE = 0,         /* Initial state (channel is unused) */
    SPP_CONNECTED_STATE,        /* Channel is connected and active */
    SPP_LISTENING_STATE,        /* Server is active but not connected to a peer */
    SPP_FINDING_SCN_STATE       /* Client is searching for the Server Channel Number */
} tspp_state;
typedef UINT8   tSPP_STATE;

/* Define the Serial Port Profile control structure */
typedef struct
{
    tSPP_CALLBACK   *spp_cback;     /* Pointer to users connection status callback function */
    tPORT_CALLBACK  *port_cback;    /* Application's callback for PORT events */
    UINT32           sdp_handle;    /* Record handle in SDP server */
    TIMER_LIST_ENT   retry_tle;     /* Timer entry used for a Client that is trying to (re)connect to a service */
    tSPP_CONN_INFO   conn_info;     /* information and state of a particular connection */
    tBT_SECURITY     security;      /* Security requirements */
    UINT32           event_mask;    /* The events that the upper layer wishes to receive from PORT */
    UINT16           mtu;           /* Frame size to pass to RFCOMM */
    char             port_name[SPP_MAX_PORT_NAME_LEN];  /* Local port name used for accessing the generic connection */
    BOOLEAN          in_use;        /* True when control block is allocated */
    BOOLEAN          is_server;     /* TRUE if server, FALSE if client */
    UINT8            scn;           /* Service channel number */
    tSPP_STATE       state;         /* Current state that a channel is in */
    BOOLEAN          discovering;   /* TRUE, if inquiry/discovering is in progress, FALSE, otherwise */
} tSPP_INFO;

/* Defines the discovery information; Only one Search can occur at a time! */
typedef struct
{
    tSPP_INFO           *p_disc_cb; /* Pointer to the control block of the active discovery */
    tSDP_DISCOVERY_DB   *p_sdp_db;  /* Pointer to the discovery database */
    tGAP_INQ_RESULTS    *p_inq_db;  /* Pointer to the inquiry results database */
    UINT8                num_results; /* Number of results saved */
    UINT8                cur_inq_index; /* Index into current device being saved or retrieved */
} tSPP_DISCOVERY;

typedef struct
{
    tSPP_DISCOVERY   disc;              /* Discovery Database (Only one is active at a time */
    tSPP_INFO        info[SPP_MAX_CHANNELS];
    UINT8            trace_level;
} tSPP_CB;


#ifdef __cplusplus
extern "C"
{
#endif

#if SPP_DYNAMIC_MEMORY == FALSE
SPP_API extern tSPP_CB  spp_cb;
#else
SPP_API extern tSPP_CB *spp_cb_ptr;
#define spp_cb (*spp_cb_ptr)
#endif

extern tSPP_INFO        *spp_find_channel(const char *port_name);
extern void              spp_free_cb (tSPP_INFO *p_cb);
extern tSPP_INFO        *spp_allocate_cb (void);
extern void              spp_port_cback(UINT32 event, UINT16 port_handle);
extern tSPP_STATUS       spp_does_service_exist(const char *port_name, const char *service_name);
extern void              spp_setup_port (tSPP_INFO *p_cb);
extern tSPP_STATUS       spp_close_port(tSPP_INFO *p_cb);
extern void              spp_remove_port(tSPP_INFO *p_cb);
extern BOOLEAN           spp_is_only_service(tSPP_INFO *p_cb);
extern tSPP_STATUS       spp_register_service(tSPP_INFO *p_cb);
extern tSPP_STATUS       spp_call_create_connection (tSPP_INFO *p_cb);
extern tSPP_INFO        *spp_find_porthndl_cb (UINT16 port_handle);
extern tSPP_STATUS       spp_verify_security_params (tBT_SECURITY *p_security);
extern tSPP_STATUS       spp_find_scn(tSPP_INFO *p_cb);
extern void              spp_process_timeout (TIMER_LIST_ENT  *p_tle);
extern void              spp_process_connect_retry (tSPP_INFO *p_cb);
extern void              spp_start_retry_timer (tSPP_INFO *p_cb);
extern void              spp_stop_retry_timer (tSPP_INFO *p_cb);

/*** Discovery routines ***/
extern tSPP_STATUS       spp_alloc_disc_dbs (tSPP_INFO *p_cb);
extern void              spp_free_disc_dbs (tSPP_INFO *p_cb);
extern tSPP_STATUS       spp_initiate_discovery (tSPP_INFO *p_cb);
extern void              spp_init_disc_dbs (void);
extern void              spp_inq_cback(UINT16 event, void *p);
extern void              spp_sdp_cback(UINT16 status);

#ifdef __cplusplus
}
#endif


#if (BT_USE_TRACES == TRUE)
#define SPP_TRACE_SECURITY(p_security)      spp_print_security((p_security));
#else   /* BT_USE_TRACES */
#define SPP_TRACE_SECURITY(p_security)
#endif  /* BT_USE_TRACES */

#endif
