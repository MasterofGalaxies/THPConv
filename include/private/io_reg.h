/*
 *  io_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from ../../bw/fdl/io_reg.fdl
 */

#ifndef __FDL_IO_REG_H__
#define __FDL_IO_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  io_base_address value
 */
#define IO_BASE_DI      0x0c006000
#define IO_BASE_SI      0x0c006400
#define IO_BASE_EXI     0x0c006800
#define IO_BASE_AI      0x0c006c00

/*
 *  io_mod enum
 */
#define IO_ADDR_DI      0x00000000
#define IO_ADDR_SI      0x00000001
#define IO_ADDR_EXI     0x00000002
#define IO_ADDR_AI      0x00000003

/*
 *  exi_reg enum
 */
#define EXI_0CPR_IDX    0x00000000
#define EXI_0MAR_IDX    0x00000001
#define EXI_0LENGTH_IDX 0x00000002
#define EXI_0CR_IDX     0x00000003
#define EXI_0DATA_IDX   0x00000004
#define EXI_1CPR_IDX    0x00000005
#define EXI_1MAR_IDX    0x00000006
#define EXI_1LENGTH_IDX 0x00000007
#define EXI_1CR_IDX     0x00000008
#define EXI_1DATA_IDX   0x00000009
#define EXI_2CPR_IDX    0x0000000a
#define EXI_2MAR_IDX    0x0000000b
#define EXI_2LENGTH_IDX 0x0000000c
#define EXI_2CR_IDX     0x0000000d
#define EXI_2DATA_IDX   0x0000000e
#define EXI_REG_UNUSED_15       0x0000000f

/*
 *  boot_reg enum
 */
#define EXI_BOOT0_IDX   0x00000000
#define EXI_BOOT1_IDX   0x00000001
#define EXI_BOOT2_IDX   0x00000002
#define EXI_BOOT3_IDX   0x00000003
#define EXI_BOOT4_IDX   0x00000004
#define EXI_BOOT5_IDX   0x00000005
#define EXI_BOOT6_IDX   0x00000006
#define EXI_BOOT7_IDX   0x00000007
#define EXI_BOOT8_IDX   0x00000008
#define EXI_BOOT9_IDX   0x00000009
#define EXI_BOOT10_IDX  0x0000000a
#define EXI_BOOT11_IDX  0x0000000b
#define EXI_BOOT12_IDX  0x0000000c
#define EXI_BOOT13_IDX  0x0000000d
#define EXI_BOOT14_IDX  0x0000000e
#define EXI_BOOT15_IDX  0x0000000f

/*
 *  MAX_EXI_BOOTCODE_SLOTS value
 */
#define MAX_EXI_BOOTCODE_SLOTS  16

/*
 *  EXI_BOOTCODE_OFFSET value
 */
#define EXI_BOOTCODE_OFFSET     0x00000040

/*
 *  exi_romdis enum
 */
#define EXI_ROMDIS_ENABLED      0x00000000
#define EXI_ROMDIS_DISABLED     0x00000001

/*
 *  exi_ext enum
 */
#define EXI_EXT_NOT_PRESENT     0x00000000
#define EXI_EXT_PRESENT 0x00000001

/*
 *  io_int enum
 */
#define IO_INT_NO_REQUEST       0x00000000
#define IO_INT_REQUEST  0x00000001

/*
 *  io_intmsk enum
 */
#define IO_INTMSK_MASKED        0x00000000
#define IO_INTMSK_ENABLED       0x00000001

/*
 *  exi_csb enum
 */
#define EXI_CSB_DESELECT        0x00000000
#define EXI_CSB_SELECT  0x00000001

/*
 *  exi_clk enum
 */
#define EXI_CLK_1MHZ    0x00000000
#define EXI_CLK_2MHZ    0x00000001
#define EXI_CLK_4MHZ    0x00000002
#define EXI_CLK_8MHZ    0x00000003
#define EXI_CLK_16MHZ   0x00000004
#define EXI_CLK_32MHZ   0x00000005
#define EXI_CLK_64MHZ   0x00000006
#define EXI_CLK_UNUSED_7        0x00000007

/*
 *  exi_0cpr struct
 */
