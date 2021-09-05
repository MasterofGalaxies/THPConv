/*
 *  xf_cmds.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from xf_cmds.fdl
 */

#ifndef __XF_CMDS_H__
#define __XF_CMDS_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  xf_cmd enum
 */
#define XF_CMD_VERTEX_GX	0x00000000
#define XF_CMD_VERTEX_GY	0x00000001
#define XF_CMD_VERTEX_GZ	0x00000002
#define XF_CMD_VERTEX_NX	0x00000003
#define XF_CMD_VERTEX_NY	0x00000004
#define XF_CMD_VERTEX_NZ	0x00000005
#define XF_CMD_VERTEX_C0	0x00000006
#define XF_CMD_VERTEX_C1	0x00000007
#define XF_CMD_VERTEX_S0	0x00000008
#define XF_CMD_VERTEX_T0	0x00000009
#define XF_CMD_UNUSED_10	0x0000000a
#define XF_CMD_VERTEX_S1	0x0000000b
#define XF_CMD_VERTEX_T1	0x0000000c
#define XF_CMD_UNUSED_13	0x0000000d
#define XF_CMD_VERTEX_S2	0x0000000e
#define XF_CMD_VERTEX_T2	0x0000000f
#define XF_CMD_UNUSED_16	0x00000010
#define XF_CMD_VERTEX_S3	0x00000011
#define XF_CMD_VERTEX_T3	0x00000012
#define XF_CMD_UNUSED_19	0x00000013
#define XF_CMD_VERTEX_S4	0x00000014
#define XF_CMD_VERTEX_T4	0x00000015
#define XF_CMD_UNUSED_22	0x00000016
#define XF_CMD_VERTEX_S5	0x00000017
#define XF_CMD_VERTEX_T5	0x00000018
#define XF_CMD_UNUSED_25	0x00000019
#define XF_CMD_VERTEX_S6	0x0000001a
#define XF_CMD_VERTEX_T6	0x0000001b
#define XF_CMD_UNUSED_28	0x0000001c
#define XF_CMD_VERTEX_S7	0x0000001d
#define XF_CMD_VERTEX_T7	0x0000001e
#define XF_CMD_UNUSED_31	0x0000001f
#define XF_CMD_IQUAD_GX	0x00000020
#define XF_CMD_UNUSED_33	0x00000021
#define XF_CMD_ITRI_GX	0x00000022
#define XF_CMD_STRI_GX	0x00000023
#define XF_CMD_FTRI_GX	0x00000024
#define XF_CMD_ILINE_GX	0x00000025
#define XF_CMD_SLINE_GX	0x00000026
#define XF_CMD_POINT_GX	0x00000027
#define XF_CMD_MATRIXINDEXA	0x00000028
#define XF_CMD_MATRIXINDEXB	0x00000029
#define XF_CMD_TX	0x0000002a
#define XF_CMD_TY	0x0000002b
#define XF_CMD_TZ	0x0000002c
#define XF_CMD_BX	0x0000002d
#define XF_CMD_BY	0x0000002e
#define XF_CMD_BZ	0x0000002f
#define XF_CMD_REGLOAD	0x00000030
#define XF_CMD_REGDATA	0x00000031
#define XF_CMD_REGREAD	0x00000032
#define XF_CMD_UNUSED_51	0x00000033
#define XF_CMD_UNUSED_52	0x00000034
#define XF_CMD_UNUSED_53	0x00000035
#define XF_CMD_UNUSED_54	0x00000036
#define XF_CMD_UNUSED_55	0x00000037
#define XF_CMD_UNUSED_56	0x00000038
#define XF_CMD_UNUSED_57	0x00000039
#define XF_CMD_UNUSED_58	0x0000003a
#define XF_CMD_UNUSED_59	0x0000003b
#define XF_CMD_UNUSED_60	0x0000003c
#define XF_CMD_UNUSED_61	0x0000003d
#define XF_CMD_UNUSED_62	0x0000003e
#define XF_CMD_UNUSED_63	0x0000003f
#define XF_SU_CMDS	0x00000040
#define XF_CMD_UNUSED_65	0x00000041
#define XF_CMD_UNUSED_66	0x00000042
#define XF_CMD_UNUSED_67	0x00000043
#define XF_CMD_UNUSED_68	0x00000044
#define XF_CMD_UNUSED_69	0x00000045
#define XF_CMD_UNUSED_70	0x00000046
#define XF_CMD_UNUSED_71	0x00000047
#define XF_CMD_UNUSED_72	0x00000048
#define XF_CMD_UNUSED_73	0x00000049
#define XF_CMD_UNUSED_74	0x0000004a
#define XF_CMD_UNUSED_75	0x0000004b
#define XF_CMD_UNUSED_76	0x0000004c
#define XF_CMD_UNUSED_77	0x0000004d
#define XF_CMD_UNUSED_78	0x0000004e
#define XF_CMD_UNUSED_79	0x0000004f
#define XF_CMD_UNUSED_80	0x00000050
#define XF_CMD_UNUSED_81	0x00000051
#define XF_CMD_UNUSED_82	0x00000052
#define XF_CMD_UNUSED_83	0x00000053
#define XF_CMD_UNUSED_84	0x00000054
#define XF_CMD_UNUSED_85	0x00000055
#define XF_CMD_UNUSED_86	0x00000056
#define XF_CMD_UNUSED_87	0x00000057
#define XF_CMD_UNUSED_88	0x00000058
#define XF_CMD_UNUSED_89	0x00000059
#define XF_CMD_UNUSED_90	0x0000005a
#define XF_CMD_UNUSED_91	0x0000005b
#define XF_CMD_UNUSED_92	0x0000005c
#define XF_CMD_UNUSED_93	0x0000005d
#define XF_CMD_UNUSED_94	0x0000005e
#define XF_CMD_UNUSED_95	0x0000005f
#define XF_CMD_UNUSED_96	0x00000060
#define XF_CMD_UNUSED_97	0x00000061
#define XF_CMD_UNUSED_98	0x00000062
#define XF_CMD_UNUSED_99	0x00000063
#define XF_CMD_UNUSED_100	0x00000064
#define XF_CMD_UNUSED_101	0x00000065
#define XF_CMD_UNUSED_102	0x00000066
#define XF_CMD_UNUSED_103	0x00000067
#define XF_CMD_UNUSED_104	0x00000068
#define XF_CMD_UNUSED_105	0x00000069
#define XF_CMD_UNUSED_106	0x0000006a
#define XF_CMD_UNUSED_107	0x0000006b
#define XF_CMD_UNUSED_108	0x0000006c
#define XF_CMD_UNUSED_109	0x0000006d
#define XF_CMD_UNUSED_110	0x0000006e
#define XF_CMD_UNUSED_111	0x0000006f
#define XF_CMD_UNUSED_112	0x00000070
#define XF_CMD_UNUSED_113	0x00000071
#define XF_CMD_UNUSED_114	0x00000072
#define XF_CMD_UNUSED_115	0x00000073
#define XF_CMD_UNUSED_116	0x00000074
#define XF_CMD_UNUSED_117	0x00000075
#define XF_CMD_UNUSED_118	0x00000076
#define XF_CMD_UNUSED_119	0x00000077
#define XF_CMD_UNUSED_120	0x00000078
#define XF_CMD_UNUSED_121	0x00000079
#define XF_CMD_UNUSED_122	0x0000007a
#define XF_CMD_UNUSED_123	0x0000007b
#define XF_CMD_UNUSED_124	0x0000007c
#define XF_CMD_UNUSED_125	0x0000007d
#define XF_CMD_UNUSED_126	0x0000007e
#define XF_CMD_UNUSED_127	0x0000007f

