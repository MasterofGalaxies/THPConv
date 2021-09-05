/*****************************************************************************/
/*                                                                           */
/*  Name:          l2c_int.h                                                 */
/*                                                                           */
/*  Description:   this file contains L2CAP internal definitions             */
/*                                                                           */
/*  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.              */
/*  WIDCOMM Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/
#ifndef L2C_INT_H
#define L2C_INT_H

#include <private/bte/stack/l2c_api.h>
#include <private/bte/gki.h>

#define L2CAP_MIN_MTU   48      /* Minimum acceptable MTU is 48 bytes */


/* Timeouts. Since L2CAP works off a 1-second list, all are in seconds.
*/
#define L2CAP_LINK_ROLE_SWITCH_TOUT  10           /* 10 seconds */
#define L2CAP_LINK_CONNECT_TOUT      60           /* 30 seconds */
#define L2CAP_LINK_CONNECT_TOUT_EXT  120          /* 120 seconds */
#define L2CAP_ECHO_RSP_TOUT          30           /* 30 seconds */
#define L2CAP_LINK_FLOW_CONTROL_TOUT 2            /* 2  seconds */
#define L2CAP_LINK_DISCONNECT_TOUT   30           /* 30 seconds */
#define L2CAP_CHNL_CONNECT_TOUT      60           /* 60 seconds */
#define L2CAP_CHNL_CONNECT_TOUT_EXT  120          /* 120 seconds */
#define L2CAP_CHNL_CFG_TIMEOUT       30           /* 30 seconds */
#define L2CAP_CHNL_DISCONNECT_TOUT   30           /* 30 seconds */
#define L2CAP_WAIT_UNPARK_TOUT       1            /* 1 seconds */



/* Define the possible L2CAP channel states. The names of
** the states may seem a bit strange, but they are taken from
** the Bluetooth specification.
*/
typedef enum
{
    CST_CLOSED,                           /* Channel is in clodes state           */
    CST_ORIG_W4_SEC_COMP,                 /* Originator waits security clearence  */
    CST_TERM_W4_SEC_COMP,                 /* Acceptor waits security clearence    */
    CST_W4_L2CAP_CONNECT_RSP,             /* Waiting for peer conenct response    */
    CST_W4_L2CA_CONNECT_RSP,              /* Waiting for upper layer connect rsp  */
    CST_CONFIG,                           /* Negotiating configuration            */
    CST_OPEN,                             /* Data transfer state                  */
    CST_W4_L2CAP_DISCONNECT_RSP,          /* Waiting for peer disconnect rsp      */
    CST_W4_L2CA_DISCONNECT_RSP            /* Waiting for upper layer disc rsp     */
} tL2C_CHNL_STATE;

/* Define the possible L2CAP link states
*/
typedef enum
{
    LST_DISCONNECTED,
    LST_CONNECT_HOLDING,
    LST_CONNECTING_WAIT_SWITCH,
    LST_CONNECTING,
    LST_CONNECTED,
    LST_DISCONNECTING
} tL2C_LINK_STATE;



/* Define input events to the L2CAP link and channel state machines. The names
** of the events may seem a bit strange, but they are taken from
** the Bluetooth specification.
*/
#define L2CEVT_LP_CONNECT_CFM          0          /* Lower layer connect confirm          */
#define L2CEVT_LP_CONNECT_CFM_NEG      1          /* Lower layer connect confirm (failed) */
#define L2CEVT_LP_CONNECT_IND          2          /* Lower layer connect indication       */
#define L2CEVT_LP_DISCONNECT_IND       3          /* Lower layer disconnect indication    */
#define L2CEVT_LP_QOS_CFM              4          /* Lower layer QOS confirmation         */
#define L2CEVT_LP_QOS_CFM_NEG          5          /* Lower layer QOS confirmation (failed)*/
#define L2CEVT_LP_QOS_VIOLATION_IND    6          /* Lower layer QOS violation indication */

#define L2CEVT_SEC_COMP                7          /* Security cleared successfully        */
#define L2CEVT_SEC_COMP_NEG            8          /* Security procedure failed            */

