/*
 *  vi_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from vi_reg.fdl
 */

#ifndef __VI_REG_H__
#define __VI_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  vi_hostreg value
 */
#define VI_VER_TIM	0x00
#define VI_DSP_CFG	0x01
#define VI_HOR_TIM0_U	0x02
#define VI_HOR_TIM0_L	0x03
#define VI_HOR_TIM1_U	0x04
#define VI_HOR_TIM1_L	0x05
#define VI_VER_ODD_TIM_U	0x06
#define VI_VER_ODD_TIM_L	0x07
#define VI_VER_EVN_TIM_U	0x08
#define VI_VER_EVN_TIM_L	0x09
#define VI_ODD_BBLNK_INTVL_U	0x0a
#define VI_ODD_BBLNK_INTVL_L	0x0b
#define VI_EVN_BBLNK_INTVL_U	0x0c
#define VI_EVN_BBLNK_INTVL_L	0x0d
#define VI_PIC_BASE_LFT_U	0x0e
#define VI_PIC_BASE_LFT_L	0x0f
#define VI_PIC_BASE_RGT_U	0x10
#define VI_PIC_BASE_RGT_L	0x11
#define VI_PIC_BASE_LFT_BOT_U	0x12
#define VI_PIC_BASE_LFT_BOT_L	0x13
#define VI_PIC_BASE_RGT_BOT_U	0x14
#define VI_PIC_BASE_RGT_BOT_L	0x15
#define VI_DSP_POS_U	0x16
#define VI_DSP_POS_L	0x17
#define VI_DSP_INT0_U	0x18
#define VI_DSP_INT0_L	0x19
#define VI_DSP_INT1_U	0x1a
#define VI_DSP_INT1_L	0x1b
#define VI_DSP_INT2_U	0x1c
#define VI_DSP_INT2_L	0x1d
#define VI_DSP_INT3_U	0x1e
#define VI_DSP_INT3_L	0x1f
#define VI_DSP_LATCH0_U	0x20
#define VI_DSP_LATCH0_L	0x21
#define VI_DSP_LATCH1_U	0x22
#define VI_DSP_LATCH1_L	0x23
#define VI_PIC_CFG	0x24
#define VI_HSCALE	0x25
#define VI_FLTR_COEFF0_U	0x26
#define VI_FLTR_COEFF0_L	0x27
#define VI_FLTR_COEFF1_U	0x28
#define VI_FLTR_COEFF1_L	0x29
#define VI_FLTR_COEFF2_U	0x2a
#define VI_FLTR_COEFF2_L	0x2b
#define VI_FLTR_COEFF3_U	0x2c
#define VI_FLTR_COEFF3_L	0x2d
#define VI_FLTR_COEFF4_U	0x2e
#define VI_FLTR_COEFF4_L	0x2f
#define VI_FLTR_COEFF5_U	0x30
#define VI_FLTR_COEFF5_L	0x31
#define VI_FLTR_COEFF6_U	0x32
#define VI_FLTR_COEFF6_L	0x33
#define VI_OUTPOL	0x35
#define VI_CLKSEL	0x36
#define VI_DTVSTATUS	0x37
#define VI_WIDTH	0x38
#define VI_HBE656	0x39
#define VI_HBS656	0x3a

/*
 *  vi_hbe656_reg struct
 */
#define VI_HBE656_REG_HBE656_SIZE	10
#define VI_HBE656_REG_HBE656_SHIFT	0
#define VI_HBE656_REG_HBE656_MASK	0x000003ff
#define VI_HBE656_REG_GET_HBE656(vi_hbe656_reg) \
	((((unsigned long)(vi_hbe656_reg)) & VI_HBE656_REG_HBE656_MASK) >> VI_HBE656_REG_HBE656_SHIFT)
#define VI_HBE656_REG_SET_HBE656(vi_hbe656_reg, hbe656) { \
	FDL_ASSERT(!((hbe656) & ~((1 << VI_HBE656_REG_HBE656_SIZE)-1))); \
	vi_hbe656_reg = (((unsigned long)(vi_hbe656_reg)) & ~VI_HBE656_REG_HBE656_MASK) | (((unsigned long)(hbe656)) << VI_HBE656_REG_HBE656_SHIFT);\
}
#define VI_HBE656_REG_PAD0_SIZE	5
#define VI_HBE656_REG_PAD0_SHIFT	10
#define VI_HBE656_REG_PAD0_MASK	0x00007c00
#define VI_HBE656_REG_GET_PAD0(vi_hbe656_reg) \
	((((unsigned long)(vi_hbe656_reg)) & VI_HBE656_REG_PAD0_MASK) >> VI_HBE656_REG_PAD0_SHIFT)
#define VI_HBE656_REG_SET_PAD0(vi_hbe656_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_HBE656_REG_PAD0_SIZE)-1))); \
	vi_hbe656_reg = (((unsigned long)(vi_hbe656_reg)) & ~VI_HBE656_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_HBE656_REG_PAD0_SHIFT);\
}
#define VI_HBE656_REG_BRDR_EN_SIZE	1
#define VI_HBE656_REG_BRDR_EN_SHIFT	15
#define VI_HBE656_REG_BRDR_EN_MASK	0x00008000
#define VI_HBE656_REG_GET_BRDR_EN(vi_hbe656_reg) \
	((((unsigned long)(vi_hbe656_reg)) & VI_HBE656_REG_BRDR_EN_MASK) >> VI_HBE656_REG_BRDR_EN_SHIFT)
#define VI_HBE656_REG_SET_BRDR_EN(vi_hbe656_reg, brdr_en) { \
	FDL_ASSERT(!((brdr_en) & ~((1 << VI_HBE656_REG_BRDR_EN_SIZE)-1))); \
	vi_hbe656_reg = (((unsigned long)(vi_hbe656_reg)) & ~VI_HBE656_REG_BRDR_EN_MASK) | (((unsigned long)(brdr_en)) << VI_HBE656_REG_BRDR_EN_SHIFT);\
}
#define VI_HBE656_REG_TOTAL_SIZE	16
#define VI_HBE656_REG(hbe656, brdr_en) \
	((((unsigned long)(hbe656)) << VI_HBE656_REG_HBE656_SHIFT) | \
	 (((unsigned long)(brdr_en)) << VI_HBE656_REG_BRDR_EN_SHIFT))

typedef struct {
    unsigned long brdr_en:VI_HBE656_REG_BRDR_EN_SIZE;
    unsigned long pad0:VI_HBE656_REG_PAD0_SIZE;
    unsigned long hbe656:VI_HBE656_REG_HBE656_SIZE;
} vi_hbe656_reg_t;

typedef union {
    unsigned long val;
    vi_hbe656_reg_t f;
} vi_hbe656_reg_u;

/*
 *  vi_hbs656_reg struct
 */
#define VI_HBS656_REG_HBS656_SIZE	10
#define VI_HBS656_REG_HBS656_SHIFT	0
#define VI_HBS656_REG_HBS656_MASK	0x000003ff
#define VI_HBS656_REG_GET_HBS656(vi_hbs656_reg) \
	((((unsigned long)(vi_hbs656_reg)) & VI_HBS656_REG_HBS656_MASK) >> VI_HBS656_REG_HBS656_SHIFT)
