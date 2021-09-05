/*
 *  akehd_dac_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from akehd_dac_reg.fdl
 *
 */

#ifndef __AKEHD_DAC_REG_H__
#define __AKEHD_DAC_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c)
#endif

/*
 *  ake_reg value
 */
#define AKE_R00	0x00
#define AKE_R01	0x01
#define AKE_R02	0x02
#define AKE_R03	0x03
#define AKE_R04	0x04
#define AKE_R05	0x05
#define AKE_R06	0x06
#define AKE_R08	0x08
#define AKE_R09	0x09
#define AKE_R0A	0x0A
#define AKE_R0D	0x0D
#define AKE_R0E	0x0E
#define AKE_R0F	0x0F
#define AKE_R10	0x10
#define AKE_R11	0x11
#define AKE_R12	0x12
#define AKE_R13	0x13
#define AKE_R14	0x14
#define AKE_R15	0x15
#define AKE_R16	0x16
#define AKE_R17	0x17
#define AKE_R18	0x18
#define AKE_R19	0x19
#define AKE_R1A	0x1A
#define AKE_R1B	0x1B
#define AKE_R1C	0x1C
#define AKE_R1D	0x1D
#define AKE_R1E	0x1E
#define AKE_R1F	0x1F
#define AKE_R20	0x20
#define AKE_R21	0x21
#define AKE_R22	0x22
#define AKE_R23	0x23
#define AKE_R24	0x24
#define AKE_R25	0x25
#define AKE_R26	0x26
#define AKE_R27	0x27
#define AKE_R28	0x28
#define AKE_R29	0x29
#define AKE_R2A	0x2A
#define AKE_R2B	0x2B
#define AKE_R2C	0x2C
#define AKE_R2D	0x2D
#define AKE_R2E	0x2E
#define AKE_R2F	0x2F
#define AKE_R30	0x30
#define AKE_R6A	0x6A
#define AKE_R71	0x71
#define AKE_R72	0x72
#define AKE_R7A	0x7A
#define AKE_R7B	0x7B
#define AKE_R7C	0x7C
#define AKE_R7D	0x7D
#define AKE_R7F	0x7F

/*
 *  ake_r00_reg struct
 */
#define AKE_R00_REG_TIMING_SIZE	1
#define AKE_R00_REG_TIMING_SHIFT	0
#define AKE_R00_REG_TIMING_MASK	0x00000001
#define AKE_R00_REG_GET_TIMING(ake_r00_reg) \
	((((unsigned long)(ake_r00_reg)) & AKE_R00_REG_TIMING_MASK) >> AKE_R00_REG_TIMING_SHIFT)
#define AKE_R00_REG_SET_TIMING(ake_r00_reg, timing) { \
	FDL_ASSERT(!((timing) & ~((1 << AKE_R00_REG_TIMING_SIZE)-1))); \
	ake_r00_reg = (((unsigned long)(ake_r00_reg)) & ~AKE_R00_REG_TIMING_MASK) | (((unsigned long)(timing)) << AKE_R00_REG_TIMING_SHIFT); \
}

#define AKE_R00_REG_TOTAL_SIZE	8
#define AKE_R00_REG(timing) \
	((((unsigned long)(timing)) << AKE_R00_REG_TIMING_SHIFT))

/*
 *  ake_r01_reg struct
 */
#define AKE_R01_REG_MODE0_SIZE	1
#define AKE_R01_REG_MODE0_SHIFT	0
#define AKE_R01_REG_MODE0_MASK	0x00000001
#define AKE_R01_REG_GET_MODE0(ake_r01_reg) \
	((((unsigned long)(ake_r01_reg)) & AKE_R01_REG_MODE0_MASK) >> AKE_R01_REG_MODE0_SHIFT)
#define AKE_R01_REG_SET_MODE0(ake_r01_reg, mode0) { \
	FDL_ASSERT(!((mode0) & ~((1 << AKE_R01_REG_MODE0_SIZE)-1))); \
	ake_r01_reg = (((unsigned long)(ake_r01_reg)) & ~AKE_R01_REG_MODE0_MASK) | (((unsigned long)(mode0)) << AKE_R01_REG_MODE0_SHIFT); \
}

#define AKE_R01_REG_MODE1_SIZE	1
#define AKE_R01_REG_MODE1_SHIFT	1
#define AKE_R01_REG_MODE1_MASK	0x00000002
#define AKE_R01_REG_GET_MODE1(ake_r01_reg) \
	((((unsigned long)(ake_r01_reg)) & AKE_R01_REG_MODE1_MASK) >> AKE_R01_REG_MODE1_SHIFT)
#define AKE_R01_REG_SET_MODE1(ake_r01_reg, mode1) { \
	FDL_ASSERT(!((mode1) & ~((1 << AKE_R01_REG_MODE1_SIZE)-1))); \
	ake_r01_reg = (((unsigned long)(ake_r01_reg)) & ~AKE_R01_REG_MODE1_MASK) | (((unsigned long)(mode1)) << AKE_R01_REG_MODE1_SHIFT); \
}

#define AKE_R01_REG_OUTSEL_SIZE	1
#define AKE_R01_REG_OUTSEL_SHIFT	5
#define AKE_R01_REG_OUTSEL_MASK	0x00000020
#define AKE_R01_REG_GET_OUTSEL(ake_r01_reg) \
	((((unsigned long)(ake_r01_reg)) & AKE_R01_REG_OUTSEL_MASK) >> AKE_R01_REG_OUTSEL_SHIFT)
#define AKE_R01_REG_SET_OUTSEL(ake_r01_reg, outsel) { \
	FDL_ASSERT(!((outsel) & ~((1 << AKE_R01_REG_OUTSEL_SIZE)-1))); \
	ake_r01_reg = (((unsigned long)(ake_r01_reg)) & ~AKE_R01_REG_OUTSEL_MASK) | (((unsigned long)(outsel)) << AKE_R01_REG_OUTSEL_SHIFT); \
}

#define AKE_R01_REG_TOTAL_SIZE	8
#define AKE_R01_REG(mode0, mode1, outsel) \
	((((unsigned long)(mode0)) << AKE_R01_REG_MODE0_SHIFT) | \
	 (((unsigned long)(mode1)) << AKE_R01_REG_MODE1_SHIFT) | \
	 (((unsigned long)(outsel)) << AKE_R01_REG_OUTSEL_SHIFT))

/*
 *  ake_r02_reg struct
 */
#define AKE_R02_REG_CC_SIZE	1
#define AKE_R02_REG_CC_SHIFT	0
#define AKE_R02_REG_CC_MASK	0x00000001
#define AKE_R02_REG_GET_CC(ake_r02_reg) \
	((((unsigned long)(ake_r02_reg)) & AKE_R02_REG_CC_MASK) >> AKE_R02_REG_CC_SHIFT)
#define AKE_R02_REG_SET_CC(ake_r02_reg, cc) { \
	FDL_ASSERT(!((cc) & ~((1 << AKE_R02_REG_CC_SIZE)-1))); \
	ake_r02_reg = (((unsigned long)(ake_r02_reg)) & ~AKE_R02_REG_CC_MASK) | (((unsigned long)(cc)) << AKE_R02_REG_CC_SHIFT); \
}

#define AKE_R02_REG_CGMS_SIZE	1
#define AKE_R02_REG_CGMS_SHIFT	1
#define AKE_R02_REG_CGMS_MASK	0x00000002
#define AKE_R02_REG_GET_CGMS(ake_r02_reg) \
	((((unsigned long)(ake_r02_reg)) & AKE_R02_REG_CGMS_MASK) >> AKE_R02_REG_CGMS_SHIFT)
#define AKE_R02_REG_SET_CGMS(ake_r02_reg, cgms) { \
	FDL_ASSERT(!((cgms) & ~((1 << AKE_R02_REG_CGMS_SIZE)-1))); \
	ake_r02_reg = (((unsigned long)(ake_r02_reg)) & ~AKE_R02_REG_CGMS_MASK) | (((unsigned long)(cgms)) << AKE_R02_REG_CGMS_SHIFT); \
}

#define AKE_R02_REG_WSS_SIZE	1
#define AKE_R02_REG_WSS_SHIFT	2
#define AKE_R02_REG_WSS_MASK	0x00000004
#define AKE_R02_REG_GET_WSS(ake_r02_reg) \
	((((unsigned long)(ake_r02_reg)) & AKE_R02_REG_WSS_MASK) >> AKE_R02_REG_WSS_SHIFT)
#define AKE_R02_REG_SET_WSS(ake_r02_reg, wss) { \
	FDL_ASSERT(!((wss) & ~((1 << AKE_R02_REG_WSS_SIZE)-1))); \
	ake_r02_reg = (((unsigned long)(ake_r02_reg)) & ~AKE_R02_REG_WSS_MASK) | (((unsigned long)(wss)) << AKE_R02_REG_WSS_SHIFT); \
}

#define AKE_R02_REG_TOTAL_SIZE	8
#define AKE_R02_REG(cc, cgms, wss) \
	((((unsigned long)(cc)) << AKE_R02_REG_CC_SHIFT) | \
	 (((unsigned long)(cgms)) << AKE_R02_REG_CGMS_SHIFT) | \
	 (((unsigned long)(wss)) << AKE_R02_REG_WSS_SHIFT))

/*
 *  ake_r03_reg struct
 */
#define AKE_R03_REG_TRAP_SIZE	1
#define AKE_R03_REG_TRAP_SHIFT	0
#define AKE_R03_REG_TRAP_MASK	0x00000001
#define AKE_R03_REG_GET_TRAP(ake_r03_reg) \
	((((unsigned long)(ake_r03_reg)) & AKE_R03_REG_TRAP_MASK) >> AKE_R03_REG_TRAP_SHIFT)
#define AKE_R03_REG_SET_TRAP(ake_r03_reg, trap) { \
	FDL_ASSERT(!((trap) & ~((1 << AKE_R03_REG_TRAP_SIZE)-1))); \
	ake_r03_reg = (((unsigned long)(ake_r03_reg)) & ~AKE_R03_REG_TRAP_MASK) | (((unsigned long)(trap)) << AKE_R03_REG_TRAP_SHIFT); \
}

#define AKE_R03_REG_TOTAL_SIZE	8
#define AKE_R03_REG(trap) \
	((((unsigned long)(trap)) << AKE_R03_REG_TRAP_SHIFT))

/*
 *  ake_r04_reg struct
 */
#define AKE_R04_REG_BLOUT_SIZE	1
#define AKE_R04_REG_BLOUT_SHIFT	0
#define AKE_R04_REG_BLOUT_MASK	0x00000001
#define AKE_R04_REG_GET_BLOUT(ake_r04_reg) \
	((((unsigned long)(ake_r04_reg)) & AKE_R04_REG_BLOUT_MASK) >> AKE_R04_REG_BLOUT_SHIFT)
