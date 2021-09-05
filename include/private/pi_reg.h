/*
 *  pi_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from ../../bw/fdl/pi_reg.fdl
 */

#ifndef __FDL_PI_REG_H__
#define __FDL_PI_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  pi_reg_index value
 */
#define PI_REG_INTSR	0x000
#define PI_REG_INTMSK	0x004
#define PI_REG_CPBAS	0x00c
#define PI_REG_CPTOP	0x010
#define PI_REG_CPWRT	0x014
#define PI_REG_CPABT	0x018
#define PI_REG_PIESR	0x01c
#define PI_REG_PIEAR	0x020
#define PI_REG_CONFIG	0x024
#define PI_REG_DURAR	0x028
#define PI_REG_CHIPID	0x02c
#define PI_REG_STRGTH	0x030
#define PI_REG_CPUDBB	0x034

/*
 *  pi_regspace value
 */
#define PI_REGSP_CP	0x0c000000
#define PI_REGSP_PE	0x0c001000
#define PI_REGSP_VI	0x0c002000
#define PI_REGSP_PI	0x0c003000
#define PI_REGSP_MEM	0x0c004000
#define PI_REGSP_DSP	0x0c005000
#define PI_REGSP_IO	0x0c006000
#define PI_GFXSP	0x0c008000

/*
 *  pi_memspace value
 */
#define PI_MEMSP_MEM1	0x00000000
#define PI_MEMSP_MEM2	0x01800000
#define PI_MEMSP_EFB	0x08000000
#define PI_MEMSP_ROM	0xfff00000

/*
 *  pi_intsr_reg struct
 */