#define VI_HBS656_REG_SET_HBS656(vi_hbs656_reg, hbs656) { \
	FDL_ASSERT(!((hbs656) & ~((1 << VI_HBS656_REG_HBS656_SIZE)-1))); \
	vi_hbs656_reg = (((unsigned long)(vi_hbs656_reg)) & ~VI_HBS656_REG_HBS656_MASK) | (((unsigned long)(hbs656)) << VI_HBS656_REG_HBS656_SHIFT);\
}
#define VI_HBS656_REG_TOTAL_SIZE	10
#define VI_HBS656_REG(hbs656) \
	((((unsigned long)(hbs656)) << VI_HBS656_REG_HBS656_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long hbs656:VI_HBS656_REG_HBS656_SIZE;
} vi_hbs656_reg_t;

typedef union {
    unsigned long val;
    vi_hbs656_reg_t f;
} vi_hbs656_reg_u;

/*
 *  vi_width_reg struct
 */
#define VI_WIDTH_REG_SRCWIDTH_SIZE	10
#define VI_WIDTH_REG_SRCWIDTH_SHIFT	0
#define VI_WIDTH_REG_SRCWIDTH_MASK	0x000003ff
#define VI_WIDTH_REG_GET_SRCWIDTH(vi_width_reg) \
	((((unsigned long)(vi_width_reg)) & VI_WIDTH_REG_SRCWIDTH_MASK) >> VI_WIDTH_REG_SRCWIDTH_SHIFT)
#define VI_WIDTH_REG_SET_SRCWIDTH(vi_width_reg, srcwidth) { \
	FDL_ASSERT(!((srcwidth) & ~((1 << VI_WIDTH_REG_SRCWIDTH_SIZE)-1))); \
	vi_width_reg = (((unsigned long)(vi_width_reg)) & ~VI_WIDTH_REG_SRCWIDTH_MASK) | (((unsigned long)(srcwidth)) << VI_WIDTH_REG_SRCWIDTH_SHIFT);\
}
#define VI_WIDTH_REG_TOTAL_SIZE	10
#define VI_WIDTH_REG(srcwidth) \
	((((unsigned long)(srcwidth)) << VI_WIDTH_REG_SRCWIDTH_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long srcwidth:VI_WIDTH_REG_SRCWIDTH_SIZE;
} vi_width_reg_t;

typedef union {
    unsigned long val;
    vi_width_reg_t f;
} vi_width_reg_u;

/*
 *  vi_outpol_reg struct
 */
#define VI_OUTPOL_REG_IPOL_SIZE	1
#define VI_OUTPOL_REG_IPOL_SHIFT	0
#define VI_OUTPOL_REG_IPOL_MASK	0x00000001
#define VI_OUTPOL_REG_GET_IPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_IPOL_MASK) >> VI_OUTPOL_REG_IPOL_SHIFT)
#define VI_OUTPOL_REG_SET_IPOL(vi_outpol_reg, ipol) { \
	FDL_ASSERT(!((ipol) & ~((1 << VI_OUTPOL_REG_IPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_IPOL_MASK) | (((unsigned long)(ipol)) << VI_OUTPOL_REG_IPOL_SHIFT);\
}
#define VI_OUTPOL_REG_NPOL_SIZE	1
#define VI_OUTPOL_REG_NPOL_SHIFT	1
#define VI_OUTPOL_REG_NPOL_MASK	0x00000002
#define VI_OUTPOL_REG_GET_NPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_NPOL_MASK) >> VI_OUTPOL_REG_NPOL_SHIFT)
#define VI_OUTPOL_REG_SET_NPOL(vi_outpol_reg, npol) { \
	FDL_ASSERT(!((npol) & ~((1 << VI_OUTPOL_REG_NPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_NPOL_MASK) | (((unsigned long)(npol)) << VI_OUTPOL_REG_NPOL_SHIFT);\
}
#define VI_OUTPOL_REG_KPOL_SIZE	1
#define VI_OUTPOL_REG_KPOL_SHIFT	2
#define VI_OUTPOL_REG_KPOL_MASK	0x00000004
#define VI_OUTPOL_REG_GET_KPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_KPOL_MASK) >> VI_OUTPOL_REG_KPOL_SHIFT)
#define VI_OUTPOL_REG_SET_KPOL(vi_outpol_reg, kpol) { \
	FDL_ASSERT(!((kpol) & ~((1 << VI_OUTPOL_REG_KPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_KPOL_MASK) | (((unsigned long)(kpol)) << VI_OUTPOL_REG_KPOL_SHIFT);\
}
#define VI_OUTPOL_REG_BPOL_SIZE	1
#define VI_OUTPOL_REG_BPOL_SHIFT	3
#define VI_OUTPOL_REG_BPOL_MASK	0x00000008
#define VI_OUTPOL_REG_GET_BPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_BPOL_MASK) >> VI_OUTPOL_REG_BPOL_SHIFT)
#define VI_OUTPOL_REG_SET_BPOL(vi_outpol_reg, bpol) { \
	FDL_ASSERT(!((bpol) & ~((1 << VI_OUTPOL_REG_BPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_BPOL_MASK) | (((unsigned long)(bpol)) << VI_OUTPOL_REG_BPOL_SHIFT);\
}
#define VI_OUTPOL_REG_HPOL_SIZE	1
#define VI_OUTPOL_REG_HPOL_SHIFT	4
#define VI_OUTPOL_REG_HPOL_MASK	0x00000010
#define VI_OUTPOL_REG_GET_HPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_HPOL_MASK) >> VI_OUTPOL_REG_HPOL_SHIFT)
#define VI_OUTPOL_REG_SET_HPOL(vi_outpol_reg, hpol) { \
	FDL_ASSERT(!((hpol) & ~((1 << VI_OUTPOL_REG_HPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_HPOL_MASK) | (((unsigned long)(hpol)) << VI_OUTPOL_REG_HPOL_SHIFT);\
}
#define VI_OUTPOL_REG_VPOL_SIZE	1
#define VI_OUTPOL_REG_VPOL_SHIFT	5
#define VI_OUTPOL_REG_VPOL_MASK	0x00000020
#define VI_OUTPOL_REG_GET_VPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_VPOL_MASK) >> VI_OUTPOL_REG_VPOL_SHIFT)
#define VI_OUTPOL_REG_SET_VPOL(vi_outpol_reg, vpol) { \
	FDL_ASSERT(!((vpol) & ~((1 << VI_OUTPOL_REG_VPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_VPOL_MASK) | (((unsigned long)(vpol)) << VI_OUTPOL_REG_VPOL_SHIFT);\
}
#define VI_OUTPOL_REG_FPOL_SIZE	1
#define VI_OUTPOL_REG_FPOL_SHIFT	6
#define VI_OUTPOL_REG_FPOL_MASK	0x00000040
#define VI_OUTPOL_REG_GET_FPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_FPOL_MASK) >> VI_OUTPOL_REG_FPOL_SHIFT)
#define VI_OUTPOL_REG_SET_FPOL(vi_outpol_reg, fpol) { \
	FDL_ASSERT(!((fpol) & ~((1 << VI_OUTPOL_REG_FPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_FPOL_MASK) | (((unsigned long)(fpol)) << VI_OUTPOL_REG_FPOL_SHIFT);\
}
#define VI_OUTPOL_REG_CPOL_SIZE	1
#define VI_OUTPOL_REG_CPOL_SHIFT	7
#define VI_OUTPOL_REG_CPOL_MASK	0x00000080
#define VI_OUTPOL_REG_GET_CPOL(vi_outpol_reg) \
	((((unsigned long)(vi_outpol_reg)) & VI_OUTPOL_REG_CPOL_MASK) >> VI_OUTPOL_REG_CPOL_SHIFT)
#define VI_OUTPOL_REG_SET_CPOL(vi_outpol_reg, cpol) { \
	FDL_ASSERT(!((cpol) & ~((1 << VI_OUTPOL_REG_CPOL_SIZE)-1))); \
	vi_outpol_reg = (((unsigned long)(vi_outpol_reg)) & ~VI_OUTPOL_REG_CPOL_MASK) | (((unsigned long)(cpol)) << VI_OUTPOL_REG_CPOL_SHIFT);\
}
#define VI_OUTPOL_REG_TOTAL_SIZE	8
#define VI_OUTPOL_REG(ipol, npol, kpol, bpol, hpol, vpol, fpol, cpol) \
	((((unsigned long)(ipol)) << VI_OUTPOL_REG_IPOL_SHIFT) | \
	 (((unsigned long)(npol)) << VI_OUTPOL_REG_NPOL_SHIFT) | \
	 (((unsigned long)(kpol)) << VI_OUTPOL_REG_KPOL_SHIFT) | \
	 (((unsigned long)(bpol)) << VI_OUTPOL_REG_BPOL_SHIFT) | \
	 (((unsigned long)(hpol)) << VI_OUTPOL_REG_HPOL_SHIFT) | \
	 (((unsigned long)(vpol)) << VI_OUTPOL_REG_VPOL_SHIFT) | \
	 (((unsigned long)(fpol)) << VI_OUTPOL_REG_FPOL_SHIFT) | \
	 (((unsigned long)(cpol)) << VI_OUTPOL_REG_CPOL_SHIFT))

typedef struct {
    unsigned long pad0:8;
    unsigned long cpol:VI_OUTPOL_REG_CPOL_SIZE;
    unsigned long fpol:VI_OUTPOL_REG_FPOL_SIZE;
    unsigned long vpol:VI_OUTPOL_REG_VPOL_SIZE;
    unsigned long hpol:VI_OUTPOL_REG_HPOL_SIZE;
    unsigned long bpol:VI_OUTPOL_REG_BPOL_SIZE;
    unsigned long kpol:VI_OUTPOL_REG_KPOL_SIZE;
    unsigned long npol:VI_OUTPOL_REG_NPOL_SIZE;
    unsigned long ipol:VI_OUTPOL_REG_IPOL_SIZE;
} vi_outpol_reg_t;

typedef union {
    unsigned long val;
    vi_outpol_reg_t f;
} vi_outpol_reg_u;

/*
 *  vi_dsp_cfg_reg struct
 */
#define VI_DSP_CFG_REG_ENB_SIZE	1
#define VI_DSP_CFG_REG_ENB_SHIFT	0
#define VI_DSP_CFG_REG_ENB_MASK	0x00000001
#define VI_DSP_CFG_REG_GET_ENB(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_ENB_MASK) >> VI_DSP_CFG_REG_ENB_SHIFT)
#define VI_DSP_CFG_REG_SET_ENB(vi_dsp_cfg_reg, enb) { \
	FDL_ASSERT(!((enb) & ~((1 << VI_DSP_CFG_REG_ENB_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_ENB_MASK) | (((unsigned long)(enb)) << VI_DSP_CFG_REG_ENB_SHIFT);\
}
#define VI_DSP_CFG_REG_RST_SIZE	1
#define VI_DSP_CFG_REG_RST_SHIFT	1
#define VI_DSP_CFG_REG_RST_MASK	0x00000002
#define VI_DSP_CFG_REG_GET_RST(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_RST_MASK) >> VI_DSP_CFG_REG_RST_SHIFT)
#define VI_DSP_CFG_REG_SET_RST(vi_dsp_cfg_reg, rst) { \
	FDL_ASSERT(!((rst) & ~((1 << VI_DSP_CFG_REG_RST_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_RST_MASK) | (((unsigned long)(rst)) << VI_DSP_CFG_REG_RST_SHIFT);\
}
#define VI_DSP_CFG_REG_INT_SIZE	1
#define VI_DSP_CFG_REG_INT_SHIFT	2
#define VI_DSP_CFG_REG_INT_MASK	0x00000004
#define VI_DSP_CFG_REG_GET_INT(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_INT_MASK) >> VI_DSP_CFG_REG_INT_SHIFT)
#define VI_DSP_CFG_REG_SET_INT(vi_dsp_cfg_reg, int) { \
	FDL_ASSERT(!((int) & ~((1 << VI_DSP_CFG_REG_INT_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_INT_MASK) | (((unsigned long)(int)) << VI_DSP_CFG_REG_INT_SHIFT);\
}
#define VI_DSP_CFG_REG_DLR_SIZE	1
#define VI_DSP_CFG_REG_DLR_SHIFT	3
#define VI_DSP_CFG_REG_DLR_MASK	0x00000008
#define VI_DSP_CFG_REG_GET_DLR(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_DLR_MASK) >> VI_DSP_CFG_REG_DLR_SHIFT)
#define VI_DSP_CFG_REG_SET_DLR(vi_dsp_cfg_reg, dlr) { \
	FDL_ASSERT(!((dlr) & ~((1 << VI_DSP_CFG_REG_DLR_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_DLR_MASK) | (((unsigned long)(dlr)) << VI_DSP_CFG_REG_DLR_SHIFT);\
}
#define VI_DSP_CFG_REG_LE0_SIZE	2
#define VI_DSP_CFG_REG_LE0_SHIFT	4
#define VI_DSP_CFG_REG_LE0_MASK	0x00000030
#define VI_DSP_CFG_REG_GET_LE0(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_LE0_MASK) >> VI_DSP_CFG_REG_LE0_SHIFT)
#define VI_DSP_CFG_REG_SET_LE0(vi_dsp_cfg_reg, le0) { \
	FDL_ASSERT(!((le0) & ~((1 << VI_DSP_CFG_REG_LE0_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_LE0_MASK) | (((unsigned long)(le0)) << VI_DSP_CFG_REG_LE0_SHIFT);\
}
#define VI_DSP_CFG_REG_LE1_SIZE	2
#define VI_DSP_CFG_REG_LE1_SHIFT	6
#define VI_DSP_CFG_REG_LE1_MASK	0x000000c0
#define VI_DSP_CFG_REG_GET_LE1(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_LE1_MASK) >> VI_DSP_CFG_REG_LE1_SHIFT)
#define VI_DSP_CFG_REG_SET_LE1(vi_dsp_cfg_reg, le1) { \
	FDL_ASSERT(!((le1) & ~((1 << VI_DSP_CFG_REG_LE1_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_LE1_MASK) | (((unsigned long)(le1)) << VI_DSP_CFG_REG_LE1_SHIFT);\
}
#define VI_DSP_CFG_REG_MODE_SIZE	2
#define VI_DSP_CFG_REG_MODE_SHIFT	8
#define VI_DSP_CFG_REG_MODE_MASK	0x00000300
#define VI_DSP_CFG_REG_GET_MODE(vi_dsp_cfg_reg) \
	((((unsigned long)(vi_dsp_cfg_reg)) & VI_DSP_CFG_REG_MODE_MASK) >> VI_DSP_CFG_REG_MODE_SHIFT)
#define VI_DSP_CFG_REG_SET_MODE(vi_dsp_cfg_reg, mode) { \
	FDL_ASSERT(!((mode) & ~((1 << VI_DSP_CFG_REG_MODE_SIZE)-1))); \
	vi_dsp_cfg_reg = (((unsigned long)(vi_dsp_cfg_reg)) & ~VI_DSP_CFG_REG_MODE_MASK) | (((unsigned long)(mode)) << VI_DSP_CFG_REG_MODE_SHIFT);\
}
#define VI_DSP_CFG_REG_TOTAL_SIZE	10
#define VI_DSP_CFG_REG(enb, rst, int, dlr, le0, le1, mode) \
	((((unsigned long)(enb)) << VI_DSP_CFG_REG_ENB_SHIFT) | \
	 (((unsigned long)(rst)) << VI_DSP_CFG_REG_RST_SHIFT) | \
	 (((unsigned long)(int)) << VI_DSP_CFG_REG_INT_SHIFT) | \
	 (((unsigned long)(dlr)) << VI_DSP_CFG_REG_DLR_SHIFT) | \
	 (((unsigned long)(le0)) << VI_DSP_CFG_REG_LE0_SHIFT) | \
	 (((unsigned long)(le1)) << VI_DSP_CFG_REG_LE1_SHIFT) | \
	 (((unsigned long)(mode)) << VI_DSP_CFG_REG_MODE_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long mode:VI_DSP_CFG_REG_MODE_SIZE;
    unsigned long le1:VI_DSP_CFG_REG_LE1_SIZE;
    unsigned long le0:VI_DSP_CFG_REG_LE0_SIZE;
    unsigned long dlr:VI_DSP_CFG_REG_DLR_SIZE;
    unsigned long int:VI_DSP_CFG_REG_INT_SIZE;
    unsigned long rst:VI_DSP_CFG_REG_RST_SIZE;
    unsigned long enb:VI_DSP_CFG_REG_ENB_SIZE;
} vi_dsp_cfg_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_cfg_reg_t f;
} vi_dsp_cfg_reg_u;

/*
 *  vi_hor_tim0_l_reg struct
 */
#define VI_HOR_TIM0_L_REG_HLW_SIZE	10
#define VI_HOR_TIM0_L_REG_HLW_SHIFT	0
#define VI_HOR_TIM0_L_REG_HLW_MASK	0x000003ff
#define VI_HOR_TIM0_L_REG_GET_HLW(vi_hor_tim0_l_reg) \
	((((unsigned long)(vi_hor_tim0_l_reg)) & VI_HOR_TIM0_L_REG_HLW_MASK) >> VI_HOR_TIM0_L_REG_HLW_SHIFT)
#define VI_HOR_TIM0_L_REG_SET_HLW(vi_hor_tim0_l_reg, hlw) { \
	FDL_ASSERT(!((hlw) & ~((1 << VI_HOR_TIM0_L_REG_HLW_SIZE)-1))); \
	vi_hor_tim0_l_reg = (((unsigned long)(vi_hor_tim0_l_reg)) & ~VI_HOR_TIM0_L_REG_HLW_MASK) | (((unsigned long)(hlw)) << VI_HOR_TIM0_L_REG_HLW_SHIFT);\
}
#define VI_HOR_TIM0_L_REG_TOTAL_SIZE	10
#define VI_HOR_TIM0_L_REG(hlw) \
	((((unsigned long)(hlw)) << VI_HOR_TIM0_L_REG_HLW_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long hlw:VI_HOR_TIM0_L_REG_HLW_SIZE;
} vi_hor_tim0_l_reg_t;

typedef union {
    unsigned long val;
    vi_hor_tim0_l_reg_t f;
} vi_hor_tim0_l_reg_u;

/*
 *  vi_hor_tim0_u_reg struct
 */
#define VI_HOR_TIM0_U_REG_HCE_SIZE	7
#define VI_HOR_TIM0_U_REG_HCE_SHIFT	0
#define VI_HOR_TIM0_U_REG_HCE_MASK	0x0000007f
#define VI_HOR_TIM0_U_REG_GET_HCE(vi_hor_tim0_u_reg) \
	((((unsigned long)(vi_hor_tim0_u_reg)) & VI_HOR_TIM0_U_REG_HCE_MASK) >> VI_HOR_TIM0_U_REG_HCE_SHIFT)
#define VI_HOR_TIM0_U_REG_SET_HCE(vi_hor_tim0_u_reg, hce) { \
	FDL_ASSERT(!((hce) & ~((1 << VI_HOR_TIM0_U_REG_HCE_SIZE)-1))); \
	vi_hor_tim0_u_reg = (((unsigned long)(vi_hor_tim0_u_reg)) & ~VI_HOR_TIM0_U_REG_HCE_MASK) | (((unsigned long)(hce)) << VI_HOR_TIM0_U_REG_HCE_SHIFT);\
}
#define VI_HOR_TIM0_U_REG_PAD0_SIZE	1
#define VI_HOR_TIM0_U_REG_PAD0_SHIFT	7
#define VI_HOR_TIM0_U_REG_PAD0_MASK	0x00000080
#define VI_HOR_TIM0_U_REG_GET_PAD0(vi_hor_tim0_u_reg) \
	((((unsigned long)(vi_hor_tim0_u_reg)) & VI_HOR_TIM0_U_REG_PAD0_MASK) >> VI_HOR_TIM0_U_REG_PAD0_SHIFT)
#define VI_HOR_TIM0_U_REG_SET_PAD0(vi_hor_tim0_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_HOR_TIM0_U_REG_PAD0_SIZE)-1))); \
	vi_hor_tim0_u_reg = (((unsigned long)(vi_hor_tim0_u_reg)) & ~VI_HOR_TIM0_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_HOR_TIM0_U_REG_PAD0_SHIFT);\
}
#define VI_HOR_TIM0_U_REG_HCS_SIZE	7
#define VI_HOR_TIM0_U_REG_HCS_SHIFT	8
#define VI_HOR_TIM0_U_REG_HCS_MASK	0x00007f00
#define VI_HOR_TIM0_U_REG_GET_HCS(vi_hor_tim0_u_reg) \
	((((unsigned long)(vi_hor_tim0_u_reg)) & VI_HOR_TIM0_U_REG_HCS_MASK) >> VI_HOR_TIM0_U_REG_HCS_SHIFT)
#define VI_HOR_TIM0_U_REG_SET_HCS(vi_hor_tim0_u_reg, hcs) { \
	FDL_ASSERT(!((hcs) & ~((1 << VI_HOR_TIM0_U_REG_HCS_SIZE)-1))); \
	vi_hor_tim0_u_reg = (((unsigned long)(vi_hor_tim0_u_reg)) & ~VI_HOR_TIM0_U_REG_HCS_MASK) | (((unsigned long)(hcs)) << VI_HOR_TIM0_U_REG_HCS_SHIFT);\
}
#define VI_HOR_TIM0_U_REG_TOTAL_SIZE	15
#define VI_HOR_TIM0_U_REG(hce, hcs) \
	((((unsigned long)(hce)) << VI_HOR_TIM0_U_REG_HCE_SHIFT) | \
	 (((unsigned long)(hcs)) << VI_HOR_TIM0_U_REG_HCS_SHIFT))

typedef struct {
    unsigned long pad1:1;
    unsigned long hcs:VI_HOR_TIM0_U_REG_HCS_SIZE;
    unsigned long pad0:VI_HOR_TIM0_U_REG_PAD0_SIZE;
    unsigned long hce:VI_HOR_TIM0_U_REG_HCE_SIZE;
} vi_hor_tim0_u_reg_t;

typedef union {
    unsigned long val;
    vi_hor_tim0_u_reg_t f;
} vi_hor_tim0_u_reg_u;

/*
 *  vi_hor_tim1_l_reg struct
 */
#define VI_HOR_TIM1_L_REG_HSY_SIZE	7
#define VI_HOR_TIM1_L_REG_HSY_SHIFT	0
#define VI_HOR_TIM1_L_REG_HSY_MASK	0x0000007f
#define VI_HOR_TIM1_L_REG_GET_HSY(vi_hor_tim1_l_reg) \
	((((unsigned long)(vi_hor_tim1_l_reg)) & VI_HOR_TIM1_L_REG_HSY_MASK) >> VI_HOR_TIM1_L_REG_HSY_SHIFT)
#define VI_HOR_TIM1_L_REG_SET_HSY(vi_hor_tim1_l_reg, hsy) { \
	FDL_ASSERT(!((hsy) & ~((1 << VI_HOR_TIM1_L_REG_HSY_SIZE)-1))); \
	vi_hor_tim1_l_reg = (((unsigned long)(vi_hor_tim1_l_reg)) & ~VI_HOR_TIM1_L_REG_HSY_MASK) | (((unsigned long)(hsy)) << VI_HOR_TIM1_L_REG_HSY_SHIFT);\
}
#define VI_HOR_TIM1_L_REG_HBE_L_SIZE	9
#define VI_HOR_TIM1_L_REG_HBE_L_SHIFT	7
#define VI_HOR_TIM1_L_REG_HBE_L_MASK	0x0000ff80
#define VI_HOR_TIM1_L_REG_GET_HBE_L(vi_hor_tim1_l_reg) \
	((((unsigned long)(vi_hor_tim1_l_reg)) & VI_HOR_TIM1_L_REG_HBE_L_MASK) >> VI_HOR_TIM1_L_REG_HBE_L_SHIFT)
#define VI_HOR_TIM1_L_REG_SET_HBE_L(vi_hor_tim1_l_reg, hbe_l) { \
	FDL_ASSERT(!((hbe_l) & ~((1 << VI_HOR_TIM1_L_REG_HBE_L_SIZE)-1))); \
	vi_hor_tim1_l_reg = (((unsigned long)(vi_hor_tim1_l_reg)) & ~VI_HOR_TIM1_L_REG_HBE_L_MASK) | (((unsigned long)(hbe_l)) << VI_HOR_TIM1_L_REG_HBE_L_SHIFT);\
}
#define VI_HOR_TIM1_L_REG_TOTAL_SIZE	16
#define VI_HOR_TIM1_L_REG(hsy, hbe_l) \
	((((unsigned long)(hsy)) << VI_HOR_TIM1_L_REG_HSY_SHIFT) | \
	 (((unsigned long)(hbe_l)) << VI_HOR_TIM1_L_REG_HBE_L_SHIFT))

typedef struct {
    unsigned long hbe_l:VI_HOR_TIM1_L_REG_HBE_L_SIZE;
    unsigned long hsy:VI_HOR_TIM1_L_REG_HSY_SIZE;
} vi_hor_tim1_l_reg_t;

typedef union {
    unsigned long val;
    vi_hor_tim1_l_reg_t f;
} vi_hor_tim1_l_reg_u;

/*
 *  vi_hor_tim1_u_reg struct
 */
#define VI_HOR_TIM1_U_REG_HBE_U_SIZE	1
#define VI_HOR_TIM1_U_REG_HBE_U_SHIFT	0
#define VI_HOR_TIM1_U_REG_HBE_U_MASK	0x00000001
#define VI_HOR_TIM1_U_REG_GET_HBE_U(vi_hor_tim1_u_reg) \
	((((unsigned long)(vi_hor_tim1_u_reg)) & VI_HOR_TIM1_U_REG_HBE_U_MASK) >> VI_HOR_TIM1_U_REG_HBE_U_SHIFT)
#define VI_HOR_TIM1_U_REG_SET_HBE_U(vi_hor_tim1_u_reg, hbe_u) { \
	FDL_ASSERT(!((hbe_u) & ~((1 << VI_HOR_TIM1_U_REG_HBE_U_SIZE)-1))); \
	vi_hor_tim1_u_reg = (((unsigned long)(vi_hor_tim1_u_reg)) & ~VI_HOR_TIM1_U_REG_HBE_U_MASK) | (((unsigned long)(hbe_u)) << VI_HOR_TIM1_U_REG_HBE_U_SHIFT);\
}
#define VI_HOR_TIM1_U_REG_HBS_SIZE	10
#define VI_HOR_TIM1_U_REG_HBS_SHIFT	1
#define VI_HOR_TIM1_U_REG_HBS_MASK	0x000007fe
#define VI_HOR_TIM1_U_REG_GET_HBS(vi_hor_tim1_u_reg) \
	((((unsigned long)(vi_hor_tim1_u_reg)) & VI_HOR_TIM1_U_REG_HBS_MASK) >> VI_HOR_TIM1_U_REG_HBS_SHIFT)
#define VI_HOR_TIM1_U_REG_SET_HBS(vi_hor_tim1_u_reg, hbs) { \
	FDL_ASSERT(!((hbs) & ~((1 << VI_HOR_TIM1_U_REG_HBS_SIZE)-1))); \
	vi_hor_tim1_u_reg = (((unsigned long)(vi_hor_tim1_u_reg)) & ~VI_HOR_TIM1_U_REG_HBS_MASK) | (((unsigned long)(hbs)) << VI_HOR_TIM1_U_REG_HBS_SHIFT);\
}
#define VI_HOR_TIM1_U_REG_TOTAL_SIZE	11
#define VI_HOR_TIM1_U_REG(hbe_u, hbs) \
	((((unsigned long)(hbe_u)) << VI_HOR_TIM1_U_REG_HBE_U_SHIFT) | \
	 (((unsigned long)(hbs)) << VI_HOR_TIM1_U_REG_HBS_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hbs:VI_HOR_TIM1_U_REG_HBS_SIZE;
    unsigned long hbe_u:VI_HOR_TIM1_U_REG_HBE_U_SIZE;
} vi_hor_tim1_u_reg_t;

typedef union {
    unsigned long val;
    vi_hor_tim1_u_reg_t f;
} vi_hor_tim1_u_reg_u;

/*
 *  vi_ver_tim_reg struct
 */
#define VI_VER_TIM_REG_EQU_SIZE	4
#define VI_VER_TIM_REG_EQU_SHIFT	0
#define VI_VER_TIM_REG_EQU_MASK	0x0000000f
#define VI_VER_TIM_REG_GET_EQU(vi_ver_tim_reg) \
	((((unsigned long)(vi_ver_tim_reg)) & VI_VER_TIM_REG_EQU_MASK) >> VI_VER_TIM_REG_EQU_SHIFT)
#define VI_VER_TIM_REG_SET_EQU(vi_ver_tim_reg, equ) { \
	FDL_ASSERT(!((equ) & ~((1 << VI_VER_TIM_REG_EQU_SIZE)-1))); \
	vi_ver_tim_reg = (((unsigned long)(vi_ver_tim_reg)) & ~VI_VER_TIM_REG_EQU_MASK) | (((unsigned long)(equ)) << VI_VER_TIM_REG_EQU_SHIFT);\
}
#define VI_VER_TIM_REG_ACV_SIZE	10
#define VI_VER_TIM_REG_ACV_SHIFT	4
#define VI_VER_TIM_REG_ACV_MASK	0x00003ff0
#define VI_VER_TIM_REG_GET_ACV(vi_ver_tim_reg) \
	((((unsigned long)(vi_ver_tim_reg)) & VI_VER_TIM_REG_ACV_MASK) >> VI_VER_TIM_REG_ACV_SHIFT)
#define VI_VER_TIM_REG_SET_ACV(vi_ver_tim_reg, acv) { \
	FDL_ASSERT(!((acv) & ~((1 << VI_VER_TIM_REG_ACV_SIZE)-1))); \
	vi_ver_tim_reg = (((unsigned long)(vi_ver_tim_reg)) & ~VI_VER_TIM_REG_ACV_MASK) | (((unsigned long)(acv)) << VI_VER_TIM_REG_ACV_SHIFT);\
}
#define VI_VER_TIM_REG_TOTAL_SIZE	14
#define VI_VER_TIM_REG(equ, acv) \
	((((unsigned long)(equ)) << VI_VER_TIM_REG_EQU_SHIFT) | \
	 (((unsigned long)(acv)) << VI_VER_TIM_REG_ACV_SHIFT))

typedef struct {
    unsigned long pad0:2;
    unsigned long acv:VI_VER_TIM_REG_ACV_SIZE;
    unsigned long equ:VI_VER_TIM_REG_EQU_SIZE;
} vi_ver_tim_reg_t;

typedef union {
    unsigned long val;
    vi_ver_tim_reg_t f;
} vi_ver_tim_reg_u;

/*
 *  vi_ver_odd_tim_l_reg struct
 */
#define VI_VER_ODD_TIM_L_REG_OPRB_SIZE	10
#define VI_VER_ODD_TIM_L_REG_OPRB_SHIFT	0
#define VI_VER_ODD_TIM_L_REG_OPRB_MASK	0x000003ff
#define VI_VER_ODD_TIM_L_REG_GET_OPRB(vi_ver_odd_tim_l_reg) \
	((((unsigned long)(vi_ver_odd_tim_l_reg)) & VI_VER_ODD_TIM_L_REG_OPRB_MASK) >> VI_VER_ODD_TIM_L_REG_OPRB_SHIFT)
#define VI_VER_ODD_TIM_L_REG_SET_OPRB(vi_ver_odd_tim_l_reg, oprb) { \
	FDL_ASSERT(!((oprb) & ~((1 << VI_VER_ODD_TIM_L_REG_OPRB_SIZE)-1))); \
	vi_ver_odd_tim_l_reg = (((unsigned long)(vi_ver_odd_tim_l_reg)) & ~VI_VER_ODD_TIM_L_REG_OPRB_MASK) | (((unsigned long)(oprb)) << VI_VER_ODD_TIM_L_REG_OPRB_SHIFT);\
}
#define VI_VER_ODD_TIM_L_REG_TOTAL_SIZE	10
#define VI_VER_ODD_TIM_L_REG(oprb) \
	((((unsigned long)(oprb)) << VI_VER_ODD_TIM_L_REG_OPRB_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long oprb:VI_VER_ODD_TIM_L_REG_OPRB_SIZE;
} vi_ver_odd_tim_l_reg_t;

typedef union {
    unsigned long val;
    vi_ver_odd_tim_l_reg_t f;
} vi_ver_odd_tim_l_reg_u;

/*
 *  vi_ver_odd_tim_u_reg struct
 */
#define VI_VER_ODD_TIM_U_REG_OPSB_SIZE	10
#define VI_VER_ODD_TIM_U_REG_OPSB_SHIFT	0
#define VI_VER_ODD_TIM_U_REG_OPSB_MASK	0x000003ff
#define VI_VER_ODD_TIM_U_REG_GET_OPSB(vi_ver_odd_tim_u_reg) \
	((((unsigned long)(vi_ver_odd_tim_u_reg)) & VI_VER_ODD_TIM_U_REG_OPSB_MASK) >> VI_VER_ODD_TIM_U_REG_OPSB_SHIFT)
#define VI_VER_ODD_TIM_U_REG_SET_OPSB(vi_ver_odd_tim_u_reg, opsb) { \
	FDL_ASSERT(!((opsb) & ~((1 << VI_VER_ODD_TIM_U_REG_OPSB_SIZE)-1))); \
	vi_ver_odd_tim_u_reg = (((unsigned long)(vi_ver_odd_tim_u_reg)) & ~VI_VER_ODD_TIM_U_REG_OPSB_MASK) | (((unsigned long)(opsb)) << VI_VER_ODD_TIM_U_REG_OPSB_SHIFT);\
}
#define VI_VER_ODD_TIM_U_REG_TOTAL_SIZE	10
#define VI_VER_ODD_TIM_U_REG(opsb) \
	((((unsigned long)(opsb)) << VI_VER_ODD_TIM_U_REG_OPSB_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long opsb:VI_VER_ODD_TIM_U_REG_OPSB_SIZE;
} vi_ver_odd_tim_u_reg_t;

typedef union {
    unsigned long val;
    vi_ver_odd_tim_u_reg_t f;
} vi_ver_odd_tim_u_reg_u;

/*
 *  vi_ver_evn_tim_l_reg struct
 */
#define VI_VER_EVN_TIM_L_REG_EPRB_SIZE	10
#define VI_VER_EVN_TIM_L_REG_EPRB_SHIFT	0
#define VI_VER_EVN_TIM_L_REG_EPRB_MASK	0x000003ff
#define VI_VER_EVN_TIM_L_REG_GET_EPRB(vi_ver_evn_tim_l_reg) \
	((((unsigned long)(vi_ver_evn_tim_l_reg)) & VI_VER_EVN_TIM_L_REG_EPRB_MASK) >> VI_VER_EVN_TIM_L_REG_EPRB_SHIFT)
#define VI_VER_EVN_TIM_L_REG_SET_EPRB(vi_ver_evn_tim_l_reg, eprb) { \
	FDL_ASSERT(!((eprb) & ~((1 << VI_VER_EVN_TIM_L_REG_EPRB_SIZE)-1))); \
	vi_ver_evn_tim_l_reg = (((unsigned long)(vi_ver_evn_tim_l_reg)) & ~VI_VER_EVN_TIM_L_REG_EPRB_MASK) | (((unsigned long)(eprb)) << VI_VER_EVN_TIM_L_REG_EPRB_SHIFT);\
}
#define VI_VER_EVN_TIM_L_REG_TOTAL_SIZE	10
#define VI_VER_EVN_TIM_L_REG(eprb) \
	((((unsigned long)(eprb)) << VI_VER_EVN_TIM_L_REG_EPRB_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long eprb:VI_VER_EVN_TIM_L_REG_EPRB_SIZE;
} vi_ver_evn_tim_l_reg_t;

typedef union {
    unsigned long val;
    vi_ver_evn_tim_l_reg_t f;
} vi_ver_evn_tim_l_reg_u;

/*
 *  vi_ver_evn_tim_u_reg struct
 */
#define VI_VER_EVN_TIM_U_REG_EPSB_SIZE	10
#define VI_VER_EVN_TIM_U_REG_EPSB_SHIFT	0
#define VI_VER_EVN_TIM_U_REG_EPSB_MASK	0x000003ff
#define VI_VER_EVN_TIM_U_REG_GET_EPSB(vi_ver_evn_tim_u_reg) \
	((((unsigned long)(vi_ver_evn_tim_u_reg)) & VI_VER_EVN_TIM_U_REG_EPSB_MASK) >> VI_VER_EVN_TIM_U_REG_EPSB_SHIFT)
#define VI_VER_EVN_TIM_U_REG_SET_EPSB(vi_ver_evn_tim_u_reg, epsb) { \
	FDL_ASSERT(!((epsb) & ~((1 << VI_VER_EVN_TIM_U_REG_EPSB_SIZE)-1))); \
	vi_ver_evn_tim_u_reg = (((unsigned long)(vi_ver_evn_tim_u_reg)) & ~VI_VER_EVN_TIM_U_REG_EPSB_MASK) | (((unsigned long)(epsb)) << VI_VER_EVN_TIM_U_REG_EPSB_SHIFT);\
}
#define VI_VER_EVN_TIM_U_REG_TOTAL_SIZE	10
#define VI_VER_EVN_TIM_U_REG(epsb) \
	((((unsigned long)(epsb)) << VI_VER_EVN_TIM_U_REG_EPSB_SHIFT))

typedef struct {
    unsigned long pad0:6;
    unsigned long epsb:VI_VER_EVN_TIM_U_REG_EPSB_SIZE;
} vi_ver_evn_tim_u_reg_t;

typedef union {
    unsigned long val;
    vi_ver_evn_tim_u_reg_t f;
} vi_ver_evn_tim_u_reg_u;

/*
 *  vi_odd_bblnk_intvl_l_reg struct
 */
#define VI_ODD_BBLNK_INTVL_L_REG_BS1_SIZE	5
#define VI_ODD_BBLNK_INTVL_L_REG_BS1_SHIFT	0
#define VI_ODD_BBLNK_INTVL_L_REG_BS1_MASK	0x0000001f
#define VI_ODD_BBLNK_INTVL_L_REG_GET_BS1(vi_odd_bblnk_intvl_l_reg) \
	((((unsigned long)(vi_odd_bblnk_intvl_l_reg)) & VI_ODD_BBLNK_INTVL_L_REG_BS1_MASK) >> VI_ODD_BBLNK_INTVL_L_REG_BS1_SHIFT)
#define VI_ODD_BBLNK_INTVL_L_REG_SET_BS1(vi_odd_bblnk_intvl_l_reg, bs1) { \
	FDL_ASSERT(!((bs1) & ~((1 << VI_ODD_BBLNK_INTVL_L_REG_BS1_SIZE)-1))); \
	vi_odd_bblnk_intvl_l_reg = (((unsigned long)(vi_odd_bblnk_intvl_l_reg)) & ~VI_ODD_BBLNK_INTVL_L_REG_BS1_MASK) | (((unsigned long)(bs1)) << VI_ODD_BBLNK_INTVL_L_REG_BS1_SHIFT);\
}
#define VI_ODD_BBLNK_INTVL_L_REG_BE1_SIZE	11
#define VI_ODD_BBLNK_INTVL_L_REG_BE1_SHIFT	5
#define VI_ODD_BBLNK_INTVL_L_REG_BE1_MASK	0x0000ffe0
#define VI_ODD_BBLNK_INTVL_L_REG_GET_BE1(vi_odd_bblnk_intvl_l_reg) \
	((((unsigned long)(vi_odd_bblnk_intvl_l_reg)) & VI_ODD_BBLNK_INTVL_L_REG_BE1_MASK) >> VI_ODD_BBLNK_INTVL_L_REG_BE1_SHIFT)
#define VI_ODD_BBLNK_INTVL_L_REG_SET_BE1(vi_odd_bblnk_intvl_l_reg, be1) { \
	FDL_ASSERT(!((be1) & ~((1 << VI_ODD_BBLNK_INTVL_L_REG_BE1_SIZE)-1))); \
	vi_odd_bblnk_intvl_l_reg = (((unsigned long)(vi_odd_bblnk_intvl_l_reg)) & ~VI_ODD_BBLNK_INTVL_L_REG_BE1_MASK) | (((unsigned long)(be1)) << VI_ODD_BBLNK_INTVL_L_REG_BE1_SHIFT);\
}
#define VI_ODD_BBLNK_INTVL_L_REG_TOTAL_SIZE	16
#define VI_ODD_BBLNK_INTVL_L_REG(bs1, be1) \
	((((unsigned long)(bs1)) << VI_ODD_BBLNK_INTVL_L_REG_BS1_SHIFT) | \
	 (((unsigned long)(be1)) << VI_ODD_BBLNK_INTVL_L_REG_BE1_SHIFT))

typedef struct {
    unsigned long be1:VI_ODD_BBLNK_INTVL_L_REG_BE1_SIZE;
    unsigned long bs1:VI_ODD_BBLNK_INTVL_L_REG_BS1_SIZE;
} vi_odd_bblnk_intvl_l_reg_t;

typedef union {
    unsigned long val;
    vi_odd_bblnk_intvl_l_reg_t f;
} vi_odd_bblnk_intvl_l_reg_u;

/*
 *  vi_odd_bblnk_intvl_u_reg struct
 */
#define VI_ODD_BBLNK_INTVL_U_REG_BS3_SIZE	5
#define VI_ODD_BBLNK_INTVL_U_REG_BS3_SHIFT	0
#define VI_ODD_BBLNK_INTVL_U_REG_BS3_MASK	0x0000001f
#define VI_ODD_BBLNK_INTVL_U_REG_GET_BS3(vi_odd_bblnk_intvl_u_reg) \
	((((unsigned long)(vi_odd_bblnk_intvl_u_reg)) & VI_ODD_BBLNK_INTVL_U_REG_BS3_MASK) >> VI_ODD_BBLNK_INTVL_U_REG_BS3_SHIFT)
#define VI_ODD_BBLNK_INTVL_U_REG_SET_BS3(vi_odd_bblnk_intvl_u_reg, bs3) { \
	FDL_ASSERT(!((bs3) & ~((1 << VI_ODD_BBLNK_INTVL_U_REG_BS3_SIZE)-1))); \
	vi_odd_bblnk_intvl_u_reg = (((unsigned long)(vi_odd_bblnk_intvl_u_reg)) & ~VI_ODD_BBLNK_INTVL_U_REG_BS3_MASK) | (((unsigned long)(bs3)) << VI_ODD_BBLNK_INTVL_U_REG_BS3_SHIFT);\
}
#define VI_ODD_BBLNK_INTVL_U_REG_BE3_SIZE	11
#define VI_ODD_BBLNK_INTVL_U_REG_BE3_SHIFT	5
#define VI_ODD_BBLNK_INTVL_U_REG_BE3_MASK	0x0000ffe0
#define VI_ODD_BBLNK_INTVL_U_REG_GET_BE3(vi_odd_bblnk_intvl_u_reg) \
	((((unsigned long)(vi_odd_bblnk_intvl_u_reg)) & VI_ODD_BBLNK_INTVL_U_REG_BE3_MASK) >> VI_ODD_BBLNK_INTVL_U_REG_BE3_SHIFT)
#define VI_ODD_BBLNK_INTVL_U_REG_SET_BE3(vi_odd_bblnk_intvl_u_reg, be3) { \
	FDL_ASSERT(!((be3) & ~((1 << VI_ODD_BBLNK_INTVL_U_REG_BE3_SIZE)-1))); \
	vi_odd_bblnk_intvl_u_reg = (((unsigned long)(vi_odd_bblnk_intvl_u_reg)) & ~VI_ODD_BBLNK_INTVL_U_REG_BE3_MASK) | (((unsigned long)(be3)) << VI_ODD_BBLNK_INTVL_U_REG_BE3_SHIFT);\
}
#define VI_ODD_BBLNK_INTVL_U_REG_TOTAL_SIZE	16
#define VI_ODD_BBLNK_INTVL_U_REG(bs3, be3) \
	((((unsigned long)(bs3)) << VI_ODD_BBLNK_INTVL_U_REG_BS3_SHIFT) | \
	 (((unsigned long)(be3)) << VI_ODD_BBLNK_INTVL_U_REG_BE3_SHIFT))

typedef struct {
    unsigned long be3:VI_ODD_BBLNK_INTVL_U_REG_BE3_SIZE;
    unsigned long bs3:VI_ODD_BBLNK_INTVL_U_REG_BS3_SIZE;
} vi_odd_bblnk_intvl_u_reg_t;

typedef union {
    unsigned long val;
    vi_odd_bblnk_intvl_u_reg_t f;
} vi_odd_bblnk_intvl_u_reg_u;

/*
 *  vi_evn_bblnk_intvl_l_reg struct
 */
#define VI_EVN_BBLNK_INTVL_L_REG_BS2_SIZE	5
#define VI_EVN_BBLNK_INTVL_L_REG_BS2_SHIFT	0
#define VI_EVN_BBLNK_INTVL_L_REG_BS2_MASK	0x0000001f
#define VI_EVN_BBLNK_INTVL_L_REG_GET_BS2(vi_evn_bblnk_intvl_l_reg) \
	((((unsigned long)(vi_evn_bblnk_intvl_l_reg)) & VI_EVN_BBLNK_INTVL_L_REG_BS2_MASK) >> VI_EVN_BBLNK_INTVL_L_REG_BS2_SHIFT)
#define VI_EVN_BBLNK_INTVL_L_REG_SET_BS2(vi_evn_bblnk_intvl_l_reg, bs2) { \
	FDL_ASSERT(!((bs2) & ~((1 << VI_EVN_BBLNK_INTVL_L_REG_BS2_SIZE)-1))); \
	vi_evn_bblnk_intvl_l_reg = (((unsigned long)(vi_evn_bblnk_intvl_l_reg)) & ~VI_EVN_BBLNK_INTVL_L_REG_BS2_MASK) | (((unsigned long)(bs2)) << VI_EVN_BBLNK_INTVL_L_REG_BS2_SHIFT);\
}
#define VI_EVN_BBLNK_INTVL_L_REG_BE2_SIZE	11
#define VI_EVN_BBLNK_INTVL_L_REG_BE2_SHIFT	5
#define VI_EVN_BBLNK_INTVL_L_REG_BE2_MASK	0x0000ffe0
#define VI_EVN_BBLNK_INTVL_L_REG_GET_BE2(vi_evn_bblnk_intvl_l_reg) \
	((((unsigned long)(vi_evn_bblnk_intvl_l_reg)) & VI_EVN_BBLNK_INTVL_L_REG_BE2_MASK) >> VI_EVN_BBLNK_INTVL_L_REG_BE2_SHIFT)
#define VI_EVN_BBLNK_INTVL_L_REG_SET_BE2(vi_evn_bblnk_intvl_l_reg, be2) { \
	FDL_ASSERT(!((be2) & ~((1 << VI_EVN_BBLNK_INTVL_L_REG_BE2_SIZE)-1))); \
	vi_evn_bblnk_intvl_l_reg = (((unsigned long)(vi_evn_bblnk_intvl_l_reg)) & ~VI_EVN_BBLNK_INTVL_L_REG_BE2_MASK) | (((unsigned long)(be2)) << VI_EVN_BBLNK_INTVL_L_REG_BE2_SHIFT);\
}
#define VI_EVN_BBLNK_INTVL_L_REG_TOTAL_SIZE	16
#define VI_EVN_BBLNK_INTVL_L_REG(bs2, be2) \
	((((unsigned long)(bs2)) << VI_EVN_BBLNK_INTVL_L_REG_BS2_SHIFT) | \
	 (((unsigned long)(be2)) << VI_EVN_BBLNK_INTVL_L_REG_BE2_SHIFT))

typedef struct {
    unsigned long be2:VI_EVN_BBLNK_INTVL_L_REG_BE2_SIZE;
    unsigned long bs2:VI_EVN_BBLNK_INTVL_L_REG_BS2_SIZE;
} vi_evn_bblnk_intvl_l_reg_t;

typedef union {
    unsigned long val;
    vi_evn_bblnk_intvl_l_reg_t f;
} vi_evn_bblnk_intvl_l_reg_u;

/*
 *  vi_evn_bblnk_intvl_u_reg struct
 */
#define VI_EVN_BBLNK_INTVL_U_REG_BS4_SIZE	5
#define VI_EVN_BBLNK_INTVL_U_REG_BS4_SHIFT	0
#define VI_EVN_BBLNK_INTVL_U_REG_BS4_MASK	0x0000001f
#define VI_EVN_BBLNK_INTVL_U_REG_GET_BS4(vi_evn_bblnk_intvl_u_reg) \
	((((unsigned long)(vi_evn_bblnk_intvl_u_reg)) & VI_EVN_BBLNK_INTVL_U_REG_BS4_MASK) >> VI_EVN_BBLNK_INTVL_U_REG_BS4_SHIFT)
#define VI_EVN_BBLNK_INTVL_U_REG_SET_BS4(vi_evn_bblnk_intvl_u_reg, bs4) { \
	FDL_ASSERT(!((bs4) & ~((1 << VI_EVN_BBLNK_INTVL_U_REG_BS4_SIZE)-1))); \
	vi_evn_bblnk_intvl_u_reg = (((unsigned long)(vi_evn_bblnk_intvl_u_reg)) & ~VI_EVN_BBLNK_INTVL_U_REG_BS4_MASK) | (((unsigned long)(bs4)) << VI_EVN_BBLNK_INTVL_U_REG_BS4_SHIFT);\
}
#define VI_EVN_BBLNK_INTVL_U_REG_BE4_SIZE	11
#define VI_EVN_BBLNK_INTVL_U_REG_BE4_SHIFT	5
#define VI_EVN_BBLNK_INTVL_U_REG_BE4_MASK	0x0000ffe0
#define VI_EVN_BBLNK_INTVL_U_REG_GET_BE4(vi_evn_bblnk_intvl_u_reg) \
	((((unsigned long)(vi_evn_bblnk_intvl_u_reg)) & VI_EVN_BBLNK_INTVL_U_REG_BE4_MASK) >> VI_EVN_BBLNK_INTVL_U_REG_BE4_SHIFT)
#define VI_EVN_BBLNK_INTVL_U_REG_SET_BE4(vi_evn_bblnk_intvl_u_reg, be4) { \
	FDL_ASSERT(!((be4) & ~((1 << VI_EVN_BBLNK_INTVL_U_REG_BE4_SIZE)-1))); \
	vi_evn_bblnk_intvl_u_reg = (((unsigned long)(vi_evn_bblnk_intvl_u_reg)) & ~VI_EVN_BBLNK_INTVL_U_REG_BE4_MASK) | (((unsigned long)(be4)) << VI_EVN_BBLNK_INTVL_U_REG_BE4_SHIFT);\
}
#define VI_EVN_BBLNK_INTVL_U_REG_TOTAL_SIZE	16
#define VI_EVN_BBLNK_INTVL_U_REG(bs4, be4) \
	((((unsigned long)(bs4)) << VI_EVN_BBLNK_INTVL_U_REG_BS4_SHIFT) | \
	 (((unsigned long)(be4)) << VI_EVN_BBLNK_INTVL_U_REG_BE4_SHIFT))

typedef struct {
    unsigned long be4:VI_EVN_BBLNK_INTVL_U_REG_BE4_SIZE;
    unsigned long bs4:VI_EVN_BBLNK_INTVL_U_REG_BS4_SIZE;
} vi_evn_bblnk_intvl_u_reg_t;

typedef union {
    unsigned long val;
    vi_evn_bblnk_intvl_u_reg_t f;
} vi_evn_bblnk_intvl_u_reg_u;

/*
 *  vi_pic_base_lft_l_reg struct
 */
#define VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SIZE	16
#define VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SHIFT	0
#define VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_MASK	0x0000ffff
#define VI_PIC_BASE_LFT_L_REG_GET_FBB_LFT_L(vi_pic_base_lft_l_reg) \
	((((unsigned long)(vi_pic_base_lft_l_reg)) & VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_MASK) >> VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SHIFT)
#define VI_PIC_BASE_LFT_L_REG_SET_FBB_LFT_L(vi_pic_base_lft_l_reg, fbb_lft_l) { \
	FDL_ASSERT(!((fbb_lft_l) & ~((1 << VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SIZE)-1))); \
	vi_pic_base_lft_l_reg = (((unsigned long)(vi_pic_base_lft_l_reg)) & ~VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_MASK) | (((unsigned long)(fbb_lft_l)) << VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SHIFT);\
}
#define VI_PIC_BASE_LFT_L_REG_TOTAL_SIZE	16
#define VI_PIC_BASE_LFT_L_REG(fbb_lft_l) \
	((((unsigned long)(fbb_lft_l)) << VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SHIFT))

typedef struct {
    unsigned long fbb_lft_l:VI_PIC_BASE_LFT_L_REG_FBB_LFT_L_SIZE;
} vi_pic_base_lft_l_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_lft_l_reg_t f;
} vi_pic_base_lft_l_reg_u;

/*
 *  vi_pic_base_lft_u_reg struct
 */
#define VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SIZE	8
#define VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SHIFT	0
#define VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_MASK	0x000000ff
#define VI_PIC_BASE_LFT_U_REG_GET_FBB_LFT_U(vi_pic_base_lft_u_reg) \
	((((unsigned long)(vi_pic_base_lft_u_reg)) & VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_MASK) >> VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SHIFT)
#define VI_PIC_BASE_LFT_U_REG_SET_FBB_LFT_U(vi_pic_base_lft_u_reg, fbb_lft_u) { \
	FDL_ASSERT(!((fbb_lft_u) & ~((1 << VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SIZE)-1))); \
	vi_pic_base_lft_u_reg = (((unsigned long)(vi_pic_base_lft_u_reg)) & ~VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_MASK) | (((unsigned long)(fbb_lft_u)) << VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SHIFT);\
}
#define VI_PIC_BASE_LFT_U_REG_XOF_SIZE	4
#define VI_PIC_BASE_LFT_U_REG_XOF_SHIFT	8
#define VI_PIC_BASE_LFT_U_REG_XOF_MASK	0x00000f00
#define VI_PIC_BASE_LFT_U_REG_GET_XOF(vi_pic_base_lft_u_reg) \
	((((unsigned long)(vi_pic_base_lft_u_reg)) & VI_PIC_BASE_LFT_U_REG_XOF_MASK) >> VI_PIC_BASE_LFT_U_REG_XOF_SHIFT)
#define VI_PIC_BASE_LFT_U_REG_SET_XOF(vi_pic_base_lft_u_reg, xof) { \
	FDL_ASSERT(!((xof) & ~((1 << VI_PIC_BASE_LFT_U_REG_XOF_SIZE)-1))); \
	vi_pic_base_lft_u_reg = (((unsigned long)(vi_pic_base_lft_u_reg)) & ~VI_PIC_BASE_LFT_U_REG_XOF_MASK) | (((unsigned long)(xof)) << VI_PIC_BASE_LFT_U_REG_XOF_SHIFT);\
}
#define VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SIZE	1
#define VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SHIFT	12
#define VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_MASK	0x00001000
#define VI_PIC_BASE_LFT_U_REG_GET_HIGH_ADDR(vi_pic_base_lft_u_reg) \
	((((unsigned long)(vi_pic_base_lft_u_reg)) & VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_MASK) >> VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SHIFT)
#define VI_PIC_BASE_LFT_U_REG_SET_HIGH_ADDR(vi_pic_base_lft_u_reg, high_addr) { \
	FDL_ASSERT(!((high_addr) & ~((1 << VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SIZE)-1))); \
	vi_pic_base_lft_u_reg = (((unsigned long)(vi_pic_base_lft_u_reg)) & ~VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_MASK) | (((unsigned long)(high_addr)) << VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SHIFT);\
}
#define VI_PIC_BASE_LFT_U_REG_TOTAL_SIZE	13
#define VI_PIC_BASE_LFT_U_REG(fbb_lft_u, xof, high_addr) \
	((((unsigned long)(fbb_lft_u)) << VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SHIFT) | \
	 (((unsigned long)(xof)) << VI_PIC_BASE_LFT_U_REG_XOF_SHIFT) | \
	 (((unsigned long)(high_addr)) << VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SHIFT))

typedef struct {
    unsigned long pad0:3;
    unsigned long high_addr:VI_PIC_BASE_LFT_U_REG_HIGH_ADDR_SIZE;
    unsigned long xof:VI_PIC_BASE_LFT_U_REG_XOF_SIZE;
    unsigned long fbb_lft_u:VI_PIC_BASE_LFT_U_REG_FBB_LFT_U_SIZE;
} vi_pic_base_lft_u_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_lft_u_reg_t f;
} vi_pic_base_lft_u_reg_u;

/*
 *  vi_pic_base_rgt_l_reg struct
 */
#define VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SIZE	16
#define VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SHIFT	0
#define VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_MASK	0x0000ffff
#define VI_PIC_BASE_RGT_L_REG_GET_FBB_RGT_L(vi_pic_base_rgt_l_reg) \
	((((unsigned long)(vi_pic_base_rgt_l_reg)) & VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_MASK) >> VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SHIFT)
#define VI_PIC_BASE_RGT_L_REG_SET_FBB_RGT_L(vi_pic_base_rgt_l_reg, fbb_rgt_l) { \
	FDL_ASSERT(!((fbb_rgt_l) & ~((1 << VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SIZE)-1))); \
	vi_pic_base_rgt_l_reg = (((unsigned long)(vi_pic_base_rgt_l_reg)) & ~VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_MASK) | (((unsigned long)(fbb_rgt_l)) << VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SHIFT);\
}
#define VI_PIC_BASE_RGT_L_REG_TOTAL_SIZE	16
#define VI_PIC_BASE_RGT_L_REG(fbb_rgt_l) \
	((((unsigned long)(fbb_rgt_l)) << VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SHIFT))

typedef struct {
    unsigned long fbb_rgt_l:VI_PIC_BASE_RGT_L_REG_FBB_RGT_L_SIZE;
} vi_pic_base_rgt_l_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_rgt_l_reg_t f;
} vi_pic_base_rgt_l_reg_u;