#define AKE_R04_REG_SET_BLOUT(ake_r04_reg, blout) { \
	FDL_ASSERT(!((blout) & ~((1 << AKE_R04_REG_BLOUT_SIZE)-1))); \
	ake_r04_reg = (((unsigned long)(ake_r04_reg)) & ~AKE_R04_REG_BLOUT_MASK) | (((unsigned long)(blout)) << AKE_R04_REG_BLOUT_SHIFT); \
}

#define AKE_R04_REG_CBGEN_SIZE	1
#define AKE_R04_REG_CBGEN_SHIFT	1
#define AKE_R04_REG_CBGEN_MASK	0x00000002
#define AKE_R04_REG_GET_CBGEN(ake_r04_reg) \
	((((unsigned long)(ake_r04_reg)) & AKE_R04_REG_CBGEN_MASK) >> AKE_R04_REG_CBGEN_SHIFT)
#define AKE_R04_REG_SET_CBGEN(ake_r04_reg, cbgen) { \
	FDL_ASSERT(!((cbgen) & ~((1 << AKE_R04_REG_CBGEN_SIZE)-1))); \
	ake_r04_reg = (((unsigned long)(ake_r04_reg)) & ~AKE_R04_REG_CBGEN_MASK) | (((unsigned long)(cbgen)) << AKE_R04_REG_CBGEN_SHIFT); \
}

#define AKE_R04_REG_TOTAL_SIZE	8
#define AKE_R04_REG(blout, cbgen) \
	((((unsigned long)(blout)) << AKE_R04_REG_BLOUT_SHIFT) | \
	 (((unsigned long)(cbgen)) << AKE_R04_REG_CBGEN_SHIFT))

/*
 *  ake_r05_reg struct
 */
#define AKE_R05_REG_WORD0_SIZE	2
#define AKE_R05_REG_WORD0_SHIFT	0
#define AKE_R05_REG_WORD0_MASK	0x00000003
#define AKE_R05_REG_GET_WORD0(ake_r05_reg) \
	((((unsigned long)(ake_r05_reg)) & AKE_R05_REG_WORD0_MASK) >> AKE_R05_REG_WORD0_SHIFT)
#define AKE_R05_REG_SET_WORD0(ake_r05_reg, word0) { \
	FDL_ASSERT(!((word0) & ~((1 << AKE_R05_REG_WORD0_SIZE)-1))); \
	ake_r05_reg = (((unsigned long)(ake_r05_reg)) & ~AKE_R05_REG_WORD0_MASK) | (((unsigned long)(word0)) << AKE_R05_REG_WORD0_SHIFT); \
}

#define AKE_R05_REG_WORD1_SIZE	4
#define AKE_R05_REG_WORD1_SHIFT	2
#define AKE_R05_REG_WORD1_MASK	0x0000003c
#define AKE_R05_REG_GET_WORD1(ake_r05_reg) \
	((((unsigned long)(ake_r05_reg)) & AKE_R05_REG_WORD1_MASK) >> AKE_R05_REG_WORD1_SHIFT)
#define AKE_R05_REG_SET_WORD1(ake_r05_reg, word1) { \
	FDL_ASSERT(!((word1) & ~((1 << AKE_R05_REG_WORD1_SIZE)-1))); \
	ake_r05_reg = (((unsigned long)(ake_r05_reg)) & ~AKE_R05_REG_WORD1_MASK) | (((unsigned long)(word1)) << AKE_R05_REG_WORD1_SHIFT); \
}

#define AKE_R05_REG_TOTAL_SIZE	8
#define AKE_R05_REG(word0, word1) \
	((((unsigned long)(word0)) << AKE_R05_REG_WORD0_SHIFT) | \
	 (((unsigned long)(word1)) << AKE_R05_REG_WORD1_SHIFT))

/*
 *  ake_r06_reg struct
 */
#define AKE_R06_REG_WORD2_SIZE	8
#define AKE_R06_REG_WORD2_SHIFT	0
#define AKE_R06_REG_WORD2_MASK	0x000000ff
#define AKE_R06_REG_GET_WORD2(ake_r06_reg) \
	((((unsigned long)(ake_r06_reg)) & AKE_R06_REG_WORD2_MASK) >> AKE_R06_REG_WORD2_SHIFT)
#define AKE_R06_REG_SET_WORD2(ake_r06_reg, word2) { \
	FDL_ASSERT(!((word2) & ~((1 << AKE_R06_REG_WORD2_SIZE)-1))); \
	ake_r06_reg = (((unsigned long)(ake_r06_reg)) & ~AKE_R06_REG_WORD2_MASK) | (((unsigned long)(word2)) << AKE_R06_REG_WORD2_SHIFT); \
}

#define AKE_R06_REG_TOTAL_SIZE	8
#define AKE_R06_REG(word2) \
	((((unsigned long)(word2)) << AKE_R06_REG_WORD2_SHIFT))

/*
 *  ake_r08_reg struct
 */
#define AKE_R08_REG_GROUP1_SIZE	4
#define AKE_R08_REG_GROUP1_SHIFT	0
#define AKE_R08_REG_GROUP1_MASK	0x0000000f
#define AKE_R08_REG_GET_GROUP1(ake_r08_reg) \
	((((unsigned long)(ake_r08_reg)) & AKE_R08_REG_GROUP1_MASK) >> AKE_R08_REG_GROUP1_SHIFT)
#define AKE_R08_REG_SET_GROUP1(ake_r08_reg, group1) { \
	FDL_ASSERT(!((group1) & ~((1 << AKE_R08_REG_GROUP1_SIZE)-1))); \
	ake_r08_reg = (((unsigned long)(ake_r08_reg)) & ~AKE_R08_REG_GROUP1_MASK) | (((unsigned long)(group1)) << AKE_R08_REG_GROUP1_SHIFT); \
}

#define AKE_R08_REG_GROUP2_SIZE	4
#define AKE_R08_REG_GROUP2_SHIFT	4
#define AKE_R08_REG_GROUP2_MASK	0x000000f0
#define AKE_R08_REG_GET_GROUP2(ake_r08_reg) \
	((((unsigned long)(ake_r08_reg)) & AKE_R08_REG_GROUP2_MASK) >> AKE_R08_REG_GROUP2_SHIFT)
#define AKE_R08_REG_SET_GROUP2(ake_r08_reg, group2) { \
	FDL_ASSERT(!((group2) & ~((1 << AKE_R08_REG_GROUP2_SIZE)-1))); \
	ake_r08_reg = (((unsigned long)(ake_r08_reg)) & ~AKE_R08_REG_GROUP2_MASK) | (((unsigned long)(group2)) << AKE_R08_REG_GROUP2_SHIFT); \
}

#define AKE_R08_REG_TOTAL_SIZE	8
#define AKE_R08_REG(group1, group2) \
	((((unsigned long)(group1)) << AKE_R08_REG_GROUP1_SHIFT) | \
	 (((unsigned long)(group2)) << AKE_R08_REG_GROUP2_SHIFT))

/*
 *  ake_r09_reg struct
 */
#define AKE_R09_REG_GROUP3_SIZE	3
#define AKE_R09_REG_GROUP3_SHIFT	0
#define AKE_R09_REG_GROUP3_MASK	0x00000007
#define AKE_R09_REG_GET_GROUP3(ake_r09_reg) \
	((((unsigned long)(ake_r09_reg)) & AKE_R09_REG_GROUP3_MASK) >> AKE_R09_REG_GROUP3_SHIFT)
#define AKE_R09_REG_SET_GROUP3(ake_r09_reg, group3) { \
	FDL_ASSERT(!((group3) & ~((1 << AKE_R09_REG_GROUP3_SIZE)-1))); \
	ake_r09_reg = (((unsigned long)(ake_r09_reg)) & ~AKE_R09_REG_GROUP3_MASK) | (((unsigned long)(group3)) << AKE_R09_REG_GROUP3_SHIFT); \
}

#define AKE_R09_REG_GROUP4_SIZE	3
#define AKE_R09_REG_GROUP4_SHIFT	3
#define AKE_R09_REG_GROUP4_MASK	0x00000038
#define AKE_R09_REG_GET_GROUP4(ake_r09_reg) \
	((((unsigned long)(ake_r09_reg)) & AKE_R09_REG_GROUP4_MASK) >> AKE_R09_REG_GROUP4_SHIFT)
#define AKE_R09_REG_SET_GROUP4(ake_r09_reg, group4) { \
	FDL_ASSERT(!((group4) & ~((1 << AKE_R09_REG_GROUP4_SIZE)-1))); \
	ake_r09_reg = (((unsigned long)(ake_r09_reg)) & ~AKE_R09_REG_GROUP4_MASK) | (((unsigned long)(group4)) << AKE_R09_REG_GROUP4_SHIFT); \
}

#define AKE_R09_REG_TOTAL_SIZE	8
#define AKE_R09_REG(group3, group4) \
	((((unsigned long)(group3)) << AKE_R09_REG_GROUP3_SHIFT) | \
	 (((unsigned long)(group4)) << AKE_R09_REG_GROUP4_SHIFT))

/*
 *  ake_r0a_reg struct
 */
#define AKE_R0A_REG_ODRIVE_SIZE	1
#define AKE_R0A_REG_ODRIVE_SHIFT	0
#define AKE_R0A_REG_ODRIVE_MASK	0x00000001
#define AKE_R0A_REG_GET_ODRIVE(ake_r0a_reg) \
	((((unsigned long)(ake_r0a_reg)) & AKE_R0A_REG_ODRIVE_MASK) >> AKE_R0A_REG_ODRIVE_SHIFT)
#define AKE_R0A_REG_SET_ODRIVE(ake_r0a_reg, odrive) { \
	FDL_ASSERT(!((odrive) & ~((1 << AKE_R0A_REG_ODRIVE_SIZE)-1))); \
	ake_r0a_reg = (((unsigned long)(ake_r0a_reg)) & ~AKE_R0A_REG_ODRIVE_MASK) | (((unsigned long)(odrive)) << AKE_R0A_REG_ODRIVE_SHIFT); \
}

#define AKE_R0A_REG_ODLVL_SIZE	3
#define AKE_R0A_REG_ODLVL_SHIFT	1
#define AKE_R0A_REG_ODLVL_MASK	0x0000000e
#define AKE_R0A_REG_GET_ODLVL(ake_r0a_reg) \
	((((unsigned long)(ake_r0a_reg)) & AKE_R0A_REG_ODLVL_MASK) >> AKE_R0A_REG_ODLVL_SHIFT)
#define AKE_R0A_REG_SET_ODLVL(ake_r0a_reg, odlvl) { \
	FDL_ASSERT(!((odlvl) & ~((1 << AKE_R0A_REG_ODLVL_SIZE)-1))); \
	ake_r0a_reg = (((unsigned long)(ake_r0a_reg)) & ~AKE_R0A_REG_ODLVL_MASK) | (((unsigned long)(odlvl)) << AKE_R0A_REG_ODLVL_SHIFT); \
}

#define AKE_R0A_REG_TOTAL_SIZE	8
#define AKE_R0A_REG(odrive, odlvl) \
	((((unsigned long)(odrive)) << AKE_R0A_REG_ODRIVE_SHIFT) | \
	 (((unsigned long)(odlvl)) << AKE_R0A_REG_ODLVL_SHIFT))

