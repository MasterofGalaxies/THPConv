/*
 *  dsp_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from ../../bw/fdl/dsp_reg.fdl
 */

#ifndef __FDL_DSP_REG_H__
#define __FDL_DSP_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  dsp_reg enum
 */
#define DSP_CDMB_IDX    0x00000000
#define DSP_REG_UNUSED_1        0x00000001
#define DSP_DCMBHI_IDX  0x00000002
#define DSP_DCMBLO_IDX  0x00000003
#define DSP_REG_UNUSED_4        0x00000004
#define DSP_CDCR_IDX    0x00000005
#define DSP_REG_UNUSED_6        0x00000006
#define DSP_REG_UNUSED_7        0x00000007
#define DSP_REG_UNUSED_8        0x00000008
#define DSP_AMCR_IDX    0x00000009
#define DSP_REG_UNUSED_10       0x0000000a
#define DSP_AMNF_IDX    0x0000000b
#define DSP_REG_UNUSED_12       0x0000000c
#define DSP_AMCT_IDX    0x0000000d
#define DSP_REG_UNUSED_14       0x0000000e
#define DSP_REG_UNUSED_15       0x0000000f
#define DSP_AMMA_IDX    0x00000010
#define DSP_REG_UNUSED_17       0x00000011
#define DSP_AMAA_IDX    0x00000012
#define DSP_REG_UNUSED_19       0x00000013
#define DSP_AMBL_IDX    0x00000014
#define DSP_REG_UNUSED_21       0x00000015
#define DSP_REG_UNUSED_22       0x00000016
#define DSP_REG_UNUSED_23       0x00000017
#define DSP_AIMA_IDX    0x00000018
#define DSP_REG_UNUSED_25       0x00000019
#define DSP_REG_UNUSED_26       0x0000001a
#define DSP_AIBL_IDX    0x0000001b
#define DSP_REG_UNUSED_28       0x0000001c
#define DSP_AIBLC_IDX   0x0000001d
#define DSP_REG_UNUSED_30       0x0000001e
#define DSP_REG_UNUSED_31       0x0000001f

/*
 *  dsp_expramsz enum
 */
#define DSP_EXP_16M     0x00000000
#define DSP_EXP_32M     0x00000001
#define DSP_EXP_64M     0x00000002
#define DSP_EXP_128M    0x00000003
#define DSP_EXP_256M    0x00000004
#define DSP_EXPRAMSZ_UNUSED_5   0x00000005
#define DSP_EXPRAMSZ_UNUSED_6   0x00000006
#define DSP_EXPRAMSZ_UNUSED_7   0x00000007

/*
 *  dsp_intramsz enum
 */
#define DSP_INT_16M     0x00000000
#define DSP_INT_32M     0x00000001
#define DSP_INT_64M     0x00000002
#define DSP_INT_128M    0x00000003

/*
 *  dsp_caslat enum
 */
#define DSP_CASLAT3     0x00000000
#define DSP_CASLAT2     0x00000001

/*
 *  dsp_cdmb struct
 */
#define DSP_CDMB_DATA_SIZE      31
#define DSP_CDMB_DATA_SHIFT     0
#define DSP_CDMB_DATA_MASK      0x7fffffff
#define DSP_CDMB_GET_DATA(dsp_cdmb) \
        ((((unsigned long)(dsp_cdmb)) & DSP_CDMB_DATA_MASK) >> DSP_CDMB_DATA_SHIFT)
#define DSP_CDMB_SET_DATA(dsp_cdmb, data) { \
        FDL_ASSERT(!((data) & ~((1 << DSP_CDMB_DATA_SIZE)-1))); \
        dsp_cdmb = (((unsigned long)(dsp_cdmb)) & ~DSP_CDMB_DATA_MASK) | (((unsigned long)(data)) << DSP_CDMB_DATA_SHIFT);\
}
#define DSP_CDMB_VLD_SIZE       1
#define DSP_CDMB_VLD_SHIFT      31
#define DSP_CDMB_VLD_MASK       0x80000000
#define DSP_CDMB_GET_VLD(dsp_cdmb) \
        ((((unsigned long)(dsp_cdmb)) & DSP_CDMB_VLD_MASK) >> DSP_CDMB_VLD_SHIFT)
#define DSP_CDMB_SET_VLD(dsp_cdmb, vld) { \
        FDL_ASSERT(!((vld) & ~((1 << DSP_CDMB_VLD_SIZE)-1))); \
        dsp_cdmb = (((unsigned long)(dsp_cdmb)) & ~DSP_CDMB_VLD_MASK) | (((unsigned long)(vld)) << DSP_CDMB_VLD_SHIFT);\
}
#define DSP_CDMB_TOTAL_SIZE     32
#define DSP_CDMB(data, vld) \
        ((((unsigned long)(data)) << DSP_CDMB_DATA_SHIFT) | \
         (((unsigned long)(vld)) << DSP_CDMB_VLD_SHIFT))

/*
 *  dsp_dcmbhi struct
 */
