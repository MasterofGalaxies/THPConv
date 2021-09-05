/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __IOS_USBTYPES_H__
#define __IOS_USBTYPES_H__

/* Note about the addr field in these structs:
 *   You don't need to set the device address. If you do, it
 *   will be ignored.
 */

/* Request for control transfers */
typedef struct {
    u8 bmRequestType;
    u8 bRequest;
    u16 wValue;
    u16 wIndex;
    u16 wLength;
    u32 data;
    u8 ep;
    u8 addr;  
} USBCtrlReq;

/* Request for bulk and interrupt transfers */
typedef struct {
    u8 ep;
    u8 addr; 
    u16 wLength;
    u32 data;
} USBIntrBlkReq;

typedef struct USBDeviceInfo{
    IOSFd fd;
    u16 vid;
    u16 pid;
}USBDeviceInfo;

typedef struct {
 USBDeviceInfo *deviceList;
 u8 maxDev;
 u8 deviceClass;
 u8 *numDev;
} USBGetDevListReq;

/* Device descriptor */
typedef struct {
    u8 bLength;
    u8 bDescriptorType;
    u16 bcdUSB;
    u8 bDeviceClass;
    u8 bDeviceSubClass;
    u8 bDeviceProtocol;
    u8 bMaxPacketSize0;
    u16 idVendor;
    u16 idProduct;
    u16 bcdDevice;
    u8 iManufacturer;
    u8 iProduct;
    u8 iSerialNumber;
   u8 bNumConfigurations;
} USB_DevDescr ;

/* Ioctl commands */
#define OHC_CTRL_MSG           0         
#define OHC_BLK_MSG            1
#define OHC_INTR_MSG           2

#define OHC_SUSPEND_MSG        5
#define OHC_RESUME_MSG         6
#define OHC_ISO_MSG            8
#define OHC_ISO_NEW_MSG        9
#define OHC_BLK_LONG_MSG      10

#define OHC_GET_DEVLIST_MSG   12
#define OHC_GET_RHDESCA_MSG   15
#define OHC_GET_RHPSTAT_MSG   20
#define OHC_SET_RHPSTAT_MSG   25
#define OHC_NOTIFYREMOVAL_MSG 26
#define OHC_NOTIFYINSERT_MSG  27
#define OHC_NOTIFYCLASSINSERT_MSG  28
#define OHC_RESET_MSG              29

#define SWAP32(val) \
    ((u32)( \
            (((u32)(val) & (u32)0x000000ffUL) << 24) | \
            (((u32)(val) & (u32)0x0000ff00UL) <<  8) | \
            (((u32)(val) & (u32)0x00ff0000UL) >>  8) | \
            (((u32)(val) & (u32)0xff000000UL) >> 24) ))

#define SWAP16(val) \
    ((u16)( \
            (((u16)(val) & (u16)0x00ffUL) << 8) | \
            (((u16)(val) & (u16)0xff00) >> 8) ))

/* Error codes */
/* See OHCI specs sec 4.3.3 */
#define IUSB_ERROR_NOERROR              0
#define IUSB_ERROR_CRC                 -7001  /* CRC error */
#define IUSB_ERROR_BITSTUFF            -7002  /* Bit stuffing error */
#define IUSB_ERROR_DTMISMATCH          -7003  /* Toggle mismatch */
#define IUSB_ERROR_STALL               -7004  /* Stall */
#define IUSB_ERROR_DEVNOTRESP          -7005  /* Device not responding */
#define IUSB_ERROR_PIDCHK              -7006  /* PID check failed*/
#define IUSB_ERROR_PID                 -7007  /* Unexpected PID */
#define IUSB_ERROR_DOVERRUN            -7008  /* Babble */
#define IUSB_ERROR_DUNDERRUN           -7009  /* Data underrun */

#define IUSB_ERROR_CC_ABORT            -7010  /* HCD code for abort */
#define IUSB_ERROR_CC_RSVD             -7011  /* Unused */

#define IUSB_ERROR_BOVERRUN            -7012  /* HC buffer overrun */
#define IUSB_ERROR_BUNDERRUN           -7013  /* HC buffer underrun */
#define IUSB_ERROR_NOTACCESSED         -7014  /* TD not accessed */
#define IUSB_ERROR_NOTACCESSED2        -7015  /* TD not accessed */

/* EHCI errors */
#define IUSB_ERROR_DBUFFER             -7100  /* Data buffer error */
#define IUSB_ERROR_BABBLE              -7101  /* Babble detected */
#define IUSB_ERROR_HALT                -7102  /* Endpoint halted */
#define IUSB_ERROR_DEVERR              -7103  /* Transaction error. Invalid
                                               * response from device - CRC,
                                               * timeout, bad PID, etc.
                                               */
#define IUSB_ERROR_CTRL_XFER   -7021
#endif /* __IOS_USBTYPES_H__ */