/*
 *  ake_r0d_reg struct
 */
#define AKE_R0D_REG_PLLEN_SIZE	1
#define AKE_R0D_REG_PLLEN_SHIFT	0
#define AKE_R0D_REG_PLLEN_MASK	0x00000001
#define AKE_R0D_REG_GET_PLLEN(ake_r0d_reg) \
	((((unsigned long)(ake_r0d_reg)) & AKE_R0D_REG_PLLEN_MASK) >> AKE_R0D_REG_PLLEN_SHIFT)
#define AKE_R0D_REG_SET_PLLEN(ake_r0d_reg, pllen) { \
	FDL_ASSERT(!((pllen) & ~((1 << AKE_R0D_REG_PLLEN_SIZE)-1))); \
	ake_r0d_reg = (((unsigned long)(ake_r0d_reg)) & ~AKE_R0D_REG_PLLEN_MASK) | (((unsigned long)(pllen)) << AKE_R0D_REG_PLLEN_SHIFT); \
}

#define AKE_R0D_REG_TOTAL_SIZE	8
#define AKE_R0D_REG(pllen) \
	((((unsigned long)(pllen)) << AKE_R0D_REG_PLLEN_SHIFT))

/*
 *  ake_r0f_reg struct
 */
#define AKE_R0F_REG_ASPECT0_SIZE	1
#define AKE_R0F_REG_ASPECT0_SHIFT	0
#define AKE_R0F_REG_ASPECT0_MASK	0x00000001
#define AKE_R0F_REG_GET_ASPECT0(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_ASPECT0_MASK) >> AKE_R0F_REG_ASPECT0_SHIFT)
#define AKE_R0F_REG_SET_ASPECT0(ake_r0f_reg, aspect0) { \
	FDL_ASSERT(!((aspect0) & ~((1 << AKE_R0F_REG_ASPECT0_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_ASPECT0_MASK) | (((unsigned long)(aspect0)) << AKE_R0F_REG_ASPECT0_SHIFT); \
}

#define AKE_R0F_REG_ASPECT1_SIZE	1
#define AKE_R0F_REG_ASPECT1_SHIFT	1
#define AKE_R0F_REG_ASPECT1_MASK	0x00000002
#define AKE_R0F_REG_GET_ASPECT1(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_ASPECT1_MASK) >> AKE_R0F_REG_ASPECT1_SHIFT)
#define AKE_R0F_REG_SET_ASPECT1(ake_r0f_reg, aspect1) { \
	FDL_ASSERT(!((aspect1) & ~((1 << AKE_R0F_REG_ASPECT1_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_ASPECT1_MASK) | (((unsigned long)(aspect1)) << AKE_R0F_REG_ASPECT1_SHIFT); \
}

#define AKE_R0F_REG_HVPOL_SIZE	1
#define AKE_R0F_REG_HVPOL_SHIFT	3
#define AKE_R0F_REG_HVPOL_MASK	0x00000008
#define AKE_R0F_REG_GET_HVPOL(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_HVPOL_MASK) >> AKE_R0F_REG_HVPOL_SHIFT)
#define AKE_R0F_REG_SET_HVPOL(ake_r0f_reg, hvpol) { \
	FDL_ASSERT(!((hvpol) & ~((1 << AKE_R0F_REG_HVPOL_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_HVPOL_MASK) | (((unsigned long)(hvpol)) << AKE_R0F_REG_HVPOL_SHIFT); \
}

#define AKE_R0F_REG_DTEXCNG_SIZE	1
#define AKE_R0F_REG_DTEXCNG_SHIFT	4
#define AKE_R0F_REG_DTEXCNG_MASK	0x00000010
#define AKE_R0F_REG_GET_DTEXCNG(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_DTEXCNG_MASK) >> AKE_R0F_REG_DTEXCNG_SHIFT)
#define AKE_R0F_REG_SET_DTEXCNG(ake_r0f_reg, dtexcng) { \
	FDL_ASSERT(!((dtexcng) & ~((1 << AKE_R0F_REG_DTEXCNG_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_DTEXCNG_MASK) | (((unsigned long)(dtexcng)) << AKE_R0F_REG_DTEXCNG_SHIFT); \
}

#define AKE_R0F_REG_D3D4_SIZE	1
#define AKE_R0F_REG_D3D4_SHIFT	5
#define AKE_R0F_REG_D3D4_MASK	0x00000020
#define AKE_R0F_REG_GET_D3D4(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_D3D4_MASK) >> AKE_R0F_REG_D3D4_SHIFT)
#define AKE_R0F_REG_SET_D3D4(ake_r0f_reg, d3d4) { \
	FDL_ASSERT(!((d3d4) & ~((1 << AKE_R0F_REG_D3D4_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_D3D4_MASK) | (((unsigned long)(d3d4)) << AKE_R0F_REG_D3D4_SHIFT); \
}

#define AKE_R0F_REG_VFRQ_SIZE	1
#define AKE_R0F_REG_VFRQ_SHIFT	6
#define AKE_R0F_REG_VFRQ_MASK	0x00000040
#define AKE_R0F_REG_GET_VFRQ(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_VFRQ_MASK) >> AKE_R0F_REG_VFRQ_SHIFT)
#define AKE_R0F_REG_SET_VFRQ(ake_r0f_reg, vfrq) { \
	FDL_ASSERT(!((vfrq) & ~((1 << AKE_R0F_REG_VFRQ_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_VFRQ_MASK) | (((unsigned long)(vfrq)) << AKE_R0F_REG_VFRQ_SHIFT); \
}

#define AKE_R0F_REG_HDENC_SIZE	1
#define AKE_R0F_REG_HDENC_SHIFT	7
#define AKE_R0F_REG_HDENC_MASK	0x00000080
#define AKE_R0F_REG_GET_HDENC(ake_r0f_reg) \
	((((unsigned long)(ake_r0f_reg)) & AKE_R0F_REG_HDENC_MASK) >> AKE_R0F_REG_HDENC_SHIFT)
#define AKE_R0F_REG_SET_HDENC(ake_r0f_reg, hdenc) { \
	FDL_ASSERT(!((hdenc) & ~((1 << AKE_R0F_REG_HDENC_SIZE)-1))); \
	ake_r0f_reg = (((unsigned long)(ake_r0f_reg)) & ~AKE_R0F_REG_HDENC_MASK) | (((unsigned long)(hdenc)) << AKE_R0F_REG_HDENC_SHIFT); \
}

#define AKE_R0F_REG_TOTAL_SIZE	8
#define AKE_R0F_REG(aspect0, aspect1, hvpol, dtexcng, d3d4, vfrq, hdenc) \
	((((unsigned long)(aspect0)) << AKE_R0F_REG_ASPECT0_SHIFT) | \
	 (((unsigned long)(aspect1)) << AKE_R0F_REG_ASPECT1_SHIFT) | \
	 (((unsigned long)(hvpol)) << AKE_R0F_REG_HVPOL_SHIFT) | \
	 (((unsigned long)(dtexcng)) << AKE_R0F_REG_DTEXCNG_SHIFT) | \
	 (((unsigned long)(d3d4)) << AKE_R0F_REG_D3D4_SHIFT) | \
	 (((unsigned long)(vfrq)) << AKE_R0F_REG_VFRQ_SHIFT) | \
	 (((unsigned long)(hdenc)) << AKE_R0F_REG_HDENC_SHIFT))

/*
 *  ake_r10_reg struct
 */
#define AKE_R10_REG_GAMMA_A0_15_8_M_SIZE	8
#define AKE_R10_REG_GAMMA_A0_15_8_M_SHIFT	0
#define AKE_R10_REG_GAMMA_A0_15_8_M_MASK	0x000000ff
#define AKE_R10_REG_GET_GAMMA_A0_15_8_M(ake_r10_reg) \
	((((unsigned long)(ake_r10_reg)) & AKE_R10_REG_GAMMA_A0_15_8_M_MASK) >> AKE_R10_REG_GAMMA_A0_15_8_M_SHIFT)
#define AKE_R10_REG_SET_GAMMA_A0_15_8_M(ake_r10_reg, gamma_a0_15_8_m) { \
	FDL_ASSERT(!((gamma_a0_15_8_m) & ~((1 << AKE_R10_REG_GAMMA_A0_15_8_M_SIZE)-1))); \
	ake_r10_reg = (((unsigned long)(ake_r10_reg)) & ~AKE_R10_REG_GAMMA_A0_15_8_M_MASK) | (((unsigned long)(gamma_a0_15_8_m)) << AKE_R10_REG_GAMMA_A0_15_8_M_SHIFT); \
}

#define AKE_R10_REG_TOTAL_SIZE	8
#define AKE_R10_REG(gamma_a0_15_8_m) \
	((((unsigned long)(gamma_a0_15_8_m)) << AKE_R10_REG_GAMMA_A0_15_8_M_SHIFT))

/*
 *  ake_r11_reg struct
 */
#define AKE_R11_REG_GAMMA_A0_7_0_M_SIZE	8
#define AKE_R11_REG_GAMMA_A0_7_0_M_SHIFT	0
#define AKE_R11_REG_GAMMA_A0_7_0_M_MASK	0x000000ff
#define AKE_R11_REG_GET_GAMMA_A0_7_0_M(ake_r11_reg) \
	((((unsigned long)(ake_r11_reg)) & AKE_R11_REG_GAMMA_A0_7_0_M_MASK) >> AKE_R11_REG_GAMMA_A0_7_0_M_SHIFT)
#define AKE_R11_REG_SET_GAMMA_A0_7_0_M(ake_r11_reg, gamma_a0_7_0_m) { \
	FDL_ASSERT(!((gamma_a0_7_0_m) & ~((1 << AKE_R11_REG_GAMMA_A0_7_0_M_SIZE)-1))); \
	ake_r11_reg = (((unsigned long)(ake_r11_reg)) & ~AKE_R11_REG_GAMMA_A0_7_0_M_MASK) | (((unsigned long)(gamma_a0_7_0_m)) << AKE_R11_REG_GAMMA_A0_7_0_M_SHIFT); \
}

#define AKE_R11_REG_TOTAL_SIZE	8
#define AKE_R11_REG(gamma_a0_7_0_m) \
	((((unsigned long)(gamma_a0_7_0_m)) << AKE_R11_REG_GAMMA_A0_7_0_M_SHIFT))

/*
 *  ake_r12_reg struct
 */
#define AKE_R12_REG_GAMMA_A1_15_8_M_SIZE	8
#define AKE_R12_REG_GAMMA_A1_15_8_M_SHIFT	0
#define AKE_R12_REG_GAMMA_A1_15_8_M_MASK	0x000000ff
#define AKE_R12_REG_GET_GAMMA_A1_15_8_M(ake_r12_reg) \
	((((unsigned long)(ake_r12_reg)) & AKE_R12_REG_GAMMA_A1_15_8_M_MASK) >> AKE_R12_REG_GAMMA_A1_15_8_M_SHIFT)
#define AKE_R12_REG_SET_GAMMA_A1_15_8_M(ake_r12_reg, gamma_a1_15_8_m) { \
	FDL_ASSERT(!((gamma_a1_15_8_m) & ~((1 << AKE_R12_REG_GAMMA_A1_15_8_M_SIZE)-1))); \
	ake_r12_reg = (((unsigned long)(ake_r12_reg)) & ~AKE_R12_REG_GAMMA_A1_15_8_M_MASK) | (((unsigned long)(gamma_a1_15_8_m)) << AKE_R12_REG_GAMMA_A1_15_8_M_SHIFT); \
}

#define AKE_R12_REG_TOTAL_SIZE	8
#define AKE_R12_REG(gamma_a1_15_8_m) \
	((((unsigned long)(gamma_a1_15_8_m)) << AKE_R12_REG_GAMMA_A1_15_8_M_SHIFT))

/*
 *  ake_r13_reg struct
 */
#define AKE_R13_REG_GAMMA_A1_7_0_M_SIZE	8
#define AKE_R13_REG_GAMMA_A1_7_0_M_SHIFT	0
#define AKE_R13_REG_GAMMA_A1_7_0_M_MASK	0x000000ff
#define AKE_R13_REG_GET_GAMMA_A1_7_0_M(ake_r13_reg) \
	((((unsigned long)(ake_r13_reg)) & AKE_R13_REG_GAMMA_A1_7_0_M_MASK) >> AKE_R13_REG_GAMMA_A1_7_0_M_SHIFT)
#define AKE_R13_REG_SET_GAMMA_A1_7_0_M(ake_r13_reg, gamma_a1_7_0_m) { \
	FDL_ASSERT(!((gamma_a1_7_0_m) & ~((1 << AKE_R13_REG_GAMMA_A1_7_0_M_SIZE)-1))); \
	ake_r13_reg = (((unsigned long)(ake_r13_reg)) & ~AKE_R13_REG_GAMMA_A1_7_0_M_MASK) | (((unsigned long)(gamma_a1_7_0_m)) << AKE_R13_REG_GAMMA_A1_7_0_M_SHIFT); \
}

#define AKE_R13_REG_TOTAL_SIZE	8
#define AKE_R13_REG(gamma_a1_7_0_m) \
	((((unsigned long)(gamma_a1_7_0_m)) << AKE_R13_REG_GAMMA_A1_7_0_M_SHIFT))

/*
 *  ake_r14_reg struct
 */
#define AKE_R14_REG_GAMMA_A2_15_8_M_SIZE	8
#define AKE_R14_REG_GAMMA_A2_15_8_M_SHIFT	0
#define AKE_R14_REG_GAMMA_A2_15_8_M_MASK	0x000000ff
#define AKE_R14_REG_GET_GAMMA_A2_15_8_M(ake_r14_reg) \
	((((unsigned long)(ake_r14_reg)) & AKE_R14_REG_GAMMA_A2_15_8_M_MASK) >> AKE_R14_REG_GAMMA_A2_15_8_M_SHIFT)
#define AKE_R14_REG_SET_GAMMA_A2_15_8_M(ake_r14_reg, gamma_a2_15_8_m) { \
	FDL_ASSERT(!((gamma_a2_15_8_m) & ~((1 << AKE_R14_REG_GAMMA_A2_15_8_M_SIZE)-1))); \
	ake_r14_reg = (((unsigned long)(ake_r14_reg)) & ~AKE_R14_REG_GAMMA_A2_15_8_M_MASK) | (((unsigned long)(gamma_a2_15_8_m)) << AKE_R14_REG_GAMMA_A2_15_8_M_SHIFT); \
}

#define AKE_R14_REG_TOTAL_SIZE	8
#define AKE_R14_REG(gamma_a2_15_8_m) \
	((((unsigned long)(gamma_a2_15_8_m)) << AKE_R14_REG_GAMMA_A2_15_8_M_SHIFT))

/*
 *  ake_r15_reg struct
 */
#define AKE_R15_REG_GAMMA_A2_7_0_M_SIZE	8
#define AKE_R15_REG_GAMMA_A2_7_0_M_SHIFT	0
#define AKE_R15_REG_GAMMA_A2_7_0_M_MASK	0x000000ff
#define AKE_R15_REG_GET_GAMMA_A2_7_0_M(ake_r15_reg) \
	((((unsigned long)(ake_r15_reg)) & AKE_R15_REG_GAMMA_A2_7_0_M_MASK) >> AKE_R15_REG_GAMMA_A2_7_0_M_SHIFT)
#define AKE_R15_REG_SET_GAMMA_A2_7_0_M(ake_r15_reg, gamma_a2_7_0_m) { \
	FDL_ASSERT(!((gamma_a2_7_0_m) & ~((1 << AKE_R15_REG_GAMMA_A2_7_0_M_SIZE)-1))); \
	ake_r15_reg = (((unsigned long)(ake_r15_reg)) & ~AKE_R15_REG_GAMMA_A2_7_0_M_MASK) | (((unsigned long)(gamma_a2_7_0_m)) << AKE_R15_REG_GAMMA_A2_7_0_M_SHIFT); \
}

#define AKE_R15_REG_TOTAL_SIZE	8
#define AKE_R15_REG(gamma_a2_7_0_m) \
	((((unsigned long)(gamma_a2_7_0_m)) << AKE_R15_REG_GAMMA_A2_7_0_M_SHIFT))

/*
 *  ake_r16_reg struct
 */
#define AKE_R16_REG_GAMMA_A3_15_8_M_SIZE	8
#define AKE_R16_REG_GAMMA_A3_15_8_M_SHIFT	0
#define AKE_R16_REG_GAMMA_A3_15_8_M_MASK	0x000000ff
#define AKE_R16_REG_GET_GAMMA_A3_15_8_M(ake_r16_reg) \
	((((unsigned long)(ake_r16_reg)) & AKE_R16_REG_GAMMA_A3_15_8_M_MASK) >> AKE_R16_REG_GAMMA_A3_15_8_M_SHIFT)
#define AKE_R16_REG_SET_GAMMA_A3_15_8_M(ake_r16_reg, gamma_a3_15_8_m) { \
	FDL_ASSERT(!((gamma_a3_15_8_m) & ~((1 << AKE_R16_REG_GAMMA_A3_15_8_M_SIZE)-1))); \
	ake_r16_reg = (((unsigned long)(ake_r16_reg)) & ~AKE_R16_REG_GAMMA_A3_15_8_M_MASK) | (((unsigned long)(gamma_a3_15_8_m)) << AKE_R16_REG_GAMMA_A3_15_8_M_SHIFT); \
}

#define AKE_R16_REG_TOTAL_SIZE	8
#define AKE_R16_REG(gamma_a3_15_8_m) \
	((((unsigned long)(gamma_a3_15_8_m)) << AKE_R16_REG_GAMMA_A3_15_8_M_SHIFT))

/*
 *  ake_r17_reg struct
 */
#define AKE_R17_REG_GAMMA_A3_7_0_M_SIZE	8
#define AKE_R17_REG_GAMMA_A3_7_0_M_SHIFT	0
#define AKE_R17_REG_GAMMA_A3_7_0_M_MASK	0x000000ff
#define AKE_R17_REG_GET_GAMMA_A3_7_0_M(ake_r17_reg) \
	((((unsigned long)(ake_r17_reg)) & AKE_R17_REG_GAMMA_A3_7_0_M_MASK) >> AKE_R17_REG_GAMMA_A3_7_0_M_SHIFT)
#define AKE_R17_REG_SET_GAMMA_A3_7_0_M(ake_r17_reg, gamma_a3_7_0_m) { \
	FDL_ASSERT(!((gamma_a3_7_0_m) & ~((1 << AKE_R17_REG_GAMMA_A3_7_0_M_SIZE)-1))); \
	ake_r17_reg = (((unsigned long)(ake_r17_reg)) & ~AKE_R17_REG_GAMMA_A3_7_0_M_MASK) | (((unsigned long)(gamma_a3_7_0_m)) << AKE_R17_REG_GAMMA_A3_7_0_M_SHIFT); \
}

#define AKE_R17_REG_TOTAL_SIZE	8
#define AKE_R17_REG(gamma_a3_7_0_m) \
	((((unsigned long)(gamma_a3_7_0_m)) << AKE_R17_REG_GAMMA_A3_7_0_M_SHIFT))

/*
 *  ake_r18_reg struct
 */
#define AKE_R18_REG_GAMMA_A4_15_8_M_SIZE	8
#define AKE_R18_REG_GAMMA_A4_15_8_M_SHIFT	0
#define AKE_R18_REG_GAMMA_A4_15_8_M_MASK	0x000000ff
#define AKE_R18_REG_GET_GAMMA_A4_15_8_M(ake_r18_reg) \
	((((unsigned long)(ake_r18_reg)) & AKE_R18_REG_GAMMA_A4_15_8_M_MASK) >> AKE_R18_REG_GAMMA_A4_15_8_M_SHIFT)
#define AKE_R18_REG_SET_GAMMA_A4_15_8_M(ake_r18_reg, gamma_a4_15_8_m) { \
	FDL_ASSERT(!((gamma_a4_15_8_m) & ~((1 << AKE_R18_REG_GAMMA_A4_15_8_M_SIZE)-1))); \
	ake_r18_reg = (((unsigned long)(ake_r18_reg)) & ~AKE_R18_REG_GAMMA_A4_15_8_M_MASK) | (((unsigned long)(gamma_a4_15_8_m)) << AKE_R18_REG_GAMMA_A4_15_8_M_SHIFT); \
}

#define AKE_R18_REG_TOTAL_SIZE	8
#define AKE_R18_REG(gamma_a4_15_8_m) \
	((((unsigned long)(gamma_a4_15_8_m)) << AKE_R18_REG_GAMMA_A4_15_8_M_SHIFT))

/*
 *  ake_r19_reg struct
 */
#define AKE_R19_REG_GAMMA_A4_7_0_M_SIZE	8
#define AKE_R19_REG_GAMMA_A4_7_0_M_SHIFT	0
#define AKE_R19_REG_GAMMA_A4_7_0_M_MASK	0x000000ff
#define AKE_R19_REG_GET_GAMMA_A4_7_0_M(ake_r19_reg) \
	((((unsigned long)(ake_r19_reg)) & AKE_R19_REG_GAMMA_A4_7_0_M_MASK) >> AKE_R19_REG_GAMMA_A4_7_0_M_SHIFT)
#define AKE_R19_REG_SET_GAMMA_A4_7_0_M(ake_r19_reg, gamma_a4_7_0_m) { \
	FDL_ASSERT(!((gamma_a4_7_0_m) & ~((1 << AKE_R19_REG_GAMMA_A4_7_0_M_SIZE)-1))); \
	ake_r19_reg = (((unsigned long)(ake_r19_reg)) & ~AKE_R19_REG_GAMMA_A4_7_0_M_MASK) | (((unsigned long)(gamma_a4_7_0_m)) << AKE_R19_REG_GAMMA_A4_7_0_M_SHIFT); \
}

#define AKE_R19_REG_TOTAL_SIZE	8
#define AKE_R19_REG(gamma_a4_7_0_m) \
	((((unsigned long)(gamma_a4_7_0_m)) << AKE_R19_REG_GAMMA_A4_7_0_M_SHIFT))

/*
 *  ake_r1a_reg struct
 */
#define AKE_R1A_REG_GAMMA_A5_15_8_M_SIZE	8
#define AKE_R1A_REG_GAMMA_A5_15_8_M_SHIFT	0
#define AKE_R1A_REG_GAMMA_A5_15_8_M_MASK	0x000000ff
#define AKE_R1A_REG_GET_GAMMA_A5_15_8_M(ake_r1a_reg) \
	((((unsigned long)(ake_r1a_reg)) & AKE_R1A_REG_GAMMA_A5_15_8_M_MASK) >> AKE_R1A_REG_GAMMA_A5_15_8_M_SHIFT)
#define AKE_R1A_REG_SET_GAMMA_A5_15_8_M(ake_r1a_reg, gamma_a5_15_8_m) { \
	FDL_ASSERT(!((gamma_a5_15_8_m) & ~((1 << AKE_R1A_REG_GAMMA_A5_15_8_M_SIZE)-1))); \
	ake_r1a_reg = (((unsigned long)(ake_r1a_reg)) & ~AKE_R1A_REG_GAMMA_A5_15_8_M_MASK) | (((unsigned long)(gamma_a5_15_8_m)) << AKE_R1A_REG_GAMMA_A5_15_8_M_SHIFT); \
}

