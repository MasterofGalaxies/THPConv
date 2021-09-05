/******************************************************************************
**
**   File Name:  hcrp_fsm.h
**
** Description:  This file contains definitions used by the HCRP Client State
**               Machine.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/
#ifndef HCRP_FSM_H
#define HCRP_FSM_H

#include <private/bte/common/target.h>

/* Main FSM States */
enum
{
    /* Common State */
    HCRP_CFSM_OFF_ST = 0,

    /* Client States */
    HCRP_CFSM_IDLE_ST,
    HCRP_CFSM_W4_CCHAN_ST,
    HCRP_CFSM_W4_DCHAN_ST,
    HCRP_CFSM_OPEN_ST,
    HCRP_CFSM_W4_CLOSE_ST
};
typedef UINT8 tHCRP_CFSM_STATE;


/* Main FSM Events */
enum
{
    HCRP_CFSM_NULL_EVT = 0,         /* Ignored events are redirected to null event  */
    HCRP_CFSM_REG_CLIENT_API_EVT,   /* Sent by API to register HCRP                 */
    HCRP_CFSM_DEREGISTER_API_EVT,   /* Sent by API to deregister HCRP               */
    HCRP_CFSM_SEND_DATA_API_EVT,    /* Sent by HCRP_SendData API function to
                                       send data to the client/server               */
    HCRP_CFSM_RCV_DATA_EVT,         /* Sent by GAP callback when data is received   */
    HCRP_CFSM_RCV_READY_API_EVT,    /* Sent by HCRP_RcvReady API to update credits  */
    HCRP_CFSM_RCV_RSP_EVT,          /* Received a peer command/response on the
                                       control channel. This event handles the
                                       credit, vendor specific, LPT status, 1284ID,
                                       notification registration, and hard/soft
                                       reset command/response events.               */
    HCRP_CFSM_DATA_CHAN_OPN_EVT,    /* Sent by GAP cback when data channel is open  */
    HCRP_CFSM_CTRL_CHAN_OPN_EVT,    /* Sent by GAP cback when ctrl channel is open  */
    HCRP_CFSM_GAP_CHAN_CLS_EVT,     /* Sent by GAP cback if data, ctrl chan is clsd */
    HCRP_CFSM_CLOSING_TOUT_EVT,     /* Internal timer expiration in the
                                       HCRP_CFSM_W4_CLOSE_ST or
                                       HCRP_SFSM_W4_CLOSE_ST state                  */
    HCRP_CFSM_DATA_CONGESTED_EVT,   /* Data Channel is congested                    */
    HCRP_CFSM_PROTO_CMD_API_EVT,    /* Sent by HCRP_SendProtoCmd() API to send a
                                       protocol command to
                                       state machine (Refer to commands listed in
                                       the HCRP specification)                      */
    HCRP_CFSM_FIND_SERV_API_EVT,    /* Sent by API function to initiate an SDP
                                       service search for a specified function
                                       (printer, scanner, dot4, etc.)               */
    HCRP_CFSM_SDP_CMPL_EVT,         /* Sent when SDP control or data channel
                                       search completes                             */
    HCRP_CFSM_EST_CONN_API_EVT,     /* Sent by API to initiate opening of HCRP chans*/
    HCRP_CFSM_REL_CONN_API_EVT,     /* Sent by API to release the HCRP channels     */
    HCRP_CFSM_PROTO_TOUT_EVT        /* Response to a command is not received (tout) */

    /* Notification Substate Events (server) */
#if HCRP_NOTIFICATION_INCLUDED == TRUE
    /* Need a comma to complete the table syntax -> */ ,
    HCRP_CFSM_NOTIF_EVT,            /* Sent by GAP cback for notification event     */
    HCRP_CFSM_NOTIF_OPEN_EVT,       /* Sent by GAP cback when notif channel is open */
    HCRP_CFSM_NOTIF_CLOSE_IND_EVT   /* Sent by GAP cback when the notification
                                       channel has been closed                      */
#endif
};
typedef UINT8 tHCRP_CFSM_EVT;

#if HCRP_FSM_DEBUG == TRUE
extern const char * const hcrp_status_str[];
/* Prints out the string associated with the return status */
#define HCRPSTATUS(x)    (((x) == HCRP_SUCCESS) ? "HCRP_SUCCESS" : hcrp_status_str[(x) - HCRP_ERR_GRP])
#endif

#endif /* HCRP_FSM_H */

