/*---------------------------------------------------------------------------*
  Project:  Revolution WFS library
  File:     wfs.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.85  2008/01/10 09:34:35  nakanose_jin
  bye - WFSExitAsync

  Revision 1.84  2007/12/12 19:58:56  paul
  Clarified WFSSearchDirectoryFirst spec - handle is not created when an error occurs.

  Revision 1.83  2007/12/12 07:45:08  paul
  Added WFSGetFileSizeAsync - WFSGetFileSize is no longer implemented on the client side

  Revision 1.82  2007/12/08 00:01:57  paul
  Updated the comment for WFS_RESULT_LIB_NOT_INITIALIZED

  Revision 1.81  2007/11/27 02:58:20  nakanose_jin
  add extern "C"

  Revision 1.80  2007/11/22 09:40:05  nakanose_jin
  Add WFS_RESULT_NOT_FILE for WFSFileOpen

  Revision 1.79  2007/11/22 01:48:29  paul
  Added nFileSize to WFSCloseFileAsync

  Revision 1.78  2007/11/21 22:15:41  paul
  Added WFS_RESULT_ALREADY_MOUNTED

  Revision 1.77  2007/11/20 00:16:34  paul
  Removed WFS_RESULT_BUSY from WFSGetFilePosition, WFSSetFilePosition, WFSGetFileSize.

  Revision 1.76  2007/11/16 13:12:04  nakanose_jin
  modify comment for NOT_FOUND

  Revision 1.75  2007/11/16 02:33:57  paul
  Changed error code for WFSMountDevice(). Now, trying to mount the same device twice results in WFS_RESULT_ALREADY_EXISTS error.

  Revision 1.74  2007/11/16 01:29:21  paul
  Added WFSFlush()

  Revision 1.73  2007/11/15 23:40:42  paul
  Updated device name errors to WFS_RESULT_NOT_FOUND

  Revision 1.72  2007/11/09 01:18:37  paul
  Updated validation error checks for several functions
  Updated max path depth

  Revision 1.71  2007/11/02 00:34:38  paul
  now logging updates.
  Changed WFSReadFileAsync, WFSWriteFileAsync to require explicit start position

*---------------------------------------------------------------------------*/

#ifndef __WFS_H__
#define __WFS_H__

// ---------------------------------------------------------------------
// wfs.h - Wii File System (WFS) API
// ---------------------------------------------------------------------

// Provides a standard interface to the Wii file system

#include <revolution.h>
#include <revolution/wfstypes.h>

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
// WFS error codes
// ---------------------------------------------------------------------
typedef enum {
    WFS_RESULT_OK                  =    0,  // Success

    // Errors that can usually be detected early, and if detected, would result in the Async callback not being called:
    WFS_RESULT_BUSY                =   -1,  // Too many requests, try waiting then calling again.
    WFS_RESULT_OUT_OF_MEMORY       =   -2,  // The library does not have enough memory to complete the requested operation. (May be due to too many outstanding aysnc calls).
    WFS_RESULT_INVALID             =   -3,  // The function parameters were invalid, e.g. File name is too long, Path is too long or too deep.
    WFS_RESULT_ACCESS              =   -4,  // Trying to write to a file which was opened for read-only access, or vice versa.
    WFS_RESULT_LIB_NOT_INITIALIZED =   -5,  // The WFS library has not been initialized. Please call WFSInit() (This error is checked in functions that require the library to be initialized, but only in the debug versions).
    WFS_RESULT_LIB_ALREADY_INITIALIZED = -6,  // The WFS library has already been initialized.
    WFS_RESULT_FILE_TOO_BIG        =   -7,  // The current write/append request would push the file over the size limit.
    WFS_RESULT_NO_CHANGE_SIZE      =   -8,  // The requested operation would cause the file size to change, but this file has WFS_PERM_NO_CHANGE_SIZE flag set.

    // Errors that cannot usually be detected early, and would be passed via nResult to the Async callbacks:
    WFS_RESULT_MEDIA_ERROR         =   -9,  // The device or media is not attached, or was removed before the requested operation could be completed.
    WFS_RESULT_DEV_UNUSABLE        =  -10,  // Attached device is not accessible, e.g. because it is an unsupported device, or has an unknown format.
    WFS_RESULT_DEV_NOT_INITIALIZED =  -11,  // Device not formatted, or does not yet contain a WFS volume
    WFS_RESULT_VOL_ID_ERROR        =  -12,  // Attempted to mount a volume with the same unique Id as an already mounted volume (This could happen if the User backs up an entire WFS volume using a PC)
    WFS_RESULT_WRITE_PROTECTED     =  -13,  // Device is physically write protected (e.g. USB Flash memory, SD Card)
    WFS_RESULT_ALREADY_MOUNTED     =  -14,  // The device is already mounted

    WFS_RESULT_PERMISSION          =  -15,  // Permission flags do not permit the requested access from this application.
    WFS_RESULT_INHERITANCE         =  -16,  // Trying to set permissions for a file which are incompatible with its parent directory.
    WFS_RESULT_AUTHENTICATION      =  -17,  // Trying to access content on a different Wii, which does not have the required access rights.
    WFS_RESULT_CORRUPTION          =  -18,  // A corrupted block was encountered which prevented the operation from being completed.

    WFS_RESULT_DIRECTORY_FULL      =  -19,  // This directory already contains the maximum number of entries. //ToDo: May not need this error
    WFS_RESULT_DIRECTORY_QUOTA     =  -20,  // One of the ancestor directories would exceed its quota.
    WFS_RESULT_DEV_FULL            =  -21,  // The storage device does not have enough free space to complete the requested operation.

    WFS_RESULT_MAX_HANDLES         =  -22,  // The maximum number of concurrent file handles / search handles are already in use.
    WFS_RESULT_ALREADY_EXISTS      =  -23,  // The file or directory being created already exists.
    WFS_RESULT_NOT_FOUND           =  -24,  // The specified file or directory or device does not exist.
    WFS_RESULT_NOT_EMPTY           =  -25,  // The specified directory cannot be deleted because it is not empty.
    WFS_RESULT_NOT_FILE            =  -26,  // The specified path is directory not a file.
    WFS_RESULT_FILE_OPEN           =  -27,  // The file is open. Cannot delete, move, rename, change permissions of an open file. Cannot open a file more than once unless all opens are WFS_ACCESS_READ.
    WFS_RESULT_LOCKED              =  -28,  // Cannot access the requested file or directory since it is locked or it's parent directory is locked by an existing operation.
    WFS_RESULT_RESOURCE_LIMIT_EXCEEDED = -29,  // A resource limit prevents this function call. Try smaller values.

    WFS_RESULT_NOT_IMPLEMENTED     = -126,  // The requested function has not yet been implemented  //ToDo: This error should be removed from the final API
    WFS_RESULT_UNKNOWN             = -127,  // Unexpected error - could be caused by a bug in the file system.
    WFS_RESULT_FATAL_ERROR         = -128   // May be caused by critical metadata corruption.

} WFSResult;


// ---------------------------------------------------------------------
// WFS devices
// ---------------------------------------------------------------------

// Possible WFS device states:
//  1. Valid - valid WFS volume exists
//  2. Unusable - bad device
//  3. Unknown format (e.g., FAT12, NTFS, HFS)
//  4. Uninitialized - recognized format (FAT32), but not enough free space for a WFS volume

// Whenever a compatible device is attached, we check to see if a WFS volume already exists. If not,
// we try to create it automatically. If it is not created, then the device must not have enough space.

#define WFS_DEVFLAG_UNUSABLE        1       // Device is unusable (e.g. unknown format, unsupported device)
#define WFS_DEVFLAG_WRITE_PROTECTED 2       // Device is physically write protected
#define WFS_DEVFLAG_NOT_INITIALIZED 4       // Device not formatted or does not yet contain a WFS volume
#define WFS_DEVFLAG_NOT_MOUNTED     8       // Device has not yet been mounted

