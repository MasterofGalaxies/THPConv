/*****************************************************************************/
/*                                                                           */
/*  Name:          gap_int.h                                                 */
/*                                                                           */
/*  Description:   this file contains the GAP internal interface             */
/*                 definitions.                                              */
/*                                                                           */
/*                                                                           */
/*  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.              */
/*  WIDCOMM Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/
#ifndef GAP_INT_H
#define GAP_INT_H

#include <private/bte/common/target.h>
#include <private/bte/stack/gap_api.h>
#include <private/bte/stack/btm_api.h>
#include <private/bte/gki.h>

#define GAP_MAX_BLOCKS 2        /* Concurrent GAP commands pending at a time*/
                                /* There must be a different btm callback for*/
                                /* each control block.*/


/* Definitions of limits for inquiries */
#define GAP_PER_INQ_MIN_MAX_PERIOD      BTM_PER_INQ_MIN_MAX_PERIOD
#define GAP_PER_INQ_MAX_MAX_PERIOD      BTM_PER_INQ_MAX_MAX_PERIOD
#define GAP_PER_INQ_MIN_MIN_PERIOD      BTM_PER_INQ_MIN_MIN_PERIOD
#define GAP_PER_INQ_MAX_MIN_PERIOD      BTM_PER_INQ_MAX_MIN_PERIOD
#define GAP_MAX_INQUIRY_LENGTH          BTM_MAX_INQUIRY_LENGTH
#define GAP_MIN_INQUIRY_LEN             BTM_MIN_INQUIRY_LEN

/* Define the Generic Access Profile control structure */
typedef struct
{
    void          *p_data;      /* Pointer to any data returned in callback */
    tGAP_CALLBACK *gap_cback;   /* Pointer to users callback function */
    tGAP_CALLBACK *gap_inq_rslt_cback; /* Used for inquiry results */
    UINT16         event;       /* Passed back in the callback */
    UINT8          index;       /* Index of this control block and callback */
    BOOLEAN        in_use;      /* True when structure is allocated */
} tGAP_INFO;

/* Define the control block for the FindAddrByName operation (Only 1 active at a time) */
typedef struct
{
    tGAP_CALLBACK           *p_cback;
    tBTM_INQ_INFO           *p_cur_inq; /* Pointer to the current inquiry database entry */
    tGAP_FINDADDR_RESULTS    results;
    BOOLEAN                  in_use;
} tGAP_FINDADDR_CB;


/* Define the GAP Connection Control Block.
*/
typedef struct
{
#define GAP_CCB_STATE_IDLE              0
#define GAP_CCB_STATE_LISTENING         1
#define GAP_CCB_STATE_CONN_SETUP        2
#define GAP_CCB_STATE_CFG_SETUP         3
#define GAP_CCB_STATE_CONNECTED         4
    UINT8             con_state;

#define GAP_CCB_FLAGS_IS_ORIG           0x01
#define GAP_CCB_FLAGS_HIS_CFG_DONE      0x02
#define GAP_CCB_FLAGS_MY_CFG_DONE       0x04
    UINT8             con_flags;

    UINT8             security_flags;       /* Security flags                       */
    UINT16            gap_handle;           /* GAP handle                           */
    UINT16            connection_id;        /* L2CAP CID                            */
    BOOLEAN           rem_addr_specified;
    BD_ADDR           rem_dev_address;
    UINT16            psm;
    UINT16            rem_mtu_size;

    BUFFER_Q          rx_queue;             /* Queue of buffers waiting to be read  */

    tGAP_CONN_CALLBACK *p_callback;         /* Users callback function              */

    tL2CAP_CFG_INFO   cfg;                  /* Configuration                        */

} tGAP_CCB;

typedef struct
{
    tL2CAP_APPL_INFO  reg_info;                     /* L2CAP Registration info */
    tGAP_CCB    ccb_pool[GAP_MAX_CONNECTIONS];
} tGAP_CONN;


/**********************************************************************
** M A I N   C O N T R O L   B L O C K 
***********************************************************************/
typedef struct
{
    tGAP_INFO        blk[GAP_MAX_BLOCKS];
    tBTM_CMPL_CB    *btm_cback[GAP_MAX_BLOCKS];
    UINT8            trace_level;
#if BTM_INQUIRY_INCLUDED == TRUE
    tGAP_FINDADDR_CB findaddr_cb;   /* Contains the control block for finding a device addr */
    tBTM_INQ_INFO   *cur_inqptr;
#endif
#if GAP_CONN_INCLUDED == TRUE
    tGAP_CONN        conn;
#endif
} tGAP_CB;


#ifdef __cplusplus
extern "C" {
#endif

#if GAP_DYNAMIC_MEMORY == FALSE
GAP_API extern tGAP_CB  gap_cb;
#else
GAP_API extern tGAP_CB *gap_cb_ptr;
#define gap_cb (*gap_cb_ptr)
#endif

extern tGAP_INFO        *gap_allocate_cb(void);
extern void              gap_free_cb(tGAP_INFO *p_cb);

#if BTM_INQUIRY_INCLUDED == TRUE
extern void              gap_inq_results_cb(tGAP_INQ_RESULTS *p_results);
extern UINT16            gap_find_local_addr_by_name (const BD_NAME devname, BD_ADDR bd_addr);
extern void              gap_find_addr_inq_cb (tBTM_INQUIRY_CMPL *p);
#endif
extern BOOLEAN           gap_is_service_busy (UINT16 request);
extern UINT16            gap_convert_btm_status (tBTM_STATUS btm_status);

extern void gap_btm_cback0(void *p1);
#if GAP_MAX_BLOCKS > 1
extern void gap_btm_cback1(void *p1);
#endif
#if GAP_MAX_BLOCKS > 2
extern void gap_btm_cback2(void *p1);
#endif

#if (GAP_CONN_INCLUDED == TRUE)
extern void gap_conn_init(void);
#endif

#ifdef __cplusplus
}
#endif

#endif