#define AKE_R1A_REG_TOTAL_SIZE	8
#define AKE_R1A_REG(gamma_a5_15_8_m) \
	((((unsigned long)(gamma_a5_15_8_m)) << AKE_R1A_REG_GAMMA_A5_15_8_M_SHIFT))

/*
 *  ake_r1b_reg struct
 */
#define AKE_R1B_REG_GAMMA_A5_7_0_M_SIZE	8
#define AKE_R1B_REG_GAMMA_A5_7_0_M_SHIFT	0
#define AKE_R1B_REG_GAMMA_A5_7_0_M_MASK	0x000000ff
#define AKE_R1B_REG_GET_GAMMA_A5_7_0_M(ake_r1b_reg) \
	((((unsigned long)(ake_r1b_reg)) & AKE_R1B_REG_GAMMA_A5_7_0_M_MASK) >> AKE_R1B_REG_GAMMA_A5_7_0_M_SHIFT)
#define AKE_R1B_REG_SET_GAMMA_A5_7_0_M(ake_r1b_reg, gamma_a5_7_0_m) { \
	FDL_ASSERT(!((gamma_a5_7_0_m) & ~((1 << AKE_R1B_REG_GAMMA_A5_7_0_M_SIZE)-1))); \
	ake_r1b_reg = (((unsigned long)(ake_r1b_reg)) & ~AKE_R1B_REG_GAMMA_A5_7_0_M_MASK) | (((unsigned long)(gamma_a5_7_0_m)) << AKE_R1B_REG_GAMMA_A5_7_0_M_SHIFT); \
}