#define EXI_0CPR_EXIINTMSK_SIZE 1
#define EXI_0CPR_EXIINTMSK_SHIFT        0
#define EXI_0CPR_EXIINTMSK_MASK 0x00000001
#define EXI_0CPR_GET_EXIINTMSK(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_EXIINTMSK_MASK) >> EXI_0CPR_EXIINTMSK_SHIFT)
#define EXI_0CPR_SET_EXIINTMSK(exi_0cpr, exiintmsk) { \
        FDL_ASSERT(!((exiintmsk) & ~((1 << EXI_0CPR_EXIINTMSK_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_EXIINTMSK_MASK) | (((unsigned long)(exiintmsk)) << EXI_0CPR_EXIINTMSK_SHIFT);\
}
#define EXI_0CPR_EXIINT_SIZE    1
#define EXI_0CPR_EXIINT_SHIFT   1
#define EXI_0CPR_EXIINT_MASK    0x00000002
#define EXI_0CPR_GET_EXIINT(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_EXIINT_MASK) >> EXI_0CPR_EXIINT_SHIFT)
#define EXI_0CPR_SET_EXIINT(exi_0cpr, exiint) { \
        FDL_ASSERT(!((exiint) & ~((1 << EXI_0CPR_EXIINT_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_EXIINT_MASK) | (((unsigned long)(exiint)) << EXI_0CPR_EXIINT_SHIFT);\
}
#define EXI_0CPR_TCINTMSK_SIZE  1
#define EXI_0CPR_TCINTMSK_SHIFT 2
#define EXI_0CPR_TCINTMSK_MASK  0x00000004
#define EXI_0CPR_GET_TCINTMSK(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_TCINTMSK_MASK) >> EXI_0CPR_TCINTMSK_SHIFT)
#define EXI_0CPR_SET_TCINTMSK(exi_0cpr, tcintmsk) { \
        FDL_ASSERT(!((tcintmsk) & ~((1 << EXI_0CPR_TCINTMSK_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_TCINTMSK_MASK) | (((unsigned long)(tcintmsk)) << EXI_0CPR_TCINTMSK_SHIFT);\
}
#define EXI_0CPR_TCINT_SIZE     1
#define EXI_0CPR_TCINT_SHIFT    3
#define EXI_0CPR_TCINT_MASK     0x00000008
#define EXI_0CPR_GET_TCINT(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_TCINT_MASK) >> EXI_0CPR_TCINT_SHIFT)
#define EXI_0CPR_SET_TCINT(exi_0cpr, tcint) { \
        FDL_ASSERT(!((tcint) & ~((1 << EXI_0CPR_TCINT_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_TCINT_MASK) | (((unsigned long)(tcint)) << EXI_0CPR_TCINT_SHIFT);\
}
#define EXI_0CPR_CLK_SIZE       3
#define EXI_0CPR_CLK_SHIFT      4
#define EXI_0CPR_CLK_MASK       0x00000070
#define EXI_0CPR_GET_CLK(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_CLK_MASK) >> EXI_0CPR_CLK_SHIFT)
#define EXI_0CPR_SET_CLK(exi_0cpr, clk) { \
        FDL_ASSERT(!((clk) & ~((1 << EXI_0CPR_CLK_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_CLK_MASK) | (((unsigned long)(clk)) << EXI_0CPR_CLK_SHIFT);\
}
#define EXI_0CPR_CS0B_SIZE      1
#define EXI_0CPR_CS0B_SHIFT     7
#define EXI_0CPR_CS0B_MASK      0x00000080
#define EXI_0CPR_GET_CS0B(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_CS0B_MASK) >> EXI_0CPR_CS0B_SHIFT)
#define EXI_0CPR_SET_CS0B(exi_0cpr, cs0b) { \
        FDL_ASSERT(!((cs0b) & ~((1 << EXI_0CPR_CS0B_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_CS0B_MASK) | (((unsigned long)(cs0b)) << EXI_0CPR_CS0B_SHIFT);\
}
#define EXI_0CPR_CS1B_SIZE      1
#define EXI_0CPR_CS1B_SHIFT     8
#define EXI_0CPR_CS1B_MASK      0x00000100
#define EXI_0CPR_GET_CS1B(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_CS1B_MASK) >> EXI_0CPR_CS1B_SHIFT)
#define EXI_0CPR_SET_CS1B(exi_0cpr, cs1b) { \
        FDL_ASSERT(!((cs1b) & ~((1 << EXI_0CPR_CS1B_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_CS1B_MASK) | (((unsigned long)(cs1b)) << EXI_0CPR_CS1B_SHIFT);\
}
#define EXI_0CPR_CS2B_SIZE      1
#define EXI_0CPR_CS2B_SHIFT     9
#define EXI_0CPR_CS2B_MASK      0x00000200
#define EXI_0CPR_GET_CS2B(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_CS2B_MASK) >> EXI_0CPR_CS2B_SHIFT)
#define EXI_0CPR_SET_CS2B(exi_0cpr, cs2b) { \
        FDL_ASSERT(!((cs2b) & ~((1 << EXI_0CPR_CS2B_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_CS2B_MASK) | (((unsigned long)(cs2b)) << EXI_0CPR_CS2B_SHIFT);\
}
#define EXI_0CPR_EXTINTMSK_SIZE 1
#define EXI_0CPR_EXTINTMSK_SHIFT        10
#define EXI_0CPR_EXTINTMSK_MASK 0x00000400
#define EXI_0CPR_GET_EXTINTMSK(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_EXTINTMSK_MASK) >> EXI_0CPR_EXTINTMSK_SHIFT)
#define EXI_0CPR_SET_EXTINTMSK(exi_0cpr, extintmsk) { \
        FDL_ASSERT(!((extintmsk) & ~((1 << EXI_0CPR_EXTINTMSK_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_EXTINTMSK_MASK) | (((unsigned long)(extintmsk)) << EXI_0CPR_EXTINTMSK_SHIFT);\
}
#define EXI_0CPR_EXTINT_SIZE    1
#define EXI_0CPR_EXTINT_SHIFT   11
#define EXI_0CPR_EXTINT_MASK    0x00000800
#define EXI_0CPR_GET_EXTINT(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_EXTINT_MASK) >> EXI_0CPR_EXTINT_SHIFT)
#define EXI_0CPR_SET_EXTINT(exi_0cpr, extint) { \
        FDL_ASSERT(!((extint) & ~((1 << EXI_0CPR_EXTINT_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_EXTINT_MASK) | (((unsigned long)(extint)) << EXI_0CPR_EXTINT_SHIFT);\
}
#define EXI_0CPR_EXT_SIZE       1
#define EXI_0CPR_EXT_SHIFT      12
#define EXI_0CPR_EXT_MASK       0x00001000
#define EXI_0CPR_GET_EXT(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_EXT_MASK) >> EXI_0CPR_EXT_SHIFT)
#define EXI_0CPR_SET_EXT(exi_0cpr, ext) { \
        FDL_ASSERT(!((ext) & ~((1 << EXI_0CPR_EXT_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_EXT_MASK) | (((unsigned long)(ext)) << EXI_0CPR_EXT_SHIFT);\
}
#define EXI_0CPR_ROMDIS_SIZE    1
#define EXI_0CPR_ROMDIS_SHIFT   13
#define EXI_0CPR_ROMDIS_MASK    0x00002000
#define EXI_0CPR_GET_ROMDIS(exi_0cpr) \
        ((((unsigned long)(exi_0cpr)) & EXI_0CPR_ROMDIS_MASK) >> EXI_0CPR_ROMDIS_SHIFT)
#define EXI_0CPR_SET_ROMDIS(exi_0cpr, romdis) { \
        FDL_ASSERT(!((romdis) & ~((1 << EXI_0CPR_ROMDIS_SIZE)-1))); \
        exi_0cpr = (((unsigned long)(exi_0cpr)) & ~EXI_0CPR_ROMDIS_MASK) | (((unsigned long)(romdis)) << EXI_0CPR_ROMDIS_SHIFT);\
}
#define EXI_0CPR_TOTAL_SIZE     14
#define EXI_0CPR_UNUSED_SIZE    18

#define EXI_0CPR(exiintmsk, exiint, tcintmsk, tcint, clk, cs0b, cs1b, cs2b, extintmsk, extint, ext, romdis) \
        ((((unsigned long)(exiintmsk)) << EXI_0CPR_EXIINTMSK_SHIFT) | \
         (((unsigned long)(exiint)) << EXI_0CPR_EXIINT_SHIFT) | \
         (((unsigned long)(tcintmsk)) << EXI_0CPR_TCINTMSK_SHIFT) | \
         (((unsigned long)(tcint)) << EXI_0CPR_TCINT_SHIFT) | \
         (((unsigned long)(clk)) << EXI_0CPR_CLK_SHIFT) | \
         (((unsigned long)(cs0b)) << EXI_0CPR_CS0B_SHIFT) | \
         (((unsigned long)(cs1b)) << EXI_0CPR_CS1B_SHIFT) | \
         (((unsigned long)(cs2b)) << EXI_0CPR_CS2B_SHIFT) | \
         (((unsigned long)(extintmsk)) << EXI_0CPR_EXTINTMSK_SHIFT) | \
         (((unsigned long)(extint)) << EXI_0CPR_EXTINT_SHIFT) | \
         (((unsigned long)(ext)) << EXI_0CPR_EXT_SHIFT) | \
         (((unsigned long)(romdis)) << EXI_0CPR_ROMDIS_SHIFT))

/*
 *  exi_0mar struct
 */
#define EXI_0MAR_PAD0_SIZE      5
#define EXI_0MAR_PAD0_SHIFT     0
#define EXI_0MAR_PAD0_MASK      0x0000001f
#define EXI_0MAR_GET_PAD0(exi_0mar) \
        ((((unsigned long)(exi_0mar)) & EXI_0MAR_PAD0_MASK) >> EXI_0MAR_PAD0_SHIFT)
#define EXI_0MAR_SET_PAD0(exi_0mar, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_0MAR_PAD0_SIZE)-1))); \
        exi_0mar = (((unsigned long)(exi_0mar)) & ~EXI_0MAR_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_0MAR_PAD0_SHIFT);\
}
#define EXI_0MAR_EXIMAR_SIZE    27
#define EXI_0MAR_EXIMAR_SHIFT   5
#define EXI_0MAR_EXIMAR_MASK    0xffffffe0
#define EXI_0MAR_GET_EXIMAR(exi_0mar) \
        ((((unsigned long)(exi_0mar)) & EXI_0MAR_EXIMAR_MASK) >> EXI_0MAR_EXIMAR_SHIFT)
#define EXI_0MAR_SET_EXIMAR(exi_0mar, eximar) { \
        FDL_ASSERT(!((eximar) & ~((1 << EXI_0MAR_EXIMAR_SIZE)-1))); \
        exi_0mar = (((unsigned long)(exi_0mar)) & ~EXI_0MAR_EXIMAR_MASK) | (((unsigned long)(eximar)) << EXI_0MAR_EXIMAR_SHIFT);\
}
#define EXI_0MAR_TOTAL_SIZE     32
#define EXI_0MAR(eximar) \
        ((((unsigned long)(eximar)) << EXI_0MAR_EXIMAR_SHIFT))

/*
 *  exi_0length struct
 */
#define EXI_0LENGTH_PAD0_SIZE   5
#define EXI_0LENGTH_PAD0_SHIFT  0
#define EXI_0LENGTH_PAD0_MASK   0x0000001f
#define EXI_0LENGTH_GET_PAD0(exi_0length) \
        ((((unsigned long)(exi_0length)) & EXI_0LENGTH_PAD0_MASK) >> EXI_0LENGTH_PAD0_SHIFT)
#define EXI_0LENGTH_SET_PAD0(exi_0length, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_0LENGTH_PAD0_SIZE)-1))); \
        exi_0length = (((unsigned long)(exi_0length)) & ~EXI_0LENGTH_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_0LENGTH_PAD0_SHIFT);\
}
#define EXI_0LENGTH_EXILENGTH_SIZE      27
#define EXI_0LENGTH_EXILENGTH_SHIFT     5
#define EXI_0LENGTH_EXILENGTH_MASK      0xffffffe0
#define EXI_0LENGTH_GET_EXILENGTH(exi_0length) \
        ((((unsigned long)(exi_0length)) & EXI_0LENGTH_EXILENGTH_MASK) >> EXI_0LENGTH_EXILENGTH_SHIFT)
#define EXI_0LENGTH_SET_EXILENGTH(exi_0length, exilength) { \
        FDL_ASSERT(!((exilength) & ~((1 << EXI_0LENGTH_EXILENGTH_SIZE)-1))); \
        exi_0length = (((unsigned long)(exi_0length)) & ~EXI_0LENGTH_EXILENGTH_MASK) | (((unsigned long)(exilength)) << EXI_0LENGTH_EXILENGTH_SHIFT);\
}
#define EXI_0LENGTH_TOTAL_SIZE  32
#define EXI_0LENGTH(exilength) \
        ((((unsigned long)(exilength)) << EXI_0LENGTH_EXILENGTH_SHIFT))

/*
 *  exi_tlen enum
 */
#define EXI_TLEN_1B     0x00000000
#define EXI_TLEN_2B     0x00000001
#define EXI_TLEN_3B     0x00000002
#define EXI_TLEN_4B     0x00000003

/*
 *  exi_rw enum
 */
#define EXI_RW_RD       0x00000000
#define EXI_RW_WR       0x00000001
#define EXI_RW_RDWR     0x00000002
#define EXI_RW_UNUSED_3 0x00000003

/*
 *  io_dma enum
 */
#define IO_DMA_IMM      0x00000000
#define IO_DMA_DMA      0x00000001

/*
 *  di_rw enum
 */
#define DI_RW_RD        0x00000000
#define DI_RW_WR        0x00000001

/*
 *  io_tstart enum
 */
#define IO_TSTART_DONE  0x00000000
#define IO_TSTART_START 0x00000001

/*
 *  exi_0cr struct
 */
#define EXI_0CR_TSTART_SIZE     1
#define EXI_0CR_TSTART_SHIFT    0
#define EXI_0CR_TSTART_MASK     0x00000001
#define EXI_0CR_GET_TSTART(exi_0cr) \
        ((((unsigned long)(exi_0cr)) & EXI_0CR_TSTART_MASK) >> EXI_0CR_TSTART_SHIFT)
#define EXI_0CR_SET_TSTART(exi_0cr, tstart) { \
        FDL_ASSERT(!((tstart) & ~((1 << EXI_0CR_TSTART_SIZE)-1))); \
        exi_0cr = (((unsigned long)(exi_0cr)) & ~EXI_0CR_TSTART_MASK) | (((unsigned long)(tstart)) << EXI_0CR_TSTART_SHIFT);\
}
#define EXI_0CR_DMA_SIZE        1
#define EXI_0CR_DMA_SHIFT       1
#define EXI_0CR_DMA_MASK        0x00000002
#define EXI_0CR_GET_DMA(exi_0cr) \
        ((((unsigned long)(exi_0cr)) & EXI_0CR_DMA_MASK) >> EXI_0CR_DMA_SHIFT)
#define EXI_0CR_SET_DMA(exi_0cr, dma) { \
        FDL_ASSERT(!((dma) & ~((1 << EXI_0CR_DMA_SIZE)-1))); \
        exi_0cr = (((unsigned long)(exi_0cr)) & ~EXI_0CR_DMA_MASK) | (((unsigned long)(dma)) << EXI_0CR_DMA_SHIFT);\
}
#define EXI_0CR_RW_SIZE 2
#define EXI_0CR_RW_SHIFT        2
#define EXI_0CR_RW_MASK 0x0000000c
#define EXI_0CR_GET_RW(exi_0cr) \
        ((((unsigned long)(exi_0cr)) & EXI_0CR_RW_MASK) >> EXI_0CR_RW_SHIFT)
#define EXI_0CR_SET_RW(exi_0cr, rw) { \
        FDL_ASSERT(!((rw) & ~((1 << EXI_0CR_RW_SIZE)-1))); \
        exi_0cr = (((unsigned long)(exi_0cr)) & ~EXI_0CR_RW_MASK) | (((unsigned long)(rw)) << EXI_0CR_RW_SHIFT);\
}
#define EXI_0CR_TLEN_SIZE       2
#define EXI_0CR_TLEN_SHIFT      4
#define EXI_0CR_TLEN_MASK       0x00000030
#define EXI_0CR_GET_TLEN(exi_0cr) \
        ((((unsigned long)(exi_0cr)) & EXI_0CR_TLEN_MASK) >> EXI_0CR_TLEN_SHIFT)
#define EXI_0CR_SET_TLEN(exi_0cr, tlen) { \
        FDL_ASSERT(!((tlen) & ~((1 << EXI_0CR_TLEN_SIZE)-1))); \
        exi_0cr = (((unsigned long)(exi_0cr)) & ~EXI_0CR_TLEN_MASK) | (((unsigned long)(tlen)) << EXI_0CR_TLEN_SHIFT);\
}
#define EXI_0CR_TOTAL_SIZE      6
#define EXI_0CR_UNUSED_SIZE     26

#define EXI_0CR(tstart, dma, rw, tlen) \
        ((((unsigned long)(tstart)) << EXI_0CR_TSTART_SHIFT) | \
         (((unsigned long)(dma)) << EXI_0CR_DMA_SHIFT) | \
         (((unsigned long)(rw)) << EXI_0CR_RW_SHIFT) | \
         (((unsigned long)(tlen)) << EXI_0CR_TLEN_SHIFT))

/*
 *  exi_0data struct
 */
#define EXI_0DATA_DATA3_SIZE    8
#define EXI_0DATA_DATA3_SHIFT   0
#define EXI_0DATA_DATA3_MASK    0x000000ff
#define EXI_0DATA_GET_DATA3(exi_0data) \
        ((((unsigned long)(exi_0data)) & EXI_0DATA_DATA3_MASK) >> EXI_0DATA_DATA3_SHIFT)
#define EXI_0DATA_SET_DATA3(exi_0data, data3) { \
        FDL_ASSERT(!((data3) & ~((1 << EXI_0DATA_DATA3_SIZE)-1))); \
        exi_0data = (((unsigned long)(exi_0data)) & ~EXI_0DATA_DATA3_MASK) | (((unsigned long)(data3)) << EXI_0DATA_DATA3_SHIFT);\
}
#define EXI_0DATA_DATA2_SIZE    8
#define EXI_0DATA_DATA2_SHIFT   8
#define EXI_0DATA_DATA2_MASK    0x0000ff00
#define EXI_0DATA_GET_DATA2(exi_0data) \
        ((((unsigned long)(exi_0data)) & EXI_0DATA_DATA2_MASK) >> EXI_0DATA_DATA2_SHIFT)
#define EXI_0DATA_SET_DATA2(exi_0data, data2) { \
        FDL_ASSERT(!((data2) & ~((1 << EXI_0DATA_DATA2_SIZE)-1))); \
        exi_0data = (((unsigned long)(exi_0data)) & ~EXI_0DATA_DATA2_MASK) | (((unsigned long)(data2)) << EXI_0DATA_DATA2_SHIFT);\
}
#define EXI_0DATA_DATA1_SIZE    8
#define EXI_0DATA_DATA1_SHIFT   16
#define EXI_0DATA_DATA1_MASK    0x00ff0000
#define EXI_0DATA_GET_DATA1(exi_0data) \
        ((((unsigned long)(exi_0data)) & EXI_0DATA_DATA1_MASK) >> EXI_0DATA_DATA1_SHIFT)
#define EXI_0DATA_SET_DATA1(exi_0data, data1) { \
        FDL_ASSERT(!((data1) & ~((1 << EXI_0DATA_DATA1_SIZE)-1))); \
        exi_0data = (((unsigned long)(exi_0data)) & ~EXI_0DATA_DATA1_MASK) | (((unsigned long)(data1)) << EXI_0DATA_DATA1_SHIFT);\
}
#define EXI_0DATA_DATA0_SIZE    8
#define EXI_0DATA_DATA0_SHIFT   24
#define EXI_0DATA_DATA0_MASK    0xff000000
#define EXI_0DATA_GET_DATA0(exi_0data) \
        ((((unsigned long)(exi_0data)) & EXI_0DATA_DATA0_MASK) >> EXI_0DATA_DATA0_SHIFT)
#define EXI_0DATA_SET_DATA0(exi_0data, data0) { \
        FDL_ASSERT(!((data0) & ~((1 << EXI_0DATA_DATA0_SIZE)-1))); \
        exi_0data = (((unsigned long)(exi_0data)) & ~EXI_0DATA_DATA0_MASK) | (((unsigned long)(data0)) << EXI_0DATA_DATA0_SHIFT);\
}
#define EXI_0DATA_TOTAL_SIZE    32
#define EXI_0DATA(data3, data2, data1, data0) \
        ((((unsigned long)(data3)) << EXI_0DATA_DATA3_SHIFT) | \
         (((unsigned long)(data2)) << EXI_0DATA_DATA2_SHIFT) | \
         (((unsigned long)(data1)) << EXI_0DATA_DATA1_SHIFT) | \
         (((unsigned long)(data0)) << EXI_0DATA_DATA0_SHIFT))

/*
 *  exi_1cpr struct
 */
#define EXI_1CPR_EXIINTMSK_SIZE 1
#define EXI_1CPR_EXIINTMSK_SHIFT        0
#define EXI_1CPR_EXIINTMSK_MASK 0x00000001
#define EXI_1CPR_GET_EXIINTMSK(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_EXIINTMSK_MASK) >> EXI_1CPR_EXIINTMSK_SHIFT)
#define EXI_1CPR_SET_EXIINTMSK(exi_1cpr, exiintmsk) { \
        FDL_ASSERT(!((exiintmsk) & ~((1 << EXI_1CPR_EXIINTMSK_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_EXIINTMSK_MASK) | (((unsigned long)(exiintmsk)) << EXI_1CPR_EXIINTMSK_SHIFT);\
}
#define EXI_1CPR_EXIINT_SIZE    1
#define EXI_1CPR_EXIINT_SHIFT   1
#define EXI_1CPR_EXIINT_MASK    0x00000002
#define EXI_1CPR_GET_EXIINT(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_EXIINT_MASK) >> EXI_1CPR_EXIINT_SHIFT)
#define EXI_1CPR_SET_EXIINT(exi_1cpr, exiint) { \
        FDL_ASSERT(!((exiint) & ~((1 << EXI_1CPR_EXIINT_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_EXIINT_MASK) | (((unsigned long)(exiint)) << EXI_1CPR_EXIINT_SHIFT);\
}
#define EXI_1CPR_TCINTMSK_SIZE  1
#define EXI_1CPR_TCINTMSK_SHIFT 2
#define EXI_1CPR_TCINTMSK_MASK  0x00000004
#define EXI_1CPR_GET_TCINTMSK(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_TCINTMSK_MASK) >> EXI_1CPR_TCINTMSK_SHIFT)
#define EXI_1CPR_SET_TCINTMSK(exi_1cpr, tcintmsk) { \
        FDL_ASSERT(!((tcintmsk) & ~((1 << EXI_1CPR_TCINTMSK_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_TCINTMSK_MASK) | (((unsigned long)(tcintmsk)) << EXI_1CPR_TCINTMSK_SHIFT);\
}
#define EXI_1CPR_TCINT_SIZE     1
#define EXI_1CPR_TCINT_SHIFT    3
#define EXI_1CPR_TCINT_MASK     0x00000008
#define EXI_1CPR_GET_TCINT(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_TCINT_MASK) >> EXI_1CPR_TCINT_SHIFT)
#define EXI_1CPR_SET_TCINT(exi_1cpr, tcint) { \
        FDL_ASSERT(!((tcint) & ~((1 << EXI_1CPR_TCINT_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_TCINT_MASK) | (((unsigned long)(tcint)) << EXI_1CPR_TCINT_SHIFT);\
}
#define EXI_1CPR_CLK_SIZE       3
#define EXI_1CPR_CLK_SHIFT      4
#define EXI_1CPR_CLK_MASK       0x00000070
#define EXI_1CPR_GET_CLK(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_CLK_MASK) >> EXI_1CPR_CLK_SHIFT)
#define EXI_1CPR_SET_CLK(exi_1cpr, clk) { \
        FDL_ASSERT(!((clk) & ~((1 << EXI_1CPR_CLK_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_CLK_MASK) | (((unsigned long)(clk)) << EXI_1CPR_CLK_SHIFT);\
}
#define EXI_1CPR_CS0B_SIZE      1
#define EXI_1CPR_CS0B_SHIFT     7
#define EXI_1CPR_CS0B_MASK      0x00000080
#define EXI_1CPR_GET_CS0B(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_CS0B_MASK) >> EXI_1CPR_CS0B_SHIFT)
#define EXI_1CPR_SET_CS0B(exi_1cpr, cs0b) { \
        FDL_ASSERT(!((cs0b) & ~((1 << EXI_1CPR_CS0B_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_CS0B_MASK) | (((unsigned long)(cs0b)) << EXI_1CPR_CS0B_SHIFT);\
}
#define EXI_1CPR_PAD0_SIZE      2
#define EXI_1CPR_PAD0_SHIFT     8
#define EXI_1CPR_PAD0_MASK      0x00000300
#define EXI_1CPR_GET_PAD0(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_PAD0_MASK) >> EXI_1CPR_PAD0_SHIFT)
#define EXI_1CPR_SET_PAD0(exi_1cpr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_1CPR_PAD0_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_1CPR_PAD0_SHIFT);\
}
#define EXI_1CPR_EXTINTMSK_SIZE 1
#define EXI_1CPR_EXTINTMSK_SHIFT        10
#define EXI_1CPR_EXTINTMSK_MASK 0x00000400
#define EXI_1CPR_GET_EXTINTMSK(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_EXTINTMSK_MASK) >> EXI_1CPR_EXTINTMSK_SHIFT)
#define EXI_1CPR_SET_EXTINTMSK(exi_1cpr, extintmsk) { \
        FDL_ASSERT(!((extintmsk) & ~((1 << EXI_1CPR_EXTINTMSK_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_EXTINTMSK_MASK) | (((unsigned long)(extintmsk)) << EXI_1CPR_EXTINTMSK_SHIFT);\
}
#define EXI_1CPR_EXTINT_SIZE    1
#define EXI_1CPR_EXTINT_SHIFT   11
#define EXI_1CPR_EXTINT_MASK    0x00000800
#define EXI_1CPR_GET_EXTINT(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_EXTINT_MASK) >> EXI_1CPR_EXTINT_SHIFT)
#define EXI_1CPR_SET_EXTINT(exi_1cpr, extint) { \
        FDL_ASSERT(!((extint) & ~((1 << EXI_1CPR_EXTINT_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_EXTINT_MASK) | (((unsigned long)(extint)) << EXI_1CPR_EXTINT_SHIFT);\
}
#define EXI_1CPR_EXT_SIZE       1
#define EXI_1CPR_EXT_SHIFT      12
#define EXI_1CPR_EXT_MASK       0x00001000
#define EXI_1CPR_GET_EXT(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_EXT_MASK) >> EXI_1CPR_EXT_SHIFT)
#define EXI_1CPR_SET_EXT(exi_1cpr, ext) { \
        FDL_ASSERT(!((ext) & ~((1 << EXI_1CPR_EXT_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_EXT_MASK) | (((unsigned long)(ext)) << EXI_1CPR_EXT_SHIFT);\
}
#define EXI_1CPR_PAD1_SIZE      1
#define EXI_1CPR_PAD1_SHIFT     13
#define EXI_1CPR_PAD1_MASK      0x00002000
#define EXI_1CPR_GET_PAD1(exi_1cpr) \
        ((((unsigned long)(exi_1cpr)) & EXI_1CPR_PAD1_MASK) >> EXI_1CPR_PAD1_SHIFT)
#define EXI_1CPR_SET_PAD1(exi_1cpr, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << EXI_1CPR_PAD1_SIZE)-1))); \
        exi_1cpr = (((unsigned long)(exi_1cpr)) & ~EXI_1CPR_PAD1_MASK) | (((unsigned long)(pad1)) << EXI_1CPR_PAD1_SHIFT);\
}
#define EXI_1CPR_TOTAL_SIZE     14
#define EXI_1CPR_UNUSED_SIZE    18

#define EXI_1CPR(exiintmsk, exiint, tcintmsk, tcint, clk, cs0b, extintmsk, extint, ext) \
        ((((unsigned long)(exiintmsk)) << EXI_1CPR_EXIINTMSK_SHIFT) | \
         (((unsigned long)(exiint)) << EXI_1CPR_EXIINT_SHIFT) | \
         (((unsigned long)(tcintmsk)) << EXI_1CPR_TCINTMSK_SHIFT) | \
         (((unsigned long)(tcint)) << EXI_1CPR_TCINT_SHIFT) | \
         (((unsigned long)(clk)) << EXI_1CPR_CLK_SHIFT) | \
         (((unsigned long)(cs0b)) << EXI_1CPR_CS0B_SHIFT) | \
         (((unsigned long)(extintmsk)) << EXI_1CPR_EXTINTMSK_SHIFT) | \
         (((unsigned long)(extint)) << EXI_1CPR_EXTINT_SHIFT) | \
         (((unsigned long)(ext)) << EXI_1CPR_EXT_SHIFT))

/*
 *  exi_1mar struct
 */
#define EXI_1MAR_PAD0_SIZE      5
#define EXI_1MAR_PAD0_SHIFT     0
#define EXI_1MAR_PAD0_MASK      0x0000001f
#define EXI_1MAR_GET_PAD0(exi_1mar) \
        ((((unsigned long)(exi_1mar)) & EXI_1MAR_PAD0_MASK) >> EXI_1MAR_PAD0_SHIFT)
#define EXI_1MAR_SET_PAD0(exi_1mar, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_1MAR_PAD0_SIZE)-1))); \
        exi_1mar = (((unsigned long)(exi_1mar)) & ~EXI_1MAR_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_1MAR_PAD0_SHIFT);\
}
#define EXI_1MAR_EXIMAR_SIZE    27
#define EXI_1MAR_EXIMAR_SHIFT   5
#define EXI_1MAR_EXIMAR_MASK    0xffffffe0
#define EXI_1MAR_GET_EXIMAR(exi_1mar) \
        ((((unsigned long)(exi_1mar)) & EXI_1MAR_EXIMAR_MASK) >> EXI_1MAR_EXIMAR_SHIFT)
#define EXI_1MAR_SET_EXIMAR(exi_1mar, eximar) { \
        FDL_ASSERT(!((eximar) & ~((1 << EXI_1MAR_EXIMAR_SIZE)-1))); \
        exi_1mar = (((unsigned long)(exi_1mar)) & ~EXI_1MAR_EXIMAR_MASK) | (((unsigned long)(eximar)) << EXI_1MAR_EXIMAR_SHIFT);\
}
#define EXI_1MAR_TOTAL_SIZE     32
#define EXI_1MAR(eximar) \
        ((((unsigned long)(eximar)) << EXI_1MAR_EXIMAR_SHIFT))

/*
 *  exi_1length struct
 */
#define EXI_1LENGTH_PAD0_SIZE   5
#define EXI_1LENGTH_PAD0_SHIFT  0
#define EXI_1LENGTH_PAD0_MASK   0x0000001f
#define EXI_1LENGTH_GET_PAD0(exi_1length) \
        ((((unsigned long)(exi_1length)) & EXI_1LENGTH_PAD0_MASK) >> EXI_1LENGTH_PAD0_SHIFT)
#define EXI_1LENGTH_SET_PAD0(exi_1length, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_1LENGTH_PAD0_SIZE)-1))); \
        exi_1length = (((unsigned long)(exi_1length)) & ~EXI_1LENGTH_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_1LENGTH_PAD0_SHIFT);\
}
#define EXI_1LENGTH_EXILENGTH_SIZE      27
#define EXI_1LENGTH_EXILENGTH_SHIFT     5
#define EXI_1LENGTH_EXILENGTH_MASK      0xffffffe0
#define EXI_1LENGTH_GET_EXILENGTH(exi_1length) \
        ((((unsigned long)(exi_1length)) & EXI_1LENGTH_EXILENGTH_MASK) >> EXI_1LENGTH_EXILENGTH_SHIFT)
#define EXI_1LENGTH_SET_EXILENGTH(exi_1length, exilength) { \
        FDL_ASSERT(!((exilength) & ~((1 << EXI_1LENGTH_EXILENGTH_SIZE)-1))); \
        exi_1length = (((unsigned long)(exi_1length)) & ~EXI_1LENGTH_EXILENGTH_MASK) | (((unsigned long)(exilength)) << EXI_1LENGTH_EXILENGTH_SHIFT);\
}
#define EXI_1LENGTH_TOTAL_SIZE  32
#define EXI_1LENGTH(exilength) \
        ((((unsigned long)(exilength)) << EXI_1LENGTH_EXILENGTH_SHIFT))

/*
 *  exi_1cr struct
 */
#define EXI_1CR_TSTART_SIZE     1
#define EXI_1CR_TSTART_SHIFT    0
#define EXI_1CR_TSTART_MASK     0x00000001
#define EXI_1CR_GET_TSTART(exi_1cr) \
        ((((unsigned long)(exi_1cr)) & EXI_1CR_TSTART_MASK) >> EXI_1CR_TSTART_SHIFT)
#define EXI_1CR_SET_TSTART(exi_1cr, tstart) { \
        FDL_ASSERT(!((tstart) & ~((1 << EXI_1CR_TSTART_SIZE)-1))); \
        exi_1cr = (((unsigned long)(exi_1cr)) & ~EXI_1CR_TSTART_MASK) | (((unsigned long)(tstart)) << EXI_1CR_TSTART_SHIFT);\
}
#define EXI_1CR_DMA_SIZE        1
#define EXI_1CR_DMA_SHIFT       1
#define EXI_1CR_DMA_MASK        0x00000002
#define EXI_1CR_GET_DMA(exi_1cr) \
        ((((unsigned long)(exi_1cr)) & EXI_1CR_DMA_MASK) >> EXI_1CR_DMA_SHIFT)
#define EXI_1CR_SET_DMA(exi_1cr, dma) { \
        FDL_ASSERT(!((dma) & ~((1 << EXI_1CR_DMA_SIZE)-1))); \
        exi_1cr = (((unsigned long)(exi_1cr)) & ~EXI_1CR_DMA_MASK) | (((unsigned long)(dma)) << EXI_1CR_DMA_SHIFT);\
}
#define EXI_1CR_RW_SIZE 2
#define EXI_1CR_RW_SHIFT        2
#define EXI_1CR_RW_MASK 0x0000000c
#define EXI_1CR_GET_RW(exi_1cr) \
        ((((unsigned long)(exi_1cr)) & EXI_1CR_RW_MASK) >> EXI_1CR_RW_SHIFT)
#define EXI_1CR_SET_RW(exi_1cr, rw) { \
        FDL_ASSERT(!((rw) & ~((1 << EXI_1CR_RW_SIZE)-1))); \
        exi_1cr = (((unsigned long)(exi_1cr)) & ~EXI_1CR_RW_MASK) | (((unsigned long)(rw)) << EXI_1CR_RW_SHIFT);\
}
#define EXI_1CR_TLEN_SIZE       2
#define EXI_1CR_TLEN_SHIFT      4
#define EXI_1CR_TLEN_MASK       0x00000030
#define EXI_1CR_GET_TLEN(exi_1cr) \
        ((((unsigned long)(exi_1cr)) & EXI_1CR_TLEN_MASK) >> EXI_1CR_TLEN_SHIFT)
#define EXI_1CR_SET_TLEN(exi_1cr, tlen) { \
        FDL_ASSERT(!((tlen) & ~((1 << EXI_1CR_TLEN_SIZE)-1))); \
        exi_1cr = (((unsigned long)(exi_1cr)) & ~EXI_1CR_TLEN_MASK) | (((unsigned long)(tlen)) << EXI_1CR_TLEN_SHIFT);\
}
#define EXI_1CR_TOTAL_SIZE      6
#define EXI_1CR_UNUSED_SIZE     26

#define EXI_1CR(tstart, dma, rw, tlen) \
        ((((unsigned long)(tstart)) << EXI_1CR_TSTART_SHIFT) | \
         (((unsigned long)(dma)) << EXI_1CR_DMA_SHIFT) | \
         (((unsigned long)(rw)) << EXI_1CR_RW_SHIFT) | \
         (((unsigned long)(tlen)) << EXI_1CR_TLEN_SHIFT))

/*
 *  exi_1data struct
 */
#define EXI_1DATA_DATA3_SIZE    8
#define EXI_1DATA_DATA3_SHIFT   0
#define EXI_1DATA_DATA3_MASK    0x000000ff
#define EXI_1DATA_GET_DATA3(exi_1data) \
        ((((unsigned long)(exi_1data)) & EXI_1DATA_DATA3_MASK) >> EXI_1DATA_DATA3_SHIFT)
#define EXI_1DATA_SET_DATA3(exi_1data, data3) { \
        FDL_ASSERT(!((data3) & ~((1 << EXI_1DATA_DATA3_SIZE)-1))); \
        exi_1data = (((unsigned long)(exi_1data)) & ~EXI_1DATA_DATA3_MASK) | (((unsigned long)(data3)) << EXI_1DATA_DATA3_SHIFT);\
}
#define EXI_1DATA_DATA2_SIZE    8
#define EXI_1DATA_DATA2_SHIFT   8
#define EXI_1DATA_DATA2_MASK    0x0000ff00
#define EXI_1DATA_GET_DATA2(exi_1data) \
        ((((unsigned long)(exi_1data)) & EXI_1DATA_DATA2_MASK) >> EXI_1DATA_DATA2_SHIFT)
#define EXI_1DATA_SET_DATA2(exi_1data, data2) { \
        FDL_ASSERT(!((data2) & ~((1 << EXI_1DATA_DATA2_SIZE)-1))); \
        exi_1data = (((unsigned long)(exi_1data)) & ~EXI_1DATA_DATA2_MASK) | (((unsigned long)(data2)) << EXI_1DATA_DATA2_SHIFT);\
}
#define EXI_1DATA_DATA1_SIZE    8
#define EXI_1DATA_DATA1_SHIFT   16
#define EXI_1DATA_DATA1_MASK    0x00ff0000
#define EXI_1DATA_GET_DATA1(exi_1data) \
        ((((unsigned long)(exi_1data)) & EXI_1DATA_DATA1_MASK) >> EXI_1DATA_DATA1_SHIFT)
#define EXI_1DATA_SET_DATA1(exi_1data, data1) { \
        FDL_ASSERT(!((data1) & ~((1 << EXI_1DATA_DATA1_SIZE)-1))); \
        exi_1data = (((unsigned long)(exi_1data)) & ~EXI_1DATA_DATA1_MASK) | (((unsigned long)(data1)) << EXI_1DATA_DATA1_SHIFT);\
}
#define EXI_1DATA_DATA0_SIZE    8
#define EXI_1DATA_DATA0_SHIFT   24
#define EXI_1DATA_DATA0_MASK    0xff000000
#define EXI_1DATA_GET_DATA0(exi_1data) \
        ((((unsigned long)(exi_1data)) & EXI_1DATA_DATA0_MASK) >> EXI_1DATA_DATA0_SHIFT)
#define EXI_1DATA_SET_DATA0(exi_1data, data0) { \
        FDL_ASSERT(!((data0) & ~((1 << EXI_1DATA_DATA0_SIZE)-1))); \
        exi_1data = (((unsigned long)(exi_1data)) & ~EXI_1DATA_DATA0_MASK) | (((unsigned long)(data0)) << EXI_1DATA_DATA0_SHIFT);\
}
#define EXI_1DATA_TOTAL_SIZE    32
#define EXI_1DATA(data3, data2, data1, data0) \
        ((((unsigned long)(data3)) << EXI_1DATA_DATA3_SHIFT) | \
         (((unsigned long)(data2)) << EXI_1DATA_DATA2_SHIFT) | \
         (((unsigned long)(data1)) << EXI_1DATA_DATA1_SHIFT) | \
         (((unsigned long)(data0)) << EXI_1DATA_DATA0_SHIFT))

/*
 *  exi_2cpr struct
 */
#define EXI_2CPR_EXIINTMSK_SIZE 1
#define EXI_2CPR_EXIINTMSK_SHIFT        0
#define EXI_2CPR_EXIINTMSK_MASK 0x00000001
#define EXI_2CPR_GET_EXIINTMSK(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_EXIINTMSK_MASK) >> EXI_2CPR_EXIINTMSK_SHIFT)
#define EXI_2CPR_SET_EXIINTMSK(exi_2cpr, exiintmsk) { \
        FDL_ASSERT(!((exiintmsk) & ~((1 << EXI_2CPR_EXIINTMSK_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_EXIINTMSK_MASK) | (((unsigned long)(exiintmsk)) << EXI_2CPR_EXIINTMSK_SHIFT);\
}
#define EXI_2CPR_EXIINT_SIZE    1
#define EXI_2CPR_EXIINT_SHIFT   1
#define EXI_2CPR_EXIINT_MASK    0x00000002
#define EXI_2CPR_GET_EXIINT(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_EXIINT_MASK) >> EXI_2CPR_EXIINT_SHIFT)
#define EXI_2CPR_SET_EXIINT(exi_2cpr, exiint) { \
        FDL_ASSERT(!((exiint) & ~((1 << EXI_2CPR_EXIINT_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_EXIINT_MASK) | (((unsigned long)(exiint)) << EXI_2CPR_EXIINT_SHIFT);\
}
#define EXI_2CPR_TCINTMSK_SIZE  1
#define EXI_2CPR_TCINTMSK_SHIFT 2
#define EXI_2CPR_TCINTMSK_MASK  0x00000004
#define EXI_2CPR_GET_TCINTMSK(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_TCINTMSK_MASK) >> EXI_2CPR_TCINTMSK_SHIFT)
#define EXI_2CPR_SET_TCINTMSK(exi_2cpr, tcintmsk) { \
        FDL_ASSERT(!((tcintmsk) & ~((1 << EXI_2CPR_TCINTMSK_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_TCINTMSK_MASK) | (((unsigned long)(tcintmsk)) << EXI_2CPR_TCINTMSK_SHIFT);\
}
#define EXI_2CPR_TCINT_SIZE     1
#define EXI_2CPR_TCINT_SHIFT    3
#define EXI_2CPR_TCINT_MASK     0x00000008
#define EXI_2CPR_GET_TCINT(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_TCINT_MASK) >> EXI_2CPR_TCINT_SHIFT)
#define EXI_2CPR_SET_TCINT(exi_2cpr, tcint) { \
        FDL_ASSERT(!((tcint) & ~((1 << EXI_2CPR_TCINT_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_TCINT_MASK) | (((unsigned long)(tcint)) << EXI_2CPR_TCINT_SHIFT);\
}
#define EXI_2CPR_CLK_SIZE       3
#define EXI_2CPR_CLK_SHIFT      4
#define EXI_2CPR_CLK_MASK       0x00000070
#define EXI_2CPR_GET_CLK(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_CLK_MASK) >> EXI_2CPR_CLK_SHIFT)
#define EXI_2CPR_SET_CLK(exi_2cpr, clk) { \
        FDL_ASSERT(!((clk) & ~((1 << EXI_2CPR_CLK_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_CLK_MASK) | (((unsigned long)(clk)) << EXI_2CPR_CLK_SHIFT);\
}
#define EXI_2CPR_CS0B_SIZE      1
#define EXI_2CPR_CS0B_SHIFT     7
#define EXI_2CPR_CS0B_MASK      0x00000080
#define EXI_2CPR_GET_CS0B(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_CS0B_MASK) >> EXI_2CPR_CS0B_SHIFT)
#define EXI_2CPR_SET_CS0B(exi_2cpr, cs0b) { \
        FDL_ASSERT(!((cs0b) & ~((1 << EXI_2CPR_CS0B_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_CS0B_MASK) | (((unsigned long)(cs0b)) << EXI_2CPR_CS0B_SHIFT);\
}
#define EXI_2CPR_PAD0_SIZE      6
#define EXI_2CPR_PAD0_SHIFT     8
#define EXI_2CPR_PAD0_MASK      0x00003f00
#define EXI_2CPR_GET_PAD0(exi_2cpr) \
        ((((unsigned long)(exi_2cpr)) & EXI_2CPR_PAD0_MASK) >> EXI_2CPR_PAD0_SHIFT)
#define EXI_2CPR_SET_PAD0(exi_2cpr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_2CPR_PAD0_SIZE)-1))); \
        exi_2cpr = (((unsigned long)(exi_2cpr)) & ~EXI_2CPR_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_2CPR_PAD0_SHIFT);\
}
#define EXI_2CPR_TOTAL_SIZE     14
#define EXI_2CPR_UNUSED_SIZE    18

#define EXI_2CPR(exiintmsk, exiint, tcintmsk, tcint, clk, cs0b) \
        ((((unsigned long)(exiintmsk)) << EXI_2CPR_EXIINTMSK_SHIFT) | \
         (((unsigned long)(exiint)) << EXI_2CPR_EXIINT_SHIFT) | \
         (((unsigned long)(tcintmsk)) << EXI_2CPR_TCINTMSK_SHIFT) | \
         (((unsigned long)(tcint)) << EXI_2CPR_TCINT_SHIFT) | \
         (((unsigned long)(clk)) << EXI_2CPR_CLK_SHIFT) | \
         (((unsigned long)(cs0b)) << EXI_2CPR_CS0B_SHIFT))

/*
 *  exi_2mar struct
 */
#define EXI_2MAR_PAD0_SIZE      5
#define EXI_2MAR_PAD0_SHIFT     0
#define EXI_2MAR_PAD0_MASK      0x0000001f
#define EXI_2MAR_GET_PAD0(exi_2mar) \
        ((((unsigned long)(exi_2mar)) & EXI_2MAR_PAD0_MASK) >> EXI_2MAR_PAD0_SHIFT)
#define EXI_2MAR_SET_PAD0(exi_2mar, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_2MAR_PAD0_SIZE)-1))); \
        exi_2mar = (((unsigned long)(exi_2mar)) & ~EXI_2MAR_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_2MAR_PAD0_SHIFT);\
}
#define EXI_2MAR_EXIMAR_SIZE    27
#define EXI_2MAR_EXIMAR_SHIFT   5
#define EXI_2MAR_EXIMAR_MASK    0xffffffe0
#define EXI_2MAR_GET_EXIMAR(exi_2mar) \
        ((((unsigned long)(exi_2mar)) & EXI_2MAR_EXIMAR_MASK) >> EXI_2MAR_EXIMAR_SHIFT)
#define EXI_2MAR_SET_EXIMAR(exi_2mar, eximar) { \
        FDL_ASSERT(!((eximar) & ~((1 << EXI_2MAR_EXIMAR_SIZE)-1))); \
        exi_2mar = (((unsigned long)(exi_2mar)) & ~EXI_2MAR_EXIMAR_MASK) | (((unsigned long)(eximar)) << EXI_2MAR_EXIMAR_SHIFT);\
}
#define EXI_2MAR_TOTAL_SIZE     32
#define EXI_2MAR(eximar) \
        ((((unsigned long)(eximar)) << EXI_2MAR_EXIMAR_SHIFT))

/*
 *  exi_2length struct
 */
#define EXI_2LENGTH_PAD0_SIZE   5
#define EXI_2LENGTH_PAD0_SHIFT  0
#define EXI_2LENGTH_PAD0_MASK   0x0000001f
#define EXI_2LENGTH_GET_PAD0(exi_2length) \
        ((((unsigned long)(exi_2length)) & EXI_2LENGTH_PAD0_MASK) >> EXI_2LENGTH_PAD0_SHIFT)
#define EXI_2LENGTH_SET_PAD0(exi_2length, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << EXI_2LENGTH_PAD0_SIZE)-1))); \
        exi_2length = (((unsigned long)(exi_2length)) & ~EXI_2LENGTH_PAD0_MASK) | (((unsigned long)(pad0)) << EXI_2LENGTH_PAD0_SHIFT);\
}
#define EXI_2LENGTH_EXILENGTH_SIZE      27
#define EXI_2LENGTH_EXILENGTH_SHIFT     5
#define EXI_2LENGTH_EXILENGTH_MASK      0xffffffe0
#define EXI_2LENGTH_GET_EXILENGTH(exi_2length) \
        ((((unsigned long)(exi_2length)) & EXI_2LENGTH_EXILENGTH_MASK) >> EXI_2LENGTH_EXILENGTH_SHIFT)
#define EXI_2LENGTH_SET_EXILENGTH(exi_2length, exilength) { \
        FDL_ASSERT(!((exilength) & ~((1 << EXI_2LENGTH_EXILENGTH_SIZE)-1))); \
        exi_2length = (((unsigned long)(exi_2length)) & ~EXI_2LENGTH_EXILENGTH_MASK) | (((unsigned long)(exilength)) << EXI_2LENGTH_EXILENGTH_SHIFT);\
}
#define EXI_2LENGTH_TOTAL_SIZE  32
#define EXI_2LENGTH(exilength) \
        ((((unsigned long)(exilength)) << EXI_2LENGTH_EXILENGTH_SHIFT))

/*
 *  exi_2cr struct
 */
#define EXI_2CR_TSTART_SIZE     1
#define EXI_2CR_TSTART_SHIFT    0
#define EXI_2CR_TSTART_MASK     0x00000001
#define EXI_2CR_GET_TSTART(exi_2cr) \
        ((((unsigned long)(exi_2cr)) & EXI_2CR_TSTART_MASK) >> EXI_2CR_TSTART_SHIFT)
#define EXI_2CR_SET_TSTART(exi_2cr, tstart) { \
        FDL_ASSERT(!((tstart) & ~((1 << EXI_2CR_TSTART_SIZE)-1))); \
        exi_2cr = (((unsigned long)(exi_2cr)) & ~EXI_2CR_TSTART_MASK) | (((unsigned long)(tstart)) << EXI_2CR_TSTART_SHIFT);\
}
#define EXI_2CR_DMA_SIZE        1
#define EXI_2CR_DMA_SHIFT       1
#define EXI_2CR_DMA_MASK        0x00000002
#define EXI_2CR_GET_DMA(exi_2cr) \
        ((((unsigned long)(exi_2cr)) & EXI_2CR_DMA_MASK) >> EXI_2CR_DMA_SHIFT)
#define EXI_2CR_SET_DMA(exi_2cr, dma) { \
        FDL_ASSERT(!((dma) & ~((1 << EXI_2CR_DMA_SIZE)-1))); \
        exi_2cr = (((unsigned long)(exi_2cr)) & ~EXI_2CR_DMA_MASK) | (((unsigned long)(dma)) << EXI_2CR_DMA_SHIFT);\
}
#define EXI_2CR_RW_SIZE 2
#define EXI_2CR_RW_SHIFT        2
#define EXI_2CR_RW_MASK 0x0000000c
#define EXI_2CR_GET_RW(exi_2cr) \
        ((((unsigned long)(exi_2cr)) & EXI_2CR_RW_MASK) >> EXI_2CR_RW_SHIFT)
#define EXI_2CR_SET_RW(exi_2cr, rw) { \
        FDL_ASSERT(!((rw) & ~((1 << EXI_2CR_RW_SIZE)-1))); \
        exi_2cr = (((unsigned long)(exi_2cr)) & ~EXI_2CR_RW_MASK) | (((unsigned long)(rw)) << EXI_2CR_RW_SHIFT);\
}
#define EXI_2CR_TLEN_SIZE       2
#define EXI_2CR_TLEN_SHIFT      4
#define EXI_2CR_TLEN_MASK       0x00000030
#define EXI_2CR_GET_TLEN(exi_2cr) \
        ((((unsigned long)(exi_2cr)) & EXI_2CR_TLEN_MASK) >> EXI_2CR_TLEN_SHIFT)
#define EXI_2CR_SET_TLEN(exi_2cr, tlen) { \
        FDL_ASSERT(!((tlen) & ~((1 << EXI_2CR_TLEN_SIZE)-1))); \
        exi_2cr = (((unsigned long)(exi_2cr)) & ~EXI_2CR_TLEN_MASK) | (((unsigned long)(tlen)) << EXI_2CR_TLEN_SHIFT);\
}
#define EXI_2CR_TOTAL_SIZE      6
#define EXI_2CR_UNUSED_SIZE     26

#define EXI_2CR(tstart, dma, rw, tlen) \
        ((((unsigned long)(tstart)) << EXI_2CR_TSTART_SHIFT) | \
         (((unsigned long)(dma)) << EXI_2CR_DMA_SHIFT) | \
         (((unsigned long)(rw)) << EXI_2CR_RW_SHIFT) | \
         (((unsigned long)(tlen)) << EXI_2CR_TLEN_SHIFT))

/*
 *  exi_2data struct
 */
#define EXI_2DATA_DATA3_SIZE    8
#define EXI_2DATA_DATA3_SHIFT   0
#define EXI_2DATA_DATA3_MASK    0x000000ff
#define EXI_2DATA_GET_DATA3(exi_2data) \
        ((((unsigned long)(exi_2data)) & EXI_2DATA_DATA3_MASK) >> EXI_2DATA_DATA3_SHIFT)
#define EXI_2DATA_SET_DATA3(exi_2data, data3) { \
        FDL_ASSERT(!((data3) & ~((1 << EXI_2DATA_DATA3_SIZE)-1))); \
        exi_2data = (((unsigned long)(exi_2data)) & ~EXI_2DATA_DATA3_MASK) | (((unsigned long)(data3)) << EXI_2DATA_DATA3_SHIFT);\
}
#define EXI_2DATA_DATA2_SIZE    8
#define EXI_2DATA_DATA2_SHIFT   8
#define EXI_2DATA_DATA2_MASK    0x0000ff00
#define EXI_2DATA_GET_DATA2(exi_2data) \
        ((((unsigned long)(exi_2data)) & EXI_2DATA_DATA2_MASK) >> EXI_2DATA_DATA2_SHIFT)
#define EXI_2DATA_SET_DATA2(exi_2data, data2) { \
        FDL_ASSERT(!((data2) & ~((1 << EXI_2DATA_DATA2_SIZE)-1))); \
        exi_2data = (((unsigned long)(exi_2data)) & ~EXI_2DATA_DATA2_MASK) | (((unsigned long)(data2)) << EXI_2DATA_DATA2_SHIFT);\
}
#define EXI_2DATA_DATA1_SIZE    8
#define EXI_2DATA_DATA1_SHIFT   16
#define EXI_2DATA_DATA1_MASK    0x00ff0000
#define EXI_2DATA_GET_DATA1(exi_2data) \
        ((((unsigned long)(exi_2data)) & EXI_2DATA_DATA1_MASK) >> EXI_2DATA_DATA1_SHIFT)
#define EXI_2DATA_SET_DATA1(exi_2data, data1) { \
        FDL_ASSERT(!((data1) & ~((1 << EXI_2DATA_DATA1_SIZE)-1))); \
        exi_2data = (((unsigned long)(exi_2data)) & ~EXI_2DATA_DATA1_MASK) | (((unsigned long)(data1)) << EXI_2DATA_DATA1_SHIFT);\
}
#define EXI_2DATA_DATA0_SIZE    8
#define EXI_2DATA_DATA0_SHIFT   24
#define EXI_2DATA_DATA0_MASK    0xff000000
#define EXI_2DATA_GET_DATA0(exi_2data) \
        ((((unsigned long)(exi_2data)) & EXI_2DATA_DATA0_MASK) >> EXI_2DATA_DATA0_SHIFT)
#define EXI_2DATA_SET_DATA0(exi_2data, data0) { \
        FDL_ASSERT(!((data0) & ~((1 << EXI_2DATA_DATA0_SIZE)-1))); \
        exi_2data = (((unsigned long)(exi_2data)) & ~EXI_2DATA_DATA0_MASK) | (((unsigned long)(data0)) << EXI_2DATA_DATA0_SHIFT);\
}
#define EXI_2DATA_TOTAL_SIZE    32
#define EXI_2DATA(data3, data2, data1, data0) \
        ((((unsigned long)(data3)) << EXI_2DATA_DATA3_SHIFT) | \
         (((unsigned long)(data2)) << EXI_2DATA_DATA2_SHIFT) | \
         (((unsigned long)(data1)) << EXI_2DATA_DATA1_SHIFT) | \
         (((unsigned long)(data0)) << EXI_2DATA_DATA0_SHIFT))

/*
 *  di_reg enum
 */
#define DI_SR_IDX       0x00000000
#define DI_CVR_IDX      0x00000001
#define DI_CMDBUF0_IDX  0x00000002
#define DI_CMDBUF1_IDX  0x00000003
#define DI_CMDBUF2_IDX  0x00000004
#define DI_MAR_IDX      0x00000005
#define DI_LENGTH_IDX   0x00000006
#define DI_CR_IDX       0x00000007
#define DI_IMMBUF_IDX   0x00000008
#define DI_CONFIG_IDX   0x00000009
#define DI_REG_UNUSED_10        0x0000000a
#define DI_REG_UNUSED_11        0x0000000b
#define DI_REG_UNUSED_12        0x0000000c
#define DI_REG_UNUSED_13        0x0000000d
#define DI_REG_UNUSED_14        0x0000000e
#define DI_REG_UNUSED_15        0x0000000f

/*
 *  di_brk enum
 */
#define DI_BRK_DONE     0x00000000
#define DI_BRK_REQUEST  0x00000001

/*
 *  di_sr struct
 */
#define DI_SR_BRK_SIZE  1
#define DI_SR_BRK_SHIFT 0
#define DI_SR_BRK_MASK  0x00000001
#define DI_SR_GET_BRK(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_BRK_MASK) >> DI_SR_BRK_SHIFT)
#define DI_SR_SET_BRK(di_sr, brk) { \
        FDL_ASSERT(!((brk) & ~((1 << DI_SR_BRK_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_BRK_MASK) | (((unsigned long)(brk)) << DI_SR_BRK_SHIFT);\
}
#define DI_SR_DEINTMSK_SIZE     1
#define DI_SR_DEINTMSK_SHIFT    1
#define DI_SR_DEINTMSK_MASK     0x00000002
#define DI_SR_GET_DEINTMSK(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_DEINTMSK_MASK) >> DI_SR_DEINTMSK_SHIFT)
#define DI_SR_SET_DEINTMSK(di_sr, deintmsk) { \
        FDL_ASSERT(!((deintmsk) & ~((1 << DI_SR_DEINTMSK_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_DEINTMSK_MASK) | (((unsigned long)(deintmsk)) << DI_SR_DEINTMSK_SHIFT);\
}
#define DI_SR_DEINT_SIZE        1
#define DI_SR_DEINT_SHIFT       2
#define DI_SR_DEINT_MASK        0x00000004
#define DI_SR_GET_DEINT(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_DEINT_MASK) >> DI_SR_DEINT_SHIFT)
#define DI_SR_SET_DEINT(di_sr, deint) { \
        FDL_ASSERT(!((deint) & ~((1 << DI_SR_DEINT_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_DEINT_MASK) | (((unsigned long)(deint)) << DI_SR_DEINT_SHIFT);\
}
#define DI_SR_TCINTMSK_SIZE     1
#define DI_SR_TCINTMSK_SHIFT    3
#define DI_SR_TCINTMSK_MASK     0x00000008
#define DI_SR_GET_TCINTMSK(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_TCINTMSK_MASK) >> DI_SR_TCINTMSK_SHIFT)
#define DI_SR_SET_TCINTMSK(di_sr, tcintmsk) { \
        FDL_ASSERT(!((tcintmsk) & ~((1 << DI_SR_TCINTMSK_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_TCINTMSK_MASK) | (((unsigned long)(tcintmsk)) << DI_SR_TCINTMSK_SHIFT);\
}
#define DI_SR_TCINT_SIZE        1
#define DI_SR_TCINT_SHIFT       4
#define DI_SR_TCINT_MASK        0x00000010
#define DI_SR_GET_TCINT(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_TCINT_MASK) >> DI_SR_TCINT_SHIFT)
#define DI_SR_SET_TCINT(di_sr, tcint) { \
        FDL_ASSERT(!((tcint) & ~((1 << DI_SR_TCINT_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_TCINT_MASK) | (((unsigned long)(tcint)) << DI_SR_TCINT_SHIFT);\
}
#define DI_SR_BRKINTMSK_SIZE    1
#define DI_SR_BRKINTMSK_SHIFT   5
#define DI_SR_BRKINTMSK_MASK    0x00000020
#define DI_SR_GET_BRKINTMSK(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_BRKINTMSK_MASK) >> DI_SR_BRKINTMSK_SHIFT)
#define DI_SR_SET_BRKINTMSK(di_sr, brkintmsk) { \
        FDL_ASSERT(!((brkintmsk) & ~((1 << DI_SR_BRKINTMSK_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_BRKINTMSK_MASK) | (((unsigned long)(brkintmsk)) << DI_SR_BRKINTMSK_SHIFT);\
}
#define DI_SR_BRKINT_SIZE       1
#define DI_SR_BRKINT_SHIFT      6
#define DI_SR_BRKINT_MASK       0x00000040
#define DI_SR_GET_BRKINT(di_sr) \
        ((((unsigned long)(di_sr)) & DI_SR_BRKINT_MASK) >> DI_SR_BRKINT_SHIFT)
#define DI_SR_SET_BRKINT(di_sr, brkint) { \
        FDL_ASSERT(!((brkint) & ~((1 << DI_SR_BRKINT_SIZE)-1))); \
        di_sr = (((unsigned long)(di_sr)) & ~DI_SR_BRKINT_MASK) | (((unsigned long)(brkint)) << DI_SR_BRKINT_SHIFT);\
}
#define DI_SR_TOTAL_SIZE        7
#define DI_SR_UNUSED_SIZE       25

#define DI_SR(brk, deintmsk, deint, tcintmsk, tcint, brkintmsk, brkint) \
        ((((unsigned long)(brk)) << DI_SR_BRK_SHIFT) | \
         (((unsigned long)(deintmsk)) << DI_SR_DEINTMSK_SHIFT) | \
         (((unsigned long)(deint)) << DI_SR_DEINT_SHIFT) | \
         (((unsigned long)(tcintmsk)) << DI_SR_TCINTMSK_SHIFT) | \
         (((unsigned long)(tcint)) << DI_SR_TCINT_SHIFT) | \
         (((unsigned long)(brkintmsk)) << DI_SR_BRKINTMSK_SHIFT) | \
         (((unsigned long)(brkint)) << DI_SR_BRKINT_SHIFT))

/*
 *  di_cvr enum
 */
#define DI_CVR_CLOSED   0x00000000
#define DI_CVR_OPEN     0x00000001

/*
 *  di_cvr struct
 */
#define DI_CVR_CVR_SIZE 1
#define DI_CVR_CVR_SHIFT        0
#define DI_CVR_CVR_MASK 0x00000001
#define DI_CVR_GET_CVR(di_cvr) \
        ((((unsigned long)(di_cvr)) & DI_CVR_CVR_MASK) >> DI_CVR_CVR_SHIFT)
#define DI_CVR_SET_CVR(di_cvr, cvr) { \
        FDL_ASSERT(!((cvr) & ~((1 << DI_CVR_CVR_SIZE)-1))); \
        di_cvr = (((unsigned long)(di_cvr)) & ~DI_CVR_CVR_MASK) | (((unsigned long)(cvr)) << DI_CVR_CVR_SHIFT);\
}
#define DI_CVR_CVRINTMSK_SIZE   1
#define DI_CVR_CVRINTMSK_SHIFT  1
#define DI_CVR_CVRINTMSK_MASK   0x00000002
#define DI_CVR_GET_CVRINTMSK(di_cvr) \
        ((((unsigned long)(di_cvr)) & DI_CVR_CVRINTMSK_MASK) >> DI_CVR_CVRINTMSK_SHIFT)
#define DI_CVR_SET_CVRINTMSK(di_cvr, cvrintmsk) { \
        FDL_ASSERT(!((cvrintmsk) & ~((1 << DI_CVR_CVRINTMSK_SIZE)-1))); \
        di_cvr = (((unsigned long)(di_cvr)) & ~DI_CVR_CVRINTMSK_MASK) | (((unsigned long)(cvrintmsk)) << DI_CVR_CVRINTMSK_SHIFT);\
}
#define DI_CVR_CVRINT_SIZE      1
#define DI_CVR_CVRINT_SHIFT     2
#define DI_CVR_CVRINT_MASK      0x00000004
#define DI_CVR_GET_CVRINT(di_cvr) \
        ((((unsigned long)(di_cvr)) & DI_CVR_CVRINT_MASK) >> DI_CVR_CVRINT_SHIFT)
#define DI_CVR_SET_CVRINT(di_cvr, cvrint) { \
        FDL_ASSERT(!((cvrint) & ~((1 << DI_CVR_CVRINT_SIZE)-1))); \
        di_cvr = (((unsigned long)(di_cvr)) & ~DI_CVR_CVRINT_MASK) | (((unsigned long)(cvrint)) << DI_CVR_CVRINT_SHIFT);\
}
#define DI_CVR_TOTAL_SIZE       3
#define DI_CVR_UNUSED_SIZE      29

#define DI_CVR(cvr, cvrintmsk, cvrint) \
        ((((unsigned long)(cvr)) << DI_CVR_CVR_SHIFT) | \
         (((unsigned long)(cvrintmsk)) << DI_CVR_CVRINTMSK_SHIFT) | \
         (((unsigned long)(cvrint)) << DI_CVR_CVRINT_SHIFT))

/*
 *  di_cmdbuf0 struct
 */
#define DI_CMDBUF0_CMDBYTE0_SIZE        8
#define DI_CMDBUF0_CMDBYTE0_SHIFT       0
#define DI_CMDBUF0_CMDBYTE0_MASK        0x000000ff
#define DI_CMDBUF0_GET_CMDBYTE0(di_cmdbuf0) \
        ((((unsigned long)(di_cmdbuf0)) & DI_CMDBUF0_CMDBYTE0_MASK) >> DI_CMDBUF0_CMDBYTE0_SHIFT)
#define DI_CMDBUF0_SET_CMDBYTE0(di_cmdbuf0, cmdbyte0) { \
        FDL_ASSERT(!((cmdbyte0) & ~((1 << DI_CMDBUF0_CMDBYTE0_SIZE)-1))); \
        di_cmdbuf0 = (((unsigned long)(di_cmdbuf0)) & ~DI_CMDBUF0_CMDBYTE0_MASK) | (((unsigned long)(cmdbyte0)) << DI_CMDBUF0_CMDBYTE0_SHIFT);\
}
#define DI_CMDBUF0_CMDBYTE1_SIZE        8
#define DI_CMDBUF0_CMDBYTE1_SHIFT       8
#define DI_CMDBUF0_CMDBYTE1_MASK        0x0000ff00
#define DI_CMDBUF0_GET_CMDBYTE1(di_cmdbuf0) \
        ((((unsigned long)(di_cmdbuf0)) & DI_CMDBUF0_CMDBYTE1_MASK) >> DI_CMDBUF0_CMDBYTE1_SHIFT)
#define DI_CMDBUF0_SET_CMDBYTE1(di_cmdbuf0, cmdbyte1) { \
        FDL_ASSERT(!((cmdbyte1) & ~((1 << DI_CMDBUF0_CMDBYTE1_SIZE)-1))); \
        di_cmdbuf0 = (((unsigned long)(di_cmdbuf0)) & ~DI_CMDBUF0_CMDBYTE1_MASK) | (((unsigned long)(cmdbyte1)) << DI_CMDBUF0_CMDBYTE1_SHIFT);\
}
#define DI_CMDBUF0_CMDBYTE2_SIZE        8
#define DI_CMDBUF0_CMDBYTE2_SHIFT       16
#define DI_CMDBUF0_CMDBYTE2_MASK        0x00ff0000
#define DI_CMDBUF0_GET_CMDBYTE2(di_cmdbuf0) \
        ((((unsigned long)(di_cmdbuf0)) & DI_CMDBUF0_CMDBYTE2_MASK) >> DI_CMDBUF0_CMDBYTE2_SHIFT)
#define DI_CMDBUF0_SET_CMDBYTE2(di_cmdbuf0, cmdbyte2) { \
        FDL_ASSERT(!((cmdbyte2) & ~((1 << DI_CMDBUF0_CMDBYTE2_SIZE)-1))); \
        di_cmdbuf0 = (((unsigned long)(di_cmdbuf0)) & ~DI_CMDBUF0_CMDBYTE2_MASK) | (((unsigned long)(cmdbyte2)) << DI_CMDBUF0_CMDBYTE2_SHIFT);\
}
#define DI_CMDBUF0_CMDBYTE3_SIZE        8
#define DI_CMDBUF0_CMDBYTE3_SHIFT       24
#define DI_CMDBUF0_CMDBYTE3_MASK        0xff000000
#define DI_CMDBUF0_GET_CMDBYTE3(di_cmdbuf0) \
        ((((unsigned long)(di_cmdbuf0)) & DI_CMDBUF0_CMDBYTE3_MASK) >> DI_CMDBUF0_CMDBYTE3_SHIFT)
#define DI_CMDBUF0_SET_CMDBYTE3(di_cmdbuf0, cmdbyte3) { \
        FDL_ASSERT(!((cmdbyte3) & ~((1 << DI_CMDBUF0_CMDBYTE3_SIZE)-1))); \
        di_cmdbuf0 = (((unsigned long)(di_cmdbuf0)) & ~DI_CMDBUF0_CMDBYTE3_MASK) | (((unsigned long)(cmdbyte3)) << DI_CMDBUF0_CMDBYTE3_SHIFT);\
}
#define DI_CMDBUF0_TOTAL_SIZE   32
#define DI_CMDBUF0(cmdbyte0, cmdbyte1, cmdbyte2, cmdbyte3) \
        ((((unsigned long)(cmdbyte0)) << DI_CMDBUF0_CMDBYTE0_SHIFT) | \
         (((unsigned long)(cmdbyte1)) << DI_CMDBUF0_CMDBYTE1_SHIFT) | \
         (((unsigned long)(cmdbyte2)) << DI_CMDBUF0_CMDBYTE2_SHIFT) | \
         (((unsigned long)(cmdbyte3)) << DI_CMDBUF0_CMDBYTE3_SHIFT))

/*
 *  di_cmdbuf1 struct
 */
#define DI_CMDBUF1_CMDBYTE4_SIZE        8
#define DI_CMDBUF1_CMDBYTE4_SHIFT       0
#define DI_CMDBUF1_CMDBYTE4_MASK        0x000000ff
#define DI_CMDBUF1_GET_CMDBYTE4(di_cmdbuf1) \
        ((((unsigned long)(di_cmdbuf1)) & DI_CMDBUF1_CMDBYTE4_MASK) >> DI_CMDBUF1_CMDBYTE4_SHIFT)
#define DI_CMDBUF1_SET_CMDBYTE4(di_cmdbuf1, cmdbyte4) { \
        FDL_ASSERT(!((cmdbyte4) & ~((1 << DI_CMDBUF1_CMDBYTE4_SIZE)-1))); \
        di_cmdbuf1 = (((unsigned long)(di_cmdbuf1)) & ~DI_CMDBUF1_CMDBYTE4_MASK) | (((unsigned long)(cmdbyte4)) << DI_CMDBUF1_CMDBYTE4_SHIFT);\
}
#define DI_CMDBUF1_CMDBYTE5_SIZE        8
#define DI_CMDBUF1_CMDBYTE5_SHIFT       8
#define DI_CMDBUF1_CMDBYTE5_MASK        0x0000ff00
#define DI_CMDBUF1_GET_CMDBYTE5(di_cmdbuf1) \
        ((((unsigned long)(di_cmdbuf1)) & DI_CMDBUF1_CMDBYTE5_MASK) >> DI_CMDBUF1_CMDBYTE5_SHIFT)
#define DI_CMDBUF1_SET_CMDBYTE5(di_cmdbuf1, cmdbyte5) { \
        FDL_ASSERT(!((cmdbyte5) & ~((1 << DI_CMDBUF1_CMDBYTE5_SIZE)-1))); \
        di_cmdbuf1 = (((unsigned long)(di_cmdbuf1)) & ~DI_CMDBUF1_CMDBYTE5_MASK) | (((unsigned long)(cmdbyte5)) << DI_CMDBUF1_CMDBYTE5_SHIFT);\
}
#define DI_CMDBUF1_CMDBYTE6_SIZE        8
#define DI_CMDBUF1_CMDBYTE6_SHIFT       16
#define DI_CMDBUF1_CMDBYTE6_MASK        0x00ff0000
#define DI_CMDBUF1_GET_CMDBYTE6(di_cmdbuf1) \
        ((((unsigned long)(di_cmdbuf1)) & DI_CMDBUF1_CMDBYTE6_MASK) >> DI_CMDBUF1_CMDBYTE6_SHIFT)
#define DI_CMDBUF1_SET_CMDBYTE6(di_cmdbuf1, cmdbyte6) { \
        FDL_ASSERT(!((cmdbyte6) & ~((1 << DI_CMDBUF1_CMDBYTE6_SIZE)-1))); \
        di_cmdbuf1 = (((unsigned long)(di_cmdbuf1)) & ~DI_CMDBUF1_CMDBYTE6_MASK) | (((unsigned long)(cmdbyte6)) << DI_CMDBUF1_CMDBYTE6_SHIFT);\
}
#define DI_CMDBUF1_CMDBYTE7_SIZE        8
#define DI_CMDBUF1_CMDBYTE7_SHIFT       24
#define DI_CMDBUF1_CMDBYTE7_MASK        0xff000000
#define DI_CMDBUF1_GET_CMDBYTE7(di_cmdbuf1) \
        ((((unsigned long)(di_cmdbuf1)) & DI_CMDBUF1_CMDBYTE7_MASK) >> DI_CMDBUF1_CMDBYTE7_SHIFT)
#define DI_CMDBUF1_SET_CMDBYTE7(di_cmdbuf1, cmdbyte7) { \
        FDL_ASSERT(!((cmdbyte7) & ~((1 << DI_CMDBUF1_CMDBYTE7_SIZE)-1))); \
        di_cmdbuf1 = (((unsigned long)(di_cmdbuf1)) & ~DI_CMDBUF1_CMDBYTE7_MASK) | (((unsigned long)(cmdbyte7)) << DI_CMDBUF1_CMDBYTE7_SHIFT);\
}
#define DI_CMDBUF1_TOTAL_SIZE   32
#define DI_CMDBUF1(cmdbyte4, cmdbyte5, cmdbyte6, cmdbyte7) \
        ((((unsigned long)(cmdbyte4)) << DI_CMDBUF1_CMDBYTE4_SHIFT) | \
         (((unsigned long)(cmdbyte5)) << DI_CMDBUF1_CMDBYTE5_SHIFT) | \
         (((unsigned long)(cmdbyte6)) << DI_CMDBUF1_CMDBYTE6_SHIFT) | \
         (((unsigned long)(cmdbyte7)) << DI_CMDBUF1_CMDBYTE7_SHIFT))

/*
 *  di_cmdbuf2 struct
 */
#define DI_CMDBUF2_CMDBYTE8_SIZE        8
#define DI_CMDBUF2_CMDBYTE8_SHIFT       0
#define DI_CMDBUF2_CMDBYTE8_MASK        0x000000ff
#define DI_CMDBUF2_GET_CMDBYTE8(di_cmdbuf2) \
        ((((unsigned long)(di_cmdbuf2)) & DI_CMDBUF2_CMDBYTE8_MASK) >> DI_CMDBUF2_CMDBYTE8_SHIFT)
#define DI_CMDBUF2_SET_CMDBYTE8(di_cmdbuf2, cmdbyte8) { \
        FDL_ASSERT(!((cmdbyte8) & ~((1 << DI_CMDBUF2_CMDBYTE8_SIZE)-1))); \
        di_cmdbuf2 = (((unsigned long)(di_cmdbuf2)) & ~DI_CMDBUF2_CMDBYTE8_MASK) | (((unsigned long)(cmdbyte8)) << DI_CMDBUF2_CMDBYTE8_SHIFT);\
}
#define DI_CMDBUF2_CMDBYTE9_SIZE        8
#define DI_CMDBUF2_CMDBYTE9_SHIFT       8
#define DI_CMDBUF2_CMDBYTE9_MASK        0x0000ff00
#define DI_CMDBUF2_GET_CMDBYTE9(di_cmdbuf2) \
        ((((unsigned long)(di_cmdbuf2)) & DI_CMDBUF2_CMDBYTE9_MASK) >> DI_CMDBUF2_CMDBYTE9_SHIFT)
#define DI_CMDBUF2_SET_CMDBYTE9(di_cmdbuf2, cmdbyte9) { \
        FDL_ASSERT(!((cmdbyte9) & ~((1 << DI_CMDBUF2_CMDBYTE9_SIZE)-1))); \
        di_cmdbuf2 = (((unsigned long)(di_cmdbuf2)) & ~DI_CMDBUF2_CMDBYTE9_MASK) | (((unsigned long)(cmdbyte9)) << DI_CMDBUF2_CMDBYTE9_SHIFT);\
}
#define DI_CMDBUF2_CMDBYTE10_SIZE       8
#define DI_CMDBUF2_CMDBYTE10_SHIFT      16
#define DI_CMDBUF2_CMDBYTE10_MASK       0x00ff0000
#define DI_CMDBUF2_GET_CMDBYTE10(di_cmdbuf2) \
        ((((unsigned long)(di_cmdbuf2)) & DI_CMDBUF2_CMDBYTE10_MASK) >> DI_CMDBUF2_CMDBYTE10_SHIFT)
#define DI_CMDBUF2_SET_CMDBYTE10(di_cmdbuf2, cmdbyte10) { \
        FDL_ASSERT(!((cmdbyte10) & ~((1 << DI_CMDBUF2_CMDBYTE10_SIZE)-1))); \
        di_cmdbuf2 = (((unsigned long)(di_cmdbuf2)) & ~DI_CMDBUF2_CMDBYTE10_MASK) | (((unsigned long)(cmdbyte10)) << DI_CMDBUF2_CMDBYTE10_SHIFT);\
}
#define DI_CMDBUF2_CMDBYTE11_SIZE       8
#define DI_CMDBUF2_CMDBYTE11_SHIFT      24
#define DI_CMDBUF2_CMDBYTE11_MASK       0xff000000
#define DI_CMDBUF2_GET_CMDBYTE11(di_cmdbuf2) \
        ((((unsigned long)(di_cmdbuf2)) & DI_CMDBUF2_CMDBYTE11_MASK) >> DI_CMDBUF2_CMDBYTE11_SHIFT)
#define DI_CMDBUF2_SET_CMDBYTE11(di_cmdbuf2, cmdbyte11) { \
        FDL_ASSERT(!((cmdbyte11) & ~((1 << DI_CMDBUF2_CMDBYTE11_SIZE)-1))); \
        di_cmdbuf2 = (((unsigned long)(di_cmdbuf2)) & ~DI_CMDBUF2_CMDBYTE11_MASK) | (((unsigned long)(cmdbyte11)) << DI_CMDBUF2_CMDBYTE11_SHIFT);\
}
#define DI_CMDBUF2_TOTAL_SIZE   32
#define DI_CMDBUF2(cmdbyte8, cmdbyte9, cmdbyte10, cmdbyte11) \
        ((((unsigned long)(cmdbyte8)) << DI_CMDBUF2_CMDBYTE8_SHIFT) | \
         (((unsigned long)(cmdbyte9)) << DI_CMDBUF2_CMDBYTE9_SHIFT) | \
         (((unsigned long)(cmdbyte10)) << DI_CMDBUF2_CMDBYTE10_SHIFT) | \
         (((unsigned long)(cmdbyte11)) << DI_CMDBUF2_CMDBYTE11_SHIFT))

/*
 *  di_mar struct
 */
#define DI_MAR_PAD0_SIZE        5
#define DI_MAR_PAD0_SHIFT       0
#define DI_MAR_PAD0_MASK        0x0000001f
#define DI_MAR_GET_PAD0(di_mar) \
        ((((unsigned long)(di_mar)) & DI_MAR_PAD0_MASK) >> DI_MAR_PAD0_SHIFT)
#define DI_MAR_SET_PAD0(di_mar, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << DI_MAR_PAD0_SIZE)-1))); \
        di_mar = (((unsigned long)(di_mar)) & ~DI_MAR_PAD0_MASK) | (((unsigned long)(pad0)) << DI_MAR_PAD0_SHIFT);\
}
#define DI_MAR_DIMAR_SIZE       21
#define DI_MAR_DIMAR_SHIFT      5
#define DI_MAR_DIMAR_MASK       0x03ffffe0
#define DI_MAR_GET_DIMAR(di_mar) \
        ((((unsigned long)(di_mar)) & DI_MAR_DIMAR_MASK) >> DI_MAR_DIMAR_SHIFT)
#define DI_MAR_SET_DIMAR(di_mar, dimar) { \
        FDL_ASSERT(!((dimar) & ~((1 << DI_MAR_DIMAR_SIZE)-1))); \
        di_mar = (((unsigned long)(di_mar)) & ~DI_MAR_DIMAR_MASK) | (((unsigned long)(dimar)) << DI_MAR_DIMAR_SHIFT);\
}
#define DI_MAR_PAD1_SIZE        6
#define DI_MAR_PAD1_SHIFT       26
#define DI_MAR_PAD1_MASK        0xfc000000
#define DI_MAR_GET_PAD1(di_mar) \
        ((((unsigned long)(di_mar)) & DI_MAR_PAD1_MASK) >> DI_MAR_PAD1_SHIFT)
#define DI_MAR_SET_PAD1(di_mar, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << DI_MAR_PAD1_SIZE)-1))); \
        di_mar = (((unsigned long)(di_mar)) & ~DI_MAR_PAD1_MASK) | (((unsigned long)(pad1)) << DI_MAR_PAD1_SHIFT);\
}
#define DI_MAR_TOTAL_SIZE       32
#define DI_MAR(dimar) \
        ((((unsigned long)(dimar)) << DI_MAR_DIMAR_SHIFT))

/*
 *  di_length struct
 */
#define DI_LENGTH_PAD0_SIZE     5
#define DI_LENGTH_PAD0_SHIFT    0
#define DI_LENGTH_PAD0_MASK     0x0000001f
#define DI_LENGTH_GET_PAD0(di_length) \
        ((((unsigned long)(di_length)) & DI_LENGTH_PAD0_MASK) >> DI_LENGTH_PAD0_SHIFT)
#define DI_LENGTH_SET_PAD0(di_length, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << DI_LENGTH_PAD0_SIZE)-1))); \
        di_length = (((unsigned long)(di_length)) & ~DI_LENGTH_PAD0_MASK) | (((unsigned long)(pad0)) << DI_LENGTH_PAD0_SHIFT);\
}
#define DI_LENGTH_DILENGTH_SIZE 21
#define DI_LENGTH_DILENGTH_SHIFT        5
#define DI_LENGTH_DILENGTH_MASK 0x03ffffe0
#define DI_LENGTH_GET_DILENGTH(di_length) \
        ((((unsigned long)(di_length)) & DI_LENGTH_DILENGTH_MASK) >> DI_LENGTH_DILENGTH_SHIFT)
#define DI_LENGTH_SET_DILENGTH(di_length, dilength) { \
        FDL_ASSERT(!((dilength) & ~((1 << DI_LENGTH_DILENGTH_SIZE)-1))); \
        di_length = (((unsigned long)(di_length)) & ~DI_LENGTH_DILENGTH_MASK) | (((unsigned long)(dilength)) << DI_LENGTH_DILENGTH_SHIFT);\
}
#define DI_LENGTH_PAD1_SIZE     6
#define DI_LENGTH_PAD1_SHIFT    26
#define DI_LENGTH_PAD1_MASK     0xfc000000
#define DI_LENGTH_GET_PAD1(di_length) \
        ((((unsigned long)(di_length)) & DI_LENGTH_PAD1_MASK) >> DI_LENGTH_PAD1_SHIFT)
#define DI_LENGTH_SET_PAD1(di_length, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << DI_LENGTH_PAD1_SIZE)-1))); \
        di_length = (((unsigned long)(di_length)) & ~DI_LENGTH_PAD1_MASK) | (((unsigned long)(pad1)) << DI_LENGTH_PAD1_SHIFT);\
}
#define DI_LENGTH_TOTAL_SIZE    32
#define DI_LENGTH(dilength) \
        ((((unsigned long)(dilength)) << DI_LENGTH_DILENGTH_SHIFT))

/*
 *  di_cr struct
 */
#define DI_CR_TSTART_SIZE       1
#define DI_CR_TSTART_SHIFT      0
#define DI_CR_TSTART_MASK       0x00000001
#define DI_CR_GET_TSTART(di_cr) \
        ((((unsigned long)(di_cr)) & DI_CR_TSTART_MASK) >> DI_CR_TSTART_SHIFT)
#define DI_CR_SET_TSTART(di_cr, tstart) { \
        FDL_ASSERT(!((tstart) & ~((1 << DI_CR_TSTART_SIZE)-1))); \
        di_cr = (((unsigned long)(di_cr)) & ~DI_CR_TSTART_MASK) | (((unsigned long)(tstart)) << DI_CR_TSTART_SHIFT);\
}
#define DI_CR_DMA_SIZE  1
#define DI_CR_DMA_SHIFT 1
#define DI_CR_DMA_MASK  0x00000002
#define DI_CR_GET_DMA(di_cr) \
        ((((unsigned long)(di_cr)) & DI_CR_DMA_MASK) >> DI_CR_DMA_SHIFT)
#define DI_CR_SET_DMA(di_cr, dma) { \
        FDL_ASSERT(!((dma) & ~((1 << DI_CR_DMA_SIZE)-1))); \
        di_cr = (((unsigned long)(di_cr)) & ~DI_CR_DMA_MASK) | (((unsigned long)(dma)) << DI_CR_DMA_SHIFT);\
}
#define DI_CR_RW_SIZE   1
#define DI_CR_RW_SHIFT  2
#define DI_CR_RW_MASK   0x00000004
#define DI_CR_GET_RW(di_cr) \
        ((((unsigned long)(di_cr)) & DI_CR_RW_MASK) >> DI_CR_RW_SHIFT)
