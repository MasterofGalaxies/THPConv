/*---------------------------------------------------------------------------*
  Project:  MSC lib API
  File:     msc.h

  Copyright (C)1998-2007 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
    
  $Log: not supported by cvs2svn $
  Revision 1.5  2007/12/06 00:29:03  henrch
  - added SCSI commands
  - changed some APIs for uniformity
  - more thorough ASSERTMSG on API front end
  - removed read write 12 commands

  Revision 1.4  2007/12/04 21:34:57  henrch
  - rearranged scsi inquiry for smaller foot print
  - changed memory size

  Revision 1.3  2007/11/27 22:10:06  henrch
  changed inquery to inquiry

  Revision 1.2  2007/11/19 21:36:58  henrch
  - update API, removed some functions
  - changed error handeling for API, both MSCError and SCSI CSW status now in user callback

  Revision 1.1  2007/11/12 22:09:06  henrch
  created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/
#ifndef __MSC_H__
#define __MSC_H__
#ifdef __cplusplus
extern "C" {
#endif
///////////////////////////////////////////////////////////////////////////////
#define MSC_MEM_SIZE    11744
///////////////////////////////////////////////////////////////////////////////
typedef s32 MSCError;
    
#define MSC_ERROR_OK                            0
#define MSC_ERROR_NOT_OPEN                      -1
#define MSC_ERROR_ALREADY_OPEN                  -2
#define MSC_ERROR_FIRMWARE_VERSION              -3
#define MSC_ERROR_FIRMWARE_MALFUNCTION          -4
#define MSC_ERROR_BUSY                          -5
#define MSC_ERROR_COMMAND_IN_PROGRESS           -6                      

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

} MSCDeviceDescriptor;


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

} MSCConfigurationDescriptor;


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

} MSCInterfaceDescriptor;


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

} MSCEndpointDescriptor;


// SCSI inquiry
typedef struct
{

    // ***** bit field may be compiler dependent *****


    u8  peripheral_qualifier    : 3;
    u8  peripheral_device_type  : 5;

    u8  rmb                     : 1;
    u8  device_type_modifier    : 7;

    u8  iso_version             : 2;
    u8  ecma_version            : 3;
    u8  ansi_approved_version   : 3;

    u8  aec                     : 1;
    u8  trm_iop                 : 1;
    u8  reserved_0              : 2;
    u8  response_data_format    : 4;

    u8  additional_length;
    u8  reserved_1;
    u8  reserved_2;

    u8  rel_adr                 : 1;
    u8  w_bus_32                : 1;
    u8  w_bus_16                : 1;
    u8  sync                    : 1;
    u8  linked                  : 1;
    u8  reserved_3              : 1;
    u8  cmd_queue               : 1;
    u8  sft_re                  : 1;

} MSCInquiry;


// client gets reference to one of these on attach
typedef struct
{

    s32                         fd;
    u16                         vid;
    u16                         pid;
    u8                          iInterface;
    u8                          endpoint_address_0;
    u8                          endpoint_address_1;
    volatile u8                 inst;

    MSCDeviceDescriptor         *p_mdd;
    MSCConfigurationDescriptor  *p_mcd;
    MSCInterfaceDescriptor      *p_mid;
    MSCEndpointDescriptor       *p_med0;
    MSCEndpointDescriptor       *p_med1;

    MSCInquiry                  inquiry[8];     // per LUN
    u32                         scratch_pad[8];
    u32                         max_lun;
    u32                         block_size;

    volatile int                command_flag;
    u32                         command_tag;
    void                        *p_user;
    void                        *p_command;

    u32                         pad[2];

} MSCDevice;


///////////////////////////////////////////////////////////////////////////////
typedef struct _MSCClient MSCClient;

typedef int (*MSCAttachHandler)(
                        MSCClient   *p_mc,
                        MSCDevice   *p_md,   
                        u32         attach
                        );

struct _MSCClient
{

    MSCClient           *next;
    MSCAttachHandler    attachHandler;
    void				*p_user;

};


///////////////////////////////////////////////////////////////////////////////
// setup and teardown
typedef void (*MSCSetupHandler)(MSCError me, void *p_user);

MSCError MSCOpenAsync(
                void *mem,
                MSCSetupHandler msh,
                void            *p_user
                );

MSCError MSCCloseAsync(
                MSCSetupHandler msh,
                void            *p_user
                );

// client registration
typedef void (*MSCClientHandler)(MSCError me, void *p_user);

MSCError MSCRegisterClient(
                MSCClient       *p_mc,
                MSCAttachHandler mah
                );
 
MSCError MSCUnregisterClientAsync(
                MSCClient       *p_mc,
                MSCClientHandler mch,
                void            *p_user
                ); 

// MSC runtime APIs
typedef void (*MSCDoneHandler)(
                MSCDevice       *p_md,   
                MSCError        me,
                u8              csw_status,
                u8              *p_data,
                u32             bytes,
                void            *p_user
                );

//////////////////////////////////////////////////////////////////////////////
// USB
typedef struct
{

    char str[256];

} MSCDeviceString;

MSCError MSCGetAsciiStringAsync(
                MSCDevice       *p_md,   
                u8              index,
                MSCDeviceString *p_mds,
                MSCDoneHandler  mdh,
                void            *p_user
                );

MSCError MSCResetDeviceAsync(
                MSCDevice       *p_md,
                MSCDoneHandler  mdh,
                void            *p_user
                );

typedef struct
{

    u8 max_lun;
    u8 pad[31];

} MSCDeviceMaxLun;

MSCError MSCGetMaxLUNAsync(
                MSCDevice       *p_md,
                MSCDeviceMaxLun *p_mdml,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
// SCSI commands
//////////////////////////////////////////////////////////////////////////////
MSCError MSCTestUnitReadyAsync(
                MSCDevice       *p_md,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
typedef struct
{

    u8 data[19];
    u8 pad[13];

} MSCScsiSense;

MSCError MSCRequestSenseAsync(
                MSCDevice       *p_md,
                u8              lun,
                MSCScsiSense    *p_mss,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCFormatUnitAsync(
                MSCDevice       *p_md,
                u8              lun,
                MSCDoneHandler  mdh,
                void            *p_user
                );

                             
//////////////////////////////////////////////////////////////////////////////
typedef struct
{

    u8 data[8];
    u8 pad[24]; 

} MSCScsiInquiry;
                
MSCError MSCInquiryAsync(
                MSCDevice       *p_md,
                u8              lun,
                MSCScsiInquiry  *p_msi,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCModeSelect6Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            pf,
                BOOL            sp,
                u8              parameter_list_length,
                u8              *p_data,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCModeSense6Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            dbd,
                u8              pc,
                u8              page_code,
                u8              allocation_length,
                u8              *p_data,
                MSCDoneHandler  mdh,
                void            *p_user
                );




//////////////////////////////////////////////////////////////////////////////
MSCError MSCStartStopUnitAsync(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            immediate_return,
                BOOL            load_eject,
                BOOL            start,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
typedef struct
{

    u32 total_blocks;
    u32 block_length;
    u8  pad[24];

} MSCScsiCapacity;


MSCError MSCReadCapacityAsync(
                MSCDevice       *p_md,
                u8              lun,
                MSCScsiCapacity *p_msc,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCRead10Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            dpo,
                BOOL            fua,
                BOOL            rel_adr,
                u32             lba,
                u8              *p_data,
                u16             blocks,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCWrite10Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            dpo,
                BOOL            fua,
                BOOL            ebp,
                BOOL            rel_adr,
                u32             lba,
                u8              *p_data,
                u16             blocks,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCVerifyAsync(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            dpo,
                BOOL            byt_chk,
                BOOL            rel_adr,
                u32             lba,
                u16             blocks,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCSynchronizeCacheAsync(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            immed,
                BOOL            rel_adr,
                u32             lba,
                u16             blocks,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCModeSelect10Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            pf,
                BOOL            sp,
                u16             parameter_list_length,
                u8              *p_data,
                MSCDoneHandler  mdh,
                void            *p_user
                );


//////////////////////////////////////////////////////////////////////////////
MSCError MSCModeSense10Async(
                MSCDevice       *p_md,
                u8              lun,
                BOOL            llbaa,
                BOOL            dbd,
                u8              pc,
                u8              page_code,
                u16             allocation_length,
                u8              *p_data,
                MSCDoneHandler  mdh,
                void            *p_user
                );


/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif
#endif  // __MSC_H__
