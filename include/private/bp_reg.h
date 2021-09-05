/*
 *  bp_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from bp_reg.fdl
 */

#ifndef __BP_REG_H__
#define __BP_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  bp_fmt enum
 */
#define BP_FMT8	0x00000000
#define BP_FMT5	0x00000001
#define BP_FMT4	0x00000002
#define BP_FMT3	0x00000003

/*
 *  bp_bias enum
 */
#define BP_BIAS_000	0x00000000
#define BP_BIAS_001	0x00000001
#define BP_BIAS_010	0x00000002
#define BP_BIAS_011	0x00000003
#define BP_BIAS_100	0x00000004
#define BP_BIAS_101	0x00000005
#define BP_BIAS_110	0x00000006
#define BP_BIAS_111	0x00000007

/*
 *  bp_bs enum
 */
#define BP_BA_OFF	0x00000000
#define BP_BA_S	0x00000001
#define BP_BA_T	0x00000002
#define BP_BA_U	0x00000003

/*
 *  bp_m enum
 */
#define BP_M_OFF	0x00000000
#define BP_M_0	0x00000001
#define BP_M_1	0x00000002
#define BP_M_2	0x00000003
#define BP_M_UNUSED_4	0x00000004
#define BP_M_A0	0x00000005
#define BP_M_A1	0x00000006
#define BP_M_A2	0x00000007
#define BP_M_UNUSED_8	0x00000008
#define BP_M_B0	0x00000009
#define BP_M_B1	0x0000000a
#define BP_M_B2	0x0000000b
#define BP_M_UNUSED_12	0x0000000c
#define BP_M_UNUSED_13	0x0000000d
#define BP_M_UNUSED_14	0x0000000e
#define BP_M_UNUSED_15	0x0000000f

/*
 *  bp_wrap enum
 */
#define BP_WRAP_OFF	0x00000000
#define BP_WRAP_8	0x00000001
#define BP_WRAP_7	0x00000002
#define BP_WRAP_6	0x00000003
#define BP_WRAP_5	0x00000004
#define BP_WRAP_4	0x00000005
#define BP_WRAP_ZERO	0x00000006
#define BP_WRAP_UNUSED_7	0x00000007

/*
 *  bp_lb enum
 */
#define BP_LB_BUMP	0x00000000
#define BP_LB_RAS	0x00000001

/*
 *  bp_fb enum
 */
#define BP_FB_OFF	0x00000000
#define BP_FB_ON	0x00000001

/*
 *  bp_mtxa struct
 */
#define BP_MTXA_MA_SIZE	11
#define BP_MTXA_MA_SHIFT	0
#define BP_MTXA_MA_MASK	0x000007ff
#define BP_MTXA_GET_MA(bp_mtxa) \
	((((unsigned long)(bp_mtxa)) & BP_MTXA_MA_MASK) >> BP_MTXA_MA_SHIFT)
#define BP_MTXA_SET_MA(bp_mtxa, ma) { \
	FDL_ASSERT(!((ma) & ~((1 << BP_MTXA_MA_SIZE)-1))); \
	bp_mtxa = (((unsigned long)(bp_mtxa)) & ~BP_MTXA_MA_MASK) | (((unsigned long)(ma)) << BP_MTXA_MA_SHIFT);\
}
#define BP_MTXA_MB_SIZE	11
#define BP_MTXA_MB_SHIFT	11
#define BP_MTXA_MB_MASK	0x003ff800
#define BP_MTXA_GET_MB(bp_mtxa) \
	((((unsigned long)(bp_mtxa)) & BP_MTXA_MB_MASK) >> BP_MTXA_MB_SHIFT)
#define BP_MTXA_SET_MB(bp_mtxa, mb) { \
	FDL_ASSERT(!((mb) & ~((1 << BP_MTXA_MB_SIZE)-1))); \
	bp_mtxa = (((unsigned long)(bp_mtxa)) & ~BP_MTXA_MB_MASK) | (((unsigned long)(mb)) << BP_MTXA_MB_SHIFT);\
}
#define BP_MTXA_S_SIZE	2
#define BP_MTXA_S_SHIFT	22
#define BP_MTXA_S_MASK	0x00c00000
#define BP_MTXA_GET_S(bp_mtxa) \
	((((unsigned long)(bp_mtxa)) & BP_MTXA_S_MASK) >> BP_MTXA_S_SHIFT)