#define AKE_R1B_REG_TOTAL_SIZE	8
#define AKE_R1B_REG(gamma_a5_7_0_m) \
	((((unsigned long)(gamma_a5_7_0_m)) << AKE_R1B_REG_GAMMA_A5_7_0_M_SHIFT))

/*
 *  ake_r1c_reg struct
 */
#define AKE_R1C_REG_GAMMA_X0_M_SIZE	8
#define AKE_R1C_REG_GAMMA_X0_M_SHIFT	0
#define AKE_R1C_REG_GAMMA_X0_M_MASK	0x000000ff
#define AKE_R1C_REG_GET_GAMMA_X0_M(ake_r1c_reg) \
	((((unsigned long)(ake_r1c_reg)) & AKE_R1C_REG_GAMMA_X0_M_MASK) >> AKE_R1C_REG_GAMMA_X0_M_SHIFT)
#define AKE_R1C_REG_SET_GAMMA_X0_M(ake_r1c_reg, gamma_x0_m) { \
	FDL_ASSERT(!((gamma_x0_m) & ~((1 << AKE_R1C_REG_GAMMA_X0_M_SIZE)-1))); \
	ake_r1c_reg = (((unsigned long)(ake_r1c_reg)) & ~AKE_R1C_REG_GAMMA_X0_M_MASK) | (((unsigned long)(gamma_x0_m)) << AKE_R1C_REG_GAMMA_X0_M_SHIFT); \
}

#define AKE_R1C_REG_TOTAL_SIZE	8
#define AKE_R1C_REG(gamma_x0_m) \
	((((unsigned long)(gamma_x0_m)) << AKE_R1C_REG_GAMMA_X0_M_SHIFT))

/*
 *  ake_r1d_reg struct
 */
#define AKE_R1D_REG_GAMMA_X1_M_SIZE	8
#define AKE_R1D_REG_GAMMA_X1_M_SHIFT	0
#define AKE_R1D_REG_GAMMA_X1_M_MASK	0x000000ff
#define AKE_R1D_REG_GET_GAMMA_X1_M(ake_r1d_reg) \
	((((unsigned long)(ake_r1d_reg)) & AKE_R1D_REG_GAMMA_X1_M_MASK) >> AKE_R1D_REG_GAMMA_X1_M_SHIFT)
#define AKE_R1D_REG_SET_GAMMA_X1_M(ake_r1d_reg, gamma_x1_m) { \
	FDL_ASSERT(!((gamma_x1_m) & ~((1 << AKE_R1D_REG_GAMMA_X1_M_SIZE)-1))); \
	ake_r1d_reg = (((unsigned long)(ake_r1d_reg)) & ~AKE_R1D_REG_GAMMA_X1_M_MASK) | (((unsigned long)(gamma_x1_m)) << AKE_R1D_REG_GAMMA_X1_M_SHIFT); \
}

#define AKE_R1D_REG_TOTAL_SIZE	8
#define AKE_R1D_REG(gamma_x1_m) \
	((((unsigned long)(gamma_x1_m)) << AKE_R1D_REG_GAMMA_X1_M_SHIFT))

/*
 *  ake_r1e_reg struct
 */
#define AKE_R1E_REG_GAMMA_X2_M_SIZE	8
#define AKE_R1E_REG_GAMMA_X2_M_SHIFT	0
#define AKE_R1E_REG_GAMMA_X2_M_MASK	0x000000ff
#define AKE_R1E_REG_GET_GAMMA_X2_M(ake_r1e_reg) \
	((((unsigned long)(ake_r1e_reg)) & AKE_R1E_REG_GAMMA_X2_M_MASK) >> AKE_R1E_REG_GAMMA_X2_M_SHIFT)
#define AKE_R1E_REG_SET_GAMMA_X2_M(ake_r1e_reg, gamma_x2_m) { \
	FDL_ASSERT(!((gamma_x2_m) & ~((1 << AKE_R1E_REG_GAMMA_X2_M_SIZE)-1))); \
	ake_r1e_reg = (((unsigned long)(ake_r1e_reg)) & ~AKE_R1E_REG_GAMMA_X2_M_MASK) | (((unsigned long)(gamma_x2_m)) << AKE_R1E_REG_GAMMA_X2_M_SHIFT); \
}

#define AKE_R1E_REG_TOTAL_SIZE	8
#define AKE_R1E_REG(gamma_x2_m) \
	((((unsigned long)(gamma_x2_m)) << AKE_R1E_REG_GAMMA_X2_M_SHIFT))

/*
 *  ake_r1f_reg struct
 */
#define AKE_R1F_REG_GAMMA_X3_M_SIZE	8
#define AKE_R1F_REG_GAMMA_X3_M_SHIFT	0
#define AKE_R1F_REG_GAMMA_X3_M_MASK	0x000000ff
#define AKE_R1F_REG_GET_GAMMA_X3_M(ake_r1f_reg) \
	((((unsigned long)(ake_r1f_reg)) & AKE_R1F_REG_GAMMA_X3_M_MASK) >> AKE_R1F_REG_GAMMA_X3_M_SHIFT)
#define AKE_R1F_REG_SET_GAMMA_X3_M(ake_r1f_reg, gamma_x3_m) { \
	FDL_ASSERT(!((gamma_x3_m) & ~((1 << AKE_R1F_REG_GAMMA_X3_M_SIZE)-1))); \
	ake_r1f_reg = (((unsigned long)(ake_r1f_reg)) & ~AKE_R1F_REG_GAMMA_X3_M_MASK) | (((unsigned long)(gamma_x3_m)) << AKE_R1F_REG_GAMMA_X3_M_SHIFT); \
}

#define AKE_R1F_REG_TOTAL_SIZE	8
#define AKE_R1F_REG(gamma_x3_m) \
	((((unsigned long)(gamma_x3_m)) << AKE_R1F_REG_GAMMA_X3_M_SHIFT))

/*
 *  ake_r20_reg struct
 */
#define AKE_R20_REG_GAMMA_X4_M_SIZE	8
#define AKE_R20_REG_GAMMA_X4_M_SHIFT	0
#define AKE_R20_REG_GAMMA_X4_M_MASK	0x000000ff
#define AKE_R20_REG_GET_GAMMA_X4_M(ake_r20_reg) \
	((((unsigned long)(ake_r20_reg)) & AKE_R20_REG_GAMMA_X4_M_MASK) >> AKE_R20_REG_GAMMA_X4_M_SHIFT)
#define AKE_R20_REG_SET_GAMMA_X4_M(ake_r20_reg, gamma_x4_m) { \
	FDL_ASSERT(!((gamma_x4_m) & ~((1 << AKE_R20_REG_GAMMA_X4_M_SIZE)-1))); \
	ake_r20_reg = (((unsigned long)(ake_r20_reg)) & ~AKE_R20_REG_GAMMA_X4_M_MASK) | (((unsigned long)(gamma_x4_m)) << AKE_R20_REG_GAMMA_X4_M_SHIFT); \
}

#define AKE_R20_REG_TOTAL_SIZE	8
#define AKE_R20_REG(gamma_x4_m) \
	((((unsigned long)(gamma_x4_m)) << AKE_R20_REG_GAMMA_X4_M_SHIFT))

/*
 *  ake_r21_reg struct
 */
#define AKE_R21_REG_GAMMA_X5_M_SIZE	8
#define AKE_R21_REG_GAMMA_X5_M_SHIFT	0
#define AKE_R21_REG_GAMMA_X5_M_MASK	0x000000ff
#define AKE_R21_REG_GET_GAMMA_X5_M(ake_r21_reg) \
	((((unsigned long)(ake_r21_reg)) & AKE_R21_REG_GAMMA_X5_M_MASK) >> AKE_R21_REG_GAMMA_X5_M_SHIFT)
#define AKE_R21_REG_SET_GAMMA_X5_M(ake_r21_reg, gamma_x5_m) { \
	FDL_ASSERT(!((gamma_x5_m) & ~((1 << AKE_R21_REG_GAMMA_X5_M_SIZE)-1))); \
	ake_r21_reg = (((unsigned long)(ake_r21_reg)) & ~AKE_R21_REG_GAMMA_X5_M_MASK) | (((unsigned long)(gamma_x5_m)) << AKE_R21_REG_GAMMA_X5_M_SHIFT); \
}

