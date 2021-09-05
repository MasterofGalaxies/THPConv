/*
 *  su_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from su_reg.fdl
 */

#ifndef __SU_REG_H__
#define __SU_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  su_cmds enum
 */
#define SU_CMD_NOP	0x00000000
#define SU_CMD_REGISTER	0x00000001
#define SU_CMD_TSTRIP_ODD	0x00000002
#define SU_CMD_TSTRIP_EVEN	0x00000003
#define SU_CMD_TFAN	0x00000004
#define SU_CMD_POINTS	0x00000005
#define SU_CMD_LINES	0x00000006
#define SU_CMD_POLY	0x00000007
#define SU_CMD_CONT	0x00000008
#define SU_CMD_CONT_NODRAW	0x00000009
#define SU_CMDS_UNUSED_10	0x0000000a
#define SU_CMDS_UNUSED_11	0x0000000b
#define SU_CMDS_UNUSED_12	0x0000000c
#define SU_CMDS_UNUSED_13	0x0000000d
#define SU_CMDS_UNUSED_14	0x0000000e
#define SU_CMDS_UNUSED_15	0x0000000f

/*
 *  su_lptoff enum
 */
#define SU_LPTOFF_ZERO	0x00000000
#define SU_LPTOFF_1_16	0x00000001
#define SU_LPTOFF_1_8	0x00000002
#define SU_LPTOFF_1_4	0x00000003
#define SU_LPTOFF_1_2	0x00000004
#define SU_LPTOFF_ONE	0x00000005
#define SU_LPTOFF_UNUSED_6	0x00000006
#define SU_LPTOFF_UNUSED_7	0x00000007

/*
 *  su_onoff enum
 */
#define SU_ONOFF_OFF	0x00000000
#define SU_ONOFF_ON	0x00000001

/*
 *  pf_sel enum
 */
#define PF_ZERO	0x00000000
#define PF_ONE	0x00000001
#define PF_VR	0x00000002
#define PF_VLD	0x00000003
#define PF_RDY	0x00000004
#define PF_NVR	0x00000005
#define PF_REG	0x00000006
#define PF_TRI	0x00000007

/*
 *  pf_ntex enum
 */
#define PF_T0	0x00000000
#define PF_T1	0x00000001
#define PF_T2	0x00000002
#define PF_T3	0x00000003
#define PF_T4	0x00000004
#define PF_T5	0x00000005
#define PF_T6	0x00000006
#define PF_T7	0x00000007
#define PF_T8	0x00000008
#define PF_TA	0x00000009
#define PF_NTEX_UNUSED_10	0x0000000a
#define PF_NTEX_UNUSED_11	0x0000000b
#define PF_NTEX_UNUSED_12	0x0000000c
#define PF_NTEX_UNUSED_13	0x0000000d
#define PF_NTEX_UNUSED_14	0x0000000e
#define PF_NTEX_UNUSED_15	0x0000000f

/*
 *  pf_ncol enum
 */
#define PF_C0	0x00000000
#define PF_C1	0x00000001
#define PF_C2	0x00000002
#define PF_CA	0x00000003

/*
 *  pf_rejf enum
 */
#define PF_F0	0x00000000
#define PF_F1	0x00000001
#define PF_FA	0x00000002
#define PF_REJF_UNUSED_3	0x00000003

/*
 *  pf_rejs enum
 */
#define PF_S0	0x00000000
#define PF_S1	0x00000001
#define PF_SA	0x00000002
#define PF_REJS_UNUSED_3	0x00000003

/*
 *  pf_cmd enum
 */
#define PF_CMD0	0x00000000
#define PF_CMD1	0x00000001
#define PF_CMD2	0x00000002
#define PF_CMDA	0x00000003

/*
 *  pf_en enum
 */
#define PF_EIO	0x00000000
#define PF_DI	0x00000001
#define PF_DO	0x00000002
#define PF_DIO	0x00000003

/*
 *  pwr_en enum
 */
#define PS_OFF	0x00000000
#define PS_256	0x00000001
#define PS_8K	0x00000002
#define PS_256K	0x00000003

/*
 *  su_scis0 struct
 */
#define SU_SCIS0_SY0_SIZE	11
#define SU_SCIS0_SY0_SHIFT	0
#define SU_SCIS0_SY0_MASK	0x000007ff
#define SU_SCIS0_GET_SY0(su_scis0) \
	((((unsigned long)(su_scis0)) & SU_SCIS0_SY0_MASK) >> SU_SCIS0_SY0_SHIFT)
#define SU_SCIS0_SET_SY0(su_scis0, sy0) { \
	FDL_ASSERT(!((sy0) & ~((1 << SU_SCIS0_SY0_SIZE)-1))); \
	su_scis0 = (((unsigned long)(su_scis0)) & ~SU_SCIS0_SY0_MASK) | (((unsigned long)(sy0)) << SU_SCIS0_SY0_SHIFT);\
}
#define SU_SCIS0_PAD0_SIZE	1
#define SU_SCIS0_PAD0_SHIFT	11
#define SU_SCIS0_PAD0_MASK	0x00000800
#define SU_SCIS0_GET_PAD0(su_scis0) \
	((((unsigned long)(su_scis0)) & SU_SCIS0_PAD0_MASK) >> SU_SCIS0_PAD0_SHIFT)