#define L2CEVT_L2CAP_CONNECT_REQ      10          /* Peer connection request              */
#define L2CEVT_L2CAP_CONNECT_RSP      11          /* Peer connection response             */
#define L2CEVT_L2CAP_CONNECT_RSP_PND  12          /* Peer connection response pending     */
#define L2CEVT_L2CAP_CONNECT_RSP_NEG  13          /* Peer connection response (failed)    */
#define L2CEVT_L2CAP_CONFIG_REQ       14          /* Peer configuration request           */
#define L2CEVT_L2CAP_CONFIG_RSP       15          /* Peer configuration response          */
#define L2CEVT_L2CAP_CONFIG_RSP_NEG   16          /* Peer configuration response (failed) */
#define L2CEVT_L2CAP_DISCONNECT_REQ   17          /* Peer disconnect request              */
#define L2CEVT_L2CAP_DISCONNECT_RSP   18          /* Peer disconnect response             */
#define L2CEVT_L2CAP_DATA             19          /* Peer data                            */

#define L2CEVT_L2CA_CONNECT_REQ       20          /* Upper layer connect request          */
#define L2CEVT_L2CA_CONNECT_RSP       21          /* Upper layer connect response         */
#define L2CEVT_L2CA_CONNECT_RSP_NEG   22          /* Upper layer connect response (failed)*/
#define L2CEVT_L2CA_CONFIG_REQ        23          /* Upper layer config request           */
#define L2CEVT_L2CA_CONFIG_RSP        24          /* Upper layer config response          */
#define L2CEVT_L2CA_CONFIG_RSP_NEG    25          /* Upper layer config response (failed) */
#define L2CEVT_L2CA_DISCONNECT_REQ    26          /* Upper layer disconnect request       */
#define L2CEVT_L2CA_DISCONNECT_RSP    27          /* Upper layer disconnect response      */
#define L2CEVT_L2CA_DATA_READ         28          /* Upper layer data read                */
#define L2CEVT_L2CA_DATA_WRITE        29          /* Upper layer data write               */

#define L2CEVT_TIMEOUT                30          /* Timeout                              */

#define L2CAP_COMPRESSION_OUTPUT      0
#define L2CAP_COMPRESSION_INPUT       1
#define L2CAP_COMPRESSION_BIDIRECTION 2

#if (L2CAP_FCR_INCLUDED == TRUE)
#define L2CAP_FCR_OVERHEAD         2   /* */
#define L2CAP_FCS_LEN              2   /* FCS takes 2 bytes */
#define L2CAP_SDU_LEN_OVERHEAD     2   /* SDU length field is 2 bytes */
#define L2CAP_SDU_LEN_OFFSET       2   /* SDU length offset is 2 bytes */

/* Part of L2CAP_MIN_OFFSET that is not part of L2CAP */  
#define L2CAP_OFFSET_WO_L2HDR  (L2CAP_MIN_OFFSET-(L2CAP_PKT_OVERHEAD+L2CAP_FCR_OVERHEAD))

#define L2CAP_FCR_UNSEG_SDU    0x0000   /* Control word to begin with for unsegmented PDU*/
#define L2CAP_FCR_START_SDU    0x4000   /* ...for Starting PDU of a semented SDU */
#define L2CAP_FCR_END_SDU      0x8000   /* ...for ending PDU of a segmented SDU */
#define L2CAP_FCR_CONT_SDU     0xc000   /* ...for continuation PDU of a segmented SDU */
#define L2CAP_FCR_RR_FRAME     0x0001   /* Control word to begin with for an RR S-frame */
#define L2CAP_FCR_REJ_FRAME    0x0005   /* ...for REJ S-frame */