#define BP_MTXA_SET_S(bp_mtxa, s) { \
	FDL_ASSERT(!((s) & ~((1 << BP_MTXA_S_SIZE)-1))); \
	bp_mtxa = (((unsigned long)(bp_mtxa)) & ~BP_MTXA_S_MASK) | (((unsigned long)(s)) << BP_MTXA_S_SHIFT);\
}
#define BP_MTXA_RID_SIZE	8
#define BP_MTXA_RID_SHIFT	24
#define BP_MTXA_RID_MASK	0xff000000
#define BP_MTXA_GET_RID(bp_mtxa) \
	((((unsigned long)(bp_mtxa)) & BP_MTXA_RID_MASK) >> BP_MTXA_RID_SHIFT)
#define BP_MTXA_SET_RID(bp_mtxa, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << BP_MTXA_RID_SIZE)-1))); \
	bp_mtxa = (((unsigned long)(bp_mtxa)) & ~BP_MTXA_RID_MASK) | (((unsigned long)(rid)) << BP_MTXA_RID_SHIFT);\
}
#define BP_MTXA_TOTAL_SIZE	32
#define BP_MTXA(ma, mb, s, rid) \
	((((unsigned long)(ma)) << BP_MTXA_MA_SHIFT) | \
	 (((unsigned long)(mb)) << BP_MTXA_MB_SHIFT) | \
	 (((unsigned long)(s)) << BP_MTXA_S_SHIFT) | \
	 (((unsigned long)(rid)) << BP_MTXA_RID_SHIFT))

typedef struct {
    unsigned long rid:BP_MTXA_RID_SIZE;
    unsigned long s:BP_MTXA_S_SIZE;
    unsigned long mb:BP_MTXA_MB_SIZE;
    unsigned long ma:BP_MTXA_MA_SIZE;
} bp_mtxa_t;

typedef union {
    unsigned long val;
    bp_mtxa_t f;
} bp_mtxa_u;

/*
 *  bp_mtxb struct
 */
#define BP_MTXB_MC_SIZE	11
#define BP_MTXB_MC_SHIFT	0
#define BP_MTXB_MC_MASK	0x000007ff
#define BP_MTXB_GET_MC(bp_mtxb) \
	((((unsigned long)(bp_mtxb)) & BP_MTXB_MC_MASK) >> BP_MTXB_MC_SHIFT)
#define BP_MTXB_SET_MC(bp_mtxb, mc) { \
	FDL_ASSERT(!((mc) & ~((1 << BP_MTXB_MC_SIZE)-1))); \
	bp_mtxb = (((unsigned long)(bp_mtxb)) & ~BP_MTXB_MC_MASK) | (((unsigned long)(mc)) << BP_MTXB_MC_SHIFT);\
}
#define BP_MTXB_MD_SIZE	11
#define BP_MTXB_MD_SHIFT	11
#define BP_MTXB_MD_MASK	0x003ff800
#define BP_MTXB_GET_MD(bp_mtxb) \
	((((unsigned long)(bp_mtxb)) & BP_MTXB_MD_MASK) >> BP_MTXB_MD_SHIFT)
#define BP_MTXB_SET_MD(bp_mtxb, md) { \
	FDL_ASSERT(!((md) & ~((1 << BP_MTXB_MD_SIZE)-1))); \
	bp_mtxb = (((unsigned long)(bp_mtxb)) & ~BP_MTXB_MD_MASK) | (((unsigned long)(md)) << BP_MTXB_MD_SHIFT);\
}
#define BP_MTXB_S_SIZE	2
#define BP_MTXB_S_SHIFT	22
#define BP_MTXB_S_MASK	0x00c00000
#define BP_MTXB_GET_S(bp_mtxb) \
	((((unsigned long)(bp_mtxb)) & BP_MTXB_S_MASK) >> BP_MTXB_S_SHIFT)