// ToDo: Can we force this enum to be u8?
typedef enum {
    WFS_DEVTYPE_NONE    = 0x00,
    WFS_DEVTYPE_SD      = 0x01,
    WFS_DEVTYPE_USB_MSC = 0x02
} WFSDevType;

typedef struct {
    u64        nDevTotalCapacity;   // Total capacity of underlying device in bytes
    u8         nDevType;            // One of WFS_DEVTYPE_*
    u8         nDevFlags;           // Combination of WFS_DEVFLAG_*
} WFSDeviceInfo;

// ToDo: Should consider the case of users making an exact copy of a WFS volume causing two devices to
// have the same "unique" device Id. This may be an unavoidable problem.
// We can return WFS_RESULT_VOL_ID_ERROR if we attempt to mount a device with the same Id as an existing device.

// ---------------------------------------------------------------------
// WFS callback types
// ---------------------------------------------------------------------
typedef void (*WFSResultCallback          )(WFSResult nResult, void *pUserData);
typedef void (*WFSDeviceCallback          )(const utf8 *sDeviceName, void *pUserData); // For attach/detach callbacks
typedef void (*WFSDeviceInfoCallback      )(WFSResult nResult, const utf8 *sDeviceName, WFSDeviceInfo *pDi, void *pUserData);
typedef void (*WFSDeviceVolumeCallback    )(WFSResult nResult, const utf8 *sDeviceName, utf8 *sVolumeId, void *pUserData);
typedef void (*WFSUnmountVolumeCallback   )(WFSResult nResult, const utf8 *sVolumeId, void *pUserData);
typedef void (*WFSInitializeDeviceCallback)(WFSResult nResult, const utf8 *sDeviceName, void *pUserData);
typedef void (*WFSFileOpCallback          )(WFSResult nResult, WFSFileHandle fh, void *pUserData);
typedef void (*WFSGetFileSizeCallback     )(WFSResult nResult, u32 nFileSize, WFSFileHandle fh, void *pUserData);
typedef void (*WFSReadFileCallback        )(s32 nResultOrNumBytesRead, WFSFileHandle fh, void *pUserData);
typedef void (*WFSGetFreeSpaceCallback    )(WFSResult nResult, u64 nSize, void *pUserData);
typedef void (*WFSGetAttributesCallback   )(WFSResult nResult, const WFSFileAttributes *pFa, void *pUserData);
typedef void (*WFSSearchDirectoryCallback )(WFSResult nResult, WFSSearchDirectoryHandle sdh, const WFSFileInfo *pFi, void *pUserData);
typedef void (*WFSSearchDirectoryCloseCallback)(WFSResult nResult, WFSSearchDirectoryHandle sdh, void *pUserData);


//--------------------------------------------------------------------------------------------------------------
// WFSInit
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSInit(void *pWorkSpaceBuffer, u32 nWorkSpaceSize);
// Arguments:
// ----------
// pWorkSpaceBuffer    .. Points to a workspace buffer that will be used by WFS as workspace. Must be 64 Byte aligned.
// nWorkSpaceSize      .. The size of the workspace buffer. Must be >= WFS_MIN_WORK_SPACE_SIZE.
//
// Return Values:
// --------------
// Possible return values for WFSSetCurrentDirectory:
//      WFS_RESULT_OK                  .. WFS has been successfully initialized
//      WFS_RESULT_LIB_ALREADY_INITIALIZED .. WFS library has already been initialized.
//      WFS_RESULT_INVALID             .. The input parameters are invalid
//
// Description:
// ------------
// Call this function to initialize the WFS library.
// NOTE: If an attach callback has been registered using WFSSetAttachDeviceCallback,
// it will be called for any existing attached devices during the processing of WFSInit



//--------------------------------------------------------------------------------------------------------------
// WFSExit, WFSExitAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSExit();

// Arguments:
// ----------
// none
//
// Return Values:
// --------------

// Possible return values for WFSExit:
//      WFS_RESULT_OK                      .. Successfully mounted the device. VolumeId has been added to the /vol directory.
//      WFS_RESULT_BUSY                    .. Too many requests, try waiting then calling again.
//      WFS_RESULT_LIB_NOT_INITIALIZED     .. The WFS library has not been initialized.
// Possible immediate return values for WFSExitAsync:
//      WFS_RESULT_OK                      .. WFSMountDevice request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                    .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY           .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_LIB_NOT_INITIALIZED     .. The WFS library has not been initialized.
// Possible values of nResult passed to WFSExitAsync callback:
//     WFS_RESULT_OK                       .. WFS has been successfully terminated
//
// Description:
// ------------
// Waits until all outstanding operations have been completed, then closes the library and frees up
// the workspace memory specified in WFSInit. No further WFS calls can be made until the library
// is re-initialized.



//--------------------------------------------------------------------------------------------------------------
// WFSSetAttachDeviceCallback
//--------------------------------------------------------------------------------------------------------------
void WFSSetAttachDeviceCallback(utf8 *sDeviceNameBuffer, WFSDeviceCallback cbAttachDevice, void *pUserData);
// Arguments:
// ----------
// sDeviceNameBuffer   .. A pointer to a buffer of at least WFS_MAX_DEVICE_NAME_SIZE+1 bytes which will be overwritten with the
//                        NULL terminated device name, and passed to the callback. (output)
// cbAttachDevice      .. A pointer to the function to call when a storage device is attached.
// pUserData           .. Arbitrary user data that is passed to the callback function.
//
// Return Values:
// --------------
// None.
//
// Description:
// ------------
// This function is used to register callback functions for notification of storage devices or
// storage media being attached.
//
// NOTE: Already attached devices can be enumerated by passing "/dev/*" as the search pattern to WFSSearchDirectoryFirst.



//--------------------------------------------------------------------------------------------------------------
// WFSGetAttachDeviceCallback
//--------------------------------------------------------------------------------------------------------------
void WFSGetAttachDeviceCallback(utf8 **psDeviceName, WFSDeviceCallback *pCbAttachDevice, void **ppUserData);
// Arguments:
// ----------
// psDeviceName        .. A pointer to a variable to receive the current value of the sDeviceNameBuffer pointer
//                        that was previously set using WFSSetAttachDeviceCallback.
// pCbAttachDevice     .. A pointer to a variable to receive the current callback function pointer.
// ppUserData          .. A pointer to a variable to receive the current user data pointer.
//
// Return Values:
// --------------
// None.
//
// Description:
// ------------
// This function is used to get information about the existing callback functions for notification of
// storage devices or storage media being attached. The information can be saved and restored later,
// or can be used to implement callback chaining.
// ("Callback chaining" means calling the old callback function from within the new callback function).



//--------------------------------------------------------------------------------------------------------------
// WFSSetDetachDeviceCallback
//--------------------------------------------------------------------------------------------------------------
void WFSSetDetachDeviceCallback(utf8 *sDeviceNameBuffer, WFSDeviceCallback cbDetachDevice, void *pUserData);
// Arguments:
// ----------
// sDeviceName         .. A pointer to a buffer of at least WFS_MAX_DEVICE_NAME_SIZE+1 bytes, which is overwritten
//                        with the NULL terminated device name, and passed to the callback. (output)
// cbDetachDevice      .. A pointer to the function to call when a storage device is detached.
// pUserData           .. Arbitrary user data that is passed to the callback function.
//
// Return Values:
// --------------
// None.
//
// Description:
// ------------
// This function is used to register callback functions for notification of storage devices or
// storage media being detached.



//--------------------------------------------------------------------------------------------------------------
// WFSGetDetachDeviceCallback
//--------------------------------------------------------------------------------------------------------------
void WFSGetDetachDeviceCallback(utf8 **psDeviceName, WFSDeviceCallback *pCbDetachDevice, void **ppUserData);
// Arguments:
// ----------
// psDeviceName        .. A pointer to a variable to receive the current value of the sDeviceName pointer
//                        that was previously set using WFSSetDetachDeviceCallback.
// pCbDetachDevice     .. A pointer to a variable to receive the current callback function pointer.
// ppUserData          .. A pointer to a variable to receive the current user data pointer.
//
// Return Values:
// --------------
// None.
//
// Description:
// ------------
// This function is used to get information about the existing callback functions for notification of
// storage devices or storage media being detached. The information can be saved and restored later,
// or can be used to implement callback chaining.
// ("Callback chaining" means calling the old callback function from within the new callback function).