#define L2CAP_FCR_S_FRAME_BIT         0x0001   /* Mask to check if a PDU is S-frame */
#define L2CAP_FCR_REQ_SEQ_BITS        0x3F00   /* Mask to get the req-seq from control word */
#define L2CAP_FCR_REQ_SEQ_BITS_OFFSET 8        /* Bits to shift right to get the req-seq from ctrl-word */
#define L2CAP_FCR_TX_SEQ_BITS         0x007E   /* Mask on get the tx-seq from control word */
#define L2CAP_FCR_TX_SEQ_BITS_OFFSET  1        /* Bits to shift right to get the tx-seq from ctrl-word */
#define L2CAP_FCR_RDB_BIT             0x0080   /* Mask to check the RDB in control word */
#define L2CAP_FCR_RDB_BIT_OFFSET      7        /* Bits to shift right to get the rdb from ctrl-word */
#define L2CAP_FCR_SEG_BITS            0xC000   /* Mask to get the segmentation bits from ctrl-word */
#define L2CAP_FCR_S_BIT_OFFSET        2        /* Bits to shift right to get the S-bits from ctrl-word */
#define L2CAP_FCR_S_BITS              0x000C   /* Mask to get the supervisory bits from ctrl-word */

#define L2CAP_FCR_SIZEOF_LEN_FIELD    2   /* Size of the length field in an I-frame */
#define L2CAP_FCR_INIT_CRC            0   /* Initial state of the CRC register */

#define L2CAP_RTRANS_I_FRAME_BIT      0x0100


enum
{
    L2C_FCR_EVT_RX_GOOD_S_FRAME,
    L2C_FCR_EVT_RX_GOOD_I_FRAME,
    L2C_FCR_EVT_TX_SCHEDULED,
    L2C_FCR_EVT_RTRANS_REQ,
    L2C_FCR_EVT_RDB_ON,
    L2C_FCR_EVT_RDB_OFF,
    L2C_FCR_EVT_TIMER_EXP  
};

enum
{
    L2C_FCR_TX_ST_NULL,
    L2C_FCR_TX_ST_NULL_RDB_ON,
    L2C_FCR_TX_ST_AWAIT_ACK_RDB_OFF_RTRANS,
    L2C_FCR_TX_ST_AWAIT_ACK_RDB_ON_RTRANS,
    L2C_FCR_TX_ST_AWAIT_ACK_FC
};

typedef struct
{
    UINT8     state;

    UINT8     tx_seq;
    UINT8     next_tx_seq;
    UINT8     expected_ack_seq;
    UINT8     req_seq;
    UINT8     expected_tx_seq;
    UINT8     buff_seq;
    UINT8     num_tries;
    UINT8     yet_to_ack;
    UINT8     remaining_tx_window;

    UINT16   to_be_rxed_sdu_len;
    BT_HDR   *to_be_rxed;
    BOOLEAN   rx_rdb;
    BOOLEAN   tx_rdb;
    BOOLEAN   rej_exception;
    BUFFER_Q  waiting_for_ack_q;

} tL2C_FCRB;

#endif

/* Define a registration control block. Every application (e.g. RFCOMM, SDP,
** TCS etc) that registers with L2CAP is assigned one of these.
*/
typedef struct
{
    BOOLEAN             in_use;
    UINT16              psm;
    tL2CAP_APPL_INFO    api;
#if (L2CAP_FCR_INCLUDED == TRUE)
    UINT32              ext_fea_mask;
#endif
} tL2C_RCB;

