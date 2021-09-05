/*---------------------------------------------------------------------------*
  Project:  Revolution WFS abstraction layer library
  File:     wfacb.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2007/12/17 05:39:15  ooizumi
  Added WFA_COMMAND_GET_LENGTH.

  Revision 1.2  2007/12/11 18:26:57  ooizumi
  Updated.

  Revision 1.1  2007/11/29 05:35:12  ooizumi
  Initial check-in.

  $NoKeywords: $
*---------------------------------------------------------------------------*/

#ifndef __WFACB_H__
#define __WFACB_H__

#include <revolution.h>
#include <private/ga.h>
#include <revolution/wfs.h>
#include <revolution/wfa.h>

#define WFA_COMMAND_OPEN                  1
#define WFA_COMMAND_CREATE_AND_OPEN       2
#define WFA_COMMAND_READ                  3
#define WFA_COMMAND_WRITE                 4
#define WFA_COMMAND_CLOSE                 5
#define WFA_COMMAND_DELETE                6
#define WFA_COMMAND_MOVE                  7
#define WFA_COMMAND_GET_STATUS            8
#define WFA_COMMAND_GET_LENGTH            9
#define WFA_COMMAND_OPEN_DIR             10
#define WFA_COMMAND_OPEN_DIR_EX          11
#define WFA_COMMAND_READ_DIR             12
#define WFA_COMMAND_REWIND_DIR           13
#define WFA_COMMAND_CLOSE_DIR            14
#define WFA_COMMAND_CREATE_DIR           15
#define WFA_COMMAND_SEARCH_DIR           16
#define WFA_COMMAND_CHANGE_DIR           17
#define WFA_COMMAND_GET_FREE_SPACE_SIZE  18

#endif //define __WFACB_H__
