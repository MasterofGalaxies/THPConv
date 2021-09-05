/*---------------------------------------------------------------------------*
  Project:  ARAM Queue
  File:     arq.h
 
  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:27  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:06  yasuh-to
  dolphinシースツリーから移植

    
    5     03/08/08 8:02 Dante
    Added ARQCheckInit() to check if the ARQ API is initialized.
    
    4     5/01/01 6:44p Eugene
    Added XXXReset() functions to clear respective init flags. 
    All XXXInit() functions modified to return safely if respective init
    flags are asserted.
    
    3     12/07/00 3:18p Eugene
    Changed alignment to 32bytes for length of DMA xfers.
    
    2     3/14/00 11:44a Eugene
    Corrected prototype for ARQInit(). "blocksize" argument is unused; 
    call ARSetBlockSize() (or whatever) to set DMA block size for
    low-priority
    xfers.
    
    1     3/13/00 6:34p Eugene
    For ARAM Queue Manager
  
  $NoKeywords: $

 *---------------------------------------------------------------------------*/

#ifndef __ARQ_H__
#define __ARQ_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "revolution/ar.h"


/*---------------------------------------------------------------------------*
    misc defines
 *---------------------------------------------------------------------------*/
#define ARQ_DMA_ALIGNMENT       32      // byte alignment for ARAM DMA
#define ARQ_CHUNK_SIZE_DEFAULT  4096    // default chunk size after init

/*---------------------------------------------------------------------------*
    ARQ type definitions for DMA direction
 *---------------------------------------------------------------------------*/
#define ARQ_TYPE_MRAM_TO_ARAM   ARAM_DIR_MRAM_TO_ARAM
#define ARQ_TYPE_ARAM_TO_MRAM   ARAM_DIR_ARAM_TO_MRAM


/*---------------------------------------------------------------------------*
    ARQ priority definitions for DMA request
 *---------------------------------------------------------------------------*/
#define ARQ_PRIORITY_LOW        0
#define ARQ_PRIORITY_HIGH       1

/*---------------------------------------------------------------------------*
    ARQ callback interface
 *---------------------------------------------------------------------------*/
typedef void (*ARQCallback)(u32 pointerToARQRequest);


/*---------------------------------------------------------------------------*
    ARQRequest definition
 *---------------------------------------------------------------------------*/
typedef struct ARQRequest
{

    struct ARQRequest*  next;       // pointer to next in list
    u32             owner;      // user enumerated owner id 
    u32             type;       // DMA direction
    u32             priority;   // priority for transaction
    u32             source;     // address of source
    u32             dest;       // address of destination
    u32             length;     // length in bytes
    ARQCallback     callback;   // user specified callback routine

} ARQRequest;


/*---------------------------------------------------------------------------*
    function prototypes
 *---------------------------------------------------------------------------*/
void    ARQInit                 (void);
void    ARQReset                (void);
void    ARQPostRequest          (ARQRequest* task,
                                 u32         owner,
                                 u32         type,
                                 u32         priority,
                                 u32         source,
                                 u32         dest,
                                 u32         length,
                                 ARQCallback callback
                                );
void    ARQRemoveRequest        (ARQRequest* task);
void    ARQRemoveOwnerRequest   (u32 owner);
void    ARQFlushQueue           (void);
void    ARQSetChunkSize         (u32 size);
u32     ARQGetChunkSize         (void);
BOOL    ARQCheckInit            (void);

#ifdef __cplusplus
}
#endif

#endif // __ARQ_H__ 