#define SU_SCIS0_SET_PAD0(su_scis0, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_SCIS0_PAD0_SIZE)-1))); \
	su_scis0 = (((unsigned long)(su_scis0)) & ~SU_SCIS0_PAD0_MASK) | (((unsigned long)(pad0)) << SU_SCIS0_PAD0_SHIFT);\
}
#define SU_SCIS0_SX0_SIZE	11
#define SU_SCIS0_SX0_SHIFT	12
#define SU_SCIS0_SX0_MASK	0x007ff000
#define SU_SCIS0_GET_SX0(su_scis0) \
	((((unsigned long)(su_scis0)) & SU_SCIS0_SX0_MASK) >> SU_SCIS0_SX0_SHIFT)
#define SU_SCIS0_SET_SX0(su_scis0, sx0) { \
	FDL_ASSERT(!((sx0) & ~((1 << SU_SCIS0_SX0_SIZE)-1))); \
	su_scis0 = (((unsigned long)(su_scis0)) & ~SU_SCIS0_SX0_MASK) | (((unsigned long)(sx0)) << SU_SCIS0_SX0_SHIFT);\
}
#define SU_SCIS0_PAD1_SIZE	1
#define SU_SCIS0_PAD1_SHIFT	23
#define SU_SCIS0_PAD1_MASK	0x00800000
#define SU_SCIS0_GET_PAD1(su_scis0) \
	((((unsigned long)(su_scis0)) & SU_SCIS0_PAD1_MASK) >> SU_SCIS0_PAD1_SHIFT)
#define SU_SCIS0_SET_PAD1(su_scis0, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << SU_SCIS0_PAD1_SIZE)-1))); \
	su_scis0 = (((unsigned long)(su_scis0)) & ~SU_SCIS0_PAD1_MASK) | (((unsigned long)(pad1)) << SU_SCIS0_PAD1_SHIFT);\
}
#define SU_SCIS0_RID_SIZE	8
#define SU_SCIS0_RID_SHIFT	24
#define SU_SCIS0_RID_MASK	0xff000000
#define SU_SCIS0_GET_RID(su_scis0) \
	((((unsigned long)(su_scis0)) & SU_SCIS0_RID_MASK) >> SU_SCIS0_RID_SHIFT)
#define SU_SCIS0_SET_RID(su_scis0, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_SCIS0_RID_SIZE)-1))); \
	su_scis0 = (((unsigned long)(su_scis0)) & ~SU_SCIS0_RID_MASK) | (((unsigned long)(rid)) << SU_SCIS0_RID_SHIFT);\
}
#define SU_SCIS0_TOTAL_SIZE	32
#define SU_SCIS0(sy0, sx0, rid) \
	((((unsigned long)(sy0)) << SU_SCIS0_SY0_SHIFT) | \
	 (((unsigned long)(sx0)) << SU_SCIS0_SX0_SHIFT) | \
	 (((unsigned long)(rid)) << SU_SCIS0_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_SCIS0_RID_SIZE;
    unsigned long pad1:SU_SCIS0_PAD1_SIZE;
    unsigned long sx0:SU_SCIS0_SX0_SIZE;
    unsigned long pad0:SU_SCIS0_PAD0_SIZE;
    unsigned long sy0:SU_SCIS0_SY0_SIZE;
} su_scis0_t;

typedef union {
    unsigned long val;
    su_scis0_t f;
} su_scis0_u;

/*
 *  su_scis1 struct
 */
#define SU_SCIS1_SY1_SIZE	11
#define SU_SCIS1_SY1_SHIFT	0
#define SU_SCIS1_SY1_MASK	0x000007ff
#define SU_SCIS1_GET_SY1(su_scis1) \
	((((unsigned long)(su_scis1)) & SU_SCIS1_SY1_MASK) >> SU_SCIS1_SY1_SHIFT)
#define SU_SCIS1_SET_SY1(su_scis1, sy1) { \
	FDL_ASSERT(!((sy1) & ~((1 << SU_SCIS1_SY1_SIZE)-1))); \
	su_scis1 = (((unsigned long)(su_scis1)) & ~SU_SCIS1_SY1_MASK) | (((unsigned long)(sy1)) << SU_SCIS1_SY1_SHIFT);\
}
#define SU_SCIS1_PAD0_SIZE	1
#define SU_SCIS1_PAD0_SHIFT	11
#define SU_SCIS1_PAD0_MASK	0x00000800
#define SU_SCIS1_GET_PAD0(su_scis1) \
	((((unsigned long)(su_scis1)) & SU_SCIS1_PAD0_MASK) >> SU_SCIS1_PAD0_SHIFT)
