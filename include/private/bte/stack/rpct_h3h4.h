/*****************************************************************************
**
**  Name:           rpct_h3h4.h
**
**  Description:    This interface file contains the interface to the RPCT
**                  H3H4 link layer module.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_H3H4_H
#define RPCT_H3H4_H

#include <private/bte/stack/rpct_drv.h>
#include <private/bte/stack/rpct_link.h>
#include <private/bte/stack/ucbuf.h>

/*****************************************************************************
**  constants
*****************************************************************************/

/* mode constants */
#define RPCT_H3H4_MODE_H3   0
#define RPCT_H3H4_MODE_H4   1

/*****************************************************************************
**  type definitions
*****************************************************************************/

/* H3H4 configuration structure.  This structure is set by clients to
** configure the H3H4 link layer.
*/
typedef struct t_rpct_h3h4_cfg {
    tRPCT_DRV_CB        drv_cb;         /* driver control block pointer */
    tRPCT_LINK_CBACK    rcv_cback;      /* receive callback pointer */
    tUCBUF_CB           *p_ucbuf;       /* pointer to circular buffer */
    UINT16              pool_size;      /* size of GKI buffers in pool */
    UINT8               pool;           /* GKI pool used by RcvMsg() */
    UINT8               mbox;           /* GKI mailbox for SendMsg() */
    UINT8               mode;           /* H3 or H4 mode */
} tRPCT_H3H4_CFG;

/* Control block type.  The client must define this structure, but never
** access it.  All this data is internal to H3H4.
*/
typedef struct t_rpct_h3h4_cb {
    tRPCT_DRV_IF    *p_drv;         /* pointer to driver interface functions */
    tRPCT_H3H4_CFG  *p_cfg;         /* pointer to configuration structure */
    BT_HDR          *p_rcv_msg;     /* pointer to current GKI receive buffer */
    BT_HDR          *p_tx_msg;      /* pointer to current GKI transmit buffer */
    UINT16          tx_buf_len;     /* remaining length of packet in circular buffer */
    UINT16          rcv_len;        /* length of packet currently being received */
    UINT16          rcv_crc;        /* crc of the packet currently being received */
    UINT8           tx_seq;         /* transmit sequence number */
    UINT8           rcv_seq;        /* receive sequence number */
    UINT8           rcv_type;       /* type of packet currently being received */
    UINT8           rcv_state;      /* byte stream receive state */
} tRPCT_H3H4_CB;

/*****************************************************************************
**  global data
*****************************************************************************/

/* structure of interface functions */
extern const tRPCT_LINK_IF rpct_h3h4;

/*******************************************************************************
**
** Function         RPCT_H3H4Init
**
** Description      This callback function initializes the link layer with the
**                  given configuration.
**                  
**
** Returns          void
**
*******************************************************************************/
extern void RPCT_H3H4Init(tRPCT_LINK_CB cb, tRPCT_LINK_CFG cfg);

/*******************************************************************************
**
** Function         RPCT_H3H4SendMsg
**
** Description      This function sends an RPC packet to the link layer.  The
**                  packet is in a GKI message read from a GKI mailbox queue.
**                  
**
** Returns          void
**
*******************************************************************************/
extern UINT8 RPCT_H3H4SendMsg(tRPCT_LINK_CB cb);

/*******************************************************************************
**
** Function         RPCT_H3H4SendBuf
**
** Description      This function sends an RPC packet to the link layer.  The
**                  packet is in a GKI message read a circular buffer.
**                  
**
** Returns          void
**
*******************************************************************************/
extern UINT8 RPCT_H3H4SendBuf(tRPCT_LINK_CB cb);

/*******************************************************************************
**
** Function         RPCT_H3H4RcvMsg
**
** Description      This function implements a state machine that receives an
**                  RPC packet from a byte stream.  It reads data from the driver
**                  and builds a packet into a GKI buffer.
**                  
**
** Returns          void
**
*******************************************************************************/
extern void RPCT_H3H4RcvMsg(tRPCT_LINK_CB cb);

/*******************************************************************************
**
** Function         RPCT_H3H4Header
**
** Description      This function returns the number of bytes in the header
**                  of the link layer message.
**                  
**
** Returns          Number of bytes.
**
*******************************************************************************/
extern UINT8 RPCT_H3H4Header(tRPCT_LINK_CB cb);

/*******************************************************************************
**
** Function         RPCT_H3H4Trailer
**
** Description      This function returns the number of bytes in the trailer
**                  of the link layer message.
**                  
**
** Returns          Number of bytes.
**
*******************************************************************************/
extern UINT8 RPCT_H3H4Trailer(tRPCT_LINK_CB cb);

#endif /* RPCT_H3H4_H */
