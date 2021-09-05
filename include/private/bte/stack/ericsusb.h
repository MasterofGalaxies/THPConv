//
// FILE FUNCTION: ERICSUSB Driver Definitions
//
// REVISION HISTORY:
//
// DATE     NAME            REASON
// -------  ------------    ------------
// 11May00  Ilya Faenson    Create original
//
// Copyright (c) 2000 WidComm, Inc.
//
// NOTE: This header is used by both the driver and the apps.
// Driver only definitions are under the ERICSUSB_DRIVER
// conditional compilation.
//
#ifndef _ERICSUSBDR_
#define _ERICSUSBDR_

//
// ERICSUSB Stats
//
typedef struct ERICSUSBStats
{
    // Number of Read IRPs submitted to the USB software stack
    unsigned long reads_submitted;

    // Number of Read IRP completions from the USB software stack
    unsigned long reads_completed;

    // Number of Read IRP completions in error
    unsigned long reads_completed_error;

    // Read frames discarded due to no buffers
    unsigned long reads_disc_nobuf;

    // Bytes received
    unsigned long reads_bytes;

    // Read buffers filled
    unsigned long reads_filled;

    // Number of Event IRPs submitted to the USB software stack
    unsigned long events_submitted;

    // Number of Event IRP completions from the USB software stack
    unsigned long events_completed;

    // Number of Event IRP completions in error
    unsigned long events_completed_error;

    // Event frames discarded due to no buffers
    unsigned long events_disc_nobuf;

    // Bytes received
    unsigned long events_bytes;

    // Event buffers filled
    unsigned long events_filled;

    // Number of Write IRPs submitted
    unsigned long writes_submitted;

    // Number of Write IRPs completed
    unsigned long writes_completed;

    // Number of Write IRPs completed in error
    unsigned long writes_completed_error;

    // Number of Write time-outs
    unsigned long writes_timeout;

    // Number of Writes not submitted due to no room on the tx queue
    unsigned long writes_disc_nobuf;

    // Number of Writes not submitted due to too long data
    unsigned long writes_disc_toolong;

    // Number of Command IRPs submitted
    unsigned long commands_submitted;

    // Number of Command IRPs completed
    unsigned long commands_completed;

    // Number of Command IRPs completed in error
    unsigned long commands_completed_error;

    // Number of Command time-outs
    unsigned long commands_timeout;

    // Number of Commands not submitted due to no room on the tx queue
    unsigned long commands_disc_nobuf;

    // Number of Commands not submitted due to too long data
    unsigned long commands_disc_toolong;

    // Number of configuration request time-outs
    unsigned long configs_timeout;

    // Last error reported by IRP
    unsigned long last_irp_error;

    // Last error reported by URB
    unsigned long last_urb_error;

} ERICSUSBStats, *pERICSUSBStats;

// Apps need to have an additional header included
#ifndef ERICSUSB_DRIVER
#include <winioctl.h>
#endif

//
//              IOCTL Definitions
// Note: this file depends on the file DEVIOCTL.H which contains
// the macro definition for "CTL_CODE" below.  Include that file
// before  you include this one in your source code.

// The base of the IOCTL control codes.
#define ERICSUSB_IOCTL_INDEX  0x089a

#define IOCTL_ERICSUSB_GET_PIPE_INFO     CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+0,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET_DEVICE_DESCRIPTOR CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+1,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET_CONFIGURATION_DESCRIPTOR CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+2,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_PUT CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+3,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_PUT_CMD CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+4,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+5,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET_EVENT CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+6,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET_STATS CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+7,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_CLEAR_STATS CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+8,METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_ERICSUSB_GET_VERSION CTL_CODE(FILE_DEVICE_UNKNOWN,  \
    ERICSUSB_IOCTL_INDEX+9,METHOD_BUFFERED, FILE_ANY_ACCESS)

//
// TBD: Placeholder for future IoControl from other drivers...
//
#define IRP_MN_1 1

// Max driver version length as seen by apps
#define MAX_VERSION_LENGTH 40

// Max number of instances
#define ERICSUSB_MAX_INSTANCES  64

