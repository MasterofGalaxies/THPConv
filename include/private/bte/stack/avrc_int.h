/*****************************************************************************
**
**  Name:       avrc_int.h
**
**  Description:AVRCP internal header file
**
**  Copyright (c) 2003-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/


#ifndef AVRC_INT_H
#define AVRC_INT_H

#include <private/bte/stack/avrc_api.h>

/*****************************************************************************
**  Constants
*****************************************************************************/

/* Number of attributes in AVRC SDP record. */
#define AVRC_NUM_ATTR            5

/* Number of protocol elements in protocol element list. */
#define AVRC_NUM_PROTO_ELEMS     2

#ifndef AVRC_MIN_CMD_LEN
#define AVRC_MIN_CMD_LEN    20
#endif

#define AVRC_UNIT_OPRND_BYTES   5
#define AVRC_SUB_OPRND_BYTES    4
#define AVRC_SUBRSP_OPRND_BYTES 3
#define AVRC_SUB_PAGE_MASK      7
#define AVRC_SUB_PAGE_SHIFT     4
#define AVRC_SUB_EXT_CODE       7
#define AVRC_PASS_OP_ID_MASK    0x7F
#define AVRC_PASS_STATE_MASK    0x80
#define AVRC_CMD_OPRND_PAD      0xFF

#define AVRC_CTYPE_MASK         0x0F
#define AVRC_SUBTYPE_MASK       0xF8
#define AVRC_SUBTYPE_SHIFT      3
#define AVRC_SUBID_MASK         0x07
#define AVRC_SUBID_IGNORE       0x07

/* Company ID is 24-bit integer We can not use the macros in bt_types.h */
#define AVRC_CO_ID_TO_BE_STREAM(p, u32) {*(p)++ = (UINT8)((u32) >> 16); *(p)++ = (UINT8)((u32) >> 8); *(p)++ = (UINT8)(u32); }
#define AVRC_BE_STREAM_TO_CO_ID(u32, p) {u32 = (((UINT32)(*((p) + 2))) + (((UINT32)(*((p) + 1))) << 8) + (((UINT32)(*(p))) << 16)); (p) += 3;}


/*****************************************************************************
**  Type definitions
*****************************************************************************/


typedef struct
{
    tAVRC_CONN_CB       ccb[AVCT_NUM_CONN];
    tAVRC_FIND_CBACK    *p_cback;       /* pointer to application callback */
    tSDP_DISCOVERY_DB   *p_db;          /* pointer to discovery database */
    UINT16              service_uuid;   /* service UUID to search */
    UINT8               trace_level;
} tAVRC_CB;



#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
** Main Control Block
*******************************************************************************/
#if AVRC_DYNAMIC_MEMORY == FALSE
AVRC_API extern tAVRC_CB  avrc_cb;
#else
AVRC_API extern tAVRC_CB *avrc_cb_ptr;
#define avrc_cb (*avrc_cb_ptr)
#endif

#ifdef __cplusplus
}
#endif

#endif /* AVRC_INT_H */