#define AKE_R21_REG_TOTAL_SIZE	8
#define AKE_R21_REG(gamma_x5_m) \
	((((unsigned long)(gamma_x5_m)) << AKE_R21_REG_GAMMA_X5_M_SHIFT))

/*
 *  ake_r22_reg struct
 */
#define AKE_R22_REG_GAMMA_X6_M_SIZE	8
#define AKE_R22_REG_GAMMA_X6_M_SHIFT	0
#define AKE_R22_REG_GAMMA_X6_M_MASK	0x000000ff
#define AKE_R22_REG_GET_GAMMA_X6_M(ake_r22_reg) \
	((((unsigned long)(ake_r22_reg)) & AKE_R22_REG_GAMMA_X6_M_MASK) >> AKE_R22_REG_GAMMA_X6_M_SHIFT)
#define AKE_R22_REG_SET_GAMMA_X6_M(ake_r22_reg, gamma_x6_m) { \
	FDL_ASSERT(!((gamma_x6_m) & ~((1 << AKE_R22_REG_GAMMA_X6_M_SIZE)-1))); \
	ake_r22_reg = (((unsigned long)(ake_r22_reg)) & ~AKE_R22_REG_GAMMA_X6_M_MASK) | (((unsigned long)(gamma_x6_m)) << AKE_R22_REG_GAMMA_X6_M_SHIFT); \
}

#define AKE_R22_REG_TOTAL_SIZE	8
#define AKE_R22_REG(gamma_x6_m) \
	((((unsigned long)(gamma_x6_m)) << AKE_R22_REG_GAMMA_X6_M_SHIFT))

/*
 *  ake_r23_reg struct
 */
#define AKE_R23_REG_GAMMA_Y0_9_2_M_SIZE	8
#define AKE_R23_REG_GAMMA_Y0_9_2_M_SHIFT	0
#define AKE_R23_REG_GAMMA_Y0_9_2_M_MASK	0x000000ff
#define AKE_R23_REG_GET_GAMMA_Y0_9_2_M(ake_r23_reg) \
	((((unsigned long)(ake_r23_reg)) & AKE_R23_REG_GAMMA_Y0_9_2_M_MASK) >> AKE_R23_REG_GAMMA_Y0_9_2_M_SHIFT)
#define AKE_R23_REG_SET_GAMMA_Y0_9_2_M(ake_r23_reg, gamma_y0_9_2_m) { \
	FDL_ASSERT(!((gamma_y0_9_2_m) & ~((1 << AKE_R23_REG_GAMMA_Y0_9_2_M_SIZE)-1))); \
	ake_r23_reg = (((unsigned long)(ake_r23_reg)) & ~AKE_R23_REG_GAMMA_Y0_9_2_M_MASK) | (((unsigned long)(gamma_y0_9_2_m)) << AKE_R23_REG_GAMMA_Y0_9_2_M_SHIFT); \
}

#define AKE_R23_REG_TOTAL_SIZE	8
#define AKE_R23_REG(gamma_y0_9_2_m) \
	((((unsigned long)(gamma_y0_9_2_m)) << AKE_R23_REG_GAMMA_Y0_9_2_M_SHIFT))

/*
 *  ake_r24_reg struct
 */
#define AKE_R24_REG_GAMMA_Y0_1_0_M_SIZE	2
#define AKE_R24_REG_GAMMA_Y0_1_0_M_SHIFT	6
#define AKE_R24_REG_GAMMA_Y0_1_0_M_MASK	0x000000c0
#define AKE_R24_REG_GET_GAMMA_Y0_1_0_M(ake_r24_reg) \
	((((unsigned long)(ake_r24_reg)) & AKE_R24_REG_GAMMA_Y0_1_0_M_MASK) >> AKE_R24_REG_GAMMA_Y0_1_0_M_SHIFT)
#define AKE_R24_REG_SET_GAMMA_Y0_1_0_M(ake_r24_reg, gamma_y0_1_0_m) { \
	FDL_ASSERT(!((gamma_y0_1_0_m) & ~((1 << AKE_R24_REG_GAMMA_Y0_1_0_M_SIZE)-1))); \
	ake_r24_reg = (((unsigned long)(ake_r24_reg)) & ~AKE_R24_REG_GAMMA_Y0_1_0_M_MASK) | (((unsigned long)(gamma_y0_1_0_m)) << AKE_R24_REG_GAMMA_Y0_1_0_M_SHIFT); \
}

#define AKE_R24_REG_TOTAL_SIZE	8
#define AKE_R24_REG(gamma_y0_1_0_m) \
	((((unsigned long)(gamma_y0_1_0_m)) << AKE_R24_REG_GAMMA_Y0_1_0_M_SHIFT))

/*
 *  ake_r25_reg struct
 */
#define AKE_R25_REG_GAMMA_Y1_9_2_M_SIZE	8
#define AKE_R25_REG_GAMMA_Y1_9_2_M_SHIFT	0
#define AKE_R25_REG_GAMMA_Y1_9_2_M_MASK	0x000000ff
#define AKE_R25_REG_GET_GAMMA_Y1_9_2_M(ake_r25_reg) \
	((((unsigned long)(ake_r25_reg)) & AKE_R25_REG_GAMMA_Y1_9_2_M_MASK) >> AKE_R25_REG_GAMMA_Y1_9_2_M_SHIFT)
#define AKE_R25_REG_SET_GAMMA_Y1_9_2_M(ake_r25_reg, gamma_y1_9_2_m) { \
	FDL_ASSERT(!((gamma_y1_9_2_m) & ~((1 << AKE_R25_REG_GAMMA_Y1_9_2_M_SIZE)-1))); \
	ake_r25_reg = (((unsigned long)(ake_r25_reg)) & ~AKE_R25_REG_GAMMA_Y1_9_2_M_MASK) | (((unsigned long)(gamma_y1_9_2_m)) << AKE_R25_REG_GAMMA_Y1_9_2_M_SHIFT); \
}

#define AKE_R25_REG_TOTAL_SIZE	8
#define AKE_R25_REG(gamma_y1_9_2_m) \
	((((unsigned long)(gamma_y1_9_2_m)) << AKE_R25_REG_GAMMA_Y1_9_2_M_SHIFT))

/*
 *  ake_r26_reg struct
 */
#define AKE_R26_REG_GAMMA_Y1_1_0_M_SIZE	2
#define AKE_R26_REG_GAMMA_Y1_1_0_M_SHIFT	6
#define AKE_R26_REG_GAMMA_Y1_1_0_M_MASK	0x000000c0
#define AKE_R26_REG_GET_GAMMA_Y1_1_0_M(ake_r26_reg) \
	((((unsigned long)(ake_r26_reg)) & AKE_R26_REG_GAMMA_Y1_1_0_M_MASK) >> AKE_R26_REG_GAMMA_Y1_1_0_M_SHIFT)
#define AKE_R26_REG_SET_GAMMA_Y1_1_0_M(ake_r26_reg, gamma_y1_1_0_m) { \
	FDL_ASSERT(!((gamma_y1_1_0_m) & ~((1 << AKE_R26_REG_GAMMA_Y1_1_0_M_SIZE)-1))); \
	ake_r26_reg = (((unsigned long)(ake_r26_reg)) & ~AKE_R26_REG_GAMMA_Y1_1_0_M_MASK) | (((unsigned long)(gamma_y1_1_0_m)) << AKE_R26_REG_GAMMA_Y1_1_0_M_SHIFT); \
}

#define AKE_R26_REG_TOTAL_SIZE	8
#define AKE_R26_REG(gamma_y1_1_0_m) \
	((((unsigned long)(gamma_y1_1_0_m)) << AKE_R26_REG_GAMMA_Y1_1_0_M_SHIFT))

/*
 *  ake_r27_reg struct
 */
#define AKE_R27_REG_GAMMA_Y2_9_2_M_SIZE	8
#define AKE_R27_REG_GAMMA_Y2_9_2_M_SHIFT	0
#define AKE_R27_REG_GAMMA_Y2_9_2_M_MASK	0x000000ff
#define AKE_R27_REG_GET_GAMMA_Y2_9_2_M(ake_r27_reg) \
	((((unsigned long)(ake_r27_reg)) & AKE_R27_REG_GAMMA_Y2_9_2_M_MASK) >> AKE_R27_REG_GAMMA_Y2_9_2_M_SHIFT)
#define AKE_R27_REG_SET_GAMMA_Y2_9_2_M(ake_r27_reg, gamma_y2_9_2_m) { \
	FDL_ASSERT(!((gamma_y2_9_2_m) & ~((1 << AKE_R27_REG_GAMMA_Y2_9_2_M_SIZE)-1))); \
	ake_r27_reg = (((unsigned long)(ake_r27_reg)) & ~AKE_R27_REG_GAMMA_Y2_9_2_M_MASK) | (((unsigned long)(gamma_y2_9_2_m)) << AKE_R27_REG_GAMMA_Y2_9_2_M_SHIFT); \
}

#define AKE_R27_REG_TOTAL_SIZE	8
#define AKE_R27_REG(gamma_y2_9_2_m) \
	((((unsigned long)(gamma_y2_9_2_m)) << AKE_R27_REG_GAMMA_Y2_9_2_M_SHIFT))

/*
 *  ake_r28_reg struct
 */
#define AKE_R28_REG_GAMMA_Y2_1_0_M_SIZE	2
#define AKE_R28_REG_GAMMA_Y2_1_0_M_SHIFT	6
#define AKE_R28_REG_GAMMA_Y2_1_0_M_MASK	0x000000c0
#define AKE_R28_REG_GET_GAMMA_Y2_1_0_M(ake_r28_reg) \
	((((unsigned long)(ake_r28_reg)) & AKE_R28_REG_GAMMA_Y2_1_0_M_MASK) >> AKE_R28_REG_GAMMA_Y2_1_0_M_SHIFT)
#define AKE_R28_REG_SET_GAMMA_Y2_1_0_M(ake_r28_reg, gamma_y2_1_0_m) { \
	FDL_ASSERT(!((gamma_y2_1_0_m) & ~((1 << AKE_R28_REG_GAMMA_Y2_1_0_M_SIZE)-1))); \
	ake_r28_reg = (((unsigned long)(ake_r28_reg)) & ~AKE_R28_REG_GAMMA_Y2_1_0_M_MASK) | (((unsigned long)(gamma_y2_1_0_m)) << AKE_R28_REG_GAMMA_Y2_1_0_M_SHIFT); \
}

#define AKE_R28_REG_TOTAL_SIZE	8
#define AKE_R28_REG(gamma_y2_1_0_m) \
	((((unsigned long)(gamma_y2_1_0_m)) << AKE_R28_REG_GAMMA_Y2_1_0_M_SHIFT))

/*
 *  ake_r29_reg struct
 */