#define SU_SCIS1_SET_PAD0(su_scis1, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_SCIS1_PAD0_SIZE)-1))); \
	su_scis1 = (((unsigned long)(su_scis1)) & ~SU_SCIS1_PAD0_MASK) | (((unsigned long)(pad0)) << SU_SCIS1_PAD0_SHIFT);\
}
#define SU_SCIS1_SX1_SIZE	11
#define SU_SCIS1_SX1_SHIFT	12
#define SU_SCIS1_SX1_MASK	0x007ff000
#define SU_SCIS1_GET_SX1(su_scis1) \
	((((unsigned long)(su_scis1)) & SU_SCIS1_SX1_MASK) >> SU_SCIS1_SX1_SHIFT)
#define SU_SCIS1_SET_SX1(su_scis1, sx1) { \
	FDL_ASSERT(!((sx1) & ~((1 << SU_SCIS1_SX1_SIZE)-1))); \
	su_scis1 = (((unsigned long)(su_scis1)) & ~SU_SCIS1_SX1_MASK) | (((unsigned long)(sx1)) << SU_SCIS1_SX1_SHIFT);\
}
#define SU_SCIS1_PAD1_SIZE	1
#define SU_SCIS1_PAD1_SHIFT	23
#define SU_SCIS1_PAD1_MASK	0x00800000
#define SU_SCIS1_GET_PAD1(su_scis1) \
	((((unsigned long)(su_scis1)) & SU_SCIS1_PAD1_MASK) >> SU_SCIS1_PAD1_SHIFT)
#define SU_SCIS1_SET_PAD1(su_scis1, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << SU_SCIS1_PAD1_SIZE)-1))); \
	su_scis1 = (((unsigned long)(su_scis1)) & ~SU_SCIS1_PAD1_MASK) | (((unsigned long)(pad1)) << SU_SCIS1_PAD1_SHIFT);\
}
#define SU_SCIS1_RID_SIZE	8
#define SU_SCIS1_RID_SHIFT	24
#define SU_SCIS1_RID_MASK	0xff000000
#define SU_SCIS1_GET_RID(su_scis1) \
	((((unsigned long)(su_scis1)) & SU_SCIS1_RID_MASK) >> SU_SCIS1_RID_SHIFT)