//--------------------------------------------------------------------------------------------------------------
// WFSGetDeviceInfo, WFSGetDeviceInfoAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetDeviceInfo     (const utf8 *sDeviceName, WFSDeviceInfo *pDi);
WFSResult WFSGetDeviceInfoAsync(const utf8 *sDeviceName, WFSDeviceInfo *pDi, void *pUserData, WFSDeviceInfoCallback cb);
// Arguments:
// ----------
// sDeviceName         .. A pointer to the NULL terminated device name. (input)
// pDi                 .. A pointer to a WFSDeviceInfo struct to receive the requested device information. (output)
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a device callback function.
//
// Return Values:
// --------------
// Possible return values for WFSGetDeviceInfo:
//      WFS_RESULT_OK                  .. Successfully retrieved the device information. *pDi has been updated.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
// Possible immediate return values for WFSGetDeviceInfoAsync:
//      WFS_RESULT_OK                  .. GetDeviceInfo request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid.
// Possible values of nResult passed to WFSGetDeviceInfoAsync callback:
//      WFS_RESULT_OK                  .. Successfully retrieved the device information. *pDi has been updated.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
//
// Description:
// ------------
// These functions return the device information associated with a device name.



//--------------------------------------------------------------------------------------------------------------
// WFSMountDevice, WFSMountDeviceAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSMountDevice     (const utf8 *sDeviceName, utf8 *sVolumeIdBuffer);
WFSResult WFSMountDeviceAsync(const utf8 *sDeviceName, utf8 *sVolumeIdBuffer, void *pUserData, WFSDeviceVolumeCallback cb);
// Arguments:
// ----------
// sDeviceName         .. A pointer to the NULL terminated device name. (input)
// sVolumeIdBuffer     .. A pointer to a buffer of at least WFS_MAX_VOLUME_ID+1 bytes which will be overwritten with the
//                        NULL terminated volume id. (output)
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a device callback function.
//
// Return Values:
// --------------
// Possible return values for WFSMountDevice:
//      WFS_RESULT_OK                  .. Successfully mounted the device. VolumeId has been added to the /vol directory.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sDeviceName is too long, sVolumeIdBuffer is NULL.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_DEV_UNUSABLE        .. Device is not accessible, e.g. because it is an unsupported device, or has an unknown format.
//      WFS_RESULT_DEV_NOT_INITIALIZED .. Device not formatted, or does not yet contain a WFS volume
//      WFS_RESULT_VOL_ID_ERROR        .. Device has the same Id as an already mounted device. (This could happen if the User backs up an entire WFS volume using a PC)
//      WFS_RESULT_ALREADY_MOUNTED     .. The device is already mounted.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
// Possible immediate return values for WFSMountDeviceAsync:
//      WFS_RESULT_OK                  .. WFSMountDevice request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sDeviceName is too long, sVolumeIdBuffer is NULL.
// Possible values of nResult passed to WFSMountDeviceAsync callback:
//      WFS_RESULT_OK                  .. Successfully mounted the device. VolumeId has been added to the /vol directory.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_DEV_UNUSABLE        .. Device is not accessible, e.g. because it is an unsupported device, or has an unknown format.
//      WFS_RESULT_DEV_NOT_INITIALIZED .. Device not formatted, or does not yet contain a WFS volume
//      WFS_RESULT_VOL_ID_ERROR        .. Device has the same Id as an already mounted device. (This could happen if the User backs up an entire WFS volume using a PC)
//      WFS_RESULT_ALREADY_MOUNTED     .. The device is already mounted.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName
//
// Description:
// ------------
// These functions are used to mount a WFS volume. 
// The mount point is "/vol/VolumeId" as described in "WFS Path Names".



//--------------------------------------------------------------------------------------------------------------
// WFSUnmountVolume, WFSUnmountVolumeAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSUnmountVolume     (const utf8 *sVolumeId);
WFSResult WFSUnmountVolumeAsync(const utf8 *sVolumeId, void *pUserData, WFSUnmountVolumeCallback cb);
// Arguments:
// ----------
// sVolumeId           .. pointer to a string buffer containing the mounted Volume Id.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a device callback function.
//
// Return Values:
// --------------
// Possible return values for WFSUnmountVolume:
//      WFS_RESULT_OK                  .. Successfully unmounted the device. The Volume Id has been removed from the "/vol" directory.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. sVolumeId is too long, or NULL.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_FILE_OPEN           .. The volume cannot be closed because one or more files within it are currently open.
//      WFS_RESULT_NOT_FOUND           .. No mounted volume exists which matches sVolumeId.
// Possible immediate return values for WFSUnmountVolumeAsync:
//      WFS_RESULT_OK                  .. WFSMountDevice request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. sVolumeId is too long, or NULL.
// Possible values of nResult passed to WFSUnmountVolumeAsync callback:
//      WFS_RESULT_OK                  .. Successfully unmounted the device. The Volume Id has been removed from the "/vol" directory.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_FILE_OPEN           .. The volume cannot be closed because one or more files within it are currently open.
//      WFS_RESULT_NOT_FOUND           .. No mounted volume exists which matches sVolumeId
//
// Description:
// ------------
// These functions are used to unmount a WFS volume.



//--------------------------------------------------------------------------------------------------------------
// WFSInitializeDevice, WFSInitializeDeviceAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSInitializeDevice     (const utf8 *sDeviceName);
WFSResult WFSInitializeDeviceAsync(const utf8 *sDeviceName, void *pUserData, WFSInitializeDeviceCallback cb);
// Arguments:
// ----------
// sDeviceName         .. A pointer to the NULL terminated device name.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a device callback function.
//
// Return Values:
// --------------
// Possible return values for WFSInitializeDevice:
//      WFS_RESULT_OK                  .. Initialization was successful.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid. e.g. sDeviceName is too long, or NULL.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_DEV_UNUSABLE        .. Unable to initialize device.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. The device may not be initialized by the calling application.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
// Possible immediate return values for WFSInitializeDeviceAsync:
//      WFS_RESULT_OK                  .. Initialization request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid. e.g. sDeviceName is too long, or NULL.
// Possible values of nResult passed to WFSInitializeDeviceAsync callback:
//      WFS_RESULT_OK                  .. Initialization was successful.
//      WFS_RESULT_DEV_UNUSABLE        .. Unable to initialize device.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. The device may not be initialized by the calling application.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
//
// Description:
// ------------
// These functions can be used to initialize a device (format, and create a WFS volume on the device).
// When the volume is created it is assigned a (relatively) unique Volume Id.



//--------------------------------------------------------------------------------------------------------------
// WFSGetVolumeId, WFSGetVolumeIdAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetVolumeId     (const utf8 *sDeviceName, utf8 *sVolumeIdBuffer);
WFSResult WFSGetVolumeIdAsync(const utf8 *sDeviceName, utf8 *sVolumeIdBuffer, void *pUserData, WFSDeviceVolumeCallback cb);
// Arguments:
// ----------
// sDeviceName         .. A pointer to the NULL terminated device name. (input)
// sVolumeIdBuffer     .. A pointer to a buffer of at least WFS_MAX_VOLUME_ID+1 bytes which will be overwritten with the volume id. (output)
// pDi                 .. A pointer to a WFSDeviceInfo struct to receive the requested device information. (output)
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a device callback function.
//
// Return Values:
// --------------
// Possible return values for WFSGetVolumeId:
//      WFS_RESULT_OK                  .. Successfully retrieved the device information. *sVolumeId has been updated. (In all other cases sVolumeId is unchanged)
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid. e.g. sDeviceName is too long or NULL, sVolumeIdBuffer is NULL.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_DEV_NOT_INITIALIZED .. No WFS volume exists on the device.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
// Possible immediate return values for WFSGetVolumeIdAsync:
//      WFS_RESULT_OK                  .. GetDeviceInfo request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sDeviceName is too long or NULL, sVolumeIdBuffer is NULL.
// Possible values of nResult passed to WFSGetVolumeIdAsync callback:
//      WFS_RESULT_OK                  .. Successfully retrieved the device information. *sVolumeId has been updated. (In all other cases sVolumeId is unchanged)
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_DEV_NOT_INITIALIZED .. No WFS volume exists on the device.
//      WFS_RESULT_NOT_FOUND           .. No attached device exists which matches sDeviceName.
//
// Description:
// ------------
// These functions can be used to determine if a volume exists, and if so retrieve the volume id. 