#define AKE_R29_REG_GAMMA_Y3_9_2_M_SIZE	8
#define AKE_R29_REG_GAMMA_Y3_9_2_M_SHIFT	0
#define AKE_R29_REG_GAMMA_Y3_9_2_M_MASK	0x000000ff
#define AKE_R29_REG_GET_GAMMA_Y3_9_2_M(ake_r29_reg) \
	((((unsigned long)(ake_r29_reg)) & AKE_R29_REG_GAMMA_Y3_9_2_M_MASK) >> AKE_R29_REG_GAMMA_Y3_9_2_M_SHIFT)
#define AKE_R29_REG_SET_GAMMA_Y3_9_2_M(ake_r29_reg, gamma_y3_9_2_m) { \
	FDL_ASSERT(!((gamma_y3_9_2_m) & ~((1 << AKE_R29_REG_GAMMA_Y3_9_2_M_SIZE)-1))); \
	ake_r29_reg = (((unsigned long)(ake_r29_reg)) & ~AKE_R29_REG_GAMMA_Y3_9_2_M_MASK) | (((unsigned long)(gamma_y3_9_2_m)) << AKE_R29_REG_GAMMA_Y3_9_2_M_SHIFT); \
}

#define AKE_R29_REG_TOTAL_SIZE	8
#define AKE_R29_REG(gamma_y3_9_2_m) \
	((((unsigned long)(gamma_y3_9_2_m)) << AKE_R29_REG_GAMMA_Y3_9_2_M_SHIFT))

/*
 *  ake_r2a_reg struct
 */
#define AKE_R2A_REG_GAMMA_Y3_1_0_M_SIZE	2
#define AKE_R2A_REG_GAMMA_Y3_1_0_M_SHIFT	6
#define AKE_R2A_REG_GAMMA_Y3_1_0_M_MASK	0x000000c0
#define AKE_R2A_REG_GET_GAMMA_Y3_1_0_M(ake_r2a_reg) \
	((((unsigned long)(ake_r2a_reg)) & AKE_R2A_REG_GAMMA_Y3_1_0_M_MASK) >> AKE_R2A_REG_GAMMA_Y3_1_0_M_SHIFT)
#define AKE_R2A_REG_SET_GAMMA_Y3_1_0_M(ake_r2a_reg, gamma_y3_1_0_m) { \
	FDL_ASSERT(!((gamma_y3_1_0_m) & ~((1 << AKE_R2A_REG_GAMMA_Y3_1_0_M_SIZE)-1))); \
	ake_r2a_reg = (((unsigned long)(ake_r2a_reg)) & ~AKE_R2A_REG_GAMMA_Y3_1_0_M_MASK) | (((unsigned long)(gamma_y3_1_0_m)) << AKE_R2A_REG_GAMMA_Y3_1_0_M_SHIFT); \
}

#define AKE_R2A_REG_TOTAL_SIZE	8
#define AKE_R2A_REG(gamma_y3_1_0_m) \
	((((unsigned long)(gamma_y3_1_0_m)) << AKE_R2A_REG_GAMMA_Y3_1_0_M_SHIFT))

/*
 *  ake_r2b_reg struct
 */
#define AKE_R2B_REG_GAMMA_Y4_9_2_M_SIZE	8
#define AKE_R2B_REG_GAMMA_Y4_9_2_M_SHIFT	0
#define AKE_R2B_REG_GAMMA_Y4_9_2_M_MASK	0x000000ff
#define AKE_R2B_REG_GET_GAMMA_Y4_9_2_M(ake_r2b_reg) \
	((((unsigned long)(ake_r2b_reg)) & AKE_R2B_REG_GAMMA_Y4_9_2_M_MASK) >> AKE_R2B_REG_GAMMA_Y4_9_2_M_SHIFT)
#define AKE_R2B_REG_SET_GAMMA_Y4_9_2_M(ake_r2b_reg, gamma_y4_9_2_m) { \
	FDL_ASSERT(!((gamma_y4_9_2_m) & ~((1 << AKE_R2B_REG_GAMMA_Y4_9_2_M_SIZE)-1))); \
	ake_r2b_reg = (((unsigned long)(ake_r2b_reg)) & ~AKE_R2B_REG_GAMMA_Y4_9_2_M_MASK) | (((unsigned long)(gamma_y4_9_2_m)) << AKE_R2B_REG_GAMMA_Y4_9_2_M_SHIFT); \
}

#define AKE_R2B_REG_TOTAL_SIZE	8
#define AKE_R2B_REG(gamma_y4_9_2_m) \
	((((unsigned long)(gamma_y4_9_2_m)) << AKE_R2B_REG_GAMMA_Y4_9_2_M_SHIFT))

/*
 *  ake_r2c_reg struct
 */
#define AKE_R2C_REG_GAMMA_Y4_1_0_M_SIZE	2
#define AKE_R2C_REG_GAMMA_Y4_1_0_M_SHIFT	6
#define AKE_R2C_REG_GAMMA_Y4_1_0_M_MASK	0x000000c0
#define AKE_R2C_REG_GET_GAMMA_Y4_1_0_M(ake_r2c_reg) \
	((((unsigned long)(ake_r2c_reg)) & AKE_R2C_REG_GAMMA_Y4_1_0_M_MASK) >> AKE_R2C_REG_GAMMA_Y4_1_0_M_SHIFT)
#define AKE_R2C_REG_SET_GAMMA_Y4_1_0_M(ake_r2c_reg, gamma_y4_1_0_m) { \
	FDL_ASSERT(!((gamma_y4_1_0_m) & ~((1 << AKE_R2C_REG_GAMMA_Y4_1_0_M_SIZE)-1))); \
	ake_r2c_reg = (((unsigned long)(ake_r2c_reg)) & ~AKE_R2C_REG_GAMMA_Y4_1_0_M_MASK) | (((unsigned long)(gamma_y4_1_0_m)) << AKE_R2C_REG_GAMMA_Y4_1_0_M_SHIFT); \
}

#define AKE_R2C_REG_TOTAL_SIZE	8
#define AKE_R2C_REG(gamma_y4_1_0_m) \
	((((unsigned long)(gamma_y4_1_0_m)) << AKE_R2C_REG_GAMMA_Y4_1_0_M_SHIFT))

/*
 *  ake_r2d_reg struct
 */
#define AKE_R2D_REG_GAMMA_Y5_9_2_M_SIZE	8
#define AKE_R2D_REG_GAMMA_Y5_9_2_M_SHIFT	0
#define AKE_R2D_REG_GAMMA_Y5_9_2_M_MASK	0x000000ff
#define AKE_R2D_REG_GET_GAMMA_Y5_9_2_M(ake_r2d_reg) \
	((((unsigned long)(ake_r2d_reg)) & AKE_R2D_REG_GAMMA_Y5_9_2_M_MASK) >> AKE_R2D_REG_GAMMA_Y5_9_2_M_SHIFT)
#define AKE_R2D_REG_SET_GAMMA_Y5_9_2_M(ake_r2d_reg, gamma_y5_9_2_m) { \
	FDL_ASSERT(!((gamma_y5_9_2_m) & ~((1 << AKE_R2D_REG_GAMMA_Y5_9_2_M_SIZE)-1))); \
	ake_r2d_reg = (((unsigned long)(ake_r2d_reg)) & ~AKE_R2D_REG_GAMMA_Y5_9_2_M_MASK) | (((unsigned long)(gamma_y5_9_2_m)) << AKE_R2D_REG_GAMMA_Y5_9_2_M_SHIFT); \
}

#define AKE_R2D_REG_TOTAL_SIZE	8
#define AKE_R2D_REG(gamma_y5_9_2_m) \
	((((unsigned long)(gamma_y5_9_2_m)) << AKE_R2D_REG_GAMMA_Y5_9_2_M_SHIFT))

/*
 *  ake_r2e_reg struct
 */
#define AKE_R2E_REG_GAMMA_Y5_1_0_M_SIZE	2
#define AKE_R2E_REG_GAMMA_Y5_1_0_M_SHIFT	6
#define AKE_R2E_REG_GAMMA_Y5_1_0_M_MASK	0x000000c0
#define AKE_R2E_REG_GET_GAMMA_Y5_1_0_M(ake_r2e_reg) \
	((((unsigned long)(ake_r2e_reg)) & AKE_R2E_REG_GAMMA_Y5_1_0_M_MASK) >> AKE_R2E_REG_GAMMA_Y5_1_0_M_SHIFT)
#define AKE_R2E_REG_SET_GAMMA_Y5_1_0_M(ake_r2e_reg, gamma_y5_1_0_m) { \
	FDL_ASSERT(!((gamma_y5_1_0_m) & ~((1 << AKE_R2E_REG_GAMMA_Y5_1_0_M_SIZE)-1))); \
	ake_r2e_reg = (((unsigned long)(ake_r2e_reg)) & ~AKE_R2E_REG_GAMMA_Y5_1_0_M_MASK) | (((unsigned long)(gamma_y5_1_0_m)) << AKE_R2E_REG_GAMMA_Y5_1_0_M_SHIFT); \
}

#define AKE_R2E_REG_TOTAL_SIZE	8
#define AKE_R2E_REG(gamma_y5_1_0_m) \
	((((unsigned long)(gamma_y5_1_0_m)) << AKE_R2E_REG_GAMMA_Y5_1_0_M_SHIFT))

/*
 *  ake_r2f_reg struct
 */
#define AKE_R2F_REG_GAMMA_Y6_9_2_M_SIZE	8
#define AKE_R2F_REG_GAMMA_Y6_9_2_M_SHIFT	0
#define AKE_R2F_REG_GAMMA_Y6_9_2_M_MASK	0x000000ff
#define AKE_R2F_REG_GET_GAMMA_Y6_9_2_M(ake_r2f_reg) \
	((((unsigned long)(ake_r2f_reg)) & AKE_R2F_REG_GAMMA_Y6_9_2_M_MASK) >> AKE_R2F_REG_GAMMA_Y6_9_2_M_SHIFT)
#define AKE_R2F_REG_SET_GAMMA_Y6_9_2_M(ake_r2f_reg, gamma_y6_9_2_m) { \
	FDL_ASSERT(!((gamma_y6_9_2_m) & ~((1 << AKE_R2F_REG_GAMMA_Y6_9_2_M_SIZE)-1))); \
	ake_r2f_reg = (((unsigned long)(ake_r2f_reg)) & ~AKE_R2F_REG_GAMMA_Y6_9_2_M_MASK) | (((unsigned long)(gamma_y6_9_2_m)) << AKE_R2F_REG_GAMMA_Y6_9_2_M_SHIFT); \
}

#define AKE_R2F_REG_TOTAL_SIZE	8
#define AKE_R2F_REG(gamma_y6_9_2_m) \
	((((unsigned long)(gamma_y6_9_2_m)) << AKE_R2F_REG_GAMMA_Y6_9_2_M_SHIFT))

/*
 *  ake_r30_reg struct
 */