// Defs needed by the ERICSUSB driver only
#ifdef ERICSUSB_DRIVER

#define ERICSUSB_MAXIMUM_TRANSFER_SIZE 3900
#define ERICSUSB_PAGE_SIZE             4096
#define ERICSUSB_MAXIMUM_REQUEST_SIZE  3900
#define ERICSUSB_MAXIMUM_COMMAND_SIZE  3900

//
// Offset in data/event reception.
// Provides room for context info in order to avoid extra copies
//
#define ERICSUSB_OFFSET 4

// Pipe Numbers
#define ERICSUSB_RECEIVE_PIPE 0
#define ERICSUSB_SEND_PIPE    1
#define ERICSUSB_EVENT_PIPE   2

// Number of Receive and Transmit Buffers
#define ERICSUSB_NUM_OF_REC_BUFFERS   20
#define ERICSUSB_NUM_OF_EVENT_BUFFERS 10
#define ERICSUSB_NUM_OF_XMT_BUFFERS   12
#define ERICSUSB_NUM_OF_CMD_BUFFERS   12

// Milliseconds in 100ns units
#define MILLISECONDS              10000

// Write timeout in milliseconds
#define ERICSUSB_WRITE_TIMEOUT      5000

// Command timeout in milliseconds
#define ERICSUSB_CMD_TIMEOUT        5000

// This data structure is used for async transfers, contains
// urb structure, a timer object, pointer to the irp, and a
// callback object for the timer. The timer will be cancelled
// when the USB transfer completes.  The timer use is optional.
typedef struct AsyncTransfer
{
    URB urb;
    KTIMER TimeoutTimer;
    PIRP irp;
    KDPC TimeoutDpc;
    BOOLEAN bTimerExpired;
    PDEVICE_OBJECT deviceObject;
    unsigned char *packet;
    int length;
    int index;
    BOOLEAN used;
    BOOLEAN filled;
} AsyncTransfer, *pAsyncTransfer;

