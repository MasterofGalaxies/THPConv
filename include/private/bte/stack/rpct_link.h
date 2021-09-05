/*****************************************************************************
**
**  Name:           rpct_link.h
**
**  Description:    This interface file provides a virtual base class for the
**                  RPCT link layer modules.  It declares the common interface
**                  function structure for link layer modules.  It also contains
**                  a forward declaration of each link layer control block and
**                  a union of all link layer control block types.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_LINK_H
#define RPCT_LINK_H

/*****************************************************************************
**  Constants
*****************************************************************************/

/* sending state; returned by sendmsg and sendbuf functions */
#define RPCT_LINK_SEND_NONE     0   /* no send in progress */
#define RPCT_LINK_SEND_MSG      1   /* send of message from GKI buffer in progress */
#define RPCT_LINK_SEND_BUF      2   /* send of message from circular buffer in progress */

/*****************************************************************************
**  Declaration of driver control and configuration structures
*****************************************************************************/

/* forward declaration of h3h4 configuration */
typedef struct t_rpct_h3h4_cfg *tpRPCT_H3H4_CFG;

/* union of all link layer configuration types */
typedef union {
    tpRPCT_H3H4_CFG   p_h3h4;       /* h3h4 link layer */
} tRPCT_LINK_CFG;

/* forward declaration of h3h4 control block */
typedef struct t_rpct_h3h4_cb *tpRPCT_H3H4_CB;

/* union of all link layer control block types */
typedef union {
    tpRPCT_H3H4_CB   p_h3h4;       /* h3h4 link layer */
} tRPCT_LINK_CB;

/*****************************************************************************
**  Common interface function type definitions
*****************************************************************************/

/* Link callback function type */
typedef void (*tRPCT_LINK_CBACK)(BT_HDR *p_msg);

/* Init function */
typedef void (*tRPCT_LINK_INIT)(tRPCT_LINK_CB cb, tRPCT_LINK_CFG cfg);

/* Send msg function */
typedef UINT8 (*tRPCT_LINK_SENDMSG)(tRPCT_LINK_CB cb);

/* Send buf function */
typedef UINT8 (*tRPCT_LINK_SENDBUF)(tRPCT_LINK_CB cb);

/* Rcv msg function */
typedef void (*tRPCT_LINK_RCVMSG)(tRPCT_LINK_CB cb);

/* Header function */
typedef UINT8 (*tRPCT_LINK_HEADER)(tRPCT_LINK_CB cb);

/* Trailer function */
typedef UINT8 (*tRPCT_LINK_TRAILER)(tRPCT_LINK_CB cb);

/* structure of interface functions */
typedef struct {
    tRPCT_LINK_INIT          init;
    tRPCT_LINK_SENDMSG       sendmsg;
    tRPCT_LINK_SENDBUF       sendbuf;
    tRPCT_LINK_RCVMSG        rcvmsg;
    tRPCT_LINK_HEADER        header;
    tRPCT_LINK_TRAILER       trailer;
} tRPCT_LINK_IF;

#endif /* RPCT_LINK_H */
