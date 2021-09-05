/*****************************************************************************
**
**  Name:           opp_fmt.h
**
**  Description:    This is the interface file for common functions and data 
**                  types used by the optional OPP object formatting functions.
**
**  Copyright (c) 2003-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef OPP_FMT_H
#define OPP_FMT_H

/*****************************************************************************
** Constants
*****************************************************************************/

#define OPP_PROP_OVHD        3

/*****************************************************************************
** Data types
*****************************************************************************/

typedef struct
{
    const char          *p_name;
    UINT8               len;
} tOPP_PARAM;

typedef struct
{
    const char          *p_name;
    const tOPP_PARAM    *p_param_tbl;
    UINT8               len;
} tOPP_PROP_TBL;

typedef struct
{
    const tOPP_PROP_TBL *p_tbl;
    const char          *p_begin_str;
    const char          *p_end_str;
    UINT8               begin_len;
    UINT8               end_len;
    UINT8               min_len;
} tOPP_OBJ_TBL;

/*****************************************************************************
**  Function prototypes
*****************************************************************************/

extern tOPP_STATUS opp_build_obj(const tOPP_OBJ_TBL *p_bld,
                                       UINT8 *p_data, UINT16 *p_len,
                                       tOPP_PROP *p_prop, UINT8 num_prop);

extern tOPP_STATUS opp_parse_obj(const tOPP_OBJ_TBL *p_prs,
                                       tOPP_PROP *p_prop, UINT8 *p_num_prop,
                                       UINT8 *p_data, UINT16 len);

extern tOPP_STATUS opp_parse_next_prop(const tOPP_OBJ_TBL *p_prs, tOPP_PROP *p_prop,
                                       UINT8 **p_data, UINT16 *p_len,
                                       BOOLEAN new_card);

extern UINT8 *opp_scanstr(UINT8 *p, UINT8 *p_end, const char *p_str);

#endif /* OPP_FMT_H */