//--------------------------------------------------------------------------------------------------------------
// WFSGetFreeSpaceSize, WFSGetFreeSpaceSizeAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetFreeSpaceSize     (const utf8 *sPathName, u64 *pSize);
WFSResult WFSGetFreeSpaceSizeAsync(const utf8 *sPathName, void *pUserData, WFSGetFreeSpaceCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of a file or directory.
//                        See "WFS Path Names" for rules about path names.
// pSize               .. A pointer to a u64 to receive the free space size value.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSGetFreeSpaceSizeAsync.
//
// Return Values:
// --------------
// Possible return values for WFSGetFreeSpaceSize
//      WFS_RESULT_OK                  .. Successfully calculated the free space size.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sPathName is too long, too deep, or NULL; or pSize is NULL.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_NOT_FOUND           .. The specified path does not exist.
// Possible immediate return values for WFSGetFreeSpaceSizeAsync:
//      WFS_RESULT_OK                  .. GetDeviceInfo request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sPathName is too long, too deep, or NULL.
// Possible values of nResult passed to WFSGetDeviceInfoAsync callback:
//      WFS_RESULT_OK                  .. Successfully calculated the free space size.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the operation completed.
//      WFS_RESULT_NOT_FOUND           .. The specified path does not exist.
//
// Description:
// ------------
// Use this function to calculate the number of bytes free on the device associated with a path name.
// The result also depends on the TitleId of the calling process, since titles would typically have
// a fixed storage quota assigned.
//
// Examples:
// Applying these functions to "/vol/VolumeId/tmp" would return the remaining free space quota
// of the shared tmp directory.
// Applying these functions to "/vol/VolumeId/titles/CompanyId/TitleId", would
// return the remaining free space quota of the title's home directory.
// Applying these functions to "/vol/VolumeId/" would return the sum of the
// free space quotas of the shared tmp directory, and the title's home directory.



//--------------------------------------------------------------------------------------------------------------
// WFSSetHomeDirectory, WFSSetHomeDirectoryAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSetHomeDirectory     (const utf8 *sAbsPathName);
WFSResult WFSSetHomeDirectoryAsync(const utf8 *sAbsPathName, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sAbsPathName        .. absolute path name to a valid directory.
// pUserData           .. arbitrary user data that is passed to the callback function.
// cb                  .. pointer to a callback function to receive the result of WFSCreateDirectoryAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSetHomeDirectory:
//      WFS_RESULT_OK                  .. The directory is valid, and prepared for access.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. sAbsPathName was invalid: e.g. too long, too deep, NULL, or not a directory.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_PERMISSION          .. This funtion is only available to SYSTEM.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to access directory.
//      WFS_RESULT_NOT_FOUND           .. The specified directory does not exist.
// Possible immediate return values for WFSSetHomeDirectoryAsync:
//      WFS_RESULT_OK                  .. SetCurrentDirectory request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. sAbsPathName was invalid: e.g. too long, too deep, or NULL.
// Possible values of nResult passed to WFSSetHomeDirectoryAsync callback:
//      WFS_RESULT_OK                  .. The directory is valid, and prepared for access.
//      WFS_RESULT_INVALID             .. sAbsPathName was invalid: e.g. not a directory.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_PERMISSION          .. This funtion is only available to SYSTEM.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to access directory.
//      WFS_RESULT_NOT_FOUND           .. The specified directory does not exist.
//
// Description:
// ------------
// Sets the internal home directory which can be used at the start of relative path names as ~/
// This function will check that the specified directory exists.
// This function is intended for use by the application launcher.



//--------------------------------------------------------------------------------------------------------------
// WFSSetCurrentDirectory, WFSSetCurrentDirectoryAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSetCurrentDirectory     (const utf8 *sPathName);
WFSResult WFSSetCurrentDirectoryAsync(const utf8 *sPathName, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sPathName           .. absolute or relative path name to a valid directory.
//                        See "WFS Path Names" for rules about path names.
// pUserData           .. arbitrary user data that is passed to the callback function.
// cb                  .. pointer to a callback function to receive the result of WFSCreateDirectoryAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSetCurrentDirectory:
//      WFS_RESULT_OK                  .. The directory is valid, and prepared for access.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. sPathName was invalid: e.g. too long, too deep, NULL, or not a directory.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_PERMISSION          .. Permission flags do not permit access to this directory from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to access directory.
//      WFS_RESULT_NOT_FOUND           .. The specified directory does not exist.
// Possible immediate return values for WFSSetCurrentDirectoryAsync:
//      WFS_RESULT_OK                  .. SetCurrentDirectory request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. sPathName was invalid: e.g. too long, too deep, or NULL.
// Possible values of nResult passed to WFSSetCurrentDirectoryAsync callback:
//      WFS_RESULT_OK                  .. The directory is valid, and prepared for access.
//      WFS_RESULT_INVALID             .. sPathName was invalid: e.g. not a directory.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_PERMISSION          .. Permission flags do not permit access to this directory from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to access directory.
//      WFS_RESULT_NOT_FOUND           .. The specified directory does not exist.
//
// Description:
// ------------
// Sets the internal current directory which is used to resolve relative path names.
// This function will check that the specified directory exists and is accessable to the current application.



//--------------------------------------------------------------------------------------------------------------
// WFSGetCurrentDirectory
//--------------------------------------------------------------------------------------------------------------
s32 WFSGetCurrentDirectory(utf8 *sAbsPathNameBuffer, s32 nBufferSize);
// Arguments:
// ----------
// sAbsPathNameBuffer  .. A pointer to a buffer to receive a copy of the absolute path name of the Current Directory.
// nBufferSize         .. size of the buffer.
//
// Return Values:
// --------------
//      >0                             .. nBufferSize was not large enough. This is the number of bytes required to hold
//                                        the path name of the current directory including the terminating NULL character.
//      WFS_RESULT_OK                  .. The absolute path name of the current directory was copied to the user buffer.
//      WFS_RESULT_INVALID             .. The input parameters were invalid, e.g. sAbsPathNameBuffer is NULL.
//      WFS_RESULT_LIB_NOT_INITIALIZED .. The WFS library has not been initialized. Please call WFSInit(..)
//
// Description:
// ------------
// Copies the current directory to the buffer pointed to by sAbsPathName.
// nBufferSize should contain the size of the buffer including terminating NULL character.



//--------------------------------------------------------------------------------------------------------------
// WFSCreateDirectory, WFSCreateDirectoryAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSCreateDirectory     (const utf8 *sPathName, u32 nFlags, u64 nQuota);
WFSResult WFSCreateDirectoryAsync(const utf8 *sPathName, u32 nFlags, u64 nQuota, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of the directory that is to be created.
//                        See "WFS Path Names" for rules about path names.
// nFlags              .. should be a combination of the permission flags: WFS_PERM_*
//                        Note: WFS_FLAG_DIRECTORY will be set whether it is included or not.
// nQuota              .. This parameter that can be used to restrict the total size of the hierarchy beneath the
//                        new directory. A quota of 0 means there is no size restriction, i.e. the quota is Infinity.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSCreateDirectoryAsync.
//
// Return Values:
// --------------
// Possible return values for WFSCreateDirectory:
//      WFS_RESULT_OK                  .. The directory was created.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Path is too deep. (For directories the depth limit is 1 less than for files).
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory do not permit WRITE access to this application.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions for the new directory which are incompatible with its parent directory.
//      WFS_RESULT_AUTHENTICATION      .. Could occur when writing to a directory belonging to another App, whose access key no longer exists.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to create the directory.
//      WFS_RESULT_DIRECTORY_FULL      .. The parent directory already contains the maximum number of entries.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name already exists.
//      WFS_RESULT_NOT_FOUND           .. Could not find the parent directory specified in the path name.
// Possible immediate return values for WFSCreateDirectoryAsync:
//      WFS_RESULT_OK                  .. CreateDirectory request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Path is too deep. (For directories the depth limit is 1 less than for files).
// Possible values of nResult passed to WFSCreateDirectoryAsync callback:
//      WFS_RESULT_OK                  .. The directory was created.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory do not permit WRITE access to this application.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions for the new directory which are incompatible with its parent directory.
//      WFS_RESULT_AUTHENTICATION      .. Could occur when writing to a directory belonging to another App, whose access key no longer exists.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to create the directory.
//      WFS_RESULT_DIRECTORY_FULL      .. The parent directory already contains the maximum number of entries.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name already exists.
//      WFS_RESULT_NOT_FOUND           .. Could not find the parent directory specified in the path name.
//
// Description:
// ------------
// Use these functions to create directories.



//--------------------------------------------------------------------------------------------------------------
// WFSCreateAndOpenFile, WFSCreateAndOpenFileAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSCreateAndOpenFile     (const utf8 *sPathName, u32 nFlags, WFSContentIdx nCidx, WFSFileSize nPreAllocateSize, WFSFileHandle *pFh);
WFSResult WFSCreateAndOpenFileAsync(const utf8 *sPathName, u32 nFlags, WFSContentIdx nCidx, WFSFileSize nPreAllocateSize, void *pUserData, WFSFileOpCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of the file that is to be created and opened.
//                        See "WFS Path Names" for rules about path names.
// nFlags              .. should be a combination of the permission flags: WFS_PERM_*
//                        Note: This function will always open the file for writing, even if nFlags==WFS_PERM_OWNER_READ_ONLY.
//                              The specified permissions only take effect after the file is closed, and opened again.
// nCidx               .. The content idx of the file being created. Content idx is the unit of access control for purchased content.
//                        For game-save or temporary files, set nCidx to 0. Files having nCidx >0 is referred to as "Content".
//                        Content can only be written to a directory marked with the WFS_FLAG_CONTENT flag.
// nPreAllocateSize    .. The amount of disk-space to pre-allocate for the file. This can be used to assist the file system
//                        with reducing disk fragamentation. If the eventual size is unknown, set nPreAllocateSize to 0.
//                        nPreAllocateSize can be used in conjunction with the NO_CHANGE_SIZE flag to allocate a fixed size file.
// pFh                 .. A pointer to a file handle which is passed back by the library.
//                        The file handle should be used to specify this file in subsequent file operations.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSCreateAndOpenFileAsync.
//
// Return Values:
// --------------
// Possible return values for WFSCreateAndOpenFile:
//      WFS_RESULT_OK                  .. The file was created.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Filename is too long, Path is too deep.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent file handles already in use. (Too many files open).
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory do not permit WRITE access to this application.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions for the new file which are incompatible with its parent directory.
//      WFS_RESULT_AUTHENTICATION      .. Could occur when writing to a directory belonging to another App, whose access key no longer exists.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to create the file.
//      WFS_RESULT_DIRECTORY_FULL      .. This directory already contains the maximum number of entries. //ToDo: May not need this error.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name already exists.
//      WFS_RESULT_NOT_FOUND           .. Could not find the parent directory specified in the path name.
// Possible immediate return values for WFSCreateAndOpenFileAsync:
//      WFS_RESULT_OK                  .. CreateAndOpen request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Filename is too long, Path is too deep.
// Possible values of nResult passed to WFSCreateAndOpenFileAsync callback:
//      WFS_RESULT_OK                  .. The file was created.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent file handles already in use. (Too many files open).
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory do not permit WRITE access to this application.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions for the new file which are incompatible with its parent directory.
//      WFS_RESULT_AUTHENTICATION      .. Could occur when writing to a directory belonging to another App, whose access key no longer exists.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to create the file.
//      WFS_RESULT_DIRECTORY_FULL      .. This directory already contains the maximum number of entries.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name already exists.
//      WFS_RESULT_NOT_FOUND           .. Could not find the parent directory specified in the path name.
//
// Description:
// ------------
// Use these functions to create and open new files.
// These functions cannot be used to overwrite existing files (or directories). Use WFSDelete first.
// Note: This function will always open the file for writing, even if nFlags==WFS_PERM_OWNER_READ_ONLY.
//       The specified permissions only take effect after the file is closed, and opened again.



//--------------------------------------------------------------------------------------------------------------
// WFSGetAttributes, WFSGetAttributesAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetAttributes     (const utf8 *sPathName, WFSFileAttributes *pFa);
WFSResult WFSGetAttributesAsync(const utf8 *sPathName, WFSFileAttributes *pFa, void *pUserData, WFSGetAttributesCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of a file or directory.
//                        See "WFS Path Names" for rules about path names.
// pFa                 .. A pointer to a WFSFileAttributes struct which will be overwritten with the details of the specified file or directory.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSGetAttributesAsync.
//
// Return Values:
// --------------
// Possible return values for WFSGetAttributes:
//      WFS_RESULT_OK                  .. The specified file or directory was found. Details are returned in *pFi.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name too long, Path is too deep.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. Permission flags of the target or its parent directory do not permit requested access from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory was not found.
// Possible immediate return values for WFSGetAttributesAsync:
//      WFS_RESULT_OK                  .. The request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name too long, Path is too deep.
// Possible values of nResult passed to WFSGetAttributesAsync callback:
//      WFS_RESULT_OK                  .. The specified file or directory was found. Details are returned in *pFi.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. Permission flags of the target or its parent directory do not permit requested access from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory was not found.
//
// Description:
// ------------
// Use these functions to read the attributes of a file or directory.



//--------------------------------------------------------------------------------------------------------------
// WFSChangePermissions, WFSChangePermissionsAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSChangePermissions     (const utf8 *sPathName, u32 nFlags, u32 nMask);
WFSResult WFSChangePermissionsAsync(const utf8 *sPathName, u32 nFlags, u32 nMask, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of the file or directory whose permissions are to be changed.
//                        See "WFS Path Names" for rules about path names.
// nFlags              .. The new permissions flags that are to be set. Should be a combination of the permission flags: WFS_PERM_*
// nMask               .. The mask determines which flags will be changed. NewAttributes = (OldAttributes & ~nMask) | (nFlags & nMask)
//                        NOTE: The mask bits for bits which are never allowed to be changed, such as WFS_FLAG_IS_A_DIRECTORY and
//                              WFS_FLAG_CONTENT_DIRECTORY are automatically set to 0.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSChangePermissionsAsync.
//
// Return Values:
// --------------
// Possible return values for WFSChangePermissions:
//      WFS_RESULT_OK                  .. The permissions were updated successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Only the owner of a file or directory can change its permission flags.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions which are incompatible with the parent directory, or children in the case of a directory.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory does not exist.
//      WFS_RESULT_FILE_OPEN           .. Cannot change permissions of an open file.
// Possible immediate return values for WFSChangePermissionsAsync:
//      WFS_RESULT_OK                  .. Change permissions request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
// Possible values of nResult passed to WFSChangePermissionsAsync callback:
//      WFS_RESULT_OK                  .. The permissions were updated successfully.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Only the owner of a file or directory can change its permission flags.
//      WFS_RESULT_INHERITANCE         .. Trying to set permissions which are incompatible with the parent directory, or children in the case of a directory.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory does not exist.
//      WFS_RESULT_FILE_OPEN           .. Cannot change permissions of an open file.
//
// Description:
// ------------
// Use these functions to change the permissions of files or directories.



//--------------------------------------------------------------------------------------------------------------
// WFSDelete, WFSDeleteAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSDelete     (const utf8 *sPathName);
WFSResult WFSDeleteAsync(const utf8 *sPathName, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of the file or directory which is to be deleted.
//                        See "WFS Path Names" for rules about path names.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSChangePermissionsAsync.
//
// Return Values:
// --------------
// Possible return values for WFSDelete:
//      WFS_RESULT_OK                  .. Target was deleted successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the delete operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory does not permit WRITE access from this application, or the target has WFS_PERM_NO_DELETE flag set
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory does not exist.
//      WFS_RESULT_NOT_EMPTY           .. Cannot delete a directory that is not empty.
//      WFS_RESULT_FILE_OPEN           .. Cannot delete an open file.
// Possible immediate return values for WFSDeleteAsync:
//      WFS_RESULT_OK                  .. Delete request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
// Possible values of nResult passed to WFSDeleteAsync callback:
//      WFS_RESULT_OK                  .. Target was deleted successfully
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the delete operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the parent directory does not permit WRITE access from this application, or the target has WFS_PERM_NO_DELETE flag set.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_NOT_FOUND           .. The specified file or directory does not exist.
//      WFS_RESULT_NOT_EMPTY           .. Cannot delete a directory that is not empty.
//      WFS_RESULT_FILE_OPEN           .. Cannot delete an open file.
//
// Description:
// ------------
// Use these functions to delete files or directories.
// To delete a file, it must not be open. To delete a directory, it must be empty.



//--------------------------------------------------------------------------------------------------------------
// WFSMoveLocal, WFSMoveLocalAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSMoveLocal     (const utf8 *sSrcPathName, const utf8 *sDstPathName);
WFSResult WFSMoveLocalAsync(const utf8 *sSrcPathName, const utf8 *sDstPathName, void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// sSrcPathName        .. Relative or absolute path to the source file.
// sDstPathName        .. Relative or absolute path to the destination file.
//                        See "WFS Path Names" for rules about path names.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSMoveLocalAsync.
//
// Return Values:
// --------------
// Possible return values for WFSMoveLocal:
//      WFS_RESULT_OK                  .. Target was moved successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Trying to move between different devices, Trying to move a directory to it's own sub-directory, File name is too long, Path is too deep.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the move operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the source or destination parent directories do not permit WRITE access from this application, or the target has WFS_PERM_NO_MOVE flag set.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name as the destination path already exists.
//      WFS_RESULT_NOT_FOUND           .. The specified source file or path does not exist.
//      WFS_RESULT_FILE_OPEN           .. Cannot move or rename an open file, or a directory hirearchy which contains an open file, or open search handle.
// Possible immediate return values for WFSMoveLocalAsync:
//      WFS_RESULT_OK                  .. Move request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Trying to move between different devices, Trying to move a directory to it's own sub-directory, File name is too long, Path is too deep.
// Possible values of nResult passed to WFSMoveLocalAsync callback:
//      WFS_RESULT_INVALID             .. After moving sSrcPathName to the new location, it's deepest descendent path name would be too long, or too deep.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the move operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the source or destination parent directories do not permit WRITE access from this application, or the target has WFS_PERM_NO_MOVE flag set.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered which prevented the operation from being completed.
//      WFS_RESULT_ALREADY_EXISTS      .. A directory or file with the same name as the destination path already exists.
//      WFS_RESULT_NOT_FOUND           .. The specified source file or path does not exist.
//      WFS_RESULT_FILE_OPEN           .. Cannot move or rename an open file, or a directory hirearchy which contains an open file, or open search handle.
//
// Description:
//------------
// Use these functions to move or rename files or directories within the same volume.
// NOTE 1: These functions cannot be used to move a file from one volume to a different volume.
// NOTE 2: Moving or Renaming a file may cause the number of blocks required to store the directory information to increase,
//         therefore errors associated with capacity are possible.



//--------------------------------------------------------------------------------------------------------------
// WFSOpenFile, WFSOpenFileAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSOpenFile     (const utf8 *sPathName, WFSAccess nDesiredAccess, WFSFileHandle *pFh);
WFSResult WFSOpenFileAsync(const utf8 *sPathName, WFSAccess nDesiredAccess, void *pUserData, WFSFileOpCallback cb);
// Arguments:
// ----------
// sPathName           .. Absolute or relative path name of the file which is to be opened.
//                        See "WFS Path Names" for rules about path names.
// nDesiredAccess      .. The kind of access that is required: should be one of the WFS_ACCESS_* options.
// pFh                 .. A pointer to a file handle which is passed back by the library.
//                        The file handle should be used to specify this file in subsequent file operations.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSOpenAsync.
//
// Return Values:
// --------------
// Possible return values for WFSOpen:
//      WFS_RESULT_OK                  .. File was opened successfuly.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent file handles already in use. (Too many files open).
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the open operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Trying to open a file for write access, but device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the target or its parent directory do not permit requested access from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to open the file.
//      WFS_RESULT_NOT_FOUND           .. The specified file or path does not exist.
//      WFS_RESULT_NOT_FILE            .. The specified file is a directory.
//      WFS_RESULT_FILE_OPEN           .. Cannot open a file more than once unless all opens are WFS_ACCESS_READ.
// Possible immediate return values for WFSOpenAsync:
//      WFS_RESULT_OK                  .. Open request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_OUT_OF_MEMORY       .. The library does not have enough memory to dispatch the request. (May be due to too many outstanding aysnc calls).
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. File name is too long, Path is too deep.
// Possible values of nResult passed to WFSOpenAsync callback:
//      WFS_RESULT_OK                  .. File was opened successfuly.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent file handles already in use. (Too many files open).
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the open operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. Trying to open a file for write access, but device is physically write protected (e.g. USB Flash memory, SD Card).
//      WFS_RESULT_PERMISSION          .. Permission flags of the target or its parent directory do not permit requested access from this application.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while trying to open the file.
//      WFS_RESULT_NOT_FOUND           .. The specified file or path does not exist.
//      WFS_RESULT_FILE_OPEN           .. Cannot open a file more than once unless all opens are WFS_ACCESS_READ.
//
// Description:
// ------------
// Use these functions to open files for reading, writing, or both.



//--------------------------------------------------------------------------------------------------------------
// WFSSetFilePosition
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSetFilePosition(WFSFileHandle fh, WFSFileSize nFilePosition);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// nFilePosition       .. The absolute file position to set.
//
// Return Values:
// --------------
// Possible return values for WFSSetFilePosition:
//      WFS_RESULT_OK                  .. The file postion has been updated successfully.
//      WFS_RESULT_INVALID             .. Invalid file handle, or the position specified is beyond the end of the file.
//
// Description:
// ------------
// This function can be used to set the absolute file position of an opened file (i.e. seek). No Async
// version is provided because this function does not need to access the storage device, and returns quickly.
// The file position is used and updated by WFSReadFile, WFSWriteFile, but not WFSReadFileAsync, WFSWriteFileAsync.



//--------------------------------------------------------------------------------------------------------------
// WFSGetFilePosition
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetFilePosition(WFSFileHandle fh, WFSFileSize *pFilePosition);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// pFilePosition       .. A pointer to a variable which will be overwritten with the absolute file position.
//
// Return Values:
// --------------
// Possible return values for WFSGetFilePosition:
//      WFS_RESULT_OK                  .. Success. *pFilePosition contains the absolute file position.
//      WFS_RESULT_INVALID             .. Invalid file handle.
//
// Description:
// ------------
// This function can be used to get the absolute file position of an opened file. No Async version
// is provided because this function does not need to access the storage device, and returns quickly.
// The file position is used and updated by WFSReadFile, WFSWriteFile, but not WFSReadFileAsync, WFSWriteFileAsync.



//--------------------------------------------------------------------------------------------------------------
// WFSGetFileSize, WFSGetFileSizeAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSGetFileSize     (WFSFileHandle fh, WFSFileSize *pFileSize);
WFSResult WFSGetFileSizeAsync(WFSFileHandle fh, void *pUserData, WFSGetFileSizeCallback cb);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// pFileSize           .. A pointer to a variable which will be overwritten with the file size (in Bytes).
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSGetFileSizeAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSetFileSize:
//      WFS_RESULT_OK                  .. Success. *pFileSize contains the file size.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. Invalid file handle.
// Possible immediate return values for WFSGetFileSizeAsync:
//      WFS_RESULT_OK                  .. The command was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_INVALID             .. Invalid file handle.
// Possible values of nResult passed to WFSGetFileSizeAsync callback:
//      WFS_RESULT_OK                  .. Success. The file size is passed in the nFileSize parameter of the callback.
//
// Description:
// ------------
// These functions can be used to get the file size of an opened file.



//--------------------------------------------------------------------------------------------------------------
// WFSReadFile, WFSReadFileAsync
//--------------------------------------------------------------------------------------------------------------
s32       WFSReadFile     (WFSFileHandle fh, void *pFileDataBuffer, s32 nSize);
WFSResult WFSReadFileAsync(WFSFileHandle fh, void *pFileDataBuffer, WFSFileSize nStartPosition, s32 nSize, void *pUserData, WFSReadFileCallback cb);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// pFileDataBuffer     .. Points to a buffer which will be overwritten with data from the file.
// nStartPosition      .. The offset from the start of the file to start reading from. (Async version only).
// nSize               .. The number of bytes to be read.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSReadAsync.
//
// Return Values:
// --------------
// The return value is the number of bytes read, or one of the Error return values:
// Possible return values for WFSRead:
//      >=0                            .. Number of bytes read (May be less than requested if the end of the file is reached)
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle, pFileDataBuffer is NULL.
//      WFS_RESULT_ACCESS              .. The file was opened with WFS_ACCESS_WRITE_ONLY.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the read operation completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while reading the file.
// Possible immediate return values for WFSReadAsync (prior to start of read command):
//      WFS_RESULT_OK                  .. Read request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle, pFileDataBuffer is NULL.
//      WFS_RESULT_ACCESS              .. The file was opened with WFS_ACCESS_WRITE_ONLY.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media has been removed since the file was opened.
// Possible values of nResult passed to WFSReadAsync callback:
//      >=0                            .. Number of bytes read (May be less than requested if the end of the file is reached).
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the read operation completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while reading the file.
//
// Description:
// ------------
// This function is used to read data from a file that has been opened for reading.
// The file position will be advanced by the number of bytes read.
// Note: WFSReadFile automatically advances a file pointer stored within the library, whereas WFSReadFileAsync does not.
//       WFSReadFileAsync requires the start position to be specified in the call.


//--------------------------------------------------------------------------------------------------------------
// WFSWriteFile, WFSWriteFileAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSWriteFile     (WFSFileHandle fh, const void *pFileData, WFSFileSize nSize);
WFSResult WFSWriteFileAsync(WFSFileHandle fh, const void *pFileData, WFSFileSize nStartPosition, WFSFileSize nSize, void *pUserData, WFSFileOpCallback cb);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// pFileData           .. Points to the data to be written to the file.
// nStartPosition      .. The offset from the start of the file to start writing to. (Async version only).
// nSize               .. The number of bytes to be written.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSWriteAsync.
//
// Return Values:
// --------------
// Possible return values for WFSWrite:
//      WFS_RESULT_OK                  .. Write completed successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle, pFileData is NULL.
//      WFS_RESULT_ACCESS              .. The file was opened with WFS_ACCESS_READ.
//      WFS_RESULT_FILE_TOO_BIG        .. This write operation would cause the file to go over the file size limit.
//      WFS_RESULT_NO_CHANGE_SIZE      .. This write operation would cause the file size to increase, but the WFS_PERM_NO_CHANGE_SIZE flag is set.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed since the file was opened
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the write completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while writing to the file.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
// Possible immediate return values for WFSWriteAsync (prior to start of write command):
//      WFS_RESULT_OK                  .. Write request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle, pFileData is NULL.
//      WFS_RESULT_ACCESS              .. The file was opened with WFS_ACCESS_READ.
//      WFS_RESULT_FILE_TOO_BIG        .. This write operation would cause the file to go over the file size limit.
//      WFS_RESULT_NO_CHANGE_SIZE      .. This write operation would cause the file size to increase, but the WFS_PERM_NO_CHANGE_SIZE flag is set.
// Possible values of nResult passed to WFSWriteAsync callback:
//      WFS_RESULT_OK                  .. Write completed successfully.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the write operation completed.
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the write completed .
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while writing to the file.
//      WFS_RESULT_DIRECTORY_QUOTA     .. This operation would cause one of the ancestor directories to exceed its quota.
//      WFS_RESULT_DEV_FULL            .. The disk does not have enough free space to complete the operation.
// 
// Description:
// ------------
// This function is used to write data to a file that has been opened for writing.
// Data will be overwritten or appended to the file, starting from the current cursor position.
// Note: WFSWriteFile automatically advances a file pointer stored within the library, whereas WFSWriteFileAsync does not.
//       WFSWriteFileAsync requires the start position to be specified in the call.



//--------------------------------------------------------------------------------------------------------------
// WFSCloseFile, WFSCloseFileAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSCloseFile     (WFSFileHandle fh, WFSBool bTruncateFlag);
WFSResult WFSCloseFileAsync(WFSFileHandle fh, WFSBool bTruncateFlag, WFSFileSize nFileSize, void *pUserData, WFSFileOpCallback cb);
// Arguments:
// ----------
// fh                  .. The file handle which was returned when the file was opened.
// bTruncateFlag       .. If the file was opened for writing and this flag is set to TRUE, the file will be truncated.
//                        For WFSCloseFile, the current file position becomes the new file size. For WFSCloseFileAsync, nFileSize is used.
//                        If this flag is FALSE, the file will be closed without truncation.
// nFileSize           .. If bTruncateFlag is TRUE, this is the new file size (WFSCloseFileAsync only).
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSCloseAsync.
//
// Return Values:
// --------------
// Possible return values for WFSClose:
//      WFS_RESULT_OK                  .. Close completed successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again. (Can also occur if there are outstanding async read/write operations on this file handle)
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle.
//      WFS_RESULT_ACCESS              .. Trying to truncate the file, but the file was opened with WFS_ACCESS_READ.
//      WFS_RESULT_NO_CHANGE_SIZE      .. Trying to truncate the file, but the file has the WFS_PERM_NO_CHANGE_SIZE flag set.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the close completed.
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the close completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while closing the file.
// Possible immediate return values for WFSCloseAsync:
//      WFS_RESULT_OK                  .. Close request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. fh is not a valid file handle.
//      WFS_RESULT_ACCESS              .. Trying to truncate the file, but the file was opened with WFS_ACCESS_READ.
//      WFS_RESULT_NO_CHANGE_SIZE      .. Trying to truncate the file, but the file has the WFS_PERM_NO_CHANGE_SIZE flag set.
// Possible values of nResult passed to WFSCloseAsync callback:
//      WFS_RESULT_OK                  .. Close completed successfully.
//      WFS_RESULT_MEDIA_ERROR         .. The storage device/media was removed before the close completed.
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the close completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while closing the file.
//
// Description:
// ------------
// This function is used to close a file.
// If the file was opened for writing, it can be truncated by setting bTruncateFlag=TRUE



//--------------------------------------------------------------------------------------------------------------
// WFSFlush, WFSFlushAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSFlush     ();
WFSResult WFSFlushAsync(void *pUserData, WFSResultCallback cb);
// Arguments:
// ----------
// none
//
// Return Values:
// --------------
// Possible return values for WFSFlush:
//      WFS_RESULT_OK                  .. The updates made by the application have been successfully flushed to disk.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the flush completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while flushing the data.
// Possible immediate return values for WFSFlushAsync:
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
// Possible values of nResult passed to WFSFlushAsync callback:
//      WFS_RESULT_OK                  .. The updates made by the application have been successfully flushed to disk.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_WRITE_PROTECTED     .. User physically write protected the device before the flush completed.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while flushing the data.
//
// Description:
// ------------
// This function can be used to guarantee that that operations which have previously completed, have been flushed to disk.
// Because this function can take a significant amount of time, indiscriminate use of this function may adversely affect performance.



//--------------------------------------------------------------------------------------------------------------
// WFSSearchDirectoryFirst, WFSSearchDirectoryFirstAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSearchDirectoryFirst     (const utf8 *sPattern, WFSSearchDirectoryHandle *pSdh, WFSFileInfo *pFi);
WFSResult WFSSearchDirectoryFirstAsync(const utf8 *sPattern, WFSFileInfo *pFi, void *pUserData, WFSSearchDirectoryCallback cb);
// Arguments:
// ----------
// sPattern            .. specifies the search pattern. It can be prefixed by a relative or absolute path specification.
//                        The file name portion (after the last directory separator) can include the following wildcard
//                        characters:
//                                         * to match any sequence of 0 or more characters,
//                                         ? to match any single character.
//
// pSdh                .. A pointer to a WFSSearchDirectoryHandle which is passed back by the library.
//                        This handle should be passed to WFSSearchDirectoryNext or WFSSearchDirectoryNextAsync
//                        to continue the search, or WFSSearchDirectoryClose to finish the search.
// pFi                 .. A pointer to a WFSFileInfo struct which will be overwritten with the details of the
//                        first file which matches the search pattern.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSSearchDirectoryFirstAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSearchDirectoryFirst:
//      WFS_RESULT_OK                  .. At least one file exists which matches the pattern. Details of the first file are returned in *pFi. Only in this case is a search directory handle created.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Directory name too long, Path is too deep.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent search handles already in use.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. This application does not have access to the base directory of the search.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while searching the directory.
//      WFS_RESULT_NOT_FOUND           .. No files were found which matched the search pattern.
// Possible immediate return values for WFSSearchDirectoryFirstAsync:
//      WFS_RESULT_OK                  .. Search request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. Directory name too long, Path is too deep.
// Possible values of nResult passed to WFSSearchDirectoryFirstAsync callback:
//      WFS_RESULT_OK                  .. At least one file exists which matches the pattern. Details of the first file are returned in *pFi. Only in this case is a search directory handle created.
//      WFS_RESULT_MAX_HANDLES         .. Maximum number of concurrent search handles already in use.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. This application does not have access to the base directory of the search.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while searching the directory.
//      WFS_RESULT_NOT_FOUND           .. No files were found which matched the search pattern.
//
// Description:
// ------------
// Use these functions to search a directory for files matching a specific pattern.
// These functions can be used to enumerate attached devices, by passing "/dev/*" as the search pattern. // ToDo: Consider how to handle case of attachement/detachment during such device enumeration.
// These functions do not perform recursive searches of sub directories.
// NOTE: Don't forget to call WFSSearchDirectoryClose() when finished with the search.


//--------------------------------------------------------------------------------------------------------------
// WFSSearchDirectoryNext, WFSSearchDirectoryNextAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSearchDirectoryNext     (WFSSearchDirectoryHandle sdh, WFSFileInfo *pFi);
WFSResult WFSSearchDirectoryNextAsync(WFSSearchDirectoryHandle sdh, WFSFileInfo *pFi, void *pUserData, WFSSearchDirectoryCallback cb);
// Arguments:
// ----------
// sdh                 .. A WFSSearchDirectoryHandle which was created by WFSSearchDirectoryFirst.
// pFi                 .. A pointer to a WFSFileInfo struct which will be overwritten with the details of the
//                        next file which matches the search pattern.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSSearchDirectoryNextAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSearchDirectoryNext:
//      WFS_RESULT_OK                  .. Another file/directory was found which matches the search pattern associated with sdh. It's details are returned in *pFi.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sdh is not a valid search handle.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. This application does not have access to the base directory of the search.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while searching the directory.
//      WFS_RESULT_NOT_FOUND           .. No more files could be found which matched the search pattern.
// Possible immediate return values for WFSSearchDirectoryNextAsync:
//      WFS_RESULT_OK                  .. Search request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sdh is not a valid search handle.
// Possible values of nResult passed to WFSSearchDirectoryNextAsync callback:
//      WFS_RESULT_OK                  .. Another file/directory was found which matches the search pattern associated with sdh. It's details are returned in *pFi.
//      WFS_RESULT_MEDIA_ERROR         .. The device or media is not attached, or was removed before the requested operation could be completed.
//      WFS_RESULT_PERMISSION          .. This application does not have access to the base directory of the search.
//      WFS_RESULT_AUTHENTICATION      .. Trying to access content on a different Wii, which does not have the required access rights.
//      WFS_RESULT_CORRUPTION          .. A corrupted block was encountered while searching the directory.
//      WFS_RESULT_NOT_FOUND           .. No more files were found which matched the search pattern.
//
// Description:
// ------------
// Use these functions to search a directory for the next file matching a previously specified pattern.
// NOTE: Don't forget to call WFSSearchDirectoryClose() when finished with the search.



//--------------------------------------------------------------------------------------------------------------
// WFSSearchDirectoryClose, WFSSearchDirectoryCloseAsync
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSSearchDirectoryClose     (WFSSearchDirectoryHandle sdh);
WFSResult WFSSearchDirectoryCloseAsync(WFSSearchDirectoryHandle sdh, void *pUserData, WFSSearchDirectoryCloseCallback cb);
// Arguments:
// ----------
// sdh                 .. A WFSSearchDirectoryHandle which was returned by WFSSearchDirectoryFirst.
// pUserData           .. Arbitrary user data that is passed to the callback function.
// cb                  .. Pointer to a callback function to receive the result of WFSSearchDirectoryCloseAsync.
//
// Return Values:
// --------------
// Possible return values for WFSSearchDirectoryClose:
// Possible return values for WFSSearchDirectoryClose:
//      WFS_RESULT_OK                  .. The search handle has been closed successfully.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sdh is not a valid search handle.
// Possible immediate return values for WFSSearchDirectoryCloseAsync:
//      WFS_RESULT_OK                  .. The close search handle request was dispatched successfully. The callback will be called in this case only.
//      WFS_RESULT_BUSY                .. Too many requests, try waiting then calling again.
//      WFS_RESULT_INVALID             .. The function parameters were invalid, e.g. sdh is not a valid search handle.
// Possible values of nResult passed to WFSSearchDirectoryCloseAsync callback:
//      WFS_RESULT_OK                  .. The search handle has been closed successfully.
//
// Description:
// ------------
// These functions are used to close a directory search.
// This will free up the memory required to keep track of the search.



#define WFS_DEBUG_SYSTEM_PROCESS_ID  0UL
typedef u32 WFSTitleId;
typedef u16 WFSGroupId;

//--------------------------------------------------------------------------------------------------------------
// WFSDebugSetTitleId
//--------------------------------------------------------------------------------------------------------------
WFSResult WFSDebugSetTitleId(WFSTitleId titleId, WFSGroupId groupId);
// Arguments:
// ----------
// titleId             .. Title Id is assigned per application. Determines the ownership & access permissions of files.
//                        A value of WFS_DEBUG_SYSTEM_PROCESS_ID can be specified for SYSTEM level access to all files.
// groupId             .. Group Id determines the GROUP access to files. Usually corresponds to a Company Id.
//
// Return Values:
// --------------
// Possible return values for WFSDebugSetTitleId:
//      WFS_RESULT_OK                  .. The search handle has been closed successfully.
//      WFS_RESULT_INVALID             .. The function parameters were invalid.
//
// Description:
// ------------
// Allows the application to specify it's WFS Title Id, which will be used to determine access permissions to WFS files.
// NOTE: This function is for testing and debugging purposes only, and will be removed from the final API.
// NOTE: This function only affects WFS. It does not change the real Title Id.
// ToDo: This function should be removed before releasing to developers.


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //define __WFS_H__
