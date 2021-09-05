/*****************************************************************************
**
**  Name:           rpct_serial.h
**
**  Description:    This interface file contains the interface to the RPCT
**                  serial driver module.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_SERIAL_H
#define RPCT_SERIAL_H

#include <private/bte/stack/rpct_drv.h>

/*****************************************************************************
**  type definitions
*****************************************************************************/

/* serial control block structure */
typedef struct t_rpct_serial_cb {
    UINT16      port;
    UINT16      tx_done;
    UINT16      rx_ready;
    UINT8       task;
    UINT8       baud;
} tRPCT_SERIAL_CB;

/*****************************************************************************
**  global data
*****************************************************************************/

/* structure of interface functions */
extern const tRPCT_DRV_IF rpct_serial;

/*******************************************************************************
**
** Function         RPCT_SerialOpen
**
** Description      This function calls the serial driver open function with
**                  the given configuration parameters.
**                  
**
** Returns          void
**
*******************************************************************************/
extern void RPCT_SerialOpen(tRPCT_DRV_CB cb);

/*******************************************************************************
**
** Function         RPCT_SerialWrite
**
** Description      This function calls the serial driver write function with
**                  the given length and data pointer.
**                  
**
** Returns          Number of bytes written.
**
*******************************************************************************/
extern UINT16 RPCT_SerialWrite(tRPCT_DRV_CB cb, UINT8 *p_data, UINT16 len);

/*******************************************************************************
**
** Function         RPCT_SerialRead
**
** Description      This function calls the serial driver read function with
**                  the given length and data pointer.
**                  
**
** Returns          Number of bytes read
**
*******************************************************************************/
extern UINT16 RPCT_SerialRead(tRPCT_DRV_CB cb, UINT8 *p_data, UINT16 len);

#endif /* RPCT_SERIAL_H */
