/***********************************************************
 * dummy_hci.h
 *
 * This is dummy code to respond to BTE Stack startup commands.
 *
 * Author: Daniel McDowell  02/22/2006
 ************************************************************/
 
 #ifndef __DUMMY_HCI_H__
 #define __DUMMY_HCI_H__
 
#include <private/bte/common/target.h>
#include <private/bte/stack/bt_types.h>
#include <private/bte/stack_init.h>

/*****************************************************
 *  usb pipe id types
 *****************************************************
 * Defines:   Port Id:     Direction:
 *****************************************************
 *  MSG_CTRL      0          Out    (Write Only)
 *  MSG_INTR      1          In     (Read Only)
 *  MSG_BULK      2          In/Out (Read/Write)
 *  MSG_ISOC      3          In/Out (Read/Write)
 ******************************************************/

/* usb endpoint id types */
#define MSG_CTRL      0
#define MSG_INTR      1
#define MSG_BULK      2
#define MSG_ISOC      3


/* usb pipe id types */
#define MSGTYPE_CTRL      MSG_CTRL
#define MSGTYPE_INTR      MSG_INTR
#define MSGTYPE_BULK      MSG_BULK
#define MSGTYPE_ISOC      MSG_ISOC

typedef struct
{
    UINT8 ep;
    UINT8 *p_data;
} tDATA_PKT;
/* Pointer to current HCI Service functions */
extern tHCI_IF dummyhci_if;   /* Pointer to current HCIS interface functions */

#endif /*  __DUMMY_HCI_H__  */