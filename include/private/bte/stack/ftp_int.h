/*****************************************************************************
**
**  Name:       ftp_int.h
**
**  File:       File Transfer Profile Internal Definitions
**
**  Copyright (c) 2000-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef FTP_INT_H
#define FTP_INT_H

#include <private/bte/common/target.h>
#if (defined(FTP_CLIENT_INCLUDED) && FTP_CLIENT_INCLUDED == TRUE)
#include <private/bte/stack/ftp_clnt_int.h>
#endif
#if (defined(FTP_SERVER_INCLUDED) && FTP_SERVER_INCLUDED == TRUE)
#include <private/bte/stack/ftp_srvr_int.h>
#endif

/*****************************************************************************
**   Constants
*****************************************************************************/

#define FTP_FOLDER_BROWSING_TARGET_UUID "\xF9\xEC\x7B\xC4\x95\x3C\x11\xD2\x98\x4E\x52\x54\x00\xDC\x9E\x09"
#define FTP_UUID_LENGTH                 16
#define FTP_MAX_AUTH_KEY_SIZE           16  /* Must not be greater than OBX_MAX_AUTH_KEY_SIZE */
#define FTP_DEFAULT_VERSION             0x0100

#define FTP_FOLDER_LISTING_TYPE         "x-obex/folder-listing"

/* FTP Active ftp obex operation (Valid in connected state) */
#define FTP_OP_NONE         0
#define FTP_OP_GET_LIST     1
#define FTP_OP_GET_FILE     2
#define FTP_OP_PUT_FILE     3
#define FTP_OP_REMOVE       4   /* Folder or File */
#define FTP_OP_CHDIR        5
#define FTP_OP_MKDIR        6

/*****************************************************************************
**   Type Definitions
*****************************************************************************/
typedef struct
{
    tFTP_GOEP_CBACKS    fs_cbacks;
#if (defined(FTP_SERVER_INCLUDED) && FTP_SERVER_INCLUDED == TRUE)
    tFTP_SRVR_CB        scb;
#endif
#if (defined(FTP_CLIENT_INCLUDED) && FTP_CLIENT_INCLUDED == TRUE)
    tFTP_CLNT_CB        ccb;
    tFTP_CLNT_SDP       sdpcb;
#endif
    UINT8               trace_level;
} tFTP_CB;


#ifdef __cplusplus
extern "C"
{
#endif
/*
** Define prototypes for global data
*/
#if FTP_DYNAMIC_MEMORY == FALSE
FTP_API extern tFTP_CB  ftp_cb;
#else
FTP_API extern tFTP_CB *ftp_cb_ptr;
#define ftp_cb (*ftp_cb_ptr)
#endif

extern void ftp_freepkt(BT_HDR **p_pkt);
#ifdef __cplusplus
}
#endif

#endif
