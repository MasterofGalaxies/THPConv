/*
 *  ras_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from ras_reg.fdl
 */

#ifndef __RAS_REG_H__
#define __RAS_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  ras1_sts enum
 */
#define RAS1_STS_1	0x00000000
#define RAS1_STS_2	0x00000001
#define RAS1_STS_4	0x00000002
#define RAS1_STS_8	0x00000003
#define RAS1_STS_16	0x00000004
#define RAS1_STS_32	0x00000005
#define RAS1_STS_64	0x00000006
#define RAS1_STS_128	0x00000007
#define RAS1_STS_256	0x00000008
#define RAS1_STS_UNUSED_9	0x00000009
#define RAS1_STS_UNUSED_10	0x0000000a
#define RAS1_STS_UNUSED_11	0x0000000b
#define RAS1_STS_UNUSED_12	0x0000000c
#define RAS1_STS_UNUSED_13	0x0000000d
#define RAS1_STS_UNUSED_14	0x0000000e
#define RAS1_STS_UNUSED_15	0x0000000f

/*
 *  ras1_cc enum
 */
#define RAS1_CC_0	0x00000000
#define RAS1_CC_1	0x00000001
#define RAS1_CC_2	0x00000002
#define RAS1_CC_3	0x00000003
#define RAS2_CC_UNUSED	0x00000004
#define RAS1_CC_B	0x00000005
#define RAS1_CC_BN	0x00000006
#define RAS1_CC_Z	0x00000007

/*
 *  pfr_sel enum
 */
#define PFR_ZERO	0x00000000
#define PFR_ONE	0x00000001
#define PFR_R0_VR	0x00000002
#define PFR_R0_V	0x00000003
#define PFR_R0_R	0x00000004
#define PFR_R0_QUAD	0x00000005
#define PFR_R0_Z	0x00000006
#define PFR_R0_P1	0x00000007
#define PFR_R0_P2	0x00000008
#define PFR_R0_P3	0x00000009
#define PFR_R0_P4	0x0000000a
#define PFR_R0_NZ	0x0000000b
#define PFR_R0_ZE	0x0000000c
#define PFR_R0_QCNT	0x0000000d
#define PFR_R0_SCNT	0x0000000e
#define PFR_R1_VR	0x0000000f
#define PFR_R1_V	0x00000010
#define PFR_R1_R	0x00000011
#define PFR_R1_QUAD	0x00000012
#define PFR_R1_COND	0x00000013
#define PFR_R1_Z	0x00000014
#define PFR_R1_CYC	0x00000015
#define PFR_R1_CZ	0x00000016
#define PFR_R2_VR	0x00000017
#define PFR_R2_V	0x00000018
#define PFR_R2_R	0x00000019
#define PFR_R2_QUAD	0x0000001a
#define PFR_R2_REG	0x0000001b
#define PFR_R2_Z	0x0000001c
#define PFR_R2_CYC	0x0000001d
#define PFR_R2_CZ	0x0000001e
#define PFR_SEL_UNUSED_31	0x0000001f

/*
 *  pfr_ntev enum
 */
#define PFR_TEV1	0x00000000
#define PFR_TEV2	0x00000001
#define PFR_TEV3	0x00000002
#define PFR_TEV4	0x00000003
#define PFR_TEV5	0x00000004
#define PFR_TEV6	0x00000005
#define PFR_TEV7	0x00000006
#define PFR_TEV8	0x00000007
#define PFR_TEV9	0x00000008
#define PFR_TEV10	0x00000009
#define PFR_TEV11	0x0000000a
#define PFR_TEV12	0x0000000b
#define PFR_TEV13	0x0000000c
#define PFR_TEV14	0x0000000d
#define PFR_TEV15	0x0000000e
#define PFR_TEV16	0x0000000f
#define PFR_TEVA	0x00000010
#define PFR_NTEV_UNUSED_17	0x00000011
#define PFR_NTEV_UNUSED_18	0x00000012
#define PFR_NTEV_UNUSED_19	0x00000013
#define PFR_NTEV_UNUSED_20	0x00000014
#define PFR_NTEV_UNUSED_21	0x00000015
#define PFR_NTEV_UNUSED_22	0x00000016
#define PFR_NTEV_UNUSED_23	0x00000017
#define PFR_NTEV_UNUSED_24	0x00000018
#define PFR_NTEV_UNUSED_25	0x00000019
#define PFR_NTEV_UNUSED_26	0x0000001a
#define PFR_NTEV_UNUSED_27	0x0000001b
#define PFR_NTEV_UNUSED_28	0x0000001c
#define PFR_NTEV_UNUSED_29	0x0000001d
#define PFR_NTEV_UNUSED_30	0x0000001e
#define PFR_NTEV_UNUSED_31	0x0000001f