#define BP_MTXB_SET_S(bp_mtxb, s) { \
	FDL_ASSERT(!((s) & ~((1 << BP_MTXB_S_SIZE)-1))); \
	bp_mtxb = (((unsigned long)(bp_mtxb)) & ~BP_MTXB_S_MASK) | (((unsigned long)(s)) << BP_MTXB_S_SHIFT);\
}
#define BP_MTXB_RID_SIZE	8
#define BP_MTXB_RID_SHIFT	24
#define BP_MTXB_RID_MASK	0xff000000
#define BP_MTXB_GET_RID(bp_mtxb) \
	((((unsigned long)(bp_mtxb)) & BP_MTXB_RID_MASK) >> BP_MTXB_RID_SHIFT)
#define BP_MTXB_SET_RID(bp_mtxb, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << BP_MTXB_RID_SIZE)-1))); \
	bp_mtxb = (((unsigned long)(bp_mtxb)) & ~BP_MTXB_RID_MASK) | (((unsigned long)(rid)) << BP_MTXB_RID_SHIFT);\
}
#define BP_MTXB_TOTAL_SIZE	32
#define BP_MTXB(mc, md, s, rid) \
	((((unsigned long)(mc)) << BP_MTXB_MC_SHIFT) | \
	 (((unsigned long)(md)) << BP_MTXB_MD_SHIFT) | \
	 (((unsigned long)(s)) << BP_MTXB_S_SHIFT) | \
	 (((unsigned long)(rid)) << BP_MTXB_RID_SHIFT))

typedef struct {
    unsigned long rid:BP_MTXB_RID_SIZE;
    unsigned long s:BP_MTXB_S_SIZE;
    unsigned long md:BP_MTXB_MD_SIZE;
    unsigned long mc:BP_MTXB_MC_SIZE;
} bp_mtxb_t;

typedef union {
    unsigned long val;
    bp_mtxb_t f;
} bp_mtxb_u;

/*
 *  bp_mtxc struct
 */
#define BP_MTXC_ME_SIZE	11
#define BP_MTXC_ME_SHIFT	0
#define BP_MTXC_ME_MASK	0x000007ff
#define BP_MTXC_GET_ME(bp_mtxc) \
	((((unsigned long)(bp_mtxc)) & BP_MTXC_ME_MASK) >> BP_MTXC_ME_SHIFT)
#define BP_MTXC_SET_ME(bp_mtxc, me) { \
	FDL_ASSERT(!((me) & ~((1 << BP_MTXC_ME_SIZE)-1))); \
	bp_mtxc = (((unsigned long)(bp_mtxc)) & ~BP_MTXC_ME_MASK) | (((unsigned long)(me)) << BP_MTXC_ME_SHIFT);\
}
#define BP_MTXC_MF_SIZE	11
#define BP_MTXC_MF_SHIFT	11
#define BP_MTXC_MF_MASK	0x003ff800
#define BP_MTXC_GET_MF(bp_mtxc) \
	((((unsigned long)(bp_mtxc)) & BP_MTXC_MF_MASK) >> BP_MTXC_MF_SHIFT)
#define BP_MTXC_SET_MF(bp_mtxc, mf) { \
	FDL_ASSERT(!((mf) & ~((1 << BP_MTXC_MF_SIZE)-1))); \
	bp_mtxc = (((unsigned long)(bp_mtxc)) & ~BP_MTXC_MF_MASK) | (((unsigned long)(mf)) << BP_MTXC_MF_SHIFT);\
}
#define BP_MTXC_S_SIZE	2
#define BP_MTXC_S_SHIFT	22
#define BP_MTXC_S_MASK	0x00c00000
#define BP_MTXC_GET_S(bp_mtxc) \
	((((unsigned long)(bp_mtxc)) & BP_MTXC_S_MASK) >> BP_MTXC_S_SHIFT)