/*
 *  regload struct
 */
#define REGLOAD_ADDRS_SIZE	16
#define REGLOAD_ADDRS_SHIFT	0
#define REGLOAD_ADDRS_MASK	0x0000ffff
#define REGLOAD_GET_ADDRS(regload) \
	((((unsigned long)(regload)) & REGLOAD_ADDRS_MASK) >> REGLOAD_ADDRS_SHIFT)
#define REGLOAD_SET_ADDRS(regload, addrs) { \
	FDL_ASSERT(!((addrs) & ~((1 << REGLOAD_ADDRS_SIZE)-1))); \
	regload = (((unsigned long)(regload)) & ~REGLOAD_ADDRS_MASK) | (((unsigned long)(addrs)) << REGLOAD_ADDRS_SHIFT);\
}
#define REGLOAD_COUNT_SIZE	5
#define REGLOAD_COUNT_SHIFT	16
#define REGLOAD_COUNT_MASK	0x001f0000
#define REGLOAD_GET_COUNT(regload) \
	((((unsigned long)(regload)) & REGLOAD_COUNT_MASK) >> REGLOAD_COUNT_SHIFT)
#define REGLOAD_SET_COUNT(regload, count) { \
	FDL_ASSERT(!((count) & ~((1 << REGLOAD_COUNT_SIZE)-1))); \
	regload = (((unsigned long)(regload)) & ~REGLOAD_COUNT_MASK) | (((unsigned long)(count)) << REGLOAD_COUNT_SHIFT);\
}
#define REGLOAD_UNUSED_SIZE	11
#define REGLOAD_UNUSED_SHIFT	21
#define REGLOAD_UNUSED_MASK	0xffe00000
#define REGLOAD_GET_UNUSED(regload) \
	((((unsigned long)(regload)) & REGLOAD_UNUSED_MASK) >> REGLOAD_UNUSED_SHIFT)
#define REGLOAD_SET_UNUSED(regload, unused) { \
	FDL_ASSERT(!((unused) & ~((1 << REGLOAD_UNUSED_SIZE)-1))); \
	regload = (((unsigned long)(regload)) & ~REGLOAD_UNUSED_MASK) | (((unsigned long)(unused)) << REGLOAD_UNUSED_SHIFT);\
}
#define REGLOAD_TOTAL_SIZE	32
#define REGLOAD(addrs, count, unused) \
	((((unsigned long)(addrs)) << REGLOAD_ADDRS_SHIFT) | \
	 (((unsigned long)(count)) << REGLOAD_COUNT_SHIFT) | \
	 (((unsigned long)(unused)) << REGLOAD_UNUSED_SHIFT))

