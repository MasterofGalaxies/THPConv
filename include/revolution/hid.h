/*---------------------------------------------------------------------------*
  Project:  HID lib API
  File:     hid.h

  Copyright (C)1998-2007 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
    
  $Log: not supported by cvs2svn $
  Revision 2.7  2007/11/06 19:28:15  henrch
  changed ep reference fro n to in / out

  Revision 2.6  2007/11/01 20:51:58  henrch
  - changed HID_MEM_SIZE

  Revision 2.5  2007/09/26 19:27:47  henrch
  - changed HIDUnregisterClient() to HIDUnregisterClientAsync()
  - added HIDClientHandler
  - changed HID_MEM_SIZE

  Revision 2.4  2007/09/25 20:37:49  henrch
  - changed HID_MEM_SIZE
  - removed max end point size from HIDDevice

  Revision 2.3  2007/09/21 19:53:42  henrch
  - remove MEM2 data requirement
  - API change, now async task buffer is handeled by HID lib
  - chnaged HID_MEM_SIZE

  Revision 2.2  2007/09/18 20:04:33  henrch
  - added max size for endpoint
  - increased  HID_MEM_SIZE

  Revision 2.1  2007/09/07 22:08:28  henrch
  changed HID_MEM_SIZE, increased to include cancel intr message feature

  Revision 2.0  2007/09/07 18:55:39  henrch
  created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/
#ifndef __HID_H__
#define __HID_H__
#ifdef __cplusplus
extern "C" {
#endif
///////////////////////////////////////////////////////////////////////////////
#define HID_MEM_SIZE    15072
///////////////////////////////////////////////////////////////////////////////
typedef s32 HIDError;
    
#define HID_ERROR_OK                            0
#define HID_ERROR_NOT_OPEN                      -1
#define HID_ERROR_ALREADY_OPEN                  -2
#define HID_ERROR_FIRMWARE_VERSION              -3
#define HID_ERROR_FIRMWARE_MALFUNCTION          -4
#define HID_ERROR_BUSY                          -5
#define HID_ERROR_CANCELLED                     -6                      

///////////////////////////////////////////////////////////////////////////////
// Standard Device Descriptor
typedef struct         
{

    u8  bLength;
    u8  bDescriptorType;
    u16 bcdUSB;
    u8  bDeviceClass;
    u8  bDeviceSubClass;
    u8  bDeviceProtocol;
    u8  bMaxPacketSize;
    u16 idVendor;
    u16 idProduct;
    u16 bcdDevice;
    u8  iManufacturer;
    u8  iProduct;
    u8  iSerialNumber;
    u8  bNumConfigurations;

    u8  pad[2];

} HIDDeviceDescriptor;


// Standard Configuration Descriptor
typedef struct 
{

    u8  bLength;
    u8  bDescriptorType;
    u16 wTotalLength;
    u8  bNumInterfaces;
    u8  bConfigurationValue;
    u8  iConfiguration;
    u8  bmAttributes;
    u8  bMaxPower;

    u8  pad[3];

} HIDConfigurationDescriptor;


// Standard Interface Descriptor
typedef struct        
{

    u8  bLength;
    u8  bDescriptorType;
    u8  bInterfaceNumber;
    u8  bAlternateSetting;
    u8  bNumEndpoints;
    u8  bInterfaceClass;
    u8  bInterfaceSubClass;
    u8  bInterfaceProtocol;
    u8  iInterface;

    u8  pad[3];

} HIDInterfaceDescriptor;


// Standard Endpoint Descriptor
typedef struct 
{

    u8  bLength;
    u8  bDescriptorType;
    u8  bEndpointAddress;
    u8  bmAttributes;
    u16 wMaxPacketSize;
    u8  bInterval;
    
    u8  pad[1];

} HIDEndpointDescriptor;


// client gets reference to one of these on attach
typedef struct
{

    s32                         fd;
    u16                         vid;
    u16                         pid;
    u8                          iInterface;
    u8                          endpoint_address_in;
    u8                          endpoint_address_out;
    volatile u8                 inst;
    HIDDeviceDescriptor         *p_hdd;
    HIDConfigurationDescriptor  *p_hcd;
    HIDInterfaceDescriptor      *p_hid;
    HIDEndpointDescriptor       *p_hed0;
    HIDEndpointDescriptor       *p_hed1;

} HIDDevice;


///////////////////////////////////////////////////////////////////////////////
typedef struct _HIDClient HIDClient;

typedef int (*HIDAttachHandler)(
                        HIDClient   *p_hc,
                        HIDDevice   *p_hd,   
                        u32         attach
                        );

struct _HIDClient
{

    HIDClient           *next;
    HIDAttachHandler    attachHandler;
    u32					user;

};


///////////////////////////////////////////////////////////////////////////////
// setup and teardown
typedef void (*HIDSetupHandler)(HIDError he, u32 user);

HIDError HIDOpenAsync(
                void *mem,
                HIDSetupHandler hsh,
                u32             user
                );

HIDError HIDCloseAsync(
                HIDSetupHandler hsh,
                u32             user
                );

// client registration
typedef void (*HIDClientHandler)(HIDError he, u32 user);

HIDError HIDRegisterClient(
                HIDClient       *hClient,
                HIDAttachHandler hah
                );
 
HIDError HIDUnregisterClientAsync(
                HIDClient       *hClient,
                HIDClientHandler hch,
                u32             user
                ); 

// HID runtime APIs
typedef void (*HIDDoneHandler)(
                HIDDevice       *p_hd,   
                HIDError        error,
                u8              *p_data,
                u32             size,
                u32             user
                );

HIDError HIDGetAsciiStringAsync(
                HIDDevice       *p_hd, 
                u8              index,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );
                
HIDError HIDGetDescriptorAsync(
                HIDDevice       *p_hd, 
                u8              descriptor_type,
                u8              descriptor_index,
                u16             language_id,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDSetDescriptorAsync(
                HIDDevice       *p_hd, 
                u8              descriptor_type,
                u8              descriptor_index,
                u16             language_id,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDGetReportAsync(
                HIDDevice       *p_hd, 
                u8              report_type,
                u8              report_id,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDSetReportAsync(
                HIDDevice       *p_hd, 
                u8              report_type,
                u8              report_id,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDGetIdleAsync(
                HIDDevice       *p_hd,
                u8              report_id,
                u8              *p_data,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDSetIdleAsync(
                HIDDevice       *p_hd,
                u8              report_id,
                u8              duration,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDGetProtocolAsync(
                HIDDevice       *p_hd,
                u8              *p_data,
                HIDDoneHandler  hdh,
                u32             user
                );

HIDError HIDSetProtocolAsync(
                HIDDevice       *p_hd,
                u8              protocol,
                HIDDoneHandler  hdh,
                u32             user
                );
                    
HIDError HIDGetReportIntAsync(
                HIDDevice       *p_hd,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );
                    
HIDError HIDSetReportIntAsync(
                HIDDevice       *p_hd,
                u8              *p_data,
                u32             size,
                HIDDoneHandler  hdh,
                u32             user
                );

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif  // __HID_H__