#define SU_SCIS1_SET_RID(su_scis1, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_SCIS1_RID_SIZE)-1))); \
	su_scis1 = (((unsigned long)(su_scis1)) & ~SU_SCIS1_RID_MASK) | (((unsigned long)(rid)) << SU_SCIS1_RID_SHIFT);\
}
#define SU_SCIS1_TOTAL_SIZE	32
#define SU_SCIS1(sy1, sx1, rid) \
	((((unsigned long)(sy1)) << SU_SCIS1_SY1_SHIFT) | \
	 (((unsigned long)(sx1)) << SU_SCIS1_SX1_SHIFT) | \
	 (((unsigned long)(rid)) << SU_SCIS1_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_SCIS1_RID_SIZE;
    unsigned long pad1:SU_SCIS1_PAD1_SIZE;
    unsigned long sx1:SU_SCIS1_SX1_SIZE;
    unsigned long pad0:SU_SCIS1_PAD0_SIZE;
    unsigned long sy1:SU_SCIS1_SY1_SIZE;
} su_scis1_t;

typedef union {
    unsigned long val;
    su_scis1_t f;
} su_scis1_u;

/*
 *  su_lpsize struct
 */
#define SU_LPSIZE_LSIZE_SIZE	8
#define SU_LPSIZE_LSIZE_SHIFT	0
#define SU_LPSIZE_LSIZE_MASK	0x000000ff
#define SU_LPSIZE_GET_LSIZE(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_LSIZE_MASK) >> SU_LPSIZE_LSIZE_SHIFT)
#define SU_LPSIZE_SET_LSIZE(su_lpsize, lsize) { \
	FDL_ASSERT(!((lsize) & ~((1 << SU_LPSIZE_LSIZE_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_LSIZE_MASK) | (((unsigned long)(lsize)) << SU_LPSIZE_LSIZE_SHIFT);\
}
#define SU_LPSIZE_PSIZE_SIZE	8
#define SU_LPSIZE_PSIZE_SHIFT	8
#define SU_LPSIZE_PSIZE_MASK	0x0000ff00
#define SU_LPSIZE_GET_PSIZE(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_PSIZE_MASK) >> SU_LPSIZE_PSIZE_SHIFT)
#define SU_LPSIZE_SET_PSIZE(su_lpsize, psize) { \
	FDL_ASSERT(!((psize) & ~((1 << SU_LPSIZE_PSIZE_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_PSIZE_MASK) | (((unsigned long)(psize)) << SU_LPSIZE_PSIZE_SHIFT);\
}
#define SU_LPSIZE_LTOFF_SIZE	3
#define SU_LPSIZE_LTOFF_SHIFT	16
#define SU_LPSIZE_LTOFF_MASK	0x00070000
#define SU_LPSIZE_GET_LTOFF(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_LTOFF_MASK) >> SU_LPSIZE_LTOFF_SHIFT)
#define SU_LPSIZE_SET_LTOFF(su_lpsize, ltoff) { \
	FDL_ASSERT(!((ltoff) & ~((1 << SU_LPSIZE_LTOFF_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_LTOFF_MASK) | (((unsigned long)(ltoff)) << SU_LPSIZE_LTOFF_SHIFT);\
}
#define SU_LPSIZE_PTOFF_SIZE	3
#define SU_LPSIZE_PTOFF_SHIFT	19
#define SU_LPSIZE_PTOFF_MASK	0x00380000
#define SU_LPSIZE_GET_PTOFF(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_PTOFF_MASK) >> SU_LPSIZE_PTOFF_SHIFT)
#define SU_LPSIZE_SET_PTOFF(su_lpsize, ptoff) { \
	FDL_ASSERT(!((ptoff) & ~((1 << SU_LPSIZE_PTOFF_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_PTOFF_MASK) | (((unsigned long)(ptoff)) << SU_LPSIZE_PTOFF_SHIFT);\
}
#define SU_LPSIZE_FIELDMODE_SIZE	1
#define SU_LPSIZE_FIELDMODE_SHIFT	22
#define SU_LPSIZE_FIELDMODE_MASK	0x00400000
#define SU_LPSIZE_GET_FIELDMODE(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_FIELDMODE_MASK) >> SU_LPSIZE_FIELDMODE_SHIFT)
#define SU_LPSIZE_SET_FIELDMODE(su_lpsize, fieldmode) { \
	FDL_ASSERT(!((fieldmode) & ~((1 << SU_LPSIZE_FIELDMODE_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_FIELDMODE_MASK) | (((unsigned long)(fieldmode)) << SU_LPSIZE_FIELDMODE_SHIFT);\
}
#define SU_LPSIZE_PAD0_SIZE	1
#define SU_LPSIZE_PAD0_SHIFT	23
#define SU_LPSIZE_PAD0_MASK	0x00800000
#define SU_LPSIZE_GET_PAD0(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_PAD0_MASK) >> SU_LPSIZE_PAD0_SHIFT)
#define SU_LPSIZE_SET_PAD0(su_lpsize, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_LPSIZE_PAD0_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_PAD0_MASK) | (((unsigned long)(pad0)) << SU_LPSIZE_PAD0_SHIFT);\
}
#define SU_LPSIZE_RID_SIZE	8
#define SU_LPSIZE_RID_SHIFT	24
#define SU_LPSIZE_RID_MASK	0xff000000
#define SU_LPSIZE_GET_RID(su_lpsize) \
	((((unsigned long)(su_lpsize)) & SU_LPSIZE_RID_MASK) >> SU_LPSIZE_RID_SHIFT)
#define SU_LPSIZE_SET_RID(su_lpsize, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_LPSIZE_RID_SIZE)-1))); \
	su_lpsize = (((unsigned long)(su_lpsize)) & ~SU_LPSIZE_RID_MASK) | (((unsigned long)(rid)) << SU_LPSIZE_RID_SHIFT);\
}
#define SU_LPSIZE_TOTAL_SIZE	32
#define SU_LPSIZE(lsize, psize, ltoff, ptoff, fieldmode, rid) \
	((((unsigned long)(lsize)) << SU_LPSIZE_LSIZE_SHIFT) | \
	 (((unsigned long)(psize)) << SU_LPSIZE_PSIZE_SHIFT) | \
	 (((unsigned long)(ltoff)) << SU_LPSIZE_LTOFF_SHIFT) | \
	 (((unsigned long)(ptoff)) << SU_LPSIZE_PTOFF_SHIFT) | \
	 (((unsigned long)(fieldmode)) << SU_LPSIZE_FIELDMODE_SHIFT) | \
	 (((unsigned long)(rid)) << SU_LPSIZE_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_LPSIZE_RID_SIZE;
    unsigned long pad0:SU_LPSIZE_PAD0_SIZE;
    unsigned long fieldmode:SU_LPSIZE_FIELDMODE_SIZE;
    unsigned long ptoff:SU_LPSIZE_PTOFF_SIZE;
    unsigned long ltoff:SU_LPSIZE_LTOFF_SIZE;
    unsigned long psize:SU_LPSIZE_PSIZE_SIZE;
    unsigned long lsize:SU_LPSIZE_LSIZE_SIZE;
} su_lpsize_t;

typedef union {
    unsigned long val;
    su_lpsize_t f;
} su_lpsize_u;

/*
 *  su_ts0 struct
 */
#define SU_TS0_SSIZE_SIZE	16
#define SU_TS0_SSIZE_SHIFT	0
#define SU_TS0_SSIZE_MASK	0x0000ffff
#define SU_TS0_GET_SSIZE(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_SSIZE_MASK) >> SU_TS0_SSIZE_SHIFT)
#define SU_TS0_SET_SSIZE(su_ts0, ssize) { \
	FDL_ASSERT(!((ssize) & ~((1 << SU_TS0_SSIZE_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_SSIZE_MASK) | (((unsigned long)(ssize)) << SU_TS0_SSIZE_SHIFT);\
}
#define SU_TS0_BS_SIZE	1
#define SU_TS0_BS_SHIFT	16
#define SU_TS0_BS_MASK	0x00010000
#define SU_TS0_GET_BS(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_BS_MASK) >> SU_TS0_BS_SHIFT)
#define SU_TS0_SET_BS(su_ts0, bs) { \
	FDL_ASSERT(!((bs) & ~((1 << SU_TS0_BS_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_BS_MASK) | (((unsigned long)(bs)) << SU_TS0_BS_SHIFT);\
}
#define SU_TS0_WS_SIZE	1
#define SU_TS0_WS_SHIFT	17
#define SU_TS0_WS_MASK	0x00020000
#define SU_TS0_GET_WS(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_WS_MASK) >> SU_TS0_WS_SHIFT)
#define SU_TS0_SET_WS(su_ts0, ws) { \
	FDL_ASSERT(!((ws) & ~((1 << SU_TS0_WS_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_WS_MASK) | (((unsigned long)(ws)) << SU_TS0_WS_SHIFT);\
}
#define SU_TS0_LF_SIZE	1
#define SU_TS0_LF_SHIFT	18
#define SU_TS0_LF_MASK	0x00040000
#define SU_TS0_GET_LF(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_LF_MASK) >> SU_TS0_LF_SHIFT)
#define SU_TS0_SET_LF(su_ts0, lf) { \
	FDL_ASSERT(!((lf) & ~((1 << SU_TS0_LF_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_LF_MASK) | (((unsigned long)(lf)) << SU_TS0_LF_SHIFT);\
}
#define SU_TS0_PF_SIZE	1
#define SU_TS0_PF_SHIFT	19
#define SU_TS0_PF_MASK	0x00080000
#define SU_TS0_GET_PF(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_PF_MASK) >> SU_TS0_PF_SHIFT)
#define SU_TS0_SET_PF(su_ts0, pf) { \
	FDL_ASSERT(!((pf) & ~((1 << SU_TS0_PF_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_PF_MASK) | (((unsigned long)(pf)) << SU_TS0_PF_SHIFT);\
}
#define SU_TS0_PAD0_SIZE	4
#define SU_TS0_PAD0_SHIFT	20
#define SU_TS0_PAD0_MASK	0x00f00000
#define SU_TS0_GET_PAD0(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_PAD0_MASK) >> SU_TS0_PAD0_SHIFT)
#define SU_TS0_SET_PAD0(su_ts0, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_TS0_PAD0_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_PAD0_MASK) | (((unsigned long)(pad0)) << SU_TS0_PAD0_SHIFT);\
}
#define SU_TS0_RID_SIZE	8
#define SU_TS0_RID_SHIFT	24
#define SU_TS0_RID_MASK	0xff000000
#define SU_TS0_GET_RID(su_ts0) \
	((((unsigned long)(su_ts0)) & SU_TS0_RID_MASK) >> SU_TS0_RID_SHIFT)
#define SU_TS0_SET_RID(su_ts0, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_TS0_RID_SIZE)-1))); \
	su_ts0 = (((unsigned long)(su_ts0)) & ~SU_TS0_RID_MASK) | (((unsigned long)(rid)) << SU_TS0_RID_SHIFT);\
}
#define SU_TS0_TOTAL_SIZE	32
#define SU_TS0(ssize, bs, ws, lf, pf, rid) \
	((((unsigned long)(ssize)) << SU_TS0_SSIZE_SHIFT) | \
	 (((unsigned long)(bs)) << SU_TS0_BS_SHIFT) | \
	 (((unsigned long)(ws)) << SU_TS0_WS_SHIFT) | \
	 (((unsigned long)(lf)) << SU_TS0_LF_SHIFT) | \
	 (((unsigned long)(pf)) << SU_TS0_PF_SHIFT) | \
	 (((unsigned long)(rid)) << SU_TS0_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_TS0_RID_SIZE;
    unsigned long pad0:SU_TS0_PAD0_SIZE;
    unsigned long pf:SU_TS0_PF_SIZE;
    unsigned long lf:SU_TS0_LF_SIZE;
    unsigned long ws:SU_TS0_WS_SIZE;
    unsigned long bs:SU_TS0_BS_SIZE;
    unsigned long ssize:SU_TS0_SSIZE_SIZE;
} su_ts0_t;

typedef union {
    unsigned long val;
    su_ts0_t f;
} su_ts0_u;

/*
 *  su_ts1 struct
 */
#define SU_TS1_TSIZE_SIZE	16
#define SU_TS1_TSIZE_SHIFT	0
#define SU_TS1_TSIZE_MASK	0x0000ffff
#define SU_TS1_GET_TSIZE(su_ts1) \
	((((unsigned long)(su_ts1)) & SU_TS1_TSIZE_MASK) >> SU_TS1_TSIZE_SHIFT)
#define SU_TS1_SET_TSIZE(su_ts1, tsize) { \
	FDL_ASSERT(!((tsize) & ~((1 << SU_TS1_TSIZE_SIZE)-1))); \
	su_ts1 = (((unsigned long)(su_ts1)) & ~SU_TS1_TSIZE_MASK) | (((unsigned long)(tsize)) << SU_TS1_TSIZE_SHIFT);\
}
#define SU_TS1_BT_SIZE	1
#define SU_TS1_BT_SHIFT	16
#define SU_TS1_BT_MASK	0x00010000
#define SU_TS1_GET_BT(su_ts1) \
	((((unsigned long)(su_ts1)) & SU_TS1_BT_MASK) >> SU_TS1_BT_SHIFT)
#define SU_TS1_SET_BT(su_ts1, bt) { \
	FDL_ASSERT(!((bt) & ~((1 << SU_TS1_BT_SIZE)-1))); \
	su_ts1 = (((unsigned long)(su_ts1)) & ~SU_TS1_BT_MASK) | (((unsigned long)(bt)) << SU_TS1_BT_SHIFT);\
}
#define SU_TS1_WT_SIZE	1
#define SU_TS1_WT_SHIFT	17
#define SU_TS1_WT_MASK	0x00020000
#define SU_TS1_GET_WT(su_ts1) \
	((((unsigned long)(su_ts1)) & SU_TS1_WT_MASK) >> SU_TS1_WT_SHIFT)
#define SU_TS1_SET_WT(su_ts1, wt) { \
	FDL_ASSERT(!((wt) & ~((1 << SU_TS1_WT_SIZE)-1))); \
	su_ts1 = (((unsigned long)(su_ts1)) & ~SU_TS1_WT_MASK) | (((unsigned long)(wt)) << SU_TS1_WT_SHIFT);\
}
#define SU_TS1_PAD0_SIZE	6
#define SU_TS1_PAD0_SHIFT	18
#define SU_TS1_PAD0_MASK	0x00fc0000
#define SU_TS1_GET_PAD0(su_ts1) \
	((((unsigned long)(su_ts1)) & SU_TS1_PAD0_MASK) >> SU_TS1_PAD0_SHIFT)
#define SU_TS1_SET_PAD0(su_ts1, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_TS1_PAD0_SIZE)-1))); \
	su_ts1 = (((unsigned long)(su_ts1)) & ~SU_TS1_PAD0_MASK) | (((unsigned long)(pad0)) << SU_TS1_PAD0_SHIFT);\
}
#define SU_TS1_RID_SIZE	8
#define SU_TS1_RID_SHIFT	24
#define SU_TS1_RID_MASK	0xff000000
#define SU_TS1_GET_RID(su_ts1) \
	((((unsigned long)(su_ts1)) & SU_TS1_RID_MASK) >> SU_TS1_RID_SHIFT)
#define SU_TS1_SET_RID(su_ts1, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_TS1_RID_SIZE)-1))); \
	su_ts1 = (((unsigned long)(su_ts1)) & ~SU_TS1_RID_MASK) | (((unsigned long)(rid)) << SU_TS1_RID_SHIFT);\
}
#define SU_TS1_TOTAL_SIZE	32
#define SU_TS1(tsize, bt, wt, rid) \
	((((unsigned long)(tsize)) << SU_TS1_TSIZE_SHIFT) | \
	 (((unsigned long)(bt)) << SU_TS1_BT_SHIFT) | \
	 (((unsigned long)(wt)) << SU_TS1_WT_SHIFT) | \
	 (((unsigned long)(rid)) << SU_TS1_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_TS1_RID_SIZE;
    unsigned long pad0:SU_TS1_PAD0_SIZE;
    unsigned long wt:SU_TS1_WT_SIZE;
    unsigned long bt:SU_TS1_BT_SIZE;
    unsigned long tsize:SU_TS1_TSIZE_SIZE;
} su_ts1_t;

typedef union {
    unsigned long val;
    su_ts1_t f;
} su_ts1_u;

/*
 *  su_perf struct
 */
#define SU_PERF_SELA_SIZE	3
#define SU_PERF_SELA_SHIFT	0
#define SU_PERF_SELA_MASK	0x00000007
#define SU_PERF_GET_SELA(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_SELA_MASK) >> SU_PERF_SELA_SHIFT)
#define SU_PERF_SET_SELA(su_perf, selA) { \
	FDL_ASSERT(!((selA) & ~((1 << SU_PERF_SELA_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_SELA_MASK) | (((unsigned long)(selA)) << SU_PERF_SELA_SHIFT);\
}
#define SU_PERF_SELB_SIZE	3
#define SU_PERF_SELB_SHIFT	3
#define SU_PERF_SELB_MASK	0x00000038
#define SU_PERF_GET_SELB(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_SELB_MASK) >> SU_PERF_SELB_SHIFT)
#define SU_PERF_SET_SELB(su_perf, selB) { \
	FDL_ASSERT(!((selB) & ~((1 << SU_PERF_SELB_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_SELB_MASK) | (((unsigned long)(selB)) << SU_PERF_SELB_SHIFT);\
}
#define SU_PERF_NTEX_SIZE	4
#define SU_PERF_NTEX_SHIFT	6
#define SU_PERF_NTEX_MASK	0x000003c0
#define SU_PERF_GET_NTEX(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_NTEX_MASK) >> SU_PERF_NTEX_SHIFT)
#define SU_PERF_SET_NTEX(su_perf, ntex) { \
	FDL_ASSERT(!((ntex) & ~((1 << SU_PERF_NTEX_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_NTEX_MASK) | (((unsigned long)(ntex)) << SU_PERF_NTEX_SHIFT);\
}
#define SU_PERF_NCOL_SIZE	2
#define SU_PERF_NCOL_SHIFT	10
#define SU_PERF_NCOL_MASK	0x00000c00
#define SU_PERF_GET_NCOL(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_NCOL_MASK) >> SU_PERF_NCOL_SHIFT)
#define SU_PERF_SET_NCOL(su_perf, ncol) { \
	FDL_ASSERT(!((ncol) & ~((1 << SU_PERF_NCOL_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_NCOL_MASK) | (((unsigned long)(ncol)) << SU_PERF_NCOL_SHIFT);\
}
#define SU_PERF_REJF_SIZE	2
#define SU_PERF_REJF_SHIFT	12
#define SU_PERF_REJF_MASK	0x00003000
#define SU_PERF_GET_REJF(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_REJF_MASK) >> SU_PERF_REJF_SHIFT)
#define SU_PERF_SET_REJF(su_perf, rejf) { \
	FDL_ASSERT(!((rejf) & ~((1 << SU_PERF_REJF_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_REJF_MASK) | (((unsigned long)(rejf)) << SU_PERF_REJF_SHIFT);\
}
#define SU_PERF_REJS_SIZE	2
#define SU_PERF_REJS_SHIFT	14
#define SU_PERF_REJS_MASK	0x0000c000
#define SU_PERF_GET_REJS(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_REJS_MASK) >> SU_PERF_REJS_SHIFT)
#define SU_PERF_SET_REJS(su_perf, rejs) { \
	FDL_ASSERT(!((rejs) & ~((1 << SU_PERF_REJS_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_REJS_MASK) | (((unsigned long)(rejs)) << SU_PERF_REJS_SHIFT);\
}
#define SU_PERF_CMD_SIZE	2
#define SU_PERF_CMD_SHIFT	16
#define SU_PERF_CMD_MASK	0x00030000
#define SU_PERF_GET_CMD(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_CMD_MASK) >> SU_PERF_CMD_SHIFT)
#define SU_PERF_SET_CMD(su_perf, cmd) { \
	FDL_ASSERT(!((cmd) & ~((1 << SU_PERF_CMD_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_CMD_MASK) | (((unsigned long)(cmd)) << SU_PERF_CMD_SHIFT);\
}
#define SU_PERF_PAD0_SIZE	2
#define SU_PERF_PAD0_SHIFT	18
#define SU_PERF_PAD0_MASK	0x000c0000
#define SU_PERF_GET_PAD0(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_PAD0_MASK) >> SU_PERF_PAD0_SHIFT)
#define SU_PERF_SET_PAD0(su_perf, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << SU_PERF_PAD0_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_PAD0_MASK) | (((unsigned long)(pad0)) << SU_PERF_PAD0_SHIFT);\
}
#define SU_PERF_EN_SIZE	2
#define SU_PERF_EN_SHIFT	20
#define SU_PERF_EN_MASK	0x00300000
#define SU_PERF_GET_EN(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_EN_MASK) >> SU_PERF_EN_SHIFT)
#define SU_PERF_SET_EN(su_perf, en) { \
	FDL_ASSERT(!((en) & ~((1 << SU_PERF_EN_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_EN_MASK) | (((unsigned long)(en)) << SU_PERF_EN_SHIFT);\
}
#define SU_PERF_PWR_EN_SIZE	2
#define SU_PERF_PWR_EN_SHIFT	22
#define SU_PERF_PWR_EN_MASK	0x00c00000
#define SU_PERF_GET_PWR_EN(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_PWR_EN_MASK) >> SU_PERF_PWR_EN_SHIFT)
#define SU_PERF_SET_PWR_EN(su_perf, pwr_en) { \
	FDL_ASSERT(!((pwr_en) & ~((1 << SU_PERF_PWR_EN_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_PWR_EN_MASK) | (((unsigned long)(pwr_en)) << SU_PERF_PWR_EN_SHIFT);\
}
#define SU_PERF_RID_SIZE	8
#define SU_PERF_RID_SHIFT	24
#define SU_PERF_RID_MASK	0xff000000
#define SU_PERF_GET_RID(su_perf) \
	((((unsigned long)(su_perf)) & SU_PERF_RID_MASK) >> SU_PERF_RID_SHIFT)
#define SU_PERF_SET_RID(su_perf, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_PERF_RID_SIZE)-1))); \
	su_perf = (((unsigned long)(su_perf)) & ~SU_PERF_RID_MASK) | (((unsigned long)(rid)) << SU_PERF_RID_SHIFT);\
}
#define SU_PERF_TOTAL_SIZE	32
#define SU_PERF(selA, selB, ntex, ncol, rejf, rejs, cmd, en, pwr_en, rid) \
	((((unsigned long)(selA)) << SU_PERF_SELA_SHIFT) | \
	 (((unsigned long)(selB)) << SU_PERF_SELB_SHIFT) | \
	 (((unsigned long)(ntex)) << SU_PERF_NTEX_SHIFT) | \
	 (((unsigned long)(ncol)) << SU_PERF_NCOL_SHIFT) | \
	 (((unsigned long)(rejf)) << SU_PERF_REJF_SHIFT) | \
	 (((unsigned long)(rejs)) << SU_PERF_REJS_SHIFT) | \
	 (((unsigned long)(cmd)) << SU_PERF_CMD_SHIFT) | \
	 (((unsigned long)(en)) << SU_PERF_EN_SHIFT) | \
	 (((unsigned long)(pwr_en)) << SU_PERF_PWR_EN_SHIFT) | \
	 (((unsigned long)(rid)) << SU_PERF_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_PERF_RID_SIZE;
    unsigned long pwr_en:SU_PERF_PWR_EN_SIZE;
    unsigned long en:SU_PERF_EN_SIZE;
    unsigned long pad0:SU_PERF_PAD0_SIZE;
    unsigned long cmd:SU_PERF_CMD_SIZE;
    unsigned long rejs:SU_PERF_REJS_SIZE;
    unsigned long rejf:SU_PERF_REJF_SIZE;
    unsigned long ncol:SU_PERF_NCOL_SIZE;
    unsigned long ntex:SU_PERF_NTEX_SIZE;
    unsigned long selB:SU_PERF_SELB_SIZE;
    unsigned long selA:SU_PERF_SELA_SIZE;
} su_perf_t;

typedef union {
    unsigned long val;
    su_perf_t f;
} su_perf_u;

/*
 *  su_ssmasks_val value
 */
#define SU_SSMASK_OFF	0x555555
#define SU_SSMASK_ON	0xaaaaaa

/*
 *  su_ssmask struct
 */
#define SU_SSMASK_SSMASK_SIZE	24
#define SU_SSMASK_SSMASK_SHIFT	0
#define SU_SSMASK_SSMASK_MASK	0x00ffffff
#define SU_SSMASK_GET_SSMASK(su_ssmask) \
	((((unsigned long)(su_ssmask)) & SU_SSMASK_SSMASK_MASK) >> SU_SSMASK_SSMASK_SHIFT)
#define SU_SSMASK_SET_SSMASK(su_ssmask, ssmask) { \
	FDL_ASSERT(!((ssmask) & ~((1 << SU_SSMASK_SSMASK_SIZE)-1))); \
	su_ssmask = (((unsigned long)(su_ssmask)) & ~SU_SSMASK_SSMASK_MASK) | (((unsigned long)(ssmask)) << SU_SSMASK_SSMASK_SHIFT);\
}
#define SU_SSMASK_RID_SIZE	8
#define SU_SSMASK_RID_SHIFT	24
#define SU_SSMASK_RID_MASK	0xff000000
#define SU_SSMASK_GET_RID(su_ssmask) \
	((((unsigned long)(su_ssmask)) & SU_SSMASK_RID_MASK) >> SU_SSMASK_RID_SHIFT)
#define SU_SSMASK_SET_RID(su_ssmask, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << SU_SSMASK_RID_SIZE)-1))); \
	su_ssmask = (((unsigned long)(su_ssmask)) & ~SU_SSMASK_RID_MASK) | (((unsigned long)(rid)) << SU_SSMASK_RID_SHIFT);\
}
#define SU_SSMASK_TOTAL_SIZE	32
#define SU_SSMASK(ssmask, rid) \
	((((unsigned long)(ssmask)) << SU_SSMASK_SSMASK_SHIFT) | \
	 (((unsigned long)(rid)) << SU_SSMASK_RID_SHIFT))

typedef struct {
    unsigned long rid:SU_SSMASK_RID_SIZE;
    unsigned long ssmask:SU_SSMASK_SSMASK_SIZE;
} su_ssmask_t;

typedef union {
    unsigned long val;
    su_ssmask_t f;
} su_ssmask_u;


#endif /* __SU_REG_H__ */