#define DI_CR_SET_RW(di_cr, rw) { \
        FDL_ASSERT(!((rw) & ~((1 << DI_CR_RW_SIZE)-1))); \
        di_cr = (((unsigned long)(di_cr)) & ~DI_CR_RW_MASK) | (((unsigned long)(rw)) << DI_CR_RW_SHIFT);\
}
#define DI_CR_PAD0_SIZE 29
#define DI_CR_PAD0_SHIFT        3
#define DI_CR_PAD0_MASK 0xfffffff8
#define DI_CR_GET_PAD0(di_cr) \
        ((((unsigned long)(di_cr)) & DI_CR_PAD0_MASK) >> DI_CR_PAD0_SHIFT)
#define DI_CR_SET_PAD0(di_cr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << DI_CR_PAD0_SIZE)-1))); \
        di_cr = (((unsigned long)(di_cr)) & ~DI_CR_PAD0_MASK) | (((unsigned long)(pad0)) << DI_CR_PAD0_SHIFT);\
}
#define DI_CR_TOTAL_SIZE        32
#define DI_CR(tstart, dma, rw) \
        ((((unsigned long)(tstart)) << DI_CR_TSTART_SHIFT) | \
         (((unsigned long)(dma)) << DI_CR_DMA_SHIFT) | \
         (((unsigned long)(rw)) << DI_CR_RW_SHIFT))