/*
 *  vi_pic_base_rgt_u_reg struct
 */
#define VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SIZE	8
#define VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SHIFT	0
#define VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_MASK	0x000000ff
#define VI_PIC_BASE_RGT_U_REG_GET_FBB_RGT_U(vi_pic_base_rgt_u_reg) \
	((((unsigned long)(vi_pic_base_rgt_u_reg)) & VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_MASK) >> VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SHIFT)
#define VI_PIC_BASE_RGT_U_REG_SET_FBB_RGT_U(vi_pic_base_rgt_u_reg, fbb_rgt_u) { \
	FDL_ASSERT(!((fbb_rgt_u) & ~((1 << VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SIZE)-1))); \
	vi_pic_base_rgt_u_reg = (((unsigned long)(vi_pic_base_rgt_u_reg)) & ~VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_MASK) | (((unsigned long)(fbb_rgt_u)) << VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SHIFT);\
}
#define VI_PIC_BASE_RGT_U_REG_TOTAL_SIZE	8
#define VI_PIC_BASE_RGT_U_REG(fbb_rgt_u) \
	((((unsigned long)(fbb_rgt_u)) << VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SHIFT))

typedef struct {
    unsigned long pad0:8;
    unsigned long fbb_rgt_u:VI_PIC_BASE_RGT_U_REG_FBB_RGT_U_SIZE;
} vi_pic_base_rgt_u_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_rgt_u_reg_t f;
} vi_pic_base_rgt_u_reg_u;