#define DSP_DCMBHI_DATA_SIZE    15
#define DSP_DCMBHI_DATA_SHIFT   0
#define DSP_DCMBHI_DATA_MASK    0x00007fff
#define DSP_DCMBHI_GET_DATA(dsp_dcmbhi) \
        ((((unsigned long)(dsp_dcmbhi)) & DSP_DCMBHI_DATA_MASK) >> DSP_DCMBHI_DATA_SHIFT)
#define DSP_DCMBHI_SET_DATA(dsp_dcmbhi, data) { \
        FDL_ASSERT(!((data) & ~((1 << DSP_DCMBHI_DATA_SIZE)-1))); \
        dsp_dcmbhi = (((unsigned long)(dsp_dcmbhi)) & ~DSP_DCMBHI_DATA_MASK) | (((unsigned long)(data)) << DSP_DCMBHI_DATA_SHIFT);\
}
#define DSP_DCMBHI_VLD_SIZE     1
#define DSP_DCMBHI_VLD_SHIFT    15
#define DSP_DCMBHI_VLD_MASK     0x00008000
#define DSP_DCMBHI_GET_VLD(dsp_dcmbhi) \
        ((((unsigned long)(dsp_dcmbhi)) & DSP_DCMBHI_VLD_MASK) >> DSP_DCMBHI_VLD_SHIFT)
#define DSP_DCMBHI_SET_VLD(dsp_dcmbhi, vld) { \
        FDL_ASSERT(!((vld) & ~((1 << DSP_DCMBHI_VLD_SIZE)-1))); \
        dsp_dcmbhi = (((unsigned long)(dsp_dcmbhi)) & ~DSP_DCMBHI_VLD_MASK) | (((unsigned long)(vld)) << DSP_DCMBHI_VLD_SHIFT);\
}
#define DSP_DCMBHI_TOTAL_SIZE   16
#define DSP_DCMBHI(data, vld) \
        ((((unsigned long)(data)) << DSP_DCMBHI_DATA_SHIFT) | \
         (((unsigned long)(vld)) << DSP_DCMBHI_VLD_SHIFT))

/*
 *  dsp_dcmblo struct
 */
#define DSP_DCMBLO_DATA_SIZE    16
#define DSP_DCMBLO_DATA_SHIFT   0
#define DSP_DCMBLO_DATA_MASK    0x0000ffff
#define DSP_DCMBLO_GET_DATA(dsp_dcmblo) \
        ((((unsigned long)(dsp_dcmblo)) & DSP_DCMBLO_DATA_MASK) >> DSP_DCMBLO_DATA_SHIFT)
#define DSP_DCMBLO_SET_DATA(dsp_dcmblo, data) { \
        FDL_ASSERT(!((data) & ~((1 << DSP_DCMBLO_DATA_SIZE)-1))); \
        dsp_dcmblo = (((unsigned long)(dsp_dcmblo)) & ~DSP_DCMBLO_DATA_MASK) | (((unsigned long)(data)) << DSP_DCMBLO_DATA_SHIFT);\
}
#define DSP_DCMBLO_TOTAL_SIZE   16
#define DSP_DCMBLO(data) \
        ((((unsigned long)(data)) << DSP_DCMBLO_DATA_SHIFT))

/*
 *  dsp_cdcr struct
 */