typedef struct {
    unsigned long unused:REGLOAD_UNUSED_SIZE;
    unsigned long count:REGLOAD_COUNT_SIZE;
    unsigned long addrs:REGLOAD_ADDRS_SIZE;
} regload_t;

typedef union {
    unsigned long val;
    regload_t f;
} regload_u;

/*
 *  regread struct
 */
#define REGREAD_ADDRS_SIZE	16
#define REGREAD_ADDRS_SHIFT	0
#define REGREAD_ADDRS_MASK	0x0000ffff
#define REGREAD_GET_ADDRS(regread) \
	((((unsigned long)(regread)) & REGREAD_ADDRS_MASK) >> REGREAD_ADDRS_SHIFT)
#define REGREAD_SET_ADDRS(regread, addrs) { \
	FDL_ASSERT(!((addrs) & ~((1 << REGREAD_ADDRS_SIZE)-1))); \
	regread = (((unsigned long)(regread)) & ~REGREAD_ADDRS_MASK) | (((unsigned long)(addrs)) << REGREAD_ADDRS_SHIFT);\
}
#define REGREAD_TOTAL_SIZE	16
#define REGREAD_UNUSED_SIZE	16

#define REGREAD(addrs) \
	((((unsigned long)(addrs)) << REGREAD_ADDRS_SHIFT))

typedef struct {
    unsigned long unused:REGREAD_UNUSED_SIZE;
    unsigned long addrs:REGREAD_ADDRS_SIZE;
} regread_t;

typedef union {
    unsigned long val;
    regread_t f;
} regread_u;

/*
 *  xf_inputrowdata enum
 */
#define XF_GEOM_INROW	0x00000000
#define XF_NORMAL_INROW	0x00000001
#define XF_COLORS_INROW	0x00000002
#define XF_BINORMAL_T_INROW	0x00000003
#define XF_BINORMAL_B_INROW	0x00000004
#define XF_TEX0_INROW	0x00000005
#define XF_TEX1_INROW	0x00000006
#define XF_TEX2_INROW	0x00000007
#define XF_TEX3_INROW	0x00000008
#define XF_TEX4_INROW	0x00000009
#define XF_TEX5_INROW	0x0000000a
#define XF_TEX6_INROW	0x0000000b
#define XF_TEX7_INROW	0x0000000c
#define XF_INPUTROWDATA_UNUSED_13	0x0000000d
#define XF_INPUTROWDATA_UNUSED_14	0x0000000e
#define XF_INPUTROWDATA_UNUSED_15	0x0000000f

/*
 *  xf_vertcmds value
 */
#define VERT_POINT	0x1
#define VERT_SLINE	0x2
#define VERT_ILINE	0x2
#define VERT_FTRI	0x3
#define VERT_STRI	0x3
#define VERT_ITRI	0x3
#define VERT_IQUAD	0x3

/*
 *  xf_intcmds enum
 */
#define XF_BYPASS	0x00000000
#define XF_GVERTEX	0x00000001
#define XF_IQUAD	0x00000002
#define XF_ITRI	0x00000003
#define XF_STRI	0x00000004
#define XF_FTRI	0x00000005
#define XF_ILINE	0x00000006
#define XF_SLINE	0x00000007
#define XF_POINT	0x00000008
#define XF_INTCMDS_UNUSED_9	0x00000009
#define XF_INTCMDS_UNUSED_10	0x0000000a
#define XF_INTCMDS_UNUSED_11	0x0000000b
#define XF_INTCMDS_UNUSED_12	0x0000000c
#define XF_INTCMDS_UNUSED_13	0x0000000d
#define XF_INTCMDS_UNUSED_14	0x0000000e
#define XF_NODRAW	0x0000000f

/*
 *  xf_outcmds enum
 */
#define XF_OUT_CMD_NOP	0x00000000
#define XF_OUT_CMD_REGISTER	0x00000001
#define XF_OUT_CMD_TSTRIP_ODD	0x00000002
#define XF_OUT_CMD_TSTRIP_EVEN	0x00000003
#define XF_OUT_CMD_TFAN	0x00000004
#define XF_OUT_CMD_POINTS	0x00000005
#define XF_OUT_CMD_LINES	0x00000006
#define XF_OUT_CMD_POLY	0x00000007
#define XF_OUT_CMD_CONT	0x00000008
#define XF_OUT_CMD_CONT_NODRAW	0x00000009
#define XF_OUTCMDS_UNUSED_10	0x0000000a
#define XF_OUTCMDS_UNUSED_11	0x0000000b
#define XF_OUTCMDS_UNUSED_12	0x0000000c
#define XF_OUTCMDS_UNUSED_13	0x0000000d
#define XF_OUTCMDS_UNUSED_14	0x0000000e
#define XF_OUTCMDS_UNUSED_15	0x0000000f


#endif /* __XF_CMDS_H__ */