#define PI_INTSR_REG_PIINT_SIZE	1
#define PI_INTSR_REG_PIINT_SHIFT	0
#define PI_INTSR_REG_PIINT_MASK	0x00000001
#define PI_INTSR_REG_GET_PIINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_PIINT_MASK) >> PI_INTSR_REG_PIINT_SHIFT)
#define PI_INTSR_REG_SET_PIINT(pi_intsr_reg, piint) { \
	FDL_ASSERT(!((piint) & ~((1 << PI_INTSR_REG_PIINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_PIINT_MASK) | (((unsigned long)(piint)) << PI_INTSR_REG_PIINT_SHIFT);\
}
#define PI_INTSR_REG_RSWINT_SIZE	1
#define PI_INTSR_REG_RSWINT_SHIFT	1
#define PI_INTSR_REG_RSWINT_MASK	0x00000002
#define PI_INTSR_REG_GET_RSWINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_RSWINT_MASK) >> PI_INTSR_REG_RSWINT_SHIFT)
#define PI_INTSR_REG_SET_RSWINT(pi_intsr_reg, rswint) { \
	FDL_ASSERT(!((rswint) & ~((1 << PI_INTSR_REG_RSWINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_RSWINT_MASK) | (((unsigned long)(rswint)) << PI_INTSR_REG_RSWINT_SHIFT);\
}
#define PI_INTSR_REG_DIINT_SIZE	1
#define PI_INTSR_REG_DIINT_SHIFT	2
#define PI_INTSR_REG_DIINT_MASK	0x00000004
#define PI_INTSR_REG_GET_DIINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_DIINT_MASK) >> PI_INTSR_REG_DIINT_SHIFT)
#define PI_INTSR_REG_SET_DIINT(pi_intsr_reg, diint) { \
	FDL_ASSERT(!((diint) & ~((1 << PI_INTSR_REG_DIINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_DIINT_MASK) | (((unsigned long)(diint)) << PI_INTSR_REG_DIINT_SHIFT);\
}
#define PI_INTSR_REG_SIINT_SIZE	1
#define PI_INTSR_REG_SIINT_SHIFT	3
#define PI_INTSR_REG_SIINT_MASK	0x00000008
#define PI_INTSR_REG_GET_SIINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_SIINT_MASK) >> PI_INTSR_REG_SIINT_SHIFT)
#define PI_INTSR_REG_SET_SIINT(pi_intsr_reg, siint) { \
	FDL_ASSERT(!((siint) & ~((1 << PI_INTSR_REG_SIINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_SIINT_MASK) | (((unsigned long)(siint)) << PI_INTSR_REG_SIINT_SHIFT);\
}
#define PI_INTSR_REG_EXINT_SIZE	1
#define PI_INTSR_REG_EXINT_SHIFT	4
#define PI_INTSR_REG_EXINT_MASK	0x00000010
#define PI_INTSR_REG_GET_EXINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_EXINT_MASK) >> PI_INTSR_REG_EXINT_SHIFT)
#define PI_INTSR_REG_SET_EXINT(pi_intsr_reg, exint) { \
	FDL_ASSERT(!((exint) & ~((1 << PI_INTSR_REG_EXINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_EXINT_MASK) | (((unsigned long)(exint)) << PI_INTSR_REG_EXINT_SHIFT);\
}
#define PI_INTSR_REG_AIINT_SIZE	1
#define PI_INTSR_REG_AIINT_SHIFT	5
#define PI_INTSR_REG_AIINT_MASK	0x00000020
#define PI_INTSR_REG_GET_AIINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_AIINT_MASK) >> PI_INTSR_REG_AIINT_SHIFT)
#define PI_INTSR_REG_SET_AIINT(pi_intsr_reg, aiint) { \
	FDL_ASSERT(!((aiint) & ~((1 << PI_INTSR_REG_AIINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_AIINT_MASK) | (((unsigned long)(aiint)) << PI_INTSR_REG_AIINT_SHIFT);\
}
#define PI_INTSR_REG_DSPINT_SIZE	1
#define PI_INTSR_REG_DSPINT_SHIFT	6
#define PI_INTSR_REG_DSPINT_MASK	0x00000040
#define PI_INTSR_REG_GET_DSPINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_DSPINT_MASK) >> PI_INTSR_REG_DSPINT_SHIFT)
#define PI_INTSR_REG_SET_DSPINT(pi_intsr_reg, dspint) { \
	FDL_ASSERT(!((dspint) & ~((1 << PI_INTSR_REG_DSPINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_DSPINT_MASK) | (((unsigned long)(dspint)) << PI_INTSR_REG_DSPINT_SHIFT);\
}
#define PI_INTSR_REG_MEMINT_SIZE	1
#define PI_INTSR_REG_MEMINT_SHIFT	7
#define PI_INTSR_REG_MEMINT_MASK	0x00000080
#define PI_INTSR_REG_GET_MEMINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_MEMINT_MASK) >> PI_INTSR_REG_MEMINT_SHIFT)
#define PI_INTSR_REG_SET_MEMINT(pi_intsr_reg, memint) { \
	FDL_ASSERT(!((memint) & ~((1 << PI_INTSR_REG_MEMINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_MEMINT_MASK) | (((unsigned long)(memint)) << PI_INTSR_REG_MEMINT_SHIFT);\
}
#define PI_INTSR_REG_VIINT_SIZE	1
#define PI_INTSR_REG_VIINT_SHIFT	8
#define PI_INTSR_REG_VIINT_MASK	0x00000100
#define PI_INTSR_REG_GET_VIINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_VIINT_MASK) >> PI_INTSR_REG_VIINT_SHIFT)
#define PI_INTSR_REG_SET_VIINT(pi_intsr_reg, viint) { \
	FDL_ASSERT(!((viint) & ~((1 << PI_INTSR_REG_VIINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_VIINT_MASK) | (((unsigned long)(viint)) << PI_INTSR_REG_VIINT_SHIFT);\
}
#define PI_INTSR_REG_PEINT0_SIZE	1
#define PI_INTSR_REG_PEINT0_SHIFT	9
#define PI_INTSR_REG_PEINT0_MASK	0x00000200
#define PI_INTSR_REG_GET_PEINT0(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_PEINT0_MASK) >> PI_INTSR_REG_PEINT0_SHIFT)
#define PI_INTSR_REG_SET_PEINT0(pi_intsr_reg, peint0) { \
	FDL_ASSERT(!((peint0) & ~((1 << PI_INTSR_REG_PEINT0_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_PEINT0_MASK) | (((unsigned long)(peint0)) << PI_INTSR_REG_PEINT0_SHIFT);\
}
#define PI_INTSR_REG_PEINT1_SIZE	1
#define PI_INTSR_REG_PEINT1_SHIFT	10
#define PI_INTSR_REG_PEINT1_MASK	0x00000400
#define PI_INTSR_REG_GET_PEINT1(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_PEINT1_MASK) >> PI_INTSR_REG_PEINT1_SHIFT)
#define PI_INTSR_REG_SET_PEINT1(pi_intsr_reg, peint1) { \
	FDL_ASSERT(!((peint1) & ~((1 << PI_INTSR_REG_PEINT1_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_PEINT1_MASK) | (((unsigned long)(peint1)) << PI_INTSR_REG_PEINT1_SHIFT);\
}
#define PI_INTSR_REG_CPINT_SIZE	1
#define PI_INTSR_REG_CPINT_SHIFT	11
#define PI_INTSR_REG_CPINT_MASK	0x00000800
#define PI_INTSR_REG_GET_CPINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_CPINT_MASK) >> PI_INTSR_REG_CPINT_SHIFT)
#define PI_INTSR_REG_SET_CPINT(pi_intsr_reg, cpint) { \
	FDL_ASSERT(!((cpint) & ~((1 << PI_INTSR_REG_CPINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_CPINT_MASK) | (((unsigned long)(cpint)) << PI_INTSR_REG_CPINT_SHIFT);\
}
#define PI_INTSR_REG_DBGINT_SIZE	1
#define PI_INTSR_REG_DBGINT_SHIFT	12
#define PI_INTSR_REG_DBGINT_MASK	0x00001000
#define PI_INTSR_REG_GET_DBGINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_DBGINT_MASK) >> PI_INTSR_REG_DBGINT_SHIFT)
#define PI_INTSR_REG_SET_DBGINT(pi_intsr_reg, dbgint) { \
	FDL_ASSERT(!((dbgint) & ~((1 << PI_INTSR_REG_DBGINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_DBGINT_MASK) | (((unsigned long)(dbgint)) << PI_INTSR_REG_DBGINT_SHIFT);\
}
#define PI_INTSR_REG_SDINT_SIZE	1
#define PI_INTSR_REG_SDINT_SHIFT	13
#define PI_INTSR_REG_SDINT_MASK	0x00002000
#define PI_INTSR_REG_GET_SDINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_SDINT_MASK) >> PI_INTSR_REG_SDINT_SHIFT)
#define PI_INTSR_REG_SET_SDINT(pi_intsr_reg, sdint) { \
	FDL_ASSERT(!((sdint) & ~((1 << PI_INTSR_REG_SDINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_SDINT_MASK) | (((unsigned long)(sdint)) << PI_INTSR_REG_SDINT_SHIFT);\
}
#define PI_INTSR_REG_ACRINT_SIZE	1
#define PI_INTSR_REG_ACRINT_SHIFT	14
#define PI_INTSR_REG_ACRINT_MASK	0x00004000
#define PI_INTSR_REG_GET_ACRINT(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_ACRINT_MASK) >> PI_INTSR_REG_ACRINT_SHIFT)
#define PI_INTSR_REG_SET_ACRINT(pi_intsr_reg, acrint) { \
	FDL_ASSERT(!((acrint) & ~((1 << PI_INTSR_REG_ACRINT_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_ACRINT_MASK) | (((unsigned long)(acrint)) << PI_INTSR_REG_ACRINT_SHIFT);\
}
#define PI_INTSR_REG_PAD0_SIZE	1
#define PI_INTSR_REG_PAD0_SHIFT	15
#define PI_INTSR_REG_PAD0_MASK	0x00008000
#define PI_INTSR_REG_GET_PAD0(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_PAD0_MASK) >> PI_INTSR_REG_PAD0_SHIFT)
#define PI_INTSR_REG_SET_PAD0(pi_intsr_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_INTSR_REG_PAD0_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_INTSR_REG_PAD0_SHIFT);\
}
#define PI_INTSR_REG_RSTVAL_SIZE	1
#define PI_INTSR_REG_RSTVAL_SHIFT	16
#define PI_INTSR_REG_RSTVAL_MASK	0x00010000
#define PI_INTSR_REG_GET_RSTVAL(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_RSTVAL_MASK) >> PI_INTSR_REG_RSTVAL_SHIFT)
#define PI_INTSR_REG_SET_RSTVAL(pi_intsr_reg, rstval) { \
	FDL_ASSERT(!((rstval) & ~((1 << PI_INTSR_REG_RSTVAL_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_RSTVAL_MASK) | (((unsigned long)(rstval)) << PI_INTSR_REG_RSTVAL_SHIFT);\
}
#define PI_INTSR_REG_PAD1_SIZE	15
#define PI_INTSR_REG_PAD1_SHIFT	17
#define PI_INTSR_REG_PAD1_MASK	0xfffe0000
#define PI_INTSR_REG_GET_PAD1(pi_intsr_reg) \
	((((unsigned long)(pi_intsr_reg)) & PI_INTSR_REG_PAD1_MASK) >> PI_INTSR_REG_PAD1_SHIFT)
#define PI_INTSR_REG_SET_PAD1(pi_intsr_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << PI_INTSR_REG_PAD1_SIZE)-1))); \
	pi_intsr_reg = (((unsigned long)(pi_intsr_reg)) & ~PI_INTSR_REG_PAD1_MASK) | (((unsigned long)(pad1)) << PI_INTSR_REG_PAD1_SHIFT);\
}
#define PI_INTSR_REG_TOTAL_SIZE	32
#define PI_INTSR_REG(piint, rswint, diint, siint, exint, aiint, dspint, memint, viint, peint0, peint1, cpint, dbgint, sdint, acrint, rstval) \
	((((unsigned long)(piint)) << PI_INTSR_REG_PIINT_SHIFT) | \
	 (((unsigned long)(rswint)) << PI_INTSR_REG_RSWINT_SHIFT) | \
	 (((unsigned long)(diint)) << PI_INTSR_REG_DIINT_SHIFT) | \
	 (((unsigned long)(siint)) << PI_INTSR_REG_SIINT_SHIFT) | \
	 (((unsigned long)(exint)) << PI_INTSR_REG_EXINT_SHIFT) | \
	 (((unsigned long)(aiint)) << PI_INTSR_REG_AIINT_SHIFT) | \
	 (((unsigned long)(dspint)) << PI_INTSR_REG_DSPINT_SHIFT) | \
	 (((unsigned long)(memint)) << PI_INTSR_REG_MEMINT_SHIFT) | \
	 (((unsigned long)(viint)) << PI_INTSR_REG_VIINT_SHIFT) | \
	 (((unsigned long)(peint0)) << PI_INTSR_REG_PEINT0_SHIFT) | \
	 (((unsigned long)(peint1)) << PI_INTSR_REG_PEINT1_SHIFT) | \
	 (((unsigned long)(cpint)) << PI_INTSR_REG_CPINT_SHIFT) | \
	 (((unsigned long)(dbgint)) << PI_INTSR_REG_DBGINT_SHIFT) | \
	 (((unsigned long)(sdint)) << PI_INTSR_REG_SDINT_SHIFT) | \
	 (((unsigned long)(acrint)) << PI_INTSR_REG_ACRINT_SHIFT) | \
	 (((unsigned long)(rstval)) << PI_INTSR_REG_RSTVAL_SHIFT))

/*
 *  pi_intmsk_reg struct
 */
#define PI_INTMSK_REG_PIMSK_SIZE	1
#define PI_INTMSK_REG_PIMSK_SHIFT	0
#define PI_INTMSK_REG_PIMSK_MASK	0x00000001
#define PI_INTMSK_REG_GET_PIMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_PIMSK_MASK) >> PI_INTMSK_REG_PIMSK_SHIFT)
#define PI_INTMSK_REG_SET_PIMSK(pi_intmsk_reg, pimsk) { \
	FDL_ASSERT(!((pimsk) & ~((1 << PI_INTMSK_REG_PIMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_PIMSK_MASK) | (((unsigned long)(pimsk)) << PI_INTMSK_REG_PIMSK_SHIFT);\
}
#define PI_INTMSK_REG_RSWMSK_SIZE	1
#define PI_INTMSK_REG_RSWMSK_SHIFT	1
#define PI_INTMSK_REG_RSWMSK_MASK	0x00000002
#define PI_INTMSK_REG_GET_RSWMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_RSWMSK_MASK) >> PI_INTMSK_REG_RSWMSK_SHIFT)
#define PI_INTMSK_REG_SET_RSWMSK(pi_intmsk_reg, rswmsk) { \
	FDL_ASSERT(!((rswmsk) & ~((1 << PI_INTMSK_REG_RSWMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_RSWMSK_MASK) | (((unsigned long)(rswmsk)) << PI_INTMSK_REG_RSWMSK_SHIFT);\
}
#define PI_INTMSK_REG_DIMSK_SIZE	1
#define PI_INTMSK_REG_DIMSK_SHIFT	2
#define PI_INTMSK_REG_DIMSK_MASK	0x00000004
#define PI_INTMSK_REG_GET_DIMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_DIMSK_MASK) >> PI_INTMSK_REG_DIMSK_SHIFT)
#define PI_INTMSK_REG_SET_DIMSK(pi_intmsk_reg, dimsk) { \
	FDL_ASSERT(!((dimsk) & ~((1 << PI_INTMSK_REG_DIMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_DIMSK_MASK) | (((unsigned long)(dimsk)) << PI_INTMSK_REG_DIMSK_SHIFT);\
}
#define PI_INTMSK_REG_SIMSK_SIZE	1
#define PI_INTMSK_REG_SIMSK_SHIFT	3
#define PI_INTMSK_REG_SIMSK_MASK	0x00000008
#define PI_INTMSK_REG_GET_SIMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_SIMSK_MASK) >> PI_INTMSK_REG_SIMSK_SHIFT)
#define PI_INTMSK_REG_SET_SIMSK(pi_intmsk_reg, simsk) { \
	FDL_ASSERT(!((simsk) & ~((1 << PI_INTMSK_REG_SIMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_SIMSK_MASK) | (((unsigned long)(simsk)) << PI_INTMSK_REG_SIMSK_SHIFT);\
}
#define PI_INTMSK_REG_EXMSK_SIZE	1
#define PI_INTMSK_REG_EXMSK_SHIFT	4
#define PI_INTMSK_REG_EXMSK_MASK	0x00000010
#define PI_INTMSK_REG_GET_EXMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_EXMSK_MASK) >> PI_INTMSK_REG_EXMSK_SHIFT)
#define PI_INTMSK_REG_SET_EXMSK(pi_intmsk_reg, exmsk) { \
	FDL_ASSERT(!((exmsk) & ~((1 << PI_INTMSK_REG_EXMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_EXMSK_MASK) | (((unsigned long)(exmsk)) << PI_INTMSK_REG_EXMSK_SHIFT);\
}
#define PI_INTMSK_REG_AIMSK_SIZE	1
#define PI_INTMSK_REG_AIMSK_SHIFT	5
#define PI_INTMSK_REG_AIMSK_MASK	0x00000020
#define PI_INTMSK_REG_GET_AIMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_AIMSK_MASK) >> PI_INTMSK_REG_AIMSK_SHIFT)
#define PI_INTMSK_REG_SET_AIMSK(pi_intmsk_reg, aimsk) { \
	FDL_ASSERT(!((aimsk) & ~((1 << PI_INTMSK_REG_AIMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_AIMSK_MASK) | (((unsigned long)(aimsk)) << PI_INTMSK_REG_AIMSK_SHIFT);\
}
#define PI_INTMSK_REG_DSPMSK_SIZE	1
#define PI_INTMSK_REG_DSPMSK_SHIFT	6
#define PI_INTMSK_REG_DSPMSK_MASK	0x00000040
#define PI_INTMSK_REG_GET_DSPMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_DSPMSK_MASK) >> PI_INTMSK_REG_DSPMSK_SHIFT)
#define PI_INTMSK_REG_SET_DSPMSK(pi_intmsk_reg, dspmsk) { \
	FDL_ASSERT(!((dspmsk) & ~((1 << PI_INTMSK_REG_DSPMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_DSPMSK_MASK) | (((unsigned long)(dspmsk)) << PI_INTMSK_REG_DSPMSK_SHIFT);\
}
#define PI_INTMSK_REG_MEMMSK_SIZE	1
#define PI_INTMSK_REG_MEMMSK_SHIFT	7
#define PI_INTMSK_REG_MEMMSK_MASK	0x00000080
#define PI_INTMSK_REG_GET_MEMMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_MEMMSK_MASK) >> PI_INTMSK_REG_MEMMSK_SHIFT)
#define PI_INTMSK_REG_SET_MEMMSK(pi_intmsk_reg, memmsk) { \
	FDL_ASSERT(!((memmsk) & ~((1 << PI_INTMSK_REG_MEMMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_MEMMSK_MASK) | (((unsigned long)(memmsk)) << PI_INTMSK_REG_MEMMSK_SHIFT);\
}
#define PI_INTMSK_REG_VIMSK_SIZE	1
#define PI_INTMSK_REG_VIMSK_SHIFT	8
#define PI_INTMSK_REG_VIMSK_MASK	0x00000100
#define PI_INTMSK_REG_GET_VIMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_VIMSK_MASK) >> PI_INTMSK_REG_VIMSK_SHIFT)
#define PI_INTMSK_REG_SET_VIMSK(pi_intmsk_reg, vimsk) { \
	FDL_ASSERT(!((vimsk) & ~((1 << PI_INTMSK_REG_VIMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_VIMSK_MASK) | (((unsigned long)(vimsk)) << PI_INTMSK_REG_VIMSK_SHIFT);\
}
#define PI_INTMSK_REG_PEMSK0_SIZE	1
#define PI_INTMSK_REG_PEMSK0_SHIFT	9
#define PI_INTMSK_REG_PEMSK0_MASK	0x00000200
#define PI_INTMSK_REG_GET_PEMSK0(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_PEMSK0_MASK) >> PI_INTMSK_REG_PEMSK0_SHIFT)
#define PI_INTMSK_REG_SET_PEMSK0(pi_intmsk_reg, pemsk0) { \
	FDL_ASSERT(!((pemsk0) & ~((1 << PI_INTMSK_REG_PEMSK0_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_PEMSK0_MASK) | (((unsigned long)(pemsk0)) << PI_INTMSK_REG_PEMSK0_SHIFT);\
}
#define PI_INTMSK_REG_PEMSK1_SIZE	1
#define PI_INTMSK_REG_PEMSK1_SHIFT	10
#define PI_INTMSK_REG_PEMSK1_MASK	0x00000400
#define PI_INTMSK_REG_GET_PEMSK1(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_PEMSK1_MASK) >> PI_INTMSK_REG_PEMSK1_SHIFT)
#define PI_INTMSK_REG_SET_PEMSK1(pi_intmsk_reg, pemsk1) { \
	FDL_ASSERT(!((pemsk1) & ~((1 << PI_INTMSK_REG_PEMSK1_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_PEMSK1_MASK) | (((unsigned long)(pemsk1)) << PI_INTMSK_REG_PEMSK1_SHIFT);\
}
#define PI_INTMSK_REG_CPMSK_SIZE	1
#define PI_INTMSK_REG_CPMSK_SHIFT	11
#define PI_INTMSK_REG_CPMSK_MASK	0x00000800
#define PI_INTMSK_REG_GET_CPMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_CPMSK_MASK) >> PI_INTMSK_REG_CPMSK_SHIFT)
#define PI_INTMSK_REG_SET_CPMSK(pi_intmsk_reg, cpmsk) { \
	FDL_ASSERT(!((cpmsk) & ~((1 << PI_INTMSK_REG_CPMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_CPMSK_MASK) | (((unsigned long)(cpmsk)) << PI_INTMSK_REG_CPMSK_SHIFT);\
}
#define PI_INTMSK_REG_DBGMSK_SIZE	1
#define PI_INTMSK_REG_DBGMSK_SHIFT	12
#define PI_INTMSK_REG_DBGMSK_MASK	0x00001000
#define PI_INTMSK_REG_GET_DBGMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_DBGMSK_MASK) >> PI_INTMSK_REG_DBGMSK_SHIFT)
#define PI_INTMSK_REG_SET_DBGMSK(pi_intmsk_reg, dbgmsk) { \
	FDL_ASSERT(!((dbgmsk) & ~((1 << PI_INTMSK_REG_DBGMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_DBGMSK_MASK) | (((unsigned long)(dbgmsk)) << PI_INTMSK_REG_DBGMSK_SHIFT);\
}
#define PI_INTMSK_REG_SDMSK_SIZE	1
#define PI_INTMSK_REG_SDMSK_SHIFT	13
#define PI_INTMSK_REG_SDMSK_MASK	0x00002000
#define PI_INTMSK_REG_GET_SDMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_SDMSK_MASK) >> PI_INTMSK_REG_SDMSK_SHIFT)
#define PI_INTMSK_REG_SET_SDMSK(pi_intmsk_reg, sdmsk) { \
	FDL_ASSERT(!((sdmsk) & ~((1 << PI_INTMSK_REG_SDMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_SDMSK_MASK) | (((unsigned long)(sdmsk)) << PI_INTMSK_REG_SDMSK_SHIFT);\
}
#define PI_INTMSK_REG_ACRMSK_SIZE	1
#define PI_INTMSK_REG_ACRMSK_SHIFT	14
#define PI_INTMSK_REG_ACRMSK_MASK	0x00004000
#define PI_INTMSK_REG_GET_ACRMSK(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_ACRMSK_MASK) >> PI_INTMSK_REG_ACRMSK_SHIFT)
#define PI_INTMSK_REG_SET_ACRMSK(pi_intmsk_reg, acrmsk) { \
	FDL_ASSERT(!((acrmsk) & ~((1 << PI_INTMSK_REG_ACRMSK_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_ACRMSK_MASK) | (((unsigned long)(acrmsk)) << PI_INTMSK_REG_ACRMSK_SHIFT);\
}
#define PI_INTMSK_REG_PAD0_SIZE	17
#define PI_INTMSK_REG_PAD0_SHIFT	15
#define PI_INTMSK_REG_PAD0_MASK	0xffff8000
#define PI_INTMSK_REG_GET_PAD0(pi_intmsk_reg) \
	((((unsigned long)(pi_intmsk_reg)) & PI_INTMSK_REG_PAD0_MASK) >> PI_INTMSK_REG_PAD0_SHIFT)
#define PI_INTMSK_REG_SET_PAD0(pi_intmsk_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_INTMSK_REG_PAD0_SIZE)-1))); \
	pi_intmsk_reg = (((unsigned long)(pi_intmsk_reg)) & ~PI_INTMSK_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_INTMSK_REG_PAD0_SHIFT);\
}
#define PI_INTMSK_REG_TOTAL_SIZE	32
#define PI_INTMSK_REG(pimsk, rswmsk, dimsk, simsk, exmsk, aimsk, dspmsk, memmsk, vimsk, pemsk0, pemsk1, cpmsk, dbgmsk, sdmsk, acrmsk) \
	((((unsigned long)(pimsk)) << PI_INTMSK_REG_PIMSK_SHIFT) | \
	 (((unsigned long)(rswmsk)) << PI_INTMSK_REG_RSWMSK_SHIFT) | \
	 (((unsigned long)(dimsk)) << PI_INTMSK_REG_DIMSK_SHIFT) | \
	 (((unsigned long)(simsk)) << PI_INTMSK_REG_SIMSK_SHIFT) | \
	 (((unsigned long)(exmsk)) << PI_INTMSK_REG_EXMSK_SHIFT) | \
	 (((unsigned long)(aimsk)) << PI_INTMSK_REG_AIMSK_SHIFT) | \
	 (((unsigned long)(dspmsk)) << PI_INTMSK_REG_DSPMSK_SHIFT) | \
	 (((unsigned long)(memmsk)) << PI_INTMSK_REG_MEMMSK_SHIFT) | \
	 (((unsigned long)(vimsk)) << PI_INTMSK_REG_VIMSK_SHIFT) | \
	 (((unsigned long)(pemsk0)) << PI_INTMSK_REG_PEMSK0_SHIFT) | \
	 (((unsigned long)(pemsk1)) << PI_INTMSK_REG_PEMSK1_SHIFT) | \
	 (((unsigned long)(cpmsk)) << PI_INTMSK_REG_CPMSK_SHIFT) | \
	 (((unsigned long)(dbgmsk)) << PI_INTMSK_REG_DBGMSK_SHIFT) | \
	 (((unsigned long)(sdmsk)) << PI_INTMSK_REG_SDMSK_SHIFT) | \
	 (((unsigned long)(acrmsk)) << PI_INTMSK_REG_ACRMSK_SHIFT))

/*
 *  pi_cpbas_reg struct
 */
#define PI_CPBAS_REG_PAD0_SIZE	5
#define PI_CPBAS_REG_PAD0_SHIFT	0
#define PI_CPBAS_REG_PAD0_MASK	0x0000001f
#define PI_CPBAS_REG_GET_PAD0(pi_cpbas_reg) \
	((((unsigned long)(pi_cpbas_reg)) & PI_CPBAS_REG_PAD0_MASK) >> PI_CPBAS_REG_PAD0_SHIFT)
#define PI_CPBAS_REG_SET_PAD0(pi_cpbas_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_CPBAS_REG_PAD0_SIZE)-1))); \
	pi_cpbas_reg = (((unsigned long)(pi_cpbas_reg)) & ~PI_CPBAS_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_CPBAS_REG_PAD0_SHIFT);\
}
#define PI_CPBAS_REG_CPBAS_SIZE	24
#define PI_CPBAS_REG_CPBAS_SHIFT	5
#define PI_CPBAS_REG_CPBAS_MASK	0x1fffffe0
#define PI_CPBAS_REG_GET_CPBAS(pi_cpbas_reg) \
	((((unsigned long)(pi_cpbas_reg)) & PI_CPBAS_REG_CPBAS_MASK) >> PI_CPBAS_REG_CPBAS_SHIFT)
#define PI_CPBAS_REG_SET_CPBAS(pi_cpbas_reg, cpbas) { \
	FDL_ASSERT(!((cpbas) & ~((1 << PI_CPBAS_REG_CPBAS_SIZE)-1))); \
	pi_cpbas_reg = (((unsigned long)(pi_cpbas_reg)) & ~PI_CPBAS_REG_CPBAS_MASK) | (((unsigned long)(cpbas)) << PI_CPBAS_REG_CPBAS_SHIFT);\
}
#define PI_CPBAS_REG_PAD1_SIZE	3
#define PI_CPBAS_REG_PAD1_SHIFT	29
#define PI_CPBAS_REG_PAD1_MASK	0xe0000000
#define PI_CPBAS_REG_GET_PAD1(pi_cpbas_reg) \
	((((unsigned long)(pi_cpbas_reg)) & PI_CPBAS_REG_PAD1_MASK) >> PI_CPBAS_REG_PAD1_SHIFT)
#define PI_CPBAS_REG_SET_PAD1(pi_cpbas_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << PI_CPBAS_REG_PAD1_SIZE)-1))); \
	pi_cpbas_reg = (((unsigned long)(pi_cpbas_reg)) & ~PI_CPBAS_REG_PAD1_MASK) | (((unsigned long)(pad1)) << PI_CPBAS_REG_PAD1_SHIFT);\
}
#define PI_CPBAS_REG_TOTAL_SIZE	32
#define PI_CPBAS_REG(cpbas) \
	((((unsigned long)(cpbas)) << PI_CPBAS_REG_CPBAS_SHIFT))

/*
 *  pi_cptop_reg struct
 */
#define PI_CPTOP_REG_PAD0_SIZE	5
#define PI_CPTOP_REG_PAD0_SHIFT	0
#define PI_CPTOP_REG_PAD0_MASK	0x0000001f
#define PI_CPTOP_REG_GET_PAD0(pi_cptop_reg) \
	((((unsigned long)(pi_cptop_reg)) & PI_CPTOP_REG_PAD0_MASK) >> PI_CPTOP_REG_PAD0_SHIFT)
#define PI_CPTOP_REG_SET_PAD0(pi_cptop_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_CPTOP_REG_PAD0_SIZE)-1))); \
	pi_cptop_reg = (((unsigned long)(pi_cptop_reg)) & ~PI_CPTOP_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_CPTOP_REG_PAD0_SHIFT);\
}
#define PI_CPTOP_REG_CPTOP_SIZE	24
#define PI_CPTOP_REG_CPTOP_SHIFT	5
#define PI_CPTOP_REG_CPTOP_MASK	0x1fffffe0
#define PI_CPTOP_REG_GET_CPTOP(pi_cptop_reg) \
	((((unsigned long)(pi_cptop_reg)) & PI_CPTOP_REG_CPTOP_MASK) >> PI_CPTOP_REG_CPTOP_SHIFT)
#define PI_CPTOP_REG_SET_CPTOP(pi_cptop_reg, cptop) { \
	FDL_ASSERT(!((cptop) & ~((1 << PI_CPTOP_REG_CPTOP_SIZE)-1))); \
	pi_cptop_reg = (((unsigned long)(pi_cptop_reg)) & ~PI_CPTOP_REG_CPTOP_MASK) | (((unsigned long)(cptop)) << PI_CPTOP_REG_CPTOP_SHIFT);\
}
#define PI_CPTOP_REG_PAD1_SIZE	3
#define PI_CPTOP_REG_PAD1_SHIFT	29
#define PI_CPTOP_REG_PAD1_MASK	0xe0000000
#define PI_CPTOP_REG_GET_PAD1(pi_cptop_reg) \
	((((unsigned long)(pi_cptop_reg)) & PI_CPTOP_REG_PAD1_MASK) >> PI_CPTOP_REG_PAD1_SHIFT)
#define PI_CPTOP_REG_SET_PAD1(pi_cptop_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << PI_CPTOP_REG_PAD1_SIZE)-1))); \
	pi_cptop_reg = (((unsigned long)(pi_cptop_reg)) & ~PI_CPTOP_REG_PAD1_MASK) | (((unsigned long)(pad1)) << PI_CPTOP_REG_PAD1_SHIFT);\
}
#define PI_CPTOP_REG_TOTAL_SIZE	32
#define PI_CPTOP_REG(cptop) \
	((((unsigned long)(cptop)) << PI_CPTOP_REG_CPTOP_SHIFT))

/*
 *  pi_cpwrt_reg struct
 */
#define PI_CPWRT_REG_PAD0_SIZE	5
#define PI_CPWRT_REG_PAD0_SHIFT	0
#define PI_CPWRT_REG_PAD0_MASK	0x0000001f
#define PI_CPWRT_REG_GET_PAD0(pi_cpwrt_reg) \
	((((unsigned long)(pi_cpwrt_reg)) & PI_CPWRT_REG_PAD0_MASK) >> PI_CPWRT_REG_PAD0_SHIFT)
#define PI_CPWRT_REG_SET_PAD0(pi_cpwrt_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_CPWRT_REG_PAD0_SIZE)-1))); \
	pi_cpwrt_reg = (((unsigned long)(pi_cpwrt_reg)) & ~PI_CPWRT_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_CPWRT_REG_PAD0_SHIFT);\
}
#define PI_CPWRT_REG_CPWRT_SIZE	24
#define PI_CPWRT_REG_CPWRT_SHIFT	5
#define PI_CPWRT_REG_CPWRT_MASK	0x1fffffe0
#define PI_CPWRT_REG_GET_CPWRT(pi_cpwrt_reg) \
	((((unsigned long)(pi_cpwrt_reg)) & PI_CPWRT_REG_CPWRT_MASK) >> PI_CPWRT_REG_CPWRT_SHIFT)
#define PI_CPWRT_REG_SET_CPWRT(pi_cpwrt_reg, cpwrt) { \
	FDL_ASSERT(!((cpwrt) & ~((1 << PI_CPWRT_REG_CPWRT_SIZE)-1))); \
	pi_cpwrt_reg = (((unsigned long)(pi_cpwrt_reg)) & ~PI_CPWRT_REG_CPWRT_MASK) | (((unsigned long)(cpwrt)) << PI_CPWRT_REG_CPWRT_SHIFT);\
}
#define PI_CPWRT_REG_CPWRAP_SIZE	1
#define PI_CPWRT_REG_CPWRAP_SHIFT	29
#define PI_CPWRT_REG_CPWRAP_MASK	0x20000000
#define PI_CPWRT_REG_GET_CPWRAP(pi_cpwrt_reg) \
	((((unsigned long)(pi_cpwrt_reg)) & PI_CPWRT_REG_CPWRAP_MASK) >> PI_CPWRT_REG_CPWRAP_SHIFT)
#define PI_CPWRT_REG_SET_CPWRAP(pi_cpwrt_reg, cpwrap) { \
	FDL_ASSERT(!((cpwrap) & ~((1 << PI_CPWRT_REG_CPWRAP_SIZE)-1))); \
	pi_cpwrt_reg = (((unsigned long)(pi_cpwrt_reg)) & ~PI_CPWRT_REG_CPWRAP_MASK) | (((unsigned long)(cpwrap)) << PI_CPWRT_REG_CPWRAP_SHIFT);\
}
#define PI_CPWRT_REG_PAD1_SIZE	2
#define PI_CPWRT_REG_PAD1_SHIFT	30
#define PI_CPWRT_REG_PAD1_MASK	0xc0000000
#define PI_CPWRT_REG_GET_PAD1(pi_cpwrt_reg) \
	((((unsigned long)(pi_cpwrt_reg)) & PI_CPWRT_REG_PAD1_MASK) >> PI_CPWRT_REG_PAD1_SHIFT)
#define PI_CPWRT_REG_SET_PAD1(pi_cpwrt_reg, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << PI_CPWRT_REG_PAD1_SIZE)-1))); \
	pi_cpwrt_reg = (((unsigned long)(pi_cpwrt_reg)) & ~PI_CPWRT_REG_PAD1_MASK) | (((unsigned long)(pad1)) << PI_CPWRT_REG_PAD1_SHIFT);\
}
#define PI_CPWRT_REG_TOTAL_SIZE	32
#define PI_CPWRT_REG(cpwrt, cpwrap) \
	((((unsigned long)(cpwrt)) << PI_CPWRT_REG_CPWRT_SHIFT) | \
	 (((unsigned long)(cpwrap)) << PI_CPWRT_REG_CPWRAP_SHIFT))

/*
 *  pi_cpabt_reg struct
 */
#define PI_CPABT_REG_CPABT_SIZE	1
#define PI_CPABT_REG_CPABT_SHIFT	0
#define PI_CPABT_REG_CPABT_MASK	0x00000001
#define PI_CPABT_REG_GET_CPABT(pi_cpabt_reg) \
	((((unsigned long)(pi_cpabt_reg)) & PI_CPABT_REG_CPABT_MASK) >> PI_CPABT_REG_CPABT_SHIFT)
#define PI_CPABT_REG_SET_CPABT(pi_cpabt_reg, cpabt) { \
	FDL_ASSERT(!((cpabt) & ~((1 << PI_CPABT_REG_CPABT_SIZE)-1))); \
	pi_cpabt_reg = (((unsigned long)(pi_cpabt_reg)) & ~PI_CPABT_REG_CPABT_MASK) | (((unsigned long)(cpabt)) << PI_CPABT_REG_CPABT_SHIFT);\
}
#define PI_CPABT_REG_PAD0_SIZE	31
#define PI_CPABT_REG_PAD0_SHIFT	1
#define PI_CPABT_REG_PAD0_MASK	0xfffffffe
#define PI_CPABT_REG_GET_PAD0(pi_cpabt_reg) \
	((((unsigned long)(pi_cpabt_reg)) & PI_CPABT_REG_PAD0_MASK) >> PI_CPABT_REG_PAD0_SHIFT)
#define PI_CPABT_REG_SET_PAD0(pi_cpabt_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_CPABT_REG_PAD0_SIZE)-1))); \
	pi_cpabt_reg = (((unsigned long)(pi_cpabt_reg)) & ~PI_CPABT_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_CPABT_REG_PAD0_SHIFT);\
}
#define PI_CPABT_REG_TOTAL_SIZE	32
#define PI_CPABT_REG(cpabt) \
	((((unsigned long)(cpabt)) << PI_CPABT_REG_CPABT_SHIFT))

/*
 *  pi_piesr_reg struct
 */
#define PI_PIESR_REG_PIESR_SIZE	3
#define PI_PIESR_REG_PIESR_SHIFT	0
#define PI_PIESR_REG_PIESR_MASK	0x00000007
#define PI_PIESR_REG_GET_PIESR(pi_piesr_reg) \
	((((unsigned long)(pi_piesr_reg)) & PI_PIESR_REG_PIESR_MASK) >> PI_PIESR_REG_PIESR_SHIFT)
#define PI_PIESR_REG_SET_PIESR(pi_piesr_reg, piesr) { \
	FDL_ASSERT(!((piesr) & ~((1 << PI_PIESR_REG_PIESR_SIZE)-1))); \
	pi_piesr_reg = (((unsigned long)(pi_piesr_reg)) & ~PI_PIESR_REG_PIESR_MASK) | (((unsigned long)(piesr)) << PI_PIESR_REG_PIESR_SHIFT);\
}
#define PI_PIESR_REG_PAD0_SIZE	29
#define PI_PIESR_REG_PAD0_SHIFT	3
#define PI_PIESR_REG_PAD0_MASK	0xfffffff8
#define PI_PIESR_REG_GET_PAD0(pi_piesr_reg) \
	((((unsigned long)(pi_piesr_reg)) & PI_PIESR_REG_PAD0_MASK) >> PI_PIESR_REG_PAD0_SHIFT)
#define PI_PIESR_REG_SET_PAD0(pi_piesr_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_PIESR_REG_PAD0_SIZE)-1))); \
	pi_piesr_reg = (((unsigned long)(pi_piesr_reg)) & ~PI_PIESR_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_PIESR_REG_PAD0_SHIFT);\
}
#define PI_PIESR_REG_TOTAL_SIZE	32
#define PI_PIESR_REG(piesr) \
	((((unsigned long)(piesr)) << PI_PIESR_REG_PIESR_SHIFT))

/*
 *  pi_piear_reg struct
 */
#define PI_PIEAR_REG_PIEAR_SIZE	32
#define PI_PIEAR_REG_PIEAR_SHIFT	0
#define PI_PIEAR_REG_PIEAR_MASK	0xffffffff
#define PI_PIEAR_REG_GET_PIEAR(pi_piear_reg) \
	((((unsigned long)(pi_piear_reg)) & PI_PIEAR_REG_PIEAR_MASK) >> PI_PIEAR_REG_PIEAR_SHIFT)
#define PI_PIEAR_REG_SET_PIEAR(pi_piear_reg, piear) { \
	FDL_ASSERT(!((piear) & ~((1 << PI_PIEAR_REG_PIEAR_SIZE)-1))); \
	pi_piear_reg = (((unsigned long)(pi_piear_reg)) & ~PI_PIEAR_REG_PIEAR_MASK) | (((unsigned long)(piear)) << PI_PIEAR_REG_PIEAR_SHIFT);\
}
#define PI_PIEAR_REG_TOTAL_SIZE	32
#define PI_PIEAR_REG(piear) \
	((((unsigned long)(piear)) << PI_PIEAR_REG_PIEAR_SHIFT))

/*
 *  pi_config_reg struct
 */
#define PI_CONFIG_REG_SYSRSTB_SIZE	1
#define PI_CONFIG_REG_SYSRSTB_SHIFT	0
#define PI_CONFIG_REG_SYSRSTB_MASK	0x00000001
#define PI_CONFIG_REG_GET_SYSRSTB(pi_config_reg) \
	((((unsigned long)(pi_config_reg)) & PI_CONFIG_REG_SYSRSTB_MASK) >> PI_CONFIG_REG_SYSRSTB_SHIFT)
#define PI_CONFIG_REG_SET_SYSRSTB(pi_config_reg, sysrstb) { \
	FDL_ASSERT(!((sysrstb) & ~((1 << PI_CONFIG_REG_SYSRSTB_SIZE)-1))); \
	pi_config_reg = (((unsigned long)(pi_config_reg)) & ~PI_CONFIG_REG_SYSRSTB_MASK) | (((unsigned long)(sysrstb)) << PI_CONFIG_REG_SYSRSTB_SHIFT);\
}
#define PI_CONFIG_REG_MEMRSTB_SIZE	1
#define PI_CONFIG_REG_MEMRSTB_SHIFT	1
#define PI_CONFIG_REG_MEMRSTB_MASK	0x00000002
#define PI_CONFIG_REG_GET_MEMRSTB(pi_config_reg) \
	((((unsigned long)(pi_config_reg)) & PI_CONFIG_REG_MEMRSTB_MASK) >> PI_CONFIG_REG_MEMRSTB_SHIFT)
#define PI_CONFIG_REG_SET_MEMRSTB(pi_config_reg, memrstb) { \
	FDL_ASSERT(!((memrstb) & ~((1 << PI_CONFIG_REG_MEMRSTB_SIZE)-1))); \
	pi_config_reg = (((unsigned long)(pi_config_reg)) & ~PI_CONFIG_REG_MEMRSTB_MASK) | (((unsigned long)(memrstb)) << PI_CONFIG_REG_MEMRSTB_SHIFT);\
}
#define PI_CONFIG_REG_DIRSTB_SIZE	1
#define PI_CONFIG_REG_DIRSTB_SHIFT	2
#define PI_CONFIG_REG_DIRSTB_MASK	0x00000004
#define PI_CONFIG_REG_GET_DIRSTB(pi_config_reg) \
	((((unsigned long)(pi_config_reg)) & PI_CONFIG_REG_DIRSTB_MASK) >> PI_CONFIG_REG_DIRSTB_SHIFT)
#define PI_CONFIG_REG_SET_DIRSTB(pi_config_reg, dirstb) { \
	FDL_ASSERT(!((dirstb) & ~((1 << PI_CONFIG_REG_DIRSTB_SIZE)-1))); \
	pi_config_reg = (((unsigned long)(pi_config_reg)) & ~PI_CONFIG_REG_DIRSTB_MASK) | (((unsigned long)(dirstb)) << PI_CONFIG_REG_DIRSTB_SHIFT);\
}
#define PI_CONFIG_REG_PICFG_SIZE	29
#define PI_CONFIG_REG_PICFG_SHIFT	3
#define PI_CONFIG_REG_PICFG_MASK	0xfffffff8
#define PI_CONFIG_REG_GET_PICFG(pi_config_reg) \
	((((unsigned long)(pi_config_reg)) & PI_CONFIG_REG_PICFG_MASK) >> PI_CONFIG_REG_PICFG_SHIFT)
#define PI_CONFIG_REG_SET_PICFG(pi_config_reg, picfg) { \
	FDL_ASSERT(!((picfg) & ~((1 << PI_CONFIG_REG_PICFG_SIZE)-1))); \
	pi_config_reg = (((unsigned long)(pi_config_reg)) & ~PI_CONFIG_REG_PICFG_MASK) | (((unsigned long)(picfg)) << PI_CONFIG_REG_PICFG_SHIFT);\
}
#define PI_CONFIG_REG_TOTAL_SIZE	32
#define PI_CONFIG_REG(sysrstb, memrstb, dirstb, picfg) \
	((((unsigned long)(sysrstb)) << PI_CONFIG_REG_SYSRSTB_SHIFT) | \
	 (((unsigned long)(memrstb)) << PI_CONFIG_REG_MEMRSTB_SHIFT) | \
	 (((unsigned long)(dirstb)) << PI_CONFIG_REG_DIRSTB_SHIFT) | \
	 (((unsigned long)(picfg)) << PI_CONFIG_REG_PICFG_SHIFT))

/*
 *  pi_durar_reg struct
 */
#define PI_DURAR_REG_PIRDR_SIZE	10
#define PI_DURAR_REG_PIRDR_SHIFT	0
#define PI_DURAR_REG_PIRDR_MASK	0x000003ff
#define PI_DURAR_REG_GET_PIRDR(pi_durar_reg) \
	((((unsigned long)(pi_durar_reg)) & PI_DURAR_REG_PIRDR_MASK) >> PI_DURAR_REG_PIRDR_SHIFT)
#define PI_DURAR_REG_SET_PIRDR(pi_durar_reg, pirdr) { \
	FDL_ASSERT(!((pirdr) & ~((1 << PI_DURAR_REG_PIRDR_SIZE)-1))); \
	pi_durar_reg = (((unsigned long)(pi_durar_reg)) & ~PI_DURAR_REG_PIRDR_MASK) | (((unsigned long)(pirdr)) << PI_DURAR_REG_PIRDR_SHIFT);\
}
#define PI_DURAR_REG_PAD0_SIZE	22
#define PI_DURAR_REG_PAD0_SHIFT	10
#define PI_DURAR_REG_PAD0_MASK	0xfffffc00
#define PI_DURAR_REG_GET_PAD0(pi_durar_reg) \
	((((unsigned long)(pi_durar_reg)) & PI_DURAR_REG_PAD0_MASK) >> PI_DURAR_REG_PAD0_SHIFT)
#define PI_DURAR_REG_SET_PAD0(pi_durar_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_DURAR_REG_PAD0_SIZE)-1))); \
	pi_durar_reg = (((unsigned long)(pi_durar_reg)) & ~PI_DURAR_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_DURAR_REG_PAD0_SHIFT);\
}
#define PI_DURAR_REG_TOTAL_SIZE	32
#define PI_DURAR_REG(pirdr) \
	((((unsigned long)(pirdr)) << PI_DURAR_REG_PIRDR_SHIFT))

/*
 *  pi_strgth_reg struct
 */
#define PI_STRGTH_REG_AI_STR_SIZE	3
#define PI_STRGTH_REG_AI_STR_SHIFT	0
#define PI_STRGTH_REG_AI_STR_MASK	0x00000007
#define PI_STRGTH_REG_GET_AI_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_AI_STR_MASK) >> PI_STRGTH_REG_AI_STR_SHIFT)
#define PI_STRGTH_REG_SET_AI_STR(pi_strgth_reg, ai_str) { \
	FDL_ASSERT(!((ai_str) & ~((1 << PI_STRGTH_REG_AI_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_AI_STR_MASK) | (((unsigned long)(ai_str)) << PI_STRGTH_REG_AI_STR_SHIFT);\
}
#define PI_STRGTH_REG_AIS_STR_SIZE	3
#define PI_STRGTH_REG_AIS_STR_SHIFT	3
#define PI_STRGTH_REG_AIS_STR_MASK	0x00000038
#define PI_STRGTH_REG_GET_AIS_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_AIS_STR_MASK) >> PI_STRGTH_REG_AIS_STR_SHIFT)
#define PI_STRGTH_REG_SET_AIS_STR(pi_strgth_reg, ais_str) { \
	FDL_ASSERT(!((ais_str) & ~((1 << PI_STRGTH_REG_AIS_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_AIS_STR_MASK) | (((unsigned long)(ais_str)) << PI_STRGTH_REG_AIS_STR_SHIFT);\
}
#define PI_STRGTH_REG_SI_STR_SIZE	3
#define PI_STRGTH_REG_SI_STR_SHIFT	6
#define PI_STRGTH_REG_SI_STR_MASK	0x000001c0
#define PI_STRGTH_REG_GET_SI_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_SI_STR_MASK) >> PI_STRGTH_REG_SI_STR_SHIFT)
#define PI_STRGTH_REG_SET_SI_STR(pi_strgth_reg, si_str) { \
	FDL_ASSERT(!((si_str) & ~((1 << PI_STRGTH_REG_SI_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_SI_STR_MASK) | (((unsigned long)(si_str)) << PI_STRGTH_REG_SI_STR_SHIFT);\
}
#define PI_STRGTH_REG_EXI2_STR_SIZE	3
#define PI_STRGTH_REG_EXI2_STR_SHIFT	9
#define PI_STRGTH_REG_EXI2_STR_MASK	0x00000e00
#define PI_STRGTH_REG_GET_EXI2_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_EXI2_STR_MASK) >> PI_STRGTH_REG_EXI2_STR_SHIFT)
#define PI_STRGTH_REG_SET_EXI2_STR(pi_strgth_reg, exi2_str) { \
	FDL_ASSERT(!((exi2_str) & ~((1 << PI_STRGTH_REG_EXI2_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_EXI2_STR_MASK) | (((unsigned long)(exi2_str)) << PI_STRGTH_REG_EXI2_STR_SHIFT);\
}
#define PI_STRGTH_REG_EXI1_STR_SIZE	3
#define PI_STRGTH_REG_EXI1_STR_SHIFT	12
#define PI_STRGTH_REG_EXI1_STR_MASK	0x00007000
#define PI_STRGTH_REG_GET_EXI1_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_EXI1_STR_MASK) >> PI_STRGTH_REG_EXI1_STR_SHIFT)
#define PI_STRGTH_REG_SET_EXI1_STR(pi_strgth_reg, exi1_str) { \
	FDL_ASSERT(!((exi1_str) & ~((1 << PI_STRGTH_REG_EXI1_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_EXI1_STR_MASK) | (((unsigned long)(exi1_str)) << PI_STRGTH_REG_EXI1_STR_SHIFT);\
}
#define PI_STRGTH_REG_EXI0_STR_SIZE	3
#define PI_STRGTH_REG_EXI0_STR_SHIFT	15
#define PI_STRGTH_REG_EXI0_STR_MASK	0x00038000
#define PI_STRGTH_REG_GET_EXI0_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_EXI0_STR_MASK) >> PI_STRGTH_REG_EXI0_STR_SHIFT)
#define PI_STRGTH_REG_SET_EXI0_STR(pi_strgth_reg, exi0_str) { \
	FDL_ASSERT(!((exi0_str) & ~((1 << PI_STRGTH_REG_EXI0_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_EXI0_STR_MASK) | (((unsigned long)(exi0_str)) << PI_STRGTH_REG_EXI0_STR_SHIFT);\
}
#define PI_STRGTH_REG_DI_STR_SIZE	3
#define PI_STRGTH_REG_DI_STR_SHIFT	18
#define PI_STRGTH_REG_DI_STR_MASK	0x001c0000
#define PI_STRGTH_REG_GET_DI_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_DI_STR_MASK) >> PI_STRGTH_REG_DI_STR_SHIFT)
#define PI_STRGTH_REG_SET_DI_STR(pi_strgth_reg, di_str) { \
	FDL_ASSERT(!((di_str) & ~((1 << PI_STRGTH_REG_DI_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_DI_STR_MASK) | (((unsigned long)(di_str)) << PI_STRGTH_REG_DI_STR_SHIFT);\
}
#define PI_STRGTH_REG_VI_STR_SIZE	3
#define PI_STRGTH_REG_VI_STR_SHIFT	21
#define PI_STRGTH_REG_VI_STR_MASK	0x00e00000
#define PI_STRGTH_REG_GET_VI_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_VI_STR_MASK) >> PI_STRGTH_REG_VI_STR_SHIFT)
#define PI_STRGTH_REG_SET_VI_STR(pi_strgth_reg, vi_str) { \
	FDL_ASSERT(!((vi_str) & ~((1 << PI_STRGTH_REG_VI_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_VI_STR_MASK) | (((unsigned long)(vi_str)) << PI_STRGTH_REG_VI_STR_SHIFT);\
}
#define PI_STRGTH_REG_SD_STR_SIZE	3
#define PI_STRGTH_REG_SD_STR_SHIFT	24
#define PI_STRGTH_REG_SD_STR_MASK	0x07000000
#define PI_STRGTH_REG_GET_SD_STR(pi_strgth_reg) \
	((((unsigned long)(pi_strgth_reg)) & PI_STRGTH_REG_SD_STR_MASK) >> PI_STRGTH_REG_SD_STR_SHIFT)
#define PI_STRGTH_REG_SET_SD_STR(pi_strgth_reg, sd_str) { \
	FDL_ASSERT(!((sd_str) & ~((1 << PI_STRGTH_REG_SD_STR_SIZE)-1))); \
	pi_strgth_reg = (((unsigned long)(pi_strgth_reg)) & ~PI_STRGTH_REG_SD_STR_MASK) | (((unsigned long)(sd_str)) << PI_STRGTH_REG_SD_STR_SHIFT);\
}
#define PI_STRGTH_REG_TOTAL_SIZE	27
#define PI_STRGTH_REG_UNUSED_SIZE	5

#define PI_STRGTH_REG(ai_str, ais_str, si_str, exi2_str, exi1_str, exi0_str, di_str, vi_str, sd_str) \
	((((unsigned long)(ai_str)) << PI_STRGTH_REG_AI_STR_SHIFT) | \
	 (((unsigned long)(ais_str)) << PI_STRGTH_REG_AIS_STR_SHIFT) | \
	 (((unsigned long)(si_str)) << PI_STRGTH_REG_SI_STR_SHIFT) | \
	 (((unsigned long)(exi2_str)) << PI_STRGTH_REG_EXI2_STR_SHIFT) | \
	 (((unsigned long)(exi1_str)) << PI_STRGTH_REG_EXI1_STR_SHIFT) | \
	 (((unsigned long)(exi0_str)) << PI_STRGTH_REG_EXI0_STR_SHIFT) | \
	 (((unsigned long)(di_str)) << PI_STRGTH_REG_DI_STR_SHIFT) | \
	 (((unsigned long)(vi_str)) << PI_STRGTH_REG_VI_STR_SHIFT) | \
	 (((unsigned long)(sd_str)) << PI_STRGTH_REG_SD_STR_SHIFT))

/*
 *  pi_cpudbb_reg struct
 */
#define PI_CPUDBB_REG_DBB_SIZE	1
#define PI_CPUDBB_REG_DBB_SHIFT	0
#define PI_CPUDBB_REG_DBB_MASK	0x00000001
#define PI_CPUDBB_REG_GET_DBB(pi_cpudbb_reg) \
	((((unsigned long)(pi_cpudbb_reg)) & PI_CPUDBB_REG_DBB_MASK) >> PI_CPUDBB_REG_DBB_SHIFT)
#define PI_CPUDBB_REG_SET_DBB(pi_cpudbb_reg, dbb) { \
	FDL_ASSERT(!((dbb) & ~((1 << PI_CPUDBB_REG_DBB_SIZE)-1))); \
	pi_cpudbb_reg = (((unsigned long)(pi_cpudbb_reg)) & ~PI_CPUDBB_REG_DBB_MASK) | (((unsigned long)(dbb)) << PI_CPUDBB_REG_DBB_SHIFT);\
}
#define PI_CPUDBB_REG_PAD0_SIZE	31
#define PI_CPUDBB_REG_PAD0_SHIFT	1
#define PI_CPUDBB_REG_PAD0_MASK	0xfffffffe
#define PI_CPUDBB_REG_GET_PAD0(pi_cpudbb_reg) \
	((((unsigned long)(pi_cpudbb_reg)) & PI_CPUDBB_REG_PAD0_MASK) >> PI_CPUDBB_REG_PAD0_SHIFT)
#define PI_CPUDBB_REG_SET_PAD0(pi_cpudbb_reg, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << PI_CPUDBB_REG_PAD0_SIZE)-1))); \
	pi_cpudbb_reg = (((unsigned long)(pi_cpudbb_reg)) & ~PI_CPUDBB_REG_PAD0_MASK) | (((unsigned long)(pad0)) << PI_CPUDBB_REG_PAD0_SHIFT);\
}
#define PI_CPUDBB_REG_TOTAL_SIZE	32
#define PI_CPUDBB_REG(dbb) \
	((((unsigned long)(dbb)) << PI_CPUDBB_REG_DBB_SHIFT))


#endif /* __FDL_PI_REG_H__ */