#define DSP_CDCR_SWRESET_SIZE   1
#define DSP_CDCR_SWRESET_SHIFT  0
#define DSP_CDCR_SWRESET_MASK   0x00000001
#define DSP_CDCR_GET_SWRESET(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_SWRESET_MASK) >> DSP_CDCR_SWRESET_SHIFT)
#define DSP_CDCR_SET_SWRESET(dsp_cdcr, swreset) { \
        FDL_ASSERT(!((swreset) & ~((1 << DSP_CDCR_SWRESET_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_SWRESET_MASK) | (((unsigned long)(swreset)) << DSP_CDCR_SWRESET_SHIFT);\
}
#define DSP_CDCR_INTDSP_SIZE    1
#define DSP_CDCR_INTDSP_SHIFT   1
#define DSP_CDCR_INTDSP_MASK    0x00000002
#define DSP_CDCR_GET_INTDSP(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_INTDSP_MASK) >> DSP_CDCR_INTDSP_SHIFT)
#define DSP_CDCR_SET_INTDSP(dsp_cdcr, intdsp) { \
        FDL_ASSERT(!((intdsp) & ~((1 << DSP_CDCR_INTDSP_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_INTDSP_MASK) | (((unsigned long)(intdsp)) << DSP_CDCR_INTDSP_SHIFT);\
}
#define DSP_CDCR_HALTDSP_SIZE   1
#define DSP_CDCR_HALTDSP_SHIFT  2
#define DSP_CDCR_HALTDSP_MASK   0x00000004
#define DSP_CDCR_GET_HALTDSP(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_HALTDSP_MASK) >> DSP_CDCR_HALTDSP_SHIFT)
#define DSP_CDCR_SET_HALTDSP(dsp_cdcr, haltdsp) { \
        FDL_ASSERT(!((haltdsp) & ~((1 << DSP_CDCR_HALTDSP_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_HALTDSP_MASK) | (((unsigned long)(haltdsp)) << DSP_CDCR_HALTDSP_SHIFT);\
}
#define DSP_CDCR_AIINT_SIZE     1
#define DSP_CDCR_AIINT_SHIFT    3
#define DSP_CDCR_AIINT_MASK     0x00000008
#define DSP_CDCR_GET_AIINT(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_AIINT_MASK) >> DSP_CDCR_AIINT_SHIFT)
#define DSP_CDCR_SET_AIINT(dsp_cdcr, aiint) { \
        FDL_ASSERT(!((aiint) & ~((1 << DSP_CDCR_AIINT_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_AIINT_MASK) | (((unsigned long)(aiint)) << DSP_CDCR_AIINT_SHIFT);\
}
#define DSP_CDCR_AIINTMSK_SIZE  1
#define DSP_CDCR_AIINTMSK_SHIFT 4
#define DSP_CDCR_AIINTMSK_MASK  0x00000010
#define DSP_CDCR_GET_AIINTMSK(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_AIINTMSK_MASK) >> DSP_CDCR_AIINTMSK_SHIFT)
#define DSP_CDCR_SET_AIINTMSK(dsp_cdcr, aiintmsk) { \
        FDL_ASSERT(!((aiintmsk) & ~((1 << DSP_CDCR_AIINTMSK_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_AIINTMSK_MASK) | (((unsigned long)(aiintmsk)) << DSP_CDCR_AIINTMSK_SHIFT);\
}
#define DSP_CDCR_ARAMINT_SIZE   1
#define DSP_CDCR_ARAMINT_SHIFT  5
#define DSP_CDCR_ARAMINT_MASK   0x00000020
#define DSP_CDCR_GET_ARAMINT(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_ARAMINT_MASK) >> DSP_CDCR_ARAMINT_SHIFT)
#define DSP_CDCR_SET_ARAMINT(dsp_cdcr, aramint) { \
        FDL_ASSERT(!((aramint) & ~((1 << DSP_CDCR_ARAMINT_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_ARAMINT_MASK) | (((unsigned long)(aramint)) << DSP_CDCR_ARAMINT_SHIFT);\
}
#define DSP_CDCR_ARAMINTMSK_SIZE        1
#define DSP_CDCR_ARAMINTMSK_SHIFT       6
#define DSP_CDCR_ARAMINTMSK_MASK        0x00000040
#define DSP_CDCR_GET_ARAMINTMSK(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_ARAMINTMSK_MASK) >> DSP_CDCR_ARAMINTMSK_SHIFT)
#define DSP_CDCR_SET_ARAMINTMSK(dsp_cdcr, aramintmsk) { \
        FDL_ASSERT(!((aramintmsk) & ~((1 << DSP_CDCR_ARAMINTMSK_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_ARAMINTMSK_MASK) | (((unsigned long)(aramintmsk)) << DSP_CDCR_ARAMINTMSK_SHIFT);\
}
#define DSP_CDCR_DSPINT_SIZE    1
#define DSP_CDCR_DSPINT_SHIFT   7
#define DSP_CDCR_DSPINT_MASK    0x00000080
#define DSP_CDCR_GET_DSPINT(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_DSPINT_MASK) >> DSP_CDCR_DSPINT_SHIFT)
#define DSP_CDCR_SET_DSPINT(dsp_cdcr, dspint) { \
        FDL_ASSERT(!((dspint) & ~((1 << DSP_CDCR_DSPINT_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_DSPINT_MASK) | (((unsigned long)(dspint)) << DSP_CDCR_DSPINT_SHIFT);\
}
#define DSP_CDCR_DSPINTMSK_SIZE 1
#define DSP_CDCR_DSPINTMSK_SHIFT        8
#define DSP_CDCR_DSPINTMSK_MASK 0x00000100
#define DSP_CDCR_GET_DSPINTMSK(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_DSPINTMSK_MASK) >> DSP_CDCR_DSPINTMSK_SHIFT)
#define DSP_CDCR_SET_DSPINTMSK(dsp_cdcr, dspintmsk) { \
        FDL_ASSERT(!((dspintmsk) & ~((1 << DSP_CDCR_DSPINTMSK_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_DSPINTMSK_MASK) | (((unsigned long)(dspintmsk)) << DSP_CDCR_DSPINTMSK_SHIFT);\
}
#define DSP_CDCR_DSPBUSY_SIZE   1
#define DSP_CDCR_DSPBUSY_SHIFT  9
#define DSP_CDCR_DSPBUSY_MASK   0x00000200
#define DSP_CDCR_GET_DSPBUSY(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_DSPBUSY_MASK) >> DSP_CDCR_DSPBUSY_SHIFT)
#define DSP_CDCR_SET_DSPBUSY(dsp_cdcr, dspbusy) { \
        FDL_ASSERT(!((dspbusy) & ~((1 << DSP_CDCR_DSPBUSY_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_DSPBUSY_MASK) | (((unsigned long)(dspbusy)) << DSP_CDCR_DSPBUSY_SHIFT);\
}
#define DSP_CDCR_UNKNOWN_SIZE   1
#define DSP_CDCR_UNKNOWN_SHIFT  10
#define DSP_CDCR_UNKNOWN_MASK   0x00000400
#define DSP_CDCR_GET_UNKNOWN(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_UNKNOWN_MASK) >> DSP_CDCR_UNKNOWN_SHIFT)
#define DSP_CDCR_SET_UNKNOWN(dsp_cdcr, unknown) { \
        FDL_ASSERT(!((unknown) & ~((1 << DSP_CDCR_UNKNOWN_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_UNKNOWN_MASK) | (((unsigned long)(unknown)) << DSP_CDCR_UNKNOWN_SHIFT);\
}
#define DSP_CDCR_USEROM_SIZE    1
#define DSP_CDCR_USEROM_SHIFT   11
#define DSP_CDCR_USEROM_MASK    0x00000800
#define DSP_CDCR_GET_USEROM(dsp_cdcr) \
        ((((unsigned long)(dsp_cdcr)) & DSP_CDCR_USEROM_MASK) >> DSP_CDCR_USEROM_SHIFT)
#define DSP_CDCR_SET_USEROM(dsp_cdcr, userom) { \
        FDL_ASSERT(!((userom) & ~((1 << DSP_CDCR_USEROM_SIZE)-1))); \
        dsp_cdcr = (((unsigned long)(dsp_cdcr)) & ~DSP_CDCR_USEROM_MASK) | (((unsigned long)(userom)) << DSP_CDCR_USEROM_SHIFT);\
}
#define DSP_CDCR_TOTAL_SIZE     12
#define DSP_CDCR(swreset, intdsp, haltdsp, aiint, aiintmsk, aramint, aramintmsk, dspint, dspintmsk, dspbusy, unknown, userom) \
        ((((unsigned long)(swreset)) << DSP_CDCR_SWRESET_SHIFT) | \
         (((unsigned long)(intdsp)) << DSP_CDCR_INTDSP_SHIFT) | \
         (((unsigned long)(haltdsp)) << DSP_CDCR_HALTDSP_SHIFT) | \
         (((unsigned long)(aiint)) << DSP_CDCR_AIINT_SHIFT) | \
         (((unsigned long)(aiintmsk)) << DSP_CDCR_AIINTMSK_SHIFT) | \
         (((unsigned long)(aramint)) << DSP_CDCR_ARAMINT_SHIFT) | \
         (((unsigned long)(aramintmsk)) << DSP_CDCR_ARAMINTMSK_SHIFT) | \
         (((unsigned long)(dspint)) << DSP_CDCR_DSPINT_SHIFT) | \
         (((unsigned long)(dspintmsk)) << DSP_CDCR_DSPINTMSK_SHIFT) | \
         (((unsigned long)(dspbusy)) << DSP_CDCR_DSPBUSY_SHIFT) | \
         (((unsigned long)(unknown)) << DSP_CDCR_UNKNOWN_SHIFT) | \
         (((unsigned long)(userom)) << DSP_CDCR_USEROM_SHIFT))

/*
 *  dsp_amcr struct
 */
#define DSP_AMCR_INTSIZE_SIZE   3
#define DSP_AMCR_INTSIZE_SHIFT  0
#define DSP_AMCR_INTSIZE_MASK   0x00000007
#define DSP_AMCR_GET_INTSIZE(dsp_amcr) \
        ((((unsigned long)(dsp_amcr)) & DSP_AMCR_INTSIZE_MASK) >> DSP_AMCR_INTSIZE_SHIFT)
#define DSP_AMCR_SET_INTSIZE(dsp_amcr, intsize) { \
        FDL_ASSERT(!((intsize) & ~((1 << DSP_AMCR_INTSIZE_SIZE)-1))); \
        dsp_amcr = (((unsigned long)(dsp_amcr)) & ~DSP_AMCR_INTSIZE_MASK) | (((unsigned long)(intsize)) << DSP_AMCR_INTSIZE_SHIFT);\
}
#define DSP_AMCR_EXPSIZE_SIZE   3
#define DSP_AMCR_EXPSIZE_SHIFT  3
#define DSP_AMCR_EXPSIZE_MASK   0x00000038
#define DSP_AMCR_GET_EXPSIZE(dsp_amcr) \
        ((((unsigned long)(dsp_amcr)) & DSP_AMCR_EXPSIZE_MASK) >> DSP_AMCR_EXPSIZE_SHIFT)
#define DSP_AMCR_SET_EXPSIZE(dsp_amcr, expsize) { \
        FDL_ASSERT(!((expsize) & ~((1 << DSP_AMCR_EXPSIZE_SIZE)-1))); \
        dsp_amcr = (((unsigned long)(dsp_amcr)) & ~DSP_AMCR_EXPSIZE_MASK) | (((unsigned long)(expsize)) << DSP_AMCR_EXPSIZE_SHIFT);\
}
#define DSP_AMCR_TOTAL_SIZE     6
#define DSP_AMCR(intsize, expsize) \
        ((((unsigned long)(intsize)) << DSP_AMCR_INTSIZE_SHIFT) | \
         (((unsigned long)(expsize)) << DSP_AMCR_EXPSIZE_SHIFT))

/*
 *  dsp_amnf struct
 */
#define DSP_AMNF_NORMAL_SIZE    1
#define DSP_AMNF_NORMAL_SHIFT   0
#define DSP_AMNF_NORMAL_MASK    0x00000001
#define DSP_AMNF_GET_NORMAL(dsp_amnf) \
        ((((unsigned long)(dsp_amnf)) & DSP_AMNF_NORMAL_MASK) >> DSP_AMNF_NORMAL_SHIFT)
#define DSP_AMNF_SET_NORMAL(dsp_amnf, normal) { \
        FDL_ASSERT(!((normal) & ~((1 << DSP_AMNF_NORMAL_SIZE)-1))); \
        dsp_amnf = (((unsigned long)(dsp_amnf)) & ~DSP_AMNF_NORMAL_MASK) | (((unsigned long)(normal)) << DSP_AMNF_NORMAL_SHIFT);\
}
#define DSP_AMNF_TOTAL_SIZE     1
#define DSP_AMNF(normal) \
        ((((unsigned long)(normal)) << DSP_AMNF_NORMAL_SHIFT))

/*
 *  dsp_amct struct
 */
#define DSP_AMCT_REFPER_SIZE    8
#define DSP_AMCT_REFPER_SHIFT   0
#define DSP_AMCT_REFPER_MASK    0x000000ff
#define DSP_AMCT_GET_REFPER(dsp_amct) \
        ((((unsigned long)(dsp_amct)) & DSP_AMCT_REFPER_MASK) >> DSP_AMCT_REFPER_SHIFT)
#define DSP_AMCT_SET_REFPER(dsp_amct, refper) { \
        FDL_ASSERT(!((refper) & ~((1 << DSP_AMCT_REFPER_SIZE)-1))); \
        dsp_amct = (((unsigned long)(dsp_amct)) & ~DSP_AMCT_REFPER_MASK) | (((unsigned long)(refper)) << DSP_AMCT_REFPER_SHIFT);\
}
#define DSP_AMCT_INFREF_SIZE    1
#define DSP_AMCT_INFREF_SHIFT   8
#define DSP_AMCT_INFREF_MASK    0x00000100
#define DSP_AMCT_GET_INFREF(dsp_amct) \
        ((((unsigned long)(dsp_amct)) & DSP_AMCT_INFREF_MASK) >> DSP_AMCT_INFREF_SHIFT)
#define DSP_AMCT_SET_INFREF(dsp_amct, infref) { \
        FDL_ASSERT(!((infref) & ~((1 << DSP_AMCT_INFREF_SIZE)-1))); \
        dsp_amct = (((unsigned long)(dsp_amct)) & ~DSP_AMCT_INFREF_MASK) | (((unsigned long)(infref)) << DSP_AMCT_INFREF_SHIFT);\
}
#define DSP_AMCT_CTLRDIS_SIZE   1
#define DSP_AMCT_CTLRDIS_SHIFT  9
#define DSP_AMCT_CTLRDIS_MASK   0x00000200
#define DSP_AMCT_GET_CTLRDIS(dsp_amct) \
        ((((unsigned long)(dsp_amct)) & DSP_AMCT_CTLRDIS_MASK) >> DSP_AMCT_CTLRDIS_SHIFT)
#define DSP_AMCT_SET_CTLRDIS(dsp_amct, ctlrdis) { \
        FDL_ASSERT(!((ctlrdis) & ~((1 << DSP_AMCT_CTLRDIS_SIZE)-1))); \
        dsp_amct = (((unsigned long)(dsp_amct)) & ~DSP_AMCT_CTLRDIS_MASK) | (((unsigned long)(ctlrdis)) << DSP_AMCT_CTLRDIS_SHIFT);\
}
#define DSP_AMCT_WAITBYPASS_SIZE        1
#define DSP_AMCT_WAITBYPASS_SHIFT       10
#define DSP_AMCT_WAITBYPASS_MASK        0x00000400
#define DSP_AMCT_GET_WAITBYPASS(dsp_amct) \
        ((((unsigned long)(dsp_amct)) & DSP_AMCT_WAITBYPASS_MASK) >> DSP_AMCT_WAITBYPASS_SHIFT)
#define DSP_AMCT_SET_WAITBYPASS(dsp_amct, waitbypass) { \
        FDL_ASSERT(!((waitbypass) & ~((1 << DSP_AMCT_WAITBYPASS_SIZE)-1))); \
        dsp_amct = (((unsigned long)(dsp_amct)) & ~DSP_AMCT_WAITBYPASS_MASK) | (((unsigned long)(waitbypass)) << DSP_AMCT_WAITBYPASS_SHIFT);\
}
#define DSP_AMCT_TOTAL_SIZE     11
#define DSP_AMCT(refper, infref, ctlrdis, waitbypass) \
        ((((unsigned long)(refper)) << DSP_AMCT_REFPER_SHIFT) | \
         (((unsigned long)(infref)) << DSP_AMCT_INFREF_SHIFT) | \
         (((unsigned long)(ctlrdis)) << DSP_AMCT_CTLRDIS_SHIFT) | \
         (((unsigned long)(waitbypass)) << DSP_AMCT_WAITBYPASS_SHIFT))

/*
 *  dsp_amma struct
 */
#define DSP_AMMA_ZERO_SIZE      5
#define DSP_AMMA_ZERO_SHIFT     0
#define DSP_AMMA_ZERO_MASK      0x0000001f
#define DSP_AMMA_GET_ZERO(dsp_amma) \
        ((((unsigned long)(dsp_amma)) & DSP_AMMA_ZERO_MASK) >> DSP_AMMA_ZERO_SHIFT)
#define DSP_AMMA_SET_ZERO(dsp_amma, zero) { \
        FDL_ASSERT(!((zero) & ~((1 << DSP_AMMA_ZERO_SIZE)-1))); \
        dsp_amma = (((unsigned long)(dsp_amma)) & ~DSP_AMMA_ZERO_MASK) | (((unsigned long)(zero)) << DSP_AMMA_ZERO_SHIFT);\
}
#define DSP_AMMA_ADDR_SIZE      21
#define DSP_AMMA_ADDR_SHIFT     5
#define DSP_AMMA_ADDR_MASK      0x03ffffe0
#define DSP_AMMA_GET_ADDR(dsp_amma) \
        ((((unsigned long)(dsp_amma)) & DSP_AMMA_ADDR_MASK) >> DSP_AMMA_ADDR_SHIFT)
#define DSP_AMMA_SET_ADDR(dsp_amma, addr) { \
        FDL_ASSERT(!((addr) & ~((1 << DSP_AMMA_ADDR_SIZE)-1))); \
        dsp_amma = (((unsigned long)(dsp_amma)) & ~DSP_AMMA_ADDR_MASK) | (((unsigned long)(addr)) << DSP_AMMA_ADDR_SHIFT);\
}
#define DSP_AMMA_TOTAL_SIZE     26
#define DSP_AMMA(zero, addr) \
        ((((unsigned long)(zero)) << DSP_AMMA_ZERO_SHIFT) | \
         (((unsigned long)(addr)) << DSP_AMMA_ADDR_SHIFT))

/*
 *  dsp_amaa struct
 */
#define DSP_AMAA_ZERO_SIZE      5
#define DSP_AMAA_ZERO_SHIFT     0
#define DSP_AMAA_ZERO_MASK      0x0000001f
#define DSP_AMAA_GET_ZERO(dsp_amaa) \
        ((((unsigned long)(dsp_amaa)) & DSP_AMAA_ZERO_MASK) >> DSP_AMAA_ZERO_SHIFT)
#define DSP_AMAA_SET_ZERO(dsp_amaa, zero) { \
        FDL_ASSERT(!((zero) & ~((1 << DSP_AMAA_ZERO_SIZE)-1))); \
        dsp_amaa = (((unsigned long)(dsp_amaa)) & ~DSP_AMAA_ZERO_MASK) | (((unsigned long)(zero)) << DSP_AMAA_ZERO_SHIFT);\
}
#define DSP_AMAA_ADDR_SIZE      21
#define DSP_AMAA_ADDR_SHIFT     5
#define DSP_AMAA_ADDR_MASK      0x03ffffe0
#define DSP_AMAA_GET_ADDR(dsp_amaa) \
        ((((unsigned long)(dsp_amaa)) & DSP_AMAA_ADDR_MASK) >> DSP_AMAA_ADDR_SHIFT)
#define DSP_AMAA_SET_ADDR(dsp_amaa, addr) { \
        FDL_ASSERT(!((addr) & ~((1 << DSP_AMAA_ADDR_SIZE)-1))); \
        dsp_amaa = (((unsigned long)(dsp_amaa)) & ~DSP_AMAA_ADDR_MASK) | (((unsigned long)(addr)) << DSP_AMAA_ADDR_SHIFT);\
}
#define DSP_AMAA_TOTAL_SIZE     26
#define DSP_AMAA(zero, addr) \
        ((((unsigned long)(zero)) << DSP_AMAA_ZERO_SHIFT) | \
         (((unsigned long)(addr)) << DSP_AMAA_ADDR_SHIFT))

/*
 *  dsp_ambl struct
 */
#define DSP_AMBL_ZERO_SIZE      5
#define DSP_AMBL_ZERO_SHIFT     0
#define DSP_AMBL_ZERO_MASK      0x0000001f
#define DSP_AMBL_GET_ZERO(dsp_ambl) \
        ((((unsigned long)(dsp_ambl)) & DSP_AMBL_ZERO_MASK) >> DSP_AMBL_ZERO_SHIFT)
#define DSP_AMBL_SET_ZERO(dsp_ambl, zero) { \
        FDL_ASSERT(!((zero) & ~((1 << DSP_AMBL_ZERO_SIZE)-1))); \
        dsp_ambl = (((unsigned long)(dsp_ambl)) & ~DSP_AMBL_ZERO_MASK) | (((unsigned long)(zero)) << DSP_AMBL_ZERO_SHIFT);\
}
#define DSP_AMBL_BLKLEN_SIZE    21
#define DSP_AMBL_BLKLEN_SHIFT   5
#define DSP_AMBL_BLKLEN_MASK    0x03ffffe0
#define DSP_AMBL_GET_BLKLEN(dsp_ambl) \
        ((((unsigned long)(dsp_ambl)) & DSP_AMBL_BLKLEN_MASK) >> DSP_AMBL_BLKLEN_SHIFT)
#define DSP_AMBL_SET_BLKLEN(dsp_ambl, blklen) { \
        FDL_ASSERT(!((blklen) & ~((1 << DSP_AMBL_BLKLEN_SIZE)-1))); \
        dsp_ambl = (((unsigned long)(dsp_ambl)) & ~DSP_AMBL_BLKLEN_MASK) | (((unsigned long)(blklen)) << DSP_AMBL_BLKLEN_SHIFT);\
}
#define DSP_AMBL_RESV_SIZE      5
#define DSP_AMBL_RESV_SHIFT     26
#define DSP_AMBL_RESV_MASK      0x7c000000
#define DSP_AMBL_GET_RESV(dsp_ambl) \
        ((((unsigned long)(dsp_ambl)) & DSP_AMBL_RESV_MASK) >> DSP_AMBL_RESV_SHIFT)
#define DSP_AMBL_SET_RESV(dsp_ambl, resv) { \
        FDL_ASSERT(!((resv) & ~((1 << DSP_AMBL_RESV_SIZE)-1))); \
        dsp_ambl = (((unsigned long)(dsp_ambl)) & ~DSP_AMBL_RESV_MASK) | (((unsigned long)(resv)) << DSP_AMBL_RESV_SHIFT);\
}
#define DSP_AMBL_DIR_SIZE       1
#define DSP_AMBL_DIR_SHIFT      31
#define DSP_AMBL_DIR_MASK       0x80000000
#define DSP_AMBL_GET_DIR(dsp_ambl) \
        ((((unsigned long)(dsp_ambl)) & DSP_AMBL_DIR_MASK) >> DSP_AMBL_DIR_SHIFT)
#define DSP_AMBL_SET_DIR(dsp_ambl, dir) { \
        FDL_ASSERT(!((dir) & ~((1 << DSP_AMBL_DIR_SIZE)-1))); \
        dsp_ambl = (((unsigned long)(dsp_ambl)) & ~DSP_AMBL_DIR_MASK) | (((unsigned long)(dir)) << DSP_AMBL_DIR_SHIFT);\
}
#define DSP_AMBL_TOTAL_SIZE     32
#define DSP_AMBL(zero, blklen, resv, dir) \
        ((((unsigned long)(zero)) << DSP_AMBL_ZERO_SHIFT) | \
         (((unsigned long)(blklen)) << DSP_AMBL_BLKLEN_SHIFT) | \
         (((unsigned long)(resv)) << DSP_AMBL_RESV_SHIFT) | \
         (((unsigned long)(dir)) << DSP_AMBL_DIR_SHIFT))

/*
 *  dsp_aima struct
 */
#define DSP_AIMA_ZERO_SIZE      5
#define DSP_AIMA_ZERO_SHIFT     0
#define DSP_AIMA_ZERO_MASK      0x0000001f
#define DSP_AIMA_GET_ZERO(dsp_aima) \
        ((((unsigned long)(dsp_aima)) & DSP_AIMA_ZERO_MASK) >> DSP_AIMA_ZERO_SHIFT)
#define DSP_AIMA_SET_ZERO(dsp_aima, zero) { \
        FDL_ASSERT(!((zero) & ~((1 << DSP_AIMA_ZERO_SIZE)-1))); \
        dsp_aima = (((unsigned long)(dsp_aima)) & ~DSP_AIMA_ZERO_MASK) | (((unsigned long)(zero)) << DSP_AIMA_ZERO_SHIFT);\
}
#define DSP_AIMA_ADDR_SIZE      21
#define DSP_AIMA_ADDR_SHIFT     5
#define DSP_AIMA_ADDR_MASK      0x03ffffe0
#define DSP_AIMA_GET_ADDR(dsp_aima) \
        ((((unsigned long)(dsp_aima)) & DSP_AIMA_ADDR_MASK) >> DSP_AIMA_ADDR_SHIFT)
#define DSP_AIMA_SET_ADDR(dsp_aima, addr) { \
        FDL_ASSERT(!((addr) & ~((1 << DSP_AIMA_ADDR_SIZE)-1))); \
        dsp_aima = (((unsigned long)(dsp_aima)) & ~DSP_AIMA_ADDR_MASK) | (((unsigned long)(addr)) << DSP_AIMA_ADDR_SHIFT);\
}
#define DSP_AIMA_TOTAL_SIZE     26
#define DSP_AIMA(zero, addr) \
        ((((unsigned long)(zero)) << DSP_AIMA_ZERO_SHIFT) | \
         (((unsigned long)(addr)) << DSP_AIMA_ADDR_SHIFT))

/*
 *  dsp_aibl struct
 */
#define DSP_AIBL_BLOCKLEN_SIZE  15
#define DSP_AIBL_BLOCKLEN_SHIFT 0
#define DSP_AIBL_BLOCKLEN_MASK  0x00007fff
#define DSP_AIBL_GET_BLOCKLEN(dsp_aibl) \
        ((((unsigned long)(dsp_aibl)) & DSP_AIBL_BLOCKLEN_MASK) >> DSP_AIBL_BLOCKLEN_SHIFT)
#define DSP_AIBL_SET_BLOCKLEN(dsp_aibl, blocklen) { \
        FDL_ASSERT(!((blocklen) & ~((1 << DSP_AIBL_BLOCKLEN_SIZE)-1))); \
        dsp_aibl = (((unsigned long)(dsp_aibl)) & ~DSP_AIBL_BLOCKLEN_MASK) | (((unsigned long)(blocklen)) << DSP_AIBL_BLOCKLEN_SHIFT);\
}
#define DSP_AIBL_ENABLEDMA_SIZE 1
#define DSP_AIBL_ENABLEDMA_SHIFT        15
#define DSP_AIBL_ENABLEDMA_MASK 0x00008000
#define DSP_AIBL_GET_ENABLEDMA(dsp_aibl) \
        ((((unsigned long)(dsp_aibl)) & DSP_AIBL_ENABLEDMA_MASK) >> DSP_AIBL_ENABLEDMA_SHIFT)
#define DSP_AIBL_SET_ENABLEDMA(dsp_aibl, enabledma) { \
        FDL_ASSERT(!((enabledma) & ~((1 << DSP_AIBL_ENABLEDMA_SIZE)-1))); \
        dsp_aibl = (((unsigned long)(dsp_aibl)) & ~DSP_AIBL_ENABLEDMA_MASK) | (((unsigned long)(enabledma)) << DSP_AIBL_ENABLEDMA_SHIFT);\
}
#define DSP_AIBL_TOTAL_SIZE     16
#define DSP_AIBL(blocklen, enabledma) \
        ((((unsigned long)(blocklen)) << DSP_AIBL_BLOCKLEN_SHIFT) | \
         (((unsigned long)(enabledma)) << DSP_AIBL_ENABLEDMA_SHIFT))

/*
 *  dsp_aiblc struct
 */
#define DSP_AIBLC_BLOCKLEN_SIZE 15
#define DSP_AIBLC_BLOCKLEN_SHIFT        0
#define DSP_AIBLC_BLOCKLEN_MASK 0x00007fff
#define DSP_AIBLC_GET_BLOCKLEN(dsp_aiblc) \
        ((((unsigned long)(dsp_aiblc)) & DSP_AIBLC_BLOCKLEN_MASK) >> DSP_AIBLC_BLOCKLEN_SHIFT)
#define DSP_AIBLC_SET_BLOCKLEN(dsp_aiblc, blocklen) { \
        FDL_ASSERT(!((blocklen) & ~((1 << DSP_AIBLC_BLOCKLEN_SIZE)-1))); \
        dsp_aiblc = (((unsigned long)(dsp_aiblc)) & ~DSP_AIBLC_BLOCKLEN_MASK) | (((unsigned long)(blocklen)) << DSP_AIBLC_BLOCKLEN_SHIFT);\
}
#define DSP_AIBLC_ZERO_SIZE     1
#define DSP_AIBLC_ZERO_SHIFT    15
#define DSP_AIBLC_ZERO_MASK     0x00008000
#define DSP_AIBLC_GET_ZERO(dsp_aiblc) \
        ((((unsigned long)(dsp_aiblc)) & DSP_AIBLC_ZERO_MASK) >> DSP_AIBLC_ZERO_SHIFT)
#define DSP_AIBLC_SET_ZERO(dsp_aiblc, zero) { \
        FDL_ASSERT(!((zero) & ~((1 << DSP_AIBLC_ZERO_SIZE)-1))); \
        dsp_aiblc = (((unsigned long)(dsp_aiblc)) & ~DSP_AIBLC_ZERO_MASK) | (((unsigned long)(zero)) << DSP_AIBLC_ZERO_SHIFT);\
}
#define DSP_AIBLC_TOTAL_SIZE    16
#define DSP_AIBLC(blocklen, zero) \
        ((((unsigned long)(blocklen)) << DSP_AIBLC_BLOCKLEN_SHIFT) | \
         (((unsigned long)(zero)) << DSP_AIBLC_ZERO_SHIFT))


#endif /* __FDL_DSP_REG_H__ */
