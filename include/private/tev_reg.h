/*
 *  tev_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from tev_reg.fdl
 */

#ifndef __TEV_REG_H__
#define __TEV_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  tev_enb enum
 */
#define TEV_ENB_DISABLE	0x00000000
#define TEV_ENB_ENABLE	0x00000001

/*
 *  tev_csel enum
 */
#define TEV_CSEL_CC0	0x00000000
#define TEV_CSEL_CA0	0x00000001
#define TEV_CSEL_CC1	0x00000002
#define TEV_CSEL_CA1	0x00000003
#define TEV_CSEL_CC2	0x00000004
#define TEV_CSEL_CA2	0x00000005
#define TEV_CSEL_CC3	0x00000006
#define TEV_CSEL_CA3	0x00000007
#define TEV_CSEL_TXC	0x00000008
#define TEV_CSEL_TXA	0x00000009
#define TEV_CSEL_RSC	0x0000000a
#define TEV_CSEL_RSA	0x0000000b
#define TEV_CSEL_K10	0x0000000c
#define TEV_CSEL_K05	0x0000000d
#define TEV_CSEL_K25	0x0000000e
#define TEV_CSEL_K00	0x0000000f

/*
 *  tev_asel enum
 */
#define TEV_ASEL_CA0	0x00000000
#define TEV_ASEL_CA1	0x00000001
#define TEV_ASEL_CA2	0x00000002
#define TEV_ASEL_CA3	0x00000003
#define TEV_ASEL_TXA	0x00000004
#define TEV_ASEL_RSA	0x00000005
#define TEV_ASEL_K10	0x00000006
#define TEV_ASEL_K00	0x00000007

/*
 *  tev_cdest enum
 */
#define TEV_CDEST_CC0	0x00000000
#define TEV_CDEST_CC1	0x00000001
#define TEV_CDEST_CC2	0x00000002
#define TEV_CDEST_CC3	0x00000003

/*
 *  tev_adest enum
 */
#define TEV_ADEST_CA0	0x00000000
#define TEV_ADEST_CA1	0x00000001
#define TEV_ADEST_CA2	0x00000002
#define TEV_ADEST_CA3	0x00000003

/*
 *  tev_bias enum
 */
#define TEV_BIAS_ZERO	0x00000000
#define TEV_BIAS_PLUS	0x00000001
#define TEV_BIAS_MINUS	0x00000002
#define TEV_BIAS_UNUSED_3	0x00000003

/*
 *  tev_sub enum
 */
#define TEV_SUB_ADD	0x00000000
#define TEV_SUB_SUB	0x00000001

/*
 *  tev_clamp enum
 */
#define TEV_CLAMP_HIGH	0x00000000
#define TEV_CLAMP_LOW	0x00000001

/*
 *  tev_shift enum
 */
#define TEV_SHIFT_0	0x00000000
#define TEV_SHIFT_1	0x00000001
#define TEV_SHIFT_2	0x00000002
#define TEV_SHIFT_R	0x00000003

/*
 *  tev_swap enum
 */
#define TEV_SWAP_0	0x00000000
#define TEV_SWAP_R	0x00000001
#define TEV_SWAP_G	0x00000002
#define TEV_SWAP_B	0x00000003

/*
 *  tev_mode enum
 */
#define TEV_MODE_LINEAR	0x00000000
#define TEV_MODE_GE0	0x00000001
#define TEV_MODE_EQ0	0x00000002
#define TEV_MODE_LE0	0x00000003

/*
 *  tev_fsel enum
 */
#define TEV_FSEL_OFF	0x00000000
#define TEV_FSEL_UNUSED_1	0x00000001
#define TEV_FSEL_LIN	0x00000002
#define TEV_FSEL_UNUSED_3	0x00000003
#define TEV_FSEL_EXP	0x00000004
#define TEV_FSEL_EX2	0x00000005
#define TEV_FSEL_BXP	0x00000006
#define TEV_FSEL_BX2	0x00000007

/*
 *  tev_proj enum
 */
#define TEV_PROJ_PERSP	0x00000000
#define TEV_PROJ_ORTHO	0x00000001

/*
 *  tev_aop enum
 */
#define TEV_AOP_NEVER	0x00000000
#define TEV_AOP_LESS	0x00000001
#define TEV_AOP_EQUAL	0x00000002
#define TEV_AOP_LE	0x00000003
#define TEV_AOP_GREATER	0x00000004
#define TEV_AOP_NOTEQUAL	0x00000005
#define TEV_AOP_GE	0x00000006
#define TEV_AOP_ALWAYS	0x00000007

/*
 *  tev_logic enum
 */
#define TEV_LOGIC_AND	0x00000000
#define TEV_LOGIC_OR	0x00000001
#define TEV_LOGIC_XOR	0x00000002
#define TEV_LOGIC_XNOR	0x00000003

/*
 *  tev_z_type enum
 */
#define TEV_Z_TYPE_U8	0x00000000
#define TEV_Z_TYPE_U16	0x00000001
#define TEV_Z_TYPE_U24	0x00000002
#define TEV_Z_TYPE_UNUSED_3	0x00000003

/*
 *  tev_zop enum
 */
#define TEV_ZOP_OFF	0x00000000
#define TEV_ZOP_ADD	0x00000001
#define TEV_ZOP_REP	0x00000002
#define TEV_ZOP_UNUSED_3	0x00000003

/*
 *  tev_color_env struct
 */