#define AKE_R30_REG_GAMMA_Y6_1_0_M_SIZE	2
#define AKE_R30_REG_GAMMA_Y6_1_0_M_SHIFT	6
#define AKE_R30_REG_GAMMA_Y6_1_0_M_MASK	0x000000c0
#define AKE_R30_REG_GET_GAMMA_Y6_1_0_M(ake_r30_reg) \
	((((unsigned long)(ake_r30_reg)) & AKE_R30_REG_GAMMA_Y6_1_0_M_MASK) >> AKE_R30_REG_GAMMA_Y6_1_0_M_SHIFT)
#define AKE_R30_REG_SET_GAMMA_Y6_1_0_M(ake_r30_reg, gamma_y6_1_0_m) { \
	FDL_ASSERT(!((gamma_y6_1_0_m) & ~((1 << AKE_R30_REG_GAMMA_Y6_1_0_M_SIZE)-1))); \
	ake_r30_reg = (((unsigned long)(ake_r30_reg)) & ~AKE_R30_REG_GAMMA_Y6_1_0_M_MASK) | (((unsigned long)(gamma_y6_1_0_m)) << AKE_R30_REG_GAMMA_Y6_1_0_M_SHIFT); \
}

#define AKE_R30_REG_TOTAL_SIZE	8
#define AKE_R30_REG(gamma_y6_1_0_m) \
	((((unsigned long)(gamma_y6_1_0_m)) << AKE_R30_REG_GAMMA_Y6_1_0_M_SHIFT))

/*
 *  ake_r6a_reg struct
 */
#define AKE_R6A_REG_CCSEL_SIZE	1
#define AKE_R6A_REG_CCSEL_SHIFT	0
#define AKE_R6A_REG_CCSEL_MASK	0x00000001
#define AKE_R6A_REG_GET_CCSEL(ake_r6a_reg) \
	((((unsigned long)(ake_r6a_reg)) & AKE_R6A_REG_CCSEL_MASK) >> AKE_R6A_REG_CCSEL_SHIFT)
#define AKE_R6A_REG_SET_CCSEL(ake_r6a_reg, ccsel) { \
	FDL_ASSERT(!((ccsel) & ~((1 << AKE_R6A_REG_CCSEL_SIZE)-1))); \
	ake_r6a_reg = (((unsigned long)(ake_r6a_reg)) & ~AKE_R6A_REG_CCSEL_MASK) | (((unsigned long)(ccsel)) << AKE_R6A_REG_CCSEL_SHIFT); \
}

#define AKE_R6A_REG_TOTAL_SIZE	8
#define AKE_R6A_REG(ccsel) \
	((((unsigned long)(ccsel)) << AKE_R6A_REG_CCSEL_SHIFT))

/*
 *  ake_r71_reg struct
 */
#define AKE_R71_REG_VOLML_SIZE	8
#define AKE_R71_REG_VOLML_SHIFT	0
#define AKE_R71_REG_VOLML_MASK	0x000000ff
#define AKE_R71_REG_GET_VOLML(ake_r71_reg) \
	((((unsigned long)(ake_r71_reg)) & AKE_R71_REG_VOLML_MASK) >> AKE_R71_REG_VOLML_SHIFT)
#define AKE_R71_REG_SET_VOLML(ake_r71_reg, volml) { \
	FDL_ASSERT(!((volml) & ~((1 << AKE_R71_REG_VOLML_SIZE)-1))); \
	ake_r71_reg = (((unsigned long)(ake_r71_reg)) & ~AKE_R71_REG_VOLML_MASK) | (((unsigned long)(volml)) << AKE_R71_REG_VOLML_SHIFT); \
}

#define AKE_R71_REG_TOTAL_SIZE	8
#define AKE_R71_REG(volml) \
	((((unsigned long)(volml)) << AKE_R71_REG_VOLML_SHIFT))

/*
 *  ake_r72_reg struct
 */
#define AKE_R72_REG_VOLMR_SIZE	8
#define AKE_R72_REG_VOLMR_SHIFT	0
#define AKE_R72_REG_VOLMR_MASK	0x000000ff
#define AKE_R72_REG_GET_VOLMR(ake_r72_reg) \
	((((unsigned long)(ake_r72_reg)) & AKE_R72_REG_VOLMR_MASK) >> AKE_R72_REG_VOLMR_SHIFT)
#define AKE_R72_REG_SET_VOLMR(ake_r72_reg, volmr) { \
	FDL_ASSERT(!((volmr) & ~((1 << AKE_R72_REG_VOLMR_SIZE)-1))); \
	ake_r72_reg = (((unsigned long)(ake_r72_reg)) & ~AKE_R72_REG_VOLMR_MASK) | (((unsigned long)(volmr)) << AKE_R72_REG_VOLMR_SHIFT); \
}

#define AKE_R72_REG_TOTAL_SIZE	8
#define AKE_R72_REG(volmr) \
	((((unsigned long)(volmr)) << AKE_R72_REG_VOLMR_SHIFT))

/*
 *  ake_r7a_reg struct
 */
#define AKE_R7A_REG_CC21_1_M_SIZE	7
#define AKE_R7A_REG_CC21_1_M_SHIFT	0
#define AKE_R7A_REG_CC21_1_M_MASK	0x0000007f
#define AKE_R7A_REG_GET_CC21_1_M(ake_r7a_reg) \
	((((unsigned long)(ake_r7a_reg)) & AKE_R7A_REG_CC21_1_M_MASK) >> AKE_R7A_REG_CC21_1_M_SHIFT)
#define AKE_R7A_REG_SET_CC21_1_M(ake_r7a_reg, cc21_1_m) { \
	FDL_ASSERT(!((cc21_1_m) & ~((1 << AKE_R7A_REG_CC21_1_M_SIZE)-1))); \
	ake_r7a_reg = (((unsigned long)(ake_r7a_reg)) & ~AKE_R7A_REG_CC21_1_M_MASK) | (((unsigned long)(cc21_1_m)) << AKE_R7A_REG_CC21_1_M_SHIFT); \
}

#define AKE_R7A_REG_TOTAL_SIZE	8
#define AKE_R7A_REG(cc21_1_m) \
	((((unsigned long)(cc21_1_m)) << AKE_R7A_REG_CC21_1_M_SHIFT))

/*
 *  ake_r7b_reg struct
 */
#define AKE_R7B_REG_CC21_2_M_SIZE	7
#define AKE_R7B_REG_CC21_2_M_SHIFT	0
#define AKE_R7B_REG_CC21_2_M_MASK	0x0000007f
#define AKE_R7B_REG_GET_CC21_2_M(ake_r7b_reg) \
	((((unsigned long)(ake_r7b_reg)) & AKE_R7B_REG_CC21_2_M_MASK) >> AKE_R7B_REG_CC21_2_M_SHIFT)
#define AKE_R7B_REG_SET_CC21_2_M(ake_r7b_reg, cc21_2_m) { \
	FDL_ASSERT(!((cc21_2_m) & ~((1 << AKE_R7B_REG_CC21_2_M_SIZE)-1))); \
	ake_r7b_reg = (((unsigned long)(ake_r7b_reg)) & ~AKE_R7B_REG_CC21_2_M_MASK) | (((unsigned long)(cc21_2_m)) << AKE_R7B_REG_CC21_2_M_SHIFT); \
}

#define AKE_R7B_REG_TOTAL_SIZE	8
#define AKE_R7B_REG(cc21_2_m) \
	((((unsigned long)(cc21_2_m)) << AKE_R7B_REG_CC21_2_M_SHIFT))

/*
 *  ake_r7c_reg struct
 */
#define AKE_R7C_REG_CC284_1_M_SIZE	7
#define AKE_R7C_REG_CC284_1_M_SHIFT	0
#define AKE_R7C_REG_CC284_1_M_MASK	0x0000007f
#define AKE_R7C_REG_GET_CC284_1_M(ake_r7c_reg) \
	((((unsigned long)(ake_r7c_reg)) & AKE_R7C_REG_CC284_1_M_MASK) >> AKE_R7C_REG_CC284_1_M_SHIFT)
#define AKE_R7C_REG_SET_CC284_1_M(ake_r7c_reg, cc284_1_m) { \
	FDL_ASSERT(!((cc284_1_m) & ~((1 << AKE_R7C_REG_CC284_1_M_SIZE)-1))); \
	ake_r7c_reg = (((unsigned long)(ake_r7c_reg)) & ~AKE_R7C_REG_CC284_1_M_MASK) | (((unsigned long)(cc284_1_m)) << AKE_R7C_REG_CC284_1_M_SHIFT); \
}

#define AKE_R7C_REG_TOTAL_SIZE	8
#define AKE_R7C_REG(cc284_1_m) \
	((((unsigned long)(cc284_1_m)) << AKE_R7C_REG_CC284_1_M_SHIFT))

/*
 *  ake_r7d_reg struct
 */
#define AKE_R7D_REG_CC284_2_M_SIZE	7
#define AKE_R7D_REG_CC284_2_M_SHIFT	0
#define AKE_R7D_REG_CC284_2_M_MASK	0x0000007f
#define AKE_R7D_REG_GET_CC284_2_M(ake_r7d_reg) \
	((((unsigned long)(ake_r7d_reg)) & AKE_R7D_REG_CC284_2_M_MASK) >> AKE_R7D_REG_CC284_2_M_SHIFT)
#define AKE_R7D_REG_SET_CC284_2_M(ake_r7d_reg, cc284_2_m) { \
	FDL_ASSERT(!((cc284_2_m) & ~((1 << AKE_R7D_REG_CC284_2_M_SIZE)-1))); \
	ake_r7d_reg = (((unsigned long)(ake_r7d_reg)) & ~AKE_R7D_REG_CC284_2_M_MASK) | (((unsigned long)(cc284_2_m)) << AKE_R7D_REG_CC284_2_M_SHIFT); \
}

#define AKE_R7D_REG_TOTAL_SIZE	8
#define AKE_R7D_REG(cc284_2_m) \
	((((unsigned long)(cc284_2_m)) << AKE_R7D_REG_CC284_2_M_SHIFT))

/*
 *  ake_r7f_reg struct
 */
#define AKE_R7F_REG_VERSION_SIZE	8
#define AKE_R7F_REG_VERSION_SHIFT	0
#define AKE_R7F_REG_VERSION_MASK	0x000000ff
#define AKE_R7F_REG_GET_VERSION(ake_r7f_reg) \
	((((unsigned long)(ake_r7f_reg)) & AKE_R7F_REG_VERSION_MASK) >> AKE_R7F_REG_VERSION_SHIFT)
#define AKE_R7F_REG_SET_VERSION(ake_r7f_reg, version) { \
	FDL_ASSERT(!((version) & ~((1 << AKE_R7F_REG_VERSION_SIZE)-1))); \
	ake_r7f_reg = (((unsigned long)(ake_r7f_reg)) & ~AKE_R7F_REG_VERSION_MASK) | (((unsigned long)(version)) << AKE_R7F_REG_VERSION_SHIFT); \
}

#define AKE_R7F_REG_TOTAL_SIZE	8
#define AKE_R7F_REG(version) \
	((((unsigned long)(version)) << AKE_R7F_REG_VERSION_SHIFT))


#endif /* __AKEHD_DAC_REG_H__ */