/*
 *  vi_pic_base_lft_bot_l_reg struct
 */
#define VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SIZE	16
#define VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SHIFT	0
#define VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_MASK	0x0000ffff
#define VI_PIC_BASE_LFT_BOT_L_REG_GET_FBB_LFT_BOT_L(vi_pic_base_lft_bot_l_reg) \
	((((unsigned long)(vi_pic_base_lft_bot_l_reg)) & VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_MASK) >> VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SHIFT)
#define VI_PIC_BASE_LFT_BOT_L_REG_SET_FBB_LFT_BOT_L(vi_pic_base_lft_bot_l_reg, fbb_lft_bot_l) { \
	FDL_ASSERT(!((fbb_lft_bot_l) & ~((1 << VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SIZE)-1))); \
	vi_pic_base_lft_bot_l_reg = (((unsigned long)(vi_pic_base_lft_bot_l_reg)) & ~VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_MASK) | (((unsigned long)(fbb_lft_bot_l)) << VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SHIFT);\
}
#define VI_PIC_BASE_LFT_BOT_L_REG_TOTAL_SIZE	16
#define VI_PIC_BASE_LFT_BOT_L_REG(fbb_lft_bot_l) \
	((((unsigned long)(fbb_lft_bot_l)) << VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SHIFT))

typedef struct {
    unsigned long fbb_lft_bot_l:VI_PIC_BASE_LFT_BOT_L_REG_FBB_LFT_BOT_L_SIZE;
} vi_pic_base_lft_bot_l_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_lft_bot_l_reg_t f;
} vi_pic_base_lft_bot_l_reg_u;

/*
 *  vi_pic_base_lft_bot_u_reg struct
 */
#define VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SIZE	8
#define VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SHIFT	0
#define VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_MASK	0x000000ff
#define VI_PIC_BASE_LFT_BOT_U_REG_GET_FBB_LFT_BOT_U(vi_pic_base_lft_bot_u_reg) \
	((((unsigned long)(vi_pic_base_lft_bot_u_reg)) & VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_MASK) >> VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SHIFT)
#define VI_PIC_BASE_LFT_BOT_U_REG_SET_FBB_LFT_BOT_U(vi_pic_base_lft_bot_u_reg, fbb_lft_bot_u) { \
	FDL_ASSERT(!((fbb_lft_bot_u) & ~((1 << VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SIZE)-1))); \
	vi_pic_base_lft_bot_u_reg = (((unsigned long)(vi_pic_base_lft_bot_u_reg)) & ~VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_MASK) | (((unsigned long)(fbb_lft_bot_u)) << VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SHIFT);\
}
#define VI_PIC_BASE_LFT_BOT_U_REG_TOTAL_SIZE	8
#define VI_PIC_BASE_LFT_BOT_U_REG(fbb_lft_bot_u) \
	((((unsigned long)(fbb_lft_bot_u)) << VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SHIFT))

typedef struct {
    unsigned long pad0:8;
    unsigned long fbb_lft_bot_u:VI_PIC_BASE_LFT_BOT_U_REG_FBB_LFT_BOT_U_SIZE;
} vi_pic_base_lft_bot_u_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_lft_bot_u_reg_t f;
} vi_pic_base_lft_bot_u_reg_u;

/*
 *  vi_pic_base_rgt_bot_l_reg struct
 */
#define VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SIZE	16
#define VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SHIFT	0
#define VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_MASK	0x0000ffff
#define VI_PIC_BASE_RGT_BOT_L_REG_GET_FBB_RGT_BOT_L(vi_pic_base_rgt_bot_l_reg) \
	((((unsigned long)(vi_pic_base_rgt_bot_l_reg)) & VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_MASK) >> VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SHIFT)
#define VI_PIC_BASE_RGT_BOT_L_REG_SET_FBB_RGT_BOT_L(vi_pic_base_rgt_bot_l_reg, fbb_rgt_bot_l) { \
	FDL_ASSERT(!((fbb_rgt_bot_l) & ~((1 << VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SIZE)-1))); \
	vi_pic_base_rgt_bot_l_reg = (((unsigned long)(vi_pic_base_rgt_bot_l_reg)) & ~VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_MASK) | (((unsigned long)(fbb_rgt_bot_l)) << VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SHIFT);\
}
#define VI_PIC_BASE_RGT_BOT_L_REG_TOTAL_SIZE	16
#define VI_PIC_BASE_RGT_BOT_L_REG(fbb_rgt_bot_l) \
	((((unsigned long)(fbb_rgt_bot_l)) << VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SHIFT))

typedef struct {
    unsigned long fbb_rgt_bot_l:VI_PIC_BASE_RGT_BOT_L_REG_FBB_RGT_BOT_L_SIZE;
} vi_pic_base_rgt_bot_l_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_rgt_bot_l_reg_t f;
} vi_pic_base_rgt_bot_l_reg_u;

/*
 *  vi_pic_base_rgt_bot_u_reg struct
 */
#define VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SIZE	8
#define VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SHIFT	0
#define VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_MASK	0x000000ff
#define VI_PIC_BASE_RGT_BOT_U_REG_GET_FBB_RGT_BOT_U(vi_pic_base_rgt_bot_u_reg) \
	((((unsigned long)(vi_pic_base_rgt_bot_u_reg)) & VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_MASK) >> VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SHIFT)
#define VI_PIC_BASE_RGT_BOT_U_REG_SET_FBB_RGT_BOT_U(vi_pic_base_rgt_bot_u_reg, fbb_rgt_bot_u) { \
	FDL_ASSERT(!((fbb_rgt_bot_u) & ~((1 << VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SIZE)-1))); \
	vi_pic_base_rgt_bot_u_reg = (((unsigned long)(vi_pic_base_rgt_bot_u_reg)) & ~VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_MASK) | (((unsigned long)(fbb_rgt_bot_u)) << VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SHIFT);\
}
#define VI_PIC_BASE_RGT_BOT_U_REG_TOTAL_SIZE	8
#define VI_PIC_BASE_RGT_BOT_U_REG(fbb_rgt_bot_u) \
	((((unsigned long)(fbb_rgt_bot_u)) << VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SHIFT))

typedef struct {
    unsigned long pad0:8;
    unsigned long fbb_rgt_bot_u:VI_PIC_BASE_RGT_BOT_U_REG_FBB_RGT_BOT_U_SIZE;
} vi_pic_base_rgt_bot_u_reg_t;

typedef union {
    unsigned long val;
    vi_pic_base_rgt_bot_u_reg_t f;
} vi_pic_base_rgt_bot_u_reg_u;

/*
 *  vi_pic_cfg_reg struct
 */
#define VI_PIC_CFG_REG_STD_SIZE	8
#define VI_PIC_CFG_REG_STD_SHIFT	0
#define VI_PIC_CFG_REG_STD_MASK	0x000000ff
#define VI_PIC_CFG_REG_GET_STD(vi_pic_cfg_reg) \
	((((unsigned long)(vi_pic_cfg_reg)) & VI_PIC_CFG_REG_STD_MASK) >> VI_PIC_CFG_REG_STD_SHIFT)
#define VI_PIC_CFG_REG_SET_STD(vi_pic_cfg_reg, std) { \
	FDL_ASSERT(!((std) & ~((1 << VI_PIC_CFG_REG_STD_SIZE)-1))); \
	vi_pic_cfg_reg = (((unsigned long)(vi_pic_cfg_reg)) & ~VI_PIC_CFG_REG_STD_MASK) | (((unsigned long)(std)) << VI_PIC_CFG_REG_STD_SHIFT);\
}
#define VI_PIC_CFG_REG_WPL_SIZE	7
#define VI_PIC_CFG_REG_WPL_SHIFT	8
#define VI_PIC_CFG_REG_WPL_MASK	0x00007f00
#define VI_PIC_CFG_REG_GET_WPL(vi_pic_cfg_reg) \
	((((unsigned long)(vi_pic_cfg_reg)) & VI_PIC_CFG_REG_WPL_MASK) >> VI_PIC_CFG_REG_WPL_SHIFT)
#define VI_PIC_CFG_REG_SET_WPL(vi_pic_cfg_reg, wpl) { \
	FDL_ASSERT(!((wpl) & ~((1 << VI_PIC_CFG_REG_WPL_SIZE)-1))); \
	vi_pic_cfg_reg = (((unsigned long)(vi_pic_cfg_reg)) & ~VI_PIC_CFG_REG_WPL_MASK) | (((unsigned long)(wpl)) << VI_PIC_CFG_REG_WPL_SHIFT);\
}
#define VI_PIC_CFG_REG_TOTAL_SIZE	15
#define VI_PIC_CFG_REG(std, wpl) \
	((((unsigned long)(std)) << VI_PIC_CFG_REG_STD_SHIFT) | \
	 (((unsigned long)(wpl)) << VI_PIC_CFG_REG_WPL_SHIFT))

typedef struct {
    unsigned long pad0:1;
    unsigned long wpl:VI_PIC_CFG_REG_WPL_SIZE;
    unsigned long std:VI_PIC_CFG_REG_STD_SIZE;
} vi_pic_cfg_reg_t;

typedef union {
    unsigned long val;
    vi_pic_cfg_reg_t f;
} vi_pic_cfg_reg_u;

/*
 *  vi_dsp_pos_l_reg struct
 */
#define VI_DSP_POS_L_REG_HCT_SIZE	11
#define VI_DSP_POS_L_REG_HCT_SHIFT	0
#define VI_DSP_POS_L_REG_HCT_MASK	0x000007ff
#define VI_DSP_POS_L_REG_GET_HCT(vi_dsp_pos_l_reg) \
	((((unsigned long)(vi_dsp_pos_l_reg)) & VI_DSP_POS_L_REG_HCT_MASK) >> VI_DSP_POS_L_REG_HCT_SHIFT)
#define VI_DSP_POS_L_REG_SET_HCT(vi_dsp_pos_l_reg, hct) { \
	FDL_ASSERT(!((hct) & ~((1 << VI_DSP_POS_L_REG_HCT_SIZE)-1))); \
	vi_dsp_pos_l_reg = (((unsigned long)(vi_dsp_pos_l_reg)) & ~VI_DSP_POS_L_REG_HCT_MASK) | (((unsigned long)(hct)) << VI_DSP_POS_L_REG_HCT_SHIFT);\
}
#define VI_DSP_POS_L_REG_TOTAL_SIZE	11
#define VI_DSP_POS_L_REG(hct) \
	((((unsigned long)(hct)) << VI_DSP_POS_L_REG_HCT_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hct:VI_DSP_POS_L_REG_HCT_SIZE;
} vi_dsp_pos_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_pos_l_reg_t f;
} vi_dsp_pos_l_reg_u;

/*
 *  vi_dsp_pos_u_reg struct
 */
#define VI_DSP_POS_U_REG_VCT_SIZE	11
#define VI_DSP_POS_U_REG_VCT_SHIFT	0
#define VI_DSP_POS_U_REG_VCT_MASK	0x000007ff
#define VI_DSP_POS_U_REG_GET_VCT(vi_dsp_pos_u_reg) \
	((((unsigned long)(vi_dsp_pos_u_reg)) & VI_DSP_POS_U_REG_VCT_MASK) >> VI_DSP_POS_U_REG_VCT_SHIFT)
#define VI_DSP_POS_U_REG_SET_VCT(vi_dsp_pos_u_reg, vct) { \
	FDL_ASSERT(!((vct) & ~((1 << VI_DSP_POS_U_REG_VCT_SIZE)-1))); \
	vi_dsp_pos_u_reg = (((unsigned long)(vi_dsp_pos_u_reg)) & ~VI_DSP_POS_U_REG_VCT_MASK) | (((unsigned long)(vct)) << VI_DSP_POS_U_REG_VCT_SHIFT);\
}
#define VI_DSP_POS_U_REG_TOTAL_SIZE	11
#define VI_DSP_POS_U_REG(vct) \
	((((unsigned long)(vct)) << VI_DSP_POS_U_REG_VCT_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long vct:VI_DSP_POS_U_REG_VCT_SIZE;
} vi_dsp_pos_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_pos_u_reg_t f;
} vi_dsp_pos_u_reg_u;

/*
 *  vi_dsp_int0_l_reg struct
 */
#define VI_DSP_INT0_L_REG_HCT0_SIZE	11
#define VI_DSP_INT0_L_REG_HCT0_SHIFT	0
#define VI_DSP_INT0_L_REG_HCT0_MASK	0x000007ff
#define VI_DSP_INT0_L_REG_GET_HCT0(vi_dsp_int0_l_reg) \
	((((unsigned long)(vi_dsp_int0_l_reg)) & VI_DSP_INT0_L_REG_HCT0_MASK) >> VI_DSP_INT0_L_REG_HCT0_SHIFT)
#define VI_DSP_INT0_L_REG_SET_HCT0(vi_dsp_int0_l_reg, hct0) { \
	FDL_ASSERT(!((hct0) & ~((1 << VI_DSP_INT0_L_REG_HCT0_SIZE)-1))); \
	vi_dsp_int0_l_reg = (((unsigned long)(vi_dsp_int0_l_reg)) & ~VI_DSP_INT0_L_REG_HCT0_MASK) | (((unsigned long)(hct0)) << VI_DSP_INT0_L_REG_HCT0_SHIFT);\
}
#define VI_DSP_INT0_L_REG_TOTAL_SIZE	11
#define VI_DSP_INT0_L_REG(hct0) \
	((((unsigned long)(hct0)) << VI_DSP_INT0_L_REG_HCT0_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hct0:VI_DSP_INT0_L_REG_HCT0_SIZE;
} vi_dsp_int0_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int0_l_reg_t f;
} vi_dsp_int0_l_reg_u;

/*
 *  vi_dsp_int0_u_reg struct
 */
#define VI_DSP_INT0_U_REG_VCT0_SIZE	11
#define VI_DSP_INT0_U_REG_VCT0_SHIFT	0
#define VI_DSP_INT0_U_REG_VCT0_MASK	0x000007ff
#define VI_DSP_INT0_U_REG_GET_VCT0(vi_dsp_int0_u_reg) \
	((((unsigned long)(vi_dsp_int0_u_reg)) & VI_DSP_INT0_U_REG_VCT0_MASK) >> VI_DSP_INT0_U_REG_VCT0_SHIFT)
#define VI_DSP_INT0_U_REG_SET_VCT0(vi_dsp_int0_u_reg, vct0) { \
	FDL_ASSERT(!((vct0) & ~((1 << VI_DSP_INT0_U_REG_VCT0_SIZE)-1))); \
	vi_dsp_int0_u_reg = (((unsigned long)(vi_dsp_int0_u_reg)) & ~VI_DSP_INT0_U_REG_VCT0_MASK) | (((unsigned long)(vct0)) << VI_DSP_INT0_U_REG_VCT0_SHIFT);\
}
#define VI_DSP_INT0_U_REG_PAD0_SIZE	1
#define VI_DSP_INT0_U_REG_PAD0_SHIFT	11
#define VI_DSP_INT0_U_REG_PAD0_MASK	0x00000800
#define VI_DSP_INT0_U_REG_GET_PAD0(vi_dsp_int0_u_reg) \
	((((unsigned long)(vi_dsp_int0_u_reg)) & VI_DSP_INT0_U_REG_PAD0_MASK) >> VI_DSP_INT0_U_REG_PAD0_SHIFT)
#define VI_DSP_INT0_U_REG_SET_PAD0(vi_dsp_int0_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_INT0_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_int0_u_reg = (((unsigned long)(vi_dsp_int0_u_reg)) & ~VI_DSP_INT0_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_INT0_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_INT0_U_REG_ENB0_SIZE	1
#define VI_DSP_INT0_U_REG_ENB0_SHIFT	12
#define VI_DSP_INT0_U_REG_ENB0_MASK	0x00001000
#define VI_DSP_INT0_U_REG_GET_ENB0(vi_dsp_int0_u_reg) \
	((((unsigned long)(vi_dsp_int0_u_reg)) & VI_DSP_INT0_U_REG_ENB0_MASK) >> VI_DSP_INT0_U_REG_ENB0_SHIFT)
#define VI_DSP_INT0_U_REG_SET_ENB0(vi_dsp_int0_u_reg, enb0) { \
	FDL_ASSERT(!((enb0) & ~((1 << VI_DSP_INT0_U_REG_ENB0_SIZE)-1))); \
	vi_dsp_int0_u_reg = (((unsigned long)(vi_dsp_int0_u_reg)) & ~VI_DSP_INT0_U_REG_ENB0_MASK) | (((unsigned long)(enb0)) << VI_DSP_INT0_U_REG_ENB0_SHIFT);\
}
#define VI_DSP_INT0_U_REG_PAD1_SIZE	2
#define VI_DSP_INT0_U_REG_PAD1_SHIFT	13
#define VI_DSP_INT0_U_REG_PAD1_MASK	0x00006000
#define VI_DSP_INT0_U_REG_GET_PAD1(vi_dsp_int0_u_reg) \
	((((unsigned long)(vi_dsp_int0_u_reg)) & VI_DSP_INT0_U_REG_PAD1_MASK) >> VI_DSP_INT0_U_REG_PAD1_SHIFT)
#define VI_DSP_INT0_U_REG_SET_PAD1(vi_dsp_int0_u_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << VI_DSP_INT0_U_REG_PAD1_SIZE)-1))); \
	vi_dsp_int0_u_reg = (((unsigned long)(vi_dsp_int0_u_reg)) & ~VI_DSP_INT0_U_REG_PAD1_MASK) | (((unsigned long)(pad1)) << VI_DSP_INT0_U_REG_PAD1_SHIFT);\
}
#define VI_DSP_INT0_U_REG_INT0_SIZE	1
#define VI_DSP_INT0_U_REG_INT0_SHIFT	15
#define VI_DSP_INT0_U_REG_INT0_MASK	0x00008000
#define VI_DSP_INT0_U_REG_GET_INT0(vi_dsp_int0_u_reg) \
	((((unsigned long)(vi_dsp_int0_u_reg)) & VI_DSP_INT0_U_REG_INT0_MASK) >> VI_DSP_INT0_U_REG_INT0_SHIFT)