/* Define a channel control block (CCB). There may be many channel control blocks
** between the same two Bluetooth devices (i.e. on the same link). 
** Each CCB has unique local and remote CIDs. All channel control blocks on
** the same physical link and are chained together.
*/
typedef struct t_l2c_ccb
{
    BOOLEAN             in_use;                 /* TRUE when in use, FALSE when not */
    tL2C_CHNL_STATE     chnl_state;             /* Channel state                    */

    struct t_l2c_ccb    *p_next_ccb;            /* Next CCB in the chain            */
    struct t_l2c_ccb    *p_prev_ccb;            /* Previous CCB in the chain        */

    struct t_l2c_linkcb *p_lcb;                 /* Link this CCB is assigned to     */

    UINT16              local_cid;              /* Local CID                        */
    UINT16              remote_cid;             /* Remote CID                       */

    TIMER_LIST_ENT      timer_entry;            /* CCB Timer List Entry             */

    tL2C_RCB            *p_rcb;                 /* Registration CB for this Channel */

#define IB_CFG_DONE     0x01
#define OB_CFG_DONE     0x02

    UINT8               config_done;            /* Configuration flag word         */
    UINT8               local_id;               /* Transaction ID for local trans  */
    UINT8               remote_id;              /* Transaction ID for local  */
    BOOLEAN             rtry_flag;

    UINT16              in_mtu;                 /* Max MTU we will accept           */
    UINT16              out_mtu;                /* Max MTU we will send             */
    UINT16              our_flush_to;           /* Our flush timeout                */
    FLOW_SPEC           in_flow;                /* Flow spec for rcvd data          */
    FLOW_SPEC           out_flow;               /* Flow spec for xmit data          */
    BUFFER_Q            xmit_hold_q;            /* Transmit data hold queue         */
#if (L2CAP_FCR_INCLUDED == TRUE)
    UINT16              cur_priority;
    UINT16              init_priority;
    tL2CAP_FCR_OPTS     in_fcr;
    tL2CAP_FCR_OPTS     out_fcr;
    tL2C_FCRB           fcrb;
    BT_HDR              *to_be_txed;
    UINT16              cong_param;                     /* Queue limit to start congestion  */
    UINT16              cong_start;                     /* Queue limit to start congestion  */
    UINT16              cong_end;                       /* Queue limit to end congestion    */
    UINT16              cong_discard;                   /* Queue limit discard buffers      */

    BOOLEAN             cong_sent;              /* Set when congested status sent   */
    BUFFER_Q            xmit_data_q;            /* Transmit data buffer queue       */
#endif
#if (L2CAP_ENHANCED_FEATURES & L2CAP_COMPRESSION)
    BOOLEAN             compression_setup_in_process;
    BOOLEAN             compression_enable;     /* Compression enable or not */
    UINT8               compression_direction;  /* Compression direction, 
                                                   0 client to server, 1 server to client, 2 bidirection */
    UINT8               pe_type;
    UINT8               mem_level;
    UINT8               wbits;
    tL2CA_SETCOMPRESSION_CBACK *p_set_comp_cb;  /* Client set compression callback */
#endif
} tL2C_CCB;

/* Define a link control block. There is one link control block between
** this device and any other device (i.e. BD ADDR). 
*/
typedef struct t_l2c_linkcb
{
    BOOLEAN             in_use;                     /* TRUE when in use, FALSE when not */
    tL2C_LINK_STATE     link_state;

    tL2C_CCB            *p_first_ccb;               /* The first channel on this link   */
    tL2C_CCB            *p_last_ccb;                /* The last  channel on this link   */

    TIMER_LIST_ENT      timer_entry;                /* Timer list entry for timeout evt */

    UINT16              handle;                     /* The handle used with LM          */
    BD_ADDR             remote_bd_addr;             /* The BD address of the remote     */

    UINT8               link_role;                  /* Master or slave                  */
    UINT8               id;

    UINT16              link_flush_tout;            /* Flush timeout used               */
    UINT16              link_xmit_quota;            /* Num outstanding pkts allowed     */
    UINT16              link_xmit_window;           /* Num we can transmit without ack  */
    UINT16              sent_not_acked;             /* Num packets sent but not acked   */
    UINT16              link_cong_start;            /* Queue limit to start congestion  */
    UINT16              link_cong_end;              /* Queue limit to end congestion    */
    UINT16              link_cong_discard;          /* Queue limit discard buffers      */
    BOOLEAN             partial_segment_being_sent; /* Set TRUE when a partial segment  */
                                                    /* is being sent.                   */
#if (L2CAP_FCR_INCLUDED == TRUE)
    UINT8               remote_fcr_support;         /* Remote device's support for FCR  */
    BOOLEAN             w4_info_rsp;                /* TRUE when info request is active */
    BT_HDR              *partial_segment;
    BUFFER_Q            sig_ch_xmit_data_q;         /* Transmit data for signaling channel*/
#else
    BOOLEAN             cong_sent;
    BUFFER_Q            link_xmit_data_q;
#endif

#if (L2CAP_HOST_FLOW_CTRL == TRUE)
    UINT16              link_pkts_unacked;          /* Packets received but not acked   */
    UINT16              link_ack_thresh;            /* Threshold at which to ack pkts   */
#endif

    BT_HDR              *p_hcit_rcv_acl;            /* Current HCIT ACL buf being rcvd  */
    tL2CA_ECHO_RSP_CB   *p_echo_rsp_cb;             /* Echo response callback           */

    UINT16              idle_timeout;               /* Idle timeout                     */
    UINT8               acl_priority;               /* L2C_PRIORITY_NORMAL or L2C_PRIORITY_HIGH */

#if (L2CAP_ENHANCED_FEATURES & L2CAP_COMPRESSION)
    BOOLEAN             compression_setup_in_process;
    UINT16              enhanced_features_used;
    void                *p_compr;
    BT_HDR              *p_decmpr_pkt;              /* Decompression pkt                */
    UINT8               *p_mem_pool;                /* compression fix memory pool      */
    UINT32              mem_pool_size;          
#endif


} tL2C_LCB;




