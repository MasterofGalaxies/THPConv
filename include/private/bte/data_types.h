/****************************************************************************
**
**  Name        data_types.h
**
**  Function    this file contains common data type definitions used
**              throughout the WIDCOMM Bluetooth code
**
**  Date       Modification
**  -----------------------
**  3/12/99    Create
**  07/27/00   Added nettohs macro for Little Endian
**                                                                         
**  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.
**  Proprietary and confidential.
**
*****************************************************************************/

#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#ifndef NULL
#define NULL     0
#endif

#ifndef FALSE
#define FALSE  0
#endif

typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned long   UINT32;
typedef signed   long   INT32;
typedef signed   char   INT8;
typedef signed   short  INT16;
typedef unsigned char   BOOLEAN;


typedef UINT32          TIME_STAMP;

#ifndef TRUE
#define TRUE   (!FALSE)
#endif

typedef unsigned char   UBYTE;

#ifdef __arm
#define PACKED  __packed
#define INLINE  __inline
#else
#define PACKED
#define INLINE
#endif

#define BIG_ENDIAN FALSE

#define UINT16_LOW_BYTE(x)      ((x) & 0xff)
#define UINT16_HI_BYTE(x)       ((x) >> 8)

#endif
