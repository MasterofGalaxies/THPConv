/*****************************************************************************/
/*                                                                           */
/*  Name:          btu.h                                                     */
/*                                                                           */
/*  Description:   this file contains the main Bluetooth Upper Layer         */
/*                 definitions. The Widcomm implementations of L2CAP         */
/*                 RFCOMM, SDP and the BTIf run as one GKI task. The         */
/*                 btu_task switches between them.                           */
/*                                                                           */
/*  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.              */
/*  WIDCOMM Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/
#ifndef BTU_H
#define BTU_H

#include <private/bte/gki.h>

/* Define the BTU mailbox usage
*/
#define BTU_HCI_RCV_MBOX        TASK_MBOX_0     /* Messages from HCI  */
#define BTU_BTIF_MBOX           TASK_MBOX_1     /* Messages to BTIF   */


/* callbacks
*/
typedef void (*tBTU_TIMER_CALLBACK)(TIMER_LIST_ENT *p_tle);
typedef void (*tBTU_EVENT_CALLBACK)(BT_HDR *p_hdr);


/* Define the timer types maintained by BTU
*/
#define BTU_TTYPE_BTM_DEV_CTL       1
#define BTU_TTYPE_L2CAP_LINK        2
#define BTU_TTYPE_L2CAP_CHNL        3
#define BTU_TTYPE_L2CAP_HOLD        4
#define BTU_TTYPE_SDP               5
#define BTU_TTYPE_BTM_SCO           6
#define BTU_TTYPE_BTM_INQ_AGE       7
#define BTU_TTYPE_BTM_DISCOVERY     8
#define BTU_TTYPE_BTM_ACL           9
#define BTU_TTYPE_BTM_RMT_NAME      10
#define BTU_TTYPE_RFCOMM_MFC        11
#define BTU_TTYPE_RFCOMM_PORT       12
#define BTU_TTYPE_TCS_L2CAP         13
#define BTU_TTYPE_TCS_CALL          14
#define BTU_TTYPE_TCS_WUG           15
#define BTU_TTYPE_AUTO_SYNC         16
#define BTU_TTYPE_CTP_RECON         17
#define BTU_TTYPE_CTP_T100          18
#define BTU_TTYPE_CTP_GUARD         19
#define BTU_TTYPE_CTP_DETACH        20

#define BTU_TTYPE_SPP_CONN_RETRY    21
#define BTU_TTYPE_USER_FUNC         22

#define BTU_TTYPE_FTP_DISC          25
#define BTU_TTYPE_OPP_DISC          26

#define BTU_TTYPE_CTP_TL_DISCVY     28
#define BTU_TTYPE_IPFRAG_TIMER      29
#define BTU_TTYPE_HSP2_AT_CMD_TO    30
#define BTU_TTYPE_HSP2_REPEAT_RING  31

#define BTU_TTYPE_CTP_GW_INIT       32
#define BTU_TTYPE_CTP_GW_CONN       33
#define BTU_TTYPE_CTP_GW_IDLE       35

#define BTU_TTYPE_ICP_L2CAP         36
#define BTU_TTYPE_ICP_T100          37

#define BTU_TTYPE_HSP2_WAIT_OK      38

/* HCRP Timers */
#define BTU_TTYPE_HCRP_NOTIF_REG    39
#define BTU_TTYPE_HCRP_PROTO_RSP    40
#define BTU_TTYPE_HCRP_CR_GRANT     41
#define BTU_TTYPE_HCRP_CR_CHECK     42
#define BTU_TTYPE_HCRP_W4_CLOSE     43

/* HCRPM Timers */
#define BTU_TTYPE_HCRPM_NOTIF_REG   44
#define BTU_TTYPE_HCRPM_NOTIF_KEEP  45
#define BTU_TTYPE_HCRPM_API_RSP     46
#define BTU_TTYPE_HCRPM_W4_OPEN     47
#define BTU_TTYPE_HCRPM_W4_CLOSE    48

/* BNEP Timers */
#define BTU_TTYPE_BNEP              50

/* OBX */
#define BTU_TTYPE_OBX_CLIENT_TO     51
#define BTU_TTYPE_OBX_SERVER_TO     52


#define BTU_TTYPE_HSP2_SDP_FAIL_TO  55
#define BTU_TTYPE_HSP2_SDP_RTRY_TO  56


/* BTU internal */
#define BTU_TTYPE_BTU_CMD_CMPL      60

#define BTU_TTYPE_AVDT_CCB_RET      61
#define BTU_TTYPE_AVDT_CCB_RSP      62
#define BTU_TTYPE_AVDT_CCB_IDLE     63
#define BTU_TTYPE_AVDT_SCB_TC       64