#define BP_MTXC_SET_S(bp_mtxc, s) { \
	FDL_ASSERT(!((s) & ~((1 << BP_MTXC_S_SIZE)-1))); \
	bp_mtxc = (((unsigned long)(bp_mtxc)) & ~BP_MTXC_S_MASK) | (((unsigned long)(s)) << BP_MTXC_S_SHIFT);\
}
#define BP_MTXC_RID_SIZE	8
#define BP_MTXC_RID_SHIFT	24
#define BP_MTXC_RID_MASK	0xff000000
#define BP_MTXC_GET_RID(bp_mtxc) \
	((((unsigned long)(bp_mtxc)) & BP_MTXC_RID_MASK) >> BP_MTXC_RID_SHIFT)
#define BP_MTXC_SET_RID(bp_mtxc, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << BP_MTXC_RID_SIZE)-1))); \
	bp_mtxc = (((unsigned long)(bp_mtxc)) & ~BP_MTXC_RID_MASK) | (((unsigned long)(rid)) << BP_MTXC_RID_SHIFT);\
}
#define BP_MTXC_TOTAL_SIZE	32
#define BP_MTXC(me, mf, s, rid) \
	((((unsigned long)(me)) << BP_MTXC_ME_SHIFT) | \
	 (((unsigned long)(mf)) << BP_MTXC_MF_SHIFT) | \
	 (((unsigned long)(s)) << BP_MTXC_S_SHIFT) | \
	 (((unsigned long)(rid)) << BP_MTXC_RID_SHIFT))

typedef struct {
    unsigned long rid:BP_MTXC_RID_SIZE;
    unsigned long s:BP_MTXC_S_SIZE;
    unsigned long mf:BP_MTXC_MF_SIZE;
    unsigned long me:BP_MTXC_ME_SIZE;
} bp_mtxc_t;

typedef union {
    unsigned long val;
    bp_mtxc_t f;
} bp_mtxc_u;

/*
 *  bp_cmd struct
 */
