/*---------------------------------------------------------------------------*
  Project:  Dolphin boot time apploader interface
  File:     Apploader.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    3     02/08/09 13:08 Hashida
    Added const.
    
    2     4/06/00 8:34p Shiki
    Revised AppInitFunc() prototype.

    1     8/05/99 2:15p Tian
    Initial checkin.  Apploader interface.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/


// Apploader interface prototypes
typedef void  (*AppInitFunc)         ( void (*report)(const char* msg, ...) );
typedef BOOL  (*AppGetNextFunc)      ( void** dest, u32* length, u32* offset );
typedef void* (*AppGetEntryFunc)     ( void );

// Interface discovery API
typedef void  (*AppInterfaceFunc)    ( AppInitFunc*      init,
                                       AppGetNextFunc*   getnext,
                                       AppGetEntryFunc*  getentry );

