/*---------------------------------------------------------------------------*
  Project:  Waikiki Multi Channel communication functions
  File:     wkmc.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/01/18 08:50:58  kawaset
  Fixed build error on Linux.

  Revision 1.3  2006/01/18 04:07:55  kawaset
  Renamed WKMCGetSize() to WKMCGetReadableSize().
  Added WKMCGetWritableSize().

  Revision 1.2  2006/01/05 04:10:18  ooizumi
  Added WKMCTick.

  Revision 1.1  2006/01/04 08:03:51  hiratsu
  Header file for Waikiki Multi Channel communication.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WKMC_H__
#define __WKMC_H__

#ifdef linux

#else

#include <private/wk.h>

#endif

#ifdef __cplusplus
extern "C" {
#endif

#define WKMC_CHAN_NAME_LEN_MAX 4 // need multiple of 4
#define WKMC_CHAN_MAX 16

#ifdef linux
  // type definitions
typedef unsigned int   u32;
typedef signed   int   s32;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned char  u8;
typedef signed   char  s8;
#endif

/*
void WKMCInit(void);
-----------------
[Description]
WKMCInit initializes WKMC (multi channel library).

[Arguments]
None.

[Return value]
None.
*/
void WKMCInit(void);

/*
s32 WKMCOpen(const char* devstring, const u8 *wbuf, const u32 lenwbuf, const u8 *rbuf, const u32 lenrbuf);
-----------------
[Description]
WKMCOpen opens a virtual channel on Waikiki. If successful, it
returns a handle value that can be used for actual transfer, etc.
The maximum number of channels that can be opened at the same 
time is 16.

[Arguments]
_devstring_  ::::  a string used in the data packet to distinguish
                   the channel. Both sides of Waikiki (both PC and RVL)
                   should specify the same string.
                     "DI" is reserved for DI HW emulation.
                   For example, use "IPC" for ipc emulation. Any length
                   is OK. 
_wbuf_ ::::::::::  Buffer for the library's internal use. This buffer
                   is used for the "write" direction. Minimum ***
                   bytes should be allocated for the library.
_lenwbuf_ :::::::  The length for the write buffer.
_rbuf_ ::::::::::  Buffer for the library's internal use. This buffer
                   is used for the "read" direction. Minimum ***
                   bytes should be allocated for the library.
_lenrbuf_ :::::::  The length for the read buffer.

[Return value]
If it's greater than or equal to zero, it means the API call was
successful, and the return value means the handle to use the channel.
If it's less than zero, it means an error occurred.
*/
s32 WKMCOpen(const char* devstring, const u8 *wbuf, const u32 lenwbuf, const u8 *rbuf, const u32 lenrbuf);

/*
s32 WKMCGetSize(const s32 handle);
-----------------
WKMCGetSize() inquiries how many bytes arrived for the channel
associated with the handle _handle_.

[Arguments]
_handle_  :::::::  channel to use

[Return value]
If successful, it returns the size of the data arrived.
If not, it returns a negative value.
*/
//s32 WKMCGetSize(const s32 handle);

// WKMCGetReadableSize() inquires how many bytes arrived for the channel.
// WKMCGetWritableSize() inquires how many bytes can be written to the channel.
s32 WKMCGetReadableSize(const s32 handle);
s32 WKMCGetWritableSize(const s32 handle);

/*
s32 WKMCRead(const s32 handle, u8 *data, const u32 len);
-----------------
WKMCRead() reads _len_ bytes from the channel associated with
_handle_, and store the data to _data_. If successful, WKMCRead()
returns the actual number of bytes transferred (should be the same
as _len_).

[Arguments]
_handle_  :::::::  channel to use
_data_ ::::::::::  Buffer to store the data read.
_len_ :::::::::::  The number of bytes to read.

[Return value]
If successful, it returns the actual number of bytes transferred.
(should be the same as _len_). If not, it returns a negative 
value.
*/
s32 WKMCRead(const s32 handle, u8 *data, const u32 len);

/*
s32 WKMCWrite(const s32 handle, const u8 *data, const u32 len);
-----------------
WKMCWrite() writes _len_ bytes of data in the buffer _data_
to the channel associated with _handle_. If successful, WKMCWrite()
writes the actual number of bytes transferred (should be the same
as _len_).

[Arguments]
_handle_  :::::::  channel to use.
_data_ ::::::::::  Data to be sent.
_len_ :::::::::::  The number of bytes to write.

[Return value]
If successful, it returns the actual number of bytes transferred.
(should be the same as _len_). If not, it returns a negative 
value.
*/
s32 WKMCWrite(const s32 handle, const u8 *data, const u32 len);

/*
s32 WKMCClose(const s32 handle);
-----------------
[Description]
WKMCClose closes the channel.

[Arguments]
_handle_  :::::::  channel to close

[Return value]
If successful, zero is returned.
If not, a negative value is returned.
*/
s32 WKMCClose(const s32 handle);

/*
void WKMCTick(void);
-----------------
[Description]
WKMCTick is tick function for WKMC.

[Arguments]
none.

[Return value]
none.
*/
void WKMCTick(void);

#ifdef __cplusplus
}
#endif

#endif  // __WKMC_H__
