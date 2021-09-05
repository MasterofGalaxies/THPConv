/*****************************************************************************
**
**  Name:          stack_init.h
**
**  Description:   this file contains constants and definitions for the bte project
**
**
**  Copyright (c) 2001-2005, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
******************************************************************************/
#ifndef STACK_INIT_H
#define STACK_INIT_H

#include <private/bte/common/target.h>

#define USB_CLOSE_SUCCESS      0
#define USB_CLOSE_FAILURE      1

/*****************************************************************************
** Prototypes for HCI Service interface functions
******************************************************************************/

/* Initialize transport's control block and hardware */
typedef void (*tHCI_INIT)(UINT8 id);

/* Open port for HCI services */
typedef BOOLEAN (*tHCI_OPEN)(void);

/* Close port for HCI services */
typedef void (*tHCI_CLOSE)(void);

/* Send HCI command/data to the transport */
typedef BOOLEAN (*tHCI_SEND)(UINT8 *p_msg, UINT16 len);

typedef void (*tUSER_CBACK)(UINT8 err);


/*****************************************************************************
** Structure of interface functions 
******************************************************************************/
typedef struct {
    tHCI_INIT init;
    tHCI_OPEN open;
    tHCI_CLOSE close;
    tHCI_SEND send;
} tHCI_IF;


/****************************************************************
 * Function: BTA_Init
 *
 * Description: Starts up all necessary BTA/BTE stack operations
 *
 *****************************************************************/
extern int BTA_Init( void );

/****************************************************************
 * Function: BTA_CleanUp
 *
 * Description: Cleans up all necessary stack operations
 *
 *****************************************************************/
extern void BTA_CleanUp( tUSER_CBACK cb );

/****************************************************************
 * Function: bta_ci_hci_msg_handler
 *
 * Description: called when there is data from IPC to be queued
 *              for BTE to process...
 *****************************************************************/
extern void bta_ci_hci_msg_handler(UINT8 *p_msg);


#endif  /* STACK_INIT_H */