#define BTU_TTYPE_HID_DEV_REPAGE_TO 65
#define BTU_TTYPE_HID_HOST_REPAGE_TO 66

#define BTU_TTYPE_HSP2_DELAY_CKPD_RCV 67

#define BTU_TTYPE_SAP_TO            68

#define BTU_TTYPE_SLIP_RETRANSMIT_TO 69

#define BTU_TTYPE_SLIP_DELAY_ACK_TO  70

#define BTU_TTYPE_SLIP_CONTROL_TO    71
/* BPP Timer */
#define BTU_TTYPE_BPP_REF_CHNL     72

/* Compression setup Timer */
#define BTU_TTYPE_L2CAP_COMPRESS_SETUP 73
/* This is the inquiry response information held by BTU, and available
** to applications.
*/
typedef struct
{
    BD_ADDR     remote_bd_addr;
    UINT8       page_scan_rep_mode;
    UINT8       page_scan_per_mode;
    UINT8       page_scan_mode;
    DEV_CLASS   dev_class;
    UINT16      clock_offset;
} tBTU_INQ_INFO;



#define BTU_MAX_REG_TIMER     (2)   /* max # timer callbacks which may register */
#define BTU_MAX_REG_EVENT     (6)   /* max # event callbacks which may register */
#define BTU_DEFAULT_DATA_SIZE (0x2a0)

/* structure to hold registered timers */
typedef struct
{
	TIMER_LIST_ENT          *p_tle;      /* timer entry */
	tBTU_TIMER_CALLBACK     timer_cb;    /* callback triggered when timer expires */
} tBTU_TIMER_REG;


/* structure to hold registered event callbacks */
typedef struct
{
	UINT16                  event_range;  /* start of event range */
	tBTU_EVENT_CALLBACK     event_cb;     /* callback triggered when event is in range */
} tBTU_EVENT_REG;


/* Define structure holding BTU variables
*/
typedef struct
{
    tBTU_TIMER_REG   timer_reg[BTU_MAX_REG_TIMER];
    tBTU_EVENT_REG   event_reg[BTU_MAX_REG_EVENT];

    TIMER_LIST_Q  timer_queue;              /* Timer queue   */

    TIMER_LIST_ENT   cmd_cmpl_timer;        /* Command complete timer */

    BUFFER_Q    cmd_xmit_q;
    BUFFER_Q    cmd_cmpl_q;

    UINT16    hcit_acl_data_size;           /* Max ACL data size across HCI transport    */
    UINT16    hcit_acl_pkt_size;            /* Max ACL packet size across HCI transport  */
                                            /* (this is data size plus 4 bytes overhead) */

    UINT16      controller_cmd_window;

    BOOLEAN     reset_complete;             /* TRUE after first ack from device received */
} tBTU_CB;


#ifdef __cplusplus
extern "C" {
#endif

/* Global BTU data */
#if BTU_DYNAMIC_MEMORY == FALSE
BTU_API extern tBTU_CB  btu_cb;
#else
BTU_API extern tBTU_CB *btu_cb_ptr;
#define btu_cb (*btu_cb_ptr)
#endif

BTU_API extern const BD_ADDR        BT_BD_ANY;

/* Functions provided by btu_task.c
************************************
*/
BTU_API extern void btu_start_timer (TIMER_LIST_ENT *p_tle, UINT16 type, UINT32 timeout); 
BTU_API extern void btu_stop_timer (TIMER_LIST_ENT *p_tle);
BTU_API extern void btu_register_timer (TIMER_LIST_ENT *p_tle, UINT16 type, UINT32 timeout, tBTU_TIMER_CALLBACK timer_cb);
BTU_API extern void btu_deregister_timer(TIMER_LIST_ENT *p_tle);


BTU_API extern void btu_register_event_range (UINT16 range, tBTU_EVENT_CALLBACK event_cb);
BTU_API extern void btu_deregister_event_range (UINT16 range);

/* Functions provided by btu_hcif.c
************************************
*/
BTU_API extern void  btu_hcif_process_event (BT_HDR *p_buf);
BTU_API extern void  btu_hcif_send_cmd (BT_HDR *p_msg);
BTU_API extern void  btu_hcif_send_host_rdy_for_data(void);
BTU_API extern void  btu_hcif_cmd_timeout (void);

/* Functions provided by btu_core.c
************************************
*/
BTU_API extern void  btu_init_core(void);
BTU_API extern void  BTE_Init(void);
BTU_API extern UINT16 BTU_AclPktSize(void);

#ifdef __cplusplus
}
#endif

#endif