/*
 *  di_immbuf struct
 */
#define DI_IMMBUF_REGVAL3_SIZE  8
#define DI_IMMBUF_REGVAL3_SHIFT 0
#define DI_IMMBUF_REGVAL3_MASK  0x000000ff
#define DI_IMMBUF_GET_REGVAL3(di_immbuf) \
        ((((unsigned long)(di_immbuf)) & DI_IMMBUF_REGVAL3_MASK) >> DI_IMMBUF_REGVAL3_SHIFT)
#define DI_IMMBUF_SET_REGVAL3(di_immbuf, regval3) { \
        FDL_ASSERT(!((regval3) & ~((1 << DI_IMMBUF_REGVAL3_SIZE)-1))); \
        di_immbuf = (((unsigned long)(di_immbuf)) & ~DI_IMMBUF_REGVAL3_MASK) | (((unsigned long)(regval3)) << DI_IMMBUF_REGVAL3_SHIFT);\
}
#define DI_IMMBUF_REGVAL2_SIZE  8
#define DI_IMMBUF_REGVAL2_SHIFT 8
#define DI_IMMBUF_REGVAL2_MASK  0x0000ff00
#define DI_IMMBUF_GET_REGVAL2(di_immbuf) \
        ((((unsigned long)(di_immbuf)) & DI_IMMBUF_REGVAL2_MASK) >> DI_IMMBUF_REGVAL2_SHIFT)
#define DI_IMMBUF_SET_REGVAL2(di_immbuf, regval2) { \
        FDL_ASSERT(!((regval2) & ~((1 << DI_IMMBUF_REGVAL2_SIZE)-1))); \
        di_immbuf = (((unsigned long)(di_immbuf)) & ~DI_IMMBUF_REGVAL2_MASK) | (((unsigned long)(regval2)) << DI_IMMBUF_REGVAL2_SHIFT);\
}
#define DI_IMMBUF_REGVAL1_SIZE  8
#define DI_IMMBUF_REGVAL1_SHIFT 16
#define DI_IMMBUF_REGVAL1_MASK  0x00ff0000
#define DI_IMMBUF_GET_REGVAL1(di_immbuf) \
        ((((unsigned long)(di_immbuf)) & DI_IMMBUF_REGVAL1_MASK) >> DI_IMMBUF_REGVAL1_SHIFT)
#define DI_IMMBUF_SET_REGVAL1(di_immbuf, regval1) { \
        FDL_ASSERT(!((regval1) & ~((1 << DI_IMMBUF_REGVAL1_SIZE)-1))); \
        di_immbuf = (((unsigned long)(di_immbuf)) & ~DI_IMMBUF_REGVAL1_MASK) | (((unsigned long)(regval1)) << DI_IMMBUF_REGVAL1_SHIFT);\
}
#define DI_IMMBUF_REGVAL0_SIZE  8
#define DI_IMMBUF_REGVAL0_SHIFT 24
#define DI_IMMBUF_REGVAL0_MASK  0xff000000
#define DI_IMMBUF_GET_REGVAL0(di_immbuf) \
        ((((unsigned long)(di_immbuf)) & DI_IMMBUF_REGVAL0_MASK) >> DI_IMMBUF_REGVAL0_SHIFT)
#define DI_IMMBUF_SET_REGVAL0(di_immbuf, regval0) { \
        FDL_ASSERT(!((regval0) & ~((1 << DI_IMMBUF_REGVAL0_SIZE)-1))); \
        di_immbuf = (((unsigned long)(di_immbuf)) & ~DI_IMMBUF_REGVAL0_MASK) | (((unsigned long)(regval0)) << DI_IMMBUF_REGVAL0_SHIFT);\
}
#define DI_IMMBUF_TOTAL_SIZE    32
#define DI_IMMBUF(regval3, regval2, regval1, regval0) \
        ((((unsigned long)(regval3)) << DI_IMMBUF_REGVAL3_SHIFT) | \
         (((unsigned long)(regval2)) << DI_IMMBUF_REGVAL2_SHIFT) | \
         (((unsigned long)(regval1)) << DI_IMMBUF_REGVAL1_SHIFT) | \
         (((unsigned long)(regval0)) << DI_IMMBUF_REGVAL0_SHIFT))

/*
 *  di_config struct
 */
#define DI_CONFIG_CONFIG_SIZE   8
#define DI_CONFIG_CONFIG_SHIFT  0
#define DI_CONFIG_CONFIG_MASK   0x000000ff
#define DI_CONFIG_GET_CONFIG(di_config) \
        ((((unsigned long)(di_config)) & DI_CONFIG_CONFIG_MASK) >> DI_CONFIG_CONFIG_SHIFT)
#define DI_CONFIG_SET_CONFIG(di_config, config) { \
        FDL_ASSERT(!((config) & ~((1 << DI_CONFIG_CONFIG_SIZE)-1))); \
        di_config = (((unsigned long)(di_config)) & ~DI_CONFIG_CONFIG_MASK) | (((unsigned long)(config)) << DI_CONFIG_CONFIG_SHIFT);\
}
#define DI_CONFIG_PAD0_SIZE     24
#define DI_CONFIG_PAD0_SHIFT    8
#define DI_CONFIG_PAD0_MASK     0xffffff00
#define DI_CONFIG_GET_PAD0(di_config) \
        ((((unsigned long)(di_config)) & DI_CONFIG_PAD0_MASK) >> DI_CONFIG_PAD0_SHIFT)
#define DI_CONFIG_SET_PAD0(di_config, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << DI_CONFIG_PAD0_SIZE)-1))); \
        di_config = (((unsigned long)(di_config)) & ~DI_CONFIG_PAD0_MASK) | (((unsigned long)(pad0)) << DI_CONFIG_PAD0_SHIFT);\
}
#define DI_CONFIG_TOTAL_SIZE    32
#define DI_CONFIG(config) \
        ((((unsigned long)(config)) << DI_CONFIG_CONFIG_SHIFT))

/*
 *  si_reg enum
 */
#define SI_0OUTBUF_IDX  0x00000000
#define SI_0INBUFH_IDX  0x00000001
#define SI_0INBUFL_IDX  0x00000002
#define SI_1OUTBUF_IDX  0x00000003
#define SI_1INBUFH_IDX  0x00000004
#define SI_1INBUFL_IDX  0x00000005
#define SI_2OUTBUF_IDX  0x00000006
#define SI_2INBUFH_IDX  0x00000007
#define SI_2INBUFL_IDX  0x00000008
#define SI_3OUTBUF_IDX  0x00000009
#define SI_3INBUFH_IDX  0x0000000a
#define SI_3INBUFL_IDX  0x0000000b
#define SI_POLL_IDX     0x0000000c
#define SI_COMCSR_IDX   0x0000000d
#define SI_SR_IDX       0x0000000e
#define SI_EXILK_IDX    0x0000000f
#define SI_DIMSM_IDX    0x00000010
#define SI_FRMCNT_IDX   0x00000011
#define SI_REG_UNUSED_18        0x00000012
#define SI_REG_UNUSED_19        0x00000013
#define SI_REG_UNUSED_20        0x00000014
#define SI_REG_UNUSED_21        0x00000015
#define SI_REG_UNUSED_22        0x00000016
#define SI_REG_UNUSED_23        0x00000017
#define SI_REG_UNUSED_24        0x00000018
#define SI_REG_UNUSED_25        0x00000019
#define SI_REG_UNUSED_26        0x0000001a
#define SI_REG_UNUSED_27        0x0000001b
#define SI_REG_UNUSED_28        0x0000001c
#define SI_REG_UNUSED_29        0x0000001d
#define SI_REG_UNUSED_30        0x0000001e
#define SI_REG_UNUSED_31        0x0000001f
#define SI_RAM_IDX      0x00000020
#define SI_REG_UNUSED_33        0x00000021
#define SI_REG_UNUSED_34        0x00000022
#define SI_REG_UNUSED_35        0x00000023
#define SI_REG_UNUSED_36        0x00000024
#define SI_REG_UNUSED_37        0x00000025
#define SI_REG_UNUSED_38        0x00000026
#define SI_REG_UNUSED_39        0x00000027
#define SI_REG_UNUSED_40        0x00000028
#define SI_REG_UNUSED_41        0x00000029
#define SI_REG_UNUSED_42        0x0000002a
#define SI_REG_UNUSED_43        0x0000002b
#define SI_REG_UNUSED_44        0x0000002c
#define SI_REG_UNUSED_45        0x0000002d
#define SI_REG_UNUSED_46        0x0000002e
#define SI_REG_UNUSED_47        0x0000002f
#define SI_REG_UNUSED_48        0x00000030
#define SI_REG_UNUSED_49        0x00000031
#define SI_REG_UNUSED_50        0x00000032
#define SI_REG_UNUSED_51        0x00000033
#define SI_REG_UNUSED_52        0x00000034
#define SI_REG_UNUSED_53        0x00000035
#define SI_REG_UNUSED_54        0x00000036
#define SI_REG_UNUSED_55        0x00000037
#define SI_REG_UNUSED_56        0x00000038
#define SI_REG_UNUSED_57        0x00000039
#define SI_REG_UNUSED_58        0x0000003a
#define SI_REG_UNUSED_59        0x0000003b
#define SI_REG_UNUSED_60        0x0000003c
#define SI_REG_UNUSED_61        0x0000003d
#define SI_REG_UNUSED_62        0x0000003e
#define SI_REG_UNUSED_63        0x0000003f

/*
 *  si_0outbuf struct
 */
#define SI_0OUTBUF_OUTPUT1_SIZE 8
#define SI_0OUTBUF_OUTPUT1_SHIFT        0
#define SI_0OUTBUF_OUTPUT1_MASK 0x000000ff
#define SI_0OUTBUF_GET_OUTPUT1(si_0outbuf) \
        ((((unsigned long)(si_0outbuf)) & SI_0OUTBUF_OUTPUT1_MASK) >> SI_0OUTBUF_OUTPUT1_SHIFT)
#define SI_0OUTBUF_SET_OUTPUT1(si_0outbuf, output1) { \
        FDL_ASSERT(!((output1) & ~((1 << SI_0OUTBUF_OUTPUT1_SIZE)-1))); \
        si_0outbuf = (((unsigned long)(si_0outbuf)) & ~SI_0OUTBUF_OUTPUT1_MASK) | (((unsigned long)(output1)) << SI_0OUTBUF_OUTPUT1_SHIFT);\
}
#define SI_0OUTBUF_OUTPUT0_SIZE 8
#define SI_0OUTBUF_OUTPUT0_SHIFT        8
#define SI_0OUTBUF_OUTPUT0_MASK 0x0000ff00
#define SI_0OUTBUF_GET_OUTPUT0(si_0outbuf) \
        ((((unsigned long)(si_0outbuf)) & SI_0OUTBUF_OUTPUT0_MASK) >> SI_0OUTBUF_OUTPUT0_SHIFT)
#define SI_0OUTBUF_SET_OUTPUT0(si_0outbuf, output0) { \
        FDL_ASSERT(!((output0) & ~((1 << SI_0OUTBUF_OUTPUT0_SIZE)-1))); \
        si_0outbuf = (((unsigned long)(si_0outbuf)) & ~SI_0OUTBUF_OUTPUT0_MASK) | (((unsigned long)(output0)) << SI_0OUTBUF_OUTPUT0_SHIFT);\
}
#define SI_0OUTBUF_CMD_SIZE     8
#define SI_0OUTBUF_CMD_SHIFT    16
#define SI_0OUTBUF_CMD_MASK     0x00ff0000
#define SI_0OUTBUF_GET_CMD(si_0outbuf) \
        ((((unsigned long)(si_0outbuf)) & SI_0OUTBUF_CMD_MASK) >> SI_0OUTBUF_CMD_SHIFT)
#define SI_0OUTBUF_SET_CMD(si_0outbuf, cmd) { \
        FDL_ASSERT(!((cmd) & ~((1 << SI_0OUTBUF_CMD_SIZE)-1))); \
        si_0outbuf = (((unsigned long)(si_0outbuf)) & ~SI_0OUTBUF_CMD_MASK) | (((unsigned long)(cmd)) << SI_0OUTBUF_CMD_SHIFT);\
}
#define SI_0OUTBUF_PAD0_SIZE    8
#define SI_0OUTBUF_PAD0_SHIFT   24
#define SI_0OUTBUF_PAD0_MASK    0xff000000
#define SI_0OUTBUF_GET_PAD0(si_0outbuf) \
        ((((unsigned long)(si_0outbuf)) & SI_0OUTBUF_PAD0_MASK) >> SI_0OUTBUF_PAD0_SHIFT)