/*
 *  pfr_nbmp enum
 */
#define PFR_BMP0	0x00000000
#define PFR_BMP1	0x00000001
#define PFR_BMP2	0x00000002
#define PFR_BMP3	0x00000003
#define PFR_BMP4	0x00000004
#define PFR_BMPA	0x00000005
#define PFR_NBMP_UNUSED_6	0x00000006
#define PFR_NBMP_UNUSED_7	0x00000007

/*
 *  pfr_br enum
 */
#define PFR_BR_OFF	0x00000000
#define PFR_BR_UNUSED	0x00000001
#define PFR_BR_RAS0	0x00000002
#define PFR_BR_RAS0A	0x00000003
#define PFR_BR_RAS1	0x00000004
#define PFR_BR_RAS1A	0x00000005
#define PFR_BR_RAS2	0x00000006
#define PFR_BR_RAS2A	0x00000007

/*
 *  ras1_ss struct
 */
#define RAS1_SS_SS0_SIZE	4
#define RAS1_SS_SS0_SHIFT	0
#define RAS1_SS_SS0_MASK	0x0000000f
#define RAS1_SS_GET_SS0(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_SS0_MASK) >> RAS1_SS_SS0_SHIFT)
#define RAS1_SS_SET_SS0(ras1_ss, ss0) { \
	FDL_ASSERT(!((ss0) & ~((1 << RAS1_SS_SS0_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_SS0_MASK) | (((unsigned long)(ss0)) << RAS1_SS_SS0_SHIFT);\
}
#define RAS1_SS_TS0_SIZE	4
#define RAS1_SS_TS0_SHIFT	4
#define RAS1_SS_TS0_MASK	0x000000f0
#define RAS1_SS_GET_TS0(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_TS0_MASK) >> RAS1_SS_TS0_SHIFT)
#define RAS1_SS_SET_TS0(ras1_ss, ts0) { \
	FDL_ASSERT(!((ts0) & ~((1 << RAS1_SS_TS0_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_TS0_MASK) | (((unsigned long)(ts0)) << RAS1_SS_TS0_SHIFT);\
}
#define RAS1_SS_SS1_SIZE	4
#define RAS1_SS_SS1_SHIFT	8
#define RAS1_SS_SS1_MASK	0x00000f00
#define RAS1_SS_GET_SS1(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_SS1_MASK) >> RAS1_SS_SS1_SHIFT)
#define RAS1_SS_SET_SS1(ras1_ss, ss1) { \
	FDL_ASSERT(!((ss1) & ~((1 << RAS1_SS_SS1_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_SS1_MASK) | (((unsigned long)(ss1)) << RAS1_SS_SS1_SHIFT);\
}
#define RAS1_SS_TS1_SIZE	4
#define RAS1_SS_TS1_SHIFT	12
#define RAS1_SS_TS1_MASK	0x0000f000
#define RAS1_SS_GET_TS1(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_TS1_MASK) >> RAS1_SS_TS1_SHIFT)
#define RAS1_SS_SET_TS1(ras1_ss, ts1) { \
	FDL_ASSERT(!((ts1) & ~((1 << RAS1_SS_TS1_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_TS1_MASK) | (((unsigned long)(ts1)) << RAS1_SS_TS1_SHIFT);\
}
#define RAS1_SS_PAD0_SIZE	8
#define RAS1_SS_PAD0_SHIFT	16
#define RAS1_SS_PAD0_MASK	0x00ff0000
#define RAS1_SS_GET_PAD0(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_PAD0_MASK) >> RAS1_SS_PAD0_SHIFT)
#define RAS1_SS_SET_PAD0(ras1_ss, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << RAS1_SS_PAD0_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_PAD0_MASK) | (((unsigned long)(pad0)) << RAS1_SS_PAD0_SHIFT);\
}
#define RAS1_SS_RID_SIZE	8
#define RAS1_SS_RID_SHIFT	24
#define RAS1_SS_RID_MASK	0xff000000
#define RAS1_SS_GET_RID(ras1_ss) \
	((((unsigned long)(ras1_ss)) & RAS1_SS_RID_MASK) >> RAS1_SS_RID_SHIFT)
#define RAS1_SS_SET_RID(ras1_ss, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << RAS1_SS_RID_SIZE)-1))); \
	ras1_ss = (((unsigned long)(ras1_ss)) & ~RAS1_SS_RID_MASK) | (((unsigned long)(rid)) << RAS1_SS_RID_SHIFT);\
}
#define RAS1_SS_TOTAL_SIZE	32
#define RAS1_SS(ss0, ts0, ss1, ts1, rid) \
	((((unsigned long)(ss0)) << RAS1_SS_SS0_SHIFT) | \
	 (((unsigned long)(ts0)) << RAS1_SS_TS0_SHIFT) | \
	 (((unsigned long)(ss1)) << RAS1_SS_SS1_SHIFT) | \
	 (((unsigned long)(ts1)) << RAS1_SS_TS1_SHIFT) | \
	 (((unsigned long)(rid)) << RAS1_SS_RID_SHIFT))

typedef struct {
    unsigned long rid:RAS1_SS_RID_SIZE;
    unsigned long pad0:RAS1_SS_PAD0_SIZE;
    unsigned long ts1:RAS1_SS_TS1_SIZE;
    unsigned long ss1:RAS1_SS_SS1_SIZE;
    unsigned long ts0:RAS1_SS_TS0_SIZE;
    unsigned long ss0:RAS1_SS_SS0_SIZE;
} ras1_ss_t;

typedef union {
    unsigned long val;
    ras1_ss_t f;
} ras1_ss_u;

/*
 *  ras1_iref struct
 */
#define RAS1_IREF_BI0_SIZE	3
#define RAS1_IREF_BI0_SHIFT	0
#define RAS1_IREF_BI0_MASK	0x00000007
#define RAS1_IREF_GET_BI0(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BI0_MASK) >> RAS1_IREF_BI0_SHIFT)
#define RAS1_IREF_SET_BI0(ras1_iref, bi0) { \
	FDL_ASSERT(!((bi0) & ~((1 << RAS1_IREF_BI0_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BI0_MASK) | (((unsigned long)(bi0)) << RAS1_IREF_BI0_SHIFT);\
}
#define RAS1_IREF_BC0_SIZE	3
#define RAS1_IREF_BC0_SHIFT	3
#define RAS1_IREF_BC0_MASK	0x00000038
#define RAS1_IREF_GET_BC0(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BC0_MASK) >> RAS1_IREF_BC0_SHIFT)
#define RAS1_IREF_SET_BC0(ras1_iref, bc0) { \
	FDL_ASSERT(!((bc0) & ~((1 << RAS1_IREF_BC0_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BC0_MASK) | (((unsigned long)(bc0)) << RAS1_IREF_BC0_SHIFT);\
}
#define RAS1_IREF_BI1_SIZE	3
#define RAS1_IREF_BI1_SHIFT	6
#define RAS1_IREF_BI1_MASK	0x000001c0
#define RAS1_IREF_GET_BI1(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BI1_MASK) >> RAS1_IREF_BI1_SHIFT)
#define RAS1_IREF_SET_BI1(ras1_iref, bi1) { \
	FDL_ASSERT(!((bi1) & ~((1 << RAS1_IREF_BI1_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BI1_MASK) | (((unsigned long)(bi1)) << RAS1_IREF_BI1_SHIFT);\
}
#define RAS1_IREF_BC1_SIZE	3
#define RAS1_IREF_BC1_SHIFT	9
#define RAS1_IREF_BC1_MASK	0x00000e00
#define RAS1_IREF_GET_BC1(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BC1_MASK) >> RAS1_IREF_BC1_SHIFT)
#define RAS1_IREF_SET_BC1(ras1_iref, bc1) { \
	FDL_ASSERT(!((bc1) & ~((1 << RAS1_IREF_BC1_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BC1_MASK) | (((unsigned long)(bc1)) << RAS1_IREF_BC1_SHIFT);\
}
#define RAS1_IREF_BI2_SIZE	3
#define RAS1_IREF_BI2_SHIFT	12
#define RAS1_IREF_BI2_MASK	0x00007000
#define RAS1_IREF_GET_BI2(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BI2_MASK) >> RAS1_IREF_BI2_SHIFT)
#define RAS1_IREF_SET_BI2(ras1_iref, bi2) { \
	FDL_ASSERT(!((bi2) & ~((1 << RAS1_IREF_BI2_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BI2_MASK) | (((unsigned long)(bi2)) << RAS1_IREF_BI2_SHIFT);\
}
#define RAS1_IREF_BC2_SIZE	3
#define RAS1_IREF_BC2_SHIFT	15
#define RAS1_IREF_BC2_MASK	0x00038000
#define RAS1_IREF_GET_BC2(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BC2_MASK) >> RAS1_IREF_BC2_SHIFT)
#define RAS1_IREF_SET_BC2(ras1_iref, bc2) { \
	FDL_ASSERT(!((bc2) & ~((1 << RAS1_IREF_BC2_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BC2_MASK) | (((unsigned long)(bc2)) << RAS1_IREF_BC2_SHIFT);\
}
#define RAS1_IREF_BI3_SIZE	3
#define RAS1_IREF_BI3_SHIFT	18
#define RAS1_IREF_BI3_MASK	0x001c0000
#define RAS1_IREF_GET_BI3(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BI3_MASK) >> RAS1_IREF_BI3_SHIFT)
#define RAS1_IREF_SET_BI3(ras1_iref, bi3) { \
	FDL_ASSERT(!((bi3) & ~((1 << RAS1_IREF_BI3_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BI3_MASK) | (((unsigned long)(bi3)) << RAS1_IREF_BI3_SHIFT);\
}
#define RAS1_IREF_BC3_SIZE	3
#define RAS1_IREF_BC3_SHIFT	21
#define RAS1_IREF_BC3_MASK	0x00e00000
#define RAS1_IREF_GET_BC3(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_BC3_MASK) >> RAS1_IREF_BC3_SHIFT)
#define RAS1_IREF_SET_BC3(ras1_iref, bc3) { \
	FDL_ASSERT(!((bc3) & ~((1 << RAS1_IREF_BC3_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_BC3_MASK) | (((unsigned long)(bc3)) << RAS1_IREF_BC3_SHIFT);\
}
#define RAS1_IREF_RID_SIZE	8
#define RAS1_IREF_RID_SHIFT	24
#define RAS1_IREF_RID_MASK	0xff000000
#define RAS1_IREF_GET_RID(ras1_iref) \
	((((unsigned long)(ras1_iref)) & RAS1_IREF_RID_MASK) >> RAS1_IREF_RID_SHIFT)
#define RAS1_IREF_SET_RID(ras1_iref, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << RAS1_IREF_RID_SIZE)-1))); \
	ras1_iref = (((unsigned long)(ras1_iref)) & ~RAS1_IREF_RID_MASK) | (((unsigned long)(rid)) << RAS1_IREF_RID_SHIFT);\
}
#define RAS1_IREF_TOTAL_SIZE	32
#define RAS1_IREF(bi0, bc0, bi1, bc1, bi2, bc2, bi3, bc3, rid) \
	((((unsigned long)(bi0)) << RAS1_IREF_BI0_SHIFT) | \
	 (((unsigned long)(bc0)) << RAS1_IREF_BC0_SHIFT) | \
	 (((unsigned long)(bi1)) << RAS1_IREF_BI1_SHIFT) | \
	 (((unsigned long)(bc1)) << RAS1_IREF_BC1_SHIFT) | \
	 (((unsigned long)(bi2)) << RAS1_IREF_BI2_SHIFT) | \
	 (((unsigned long)(bc2)) << RAS1_IREF_BC2_SHIFT) | \
	 (((unsigned long)(bi3)) << RAS1_IREF_BI3_SHIFT) | \
	 (((unsigned long)(bc3)) << RAS1_IREF_BC3_SHIFT) | \
	 (((unsigned long)(rid)) << RAS1_IREF_RID_SHIFT))

typedef struct {
    unsigned long rid:RAS1_IREF_RID_SIZE;
    unsigned long bc3:RAS1_IREF_BC3_SIZE;
    unsigned long bi3:RAS1_IREF_BI3_SIZE;
    unsigned long bc2:RAS1_IREF_BC2_SIZE;
    unsigned long bi2:RAS1_IREF_BI2_SIZE;
    unsigned long bc1:RAS1_IREF_BC1_SIZE;
    unsigned long bi1:RAS1_IREF_BI1_SIZE;
    unsigned long bc0:RAS1_IREF_BC0_SIZE;
    unsigned long bi0:RAS1_IREF_BI0_SIZE;
} ras1_iref_t;

typedef union {
    unsigned long val;
    ras1_iref_t f;
} ras1_iref_u;

/*
 *  ras1_tref struct
 */
#define RAS1_TREF_TI0_SIZE	3
#define RAS1_TREF_TI0_SHIFT	0
#define RAS1_TREF_TI0_MASK	0x00000007
#define RAS1_TREF_GET_TI0(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TI0_MASK) >> RAS1_TREF_TI0_SHIFT)
#define RAS1_TREF_SET_TI0(ras1_tref, ti0) { \
	FDL_ASSERT(!((ti0) & ~((1 << RAS1_TREF_TI0_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TI0_MASK) | (((unsigned long)(ti0)) << RAS1_TREF_TI0_SHIFT);\
}
#define RAS1_TREF_TC0_SIZE	3
#define RAS1_TREF_TC0_SHIFT	3
#define RAS1_TREF_TC0_MASK	0x00000038
#define RAS1_TREF_GET_TC0(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TC0_MASK) >> RAS1_TREF_TC0_SHIFT)
#define RAS1_TREF_SET_TC0(ras1_tref, tc0) { \
	FDL_ASSERT(!((tc0) & ~((1 << RAS1_TREF_TC0_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TC0_MASK) | (((unsigned long)(tc0)) << RAS1_TREF_TC0_SHIFT);\
}
#define RAS1_TREF_TE0_SIZE	1
#define RAS1_TREF_TE0_SHIFT	6
#define RAS1_TREF_TE0_MASK	0x00000040
#define RAS1_TREF_GET_TE0(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TE0_MASK) >> RAS1_TREF_TE0_SHIFT)
#define RAS1_TREF_SET_TE0(ras1_tref, te0) { \
	FDL_ASSERT(!((te0) & ~((1 << RAS1_TREF_TE0_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TE0_MASK) | (((unsigned long)(te0)) << RAS1_TREF_TE0_SHIFT);\
}
#define RAS1_TREF_CC0_SIZE	3
#define RAS1_TREF_CC0_SHIFT	7
#define RAS1_TREF_CC0_MASK	0x00000380
#define RAS1_TREF_GET_CC0(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_CC0_MASK) >> RAS1_TREF_CC0_SHIFT)
#define RAS1_TREF_SET_CC0(ras1_tref, cc0) { \
	FDL_ASSERT(!((cc0) & ~((1 << RAS1_TREF_CC0_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_CC0_MASK) | (((unsigned long)(cc0)) << RAS1_TREF_CC0_SHIFT);\
}
#define RAS1_TREF_PAD0_SIZE	2
#define RAS1_TREF_PAD0_SHIFT	10
#define RAS1_TREF_PAD0_MASK	0x00000c00
#define RAS1_TREF_GET_PAD0(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_PAD0_MASK) >> RAS1_TREF_PAD0_SHIFT)
#define RAS1_TREF_SET_PAD0(ras1_tref, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << RAS1_TREF_PAD0_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_PAD0_MASK) | (((unsigned long)(pad0)) << RAS1_TREF_PAD0_SHIFT);\
}
#define RAS1_TREF_TI1_SIZE	3
#define RAS1_TREF_TI1_SHIFT	12
#define RAS1_TREF_TI1_MASK	0x00007000
#define RAS1_TREF_GET_TI1(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TI1_MASK) >> RAS1_TREF_TI1_SHIFT)
#define RAS1_TREF_SET_TI1(ras1_tref, ti1) { \
	FDL_ASSERT(!((ti1) & ~((1 << RAS1_TREF_TI1_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TI1_MASK) | (((unsigned long)(ti1)) << RAS1_TREF_TI1_SHIFT);\
}
#define RAS1_TREF_TC1_SIZE	3
#define RAS1_TREF_TC1_SHIFT	15
#define RAS1_TREF_TC1_MASK	0x00038000
#define RAS1_TREF_GET_TC1(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TC1_MASK) >> RAS1_TREF_TC1_SHIFT)
#define RAS1_TREF_SET_TC1(ras1_tref, tc1) { \
	FDL_ASSERT(!((tc1) & ~((1 << RAS1_TREF_TC1_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TC1_MASK) | (((unsigned long)(tc1)) << RAS1_TREF_TC1_SHIFT);\
}
#define RAS1_TREF_TE1_SIZE	1
#define RAS1_TREF_TE1_SHIFT	18
#define RAS1_TREF_TE1_MASK	0x00040000
#define RAS1_TREF_GET_TE1(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_TE1_MASK) >> RAS1_TREF_TE1_SHIFT)
#define RAS1_TREF_SET_TE1(ras1_tref, te1) { \
	FDL_ASSERT(!((te1) & ~((1 << RAS1_TREF_TE1_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_TE1_MASK) | (((unsigned long)(te1)) << RAS1_TREF_TE1_SHIFT);\
}
#define RAS1_TREF_CC1_SIZE	3
#define RAS1_TREF_CC1_SHIFT	19
#define RAS1_TREF_CC1_MASK	0x00380000
#define RAS1_TREF_GET_CC1(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_CC1_MASK) >> RAS1_TREF_CC1_SHIFT)
#define RAS1_TREF_SET_CC1(ras1_tref, cc1) { \
	FDL_ASSERT(!((cc1) & ~((1 << RAS1_TREF_CC1_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_CC1_MASK) | (((unsigned long)(cc1)) << RAS1_TREF_CC1_SHIFT);\
}
#define RAS1_TREF_PAD1_SIZE	2
#define RAS1_TREF_PAD1_SHIFT	22
#define RAS1_TREF_PAD1_MASK	0x00c00000
#define RAS1_TREF_GET_PAD1(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_PAD1_MASK) >> RAS1_TREF_PAD1_SHIFT)
#define RAS1_TREF_SET_PAD1(ras1_tref, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << RAS1_TREF_PAD1_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_PAD1_MASK) | (((unsigned long)(pad1)) << RAS1_TREF_PAD1_SHIFT);\
}
#define RAS1_TREF_RID_SIZE	8
#define RAS1_TREF_RID_SHIFT	24
#define RAS1_TREF_RID_MASK	0xff000000
#define RAS1_TREF_GET_RID(ras1_tref) \
	((((unsigned long)(ras1_tref)) & RAS1_TREF_RID_MASK) >> RAS1_TREF_RID_SHIFT)
#define RAS1_TREF_SET_RID(ras1_tref, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << RAS1_TREF_RID_SIZE)-1))); \
	ras1_tref = (((unsigned long)(ras1_tref)) & ~RAS1_TREF_RID_MASK) | (((unsigned long)(rid)) << RAS1_TREF_RID_SHIFT);\
}
#define RAS1_TREF_TOTAL_SIZE	32
#define RAS1_TREF(ti0, tc0, te0, cc0, ti1, tc1, te1, cc1, rid) \
	((((unsigned long)(ti0)) << RAS1_TREF_TI0_SHIFT) | \
	 (((unsigned long)(tc0)) << RAS1_TREF_TC0_SHIFT) | \
	 (((unsigned long)(te0)) << RAS1_TREF_TE0_SHIFT) | \
	 (((unsigned long)(cc0)) << RAS1_TREF_CC0_SHIFT) | \
	 (((unsigned long)(ti1)) << RAS1_TREF_TI1_SHIFT) | \
	 (((unsigned long)(tc1)) << RAS1_TREF_TC1_SHIFT) | \
	 (((unsigned long)(te1)) << RAS1_TREF_TE1_SHIFT) | \
	 (((unsigned long)(cc1)) << RAS1_TREF_CC1_SHIFT) | \
	 (((unsigned long)(rid)) << RAS1_TREF_RID_SHIFT))

typedef struct {
    unsigned long rid:RAS1_TREF_RID_SIZE;
    unsigned long pad1:RAS1_TREF_PAD1_SIZE;
    unsigned long cc1:RAS1_TREF_CC1_SIZE;
    unsigned long te1:RAS1_TREF_TE1_SIZE;
    unsigned long tc1:RAS1_TREF_TC1_SIZE;
    unsigned long ti1:RAS1_TREF_TI1_SIZE;
    unsigned long pad0:RAS1_TREF_PAD0_SIZE;
    unsigned long cc0:RAS1_TREF_CC0_SIZE;
    unsigned long te0:RAS1_TREF_TE0_SIZE;
    unsigned long tc0:RAS1_TREF_TC0_SIZE;
    unsigned long ti0:RAS1_TREF_TI0_SIZE;
} ras1_tref_t;

typedef union {
    unsigned long val;
    ras1_tref_t f;
} ras1_tref_u;

/*
 *  ras_perf struct
 */
#define RAS_PERF_SELA_SIZE	5
#define RAS_PERF_SELA_SHIFT	0
#define RAS_PERF_SELA_MASK	0x0000001f
#define RAS_PERF_GET_SELA(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_SELA_MASK) >> RAS_PERF_SELA_SHIFT)
#define RAS_PERF_SET_SELA(ras_perf, selA) { \
	FDL_ASSERT(!((selA) & ~((1 << RAS_PERF_SELA_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_SELA_MASK) | (((unsigned long)(selA)) << RAS_PERF_SELA_SHIFT);\
}
#define RAS_PERF_SELB_SIZE	5
#define RAS_PERF_SELB_SHIFT	5
#define RAS_PERF_SELB_MASK	0x000003e0
#define RAS_PERF_GET_SELB(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_SELB_MASK) >> RAS_PERF_SELB_SHIFT)
#define RAS_PERF_SET_SELB(ras_perf, selB) { \
	FDL_ASSERT(!((selB) & ~((1 << RAS_PERF_SELB_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_SELB_MASK) | (((unsigned long)(selB)) << RAS_PERF_SELB_SHIFT);\
}
#define RAS_PERF_NTEV_SIZE	5
#define RAS_PERF_NTEV_SHIFT	10
#define RAS_PERF_NTEV_MASK	0x00007c00
#define RAS_PERF_GET_NTEV(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_NTEV_MASK) >> RAS_PERF_NTEV_SHIFT)
#define RAS_PERF_SET_NTEV(ras_perf, ntev) { \
	FDL_ASSERT(!((ntev) & ~((1 << RAS_PERF_NTEV_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_NTEV_MASK) | (((unsigned long)(ntev)) << RAS_PERF_NTEV_SHIFT);\
}
#define RAS_PERF_NBMP_SIZE	3
#define RAS_PERF_NBMP_SHIFT	15
#define RAS_PERF_NBMP_MASK	0x00038000
#define RAS_PERF_GET_NBMP(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_NBMP_MASK) >> RAS_PERF_NBMP_SHIFT)
#define RAS_PERF_SET_NBMP(ras_perf, nbmp) { \
	FDL_ASSERT(!((nbmp) & ~((1 << RAS_PERF_NBMP_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_NBMP_MASK) | (((unsigned long)(nbmp)) << RAS_PERF_NBMP_SHIFT);\
}
#define RAS_PERF_NBR_SIZE	3
#define RAS_PERF_NBR_SHIFT	18
#define RAS_PERF_NBR_MASK	0x001c0000
#define RAS_PERF_GET_NBR(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_NBR_MASK) >> RAS_PERF_NBR_SHIFT)
#define RAS_PERF_SET_NBR(ras_perf, nbr) { \
	FDL_ASSERT(!((nbr) & ~((1 << RAS_PERF_NBR_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_NBR_MASK) | (((unsigned long)(nbr)) << RAS_PERF_NBR_SHIFT);\
}
#define RAS_PERF_PAD0_SIZE	3
#define RAS_PERF_PAD0_SHIFT	21
#define RAS_PERF_PAD0_MASK	0x00e00000
#define RAS_PERF_GET_PAD0(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_PAD0_MASK) >> RAS_PERF_PAD0_SHIFT)
#define RAS_PERF_SET_PAD0(ras_perf, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << RAS_PERF_PAD0_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_PAD0_MASK) | (((unsigned long)(pad0)) << RAS_PERF_PAD0_SHIFT);\
}
#define RAS_PERF_RID_SIZE	8
#define RAS_PERF_RID_SHIFT	24
#define RAS_PERF_RID_MASK	0xff000000
#define RAS_PERF_GET_RID(ras_perf) \
	((((unsigned long)(ras_perf)) & RAS_PERF_RID_MASK) >> RAS_PERF_RID_SHIFT)
#define RAS_PERF_SET_RID(ras_perf, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << RAS_PERF_RID_SIZE)-1))); \
	ras_perf = (((unsigned long)(ras_perf)) & ~RAS_PERF_RID_MASK) | (((unsigned long)(rid)) << RAS_PERF_RID_SHIFT);\
}
#define RAS_PERF_TOTAL_SIZE	32
#define RAS_PERF(selA, selB, ntev, nbmp, nbr, rid) \
	((((unsigned long)(selA)) << RAS_PERF_SELA_SHIFT) | \
	 (((unsigned long)(selB)) << RAS_PERF_SELB_SHIFT) | \
	 (((unsigned long)(ntev)) << RAS_PERF_NTEV_SHIFT) | \
	 (((unsigned long)(nbmp)) << RAS_PERF_NBMP_SHIFT) | \
	 (((unsigned long)(nbr)) << RAS_PERF_NBR_SHIFT) | \
	 (((unsigned long)(rid)) << RAS_PERF_RID_SHIFT))

typedef struct {
    unsigned long rid:RAS_PERF_RID_SIZE;
    unsigned long pad0:RAS_PERF_PAD0_SIZE;
    unsigned long nbr:RAS_PERF_NBR_SIZE;
    unsigned long nbmp:RAS_PERF_NBMP_SIZE;
    unsigned long ntev:RAS_PERF_NTEV_SIZE;
    unsigned long selB:RAS_PERF_SELB_SIZE;
    unsigned long selA:RAS_PERF_SELA_SIZE;
} ras_perf_t;

typedef union {
    unsigned long val;
    ras_perf_t f;
} ras_perf_u;


#endif /* __RAS_REG_H__ */
