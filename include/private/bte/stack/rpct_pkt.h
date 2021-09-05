/*****************************************************************************
**
**  Name:           rpct_pkt.h
**
**  Description:    This interface file contains function prototypes and 
**                  constants pertaining to the RPC packet format.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_PKT_H
#define RPCT_PKT_H

/*****************************************************************************
**  Constants
*****************************************************************************/

/* definitions for attribute field */
#define RPC_ATTR_PRI_HIGH       1
#define RPC_ATTR_PRI_LOGMSG     2
#define RPC_ATTR_PRI_DISPMSG    3

#define RPC_ATTR_PRI_MASK       0x0F

#define RPC_ATTR_BLOCK          0x00
#define RPC_ATTR_NONBLOCK       0x10
#define RPC_ATTR_BLOCK_MASK     0x10

#define RPC_TYPE_MSG            0
#define RPC_TYPE_RSP            1
#define RPC_TYPE_ERR            2

/* RPC packet header size in bytes */
#define RPCT_PKT_HDR_SIZE       6

/* RPC packet reserved bits in handle */
#define RPCT_PKT_HDL_RSVD       0x2F00

/* RPC packet type bits in handle */
#define RPCT_PKT_TYPE_MASK      0x03

/* RPC attribute thread id extract mask */
#define RPCT_ATTR_THREAD_MASK		0xE0

/* RPC attribute thread id shift */
#define RPCT_ATTR_THREAD_SHIFT		5

/* RPC header size : 1(function id) + 1(attribute) */
#define RPCT_RPC_HDR_SIZE			2
/*****************************************************************************
**  Declarations
*****************************************************************************/
extern void rpc_build_pkt(UINT8 *p, UINT16 len, UINT8 subsys, UINT8 fcn, UINT8 type, UINT8 attr);
extern void rpc_parse_pkt(UINT8 *p, UINT16 *p_len, UINT8 *p_subsys, UINT8 *p_fcn, UINT8 *p_type, UINT8* p_attr, UINT8* p_threadid);

#endif /* RPCT_PKT_H */