#define VI_DSP_INT0_U_REG_SET_INT0(vi_dsp_int0_u_reg, int0) { \
	FDL_ASSERT(!((int0) & ~((1 << VI_DSP_INT0_U_REG_INT0_SIZE)-1))); \
	vi_dsp_int0_u_reg = (((unsigned long)(vi_dsp_int0_u_reg)) & ~VI_DSP_INT0_U_REG_INT0_MASK) | (((unsigned long)(int0)) << VI_DSP_INT0_U_REG_INT0_SHIFT);\
}
#define VI_DSP_INT0_U_REG_TOTAL_SIZE	16
#define VI_DSP_INT0_U_REG(vct0, enb0, int0) \
	((((unsigned long)(vct0)) << VI_DSP_INT0_U_REG_VCT0_SHIFT) | \
	 (((unsigned long)(enb0)) << VI_DSP_INT0_U_REG_ENB0_SHIFT) | \
	 (((unsigned long)(int0)) << VI_DSP_INT0_U_REG_INT0_SHIFT))

typedef struct {
    unsigned long int0:VI_DSP_INT0_U_REG_INT0_SIZE;
    unsigned long pad1:VI_DSP_INT0_U_REG_PAD1_SIZE;
    unsigned long enb0:VI_DSP_INT0_U_REG_ENB0_SIZE;
    unsigned long pad0:VI_DSP_INT0_U_REG_PAD0_SIZE;
    unsigned long vct0:VI_DSP_INT0_U_REG_VCT0_SIZE;
} vi_dsp_int0_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int0_u_reg_t f;
} vi_dsp_int0_u_reg_u;

/*
 *  vi_dsp_int1_l_reg struct
 */
#define VI_DSP_INT1_L_REG_HCT1_SIZE	11
#define VI_DSP_INT1_L_REG_HCT1_SHIFT	0
#define VI_DSP_INT1_L_REG_HCT1_MASK	0x000007ff
#define VI_DSP_INT1_L_REG_GET_HCT1(vi_dsp_int1_l_reg) \
	((((unsigned long)(vi_dsp_int1_l_reg)) & VI_DSP_INT1_L_REG_HCT1_MASK) >> VI_DSP_INT1_L_REG_HCT1_SHIFT)
#define VI_DSP_INT1_L_REG_SET_HCT1(vi_dsp_int1_l_reg, hct1) { \
	FDL_ASSERT(!((hct1) & ~((1 << VI_DSP_INT1_L_REG_HCT1_SIZE)-1))); \
	vi_dsp_int1_l_reg = (((unsigned long)(vi_dsp_int1_l_reg)) & ~VI_DSP_INT1_L_REG_HCT1_MASK) | (((unsigned long)(hct1)) << VI_DSP_INT1_L_REG_HCT1_SHIFT);\
}
#define VI_DSP_INT1_L_REG_TOTAL_SIZE	11
#define VI_DSP_INT1_L_REG(hct1) \
	((((unsigned long)(hct1)) << VI_DSP_INT1_L_REG_HCT1_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hct1:VI_DSP_INT1_L_REG_HCT1_SIZE;
} vi_dsp_int1_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int1_l_reg_t f;
} vi_dsp_int1_l_reg_u;

/*
 *  vi_dsp_int1_u_reg struct
 */
#define VI_DSP_INT1_U_REG_VCT1_SIZE	11
#define VI_DSP_INT1_U_REG_VCT1_SHIFT	0
#define VI_DSP_INT1_U_REG_VCT1_MASK	0x000007ff
#define VI_DSP_INT1_U_REG_GET_VCT1(vi_dsp_int1_u_reg) \
	((((unsigned long)(vi_dsp_int1_u_reg)) & VI_DSP_INT1_U_REG_VCT1_MASK) >> VI_DSP_INT1_U_REG_VCT1_SHIFT)
#define VI_DSP_INT1_U_REG_SET_VCT1(vi_dsp_int1_u_reg, vct1) { \
	FDL_ASSERT(!((vct1) & ~((1 << VI_DSP_INT1_U_REG_VCT1_SIZE)-1))); \
	vi_dsp_int1_u_reg = (((unsigned long)(vi_dsp_int1_u_reg)) & ~VI_DSP_INT1_U_REG_VCT1_MASK) | (((unsigned long)(vct1)) << VI_DSP_INT1_U_REG_VCT1_SHIFT);\
}
#define VI_DSP_INT1_U_REG_PAD0_SIZE	1
#define VI_DSP_INT1_U_REG_PAD0_SHIFT	11
#define VI_DSP_INT1_U_REG_PAD0_MASK	0x00000800
#define VI_DSP_INT1_U_REG_GET_PAD0(vi_dsp_int1_u_reg) \
	((((unsigned long)(vi_dsp_int1_u_reg)) & VI_DSP_INT1_U_REG_PAD0_MASK) >> VI_DSP_INT1_U_REG_PAD0_SHIFT)
#define VI_DSP_INT1_U_REG_SET_PAD0(vi_dsp_int1_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_INT1_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_int1_u_reg = (((unsigned long)(vi_dsp_int1_u_reg)) & ~VI_DSP_INT1_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_INT1_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_INT1_U_REG_ENB1_SIZE	1
#define VI_DSP_INT1_U_REG_ENB1_SHIFT	12
#define VI_DSP_INT1_U_REG_ENB1_MASK	0x00001000
#define VI_DSP_INT1_U_REG_GET_ENB1(vi_dsp_int1_u_reg) \
	((((unsigned long)(vi_dsp_int1_u_reg)) & VI_DSP_INT1_U_REG_ENB1_MASK) >> VI_DSP_INT1_U_REG_ENB1_SHIFT)
#define VI_DSP_INT1_U_REG_SET_ENB1(vi_dsp_int1_u_reg, enb1) { \
	FDL_ASSERT(!((enb1) & ~((1 << VI_DSP_INT1_U_REG_ENB1_SIZE)-1))); \
	vi_dsp_int1_u_reg = (((unsigned long)(vi_dsp_int1_u_reg)) & ~VI_DSP_INT1_U_REG_ENB1_MASK) | (((unsigned long)(enb1)) << VI_DSP_INT1_U_REG_ENB1_SHIFT);\
}
#define VI_DSP_INT1_U_REG_PAD1_SIZE	2
#define VI_DSP_INT1_U_REG_PAD1_SHIFT	13
#define VI_DSP_INT1_U_REG_PAD1_MASK	0x00006000
#define VI_DSP_INT1_U_REG_GET_PAD1(vi_dsp_int1_u_reg) \
	((((unsigned long)(vi_dsp_int1_u_reg)) & VI_DSP_INT1_U_REG_PAD1_MASK) >> VI_DSP_INT1_U_REG_PAD1_SHIFT)
#define VI_DSP_INT1_U_REG_SET_PAD1(vi_dsp_int1_u_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << VI_DSP_INT1_U_REG_PAD1_SIZE)-1))); \
	vi_dsp_int1_u_reg = (((unsigned long)(vi_dsp_int1_u_reg)) & ~VI_DSP_INT1_U_REG_PAD1_MASK) | (((unsigned long)(pad1)) << VI_DSP_INT1_U_REG_PAD1_SHIFT);\
}
#define VI_DSP_INT1_U_REG_INT1_SIZE	1
#define VI_DSP_INT1_U_REG_INT1_SHIFT	15
#define VI_DSP_INT1_U_REG_INT1_MASK	0x00008000
#define VI_DSP_INT1_U_REG_GET_INT1(vi_dsp_int1_u_reg) \
	((((unsigned long)(vi_dsp_int1_u_reg)) & VI_DSP_INT1_U_REG_INT1_MASK) >> VI_DSP_INT1_U_REG_INT1_SHIFT)
#define VI_DSP_INT1_U_REG_SET_INT1(vi_dsp_int1_u_reg, int1) { \
	FDL_ASSERT(!((int1) & ~((1 << VI_DSP_INT1_U_REG_INT1_SIZE)-1))); \
	vi_dsp_int1_u_reg = (((unsigned long)(vi_dsp_int1_u_reg)) & ~VI_DSP_INT1_U_REG_INT1_MASK) | (((unsigned long)(int1)) << VI_DSP_INT1_U_REG_INT1_SHIFT);\
}
#define VI_DSP_INT1_U_REG_TOTAL_SIZE	16
#define VI_DSP_INT1_U_REG(vct1, enb1, int1) \
	((((unsigned long)(vct1)) << VI_DSP_INT1_U_REG_VCT1_SHIFT) | \
	 (((unsigned long)(enb1)) << VI_DSP_INT1_U_REG_ENB1_SHIFT) | \
	 (((unsigned long)(int1)) << VI_DSP_INT1_U_REG_INT1_SHIFT))

typedef struct {
    unsigned long int1:VI_DSP_INT1_U_REG_INT1_SIZE;
    unsigned long pad1:VI_DSP_INT1_U_REG_PAD1_SIZE;
    unsigned long enb1:VI_DSP_INT1_U_REG_ENB1_SIZE;
    unsigned long pad0:VI_DSP_INT1_U_REG_PAD0_SIZE;
    unsigned long vct1:VI_DSP_INT1_U_REG_VCT1_SIZE;
} vi_dsp_int1_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int1_u_reg_t f;
} vi_dsp_int1_u_reg_u;

/*
 *  vi_dsp_int2_l_reg struct
 */
#define VI_DSP_INT2_L_REG_HCT2_SIZE	11
#define VI_DSP_INT2_L_REG_HCT2_SHIFT	0
#define VI_DSP_INT2_L_REG_HCT2_MASK	0x000007ff
#define VI_DSP_INT2_L_REG_GET_HCT2(vi_dsp_int2_l_reg) \
	((((unsigned long)(vi_dsp_int2_l_reg)) & VI_DSP_INT2_L_REG_HCT2_MASK) >> VI_DSP_INT2_L_REG_HCT2_SHIFT)
#define VI_DSP_INT2_L_REG_SET_HCT2(vi_dsp_int2_l_reg, hct2) { \
	FDL_ASSERT(!((hct2) & ~((1 << VI_DSP_INT2_L_REG_HCT2_SIZE)-1))); \
	vi_dsp_int2_l_reg = (((unsigned long)(vi_dsp_int2_l_reg)) & ~VI_DSP_INT2_L_REG_HCT2_MASK) | (((unsigned long)(hct2)) << VI_DSP_INT2_L_REG_HCT2_SHIFT);\
}
#define VI_DSP_INT2_L_REG_TOTAL_SIZE	11
#define VI_DSP_INT2_L_REG(hct2) \
	((((unsigned long)(hct2)) << VI_DSP_INT2_L_REG_HCT2_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hct2:VI_DSP_INT2_L_REG_HCT2_SIZE;
} vi_dsp_int2_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int2_l_reg_t f;
} vi_dsp_int2_l_reg_u;

/*
 *  vi_dsp_int2_u_reg struct
 */
#define VI_DSP_INT2_U_REG_VCT2_SIZE	11
#define VI_DSP_INT2_U_REG_VCT2_SHIFT	0
#define VI_DSP_INT2_U_REG_VCT2_MASK	0x000007ff
#define VI_DSP_INT2_U_REG_GET_VCT2(vi_dsp_int2_u_reg) \
	((((unsigned long)(vi_dsp_int2_u_reg)) & VI_DSP_INT2_U_REG_VCT2_MASK) >> VI_DSP_INT2_U_REG_VCT2_SHIFT)
#define VI_DSP_INT2_U_REG_SET_VCT2(vi_dsp_int2_u_reg, vct2) { \
	FDL_ASSERT(!((vct2) & ~((1 << VI_DSP_INT2_U_REG_VCT2_SIZE)-1))); \
	vi_dsp_int2_u_reg = (((unsigned long)(vi_dsp_int2_u_reg)) & ~VI_DSP_INT2_U_REG_VCT2_MASK) | (((unsigned long)(vct2)) << VI_DSP_INT2_U_REG_VCT2_SHIFT);\
}
#define VI_DSP_INT2_U_REG_PAD0_SIZE	1
#define VI_DSP_INT2_U_REG_PAD0_SHIFT	11
#define VI_DSP_INT2_U_REG_PAD0_MASK	0x00000800
#define VI_DSP_INT2_U_REG_GET_PAD0(vi_dsp_int2_u_reg) \
	((((unsigned long)(vi_dsp_int2_u_reg)) & VI_DSP_INT2_U_REG_PAD0_MASK) >> VI_DSP_INT2_U_REG_PAD0_SHIFT)
#define VI_DSP_INT2_U_REG_SET_PAD0(vi_dsp_int2_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_INT2_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_int2_u_reg = (((unsigned long)(vi_dsp_int2_u_reg)) & ~VI_DSP_INT2_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_INT2_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_INT2_U_REG_ENB2_SIZE	1
#define VI_DSP_INT2_U_REG_ENB2_SHIFT	12
#define VI_DSP_INT2_U_REG_ENB2_MASK	0x00001000
#define VI_DSP_INT2_U_REG_GET_ENB2(vi_dsp_int2_u_reg) \
	((((unsigned long)(vi_dsp_int2_u_reg)) & VI_DSP_INT2_U_REG_ENB2_MASK) >> VI_DSP_INT2_U_REG_ENB2_SHIFT)
#define VI_DSP_INT2_U_REG_SET_ENB2(vi_dsp_int2_u_reg, enb2) { \
	FDL_ASSERT(!((enb2) & ~((1 << VI_DSP_INT2_U_REG_ENB2_SIZE)-1))); \
	vi_dsp_int2_u_reg = (((unsigned long)(vi_dsp_int2_u_reg)) & ~VI_DSP_INT2_U_REG_ENB2_MASK) | (((unsigned long)(enb2)) << VI_DSP_INT2_U_REG_ENB2_SHIFT);\
}
#define VI_DSP_INT2_U_REG_PAD1_SIZE	2
#define VI_DSP_INT2_U_REG_PAD1_SHIFT	13
#define VI_DSP_INT2_U_REG_PAD1_MASK	0x00006000
#define VI_DSP_INT2_U_REG_GET_PAD1(vi_dsp_int2_u_reg) \
	((((unsigned long)(vi_dsp_int2_u_reg)) & VI_DSP_INT2_U_REG_PAD1_MASK) >> VI_DSP_INT2_U_REG_PAD1_SHIFT)
#define VI_DSP_INT2_U_REG_SET_PAD1(vi_dsp_int2_u_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << VI_DSP_INT2_U_REG_PAD1_SIZE)-1))); \
	vi_dsp_int2_u_reg = (((unsigned long)(vi_dsp_int2_u_reg)) & ~VI_DSP_INT2_U_REG_PAD1_MASK) | (((unsigned long)(pad1)) << VI_DSP_INT2_U_REG_PAD1_SHIFT);\
}
#define VI_DSP_INT2_U_REG_INT2_SIZE	1
#define VI_DSP_INT2_U_REG_INT2_SHIFT	15
#define VI_DSP_INT2_U_REG_INT2_MASK	0x00008000
#define VI_DSP_INT2_U_REG_GET_INT2(vi_dsp_int2_u_reg) \
	((((unsigned long)(vi_dsp_int2_u_reg)) & VI_DSP_INT2_U_REG_INT2_MASK) >> VI_DSP_INT2_U_REG_INT2_SHIFT)
#define VI_DSP_INT2_U_REG_SET_INT2(vi_dsp_int2_u_reg, int2) { \
	FDL_ASSERT(!((int2) & ~((1 << VI_DSP_INT2_U_REG_INT2_SIZE)-1))); \
	vi_dsp_int2_u_reg = (((unsigned long)(vi_dsp_int2_u_reg)) & ~VI_DSP_INT2_U_REG_INT2_MASK) | (((unsigned long)(int2)) << VI_DSP_INT2_U_REG_INT2_SHIFT);\
}
#define VI_DSP_INT2_U_REG_TOTAL_SIZE	16
#define VI_DSP_INT2_U_REG(vct2, enb2, int2) \
	((((unsigned long)(vct2)) << VI_DSP_INT2_U_REG_VCT2_SHIFT) | \
	 (((unsigned long)(enb2)) << VI_DSP_INT2_U_REG_ENB2_SHIFT) | \
	 (((unsigned long)(int2)) << VI_DSP_INT2_U_REG_INT2_SHIFT))

typedef struct {
    unsigned long int2:VI_DSP_INT2_U_REG_INT2_SIZE;
    unsigned long pad1:VI_DSP_INT2_U_REG_PAD1_SIZE;
    unsigned long enb2:VI_DSP_INT2_U_REG_ENB2_SIZE;
    unsigned long pad0:VI_DSP_INT2_U_REG_PAD0_SIZE;
    unsigned long vct2:VI_DSP_INT2_U_REG_VCT2_SIZE;
} vi_dsp_int2_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int2_u_reg_t f;
} vi_dsp_int2_u_reg_u;

/*
 *  vi_dsp_int3_l_reg struct
 */
#define VI_DSP_INT3_L_REG_HCT3_SIZE	11
#define VI_DSP_INT3_L_REG_HCT3_SHIFT	0
#define VI_DSP_INT3_L_REG_HCT3_MASK	0x000007ff
#define VI_DSP_INT3_L_REG_GET_HCT3(vi_dsp_int3_l_reg) \
	((((unsigned long)(vi_dsp_int3_l_reg)) & VI_DSP_INT3_L_REG_HCT3_MASK) >> VI_DSP_INT3_L_REG_HCT3_SHIFT)
#define VI_DSP_INT3_L_REG_SET_HCT3(vi_dsp_int3_l_reg, hct3) { \
	FDL_ASSERT(!((hct3) & ~((1 << VI_DSP_INT3_L_REG_HCT3_SIZE)-1))); \
	vi_dsp_int3_l_reg = (((unsigned long)(vi_dsp_int3_l_reg)) & ~VI_DSP_INT3_L_REG_HCT3_MASK) | (((unsigned long)(hct3)) << VI_DSP_INT3_L_REG_HCT3_SHIFT);\
}
#define VI_DSP_INT3_L_REG_TOTAL_SIZE	11
#define VI_DSP_INT3_L_REG(hct3) \
	((((unsigned long)(hct3)) << VI_DSP_INT3_L_REG_HCT3_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long hct3:VI_DSP_INT3_L_REG_HCT3_SIZE;
} vi_dsp_int3_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int3_l_reg_t f;
} vi_dsp_int3_l_reg_u;

/*
 *  vi_dsp_int3_u_reg struct
 */
#define VI_DSP_INT3_U_REG_VCT3_SIZE	11
#define VI_DSP_INT3_U_REG_VCT3_SHIFT	0
#define VI_DSP_INT3_U_REG_VCT3_MASK	0x000007ff
#define VI_DSP_INT3_U_REG_GET_VCT3(vi_dsp_int3_u_reg) \
	((((unsigned long)(vi_dsp_int3_u_reg)) & VI_DSP_INT3_U_REG_VCT3_MASK) >> VI_DSP_INT3_U_REG_VCT3_SHIFT)
#define VI_DSP_INT3_U_REG_SET_VCT3(vi_dsp_int3_u_reg, vct3) { \
	FDL_ASSERT(!((vct3) & ~((1 << VI_DSP_INT3_U_REG_VCT3_SIZE)-1))); \
	vi_dsp_int3_u_reg = (((unsigned long)(vi_dsp_int3_u_reg)) & ~VI_DSP_INT3_U_REG_VCT3_MASK) | (((unsigned long)(vct3)) << VI_DSP_INT3_U_REG_VCT3_SHIFT);\
}
#define VI_DSP_INT3_U_REG_PAD0_SIZE	1
#define VI_DSP_INT3_U_REG_PAD0_SHIFT	11
#define VI_DSP_INT3_U_REG_PAD0_MASK	0x00000800
#define VI_DSP_INT3_U_REG_GET_PAD0(vi_dsp_int3_u_reg) \
	((((unsigned long)(vi_dsp_int3_u_reg)) & VI_DSP_INT3_U_REG_PAD0_MASK) >> VI_DSP_INT3_U_REG_PAD0_SHIFT)
#define VI_DSP_INT3_U_REG_SET_PAD0(vi_dsp_int3_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_INT3_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_int3_u_reg = (((unsigned long)(vi_dsp_int3_u_reg)) & ~VI_DSP_INT3_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_INT3_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_INT3_U_REG_ENB3_SIZE	1
#define VI_DSP_INT3_U_REG_ENB3_SHIFT	12
#define VI_DSP_INT3_U_REG_ENB3_MASK	0x00001000
#define VI_DSP_INT3_U_REG_GET_ENB3(vi_dsp_int3_u_reg) \
	((((unsigned long)(vi_dsp_int3_u_reg)) & VI_DSP_INT3_U_REG_ENB3_MASK) >> VI_DSP_INT3_U_REG_ENB3_SHIFT)
#define VI_DSP_INT3_U_REG_SET_ENB3(vi_dsp_int3_u_reg, enb3) { \
	FDL_ASSERT(!((enb3) & ~((1 << VI_DSP_INT3_U_REG_ENB3_SIZE)-1))); \
	vi_dsp_int3_u_reg = (((unsigned long)(vi_dsp_int3_u_reg)) & ~VI_DSP_INT3_U_REG_ENB3_MASK) | (((unsigned long)(enb3)) << VI_DSP_INT3_U_REG_ENB3_SHIFT);\
}
#define VI_DSP_INT3_U_REG_PAD1_SIZE	2
#define VI_DSP_INT3_U_REG_PAD1_SHIFT	13
#define VI_DSP_INT3_U_REG_PAD1_MASK	0x00006000
#define VI_DSP_INT3_U_REG_GET_PAD1(vi_dsp_int3_u_reg) \
	((((unsigned long)(vi_dsp_int3_u_reg)) & VI_DSP_INT3_U_REG_PAD1_MASK) >> VI_DSP_INT3_U_REG_PAD1_SHIFT)
