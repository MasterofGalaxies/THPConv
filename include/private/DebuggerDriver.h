/*---------------------------------------------------------------------------*
  Project:  Generic debugger interface
  File:     DebuggerDriver.h

  Copyright 2000 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
 * 
 * 1     05/08/25 13:44 Yone
 * Initial check-in by HUDSON.
  Revision 1.1  2003/02/21 17:01:33  swells
  Initial commit

  Revision 1.1.2.1  2001/06/21 21:52:43  smoore
  * Enabled framing.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
  This file defines a basic interface that TRK uses to communicate to
  the host.  It was made with multichannel communications in mind, so
  "DBOpen" and "DBClose" reflect the opening and closing of the
  "debugger channel"

  When TRK is running (when the application is stopped), it always
  operates in polling mode (using DBQueryData).  When the application
  is running (when TRK is dormant), TRK can only detect input
  from the debugger if interrupt-driven communication is enabled.
  Interrupts are disabled during the first init (called before
  main).  The Dolphin OS will call a second TRK function called
  "EnableMetroTRKInterrupts" in OSInit().  This allows TRK to start
  using interrupt driven communications.
  
  It is OK for these functions to block, but none of these functions
  should allow a context switch.
  
  The I/O functions (DBQueryData, DBRead, and DBWrite) should minimize
  the number of calls they make into the Dolphin OS, because it will
  not be possible to debug any functions they call.  For example, if
  DBRead calls the standard memcpy(), then it will never be possible
  to step into or set a breakpoint in memcpy() from anywhere in the
  system.
  
  The communication is packet-based, and it is important that the
  order, number, and sizes of the packets be preserved.  See the
  comments on DBQueryData, DBRead, and DBWrite for more details.
  
 *---------------------------------------------------------------------------*/

#ifndef __DEBUGGERDRIVER_H__
#define __DEBUGGERDRIVER_H__

#include <dolphin/os.h>

#define     DB_NO_ERROR       0
#define     DB_NOT_OPEN       1


/*---------------------------------------------------------------------------*
  Name:         DBInitComm

  Description:  Initializes the communications channel for polling mode.
                Interrupt communications must wait until the OS is fully
                initialized.

  Arguments:    inputPendingPtrRef
                        The parameter inputPendingPtrRef is used to return
                        a pointer to an InputPending boolean flag. 
                        MetroTRK can then check the status of InputPending
                        to determine whether input has arrived.  The value
                        of the InputPending flag is controlled by the UART
                        driver.  Note that the status of this flag can
                        change at any time unless the serial interrupt is
                        masked.  It is important that the value of
                        InputPending always be correct. 
                        
                cb      Callback for communications interrupt ISR.

  Returns:      None.
 *---------------------------------------------------------------------------*/
typedef void (*DBCallback)( s32, OSContext* );

typedef void DBInitCommType    ( volatile unsigned char ** inputPendingPtrRef,
                                 DBCallback                cb);
DBInitCommType                 DBInitComm;

/*---------------------------------------------------------------------------*
  Name:         DBInitInterrupts

  Description:  Initializes the communications channel for interrupt-driven
                mode.

  Arguments:    None.

  Returns:      None.
 *---------------------------------------------------------------------------*/
typedef void DBInitInterruptsType ( void );
DBInitInterruptsType              DBInitInterrupts;

/*---------------------------------------------------------------------------*
  Name:         DBQueryData

  Description:  Polls communication channel to see if any data arrived.
  				Packet sizes should be preserved, so if the host sends
  				two packets, this function should return the number of
  				bytes remaining to be read in the first packet only. 
  				After the first one has been read (by DBRead()), this
  				function can then return the size of the next one.

  Arguments:    None.

  Returns:      Number of bytes remaining in the next packet waiting to
  				be read.
 *---------------------------------------------------------------------------*/
typedef s32 DBQueryDataType       ( void );
DBQueryDataType                   DBQueryData;

/*---------------------------------------------------------------------------*
  Name:         DBRead

  Description:  Reads /nbytes/ bytes of data and places it into the memory 
                pointed to by /data/.  /nbytes/ may be less than or equal
                to the number of bytes remaining the next packet waiting
                to be read.  A packet is only finished being read after
                all of the bytes have been read from it.  It is an
                error for /nbytes/ to be larger than the number of 
                remaining bytes in the packet.

  Arguments:    data    ptr to buffer
                nbytes  number of bytes to be read.

  Returns:      DB_NO_ERROR or DB_NOT_OPEN
 *---------------------------------------------------------------------------*/
typedef u32 DBReadType            ( void * data, u32 nbytes );
DBReadType                        DBRead;

/*---------------------------------------------------------------------------*
  Name:         DBWrite

  Description:  Writes a packet containing /nbytes/ bytes of data from the
                memory pointed to by /data/ to the communications channel.
                Should not return until the transmission is complete.

  Arguments:    data    ptr to buffer
                nbytes  number of bytes to be written

  Returns:      DB_NO_ERROR or DB_NOT_OPEN
 *---------------------------------------------------------------------------*/
typedef u32 DBWriteType           ( const void * data, u32 nbytes );
DBWriteType                       DBWrite;

/*---------------------------------------------------------------------------*
  Name:         DBOpen

  Description:  Reserves a channel for the debugger.  

  Arguments:    None
                
  Returns:      None
 *---------------------------------------------------------------------------*/
typedef void DBOpenType            ( void );
DBOpenType                         DBOpen;

/*---------------------------------------------------------------------------*
  Name:         DBClose

  Description:  Releases the debugger channel, if any.

  Arguments:    None
                
  Returns:      None
 *---------------------------------------------------------------------------*/
typedef void DBCloseType           ( void );
DBCloseType                        DBClose;

//??          DBGetStatus       ( u16 * reg );

#endif  // __DEBUGGERDRIVER_H__