/* Define the L2CAP control structure
*/
typedef struct
{
    UINT8           l2cap_trace_level;
    UINT8           desire_role;                    /* desire to be master/slave when accepting a connection */

    UINT16          num_lm_acl_bufs;                /* # of ACL buffers on controller   */
    UINT16          controller_xmit_window;         /* Total ACL window for all links   */

    tL2C_LCB        lcb_pool[MAX_L2CAP_LINKS];      /* Link Control Block pool          */
    tL2C_CCB        ccb_pool[MAX_L2CAP_CHANNELS];   /* Channel Control Block pool       */
    tL2C_RCB        rcb_pool[MAX_L2CAP_CLIENTS];    /* Registration info pool           */

    tL2C_CCB        *p_free_ccb_first;              /* Pointer to first free CCB        */
    tL2C_CCB        *p_free_ccb_last;               /* Pointer to last  free CCB        */

    UINT16          num_links_active;               /* Number of links active           */
    UINT16          idle_timeout;                   /* Idle timeout                     */

    tL2C_LCB        *p_cur_hcit_lcb;                /* Current HCI Transport buffer     */

    BUFFER_Q        rcv_hold_q;                     /* Recv pending queue               */
    TIMER_LIST_ENT  rcv_hold_tle;                   /* Timer list entry for rcv hold    */
    UINT8           compress_pool_id;

#if (L2CAP_ENHANCED_FEATURES & L2CAP_COMPRESSION)
    tL2CA_REGISTERCOMPRESSION_CBACK *p_reg_comp_cb; /* Server register l2cap compression callback */
    tL2CA_COMP_FREEMEM_CB           *p_comp_free_mem_cb; /* free compression memory callback */
#endif
    
} tL2C_CB;



/* Define a structure that contains the information about a connection.
** This structure is used to pass between functions, and not all the
** fields will always be filled in.
*/
typedef struct
{
    BD_ADDR         bd_addr;                        /* Remote BD address        */
    UINT8           status;                         /* Connection status        */
    UINT16          psm;                            /* PSM of the connection    */
    UINT16          l2cap_result;                   /* L2CAP result             */
    UINT16          l2cap_status;                   /* L2CAP status             */
    UINT16          remote_cid;                     /* Remote CID               */
} tL2C_CONN_INFO;

#if (L2CAP_FCR_INCLUDED == TRUE)
typedef void (tL2C_FCR_MGMT_EVT_HDLR) (UINT8, tL2C_CCB *);
#endif

/* The offset in a buffer that L2CAP will use when building commands.
*/
#define L2CAP_SEND_CMD_OFFSET       0