#define BP_CMD_BT_SIZE	2
#define BP_CMD_BT_SHIFT	0
#define BP_CMD_BT_MASK	0x00000003
#define BP_CMD_GET_BT(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_BT_MASK) >> BP_CMD_BT_SHIFT)
#define BP_CMD_SET_BT(bp_cmd, bt) { \
	FDL_ASSERT(!((bt) & ~((1 << BP_CMD_BT_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_BT_MASK) | (((unsigned long)(bt)) << BP_CMD_BT_SHIFT);\
}
#define BP_CMD_FMT_SIZE	2
#define BP_CMD_FMT_SHIFT	2
#define BP_CMD_FMT_MASK	0x0000000c
#define BP_CMD_GET_FMT(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_FMT_MASK) >> BP_CMD_FMT_SHIFT)
#define BP_CMD_SET_FMT(bp_cmd, fmt) { \
	FDL_ASSERT(!((fmt) & ~((1 << BP_CMD_FMT_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_FMT_MASK) | (((unsigned long)(fmt)) << BP_CMD_FMT_SHIFT);\
}
#define BP_CMD_BIAS_SIZE	3
#define BP_CMD_BIAS_SHIFT	4
#define BP_CMD_BIAS_MASK	0x00000070
#define BP_CMD_GET_BIAS(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_BIAS_MASK) >> BP_CMD_BIAS_SHIFT)
#define BP_CMD_SET_BIAS(bp_cmd, bias) { \
	FDL_ASSERT(!((bias) & ~((1 << BP_CMD_BIAS_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_BIAS_MASK) | (((unsigned long)(bias)) << BP_CMD_BIAS_SHIFT);\
}
#define BP_CMD_BS_SIZE	2
#define BP_CMD_BS_SHIFT	7
#define BP_CMD_BS_MASK	0x00000180
#define BP_CMD_GET_BS(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_BS_MASK) >> BP_CMD_BS_SHIFT)
#define BP_CMD_SET_BS(bp_cmd, bs) { \
	FDL_ASSERT(!((bs) & ~((1 << BP_CMD_BS_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_BS_MASK) | (((unsigned long)(bs)) << BP_CMD_BS_SHIFT);\
}
#define BP_CMD_M_SIZE	4
#define BP_CMD_M_SHIFT	9
#define BP_CMD_M_MASK	0x00001e00
#define BP_CMD_GET_M(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_M_MASK) >> BP_CMD_M_SHIFT)
#define BP_CMD_SET_M(bp_cmd, m) { \
	FDL_ASSERT(!((m) & ~((1 << BP_CMD_M_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_M_MASK) | (((unsigned long)(m)) << BP_CMD_M_SHIFT);\
}
#define BP_CMD_SW_SIZE	3
#define BP_CMD_SW_SHIFT	13
#define BP_CMD_SW_MASK	0x0000e000
#define BP_CMD_GET_SW(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_SW_MASK) >> BP_CMD_SW_SHIFT)
#define BP_CMD_SET_SW(bp_cmd, sw) { \
	FDL_ASSERT(!((sw) & ~((1 << BP_CMD_SW_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_SW_MASK) | (((unsigned long)(sw)) << BP_CMD_SW_SHIFT);\
}
#define BP_CMD_TW_SIZE	3
#define BP_CMD_TW_SHIFT	16
#define BP_CMD_TW_MASK	0x00070000
#define BP_CMD_GET_TW(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_TW_MASK) >> BP_CMD_TW_SHIFT)
#define BP_CMD_SET_TW(bp_cmd, tw) { \
	FDL_ASSERT(!((tw) & ~((1 << BP_CMD_TW_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_TW_MASK) | (((unsigned long)(tw)) << BP_CMD_TW_SHIFT);\
}
#define BP_CMD_LB_SIZE	1
#define BP_CMD_LB_SHIFT	19
#define BP_CMD_LB_MASK	0x00080000
#define BP_CMD_GET_LB(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_LB_MASK) >> BP_CMD_LB_SHIFT)
#define BP_CMD_SET_LB(bp_cmd, lb) { \
	FDL_ASSERT(!((lb) & ~((1 << BP_CMD_LB_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_LB_MASK) | (((unsigned long)(lb)) << BP_CMD_LB_SHIFT);\
}
#define BP_CMD_FB_SIZE	1
#define BP_CMD_FB_SHIFT	20
#define BP_CMD_FB_MASK	0x00100000
#define BP_CMD_GET_FB(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_FB_MASK) >> BP_CMD_FB_SHIFT)
#define BP_CMD_SET_FB(bp_cmd, fb) { \
	FDL_ASSERT(!((fb) & ~((1 << BP_CMD_FB_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_FB_MASK) | (((unsigned long)(fb)) << BP_CMD_FB_SHIFT);\
}
#define BP_CMD_PAD0_SIZE	3
#define BP_CMD_PAD0_SHIFT	21
#define BP_CMD_PAD0_MASK	0x00e00000
#define BP_CMD_GET_PAD0(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_PAD0_MASK) >> BP_CMD_PAD0_SHIFT)
#define BP_CMD_SET_PAD0(bp_cmd, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << BP_CMD_PAD0_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_PAD0_MASK) | (((unsigned long)(pad0)) << BP_CMD_PAD0_SHIFT);\
}
#define BP_CMD_RID_SIZE	8
#define BP_CMD_RID_SHIFT	24
#define BP_CMD_RID_MASK	0xff000000
#define BP_CMD_GET_RID(bp_cmd) \
	((((unsigned long)(bp_cmd)) & BP_CMD_RID_MASK) >> BP_CMD_RID_SHIFT)
#define BP_CMD_SET_RID(bp_cmd, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << BP_CMD_RID_SIZE)-1))); \
	bp_cmd = (((unsigned long)(bp_cmd)) & ~BP_CMD_RID_MASK) | (((unsigned long)(rid)) << BP_CMD_RID_SHIFT);\
}
#define BP_CMD_TOTAL_SIZE	32
#define BP_CMD(bt, fmt, bias, bs, m, sw, tw, lb, fb, rid) \
	((((unsigned long)(bt)) << BP_CMD_BT_SHIFT) | \
	 (((unsigned long)(fmt)) << BP_CMD_FMT_SHIFT) | \
	 (((unsigned long)(bias)) << BP_CMD_BIAS_SHIFT) | \
	 (((unsigned long)(bs)) << BP_CMD_BS_SHIFT) | \
	 (((unsigned long)(m)) << BP_CMD_M_SHIFT) | \
	 (((unsigned long)(sw)) << BP_CMD_SW_SHIFT) | \
	 (((unsigned long)(tw)) << BP_CMD_TW_SHIFT) | \
	 (((unsigned long)(lb)) << BP_CMD_LB_SHIFT) | \
	 (((unsigned long)(fb)) << BP_CMD_FB_SHIFT) | \
	 (((unsigned long)(rid)) << BP_CMD_RID_SHIFT))

typedef struct {
    unsigned long rid:BP_CMD_RID_SIZE;
    unsigned long pad0:BP_CMD_PAD0_SIZE;
    unsigned long fb:BP_CMD_FB_SIZE;
    unsigned long lb:BP_CMD_LB_SIZE;
    unsigned long tw:BP_CMD_TW_SIZE;
    unsigned long sw:BP_CMD_SW_SIZE;
    unsigned long m:BP_CMD_M_SIZE;
    unsigned long bs:BP_CMD_BS_SIZE;
    unsigned long bias:BP_CMD_BIAS_SIZE;
    unsigned long fmt:BP_CMD_FMT_SIZE;
    unsigned long bt:BP_CMD_BT_SIZE;
} bp_cmd_t;

typedef union {
    unsigned long val;
    bp_cmd_t f;
} bp_cmd_u;

/*
 *  bp_imask struct
 */
#define BP_IMASK_IMASK_SIZE	8
#define BP_IMASK_IMASK_SHIFT	0
#define BP_IMASK_IMASK_MASK	0x000000ff
#define BP_IMASK_GET_IMASK(bp_imask) \
	((((unsigned long)(bp_imask)) & BP_IMASK_IMASK_MASK) >> BP_IMASK_IMASK_SHIFT)
#define BP_IMASK_SET_IMASK(bp_imask, imask) { \
	FDL_ASSERT(!((imask) & ~((1 << BP_IMASK_IMASK_SIZE)-1))); \
	bp_imask = (((unsigned long)(bp_imask)) & ~BP_IMASK_IMASK_MASK) | (((unsigned long)(imask)) << BP_IMASK_IMASK_SHIFT);\
}
#define BP_IMASK_PAD0_SIZE	16
#define BP_IMASK_PAD0_SHIFT	8
#define BP_IMASK_PAD0_MASK	0x00ffff00
#define BP_IMASK_GET_PAD0(bp_imask) \
	((((unsigned long)(bp_imask)) & BP_IMASK_PAD0_MASK) >> BP_IMASK_PAD0_SHIFT)
#define BP_IMASK_SET_PAD0(bp_imask, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << BP_IMASK_PAD0_SIZE)-1))); \
	bp_imask = (((unsigned long)(bp_imask)) & ~BP_IMASK_PAD0_MASK) | (((unsigned long)(pad0)) << BP_IMASK_PAD0_SHIFT);\
}
#define BP_IMASK_RID_SIZE	8
#define BP_IMASK_RID_SHIFT	24
#define BP_IMASK_RID_MASK	0xff000000
#define BP_IMASK_GET_RID(bp_imask) \
	((((unsigned long)(bp_imask)) & BP_IMASK_RID_MASK) >> BP_IMASK_RID_SHIFT)
#define BP_IMASK_SET_RID(bp_imask, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << BP_IMASK_RID_SIZE)-1))); \
	bp_imask = (((unsigned long)(bp_imask)) & ~BP_IMASK_RID_MASK) | (((unsigned long)(rid)) << BP_IMASK_RID_SHIFT);\
}
#define BP_IMASK_TOTAL_SIZE	32
#define BP_IMASK(imask, rid) \
	((((unsigned long)(imask)) << BP_IMASK_IMASK_SHIFT) | \
	 (((unsigned long)(rid)) << BP_IMASK_RID_SHIFT))

typedef struct {
    unsigned long rid:BP_IMASK_RID_SIZE;
    unsigned long pad0:BP_IMASK_PAD0_SIZE;
    unsigned long imask:BP_IMASK_IMASK_SIZE;
} bp_imask_t;

typedef union {
    unsigned long val;
    bp_imask_t f;
} bp_imask_u;


#endif /* __BP_REG_H__ */
