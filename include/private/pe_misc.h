/*
 *  pe_misc.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from pe_misc.fdl
 */

#ifndef __PE_MISC_H__
#define __PE_MISC_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  pe_misc struct
 */
#define PE_MISC_V0_SIZE	1
#define PE_MISC_V0_SHIFT	0
#define PE_MISC_V0_MASK	0x00000001
#define PE_MISC_GET_V0(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_V0_MASK) >> PE_MISC_V0_SHIFT)
#define PE_MISC_SET_V0(pe_misc, v0) { \
	FDL_ASSERT(!((v0) & ~((1 << PE_MISC_V0_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_V0_MASK) | (((unsigned long)(v0)) << PE_MISC_V0_SHIFT);\
}
#define PE_MISC_V1_SIZE	1
#define PE_MISC_V1_SHIFT	1
#define PE_MISC_V1_MASK	0x00000002
#define PE_MISC_GET_V1(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_V1_MASK) >> PE_MISC_V1_SHIFT)
#define PE_MISC_SET_V1(pe_misc, v1) { \
	FDL_ASSERT(!((v1) & ~((1 << PE_MISC_V1_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_V1_MASK) | (((unsigned long)(v1)) << PE_MISC_V1_SHIFT);\
}
#define PE_MISC_V2_SIZE	1
#define PE_MISC_V2_SHIFT	2
#define PE_MISC_V2_MASK	0x00000004
#define PE_MISC_GET_V2(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_V2_MASK) >> PE_MISC_V2_SHIFT)
#define PE_MISC_SET_V2(pe_misc, v2) { \
	FDL_ASSERT(!((v2) & ~((1 << PE_MISC_V2_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_V2_MASK) | (((unsigned long)(v2)) << PE_MISC_V2_SHIFT);\
}
#define PE_MISC_V3_SIZE	1
#define PE_MISC_V3_SHIFT	3
#define PE_MISC_V3_MASK	0x00000008
#define PE_MISC_GET_V3(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_V3_MASK) >> PE_MISC_V3_SHIFT)
#define PE_MISC_SET_V3(pe_misc, v3) { \
	FDL_ASSERT(!((v3) & ~((1 << PE_MISC_V3_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_V3_MASK) | (((unsigned long)(v3)) << PE_MISC_V3_SHIFT);\
}
#define PE_MISC_ST_SIZE	1
#define PE_MISC_ST_SHIFT	4
#define PE_MISC_ST_MASK	0x00000010
#define PE_MISC_GET_ST(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_ST_MASK) >> PE_MISC_ST_SHIFT)
#define PE_MISC_SET_ST(pe_misc, st) { \
	FDL_ASSERT(!((st) & ~((1 << PE_MISC_ST_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_ST_MASK) | (((unsigned long)(st)) << PE_MISC_ST_SHIFT);\
}
#define PE_MISC_SB_SIZE	1
#define PE_MISC_SB_SHIFT	5
#define PE_MISC_SB_MASK	0x00000020
#define PE_MISC_GET_SB(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_SB_MASK) >> PE_MISC_SB_SHIFT)
#define PE_MISC_SET_SB(pe_misc, sb) { \
	FDL_ASSERT(!((sb) & ~((1 << PE_MISC_SB_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_SB_MASK) | (((unsigned long)(sb)) << PE_MISC_SB_SHIFT);\
}
#define PE_MISC_SL_SIZE	1
#define PE_MISC_SL_SHIFT	6
#define PE_MISC_SL_MASK	0x00000040
#define PE_MISC_GET_SL(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_SL_MASK) >> PE_MISC_SL_SHIFT)
#define PE_MISC_SET_SL(pe_misc, sl) { \
	FDL_ASSERT(!((sl) & ~((1 << PE_MISC_SL_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_SL_MASK) | (((unsigned long)(sl)) << PE_MISC_SL_SHIFT);\
}
#define PE_MISC_SR_SIZE	1
#define PE_MISC_SR_SHIFT	7
#define PE_MISC_SR_MASK	0x00000080
#define PE_MISC_GET_SR(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_SR_MASK) >> PE_MISC_SR_SHIFT)
#define PE_MISC_SET_SR(pe_misc, sr) { \
	FDL_ASSERT(!((sr) & ~((1 << PE_MISC_SR_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_SR_MASK) | (((unsigned long)(sr)) << PE_MISC_SR_SHIFT);\
}
#define PE_MISC_TT_SIZE	1
#define PE_MISC_TT_SHIFT	8
#define PE_MISC_TT_MASK	0x00000100
#define PE_MISC_GET_TT(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TT_MASK) >> PE_MISC_TT_SHIFT)
#define PE_MISC_SET_TT(pe_misc, tt) { \
	FDL_ASSERT(!((tt) & ~((1 << PE_MISC_TT_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TT_MASK) | (((unsigned long)(tt)) << PE_MISC_TT_SHIFT);\
}
#define PE_MISC_TB_SIZE	1
#define PE_MISC_TB_SHIFT	9
#define PE_MISC_TB_MASK	0x00000200
#define PE_MISC_GET_TB(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TB_MASK) >> PE_MISC_TB_SHIFT)
#define PE_MISC_SET_TB(pe_misc, tb) { \
	FDL_ASSERT(!((tb) & ~((1 << PE_MISC_TB_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TB_MASK) | (((unsigned long)(tb)) << PE_MISC_TB_SHIFT);\
}
#define PE_MISC_TL_SIZE	1
#define PE_MISC_TL_SHIFT	10
#define PE_MISC_TL_MASK	0x00000400
#define PE_MISC_GET_TL(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TL_MASK) >> PE_MISC_TL_SHIFT)
#define PE_MISC_SET_TL(pe_misc, tl) { \
	FDL_ASSERT(!((tl) & ~((1 << PE_MISC_TL_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TL_MASK) | (((unsigned long)(tl)) << PE_MISC_TL_SHIFT);\
}
#define PE_MISC_TR_SIZE	1
#define PE_MISC_TR_SHIFT	11
#define PE_MISC_TR_MASK	0x00000800
#define PE_MISC_GET_TR(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TR_MASK) >> PE_MISC_TR_SHIFT)
#define PE_MISC_SET_TR(pe_misc, tr) { \
	FDL_ASSERT(!((tr) & ~((1 << PE_MISC_TR_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TR_MASK) | (((unsigned long)(tr)) << PE_MISC_TR_SHIFT);\
}
#define PE_MISC_TM_SIZE	1
#define PE_MISC_TM_SHIFT	12
#define PE_MISC_TM_MASK	0x00001000
#define PE_MISC_GET_TM(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TM_MASK) >> PE_MISC_TM_SHIFT)
#define PE_MISC_SET_TM(pe_misc, tm) { \
	FDL_ASSERT(!((tm) & ~((1 << PE_MISC_TM_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TM_MASK) | (((unsigned long)(tm)) << PE_MISC_TM_SHIFT);\
}
#define PE_MISC_TP_SIZE	2
#define PE_MISC_TP_SHIFT	13
#define PE_MISC_TP_MASK	0x00006000
#define PE_MISC_GET_TP(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_TP_MASK) >> PE_MISC_TP_SHIFT)
#define PE_MISC_SET_TP(pe_misc, tp) { \
	FDL_ASSERT(!((tp) & ~((1 << PE_MISC_TP_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_TP_MASK) | (((unsigned long)(tp)) << PE_MISC_TP_SHIFT);\
}
#define PE_MISC_SV_SIZE	1
#define PE_MISC_SV_SHIFT	15
#define PE_MISC_SV_MASK	0x00008000
#define PE_MISC_GET_SV(pe_misc) \
	((((unsigned long)(pe_misc)) & PE_MISC_SV_MASK) >> PE_MISC_SV_SHIFT)
#define PE_MISC_SET_SV(pe_misc, sv) { \
	FDL_ASSERT(!((sv) & ~((1 << PE_MISC_SV_SIZE)-1))); \
	pe_misc = (((unsigned long)(pe_misc)) & ~PE_MISC_SV_MASK) | (((unsigned long)(sv)) << PE_MISC_SV_SHIFT);\
}
#define PE_MISC_TOTAL_SIZE	16
#define PE_MISC(v0, v1, v2, v3, st, sb, sl, sr, tt, tb, tl, tr, tm, tp, sv) \
	((((unsigned long)(v0)) << PE_MISC_V0_SHIFT) | \
	 (((unsigned long)(v1)) << PE_MISC_V1_SHIFT) | \
	 (((unsigned long)(v2)) << PE_MISC_V2_SHIFT) | \
	 (((unsigned long)(v3)) << PE_MISC_V3_SHIFT) | \
	 (((unsigned long)(st)) << PE_MISC_ST_SHIFT) | \
	 (((unsigned long)(sb)) << PE_MISC_SB_SHIFT) | \
	 (((unsigned long)(sl)) << PE_MISC_SL_SHIFT) | \
	 (((unsigned long)(sr)) << PE_MISC_SR_SHIFT) | \
	 (((unsigned long)(tt)) << PE_MISC_TT_SHIFT) | \
	 (((unsigned long)(tb)) << PE_MISC_TB_SHIFT) | \
	 (((unsigned long)(tl)) << PE_MISC_TL_SHIFT) | \
	 (((unsigned long)(tr)) << PE_MISC_TR_SHIFT) | \
	 (((unsigned long)(tm)) << PE_MISC_TM_SHIFT) | \
	 (((unsigned long)(tp)) << PE_MISC_TP_SHIFT) | \
	 (((unsigned long)(sv)) << PE_MISC_SV_SHIFT))

typedef struct {
    unsigned long sv:PE_MISC_SV_SIZE;
    unsigned long tp:PE_MISC_TP_SIZE;
    unsigned long tm:PE_MISC_TM_SIZE;
    unsigned long tr:PE_MISC_TR_SIZE;
    unsigned long tl:PE_MISC_TL_SIZE;
    unsigned long tb:PE_MISC_TB_SIZE;
    unsigned long tt:PE_MISC_TT_SIZE;
    unsigned long sr:PE_MISC_SR_SIZE;
    unsigned long sl:PE_MISC_SL_SIZE;
    unsigned long sb:PE_MISC_SB_SIZE;
    unsigned long st:PE_MISC_ST_SIZE;
    unsigned long v3:PE_MISC_V3_SIZE;
    unsigned long v2:PE_MISC_V2_SIZE;
    unsigned long v1:PE_MISC_V1_SIZE;
    unsigned long v0:PE_MISC_V0_SIZE;
} pe_misc_t;

typedef union {
    unsigned long val;
    pe_misc_t f;
} pe_misc_u;

/*
 *  pe_tag struct
 */
#define PE_TAG_CYCLE_SIZE	2
#define PE_TAG_CYCLE_SHIFT	0
#define PE_TAG_CYCLE_MASK	0x00000003
#define PE_TAG_GET_CYCLE(pe_tag) \
	((((unsigned long)(pe_tag)) & PE_TAG_CYCLE_MASK) >> PE_TAG_CYCLE_SHIFT)
#define PE_TAG_SET_CYCLE(pe_tag, cycle) { \
	FDL_ASSERT(!((cycle) & ~((1 << PE_TAG_CYCLE_SIZE)-1))); \
	pe_tag = (((unsigned long)(pe_tag)) & ~PE_TAG_CYCLE_MASK) | (((unsigned long)(cycle)) << PE_TAG_CYCLE_SHIFT);\
}
#define PE_TAG_YEC_SIZE	1
#define PE_TAG_YEC_SHIFT	2
#define PE_TAG_YEC_MASK	0x00000004
#define PE_TAG_GET_YEC(pe_tag) \
	((((unsigned long)(pe_tag)) & PE_TAG_YEC_MASK) >> PE_TAG_YEC_SHIFT)
#define PE_TAG_SET_YEC(pe_tag, yec) { \
	FDL_ASSERT(!((yec) & ~((1 << PE_TAG_YEC_SIZE)-1))); \
	pe_tag = (((unsigned long)(pe_tag)) & ~PE_TAG_YEC_MASK) | (((unsigned long)(yec)) << PE_TAG_YEC_SHIFT);\
}
#define PE_TAG_YOC_SIZE	1
#define PE_TAG_YOC_SHIFT	3
#define PE_TAG_YOC_MASK	0x00000008
#define PE_TAG_GET_YOC(pe_tag) \
	((((unsigned long)(pe_tag)) & PE_TAG_YOC_MASK) >> PE_TAG_YOC_SHIFT)
#define PE_TAG_SET_YOC(pe_tag, yoc) { \
	FDL_ASSERT(!((yoc) & ~((1 << PE_TAG_YOC_SIZE)-1))); \
	pe_tag = (((unsigned long)(pe_tag)) & ~PE_TAG_YOC_MASK) | (((unsigned long)(yoc)) << PE_TAG_YOC_SHIFT);\
}
#define PE_TAG_XOC_SIZE	1
#define PE_TAG_XOC_SHIFT	4
#define PE_TAG_XOC_MASK	0x00000010
#define PE_TAG_GET_XOC(pe_tag) \
	((((unsigned long)(pe_tag)) & PE_TAG_XOC_MASK) >> PE_TAG_XOC_SHIFT)
#define PE_TAG_SET_XOC(pe_tag, xoc) { \
	FDL_ASSERT(!((xoc) & ~((1 << PE_TAG_XOC_SIZE)-1))); \
	pe_tag = (((unsigned long)(pe_tag)) & ~PE_TAG_XOC_MASK) | (((unsigned long)(xoc)) << PE_TAG_XOC_SHIFT);\
}
#define PE_TAG_CLR_SIZE	1
#define PE_TAG_CLR_SHIFT	5
#define PE_TAG_CLR_MASK	0x00000020
#define PE_TAG_GET_CLR(pe_tag) \
	((((unsigned long)(pe_tag)) & PE_TAG_CLR_MASK) >> PE_TAG_CLR_SHIFT)
#define PE_TAG_SET_CLR(pe_tag, clr) { \
	FDL_ASSERT(!((clr) & ~((1 << PE_TAG_CLR_SIZE)-1))); \
	pe_tag = (((unsigned long)(pe_tag)) & ~PE_TAG_CLR_MASK) | (((unsigned long)(clr)) << PE_TAG_CLR_SHIFT);\
}
#define PE_TAG_TOTAL_SIZE	6
#define PE_TAG(cycle, yec, yoc, xoc, clr) \
	((((unsigned long)(cycle)) << PE_TAG_CYCLE_SHIFT) | \
	 (((unsigned long)(yec)) << PE_TAG_YEC_SHIFT) | \
	 (((unsigned long)(yoc)) << PE_TAG_YOC_SHIFT) | \
	 (((unsigned long)(xoc)) << PE_TAG_XOC_SHIFT) | \
	 (((unsigned long)(clr)) << PE_TAG_CLR_SHIFT))

typedef struct {
    unsigned long clr:PE_TAG_CLR_SIZE;
    unsigned long xoc:PE_TAG_XOC_SIZE;
    unsigned long yoc:PE_TAG_YOC_SIZE;
    unsigned long yec:PE_TAG_YEC_SIZE;
    unsigned long cycle:PE_TAG_CYCLE_SIZE;
} pe_tag_t;

typedef union {
    unsigned long val;
    pe_tag_t f;
} pe_tag_u;

/*
 *  pe_pi_tsize enum
 */
#define PE_PI_TSIZE4	0x00000000
#define PE_PI_TSIZE8	0x00000001
#define PE_PI_TSIZE32	0x00000002
#define PE_PI_TSIZE_UNUSED_3	0x00000003

/*
 *  pe_op enum
 */
#define PE_PIPE_RMWZ	0x00000000
#define PE_PIPE_REG	0x00000001
#define PE_COPY_RMW	0x00000002
#define PE_COPY_READ	0x00000003
#define PE_CPU_RMWZ	0x00000004
#define PE_CPU_READ	0x00000005
#define PE_CPU_RMW	0x00000006
#define PE_REF_READ	0x00000007

/*
 *  pe_cmd struct
 */
#define PE_CMD_VALID_SIZE	1
#define PE_CMD_VALID_SHIFT	0
#define PE_CMD_VALID_MASK	0x00000001
#define PE_CMD_GET_VALID(pe_cmd) \
	((((unsigned long)(pe_cmd)) & PE_CMD_VALID_MASK) >> PE_CMD_VALID_SHIFT)
#define PE_CMD_SET_VALID(pe_cmd, valid) { \
	FDL_ASSERT(!((valid) & ~((1 << PE_CMD_VALID_SIZE)-1))); \
	pe_cmd = (((unsigned long)(pe_cmd)) & ~PE_CMD_VALID_MASK) | (((unsigned long)(valid)) << PE_CMD_VALID_SHIFT);\
}
#define PE_CMD_OP_SIZE	3
#define PE_CMD_OP_SHIFT	1
#define PE_CMD_OP_MASK	0x0000000e
#define PE_CMD_GET_OP(pe_cmd) \
	((((unsigned long)(pe_cmd)) & PE_CMD_OP_MASK) >> PE_CMD_OP_SHIFT)
#define PE_CMD_SET_OP(pe_cmd, op) { \
	FDL_ASSERT(!((op) & ~((1 << PE_CMD_OP_SIZE)-1))); \
	pe_cmd = (((unsigned long)(pe_cmd)) & ~PE_CMD_OP_MASK) | (((unsigned long)(op)) << PE_CMD_OP_SHIFT);\
}
#define PE_CMD_BANKA_SIZE	1
#define PE_CMD_BANKA_SHIFT	4
#define PE_CMD_BANKA_MASK	0x00000010
#define PE_CMD_GET_BANKA(pe_cmd) \
	((((unsigned long)(pe_cmd)) & PE_CMD_BANKA_MASK) >> PE_CMD_BANKA_SHIFT)
#define PE_CMD_SET_BANKA(pe_cmd, bankA) { \
	FDL_ASSERT(!((bankA) & ~((1 << PE_CMD_BANKA_SIZE)-1))); \
	pe_cmd = (((unsigned long)(pe_cmd)) & ~PE_CMD_BANKA_MASK) | (((unsigned long)(bankA)) << PE_CMD_BANKA_SHIFT);\
}
#define PE_CMD_BANKB_SIZE	1
#define PE_CMD_BANKB_SHIFT	5
#define PE_CMD_BANKB_MASK	0x00000020
#define PE_CMD_GET_BANKB(pe_cmd) \
	((((unsigned long)(pe_cmd)) & PE_CMD_BANKB_MASK) >> PE_CMD_BANKB_SHIFT)
#define PE_CMD_SET_BANKB(pe_cmd, bankB) { \
	FDL_ASSERT(!((bankB) & ~((1 << PE_CMD_BANKB_SIZE)-1))); \
	pe_cmd = (((unsigned long)(pe_cmd)) & ~PE_CMD_BANKB_MASK) | (((unsigned long)(bankB)) << PE_CMD_BANKB_SHIFT);\
}
#define PE_CMD_TOTAL_SIZE	6
#define PE_CMD(valid, op, bankA, bankB) \
	((((unsigned long)(valid)) << PE_CMD_VALID_SHIFT) | \
	 (((unsigned long)(op)) << PE_CMD_OP_SHIFT) | \
	 (((unsigned long)(bankA)) << PE_CMD_BANKA_SHIFT) | \
	 (((unsigned long)(bankB)) << PE_CMD_BANKB_SHIFT))

typedef struct {
    unsigned long bankB:PE_CMD_BANKB_SIZE;
    unsigned long bankA:PE_CMD_BANKA_SIZE;
    unsigned long op:PE_CMD_OP_SIZE;
    unsigned long valid:PE_CMD_VALID_SIZE;
} pe_cmd_t;

typedef union {
    unsigned long val;
    pe_cmd_t f;
} pe_cmd_u;

/*
 *  pe_intrctl struct
 */
#define PE_INTRCTL_INT0EN_SIZE	1
#define PE_INTRCTL_INT0EN_SHIFT	0
#define PE_INTRCTL_INT0EN_MASK	0x00000001
#define PE_INTRCTL_GET_INT0EN(pe_intrctl) \
	((((unsigned long)(pe_intrctl)) & PE_INTRCTL_INT0EN_MASK) >> PE_INTRCTL_INT0EN_SHIFT)
#define PE_INTRCTL_SET_INT0EN(pe_intrctl, int0en) { \
	FDL_ASSERT(!((int0en) & ~((1 << PE_INTRCTL_INT0EN_SIZE)-1))); \
	pe_intrctl = (((unsigned long)(pe_intrctl)) & ~PE_INTRCTL_INT0EN_MASK) | (((unsigned long)(int0en)) << PE_INTRCTL_INT0EN_SHIFT);\
}
#define PE_INTRCTL_INT1EN_SIZE	1
#define PE_INTRCTL_INT1EN_SHIFT	1
#define PE_INTRCTL_INT1EN_MASK	0x00000002
#define PE_INTRCTL_GET_INT1EN(pe_intrctl) \
	((((unsigned long)(pe_intrctl)) & PE_INTRCTL_INT1EN_MASK) >> PE_INTRCTL_INT1EN_SHIFT)
#define PE_INTRCTL_SET_INT1EN(pe_intrctl, int1en) { \
	FDL_ASSERT(!((int1en) & ~((1 << PE_INTRCTL_INT1EN_SIZE)-1))); \
	pe_intrctl = (((unsigned long)(pe_intrctl)) & ~PE_INTRCTL_INT1EN_MASK) | (((unsigned long)(int1en)) << PE_INTRCTL_INT1EN_SHIFT);\
}
#define PE_INTRCTL_INT0CLR_SIZE	1
#define PE_INTRCTL_INT0CLR_SHIFT	2
#define PE_INTRCTL_INT0CLR_MASK	0x00000004
#define PE_INTRCTL_GET_INT0CLR(pe_intrctl) \
	((((unsigned long)(pe_intrctl)) & PE_INTRCTL_INT0CLR_MASK) >> PE_INTRCTL_INT0CLR_SHIFT)
#define PE_INTRCTL_SET_INT0CLR(pe_intrctl, int0clr) { \
	FDL_ASSERT(!((int0clr) & ~((1 << PE_INTRCTL_INT0CLR_SIZE)-1))); \
	pe_intrctl = (((unsigned long)(pe_intrctl)) & ~PE_INTRCTL_INT0CLR_MASK) | (((unsigned long)(int0clr)) << PE_INTRCTL_INT0CLR_SHIFT);\
}
#define PE_INTRCTL_INT1CLR_SIZE	1
#define PE_INTRCTL_INT1CLR_SHIFT	3
#define PE_INTRCTL_INT1CLR_MASK	0x00000008
#define PE_INTRCTL_GET_INT1CLR(pe_intrctl) \
	((((unsigned long)(pe_intrctl)) & PE_INTRCTL_INT1CLR_MASK) >> PE_INTRCTL_INT1CLR_SHIFT)
#define PE_INTRCTL_SET_INT1CLR(pe_intrctl, int1clr) { \
	FDL_ASSERT(!((int1clr) & ~((1 << PE_INTRCTL_INT1CLR_SIZE)-1))); \
	pe_intrctl = (((unsigned long)(pe_intrctl)) & ~PE_INTRCTL_INT1CLR_MASK) | (((unsigned long)(int1clr)) << PE_INTRCTL_INT1CLR_SHIFT);\
}
#define PE_INTRCTL_TOTAL_SIZE	4
#define PE_INTRCTL(int0en, int1en, int0clr, int1clr) \
	((((unsigned long)(int0en)) << PE_INTRCTL_INT0EN_SHIFT) | \
	 (((unsigned long)(int1en)) << PE_INTRCTL_INT1EN_SHIFT) | \
	 (((unsigned long)(int0clr)) << PE_INTRCTL_INT0CLR_SHIFT) | \
	 (((unsigned long)(int1clr)) << PE_INTRCTL_INT1CLR_SHIFT))

typedef struct {
    unsigned long pad0:12;
    unsigned long int1clr:PE_INTRCTL_INT1CLR_SIZE;
    unsigned long int0clr:PE_INTRCTL_INT0CLR_SIZE;
    unsigned long int1en:PE_INTRCTL_INT1EN_SIZE;
    unsigned long int0en:PE_INTRCTL_INT0EN_SIZE;
} pe_intrctl_t;

typedef union {
    unsigned long val;
    pe_intrctl_t f;
} pe_intrctl_u;

/*
 *  pe_pi_register_id enum
 */
#define PE_PI_ZMODE_ID	0x00000000
#define PE_PI_CMODE0_ID	0x00000001
#define PE_PI_CMODE1_ID	0x00000002
#define PE_PI_ALPHA_THRESHOLD_ID	0x00000003
#define PE_PI_CTL_ID	0x00000004
#define PE_PI_INTRCTL_ID	0x00000005
#define PE_PI_INTRSTAT_ID	0x00000006
#define PE_PI_TOKEN_ID	0x00000007
#define PE_PI_XBOUND0_ID	0x00000008
#define PE_PI_XBOUND1_ID	0x00000009
#define PE_PI_YBOUND0_ID	0x0000000a
#define PE_PI_YBOUND1_ID	0x0000000b
#define PE_PI_PERF_CNTR0L_ID	0x0000000c
#define PE_PI_PERF_CNTR0H_ID	0x0000000d
#define PE_PI_PERF_CNTR1L_ID	0x0000000e
#define PE_PI_PERF_CNTR1H_ID	0x0000000f
#define PE_PI_PERF_CNTR2L_ID	0x00000010
#define PE_PI_PERF_CNTR2H_ID	0x00000011
#define PE_PI_PERF_CNTR3L_ID	0x00000012
#define PE_PI_PERF_CNTR3H_ID	0x00000013
#define PE_PI_PERF_CNTR4L_ID	0x00000014
#define PE_PI_PERF_CNTR4H_ID	0x00000015
#define PE_PI_PERF_CNTR5L_ID	0x00000016
#define PE_PI_PERF_CNTR5H_ID	0x00000017
#define PE_PI_REGISTER_ID_UNUSED_24	0x00000018
#define PE_PI_REGISTER_ID_UNUSED_25	0x00000019
#define PE_PI_REGISTER_ID_UNUSED_26	0x0000001a
#define PE_PI_REGISTER_ID_UNUSED_27	0x0000001b
#define PE_PI_REGISTER_ID_UNUSED_28	0x0000001c
#define PE_PI_REGISTER_ID_UNUSED_29	0x0000001d
#define PE_PI_REGISTER_ID_UNUSED_30	0x0000001e
#define PE_PI_REGISTER_ID_UNUSED_31	0x0000001f
#define PE_PI_REGISTER_ID_UNUSED_32	0x00000020
#define PE_PI_REGISTER_ID_UNUSED_33	0x00000021
#define PE_PI_REGISTER_ID_UNUSED_34	0x00000022
#define PE_PI_REGISTER_ID_UNUSED_35	0x00000023
#define PE_PI_REGISTER_ID_UNUSED_36	0x00000024
#define PE_PI_REGISTER_ID_UNUSED_37	0x00000025
#define PE_PI_REGISTER_ID_UNUSED_38	0x00000026
#define PE_PI_REGISTER_ID_UNUSED_39	0x00000027
#define PE_PI_REGISTER_ID_UNUSED_40	0x00000028
#define PE_PI_REGISTER_ID_UNUSED_41	0x00000029
#define PE_PI_REGISTER_ID_UNUSED_42	0x0000002a
#define PE_PI_REGISTER_ID_UNUSED_43	0x0000002b
#define PE_PI_REGISTER_ID_UNUSED_44	0x0000002c
#define PE_PI_REGISTER_ID_UNUSED_45	0x0000002d
#define PE_PI_REGISTER_ID_UNUSED_46	0x0000002e
#define PE_PI_REGISTER_ID_UNUSED_47	0x0000002f
#define PE_PI_REGISTER_ID_UNUSED_48	0x00000030
#define PE_PI_REGISTER_ID_UNUSED_49	0x00000031
#define PE_PI_REGISTER_ID_UNUSED_50	0x00000032
#define PE_PI_REGISTER_ID_UNUSED_51	0x00000033
#define PE_PI_REGISTER_ID_UNUSED_52	0x00000034
#define PE_PI_REGISTER_ID_UNUSED_53	0x00000035
#define PE_PI_REGISTER_ID_UNUSED_54	0x00000036
#define PE_PI_REGISTER_ID_UNUSED_55	0x00000037
#define PE_PI_REGISTER_ID_UNUSED_56	0x00000038
#define PE_PI_REGISTER_ID_UNUSED_57	0x00000039
#define PE_PI_REGISTER_ID_UNUSED_58	0x0000003a
#define PE_PI_REGISTER_ID_UNUSED_59	0x0000003b
#define PE_PI_REGISTER_ID_UNUSED_60	0x0000003c
#define PE_PI_REGISTER_ID_UNUSED_61	0x0000003d
#define PE_PI_REGISTER_ID_UNUSED_62	0x0000003e
#define PE_PI_REGISTER_ID_UNUSED_63	0x0000003f
#define PE_PI_REGISTER_ID_UNUSED_64	0x00000040
#define PE_PI_REGISTER_ID_UNUSED_65	0x00000041
#define PE_PI_REGISTER_ID_UNUSED_66	0x00000042
#define PE_PI_REGISTER_ID_UNUSED_67	0x00000043
#define PE_PI_REGISTER_ID_UNUSED_68	0x00000044
#define PE_PI_REGISTER_ID_UNUSED_69	0x00000045
#define PE_PI_REGISTER_ID_UNUSED_70	0x00000046
#define PE_PI_REGISTER_ID_UNUSED_71	0x00000047
#define PE_PI_REGISTER_ID_UNUSED_72	0x00000048
#define PE_PI_REGISTER_ID_UNUSED_73	0x00000049
#define PE_PI_REGISTER_ID_UNUSED_74	0x0000004a
#define PE_PI_REGISTER_ID_UNUSED_75	0x0000004b
#define PE_PI_REGISTER_ID_UNUSED_76	0x0000004c
#define PE_PI_REGISTER_ID_UNUSED_77	0x0000004d
#define PE_PI_REGISTER_ID_UNUSED_78	0x0000004e
#define PE_PI_REGISTER_ID_UNUSED_79	0x0000004f
#define PE_PI_REGISTER_ID_UNUSED_80	0x00000050
#define PE_PI_REGISTER_ID_UNUSED_81	0x00000051
#define PE_PI_REGISTER_ID_UNUSED_82	0x00000052
#define PE_PI_REGISTER_ID_UNUSED_83	0x00000053
#define PE_PI_REGISTER_ID_UNUSED_84	0x00000054
#define PE_PI_REGISTER_ID_UNUSED_85	0x00000055
#define PE_PI_REGISTER_ID_UNUSED_86	0x00000056
#define PE_PI_REGISTER_ID_UNUSED_87	0x00000057
#define PE_PI_REGISTER_ID_UNUSED_88	0x00000058
#define PE_PI_REGISTER_ID_UNUSED_89	0x00000059
#define PE_PI_REGISTER_ID_UNUSED_90	0x0000005a
#define PE_PI_REGISTER_ID_UNUSED_91	0x0000005b
#define PE_PI_REGISTER_ID_UNUSED_92	0x0000005c
#define PE_PI_REGISTER_ID_UNUSED_93	0x0000005d
#define PE_PI_REGISTER_ID_UNUSED_94	0x0000005e
#define PE_PI_REGISTER_ID_UNUSED_95	0x0000005f
#define PE_PI_REGISTER_ID_UNUSED_96	0x00000060
#define PE_PI_REGISTER_ID_UNUSED_97	0x00000061
#define PE_PI_REGISTER_ID_UNUSED_98	0x00000062
#define PE_PI_REGISTER_ID_UNUSED_99	0x00000063
#define PE_PI_REGISTER_ID_UNUSED_100	0x00000064
#define PE_PI_REGISTER_ID_UNUSED_101	0x00000065
#define PE_PI_REGISTER_ID_UNUSED_102	0x00000066
#define PE_PI_REGISTER_ID_UNUSED_103	0x00000067
#define PE_PI_REGISTER_ID_UNUSED_104	0x00000068
#define PE_PI_REGISTER_ID_UNUSED_105	0x00000069
#define PE_PI_REGISTER_ID_UNUSED_106	0x0000006a
#define PE_PI_REGISTER_ID_UNUSED_107	0x0000006b
#define PE_PI_REGISTER_ID_UNUSED_108	0x0000006c
#define PE_PI_REGISTER_ID_UNUSED_109	0x0000006d
#define PE_PI_REGISTER_ID_UNUSED_110	0x0000006e
#define PE_PI_REGISTER_ID_UNUSED_111	0x0000006f
#define PE_PI_REGISTER_ID_UNUSED_112	0x00000070
#define PE_PI_REGISTER_ID_UNUSED_113	0x00000071
#define PE_PI_REGISTER_ID_UNUSED_114	0x00000072
#define PE_PI_REGISTER_ID_UNUSED_115	0x00000073
#define PE_PI_REGISTER_ID_UNUSED_116	0x00000074
#define PE_PI_REGISTER_ID_UNUSED_117	0x00000075
#define PE_PI_REGISTER_ID_UNUSED_118	0x00000076
#define PE_PI_REGISTER_ID_UNUSED_119	0x00000077
#define PE_PI_REGISTER_ID_UNUSED_120	0x00000078
#define PE_PI_REGISTER_ID_UNUSED_121	0x00000079
#define PE_PI_REGISTER_ID_UNUSED_122	0x0000007a
#define PE_PI_REGISTER_ID_UNUSED_123	0x0000007b
#define PE_PI_REGISTER_ID_UNUSED_124	0x0000007c
#define PE_PI_REGISTER_ID_UNUSED_125	0x0000007d
#define PE_PI_REGISTER_ID_UNUSED_126	0x0000007e
#define PE_PI_REGISTER_ID_UNUSED_127	0x0000007f
#define PE_PI_REGISTER_ID_UNUSED_128	0x00000080
#define PE_PI_REGISTER_ID_UNUSED_129	0x00000081
#define PE_PI_REGISTER_ID_UNUSED_130	0x00000082
#define PE_PI_REGISTER_ID_UNUSED_131	0x00000083
#define PE_PI_REGISTER_ID_UNUSED_132	0x00000084
#define PE_PI_REGISTER_ID_UNUSED_133	0x00000085
#define PE_PI_REGISTER_ID_UNUSED_134	0x00000086
#define PE_PI_REGISTER_ID_UNUSED_135	0x00000087
#define PE_PI_REGISTER_ID_UNUSED_136	0x00000088
#define PE_PI_REGISTER_ID_UNUSED_137	0x00000089
#define PE_PI_REGISTER_ID_UNUSED_138	0x0000008a
#define PE_PI_REGISTER_ID_UNUSED_139	0x0000008b
#define PE_PI_REGISTER_ID_UNUSED_140	0x0000008c
#define PE_PI_REGISTER_ID_UNUSED_141	0x0000008d
#define PE_PI_REGISTER_ID_UNUSED_142	0x0000008e
#define PE_PI_REGISTER_ID_UNUSED_143	0x0000008f
#define PE_PI_REGISTER_ID_UNUSED_144	0x00000090
#define PE_PI_REGISTER_ID_UNUSED_145	0x00000091
#define PE_PI_REGISTER_ID_UNUSED_146	0x00000092
#define PE_PI_REGISTER_ID_UNUSED_147	0x00000093
#define PE_PI_REGISTER_ID_UNUSED_148	0x00000094
#define PE_PI_REGISTER_ID_UNUSED_149	0x00000095
#define PE_PI_REGISTER_ID_UNUSED_150	0x00000096
#define PE_PI_REGISTER_ID_UNUSED_151	0x00000097
#define PE_PI_REGISTER_ID_UNUSED_152	0x00000098
#define PE_PI_REGISTER_ID_UNUSED_153	0x00000099
#define PE_PI_REGISTER_ID_UNUSED_154	0x0000009a
#define PE_PI_REGISTER_ID_UNUSED_155	0x0000009b
#define PE_PI_REGISTER_ID_UNUSED_156	0x0000009c
#define PE_PI_REGISTER_ID_UNUSED_157	0x0000009d
#define PE_PI_REGISTER_ID_UNUSED_158	0x0000009e
#define PE_PI_REGISTER_ID_UNUSED_159	0x0000009f
#define PE_PI_REGISTER_ID_UNUSED_160	0x000000a0
#define PE_PI_REGISTER_ID_UNUSED_161	0x000000a1
#define PE_PI_REGISTER_ID_UNUSED_162	0x000000a2
#define PE_PI_REGISTER_ID_UNUSED_163	0x000000a3
#define PE_PI_REGISTER_ID_UNUSED_164	0x000000a4
#define PE_PI_REGISTER_ID_UNUSED_165	0x000000a5
#define PE_PI_REGISTER_ID_UNUSED_166	0x000000a6
#define PE_PI_REGISTER_ID_UNUSED_167	0x000000a7
#define PE_PI_REGISTER_ID_UNUSED_168	0x000000a8
#define PE_PI_REGISTER_ID_UNUSED_169	0x000000a9
#define PE_PI_REGISTER_ID_UNUSED_170	0x000000aa
#define PE_PI_REGISTER_ID_UNUSED_171	0x000000ab
#define PE_PI_REGISTER_ID_UNUSED_172	0x000000ac
#define PE_PI_REGISTER_ID_UNUSED_173	0x000000ad
#define PE_PI_REGISTER_ID_UNUSED_174	0x000000ae
#define PE_PI_REGISTER_ID_UNUSED_175	0x000000af
#define PE_PI_REGISTER_ID_UNUSED_176	0x000000b0
#define PE_PI_REGISTER_ID_UNUSED_177	0x000000b1
#define PE_PI_REGISTER_ID_UNUSED_178	0x000000b2
#define PE_PI_REGISTER_ID_UNUSED_179	0x000000b3
#define PE_PI_REGISTER_ID_UNUSED_180	0x000000b4
#define PE_PI_REGISTER_ID_UNUSED_181	0x000000b5
#define PE_PI_REGISTER_ID_UNUSED_182	0x000000b6
#define PE_PI_REGISTER_ID_UNUSED_183	0x000000b7
#define PE_PI_REGISTER_ID_UNUSED_184	0x000000b8
#define PE_PI_REGISTER_ID_UNUSED_185	0x000000b9
#define PE_PI_REGISTER_ID_UNUSED_186	0x000000ba
#define PE_PI_REGISTER_ID_UNUSED_187	0x000000bb
#define PE_PI_REGISTER_ID_UNUSED_188	0x000000bc
#define PE_PI_REGISTER_ID_UNUSED_189	0x000000bd
#define PE_PI_REGISTER_ID_UNUSED_190	0x000000be
#define PE_PI_REGISTER_ID_UNUSED_191	0x000000bf
#define PE_PI_REGISTER_ID_UNUSED_192	0x000000c0
#define PE_PI_REGISTER_ID_UNUSED_193	0x000000c1
#define PE_PI_REGISTER_ID_UNUSED_194	0x000000c2
#define PE_PI_REGISTER_ID_UNUSED_195	0x000000c3
#define PE_PI_REGISTER_ID_UNUSED_196	0x000000c4
#define PE_PI_REGISTER_ID_UNUSED_197	0x000000c5
#define PE_PI_REGISTER_ID_UNUSED_198	0x000000c6
#define PE_PI_REGISTER_ID_UNUSED_199	0x000000c7
#define PE_PI_REGISTER_ID_UNUSED_200	0x000000c8
#define PE_PI_REGISTER_ID_UNUSED_201	0x000000c9
#define PE_PI_REGISTER_ID_UNUSED_202	0x000000ca
#define PE_PI_REGISTER_ID_UNUSED_203	0x000000cb
#define PE_PI_REGISTER_ID_UNUSED_204	0x000000cc
#define PE_PI_REGISTER_ID_UNUSED_205	0x000000cd
#define PE_PI_REGISTER_ID_UNUSED_206	0x000000ce
#define PE_PI_REGISTER_ID_UNUSED_207	0x000000cf
#define PE_PI_REGISTER_ID_UNUSED_208	0x000000d0
#define PE_PI_REGISTER_ID_UNUSED_209	0x000000d1
#define PE_PI_REGISTER_ID_UNUSED_210	0x000000d2
#define PE_PI_REGISTER_ID_UNUSED_211	0x000000d3
#define PE_PI_REGISTER_ID_UNUSED_212	0x000000d4
#define PE_PI_REGISTER_ID_UNUSED_213	0x000000d5
#define PE_PI_REGISTER_ID_UNUSED_214	0x000000d6
#define PE_PI_REGISTER_ID_UNUSED_215	0x000000d7
#define PE_PI_REGISTER_ID_UNUSED_216	0x000000d8
#define PE_PI_REGISTER_ID_UNUSED_217	0x000000d9
#define PE_PI_REGISTER_ID_UNUSED_218	0x000000da
#define PE_PI_REGISTER_ID_UNUSED_219	0x000000db
#define PE_PI_REGISTER_ID_UNUSED_220	0x000000dc
#define PE_PI_REGISTER_ID_UNUSED_221	0x000000dd
#define PE_PI_REGISTER_ID_UNUSED_222	0x000000de
#define PE_PI_REGISTER_ID_UNUSED_223	0x000000df
#define PE_PI_REGISTER_ID_UNUSED_224	0x000000e0
#define PE_PI_REGISTER_ID_UNUSED_225	0x000000e1
#define PE_PI_REGISTER_ID_UNUSED_226	0x000000e2
#define PE_PI_REGISTER_ID_UNUSED_227	0x000000e3
#define PE_PI_REGISTER_ID_UNUSED_228	0x000000e4
#define PE_PI_REGISTER_ID_UNUSED_229	0x000000e5
#define PE_PI_REGISTER_ID_UNUSED_230	0x000000e6
#define PE_PI_REGISTER_ID_UNUSED_231	0x000000e7
#define PE_PI_REGISTER_ID_UNUSED_232	0x000000e8
#define PE_PI_REGISTER_ID_UNUSED_233	0x000000e9
#define PE_PI_REGISTER_ID_UNUSED_234	0x000000ea
#define PE_PI_REGISTER_ID_UNUSED_235	0x000000eb
#define PE_PI_REGISTER_ID_UNUSED_236	0x000000ec
#define PE_PI_REGISTER_ID_UNUSED_237	0x000000ed
#define PE_PI_REGISTER_ID_UNUSED_238	0x000000ee
#define PE_PI_REGISTER_ID_UNUSED_239	0x000000ef
#define PE_PI_REGISTER_ID_UNUSED_240	0x000000f0
#define PE_PI_REGISTER_ID_UNUSED_241	0x000000f1
#define PE_PI_REGISTER_ID_UNUSED_242	0x000000f2
#define PE_PI_REGISTER_ID_UNUSED_243	0x000000f3
#define PE_PI_REGISTER_ID_UNUSED_244	0x000000f4
#define PE_PI_REGISTER_ID_UNUSED_245	0x000000f5
#define PE_PI_REGISTER_ID_UNUSED_246	0x000000f6
#define PE_PI_REGISTER_ID_UNUSED_247	0x000000f7
#define PE_PI_REGISTER_ID_UNUSED_248	0x000000f8
#define PE_PI_REGISTER_ID_UNUSED_249	0x000000f9
#define PE_PI_REGISTER_ID_UNUSED_250	0x000000fa
#define PE_PI_REGISTER_ID_UNUSED_251	0x000000fb
#define PE_PI_REGISTER_ID_UNUSED_252	0x000000fc
#define PE_PI_REGISTER_ID_UNUSED_253	0x000000fd
#define PE_PI_REGISTER_ID_UNUSED_254	0x000000fe
#define PE_PI_REGISTER_ID_UNUSED_255	0x000000ff

/*
 *  pe_pi_efb_addr_type value
 */
#define PE_ADDR_COLOR	0x0
#define PE_ADDR_Z	0x1

/*
 *  pe_pi_efb_addr struct
 */
#define PE_PI_EFB_ADDR_PAD0_SIZE	2
#define PE_PI_EFB_ADDR_PAD0_SHIFT	0
#define PE_PI_EFB_ADDR_PAD0_MASK	0x00000003
#define PE_PI_EFB_ADDR_GET_PAD0(pe_pi_efb_addr) \
	((((unsigned long)(pe_pi_efb_addr)) & PE_PI_EFB_ADDR_PAD0_MASK) >> PE_PI_EFB_ADDR_PAD0_SHIFT)
#define PE_PI_EFB_ADDR_SET_PAD0(pe_pi_efb_addr, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_EFB_ADDR_PAD0_SIZE)-1))); \
	pe_pi_efb_addr = (((unsigned long)(pe_pi_efb_addr)) & ~PE_PI_EFB_ADDR_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_EFB_ADDR_PAD0_SHIFT);\
}
#define PE_PI_EFB_ADDR_X_SIZE	10
#define PE_PI_EFB_ADDR_X_SHIFT	2
#define PE_PI_EFB_ADDR_X_MASK	0x00000ffc
#define PE_PI_EFB_ADDR_GET_X(pe_pi_efb_addr) \
	((((unsigned long)(pe_pi_efb_addr)) & PE_PI_EFB_ADDR_X_MASK) >> PE_PI_EFB_ADDR_X_SHIFT)
#define PE_PI_EFB_ADDR_SET_X(pe_pi_efb_addr, x) { \
	FDL_ASSERT(!((x) & ~((1 << PE_PI_EFB_ADDR_X_SIZE)-1))); \
	pe_pi_efb_addr = (((unsigned long)(pe_pi_efb_addr)) & ~PE_PI_EFB_ADDR_X_MASK) | (((unsigned long)(x)) << PE_PI_EFB_ADDR_X_SHIFT);\
}
#define PE_PI_EFB_ADDR_Y_SIZE	10
#define PE_PI_EFB_ADDR_Y_SHIFT	12
#define PE_PI_EFB_ADDR_Y_MASK	0x003ff000
#define PE_PI_EFB_ADDR_GET_Y(pe_pi_efb_addr) \
	((((unsigned long)(pe_pi_efb_addr)) & PE_PI_EFB_ADDR_Y_MASK) >> PE_PI_EFB_ADDR_Y_SHIFT)
#define PE_PI_EFB_ADDR_SET_Y(pe_pi_efb_addr, y) { \
	FDL_ASSERT(!((y) & ~((1 << PE_PI_EFB_ADDR_Y_SIZE)-1))); \
	pe_pi_efb_addr = (((unsigned long)(pe_pi_efb_addr)) & ~PE_PI_EFB_ADDR_Y_MASK) | (((unsigned long)(y)) << PE_PI_EFB_ADDR_Y_SHIFT);\
}
#define PE_PI_EFB_ADDR_TYPE_SIZE	2
#define PE_PI_EFB_ADDR_TYPE_SHIFT	22
#define PE_PI_EFB_ADDR_TYPE_MASK	0x00c00000
#define PE_PI_EFB_ADDR_GET_TYPE(pe_pi_efb_addr) \
	((((unsigned long)(pe_pi_efb_addr)) & PE_PI_EFB_ADDR_TYPE_MASK) >> PE_PI_EFB_ADDR_TYPE_SHIFT)
#define PE_PI_EFB_ADDR_SET_TYPE(pe_pi_efb_addr, type) { \
	FDL_ASSERT(!((type) & ~((1 << PE_PI_EFB_ADDR_TYPE_SIZE)-1))); \
	pe_pi_efb_addr = (((unsigned long)(pe_pi_efb_addr)) & ~PE_PI_EFB_ADDR_TYPE_MASK) | (((unsigned long)(type)) << PE_PI_EFB_ADDR_TYPE_SHIFT);\
}
#define PE_PI_EFB_ADDR_TOTAL_SIZE	24
#define PE_PI_EFB_ADDR(x, y, type) \
	((((unsigned long)(x)) << PE_PI_EFB_ADDR_X_SHIFT) | \
	 (((unsigned long)(y)) << PE_PI_EFB_ADDR_Y_SHIFT) | \
	 (((unsigned long)(type)) << PE_PI_EFB_ADDR_TYPE_SHIFT))

typedef struct {
    unsigned long pad1:8;
    unsigned long type:PE_PI_EFB_ADDR_TYPE_SIZE;
    unsigned long y:PE_PI_EFB_ADDR_Y_SIZE;
    unsigned long x:PE_PI_EFB_ADDR_X_SIZE;
    unsigned long pad0:PE_PI_EFB_ADDR_PAD0_SIZE;
} pe_pi_efb_addr_t;

typedef union {
    unsigned long val;
    pe_pi_efb_addr_t f;
} pe_pi_efb_addr_u;

/*
 *  pe_pi_zmode struct
 */
#define PE_PI_ZMODE_ZEN_SIZE	1
#define PE_PI_ZMODE_ZEN_SHIFT	0
#define PE_PI_ZMODE_ZEN_MASK	0x00000001
#define PE_PI_ZMODE_GET_ZEN(pe_pi_zmode) \
	((((unsigned long)(pe_pi_zmode)) & PE_PI_ZMODE_ZEN_MASK) >> PE_PI_ZMODE_ZEN_SHIFT)
#define PE_PI_ZMODE_SET_ZEN(pe_pi_zmode, zen) { \
	FDL_ASSERT(!((zen) & ~((1 << PE_PI_ZMODE_ZEN_SIZE)-1))); \
	pe_pi_zmode = (((unsigned long)(pe_pi_zmode)) & ~PE_PI_ZMODE_ZEN_MASK) | (((unsigned long)(zen)) << PE_PI_ZMODE_ZEN_SHIFT);\
}
#define PE_PI_ZMODE_ZFUNC_SIZE	3
#define PE_PI_ZMODE_ZFUNC_SHIFT	1
#define PE_PI_ZMODE_ZFUNC_MASK	0x0000000e
#define PE_PI_ZMODE_GET_ZFUNC(pe_pi_zmode) \
	((((unsigned long)(pe_pi_zmode)) & PE_PI_ZMODE_ZFUNC_MASK) >> PE_PI_ZMODE_ZFUNC_SHIFT)
#define PE_PI_ZMODE_SET_ZFUNC(pe_pi_zmode, zfunc) { \
	FDL_ASSERT(!((zfunc) & ~((1 << PE_PI_ZMODE_ZFUNC_SIZE)-1))); \
	pe_pi_zmode = (((unsigned long)(pe_pi_zmode)) & ~PE_PI_ZMODE_ZFUNC_MASK) | (((unsigned long)(zfunc)) << PE_PI_ZMODE_ZFUNC_SHIFT);\
}
#define PE_PI_ZMODE_MASK_SIZE	1
#define PE_PI_ZMODE_MASK_SHIFT	4
#define PE_PI_ZMODE_MASK_MASK	0x00000010
#define PE_PI_ZMODE_GET_MASK(pe_pi_zmode) \
	((((unsigned long)(pe_pi_zmode)) & PE_PI_ZMODE_MASK_MASK) >> PE_PI_ZMODE_MASK_SHIFT)
#define PE_PI_ZMODE_SET_MASK(pe_pi_zmode, mask) { \
	FDL_ASSERT(!((mask) & ~((1 << PE_PI_ZMODE_MASK_SIZE)-1))); \
	pe_pi_zmode = (((unsigned long)(pe_pi_zmode)) & ~PE_PI_ZMODE_MASK_MASK) | (((unsigned long)(mask)) << PE_PI_ZMODE_MASK_SHIFT);\
}
#define PE_PI_ZMODE_PAD0_SIZE	19
#define PE_PI_ZMODE_PAD0_SHIFT	5
#define PE_PI_ZMODE_PAD0_MASK	0x00ffffe0
#define PE_PI_ZMODE_GET_PAD0(pe_pi_zmode) \
	((((unsigned long)(pe_pi_zmode)) & PE_PI_ZMODE_PAD0_MASK) >> PE_PI_ZMODE_PAD0_SHIFT)
#define PE_PI_ZMODE_SET_PAD0(pe_pi_zmode, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_ZMODE_PAD0_SIZE)-1))); \
	pe_pi_zmode = (((unsigned long)(pe_pi_zmode)) & ~PE_PI_ZMODE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_ZMODE_PAD0_SHIFT);\
}
#define PE_PI_ZMODE_RID_SIZE	8
#define PE_PI_ZMODE_RID_SHIFT	24
#define PE_PI_ZMODE_RID_MASK	0xff000000
#define PE_PI_ZMODE_GET_RID(pe_pi_zmode) \
	((((unsigned long)(pe_pi_zmode)) & PE_PI_ZMODE_RID_MASK) >> PE_PI_ZMODE_RID_SHIFT)
#define PE_PI_ZMODE_SET_RID(pe_pi_zmode, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << PE_PI_ZMODE_RID_SIZE)-1))); \
	pe_pi_zmode = (((unsigned long)(pe_pi_zmode)) & ~PE_PI_ZMODE_RID_MASK) | (((unsigned long)(rid)) << PE_PI_ZMODE_RID_SHIFT);\
}
#define PE_PI_ZMODE_TOTAL_SIZE	32
#define PE_PI_ZMODE(zen, zfunc, mask, rid) \
	((((unsigned long)(zen)) << PE_PI_ZMODE_ZEN_SHIFT) | \
	 (((unsigned long)(zfunc)) << PE_PI_ZMODE_ZFUNC_SHIFT) | \
	 (((unsigned long)(mask)) << PE_PI_ZMODE_MASK_SHIFT) | \
	 (((unsigned long)(rid)) << PE_PI_ZMODE_RID_SHIFT))

typedef struct {
    unsigned long rid:PE_PI_ZMODE_RID_SIZE;
    unsigned long pad0:PE_PI_ZMODE_PAD0_SIZE;
    unsigned long mask:PE_PI_ZMODE_MASK_SIZE;
    unsigned long zfunc:PE_PI_ZMODE_ZFUNC_SIZE;
    unsigned long zen:PE_PI_ZMODE_ZEN_SIZE;
} pe_pi_zmode_t;

typedef union {
    unsigned long val;
    pe_pi_zmode_t f;
} pe_pi_zmode_u;

/*
 *  pe_pi_cmode0 struct
 */
#define PE_PI_CMODE0_BEN_SIZE	1
#define PE_PI_CMODE0_BEN_SHIFT	0
#define PE_PI_CMODE0_BEN_MASK	0x00000001
#define PE_PI_CMODE0_GET_BEN(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_BEN_MASK) >> PE_PI_CMODE0_BEN_SHIFT)
#define PE_PI_CMODE0_SET_BEN(pe_pi_cmode0, ben) { \
	FDL_ASSERT(!((ben) & ~((1 << PE_PI_CMODE0_BEN_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_BEN_MASK) | (((unsigned long)(ben)) << PE_PI_CMODE0_BEN_SHIFT);\
}
#define PE_PI_CMODE0_LEN_SIZE	1
#define PE_PI_CMODE0_LEN_SHIFT	1
#define PE_PI_CMODE0_LEN_MASK	0x00000002
#define PE_PI_CMODE0_GET_LEN(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_LEN_MASK) >> PE_PI_CMODE0_LEN_SHIFT)
#define PE_PI_CMODE0_SET_LEN(pe_pi_cmode0, len) { \
	FDL_ASSERT(!((len) & ~((1 << PE_PI_CMODE0_LEN_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_LEN_MASK) | (((unsigned long)(len)) << PE_PI_CMODE0_LEN_SHIFT);\
}
#define PE_PI_CMODE0_DEN_SIZE	1
#define PE_PI_CMODE0_DEN_SHIFT	2
#define PE_PI_CMODE0_DEN_MASK	0x00000004
#define PE_PI_CMODE0_GET_DEN(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_DEN_MASK) >> PE_PI_CMODE0_DEN_SHIFT)
#define PE_PI_CMODE0_SET_DEN(pe_pi_cmode0, den) { \
	FDL_ASSERT(!((den) & ~((1 << PE_PI_CMODE0_DEN_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_DEN_MASK) | (((unsigned long)(den)) << PE_PI_CMODE0_DEN_SHIFT);\
}
#define PE_PI_CMODE0_CMSK_SIZE	1
#define PE_PI_CMODE0_CMSK_SHIFT	3
#define PE_PI_CMODE0_CMSK_MASK	0x00000008
#define PE_PI_CMODE0_GET_CMSK(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_CMSK_MASK) >> PE_PI_CMODE0_CMSK_SHIFT)
#define PE_PI_CMODE0_SET_CMSK(pe_pi_cmode0, cmsk) { \
	FDL_ASSERT(!((cmsk) & ~((1 << PE_PI_CMODE0_CMSK_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_CMSK_MASK) | (((unsigned long)(cmsk)) << PE_PI_CMODE0_CMSK_SHIFT);\
}
#define PE_PI_CMODE0_AMSK_SIZE	1
#define PE_PI_CMODE0_AMSK_SHIFT	4
#define PE_PI_CMODE0_AMSK_MASK	0x00000010
#define PE_PI_CMODE0_GET_AMSK(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_AMSK_MASK) >> PE_PI_CMODE0_AMSK_SHIFT)
#define PE_PI_CMODE0_SET_AMSK(pe_pi_cmode0, amsk) { \
	FDL_ASSERT(!((amsk) & ~((1 << PE_PI_CMODE0_AMSK_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_AMSK_MASK) | (((unsigned long)(amsk)) << PE_PI_CMODE0_AMSK_SHIFT);\
}
#define PE_PI_CMODE0_DFACTOR_SIZE	3
#define PE_PI_CMODE0_DFACTOR_SHIFT	5
#define PE_PI_CMODE0_DFACTOR_MASK	0x000000e0
#define PE_PI_CMODE0_GET_DFACTOR(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_DFACTOR_MASK) >> PE_PI_CMODE0_DFACTOR_SHIFT)
#define PE_PI_CMODE0_SET_DFACTOR(pe_pi_cmode0, dfactor) { \
	FDL_ASSERT(!((dfactor) & ~((1 << PE_PI_CMODE0_DFACTOR_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_DFACTOR_MASK) | (((unsigned long)(dfactor)) << PE_PI_CMODE0_DFACTOR_SHIFT);\
}
#define PE_PI_CMODE0_SFACTOR_SIZE	4
#define PE_PI_CMODE0_SFACTOR_SHIFT	8
#define PE_PI_CMODE0_SFACTOR_MASK	0x00000f00
#define PE_PI_CMODE0_GET_SFACTOR(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_SFACTOR_MASK) >> PE_PI_CMODE0_SFACTOR_SHIFT)
#define PE_PI_CMODE0_SET_SFACTOR(pe_pi_cmode0, sfactor) { \
	FDL_ASSERT(!((sfactor) & ~((1 << PE_PI_CMODE0_SFACTOR_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_SFACTOR_MASK) | (((unsigned long)(sfactor)) << PE_PI_CMODE0_SFACTOR_SHIFT);\
}
#define PE_PI_CMODE0_LOGICOP_SIZE	4
#define PE_PI_CMODE0_LOGICOP_SHIFT	12
#define PE_PI_CMODE0_LOGICOP_MASK	0x0000f000
#define PE_PI_CMODE0_GET_LOGICOP(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_LOGICOP_MASK) >> PE_PI_CMODE0_LOGICOP_SHIFT)
#define PE_PI_CMODE0_SET_LOGICOP(pe_pi_cmode0, logicop) { \
	FDL_ASSERT(!((logicop) & ~((1 << PE_PI_CMODE0_LOGICOP_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_LOGICOP_MASK) | (((unsigned long)(logicop)) << PE_PI_CMODE0_LOGICOP_SHIFT);\
}
#define PE_PI_CMODE0_PAD0_SIZE	8
#define PE_PI_CMODE0_PAD0_SHIFT	16
#define PE_PI_CMODE0_PAD0_MASK	0x00ff0000
#define PE_PI_CMODE0_GET_PAD0(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_PAD0_MASK) >> PE_PI_CMODE0_PAD0_SHIFT)
#define PE_PI_CMODE0_SET_PAD0(pe_pi_cmode0, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_CMODE0_PAD0_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_CMODE0_PAD0_SHIFT);\
}
#define PE_PI_CMODE0_RID_SIZE	8
#define PE_PI_CMODE0_RID_SHIFT	24
#define PE_PI_CMODE0_RID_MASK	0xff000000
#define PE_PI_CMODE0_GET_RID(pe_pi_cmode0) \
	((((unsigned long)(pe_pi_cmode0)) & PE_PI_CMODE0_RID_MASK) >> PE_PI_CMODE0_RID_SHIFT)
#define PE_PI_CMODE0_SET_RID(pe_pi_cmode0, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << PE_PI_CMODE0_RID_SIZE)-1))); \
	pe_pi_cmode0 = (((unsigned long)(pe_pi_cmode0)) & ~PE_PI_CMODE0_RID_MASK) | (((unsigned long)(rid)) << PE_PI_CMODE0_RID_SHIFT);\
}
#define PE_PI_CMODE0_TOTAL_SIZE	32
#define PE_PI_CMODE0(ben, len, den, cmsk, amsk, dfactor, sfactor, logicop, rid) \
	((((unsigned long)(ben)) << PE_PI_CMODE0_BEN_SHIFT) | \
	 (((unsigned long)(len)) << PE_PI_CMODE0_LEN_SHIFT) | \
	 (((unsigned long)(den)) << PE_PI_CMODE0_DEN_SHIFT) | \
	 (((unsigned long)(cmsk)) << PE_PI_CMODE0_CMSK_SHIFT) | \
	 (((unsigned long)(amsk)) << PE_PI_CMODE0_AMSK_SHIFT) | \
	 (((unsigned long)(dfactor)) << PE_PI_CMODE0_DFACTOR_SHIFT) | \
	 (((unsigned long)(sfactor)) << PE_PI_CMODE0_SFACTOR_SHIFT) | \
	 (((unsigned long)(logicop)) << PE_PI_CMODE0_LOGICOP_SHIFT) | \
	 (((unsigned long)(rid)) << PE_PI_CMODE0_RID_SHIFT))

typedef struct {
    unsigned long rid:PE_PI_CMODE0_RID_SIZE;
    unsigned long pad0:PE_PI_CMODE0_PAD0_SIZE;
    unsigned long logicop:PE_PI_CMODE0_LOGICOP_SIZE;
    unsigned long sfactor:PE_PI_CMODE0_SFACTOR_SIZE;
    unsigned long dfactor:PE_PI_CMODE0_DFACTOR_SIZE;
    unsigned long amsk:PE_PI_CMODE0_AMSK_SIZE;
    unsigned long cmsk:PE_PI_CMODE0_CMSK_SIZE;
    unsigned long den:PE_PI_CMODE0_DEN_SIZE;
    unsigned long len:PE_PI_CMODE0_LEN_SIZE;
    unsigned long ben:PE_PI_CMODE0_BEN_SIZE;
} pe_pi_cmode0_t;

typedef union {
    unsigned long val;
    pe_pi_cmode0_t f;
} pe_pi_cmode0_u;

/*
 *  pe_pi_cmode1 struct
 */
#define PE_PI_CMODE1_CONSTALPHA_SIZE	8
#define PE_PI_CMODE1_CONSTALPHA_SHIFT	0
#define PE_PI_CMODE1_CONSTALPHA_MASK	0x000000ff
#define PE_PI_CMODE1_GET_CONSTALPHA(pe_pi_cmode1) \
	((((unsigned long)(pe_pi_cmode1)) & PE_PI_CMODE1_CONSTALPHA_MASK) >> PE_PI_CMODE1_CONSTALPHA_SHIFT)
#define PE_PI_CMODE1_SET_CONSTALPHA(pe_pi_cmode1, constAlpha) { \
	FDL_ASSERT(!((constAlpha) & ~((1 << PE_PI_CMODE1_CONSTALPHA_SIZE)-1))); \
	pe_pi_cmode1 = (((unsigned long)(pe_pi_cmode1)) & ~PE_PI_CMODE1_CONSTALPHA_MASK) | (((unsigned long)(constAlpha)) << PE_PI_CMODE1_CONSTALPHA_SHIFT);\
}
#define PE_PI_CMODE1_EN_SIZE	1
#define PE_PI_CMODE1_EN_SHIFT	8
#define PE_PI_CMODE1_EN_MASK	0x00000100
#define PE_PI_CMODE1_GET_EN(pe_pi_cmode1) \
	((((unsigned long)(pe_pi_cmode1)) & PE_PI_CMODE1_EN_MASK) >> PE_PI_CMODE1_EN_SHIFT)
#define PE_PI_CMODE1_SET_EN(pe_pi_cmode1, en) { \
	FDL_ASSERT(!((en) & ~((1 << PE_PI_CMODE1_EN_SIZE)-1))); \
	pe_pi_cmode1 = (((unsigned long)(pe_pi_cmode1)) & ~PE_PI_CMODE1_EN_MASK) | (((unsigned long)(en)) << PE_PI_CMODE1_EN_SHIFT);\
}
#define PE_PI_CMODE1_PAD0_SIZE	15
#define PE_PI_CMODE1_PAD0_SHIFT	9
#define PE_PI_CMODE1_PAD0_MASK	0x00fffe00
#define PE_PI_CMODE1_GET_PAD0(pe_pi_cmode1) \
	((((unsigned long)(pe_pi_cmode1)) & PE_PI_CMODE1_PAD0_MASK) >> PE_PI_CMODE1_PAD0_SHIFT)
#define PE_PI_CMODE1_SET_PAD0(pe_pi_cmode1, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_CMODE1_PAD0_SIZE)-1))); \
	pe_pi_cmode1 = (((unsigned long)(pe_pi_cmode1)) & ~PE_PI_CMODE1_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_CMODE1_PAD0_SHIFT);\
}
#define PE_PI_CMODE1_RID_SIZE	8
#define PE_PI_CMODE1_RID_SHIFT	24
#define PE_PI_CMODE1_RID_MASK	0xff000000
#define PE_PI_CMODE1_GET_RID(pe_pi_cmode1) \
	((((unsigned long)(pe_pi_cmode1)) & PE_PI_CMODE1_RID_MASK) >> PE_PI_CMODE1_RID_SHIFT)
#define PE_PI_CMODE1_SET_RID(pe_pi_cmode1, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << PE_PI_CMODE1_RID_SIZE)-1))); \
	pe_pi_cmode1 = (((unsigned long)(pe_pi_cmode1)) & ~PE_PI_CMODE1_RID_MASK) | (((unsigned long)(rid)) << PE_PI_CMODE1_RID_SHIFT);\
}
#define PE_PI_CMODE1_TOTAL_SIZE	32
#define PE_PI_CMODE1(constAlpha, en, rid) \
	((((unsigned long)(constAlpha)) << PE_PI_CMODE1_CONSTALPHA_SHIFT) | \
	 (((unsigned long)(en)) << PE_PI_CMODE1_EN_SHIFT) | \
	 (((unsigned long)(rid)) << PE_PI_CMODE1_RID_SHIFT))

typedef struct {
    unsigned long rid:PE_PI_CMODE1_RID_SIZE;
    unsigned long pad0:PE_PI_CMODE1_PAD0_SIZE;
    unsigned long en:PE_PI_CMODE1_EN_SIZE;
    unsigned long constAlpha:PE_PI_CMODE1_CONSTALPHA_SIZE;
} pe_pi_cmode1_t;

typedef union {
    unsigned long val;
    pe_pi_cmode1_t f;
} pe_pi_cmode1_u;

/*
 *  pe_pi_alpha_threshold struct
 */
#define PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SIZE	8
#define PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SHIFT	0
#define PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_MASK	0x000000ff
#define PE_PI_ALPHA_THRESHOLD_GET_ALPHA_THRESHOLD(pe_pi_alpha_threshold) \
	((((unsigned long)(pe_pi_alpha_threshold)) & PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_MASK) >> PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SHIFT)
#define PE_PI_ALPHA_THRESHOLD_SET_ALPHA_THRESHOLD(pe_pi_alpha_threshold, alpha_threshold) { \
	FDL_ASSERT(!((alpha_threshold) & ~((1 << PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SIZE)-1))); \
	pe_pi_alpha_threshold = (((unsigned long)(pe_pi_alpha_threshold)) & ~PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_MASK) | (((unsigned long)(alpha_threshold)) << PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SHIFT);\
}
#define PE_PI_ALPHA_THRESHOLD_AFUNCTION_SIZE	3
#define PE_PI_ALPHA_THRESHOLD_AFUNCTION_SHIFT	8
#define PE_PI_ALPHA_THRESHOLD_AFUNCTION_MASK	0x00000700
#define PE_PI_ALPHA_THRESHOLD_GET_AFUNCTION(pe_pi_alpha_threshold) \
	((((unsigned long)(pe_pi_alpha_threshold)) & PE_PI_ALPHA_THRESHOLD_AFUNCTION_MASK) >> PE_PI_ALPHA_THRESHOLD_AFUNCTION_SHIFT)
#define PE_PI_ALPHA_THRESHOLD_SET_AFUNCTION(pe_pi_alpha_threshold, afunction) { \
	FDL_ASSERT(!((afunction) & ~((1 << PE_PI_ALPHA_THRESHOLD_AFUNCTION_SIZE)-1))); \
	pe_pi_alpha_threshold = (((unsigned long)(pe_pi_alpha_threshold)) & ~PE_PI_ALPHA_THRESHOLD_AFUNCTION_MASK) | (((unsigned long)(afunction)) << PE_PI_ALPHA_THRESHOLD_AFUNCTION_SHIFT);\
}
#define PE_PI_ALPHA_THRESHOLD_PAD0_SIZE	13
#define PE_PI_ALPHA_THRESHOLD_PAD0_SHIFT	11
#define PE_PI_ALPHA_THRESHOLD_PAD0_MASK	0x00fff800
#define PE_PI_ALPHA_THRESHOLD_GET_PAD0(pe_pi_alpha_threshold) \
	((((unsigned long)(pe_pi_alpha_threshold)) & PE_PI_ALPHA_THRESHOLD_PAD0_MASK) >> PE_PI_ALPHA_THRESHOLD_PAD0_SHIFT)
#define PE_PI_ALPHA_THRESHOLD_SET_PAD0(pe_pi_alpha_threshold, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_ALPHA_THRESHOLD_PAD0_SIZE)-1))); \
	pe_pi_alpha_threshold = (((unsigned long)(pe_pi_alpha_threshold)) & ~PE_PI_ALPHA_THRESHOLD_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_ALPHA_THRESHOLD_PAD0_SHIFT);\
}
#define PE_PI_ALPHA_THRESHOLD_RID_SIZE	8
#define PE_PI_ALPHA_THRESHOLD_RID_SHIFT	24
#define PE_PI_ALPHA_THRESHOLD_RID_MASK	0xff000000
#define PE_PI_ALPHA_THRESHOLD_GET_RID(pe_pi_alpha_threshold) \
	((((unsigned long)(pe_pi_alpha_threshold)) & PE_PI_ALPHA_THRESHOLD_RID_MASK) >> PE_PI_ALPHA_THRESHOLD_RID_SHIFT)
#define PE_PI_ALPHA_THRESHOLD_SET_RID(pe_pi_alpha_threshold, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << PE_PI_ALPHA_THRESHOLD_RID_SIZE)-1))); \
	pe_pi_alpha_threshold = (((unsigned long)(pe_pi_alpha_threshold)) & ~PE_PI_ALPHA_THRESHOLD_RID_MASK) | (((unsigned long)(rid)) << PE_PI_ALPHA_THRESHOLD_RID_SHIFT);\
}
#define PE_PI_ALPHA_THRESHOLD_TOTAL_SIZE	32
#define PE_PI_ALPHA_THRESHOLD(alpha_threshold, afunction, rid) \
	((((unsigned long)(alpha_threshold)) << PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SHIFT) | \
	 (((unsigned long)(afunction)) << PE_PI_ALPHA_THRESHOLD_AFUNCTION_SHIFT) | \
	 (((unsigned long)(rid)) << PE_PI_ALPHA_THRESHOLD_RID_SHIFT))

typedef struct {
    unsigned long rid:PE_PI_ALPHA_THRESHOLD_RID_SIZE;
    unsigned long pad0:PE_PI_ALPHA_THRESHOLD_PAD0_SIZE;
    unsigned long afunction:PE_PI_ALPHA_THRESHOLD_AFUNCTION_SIZE;
    unsigned long alpha_threshold:PE_PI_ALPHA_THRESHOLD_ALPHA_THRESHOLD_SIZE;
} pe_pi_alpha_threshold_t;

typedef union {
    unsigned long val;
    pe_pi_alpha_threshold_t f;
} pe_pi_alpha_threshold_u;

/*
 *  pe_pi_ctl struct
 */
#define PE_PI_CTL_AFMT_SIZE	2
#define PE_PI_CTL_AFMT_SHIFT	0
#define PE_PI_CTL_AFMT_MASK	0x00000003
#define PE_PI_CTL_GET_AFMT(pe_pi_ctl) \
	((((unsigned long)(pe_pi_ctl)) & PE_PI_CTL_AFMT_MASK) >> PE_PI_CTL_AFMT_SHIFT)
#define PE_PI_CTL_SET_AFMT(pe_pi_ctl, afmt) { \
	FDL_ASSERT(!((afmt) & ~((1 << PE_PI_CTL_AFMT_SIZE)-1))); \
	pe_pi_ctl = (((unsigned long)(pe_pi_ctl)) & ~PE_PI_CTL_AFMT_MASK) | (((unsigned long)(afmt)) << PE_PI_CTL_AFMT_SHIFT);\
}
#define PE_PI_CTL_ZFMT_SIZE	1
#define PE_PI_CTL_ZFMT_SHIFT	2
#define PE_PI_CTL_ZFMT_MASK	0x00000004
#define PE_PI_CTL_GET_ZFMT(pe_pi_ctl) \
	((((unsigned long)(pe_pi_ctl)) & PE_PI_CTL_ZFMT_MASK) >> PE_PI_CTL_ZFMT_SHIFT)
#define PE_PI_CTL_SET_ZFMT(pe_pi_ctl, zfmt) { \
	FDL_ASSERT(!((zfmt) & ~((1 << PE_PI_CTL_ZFMT_SIZE)-1))); \
	pe_pi_ctl = (((unsigned long)(pe_pi_ctl)) & ~PE_PI_CTL_ZFMT_MASK) | (((unsigned long)(zfmt)) << PE_PI_CTL_ZFMT_SHIFT);\
}
#define PE_PI_CTL_PAD0_SIZE	21
#define PE_PI_CTL_PAD0_SHIFT	3
#define PE_PI_CTL_PAD0_MASK	0x00fffff8
#define PE_PI_CTL_GET_PAD0(pe_pi_ctl) \
	((((unsigned long)(pe_pi_ctl)) & PE_PI_CTL_PAD0_MASK) >> PE_PI_CTL_PAD0_SHIFT)
#define PE_PI_CTL_SET_PAD0(pe_pi_ctl, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PE_PI_CTL_PAD0_SIZE)-1))); \
	pe_pi_ctl = (((unsigned long)(pe_pi_ctl)) & ~PE_PI_CTL_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PI_CTL_PAD0_SHIFT);\
}
#define PE_PI_CTL_RID_SIZE	8
#define PE_PI_CTL_RID_SHIFT	24
#define PE_PI_CTL_RID_MASK	0xff000000
#define PE_PI_CTL_GET_RID(pe_pi_ctl) \
	((((unsigned long)(pe_pi_ctl)) & PE_PI_CTL_RID_MASK) >> PE_PI_CTL_RID_SHIFT)
#define PE_PI_CTL_SET_RID(pe_pi_ctl, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << PE_PI_CTL_RID_SIZE)-1))); \
	pe_pi_ctl = (((unsigned long)(pe_pi_ctl)) & ~PE_PI_CTL_RID_MASK) | (((unsigned long)(rid)) << PE_PI_CTL_RID_SHIFT);\
}
#define PE_PI_CTL_TOTAL_SIZE	32
#define PE_PI_CTL(afmt, zfmt, rid) \
	((((unsigned long)(afmt)) << PE_PI_CTL_AFMT_SHIFT) | \
	 (((unsigned long)(zfmt)) << PE_PI_CTL_ZFMT_SHIFT) | \
	 (((unsigned long)(rid)) << PE_PI_CTL_RID_SHIFT))

typedef struct {
    unsigned long rid:PE_PI_CTL_RID_SIZE;
    unsigned long pad0:PE_PI_CTL_PAD0_SIZE;
    unsigned long zfmt:PE_PI_CTL_ZFMT_SIZE;
    unsigned long afmt:PE_PI_CTL_AFMT_SIZE;
} pe_pi_ctl_t;

typedef union {
    unsigned long val;
    pe_pi_ctl_t f;
} pe_pi_ctl_u;


#endif /* __PE_MISC_H__ */