#define VI_DSP_INT3_U_REG_SET_PAD1(vi_dsp_int3_u_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << VI_DSP_INT3_U_REG_PAD1_SIZE)-1))); \
	vi_dsp_int3_u_reg = (((unsigned long)(vi_dsp_int3_u_reg)) & ~VI_DSP_INT3_U_REG_PAD1_MASK) | (((unsigned long)(pad1)) << VI_DSP_INT3_U_REG_PAD1_SHIFT);\
}
#define VI_DSP_INT3_U_REG_INT3_SIZE	1
#define VI_DSP_INT3_U_REG_INT3_SHIFT	15
#define VI_DSP_INT3_U_REG_INT3_MASK	0x00008000
#define VI_DSP_INT3_U_REG_GET_INT3(vi_dsp_int3_u_reg) \
	((((unsigned long)(vi_dsp_int3_u_reg)) & VI_DSP_INT3_U_REG_INT3_MASK) >> VI_DSP_INT3_U_REG_INT3_SHIFT)
#define VI_DSP_INT3_U_REG_SET_INT3(vi_dsp_int3_u_reg, int3) { \
	FDL_ASSERT(!((int3) & ~((1 << VI_DSP_INT3_U_REG_INT3_SIZE)-1))); \
	vi_dsp_int3_u_reg = (((unsigned long)(vi_dsp_int3_u_reg)) & ~VI_DSP_INT3_U_REG_INT3_MASK) | (((unsigned long)(int3)) << VI_DSP_INT3_U_REG_INT3_SHIFT);\
}
#define VI_DSP_INT3_U_REG_TOTAL_SIZE	16
#define VI_DSP_INT3_U_REG(vct3, enb3, int3) \
	((((unsigned long)(vct3)) << VI_DSP_INT3_U_REG_VCT3_SHIFT) | \
	 (((unsigned long)(enb3)) << VI_DSP_INT3_U_REG_ENB3_SHIFT) | \
	 (((unsigned long)(int3)) << VI_DSP_INT3_U_REG_INT3_SHIFT))

typedef struct {
    unsigned long int3:VI_DSP_INT3_U_REG_INT3_SIZE;
    unsigned long pad1:VI_DSP_INT3_U_REG_PAD1_SIZE;
    unsigned long enb3:VI_DSP_INT3_U_REG_ENB3_SIZE;
    unsigned long pad0:VI_DSP_INT3_U_REG_PAD0_SIZE;
    unsigned long vct3:VI_DSP_INT3_U_REG_VCT3_SIZE;
} vi_dsp_int3_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_int3_u_reg_t f;
} vi_dsp_int3_u_reg_u;

/*
 *  vi_dsp_latch0_l_reg struct
 */
#define VI_DSP_LATCH0_L_REG_GUN0_HCT_SIZE	11
#define VI_DSP_LATCH0_L_REG_GUN0_HCT_SHIFT	0
#define VI_DSP_LATCH0_L_REG_GUN0_HCT_MASK	0x000007ff
#define VI_DSP_LATCH0_L_REG_GET_GUN0_HCT(vi_dsp_latch0_l_reg) \
	((((unsigned long)(vi_dsp_latch0_l_reg)) & VI_DSP_LATCH0_L_REG_GUN0_HCT_MASK) >> VI_DSP_LATCH0_L_REG_GUN0_HCT_SHIFT)
#define VI_DSP_LATCH0_L_REG_SET_GUN0_HCT(vi_dsp_latch0_l_reg, gun0_hct) { \
	FDL_ASSERT(!((gun0_hct) & ~((1 << VI_DSP_LATCH0_L_REG_GUN0_HCT_SIZE)-1))); \
	vi_dsp_latch0_l_reg = (((unsigned long)(vi_dsp_latch0_l_reg)) & ~VI_DSP_LATCH0_L_REG_GUN0_HCT_MASK) | (((unsigned long)(gun0_hct)) << VI_DSP_LATCH0_L_REG_GUN0_HCT_SHIFT);\
}
#define VI_DSP_LATCH0_L_REG_TOTAL_SIZE	11
#define VI_DSP_LATCH0_L_REG(gun0_hct) \
	((((unsigned long)(gun0_hct)) << VI_DSP_LATCH0_L_REG_GUN0_HCT_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long gun0_hct:VI_DSP_LATCH0_L_REG_GUN0_HCT_SIZE;
} vi_dsp_latch0_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_latch0_l_reg_t f;
} vi_dsp_latch0_l_reg_u;

/*
 *  vi_dsp_latch0_u_reg struct
 */
#define VI_DSP_LATCH0_U_REG_GUN0_VCT_SIZE	11
#define VI_DSP_LATCH0_U_REG_GUN0_VCT_SHIFT	0
#define VI_DSP_LATCH0_U_REG_GUN0_VCT_MASK	0x000007ff
#define VI_DSP_LATCH0_U_REG_GET_GUN0_VCT(vi_dsp_latch0_u_reg) \
	((((unsigned long)(vi_dsp_latch0_u_reg)) & VI_DSP_LATCH0_U_REG_GUN0_VCT_MASK) >> VI_DSP_LATCH0_U_REG_GUN0_VCT_SHIFT)
#define VI_DSP_LATCH0_U_REG_SET_GUN0_VCT(vi_dsp_latch0_u_reg, gun0_vct) { \
	FDL_ASSERT(!((gun0_vct) & ~((1 << VI_DSP_LATCH0_U_REG_GUN0_VCT_SIZE)-1))); \
	vi_dsp_latch0_u_reg = (((unsigned long)(vi_dsp_latch0_u_reg)) & ~VI_DSP_LATCH0_U_REG_GUN0_VCT_MASK) | (((unsigned long)(gun0_vct)) << VI_DSP_LATCH0_U_REG_GUN0_VCT_SHIFT);\
}
#define VI_DSP_LATCH0_U_REG_PAD0_SIZE	4
#define VI_DSP_LATCH0_U_REG_PAD0_SHIFT	11
#define VI_DSP_LATCH0_U_REG_PAD0_MASK	0x00007800
#define VI_DSP_LATCH0_U_REG_GET_PAD0(vi_dsp_latch0_u_reg) \
	((((unsigned long)(vi_dsp_latch0_u_reg)) & VI_DSP_LATCH0_U_REG_PAD0_MASK) >> VI_DSP_LATCH0_U_REG_PAD0_SHIFT)
#define VI_DSP_LATCH0_U_REG_SET_PAD0(vi_dsp_latch0_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_LATCH0_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_latch0_u_reg = (((unsigned long)(vi_dsp_latch0_u_reg)) & ~VI_DSP_LATCH0_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_LATCH0_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_LATCH0_U_REG_GUN0_TRG_SIZE	1
#define VI_DSP_LATCH0_U_REG_GUN0_TRG_SHIFT	15
#define VI_DSP_LATCH0_U_REG_GUN0_TRG_MASK	0x00008000
#define VI_DSP_LATCH0_U_REG_GET_GUN0_TRG(vi_dsp_latch0_u_reg) \
	((((unsigned long)(vi_dsp_latch0_u_reg)) & VI_DSP_LATCH0_U_REG_GUN0_TRG_MASK) >> VI_DSP_LATCH0_U_REG_GUN0_TRG_SHIFT)
#define VI_DSP_LATCH0_U_REG_SET_GUN0_TRG(vi_dsp_latch0_u_reg, gun0_trg) { \
	FDL_ASSERT(!((gun0_trg) & ~((1 << VI_DSP_LATCH0_U_REG_GUN0_TRG_SIZE)-1))); \
	vi_dsp_latch0_u_reg = (((unsigned long)(vi_dsp_latch0_u_reg)) & ~VI_DSP_LATCH0_U_REG_GUN0_TRG_MASK) | (((unsigned long)(gun0_trg)) << VI_DSP_LATCH0_U_REG_GUN0_TRG_SHIFT);\
}
#define VI_DSP_LATCH0_U_REG_TOTAL_SIZE	16
#define VI_DSP_LATCH0_U_REG(gun0_vct, gun0_trg) \
	((((unsigned long)(gun0_vct)) << VI_DSP_LATCH0_U_REG_GUN0_VCT_SHIFT) | \
	 (((unsigned long)(gun0_trg)) << VI_DSP_LATCH0_U_REG_GUN0_TRG_SHIFT))

typedef struct {
    unsigned long gun0_trg:VI_DSP_LATCH0_U_REG_GUN0_TRG_SIZE;
    unsigned long pad0:VI_DSP_LATCH0_U_REG_PAD0_SIZE;
    unsigned long gun0_vct:VI_DSP_LATCH0_U_REG_GUN0_VCT_SIZE;
} vi_dsp_latch0_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_latch0_u_reg_t f;
} vi_dsp_latch0_u_reg_u;

/*
 *  vi_dsp_latch1_l_reg struct
 */
#define VI_DSP_LATCH1_L_REG_GUN1_HCT_SIZE	11
#define VI_DSP_LATCH1_L_REG_GUN1_HCT_SHIFT	0
#define VI_DSP_LATCH1_L_REG_GUN1_HCT_MASK	0x000007ff
#define VI_DSP_LATCH1_L_REG_GET_GUN1_HCT(vi_dsp_latch1_l_reg) \
	((((unsigned long)(vi_dsp_latch1_l_reg)) & VI_DSP_LATCH1_L_REG_GUN1_HCT_MASK) >> VI_DSP_LATCH1_L_REG_GUN1_HCT_SHIFT)
#define VI_DSP_LATCH1_L_REG_SET_GUN1_HCT(vi_dsp_latch1_l_reg, gun1_hct) { \
	FDL_ASSERT(!((gun1_hct) & ~((1 << VI_DSP_LATCH1_L_REG_GUN1_HCT_SIZE)-1))); \
	vi_dsp_latch1_l_reg = (((unsigned long)(vi_dsp_latch1_l_reg)) & ~VI_DSP_LATCH1_L_REG_GUN1_HCT_MASK) | (((unsigned long)(gun1_hct)) << VI_DSP_LATCH1_L_REG_GUN1_HCT_SHIFT);\
}
#define VI_DSP_LATCH1_L_REG_TOTAL_SIZE	11
#define VI_DSP_LATCH1_L_REG(gun1_hct) \
	((((unsigned long)(gun1_hct)) << VI_DSP_LATCH1_L_REG_GUN1_HCT_SHIFT))

typedef struct {
    unsigned long pad0:5;
    unsigned long gun1_hct:VI_DSP_LATCH1_L_REG_GUN1_HCT_SIZE;
} vi_dsp_latch1_l_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_latch1_l_reg_t f;
} vi_dsp_latch1_l_reg_u;

/*
 *  vi_dsp_latch1_u_reg struct
 */
#define VI_DSP_LATCH1_U_REG_GUN1_VCT_SIZE	11
#define VI_DSP_LATCH1_U_REG_GUN1_VCT_SHIFT	0
#define VI_DSP_LATCH1_U_REG_GUN1_VCT_MASK	0x000007ff
#define VI_DSP_LATCH1_U_REG_GET_GUN1_VCT(vi_dsp_latch1_u_reg) \
	((((unsigned long)(vi_dsp_latch1_u_reg)) & VI_DSP_LATCH1_U_REG_GUN1_VCT_MASK) >> VI_DSP_LATCH1_U_REG_GUN1_VCT_SHIFT)
#define VI_DSP_LATCH1_U_REG_SET_GUN1_VCT(vi_dsp_latch1_u_reg, gun1_vct) { \
	FDL_ASSERT(!((gun1_vct) & ~((1 << VI_DSP_LATCH1_U_REG_GUN1_VCT_SIZE)-1))); \
	vi_dsp_latch1_u_reg = (((unsigned long)(vi_dsp_latch1_u_reg)) & ~VI_DSP_LATCH1_U_REG_GUN1_VCT_MASK) | (((unsigned long)(gun1_vct)) << VI_DSP_LATCH1_U_REG_GUN1_VCT_SHIFT);\
}
#define VI_DSP_LATCH1_U_REG_PAD0_SIZE	4
#define VI_DSP_LATCH1_U_REG_PAD0_SHIFT	11
#define VI_DSP_LATCH1_U_REG_PAD0_MASK	0x00007800
#define VI_DSP_LATCH1_U_REG_GET_PAD0(vi_dsp_latch1_u_reg) \
	((((unsigned long)(vi_dsp_latch1_u_reg)) & VI_DSP_LATCH1_U_REG_PAD0_MASK) >> VI_DSP_LATCH1_U_REG_PAD0_SHIFT)
#define VI_DSP_LATCH1_U_REG_SET_PAD0(vi_dsp_latch1_u_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_DSP_LATCH1_U_REG_PAD0_SIZE)-1))); \
	vi_dsp_latch1_u_reg = (((unsigned long)(vi_dsp_latch1_u_reg)) & ~VI_DSP_LATCH1_U_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_DSP_LATCH1_U_REG_PAD0_SHIFT);\
}
#define VI_DSP_LATCH1_U_REG_GUN1_TRG_SIZE	1
#define VI_DSP_LATCH1_U_REG_GUN1_TRG_SHIFT	15
#define VI_DSP_LATCH1_U_REG_GUN1_TRG_MASK	0x00008000
#define VI_DSP_LATCH1_U_REG_GET_GUN1_TRG(vi_dsp_latch1_u_reg) \
	((((unsigned long)(vi_dsp_latch1_u_reg)) & VI_DSP_LATCH1_U_REG_GUN1_TRG_MASK) >> VI_DSP_LATCH1_U_REG_GUN1_TRG_SHIFT)
#define VI_DSP_LATCH1_U_REG_SET_GUN1_TRG(vi_dsp_latch1_u_reg, gun1_trg) { \
	FDL_ASSERT(!((gun1_trg) & ~((1 << VI_DSP_LATCH1_U_REG_GUN1_TRG_SIZE)-1))); \
	vi_dsp_latch1_u_reg = (((unsigned long)(vi_dsp_latch1_u_reg)) & ~VI_DSP_LATCH1_U_REG_GUN1_TRG_MASK) | (((unsigned long)(gun1_trg)) << VI_DSP_LATCH1_U_REG_GUN1_TRG_SHIFT);\
}
#define VI_DSP_LATCH1_U_REG_TOTAL_SIZE	16
#define VI_DSP_LATCH1_U_REG(gun1_vct, gun1_trg) \
	((((unsigned long)(gun1_vct)) << VI_DSP_LATCH1_U_REG_GUN1_VCT_SHIFT) | \
	 (((unsigned long)(gun1_trg)) << VI_DSP_LATCH1_U_REG_GUN1_TRG_SHIFT))

typedef struct {
    unsigned long gun1_trg:VI_DSP_LATCH1_U_REG_GUN1_TRG_SIZE;
    unsigned long pad0:VI_DSP_LATCH1_U_REG_PAD0_SIZE;
    unsigned long gun1_vct:VI_DSP_LATCH1_U_REG_GUN1_VCT_SIZE;
} vi_dsp_latch1_u_reg_t;

typedef union {
    unsigned long val;
    vi_dsp_latch1_u_reg_t f;
} vi_dsp_latch1_u_reg_u;

/*
 *  vi_hscale_reg struct
 */
#define VI_HSCALE_REG_STEP_SIZE	9
#define VI_HSCALE_REG_STEP_SHIFT	0
#define VI_HSCALE_REG_STEP_MASK	0x000001ff
#define VI_HSCALE_REG_GET_STEP(vi_hscale_reg) \
	((((unsigned long)(vi_hscale_reg)) & VI_HSCALE_REG_STEP_MASK) >> VI_HSCALE_REG_STEP_SHIFT)
#define VI_HSCALE_REG_SET_STEP(vi_hscale_reg, step) { \
	FDL_ASSERT(!((step) & ~((1 << VI_HSCALE_REG_STEP_SIZE)-1))); \
	vi_hscale_reg = (((unsigned long)(vi_hscale_reg)) & ~VI_HSCALE_REG_STEP_MASK) | (((unsigned long)(step)) << VI_HSCALE_REG_STEP_SHIFT);\
}
#define VI_HSCALE_REG_PAD0_SIZE	3
#define VI_HSCALE_REG_PAD0_SHIFT	9
#define VI_HSCALE_REG_PAD0_MASK	0x00000e00
#define VI_HSCALE_REG_GET_PAD0(vi_hscale_reg) \
	((((unsigned long)(vi_hscale_reg)) & VI_HSCALE_REG_PAD0_MASK) >> VI_HSCALE_REG_PAD0_SHIFT)
#define VI_HSCALE_REG_SET_PAD0(vi_hscale_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << VI_HSCALE_REG_PAD0_SIZE)-1))); \
	vi_hscale_reg = (((unsigned long)(vi_hscale_reg)) & ~VI_HSCALE_REG_PAD0_MASK) | (((unsigned long)(pad0)) << VI_HSCALE_REG_PAD0_SHIFT);\
}
#define VI_HSCALE_REG_HSCALER_EN_SIZE	1
#define VI_HSCALE_REG_HSCALER_EN_SHIFT	12
#define VI_HSCALE_REG_HSCALER_EN_MASK	0x00001000
#define VI_HSCALE_REG_GET_HSCALER_EN(vi_hscale_reg) \
	((((unsigned long)(vi_hscale_reg)) & VI_HSCALE_REG_HSCALER_EN_MASK) >> VI_HSCALE_REG_HSCALER_EN_SHIFT)
#define VI_HSCALE_REG_SET_HSCALER_EN(vi_hscale_reg, hscaler_en) { \
	FDL_ASSERT(!((hscaler_en) & ~((1 << VI_HSCALE_REG_HSCALER_EN_SIZE)-1))); \
	vi_hscale_reg = (((unsigned long)(vi_hscale_reg)) & ~VI_HSCALE_REG_HSCALER_EN_MASK) | (((unsigned long)(hscaler_en)) << VI_HSCALE_REG_HSCALER_EN_SHIFT);\
}
#define VI_HSCALE_REG_TOTAL_SIZE	13
#define VI_HSCALE_REG(step, hscaler_en) \
	((((unsigned long)(step)) << VI_HSCALE_REG_STEP_SHIFT) | \
	 (((unsigned long)(hscaler_en)) << VI_HSCALE_REG_HSCALER_EN_SHIFT))

typedef struct {
    unsigned long pad1:3;
    unsigned long hscaler_en:VI_HSCALE_REG_HSCALER_EN_SIZE;
    unsigned long pad0:VI_HSCALE_REG_PAD0_SIZE;
    unsigned long step:VI_HSCALE_REG_STEP_SIZE;
} vi_hscale_reg_t;

typedef union {
    unsigned long val;
    vi_hscale_reg_t f;
} vi_hscale_reg_u;

/*
 *  vi_fltr_coeff0_l_reg struct
 */
#define VI_FLTR_COEFF0_L_REG_T0_SIZE	10
#define VI_FLTR_COEFF0_L_REG_T0_SHIFT	0
#define VI_FLTR_COEFF0_L_REG_T0_MASK	0x000003ff
#define VI_FLTR_COEFF0_L_REG_GET_T0(vi_fltr_coeff0_l_reg) \
	((((unsigned long)(vi_fltr_coeff0_l_reg)) & VI_FLTR_COEFF0_L_REG_T0_MASK) >> VI_FLTR_COEFF0_L_REG_T0_SHIFT)
#define VI_FLTR_COEFF0_L_REG_SET_T0(vi_fltr_coeff0_l_reg, t0) { \
	FDL_ASSERT(!((t0) & ~((1 << VI_FLTR_COEFF0_L_REG_T0_SIZE)-1))); \
	vi_fltr_coeff0_l_reg = (((unsigned long)(vi_fltr_coeff0_l_reg)) & ~VI_FLTR_COEFF0_L_REG_T0_MASK) | (((unsigned long)(t0)) << VI_FLTR_COEFF0_L_REG_T0_SHIFT);\
}
#define VI_FLTR_COEFF0_L_REG_T1_L_SIZE	6
#define VI_FLTR_COEFF0_L_REG_T1_L_SHIFT	10
#define VI_FLTR_COEFF0_L_REG_T1_L_MASK	0x0000fc00
#define VI_FLTR_COEFF0_L_REG_GET_T1_L(vi_fltr_coeff0_l_reg) \
	((((unsigned long)(vi_fltr_coeff0_l_reg)) & VI_FLTR_COEFF0_L_REG_T1_L_MASK) >> VI_FLTR_COEFF0_L_REG_T1_L_SHIFT)
#define VI_FLTR_COEFF0_L_REG_SET_T1_L(vi_fltr_coeff0_l_reg, t1_l) { \
	FDL_ASSERT(!((t1_l) & ~((1 << VI_FLTR_COEFF0_L_REG_T1_L_SIZE)-1))); \
	vi_fltr_coeff0_l_reg = (((unsigned long)(vi_fltr_coeff0_l_reg)) & ~VI_FLTR_COEFF0_L_REG_T1_L_MASK) | (((unsigned long)(t1_l)) << VI_FLTR_COEFF0_L_REG_T1_L_SHIFT);\
}
#define VI_FLTR_COEFF0_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF0_L_REG(t0, t1_l) \
	((((unsigned long)(t0)) << VI_FLTR_COEFF0_L_REG_T0_SHIFT) | \
	 (((unsigned long)(t1_l)) << VI_FLTR_COEFF0_L_REG_T1_L_SHIFT))