#define TEV_COLOR_ENV_SELD_SIZE	4
#define TEV_COLOR_ENV_SELD_SHIFT	0
#define TEV_COLOR_ENV_SELD_MASK	0x0000000f
#define TEV_COLOR_ENV_GET_SELD(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SELD_MASK) >> TEV_COLOR_ENV_SELD_SHIFT)
#define TEV_COLOR_ENV_SET_SELD(tev_color_env, seld) { \
	FDL_ASSERT(!((seld) & ~((1 << TEV_COLOR_ENV_SELD_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SELD_MASK) | (((unsigned long)(seld)) << TEV_COLOR_ENV_SELD_SHIFT);\
}
#define TEV_COLOR_ENV_SELC_SIZE	4
#define TEV_COLOR_ENV_SELC_SHIFT	4
#define TEV_COLOR_ENV_SELC_MASK	0x000000f0
#define TEV_COLOR_ENV_GET_SELC(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SELC_MASK) >> TEV_COLOR_ENV_SELC_SHIFT)
#define TEV_COLOR_ENV_SET_SELC(tev_color_env, selc) { \
	FDL_ASSERT(!((selc) & ~((1 << TEV_COLOR_ENV_SELC_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SELC_MASK) | (((unsigned long)(selc)) << TEV_COLOR_ENV_SELC_SHIFT);\
}
#define TEV_COLOR_ENV_SELB_SIZE	4
#define TEV_COLOR_ENV_SELB_SHIFT	8
#define TEV_COLOR_ENV_SELB_MASK	0x00000f00
#define TEV_COLOR_ENV_GET_SELB(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SELB_MASK) >> TEV_COLOR_ENV_SELB_SHIFT)
#define TEV_COLOR_ENV_SET_SELB(tev_color_env, selb) { \
	FDL_ASSERT(!((selb) & ~((1 << TEV_COLOR_ENV_SELB_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SELB_MASK) | (((unsigned long)(selb)) << TEV_COLOR_ENV_SELB_SHIFT);\
}
#define TEV_COLOR_ENV_SELA_SIZE	4
#define TEV_COLOR_ENV_SELA_SHIFT	12
#define TEV_COLOR_ENV_SELA_MASK	0x0000f000
#define TEV_COLOR_ENV_GET_SELA(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SELA_MASK) >> TEV_COLOR_ENV_SELA_SHIFT)
#define TEV_COLOR_ENV_SET_SELA(tev_color_env, sela) { \
	FDL_ASSERT(!((sela) & ~((1 << TEV_COLOR_ENV_SELA_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SELA_MASK) | (((unsigned long)(sela)) << TEV_COLOR_ENV_SELA_SHIFT);\
}
#define TEV_COLOR_ENV_BIAS_SIZE	2
#define TEV_COLOR_ENV_BIAS_SHIFT	16
#define TEV_COLOR_ENV_BIAS_MASK	0x00030000
#define TEV_COLOR_ENV_GET_BIAS(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_BIAS_MASK) >> TEV_COLOR_ENV_BIAS_SHIFT)
#define TEV_COLOR_ENV_SET_BIAS(tev_color_env, bias) { \
	FDL_ASSERT(!((bias) & ~((1 << TEV_COLOR_ENV_BIAS_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_BIAS_MASK) | (((unsigned long)(bias)) << TEV_COLOR_ENV_BIAS_SHIFT);\
}
#define TEV_COLOR_ENV_SUB_SIZE	1
#define TEV_COLOR_ENV_SUB_SHIFT	18
#define TEV_COLOR_ENV_SUB_MASK	0x00040000
#define TEV_COLOR_ENV_GET_SUB(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SUB_MASK) >> TEV_COLOR_ENV_SUB_SHIFT)
#define TEV_COLOR_ENV_SET_SUB(tev_color_env, sub) { \
	FDL_ASSERT(!((sub) & ~((1 << TEV_COLOR_ENV_SUB_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SUB_MASK) | (((unsigned long)(sub)) << TEV_COLOR_ENV_SUB_SHIFT);\
}
#define TEV_COLOR_ENV_CLAMP_SIZE	1
#define TEV_COLOR_ENV_CLAMP_SHIFT	19
#define TEV_COLOR_ENV_CLAMP_MASK	0x00080000
#define TEV_COLOR_ENV_GET_CLAMP(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_CLAMP_MASK) >> TEV_COLOR_ENV_CLAMP_SHIFT)
#define TEV_COLOR_ENV_SET_CLAMP(tev_color_env, clamp) { \
	FDL_ASSERT(!((clamp) & ~((1 << TEV_COLOR_ENV_CLAMP_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_CLAMP_MASK) | (((unsigned long)(clamp)) << TEV_COLOR_ENV_CLAMP_SHIFT);\
}
#define TEV_COLOR_ENV_SHIFT_SIZE	2
#define TEV_COLOR_ENV_SHIFT_SHIFT	20
#define TEV_COLOR_ENV_SHIFT_MASK	0x00300000
#define TEV_COLOR_ENV_GET_SHIFT(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_SHIFT_MASK) >> TEV_COLOR_ENV_SHIFT_SHIFT)
#define TEV_COLOR_ENV_SET_SHIFT(tev_color_env, shift) { \
	FDL_ASSERT(!((shift) & ~((1 << TEV_COLOR_ENV_SHIFT_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_SHIFT_MASK) | (((unsigned long)(shift)) << TEV_COLOR_ENV_SHIFT_SHIFT);\
}
#define TEV_COLOR_ENV_DEST_SIZE	2
#define TEV_COLOR_ENV_DEST_SHIFT	22
#define TEV_COLOR_ENV_DEST_MASK	0x00c00000
#define TEV_COLOR_ENV_GET_DEST(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_DEST_MASK) >> TEV_COLOR_ENV_DEST_SHIFT)
#define TEV_COLOR_ENV_SET_DEST(tev_color_env, dest) { \
	FDL_ASSERT(!((dest) & ~((1 << TEV_COLOR_ENV_DEST_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_DEST_MASK) | (((unsigned long)(dest)) << TEV_COLOR_ENV_DEST_SHIFT);\
}
#define TEV_COLOR_ENV_RID_SIZE	8
#define TEV_COLOR_ENV_RID_SHIFT	24
#define TEV_COLOR_ENV_RID_MASK	0xff000000
#define TEV_COLOR_ENV_GET_RID(tev_color_env) \
	((((unsigned long)(tev_color_env)) & TEV_COLOR_ENV_RID_MASK) >> TEV_COLOR_ENV_RID_SHIFT)
#define TEV_COLOR_ENV_SET_RID(tev_color_env, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_COLOR_ENV_RID_SIZE)-1))); \
	tev_color_env = (((unsigned long)(tev_color_env)) & ~TEV_COLOR_ENV_RID_MASK) | (((unsigned long)(rid)) << TEV_COLOR_ENV_RID_SHIFT);\
}
#define TEV_COLOR_ENV_TOTAL_SIZE	32
#define TEV_COLOR_ENV(seld, selc, selb, sela, bias, sub, clamp, shift, dest, rid) \
	((((unsigned long)(seld)) << TEV_COLOR_ENV_SELD_SHIFT) | \
	 (((unsigned long)(selc)) << TEV_COLOR_ENV_SELC_SHIFT) | \
	 (((unsigned long)(selb)) << TEV_COLOR_ENV_SELB_SHIFT) | \
	 (((unsigned long)(sela)) << TEV_COLOR_ENV_SELA_SHIFT) | \
	 (((unsigned long)(bias)) << TEV_COLOR_ENV_BIAS_SHIFT) | \
	 (((unsigned long)(sub)) << TEV_COLOR_ENV_SUB_SHIFT) | \
	 (((unsigned long)(clamp)) << TEV_COLOR_ENV_CLAMP_SHIFT) | \
	 (((unsigned long)(shift)) << TEV_COLOR_ENV_SHIFT_SHIFT) | \
	 (((unsigned long)(dest)) << TEV_COLOR_ENV_DEST_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_COLOR_ENV_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_COLOR_ENV_RID_SIZE;
    unsigned long dest:TEV_COLOR_ENV_DEST_SIZE;
    unsigned long shift:TEV_COLOR_ENV_SHIFT_SIZE;
    unsigned long clamp:TEV_COLOR_ENV_CLAMP_SIZE;
    unsigned long sub:TEV_COLOR_ENV_SUB_SIZE;
    unsigned long bias:TEV_COLOR_ENV_BIAS_SIZE;
    unsigned long sela:TEV_COLOR_ENV_SELA_SIZE;
    unsigned long selb:TEV_COLOR_ENV_SELB_SIZE;
    unsigned long selc:TEV_COLOR_ENV_SELC_SIZE;
    unsigned long seld:TEV_COLOR_ENV_SELD_SIZE;
} tev_color_env_t;

typedef union {
    unsigned long val;
    tev_color_env_t f;
} tev_color_env_u;

/*
 *  tev_alpha_env struct
 */
#define TEV_ALPHA_ENV_MODE_SIZE	2
#define TEV_ALPHA_ENV_MODE_SHIFT	0
#define TEV_ALPHA_ENV_MODE_MASK	0x00000003
#define TEV_ALPHA_ENV_GET_MODE(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_MODE_MASK) >> TEV_ALPHA_ENV_MODE_SHIFT)
#define TEV_ALPHA_ENV_SET_MODE(tev_alpha_env, mode) { \
	FDL_ASSERT(!((mode) & ~((1 << TEV_ALPHA_ENV_MODE_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_MODE_MASK) | (((unsigned long)(mode)) << TEV_ALPHA_ENV_MODE_SHIFT);\
}
#define TEV_ALPHA_ENV_SWAP_SIZE	2
#define TEV_ALPHA_ENV_SWAP_SHIFT	2
#define TEV_ALPHA_ENV_SWAP_MASK	0x0000000c
#define TEV_ALPHA_ENV_GET_SWAP(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SWAP_MASK) >> TEV_ALPHA_ENV_SWAP_SHIFT)
#define TEV_ALPHA_ENV_SET_SWAP(tev_alpha_env, swap) { \
	FDL_ASSERT(!((swap) & ~((1 << TEV_ALPHA_ENV_SWAP_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SWAP_MASK) | (((unsigned long)(swap)) << TEV_ALPHA_ENV_SWAP_SHIFT);\
}
#define TEV_ALPHA_ENV_SELD_SIZE	3
#define TEV_ALPHA_ENV_SELD_SHIFT	4
#define TEV_ALPHA_ENV_SELD_MASK	0x00000070
#define TEV_ALPHA_ENV_GET_SELD(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SELD_MASK) >> TEV_ALPHA_ENV_SELD_SHIFT)
#define TEV_ALPHA_ENV_SET_SELD(tev_alpha_env, seld) { \
	FDL_ASSERT(!((seld) & ~((1 << TEV_ALPHA_ENV_SELD_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SELD_MASK) | (((unsigned long)(seld)) << TEV_ALPHA_ENV_SELD_SHIFT);\
}
#define TEV_ALPHA_ENV_SELC_SIZE	3
#define TEV_ALPHA_ENV_SELC_SHIFT	7
#define TEV_ALPHA_ENV_SELC_MASK	0x00000380
#define TEV_ALPHA_ENV_GET_SELC(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SELC_MASK) >> TEV_ALPHA_ENV_SELC_SHIFT)
#define TEV_ALPHA_ENV_SET_SELC(tev_alpha_env, selc) { \
	FDL_ASSERT(!((selc) & ~((1 << TEV_ALPHA_ENV_SELC_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SELC_MASK) | (((unsigned long)(selc)) << TEV_ALPHA_ENV_SELC_SHIFT);\
}
#define TEV_ALPHA_ENV_SELB_SIZE	3
#define TEV_ALPHA_ENV_SELB_SHIFT	10
#define TEV_ALPHA_ENV_SELB_MASK	0x00001c00
#define TEV_ALPHA_ENV_GET_SELB(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SELB_MASK) >> TEV_ALPHA_ENV_SELB_SHIFT)
#define TEV_ALPHA_ENV_SET_SELB(tev_alpha_env, selb) { \
	FDL_ASSERT(!((selb) & ~((1 << TEV_ALPHA_ENV_SELB_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SELB_MASK) | (((unsigned long)(selb)) << TEV_ALPHA_ENV_SELB_SHIFT);\
}
#define TEV_ALPHA_ENV_SELA_SIZE	3
#define TEV_ALPHA_ENV_SELA_SHIFT	13
#define TEV_ALPHA_ENV_SELA_MASK	0x0000e000
#define TEV_ALPHA_ENV_GET_SELA(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SELA_MASK) >> TEV_ALPHA_ENV_SELA_SHIFT)
#define TEV_ALPHA_ENV_SET_SELA(tev_alpha_env, sela) { \
	FDL_ASSERT(!((sela) & ~((1 << TEV_ALPHA_ENV_SELA_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SELA_MASK) | (((unsigned long)(sela)) << TEV_ALPHA_ENV_SELA_SHIFT);\
}
#define TEV_ALPHA_ENV_BIAS_SIZE	2
#define TEV_ALPHA_ENV_BIAS_SHIFT	16
#define TEV_ALPHA_ENV_BIAS_MASK	0x00030000
#define TEV_ALPHA_ENV_GET_BIAS(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_BIAS_MASK) >> TEV_ALPHA_ENV_BIAS_SHIFT)
#define TEV_ALPHA_ENV_SET_BIAS(tev_alpha_env, bias) { \
	FDL_ASSERT(!((bias) & ~((1 << TEV_ALPHA_ENV_BIAS_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_BIAS_MASK) | (((unsigned long)(bias)) << TEV_ALPHA_ENV_BIAS_SHIFT);\
}
#define TEV_ALPHA_ENV_SUB_SIZE	1
#define TEV_ALPHA_ENV_SUB_SHIFT	18
#define TEV_ALPHA_ENV_SUB_MASK	0x00040000
#define TEV_ALPHA_ENV_GET_SUB(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SUB_MASK) >> TEV_ALPHA_ENV_SUB_SHIFT)
#define TEV_ALPHA_ENV_SET_SUB(tev_alpha_env, sub) { \
	FDL_ASSERT(!((sub) & ~((1 << TEV_ALPHA_ENV_SUB_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SUB_MASK) | (((unsigned long)(sub)) << TEV_ALPHA_ENV_SUB_SHIFT);\
}
#define TEV_ALPHA_ENV_CLAMP_SIZE	1
#define TEV_ALPHA_ENV_CLAMP_SHIFT	19
#define TEV_ALPHA_ENV_CLAMP_MASK	0x00080000
#define TEV_ALPHA_ENV_GET_CLAMP(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_CLAMP_MASK) >> TEV_ALPHA_ENV_CLAMP_SHIFT)
#define TEV_ALPHA_ENV_SET_CLAMP(tev_alpha_env, clamp) { \
	FDL_ASSERT(!((clamp) & ~((1 << TEV_ALPHA_ENV_CLAMP_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_CLAMP_MASK) | (((unsigned long)(clamp)) << TEV_ALPHA_ENV_CLAMP_SHIFT);\
}
#define TEV_ALPHA_ENV_SHIFT_SIZE	2
#define TEV_ALPHA_ENV_SHIFT_SHIFT	20
#define TEV_ALPHA_ENV_SHIFT_MASK	0x00300000
#define TEV_ALPHA_ENV_GET_SHIFT(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_SHIFT_MASK) >> TEV_ALPHA_ENV_SHIFT_SHIFT)
#define TEV_ALPHA_ENV_SET_SHIFT(tev_alpha_env, shift) { \
	FDL_ASSERT(!((shift) & ~((1 << TEV_ALPHA_ENV_SHIFT_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_SHIFT_MASK) | (((unsigned long)(shift)) << TEV_ALPHA_ENV_SHIFT_SHIFT);\
}
#define TEV_ALPHA_ENV_DEST_SIZE	2
#define TEV_ALPHA_ENV_DEST_SHIFT	22
#define TEV_ALPHA_ENV_DEST_MASK	0x00c00000
#define TEV_ALPHA_ENV_GET_DEST(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_DEST_MASK) >> TEV_ALPHA_ENV_DEST_SHIFT)
#define TEV_ALPHA_ENV_SET_DEST(tev_alpha_env, dest) { \
	FDL_ASSERT(!((dest) & ~((1 << TEV_ALPHA_ENV_DEST_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_DEST_MASK) | (((unsigned long)(dest)) << TEV_ALPHA_ENV_DEST_SHIFT);\
}
#define TEV_ALPHA_ENV_RID_SIZE	8
#define TEV_ALPHA_ENV_RID_SHIFT	24
#define TEV_ALPHA_ENV_RID_MASK	0xff000000
#define TEV_ALPHA_ENV_GET_RID(tev_alpha_env) \
	((((unsigned long)(tev_alpha_env)) & TEV_ALPHA_ENV_RID_MASK) >> TEV_ALPHA_ENV_RID_SHIFT)
#define TEV_ALPHA_ENV_SET_RID(tev_alpha_env, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_ALPHA_ENV_RID_SIZE)-1))); \
	tev_alpha_env = (((unsigned long)(tev_alpha_env)) & ~TEV_ALPHA_ENV_RID_MASK) | (((unsigned long)(rid)) << TEV_ALPHA_ENV_RID_SHIFT);\
}
#define TEV_ALPHA_ENV_TOTAL_SIZE	32
#define TEV_ALPHA_ENV(mode, swap, seld, selc, selb, sela, bias, sub, clamp, shift, dest, rid) \
	((((unsigned long)(mode)) << TEV_ALPHA_ENV_MODE_SHIFT) | \
	 (((unsigned long)(swap)) << TEV_ALPHA_ENV_SWAP_SHIFT) | \
	 (((unsigned long)(seld)) << TEV_ALPHA_ENV_SELD_SHIFT) | \
	 (((unsigned long)(selc)) << TEV_ALPHA_ENV_SELC_SHIFT) | \
	 (((unsigned long)(selb)) << TEV_ALPHA_ENV_SELB_SHIFT) | \
	 (((unsigned long)(sela)) << TEV_ALPHA_ENV_SELA_SHIFT) | \
	 (((unsigned long)(bias)) << TEV_ALPHA_ENV_BIAS_SHIFT) | \
	 (((unsigned long)(sub)) << TEV_ALPHA_ENV_SUB_SHIFT) | \
	 (((unsigned long)(clamp)) << TEV_ALPHA_ENV_CLAMP_SHIFT) | \
	 (((unsigned long)(shift)) << TEV_ALPHA_ENV_SHIFT_SHIFT) | \
	 (((unsigned long)(dest)) << TEV_ALPHA_ENV_DEST_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_ALPHA_ENV_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_ALPHA_ENV_RID_SIZE;
    unsigned long dest:TEV_ALPHA_ENV_DEST_SIZE;
    unsigned long shift:TEV_ALPHA_ENV_SHIFT_SIZE;
    unsigned long clamp:TEV_ALPHA_ENV_CLAMP_SIZE;
    unsigned long sub:TEV_ALPHA_ENV_SUB_SIZE;
    unsigned long bias:TEV_ALPHA_ENV_BIAS_SIZE;
    unsigned long sela:TEV_ALPHA_ENV_SELA_SIZE;
    unsigned long selb:TEV_ALPHA_ENV_SELB_SIZE;
    unsigned long selc:TEV_ALPHA_ENV_SELC_SIZE;
    unsigned long seld:TEV_ALPHA_ENV_SELD_SIZE;
    unsigned long swap:TEV_ALPHA_ENV_SWAP_SIZE;
    unsigned long mode:TEV_ALPHA_ENV_MODE_SIZE;
} tev_alpha_env_t;

typedef union {
    unsigned long val;
    tev_alpha_env_t f;
} tev_alpha_env_u;

/*
 *  tev_registerl struct
 */
#define TEV_REGISTERL_R_SIZE	11
#define TEV_REGISTERL_R_SHIFT	0
#define TEV_REGISTERL_R_MASK	0x000007ff
#define TEV_REGISTERL_GET_R(tev_registerl) \
	((((unsigned long)(tev_registerl)) & TEV_REGISTERL_R_MASK) >> TEV_REGISTERL_R_SHIFT)
#define TEV_REGISTERL_SET_R(tev_registerl, r) { \
	FDL_ASSERT(!((r) & ~((1 << TEV_REGISTERL_R_SIZE)-1))); \
	tev_registerl = (((unsigned long)(tev_registerl)) & ~TEV_REGISTERL_R_MASK) | (((unsigned long)(r)) << TEV_REGISTERL_R_SHIFT);\
}
#define TEV_REGISTERL_PAD0_SIZE	1
#define TEV_REGISTERL_PAD0_SHIFT	11
#define TEV_REGISTERL_PAD0_MASK	0x00000800
#define TEV_REGISTERL_GET_PAD0(tev_registerl) \
	((((unsigned long)(tev_registerl)) & TEV_REGISTERL_PAD0_MASK) >> TEV_REGISTERL_PAD0_SHIFT)
#define TEV_REGISTERL_SET_PAD0(tev_registerl, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_REGISTERL_PAD0_SIZE)-1))); \
	tev_registerl = (((unsigned long)(tev_registerl)) & ~TEV_REGISTERL_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_REGISTERL_PAD0_SHIFT);\
}
#define TEV_REGISTERL_A_SIZE	11
#define TEV_REGISTERL_A_SHIFT	12
#define TEV_REGISTERL_A_MASK	0x007ff000
#define TEV_REGISTERL_GET_A(tev_registerl) \
	((((unsigned long)(tev_registerl)) & TEV_REGISTERL_A_MASK) >> TEV_REGISTERL_A_SHIFT)
#define TEV_REGISTERL_SET_A(tev_registerl, a) { \
	FDL_ASSERT(!((a) & ~((1 << TEV_REGISTERL_A_SIZE)-1))); \
	tev_registerl = (((unsigned long)(tev_registerl)) & ~TEV_REGISTERL_A_MASK) | (((unsigned long)(a)) << TEV_REGISTERL_A_SHIFT);\
}
#define TEV_REGISTERL_PAD1_SIZE	1
#define TEV_REGISTERL_PAD1_SHIFT	23
#define TEV_REGISTERL_PAD1_MASK	0x00800000
#define TEV_REGISTERL_GET_PAD1(tev_registerl) \
	((((unsigned long)(tev_registerl)) & TEV_REGISTERL_PAD1_MASK) >> TEV_REGISTERL_PAD1_SHIFT)
#define TEV_REGISTERL_SET_PAD1(tev_registerl, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << TEV_REGISTERL_PAD1_SIZE)-1))); \
	tev_registerl = (((unsigned long)(tev_registerl)) & ~TEV_REGISTERL_PAD1_MASK) | (((unsigned long)(pad1)) << TEV_REGISTERL_PAD1_SHIFT);\
}
#define TEV_REGISTERL_RID_SIZE	8
#define TEV_REGISTERL_RID_SHIFT	24
#define TEV_REGISTERL_RID_MASK	0xff000000
#define TEV_REGISTERL_GET_RID(tev_registerl) \
	((((unsigned long)(tev_registerl)) & TEV_REGISTERL_RID_MASK) >> TEV_REGISTERL_RID_SHIFT)
#define TEV_REGISTERL_SET_RID(tev_registerl, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_REGISTERL_RID_SIZE)-1))); \
	tev_registerl = (((unsigned long)(tev_registerl)) & ~TEV_REGISTERL_RID_MASK) | (((unsigned long)(rid)) << TEV_REGISTERL_RID_SHIFT);\
}
#define TEV_REGISTERL_TOTAL_SIZE	32
#define TEV_REGISTERL(r, a, rid) \
	((((unsigned long)(r)) << TEV_REGISTERL_R_SHIFT) | \
	 (((unsigned long)(a)) << TEV_REGISTERL_A_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_REGISTERL_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_REGISTERL_RID_SIZE;
    unsigned long pad1:TEV_REGISTERL_PAD1_SIZE;
    unsigned long a:TEV_REGISTERL_A_SIZE;
    unsigned long pad0:TEV_REGISTERL_PAD0_SIZE;
    unsigned long r:TEV_REGISTERL_R_SIZE;
} tev_registerl_t;

typedef union {
    unsigned long val;
    tev_registerl_t f;
} tev_registerl_u;

/*
 *  tev_registerh struct
 */
#define TEV_REGISTERH_B_SIZE	11
#define TEV_REGISTERH_B_SHIFT	0
#define TEV_REGISTERH_B_MASK	0x000007ff
#define TEV_REGISTERH_GET_B(tev_registerh) \
	((((unsigned long)(tev_registerh)) & TEV_REGISTERH_B_MASK) >> TEV_REGISTERH_B_SHIFT)
#define TEV_REGISTERH_SET_B(tev_registerh, b) { \
	FDL_ASSERT(!((b) & ~((1 << TEV_REGISTERH_B_SIZE)-1))); \
	tev_registerh = (((unsigned long)(tev_registerh)) & ~TEV_REGISTERH_B_MASK) | (((unsigned long)(b)) << TEV_REGISTERH_B_SHIFT);\
}
#define TEV_REGISTERH_PAD0_SIZE	1
#define TEV_REGISTERH_PAD0_SHIFT	11
#define TEV_REGISTERH_PAD0_MASK	0x00000800
#define TEV_REGISTERH_GET_PAD0(tev_registerh) \
	((((unsigned long)(tev_registerh)) & TEV_REGISTERH_PAD0_MASK) >> TEV_REGISTERH_PAD0_SHIFT)
#define TEV_REGISTERH_SET_PAD0(tev_registerh, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_REGISTERH_PAD0_SIZE)-1))); \
	tev_registerh = (((unsigned long)(tev_registerh)) & ~TEV_REGISTERH_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_REGISTERH_PAD0_SHIFT);\
}
#define TEV_REGISTERH_G_SIZE	11
#define TEV_REGISTERH_G_SHIFT	12
#define TEV_REGISTERH_G_MASK	0x007ff000
#define TEV_REGISTERH_GET_G(tev_registerh) \
	((((unsigned long)(tev_registerh)) & TEV_REGISTERH_G_MASK) >> TEV_REGISTERH_G_SHIFT)
#define TEV_REGISTERH_SET_G(tev_registerh, g) { \
	FDL_ASSERT(!((g) & ~((1 << TEV_REGISTERH_G_SIZE)-1))); \
	tev_registerh = (((unsigned long)(tev_registerh)) & ~TEV_REGISTERH_G_MASK) | (((unsigned long)(g)) << TEV_REGISTERH_G_SHIFT);\
}
#define TEV_REGISTERH_PAD1_SIZE	1
#define TEV_REGISTERH_PAD1_SHIFT	23
#define TEV_REGISTERH_PAD1_MASK	0x00800000
#define TEV_REGISTERH_GET_PAD1(tev_registerh) \
	((((unsigned long)(tev_registerh)) & TEV_REGISTERH_PAD1_MASK) >> TEV_REGISTERH_PAD1_SHIFT)
#define TEV_REGISTERH_SET_PAD1(tev_registerh, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << TEV_REGISTERH_PAD1_SIZE)-1))); \
	tev_registerh = (((unsigned long)(tev_registerh)) & ~TEV_REGISTERH_PAD1_MASK) | (((unsigned long)(pad1)) << TEV_REGISTERH_PAD1_SHIFT);\
}
#define TEV_REGISTERH_RID_SIZE	8
#define TEV_REGISTERH_RID_SHIFT	24
#define TEV_REGISTERH_RID_MASK	0xff000000
#define TEV_REGISTERH_GET_RID(tev_registerh) \
	((((unsigned long)(tev_registerh)) & TEV_REGISTERH_RID_MASK) >> TEV_REGISTERH_RID_SHIFT)
#define TEV_REGISTERH_SET_RID(tev_registerh, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_REGISTERH_RID_SIZE)-1))); \
	tev_registerh = (((unsigned long)(tev_registerh)) & ~TEV_REGISTERH_RID_MASK) | (((unsigned long)(rid)) << TEV_REGISTERH_RID_SHIFT);\
}
#define TEV_REGISTERH_TOTAL_SIZE	32
#define TEV_REGISTERH(b, g, rid) \
	((((unsigned long)(b)) << TEV_REGISTERH_B_SHIFT) | \
	 (((unsigned long)(g)) << TEV_REGISTERH_G_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_REGISTERH_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_REGISTERH_RID_SIZE;
    unsigned long pad1:TEV_REGISTERH_PAD1_SIZE;
    unsigned long g:TEV_REGISTERH_G_SIZE;
    unsigned long pad0:TEV_REGISTERH_PAD0_SIZE;
    unsigned long b:TEV_REGISTERH_B_SIZE;
} tev_registerh_t;

typedef union {
    unsigned long val;
    tev_registerh_t f;
} tev_registerh_u;

/*
 *  tev_kregisterl struct
 */
#define TEV_KREGISTERL_R_SIZE	8
#define TEV_KREGISTERL_R_SHIFT	0
#define TEV_KREGISTERL_R_MASK	0x000000ff
#define TEV_KREGISTERL_GET_R(tev_kregisterl) \
	((((unsigned long)(tev_kregisterl)) & TEV_KREGISTERL_R_MASK) >> TEV_KREGISTERL_R_SHIFT)
#define TEV_KREGISTERL_SET_R(tev_kregisterl, r) { \
	FDL_ASSERT(!((r) & ~((1 << TEV_KREGISTERL_R_SIZE)-1))); \
	tev_kregisterl = (((unsigned long)(tev_kregisterl)) & ~TEV_KREGISTERL_R_MASK) | (((unsigned long)(r)) << TEV_KREGISTERL_R_SHIFT);\
}
#define TEV_KREGISTERL_PAD0_SIZE	4
#define TEV_KREGISTERL_PAD0_SHIFT	8
#define TEV_KREGISTERL_PAD0_MASK	0x00000f00
#define TEV_KREGISTERL_GET_PAD0(tev_kregisterl) \
	((((unsigned long)(tev_kregisterl)) & TEV_KREGISTERL_PAD0_MASK) >> TEV_KREGISTERL_PAD0_SHIFT)
#define TEV_KREGISTERL_SET_PAD0(tev_kregisterl, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_KREGISTERL_PAD0_SIZE)-1))); \
	tev_kregisterl = (((unsigned long)(tev_kregisterl)) & ~TEV_KREGISTERL_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_KREGISTERL_PAD0_SHIFT);\
}
#define TEV_KREGISTERL_A_SIZE	8
#define TEV_KREGISTERL_A_SHIFT	12
#define TEV_KREGISTERL_A_MASK	0x000ff000
#define TEV_KREGISTERL_GET_A(tev_kregisterl) \
	((((unsigned long)(tev_kregisterl)) & TEV_KREGISTERL_A_MASK) >> TEV_KREGISTERL_A_SHIFT)
#define TEV_KREGISTERL_SET_A(tev_kregisterl, a) { \
	FDL_ASSERT(!((a) & ~((1 << TEV_KREGISTERL_A_SIZE)-1))); \
	tev_kregisterl = (((unsigned long)(tev_kregisterl)) & ~TEV_KREGISTERL_A_MASK) | (((unsigned long)(a)) << TEV_KREGISTERL_A_SHIFT);\
}
#define TEV_KREGISTERL_PAD1_SIZE	4
#define TEV_KREGISTERL_PAD1_SHIFT	20
#define TEV_KREGISTERL_PAD1_MASK	0x00f00000
#define TEV_KREGISTERL_GET_PAD1(tev_kregisterl) \
	((((unsigned long)(tev_kregisterl)) & TEV_KREGISTERL_PAD1_MASK) >> TEV_KREGISTERL_PAD1_SHIFT)
#define TEV_KREGISTERL_SET_PAD1(tev_kregisterl, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << TEV_KREGISTERL_PAD1_SIZE)-1))); \
	tev_kregisterl = (((unsigned long)(tev_kregisterl)) & ~TEV_KREGISTERL_PAD1_MASK) | (((unsigned long)(pad1)) << TEV_KREGISTERL_PAD1_SHIFT);\
}
#define TEV_KREGISTERL_RID_SIZE	8
#define TEV_KREGISTERL_RID_SHIFT	24
#define TEV_KREGISTERL_RID_MASK	0xff000000
#define TEV_KREGISTERL_GET_RID(tev_kregisterl) \
	((((unsigned long)(tev_kregisterl)) & TEV_KREGISTERL_RID_MASK) >> TEV_KREGISTERL_RID_SHIFT)
#define TEV_KREGISTERL_SET_RID(tev_kregisterl, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_KREGISTERL_RID_SIZE)-1))); \
	tev_kregisterl = (((unsigned long)(tev_kregisterl)) & ~TEV_KREGISTERL_RID_MASK) | (((unsigned long)(rid)) << TEV_KREGISTERL_RID_SHIFT);\
}
#define TEV_KREGISTERL_TOTAL_SIZE	32
#define TEV_KREGISTERL(r, a, rid) \
	((((unsigned long)(r)) << TEV_KREGISTERL_R_SHIFT) | \
	 (((unsigned long)(a)) << TEV_KREGISTERL_A_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_KREGISTERL_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_KREGISTERL_RID_SIZE;
    unsigned long pad1:TEV_KREGISTERL_PAD1_SIZE;
    unsigned long a:TEV_KREGISTERL_A_SIZE;
    unsigned long pad0:TEV_KREGISTERL_PAD0_SIZE;
    unsigned long r:TEV_KREGISTERL_R_SIZE;
} tev_kregisterl_t;

typedef union {
    unsigned long val;
    tev_kregisterl_t f;
} tev_kregisterl_u;

/*
 *  tev_kregisterh struct
 */
#define TEV_KREGISTERH_B_SIZE	8
#define TEV_KREGISTERH_B_SHIFT	0
#define TEV_KREGISTERH_B_MASK	0x000000ff
#define TEV_KREGISTERH_GET_B(tev_kregisterh) \
	((((unsigned long)(tev_kregisterh)) & TEV_KREGISTERH_B_MASK) >> TEV_KREGISTERH_B_SHIFT)
#define TEV_KREGISTERH_SET_B(tev_kregisterh, b) { \
	FDL_ASSERT(!((b) & ~((1 << TEV_KREGISTERH_B_SIZE)-1))); \
	tev_kregisterh = (((unsigned long)(tev_kregisterh)) & ~TEV_KREGISTERH_B_MASK) | (((unsigned long)(b)) << TEV_KREGISTERH_B_SHIFT);\
}
#define TEV_KREGISTERH_PAD0_SIZE	4
#define TEV_KREGISTERH_PAD0_SHIFT	8
#define TEV_KREGISTERH_PAD0_MASK	0x00000f00
#define TEV_KREGISTERH_GET_PAD0(tev_kregisterh) \
	((((unsigned long)(tev_kregisterh)) & TEV_KREGISTERH_PAD0_MASK) >> TEV_KREGISTERH_PAD0_SHIFT)
#define TEV_KREGISTERH_SET_PAD0(tev_kregisterh, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_KREGISTERH_PAD0_SIZE)-1))); \
	tev_kregisterh = (((unsigned long)(tev_kregisterh)) & ~TEV_KREGISTERH_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_KREGISTERH_PAD0_SHIFT);\
}
#define TEV_KREGISTERH_G_SIZE	8
#define TEV_KREGISTERH_G_SHIFT	12
#define TEV_KREGISTERH_G_MASK	0x000ff000
#define TEV_KREGISTERH_GET_G(tev_kregisterh) \
	((((unsigned long)(tev_kregisterh)) & TEV_KREGISTERH_G_MASK) >> TEV_KREGISTERH_G_SHIFT)
#define TEV_KREGISTERH_SET_G(tev_kregisterh, g) { \
	FDL_ASSERT(!((g) & ~((1 << TEV_KREGISTERH_G_SIZE)-1))); \
	tev_kregisterh = (((unsigned long)(tev_kregisterh)) & ~TEV_KREGISTERH_G_MASK) | (((unsigned long)(g)) << TEV_KREGISTERH_G_SHIFT);\
}
#define TEV_KREGISTERH_PAD1_SIZE	4
#define TEV_KREGISTERH_PAD1_SHIFT	20
#define TEV_KREGISTERH_PAD1_MASK	0x00f00000
#define TEV_KREGISTERH_GET_PAD1(tev_kregisterh) \
	((((unsigned long)(tev_kregisterh)) & TEV_KREGISTERH_PAD1_MASK) >> TEV_KREGISTERH_PAD1_SHIFT)
#define TEV_KREGISTERH_SET_PAD1(tev_kregisterh, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << TEV_KREGISTERH_PAD1_SIZE)-1))); \
	tev_kregisterh = (((unsigned long)(tev_kregisterh)) & ~TEV_KREGISTERH_PAD1_MASK) | (((unsigned long)(pad1)) << TEV_KREGISTERH_PAD1_SHIFT);\
}
#define TEV_KREGISTERH_RID_SIZE	8
#define TEV_KREGISTERH_RID_SHIFT	24
#define TEV_KREGISTERH_RID_MASK	0xff000000
#define TEV_KREGISTERH_GET_RID(tev_kregisterh) \
	((((unsigned long)(tev_kregisterh)) & TEV_KREGISTERH_RID_MASK) >> TEV_KREGISTERH_RID_SHIFT)
#define TEV_KREGISTERH_SET_RID(tev_kregisterh, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_KREGISTERH_RID_SIZE)-1))); \
	tev_kregisterh = (((unsigned long)(tev_kregisterh)) & ~TEV_KREGISTERH_RID_MASK) | (((unsigned long)(rid)) << TEV_KREGISTERH_RID_SHIFT);\
}
#define TEV_KREGISTERH_TOTAL_SIZE	32
#define TEV_KREGISTERH(b, g, rid) \
	((((unsigned long)(b)) << TEV_KREGISTERH_B_SHIFT) | \
	 (((unsigned long)(g)) << TEV_KREGISTERH_G_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_KREGISTERH_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_KREGISTERH_RID_SIZE;
    unsigned long pad1:TEV_KREGISTERH_PAD1_SIZE;
    unsigned long g:TEV_KREGISTERH_G_SIZE;
    unsigned long pad0:TEV_KREGISTERH_PAD0_SIZE;
    unsigned long b:TEV_KREGISTERH_B_SIZE;
} tev_kregisterh_t;

typedef union {
    unsigned long val;
    tev_kregisterh_t f;
} tev_kregisterh_u;

/*
 *  tev_fog_param_0 struct
 */
#define TEV_FOG_PARAM_0_A_MANT_SIZE	11
#define TEV_FOG_PARAM_0_A_MANT_SHIFT	0
#define TEV_FOG_PARAM_0_A_MANT_MASK	0x000007ff
#define TEV_FOG_PARAM_0_GET_A_MANT(tev_fog_param_0) \
	((((unsigned long)(tev_fog_param_0)) & TEV_FOG_PARAM_0_A_MANT_MASK) >> TEV_FOG_PARAM_0_A_MANT_SHIFT)
#define TEV_FOG_PARAM_0_SET_A_MANT(tev_fog_param_0, a_mant) { \
	FDL_ASSERT(!((a_mant) & ~((1 << TEV_FOG_PARAM_0_A_MANT_SIZE)-1))); \
	tev_fog_param_0 = (((unsigned long)(tev_fog_param_0)) & ~TEV_FOG_PARAM_0_A_MANT_MASK) | (((unsigned long)(a_mant)) << TEV_FOG_PARAM_0_A_MANT_SHIFT);\
}
#define TEV_FOG_PARAM_0_A_EXPN_SIZE	8
#define TEV_FOG_PARAM_0_A_EXPN_SHIFT	11
#define TEV_FOG_PARAM_0_A_EXPN_MASK	0x0007f800
#define TEV_FOG_PARAM_0_GET_A_EXPN(tev_fog_param_0) \
	((((unsigned long)(tev_fog_param_0)) & TEV_FOG_PARAM_0_A_EXPN_MASK) >> TEV_FOG_PARAM_0_A_EXPN_SHIFT)
#define TEV_FOG_PARAM_0_SET_A_EXPN(tev_fog_param_0, a_expn) { \
	FDL_ASSERT(!((a_expn) & ~((1 << TEV_FOG_PARAM_0_A_EXPN_SIZE)-1))); \
	tev_fog_param_0 = (((unsigned long)(tev_fog_param_0)) & ~TEV_FOG_PARAM_0_A_EXPN_MASK) | (((unsigned long)(a_expn)) << TEV_FOG_PARAM_0_A_EXPN_SHIFT);\
}
#define TEV_FOG_PARAM_0_A_SIGN_SIZE	1
#define TEV_FOG_PARAM_0_A_SIGN_SHIFT	19
#define TEV_FOG_PARAM_0_A_SIGN_MASK	0x00080000
#define TEV_FOG_PARAM_0_GET_A_SIGN(tev_fog_param_0) \
	((((unsigned long)(tev_fog_param_0)) & TEV_FOG_PARAM_0_A_SIGN_MASK) >> TEV_FOG_PARAM_0_A_SIGN_SHIFT)
#define TEV_FOG_PARAM_0_SET_A_SIGN(tev_fog_param_0, a_sign) { \
	FDL_ASSERT(!((a_sign) & ~((1 << TEV_FOG_PARAM_0_A_SIGN_SIZE)-1))); \
	tev_fog_param_0 = (((unsigned long)(tev_fog_param_0)) & ~TEV_FOG_PARAM_0_A_SIGN_MASK) | (((unsigned long)(a_sign)) << TEV_FOG_PARAM_0_A_SIGN_SHIFT);\
}
#define TEV_FOG_PARAM_0_PAD0_SIZE	4
#define TEV_FOG_PARAM_0_PAD0_SHIFT	20
#define TEV_FOG_PARAM_0_PAD0_MASK	0x00f00000
#define TEV_FOG_PARAM_0_GET_PAD0(tev_fog_param_0) \
	((((unsigned long)(tev_fog_param_0)) & TEV_FOG_PARAM_0_PAD0_MASK) >> TEV_FOG_PARAM_0_PAD0_SHIFT)
#define TEV_FOG_PARAM_0_SET_PAD0(tev_fog_param_0, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_FOG_PARAM_0_PAD0_SIZE)-1))); \
	tev_fog_param_0 = (((unsigned long)(tev_fog_param_0)) & ~TEV_FOG_PARAM_0_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_FOG_PARAM_0_PAD0_SHIFT);\
}
#define TEV_FOG_PARAM_0_RID_SIZE	8
#define TEV_FOG_PARAM_0_RID_SHIFT	24
#define TEV_FOG_PARAM_0_RID_MASK	0xff000000
#define TEV_FOG_PARAM_0_GET_RID(tev_fog_param_0) \
	((((unsigned long)(tev_fog_param_0)) & TEV_FOG_PARAM_0_RID_MASK) >> TEV_FOG_PARAM_0_RID_SHIFT)
#define TEV_FOG_PARAM_0_SET_RID(tev_fog_param_0, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_FOG_PARAM_0_RID_SIZE)-1))); \
	tev_fog_param_0 = (((unsigned long)(tev_fog_param_0)) & ~TEV_FOG_PARAM_0_RID_MASK) | (((unsigned long)(rid)) << TEV_FOG_PARAM_0_RID_SHIFT);\
}
#define TEV_FOG_PARAM_0_TOTAL_SIZE	32
#define TEV_FOG_PARAM_0(a_mant, a_expn, a_sign, rid) \
	((((unsigned long)(a_mant)) << TEV_FOG_PARAM_0_A_MANT_SHIFT) | \
	 (((unsigned long)(a_expn)) << TEV_FOG_PARAM_0_A_EXPN_SHIFT) | \
	 (((unsigned long)(a_sign)) << TEV_FOG_PARAM_0_A_SIGN_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_FOG_PARAM_0_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_FOG_PARAM_0_RID_SIZE;
    unsigned long pad0:TEV_FOG_PARAM_0_PAD0_SIZE;
    unsigned long a_sign:TEV_FOG_PARAM_0_A_SIGN_SIZE;
    unsigned long a_expn:TEV_FOG_PARAM_0_A_EXPN_SIZE;
    unsigned long a_mant:TEV_FOG_PARAM_0_A_MANT_SIZE;
} tev_fog_param_0_t;

typedef union {
    unsigned long val;
    tev_fog_param_0_t f;
} tev_fog_param_0_u;

/*
 *  tev_fog_param_1 struct
 */
#define TEV_FOG_PARAM_1_B_MAG_SIZE	24
#define TEV_FOG_PARAM_1_B_MAG_SHIFT	0
#define TEV_FOG_PARAM_1_B_MAG_MASK	0x00ffffff
#define TEV_FOG_PARAM_1_GET_B_MAG(tev_fog_param_1) \
	((((unsigned long)(tev_fog_param_1)) & TEV_FOG_PARAM_1_B_MAG_MASK) >> TEV_FOG_PARAM_1_B_MAG_SHIFT)
#define TEV_FOG_PARAM_1_SET_B_MAG(tev_fog_param_1, b_mag) { \
	FDL_ASSERT(!((b_mag) & ~((1 << TEV_FOG_PARAM_1_B_MAG_SIZE)-1))); \
	tev_fog_param_1 = (((unsigned long)(tev_fog_param_1)) & ~TEV_FOG_PARAM_1_B_MAG_MASK) | (((unsigned long)(b_mag)) << TEV_FOG_PARAM_1_B_MAG_SHIFT);\
}
#define TEV_FOG_PARAM_1_RID_SIZE	8
#define TEV_FOG_PARAM_1_RID_SHIFT	24
#define TEV_FOG_PARAM_1_RID_MASK	0xff000000
#define TEV_FOG_PARAM_1_GET_RID(tev_fog_param_1) \
	((((unsigned long)(tev_fog_param_1)) & TEV_FOG_PARAM_1_RID_MASK) >> TEV_FOG_PARAM_1_RID_SHIFT)
#define TEV_FOG_PARAM_1_SET_RID(tev_fog_param_1, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_FOG_PARAM_1_RID_SIZE)-1))); \
	tev_fog_param_1 = (((unsigned long)(tev_fog_param_1)) & ~TEV_FOG_PARAM_1_RID_MASK) | (((unsigned long)(rid)) << TEV_FOG_PARAM_1_RID_SHIFT);\
}
#define TEV_FOG_PARAM_1_TOTAL_SIZE	32
#define TEV_FOG_PARAM_1(b_mag, rid) \
	((((unsigned long)(b_mag)) << TEV_FOG_PARAM_1_B_MAG_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_FOG_PARAM_1_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_FOG_PARAM_1_RID_SIZE;
    unsigned long b_mag:TEV_FOG_PARAM_1_B_MAG_SIZE;
} tev_fog_param_1_t;

typedef union {
    unsigned long val;
    tev_fog_param_1_t f;
} tev_fog_param_1_u;

/*
 *  tev_fog_param_2 struct
 */
#define TEV_FOG_PARAM_2_B_SHF_SIZE	5
#define TEV_FOG_PARAM_2_B_SHF_SHIFT	0
#define TEV_FOG_PARAM_2_B_SHF_MASK	0x0000001f
#define TEV_FOG_PARAM_2_GET_B_SHF(tev_fog_param_2) \
	((((unsigned long)(tev_fog_param_2)) & TEV_FOG_PARAM_2_B_SHF_MASK) >> TEV_FOG_PARAM_2_B_SHF_SHIFT)
#define TEV_FOG_PARAM_2_SET_B_SHF(tev_fog_param_2, b_shf) { \
	FDL_ASSERT(!((b_shf) & ~((1 << TEV_FOG_PARAM_2_B_SHF_SIZE)-1))); \
	tev_fog_param_2 = (((unsigned long)(tev_fog_param_2)) & ~TEV_FOG_PARAM_2_B_SHF_MASK) | (((unsigned long)(b_shf)) << TEV_FOG_PARAM_2_B_SHF_SHIFT);\
}
#define TEV_FOG_PARAM_2_PAD0_SIZE	19
#define TEV_FOG_PARAM_2_PAD0_SHIFT	5
#define TEV_FOG_PARAM_2_PAD0_MASK	0x00ffffe0
#define TEV_FOG_PARAM_2_GET_PAD0(tev_fog_param_2) \
	((((unsigned long)(tev_fog_param_2)) & TEV_FOG_PARAM_2_PAD0_MASK) >> TEV_FOG_PARAM_2_PAD0_SHIFT)
#define TEV_FOG_PARAM_2_SET_PAD0(tev_fog_param_2, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_FOG_PARAM_2_PAD0_SIZE)-1))); \
	tev_fog_param_2 = (((unsigned long)(tev_fog_param_2)) & ~TEV_FOG_PARAM_2_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_FOG_PARAM_2_PAD0_SHIFT);\
}
#define TEV_FOG_PARAM_2_RID_SIZE	8
#define TEV_FOG_PARAM_2_RID_SHIFT	24
#define TEV_FOG_PARAM_2_RID_MASK	0xff000000
#define TEV_FOG_PARAM_2_GET_RID(tev_fog_param_2) \
	((((unsigned long)(tev_fog_param_2)) & TEV_FOG_PARAM_2_RID_MASK) >> TEV_FOG_PARAM_2_RID_SHIFT)
#define TEV_FOG_PARAM_2_SET_RID(tev_fog_param_2, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_FOG_PARAM_2_RID_SIZE)-1))); \
	tev_fog_param_2 = (((unsigned long)(tev_fog_param_2)) & ~TEV_FOG_PARAM_2_RID_MASK) | (((unsigned long)(rid)) << TEV_FOG_PARAM_2_RID_SHIFT);\
}
#define TEV_FOG_PARAM_2_TOTAL_SIZE	32
#define TEV_FOG_PARAM_2(b_shf, rid) \
	((((unsigned long)(b_shf)) << TEV_FOG_PARAM_2_B_SHF_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_FOG_PARAM_2_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_FOG_PARAM_2_RID_SIZE;
    unsigned long pad0:TEV_FOG_PARAM_2_PAD0_SIZE;
    unsigned long b_shf:TEV_FOG_PARAM_2_B_SHF_SIZE;
} tev_fog_param_2_t;

typedef union {
    unsigned long val;
    tev_fog_param_2_t f;
} tev_fog_param_2_u;

/*
 *  tev_fog_param_3 struct
 */
#define TEV_FOG_PARAM_3_C_MANT_SIZE	11
#define TEV_FOG_PARAM_3_C_MANT_SHIFT	0
#define TEV_FOG_PARAM_3_C_MANT_MASK	0x000007ff
#define TEV_FOG_PARAM_3_GET_C_MANT(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_C_MANT_MASK) >> TEV_FOG_PARAM_3_C_MANT_SHIFT)
#define TEV_FOG_PARAM_3_SET_C_MANT(tev_fog_param_3, c_mant) { \
	FDL_ASSERT(!((c_mant) & ~((1 << TEV_FOG_PARAM_3_C_MANT_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_C_MANT_MASK) | (((unsigned long)(c_mant)) << TEV_FOG_PARAM_3_C_MANT_SHIFT);\
}
#define TEV_FOG_PARAM_3_C_EXPN_SIZE	8
#define TEV_FOG_PARAM_3_C_EXPN_SHIFT	11
#define TEV_FOG_PARAM_3_C_EXPN_MASK	0x0007f800
#define TEV_FOG_PARAM_3_GET_C_EXPN(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_C_EXPN_MASK) >> TEV_FOG_PARAM_3_C_EXPN_SHIFT)
#define TEV_FOG_PARAM_3_SET_C_EXPN(tev_fog_param_3, c_expn) { \
	FDL_ASSERT(!((c_expn) & ~((1 << TEV_FOG_PARAM_3_C_EXPN_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_C_EXPN_MASK) | (((unsigned long)(c_expn)) << TEV_FOG_PARAM_3_C_EXPN_SHIFT);\
}
#define TEV_FOG_PARAM_3_C_SIGN_SIZE	1
#define TEV_FOG_PARAM_3_C_SIGN_SHIFT	19
#define TEV_FOG_PARAM_3_C_SIGN_MASK	0x00080000
#define TEV_FOG_PARAM_3_GET_C_SIGN(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_C_SIGN_MASK) >> TEV_FOG_PARAM_3_C_SIGN_SHIFT)
#define TEV_FOG_PARAM_3_SET_C_SIGN(tev_fog_param_3, c_sign) { \
	FDL_ASSERT(!((c_sign) & ~((1 << TEV_FOG_PARAM_3_C_SIGN_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_C_SIGN_MASK) | (((unsigned long)(c_sign)) << TEV_FOG_PARAM_3_C_SIGN_SHIFT);\
}
#define TEV_FOG_PARAM_3_PROJ_SIZE	1
#define TEV_FOG_PARAM_3_PROJ_SHIFT	20
#define TEV_FOG_PARAM_3_PROJ_MASK	0x00100000
#define TEV_FOG_PARAM_3_GET_PROJ(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_PROJ_MASK) >> TEV_FOG_PARAM_3_PROJ_SHIFT)
#define TEV_FOG_PARAM_3_SET_PROJ(tev_fog_param_3, proj) { \
	FDL_ASSERT(!((proj) & ~((1 << TEV_FOG_PARAM_3_PROJ_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_PROJ_MASK) | (((unsigned long)(proj)) << TEV_FOG_PARAM_3_PROJ_SHIFT);\
}
#define TEV_FOG_PARAM_3_FSEL_SIZE	3
#define TEV_FOG_PARAM_3_FSEL_SHIFT	21
#define TEV_FOG_PARAM_3_FSEL_MASK	0x00e00000
#define TEV_FOG_PARAM_3_GET_FSEL(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_FSEL_MASK) >> TEV_FOG_PARAM_3_FSEL_SHIFT)
#define TEV_FOG_PARAM_3_SET_FSEL(tev_fog_param_3, fsel) { \
	FDL_ASSERT(!((fsel) & ~((1 << TEV_FOG_PARAM_3_FSEL_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_FSEL_MASK) | (((unsigned long)(fsel)) << TEV_FOG_PARAM_3_FSEL_SHIFT);\
}
#define TEV_FOG_PARAM_3_RID_SIZE	8
#define TEV_FOG_PARAM_3_RID_SHIFT	24
#define TEV_FOG_PARAM_3_RID_MASK	0xff000000
#define TEV_FOG_PARAM_3_GET_RID(tev_fog_param_3) \
	((((unsigned long)(tev_fog_param_3)) & TEV_FOG_PARAM_3_RID_MASK) >> TEV_FOG_PARAM_3_RID_SHIFT)
#define TEV_FOG_PARAM_3_SET_RID(tev_fog_param_3, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_FOG_PARAM_3_RID_SIZE)-1))); \
	tev_fog_param_3 = (((unsigned long)(tev_fog_param_3)) & ~TEV_FOG_PARAM_3_RID_MASK) | (((unsigned long)(rid)) << TEV_FOG_PARAM_3_RID_SHIFT);\
}
#define TEV_FOG_PARAM_3_TOTAL_SIZE	32
#define TEV_FOG_PARAM_3(c_mant, c_expn, c_sign, proj, fsel, rid) \
	((((unsigned long)(c_mant)) << TEV_FOG_PARAM_3_C_MANT_SHIFT) | \
	 (((unsigned long)(c_expn)) << TEV_FOG_PARAM_3_C_EXPN_SHIFT) | \
	 (((unsigned long)(c_sign)) << TEV_FOG_PARAM_3_C_SIGN_SHIFT) | \
	 (((unsigned long)(proj)) << TEV_FOG_PARAM_3_PROJ_SHIFT) | \
	 (((unsigned long)(fsel)) << TEV_FOG_PARAM_3_FSEL_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_FOG_PARAM_3_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_FOG_PARAM_3_RID_SIZE;
    unsigned long fsel:TEV_FOG_PARAM_3_FSEL_SIZE;
    unsigned long proj:TEV_FOG_PARAM_3_PROJ_SIZE;
    unsigned long c_sign:TEV_FOG_PARAM_3_C_SIGN_SIZE;
    unsigned long c_expn:TEV_FOG_PARAM_3_C_EXPN_SIZE;
    unsigned long c_mant:TEV_FOG_PARAM_3_C_MANT_SIZE;
} tev_fog_param_3_t;

typedef union {
    unsigned long val;
    tev_fog_param_3_t f;
} tev_fog_param_3_u;

/*
 *  tev_range_adj_c struct
 */
#define TEV_RANGE_ADJ_C_CENTER_SIZE	10
#define TEV_RANGE_ADJ_C_CENTER_SHIFT	0
#define TEV_RANGE_ADJ_C_CENTER_MASK	0x000003ff
#define TEV_RANGE_ADJ_C_GET_CENTER(tev_range_adj_c) \
	((((unsigned long)(tev_range_adj_c)) & TEV_RANGE_ADJ_C_CENTER_MASK) >> TEV_RANGE_ADJ_C_CENTER_SHIFT)
#define TEV_RANGE_ADJ_C_SET_CENTER(tev_range_adj_c, center) { \
	FDL_ASSERT(!((center) & ~((1 << TEV_RANGE_ADJ_C_CENTER_SIZE)-1))); \
	tev_range_adj_c = (((unsigned long)(tev_range_adj_c)) & ~TEV_RANGE_ADJ_C_CENTER_MASK) | (((unsigned long)(center)) << TEV_RANGE_ADJ_C_CENTER_SHIFT);\
}
#define TEV_RANGE_ADJ_C_ENB_SIZE	1
#define TEV_RANGE_ADJ_C_ENB_SHIFT	10
#define TEV_RANGE_ADJ_C_ENB_MASK	0x00000400
#define TEV_RANGE_ADJ_C_GET_ENB(tev_range_adj_c) \
	((((unsigned long)(tev_range_adj_c)) & TEV_RANGE_ADJ_C_ENB_MASK) >> TEV_RANGE_ADJ_C_ENB_SHIFT)
#define TEV_RANGE_ADJ_C_SET_ENB(tev_range_adj_c, enb) { \
	FDL_ASSERT(!((enb) & ~((1 << TEV_RANGE_ADJ_C_ENB_SIZE)-1))); \
	tev_range_adj_c = (((unsigned long)(tev_range_adj_c)) & ~TEV_RANGE_ADJ_C_ENB_MASK) | (((unsigned long)(enb)) << TEV_RANGE_ADJ_C_ENB_SHIFT);\
}
#define TEV_RANGE_ADJ_C_PAD0_SIZE	13
#define TEV_RANGE_ADJ_C_PAD0_SHIFT	11
#define TEV_RANGE_ADJ_C_PAD0_MASK	0x00fff800
#define TEV_RANGE_ADJ_C_GET_PAD0(tev_range_adj_c) \
	((((unsigned long)(tev_range_adj_c)) & TEV_RANGE_ADJ_C_PAD0_MASK) >> TEV_RANGE_ADJ_C_PAD0_SHIFT)
#define TEV_RANGE_ADJ_C_SET_PAD0(tev_range_adj_c, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_RANGE_ADJ_C_PAD0_SIZE)-1))); \
	tev_range_adj_c = (((unsigned long)(tev_range_adj_c)) & ~TEV_RANGE_ADJ_C_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_RANGE_ADJ_C_PAD0_SHIFT);\
}
#define TEV_RANGE_ADJ_C_RID_SIZE	8
#define TEV_RANGE_ADJ_C_RID_SHIFT	24
#define TEV_RANGE_ADJ_C_RID_MASK	0xff000000
#define TEV_RANGE_ADJ_C_GET_RID(tev_range_adj_c) \
	((((unsigned long)(tev_range_adj_c)) & TEV_RANGE_ADJ_C_RID_MASK) >> TEV_RANGE_ADJ_C_RID_SHIFT)
#define TEV_RANGE_ADJ_C_SET_RID(tev_range_adj_c, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_RANGE_ADJ_C_RID_SIZE)-1))); \
	tev_range_adj_c = (((unsigned long)(tev_range_adj_c)) & ~TEV_RANGE_ADJ_C_RID_MASK) | (((unsigned long)(rid)) << TEV_RANGE_ADJ_C_RID_SHIFT);\
}
#define TEV_RANGE_ADJ_C_TOTAL_SIZE	32
#define TEV_RANGE_ADJ_C(center, enb, rid) \
	((((unsigned long)(center)) << TEV_RANGE_ADJ_C_CENTER_SHIFT) | \
	 (((unsigned long)(enb)) << TEV_RANGE_ADJ_C_ENB_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_RANGE_ADJ_C_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_RANGE_ADJ_C_RID_SIZE;
    unsigned long pad0:TEV_RANGE_ADJ_C_PAD0_SIZE;
    unsigned long enb:TEV_RANGE_ADJ_C_ENB_SIZE;
    unsigned long center:TEV_RANGE_ADJ_C_CENTER_SIZE;
} tev_range_adj_c_t;

typedef union {
    unsigned long val;
    tev_range_adj_c_t f;
} tev_range_adj_c_u;

/*
 *  tev_range_adj struct
 */
#define TEV_RANGE_ADJ_R0_SIZE	12
#define TEV_RANGE_ADJ_R0_SHIFT	0
#define TEV_RANGE_ADJ_R0_MASK	0x00000fff
#define TEV_RANGE_ADJ_GET_R0(tev_range_adj) \
	((((unsigned long)(tev_range_adj)) & TEV_RANGE_ADJ_R0_MASK) >> TEV_RANGE_ADJ_R0_SHIFT)
#define TEV_RANGE_ADJ_SET_R0(tev_range_adj, r0) { \
	FDL_ASSERT(!((r0) & ~((1 << TEV_RANGE_ADJ_R0_SIZE)-1))); \
	tev_range_adj = (((unsigned long)(tev_range_adj)) & ~TEV_RANGE_ADJ_R0_MASK) | (((unsigned long)(r0)) << TEV_RANGE_ADJ_R0_SHIFT);\
}
#define TEV_RANGE_ADJ_R1_SIZE	12
#define TEV_RANGE_ADJ_R1_SHIFT	12
#define TEV_RANGE_ADJ_R1_MASK	0x00fff000
#define TEV_RANGE_ADJ_GET_R1(tev_range_adj) \
	((((unsigned long)(tev_range_adj)) & TEV_RANGE_ADJ_R1_MASK) >> TEV_RANGE_ADJ_R1_SHIFT)
#define TEV_RANGE_ADJ_SET_R1(tev_range_adj, r1) { \
	FDL_ASSERT(!((r1) & ~((1 << TEV_RANGE_ADJ_R1_SIZE)-1))); \
	tev_range_adj = (((unsigned long)(tev_range_adj)) & ~TEV_RANGE_ADJ_R1_MASK) | (((unsigned long)(r1)) << TEV_RANGE_ADJ_R1_SHIFT);\
}
#define TEV_RANGE_ADJ_RID_SIZE	8
#define TEV_RANGE_ADJ_RID_SHIFT	24
#define TEV_RANGE_ADJ_RID_MASK	0xff000000
#define TEV_RANGE_ADJ_GET_RID(tev_range_adj) \
	((((unsigned long)(tev_range_adj)) & TEV_RANGE_ADJ_RID_MASK) >> TEV_RANGE_ADJ_RID_SHIFT)
#define TEV_RANGE_ADJ_SET_RID(tev_range_adj, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_RANGE_ADJ_RID_SIZE)-1))); \
	tev_range_adj = (((unsigned long)(tev_range_adj)) & ~TEV_RANGE_ADJ_RID_MASK) | (((unsigned long)(rid)) << TEV_RANGE_ADJ_RID_SHIFT);\
}
#define TEV_RANGE_ADJ_TOTAL_SIZE	32
#define TEV_RANGE_ADJ(r0, r1, rid) \
	((((unsigned long)(r0)) << TEV_RANGE_ADJ_R0_SHIFT) | \
	 (((unsigned long)(r1)) << TEV_RANGE_ADJ_R1_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_RANGE_ADJ_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_RANGE_ADJ_RID_SIZE;
    unsigned long r1:TEV_RANGE_ADJ_R1_SIZE;
    unsigned long r0:TEV_RANGE_ADJ_R0_SIZE;
} tev_range_adj_t;

typedef union {
    unsigned long val;
    tev_range_adj_t f;
} tev_range_adj_u;

/*
 *  tev_fog_color struct
 */
#define TEV_FOG_COLOR_B_SIZE	8
#define TEV_FOG_COLOR_B_SHIFT	0
#define TEV_FOG_COLOR_B_MASK	0x000000ff
#define TEV_FOG_COLOR_GET_B(tev_fog_color) \
	((((unsigned long)(tev_fog_color)) & TEV_FOG_COLOR_B_MASK) >> TEV_FOG_COLOR_B_SHIFT)
#define TEV_FOG_COLOR_SET_B(tev_fog_color, b) { \
	FDL_ASSERT(!((b) & ~((1 << TEV_FOG_COLOR_B_SIZE)-1))); \
	tev_fog_color = (((unsigned long)(tev_fog_color)) & ~TEV_FOG_COLOR_B_MASK) | (((unsigned long)(b)) << TEV_FOG_COLOR_B_SHIFT);\
}
#define TEV_FOG_COLOR_G_SIZE	8
#define TEV_FOG_COLOR_G_SHIFT	8
#define TEV_FOG_COLOR_G_MASK	0x0000ff00
#define TEV_FOG_COLOR_GET_G(tev_fog_color) \
	((((unsigned long)(tev_fog_color)) & TEV_FOG_COLOR_G_MASK) >> TEV_FOG_COLOR_G_SHIFT)
#define TEV_FOG_COLOR_SET_G(tev_fog_color, g) { \
	FDL_ASSERT(!((g) & ~((1 << TEV_FOG_COLOR_G_SIZE)-1))); \
	tev_fog_color = (((unsigned long)(tev_fog_color)) & ~TEV_FOG_COLOR_G_MASK) | (((unsigned long)(g)) << TEV_FOG_COLOR_G_SHIFT);\
}
#define TEV_FOG_COLOR_R_SIZE	8
#define TEV_FOG_COLOR_R_SHIFT	16
#define TEV_FOG_COLOR_R_MASK	0x00ff0000
#define TEV_FOG_COLOR_GET_R(tev_fog_color) \
	((((unsigned long)(tev_fog_color)) & TEV_FOG_COLOR_R_MASK) >> TEV_FOG_COLOR_R_SHIFT)
#define TEV_FOG_COLOR_SET_R(tev_fog_color, r) { \
	FDL_ASSERT(!((r) & ~((1 << TEV_FOG_COLOR_R_SIZE)-1))); \
	tev_fog_color = (((unsigned long)(tev_fog_color)) & ~TEV_FOG_COLOR_R_MASK) | (((unsigned long)(r)) << TEV_FOG_COLOR_R_SHIFT);\
}
#define TEV_FOG_COLOR_RID_SIZE	8
#define TEV_FOG_COLOR_RID_SHIFT	24
#define TEV_FOG_COLOR_RID_MASK	0xff000000
#define TEV_FOG_COLOR_GET_RID(tev_fog_color) \
	((((unsigned long)(tev_fog_color)) & TEV_FOG_COLOR_RID_MASK) >> TEV_FOG_COLOR_RID_SHIFT)
#define TEV_FOG_COLOR_SET_RID(tev_fog_color, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_FOG_COLOR_RID_SIZE)-1))); \
	tev_fog_color = (((unsigned long)(tev_fog_color)) & ~TEV_FOG_COLOR_RID_MASK) | (((unsigned long)(rid)) << TEV_FOG_COLOR_RID_SHIFT);\
}
#define TEV_FOG_COLOR_TOTAL_SIZE	32
#define TEV_FOG_COLOR(b, g, r, rid) \
	((((unsigned long)(b)) << TEV_FOG_COLOR_B_SHIFT) | \
	 (((unsigned long)(g)) << TEV_FOG_COLOR_G_SHIFT) | \
	 (((unsigned long)(r)) << TEV_FOG_COLOR_R_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_FOG_COLOR_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_FOG_COLOR_RID_SIZE;
    unsigned long r:TEV_FOG_COLOR_R_SIZE;
    unsigned long g:TEV_FOG_COLOR_G_SIZE;
    unsigned long b:TEV_FOG_COLOR_B_SIZE;
} tev_fog_color_t;

typedef union {
    unsigned long val;
    tev_fog_color_t f;
} tev_fog_color_u;

/*
 *  tev_alphafunc struct
 */
#define TEV_ALPHAFUNC_A0_SIZE	8
#define TEV_ALPHAFUNC_A0_SHIFT	0
#define TEV_ALPHAFUNC_A0_MASK	0x000000ff
#define TEV_ALPHAFUNC_GET_A0(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_A0_MASK) >> TEV_ALPHAFUNC_A0_SHIFT)
#define TEV_ALPHAFUNC_SET_A0(tev_alphafunc, a0) { \
	FDL_ASSERT(!((a0) & ~((1 << TEV_ALPHAFUNC_A0_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_A0_MASK) | (((unsigned long)(a0)) << TEV_ALPHAFUNC_A0_SHIFT);\
}
#define TEV_ALPHAFUNC_A1_SIZE	8
#define TEV_ALPHAFUNC_A1_SHIFT	8
#define TEV_ALPHAFUNC_A1_MASK	0x0000ff00
#define TEV_ALPHAFUNC_GET_A1(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_A1_MASK) >> TEV_ALPHAFUNC_A1_SHIFT)
#define TEV_ALPHAFUNC_SET_A1(tev_alphafunc, a1) { \
	FDL_ASSERT(!((a1) & ~((1 << TEV_ALPHAFUNC_A1_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_A1_MASK) | (((unsigned long)(a1)) << TEV_ALPHAFUNC_A1_SHIFT);\
}
#define TEV_ALPHAFUNC_OP0_SIZE	3
#define TEV_ALPHAFUNC_OP0_SHIFT	16
#define TEV_ALPHAFUNC_OP0_MASK	0x00070000
#define TEV_ALPHAFUNC_GET_OP0(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_OP0_MASK) >> TEV_ALPHAFUNC_OP0_SHIFT)
#define TEV_ALPHAFUNC_SET_OP0(tev_alphafunc, op0) { \
	FDL_ASSERT(!((op0) & ~((1 << TEV_ALPHAFUNC_OP0_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_OP0_MASK) | (((unsigned long)(op0)) << TEV_ALPHAFUNC_OP0_SHIFT);\
}
#define TEV_ALPHAFUNC_OP1_SIZE	3
#define TEV_ALPHAFUNC_OP1_SHIFT	19
#define TEV_ALPHAFUNC_OP1_MASK	0x00380000
#define TEV_ALPHAFUNC_GET_OP1(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_OP1_MASK) >> TEV_ALPHAFUNC_OP1_SHIFT)
#define TEV_ALPHAFUNC_SET_OP1(tev_alphafunc, op1) { \
	FDL_ASSERT(!((op1) & ~((1 << TEV_ALPHAFUNC_OP1_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_OP1_MASK) | (((unsigned long)(op1)) << TEV_ALPHAFUNC_OP1_SHIFT);\
}
#define TEV_ALPHAFUNC_LOGIC_SIZE	2
#define TEV_ALPHAFUNC_LOGIC_SHIFT	22
#define TEV_ALPHAFUNC_LOGIC_MASK	0x00c00000
#define TEV_ALPHAFUNC_GET_LOGIC(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_LOGIC_MASK) >> TEV_ALPHAFUNC_LOGIC_SHIFT)
#define TEV_ALPHAFUNC_SET_LOGIC(tev_alphafunc, logic) { \
	FDL_ASSERT(!((logic) & ~((1 << TEV_ALPHAFUNC_LOGIC_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_LOGIC_MASK) | (((unsigned long)(logic)) << TEV_ALPHAFUNC_LOGIC_SHIFT);\
}
#define TEV_ALPHAFUNC_RID_SIZE	8
#define TEV_ALPHAFUNC_RID_SHIFT	24
#define TEV_ALPHAFUNC_RID_MASK	0xff000000
#define TEV_ALPHAFUNC_GET_RID(tev_alphafunc) \
	((((unsigned long)(tev_alphafunc)) & TEV_ALPHAFUNC_RID_MASK) >> TEV_ALPHAFUNC_RID_SHIFT)
#define TEV_ALPHAFUNC_SET_RID(tev_alphafunc, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_ALPHAFUNC_RID_SIZE)-1))); \
	tev_alphafunc = (((unsigned long)(tev_alphafunc)) & ~TEV_ALPHAFUNC_RID_MASK) | (((unsigned long)(rid)) << TEV_ALPHAFUNC_RID_SHIFT);\
}
#define TEV_ALPHAFUNC_TOTAL_SIZE	32
#define TEV_ALPHAFUNC(a0, a1, op0, op1, logic, rid) \
	((((unsigned long)(a0)) << TEV_ALPHAFUNC_A0_SHIFT) | \
	 (((unsigned long)(a1)) << TEV_ALPHAFUNC_A1_SHIFT) | \
	 (((unsigned long)(op0)) << TEV_ALPHAFUNC_OP0_SHIFT) | \
	 (((unsigned long)(op1)) << TEV_ALPHAFUNC_OP1_SHIFT) | \
	 (((unsigned long)(logic)) << TEV_ALPHAFUNC_LOGIC_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_ALPHAFUNC_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_ALPHAFUNC_RID_SIZE;
    unsigned long logic:TEV_ALPHAFUNC_LOGIC_SIZE;
    unsigned long op1:TEV_ALPHAFUNC_OP1_SIZE;
    unsigned long op0:TEV_ALPHAFUNC_OP0_SIZE;
    unsigned long a1:TEV_ALPHAFUNC_A1_SIZE;
    unsigned long a0:TEV_ALPHAFUNC_A0_SIZE;
} tev_alphafunc_t;

typedef union {
    unsigned long val;
    tev_alphafunc_t f;
} tev_alphafunc_u;

/*
 *  tev_z_env_0 struct
 */
#define TEV_Z_ENV_0_ZOFF_SIZE	24
#define TEV_Z_ENV_0_ZOFF_SHIFT	0
#define TEV_Z_ENV_0_ZOFF_MASK	0x00ffffff
#define TEV_Z_ENV_0_GET_ZOFF(tev_z_env_0) \
	((((unsigned long)(tev_z_env_0)) & TEV_Z_ENV_0_ZOFF_MASK) >> TEV_Z_ENV_0_ZOFF_SHIFT)
#define TEV_Z_ENV_0_SET_ZOFF(tev_z_env_0, zoff) { \
	FDL_ASSERT(!((zoff) & ~((1 << TEV_Z_ENV_0_ZOFF_SIZE)-1))); \
	tev_z_env_0 = (((unsigned long)(tev_z_env_0)) & ~TEV_Z_ENV_0_ZOFF_MASK) | (((unsigned long)(zoff)) << TEV_Z_ENV_0_ZOFF_SHIFT);\
}
#define TEV_Z_ENV_0_RID_SIZE	8
#define TEV_Z_ENV_0_RID_SHIFT	24
#define TEV_Z_ENV_0_RID_MASK	0xff000000
#define TEV_Z_ENV_0_GET_RID(tev_z_env_0) \
	((((unsigned long)(tev_z_env_0)) & TEV_Z_ENV_0_RID_MASK) >> TEV_Z_ENV_0_RID_SHIFT)
#define TEV_Z_ENV_0_SET_RID(tev_z_env_0, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_Z_ENV_0_RID_SIZE)-1))); \
	tev_z_env_0 = (((unsigned long)(tev_z_env_0)) & ~TEV_Z_ENV_0_RID_MASK) | (((unsigned long)(rid)) << TEV_Z_ENV_0_RID_SHIFT);\
}
#define TEV_Z_ENV_0_TOTAL_SIZE	32
#define TEV_Z_ENV_0(zoff, rid) \
	((((unsigned long)(zoff)) << TEV_Z_ENV_0_ZOFF_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_Z_ENV_0_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_Z_ENV_0_RID_SIZE;
    unsigned long zoff:TEV_Z_ENV_0_ZOFF_SIZE;
} tev_z_env_0_t;

typedef union {
    unsigned long val;
    tev_z_env_0_t f;
} tev_z_env_0_u;

/*
 *  tev_z_env_1 struct
 */
#define TEV_Z_ENV_1_TYPE_SIZE	2
#define TEV_Z_ENV_1_TYPE_SHIFT	0
#define TEV_Z_ENV_1_TYPE_MASK	0x00000003
#define TEV_Z_ENV_1_GET_TYPE(tev_z_env_1) \
	((((unsigned long)(tev_z_env_1)) & TEV_Z_ENV_1_TYPE_MASK) >> TEV_Z_ENV_1_TYPE_SHIFT)
#define TEV_Z_ENV_1_SET_TYPE(tev_z_env_1, type) { \
	FDL_ASSERT(!((type) & ~((1 << TEV_Z_ENV_1_TYPE_SIZE)-1))); \
	tev_z_env_1 = (((unsigned long)(tev_z_env_1)) & ~TEV_Z_ENV_1_TYPE_MASK) | (((unsigned long)(type)) << TEV_Z_ENV_1_TYPE_SHIFT);\
}
#define TEV_Z_ENV_1_OP_SIZE	2
#define TEV_Z_ENV_1_OP_SHIFT	2
#define TEV_Z_ENV_1_OP_MASK	0x0000000c
#define TEV_Z_ENV_1_GET_OP(tev_z_env_1) \
	((((unsigned long)(tev_z_env_1)) & TEV_Z_ENV_1_OP_MASK) >> TEV_Z_ENV_1_OP_SHIFT)
#define TEV_Z_ENV_1_SET_OP(tev_z_env_1, op) { \
	FDL_ASSERT(!((op) & ~((1 << TEV_Z_ENV_1_OP_SIZE)-1))); \
	tev_z_env_1 = (((unsigned long)(tev_z_env_1)) & ~TEV_Z_ENV_1_OP_MASK) | (((unsigned long)(op)) << TEV_Z_ENV_1_OP_SHIFT);\
}
#define TEV_Z_ENV_1_PAD0_SIZE	20
#define TEV_Z_ENV_1_PAD0_SHIFT	4
#define TEV_Z_ENV_1_PAD0_MASK	0x00fffff0
#define TEV_Z_ENV_1_GET_PAD0(tev_z_env_1) \
	((((unsigned long)(tev_z_env_1)) & TEV_Z_ENV_1_PAD0_MASK) >> TEV_Z_ENV_1_PAD0_SHIFT)
#define TEV_Z_ENV_1_SET_PAD0(tev_z_env_1, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << TEV_Z_ENV_1_PAD0_SIZE)-1))); \
	tev_z_env_1 = (((unsigned long)(tev_z_env_1)) & ~TEV_Z_ENV_1_PAD0_MASK) | (((unsigned long)(pad0)) << TEV_Z_ENV_1_PAD0_SHIFT);\
}
#define TEV_Z_ENV_1_RID_SIZE	8
#define TEV_Z_ENV_1_RID_SHIFT	24
#define TEV_Z_ENV_1_RID_MASK	0xff000000
#define TEV_Z_ENV_1_GET_RID(tev_z_env_1) \
	((((unsigned long)(tev_z_env_1)) & TEV_Z_ENV_1_RID_MASK) >> TEV_Z_ENV_1_RID_SHIFT)
#define TEV_Z_ENV_1_SET_RID(tev_z_env_1, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_Z_ENV_1_RID_SIZE)-1))); \
	tev_z_env_1 = (((unsigned long)(tev_z_env_1)) & ~TEV_Z_ENV_1_RID_MASK) | (((unsigned long)(rid)) << TEV_Z_ENV_1_RID_SHIFT);\
}
#define TEV_Z_ENV_1_TOTAL_SIZE	32
#define TEV_Z_ENV_1(type, op, rid) \
	((((unsigned long)(type)) << TEV_Z_ENV_1_TYPE_SHIFT) | \
	 (((unsigned long)(op)) << TEV_Z_ENV_1_OP_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_Z_ENV_1_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_Z_ENV_1_RID_SIZE;
    unsigned long pad0:TEV_Z_ENV_1_PAD0_SIZE;
    unsigned long op:TEV_Z_ENV_1_OP_SIZE;
    unsigned long type:TEV_Z_ENV_1_TYPE_SIZE;
} tev_z_env_1_t;

typedef union {
    unsigned long val;
    tev_z_env_1_t f;
} tev_z_env_1_u;

/*
 *  tev_ksel struct
 */
#define TEV_KSEL_XRB_SIZE	2
#define TEV_KSEL_XRB_SHIFT	0
#define TEV_KSEL_XRB_MASK	0x00000003
#define TEV_KSEL_GET_XRB(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_XRB_MASK) >> TEV_KSEL_XRB_SHIFT)
#define TEV_KSEL_SET_XRB(tev_ksel, xrb) { \
	FDL_ASSERT(!((xrb) & ~((1 << TEV_KSEL_XRB_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_XRB_MASK) | (((unsigned long)(xrb)) << TEV_KSEL_XRB_SHIFT);\
}
#define TEV_KSEL_XGA_SIZE	2
#define TEV_KSEL_XGA_SHIFT	2
#define TEV_KSEL_XGA_MASK	0x0000000c
#define TEV_KSEL_GET_XGA(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_XGA_MASK) >> TEV_KSEL_XGA_SHIFT)
#define TEV_KSEL_SET_XGA(tev_ksel, xga) { \
	FDL_ASSERT(!((xga) & ~((1 << TEV_KSEL_XGA_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_XGA_MASK) | (((unsigned long)(xga)) << TEV_KSEL_XGA_SHIFT);\
}
#define TEV_KSEL_KCSEL0_SIZE	5
#define TEV_KSEL_KCSEL0_SHIFT	4
#define TEV_KSEL_KCSEL0_MASK	0x000001f0
#define TEV_KSEL_GET_KCSEL0(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_KCSEL0_MASK) >> TEV_KSEL_KCSEL0_SHIFT)
#define TEV_KSEL_SET_KCSEL0(tev_ksel, kcsel0) { \
	FDL_ASSERT(!((kcsel0) & ~((1 << TEV_KSEL_KCSEL0_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_KCSEL0_MASK) | (((unsigned long)(kcsel0)) << TEV_KSEL_KCSEL0_SHIFT);\
}
#define TEV_KSEL_KASEL0_SIZE	5
#define TEV_KSEL_KASEL0_SHIFT	9
#define TEV_KSEL_KASEL0_MASK	0x00003e00
#define TEV_KSEL_GET_KASEL0(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_KASEL0_MASK) >> TEV_KSEL_KASEL0_SHIFT)
#define TEV_KSEL_SET_KASEL0(tev_ksel, kasel0) { \
	FDL_ASSERT(!((kasel0) & ~((1 << TEV_KSEL_KASEL0_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_KASEL0_MASK) | (((unsigned long)(kasel0)) << TEV_KSEL_KASEL0_SHIFT);\
}
#define TEV_KSEL_KCSEL1_SIZE	5
#define TEV_KSEL_KCSEL1_SHIFT	14
#define TEV_KSEL_KCSEL1_MASK	0x0007c000
#define TEV_KSEL_GET_KCSEL1(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_KCSEL1_MASK) >> TEV_KSEL_KCSEL1_SHIFT)
#define TEV_KSEL_SET_KCSEL1(tev_ksel, kcsel1) { \
	FDL_ASSERT(!((kcsel1) & ~((1 << TEV_KSEL_KCSEL1_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_KCSEL1_MASK) | (((unsigned long)(kcsel1)) << TEV_KSEL_KCSEL1_SHIFT);\
}
#define TEV_KSEL_KASEL1_SIZE	5
#define TEV_KSEL_KASEL1_SHIFT	19
#define TEV_KSEL_KASEL1_MASK	0x00f80000
#define TEV_KSEL_GET_KASEL1(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_KASEL1_MASK) >> TEV_KSEL_KASEL1_SHIFT)
#define TEV_KSEL_SET_KASEL1(tev_ksel, kasel1) { \
	FDL_ASSERT(!((kasel1) & ~((1 << TEV_KSEL_KASEL1_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_KASEL1_MASK) | (((unsigned long)(kasel1)) << TEV_KSEL_KASEL1_SHIFT);\
}
#define TEV_KSEL_RID_SIZE	8
#define TEV_KSEL_RID_SHIFT	24
#define TEV_KSEL_RID_MASK	0xff000000
#define TEV_KSEL_GET_RID(tev_ksel) \
	((((unsigned long)(tev_ksel)) & TEV_KSEL_RID_MASK) >> TEV_KSEL_RID_SHIFT)
#define TEV_KSEL_SET_RID(tev_ksel, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << TEV_KSEL_RID_SIZE)-1))); \
	tev_ksel = (((unsigned long)(tev_ksel)) & ~TEV_KSEL_RID_MASK) | (((unsigned long)(rid)) << TEV_KSEL_RID_SHIFT);\
}
#define TEV_KSEL_TOTAL_SIZE	32
#define TEV_KSEL(xrb, xga, kcsel0, kasel0, kcsel1, kasel1, rid) \
	((((unsigned long)(xrb)) << TEV_KSEL_XRB_SHIFT) | \
	 (((unsigned long)(xga)) << TEV_KSEL_XGA_SHIFT) | \
	 (((unsigned long)(kcsel0)) << TEV_KSEL_KCSEL0_SHIFT) | \
	 (((unsigned long)(kasel0)) << TEV_KSEL_KASEL0_SHIFT) | \
	 (((unsigned long)(kcsel1)) << TEV_KSEL_KCSEL1_SHIFT) | \
	 (((unsigned long)(kasel1)) << TEV_KSEL_KASEL1_SHIFT) | \
	 (((unsigned long)(rid)) << TEV_KSEL_RID_SHIFT))

typedef struct {
    unsigned long rid:TEV_KSEL_RID_SIZE;
    unsigned long kasel1:TEV_KSEL_KASEL1_SIZE;
    unsigned long kcsel1:TEV_KSEL_KCSEL1_SIZE;
    unsigned long kasel0:TEV_KSEL_KASEL0_SIZE;
    unsigned long kcsel0:TEV_KSEL_KCSEL0_SIZE;
    unsigned long xga:TEV_KSEL_XGA_SIZE;
    unsigned long xrb:TEV_KSEL_XRB_SIZE;
} tev_ksel_t;

typedef union {
    unsigned long val;
    tev_ksel_t f;
} tev_ksel_u;


#endif /* __TEV_REG_H__ */
