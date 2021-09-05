/*****************************************************************************/
/*                                                                           */
/*  Name:          compress_int.h                                            */
/*                                                                           */
/*  Description:   contains internal compression wrapper definitions         */
/*                                                                           */
/*                                                                           */
/*  Date        Modification                                                 */
/*  ------------------------                                                 */
/*  10/07/01    Ash     Create                                               */
/*                                                                           */
/*                                                                           */
/*  Copyright (c) 1999-2001, Widcomm Inc., All Rights Reserved.              */
/*  Widcomm Bluetooth Core. Proprietary and confidential.                    */
/*****************************************************************************/

#ifndef COMPRESS_INT_H
#define COMPRESS_INT_H
#include <private/bte/stack/bt_types.h>
#include <private/bte/stack/zlib.h>

/* Define the structure that holds the compression data
*/

typedef struct
{
    z_stream    zc;                 /* Compression stream                   */
    z_stream    zd;                 /* Decompression stream                 */
    UINT16      decompr_rem_len;    /* Decompression remaining length       */

} tCOMPRESS_CTRL;


#define	COMPRESSION_TYPE		Z_DEFAULT_COMPRESSION
/*								Z_NO_COMPRESSION		(0)			*/
/*								Z_BEST_SPEED			(1)			*/
/*								Z_BEST_COMPRESSION		(9)			*/
/*								Z_DEFAULT_COMPRESSION	(-1)		*/
#endif