//
// A structure representing the instance information associated with
// this particular device.
//
typedef struct _DEVICE_EXTENSION 
    {
    // physical device object
    PDEVICE_OBJECT PhysicalDeviceObject;        

    // Device object we call when submitting Urbs/Irps to the USB stack
    PDEVICE_OBJECT StackDeviceObject;              

    // configuration handle for the configuration the
    // device is currently in
    USBD_CONFIGURATION_HANDLE ConfigurationHandle;

    // ptr to the USB device descriptor for this device
    PUSB_DEVICE_DESCRIPTOR DeviceDescriptor;

    // we support just one interface
    PUSBD_INTERFACE_INFORMATION Interface;

    // Name buffer for our named Functional device object link
#define ERICSUSB_NAME_MAX 64    
    WCHAR DeviceLinkNameBuffer[ERICSUSB_NAME_MAX];

    // Instance Number
    unsigned long instanceNumber;

    // Read array
    unsigned short readLength[ERICSUSB_NUM_OF_REC_BUFFERS];
    unsigned char *readBufferList;
    AsyncTransfer readIrp;
    unsigned long readIndex;  // app is reading here
    unsigned long readIrpIndex;  // driver is writing here
    KEVENT readEvent;

    // Event array
    unsigned short eventLength[ERICSUSB_NUM_OF_EVENT_BUFFERS];
    unsigned char *eventBufferList;
    AsyncTransfer eventIrp;
    unsigned long eventIndex;  // app is reading here
    unsigned long eventIrpIndex;  // driver is writing here
    KEVENT eventEvent;

    // Write IRP array
    AsyncTransfer writeIrpList[ERICSUSB_NUM_OF_XMT_BUFFERS];
    unsigned long writeIrpIndex;

    // Command IRP array
    AsyncTransfer cmdIrpList[ERICSUSB_NUM_OF_CMD_BUFFERS];
    unsigned long cmdIrpIndex;

    DEVICE_POWER_STATE CurrentDevicePowerState;
    
    // Bus drivers set the appropriate values in this structure
    // in response to IRP_MN_QUERY_CAPABILITIES IRP. Function and
    // filter drivers might alter the capabilities set by the bus
    //  driver.
    DEVICE_CAPABILITIES DeviceCapabilities;

#if 0
    // (not really used for now)
    // Used to save the currently-being-handled system-requested
    // power irp request
    PIRP PowerIrp;
    
    // default power state to power down to on self-suspend
    ULONG PowerDownLevel; 
#endif
    
    // Driver stats
    ERICSUSBStats stats;
    
    // Flags:

    // Make sure we do just one cleanup if both STOP_DEVICE and
    // REMOVE_DEVICE are sent to us
    BOOLEAN NeedCleanup;
    
    // Device is being removed
    BOOLEAN alreadyRemoved;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

#if DBG
#define ERICSUSB_KdPrint(_x_) DbgPrint("ERICSUSB.SYS: "); DbgPrint _x_ ;
#define TRAP() DbgBreakPoint()
#else
#define ERICSUSB_KdPrint(_x_)
#define TRAP()
#endif

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

// Driver Functions
NTSTATUS ERICSUSB_Dispatch(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_PnPDispatch(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_PowerDispatch(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_PrivateDispatch(IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp);
VOID ERICSUSB_Unload(IN PDRIVER_OBJECT DriverObject);
NTSTATUS ERICSUSB_StartDevice(IN  PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_StopDevice(IN  PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_RemoveDevice(IN  PDEVICE_OBJECT DeviceObject);
pAsyncTransfer ERICSUSB_BuildAsyncRequest(IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp, IN BOOLEAN Read, IN PVOID buffer, IN ULONG length, 
    IN pAsyncTransfer pAsyncXfer);
NTSTATUS ERICSUSB_CallUSBD(IN PDEVICE_OBJECT DeviceObject, IN PURB Urb);
NTSTATUS ERICSUSB_PnPAddDevice(IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT PhysicalDeviceObject);
NTSTATUS ERICSUSB_CreateDeviceObject(IN PDRIVER_OBJECT DriverObject,
    IN PDEVICE_OBJECT *DeviceObject, LONG Instance);
NTSTATUS ERICSUSB_ConfigureDevice(IN  PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_Create(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_Close(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_ProcessIOCTL(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS ERICSUSB_SelectInterfaces(IN PDEVICE_OBJECT DeviceObject,
    IN PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    IN PUSBD_INTERFACE_INFORMATION Interface);
VOID ERICSUSB_Cleanup(PDEVICE_OBJECT DeviceObject);
ULONG ERICSUSB_GetDeviceDescriptor(IN PDEVICE_OBJECT DeviceObject,
    PVOID pvOutputBuffer);
ULONG ERICSUSB_GetConfigDescriptor(IN PDEVICE_OBJECT DeviceObject,
    PVOID pvOutputBuffer, ULONG ulLength);
NTSTATUS ERICSUSB_SubmitRead(IN PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_SubmitEvent(IN PDEVICE_OBJECT DeviceObject);
BOOLEAN ERICSUSB_SubmitWrite(IN PDEVICE_OBJECT DeviceObject,
    void *buffer, unsigned long length);
BOOLEAN ERICSUSB_SubmitCmd(IN PDEVICE_OBJECT DeviceObject,
    void *buffer, unsigned long length);
BOOLEAN ERICSUSB_Reset(IN PDEVICE_OBJECT DeviceObject); 
NTSTATUS ERICSUSB_CancelIRPs(IN  PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_ResetPipes(IN  PDEVICE_OBJECT DeviceObject);
BOOLEAN ERICSUSB_ResetPort(IN PDEVICE_OBJECT DeviceObject);
NTSTATUS ERICSUSB_AbortPipes(IN PDEVICE_OBJECT DeviceObject);
VOID ERICSUSB_SyncTimeoutDPC(IN PKDPC Dpc, IN PVOID DeferredContext,
    IN PVOID SystemArgument1, IN PVOID SystemArgument2);
NTSTATUS ERICSUSB_IrpCompletionRoutine(IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp, IN PVOID Context);
VOID ERICSUSB_SetDevicePowerState(IN PDEVICE_OBJECT DeviceObject,
    IN DEVICE_POWER_STATE DeviceState);

#endif // ERICSUSB_DRIVER section

#endif // _ERICSUSBDR_
