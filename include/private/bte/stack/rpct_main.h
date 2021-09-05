/*****************************************************************************
**
**  Name:           rpct_main.h
**
**  Description:    This file contains the interface to the main task execution
**                  loop and initialization functions of the RPC transport
**                  subsystem.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_MAIN_H
#define RPCT_MAIN_H

/*******************************************************************************
**
** Function         RPCT_Init
**
** Description      Data structure initializations that need to happen before
**                  tasks are run.
**                  
**
** Returns          void
**
*******************************************************************************/
extern void RPCT_Init(void);

/*******************************************************************************
**
** Function         RPCT_Task
**
** Description      This is the main function for the RPC transport subsystem.
**                  It handles GKI events and executes the link layer functions.
**                  Also, it keeps track of the sending state as to whether
**                  there's an RPC packet send-in-progress for either the GKI
**                  message queue or the circular buffer.
**                  
**
** Returns          void
**
*******************************************************************************/
extern void RPCT_Task(UINT32 param);

/*******************************************************************************
**
** Function         RPCT_RpcgenMsg
**
** Description      This function takes an incoming RPC message and passes it
**                  to RPCGEN for execution.  This function is called from
**                  the task which is executing the RPCGEN message, for example
**                  the BTU task.  This function reads a message off the 
**                  RPCGEN message queue. It handles one message at a time
**                  and signals back to the task to handle the next message.
**                  Note that this function frees the buffer
**                  
**
** Returns          void
**
*******************************************************************************/
BT_API extern void RPCT_RpcgenMsg(BT_HDR *p_msg);

#endif /* RPCT_MAIN_H */

