/*---------------------------------------------------------------------------*
  Project:  Revolution HD
  File:     vi_conexant.h

  Copyright 2006 - 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef _VI_CONEXANT_H_
#define _VI_CONEXANT_H_

#define CNXT_I2C_W_ADDR     0x88
#define CNXT_I2C_R_ADDR     0x89

// read-only registers
#define VIC_IDVER		0x00
#define VIC_STAT02		0x02
#define VIC_STAT04		0x04
#define VIC_STAT06		0x06

// read-write registers
#define VIC_GPO			0x26
#define VIC_SERIALTEST		0x28
#define VIC_RASTER_SEL_X	0x2e
#define VIC_DIS_CLKO_X		0x30
#define VIC_CSC_SEL_X		0x32
#define VIC_Y_ALTFF_X		0x34
#define VIC_Y_THRESH_X		0x36
#define VIC_H_BLANKI_X		0x38
#define VIC_DIV2_LATCH_X	0x3a	
#define VIC_MCOMPY		0x3c
#define VIC_MCOMPU		0x3e
#define VIC_MCOMPV		0x40
#define VIC_MSC_DB0		0x42
#define VIC_MSC_DB1		0x44
#define VIC_MSC_DB2		0x46
#define VIC_MSC_DB3		0x48
#define VIC_DR_LIMITP		0x4a
#define VIC_DR_LIMITN		0x4c
#define VIC_DR_LIMITPN		0x4e
#define VIC_DB_LIMITP		0x50
#define VIC_DB_LIMITN		0x52
#define VIC_DB_LIMITPN		0x54
#define VIC_FIL4286INCR		0x56
#define VIC_FILFSCONV		0x58
#define VIC_Y_OFF		0x5a
#define VIC_HUE_ADJ		0x5c
#define VIC_XDS_CC_SEL		0x5e
#define VIC_WSSDAT0_X		0x60
#define VIC_WSSDAT1		0x62
#define VIC_WSSDAT2		0x64
#define VIC_WSSINC0		0x66
#define VIC_WSSINC1		0x68	
#define VIC_WSSINC2		0x6a
#define VIC_FLD_MODE_X		0x6c
#define VIC_HSYNOFFSET0		0x6e
#define VIC_HSYNWIDTH_X		0x70
#define VIC_VSYNWIDTH_X		0x74
#define VIC_H_CLK0		0x76
#define VIC_H_ACTIVE		0x78
#define VIC_HSYNC_WIDTH		0x7a
#define VIC_HBURST_BEGIN	0x7c
#define VIC_HBURST_END		0x7e
#define VIC_H_BLANK0		0x80
#define VIC_V_BLANK0		0x82
#define VIC_V_ACTIVE0		0x84
#define VIC_H_CLKO_X		0x86
#define VIC_H_FRACT		0x88
#define VIC_H_CLKI		0x8a
#define VIC_H_BLANKI		0x8c
#define VIC_H_CLKI_X		0x8e
#define VIC_V_LINESI		0x90
#define VIC_V_BLANKI		0x92
#define VIC_V_ACTIVEI		0x94
#define VIC_V_LINESI_X		0x96
#define VIC_V_SCALE0		0x98
#define VIC_V_SCALE1_X		0x9a
#define VIC_PLL_FRACT0		0x9c
#define VIC_PLL_FRACT1		0x9e
#define VIC_PLL_INT_X		0xa0
#define VIC_NI_OUT_X		0xa2
#define VIC_SYNC_AMP		0xa4
#define VIC_BST_AMP		0xa6
#define VIC_MCR			0xa8
#define VIC_MCB			0xaa
#define VIC_MY			0xac
#define VIC_MSC0		0xae
#define VIC_MSC1		0xb0
#define VIC_MSC2		0xb2
#define VIC_MSC3		0xb4
#define VIC_PHASE_OFF		0xb6
#define VIC_CONFIG		0xb8
#define VIC_DACDIS_X		0xba
#define VIC_CCF2B1		0xbc
#define VIC_CCF2B2		0xbe
#define VIC_CCF1B1		0xc0
#define VIC_CCF1B2		0xc2
#define VIC_EN_OUT_X		0xc4	
#define VIC_IN_MODE_X		0xc6
#define VIC_F_SELY_X		0xc8
#define VIC_YATTEN_X		0xca
#define VIC_CATTEN_X		0xcc
#define VIC_OUT_MUX		0xce
#define VIC_CCR_START		0xd0
#define VIC_CC_ADD0		0xd2
#define VIC_CC_ADD1_X		0xd4
#define VIC_LUMADLY_X		0xd6
#define VIC_PROG_SC_X		0xd8

#endif // _VI_CONEXANT_H_
