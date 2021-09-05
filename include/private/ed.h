/*---------------------------------------------------------------------------*
  Project: ED Encryption Decryption library
  File:    ed.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law. They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2007/08/17 20:53:46  henrch
  changed title id encoding, now in header

  Revision 1.2  2007/08/16 17:27:46  henrch
  fixed ED_TYPE1_TASK_SIZE, was mis-computed :0

  Revision 1.1  2007/07/23 21:16:01  henrch
  created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/
#include <revolution.h>

#ifndef __ED_H__
#define __ED_H__

#ifdef __cplusplus
extern "C" {
#endif


/*---------------------------------------------------------------------------*
  initial vector length
*---------------------------------------------------------------------------*/
#define ED_INITIAL_VECTOR_BYTES         16

/*---------------------------------------------------------------------------*
  TYPE n definitions
 *---------------------------------------------------------------------------*/

// TYPE 1 definitions
#define ED_TYPE1                        1
#define ED_TYPE1_TASK_SIZE              1024
#define ED_TYPE1_TASK_ALIGNMENT         64
#define ED_TYPE1_INPUT_BUFFER_MIN       32
#define ED_TYPE1_INPUT_BUFFER_MAX       65536
#define ED_TYPE1_PLACEHOLDER_SIZE       832
#define ED_TYPE1_ENCRYPTED_HEADER_SIZE  864

// TYPE 2 definitions
#define ED_TYPE2                        2
#define ED_TYPE2_TASK_SIZE              1024
#define ED_TYPE2_TASK_ALIGNMENT         64
#define ED_TYPE2_INPUT_BUFFER_MIN       32
#define ED_TYPE2_INPUT_BUFFER_MAX       65536
#define ED_TYPE2_PLACEHOLDER_SIZE       832
#define ED_TYPE2_ENCRYPTED_HEADER_SIZE  864

/*---------------------------------------------------------------------------*
  Error codes.
 *---------------------------------------------------------------------------*/
typedef s32 EDError;

#define ED_ERROR_OK                     0   // no error
#define ED_ERROR_ALIGNMENT              1   // ED task buffer 64 byte alignment
#define ED_ERROR_UNKNOWN_TYPE           2   // unknown ED type
#define ED_ERROR_INPUT_BUFFER_SIZE      3   // input buffer size out of bounds
#define ED_ERROR_MISMATCH_TYPE          4   // ED type does not match data
#define ED_ERROR_TITLEID                5   // title ID does not match
#define ED_ERROR_VERIFICATION           6   // verification failed


/*---------------------------------------------------------------------------*
  Callback interface used to notify user to store output data for encrypt or
  verify functions.
 *---------------------------------------------------------------------------*/
typedef void (*EDCallback)
                    (
                     void *task,            // pointer to EDTaskType*
                     u32 offset,            // store data at offset
                     u8 *data,              // pointer to output data
                     u32 bytes,             // length of output data
                     u32 param              // user specified param
                     );

/*---------------------------------------------------------------------------*
  Flags. These symbols are use to flag initial, increment, complete for
  encrypt, verify, and decrypt functions
 *---------------------------------------------------------------------------*/
#define ED_FLAG_INITIAL                 1   // first data
#define ED_FLAG_INCREMENT               2   // add data
#define ED_FLAG_COMPLETE                4   // last data


/*---------------------------------------------------------------------------*
  Initialize EDTask. The user calls this to initialize the EDTask for
  encrypt or decrypt function
 *---------------------------------------------------------------------------*/
EDError ED_InitTask (
                     void *task,            // pointer to ED task buffer
                     u32 type,              // user specified version
                     u8 *initial_vector,    // pointer to user specified iv
                     u32 buffer_size        // user buffer size
                     );

/*---------------------------------------------------------------------------*
  Encrypt. The user calls this to input data to encrypt.
 *---------------------------------------------------------------------------*/
EDError ED_Encrypt  (
                     void *task,            // pointer to ED task buffer
                     u32 flag,              // initial, increment, complete
                     u8 *input,             // pointer to input data
                     u32 bytes,             // length of input data
                     EDCallback callback,   // callback to write output
                     u32 param              // param to pass to callback
                     );

/*---------------------------------------------------------------------------*
  Verify. The user calls this to verify encripted data prior to decript.
 *---------------------------------------------------------------------------*/
EDError ED_Verify   (
                     void *task,            // pointer to ED task buffer
                     u32 flag,              // initial, increment, complete
                     u8 *input,             // pointer to input data
                     u32 bytes              // length of input data
                     );

/*---------------------------------------------------------------------------*
  Decrypt. The user calls this to decrypt verified data.
 *---------------------------------------------------------------------------*/
EDError ED_Decrypt  (
                     void *task,            // pointer to ED task buffer
                     u32 flag,              // initial, increment, complete
                     u8 *input,             // pointer to input data
                     u32 bytes,             // length of input
                     EDCallback callback,   // callback to write output
                     u32 param              // param to pass to callback
                     );

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // __ED_H__