typedef struct {
    unsigned long t1_l:VI_FLTR_COEFF0_L_REG_T1_L_SIZE;
    unsigned long t0:VI_FLTR_COEFF0_L_REG_T0_SIZE;
} vi_fltr_coeff0_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff0_l_reg_t f;
} vi_fltr_coeff0_l_reg_u;

/*
 *  vi_fltr_coeff0_u_reg struct
 */
#define VI_FLTR_COEFF0_U_REG_T1_U_SIZE	4
#define VI_FLTR_COEFF0_U_REG_T1_U_SHIFT	0
#define VI_FLTR_COEFF0_U_REG_T1_U_MASK	0x0000000f
#define VI_FLTR_COEFF0_U_REG_GET_T1_U(vi_fltr_coeff0_u_reg) \
	((((unsigned long)(vi_fltr_coeff0_u_reg)) & VI_FLTR_COEFF0_U_REG_T1_U_MASK) >> VI_FLTR_COEFF0_U_REG_T1_U_SHIFT)
#define VI_FLTR_COEFF0_U_REG_SET_T1_U(vi_fltr_coeff0_u_reg, t1_u) { \
	FDL_ASSERT(!((t1_u) & ~((1 << VI_FLTR_COEFF0_U_REG_T1_U_SIZE)-1))); \
	vi_fltr_coeff0_u_reg = (((unsigned long)(vi_fltr_coeff0_u_reg)) & ~VI_FLTR_COEFF0_U_REG_T1_U_MASK) | (((unsigned long)(t1_u)) << VI_FLTR_COEFF0_U_REG_T1_U_SHIFT);\
}
#define VI_FLTR_COEFF0_U_REG_T2_SIZE	10
#define VI_FLTR_COEFF0_U_REG_T2_SHIFT	4
#define VI_FLTR_COEFF0_U_REG_T2_MASK	0x00003ff0
#define VI_FLTR_COEFF0_U_REG_GET_T2(vi_fltr_coeff0_u_reg) \
	((((unsigned long)(vi_fltr_coeff0_u_reg)) & VI_FLTR_COEFF0_U_REG_T2_MASK) >> VI_FLTR_COEFF0_U_REG_T2_SHIFT)
#define VI_FLTR_COEFF0_U_REG_SET_T2(vi_fltr_coeff0_u_reg, t2) { \
	FDL_ASSERT(!((t2) & ~((1 << VI_FLTR_COEFF0_U_REG_T2_SIZE)-1))); \
	vi_fltr_coeff0_u_reg = (((unsigned long)(vi_fltr_coeff0_u_reg)) & ~VI_FLTR_COEFF0_U_REG_T2_MASK) | (((unsigned long)(t2)) << VI_FLTR_COEFF0_U_REG_T2_SHIFT);\
}
#define VI_FLTR_COEFF0_U_REG_TOTAL_SIZE	14
#define VI_FLTR_COEFF0_U_REG(t1_u, t2) \
	((((unsigned long)(t1_u)) << VI_FLTR_COEFF0_U_REG_T1_U_SHIFT) | \
	 (((unsigned long)(t2)) << VI_FLTR_COEFF0_U_REG_T2_SHIFT))

typedef struct {
    unsigned long pad0:2;
    unsigned long t2:VI_FLTR_COEFF0_U_REG_T2_SIZE;
    unsigned long t1_u:VI_FLTR_COEFF0_U_REG_T1_U_SIZE;
} vi_fltr_coeff0_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff0_u_reg_t f;
} vi_fltr_coeff0_u_reg_u;

/*
 *  vi_fltr_coeff1_l_reg struct
 */
#define VI_FLTR_COEFF1_L_REG_T3_SIZE	10
#define VI_FLTR_COEFF1_L_REG_T3_SHIFT	0
#define VI_FLTR_COEFF1_L_REG_T3_MASK	0x000003ff
#define VI_FLTR_COEFF1_L_REG_GET_T3(vi_fltr_coeff1_l_reg) \
	((((unsigned long)(vi_fltr_coeff1_l_reg)) & VI_FLTR_COEFF1_L_REG_T3_MASK) >> VI_FLTR_COEFF1_L_REG_T3_SHIFT)
#define VI_FLTR_COEFF1_L_REG_SET_T3(vi_fltr_coeff1_l_reg, t3) { \
	FDL_ASSERT(!((t3) & ~((1 << VI_FLTR_COEFF1_L_REG_T3_SIZE)-1))); \
	vi_fltr_coeff1_l_reg = (((unsigned long)(vi_fltr_coeff1_l_reg)) & ~VI_FLTR_COEFF1_L_REG_T3_MASK) | (((unsigned long)(t3)) << VI_FLTR_COEFF1_L_REG_T3_SHIFT);\
}
#define VI_FLTR_COEFF1_L_REG_T4_L_SIZE	6
#define VI_FLTR_COEFF1_L_REG_T4_L_SHIFT	10
#define VI_FLTR_COEFF1_L_REG_T4_L_MASK	0x0000fc00
#define VI_FLTR_COEFF1_L_REG_GET_T4_L(vi_fltr_coeff1_l_reg) \
	((((unsigned long)(vi_fltr_coeff1_l_reg)) & VI_FLTR_COEFF1_L_REG_T4_L_MASK) >> VI_FLTR_COEFF1_L_REG_T4_L_SHIFT)
#define VI_FLTR_COEFF1_L_REG_SET_T4_L(vi_fltr_coeff1_l_reg, t4_l) { \
	FDL_ASSERT(!((t4_l) & ~((1 << VI_FLTR_COEFF1_L_REG_T4_L_SIZE)-1))); \
	vi_fltr_coeff1_l_reg = (((unsigned long)(vi_fltr_coeff1_l_reg)) & ~VI_FLTR_COEFF1_L_REG_T4_L_MASK) | (((unsigned long)(t4_l)) << VI_FLTR_COEFF1_L_REG_T4_L_SHIFT);\
}
#define VI_FLTR_COEFF1_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF1_L_REG(t3, t4_l) \
	((((unsigned long)(t3)) << VI_FLTR_COEFF1_L_REG_T3_SHIFT) | \
	 (((unsigned long)(t4_l)) << VI_FLTR_COEFF1_L_REG_T4_L_SHIFT))

typedef struct {
    unsigned long t4_l:VI_FLTR_COEFF1_L_REG_T4_L_SIZE;
    unsigned long t3:VI_FLTR_COEFF1_L_REG_T3_SIZE;
} vi_fltr_coeff1_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff1_l_reg_t f;
} vi_fltr_coeff1_l_reg_u;

/*
 *  vi_fltr_coeff1_u_reg struct
 */
#define VI_FLTR_COEFF1_U_REG_T4_U_SIZE	4
#define VI_FLTR_COEFF1_U_REG_T4_U_SHIFT	0
#define VI_FLTR_COEFF1_U_REG_T4_U_MASK	0x0000000f
#define VI_FLTR_COEFF1_U_REG_GET_T4_U(vi_fltr_coeff1_u_reg) \
	((((unsigned long)(vi_fltr_coeff1_u_reg)) & VI_FLTR_COEFF1_U_REG_T4_U_MASK) >> VI_FLTR_COEFF1_U_REG_T4_U_SHIFT)
#define VI_FLTR_COEFF1_U_REG_SET_T4_U(vi_fltr_coeff1_u_reg, t4_u) { \
	FDL_ASSERT(!((t4_u) & ~((1 << VI_FLTR_COEFF1_U_REG_T4_U_SIZE)-1))); \
	vi_fltr_coeff1_u_reg = (((unsigned long)(vi_fltr_coeff1_u_reg)) & ~VI_FLTR_COEFF1_U_REG_T4_U_MASK) | (((unsigned long)(t4_u)) << VI_FLTR_COEFF1_U_REG_T4_U_SHIFT);\
}
#define VI_FLTR_COEFF1_U_REG_T5_SIZE	10
#define VI_FLTR_COEFF1_U_REG_T5_SHIFT	4
#define VI_FLTR_COEFF1_U_REG_T5_MASK	0x00003ff0
#define VI_FLTR_COEFF1_U_REG_GET_T5(vi_fltr_coeff1_u_reg) \
	((((unsigned long)(vi_fltr_coeff1_u_reg)) & VI_FLTR_COEFF1_U_REG_T5_MASK) >> VI_FLTR_COEFF1_U_REG_T5_SHIFT)
#define VI_FLTR_COEFF1_U_REG_SET_T5(vi_fltr_coeff1_u_reg, t5) { \
	FDL_ASSERT(!((t5) & ~((1 << VI_FLTR_COEFF1_U_REG_T5_SIZE)-1))); \
	vi_fltr_coeff1_u_reg = (((unsigned long)(vi_fltr_coeff1_u_reg)) & ~VI_FLTR_COEFF1_U_REG_T5_MASK) | (((unsigned long)(t5)) << VI_FLTR_COEFF1_U_REG_T5_SHIFT);\
}
#define VI_FLTR_COEFF1_U_REG_TOTAL_SIZE	14
#define VI_FLTR_COEFF1_U_REG(t4_u, t5) \
	((((unsigned long)(t4_u)) << VI_FLTR_COEFF1_U_REG_T4_U_SHIFT) | \
	 (((unsigned long)(t5)) << VI_FLTR_COEFF1_U_REG_T5_SHIFT))

typedef struct {
    unsigned long pad0:2;
    unsigned long t5:VI_FLTR_COEFF1_U_REG_T5_SIZE;
    unsigned long t4_u:VI_FLTR_COEFF1_U_REG_T4_U_SIZE;
} vi_fltr_coeff1_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff1_u_reg_t f;
} vi_fltr_coeff1_u_reg_u;

/*
 *  vi_fltr_coeff2_l_reg struct
 */
#define VI_FLTR_COEFF2_L_REG_T6_SIZE	10
#define VI_FLTR_COEFF2_L_REG_T6_SHIFT	0
#define VI_FLTR_COEFF2_L_REG_T6_MASK	0x000003ff
#define VI_FLTR_COEFF2_L_REG_GET_T6(vi_fltr_coeff2_l_reg) \
	((((unsigned long)(vi_fltr_coeff2_l_reg)) & VI_FLTR_COEFF2_L_REG_T6_MASK) >> VI_FLTR_COEFF2_L_REG_T6_SHIFT)
#define VI_FLTR_COEFF2_L_REG_SET_T6(vi_fltr_coeff2_l_reg, t6) { \
	FDL_ASSERT(!((t6) & ~((1 << VI_FLTR_COEFF2_L_REG_T6_SIZE)-1))); \
	vi_fltr_coeff2_l_reg = (((unsigned long)(vi_fltr_coeff2_l_reg)) & ~VI_FLTR_COEFF2_L_REG_T6_MASK) | (((unsigned long)(t6)) << VI_FLTR_COEFF2_L_REG_T6_SHIFT);\
}
#define VI_FLTR_COEFF2_L_REG_T7_L_SIZE	6
#define VI_FLTR_COEFF2_L_REG_T7_L_SHIFT	10
#define VI_FLTR_COEFF2_L_REG_T7_L_MASK	0x0000fc00
#define VI_FLTR_COEFF2_L_REG_GET_T7_L(vi_fltr_coeff2_l_reg) \
	((((unsigned long)(vi_fltr_coeff2_l_reg)) & VI_FLTR_COEFF2_L_REG_T7_L_MASK) >> VI_FLTR_COEFF2_L_REG_T7_L_SHIFT)
#define VI_FLTR_COEFF2_L_REG_SET_T7_L(vi_fltr_coeff2_l_reg, t7_l) { \
	FDL_ASSERT(!((t7_l) & ~((1 << VI_FLTR_COEFF2_L_REG_T7_L_SIZE)-1))); \
	vi_fltr_coeff2_l_reg = (((unsigned long)(vi_fltr_coeff2_l_reg)) & ~VI_FLTR_COEFF2_L_REG_T7_L_MASK) | (((unsigned long)(t7_l)) << VI_FLTR_COEFF2_L_REG_T7_L_SHIFT);\
}
#define VI_FLTR_COEFF2_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF2_L_REG(t6, t7_l) \
	((((unsigned long)(t6)) << VI_FLTR_COEFF2_L_REG_T6_SHIFT) | \
	 (((unsigned long)(t7_l)) << VI_FLTR_COEFF2_L_REG_T7_L_SHIFT))

typedef struct {
    unsigned long t7_l:VI_FLTR_COEFF2_L_REG_T7_L_SIZE;
    unsigned long t6:VI_FLTR_COEFF2_L_REG_T6_SIZE;
} vi_fltr_coeff2_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff2_l_reg_t f;
} vi_fltr_coeff2_l_reg_u;

/*
 *  vi_fltr_coeff2_u_reg struct
 */
#define VI_FLTR_COEFF2_U_REG_T7_U_SIZE	4
#define VI_FLTR_COEFF2_U_REG_T7_U_SHIFT	0
#define VI_FLTR_COEFF2_U_REG_T7_U_MASK	0x0000000f
#define VI_FLTR_COEFF2_U_REG_GET_T7_U(vi_fltr_coeff2_u_reg) \
	((((unsigned long)(vi_fltr_coeff2_u_reg)) & VI_FLTR_COEFF2_U_REG_T7_U_MASK) >> VI_FLTR_COEFF2_U_REG_T7_U_SHIFT)
#define VI_FLTR_COEFF2_U_REG_SET_T7_U(vi_fltr_coeff2_u_reg, t7_u) { \
	FDL_ASSERT(!((t7_u) & ~((1 << VI_FLTR_COEFF2_U_REG_T7_U_SIZE)-1))); \
	vi_fltr_coeff2_u_reg = (((unsigned long)(vi_fltr_coeff2_u_reg)) & ~VI_FLTR_COEFF2_U_REG_T7_U_MASK) | (((unsigned long)(t7_u)) << VI_FLTR_COEFF2_U_REG_T7_U_SHIFT);\
}
#define VI_FLTR_COEFF2_U_REG_T8_SIZE	10
#define VI_FLTR_COEFF2_U_REG_T8_SHIFT	4
#define VI_FLTR_COEFF2_U_REG_T8_MASK	0x00003ff0
#define VI_FLTR_COEFF2_U_REG_GET_T8(vi_fltr_coeff2_u_reg) \
	((((unsigned long)(vi_fltr_coeff2_u_reg)) & VI_FLTR_COEFF2_U_REG_T8_MASK) >> VI_FLTR_COEFF2_U_REG_T8_SHIFT)
#define VI_FLTR_COEFF2_U_REG_SET_T8(vi_fltr_coeff2_u_reg, t8) { \
	FDL_ASSERT(!((t8) & ~((1 << VI_FLTR_COEFF2_U_REG_T8_SIZE)-1))); \
	vi_fltr_coeff2_u_reg = (((unsigned long)(vi_fltr_coeff2_u_reg)) & ~VI_FLTR_COEFF2_U_REG_T8_MASK) | (((unsigned long)(t8)) << VI_FLTR_COEFF2_U_REG_T8_SHIFT);\
}
#define VI_FLTR_COEFF2_U_REG_TOTAL_SIZE	14
#define VI_FLTR_COEFF2_U_REG(t7_u, t8) \
	((((unsigned long)(t7_u)) << VI_FLTR_COEFF2_U_REG_T7_U_SHIFT) | \
	 (((unsigned long)(t8)) << VI_FLTR_COEFF2_U_REG_T8_SHIFT))

typedef struct {
    unsigned long pad0:2;
    unsigned long t8:VI_FLTR_COEFF2_U_REG_T8_SIZE;
    unsigned long t7_u:VI_FLTR_COEFF2_U_REG_T7_U_SIZE;
} vi_fltr_coeff2_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff2_u_reg_t f;
} vi_fltr_coeff2_u_reg_u;

/*
 *  vi_fltr_coeff3_l_reg struct
 */
#define VI_FLTR_COEFF3_L_REG_T9_SIZE	8
#define VI_FLTR_COEFF3_L_REG_T9_SHIFT	0
#define VI_FLTR_COEFF3_L_REG_T9_MASK	0x000000ff
#define VI_FLTR_COEFF3_L_REG_GET_T9(vi_fltr_coeff3_l_reg) \
	((((unsigned long)(vi_fltr_coeff3_l_reg)) & VI_FLTR_COEFF3_L_REG_T9_MASK) >> VI_FLTR_COEFF3_L_REG_T9_SHIFT)
#define VI_FLTR_COEFF3_L_REG_SET_T9(vi_fltr_coeff3_l_reg, t9) { \
	FDL_ASSERT(!((t9) & ~((1 << VI_FLTR_COEFF3_L_REG_T9_SIZE)-1))); \
	vi_fltr_coeff3_l_reg = (((unsigned long)(vi_fltr_coeff3_l_reg)) & ~VI_FLTR_COEFF3_L_REG_T9_MASK) | (((unsigned long)(t9)) << VI_FLTR_COEFF3_L_REG_T9_SHIFT);\
}
#define VI_FLTR_COEFF3_L_REG_T10_SIZE	8
#define VI_FLTR_COEFF3_L_REG_T10_SHIFT	8
#define VI_FLTR_COEFF3_L_REG_T10_MASK	0x0000ff00
#define VI_FLTR_COEFF3_L_REG_GET_T10(vi_fltr_coeff3_l_reg) \
	((((unsigned long)(vi_fltr_coeff3_l_reg)) & VI_FLTR_COEFF3_L_REG_T10_MASK) >> VI_FLTR_COEFF3_L_REG_T10_SHIFT)
#define VI_FLTR_COEFF3_L_REG_SET_T10(vi_fltr_coeff3_l_reg, t10) { \
	FDL_ASSERT(!((t10) & ~((1 << VI_FLTR_COEFF3_L_REG_T10_SIZE)-1))); \
	vi_fltr_coeff3_l_reg = (((unsigned long)(vi_fltr_coeff3_l_reg)) & ~VI_FLTR_COEFF3_L_REG_T10_MASK) | (((unsigned long)(t10)) << VI_FLTR_COEFF3_L_REG_T10_SHIFT);\
}
#define VI_FLTR_COEFF3_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF3_L_REG(t9, t10) \
	((((unsigned long)(t9)) << VI_FLTR_COEFF3_L_REG_T9_SHIFT) | \
	 (((unsigned long)(t10)) << VI_FLTR_COEFF3_L_REG_T10_SHIFT))

typedef struct {
    unsigned long t10:VI_FLTR_COEFF3_L_REG_T10_SIZE;
    unsigned long t9:VI_FLTR_COEFF3_L_REG_T9_SIZE;
} vi_fltr_coeff3_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff3_l_reg_t f;
} vi_fltr_coeff3_l_reg_u;

/*
 *  vi_fltr_coeff3_u_reg struct
 */
#define VI_FLTR_COEFF3_U_REG_T11_SIZE	8
#define VI_FLTR_COEFF3_U_REG_T11_SHIFT	0
#define VI_FLTR_COEFF3_U_REG_T11_MASK	0x000000ff
#define VI_FLTR_COEFF3_U_REG_GET_T11(vi_fltr_coeff3_u_reg) \
	((((unsigned long)(vi_fltr_coeff3_u_reg)) & VI_FLTR_COEFF3_U_REG_T11_MASK) >> VI_FLTR_COEFF3_U_REG_T11_SHIFT)
#define VI_FLTR_COEFF3_U_REG_SET_T11(vi_fltr_coeff3_u_reg, t11) { \
	FDL_ASSERT(!((t11) & ~((1 << VI_FLTR_COEFF3_U_REG_T11_SIZE)-1))); \
	vi_fltr_coeff3_u_reg = (((unsigned long)(vi_fltr_coeff3_u_reg)) & ~VI_FLTR_COEFF3_U_REG_T11_MASK) | (((unsigned long)(t11)) << VI_FLTR_COEFF3_U_REG_T11_SHIFT);\
}
#define VI_FLTR_COEFF3_U_REG_T12_SIZE	8
#define VI_FLTR_COEFF3_U_REG_T12_SHIFT	8
#define VI_FLTR_COEFF3_U_REG_T12_MASK	0x0000ff00
#define VI_FLTR_COEFF3_U_REG_GET_T12(vi_fltr_coeff3_u_reg) \
	((((unsigned long)(vi_fltr_coeff3_u_reg)) & VI_FLTR_COEFF3_U_REG_T12_MASK) >> VI_FLTR_COEFF3_U_REG_T12_SHIFT)
#define VI_FLTR_COEFF3_U_REG_SET_T12(vi_fltr_coeff3_u_reg, t12) { \
	FDL_ASSERT(!((t12) & ~((1 << VI_FLTR_COEFF3_U_REG_T12_SIZE)-1))); \
	vi_fltr_coeff3_u_reg = (((unsigned long)(vi_fltr_coeff3_u_reg)) & ~VI_FLTR_COEFF3_U_REG_T12_MASK) | (((unsigned long)(t12)) << VI_FLTR_COEFF3_U_REG_T12_SHIFT);\
}
#define VI_FLTR_COEFF3_U_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF3_U_REG(t11, t12) \
	((((unsigned long)(t11)) << VI_FLTR_COEFF3_U_REG_T11_SHIFT) | \
	 (((unsigned long)(t12)) << VI_FLTR_COEFF3_U_REG_T12_SHIFT))