#ifdef __cplusplus
extern "C" {
#endif


/* L2CAP global data
************************************
*/
#if L2C_DYNAMIC_MEMORY == FALSE
L2C_API extern tL2C_CB  l2cb;
#else
L2C_API extern tL2C_CB *l2c_cb_ptr;
#define l2cb (*l2c_cb_ptr)
#endif


/* Functions provided by l2c_main.c
************************************
*/
extern void     l2c_init (void);
extern void     l2c_rcv_acl_data (BT_HDR *p_msg);
extern void     l2c_process_timeout (TIMER_LIST_ENT *p_tle);
extern void     l2c_process_held_packets (BOOLEAN timed_out);

/* Functions provided by l2c_utils.c
************************************
*/
extern tL2C_LCB *l2cu_allocate_lcb (BD_ADDR p_bd_addr);
extern void     l2cu_release_lcb (tL2C_LCB *p_lcb);
extern tL2C_LCB *l2cu_find_lcb_by_bd_addr (BD_ADDR p_bd_addr);
extern tL2C_LCB *l2cu_find_lcb_by_handle (UINT16 handle);

extern UINT8    l2cu_get_conn_role (tL2C_LCB *p_this_lcb);

extern tL2C_CCB *l2cu_allocate_ccb (tL2C_LCB *p_lcb);
extern void     l2cu_release_ccb (tL2C_CCB *p_ccb);
extern tL2C_CCB *l2cu_find_ccb_by_cid (tL2C_LCB *p_lcb, UINT16 local_cid);
extern tL2C_CCB *l2cu_find_ccb_by_remote_cid (tL2C_LCB *p_lcb, UINT16 remote_cid);

extern void     l2cu_send_peer_cmd_reject (tL2C_LCB *p_lcb, UINT16 reason,
                                           UINT8 rem_id,UINT16 p1, UINT16 p2);
extern void     l2cu_send_peer_connect_req (tL2C_CCB *p_ccb);
extern void     l2cu_send_peer_connect_rsp (tL2C_CCB *p_ccb, UINT16 result, UINT16 status);
extern void     l2cu_send_peer_config_req (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);
extern void     l2cu_send_peer_config_rsp (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);
extern void     l2cu_send_peer_config_rej (tL2C_CCB *p_ccb, UINT8 *p_data, UINT16 data_len, UINT16 rej_len);
extern void     l2cu_send_peer_disc_req (tL2C_CCB *p_ccb);
extern void     l2cu_send_peer_disc_rsp (tL2C_LCB *p_lcb, UINT8 remote_id, UINT16 local_cid, UINT16 remote_cid);
extern void     l2cu_send_peer_echo_req (tL2C_LCB *p_lcb, UINT8 *p_data, UINT16 data_len);
extern void     l2cu_send_peer_echo_rsp (tL2C_LCB *p_lcb, UINT8 id, UINT8 *p_data, UINT16 data_len);
extern void     l2cu_send_peer_info_rsp (tL2C_LCB *p_lcb, UINT8 id, UINT16 info_type);
extern void     l2cu_reject_connection (tL2C_LCB *p_lcb, UINT16 remote_cid, UINT8 rem_id, UINT16 result);
extern void     l2cu_send_peer_info_req (tL2C_LCB *p_lcb, UINT16 info_type);

/* Functions provided for compression
************************************
*/
extern BOOLEAN  l2cu_check_feature_req (tL2C_LCB *p_lcb, UINT8 id, UINT8 *p_data, UINT16 data_len);
extern void     l2cu_check_feature_rsp (tL2C_LCB *p_lcb, UINT8 id, UINT8 *p_data, UINT16 data_len);
extern void     l2cu_send_feature_req (tL2C_CCB *p_ccb);
extern BOOLEAN  l2cu_lcb_has_feature_enable(UINT16 feature, tL2C_LCB *p_lcb);
extern BOOLEAN  l2cu_ccb_has_compression_enable(tL2C_LCB *p_lcb);
extern void     l2cu_stop_compression (tL2C_LCB *p_lcb);

extern tL2C_RCB *l2cu_allocate_rcb (UINT16 psm);
extern tL2C_RCB *l2cu_find_rcb_by_psm (UINT16 psm);
extern void     l2cu_release_rcb (tL2C_RCB *p_rcb);

extern BOOLEAN  l2cu_process_peer_cfg_req (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);
extern void     l2cu_process_peer_cfg_rsp (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);
extern void     l2cu_process_our_cfg_req (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);
extern void     l2cu_process_our_cfg_rsp (tL2C_CCB *p_ccb, tL2CAP_CFG_INFO *p_cfg);

extern void     l2cu_device_reset (void);
extern tL2C_LCB *l2cu_find_lcb_by_state (tL2C_LINK_STATE state);
extern BOOLEAN  l2cu_lcb_disconnecting (void);

extern BOOLEAN l2cu_create_conn (tL2C_LCB *p_lcb);
extern BOOLEAN l2cu_create_conn_after_switch (tL2C_LCB *p_lcb);

/* Functions provided by l2c_link.c
************************************
*/
extern void     l2c_link_hci_conn_req (BD_ADDR bd_addr);
extern BOOLEAN  l2c_link_hci_conn_comp (UINT8 status, UINT16 handle, BD_ADDR p_bda);
extern BOOLEAN  l2c_link_hci_disc_comp (UINT16 handle, UINT8 reason);
extern BOOLEAN  l2c_link_hci_qos_violation (UINT16 handle);
extern void     l2c_link_timeout (tL2C_LCB *p_lcb);
extern void     l2c_link_check_send_pkts (tL2C_LCB *p_lcb, tL2C_CCB *p_ccb, BT_HDR *p_buf);
extern void     l2c_link_adjust_allocation (void);
extern void     l2c_link_process_num_completed_pkts (UINT8 *p);
extern void     l2c_link_processs_num_bufs (UINT16 num_lm_acl_bufs);
extern UINT8    l2c_link_pkts_rcvd (UINT16 *num_pkts, UINT16 *handles);
extern void     l2c_link_role_changed (BD_ADDR bd_addr, UINT8 new_role);
extern void     l2c_link_role_change_failed (void);
extern void     l2c_link_sec_comp (BD_ADDR p_bda, void *p_ref_data, UINT8 status);
extern void     l2c_link_segments_xmitted (BT_HDR *p_msg);
extern void     l2c_pin_code_request (BD_ADDR bd_addr);

/* Functions provided by l2c_csm.c
************************************
*/
extern void l2c_csm_execute (tL2C_CCB *p_ccb, UINT16 event, void *p_data);
extern void forward_peer_data(tL2C_CCB *p_ccb, BT_HDR *p_buf);

#if (L2CAP_FCR_INCLUDED == TRUE)
extern void l2c_fcr_init( tL2C_CCB *p_ccb );
extern void forward_peer_data_fcr_mode(tL2C_CCB *p_ccb, BT_HDR *p_buf);
extern tL2C_CCB *l2c_fcr_schedule_a_ccb_for_tx(tL2C_LCB *p_lcb);
extern void l2c_fcr_proc_evt( UINT8 evt, tL2C_CCB *p_ccb );
extern void l2c_fcr_proc_pdu(tL2C_CCB *p_ccb, BT_HDR *p_buf);
extern void l2c_fcr_send_S_frame( tL2C_CCB *p_ccb, UINT16 ctrl_word );
extern BT_HDR *l2c_fcr_clone_buf( BT_HDR *p_buf, UINT16 new_offset, UINT16 no_of_bytes, UINT8 pool );
#endif

L2C_API extern BT_HDR   *l2cap_link_chk_pkt_start(BT_HDR *); /* Called at start of rcv to check L2CAP segmentation */
L2C_API extern BOOLEAN   l2cap_link_chk_pkt_end (void);       /* Called at end   of rcv to check L2CAP segmentation */

L2C_API extern BT_HDR   *l2c_link_get_decompressed_pkt(BT_HDR *); /* Called at end of rcv to check L2CAP decompression */

#ifdef __cplusplus
}
#endif

#endif