#define SI_0OUTBUF_SET_PAD0(si_0outbuf, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_0OUTBUF_PAD0_SIZE)-1))); \
        si_0outbuf = (((unsigned long)(si_0outbuf)) & ~SI_0OUTBUF_PAD0_MASK) | (((unsigned long)(pad0)) << SI_0OUTBUF_PAD0_SHIFT);\
}
#define SI_0OUTBUF_TOTAL_SIZE   32
#define SI_0OUTBUF(output1, output0, cmd) \
        ((((unsigned long)(output1)) << SI_0OUTBUF_OUTPUT1_SHIFT) | \
         (((unsigned long)(output0)) << SI_0OUTBUF_OUTPUT0_SHIFT) | \
         (((unsigned long)(cmd)) << SI_0OUTBUF_CMD_SHIFT))

/*
 *  si_errlatch enum
 */
#define SI_ERRLATCH_NONE        0x00000000
#define SI_ERRLATCH_ERROR       0x00000001

/*
 *  si_errstat enum
 */
#define SI_ERRSTAT_NONE 0x00000000
#define SI_ERRSTAT_ERROR        0x00000001

/*
 *  si_0inbufh struct
 */
#define SI_0INBUFH_INPUT3_SIZE  8
#define SI_0INBUFH_INPUT3_SHIFT 0
#define SI_0INBUFH_INPUT3_MASK  0x000000ff
#define SI_0INBUFH_GET_INPUT3(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_INPUT3_MASK) >> SI_0INBUFH_INPUT3_SHIFT)
#define SI_0INBUFH_SET_INPUT3(si_0inbufh, input3) { \
        FDL_ASSERT(!((input3) & ~((1 << SI_0INBUFH_INPUT3_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_INPUT3_MASK) | (((unsigned long)(input3)) << SI_0INBUFH_INPUT3_SHIFT);\
}
#define SI_0INBUFH_INPUT2_SIZE  8
#define SI_0INBUFH_INPUT2_SHIFT 8
#define SI_0INBUFH_INPUT2_MASK  0x0000ff00
#define SI_0INBUFH_GET_INPUT2(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_INPUT2_MASK) >> SI_0INBUFH_INPUT2_SHIFT)
#define SI_0INBUFH_SET_INPUT2(si_0inbufh, input2) { \
        FDL_ASSERT(!((input2) & ~((1 << SI_0INBUFH_INPUT2_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_INPUT2_MASK) | (((unsigned long)(input2)) << SI_0INBUFH_INPUT2_SHIFT);\
}
#define SI_0INBUFH_INPUT1_SIZE  8
#define SI_0INBUFH_INPUT1_SHIFT 16
#define SI_0INBUFH_INPUT1_MASK  0x00ff0000
#define SI_0INBUFH_GET_INPUT1(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_INPUT1_MASK) >> SI_0INBUFH_INPUT1_SHIFT)
#define SI_0INBUFH_SET_INPUT1(si_0inbufh, input1) { \
        FDL_ASSERT(!((input1) & ~((1 << SI_0INBUFH_INPUT1_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_INPUT1_MASK) | (((unsigned long)(input1)) << SI_0INBUFH_INPUT1_SHIFT);\
}
#define SI_0INBUFH_INPUT0_SIZE  6
#define SI_0INBUFH_INPUT0_SHIFT 24
#define SI_0INBUFH_INPUT0_MASK  0x3f000000
#define SI_0INBUFH_GET_INPUT0(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_INPUT0_MASK) >> SI_0INBUFH_INPUT0_SHIFT)
#define SI_0INBUFH_SET_INPUT0(si_0inbufh, input0) { \
        FDL_ASSERT(!((input0) & ~((1 << SI_0INBUFH_INPUT0_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_INPUT0_MASK) | (((unsigned long)(input0)) << SI_0INBUFH_INPUT0_SHIFT);\
}
#define SI_0INBUFH_ERRLATCH_SIZE        1
#define SI_0INBUFH_ERRLATCH_SHIFT       30
#define SI_0INBUFH_ERRLATCH_MASK        0x40000000
#define SI_0INBUFH_GET_ERRLATCH(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_ERRLATCH_MASK) >> SI_0INBUFH_ERRLATCH_SHIFT)
#define SI_0INBUFH_SET_ERRLATCH(si_0inbufh, errlatch) { \
        FDL_ASSERT(!((errlatch) & ~((1 << SI_0INBUFH_ERRLATCH_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_ERRLATCH_MASK) | (((unsigned long)(errlatch)) << SI_0INBUFH_ERRLATCH_SHIFT);\
}
#define SI_0INBUFH_ERRSTAT_SIZE 1
#define SI_0INBUFH_ERRSTAT_SHIFT        31
#define SI_0INBUFH_ERRSTAT_MASK 0x80000000
#define SI_0INBUFH_GET_ERRSTAT(si_0inbufh) \
        ((((unsigned long)(si_0inbufh)) & SI_0INBUFH_ERRSTAT_MASK) >> SI_0INBUFH_ERRSTAT_SHIFT)
#define SI_0INBUFH_SET_ERRSTAT(si_0inbufh, errstat) { \
        FDL_ASSERT(!((errstat) & ~((1 << SI_0INBUFH_ERRSTAT_SIZE)-1))); \
        si_0inbufh = (((unsigned long)(si_0inbufh)) & ~SI_0INBUFH_ERRSTAT_MASK) | (((unsigned long)(errstat)) << SI_0INBUFH_ERRSTAT_SHIFT);\
}
#define SI_0INBUFH_TOTAL_SIZE   32
#define SI_0INBUFH(input3, input2, input1, input0, errlatch, errstat) \
        ((((unsigned long)(input3)) << SI_0INBUFH_INPUT3_SHIFT) | \
         (((unsigned long)(input2)) << SI_0INBUFH_INPUT2_SHIFT) | \
         (((unsigned long)(input1)) << SI_0INBUFH_INPUT1_SHIFT) | \
         (((unsigned long)(input0)) << SI_0INBUFH_INPUT0_SHIFT) | \
         (((unsigned long)(errlatch)) << SI_0INBUFH_ERRLATCH_SHIFT) | \
         (((unsigned long)(errstat)) << SI_0INBUFH_ERRSTAT_SHIFT))

/*
 *  si_0inbufl struct
 */
#define SI_0INBUFL_INPUT7_SIZE  8
#define SI_0INBUFL_INPUT7_SHIFT 0
#define SI_0INBUFL_INPUT7_MASK  0x000000ff
#define SI_0INBUFL_GET_INPUT7(si_0inbufl) \
        ((((unsigned long)(si_0inbufl)) & SI_0INBUFL_INPUT7_MASK) >> SI_0INBUFL_INPUT7_SHIFT)
#define SI_0INBUFL_SET_INPUT7(si_0inbufl, input7) { \
        FDL_ASSERT(!((input7) & ~((1 << SI_0INBUFL_INPUT7_SIZE)-1))); \
        si_0inbufl = (((unsigned long)(si_0inbufl)) & ~SI_0INBUFL_INPUT7_MASK) | (((unsigned long)(input7)) << SI_0INBUFL_INPUT7_SHIFT);\
}
#define SI_0INBUFL_INPUT6_SIZE  8
#define SI_0INBUFL_INPUT6_SHIFT 8
#define SI_0INBUFL_INPUT6_MASK  0x0000ff00
#define SI_0INBUFL_GET_INPUT6(si_0inbufl) \
        ((((unsigned long)(si_0inbufl)) & SI_0INBUFL_INPUT6_MASK) >> SI_0INBUFL_INPUT6_SHIFT)
#define SI_0INBUFL_SET_INPUT6(si_0inbufl, input6) { \
        FDL_ASSERT(!((input6) & ~((1 << SI_0INBUFL_INPUT6_SIZE)-1))); \
        si_0inbufl = (((unsigned long)(si_0inbufl)) & ~SI_0INBUFL_INPUT6_MASK) | (((unsigned long)(input6)) << SI_0INBUFL_INPUT6_SHIFT);\
}
#define SI_0INBUFL_INPUT5_SIZE  8
#define SI_0INBUFL_INPUT5_SHIFT 16
#define SI_0INBUFL_INPUT5_MASK  0x00ff0000
#define SI_0INBUFL_GET_INPUT5(si_0inbufl) \
        ((((unsigned long)(si_0inbufl)) & SI_0INBUFL_INPUT5_MASK) >> SI_0INBUFL_INPUT5_SHIFT)
#define SI_0INBUFL_SET_INPUT5(si_0inbufl, input5) { \
        FDL_ASSERT(!((input5) & ~((1 << SI_0INBUFL_INPUT5_SIZE)-1))); \
        si_0inbufl = (((unsigned long)(si_0inbufl)) & ~SI_0INBUFL_INPUT5_MASK) | (((unsigned long)(input5)) << SI_0INBUFL_INPUT5_SHIFT);\
}
#define SI_0INBUFL_INPUT4_SIZE  8
#define SI_0INBUFL_INPUT4_SHIFT 24
#define SI_0INBUFL_INPUT4_MASK  0xff000000
#define SI_0INBUFL_GET_INPUT4(si_0inbufl) \
        ((((unsigned long)(si_0inbufl)) & SI_0INBUFL_INPUT4_MASK) >> SI_0INBUFL_INPUT4_SHIFT)
#define SI_0INBUFL_SET_INPUT4(si_0inbufl, input4) { \
        FDL_ASSERT(!((input4) & ~((1 << SI_0INBUFL_INPUT4_SIZE)-1))); \
        si_0inbufl = (((unsigned long)(si_0inbufl)) & ~SI_0INBUFL_INPUT4_MASK) | (((unsigned long)(input4)) << SI_0INBUFL_INPUT4_SHIFT);\
}
#define SI_0INBUFL_TOTAL_SIZE   32
#define SI_0INBUFL(input7, input6, input5, input4) \
        ((((unsigned long)(input7)) << SI_0INBUFL_INPUT7_SHIFT) | \
         (((unsigned long)(input6)) << SI_0INBUFL_INPUT6_SHIFT) | \
         (((unsigned long)(input5)) << SI_0INBUFL_INPUT5_SHIFT) | \
         (((unsigned long)(input4)) << SI_0INBUFL_INPUT4_SHIFT))

/*
 *  si_1outbuf struct
 */
#define SI_1OUTBUF_OUTPUT1_SIZE 8
#define SI_1OUTBUF_OUTPUT1_SHIFT        0
#define SI_1OUTBUF_OUTPUT1_MASK 0x000000ff
#define SI_1OUTBUF_GET_OUTPUT1(si_1outbuf) \
        ((((unsigned long)(si_1outbuf)) & SI_1OUTBUF_OUTPUT1_MASK) >> SI_1OUTBUF_OUTPUT1_SHIFT)
#define SI_1OUTBUF_SET_OUTPUT1(si_1outbuf, output1) { \
        FDL_ASSERT(!((output1) & ~((1 << SI_1OUTBUF_OUTPUT1_SIZE)-1))); \
        si_1outbuf = (((unsigned long)(si_1outbuf)) & ~SI_1OUTBUF_OUTPUT1_MASK) | (((unsigned long)(output1)) << SI_1OUTBUF_OUTPUT1_SHIFT);\
}
#define SI_1OUTBUF_OUTPUT0_SIZE 8
#define SI_1OUTBUF_OUTPUT0_SHIFT        8
#define SI_1OUTBUF_OUTPUT0_MASK 0x0000ff00
#define SI_1OUTBUF_GET_OUTPUT0(si_1outbuf) \
        ((((unsigned long)(si_1outbuf)) & SI_1OUTBUF_OUTPUT0_MASK) >> SI_1OUTBUF_OUTPUT0_SHIFT)
#define SI_1OUTBUF_SET_OUTPUT0(si_1outbuf, output0) { \
        FDL_ASSERT(!((output0) & ~((1 << SI_1OUTBUF_OUTPUT0_SIZE)-1))); \
        si_1outbuf = (((unsigned long)(si_1outbuf)) & ~SI_1OUTBUF_OUTPUT0_MASK) | (((unsigned long)(output0)) << SI_1OUTBUF_OUTPUT0_SHIFT);\
}
#define SI_1OUTBUF_CMD_SIZE     8
#define SI_1OUTBUF_CMD_SHIFT    16
#define SI_1OUTBUF_CMD_MASK     0x00ff0000
#define SI_1OUTBUF_GET_CMD(si_1outbuf) \
        ((((unsigned long)(si_1outbuf)) & SI_1OUTBUF_CMD_MASK) >> SI_1OUTBUF_CMD_SHIFT)
#define SI_1OUTBUF_SET_CMD(si_1outbuf, cmd) { \
        FDL_ASSERT(!((cmd) & ~((1 << SI_1OUTBUF_CMD_SIZE)-1))); \
        si_1outbuf = (((unsigned long)(si_1outbuf)) & ~SI_1OUTBUF_CMD_MASK) | (((unsigned long)(cmd)) << SI_1OUTBUF_CMD_SHIFT);\
}
#define SI_1OUTBUF_PAD0_SIZE    8
#define SI_1OUTBUF_PAD0_SHIFT   24
#define SI_1OUTBUF_PAD0_MASK    0xff000000
#define SI_1OUTBUF_GET_PAD0(si_1outbuf) \
        ((((unsigned long)(si_1outbuf)) & SI_1OUTBUF_PAD0_MASK) >> SI_1OUTBUF_PAD0_SHIFT)
#define SI_1OUTBUF_SET_PAD0(si_1outbuf, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_1OUTBUF_PAD0_SIZE)-1))); \
        si_1outbuf = (((unsigned long)(si_1outbuf)) & ~SI_1OUTBUF_PAD0_MASK) | (((unsigned long)(pad0)) << SI_1OUTBUF_PAD0_SHIFT);\
}
#define SI_1OUTBUF_TOTAL_SIZE   32
#define SI_1OUTBUF(output1, output0, cmd) \
        ((((unsigned long)(output1)) << SI_1OUTBUF_OUTPUT1_SHIFT) | \
         (((unsigned long)(output0)) << SI_1OUTBUF_OUTPUT0_SHIFT) | \
         (((unsigned long)(cmd)) << SI_1OUTBUF_CMD_SHIFT))

/*
 *  si_1inbufh struct
 */
#define SI_1INBUFH_INPUT3_SIZE  8
#define SI_1INBUFH_INPUT3_SHIFT 0
#define SI_1INBUFH_INPUT3_MASK  0x000000ff
#define SI_1INBUFH_GET_INPUT3(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_INPUT3_MASK) >> SI_1INBUFH_INPUT3_SHIFT)
#define SI_1INBUFH_SET_INPUT3(si_1inbufh, input3) { \
        FDL_ASSERT(!((input3) & ~((1 << SI_1INBUFH_INPUT3_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_INPUT3_MASK) | (((unsigned long)(input3)) << SI_1INBUFH_INPUT3_SHIFT);\
}
#define SI_1INBUFH_INPUT2_SIZE  8
#define SI_1INBUFH_INPUT2_SHIFT 8
#define SI_1INBUFH_INPUT2_MASK  0x0000ff00
#define SI_1INBUFH_GET_INPUT2(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_INPUT2_MASK) >> SI_1INBUFH_INPUT2_SHIFT)
#define SI_1INBUFH_SET_INPUT2(si_1inbufh, input2) { \
        FDL_ASSERT(!((input2) & ~((1 << SI_1INBUFH_INPUT2_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_INPUT2_MASK) | (((unsigned long)(input2)) << SI_1INBUFH_INPUT2_SHIFT);\
}
#define SI_1INBUFH_INPUT1_SIZE  8
#define SI_1INBUFH_INPUT1_SHIFT 16
#define SI_1INBUFH_INPUT1_MASK  0x00ff0000
#define SI_1INBUFH_GET_INPUT1(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_INPUT1_MASK) >> SI_1INBUFH_INPUT1_SHIFT)
#define SI_1INBUFH_SET_INPUT1(si_1inbufh, input1) { \
        FDL_ASSERT(!((input1) & ~((1 << SI_1INBUFH_INPUT1_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_INPUT1_MASK) | (((unsigned long)(input1)) << SI_1INBUFH_INPUT1_SHIFT);\
}
#define SI_1INBUFH_INPUT0_SIZE  6
#define SI_1INBUFH_INPUT0_SHIFT 24
#define SI_1INBUFH_INPUT0_MASK  0x3f000000
#define SI_1INBUFH_GET_INPUT0(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_INPUT0_MASK) >> SI_1INBUFH_INPUT0_SHIFT)
#define SI_1INBUFH_SET_INPUT0(si_1inbufh, input0) { \
        FDL_ASSERT(!((input0) & ~((1 << SI_1INBUFH_INPUT0_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_INPUT0_MASK) | (((unsigned long)(input0)) << SI_1INBUFH_INPUT0_SHIFT);\
}
#define SI_1INBUFH_ERRLATCH_SIZE        1
#define SI_1INBUFH_ERRLATCH_SHIFT       30
#define SI_1INBUFH_ERRLATCH_MASK        0x40000000
#define SI_1INBUFH_GET_ERRLATCH(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_ERRLATCH_MASK) >> SI_1INBUFH_ERRLATCH_SHIFT)
#define SI_1INBUFH_SET_ERRLATCH(si_1inbufh, errlatch) { \
        FDL_ASSERT(!((errlatch) & ~((1 << SI_1INBUFH_ERRLATCH_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_ERRLATCH_MASK) | (((unsigned long)(errlatch)) << SI_1INBUFH_ERRLATCH_SHIFT);\
}
#define SI_1INBUFH_ERRSTAT_SIZE 1
#define SI_1INBUFH_ERRSTAT_SHIFT        31
#define SI_1INBUFH_ERRSTAT_MASK 0x80000000
#define SI_1INBUFH_GET_ERRSTAT(si_1inbufh) \
        ((((unsigned long)(si_1inbufh)) & SI_1INBUFH_ERRSTAT_MASK) >> SI_1INBUFH_ERRSTAT_SHIFT)
#define SI_1INBUFH_SET_ERRSTAT(si_1inbufh, errstat) { \
        FDL_ASSERT(!((errstat) & ~((1 << SI_1INBUFH_ERRSTAT_SIZE)-1))); \
        si_1inbufh = (((unsigned long)(si_1inbufh)) & ~SI_1INBUFH_ERRSTAT_MASK) | (((unsigned long)(errstat)) << SI_1INBUFH_ERRSTAT_SHIFT);\
}
#define SI_1INBUFH_TOTAL_SIZE   32
#define SI_1INBUFH(input3, input2, input1, input0, errlatch, errstat) \
        ((((unsigned long)(input3)) << SI_1INBUFH_INPUT3_SHIFT) | \
         (((unsigned long)(input2)) << SI_1INBUFH_INPUT2_SHIFT) | \
         (((unsigned long)(input1)) << SI_1INBUFH_INPUT1_SHIFT) | \
         (((unsigned long)(input0)) << SI_1INBUFH_INPUT0_SHIFT) | \
         (((unsigned long)(errlatch)) << SI_1INBUFH_ERRLATCH_SHIFT) | \
         (((unsigned long)(errstat)) << SI_1INBUFH_ERRSTAT_SHIFT))

/*
 *  si_1inbufl struct
 */
#define SI_1INBUFL_INPUT7_SIZE  8
#define SI_1INBUFL_INPUT7_SHIFT 0
#define SI_1INBUFL_INPUT7_MASK  0x000000ff
#define SI_1INBUFL_GET_INPUT7(si_1inbufl) \
        ((((unsigned long)(si_1inbufl)) & SI_1INBUFL_INPUT7_MASK) >> SI_1INBUFL_INPUT7_SHIFT)
#define SI_1INBUFL_SET_INPUT7(si_1inbufl, input7) { \
        FDL_ASSERT(!((input7) & ~((1 << SI_1INBUFL_INPUT7_SIZE)-1))); \
        si_1inbufl = (((unsigned long)(si_1inbufl)) & ~SI_1INBUFL_INPUT7_MASK) | (((unsigned long)(input7)) << SI_1INBUFL_INPUT7_SHIFT);\
}
#define SI_1INBUFL_INPUT6_SIZE  8
#define SI_1INBUFL_INPUT6_SHIFT 8
#define SI_1INBUFL_INPUT6_MASK  0x0000ff00
#define SI_1INBUFL_GET_INPUT6(si_1inbufl) \
        ((((unsigned long)(si_1inbufl)) & SI_1INBUFL_INPUT6_MASK) >> SI_1INBUFL_INPUT6_SHIFT)
#define SI_1INBUFL_SET_INPUT6(si_1inbufl, input6) { \
        FDL_ASSERT(!((input6) & ~((1 << SI_1INBUFL_INPUT6_SIZE)-1))); \
        si_1inbufl = (((unsigned long)(si_1inbufl)) & ~SI_1INBUFL_INPUT6_MASK) | (((unsigned long)(input6)) << SI_1INBUFL_INPUT6_SHIFT);\
}
#define SI_1INBUFL_INPUT5_SIZE  8
#define SI_1INBUFL_INPUT5_SHIFT 16
#define SI_1INBUFL_INPUT5_MASK  0x00ff0000
#define SI_1INBUFL_GET_INPUT5(si_1inbufl) \
        ((((unsigned long)(si_1inbufl)) & SI_1INBUFL_INPUT5_MASK) >> SI_1INBUFL_INPUT5_SHIFT)
#define SI_1INBUFL_SET_INPUT5(si_1inbufl, input5) { \
        FDL_ASSERT(!((input5) & ~((1 << SI_1INBUFL_INPUT5_SIZE)-1))); \
        si_1inbufl = (((unsigned long)(si_1inbufl)) & ~SI_1INBUFL_INPUT5_MASK) | (((unsigned long)(input5)) << SI_1INBUFL_INPUT5_SHIFT);\
}
#define SI_1INBUFL_INPUT4_SIZE  8
#define SI_1INBUFL_INPUT4_SHIFT 24
#define SI_1INBUFL_INPUT4_MASK  0xff000000
#define SI_1INBUFL_GET_INPUT4(si_1inbufl) \
        ((((unsigned long)(si_1inbufl)) & SI_1INBUFL_INPUT4_MASK) >> SI_1INBUFL_INPUT4_SHIFT)
#define SI_1INBUFL_SET_INPUT4(si_1inbufl, input4) { \
        FDL_ASSERT(!((input4) & ~((1 << SI_1INBUFL_INPUT4_SIZE)-1))); \
        si_1inbufl = (((unsigned long)(si_1inbufl)) & ~SI_1INBUFL_INPUT4_MASK) | (((unsigned long)(input4)) << SI_1INBUFL_INPUT4_SHIFT);\
}
#define SI_1INBUFL_TOTAL_SIZE   32
#define SI_1INBUFL(input7, input6, input5, input4) \
        ((((unsigned long)(input7)) << SI_1INBUFL_INPUT7_SHIFT) | \
         (((unsigned long)(input6)) << SI_1INBUFL_INPUT6_SHIFT) | \
         (((unsigned long)(input5)) << SI_1INBUFL_INPUT5_SHIFT) | \
         (((unsigned long)(input4)) << SI_1INBUFL_INPUT4_SHIFT))

/*
 *  si_2outbuf struct
 */
#define SI_2OUTBUF_OUTPUT1_SIZE 8
#define SI_2OUTBUF_OUTPUT1_SHIFT        0
#define SI_2OUTBUF_OUTPUT1_MASK 0x000000ff
#define SI_2OUTBUF_GET_OUTPUT1(si_2outbuf) \
        ((((unsigned long)(si_2outbuf)) & SI_2OUTBUF_OUTPUT1_MASK) >> SI_2OUTBUF_OUTPUT1_SHIFT)
#define SI_2OUTBUF_SET_OUTPUT1(si_2outbuf, output1) { \
        FDL_ASSERT(!((output1) & ~((1 << SI_2OUTBUF_OUTPUT1_SIZE)-1))); \
        si_2outbuf = (((unsigned long)(si_2outbuf)) & ~SI_2OUTBUF_OUTPUT1_MASK) | (((unsigned long)(output1)) << SI_2OUTBUF_OUTPUT1_SHIFT);\
}
#define SI_2OUTBUF_OUTPUT0_SIZE 8
#define SI_2OUTBUF_OUTPUT0_SHIFT        8
#define SI_2OUTBUF_OUTPUT0_MASK 0x0000ff00
#define SI_2OUTBUF_GET_OUTPUT0(si_2outbuf) \
        ((((unsigned long)(si_2outbuf)) & SI_2OUTBUF_OUTPUT0_MASK) >> SI_2OUTBUF_OUTPUT0_SHIFT)
#define SI_2OUTBUF_SET_OUTPUT0(si_2outbuf, output0) { \
        FDL_ASSERT(!((output0) & ~((1 << SI_2OUTBUF_OUTPUT0_SIZE)-1))); \
        si_2outbuf = (((unsigned long)(si_2outbuf)) & ~SI_2OUTBUF_OUTPUT0_MASK) | (((unsigned long)(output0)) << SI_2OUTBUF_OUTPUT0_SHIFT);\
}
#define SI_2OUTBUF_CMD_SIZE     8
#define SI_2OUTBUF_CMD_SHIFT    16
#define SI_2OUTBUF_CMD_MASK     0x00ff0000
#define SI_2OUTBUF_GET_CMD(si_2outbuf) \
        ((((unsigned long)(si_2outbuf)) & SI_2OUTBUF_CMD_MASK) >> SI_2OUTBUF_CMD_SHIFT)
#define SI_2OUTBUF_SET_CMD(si_2outbuf, cmd) { \
        FDL_ASSERT(!((cmd) & ~((1 << SI_2OUTBUF_CMD_SIZE)-1))); \
        si_2outbuf = (((unsigned long)(si_2outbuf)) & ~SI_2OUTBUF_CMD_MASK) | (((unsigned long)(cmd)) << SI_2OUTBUF_CMD_SHIFT);\
}
#define SI_2OUTBUF_PAD0_SIZE    8
#define SI_2OUTBUF_PAD0_SHIFT   24
#define SI_2OUTBUF_PAD0_MASK    0xff000000
#define SI_2OUTBUF_GET_PAD0(si_2outbuf) \
        ((((unsigned long)(si_2outbuf)) & SI_2OUTBUF_PAD0_MASK) >> SI_2OUTBUF_PAD0_SHIFT)
#define SI_2OUTBUF_SET_PAD0(si_2outbuf, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_2OUTBUF_PAD0_SIZE)-1))); \
        si_2outbuf = (((unsigned long)(si_2outbuf)) & ~SI_2OUTBUF_PAD0_MASK) | (((unsigned long)(pad0)) << SI_2OUTBUF_PAD0_SHIFT);\
}
#define SI_2OUTBUF_TOTAL_SIZE   32
#define SI_2OUTBUF(output1, output0, cmd) \
        ((((unsigned long)(output1)) << SI_2OUTBUF_OUTPUT1_SHIFT) | \
         (((unsigned long)(output0)) << SI_2OUTBUF_OUTPUT0_SHIFT) | \
         (((unsigned long)(cmd)) << SI_2OUTBUF_CMD_SHIFT))

/*
 *  si_2inbufh struct
 */
#define SI_2INBUFH_INPUT3_SIZE  8
#define SI_2INBUFH_INPUT3_SHIFT 0
#define SI_2INBUFH_INPUT3_MASK  0x000000ff
#define SI_2INBUFH_GET_INPUT3(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_INPUT3_MASK) >> SI_2INBUFH_INPUT3_SHIFT)
#define SI_2INBUFH_SET_INPUT3(si_2inbufh, input3) { \
        FDL_ASSERT(!((input3) & ~((1 << SI_2INBUFH_INPUT3_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_INPUT3_MASK) | (((unsigned long)(input3)) << SI_2INBUFH_INPUT3_SHIFT);\
}
#define SI_2INBUFH_INPUT2_SIZE  8
#define SI_2INBUFH_INPUT2_SHIFT 8
#define SI_2INBUFH_INPUT2_MASK  0x0000ff00
#define SI_2INBUFH_GET_INPUT2(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_INPUT2_MASK) >> SI_2INBUFH_INPUT2_SHIFT)
#define SI_2INBUFH_SET_INPUT2(si_2inbufh, input2) { \
        FDL_ASSERT(!((input2) & ~((1 << SI_2INBUFH_INPUT2_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_INPUT2_MASK) | (((unsigned long)(input2)) << SI_2INBUFH_INPUT2_SHIFT);\
}
#define SI_2INBUFH_INPUT1_SIZE  8
#define SI_2INBUFH_INPUT1_SHIFT 16
#define SI_2INBUFH_INPUT1_MASK  0x00ff0000
#define SI_2INBUFH_GET_INPUT1(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_INPUT1_MASK) >> SI_2INBUFH_INPUT1_SHIFT)
#define SI_2INBUFH_SET_INPUT1(si_2inbufh, input1) { \
        FDL_ASSERT(!((input1) & ~((1 << SI_2INBUFH_INPUT1_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_INPUT1_MASK) | (((unsigned long)(input1)) << SI_2INBUFH_INPUT1_SHIFT);\
}
#define SI_2INBUFH_INPUT0_SIZE  6
#define SI_2INBUFH_INPUT0_SHIFT 24
#define SI_2INBUFH_INPUT0_MASK  0x3f000000
#define SI_2INBUFH_GET_INPUT0(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_INPUT0_MASK) >> SI_2INBUFH_INPUT0_SHIFT)
#define SI_2INBUFH_SET_INPUT0(si_2inbufh, input0) { \
        FDL_ASSERT(!((input0) & ~((1 << SI_2INBUFH_INPUT0_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_INPUT0_MASK) | (((unsigned long)(input0)) << SI_2INBUFH_INPUT0_SHIFT);\
}
#define SI_2INBUFH_ERRLATCH_SIZE        1
#define SI_2INBUFH_ERRLATCH_SHIFT       30
#define SI_2INBUFH_ERRLATCH_MASK        0x40000000
#define SI_2INBUFH_GET_ERRLATCH(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_ERRLATCH_MASK) >> SI_2INBUFH_ERRLATCH_SHIFT)
#define SI_2INBUFH_SET_ERRLATCH(si_2inbufh, errlatch) { \
        FDL_ASSERT(!((errlatch) & ~((1 << SI_2INBUFH_ERRLATCH_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_ERRLATCH_MASK) | (((unsigned long)(errlatch)) << SI_2INBUFH_ERRLATCH_SHIFT);\
}
#define SI_2INBUFH_ERRSTAT_SIZE 1
#define SI_2INBUFH_ERRSTAT_SHIFT        31
#define SI_2INBUFH_ERRSTAT_MASK 0x80000000
#define SI_2INBUFH_GET_ERRSTAT(si_2inbufh) \
        ((((unsigned long)(si_2inbufh)) & SI_2INBUFH_ERRSTAT_MASK) >> SI_2INBUFH_ERRSTAT_SHIFT)
#define SI_2INBUFH_SET_ERRSTAT(si_2inbufh, errstat) { \
        FDL_ASSERT(!((errstat) & ~((1 << SI_2INBUFH_ERRSTAT_SIZE)-1))); \
        si_2inbufh = (((unsigned long)(si_2inbufh)) & ~SI_2INBUFH_ERRSTAT_MASK) | (((unsigned long)(errstat)) << SI_2INBUFH_ERRSTAT_SHIFT);\
}
#define SI_2INBUFH_TOTAL_SIZE   32
#define SI_2INBUFH(input3, input2, input1, input0, errlatch, errstat) \
        ((((unsigned long)(input3)) << SI_2INBUFH_INPUT3_SHIFT) | \
         (((unsigned long)(input2)) << SI_2INBUFH_INPUT2_SHIFT) | \
         (((unsigned long)(input1)) << SI_2INBUFH_INPUT1_SHIFT) | \
         (((unsigned long)(input0)) << SI_2INBUFH_INPUT0_SHIFT) | \
         (((unsigned long)(errlatch)) << SI_2INBUFH_ERRLATCH_SHIFT) | \
         (((unsigned long)(errstat)) << SI_2INBUFH_ERRSTAT_SHIFT))

/*
 *  si_2inbufl struct
 */
#define SI_2INBUFL_INPUT7_SIZE  8
#define SI_2INBUFL_INPUT7_SHIFT 0
#define SI_2INBUFL_INPUT7_MASK  0x000000ff
#define SI_2INBUFL_GET_INPUT7(si_2inbufl) \
        ((((unsigned long)(si_2inbufl)) & SI_2INBUFL_INPUT7_MASK) >> SI_2INBUFL_INPUT7_SHIFT)
#define SI_2INBUFL_SET_INPUT7(si_2inbufl, input7) { \
        FDL_ASSERT(!((input7) & ~((1 << SI_2INBUFL_INPUT7_SIZE)-1))); \
        si_2inbufl = (((unsigned long)(si_2inbufl)) & ~SI_2INBUFL_INPUT7_MASK) | (((unsigned long)(input7)) << SI_2INBUFL_INPUT7_SHIFT);\
}
#define SI_2INBUFL_INPUT6_SIZE  8
#define SI_2INBUFL_INPUT6_SHIFT 8
#define SI_2INBUFL_INPUT6_MASK  0x0000ff00
#define SI_2INBUFL_GET_INPUT6(si_2inbufl) \
        ((((unsigned long)(si_2inbufl)) & SI_2INBUFL_INPUT6_MASK) >> SI_2INBUFL_INPUT6_SHIFT)
#define SI_2INBUFL_SET_INPUT6(si_2inbufl, input6) { \
        FDL_ASSERT(!((input6) & ~((1 << SI_2INBUFL_INPUT6_SIZE)-1))); \
        si_2inbufl = (((unsigned long)(si_2inbufl)) & ~SI_2INBUFL_INPUT6_MASK) | (((unsigned long)(input6)) << SI_2INBUFL_INPUT6_SHIFT);\
}
#define SI_2INBUFL_INPUT5_SIZE  8
#define SI_2INBUFL_INPUT5_SHIFT 16
#define SI_2INBUFL_INPUT5_MASK  0x00ff0000
#define SI_2INBUFL_GET_INPUT5(si_2inbufl) \
        ((((unsigned long)(si_2inbufl)) & SI_2INBUFL_INPUT5_MASK) >> SI_2INBUFL_INPUT5_SHIFT)
#define SI_2INBUFL_SET_INPUT5(si_2inbufl, input5) { \
        FDL_ASSERT(!((input5) & ~((1 << SI_2INBUFL_INPUT5_SIZE)-1))); \
        si_2inbufl = (((unsigned long)(si_2inbufl)) & ~SI_2INBUFL_INPUT5_MASK) | (((unsigned long)(input5)) << SI_2INBUFL_INPUT5_SHIFT);\
}
#define SI_2INBUFL_INPUT4_SIZE  8
#define SI_2INBUFL_INPUT4_SHIFT 24
#define SI_2INBUFL_INPUT4_MASK  0xff000000
#define SI_2INBUFL_GET_INPUT4(si_2inbufl) \
        ((((unsigned long)(si_2inbufl)) & SI_2INBUFL_INPUT4_MASK) >> SI_2INBUFL_INPUT4_SHIFT)
#define SI_2INBUFL_SET_INPUT4(si_2inbufl, input4) { \
        FDL_ASSERT(!((input4) & ~((1 << SI_2INBUFL_INPUT4_SIZE)-1))); \
        si_2inbufl = (((unsigned long)(si_2inbufl)) & ~SI_2INBUFL_INPUT4_MASK) | (((unsigned long)(input4)) << SI_2INBUFL_INPUT4_SHIFT);\
}
#define SI_2INBUFL_TOTAL_SIZE   32
#define SI_2INBUFL(input7, input6, input5, input4) \
        ((((unsigned long)(input7)) << SI_2INBUFL_INPUT7_SHIFT) | \
         (((unsigned long)(input6)) << SI_2INBUFL_INPUT6_SHIFT) | \
         (((unsigned long)(input5)) << SI_2INBUFL_INPUT5_SHIFT) | \
         (((unsigned long)(input4)) << SI_2INBUFL_INPUT4_SHIFT))

/*
 *  si_3outbuf struct
 */
#define SI_3OUTBUF_OUTPUT1_SIZE 8
#define SI_3OUTBUF_OUTPUT1_SHIFT        0
#define SI_3OUTBUF_OUTPUT1_MASK 0x000000ff
#define SI_3OUTBUF_GET_OUTPUT1(si_3outbuf) \
        ((((unsigned long)(si_3outbuf)) & SI_3OUTBUF_OUTPUT1_MASK) >> SI_3OUTBUF_OUTPUT1_SHIFT)
#define SI_3OUTBUF_SET_OUTPUT1(si_3outbuf, output1) { \
        FDL_ASSERT(!((output1) & ~((1 << SI_3OUTBUF_OUTPUT1_SIZE)-1))); \
        si_3outbuf = (((unsigned long)(si_3outbuf)) & ~SI_3OUTBUF_OUTPUT1_MASK) | (((unsigned long)(output1)) << SI_3OUTBUF_OUTPUT1_SHIFT);\
}
#define SI_3OUTBUF_OUTPUT0_SIZE 8
#define SI_3OUTBUF_OUTPUT0_SHIFT        8
#define SI_3OUTBUF_OUTPUT0_MASK 0x0000ff00
#define SI_3OUTBUF_GET_OUTPUT0(si_3outbuf) \
        ((((unsigned long)(si_3outbuf)) & SI_3OUTBUF_OUTPUT0_MASK) >> SI_3OUTBUF_OUTPUT0_SHIFT)
#define SI_3OUTBUF_SET_OUTPUT0(si_3outbuf, output0) { \
        FDL_ASSERT(!((output0) & ~((1 << SI_3OUTBUF_OUTPUT0_SIZE)-1))); \
        si_3outbuf = (((unsigned long)(si_3outbuf)) & ~SI_3OUTBUF_OUTPUT0_MASK) | (((unsigned long)(output0)) << SI_3OUTBUF_OUTPUT0_SHIFT);\
}
#define SI_3OUTBUF_CMD_SIZE     8
#define SI_3OUTBUF_CMD_SHIFT    16
#define SI_3OUTBUF_CMD_MASK     0x00ff0000
#define SI_3OUTBUF_GET_CMD(si_3outbuf) \
        ((((unsigned long)(si_3outbuf)) & SI_3OUTBUF_CMD_MASK) >> SI_3OUTBUF_CMD_SHIFT)
#define SI_3OUTBUF_SET_CMD(si_3outbuf, cmd) { \
        FDL_ASSERT(!((cmd) & ~((1 << SI_3OUTBUF_CMD_SIZE)-1))); \
        si_3outbuf = (((unsigned long)(si_3outbuf)) & ~SI_3OUTBUF_CMD_MASK) | (((unsigned long)(cmd)) << SI_3OUTBUF_CMD_SHIFT);\
}
#define SI_3OUTBUF_PAD0_SIZE    8
#define SI_3OUTBUF_PAD0_SHIFT   24
#define SI_3OUTBUF_PAD0_MASK    0xff000000
#define SI_3OUTBUF_GET_PAD0(si_3outbuf) \
        ((((unsigned long)(si_3outbuf)) & SI_3OUTBUF_PAD0_MASK) >> SI_3OUTBUF_PAD0_SHIFT)
#define SI_3OUTBUF_SET_PAD0(si_3outbuf, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_3OUTBUF_PAD0_SIZE)-1))); \
        si_3outbuf = (((unsigned long)(si_3outbuf)) & ~SI_3OUTBUF_PAD0_MASK) | (((unsigned long)(pad0)) << SI_3OUTBUF_PAD0_SHIFT);\
}
#define SI_3OUTBUF_TOTAL_SIZE   32
#define SI_3OUTBUF(output1, output0, cmd) \
        ((((unsigned long)(output1)) << SI_3OUTBUF_OUTPUT1_SHIFT) | \
         (((unsigned long)(output0)) << SI_3OUTBUF_OUTPUT0_SHIFT) | \
         (((unsigned long)(cmd)) << SI_3OUTBUF_CMD_SHIFT))

/*
 *  si_3inbufh struct
 */
#define SI_3INBUFH_INPUT3_SIZE  8
#define SI_3INBUFH_INPUT3_SHIFT 0
#define SI_3INBUFH_INPUT3_MASK  0x000000ff
#define SI_3INBUFH_GET_INPUT3(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_INPUT3_MASK) >> SI_3INBUFH_INPUT3_SHIFT)
#define SI_3INBUFH_SET_INPUT3(si_3inbufh, input3) { \
        FDL_ASSERT(!((input3) & ~((1 << SI_3INBUFH_INPUT3_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_INPUT3_MASK) | (((unsigned long)(input3)) << SI_3INBUFH_INPUT3_SHIFT);\
}
#define SI_3INBUFH_INPUT2_SIZE  8
#define SI_3INBUFH_INPUT2_SHIFT 8
#define SI_3INBUFH_INPUT2_MASK  0x0000ff00
#define SI_3INBUFH_GET_INPUT2(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_INPUT2_MASK) >> SI_3INBUFH_INPUT2_SHIFT)
#define SI_3INBUFH_SET_INPUT2(si_3inbufh, input2) { \
        FDL_ASSERT(!((input2) & ~((1 << SI_3INBUFH_INPUT2_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_INPUT2_MASK) | (((unsigned long)(input2)) << SI_3INBUFH_INPUT2_SHIFT);\
}
#define SI_3INBUFH_INPUT1_SIZE  8
#define SI_3INBUFH_INPUT1_SHIFT 16
#define SI_3INBUFH_INPUT1_MASK  0x00ff0000
#define SI_3INBUFH_GET_INPUT1(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_INPUT1_MASK) >> SI_3INBUFH_INPUT1_SHIFT)
#define SI_3INBUFH_SET_INPUT1(si_3inbufh, input1) { \
        FDL_ASSERT(!((input1) & ~((1 << SI_3INBUFH_INPUT1_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_INPUT1_MASK) | (((unsigned long)(input1)) << SI_3INBUFH_INPUT1_SHIFT);\
}
#define SI_3INBUFH_INPUT0_SIZE  6
#define SI_3INBUFH_INPUT0_SHIFT 24
#define SI_3INBUFH_INPUT0_MASK  0x3f000000
#define SI_3INBUFH_GET_INPUT0(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_INPUT0_MASK) >> SI_3INBUFH_INPUT0_SHIFT)
#define SI_3INBUFH_SET_INPUT0(si_3inbufh, input0) { \
        FDL_ASSERT(!((input0) & ~((1 << SI_3INBUFH_INPUT0_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_INPUT0_MASK) | (((unsigned long)(input0)) << SI_3INBUFH_INPUT0_SHIFT);\
}
#define SI_3INBUFH_ERRLATCH_SIZE        1
#define SI_3INBUFH_ERRLATCH_SHIFT       30
#define SI_3INBUFH_ERRLATCH_MASK        0x40000000
#define SI_3INBUFH_GET_ERRLATCH(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_ERRLATCH_MASK) >> SI_3INBUFH_ERRLATCH_SHIFT)
#define SI_3INBUFH_SET_ERRLATCH(si_3inbufh, errlatch) { \
        FDL_ASSERT(!((errlatch) & ~((1 << SI_3INBUFH_ERRLATCH_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_ERRLATCH_MASK) | (((unsigned long)(errlatch)) << SI_3INBUFH_ERRLATCH_SHIFT);\
}
#define SI_3INBUFH_ERRSTAT_SIZE 1
#define SI_3INBUFH_ERRSTAT_SHIFT        31
#define SI_3INBUFH_ERRSTAT_MASK 0x80000000
#define SI_3INBUFH_GET_ERRSTAT(si_3inbufh) \
        ((((unsigned long)(si_3inbufh)) & SI_3INBUFH_ERRSTAT_MASK) >> SI_3INBUFH_ERRSTAT_SHIFT)
#define SI_3INBUFH_SET_ERRSTAT(si_3inbufh, errstat) { \
        FDL_ASSERT(!((errstat) & ~((1 << SI_3INBUFH_ERRSTAT_SIZE)-1))); \
        si_3inbufh = (((unsigned long)(si_3inbufh)) & ~SI_3INBUFH_ERRSTAT_MASK) | (((unsigned long)(errstat)) << SI_3INBUFH_ERRSTAT_SHIFT);\
}
#define SI_3INBUFH_TOTAL_SIZE   32
#define SI_3INBUFH(input3, input2, input1, input0, errlatch, errstat) \
        ((((unsigned long)(input3)) << SI_3INBUFH_INPUT3_SHIFT) | \
         (((unsigned long)(input2)) << SI_3INBUFH_INPUT2_SHIFT) | \
         (((unsigned long)(input1)) << SI_3INBUFH_INPUT1_SHIFT) | \
         (((unsigned long)(input0)) << SI_3INBUFH_INPUT0_SHIFT) | \
         (((unsigned long)(errlatch)) << SI_3INBUFH_ERRLATCH_SHIFT) | \
         (((unsigned long)(errstat)) << SI_3INBUFH_ERRSTAT_SHIFT))

/*
 *  si_3inbufl struct
 */
#define SI_3INBUFL_INPUT7_SIZE  8
#define SI_3INBUFL_INPUT7_SHIFT 0
#define SI_3INBUFL_INPUT7_MASK  0x000000ff
#define SI_3INBUFL_GET_INPUT7(si_3inbufl) \
        ((((unsigned long)(si_3inbufl)) & SI_3INBUFL_INPUT7_MASK) >> SI_3INBUFL_INPUT7_SHIFT)
#define SI_3INBUFL_SET_INPUT7(si_3inbufl, input7) { \
        FDL_ASSERT(!((input7) & ~((1 << SI_3INBUFL_INPUT7_SIZE)-1))); \
        si_3inbufl = (((unsigned long)(si_3inbufl)) & ~SI_3INBUFL_INPUT7_MASK) | (((unsigned long)(input7)) << SI_3INBUFL_INPUT7_SHIFT);\
}
#define SI_3INBUFL_INPUT6_SIZE  8
#define SI_3INBUFL_INPUT6_SHIFT 8
#define SI_3INBUFL_INPUT6_MASK  0x0000ff00
#define SI_3INBUFL_GET_INPUT6(si_3inbufl) \
        ((((unsigned long)(si_3inbufl)) & SI_3INBUFL_INPUT6_MASK) >> SI_3INBUFL_INPUT6_SHIFT)
#define SI_3INBUFL_SET_INPUT6(si_3inbufl, input6) { \
        FDL_ASSERT(!((input6) & ~((1 << SI_3INBUFL_INPUT6_SIZE)-1))); \
        si_3inbufl = (((unsigned long)(si_3inbufl)) & ~SI_3INBUFL_INPUT6_MASK) | (((unsigned long)(input6)) << SI_3INBUFL_INPUT6_SHIFT);\
}
#define SI_3INBUFL_INPUT5_SIZE  8
#define SI_3INBUFL_INPUT5_SHIFT 16
#define SI_3INBUFL_INPUT5_MASK  0x00ff0000
#define SI_3INBUFL_GET_INPUT5(si_3inbufl) \
        ((((unsigned long)(si_3inbufl)) & SI_3INBUFL_INPUT5_MASK) >> SI_3INBUFL_INPUT5_SHIFT)
#define SI_3INBUFL_SET_INPUT5(si_3inbufl, input5) { \
        FDL_ASSERT(!((input5) & ~((1 << SI_3INBUFL_INPUT5_SIZE)-1))); \
        si_3inbufl = (((unsigned long)(si_3inbufl)) & ~SI_3INBUFL_INPUT5_MASK) | (((unsigned long)(input5)) << SI_3INBUFL_INPUT5_SHIFT);\
}
#define SI_3INBUFL_INPUT4_SIZE  8
#define SI_3INBUFL_INPUT4_SHIFT 24
#define SI_3INBUFL_INPUT4_MASK  0xff000000
#define SI_3INBUFL_GET_INPUT4(si_3inbufl) \
        ((((unsigned long)(si_3inbufl)) & SI_3INBUFL_INPUT4_MASK) >> SI_3INBUFL_INPUT4_SHIFT)
#define SI_3INBUFL_SET_INPUT4(si_3inbufl, input4) { \
        FDL_ASSERT(!((input4) & ~((1 << SI_3INBUFL_INPUT4_SIZE)-1))); \
        si_3inbufl = (((unsigned long)(si_3inbufl)) & ~SI_3INBUFL_INPUT4_MASK) | (((unsigned long)(input4)) << SI_3INBUFL_INPUT4_SHIFT);\
}
#define SI_3INBUFL_TOTAL_SIZE   32
#define SI_3INBUFL(input7, input6, input5, input4) \
        ((((unsigned long)(input7)) << SI_3INBUFL_INPUT7_SHIFT) | \
         (((unsigned long)(input6)) << SI_3INBUFL_INPUT6_SHIFT) | \
         (((unsigned long)(input5)) << SI_3INBUFL_INPUT5_SHIFT) | \
         (((unsigned long)(input4)) << SI_3INBUFL_INPUT4_SHIFT))

/*
 *  si_vbcpy enum
 */
#define SI_VBCPY_DISABLE        0x00000000
#define SI_VBCPY_ENABLE 0x00000001

/*
 *  si_en enum
 */
#define SI_EN_DISABLE   0x00000000
#define SI_EN_ENABLE    0x00000001

/*
 *  si_poll struct
 */
#define SI_POLL_VBCPY3_SIZE     1
#define SI_POLL_VBCPY3_SHIFT    0
#define SI_POLL_VBCPY3_MASK     0x00000001
#define SI_POLL_GET_VBCPY3(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_VBCPY3_MASK) >> SI_POLL_VBCPY3_SHIFT)
#define SI_POLL_SET_VBCPY3(si_poll, vbcpy3) { \
        FDL_ASSERT(!((vbcpy3) & ~((1 << SI_POLL_VBCPY3_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_VBCPY3_MASK) | (((unsigned long)(vbcpy3)) << SI_POLL_VBCPY3_SHIFT);\
}
#define SI_POLL_VBCPY2_SIZE     1
#define SI_POLL_VBCPY2_SHIFT    1
#define SI_POLL_VBCPY2_MASK     0x00000002
#define SI_POLL_GET_VBCPY2(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_VBCPY2_MASK) >> SI_POLL_VBCPY2_SHIFT)
#define SI_POLL_SET_VBCPY2(si_poll, vbcpy2) { \
        FDL_ASSERT(!((vbcpy2) & ~((1 << SI_POLL_VBCPY2_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_VBCPY2_MASK) | (((unsigned long)(vbcpy2)) << SI_POLL_VBCPY2_SHIFT);\
}
#define SI_POLL_VBCPY1_SIZE     1
#define SI_POLL_VBCPY1_SHIFT    2
#define SI_POLL_VBCPY1_MASK     0x00000004
#define SI_POLL_GET_VBCPY1(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_VBCPY1_MASK) >> SI_POLL_VBCPY1_SHIFT)
#define SI_POLL_SET_VBCPY1(si_poll, vbcpy1) { \
        FDL_ASSERT(!((vbcpy1) & ~((1 << SI_POLL_VBCPY1_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_VBCPY1_MASK) | (((unsigned long)(vbcpy1)) << SI_POLL_VBCPY1_SHIFT);\
}
#define SI_POLL_VBCPY0_SIZE     1
#define SI_POLL_VBCPY0_SHIFT    3
#define SI_POLL_VBCPY0_MASK     0x00000008
#define SI_POLL_GET_VBCPY0(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_VBCPY0_MASK) >> SI_POLL_VBCPY0_SHIFT)
#define SI_POLL_SET_VBCPY0(si_poll, vbcpy0) { \
        FDL_ASSERT(!((vbcpy0) & ~((1 << SI_POLL_VBCPY0_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_VBCPY0_MASK) | (((unsigned long)(vbcpy0)) << SI_POLL_VBCPY0_SHIFT);\
}
#define SI_POLL_EN3_SIZE        1
#define SI_POLL_EN3_SHIFT       4
#define SI_POLL_EN3_MASK        0x00000010
#define SI_POLL_GET_EN3(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_EN3_MASK) >> SI_POLL_EN3_SHIFT)
#define SI_POLL_SET_EN3(si_poll, en3) { \
        FDL_ASSERT(!((en3) & ~((1 << SI_POLL_EN3_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_EN3_MASK) | (((unsigned long)(en3)) << SI_POLL_EN3_SHIFT);\
}
#define SI_POLL_EN2_SIZE        1
#define SI_POLL_EN2_SHIFT       5
#define SI_POLL_EN2_MASK        0x00000020
#define SI_POLL_GET_EN2(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_EN2_MASK) >> SI_POLL_EN2_SHIFT)
#define SI_POLL_SET_EN2(si_poll, en2) { \
        FDL_ASSERT(!((en2) & ~((1 << SI_POLL_EN2_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_EN2_MASK) | (((unsigned long)(en2)) << SI_POLL_EN2_SHIFT);\
}
#define SI_POLL_EN1_SIZE        1
#define SI_POLL_EN1_SHIFT       6
#define SI_POLL_EN1_MASK        0x00000040
#define SI_POLL_GET_EN1(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_EN1_MASK) >> SI_POLL_EN1_SHIFT)
#define SI_POLL_SET_EN1(si_poll, en1) { \
        FDL_ASSERT(!((en1) & ~((1 << SI_POLL_EN1_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_EN1_MASK) | (((unsigned long)(en1)) << SI_POLL_EN1_SHIFT);\
}
#define SI_POLL_EN0_SIZE        1
#define SI_POLL_EN0_SHIFT       7
#define SI_POLL_EN0_MASK        0x00000080
#define SI_POLL_GET_EN0(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_EN0_MASK) >> SI_POLL_EN0_SHIFT)
#define SI_POLL_SET_EN0(si_poll, en0) { \
        FDL_ASSERT(!((en0) & ~((1 << SI_POLL_EN0_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_EN0_MASK) | (((unsigned long)(en0)) << SI_POLL_EN0_SHIFT);\
}
#define SI_POLL_Y_SIZE  8
#define SI_POLL_Y_SHIFT 8
#define SI_POLL_Y_MASK  0x0000ff00
#define SI_POLL_GET_Y(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_Y_MASK) >> SI_POLL_Y_SHIFT)
#define SI_POLL_SET_Y(si_poll, y) { \
        FDL_ASSERT(!((y) & ~((1 << SI_POLL_Y_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_Y_MASK) | (((unsigned long)(y)) << SI_POLL_Y_SHIFT);\
}
#define SI_POLL_X_SIZE  10
#define SI_POLL_X_SHIFT 16
#define SI_POLL_X_MASK  0x03ff0000
#define SI_POLL_GET_X(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_X_MASK) >> SI_POLL_X_SHIFT)
#define SI_POLL_SET_X(si_poll, x) { \
        FDL_ASSERT(!((x) & ~((1 << SI_POLL_X_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_X_MASK) | (((unsigned long)(x)) << SI_POLL_X_SHIFT);\
}
#define SI_POLL_PAD0_SIZE       6
#define SI_POLL_PAD0_SHIFT      26
#define SI_POLL_PAD0_MASK       0xfc000000
#define SI_POLL_GET_PAD0(si_poll) \
        ((((unsigned long)(si_poll)) & SI_POLL_PAD0_MASK) >> SI_POLL_PAD0_SHIFT)
#define SI_POLL_SET_PAD0(si_poll, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_POLL_PAD0_SIZE)-1))); \
        si_poll = (((unsigned long)(si_poll)) & ~SI_POLL_PAD0_MASK) | (((unsigned long)(pad0)) << SI_POLL_PAD0_SHIFT);\
}
#define SI_POLL_TOTAL_SIZE      32
#define SI_POLL(vbcpy3, vbcpy2, vbcpy1, vbcpy0, en3, en2, en1, en0, y, x) \
        ((((unsigned long)(vbcpy3)) << SI_POLL_VBCPY3_SHIFT) | \
         (((unsigned long)(vbcpy2)) << SI_POLL_VBCPY2_SHIFT) | \
         (((unsigned long)(vbcpy1)) << SI_POLL_VBCPY1_SHIFT) | \
         (((unsigned long)(vbcpy0)) << SI_POLL_VBCPY0_SHIFT) | \
         (((unsigned long)(en3)) << SI_POLL_EN3_SHIFT) | \
         (((unsigned long)(en2)) << SI_POLL_EN2_SHIFT) | \
         (((unsigned long)(en1)) << SI_POLL_EN1_SHIFT) | \
         (((unsigned long)(en0)) << SI_POLL_EN0_SHIFT) | \
         (((unsigned long)(y)) << SI_POLL_Y_SHIFT) | \
         (((unsigned long)(x)) << SI_POLL_X_SHIFT))

/*
 *  si_channel enum
 */
#define SI_CHANNEL_0    0x00000000
#define SI_CHANNEL_1    0x00000001
#define SI_CHANNEL_2    0x00000002
#define SI_CHANNEL_3    0x00000003

/*
 *  si_comcsr struct
 */
#define SI_COMCSR_TSTART_SIZE   1
#define SI_COMCSR_TSTART_SHIFT  0
#define SI_COMCSR_TSTART_MASK   0x00000001
#define SI_COMCSR_GET_TSTART(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_TSTART_MASK) >> SI_COMCSR_TSTART_SHIFT)
#define SI_COMCSR_SET_TSTART(si_comcsr, tstart) { \
        FDL_ASSERT(!((tstart) & ~((1 << SI_COMCSR_TSTART_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_TSTART_MASK) | (((unsigned long)(tstart)) << SI_COMCSR_TSTART_SHIFT);\
}
#define SI_COMCSR_CHANNEL_SIZE  2
#define SI_COMCSR_CHANNEL_SHIFT 1
#define SI_COMCSR_CHANNEL_MASK  0x00000006
#define SI_COMCSR_GET_CHANNEL(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_CHANNEL_MASK) >> SI_COMCSR_CHANNEL_SHIFT)
#define SI_COMCSR_SET_CHANNEL(si_comcsr, channel) { \
        FDL_ASSERT(!((channel) & ~((1 << SI_COMCSR_CHANNEL_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_CHANNEL_MASK) | (((unsigned long)(channel)) << SI_COMCSR_CHANNEL_SHIFT);\
}
#define SI_COMCSR_PAD0_SIZE     5
#define SI_COMCSR_PAD0_SHIFT    3
#define SI_COMCSR_PAD0_MASK     0x000000f8
#define SI_COMCSR_GET_PAD0(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_PAD0_MASK) >> SI_COMCSR_PAD0_SHIFT)
#define SI_COMCSR_SET_PAD0(si_comcsr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_COMCSR_PAD0_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_PAD0_MASK) | (((unsigned long)(pad0)) << SI_COMCSR_PAD0_SHIFT);\
}
#define SI_COMCSR_INLNGTH_SIZE  7
#define SI_COMCSR_INLNGTH_SHIFT 8
#define SI_COMCSR_INLNGTH_MASK  0x00007f00
#define SI_COMCSR_GET_INLNGTH(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_INLNGTH_MASK) >> SI_COMCSR_INLNGTH_SHIFT)
#define SI_COMCSR_SET_INLNGTH(si_comcsr, inlngth) { \
        FDL_ASSERT(!((inlngth) & ~((1 << SI_COMCSR_INLNGTH_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_INLNGTH_MASK) | (((unsigned long)(inlngth)) << SI_COMCSR_INLNGTH_SHIFT);\
}
#define SI_COMCSR_PAD1_SIZE     1
#define SI_COMCSR_PAD1_SHIFT    15
#define SI_COMCSR_PAD1_MASK     0x00008000
#define SI_COMCSR_GET_PAD1(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_PAD1_MASK) >> SI_COMCSR_PAD1_SHIFT)
#define SI_COMCSR_SET_PAD1(si_comcsr, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << SI_COMCSR_PAD1_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_PAD1_MASK) | (((unsigned long)(pad1)) << SI_COMCSR_PAD1_SHIFT);\
}
#define SI_COMCSR_OUTLNGTH_SIZE 7
#define SI_COMCSR_OUTLNGTH_SHIFT        16
#define SI_COMCSR_OUTLNGTH_MASK 0x007f0000
#define SI_COMCSR_GET_OUTLNGTH(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_OUTLNGTH_MASK) >> SI_COMCSR_OUTLNGTH_SHIFT)
#define SI_COMCSR_SET_OUTLNGTH(si_comcsr, outlngth) { \
        FDL_ASSERT(!((outlngth) & ~((1 << SI_COMCSR_OUTLNGTH_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_OUTLNGTH_MASK) | (((unsigned long)(outlngth)) << SI_COMCSR_OUTLNGTH_SHIFT);\
}
#define SI_COMCSR_PAD2_SIZE     4
#define SI_COMCSR_PAD2_SHIFT    23
#define SI_COMCSR_PAD2_MASK     0x07800000
#define SI_COMCSR_GET_PAD2(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_PAD2_MASK) >> SI_COMCSR_PAD2_SHIFT)
#define SI_COMCSR_SET_PAD2(si_comcsr, pad2) { \
        FDL_ASSERT(!((pad2) & ~((1 << SI_COMCSR_PAD2_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_PAD2_MASK) | (((unsigned long)(pad2)) << SI_COMCSR_PAD2_SHIFT);\
}
#define SI_COMCSR_RDSTINTMSK_SIZE       1
#define SI_COMCSR_RDSTINTMSK_SHIFT      27
#define SI_COMCSR_RDSTINTMSK_MASK       0x08000000
#define SI_COMCSR_GET_RDSTINTMSK(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_RDSTINTMSK_MASK) >> SI_COMCSR_RDSTINTMSK_SHIFT)
#define SI_COMCSR_SET_RDSTINTMSK(si_comcsr, rdstintmsk) { \
        FDL_ASSERT(!((rdstintmsk) & ~((1 << SI_COMCSR_RDSTINTMSK_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_RDSTINTMSK_MASK) | (((unsigned long)(rdstintmsk)) << SI_COMCSR_RDSTINTMSK_SHIFT);\
}
#define SI_COMCSR_RDSTINT_SIZE  1
#define SI_COMCSR_RDSTINT_SHIFT 28
#define SI_COMCSR_RDSTINT_MASK  0x10000000
#define SI_COMCSR_GET_RDSTINT(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_RDSTINT_MASK) >> SI_COMCSR_RDSTINT_SHIFT)
#define SI_COMCSR_SET_RDSTINT(si_comcsr, rdstint) { \
        FDL_ASSERT(!((rdstint) & ~((1 << SI_COMCSR_RDSTINT_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_RDSTINT_MASK) | (((unsigned long)(rdstint)) << SI_COMCSR_RDSTINT_SHIFT);\
}
#define SI_COMCSR_COMERR_SIZE   1
#define SI_COMCSR_COMERR_SHIFT  29
#define SI_COMCSR_COMERR_MASK   0x20000000
#define SI_COMCSR_GET_COMERR(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_COMERR_MASK) >> SI_COMCSR_COMERR_SHIFT)
#define SI_COMCSR_SET_COMERR(si_comcsr, comerr) { \
        FDL_ASSERT(!((comerr) & ~((1 << SI_COMCSR_COMERR_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_COMERR_MASK) | (((unsigned long)(comerr)) << SI_COMCSR_COMERR_SHIFT);\
}
#define SI_COMCSR_TCINTMSK_SIZE 1
#define SI_COMCSR_TCINTMSK_SHIFT        30
#define SI_COMCSR_TCINTMSK_MASK 0x40000000
#define SI_COMCSR_GET_TCINTMSK(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_TCINTMSK_MASK) >> SI_COMCSR_TCINTMSK_SHIFT)
#define SI_COMCSR_SET_TCINTMSK(si_comcsr, tcintmsk) { \
        FDL_ASSERT(!((tcintmsk) & ~((1 << SI_COMCSR_TCINTMSK_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_TCINTMSK_MASK) | (((unsigned long)(tcintmsk)) << SI_COMCSR_TCINTMSK_SHIFT);\
}
#define SI_COMCSR_TCINT_SIZE    1
#define SI_COMCSR_TCINT_SHIFT   31
#define SI_COMCSR_TCINT_MASK    0x80000000
#define SI_COMCSR_GET_TCINT(si_comcsr) \
        ((((unsigned long)(si_comcsr)) & SI_COMCSR_TCINT_MASK) >> SI_COMCSR_TCINT_SHIFT)
#define SI_COMCSR_SET_TCINT(si_comcsr, tcint) { \
        FDL_ASSERT(!((tcint) & ~((1 << SI_COMCSR_TCINT_SIZE)-1))); \
        si_comcsr = (((unsigned long)(si_comcsr)) & ~SI_COMCSR_TCINT_MASK) | (((unsigned long)(tcint)) << SI_COMCSR_TCINT_SHIFT);\
}
#define SI_COMCSR_TOTAL_SIZE    32
#define SI_COMCSR(tstart, channel, inlngth, outlngth, rdstintmsk, rdstint, comerr, tcintmsk, tcint) \
        ((((unsigned long)(tstart)) << SI_COMCSR_TSTART_SHIFT) | \
         (((unsigned long)(channel)) << SI_COMCSR_CHANNEL_SHIFT) | \
         (((unsigned long)(inlngth)) << SI_COMCSR_INLNGTH_SHIFT) | \
         (((unsigned long)(outlngth)) << SI_COMCSR_OUTLNGTH_SHIFT) | \
         (((unsigned long)(rdstintmsk)) << SI_COMCSR_RDSTINTMSK_SHIFT) | \
         (((unsigned long)(rdstint)) << SI_COMCSR_RDSTINT_SHIFT) | \
         (((unsigned long)(comerr)) << SI_COMCSR_COMERR_SHIFT) | \
         (((unsigned long)(tcintmsk)) << SI_COMCSR_TCINTMSK_SHIFT) | \
         (((unsigned long)(tcint)) << SI_COMCSR_TCINT_SHIFT))

typedef struct {
    unsigned long tcint:SI_COMCSR_TCINT_SIZE;
    unsigned long tcintmsk:SI_COMCSR_TCINTMSK_SIZE;
    unsigned long comerr:SI_COMCSR_COMERR_SIZE;
    unsigned long rdstint:SI_COMCSR_RDSTINT_SIZE;
    unsigned long rdstintmsk:SI_COMCSR_RDSTINTMSK_SIZE;
    unsigned long pad2:SI_COMCSR_PAD2_SIZE;
    unsigned long outlngth:SI_COMCSR_OUTLNGTH_SIZE;
    unsigned long pad1:SI_COMCSR_PAD1_SIZE;
    unsigned long inlngth:SI_COMCSR_INLNGTH_SIZE;
    unsigned long pad0:SI_COMCSR_PAD0_SIZE;
    unsigned long channel:SI_COMCSR_CHANNEL_SIZE;
    unsigned long tstart:SI_COMCSR_TSTART_SIZE;
} si_comcsr_t;

typedef union {
    unsigned long val;
    si_comcsr_t f;
} si_comcsr_u;


/*
 *  si_error enum
 */
#define SI_ERROR_NONE   0x00000000
#define SI_ERROR_ERROR  0x00000001

/*
 *  si_wr enum
 */
#define SI_WR_DONE      0x00000000
#define SI_WR_WRITE     0x00000001

/*
 *  si_rd enum
 */
#define SI_RD_DONE      0x00000000
#define SI_RD_VALID     0x00000001

/*
 *  si_sr struct
 */
#define SI_SR_UNRUN3_SIZE       1
#define SI_SR_UNRUN3_SHIFT      0
#define SI_SR_UNRUN3_MASK       0x00000001
#define SI_SR_GET_UNRUN3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_UNRUN3_MASK) >> SI_SR_UNRUN3_SHIFT)
#define SI_SR_SET_UNRUN3(si_sr, unrun3) { \
        FDL_ASSERT(!((unrun3) & ~((1 << SI_SR_UNRUN3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_UNRUN3_MASK) | (((unsigned long)(unrun3)) << SI_SR_UNRUN3_SHIFT);\
}
#define SI_SR_OVRUN3_SIZE       1
#define SI_SR_OVRUN3_SHIFT      1
#define SI_SR_OVRUN3_MASK       0x00000002
#define SI_SR_GET_OVRUN3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_OVRUN3_MASK) >> SI_SR_OVRUN3_SHIFT)
#define SI_SR_SET_OVRUN3(si_sr, ovrun3) { \
        FDL_ASSERT(!((ovrun3) & ~((1 << SI_SR_OVRUN3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_OVRUN3_MASK) | (((unsigned long)(ovrun3)) << SI_SR_OVRUN3_SHIFT);\
}
#define SI_SR_COLL3_SIZE        1
#define SI_SR_COLL3_SHIFT       2
#define SI_SR_COLL3_MASK        0x00000004
#define SI_SR_GET_COLL3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_COLL3_MASK) >> SI_SR_COLL3_SHIFT)
#define SI_SR_SET_COLL3(si_sr, coll3) { \
        FDL_ASSERT(!((coll3) & ~((1 << SI_SR_COLL3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_COLL3_MASK) | (((unsigned long)(coll3)) << SI_SR_COLL3_SHIFT);\
}
#define SI_SR_NOREP3_SIZE       1
#define SI_SR_NOREP3_SHIFT      3
#define SI_SR_NOREP3_MASK       0x00000008
#define SI_SR_GET_NOREP3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_NOREP3_MASK) >> SI_SR_NOREP3_SHIFT)
#define SI_SR_SET_NOREP3(si_sr, norep3) { \
        FDL_ASSERT(!((norep3) & ~((1 << SI_SR_NOREP3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_NOREP3_MASK) | (((unsigned long)(norep3)) << SI_SR_NOREP3_SHIFT);\
}
#define SI_SR_WRST3_SIZE        1
#define SI_SR_WRST3_SHIFT       4
#define SI_SR_WRST3_MASK        0x00000010
#define SI_SR_GET_WRST3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_WRST3_MASK) >> SI_SR_WRST3_SHIFT)
#define SI_SR_SET_WRST3(si_sr, wrst3) { \
        FDL_ASSERT(!((wrst3) & ~((1 << SI_SR_WRST3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_WRST3_MASK) | (((unsigned long)(wrst3)) << SI_SR_WRST3_SHIFT);\
}
#define SI_SR_RDST3_SIZE        1
#define SI_SR_RDST3_SHIFT       5
#define SI_SR_RDST3_MASK        0x00000020
#define SI_SR_GET_RDST3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_RDST3_MASK) >> SI_SR_RDST3_SHIFT)
#define SI_SR_SET_RDST3(si_sr, rdst3) { \
        FDL_ASSERT(!((rdst3) & ~((1 << SI_SR_RDST3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_RDST3_MASK) | (((unsigned long)(rdst3)) << SI_SR_RDST3_SHIFT);\
}
#define SI_SR_PAD0_SIZE 2
#define SI_SR_PAD0_SHIFT        6
#define SI_SR_PAD0_MASK 0x000000c0
#define SI_SR_GET_PAD0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_PAD0_MASK) >> SI_SR_PAD0_SHIFT)
#define SI_SR_SET_PAD0(si_sr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_SR_PAD0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_PAD0_MASK) | (((unsigned long)(pad0)) << SI_SR_PAD0_SHIFT);\
}
#define SI_SR_UNRUN2_SIZE       1
#define SI_SR_UNRUN2_SHIFT      8
#define SI_SR_UNRUN2_MASK       0x00000100
#define SI_SR_GET_UNRUN2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_UNRUN2_MASK) >> SI_SR_UNRUN2_SHIFT)
#define SI_SR_SET_UNRUN2(si_sr, unrun2) { \
        FDL_ASSERT(!((unrun2) & ~((1 << SI_SR_UNRUN2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_UNRUN2_MASK) | (((unsigned long)(unrun2)) << SI_SR_UNRUN2_SHIFT);\
}
#define SI_SR_OVRUN2_SIZE       1
#define SI_SR_OVRUN2_SHIFT      9
#define SI_SR_OVRUN2_MASK       0x00000200
#define SI_SR_GET_OVRUN2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_OVRUN2_MASK) >> SI_SR_OVRUN2_SHIFT)
#define SI_SR_SET_OVRUN2(si_sr, ovrun2) { \
        FDL_ASSERT(!((ovrun2) & ~((1 << SI_SR_OVRUN2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_OVRUN2_MASK) | (((unsigned long)(ovrun2)) << SI_SR_OVRUN2_SHIFT);\
}
#define SI_SR_COLL2_SIZE        1
#define SI_SR_COLL2_SHIFT       10
#define SI_SR_COLL2_MASK        0x00000400
#define SI_SR_GET_COLL2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_COLL2_MASK) >> SI_SR_COLL2_SHIFT)
#define SI_SR_SET_COLL2(si_sr, coll2) { \
        FDL_ASSERT(!((coll2) & ~((1 << SI_SR_COLL2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_COLL2_MASK) | (((unsigned long)(coll2)) << SI_SR_COLL2_SHIFT);\
}
#define SI_SR_NOREP2_SIZE       1
#define SI_SR_NOREP2_SHIFT      11
#define SI_SR_NOREP2_MASK       0x00000800
#define SI_SR_GET_NOREP2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_NOREP2_MASK) >> SI_SR_NOREP2_SHIFT)
#define SI_SR_SET_NOREP2(si_sr, norep2) { \
        FDL_ASSERT(!((norep2) & ~((1 << SI_SR_NOREP2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_NOREP2_MASK) | (((unsigned long)(norep2)) << SI_SR_NOREP2_SHIFT);\
}
#define SI_SR_WRST2_SIZE        1
#define SI_SR_WRST2_SHIFT       12
#define SI_SR_WRST2_MASK        0x00001000
#define SI_SR_GET_WRST2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_WRST2_MASK) >> SI_SR_WRST2_SHIFT)
#define SI_SR_SET_WRST2(si_sr, wrst2) { \
        FDL_ASSERT(!((wrst2) & ~((1 << SI_SR_WRST2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_WRST2_MASK) | (((unsigned long)(wrst2)) << SI_SR_WRST2_SHIFT);\
}
#define SI_SR_RDST2_SIZE        1
#define SI_SR_RDST2_SHIFT       13
#define SI_SR_RDST2_MASK        0x00002000
#define SI_SR_GET_RDST2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_RDST2_MASK) >> SI_SR_RDST2_SHIFT)
#define SI_SR_SET_RDST2(si_sr, rdst2) { \
        FDL_ASSERT(!((rdst2) & ~((1 << SI_SR_RDST2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_RDST2_MASK) | (((unsigned long)(rdst2)) << SI_SR_RDST2_SHIFT);\
}
#define SI_SR_PAD1_SIZE 2
#define SI_SR_PAD1_SHIFT        14
#define SI_SR_PAD1_MASK 0x0000c000
#define SI_SR_GET_PAD1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_PAD1_MASK) >> SI_SR_PAD1_SHIFT)
#define SI_SR_SET_PAD1(si_sr, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << SI_SR_PAD1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_PAD1_MASK) | (((unsigned long)(pad1)) << SI_SR_PAD1_SHIFT);\
}
#define SI_SR_UNRUN1_SIZE       1
#define SI_SR_UNRUN1_SHIFT      16
#define SI_SR_UNRUN1_MASK       0x00010000
#define SI_SR_GET_UNRUN1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_UNRUN1_MASK) >> SI_SR_UNRUN1_SHIFT)
#define SI_SR_SET_UNRUN1(si_sr, unrun1) { \
        FDL_ASSERT(!((unrun1) & ~((1 << SI_SR_UNRUN1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_UNRUN1_MASK) | (((unsigned long)(unrun1)) << SI_SR_UNRUN1_SHIFT);\
}
#define SI_SR_OVRUN1_SIZE       1
#define SI_SR_OVRUN1_SHIFT      17
#define SI_SR_OVRUN1_MASK       0x00020000
#define SI_SR_GET_OVRUN1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_OVRUN1_MASK) >> SI_SR_OVRUN1_SHIFT)
#define SI_SR_SET_OVRUN1(si_sr, ovrun1) { \
        FDL_ASSERT(!((ovrun1) & ~((1 << SI_SR_OVRUN1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_OVRUN1_MASK) | (((unsigned long)(ovrun1)) << SI_SR_OVRUN1_SHIFT);\
}
#define SI_SR_COLL1_SIZE        1
#define SI_SR_COLL1_SHIFT       18
#define SI_SR_COLL1_MASK        0x00040000
#define SI_SR_GET_COLL1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_COLL1_MASK) >> SI_SR_COLL1_SHIFT)
#define SI_SR_SET_COLL1(si_sr, coll1) { \
        FDL_ASSERT(!((coll1) & ~((1 << SI_SR_COLL1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_COLL1_MASK) | (((unsigned long)(coll1)) << SI_SR_COLL1_SHIFT);\
}
#define SI_SR_NOREP1_SIZE       1
#define SI_SR_NOREP1_SHIFT      19
#define SI_SR_NOREP1_MASK       0x00080000
#define SI_SR_GET_NOREP1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_NOREP1_MASK) >> SI_SR_NOREP1_SHIFT)
#define SI_SR_SET_NOREP1(si_sr, norep1) { \
        FDL_ASSERT(!((norep1) & ~((1 << SI_SR_NOREP1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_NOREP1_MASK) | (((unsigned long)(norep1)) << SI_SR_NOREP1_SHIFT);\
}
#define SI_SR_WRST1_SIZE        1
#define SI_SR_WRST1_SHIFT       20
#define SI_SR_WRST1_MASK        0x00100000
#define SI_SR_GET_WRST1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_WRST1_MASK) >> SI_SR_WRST1_SHIFT)
#define SI_SR_SET_WRST1(si_sr, wrst1) { \
        FDL_ASSERT(!((wrst1) & ~((1 << SI_SR_WRST1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_WRST1_MASK) | (((unsigned long)(wrst1)) << SI_SR_WRST1_SHIFT);\
}
#define SI_SR_RDST1_SIZE        1
#define SI_SR_RDST1_SHIFT       21
#define SI_SR_RDST1_MASK        0x00200000
#define SI_SR_GET_RDST1(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_RDST1_MASK) >> SI_SR_RDST1_SHIFT)
#define SI_SR_SET_RDST1(si_sr, rdst1) { \
        FDL_ASSERT(!((rdst1) & ~((1 << SI_SR_RDST1_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_RDST1_MASK) | (((unsigned long)(rdst1)) << SI_SR_RDST1_SHIFT);\
}
#define SI_SR_PAD2_SIZE 2
#define SI_SR_PAD2_SHIFT        22
#define SI_SR_PAD2_MASK 0x00c00000
#define SI_SR_GET_PAD2(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_PAD2_MASK) >> SI_SR_PAD2_SHIFT)
#define SI_SR_SET_PAD2(si_sr, pad2) { \
        FDL_ASSERT(!((pad2) & ~((1 << SI_SR_PAD2_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_PAD2_MASK) | (((unsigned long)(pad2)) << SI_SR_PAD2_SHIFT);\
}
#define SI_SR_UNRUN0_SIZE       1
#define SI_SR_UNRUN0_SHIFT      24
#define SI_SR_UNRUN0_MASK       0x01000000
#define SI_SR_GET_UNRUN0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_UNRUN0_MASK) >> SI_SR_UNRUN0_SHIFT)
#define SI_SR_SET_UNRUN0(si_sr, unrun0) { \
        FDL_ASSERT(!((unrun0) & ~((1 << SI_SR_UNRUN0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_UNRUN0_MASK) | (((unsigned long)(unrun0)) << SI_SR_UNRUN0_SHIFT);\
}
#define SI_SR_OVRUN0_SIZE       1
#define SI_SR_OVRUN0_SHIFT      25
#define SI_SR_OVRUN0_MASK       0x02000000
#define SI_SR_GET_OVRUN0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_OVRUN0_MASK) >> SI_SR_OVRUN0_SHIFT)
#define SI_SR_SET_OVRUN0(si_sr, ovrun0) { \
        FDL_ASSERT(!((ovrun0) & ~((1 << SI_SR_OVRUN0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_OVRUN0_MASK) | (((unsigned long)(ovrun0)) << SI_SR_OVRUN0_SHIFT);\
}
#define SI_SR_COLL0_SIZE        1
#define SI_SR_COLL0_SHIFT       26
#define SI_SR_COLL0_MASK        0x04000000
#define SI_SR_GET_COLL0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_COLL0_MASK) >> SI_SR_COLL0_SHIFT)
#define SI_SR_SET_COLL0(si_sr, coll0) { \
        FDL_ASSERT(!((coll0) & ~((1 << SI_SR_COLL0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_COLL0_MASK) | (((unsigned long)(coll0)) << SI_SR_COLL0_SHIFT);\
}
#define SI_SR_NOREP0_SIZE       1
#define SI_SR_NOREP0_SHIFT      27
#define SI_SR_NOREP0_MASK       0x08000000
#define SI_SR_GET_NOREP0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_NOREP0_MASK) >> SI_SR_NOREP0_SHIFT)
#define SI_SR_SET_NOREP0(si_sr, norep0) { \
        FDL_ASSERT(!((norep0) & ~((1 << SI_SR_NOREP0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_NOREP0_MASK) | (((unsigned long)(norep0)) << SI_SR_NOREP0_SHIFT);\
}
#define SI_SR_WRST0_SIZE        1
#define SI_SR_WRST0_SHIFT       28
#define SI_SR_WRST0_MASK        0x10000000
#define SI_SR_GET_WRST0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_WRST0_MASK) >> SI_SR_WRST0_SHIFT)
#define SI_SR_SET_WRST0(si_sr, wrst0) { \
        FDL_ASSERT(!((wrst0) & ~((1 << SI_SR_WRST0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_WRST0_MASK) | (((unsigned long)(wrst0)) << SI_SR_WRST0_SHIFT);\
}
#define SI_SR_RDST0_SIZE        1
#define SI_SR_RDST0_SHIFT       29
#define SI_SR_RDST0_MASK        0x20000000
#define SI_SR_GET_RDST0(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_RDST0_MASK) >> SI_SR_RDST0_SHIFT)
#define SI_SR_SET_RDST0(si_sr, rdst0) { \
        FDL_ASSERT(!((rdst0) & ~((1 << SI_SR_RDST0_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_RDST0_MASK) | (((unsigned long)(rdst0)) << SI_SR_RDST0_SHIFT);\
}
#define SI_SR_PAD3_SIZE 1
#define SI_SR_PAD3_SHIFT        30
#define SI_SR_PAD3_MASK 0x40000000
#define SI_SR_GET_PAD3(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_PAD3_MASK) >> SI_SR_PAD3_SHIFT)
#define SI_SR_SET_PAD3(si_sr, pad3) { \
        FDL_ASSERT(!((pad3) & ~((1 << SI_SR_PAD3_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_PAD3_MASK) | (((unsigned long)(pad3)) << SI_SR_PAD3_SHIFT);\
}
#define SI_SR_WR_SIZE   1
#define SI_SR_WR_SHIFT  31
#define SI_SR_WR_MASK   0x80000000
#define SI_SR_GET_WR(si_sr) \
        ((((unsigned long)(si_sr)) & SI_SR_WR_MASK) >> SI_SR_WR_SHIFT)
#define SI_SR_SET_WR(si_sr, wr) { \
        FDL_ASSERT(!((wr) & ~((1 << SI_SR_WR_SIZE)-1))); \
        si_sr = (((unsigned long)(si_sr)) & ~SI_SR_WR_MASK) | (((unsigned long)(wr)) << SI_SR_WR_SHIFT);\
}
#define SI_SR_TOTAL_SIZE        32
#define SI_SR(unrun3, ovrun3, coll3, norep3, wrst3, rdst3, unrun2, ovrun2, coll2, norep2, wrst2, rdst2, unrun1, ovrun1, coll1, norep1, wrst1, rdst1, unrun0, ovrun0, coll0, norep0, wrst0, rdst0, wr) \
        ((((unsigned long)(unrun3)) << SI_SR_UNRUN3_SHIFT) | \
         (((unsigned long)(ovrun3)) << SI_SR_OVRUN3_SHIFT) | \
         (((unsigned long)(coll3)) << SI_SR_COLL3_SHIFT) | \
         (((unsigned long)(norep3)) << SI_SR_NOREP3_SHIFT) | \
         (((unsigned long)(wrst3)) << SI_SR_WRST3_SHIFT) | \
         (((unsigned long)(rdst3)) << SI_SR_RDST3_SHIFT) | \
         (((unsigned long)(unrun2)) << SI_SR_UNRUN2_SHIFT) | \
         (((unsigned long)(ovrun2)) << SI_SR_OVRUN2_SHIFT) | \
         (((unsigned long)(coll2)) << SI_SR_COLL2_SHIFT) | \
         (((unsigned long)(norep2)) << SI_SR_NOREP2_SHIFT) | \
         (((unsigned long)(wrst2)) << SI_SR_WRST2_SHIFT) | \
         (((unsigned long)(rdst2)) << SI_SR_RDST2_SHIFT) | \
         (((unsigned long)(unrun1)) << SI_SR_UNRUN1_SHIFT) | \
         (((unsigned long)(ovrun1)) << SI_SR_OVRUN1_SHIFT) | \
         (((unsigned long)(coll1)) << SI_SR_COLL1_SHIFT) | \
         (((unsigned long)(norep1)) << SI_SR_NOREP1_SHIFT) | \
         (((unsigned long)(wrst1)) << SI_SR_WRST1_SHIFT) | \
         (((unsigned long)(rdst1)) << SI_SR_RDST1_SHIFT) | \
         (((unsigned long)(unrun0)) << SI_SR_UNRUN0_SHIFT) | \
         (((unsigned long)(ovrun0)) << SI_SR_OVRUN0_SHIFT) | \
         (((unsigned long)(coll0)) << SI_SR_COLL0_SHIFT) | \
         (((unsigned long)(norep0)) << SI_SR_NOREP0_SHIFT) | \
         (((unsigned long)(wrst0)) << SI_SR_WRST0_SHIFT) | \
         (((unsigned long)(rdst0)) << SI_SR_RDST0_SHIFT) | \
         (((unsigned long)(wr)) << SI_SR_WR_SHIFT))

/*
 *  si_exilock enum
 */
#define SI_EXILK_UNLOCKED       0x00000000
#define SI_EXILK_LOCKED 0x00000001

/*
 *  si_exilk struct
 */
#define SI_EXILK_PAD0_SIZE      31
#define SI_EXILK_PAD0_SHIFT     0
#define SI_EXILK_PAD0_MASK      0x7fffffff
#define SI_EXILK_GET_PAD0(si_exilk) \
        ((((unsigned long)(si_exilk)) & SI_EXILK_PAD0_MASK) >> SI_EXILK_PAD0_SHIFT)
#define SI_EXILK_SET_PAD0(si_exilk, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_EXILK_PAD0_SIZE)-1))); \
        si_exilk = (((unsigned long)(si_exilk)) & ~SI_EXILK_PAD0_MASK) | (((unsigned long)(pad0)) << SI_EXILK_PAD0_SHIFT);\
}
#define SI_EXILK_LOCK_SIZE      1
#define SI_EXILK_LOCK_SHIFT     31
#define SI_EXILK_LOCK_MASK      0x80000000
#define SI_EXILK_GET_LOCK(si_exilk) \
        ((((unsigned long)(si_exilk)) & SI_EXILK_LOCK_MASK) >> SI_EXILK_LOCK_SHIFT)
#define SI_EXILK_SET_LOCK(si_exilk, lock) { \
        FDL_ASSERT(!((lock) & ~((1 << SI_EXILK_LOCK_SIZE)-1))); \
        si_exilk = (((unsigned long)(si_exilk)) & ~SI_EXILK_LOCK_MASK) | (((unsigned long)(lock)) << SI_EXILK_LOCK_SHIFT);\
}
#define SI_EXILK_TOTAL_SIZE     32
#define SI_EXILK(lock) \
        ((((unsigned long)(lock)) << SI_EXILK_LOCK_SHIFT))

/*
 *  si_dimsm struct
 */
#define SI_DIMSM_ENABLE_SIZE    1
#define SI_DIMSM_ENABLE_SHIFT   0
#define SI_DIMSM_ENABLE_MASK    0x00000001
#define SI_DIMSM_GET_ENABLE(si_dimsm) \
        ((((unsigned long)(si_dimsm)) & SI_DIMSM_ENABLE_MASK) >> SI_DIMSM_ENABLE_SHIFT)
#define SI_DIMSM_SET_ENABLE(si_dimsm, enable) { \
        FDL_ASSERT(!((enable) & ~((1 << SI_DIMSM_ENABLE_SIZE)-1))); \
        si_dimsm = (((unsigned long)(si_dimsm)) & ~SI_DIMSM_ENABLE_MASK) | (((unsigned long)(enable)) << SI_DIMSM_ENABLE_SHIFT);\
}
#define SI_DIMSM_PAD0_SIZE      31
#define SI_DIMSM_PAD0_SHIFT     1
#define SI_DIMSM_PAD0_MASK      0xfffffffe
#define SI_DIMSM_GET_PAD0(si_dimsm) \
        ((((unsigned long)(si_dimsm)) & SI_DIMSM_PAD0_MASK) >> SI_DIMSM_PAD0_SHIFT)
#define SI_DIMSM_SET_PAD0(si_dimsm, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_DIMSM_PAD0_SIZE)-1))); \
        si_dimsm = (((unsigned long)(si_dimsm)) & ~SI_DIMSM_PAD0_MASK) | (((unsigned long)(pad0)) << SI_DIMSM_PAD0_SHIFT);\
}
#define SI_DIMSM_TOTAL_SIZE     32
#define SI_DIMSM(enable) \
        ((((unsigned long)(enable)) << SI_DIMSM_ENABLE_SHIFT))

/*
 *  si_frmcnt struct
 */
#define SI_FRMCNT_COUNT_SIZE    16
#define SI_FRMCNT_COUNT_SHIFT   0
#define SI_FRMCNT_COUNT_MASK    0x0000ffff
#define SI_FRMCNT_GET_COUNT(si_frmcnt) \
        ((((unsigned long)(si_frmcnt)) & SI_FRMCNT_COUNT_MASK) >> SI_FRMCNT_COUNT_SHIFT)
#define SI_FRMCNT_SET_COUNT(si_frmcnt, count) { \
        FDL_ASSERT(!((count) & ~((1 << SI_FRMCNT_COUNT_SIZE)-1))); \
        si_frmcnt = (((unsigned long)(si_frmcnt)) & ~SI_FRMCNT_COUNT_MASK) | (((unsigned long)(count)) << SI_FRMCNT_COUNT_SHIFT);\
}
#define SI_FRMCNT_PAD0_SIZE     16
#define SI_FRMCNT_PAD0_SHIFT    16
#define SI_FRMCNT_PAD0_MASK     0xffff0000
#define SI_FRMCNT_GET_PAD0(si_frmcnt) \
        ((((unsigned long)(si_frmcnt)) & SI_FRMCNT_PAD0_MASK) >> SI_FRMCNT_PAD0_SHIFT)
#define SI_FRMCNT_SET_PAD0(si_frmcnt, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << SI_FRMCNT_PAD0_SIZE)-1))); \
        si_frmcnt = (((unsigned long)(si_frmcnt)) & ~SI_FRMCNT_PAD0_MASK) | (((unsigned long)(pad0)) << SI_FRMCNT_PAD0_SHIFT);\
}
#define SI_FRMCNT_TOTAL_SIZE    32
#define SI_FRMCNT(count) \
        ((((unsigned long)(count)) << SI_FRMCNT_COUNT_SHIFT))

/*
 *  ai_reg enum
 */
#define AI_CR_IDX       0x00000000
#define AI_VR_IDX       0x00000001
#define AI_SCNT_IDX     0x00000002
#define AI_IT_IDX       0x00000003
#define AI_REG_UNUSED_4 0x00000004
#define AI_REG_UNUSED_5 0x00000005
#define AI_REG_UNUSED_6 0x00000006
#define AI_REG_UNUSED_7 0x00000007

/*
 *  ai_pstat enum
 */
#define AI_PSTAT_STOP   0x00000000
#define AI_PSTAT_PLAY   0x00000001

/*
 *  ai_afr enum
 */
#define AI_AFR_32K      0x00000000
#define AI_AFR_48K      0x00000001

/*
 *  ai_scrst enum
 */
#define AI_SCRST_NONE   0x00000000
#define AI_SCRST_RESET  0x00000001

/*
 *  ai_intvld enum
 */
#define AI_INTVLD_VALID 0x00000000
#define AI_INTVLD_HOLD  0x00000001

/*
 *  ai_dsp32 enum
 */
#define AI_DSP32_OFF    0x00000000
#define AI_DSP32_ON     0x00000001

/*
 *  ai_dvdaudio enum
 */
#define AI_DVDAUDIO_OFF 0x00000000
#define AI_DVDAUDIO_ON  0x00000001

/*
 *  ai_cr struct
 */
#define AI_CR_PSTAT_SIZE        1
#define AI_CR_PSTAT_SHIFT       0
#define AI_CR_PSTAT_MASK        0x00000001
#define AI_CR_GET_PSTAT(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_PSTAT_MASK) >> AI_CR_PSTAT_SHIFT)
#define AI_CR_SET_PSTAT(ai_cr, pstat) { \
        FDL_ASSERT(!((pstat) & ~((1 << AI_CR_PSTAT_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_PSTAT_MASK) | (((unsigned long)(pstat)) << AI_CR_PSTAT_SHIFT);\
}
#define AI_CR_AFR_SIZE  1
#define AI_CR_AFR_SHIFT 1
#define AI_CR_AFR_MASK  0x00000002
#define AI_CR_GET_AFR(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_AFR_MASK) >> AI_CR_AFR_SHIFT)
#define AI_CR_SET_AFR(ai_cr, afr) { \
        FDL_ASSERT(!((afr) & ~((1 << AI_CR_AFR_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_AFR_MASK) | (((unsigned long)(afr)) << AI_CR_AFR_SHIFT);\
}
#define AI_CR_AIINTMSK_SIZE     1
#define AI_CR_AIINTMSK_SHIFT    2
#define AI_CR_AIINTMSK_MASK     0x00000004
#define AI_CR_GET_AIINTMSK(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_AIINTMSK_MASK) >> AI_CR_AIINTMSK_SHIFT)
#define AI_CR_SET_AIINTMSK(ai_cr, aiintmsk) { \
        FDL_ASSERT(!((aiintmsk) & ~((1 << AI_CR_AIINTMSK_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_AIINTMSK_MASK) | (((unsigned long)(aiintmsk)) << AI_CR_AIINTMSK_SHIFT);\
}
#define AI_CR_AIINT_SIZE        1
#define AI_CR_AIINT_SHIFT       3
#define AI_CR_AIINT_MASK        0x00000008
#define AI_CR_GET_AIINT(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_AIINT_MASK) >> AI_CR_AIINT_SHIFT)
#define AI_CR_SET_AIINT(ai_cr, aiint) { \
        FDL_ASSERT(!((aiint) & ~((1 << AI_CR_AIINT_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_AIINT_MASK) | (((unsigned long)(aiint)) << AI_CR_AIINT_SHIFT);\
}
#define AI_CR_AIINTVLD_SIZE     1
#define AI_CR_AIINTVLD_SHIFT    4
#define AI_CR_AIINTVLD_MASK     0x00000010
#define AI_CR_GET_AIINTVLD(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_AIINTVLD_MASK) >> AI_CR_AIINTVLD_SHIFT)
#define AI_CR_SET_AIINTVLD(ai_cr, aiintvld) { \
        FDL_ASSERT(!((aiintvld) & ~((1 << AI_CR_AIINTVLD_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_AIINTVLD_MASK) | (((unsigned long)(aiintvld)) << AI_CR_AIINTVLD_SHIFT);\
}
#define AI_CR_SCRST_SIZE        1
#define AI_CR_SCRST_SHIFT       5
#define AI_CR_SCRST_MASK        0x00000020
#define AI_CR_GET_SCRST(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_SCRST_MASK) >> AI_CR_SCRST_SHIFT)
#define AI_CR_SET_SCRST(ai_cr, scrst) { \
        FDL_ASSERT(!((scrst) & ~((1 << AI_CR_SCRST_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_SCRST_MASK) | (((unsigned long)(scrst)) << AI_CR_SCRST_SHIFT);\
}
#define AI_CR_DSP32_SIZE        1
#define AI_CR_DSP32_SHIFT       6
#define AI_CR_DSP32_MASK        0x00000040
#define AI_CR_GET_DSP32(ai_cr) \
        ((((unsigned long)(ai_cr)) & AI_CR_DSP32_MASK) >> AI_CR_DSP32_SHIFT)
#define AI_CR_SET_DSP32(ai_cr, dsp32) { \
        FDL_ASSERT(!((dsp32) & ~((1 << AI_CR_DSP32_SIZE)-1))); \
        ai_cr = (((unsigned long)(ai_cr)) & ~AI_CR_DSP32_MASK) | (((unsigned long)(dsp32)) << AI_CR_DSP32_SHIFT);\
}
#define AI_CR_TOTAL_SIZE        7
#define AI_CR_UNUSED_SIZE       25

#define AI_CR(pstat, afr, aiintmsk, aiint, aiintvld, scrst, dsp32) \
        ((((unsigned long)(pstat)) << AI_CR_PSTAT_SHIFT) | \
         (((unsigned long)(afr)) << AI_CR_AFR_SHIFT) | \
         (((unsigned long)(aiintmsk)) << AI_CR_AIINTMSK_SHIFT) | \
         (((unsigned long)(aiint)) << AI_CR_AIINT_SHIFT) | \
         (((unsigned long)(aiintvld)) << AI_CR_AIINTVLD_SHIFT) | \
         (((unsigned long)(scrst)) << AI_CR_SCRST_SHIFT) | \
         (((unsigned long)(dsp32)) << AI_CR_DSP32_SHIFT))

/*
 *  ai_vr struct
 */
#define AI_VR_AVRL_SIZE 8
#define AI_VR_AVRL_SHIFT        0
#define AI_VR_AVRL_MASK 0x000000ff
#define AI_VR_GET_AVRL(ai_vr) \
        ((((unsigned long)(ai_vr)) & AI_VR_AVRL_MASK) >> AI_VR_AVRL_SHIFT)
#define AI_VR_SET_AVRL(ai_vr, avrl) { \
        FDL_ASSERT(!((avrl) & ~((1 << AI_VR_AVRL_SIZE)-1))); \
        ai_vr = (((unsigned long)(ai_vr)) & ~AI_VR_AVRL_MASK) | (((unsigned long)(avrl)) << AI_VR_AVRL_SHIFT);\
}
#define AI_VR_AVRR_SIZE 8
#define AI_VR_AVRR_SHIFT        8
#define AI_VR_AVRR_MASK 0x0000ff00
#define AI_VR_GET_AVRR(ai_vr) \
        ((((unsigned long)(ai_vr)) & AI_VR_AVRR_MASK) >> AI_VR_AVRR_SHIFT)
#define AI_VR_SET_AVRR(ai_vr, avrr) { \
        FDL_ASSERT(!((avrr) & ~((1 << AI_VR_AVRR_SIZE)-1))); \
        ai_vr = (((unsigned long)(ai_vr)) & ~AI_VR_AVRR_MASK) | (((unsigned long)(avrr)) << AI_VR_AVRR_SHIFT);\
}
#define AI_VR_TOTAL_SIZE        16
#define AI_VR_UNUSED_SIZE       16

#define AI_VR(avrl, avrr) \
        ((((unsigned long)(avrl)) << AI_VR_AVRL_SHIFT) | \
         (((unsigned long)(avrr)) << AI_VR_AVRR_SHIFT))

/*
 *  ai_scnt struct
 */
#define AI_SCNT_AISCNT_SIZE     31
#define AI_SCNT_AISCNT_SHIFT    0
#define AI_SCNT_AISCNT_MASK     0x7fffffff
#define AI_SCNT_GET_AISCNT(ai_scnt) \
        ((((unsigned long)(ai_scnt)) & AI_SCNT_AISCNT_MASK) >> AI_SCNT_AISCNT_SHIFT)
#define AI_SCNT_SET_AISCNT(ai_scnt, aiscnt) { \
        FDL_ASSERT(!((aiscnt) & ~((1 << AI_SCNT_AISCNT_SIZE)-1))); \
        ai_scnt = (((unsigned long)(ai_scnt)) & ~AI_SCNT_AISCNT_MASK) | (((unsigned long)(aiscnt)) << AI_SCNT_AISCNT_SHIFT);\
}
#define AI_SCNT_TOTAL_SIZE      31
#define AI_SCNT_UNUSED_SIZE     1

#define AI_SCNT(aiscnt) \
        ((((unsigned long)(aiscnt)) << AI_SCNT_AISCNT_SHIFT))

/*
 *  ai_it struct
 */
#define AI_IT_AIIT_SIZE 31
#define AI_IT_AIIT_SHIFT        0
#define AI_IT_AIIT_MASK 0x7fffffff
#define AI_IT_GET_AIIT(ai_it) \
        ((((unsigned long)(ai_it)) & AI_IT_AIIT_MASK) >> AI_IT_AIIT_SHIFT)
#define AI_IT_SET_AIIT(ai_it, aiit) { \
        FDL_ASSERT(!((aiit) & ~((1 << AI_IT_AIIT_SIZE)-1))); \
        ai_it = (((unsigned long)(ai_it)) & ~AI_IT_AIIT_MASK) | (((unsigned long)(aiit)) << AI_IT_AIIT_SHIFT);\
}
#define AI_IT_DVDAUDIO_SIZE     1
#define AI_IT_DVDAUDIO_SHIFT    31
#define AI_IT_DVDAUDIO_MASK     0x80000000
#define AI_IT_GET_DVDAUDIO(ai_it) \
        ((((unsigned long)(ai_it)) & AI_IT_DVDAUDIO_MASK) >> AI_IT_DVDAUDIO_SHIFT)
#define AI_IT_SET_DVDAUDIO(ai_it, dvdaudio) { \
        FDL_ASSERT(!((dvdaudio) & ~((1 << AI_IT_DVDAUDIO_SIZE)-1))); \
        ai_it = (((unsigned long)(ai_it)) & ~AI_IT_DVDAUDIO_MASK) | (((unsigned long)(dvdaudio)) << AI_IT_DVDAUDIO_SHIFT);\
}
#define AI_IT_TOTAL_SIZE        32
#define AI_IT(aiit, dvdaudio) \
        ((((unsigned long)(aiit)) << AI_IT_AIIT_SHIFT) | \
         (((unsigned long)(dvdaudio)) << AI_IT_DVDAUDIO_SHIFT))

/*
 *  io_reg struct
 */
#define IO_REG_LO_SIZE  16
#define IO_REG_LO_SHIFT 0
#define IO_REG_LO_MASK  0x0000ffff
#define IO_REG_GET_LO(io_reg) \
        ((((unsigned long)(io_reg)) & IO_REG_LO_MASK) >> IO_REG_LO_SHIFT)
#define IO_REG_SET_LO(io_reg, lo) { \
        FDL_ASSERT(!((lo) & ~((1 << IO_REG_LO_SIZE)-1))); \
        io_reg = (((unsigned long)(io_reg)) & ~IO_REG_LO_MASK) | (((unsigned long)(lo)) << IO_REG_LO_SHIFT);\
}
#define IO_REG_HI_SIZE  16
#define IO_REG_HI_SHIFT 16
#define IO_REG_HI_MASK  0xffff0000
#define IO_REG_GET_HI(io_reg) \
        ((((unsigned long)(io_reg)) & IO_REG_HI_MASK) >> IO_REG_HI_SHIFT)
#define IO_REG_SET_HI(io_reg, hi) { \
        FDL_ASSERT(!((hi) & ~((1 << IO_REG_HI_SIZE)-1))); \
        io_reg = (((unsigned long)(io_reg)) & ~IO_REG_HI_MASK) | (((unsigned long)(hi)) << IO_REG_HI_SHIFT);\
}
#define IO_REG_TOTAL_SIZE       32
#define IO_REG(lo, hi) \
        ((((unsigned long)(lo)) << IO_REG_LO_SHIFT) | \
         (((unsigned long)(hi)) << IO_REG_HI_SHIFT))


#endif /* __FDL_IO_REG_H__ */