typedef struct {
    unsigned long t12:VI_FLTR_COEFF3_U_REG_T12_SIZE;
    unsigned long t11:VI_FLTR_COEFF3_U_REG_T11_SIZE;
} vi_fltr_coeff3_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff3_u_reg_t f;
} vi_fltr_coeff3_u_reg_u;

/*
 *  vi_fltr_coeff4_l_reg struct
 */
#define VI_FLTR_COEFF4_L_REG_T13_SIZE	8
#define VI_FLTR_COEFF4_L_REG_T13_SHIFT	0
#define VI_FLTR_COEFF4_L_REG_T13_MASK	0x000000ff
#define VI_FLTR_COEFF4_L_REG_GET_T13(vi_fltr_coeff4_l_reg) \
	((((unsigned long)(vi_fltr_coeff4_l_reg)) & VI_FLTR_COEFF4_L_REG_T13_MASK) >> VI_FLTR_COEFF4_L_REG_T13_SHIFT)
#define VI_FLTR_COEFF4_L_REG_SET_T13(vi_fltr_coeff4_l_reg, t13) { \
	FDL_ASSERT(!((t13) & ~((1 << VI_FLTR_COEFF4_L_REG_T13_SIZE)-1))); \
	vi_fltr_coeff4_l_reg = (((unsigned long)(vi_fltr_coeff4_l_reg)) & ~VI_FLTR_COEFF4_L_REG_T13_MASK) | (((unsigned long)(t13)) << VI_FLTR_COEFF4_L_REG_T13_SHIFT);\
}
#define VI_FLTR_COEFF4_L_REG_T14_SIZE	8
#define VI_FLTR_COEFF4_L_REG_T14_SHIFT	8
#define VI_FLTR_COEFF4_L_REG_T14_MASK	0x0000ff00
#define VI_FLTR_COEFF4_L_REG_GET_T14(vi_fltr_coeff4_l_reg) \
	((((unsigned long)(vi_fltr_coeff4_l_reg)) & VI_FLTR_COEFF4_L_REG_T14_MASK) >> VI_FLTR_COEFF4_L_REG_T14_SHIFT)
#define VI_FLTR_COEFF4_L_REG_SET_T14(vi_fltr_coeff4_l_reg, t14) { \
	FDL_ASSERT(!((t14) & ~((1 << VI_FLTR_COEFF4_L_REG_T14_SIZE)-1))); \
	vi_fltr_coeff4_l_reg = (((unsigned long)(vi_fltr_coeff4_l_reg)) & ~VI_FLTR_COEFF4_L_REG_T14_MASK) | (((unsigned long)(t14)) << VI_FLTR_COEFF4_L_REG_T14_SHIFT);\
}
#define VI_FLTR_COEFF4_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF4_L_REG(t13, t14) \
	((((unsigned long)(t13)) << VI_FLTR_COEFF4_L_REG_T13_SHIFT) | \
	 (((unsigned long)(t14)) << VI_FLTR_COEFF4_L_REG_T14_SHIFT))

typedef struct {
    unsigned long t14:VI_FLTR_COEFF4_L_REG_T14_SIZE;
    unsigned long t13:VI_FLTR_COEFF4_L_REG_T13_SIZE;
} vi_fltr_coeff4_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff4_l_reg_t f;
} vi_fltr_coeff4_l_reg_u;

/*
 *  vi_fltr_coeff4_u_reg struct
 */
#define VI_FLTR_COEFF4_U_REG_T15_SIZE	8
#define VI_FLTR_COEFF4_U_REG_T15_SHIFT	0
#define VI_FLTR_COEFF4_U_REG_T15_MASK	0x000000ff
#define VI_FLTR_COEFF4_U_REG_GET_T15(vi_fltr_coeff4_u_reg) \
	((((unsigned long)(vi_fltr_coeff4_u_reg)) & VI_FLTR_COEFF4_U_REG_T15_MASK) >> VI_FLTR_COEFF4_U_REG_T15_SHIFT)
#define VI_FLTR_COEFF4_U_REG_SET_T15(vi_fltr_coeff4_u_reg, t15) { \
	FDL_ASSERT(!((t15) & ~((1 << VI_FLTR_COEFF4_U_REG_T15_SIZE)-1))); \
	vi_fltr_coeff4_u_reg = (((unsigned long)(vi_fltr_coeff4_u_reg)) & ~VI_FLTR_COEFF4_U_REG_T15_MASK) | (((unsigned long)(t15)) << VI_FLTR_COEFF4_U_REG_T15_SHIFT);\
}
#define VI_FLTR_COEFF4_U_REG_T16_SIZE	8
#define VI_FLTR_COEFF4_U_REG_T16_SHIFT	8
#define VI_FLTR_COEFF4_U_REG_T16_MASK	0x0000ff00
#define VI_FLTR_COEFF4_U_REG_GET_T16(vi_fltr_coeff4_u_reg) \
	((((unsigned long)(vi_fltr_coeff4_u_reg)) & VI_FLTR_COEFF4_U_REG_T16_MASK) >> VI_FLTR_COEFF4_U_REG_T16_SHIFT)
#define VI_FLTR_COEFF4_U_REG_SET_T16(vi_fltr_coeff4_u_reg, t16) { \
	FDL_ASSERT(!((t16) & ~((1 << VI_FLTR_COEFF4_U_REG_T16_SIZE)-1))); \
	vi_fltr_coeff4_u_reg = (((unsigned long)(vi_fltr_coeff4_u_reg)) & ~VI_FLTR_COEFF4_U_REG_T16_MASK) | (((unsigned long)(t16)) << VI_FLTR_COEFF4_U_REG_T16_SHIFT);\
}
#define VI_FLTR_COEFF4_U_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF4_U_REG(t15, t16) \
	((((unsigned long)(t15)) << VI_FLTR_COEFF4_U_REG_T15_SHIFT) | \
	 (((unsigned long)(t16)) << VI_FLTR_COEFF4_U_REG_T16_SHIFT))

typedef struct {
    unsigned long t16:VI_FLTR_COEFF4_U_REG_T16_SIZE;
    unsigned long t15:VI_FLTR_COEFF4_U_REG_T15_SIZE;
} vi_fltr_coeff4_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff4_u_reg_t f;
} vi_fltr_coeff4_u_reg_u;

/*
 *  vi_fltr_coeff5_l_reg struct
 */
#define VI_FLTR_COEFF5_L_REG_T17_SIZE	8
#define VI_FLTR_COEFF5_L_REG_T17_SHIFT	0
#define VI_FLTR_COEFF5_L_REG_T17_MASK	0x000000ff
#define VI_FLTR_COEFF5_L_REG_GET_T17(vi_fltr_coeff5_l_reg) \
	((((unsigned long)(vi_fltr_coeff5_l_reg)) & VI_FLTR_COEFF5_L_REG_T17_MASK) >> VI_FLTR_COEFF5_L_REG_T17_SHIFT)
#define VI_FLTR_COEFF5_L_REG_SET_T17(vi_fltr_coeff5_l_reg, t17) { \
	FDL_ASSERT(!((t17) & ~((1 << VI_FLTR_COEFF5_L_REG_T17_SIZE)-1))); \
	vi_fltr_coeff5_l_reg = (((unsigned long)(vi_fltr_coeff5_l_reg)) & ~VI_FLTR_COEFF5_L_REG_T17_MASK) | (((unsigned long)(t17)) << VI_FLTR_COEFF5_L_REG_T17_SHIFT);\
}
#define VI_FLTR_COEFF5_L_REG_T18_SIZE	8
#define VI_FLTR_COEFF5_L_REG_T18_SHIFT	8
#define VI_FLTR_COEFF5_L_REG_T18_MASK	0x0000ff00
#define VI_FLTR_COEFF5_L_REG_GET_T18(vi_fltr_coeff5_l_reg) \
	((((unsigned long)(vi_fltr_coeff5_l_reg)) & VI_FLTR_COEFF5_L_REG_T18_MASK) >> VI_FLTR_COEFF5_L_REG_T18_SHIFT)
#define VI_FLTR_COEFF5_L_REG_SET_T18(vi_fltr_coeff5_l_reg, t18) { \
	FDL_ASSERT(!((t18) & ~((1 << VI_FLTR_COEFF5_L_REG_T18_SIZE)-1))); \
	vi_fltr_coeff5_l_reg = (((unsigned long)(vi_fltr_coeff5_l_reg)) & ~VI_FLTR_COEFF5_L_REG_T18_MASK) | (((unsigned long)(t18)) << VI_FLTR_COEFF5_L_REG_T18_SHIFT);\
}
#define VI_FLTR_COEFF5_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF5_L_REG(t17, t18) \
	((((unsigned long)(t17)) << VI_FLTR_COEFF5_L_REG_T17_SHIFT) | \
	 (((unsigned long)(t18)) << VI_FLTR_COEFF5_L_REG_T18_SHIFT))

typedef struct {
    unsigned long t18:VI_FLTR_COEFF5_L_REG_T18_SIZE;
    unsigned long t17:VI_FLTR_COEFF5_L_REG_T17_SIZE;
} vi_fltr_coeff5_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff5_l_reg_t f;
} vi_fltr_coeff5_l_reg_u;

/*
 *  vi_fltr_coeff5_u_reg struct
 */
#define VI_FLTR_COEFF5_U_REG_T19_SIZE	8
#define VI_FLTR_COEFF5_U_REG_T19_SHIFT	0
#define VI_FLTR_COEFF5_U_REG_T19_MASK	0x000000ff
#define VI_FLTR_COEFF5_U_REG_GET_T19(vi_fltr_coeff5_u_reg) \
	((((unsigned long)(vi_fltr_coeff5_u_reg)) & VI_FLTR_COEFF5_U_REG_T19_MASK) >> VI_FLTR_COEFF5_U_REG_T19_SHIFT)
#define VI_FLTR_COEFF5_U_REG_SET_T19(vi_fltr_coeff5_u_reg, t19) { \
	FDL_ASSERT(!((t19) & ~((1 << VI_FLTR_COEFF5_U_REG_T19_SIZE)-1))); \
	vi_fltr_coeff5_u_reg = (((unsigned long)(vi_fltr_coeff5_u_reg)) & ~VI_FLTR_COEFF5_U_REG_T19_MASK) | (((unsigned long)(t19)) << VI_FLTR_COEFF5_U_REG_T19_SHIFT);\
}
#define VI_FLTR_COEFF5_U_REG_T20_SIZE	8
#define VI_FLTR_COEFF5_U_REG_T20_SHIFT	8
#define VI_FLTR_COEFF5_U_REG_T20_MASK	0x0000ff00
#define VI_FLTR_COEFF5_U_REG_GET_T20(vi_fltr_coeff5_u_reg) \
	((((unsigned long)(vi_fltr_coeff5_u_reg)) & VI_FLTR_COEFF5_U_REG_T20_MASK) >> VI_FLTR_COEFF5_U_REG_T20_SHIFT)
#define VI_FLTR_COEFF5_U_REG_SET_T20(vi_fltr_coeff5_u_reg, t20) { \
	FDL_ASSERT(!((t20) & ~((1 << VI_FLTR_COEFF5_U_REG_T20_SIZE)-1))); \
	vi_fltr_coeff5_u_reg = (((unsigned long)(vi_fltr_coeff5_u_reg)) & ~VI_FLTR_COEFF5_U_REG_T20_MASK) | (((unsigned long)(t20)) << VI_FLTR_COEFF5_U_REG_T20_SHIFT);\
}
#define VI_FLTR_COEFF5_U_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF5_U_REG(t19, t20) \
	((((unsigned long)(t19)) << VI_FLTR_COEFF5_U_REG_T19_SHIFT) | \
	 (((unsigned long)(t20)) << VI_FLTR_COEFF5_U_REG_T20_SHIFT))

typedef struct {
    unsigned long t20:VI_FLTR_COEFF5_U_REG_T20_SIZE;
    unsigned long t19:VI_FLTR_COEFF5_U_REG_T19_SIZE;
} vi_fltr_coeff5_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff5_u_reg_t f;
} vi_fltr_coeff5_u_reg_u;

/*
 *  vi_fltr_coeff6_l_reg struct
 */
#define VI_FLTR_COEFF6_L_REG_T21_SIZE	8
#define VI_FLTR_COEFF6_L_REG_T21_SHIFT	0
#define VI_FLTR_COEFF6_L_REG_T21_MASK	0x000000ff
#define VI_FLTR_COEFF6_L_REG_GET_T21(vi_fltr_coeff6_l_reg) \
	((((unsigned long)(vi_fltr_coeff6_l_reg)) & VI_FLTR_COEFF6_L_REG_T21_MASK) >> VI_FLTR_COEFF6_L_REG_T21_SHIFT)
#define VI_FLTR_COEFF6_L_REG_SET_T21(vi_fltr_coeff6_l_reg, t21) { \
	FDL_ASSERT(!((t21) & ~((1 << VI_FLTR_COEFF6_L_REG_T21_SIZE)-1))); \
	vi_fltr_coeff6_l_reg = (((unsigned long)(vi_fltr_coeff6_l_reg)) & ~VI_FLTR_COEFF6_L_REG_T21_MASK) | (((unsigned long)(t21)) << VI_FLTR_COEFF6_L_REG_T21_SHIFT);\
}
#define VI_FLTR_COEFF6_L_REG_T22_SIZE	8
#define VI_FLTR_COEFF6_L_REG_T22_SHIFT	8
#define VI_FLTR_COEFF6_L_REG_T22_MASK	0x0000ff00
#define VI_FLTR_COEFF6_L_REG_GET_T22(vi_fltr_coeff6_l_reg) \
	((((unsigned long)(vi_fltr_coeff6_l_reg)) & VI_FLTR_COEFF6_L_REG_T22_MASK) >> VI_FLTR_COEFF6_L_REG_T22_SHIFT)
#define VI_FLTR_COEFF6_L_REG_SET_T22(vi_fltr_coeff6_l_reg, t22) { \
	FDL_ASSERT(!((t22) & ~((1 << VI_FLTR_COEFF6_L_REG_T22_SIZE)-1))); \
	vi_fltr_coeff6_l_reg = (((unsigned long)(vi_fltr_coeff6_l_reg)) & ~VI_FLTR_COEFF6_L_REG_T22_MASK) | (((unsigned long)(t22)) << VI_FLTR_COEFF6_L_REG_T22_SHIFT);\
}
#define VI_FLTR_COEFF6_L_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF6_L_REG(t21, t22) \
	((((unsigned long)(t21)) << VI_FLTR_COEFF6_L_REG_T21_SHIFT) | \
	 (((unsigned long)(t22)) << VI_FLTR_COEFF6_L_REG_T22_SHIFT))

typedef struct {
    unsigned long t22:VI_FLTR_COEFF6_L_REG_T22_SIZE;
    unsigned long t21:VI_FLTR_COEFF6_L_REG_T21_SIZE;
} vi_fltr_coeff6_l_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff6_l_reg_t f;
} vi_fltr_coeff6_l_reg_u;

/*
 *  vi_fltr_coeff6_u_reg struct
 */
#define VI_FLTR_COEFF6_U_REG_T23_SIZE	8
#define VI_FLTR_COEFF6_U_REG_T23_SHIFT	0
#define VI_FLTR_COEFF6_U_REG_T23_MASK	0x000000ff
#define VI_FLTR_COEFF6_U_REG_GET_T23(vi_fltr_coeff6_u_reg) \
	((((unsigned long)(vi_fltr_coeff6_u_reg)) & VI_FLTR_COEFF6_U_REG_T23_MASK) >> VI_FLTR_COEFF6_U_REG_T23_SHIFT)
#define VI_FLTR_COEFF6_U_REG_SET_T23(vi_fltr_coeff6_u_reg, t23) { \
	FDL_ASSERT(!((t23) & ~((1 << VI_FLTR_COEFF6_U_REG_T23_SIZE)-1))); \
	vi_fltr_coeff6_u_reg = (((unsigned long)(vi_fltr_coeff6_u_reg)) & ~VI_FLTR_COEFF6_U_REG_T23_MASK) | (((unsigned long)(t23)) << VI_FLTR_COEFF6_U_REG_T23_SHIFT);\
}
#define VI_FLTR_COEFF6_U_REG_T24_SIZE	8
#define VI_FLTR_COEFF6_U_REG_T24_SHIFT	8
#define VI_FLTR_COEFF6_U_REG_T24_MASK	0x0000ff00
#define VI_FLTR_COEFF6_U_REG_GET_T24(vi_fltr_coeff6_u_reg) \
	((((unsigned long)(vi_fltr_coeff6_u_reg)) & VI_FLTR_COEFF6_U_REG_T24_MASK) >> VI_FLTR_COEFF6_U_REG_T24_SHIFT)
#define VI_FLTR_COEFF6_U_REG_SET_T24(vi_fltr_coeff6_u_reg, t24) { \
	FDL_ASSERT(!((t24) & ~((1 << VI_FLTR_COEFF6_U_REG_T24_SIZE)-1))); \
	vi_fltr_coeff6_u_reg = (((unsigned long)(vi_fltr_coeff6_u_reg)) & ~VI_FLTR_COEFF6_U_REG_T24_MASK) | (((unsigned long)(t24)) << VI_FLTR_COEFF6_U_REG_T24_SHIFT);\
}
#define VI_FLTR_COEFF6_U_REG_TOTAL_SIZE	16
#define VI_FLTR_COEFF6_U_REG(t23, t24) \
	((((unsigned long)(t23)) << VI_FLTR_COEFF6_U_REG_T23_SHIFT) | \
	 (((unsigned long)(t24)) << VI_FLTR_COEFF6_U_REG_T24_SHIFT))

typedef struct {
    unsigned long t24:VI_FLTR_COEFF6_U_REG_T24_SIZE;
    unsigned long t23:VI_FLTR_COEFF6_U_REG_T23_SIZE;
} vi_fltr_coeff6_u_reg_t;

typedef union {
    unsigned long val;
    vi_fltr_coeff6_u_reg_t f;
} vi_fltr_coeff6_u_reg_u;

/*
 *  vi_clksel_reg struct
 */
#define VI_CLKSEL_REG_VICLKSEL_SIZE	1
#define VI_CLKSEL_REG_VICLKSEL_SHIFT	0
#define VI_CLKSEL_REG_VICLKSEL_MASK	0x00000001
#define VI_CLKSEL_REG_GET_VICLKSEL(vi_clksel_reg) \
	((((unsigned long)(vi_clksel_reg)) & VI_CLKSEL_REG_VICLKSEL_MASK) >> VI_CLKSEL_REG_VICLKSEL_SHIFT)
#define VI_CLKSEL_REG_SET_VICLKSEL(vi_clksel_reg, viclksel) { \
	FDL_ASSERT(!((viclksel) & ~((1 << VI_CLKSEL_REG_VICLKSEL_SIZE)-1))); \
	vi_clksel_reg = (((unsigned long)(vi_clksel_reg)) & ~VI_CLKSEL_REG_VICLKSEL_MASK) | (((unsigned long)(viclksel)) << VI_CLKSEL_REG_VICLKSEL_SHIFT);\
}
#define VI_CLKSEL_REG_TOTAL_SIZE	1
#define VI_CLKSEL_REG(viclksel) \
	((((unsigned long)(viclksel)) << VI_CLKSEL_REG_VICLKSEL_SHIFT))

typedef struct {
    unsigned long pad0:15;
    unsigned long viclksel:VI_CLKSEL_REG_VICLKSEL_SIZE;
} vi_clksel_reg_t;

typedef union {
    unsigned long val;
    vi_clksel_reg_t f;
} vi_clksel_reg_u;

/*
 *  vi_dtvstatus_reg struct
 */
#define VI_DTVSTATUS_REG_VISEL_SIZE	2
#define VI_DTVSTATUS_REG_VISEL_SHIFT	0
#define VI_DTVSTATUS_REG_VISEL_MASK	0x00000003
#define VI_DTVSTATUS_REG_GET_VISEL(vi_dtvstatus_reg) \
	((((unsigned long)(vi_dtvstatus_reg)) & VI_DTVSTATUS_REG_VISEL_MASK) >> VI_DTVSTATUS_REG_VISEL_SHIFT)
#define VI_DTVSTATUS_REG_SET_VISEL(vi_dtvstatus_reg, visel) { \
	FDL_ASSERT(!((visel) & ~((1 << VI_DTVSTATUS_REG_VISEL_SIZE)-1))); \
	vi_dtvstatus_reg = (((unsigned long)(vi_dtvstatus_reg)) & ~VI_DTVSTATUS_REG_VISEL_MASK) | (((unsigned long)(visel)) << VI_DTVSTATUS_REG_VISEL_SHIFT);\
}
#define VI_DTVSTATUS_REG_TOTAL_SIZE	2
#define VI_DTVSTATUS_REG(visel) \
	((((unsigned long)(visel)) << VI_DTVSTATUS_REG_VISEL_SHIFT))

typedef struct {
    unsigned long pad0:14;
    unsigned long visel:VI_DTVSTATUS_REG_VISEL_SIZE;
} vi_dtvstatus_reg_t;

typedef union {
    unsigned long val;
    vi_dtvstatus_reg_t f;
} vi_dtvstatus_reg_u;


#endif /* __VI_REG_H__ */
