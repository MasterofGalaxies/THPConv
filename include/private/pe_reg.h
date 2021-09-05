/*
 *  pe_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from ../../bw/fdl/pe_reg.fdl
 */

#ifndef __FDL_PE_REG_H__
#define __FDL_PE_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  pe_pixtype enum
 */
#define PE_PIXTYPE_RGB8 0x00000000
#define PE_PIXTYPE_RGBA6        0x00000001
#define PE_PIXTYPE_RGB_AA       0x00000002
#define PE_PIXTYPE_Z    0x00000003
#define PE_PIXTYPE_YUV8 0x00000004
#define PE_PIXTYPE_YUV_420      0x00000005
#define PE_PIXTYPE_UNUSED_6     0x00000006
#define PE_PIXTYPE_UNUSED_7     0x00000007

/*
 *  pe_sfactor enum
 */
#define PE_SFACTOR_ZERO 0x00000000
#define PE_SFACTOR_ONE  0x00000001
#define PE_SFACTOR_DST_COLOR    0x00000002
#define PE_SFACTOR_ONE_MINUS_DST_COLOR  0x00000003
#define PE_SFACTOR_SRC_ALPHA    0x00000004
#define PE_SFACTOR_ONE_MINUS_SRC_ALPHA  0x00000005
#define PE_SFACTOR_DST_ALPHA    0x00000006
#define PE_SFACTOR_ONE_MINUS_DST_ALPHA  0x00000007
#define PE_SFACTOR_SRC_ALPHA_SATURATE   0x00000008
#define PE_SFACTOR_UNUSED_9     0x00000009
#define PE_SFACTOR_UNUSED_10    0x0000000a
#define PE_SFACTOR_UNUSED_11    0x0000000b
#define PE_SFACTOR_UNUSED_12    0x0000000c
#define PE_SFACTOR_UNUSED_13    0x0000000d
#define PE_SFACTOR_UNUSED_14    0x0000000e
#define PE_SFACTOR_UNUSED_15    0x0000000f

/*
 *  pe_dfactor enum
 */
#define PE_DFACTOR_ZERO 0x00000000
#define PE_DFACTOR_ONE  0x00000001
#define PE_DFACTOR_SRC_COLOR    0x00000002
#define PE_DFACTOR_ONE_MINUS_SRC_COLOR  0x00000003
#define PE_DFACTOR_SRC_ALPHA    0x00000004
#define PE_DFACTOR_ONE_MINUS_SRC_ALPHA  0x00000005
#define PE_DFACTOR_DST_ALPHA    0x00000006
#define PE_DFACTOR_ONE_MINUS_DST_ALPHA  0x00000007

/*
 *  pe_blend_op enum
 */
#define PE_BLEND_ADD    0x00000000
#define PE_BLEND_SUB    0x00000001

/*
 *  pe_yuv enum
 */
#define PE_Y    0x00000000
#define PE_U    0x00000001
#define PE_V    0x00000002
#define PE_YUV_UNUSED_3 0x00000003

/*
 *  pe_enab enum
 */
#define PE_DISABLE      0x00000000
#define PE_ENABLE       0x00000001

/*
 *  pe_logicop enum
 */
#define PE_LOGICOP_CLEAR        0x00000000
#define PE_LOGICOP_AND  0x00000001
#define PE_LOGICOP_AND_REVERSE  0x00000002
#define PE_LOGICOP_COPY 0x00000003
#define PE_LOGICOP_AND_INVERTED 0x00000004
#define PE_LOGICOP_NOOP 0x00000005
#define PE_LOGICOP_XOR  0x00000006
#define PE_LOGICOP_OR   0x00000007
#define PE_LOGICOP_NOR  0x00000008
#define PE_LOGICOP_EQUIV        0x00000009
#define PE_LOGICOP_INVERT       0x0000000a
#define PE_LOGICOP_OR_REVERSE   0x0000000b
#define PE_LOGICOP_COPY_INVERTED        0x0000000c
#define PE_LOGICOP_OR_INVERTED  0x0000000d
#define PE_LOGICOP_NAND 0x0000000e
#define PE_LOGICOP_SET  0x0000000f

/*
 *  pe_zfunction enum
 */
#define PE_ZFUNCTION_NEVER      0x00000000
#define PE_ZFUNCTION_LESS       0x00000001
#define PE_ZFUNCTION_EQUAL      0x00000002
#define PE_ZFUNCTION_LESS_EQUAL 0x00000003
#define PE_ZFUNCTION_GREATER    0x00000004
#define PE_ZFUNCTION_NOT_EQUAL  0x00000005
#define PE_ZFUNCTION_GREATER_EQUAL      0x00000006
#define PE_ZFUNCTION_ALWAYS     0x00000007

/*
 *  pe_finish_dst enum
 */
#define PE_FINISH_DST_NONE      0x00000000
#define PE_FINISH_DST_CP        0x00000001
#define PE_FINISH_DST_RAS       0x00000002
#define PE_FINISH_DST_TX        0x00000003

/*
 *  pe_tex_format enum
 */
#define PE_TEX_FORMAT_I4        0x00000000
#define PE_TEX_FORMAT_I8        0x00000001
#define PE_TEX_FORMAT_IA4       0x00000002
#define PE_TEX_FORMAT_IA8       0x00000003
#define PE_TEX_FORMAT_R5G6B5    0x00000004
#define PE_TEX_FORMAT_RGB5A3    0x00000005
#define PE_TEX_FORMAT_RGBA8     0x00000006
#define PE_TEX_FORMAT_A8        0x00000007
#define PE_TEX_FORMAT_R8        0x00000008
#define PE_TEX_FORMAT_G8        0x00000009
#define PE_TEX_FORMAT_B8        0x0000000a
#define PE_TEX_FORMAT_RG8       0x0000000b
#define PE_TEX_FORMAT_GB8       0x0000000c
#define PE_TEX_FORMAT_UNUSED_13 0x0000000d
#define PE_TEX_FORMAT_UNUSED_14 0x0000000e
#define PE_TEX_FORMAT_UNUSED_15 0x0000000f

/*
 *  pe_gamma enum
 */
#define PE_GAMMA_10     0x00000000
#define PE_GAMMA_17     0x00000001
#define PE_GAMMA_22     0x00000002
#define PE_GAMMA_NONE   0x00000003

/*
 *  pe_cntr enum
 */
#define PE_CNTR_RST     0x00000000
#define PE_CNTR_OFF     0x00000001
#define PE_CNTR_ON      0x00000002
#define PE_CNTR_ALWAYS  0x00000003

/*
 *  pe_zcmode enum
 */
#define PE_ZCMODE_LINEAR        0x00000000
#define PE_ZCMODE_14E2  0x00000001
#define PE_ZCMODE_13E3  0x00000002
#define PE_ZCMODE_NONE  0x00000003
#define PE_ZCMODE_LINEAR_INV    0x00000004
#define PE_ZCMODE_14E2_INV      0x00000005
#define PE_ZCMODE_13E3_INV      0x00000006
#define PE_ZCMODE_UNUSED_7      0x00000007

/*
 *  pe_copy_cmd enum
 */
#define PE_COPY_CMD_TEXTURE     0x00000000
#define PE_COPY_CMD_DISPLAY     0x00000001

/*
 *  pe_interlaced enum
 */
#define PE_INTERLACED_OFF       0x00000000
#define PE_INTERLACED_UNUSED_1  0x00000001
#define PE_INTERLACED_EVEN      0x00000002
#define PE_INTERLACED_ODD       0x00000003

/*
 *  pe_ccv_mode enum
 */
#define PE_CCV_AUTO     0x00000000
#define PE_CCV_MODE_UNUSED_1    0x00000001
#define PE_CCV_OFF      0x00000002
#define PE_CCV_ON       0x00000003

/*
 *  pe_zmode struct
 */
#define PE_ZMODE_ENABLE_SIZE    1
#define PE_ZMODE_ENABLE_SHIFT   0
#define PE_ZMODE_ENABLE_MASK    0x00000001
#define PE_ZMODE_GET_ENABLE(pe_zmode) \
        ((((unsigned long)(pe_zmode)) & PE_ZMODE_ENABLE_MASK) >> PE_ZMODE_ENABLE_SHIFT)
#define PE_ZMODE_SET_ENABLE(pe_zmode, enable) { \
        FDL_ASSERT(!((enable) & ~((1 << PE_ZMODE_ENABLE_SIZE)-1))); \
        pe_zmode = (((unsigned long)(pe_zmode)) & ~PE_ZMODE_ENABLE_MASK) | (((unsigned long)(enable)) << PE_ZMODE_ENABLE_SHIFT);\
}
#define PE_ZMODE_FUNC_SIZE      3
#define PE_ZMODE_FUNC_SHIFT     1
#define PE_ZMODE_FUNC_MASK      0x0000000e
#define PE_ZMODE_GET_FUNC(pe_zmode) \
        ((((unsigned long)(pe_zmode)) & PE_ZMODE_FUNC_MASK) >> PE_ZMODE_FUNC_SHIFT)
#define PE_ZMODE_SET_FUNC(pe_zmode, func) { \
        FDL_ASSERT(!((func) & ~((1 << PE_ZMODE_FUNC_SIZE)-1))); \
        pe_zmode = (((unsigned long)(pe_zmode)) & ~PE_ZMODE_FUNC_MASK) | (((unsigned long)(func)) << PE_ZMODE_FUNC_SHIFT);\
}
#define PE_ZMODE_MASK_SIZE      1
#define PE_ZMODE_MASK_SHIFT     4
#define PE_ZMODE_MASK_MASK      0x00000010
#define PE_ZMODE_GET_MASK(pe_zmode) \
        ((((unsigned long)(pe_zmode)) & PE_ZMODE_MASK_MASK) >> PE_ZMODE_MASK_SHIFT)
#define PE_ZMODE_SET_MASK(pe_zmode, mask) { \
        FDL_ASSERT(!((mask) & ~((1 << PE_ZMODE_MASK_SIZE)-1))); \
        pe_zmode = (((unsigned long)(pe_zmode)) & ~PE_ZMODE_MASK_MASK) | (((unsigned long)(mask)) << PE_ZMODE_MASK_SHIFT);\
}
#define PE_ZMODE_PAD0_SIZE      19
#define PE_ZMODE_PAD0_SHIFT     5
#define PE_ZMODE_PAD0_MASK      0x00ffffe0
#define PE_ZMODE_GET_PAD0(pe_zmode) \
        ((((unsigned long)(pe_zmode)) & PE_ZMODE_PAD0_MASK) >> PE_ZMODE_PAD0_SHIFT)
#define PE_ZMODE_SET_PAD0(pe_zmode, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_ZMODE_PAD0_SIZE)-1))); \
        pe_zmode = (((unsigned long)(pe_zmode)) & ~PE_ZMODE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_ZMODE_PAD0_SHIFT);\
}
#define PE_ZMODE_RID_SIZE       8
#define PE_ZMODE_RID_SHIFT      24
#define PE_ZMODE_RID_MASK       0xff000000
#define PE_ZMODE_GET_RID(pe_zmode) \
        ((((unsigned long)(pe_zmode)) & PE_ZMODE_RID_MASK) >> PE_ZMODE_RID_SHIFT)
#define PE_ZMODE_SET_RID(pe_zmode, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_ZMODE_RID_SIZE)-1))); \
        pe_zmode = (((unsigned long)(pe_zmode)) & ~PE_ZMODE_RID_MASK) | (((unsigned long)(rid)) << PE_ZMODE_RID_SHIFT);\
}
#define PE_ZMODE_TOTAL_SIZE     32
#define PE_ZMODE(enable, func, mask, rid) \
        ((((unsigned long)(enable)) << PE_ZMODE_ENABLE_SHIFT) | \
         (((unsigned long)(func)) << PE_ZMODE_FUNC_SHIFT) | \
         (((unsigned long)(mask)) << PE_ZMODE_MASK_SHIFT) | \
         (((unsigned long)(rid)) << PE_ZMODE_RID_SHIFT))

/*
 *  pe_cmode0 struct
 */
#define PE_CMODE0_BLEND_ENABLE_SIZE     1
#define PE_CMODE0_BLEND_ENABLE_SHIFT    0
#define PE_CMODE0_BLEND_ENABLE_MASK     0x00000001
#define PE_CMODE0_GET_BLEND_ENABLE(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_BLEND_ENABLE_MASK) >> PE_CMODE0_BLEND_ENABLE_SHIFT)
#define PE_CMODE0_SET_BLEND_ENABLE(pe_cmode0, blend_enable) { \
        FDL_ASSERT(!((blend_enable) & ~((1 << PE_CMODE0_BLEND_ENABLE_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_BLEND_ENABLE_MASK) | (((unsigned long)(blend_enable)) << PE_CMODE0_BLEND_ENABLE_SHIFT);\
}
#define PE_CMODE0_LOGICOP_ENABLE_SIZE   1
#define PE_CMODE0_LOGICOP_ENABLE_SHIFT  1
#define PE_CMODE0_LOGICOP_ENABLE_MASK   0x00000002
#define PE_CMODE0_GET_LOGICOP_ENABLE(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_LOGICOP_ENABLE_MASK) >> PE_CMODE0_LOGICOP_ENABLE_SHIFT)
#define PE_CMODE0_SET_LOGICOP_ENABLE(pe_cmode0, logicop_enable) { \
        FDL_ASSERT(!((logicop_enable) & ~((1 << PE_CMODE0_LOGICOP_ENABLE_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_LOGICOP_ENABLE_MASK) | (((unsigned long)(logicop_enable)) << PE_CMODE0_LOGICOP_ENABLE_SHIFT);\
}
#define PE_CMODE0_DITHER_ENABLE_SIZE    1
#define PE_CMODE0_DITHER_ENABLE_SHIFT   2
#define PE_CMODE0_DITHER_ENABLE_MASK    0x00000004
#define PE_CMODE0_GET_DITHER_ENABLE(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_DITHER_ENABLE_MASK) >> PE_CMODE0_DITHER_ENABLE_SHIFT)
#define PE_CMODE0_SET_DITHER_ENABLE(pe_cmode0, dither_enable) { \
        FDL_ASSERT(!((dither_enable) & ~((1 << PE_CMODE0_DITHER_ENABLE_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_DITHER_ENABLE_MASK) | (((unsigned long)(dither_enable)) << PE_CMODE0_DITHER_ENABLE_SHIFT);\
}
#define PE_CMODE0_COLOR_MASK_SIZE       1
#define PE_CMODE0_COLOR_MASK_SHIFT      3
#define PE_CMODE0_COLOR_MASK_MASK       0x00000008
#define PE_CMODE0_GET_COLOR_MASK(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_COLOR_MASK_MASK) >> PE_CMODE0_COLOR_MASK_SHIFT)
#define PE_CMODE0_SET_COLOR_MASK(pe_cmode0, color_mask) { \
        FDL_ASSERT(!((color_mask) & ~((1 << PE_CMODE0_COLOR_MASK_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_COLOR_MASK_MASK) | (((unsigned long)(color_mask)) << PE_CMODE0_COLOR_MASK_SHIFT);\
}
#define PE_CMODE0_ALPHA_MASK_SIZE       1
#define PE_CMODE0_ALPHA_MASK_SHIFT      4
#define PE_CMODE0_ALPHA_MASK_MASK       0x00000010
#define PE_CMODE0_GET_ALPHA_MASK(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_ALPHA_MASK_MASK) >> PE_CMODE0_ALPHA_MASK_SHIFT)
#define PE_CMODE0_SET_ALPHA_MASK(pe_cmode0, alpha_mask) { \
        FDL_ASSERT(!((alpha_mask) & ~((1 << PE_CMODE0_ALPHA_MASK_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_ALPHA_MASK_MASK) | (((unsigned long)(alpha_mask)) << PE_CMODE0_ALPHA_MASK_SHIFT);\
}
#define PE_CMODE0_DFACTOR_SIZE  3
#define PE_CMODE0_DFACTOR_SHIFT 5
#define PE_CMODE0_DFACTOR_MASK  0x000000e0
#define PE_CMODE0_GET_DFACTOR(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_DFACTOR_MASK) >> PE_CMODE0_DFACTOR_SHIFT)
#define PE_CMODE0_SET_DFACTOR(pe_cmode0, dfactor) { \
        FDL_ASSERT(!((dfactor) & ~((1 << PE_CMODE0_DFACTOR_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_DFACTOR_MASK) | (((unsigned long)(dfactor)) << PE_CMODE0_DFACTOR_SHIFT);\
}
#define PE_CMODE0_SFACTOR_SIZE  3
#define PE_CMODE0_SFACTOR_SHIFT 8
#define PE_CMODE0_SFACTOR_MASK  0x00000700
#define PE_CMODE0_GET_SFACTOR(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_SFACTOR_MASK) >> PE_CMODE0_SFACTOR_SHIFT)
#define PE_CMODE0_SET_SFACTOR(pe_cmode0, sfactor) { \
        FDL_ASSERT(!((sfactor) & ~((1 << PE_CMODE0_SFACTOR_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_SFACTOR_MASK) | (((unsigned long)(sfactor)) << PE_CMODE0_SFACTOR_SHIFT);\
}
#define PE_CMODE0_BLENDOP_SIZE  1
#define PE_CMODE0_BLENDOP_SHIFT 11
#define PE_CMODE0_BLENDOP_MASK  0x00000800
#define PE_CMODE0_GET_BLENDOP(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_BLENDOP_MASK) >> PE_CMODE0_BLENDOP_SHIFT)
#define PE_CMODE0_SET_BLENDOP(pe_cmode0, blendop) { \
        FDL_ASSERT(!((blendop) & ~((1 << PE_CMODE0_BLENDOP_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_BLENDOP_MASK) | (((unsigned long)(blendop)) << PE_CMODE0_BLENDOP_SHIFT);\
}
#define PE_CMODE0_LOGICOP_SIZE  4
#define PE_CMODE0_LOGICOP_SHIFT 12
#define PE_CMODE0_LOGICOP_MASK  0x0000f000
#define PE_CMODE0_GET_LOGICOP(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_LOGICOP_MASK) >> PE_CMODE0_LOGICOP_SHIFT)
#define PE_CMODE0_SET_LOGICOP(pe_cmode0, logicop) { \
        FDL_ASSERT(!((logicop) & ~((1 << PE_CMODE0_LOGICOP_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_LOGICOP_MASK) | (((unsigned long)(logicop)) << PE_CMODE0_LOGICOP_SHIFT);\
}
#define PE_CMODE0_PAD0_SIZE     8
#define PE_CMODE0_PAD0_SHIFT    16
#define PE_CMODE0_PAD0_MASK     0x00ff0000
#define PE_CMODE0_GET_PAD0(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_PAD0_MASK) >> PE_CMODE0_PAD0_SHIFT)
#define PE_CMODE0_SET_PAD0(pe_cmode0, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_CMODE0_PAD0_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_PAD0_MASK) | (((unsigned long)(pad0)) << PE_CMODE0_PAD0_SHIFT);\
}
#define PE_CMODE0_RID_SIZE      8
#define PE_CMODE0_RID_SHIFT     24
#define PE_CMODE0_RID_MASK      0xff000000
#define PE_CMODE0_GET_RID(pe_cmode0) \
        ((((unsigned long)(pe_cmode0)) & PE_CMODE0_RID_MASK) >> PE_CMODE0_RID_SHIFT)
#define PE_CMODE0_SET_RID(pe_cmode0, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_CMODE0_RID_SIZE)-1))); \
        pe_cmode0 = (((unsigned long)(pe_cmode0)) & ~PE_CMODE0_RID_MASK) | (((unsigned long)(rid)) << PE_CMODE0_RID_SHIFT);\
}
#define PE_CMODE0_TOTAL_SIZE    32
#define PE_CMODE0(blend_enable, logicop_enable, dither_enable, color_mask, alpha_mask, dfactor, sfactor, blendop, logicop, rid) \
        ((((unsigned long)(blend_enable)) << PE_CMODE0_BLEND_ENABLE_SHIFT) | \
         (((unsigned long)(logicop_enable)) << PE_CMODE0_LOGICOP_ENABLE_SHIFT) | \
         (((unsigned long)(dither_enable)) << PE_CMODE0_DITHER_ENABLE_SHIFT) | \
         (((unsigned long)(color_mask)) << PE_CMODE0_COLOR_MASK_SHIFT) | \
         (((unsigned long)(alpha_mask)) << PE_CMODE0_ALPHA_MASK_SHIFT) | \
         (((unsigned long)(dfactor)) << PE_CMODE0_DFACTOR_SHIFT) | \
         (((unsigned long)(sfactor)) << PE_CMODE0_SFACTOR_SHIFT) | \
         (((unsigned long)(blendop)) << PE_CMODE0_BLENDOP_SHIFT) | \
         (((unsigned long)(logicop)) << PE_CMODE0_LOGICOP_SHIFT) | \
         (((unsigned long)(rid)) << PE_CMODE0_RID_SHIFT))

/*
 *  pe_cmode1 struct
 */
#define PE_CMODE1_CONSTANT_ALPHA_SIZE   8
#define PE_CMODE1_CONSTANT_ALPHA_SHIFT  0
#define PE_CMODE1_CONSTANT_ALPHA_MASK   0x000000ff
#define PE_CMODE1_GET_CONSTANT_ALPHA(pe_cmode1) \
        ((((unsigned long)(pe_cmode1)) & PE_CMODE1_CONSTANT_ALPHA_MASK) >> PE_CMODE1_CONSTANT_ALPHA_SHIFT)
#define PE_CMODE1_SET_CONSTANT_ALPHA(pe_cmode1, constant_alpha) { \
        FDL_ASSERT(!((constant_alpha) & ~((1 << PE_CMODE1_CONSTANT_ALPHA_SIZE)-1))); \
        pe_cmode1 = (((unsigned long)(pe_cmode1)) & ~PE_CMODE1_CONSTANT_ALPHA_MASK) | (((unsigned long)(constant_alpha)) << PE_CMODE1_CONSTANT_ALPHA_SHIFT);\
}
#define PE_CMODE1_CONSTANT_ALPHA_ENABLE_SIZE    1
#define PE_CMODE1_CONSTANT_ALPHA_ENABLE_SHIFT   8
#define PE_CMODE1_CONSTANT_ALPHA_ENABLE_MASK    0x00000100
#define PE_CMODE1_GET_CONSTANT_ALPHA_ENABLE(pe_cmode1) \
        ((((unsigned long)(pe_cmode1)) & PE_CMODE1_CONSTANT_ALPHA_ENABLE_MASK) >> PE_CMODE1_CONSTANT_ALPHA_ENABLE_SHIFT)
#define PE_CMODE1_SET_CONSTANT_ALPHA_ENABLE(pe_cmode1, constant_alpha_enable) { \
        FDL_ASSERT(!((constant_alpha_enable) & ~((1 << PE_CMODE1_CONSTANT_ALPHA_ENABLE_SIZE)-1))); \
        pe_cmode1 = (((unsigned long)(pe_cmode1)) & ~PE_CMODE1_CONSTANT_ALPHA_ENABLE_MASK) | (((unsigned long)(constant_alpha_enable)) << PE_CMODE1_CONSTANT_ALPHA_ENABLE_SHIFT);\
}
#define PE_CMODE1_YUV_SIZE      2
#define PE_CMODE1_YUV_SHIFT     9
#define PE_CMODE1_YUV_MASK      0x00000600
#define PE_CMODE1_GET_YUV(pe_cmode1) \
        ((((unsigned long)(pe_cmode1)) & PE_CMODE1_YUV_MASK) >> PE_CMODE1_YUV_SHIFT)
#define PE_CMODE1_SET_YUV(pe_cmode1, yuv) { \
        FDL_ASSERT(!((yuv) & ~((1 << PE_CMODE1_YUV_SIZE)-1))); \
        pe_cmode1 = (((unsigned long)(pe_cmode1)) & ~PE_CMODE1_YUV_MASK) | (((unsigned long)(yuv)) << PE_CMODE1_YUV_SHIFT);\
}
#define PE_CMODE1_PAD0_SIZE     13
#define PE_CMODE1_PAD0_SHIFT    11
#define PE_CMODE1_PAD0_MASK     0x00fff800
#define PE_CMODE1_GET_PAD0(pe_cmode1) \
        ((((unsigned long)(pe_cmode1)) & PE_CMODE1_PAD0_MASK) >> PE_CMODE1_PAD0_SHIFT)
#define PE_CMODE1_SET_PAD0(pe_cmode1, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_CMODE1_PAD0_SIZE)-1))); \
        pe_cmode1 = (((unsigned long)(pe_cmode1)) & ~PE_CMODE1_PAD0_MASK) | (((unsigned long)(pad0)) << PE_CMODE1_PAD0_SHIFT);\
}
#define PE_CMODE1_RID_SIZE      8
#define PE_CMODE1_RID_SHIFT     24
#define PE_CMODE1_RID_MASK      0xff000000
#define PE_CMODE1_GET_RID(pe_cmode1) \
        ((((unsigned long)(pe_cmode1)) & PE_CMODE1_RID_MASK) >> PE_CMODE1_RID_SHIFT)
#define PE_CMODE1_SET_RID(pe_cmode1, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_CMODE1_RID_SIZE)-1))); \
        pe_cmode1 = (((unsigned long)(pe_cmode1)) & ~PE_CMODE1_RID_MASK) | (((unsigned long)(rid)) << PE_CMODE1_RID_SHIFT);\
}
#define PE_CMODE1_TOTAL_SIZE    32
#define PE_CMODE1(constant_alpha, constant_alpha_enable, yuv, rid) \
        ((((unsigned long)(constant_alpha)) << PE_CMODE1_CONSTANT_ALPHA_SHIFT) | \
         (((unsigned long)(constant_alpha_enable)) << PE_CMODE1_CONSTANT_ALPHA_ENABLE_SHIFT) | \
         (((unsigned long)(yuv)) << PE_CMODE1_YUV_SHIFT) | \
         (((unsigned long)(rid)) << PE_CMODE1_RID_SHIFT))

/*
 *  pe_control struct
 */
#define PE_CONTROL_PIXTYPE_SIZE 3
#define PE_CONTROL_PIXTYPE_SHIFT        0
#define PE_CONTROL_PIXTYPE_MASK 0x00000007
#define PE_CONTROL_GET_PIXTYPE(pe_control) \
        ((((unsigned long)(pe_control)) & PE_CONTROL_PIXTYPE_MASK) >> PE_CONTROL_PIXTYPE_SHIFT)
#define PE_CONTROL_SET_PIXTYPE(pe_control, pixtype) { \
        FDL_ASSERT(!((pixtype) & ~((1 << PE_CONTROL_PIXTYPE_SIZE)-1))); \
        pe_control = (((unsigned long)(pe_control)) & ~PE_CONTROL_PIXTYPE_MASK) | (((unsigned long)(pixtype)) << PE_CONTROL_PIXTYPE_SHIFT);\
}
#define PE_CONTROL_ZCMODE_SIZE  3
#define PE_CONTROL_ZCMODE_SHIFT 3
#define PE_CONTROL_ZCMODE_MASK  0x00000038
#define PE_CONTROL_GET_ZCMODE(pe_control) \
        ((((unsigned long)(pe_control)) & PE_CONTROL_ZCMODE_MASK) >> PE_CONTROL_ZCMODE_SHIFT)
#define PE_CONTROL_SET_ZCMODE(pe_control, zcmode) { \
        FDL_ASSERT(!((zcmode) & ~((1 << PE_CONTROL_ZCMODE_SIZE)-1))); \
        pe_control = (((unsigned long)(pe_control)) & ~PE_CONTROL_ZCMODE_MASK) | (((unsigned long)(zcmode)) << PE_CONTROL_ZCMODE_SHIFT);\
}
#define PE_CONTROL_ZTOP_SIZE    1
#define PE_CONTROL_ZTOP_SHIFT   6
#define PE_CONTROL_ZTOP_MASK    0x00000040
#define PE_CONTROL_GET_ZTOP(pe_control) \
        ((((unsigned long)(pe_control)) & PE_CONTROL_ZTOP_MASK) >> PE_CONTROL_ZTOP_SHIFT)
#define PE_CONTROL_SET_ZTOP(pe_control, ztop) { \
        FDL_ASSERT(!((ztop) & ~((1 << PE_CONTROL_ZTOP_SIZE)-1))); \
        pe_control = (((unsigned long)(pe_control)) & ~PE_CONTROL_ZTOP_MASK) | (((unsigned long)(ztop)) << PE_CONTROL_ZTOP_SHIFT);\
}
#define PE_CONTROL_PAD0_SIZE    17
#define PE_CONTROL_PAD0_SHIFT   7
#define PE_CONTROL_PAD0_MASK    0x00ffff80
#define PE_CONTROL_GET_PAD0(pe_control) \
        ((((unsigned long)(pe_control)) & PE_CONTROL_PAD0_MASK) >> PE_CONTROL_PAD0_SHIFT)
#define PE_CONTROL_SET_PAD0(pe_control, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_CONTROL_PAD0_SIZE)-1))); \
        pe_control = (((unsigned long)(pe_control)) & ~PE_CONTROL_PAD0_MASK) | (((unsigned long)(pad0)) << PE_CONTROL_PAD0_SHIFT);\
}
#define PE_CONTROL_RID_SIZE     8
#define PE_CONTROL_RID_SHIFT    24
#define PE_CONTROL_RID_MASK     0xff000000
#define PE_CONTROL_GET_RID(pe_control) \
        ((((unsigned long)(pe_control)) & PE_CONTROL_RID_MASK) >> PE_CONTROL_RID_SHIFT)
#define PE_CONTROL_SET_RID(pe_control, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_CONTROL_RID_SIZE)-1))); \
        pe_control = (((unsigned long)(pe_control)) & ~PE_CONTROL_RID_MASK) | (((unsigned long)(rid)) << PE_CONTROL_RID_SHIFT);\
}
#define PE_CONTROL_TOTAL_SIZE   32
#define PE_CONTROL(pixtype, zcmode, ztop, rid) \
        ((((unsigned long)(pixtype)) << PE_CONTROL_PIXTYPE_SHIFT) | \
         (((unsigned long)(zcmode)) << PE_CONTROL_ZCMODE_SHIFT) | \
         (((unsigned long)(ztop)) << PE_CONTROL_ZTOP_SHIFT) | \
         (((unsigned long)(rid)) << PE_CONTROL_RID_SHIFT))

/*
 *  pe_field_mask struct
 */
#define PE_FIELD_MASK_EVEN_SIZE 1
#define PE_FIELD_MASK_EVEN_SHIFT        0
#define PE_FIELD_MASK_EVEN_MASK 0x00000001
#define PE_FIELD_MASK_GET_EVEN(pe_field_mask) \
        ((((unsigned long)(pe_field_mask)) & PE_FIELD_MASK_EVEN_MASK) >> PE_FIELD_MASK_EVEN_SHIFT)
#define PE_FIELD_MASK_SET_EVEN(pe_field_mask, even) { \
        FDL_ASSERT(!((even) & ~((1 << PE_FIELD_MASK_EVEN_SIZE)-1))); \
        pe_field_mask = (((unsigned long)(pe_field_mask)) & ~PE_FIELD_MASK_EVEN_MASK) | (((unsigned long)(even)) << PE_FIELD_MASK_EVEN_SHIFT);\
}
#define PE_FIELD_MASK_ODD_SIZE  1
#define PE_FIELD_MASK_ODD_SHIFT 1
#define PE_FIELD_MASK_ODD_MASK  0x00000002
#define PE_FIELD_MASK_GET_ODD(pe_field_mask) \
        ((((unsigned long)(pe_field_mask)) & PE_FIELD_MASK_ODD_MASK) >> PE_FIELD_MASK_ODD_SHIFT)
#define PE_FIELD_MASK_SET_ODD(pe_field_mask, odd) { \
        FDL_ASSERT(!((odd) & ~((1 << PE_FIELD_MASK_ODD_SIZE)-1))); \
        pe_field_mask = (((unsigned long)(pe_field_mask)) & ~PE_FIELD_MASK_ODD_MASK) | (((unsigned long)(odd)) << PE_FIELD_MASK_ODD_SHIFT);\
}
#define PE_FIELD_MASK_PAD0_SIZE 22
#define PE_FIELD_MASK_PAD0_SHIFT        2
#define PE_FIELD_MASK_PAD0_MASK 0x00fffffc
#define PE_FIELD_MASK_GET_PAD0(pe_field_mask) \
        ((((unsigned long)(pe_field_mask)) & PE_FIELD_MASK_PAD0_MASK) >> PE_FIELD_MASK_PAD0_SHIFT)
#define PE_FIELD_MASK_SET_PAD0(pe_field_mask, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_FIELD_MASK_PAD0_SIZE)-1))); \
        pe_field_mask = (((unsigned long)(pe_field_mask)) & ~PE_FIELD_MASK_PAD0_MASK) | (((unsigned long)(pad0)) << PE_FIELD_MASK_PAD0_SHIFT);\
}
#define PE_FIELD_MASK_RID_SIZE  8
#define PE_FIELD_MASK_RID_SHIFT 24
#define PE_FIELD_MASK_RID_MASK  0xff000000
#define PE_FIELD_MASK_GET_RID(pe_field_mask) \
        ((((unsigned long)(pe_field_mask)) & PE_FIELD_MASK_RID_MASK) >> PE_FIELD_MASK_RID_SHIFT)
#define PE_FIELD_MASK_SET_RID(pe_field_mask, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_FIELD_MASK_RID_SIZE)-1))); \
        pe_field_mask = (((unsigned long)(pe_field_mask)) & ~PE_FIELD_MASK_RID_MASK) | (((unsigned long)(rid)) << PE_FIELD_MASK_RID_SHIFT);\
}
#define PE_FIELD_MASK_TOTAL_SIZE        32
#define PE_FIELD_MASK(even, odd, rid) \
        ((((unsigned long)(even)) << PE_FIELD_MASK_EVEN_SHIFT) | \
         (((unsigned long)(odd)) << PE_FIELD_MASK_ODD_SHIFT) | \
         (((unsigned long)(rid)) << PE_FIELD_MASK_RID_SHIFT))

/*
 *  pe_finish struct
 */
#define PE_FINISH_DST_SIZE      2
#define PE_FINISH_DST_SHIFT     0
#define PE_FINISH_DST_MASK      0x00000003
#define PE_FINISH_GET_DST(pe_finish) \
        ((((unsigned long)(pe_finish)) & PE_FINISH_DST_MASK) >> PE_FINISH_DST_SHIFT)
#define PE_FINISH_SET_DST(pe_finish, dst) { \
        FDL_ASSERT(!((dst) & ~((1 << PE_FINISH_DST_SIZE)-1))); \
        pe_finish = (((unsigned long)(pe_finish)) & ~PE_FINISH_DST_MASK) | (((unsigned long)(dst)) << PE_FINISH_DST_SHIFT);\
}
#define PE_FINISH_PAD0_SIZE     22
#define PE_FINISH_PAD0_SHIFT    2
#define PE_FINISH_PAD0_MASK     0x00fffffc
#define PE_FINISH_GET_PAD0(pe_finish) \
        ((((unsigned long)(pe_finish)) & PE_FINISH_PAD0_MASK) >> PE_FINISH_PAD0_SHIFT)
#define PE_FINISH_SET_PAD0(pe_finish, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_FINISH_PAD0_SIZE)-1))); \
        pe_finish = (((unsigned long)(pe_finish)) & ~PE_FINISH_PAD0_MASK) | (((unsigned long)(pad0)) << PE_FINISH_PAD0_SHIFT);\
}
#define PE_FINISH_RID_SIZE      8
#define PE_FINISH_RID_SHIFT     24
#define PE_FINISH_RID_MASK      0xff000000
#define PE_FINISH_GET_RID(pe_finish) \
        ((((unsigned long)(pe_finish)) & PE_FINISH_RID_MASK) >> PE_FINISH_RID_SHIFT)
#define PE_FINISH_SET_RID(pe_finish, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_FINISH_RID_SIZE)-1))); \
        pe_finish = (((unsigned long)(pe_finish)) & ~PE_FINISH_RID_MASK) | (((unsigned long)(rid)) << PE_FINISH_RID_SHIFT);\
}
#define PE_FINISH_TOTAL_SIZE    32
#define PE_FINISH(dst, rid) \
        ((((unsigned long)(dst)) << PE_FINISH_DST_SHIFT) | \
         (((unsigned long)(rid)) << PE_FINISH_RID_SHIFT))

/*
 *  pe_refresh struct
 */
#define PE_REFRESH_INTERVAL_SIZE        9
#define PE_REFRESH_INTERVAL_SHIFT       0
#define PE_REFRESH_INTERVAL_MASK        0x000001ff
#define PE_REFRESH_GET_INTERVAL(pe_refresh) \
        ((((unsigned long)(pe_refresh)) & PE_REFRESH_INTERVAL_MASK) >> PE_REFRESH_INTERVAL_SHIFT)
#define PE_REFRESH_SET_INTERVAL(pe_refresh, interval) { \
        FDL_ASSERT(!((interval) & ~((1 << PE_REFRESH_INTERVAL_SIZE)-1))); \
        pe_refresh = (((unsigned long)(pe_refresh)) & ~PE_REFRESH_INTERVAL_MASK) | (((unsigned long)(interval)) << PE_REFRESH_INTERVAL_SHIFT);\
}
#define PE_REFRESH_ENABLE_SIZE  1
#define PE_REFRESH_ENABLE_SHIFT 9
#define PE_REFRESH_ENABLE_MASK  0x00000200
#define PE_REFRESH_GET_ENABLE(pe_refresh) \
        ((((unsigned long)(pe_refresh)) & PE_REFRESH_ENABLE_MASK) >> PE_REFRESH_ENABLE_SHIFT)
#define PE_REFRESH_SET_ENABLE(pe_refresh, enable) { \
        FDL_ASSERT(!((enable) & ~((1 << PE_REFRESH_ENABLE_SIZE)-1))); \
        pe_refresh = (((unsigned long)(pe_refresh)) & ~PE_REFRESH_ENABLE_MASK) | (((unsigned long)(enable)) << PE_REFRESH_ENABLE_SHIFT);\
}
#define PE_REFRESH_PAD0_SIZE    14
#define PE_REFRESH_PAD0_SHIFT   10
#define PE_REFRESH_PAD0_MASK    0x00fffc00
#define PE_REFRESH_GET_PAD0(pe_refresh) \
        ((((unsigned long)(pe_refresh)) & PE_REFRESH_PAD0_MASK) >> PE_REFRESH_PAD0_SHIFT)
#define PE_REFRESH_SET_PAD0(pe_refresh, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_REFRESH_PAD0_SIZE)-1))); \
        pe_refresh = (((unsigned long)(pe_refresh)) & ~PE_REFRESH_PAD0_MASK) | (((unsigned long)(pad0)) << PE_REFRESH_PAD0_SHIFT);\
}
#define PE_REFRESH_RID_SIZE     8
#define PE_REFRESH_RID_SHIFT    24
#define PE_REFRESH_RID_MASK     0xff000000
#define PE_REFRESH_GET_RID(pe_refresh) \
        ((((unsigned long)(pe_refresh)) & PE_REFRESH_RID_MASK) >> PE_REFRESH_RID_SHIFT)
#define PE_REFRESH_SET_RID(pe_refresh, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_REFRESH_RID_SIZE)-1))); \
        pe_refresh = (((unsigned long)(pe_refresh)) & ~PE_REFRESH_RID_MASK) | (((unsigned long)(rid)) << PE_REFRESH_RID_SHIFT);\
}
#define PE_REFRESH_TOTAL_SIZE   32
#define PE_REFRESH(interval, enable, rid) \
        ((((unsigned long)(interval)) << PE_REFRESH_INTERVAL_SHIFT) | \
         (((unsigned long)(enable)) << PE_REFRESH_ENABLE_SHIFT) | \
         (((unsigned long)(rid)) << PE_REFRESH_RID_SHIFT))

/*
 *  pe_token struct
 */
#define PE_TOKEN_TOKEN_SIZE     16
#define PE_TOKEN_TOKEN_SHIFT    0
#define PE_TOKEN_TOKEN_MASK     0x0000ffff
#define PE_TOKEN_GET_TOKEN(pe_token) \
        ((((unsigned long)(pe_token)) & PE_TOKEN_TOKEN_MASK) >> PE_TOKEN_TOKEN_SHIFT)
#define PE_TOKEN_SET_TOKEN(pe_token, token) { \
        FDL_ASSERT(!((token) & ~((1 << PE_TOKEN_TOKEN_SIZE)-1))); \
        pe_token = (((unsigned long)(pe_token)) & ~PE_TOKEN_TOKEN_MASK) | (((unsigned long)(token)) << PE_TOKEN_TOKEN_SHIFT);\
}
#define PE_TOKEN_PAD0_SIZE      8
#define PE_TOKEN_PAD0_SHIFT     16
#define PE_TOKEN_PAD0_MASK      0x00ff0000
#define PE_TOKEN_GET_PAD0(pe_token) \
        ((((unsigned long)(pe_token)) & PE_TOKEN_PAD0_MASK) >> PE_TOKEN_PAD0_SHIFT)
#define PE_TOKEN_SET_PAD0(pe_token, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_TOKEN_PAD0_SIZE)-1))); \
        pe_token = (((unsigned long)(pe_token)) & ~PE_TOKEN_PAD0_MASK) | (((unsigned long)(pad0)) << PE_TOKEN_PAD0_SHIFT);\
}
#define PE_TOKEN_RID_SIZE       8
#define PE_TOKEN_RID_SHIFT      24
#define PE_TOKEN_RID_MASK       0xff000000
#define PE_TOKEN_GET_RID(pe_token) \
        ((((unsigned long)(pe_token)) & PE_TOKEN_RID_MASK) >> PE_TOKEN_RID_SHIFT)
#define PE_TOKEN_SET_RID(pe_token, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_TOKEN_RID_SIZE)-1))); \
        pe_token = (((unsigned long)(pe_token)) & ~PE_TOKEN_RID_MASK) | (((unsigned long)(rid)) << PE_TOKEN_RID_SHIFT);\
}
#define PE_TOKEN_TOTAL_SIZE     32
#define PE_TOKEN(token, rid) \
        ((((unsigned long)(token)) << PE_TOKEN_TOKEN_SHIFT) | \
         (((unsigned long)(rid)) << PE_TOKEN_RID_SHIFT))

/*
 *  pe_token_int struct
 */
#define PE_TOKEN_INT_TOKEN_SIZE 16
#define PE_TOKEN_INT_TOKEN_SHIFT        0
#define PE_TOKEN_INT_TOKEN_MASK 0x0000ffff
#define PE_TOKEN_INT_GET_TOKEN(pe_token_int) \
        ((((unsigned long)(pe_token_int)) & PE_TOKEN_INT_TOKEN_MASK) >> PE_TOKEN_INT_TOKEN_SHIFT)
#define PE_TOKEN_INT_SET_TOKEN(pe_token_int, token) { \
        FDL_ASSERT(!((token) & ~((1 << PE_TOKEN_INT_TOKEN_SIZE)-1))); \
        pe_token_int = (((unsigned long)(pe_token_int)) & ~PE_TOKEN_INT_TOKEN_MASK) | (((unsigned long)(token)) << PE_TOKEN_INT_TOKEN_SHIFT);\
}
#define PE_TOKEN_INT_PAD0_SIZE  8
#define PE_TOKEN_INT_PAD0_SHIFT 16
#define PE_TOKEN_INT_PAD0_MASK  0x00ff0000
#define PE_TOKEN_INT_GET_PAD0(pe_token_int) \
        ((((unsigned long)(pe_token_int)) & PE_TOKEN_INT_PAD0_MASK) >> PE_TOKEN_INT_PAD0_SHIFT)
#define PE_TOKEN_INT_SET_PAD0(pe_token_int, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_TOKEN_INT_PAD0_SIZE)-1))); \
        pe_token_int = (((unsigned long)(pe_token_int)) & ~PE_TOKEN_INT_PAD0_MASK) | (((unsigned long)(pad0)) << PE_TOKEN_INT_PAD0_SHIFT);\
}
#define PE_TOKEN_INT_RID_SIZE   8
#define PE_TOKEN_INT_RID_SHIFT  24
#define PE_TOKEN_INT_RID_MASK   0xff000000
#define PE_TOKEN_INT_GET_RID(pe_token_int) \
        ((((unsigned long)(pe_token_int)) & PE_TOKEN_INT_RID_MASK) >> PE_TOKEN_INT_RID_SHIFT)
#define PE_TOKEN_INT_SET_RID(pe_token_int, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_TOKEN_INT_RID_SIZE)-1))); \
        pe_token_int = (((unsigned long)(pe_token_int)) & ~PE_TOKEN_INT_RID_MASK) | (((unsigned long)(rid)) << PE_TOKEN_INT_RID_SHIFT);\
}
#define PE_TOKEN_INT_TOTAL_SIZE 32
#define PE_TOKEN_INT(token, rid) \
        ((((unsigned long)(token)) << PE_TOKEN_INT_TOKEN_SHIFT) | \
         (((unsigned long)(rid)) << PE_TOKEN_INT_RID_SHIFT))

/*
 *  pe_copy_src_addr struct
 */
#define PE_COPY_SRC_ADDR_X_SIZE 10
#define PE_COPY_SRC_ADDR_X_SHIFT        0
#define PE_COPY_SRC_ADDR_X_MASK 0x000003ff
#define PE_COPY_SRC_ADDR_GET_X(pe_copy_src_addr) \
        ((((unsigned long)(pe_copy_src_addr)) & PE_COPY_SRC_ADDR_X_MASK) >> PE_COPY_SRC_ADDR_X_SHIFT)
#define PE_COPY_SRC_ADDR_SET_X(pe_copy_src_addr, x) { \
        FDL_ASSERT(!((x) & ~((1 << PE_COPY_SRC_ADDR_X_SIZE)-1))); \
        pe_copy_src_addr = (((unsigned long)(pe_copy_src_addr)) & ~PE_COPY_SRC_ADDR_X_MASK) | (((unsigned long)(x)) << PE_COPY_SRC_ADDR_X_SHIFT);\
}
#define PE_COPY_SRC_ADDR_Y_SIZE 10
#define PE_COPY_SRC_ADDR_Y_SHIFT        10
#define PE_COPY_SRC_ADDR_Y_MASK 0x000ffc00
#define PE_COPY_SRC_ADDR_GET_Y(pe_copy_src_addr) \
        ((((unsigned long)(pe_copy_src_addr)) & PE_COPY_SRC_ADDR_Y_MASK) >> PE_COPY_SRC_ADDR_Y_SHIFT)
#define PE_COPY_SRC_ADDR_SET_Y(pe_copy_src_addr, y) { \
        FDL_ASSERT(!((y) & ~((1 << PE_COPY_SRC_ADDR_Y_SIZE)-1))); \
        pe_copy_src_addr = (((unsigned long)(pe_copy_src_addr)) & ~PE_COPY_SRC_ADDR_Y_MASK) | (((unsigned long)(y)) << PE_COPY_SRC_ADDR_Y_SHIFT);\
}
#define PE_COPY_SRC_ADDR_PAD0_SIZE      4
#define PE_COPY_SRC_ADDR_PAD0_SHIFT     20
#define PE_COPY_SRC_ADDR_PAD0_MASK      0x00f00000
#define PE_COPY_SRC_ADDR_GET_PAD0(pe_copy_src_addr) \
        ((((unsigned long)(pe_copy_src_addr)) & PE_COPY_SRC_ADDR_PAD0_MASK) >> PE_COPY_SRC_ADDR_PAD0_SHIFT)
#define PE_COPY_SRC_ADDR_SET_PAD0(pe_copy_src_addr, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_SRC_ADDR_PAD0_SIZE)-1))); \
        pe_copy_src_addr = (((unsigned long)(pe_copy_src_addr)) & ~PE_COPY_SRC_ADDR_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_SRC_ADDR_PAD0_SHIFT);\
}
#define PE_COPY_SRC_ADDR_RID_SIZE       8
#define PE_COPY_SRC_ADDR_RID_SHIFT      24
#define PE_COPY_SRC_ADDR_RID_MASK       0xff000000
#define PE_COPY_SRC_ADDR_GET_RID(pe_copy_src_addr) \
        ((((unsigned long)(pe_copy_src_addr)) & PE_COPY_SRC_ADDR_RID_MASK) >> PE_COPY_SRC_ADDR_RID_SHIFT)
#define PE_COPY_SRC_ADDR_SET_RID(pe_copy_src_addr, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_SRC_ADDR_RID_SIZE)-1))); \
        pe_copy_src_addr = (((unsigned long)(pe_copy_src_addr)) & ~PE_COPY_SRC_ADDR_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_SRC_ADDR_RID_SHIFT);\
}
#define PE_COPY_SRC_ADDR_TOTAL_SIZE     32
#define PE_COPY_SRC_ADDR(x, y, rid) \
        ((((unsigned long)(x)) << PE_COPY_SRC_ADDR_X_SHIFT) | \
         (((unsigned long)(y)) << PE_COPY_SRC_ADDR_Y_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_SRC_ADDR_RID_SHIFT))

/*
 *  pe_copy_src_size struct
 */
#define PE_COPY_SRC_SIZE_X_SIZE 10
#define PE_COPY_SRC_SIZE_X_SHIFT        0
#define PE_COPY_SRC_SIZE_X_MASK 0x000003ff
#define PE_COPY_SRC_SIZE_GET_X(pe_copy_src_size) \
        ((((unsigned long)(pe_copy_src_size)) & PE_COPY_SRC_SIZE_X_MASK) >> PE_COPY_SRC_SIZE_X_SHIFT)
#define PE_COPY_SRC_SIZE_SET_X(pe_copy_src_size, x) { \
        FDL_ASSERT(!((x) & ~((1 << PE_COPY_SRC_SIZE_X_SIZE)-1))); \
        pe_copy_src_size = (((unsigned long)(pe_copy_src_size)) & ~PE_COPY_SRC_SIZE_X_MASK) | (((unsigned long)(x)) << PE_COPY_SRC_SIZE_X_SHIFT);\
}
#define PE_COPY_SRC_SIZE_Y_SIZE 10
#define PE_COPY_SRC_SIZE_Y_SHIFT        10
#define PE_COPY_SRC_SIZE_Y_MASK 0x000ffc00
#define PE_COPY_SRC_SIZE_GET_Y(pe_copy_src_size) \
        ((((unsigned long)(pe_copy_src_size)) & PE_COPY_SRC_SIZE_Y_MASK) >> PE_COPY_SRC_SIZE_Y_SHIFT)
#define PE_COPY_SRC_SIZE_SET_Y(pe_copy_src_size, y) { \
        FDL_ASSERT(!((y) & ~((1 << PE_COPY_SRC_SIZE_Y_SIZE)-1))); \
        pe_copy_src_size = (((unsigned long)(pe_copy_src_size)) & ~PE_COPY_SRC_SIZE_Y_MASK) | (((unsigned long)(y)) << PE_COPY_SRC_SIZE_Y_SHIFT);\
}
#define PE_COPY_SRC_SIZE_PAD0_SIZE      4
#define PE_COPY_SRC_SIZE_PAD0_SHIFT     20
#define PE_COPY_SRC_SIZE_PAD0_MASK      0x00f00000
#define PE_COPY_SRC_SIZE_GET_PAD0(pe_copy_src_size) \
        ((((unsigned long)(pe_copy_src_size)) & PE_COPY_SRC_SIZE_PAD0_MASK) >> PE_COPY_SRC_SIZE_PAD0_SHIFT)
#define PE_COPY_SRC_SIZE_SET_PAD0(pe_copy_src_size, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_SRC_SIZE_PAD0_SIZE)-1))); \
        pe_copy_src_size = (((unsigned long)(pe_copy_src_size)) & ~PE_COPY_SRC_SIZE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_SRC_SIZE_PAD0_SHIFT);\
}
#define PE_COPY_SRC_SIZE_RID_SIZE       8
#define PE_COPY_SRC_SIZE_RID_SHIFT      24
#define PE_COPY_SRC_SIZE_RID_MASK       0xff000000
#define PE_COPY_SRC_SIZE_GET_RID(pe_copy_src_size) \
        ((((unsigned long)(pe_copy_src_size)) & PE_COPY_SRC_SIZE_RID_MASK) >> PE_COPY_SRC_SIZE_RID_SHIFT)
#define PE_COPY_SRC_SIZE_SET_RID(pe_copy_src_size, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_SRC_SIZE_RID_SIZE)-1))); \
        pe_copy_src_size = (((unsigned long)(pe_copy_src_size)) & ~PE_COPY_SRC_SIZE_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_SRC_SIZE_RID_SHIFT);\
}
#define PE_COPY_SRC_SIZE_TOTAL_SIZE     32
#define PE_COPY_SRC_SIZE(x, y, rid) \
        ((((unsigned long)(x)) << PE_COPY_SRC_SIZE_X_SHIFT) | \
         (((unsigned long)(y)) << PE_COPY_SRC_SIZE_Y_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_SRC_SIZE_RID_SHIFT))

/*
 *  pe_copy_dst_base struct
 */
#define PE_COPY_DST_BASE_BASE_SIZE      24
#define PE_COPY_DST_BASE_BASE_SHIFT     0
#define PE_COPY_DST_BASE_BASE_MASK      0x00ffffff
#define PE_COPY_DST_BASE_GET_BASE(pe_copy_dst_base) \
        ((((unsigned long)(pe_copy_dst_base)) & PE_COPY_DST_BASE_BASE_MASK) >> PE_COPY_DST_BASE_BASE_SHIFT)
#define PE_COPY_DST_BASE_SET_BASE(pe_copy_dst_base, base) { \
        FDL_ASSERT(!((base) & ~((1 << PE_COPY_DST_BASE_BASE_SIZE)-1))); \
        pe_copy_dst_base = (((unsigned long)(pe_copy_dst_base)) & ~PE_COPY_DST_BASE_BASE_MASK) | (((unsigned long)(base)) << PE_COPY_DST_BASE_BASE_SHIFT);\
}
#define PE_COPY_DST_BASE_RID_SIZE       8
#define PE_COPY_DST_BASE_RID_SHIFT      24
#define PE_COPY_DST_BASE_RID_MASK       0xff000000
#define PE_COPY_DST_BASE_GET_RID(pe_copy_dst_base) \
        ((((unsigned long)(pe_copy_dst_base)) & PE_COPY_DST_BASE_RID_MASK) >> PE_COPY_DST_BASE_RID_SHIFT)
#define PE_COPY_DST_BASE_SET_RID(pe_copy_dst_base, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_DST_BASE_RID_SIZE)-1))); \
        pe_copy_dst_base = (((unsigned long)(pe_copy_dst_base)) & ~PE_COPY_DST_BASE_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_DST_BASE_RID_SHIFT);\
}
#define PE_COPY_DST_BASE_TOTAL_SIZE     32
#define PE_COPY_DST_BASE(base, rid) \
        ((((unsigned long)(base)) << PE_COPY_DST_BASE_BASE_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_DST_BASE_RID_SHIFT))

/*
 *  pe_copy_dst_stride struct
 */
#define PE_COPY_DST_STRIDE_STRIDE_SIZE  10
#define PE_COPY_DST_STRIDE_STRIDE_SHIFT 0
#define PE_COPY_DST_STRIDE_STRIDE_MASK  0x000003ff
#define PE_COPY_DST_STRIDE_GET_STRIDE(pe_copy_dst_stride) \
        ((((unsigned long)(pe_copy_dst_stride)) & PE_COPY_DST_STRIDE_STRIDE_MASK) >> PE_COPY_DST_STRIDE_STRIDE_SHIFT)
#define PE_COPY_DST_STRIDE_SET_STRIDE(pe_copy_dst_stride, stride) { \
        FDL_ASSERT(!((stride) & ~((1 << PE_COPY_DST_STRIDE_STRIDE_SIZE)-1))); \
        pe_copy_dst_stride = (((unsigned long)(pe_copy_dst_stride)) & ~PE_COPY_DST_STRIDE_STRIDE_MASK) | (((unsigned long)(stride)) << PE_COPY_DST_STRIDE_STRIDE_SHIFT);\
}
#define PE_COPY_DST_STRIDE_PAD0_SIZE    14
#define PE_COPY_DST_STRIDE_PAD0_SHIFT   10
#define PE_COPY_DST_STRIDE_PAD0_MASK    0x00fffc00
#define PE_COPY_DST_STRIDE_GET_PAD0(pe_copy_dst_stride) \
        ((((unsigned long)(pe_copy_dst_stride)) & PE_COPY_DST_STRIDE_PAD0_MASK) >> PE_COPY_DST_STRIDE_PAD0_SHIFT)
#define PE_COPY_DST_STRIDE_SET_PAD0(pe_copy_dst_stride, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_DST_STRIDE_PAD0_SIZE)-1))); \
        pe_copy_dst_stride = (((unsigned long)(pe_copy_dst_stride)) & ~PE_COPY_DST_STRIDE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_DST_STRIDE_PAD0_SHIFT);\
}
#define PE_COPY_DST_STRIDE_RID_SIZE     8
#define PE_COPY_DST_STRIDE_RID_SHIFT    24
#define PE_COPY_DST_STRIDE_RID_MASK     0xff000000
#define PE_COPY_DST_STRIDE_GET_RID(pe_copy_dst_stride) \
        ((((unsigned long)(pe_copy_dst_stride)) & PE_COPY_DST_STRIDE_RID_MASK) >> PE_COPY_DST_STRIDE_RID_SHIFT)
#define PE_COPY_DST_STRIDE_SET_RID(pe_copy_dst_stride, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_DST_STRIDE_RID_SIZE)-1))); \
        pe_copy_dst_stride = (((unsigned long)(pe_copy_dst_stride)) & ~PE_COPY_DST_STRIDE_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_DST_STRIDE_RID_SHIFT);\
}
#define PE_COPY_DST_STRIDE_TOTAL_SIZE   32
#define PE_COPY_DST_STRIDE(stride, rid) \
        ((((unsigned long)(stride)) << PE_COPY_DST_STRIDE_STRIDE_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_DST_STRIDE_RID_SHIFT))

/*
 *  pe_copy_scale struct
 */
#define PE_COPY_SCALE_SCALE_SIZE        9
#define PE_COPY_SCALE_SCALE_SHIFT       0
#define PE_COPY_SCALE_SCALE_MASK        0x000001ff
#define PE_COPY_SCALE_GET_SCALE(pe_copy_scale) \
        ((((unsigned long)(pe_copy_scale)) & PE_COPY_SCALE_SCALE_MASK) >> PE_COPY_SCALE_SCALE_SHIFT)
#define PE_COPY_SCALE_SET_SCALE(pe_copy_scale, scale) { \
        FDL_ASSERT(!((scale) & ~((1 << PE_COPY_SCALE_SCALE_SIZE)-1))); \
        pe_copy_scale = (((unsigned long)(pe_copy_scale)) & ~PE_COPY_SCALE_SCALE_MASK) | (((unsigned long)(scale)) << PE_COPY_SCALE_SCALE_SHIFT);\
}
#define PE_COPY_SCALE_PAD0_SIZE 15
#define PE_COPY_SCALE_PAD0_SHIFT        9
#define PE_COPY_SCALE_PAD0_MASK 0x00fffe00
#define PE_COPY_SCALE_GET_PAD0(pe_copy_scale) \
        ((((unsigned long)(pe_copy_scale)) & PE_COPY_SCALE_PAD0_MASK) >> PE_COPY_SCALE_PAD0_SHIFT)
#define PE_COPY_SCALE_SET_PAD0(pe_copy_scale, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_SCALE_PAD0_SIZE)-1))); \
        pe_copy_scale = (((unsigned long)(pe_copy_scale)) & ~PE_COPY_SCALE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_SCALE_PAD0_SHIFT);\
}
#define PE_COPY_SCALE_RID_SIZE  8
#define PE_COPY_SCALE_RID_SHIFT 24
#define PE_COPY_SCALE_RID_MASK  0xff000000
#define PE_COPY_SCALE_GET_RID(pe_copy_scale) \
        ((((unsigned long)(pe_copy_scale)) & PE_COPY_SCALE_RID_MASK) >> PE_COPY_SCALE_RID_SHIFT)
#define PE_COPY_SCALE_SET_RID(pe_copy_scale, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_SCALE_RID_SIZE)-1))); \
        pe_copy_scale = (((unsigned long)(pe_copy_scale)) & ~PE_COPY_SCALE_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_SCALE_RID_SHIFT);\
}
#define PE_COPY_SCALE_TOTAL_SIZE        32
#define PE_COPY_SCALE(scale, rid) \
        ((((unsigned long)(scale)) << PE_COPY_SCALE_SCALE_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_SCALE_RID_SHIFT))

/*
 *  pe_copy_clear_color_ar struct
 */
#define PE_COPY_CLEAR_COLOR_AR_RED_SIZE 8
#define PE_COPY_CLEAR_COLOR_AR_RED_SHIFT        0
#define PE_COPY_CLEAR_COLOR_AR_RED_MASK 0x000000ff
#define PE_COPY_CLEAR_COLOR_AR_GET_RED(pe_copy_clear_color_ar) \
        ((((unsigned long)(pe_copy_clear_color_ar)) & PE_COPY_CLEAR_COLOR_AR_RED_MASK) >> PE_COPY_CLEAR_COLOR_AR_RED_SHIFT)
#define PE_COPY_CLEAR_COLOR_AR_SET_RED(pe_copy_clear_color_ar, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_COPY_CLEAR_COLOR_AR_RED_SIZE)-1))); \
        pe_copy_clear_color_ar = (((unsigned long)(pe_copy_clear_color_ar)) & ~PE_COPY_CLEAR_COLOR_AR_RED_MASK) | (((unsigned long)(red)) << PE_COPY_CLEAR_COLOR_AR_RED_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_AR_ALPHA_SIZE       8
#define PE_COPY_CLEAR_COLOR_AR_ALPHA_SHIFT      8
#define PE_COPY_CLEAR_COLOR_AR_ALPHA_MASK       0x0000ff00
#define PE_COPY_CLEAR_COLOR_AR_GET_ALPHA(pe_copy_clear_color_ar) \
        ((((unsigned long)(pe_copy_clear_color_ar)) & PE_COPY_CLEAR_COLOR_AR_ALPHA_MASK) >> PE_COPY_CLEAR_COLOR_AR_ALPHA_SHIFT)
#define PE_COPY_CLEAR_COLOR_AR_SET_ALPHA(pe_copy_clear_color_ar, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_COPY_CLEAR_COLOR_AR_ALPHA_SIZE)-1))); \
        pe_copy_clear_color_ar = (((unsigned long)(pe_copy_clear_color_ar)) & ~PE_COPY_CLEAR_COLOR_AR_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_COPY_CLEAR_COLOR_AR_ALPHA_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_AR_PAD0_SIZE        8
#define PE_COPY_CLEAR_COLOR_AR_PAD0_SHIFT       16
#define PE_COPY_CLEAR_COLOR_AR_PAD0_MASK        0x00ff0000
#define PE_COPY_CLEAR_COLOR_AR_GET_PAD0(pe_copy_clear_color_ar) \
        ((((unsigned long)(pe_copy_clear_color_ar)) & PE_COPY_CLEAR_COLOR_AR_PAD0_MASK) >> PE_COPY_CLEAR_COLOR_AR_PAD0_SHIFT)
#define PE_COPY_CLEAR_COLOR_AR_SET_PAD0(pe_copy_clear_color_ar, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_CLEAR_COLOR_AR_PAD0_SIZE)-1))); \
        pe_copy_clear_color_ar = (((unsigned long)(pe_copy_clear_color_ar)) & ~PE_COPY_CLEAR_COLOR_AR_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_CLEAR_COLOR_AR_PAD0_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_AR_RID_SIZE 8
#define PE_COPY_CLEAR_COLOR_AR_RID_SHIFT        24
#define PE_COPY_CLEAR_COLOR_AR_RID_MASK 0xff000000
#define PE_COPY_CLEAR_COLOR_AR_GET_RID(pe_copy_clear_color_ar) \
        ((((unsigned long)(pe_copy_clear_color_ar)) & PE_COPY_CLEAR_COLOR_AR_RID_MASK) >> PE_COPY_CLEAR_COLOR_AR_RID_SHIFT)
#define PE_COPY_CLEAR_COLOR_AR_SET_RID(pe_copy_clear_color_ar, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_CLEAR_COLOR_AR_RID_SIZE)-1))); \
        pe_copy_clear_color_ar = (((unsigned long)(pe_copy_clear_color_ar)) & ~PE_COPY_CLEAR_COLOR_AR_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_CLEAR_COLOR_AR_RID_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_AR_TOTAL_SIZE       32
#define PE_COPY_CLEAR_COLOR_AR(red, alpha, rid) \
        ((((unsigned long)(red)) << PE_COPY_CLEAR_COLOR_AR_RED_SHIFT) | \
         (((unsigned long)(alpha)) << PE_COPY_CLEAR_COLOR_AR_ALPHA_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_CLEAR_COLOR_AR_RID_SHIFT))

/*
 *  pe_copy_clear_color_gb struct
 */
#define PE_COPY_CLEAR_COLOR_GB_BLUE_SIZE        8
#define PE_COPY_CLEAR_COLOR_GB_BLUE_SHIFT       0
#define PE_COPY_CLEAR_COLOR_GB_BLUE_MASK        0x000000ff
#define PE_COPY_CLEAR_COLOR_GB_GET_BLUE(pe_copy_clear_color_gb) \
        ((((unsigned long)(pe_copy_clear_color_gb)) & PE_COPY_CLEAR_COLOR_GB_BLUE_MASK) >> PE_COPY_CLEAR_COLOR_GB_BLUE_SHIFT)
#define PE_COPY_CLEAR_COLOR_GB_SET_BLUE(pe_copy_clear_color_gb, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_COPY_CLEAR_COLOR_GB_BLUE_SIZE)-1))); \
        pe_copy_clear_color_gb = (((unsigned long)(pe_copy_clear_color_gb)) & ~PE_COPY_CLEAR_COLOR_GB_BLUE_MASK) | (((unsigned long)(blue)) << PE_COPY_CLEAR_COLOR_GB_BLUE_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_GB_GREEN_SIZE       8
#define PE_COPY_CLEAR_COLOR_GB_GREEN_SHIFT      8
#define PE_COPY_CLEAR_COLOR_GB_GREEN_MASK       0x0000ff00
#define PE_COPY_CLEAR_COLOR_GB_GET_GREEN(pe_copy_clear_color_gb) \
        ((((unsigned long)(pe_copy_clear_color_gb)) & PE_COPY_CLEAR_COLOR_GB_GREEN_MASK) >> PE_COPY_CLEAR_COLOR_GB_GREEN_SHIFT)
#define PE_COPY_CLEAR_COLOR_GB_SET_GREEN(pe_copy_clear_color_gb, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_COPY_CLEAR_COLOR_GB_GREEN_SIZE)-1))); \
        pe_copy_clear_color_gb = (((unsigned long)(pe_copy_clear_color_gb)) & ~PE_COPY_CLEAR_COLOR_GB_GREEN_MASK) | (((unsigned long)(green)) << PE_COPY_CLEAR_COLOR_GB_GREEN_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_GB_PAD0_SIZE        8
#define PE_COPY_CLEAR_COLOR_GB_PAD0_SHIFT       16
#define PE_COPY_CLEAR_COLOR_GB_PAD0_MASK        0x00ff0000
#define PE_COPY_CLEAR_COLOR_GB_GET_PAD0(pe_copy_clear_color_gb) \
        ((((unsigned long)(pe_copy_clear_color_gb)) & PE_COPY_CLEAR_COLOR_GB_PAD0_MASK) >> PE_COPY_CLEAR_COLOR_GB_PAD0_SHIFT)
#define PE_COPY_CLEAR_COLOR_GB_SET_PAD0(pe_copy_clear_color_gb, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_CLEAR_COLOR_GB_PAD0_SIZE)-1))); \
        pe_copy_clear_color_gb = (((unsigned long)(pe_copy_clear_color_gb)) & ~PE_COPY_CLEAR_COLOR_GB_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_CLEAR_COLOR_GB_PAD0_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_GB_RID_SIZE 8
#define PE_COPY_CLEAR_COLOR_GB_RID_SHIFT        24
#define PE_COPY_CLEAR_COLOR_GB_RID_MASK 0xff000000
#define PE_COPY_CLEAR_COLOR_GB_GET_RID(pe_copy_clear_color_gb) \
        ((((unsigned long)(pe_copy_clear_color_gb)) & PE_COPY_CLEAR_COLOR_GB_RID_MASK) >> PE_COPY_CLEAR_COLOR_GB_RID_SHIFT)
#define PE_COPY_CLEAR_COLOR_GB_SET_RID(pe_copy_clear_color_gb, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_CLEAR_COLOR_GB_RID_SIZE)-1))); \
        pe_copy_clear_color_gb = (((unsigned long)(pe_copy_clear_color_gb)) & ~PE_COPY_CLEAR_COLOR_GB_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_CLEAR_COLOR_GB_RID_SHIFT);\
}
#define PE_COPY_CLEAR_COLOR_GB_TOTAL_SIZE       32
#define PE_COPY_CLEAR_COLOR_GB(blue, green, rid) \
        ((((unsigned long)(blue)) << PE_COPY_CLEAR_COLOR_GB_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_COPY_CLEAR_COLOR_GB_GREEN_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_CLEAR_COLOR_GB_RID_SHIFT))

/*
 *  pe_copy_clear_z struct
 */
#define PE_COPY_CLEAR_Z_DATA_SIZE       24
#define PE_COPY_CLEAR_Z_DATA_SHIFT      0
#define PE_COPY_CLEAR_Z_DATA_MASK       0x00ffffff
#define PE_COPY_CLEAR_Z_GET_DATA(pe_copy_clear_z) \
        ((((unsigned long)(pe_copy_clear_z)) & PE_COPY_CLEAR_Z_DATA_MASK) >> PE_COPY_CLEAR_Z_DATA_SHIFT)
#define PE_COPY_CLEAR_Z_SET_DATA(pe_copy_clear_z, data) { \
        FDL_ASSERT(!((data) & ~((1 << PE_COPY_CLEAR_Z_DATA_SIZE)-1))); \
        pe_copy_clear_z = (((unsigned long)(pe_copy_clear_z)) & ~PE_COPY_CLEAR_Z_DATA_MASK) | (((unsigned long)(data)) << PE_COPY_CLEAR_Z_DATA_SHIFT);\
}
#define PE_COPY_CLEAR_Z_RID_SIZE        8
#define PE_COPY_CLEAR_Z_RID_SHIFT       24
#define PE_COPY_CLEAR_Z_RID_MASK        0xff000000
#define PE_COPY_CLEAR_Z_GET_RID(pe_copy_clear_z) \
        ((((unsigned long)(pe_copy_clear_z)) & PE_COPY_CLEAR_Z_RID_MASK) >> PE_COPY_CLEAR_Z_RID_SHIFT)
#define PE_COPY_CLEAR_Z_SET_RID(pe_copy_clear_z, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_CLEAR_Z_RID_SIZE)-1))); \
        pe_copy_clear_z = (((unsigned long)(pe_copy_clear_z)) & ~PE_COPY_CLEAR_Z_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_CLEAR_Z_RID_SHIFT);\
}
#define PE_COPY_CLEAR_Z_TOTAL_SIZE      32
#define PE_COPY_CLEAR_Z(data, rid) \
        ((((unsigned long)(data)) << PE_COPY_CLEAR_Z_DATA_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_CLEAR_Z_RID_SHIFT))

/*
 *  pe_copy_cmd struct
 */
#define PE_COPY_CMD_CLAMP_TOP_SIZE      1
#define PE_COPY_CMD_CLAMP_TOP_SHIFT     0
#define PE_COPY_CMD_CLAMP_TOP_MASK      0x00000001
#define PE_COPY_CMD_GET_CLAMP_TOP(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_CLAMP_TOP_MASK) >> PE_COPY_CMD_CLAMP_TOP_SHIFT)
#define PE_COPY_CMD_SET_CLAMP_TOP(pe_copy_cmd, clamp_top) { \
        FDL_ASSERT(!((clamp_top) & ~((1 << PE_COPY_CMD_CLAMP_TOP_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_CLAMP_TOP_MASK) | (((unsigned long)(clamp_top)) << PE_COPY_CMD_CLAMP_TOP_SHIFT);\
}
#define PE_COPY_CMD_CLAMP_BOTTOM_SIZE   1
#define PE_COPY_CMD_CLAMP_BOTTOM_SHIFT  1
#define PE_COPY_CMD_CLAMP_BOTTOM_MASK   0x00000002
#define PE_COPY_CMD_GET_CLAMP_BOTTOM(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_CLAMP_BOTTOM_MASK) >> PE_COPY_CMD_CLAMP_BOTTOM_SHIFT)
#define PE_COPY_CMD_SET_CLAMP_BOTTOM(pe_copy_cmd, clamp_bottom) { \
        FDL_ASSERT(!((clamp_bottom) & ~((1 << PE_COPY_CMD_CLAMP_BOTTOM_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_CLAMP_BOTTOM_MASK) | (((unsigned long)(clamp_bottom)) << PE_COPY_CMD_CLAMP_BOTTOM_SHIFT);\
}
#define PE_COPY_CMD_PAD0_SIZE   1
#define PE_COPY_CMD_PAD0_SHIFT  2
#define PE_COPY_CMD_PAD0_MASK   0x00000004
#define PE_COPY_CMD_GET_PAD0(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_PAD0_MASK) >> PE_COPY_CMD_PAD0_SHIFT)
#define PE_COPY_CMD_SET_PAD0(pe_copy_cmd, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_CMD_PAD0_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_CMD_PAD0_SHIFT);\
}
#define PE_COPY_CMD_TEX_FORMATH_SIZE    1
#define PE_COPY_CMD_TEX_FORMATH_SHIFT   3
#define PE_COPY_CMD_TEX_FORMATH_MASK    0x00000008
#define PE_COPY_CMD_GET_TEX_FORMATH(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_TEX_FORMATH_MASK) >> PE_COPY_CMD_TEX_FORMATH_SHIFT)
#define PE_COPY_CMD_SET_TEX_FORMATH(pe_copy_cmd, tex_formatH) { \
        FDL_ASSERT(!((tex_formatH) & ~((1 << PE_COPY_CMD_TEX_FORMATH_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_TEX_FORMATH_MASK) | (((unsigned long)(tex_formatH)) << PE_COPY_CMD_TEX_FORMATH_SHIFT);\
}
#define PE_COPY_CMD_TEX_FORMAT_SIZE     3
#define PE_COPY_CMD_TEX_FORMAT_SHIFT    4
#define PE_COPY_CMD_TEX_FORMAT_MASK     0x00000070
#define PE_COPY_CMD_GET_TEX_FORMAT(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_TEX_FORMAT_MASK) >> PE_COPY_CMD_TEX_FORMAT_SHIFT)
#define PE_COPY_CMD_SET_TEX_FORMAT(pe_copy_cmd, tex_format) { \
        FDL_ASSERT(!((tex_format) & ~((1 << PE_COPY_CMD_TEX_FORMAT_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_TEX_FORMAT_MASK) | (((unsigned long)(tex_format)) << PE_COPY_CMD_TEX_FORMAT_SHIFT);\
}
#define PE_COPY_CMD_GAMMA_SIZE  2
#define PE_COPY_CMD_GAMMA_SHIFT 7
#define PE_COPY_CMD_GAMMA_MASK  0x00000180
#define PE_COPY_CMD_GET_GAMMA(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_GAMMA_MASK) >> PE_COPY_CMD_GAMMA_SHIFT)
#define PE_COPY_CMD_SET_GAMMA(pe_copy_cmd, gamma) { \
        FDL_ASSERT(!((gamma) & ~((1 << PE_COPY_CMD_GAMMA_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_GAMMA_MASK) | (((unsigned long)(gamma)) << PE_COPY_CMD_GAMMA_SHIFT);\
}
#define PE_COPY_CMD_MIP_MAP_FILTER_SIZE 1
#define PE_COPY_CMD_MIP_MAP_FILTER_SHIFT        9
#define PE_COPY_CMD_MIP_MAP_FILTER_MASK 0x00000200
#define PE_COPY_CMD_GET_MIP_MAP_FILTER(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_MIP_MAP_FILTER_MASK) >> PE_COPY_CMD_MIP_MAP_FILTER_SHIFT)
#define PE_COPY_CMD_SET_MIP_MAP_FILTER(pe_copy_cmd, mip_map_filter) { \
        FDL_ASSERT(!((mip_map_filter) & ~((1 << PE_COPY_CMD_MIP_MAP_FILTER_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_MIP_MAP_FILTER_MASK) | (((unsigned long)(mip_map_filter)) << PE_COPY_CMD_MIP_MAP_FILTER_SHIFT);\
}
#define PE_COPY_CMD_VERTICAL_SCALE_SIZE 1
#define PE_COPY_CMD_VERTICAL_SCALE_SHIFT        10
#define PE_COPY_CMD_VERTICAL_SCALE_MASK 0x00000400
#define PE_COPY_CMD_GET_VERTICAL_SCALE(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_VERTICAL_SCALE_MASK) >> PE_COPY_CMD_VERTICAL_SCALE_SHIFT)
#define PE_COPY_CMD_SET_VERTICAL_SCALE(pe_copy_cmd, vertical_scale) { \
        FDL_ASSERT(!((vertical_scale) & ~((1 << PE_COPY_CMD_VERTICAL_SCALE_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_VERTICAL_SCALE_MASK) | (((unsigned long)(vertical_scale)) << PE_COPY_CMD_VERTICAL_SCALE_SHIFT);\
}
#define PE_COPY_CMD_CLEAR_SIZE  1
#define PE_COPY_CMD_CLEAR_SHIFT 11
#define PE_COPY_CMD_CLEAR_MASK  0x00000800
#define PE_COPY_CMD_GET_CLEAR(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_CLEAR_MASK) >> PE_COPY_CMD_CLEAR_SHIFT)
#define PE_COPY_CMD_SET_CLEAR(pe_copy_cmd, clear) { \
        FDL_ASSERT(!((clear) & ~((1 << PE_COPY_CMD_CLEAR_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_CLEAR_MASK) | (((unsigned long)(clear)) << PE_COPY_CMD_CLEAR_SHIFT);\
}
#define PE_COPY_CMD_INTERLACED_SIZE     2
#define PE_COPY_CMD_INTERLACED_SHIFT    12
#define PE_COPY_CMD_INTERLACED_MASK     0x00003000
#define PE_COPY_CMD_GET_INTERLACED(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_INTERLACED_MASK) >> PE_COPY_CMD_INTERLACED_SHIFT)
#define PE_COPY_CMD_SET_INTERLACED(pe_copy_cmd, interlaced) { \
        FDL_ASSERT(!((interlaced) & ~((1 << PE_COPY_CMD_INTERLACED_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_INTERLACED_MASK) | (((unsigned long)(interlaced)) << PE_COPY_CMD_INTERLACED_SHIFT);\
}
#define PE_COPY_CMD_OPCODE_SIZE 1
#define PE_COPY_CMD_OPCODE_SHIFT        14
#define PE_COPY_CMD_OPCODE_MASK 0x00004000
#define PE_COPY_CMD_GET_OPCODE(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_OPCODE_MASK) >> PE_COPY_CMD_OPCODE_SHIFT)
#define PE_COPY_CMD_SET_OPCODE(pe_copy_cmd, opcode) { \
        FDL_ASSERT(!((opcode) & ~((1 << PE_COPY_CMD_OPCODE_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_OPCODE_MASK) | (((unsigned long)(opcode)) << PE_COPY_CMD_OPCODE_SHIFT);\
}
#define PE_COPY_CMD_CCV_SIZE    2
#define PE_COPY_CMD_CCV_SHIFT   15
#define PE_COPY_CMD_CCV_MASK    0x00018000
#define PE_COPY_CMD_GET_CCV(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_CCV_MASK) >> PE_COPY_CMD_CCV_SHIFT)
#define PE_COPY_CMD_SET_CCV(pe_copy_cmd, ccv) { \
        FDL_ASSERT(!((ccv) & ~((1 << PE_COPY_CMD_CCV_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_CCV_MASK) | (((unsigned long)(ccv)) << PE_COPY_CMD_CCV_SHIFT);\
}
#define PE_COPY_CMD_PAD1_SIZE   7
#define PE_COPY_CMD_PAD1_SHIFT  17
#define PE_COPY_CMD_PAD1_MASK   0x00fe0000
#define PE_COPY_CMD_GET_PAD1(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_PAD1_MASK) >> PE_COPY_CMD_PAD1_SHIFT)
#define PE_COPY_CMD_SET_PAD1(pe_copy_cmd, pad1) { \
        FDL_ASSERT(!((pad1) & ~((1 << PE_COPY_CMD_PAD1_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_PAD1_MASK) | (((unsigned long)(pad1)) << PE_COPY_CMD_PAD1_SHIFT);\
}
#define PE_COPY_CMD_RID_SIZE    8
#define PE_COPY_CMD_RID_SHIFT   24
#define PE_COPY_CMD_RID_MASK    0xff000000
#define PE_COPY_CMD_GET_RID(pe_copy_cmd) \
        ((((unsigned long)(pe_copy_cmd)) & PE_COPY_CMD_RID_MASK) >> PE_COPY_CMD_RID_SHIFT)
#define PE_COPY_CMD_SET_RID(pe_copy_cmd, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_CMD_RID_SIZE)-1))); \
        pe_copy_cmd = (((unsigned long)(pe_copy_cmd)) & ~PE_COPY_CMD_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_CMD_RID_SHIFT);\
}
#define PE_COPY_CMD_TOTAL_SIZE  32
#define PE_COPY_CMD(clamp_top, clamp_bottom, tex_formatH, tex_format, gamma, mip_map_filter, vertical_scale, clear, interlaced, opcode, ccv, rid) \
        ((((unsigned long)(clamp_top)) << PE_COPY_CMD_CLAMP_TOP_SHIFT) | \
         (((unsigned long)(clamp_bottom)) << PE_COPY_CMD_CLAMP_BOTTOM_SHIFT) | \
         (((unsigned long)(tex_formatH)) << PE_COPY_CMD_TEX_FORMATH_SHIFT) | \
         (((unsigned long)(tex_format)) << PE_COPY_CMD_TEX_FORMAT_SHIFT) | \
         (((unsigned long)(gamma)) << PE_COPY_CMD_GAMMA_SHIFT) | \
         (((unsigned long)(mip_map_filter)) << PE_COPY_CMD_MIP_MAP_FILTER_SHIFT) | \
         (((unsigned long)(vertical_scale)) << PE_COPY_CMD_VERTICAL_SCALE_SHIFT) | \
         (((unsigned long)(clear)) << PE_COPY_CMD_CLEAR_SHIFT) | \
         (((unsigned long)(interlaced)) << PE_COPY_CMD_INTERLACED_SHIFT) | \
         (((unsigned long)(opcode)) << PE_COPY_CMD_OPCODE_SHIFT) | \
         (((unsigned long)(ccv)) << PE_COPY_CMD_CCV_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_CMD_RID_SHIFT))

/*
 *  pe_copy_vfilter0 struct
 */
#define PE_COPY_VFILTER0_COEFF0_SIZE    6
#define PE_COPY_VFILTER0_COEFF0_SHIFT   0
#define PE_COPY_VFILTER0_COEFF0_MASK    0x0000003f
#define PE_COPY_VFILTER0_GET_COEFF0(pe_copy_vfilter0) \
        ((((unsigned long)(pe_copy_vfilter0)) & PE_COPY_VFILTER0_COEFF0_MASK) >> PE_COPY_VFILTER0_COEFF0_SHIFT)
#define PE_COPY_VFILTER0_SET_COEFF0(pe_copy_vfilter0, coeff0) { \
        FDL_ASSERT(!((coeff0) & ~((1 << PE_COPY_VFILTER0_COEFF0_SIZE)-1))); \
        pe_copy_vfilter0 = (((unsigned long)(pe_copy_vfilter0)) & ~PE_COPY_VFILTER0_COEFF0_MASK) | (((unsigned long)(coeff0)) << PE_COPY_VFILTER0_COEFF0_SHIFT);\
}
#define PE_COPY_VFILTER0_COEFF1_SIZE    6
#define PE_COPY_VFILTER0_COEFF1_SHIFT   6
#define PE_COPY_VFILTER0_COEFF1_MASK    0x00000fc0
#define PE_COPY_VFILTER0_GET_COEFF1(pe_copy_vfilter0) \
        ((((unsigned long)(pe_copy_vfilter0)) & PE_COPY_VFILTER0_COEFF1_MASK) >> PE_COPY_VFILTER0_COEFF1_SHIFT)
#define PE_COPY_VFILTER0_SET_COEFF1(pe_copy_vfilter0, coeff1) { \
        FDL_ASSERT(!((coeff1) & ~((1 << PE_COPY_VFILTER0_COEFF1_SIZE)-1))); \
        pe_copy_vfilter0 = (((unsigned long)(pe_copy_vfilter0)) & ~PE_COPY_VFILTER0_COEFF1_MASK) | (((unsigned long)(coeff1)) << PE_COPY_VFILTER0_COEFF1_SHIFT);\
}
#define PE_COPY_VFILTER0_COEFF2_SIZE    6
#define PE_COPY_VFILTER0_COEFF2_SHIFT   12
#define PE_COPY_VFILTER0_COEFF2_MASK    0x0003f000
#define PE_COPY_VFILTER0_GET_COEFF2(pe_copy_vfilter0) \
        ((((unsigned long)(pe_copy_vfilter0)) & PE_COPY_VFILTER0_COEFF2_MASK) >> PE_COPY_VFILTER0_COEFF2_SHIFT)
#define PE_COPY_VFILTER0_SET_COEFF2(pe_copy_vfilter0, coeff2) { \
        FDL_ASSERT(!((coeff2) & ~((1 << PE_COPY_VFILTER0_COEFF2_SIZE)-1))); \
        pe_copy_vfilter0 = (((unsigned long)(pe_copy_vfilter0)) & ~PE_COPY_VFILTER0_COEFF2_MASK) | (((unsigned long)(coeff2)) << PE_COPY_VFILTER0_COEFF2_SHIFT);\
}
#define PE_COPY_VFILTER0_COEFF3_SIZE    6
#define PE_COPY_VFILTER0_COEFF3_SHIFT   18
#define PE_COPY_VFILTER0_COEFF3_MASK    0x00fc0000
#define PE_COPY_VFILTER0_GET_COEFF3(pe_copy_vfilter0) \
        ((((unsigned long)(pe_copy_vfilter0)) & PE_COPY_VFILTER0_COEFF3_MASK) >> PE_COPY_VFILTER0_COEFF3_SHIFT)
#define PE_COPY_VFILTER0_SET_COEFF3(pe_copy_vfilter0, coeff3) { \
        FDL_ASSERT(!((coeff3) & ~((1 << PE_COPY_VFILTER0_COEFF3_SIZE)-1))); \
        pe_copy_vfilter0 = (((unsigned long)(pe_copy_vfilter0)) & ~PE_COPY_VFILTER0_COEFF3_MASK) | (((unsigned long)(coeff3)) << PE_COPY_VFILTER0_COEFF3_SHIFT);\
}
#define PE_COPY_VFILTER0_RID_SIZE       8
#define PE_COPY_VFILTER0_RID_SHIFT      24
#define PE_COPY_VFILTER0_RID_MASK       0xff000000
#define PE_COPY_VFILTER0_GET_RID(pe_copy_vfilter0) \
        ((((unsigned long)(pe_copy_vfilter0)) & PE_COPY_VFILTER0_RID_MASK) >> PE_COPY_VFILTER0_RID_SHIFT)
#define PE_COPY_VFILTER0_SET_RID(pe_copy_vfilter0, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_VFILTER0_RID_SIZE)-1))); \
        pe_copy_vfilter0 = (((unsigned long)(pe_copy_vfilter0)) & ~PE_COPY_VFILTER0_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_VFILTER0_RID_SHIFT);\
}
#define PE_COPY_VFILTER0_TOTAL_SIZE     32
#define PE_COPY_VFILTER0(coeff0, coeff1, coeff2, coeff3, rid) \
        ((((unsigned long)(coeff0)) << PE_COPY_VFILTER0_COEFF0_SHIFT) | \
         (((unsigned long)(coeff1)) << PE_COPY_VFILTER0_COEFF1_SHIFT) | \
         (((unsigned long)(coeff2)) << PE_COPY_VFILTER0_COEFF2_SHIFT) | \
         (((unsigned long)(coeff3)) << PE_COPY_VFILTER0_COEFF3_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_VFILTER0_RID_SHIFT))

/*
 *  pe_copy_vfilter1 struct
 */
#define PE_COPY_VFILTER1_COEFF4_SIZE    6
#define PE_COPY_VFILTER1_COEFF4_SHIFT   0
#define PE_COPY_VFILTER1_COEFF4_MASK    0x0000003f
#define PE_COPY_VFILTER1_GET_COEFF4(pe_copy_vfilter1) \
        ((((unsigned long)(pe_copy_vfilter1)) & PE_COPY_VFILTER1_COEFF4_MASK) >> PE_COPY_VFILTER1_COEFF4_SHIFT)
#define PE_COPY_VFILTER1_SET_COEFF4(pe_copy_vfilter1, coeff4) { \
        FDL_ASSERT(!((coeff4) & ~((1 << PE_COPY_VFILTER1_COEFF4_SIZE)-1))); \
        pe_copy_vfilter1 = (((unsigned long)(pe_copy_vfilter1)) & ~PE_COPY_VFILTER1_COEFF4_MASK) | (((unsigned long)(coeff4)) << PE_COPY_VFILTER1_COEFF4_SHIFT);\
}
#define PE_COPY_VFILTER1_COEFF5_SIZE    6
#define PE_COPY_VFILTER1_COEFF5_SHIFT   6
#define PE_COPY_VFILTER1_COEFF5_MASK    0x00000fc0
#define PE_COPY_VFILTER1_GET_COEFF5(pe_copy_vfilter1) \
        ((((unsigned long)(pe_copy_vfilter1)) & PE_COPY_VFILTER1_COEFF5_MASK) >> PE_COPY_VFILTER1_COEFF5_SHIFT)
#define PE_COPY_VFILTER1_SET_COEFF5(pe_copy_vfilter1, coeff5) { \
        FDL_ASSERT(!((coeff5) & ~((1 << PE_COPY_VFILTER1_COEFF5_SIZE)-1))); \
        pe_copy_vfilter1 = (((unsigned long)(pe_copy_vfilter1)) & ~PE_COPY_VFILTER1_COEFF5_MASK) | (((unsigned long)(coeff5)) << PE_COPY_VFILTER1_COEFF5_SHIFT);\
}
#define PE_COPY_VFILTER1_COEFF6_SIZE    6
#define PE_COPY_VFILTER1_COEFF6_SHIFT   12
#define PE_COPY_VFILTER1_COEFF6_MASK    0x0003f000
#define PE_COPY_VFILTER1_GET_COEFF6(pe_copy_vfilter1) \
        ((((unsigned long)(pe_copy_vfilter1)) & PE_COPY_VFILTER1_COEFF6_MASK) >> PE_COPY_VFILTER1_COEFF6_SHIFT)
#define PE_COPY_VFILTER1_SET_COEFF6(pe_copy_vfilter1, coeff6) { \
        FDL_ASSERT(!((coeff6) & ~((1 << PE_COPY_VFILTER1_COEFF6_SIZE)-1))); \
        pe_copy_vfilter1 = (((unsigned long)(pe_copy_vfilter1)) & ~PE_COPY_VFILTER1_COEFF6_MASK) | (((unsigned long)(coeff6)) << PE_COPY_VFILTER1_COEFF6_SHIFT);\
}
#define PE_COPY_VFILTER1_PAD0_SIZE      6
#define PE_COPY_VFILTER1_PAD0_SHIFT     18
#define PE_COPY_VFILTER1_PAD0_MASK      0x00fc0000
#define PE_COPY_VFILTER1_GET_PAD0(pe_copy_vfilter1) \
        ((((unsigned long)(pe_copy_vfilter1)) & PE_COPY_VFILTER1_PAD0_MASK) >> PE_COPY_VFILTER1_PAD0_SHIFT)
#define PE_COPY_VFILTER1_SET_PAD0(pe_copy_vfilter1, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COPY_VFILTER1_PAD0_SIZE)-1))); \
        pe_copy_vfilter1 = (((unsigned long)(pe_copy_vfilter1)) & ~PE_COPY_VFILTER1_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COPY_VFILTER1_PAD0_SHIFT);\
}
#define PE_COPY_VFILTER1_RID_SIZE       8
#define PE_COPY_VFILTER1_RID_SHIFT      24
#define PE_COPY_VFILTER1_RID_MASK       0xff000000
#define PE_COPY_VFILTER1_GET_RID(pe_copy_vfilter1) \
        ((((unsigned long)(pe_copy_vfilter1)) & PE_COPY_VFILTER1_RID_MASK) >> PE_COPY_VFILTER1_RID_SHIFT)
#define PE_COPY_VFILTER1_SET_RID(pe_copy_vfilter1, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_COPY_VFILTER1_RID_SIZE)-1))); \
        pe_copy_vfilter1 = (((unsigned long)(pe_copy_vfilter1)) & ~PE_COPY_VFILTER1_RID_MASK) | (((unsigned long)(rid)) << PE_COPY_VFILTER1_RID_SHIFT);\
}
#define PE_COPY_VFILTER1_TOTAL_SIZE     32
#define PE_COPY_VFILTER1(coeff4, coeff5, coeff6, rid) \
        ((((unsigned long)(coeff4)) << PE_COPY_VFILTER1_COEFF4_SHIFT) | \
         (((unsigned long)(coeff5)) << PE_COPY_VFILTER1_COEFF5_SHIFT) | \
         (((unsigned long)(coeff6)) << PE_COPY_VFILTER1_COEFF6_SHIFT) | \
         (((unsigned long)(rid)) << PE_COPY_VFILTER1_RID_SHIFT))

/*
 *  pe_xbound struct
 */
#define PE_XBOUND_LEFT_SIZE     10
#define PE_XBOUND_LEFT_SHIFT    0
#define PE_XBOUND_LEFT_MASK     0x000003ff
#define PE_XBOUND_GET_LEFT(pe_xbound) \
        ((((unsigned long)(pe_xbound)) & PE_XBOUND_LEFT_MASK) >> PE_XBOUND_LEFT_SHIFT)
#define PE_XBOUND_SET_LEFT(pe_xbound, left) { \
        FDL_ASSERT(!((left) & ~((1 << PE_XBOUND_LEFT_SIZE)-1))); \
        pe_xbound = (((unsigned long)(pe_xbound)) & ~PE_XBOUND_LEFT_MASK) | (((unsigned long)(left)) << PE_XBOUND_LEFT_SHIFT);\
}
#define PE_XBOUND_RIGHT_SIZE    10
#define PE_XBOUND_RIGHT_SHIFT   10
#define PE_XBOUND_RIGHT_MASK    0x000ffc00
#define PE_XBOUND_GET_RIGHT(pe_xbound) \
        ((((unsigned long)(pe_xbound)) & PE_XBOUND_RIGHT_MASK) >> PE_XBOUND_RIGHT_SHIFT)
#define PE_XBOUND_SET_RIGHT(pe_xbound, right) { \
        FDL_ASSERT(!((right) & ~((1 << PE_XBOUND_RIGHT_SIZE)-1))); \
        pe_xbound = (((unsigned long)(pe_xbound)) & ~PE_XBOUND_RIGHT_MASK) | (((unsigned long)(right)) << PE_XBOUND_RIGHT_SHIFT);\
}
#define PE_XBOUND_PAD0_SIZE     4
#define PE_XBOUND_PAD0_SHIFT    20
#define PE_XBOUND_PAD0_MASK     0x00f00000
#define PE_XBOUND_GET_PAD0(pe_xbound) \
        ((((unsigned long)(pe_xbound)) & PE_XBOUND_PAD0_MASK) >> PE_XBOUND_PAD0_SHIFT)
#define PE_XBOUND_SET_PAD0(pe_xbound, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_XBOUND_PAD0_SIZE)-1))); \
        pe_xbound = (((unsigned long)(pe_xbound)) & ~PE_XBOUND_PAD0_MASK) | (((unsigned long)(pad0)) << PE_XBOUND_PAD0_SHIFT);\
}
#define PE_XBOUND_RID_SIZE      8
#define PE_XBOUND_RID_SHIFT     24
#define PE_XBOUND_RID_MASK      0xff000000
#define PE_XBOUND_GET_RID(pe_xbound) \
        ((((unsigned long)(pe_xbound)) & PE_XBOUND_RID_MASK) >> PE_XBOUND_RID_SHIFT)
#define PE_XBOUND_SET_RID(pe_xbound, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_XBOUND_RID_SIZE)-1))); \
        pe_xbound = (((unsigned long)(pe_xbound)) & ~PE_XBOUND_RID_MASK) | (((unsigned long)(rid)) << PE_XBOUND_RID_SHIFT);\
}
#define PE_XBOUND_TOTAL_SIZE    32
#define PE_XBOUND(left, right, rid) \
        ((((unsigned long)(left)) << PE_XBOUND_LEFT_SHIFT) | \
         (((unsigned long)(right)) << PE_XBOUND_RIGHT_SHIFT) | \
         (((unsigned long)(rid)) << PE_XBOUND_RID_SHIFT))

/*
 *  pe_ybound struct
 */
#define PE_YBOUND_TOP_SIZE      10
#define PE_YBOUND_TOP_SHIFT     0
#define PE_YBOUND_TOP_MASK      0x000003ff
#define PE_YBOUND_GET_TOP(pe_ybound) \
        ((((unsigned long)(pe_ybound)) & PE_YBOUND_TOP_MASK) >> PE_YBOUND_TOP_SHIFT)
#define PE_YBOUND_SET_TOP(pe_ybound, top) { \
        FDL_ASSERT(!((top) & ~((1 << PE_YBOUND_TOP_SIZE)-1))); \
        pe_ybound = (((unsigned long)(pe_ybound)) & ~PE_YBOUND_TOP_MASK) | (((unsigned long)(top)) << PE_YBOUND_TOP_SHIFT);\
}
#define PE_YBOUND_BOTTOM_SIZE   10
#define PE_YBOUND_BOTTOM_SHIFT  10
#define PE_YBOUND_BOTTOM_MASK   0x000ffc00
#define PE_YBOUND_GET_BOTTOM(pe_ybound) \
        ((((unsigned long)(pe_ybound)) & PE_YBOUND_BOTTOM_MASK) >> PE_YBOUND_BOTTOM_SHIFT)
#define PE_YBOUND_SET_BOTTOM(pe_ybound, bottom) { \
        FDL_ASSERT(!((bottom) & ~((1 << PE_YBOUND_BOTTOM_SIZE)-1))); \
        pe_ybound = (((unsigned long)(pe_ybound)) & ~PE_YBOUND_BOTTOM_MASK) | (((unsigned long)(bottom)) << PE_YBOUND_BOTTOM_SHIFT);\
}
#define PE_YBOUND_PAD0_SIZE     4
#define PE_YBOUND_PAD0_SHIFT    20
#define PE_YBOUND_PAD0_MASK     0x00f00000
#define PE_YBOUND_GET_PAD0(pe_ybound) \
        ((((unsigned long)(pe_ybound)) & PE_YBOUND_PAD0_MASK) >> PE_YBOUND_PAD0_SHIFT)
#define PE_YBOUND_SET_PAD0(pe_ybound, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_YBOUND_PAD0_SIZE)-1))); \
        pe_ybound = (((unsigned long)(pe_ybound)) & ~PE_YBOUND_PAD0_MASK) | (((unsigned long)(pad0)) << PE_YBOUND_PAD0_SHIFT);\
}
#define PE_YBOUND_RID_SIZE      8
#define PE_YBOUND_RID_SHIFT     24
#define PE_YBOUND_RID_MASK      0xff000000
#define PE_YBOUND_GET_RID(pe_ybound) \
        ((((unsigned long)(pe_ybound)) & PE_YBOUND_RID_MASK) >> PE_YBOUND_RID_SHIFT)
#define PE_YBOUND_SET_RID(pe_ybound, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_YBOUND_RID_SIZE)-1))); \
        pe_ybound = (((unsigned long)(pe_ybound)) & ~PE_YBOUND_RID_MASK) | (((unsigned long)(rid)) << PE_YBOUND_RID_SHIFT);\
}
#define PE_YBOUND_TOTAL_SIZE    32
#define PE_YBOUND(top, bottom, rid) \
        ((((unsigned long)(top)) << PE_YBOUND_TOP_SHIFT) | \
         (((unsigned long)(bottom)) << PE_YBOUND_BOTTOM_SHIFT) | \
         (((unsigned long)(rid)) << PE_YBOUND_RID_SHIFT))

/*
 *  pe_perfmode struct
 */
#define PE_PERFMODE_CNTR0_SIZE  2
#define PE_PERFMODE_CNTR0_SHIFT 0
#define PE_PERFMODE_CNTR0_MASK  0x00000003
#define PE_PERFMODE_GET_CNTR0(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR0_MASK) >> PE_PERFMODE_CNTR0_SHIFT)
#define PE_PERFMODE_SET_CNTR0(pe_perfmode, cntr0) { \
        FDL_ASSERT(!((cntr0) & ~((1 << PE_PERFMODE_CNTR0_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR0_MASK) | (((unsigned long)(cntr0)) << PE_PERFMODE_CNTR0_SHIFT);\
}
#define PE_PERFMODE_CNTR1_SIZE  2
#define PE_PERFMODE_CNTR1_SHIFT 2
#define PE_PERFMODE_CNTR1_MASK  0x0000000c
#define PE_PERFMODE_GET_CNTR1(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR1_MASK) >> PE_PERFMODE_CNTR1_SHIFT)
#define PE_PERFMODE_SET_CNTR1(pe_perfmode, cntr1) { \
        FDL_ASSERT(!((cntr1) & ~((1 << PE_PERFMODE_CNTR1_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR1_MASK) | (((unsigned long)(cntr1)) << PE_PERFMODE_CNTR1_SHIFT);\
}
#define PE_PERFMODE_CNTR2_SIZE  2
#define PE_PERFMODE_CNTR2_SHIFT 4
#define PE_PERFMODE_CNTR2_MASK  0x00000030
#define PE_PERFMODE_GET_CNTR2(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR2_MASK) >> PE_PERFMODE_CNTR2_SHIFT)
#define PE_PERFMODE_SET_CNTR2(pe_perfmode, cntr2) { \
        FDL_ASSERT(!((cntr2) & ~((1 << PE_PERFMODE_CNTR2_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR2_MASK) | (((unsigned long)(cntr2)) << PE_PERFMODE_CNTR2_SHIFT);\
}
#define PE_PERFMODE_CNTR3_SIZE  2
#define PE_PERFMODE_CNTR3_SHIFT 6
#define PE_PERFMODE_CNTR3_MASK  0x000000c0
#define PE_PERFMODE_GET_CNTR3(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR3_MASK) >> PE_PERFMODE_CNTR3_SHIFT)
#define PE_PERFMODE_SET_CNTR3(pe_perfmode, cntr3) { \
        FDL_ASSERT(!((cntr3) & ~((1 << PE_PERFMODE_CNTR3_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR3_MASK) | (((unsigned long)(cntr3)) << PE_PERFMODE_CNTR3_SHIFT);\
}
#define PE_PERFMODE_CNTR4_SIZE  2
#define PE_PERFMODE_CNTR4_SHIFT 8
#define PE_PERFMODE_CNTR4_MASK  0x00000300
#define PE_PERFMODE_GET_CNTR4(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR4_MASK) >> PE_PERFMODE_CNTR4_SHIFT)
#define PE_PERFMODE_SET_CNTR4(pe_perfmode, cntr4) { \
        FDL_ASSERT(!((cntr4) & ~((1 << PE_PERFMODE_CNTR4_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR4_MASK) | (((unsigned long)(cntr4)) << PE_PERFMODE_CNTR4_SHIFT);\
}
#define PE_PERFMODE_CNTR5_SIZE  2
#define PE_PERFMODE_CNTR5_SHIFT 10
#define PE_PERFMODE_CNTR5_MASK  0x00000c00
#define PE_PERFMODE_GET_CNTR5(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_CNTR5_MASK) >> PE_PERFMODE_CNTR5_SHIFT)
#define PE_PERFMODE_SET_CNTR5(pe_perfmode, cntr5) { \
        FDL_ASSERT(!((cntr5) & ~((1 << PE_PERFMODE_CNTR5_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_CNTR5_MASK) | (((unsigned long)(cntr5)) << PE_PERFMODE_CNTR5_SHIFT);\
}
#define PE_PERFMODE_PAD0_SIZE   12
#define PE_PERFMODE_PAD0_SHIFT  12
#define PE_PERFMODE_PAD0_MASK   0x00fff000
#define PE_PERFMODE_GET_PAD0(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_PAD0_MASK) >> PE_PERFMODE_PAD0_SHIFT)
#define PE_PERFMODE_SET_PAD0(pe_perfmode, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_PERFMODE_PAD0_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_PAD0_MASK) | (((unsigned long)(pad0)) << PE_PERFMODE_PAD0_SHIFT);\
}
#define PE_PERFMODE_RID_SIZE    8
#define PE_PERFMODE_RID_SHIFT   24
#define PE_PERFMODE_RID_MASK    0xff000000
#define PE_PERFMODE_GET_RID(pe_perfmode) \
        ((((unsigned long)(pe_perfmode)) & PE_PERFMODE_RID_MASK) >> PE_PERFMODE_RID_SHIFT)
#define PE_PERFMODE_SET_RID(pe_perfmode, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_PERFMODE_RID_SIZE)-1))); \
        pe_perfmode = (((unsigned long)(pe_perfmode)) & ~PE_PERFMODE_RID_MASK) | (((unsigned long)(rid)) << PE_PERFMODE_RID_SHIFT);\
}
#define PE_PERFMODE_TOTAL_SIZE  32
#define PE_PERFMODE(cntr0, cntr1, cntr2, cntr3, cntr4, cntr5, rid) \
        ((((unsigned long)(cntr0)) << PE_PERFMODE_CNTR0_SHIFT) | \
         (((unsigned long)(cntr1)) << PE_PERFMODE_CNTR1_SHIFT) | \
         (((unsigned long)(cntr2)) << PE_PERFMODE_CNTR2_SHIFT) | \
         (((unsigned long)(cntr3)) << PE_PERFMODE_CNTR3_SHIFT) | \
         (((unsigned long)(cntr4)) << PE_PERFMODE_CNTR4_SHIFT) | \
         (((unsigned long)(cntr5)) << PE_PERFMODE_CNTR5_SHIFT) | \
         (((unsigned long)(rid)) << PE_PERFMODE_RID_SHIFT))

/*
 *  pe_chicken struct
 */
#define PE_CHICKEN_PIWR_SIZE    1
#define PE_CHICKEN_PIWR_SHIFT   0
#define PE_CHICKEN_PIWR_MASK    0x00000001
#define PE_CHICKEN_GET_PIWR(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_PIWR_MASK) >> PE_CHICKEN_PIWR_SHIFT)
#define PE_CHICKEN_SET_PIWR(pe_chicken, piwr) { \
        FDL_ASSERT(!((piwr) & ~((1 << PE_CHICKEN_PIWR_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_PIWR_MASK) | (((unsigned long)(piwr)) << PE_CHICKEN_PIWR_SHIFT);\
}
#define PE_CHICKEN_TXCPY_FMT_SIZE       1
#define PE_CHICKEN_TXCPY_FMT_SHIFT      1
#define PE_CHICKEN_TXCPY_FMT_MASK       0x00000002
#define PE_CHICKEN_GET_TXCPY_FMT(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_TXCPY_FMT_MASK) >> PE_CHICKEN_TXCPY_FMT_SHIFT)
#define PE_CHICKEN_SET_TXCPY_FMT(pe_chicken, txcpy_fmt) { \
        FDL_ASSERT(!((txcpy_fmt) & ~((1 << PE_CHICKEN_TXCPY_FMT_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_TXCPY_FMT_MASK) | (((unsigned long)(txcpy_fmt)) << PE_CHICKEN_TXCPY_FMT_SHIFT);\
}
#define PE_CHICKEN_TXCPY_CCV_SIZE       1
#define PE_CHICKEN_TXCPY_CCV_SHIFT      2
#define PE_CHICKEN_TXCPY_CCV_MASK       0x00000004
#define PE_CHICKEN_GET_TXCPY_CCV(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_TXCPY_CCV_MASK) >> PE_CHICKEN_TXCPY_CCV_SHIFT)
#define PE_CHICKEN_SET_TXCPY_CCV(pe_chicken, txcpy_ccv) { \
        FDL_ASSERT(!((txcpy_ccv) & ~((1 << PE_CHICKEN_TXCPY_CCV_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_TXCPY_CCV_MASK) | (((unsigned long)(txcpy_ccv)) << PE_CHICKEN_TXCPY_CCV_SHIFT);\
}
#define PE_CHICKEN_BLENDOP_SIZE 1
#define PE_CHICKEN_BLENDOP_SHIFT        3
#define PE_CHICKEN_BLENDOP_MASK 0x00000008
#define PE_CHICKEN_GET_BLENDOP(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_BLENDOP_MASK) >> PE_CHICKEN_BLENDOP_SHIFT)
#define PE_CHICKEN_SET_BLENDOP(pe_chicken, blendop) { \
        FDL_ASSERT(!((blendop) & ~((1 << PE_CHICKEN_BLENDOP_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_BLENDOP_MASK) | (((unsigned long)(blendop)) << PE_CHICKEN_BLENDOP_SHIFT);\
}
#define PE_CHICKEN_PAD0_SIZE    20
#define PE_CHICKEN_PAD0_SHIFT   4
#define PE_CHICKEN_PAD0_MASK    0x00fffff0
#define PE_CHICKEN_GET_PAD0(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_PAD0_MASK) >> PE_CHICKEN_PAD0_SHIFT)
#define PE_CHICKEN_SET_PAD0(pe_chicken, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_CHICKEN_PAD0_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_PAD0_MASK) | (((unsigned long)(pad0)) << PE_CHICKEN_PAD0_SHIFT);\
}
#define PE_CHICKEN_RID_SIZE     8
#define PE_CHICKEN_RID_SHIFT    24
#define PE_CHICKEN_RID_MASK     0xff000000
#define PE_CHICKEN_GET_RID(pe_chicken) \
        ((((unsigned long)(pe_chicken)) & PE_CHICKEN_RID_MASK) >> PE_CHICKEN_RID_SHIFT)
#define PE_CHICKEN_SET_RID(pe_chicken, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_CHICKEN_RID_SIZE)-1))); \
        pe_chicken = (((unsigned long)(pe_chicken)) & ~PE_CHICKEN_RID_MASK) | (((unsigned long)(rid)) << PE_CHICKEN_RID_SHIFT);\
}
#define PE_CHICKEN_TOTAL_SIZE   32
#define PE_CHICKEN(piwr, txcpy_fmt, txcpy_ccv, blendop, rid) \
        ((((unsigned long)(piwr)) << PE_CHICKEN_PIWR_SHIFT) | \
         (((unsigned long)(txcpy_fmt)) << PE_CHICKEN_TXCPY_FMT_SHIFT) | \
         (((unsigned long)(txcpy_ccv)) << PE_CHICKEN_TXCPY_CCV_SHIFT) | \
         (((unsigned long)(blendop)) << PE_CHICKEN_BLENDOP_SHIFT) | \
         (((unsigned long)(rid)) << PE_CHICKEN_RID_SHIFT))

/*
 *  pe_quad_offset struct
 */
#define PE_QUAD_OFFSET_X_SIZE   10
#define PE_QUAD_OFFSET_X_SHIFT  0
#define PE_QUAD_OFFSET_X_MASK   0x000003ff
#define PE_QUAD_OFFSET_GET_X(pe_quad_offset) \
        ((((unsigned long)(pe_quad_offset)) & PE_QUAD_OFFSET_X_MASK) >> PE_QUAD_OFFSET_X_SHIFT)
#define PE_QUAD_OFFSET_SET_X(pe_quad_offset, x) { \
        FDL_ASSERT(!((x) & ~((1 << PE_QUAD_OFFSET_X_SIZE)-1))); \
        pe_quad_offset = (((unsigned long)(pe_quad_offset)) & ~PE_QUAD_OFFSET_X_MASK) | (((unsigned long)(x)) << PE_QUAD_OFFSET_X_SHIFT);\
}
#define PE_QUAD_OFFSET_Y_SIZE   10
#define PE_QUAD_OFFSET_Y_SHIFT  10
#define PE_QUAD_OFFSET_Y_MASK   0x000ffc00
#define PE_QUAD_OFFSET_GET_Y(pe_quad_offset) \
        ((((unsigned long)(pe_quad_offset)) & PE_QUAD_OFFSET_Y_MASK) >> PE_QUAD_OFFSET_Y_SHIFT)
#define PE_QUAD_OFFSET_SET_Y(pe_quad_offset, y) { \
        FDL_ASSERT(!((y) & ~((1 << PE_QUAD_OFFSET_Y_SIZE)-1))); \
        pe_quad_offset = (((unsigned long)(pe_quad_offset)) & ~PE_QUAD_OFFSET_Y_MASK) | (((unsigned long)(y)) << PE_QUAD_OFFSET_Y_SHIFT);\
}
#define PE_QUAD_OFFSET_PAD0_SIZE        4
#define PE_QUAD_OFFSET_PAD0_SHIFT       20
#define PE_QUAD_OFFSET_PAD0_MASK        0x00f00000
#define PE_QUAD_OFFSET_GET_PAD0(pe_quad_offset) \
        ((((unsigned long)(pe_quad_offset)) & PE_QUAD_OFFSET_PAD0_MASK) >> PE_QUAD_OFFSET_PAD0_SHIFT)
#define PE_QUAD_OFFSET_SET_PAD0(pe_quad_offset, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_QUAD_OFFSET_PAD0_SIZE)-1))); \
        pe_quad_offset = (((unsigned long)(pe_quad_offset)) & ~PE_QUAD_OFFSET_PAD0_MASK) | (((unsigned long)(pad0)) << PE_QUAD_OFFSET_PAD0_SHIFT);\
}
#define PE_QUAD_OFFSET_RID_SIZE 8
#define PE_QUAD_OFFSET_RID_SHIFT        24
#define PE_QUAD_OFFSET_RID_MASK 0xff000000
#define PE_QUAD_OFFSET_GET_RID(pe_quad_offset) \
        ((((unsigned long)(pe_quad_offset)) & PE_QUAD_OFFSET_RID_MASK) >> PE_QUAD_OFFSET_RID_SHIFT)
#define PE_QUAD_OFFSET_SET_RID(pe_quad_offset, rid) { \
        FDL_ASSERT(!((rid) & ~((1 << PE_QUAD_OFFSET_RID_SIZE)-1))); \
        pe_quad_offset = (((unsigned long)(pe_quad_offset)) & ~PE_QUAD_OFFSET_RID_MASK) | (((unsigned long)(rid)) << PE_QUAD_OFFSET_RID_SHIFT);\
}
#define PE_QUAD_OFFSET_TOTAL_SIZE       32
#define PE_QUAD_OFFSET(x, y, rid) \
        ((((unsigned long)(x)) << PE_QUAD_OFFSET_X_SHIFT) | \
         (((unsigned long)(y)) << PE_QUAD_OFFSET_Y_SHIFT) | \
         (((unsigned long)(rid)) << PE_QUAD_OFFSET_RID_SHIFT))

/*
 *  pe_color_rgb8 struct
 */
#define PE_COLOR_RGB8_BLUE_SIZE 8
#define PE_COLOR_RGB8_BLUE_SHIFT        0
#define PE_COLOR_RGB8_BLUE_MASK 0x000000ff
#define PE_COLOR_RGB8_GET_BLUE(pe_color_rgb8) \
        ((((unsigned long)(pe_color_rgb8)) & PE_COLOR_RGB8_BLUE_MASK) >> PE_COLOR_RGB8_BLUE_SHIFT)
#define PE_COLOR_RGB8_SET_BLUE(pe_color_rgb8, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_COLOR_RGB8_BLUE_SIZE)-1))); \
        pe_color_rgb8 = (((unsigned long)(pe_color_rgb8)) & ~PE_COLOR_RGB8_BLUE_MASK) | (((unsigned long)(blue)) << PE_COLOR_RGB8_BLUE_SHIFT);\
}
#define PE_COLOR_RGB8_GREEN_SIZE        8
#define PE_COLOR_RGB8_GREEN_SHIFT       8
#define PE_COLOR_RGB8_GREEN_MASK        0x0000ff00
#define PE_COLOR_RGB8_GET_GREEN(pe_color_rgb8) \
        ((((unsigned long)(pe_color_rgb8)) & PE_COLOR_RGB8_GREEN_MASK) >> PE_COLOR_RGB8_GREEN_SHIFT)
#define PE_COLOR_RGB8_SET_GREEN(pe_color_rgb8, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_COLOR_RGB8_GREEN_SIZE)-1))); \
        pe_color_rgb8 = (((unsigned long)(pe_color_rgb8)) & ~PE_COLOR_RGB8_GREEN_MASK) | (((unsigned long)(green)) << PE_COLOR_RGB8_GREEN_SHIFT);\
}
#define PE_COLOR_RGB8_RED_SIZE  8
#define PE_COLOR_RGB8_RED_SHIFT 16
#define PE_COLOR_RGB8_RED_MASK  0x00ff0000
#define PE_COLOR_RGB8_GET_RED(pe_color_rgb8) \
        ((((unsigned long)(pe_color_rgb8)) & PE_COLOR_RGB8_RED_MASK) >> PE_COLOR_RGB8_RED_SHIFT)
#define PE_COLOR_RGB8_SET_RED(pe_color_rgb8, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_COLOR_RGB8_RED_SIZE)-1))); \
        pe_color_rgb8 = (((unsigned long)(pe_color_rgb8)) & ~PE_COLOR_RGB8_RED_MASK) | (((unsigned long)(red)) << PE_COLOR_RGB8_RED_SHIFT);\
}
#define PE_COLOR_RGB8_PAD0_SIZE 8
#define PE_COLOR_RGB8_PAD0_SHIFT        24
#define PE_COLOR_RGB8_PAD0_MASK 0xff000000
#define PE_COLOR_RGB8_GET_PAD0(pe_color_rgb8) \
        ((((unsigned long)(pe_color_rgb8)) & PE_COLOR_RGB8_PAD0_MASK) >> PE_COLOR_RGB8_PAD0_SHIFT)
#define PE_COLOR_RGB8_SET_PAD0(pe_color_rgb8, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COLOR_RGB8_PAD0_SIZE)-1))); \
        pe_color_rgb8 = (((unsigned long)(pe_color_rgb8)) & ~PE_COLOR_RGB8_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COLOR_RGB8_PAD0_SHIFT);\
}
#define PE_COLOR_RGB8_TOTAL_SIZE        32
#define PE_COLOR_RGB8(blue, green, red) \
        ((((unsigned long)(blue)) << PE_COLOR_RGB8_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_COLOR_RGB8_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_COLOR_RGB8_RED_SHIFT))

/*
 *  pe_color_rgba6 struct
 */
#define PE_COLOR_RGBA6_ALPHA_SIZE       6
#define PE_COLOR_RGBA6_ALPHA_SHIFT      0
#define PE_COLOR_RGBA6_ALPHA_MASK       0x0000003f
#define PE_COLOR_RGBA6_GET_ALPHA(pe_color_rgba6) \
        ((((unsigned long)(pe_color_rgba6)) & PE_COLOR_RGBA6_ALPHA_MASK) >> PE_COLOR_RGBA6_ALPHA_SHIFT)
#define PE_COLOR_RGBA6_SET_ALPHA(pe_color_rgba6, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_COLOR_RGBA6_ALPHA_SIZE)-1))); \
        pe_color_rgba6 = (((unsigned long)(pe_color_rgba6)) & ~PE_COLOR_RGBA6_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_COLOR_RGBA6_ALPHA_SHIFT);\
}
#define PE_COLOR_RGBA6_BLUE_SIZE        6
#define PE_COLOR_RGBA6_BLUE_SHIFT       6
#define PE_COLOR_RGBA6_BLUE_MASK        0x00000fc0
#define PE_COLOR_RGBA6_GET_BLUE(pe_color_rgba6) \
        ((((unsigned long)(pe_color_rgba6)) & PE_COLOR_RGBA6_BLUE_MASK) >> PE_COLOR_RGBA6_BLUE_SHIFT)
#define PE_COLOR_RGBA6_SET_BLUE(pe_color_rgba6, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_COLOR_RGBA6_BLUE_SIZE)-1))); \
        pe_color_rgba6 = (((unsigned long)(pe_color_rgba6)) & ~PE_COLOR_RGBA6_BLUE_MASK) | (((unsigned long)(blue)) << PE_COLOR_RGBA6_BLUE_SHIFT);\
}
#define PE_COLOR_RGBA6_GREEN_SIZE       6
#define PE_COLOR_RGBA6_GREEN_SHIFT      12
#define PE_COLOR_RGBA6_GREEN_MASK       0x0003f000
#define PE_COLOR_RGBA6_GET_GREEN(pe_color_rgba6) \
        ((((unsigned long)(pe_color_rgba6)) & PE_COLOR_RGBA6_GREEN_MASK) >> PE_COLOR_RGBA6_GREEN_SHIFT)
#define PE_COLOR_RGBA6_SET_GREEN(pe_color_rgba6, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_COLOR_RGBA6_GREEN_SIZE)-1))); \
        pe_color_rgba6 = (((unsigned long)(pe_color_rgba6)) & ~PE_COLOR_RGBA6_GREEN_MASK) | (((unsigned long)(green)) << PE_COLOR_RGBA6_GREEN_SHIFT);\
}
#define PE_COLOR_RGBA6_RED_SIZE 6
#define PE_COLOR_RGBA6_RED_SHIFT        18
#define PE_COLOR_RGBA6_RED_MASK 0x00fc0000
#define PE_COLOR_RGBA6_GET_RED(pe_color_rgba6) \
        ((((unsigned long)(pe_color_rgba6)) & PE_COLOR_RGBA6_RED_MASK) >> PE_COLOR_RGBA6_RED_SHIFT)
#define PE_COLOR_RGBA6_SET_RED(pe_color_rgba6, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_COLOR_RGBA6_RED_SIZE)-1))); \
        pe_color_rgba6 = (((unsigned long)(pe_color_rgba6)) & ~PE_COLOR_RGBA6_RED_MASK) | (((unsigned long)(red)) << PE_COLOR_RGBA6_RED_SHIFT);\
}
#define PE_COLOR_RGBA6_PAD0_SIZE        8
#define PE_COLOR_RGBA6_PAD0_SHIFT       24
#define PE_COLOR_RGBA6_PAD0_MASK        0xff000000
#define PE_COLOR_RGBA6_GET_PAD0(pe_color_rgba6) \
        ((((unsigned long)(pe_color_rgba6)) & PE_COLOR_RGBA6_PAD0_MASK) >> PE_COLOR_RGBA6_PAD0_SHIFT)
#define PE_COLOR_RGBA6_SET_PAD0(pe_color_rgba6, pad0) { \
        FDL_ASSERT(!((pad0) & ~((1 << PE_COLOR_RGBA6_PAD0_SIZE)-1))); \
        pe_color_rgba6 = (((unsigned long)(pe_color_rgba6)) & ~PE_COLOR_RGBA6_PAD0_MASK) | (((unsigned long)(pad0)) << PE_COLOR_RGBA6_PAD0_SHIFT);\
}
#define PE_COLOR_RGBA6_TOTAL_SIZE       32
#define PE_COLOR_RGBA6(alpha, blue, green, red) \
        ((((unsigned long)(alpha)) << PE_COLOR_RGBA6_ALPHA_SHIFT) | \
         (((unsigned long)(blue)) << PE_COLOR_RGBA6_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_COLOR_RGBA6_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_COLOR_RGBA6_RED_SHIFT))

/*
 *  pe_color_rgbaa struct
 */
#define PE_COLOR_RGBAA_BLUE_SIZE        5
#define PE_COLOR_RGBAA_BLUE_SHIFT       0
#define PE_COLOR_RGBAA_BLUE_MASK        0x0000001f
#define PE_COLOR_RGBAA_GET_BLUE(pe_color_rgbaa) \
        ((((unsigned long)(pe_color_rgbaa)) & PE_COLOR_RGBAA_BLUE_MASK) >> PE_COLOR_RGBAA_BLUE_SHIFT)
#define PE_COLOR_RGBAA_SET_BLUE(pe_color_rgbaa, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_COLOR_RGBAA_BLUE_SIZE)-1))); \
        pe_color_rgbaa = (((unsigned long)(pe_color_rgbaa)) & ~PE_COLOR_RGBAA_BLUE_MASK) | (((unsigned long)(blue)) << PE_COLOR_RGBAA_BLUE_SHIFT);\
}
#define PE_COLOR_RGBAA_GREEN_SIZE       6
#define PE_COLOR_RGBAA_GREEN_SHIFT      5
#define PE_COLOR_RGBAA_GREEN_MASK       0x000007e0
#define PE_COLOR_RGBAA_GET_GREEN(pe_color_rgbaa) \
        ((((unsigned long)(pe_color_rgbaa)) & PE_COLOR_RGBAA_GREEN_MASK) >> PE_COLOR_RGBAA_GREEN_SHIFT)
#define PE_COLOR_RGBAA_SET_GREEN(pe_color_rgbaa, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_COLOR_RGBAA_GREEN_SIZE)-1))); \
        pe_color_rgbaa = (((unsigned long)(pe_color_rgbaa)) & ~PE_COLOR_RGBAA_GREEN_MASK) | (((unsigned long)(green)) << PE_COLOR_RGBAA_GREEN_SHIFT);\
}
#define PE_COLOR_RGBAA_RED_SIZE 5
#define PE_COLOR_RGBAA_RED_SHIFT        11
#define PE_COLOR_RGBAA_RED_MASK 0x0000f800
#define PE_COLOR_RGBAA_GET_RED(pe_color_rgbaa) \
        ((((unsigned long)(pe_color_rgbaa)) & PE_COLOR_RGBAA_RED_MASK) >> PE_COLOR_RGBAA_RED_SHIFT)
#define PE_COLOR_RGBAA_SET_RED(pe_color_rgbaa, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_COLOR_RGBAA_RED_SIZE)-1))); \
        pe_color_rgbaa = (((unsigned long)(pe_color_rgbaa)) & ~PE_COLOR_RGBAA_RED_MASK) | (((unsigned long)(red)) << PE_COLOR_RGBAA_RED_SHIFT);\
}
#define PE_COLOR_RGBAA_TOTAL_SIZE       16
#define PE_COLOR_RGBAA(blue, green, red) \
        ((((unsigned long)(blue)) << PE_COLOR_RGBAA_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_COLOR_RGBAA_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_COLOR_RGBAA_RED_SHIFT))

/*
 *  pe_tex_copy_i4 struct
 */
#define PE_TEX_COPY_I4_I1_SIZE  4
#define PE_TEX_COPY_I4_I1_SHIFT 0
#define PE_TEX_COPY_I4_I1_MASK  0x0000000f
#define PE_TEX_COPY_I4_GET_I1(pe_tex_copy_i4) \
        ((((unsigned long)(pe_tex_copy_i4)) & PE_TEX_COPY_I4_I1_MASK) >> PE_TEX_COPY_I4_I1_SHIFT)
#define PE_TEX_COPY_I4_SET_I1(pe_tex_copy_i4, i1) { \
        FDL_ASSERT(!((i1) & ~((1 << PE_TEX_COPY_I4_I1_SIZE)-1))); \
        pe_tex_copy_i4 = (((unsigned long)(pe_tex_copy_i4)) & ~PE_TEX_COPY_I4_I1_MASK) | (((unsigned long)(i1)) << PE_TEX_COPY_I4_I1_SHIFT);\
}
#define PE_TEX_COPY_I4_I0_SIZE  4
#define PE_TEX_COPY_I4_I0_SHIFT 4
#define PE_TEX_COPY_I4_I0_MASK  0x000000f0
#define PE_TEX_COPY_I4_GET_I0(pe_tex_copy_i4) \
        ((((unsigned long)(pe_tex_copy_i4)) & PE_TEX_COPY_I4_I0_MASK) >> PE_TEX_COPY_I4_I0_SHIFT)
#define PE_TEX_COPY_I4_SET_I0(pe_tex_copy_i4, i0) { \
        FDL_ASSERT(!((i0) & ~((1 << PE_TEX_COPY_I4_I0_SIZE)-1))); \
        pe_tex_copy_i4 = (((unsigned long)(pe_tex_copy_i4)) & ~PE_TEX_COPY_I4_I0_MASK) | (((unsigned long)(i0)) << PE_TEX_COPY_I4_I0_SHIFT);\
}
#define PE_TEX_COPY_I4_TOTAL_SIZE       8
#define PE_TEX_COPY_I4(i1, i0) \
        ((((unsigned long)(i1)) << PE_TEX_COPY_I4_I1_SHIFT) | \
         (((unsigned long)(i0)) << PE_TEX_COPY_I4_I0_SHIFT))

/*
 *  pe_tex_copy_ia4 struct
 */
#define PE_TEX_COPY_IA4_I_SIZE  4
#define PE_TEX_COPY_IA4_I_SHIFT 0
#define PE_TEX_COPY_IA4_I_MASK  0x0000000f
#define PE_TEX_COPY_IA4_GET_I(pe_tex_copy_ia4) \
        ((((unsigned long)(pe_tex_copy_ia4)) & PE_TEX_COPY_IA4_I_MASK) >> PE_TEX_COPY_IA4_I_SHIFT)
#define PE_TEX_COPY_IA4_SET_I(pe_tex_copy_ia4, i) { \
        FDL_ASSERT(!((i) & ~((1 << PE_TEX_COPY_IA4_I_SIZE)-1))); \
        pe_tex_copy_ia4 = (((unsigned long)(pe_tex_copy_ia4)) & ~PE_TEX_COPY_IA4_I_MASK) | (((unsigned long)(i)) << PE_TEX_COPY_IA4_I_SHIFT);\
}
#define PE_TEX_COPY_IA4_ALPHA_SIZE      4
#define PE_TEX_COPY_IA4_ALPHA_SHIFT     4
#define PE_TEX_COPY_IA4_ALPHA_MASK      0x000000f0
#define PE_TEX_COPY_IA4_GET_ALPHA(pe_tex_copy_ia4) \
        ((((unsigned long)(pe_tex_copy_ia4)) & PE_TEX_COPY_IA4_ALPHA_MASK) >> PE_TEX_COPY_IA4_ALPHA_SHIFT)
#define PE_TEX_COPY_IA4_SET_ALPHA(pe_tex_copy_ia4, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_TEX_COPY_IA4_ALPHA_SIZE)-1))); \
        pe_tex_copy_ia4 = (((unsigned long)(pe_tex_copy_ia4)) & ~PE_TEX_COPY_IA4_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_TEX_COPY_IA4_ALPHA_SHIFT);\
}
#define PE_TEX_COPY_IA4_TOTAL_SIZE      8
#define PE_TEX_COPY_IA4(i, alpha) \
        ((((unsigned long)(i)) << PE_TEX_COPY_IA4_I_SHIFT) | \
         (((unsigned long)(alpha)) << PE_TEX_COPY_IA4_ALPHA_SHIFT))

/*
 *  pe_tex_copy_ia8 struct
 */
#define PE_TEX_COPY_IA8_I_SIZE  8
#define PE_TEX_COPY_IA8_I_SHIFT 0
#define PE_TEX_COPY_IA8_I_MASK  0x000000ff
#define PE_TEX_COPY_IA8_GET_I(pe_tex_copy_ia8) \
        ((((unsigned long)(pe_tex_copy_ia8)) & PE_TEX_COPY_IA8_I_MASK) >> PE_TEX_COPY_IA8_I_SHIFT)
#define PE_TEX_COPY_IA8_SET_I(pe_tex_copy_ia8, i) { \
        FDL_ASSERT(!((i) & ~((1 << PE_TEX_COPY_IA8_I_SIZE)-1))); \
        pe_tex_copy_ia8 = (((unsigned long)(pe_tex_copy_ia8)) & ~PE_TEX_COPY_IA8_I_MASK) | (((unsigned long)(i)) << PE_TEX_COPY_IA8_I_SHIFT);\
}
#define PE_TEX_COPY_IA8_ALPHA_SIZE      8
#define PE_TEX_COPY_IA8_ALPHA_SHIFT     8
#define PE_TEX_COPY_IA8_ALPHA_MASK      0x0000ff00
#define PE_TEX_COPY_IA8_GET_ALPHA(pe_tex_copy_ia8) \
        ((((unsigned long)(pe_tex_copy_ia8)) & PE_TEX_COPY_IA8_ALPHA_MASK) >> PE_TEX_COPY_IA8_ALPHA_SHIFT)
#define PE_TEX_COPY_IA8_SET_ALPHA(pe_tex_copy_ia8, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_TEX_COPY_IA8_ALPHA_SIZE)-1))); \
        pe_tex_copy_ia8 = (((unsigned long)(pe_tex_copy_ia8)) & ~PE_TEX_COPY_IA8_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_TEX_COPY_IA8_ALPHA_SHIFT);\
}
#define PE_TEX_COPY_IA8_TOTAL_SIZE      16
#define PE_TEX_COPY_IA8(i, alpha) \
        ((((unsigned long)(i)) << PE_TEX_COPY_IA8_I_SHIFT) | \
         (((unsigned long)(alpha)) << PE_TEX_COPY_IA8_ALPHA_SHIFT))

/*
 *  pe_tex_copy_r5g6b5 struct
 */
#define PE_TEX_COPY_R5G6B5_BLUE_SIZE    5
#define PE_TEX_COPY_R5G6B5_BLUE_SHIFT   0
#define PE_TEX_COPY_R5G6B5_BLUE_MASK    0x0000001f
#define PE_TEX_COPY_R5G6B5_GET_BLUE(pe_tex_copy_r5g6b5) \
        ((((unsigned long)(pe_tex_copy_r5g6b5)) & PE_TEX_COPY_R5G6B5_BLUE_MASK) >> PE_TEX_COPY_R5G6B5_BLUE_SHIFT)
#define PE_TEX_COPY_R5G6B5_SET_BLUE(pe_tex_copy_r5g6b5, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_TEX_COPY_R5G6B5_BLUE_SIZE)-1))); \
        pe_tex_copy_r5g6b5 = (((unsigned long)(pe_tex_copy_r5g6b5)) & ~PE_TEX_COPY_R5G6B5_BLUE_MASK) | (((unsigned long)(blue)) << PE_TEX_COPY_R5G6B5_BLUE_SHIFT);\
}
#define PE_TEX_COPY_R5G6B5_GREEN_SIZE   6
#define PE_TEX_COPY_R5G6B5_GREEN_SHIFT  5
#define PE_TEX_COPY_R5G6B5_GREEN_MASK   0x000007e0
#define PE_TEX_COPY_R5G6B5_GET_GREEN(pe_tex_copy_r5g6b5) \
        ((((unsigned long)(pe_tex_copy_r5g6b5)) & PE_TEX_COPY_R5G6B5_GREEN_MASK) >> PE_TEX_COPY_R5G6B5_GREEN_SHIFT)
#define PE_TEX_COPY_R5G6B5_SET_GREEN(pe_tex_copy_r5g6b5, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_TEX_COPY_R5G6B5_GREEN_SIZE)-1))); \
        pe_tex_copy_r5g6b5 = (((unsigned long)(pe_tex_copy_r5g6b5)) & ~PE_TEX_COPY_R5G6B5_GREEN_MASK) | (((unsigned long)(green)) << PE_TEX_COPY_R5G6B5_GREEN_SHIFT);\
}
#define PE_TEX_COPY_R5G6B5_RED_SIZE     5
#define PE_TEX_COPY_R5G6B5_RED_SHIFT    11
#define PE_TEX_COPY_R5G6B5_RED_MASK     0x0000f800
#define PE_TEX_COPY_R5G6B5_GET_RED(pe_tex_copy_r5g6b5) \
        ((((unsigned long)(pe_tex_copy_r5g6b5)) & PE_TEX_COPY_R5G6B5_RED_MASK) >> PE_TEX_COPY_R5G6B5_RED_SHIFT)
#define PE_TEX_COPY_R5G6B5_SET_RED(pe_tex_copy_r5g6b5, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_TEX_COPY_R5G6B5_RED_SIZE)-1))); \
        pe_tex_copy_r5g6b5 = (((unsigned long)(pe_tex_copy_r5g6b5)) & ~PE_TEX_COPY_R5G6B5_RED_MASK) | (((unsigned long)(red)) << PE_TEX_COPY_R5G6B5_RED_SHIFT);\
}
#define PE_TEX_COPY_R5G6B5_TOTAL_SIZE   16
#define PE_TEX_COPY_R5G6B5(blue, green, red) \
        ((((unsigned long)(blue)) << PE_TEX_COPY_R5G6B5_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_TEX_COPY_R5G6B5_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_TEX_COPY_R5G6B5_RED_SHIFT))

/*
 *  pe_alpha_format enum
 */
#define RGB4A3  0x00000000
#define RGB5    0x00000001

/*
 *  pe_tex_copy_rgb5 struct
 */
#define PE_TEX_COPY_RGB5_BLUE_SIZE      5
#define PE_TEX_COPY_RGB5_BLUE_SHIFT     0
#define PE_TEX_COPY_RGB5_BLUE_MASK      0x0000001f
#define PE_TEX_COPY_RGB5_GET_BLUE(pe_tex_copy_rgb5) \
        ((((unsigned long)(pe_tex_copy_rgb5)) & PE_TEX_COPY_RGB5_BLUE_MASK) >> PE_TEX_COPY_RGB5_BLUE_SHIFT)
#define PE_TEX_COPY_RGB5_SET_BLUE(pe_tex_copy_rgb5, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_TEX_COPY_RGB5_BLUE_SIZE)-1))); \
        pe_tex_copy_rgb5 = (((unsigned long)(pe_tex_copy_rgb5)) & ~PE_TEX_COPY_RGB5_BLUE_MASK) | (((unsigned long)(blue)) << PE_TEX_COPY_RGB5_BLUE_SHIFT);\
}
#define PE_TEX_COPY_RGB5_GREEN_SIZE     5
#define PE_TEX_COPY_RGB5_GREEN_SHIFT    5
#define PE_TEX_COPY_RGB5_GREEN_MASK     0x000003e0
#define PE_TEX_COPY_RGB5_GET_GREEN(pe_tex_copy_rgb5) \
        ((((unsigned long)(pe_tex_copy_rgb5)) & PE_TEX_COPY_RGB5_GREEN_MASK) >> PE_TEX_COPY_RGB5_GREEN_SHIFT)
#define PE_TEX_COPY_RGB5_SET_GREEN(pe_tex_copy_rgb5, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_TEX_COPY_RGB5_GREEN_SIZE)-1))); \
        pe_tex_copy_rgb5 = (((unsigned long)(pe_tex_copy_rgb5)) & ~PE_TEX_COPY_RGB5_GREEN_MASK) | (((unsigned long)(green)) << PE_TEX_COPY_RGB5_GREEN_SHIFT);\
}
#define PE_TEX_COPY_RGB5_RED_SIZE       5
#define PE_TEX_COPY_RGB5_RED_SHIFT      10
#define PE_TEX_COPY_RGB5_RED_MASK       0x00007c00
#define PE_TEX_COPY_RGB5_GET_RED(pe_tex_copy_rgb5) \
        ((((unsigned long)(pe_tex_copy_rgb5)) & PE_TEX_COPY_RGB5_RED_MASK) >> PE_TEX_COPY_RGB5_RED_SHIFT)
#define PE_TEX_COPY_RGB5_SET_RED(pe_tex_copy_rgb5, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_TEX_COPY_RGB5_RED_SIZE)-1))); \
        pe_tex_copy_rgb5 = (((unsigned long)(pe_tex_copy_rgb5)) & ~PE_TEX_COPY_RGB5_RED_MASK) | (((unsigned long)(red)) << PE_TEX_COPY_RGB5_RED_SHIFT);\
}
#define PE_TEX_COPY_RGB5_FORMAT_SIZE    1
#define PE_TEX_COPY_RGB5_FORMAT_SHIFT   15
#define PE_TEX_COPY_RGB5_FORMAT_MASK    0x00008000
#define PE_TEX_COPY_RGB5_GET_FORMAT(pe_tex_copy_rgb5) \
        ((((unsigned long)(pe_tex_copy_rgb5)) & PE_TEX_COPY_RGB5_FORMAT_MASK) >> PE_TEX_COPY_RGB5_FORMAT_SHIFT)
#define PE_TEX_COPY_RGB5_SET_FORMAT(pe_tex_copy_rgb5, format) { \
        FDL_ASSERT(!((format) & ~((1 << PE_TEX_COPY_RGB5_FORMAT_SIZE)-1))); \
        pe_tex_copy_rgb5 = (((unsigned long)(pe_tex_copy_rgb5)) & ~PE_TEX_COPY_RGB5_FORMAT_MASK) | (((unsigned long)(format)) << PE_TEX_COPY_RGB5_FORMAT_SHIFT);\
}
#define PE_TEX_COPY_RGB5_TOTAL_SIZE     16
#define PE_TEX_COPY_RGB5(blue, green, red, format) \
        ((((unsigned long)(blue)) << PE_TEX_COPY_RGB5_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_TEX_COPY_RGB5_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_TEX_COPY_RGB5_RED_SHIFT) | \
         (((unsigned long)(format)) << PE_TEX_COPY_RGB5_FORMAT_SHIFT))

/*
 *  pe_tex_copy_rgb4a3 struct
 */
#define PE_TEX_COPY_RGB4A3_BLUE_SIZE    4
#define PE_TEX_COPY_RGB4A3_BLUE_SHIFT   0
#define PE_TEX_COPY_RGB4A3_BLUE_MASK    0x0000000f
#define PE_TEX_COPY_RGB4A3_GET_BLUE(pe_tex_copy_rgb4a3) \
        ((((unsigned long)(pe_tex_copy_rgb4a3)) & PE_TEX_COPY_RGB4A3_BLUE_MASK) >> PE_TEX_COPY_RGB4A3_BLUE_SHIFT)
#define PE_TEX_COPY_RGB4A3_SET_BLUE(pe_tex_copy_rgb4a3, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_TEX_COPY_RGB4A3_BLUE_SIZE)-1))); \
        pe_tex_copy_rgb4a3 = (((unsigned long)(pe_tex_copy_rgb4a3)) & ~PE_TEX_COPY_RGB4A3_BLUE_MASK) | (((unsigned long)(blue)) << PE_TEX_COPY_RGB4A3_BLUE_SHIFT);\
}
#define PE_TEX_COPY_RGB4A3_GREEN_SIZE   4
#define PE_TEX_COPY_RGB4A3_GREEN_SHIFT  4
#define PE_TEX_COPY_RGB4A3_GREEN_MASK   0x000000f0
#define PE_TEX_COPY_RGB4A3_GET_GREEN(pe_tex_copy_rgb4a3) \
        ((((unsigned long)(pe_tex_copy_rgb4a3)) & PE_TEX_COPY_RGB4A3_GREEN_MASK) >> PE_TEX_COPY_RGB4A3_GREEN_SHIFT)
#define PE_TEX_COPY_RGB4A3_SET_GREEN(pe_tex_copy_rgb4a3, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_TEX_COPY_RGB4A3_GREEN_SIZE)-1))); \
        pe_tex_copy_rgb4a3 = (((unsigned long)(pe_tex_copy_rgb4a3)) & ~PE_TEX_COPY_RGB4A3_GREEN_MASK) | (((unsigned long)(green)) << PE_TEX_COPY_RGB4A3_GREEN_SHIFT);\
}
#define PE_TEX_COPY_RGB4A3_RED_SIZE     4
#define PE_TEX_COPY_RGB4A3_RED_SHIFT    8
#define PE_TEX_COPY_RGB4A3_RED_MASK     0x00000f00
#define PE_TEX_COPY_RGB4A3_GET_RED(pe_tex_copy_rgb4a3) \
        ((((unsigned long)(pe_tex_copy_rgb4a3)) & PE_TEX_COPY_RGB4A3_RED_MASK) >> PE_TEX_COPY_RGB4A3_RED_SHIFT)
#define PE_TEX_COPY_RGB4A3_SET_RED(pe_tex_copy_rgb4a3, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_TEX_COPY_RGB4A3_RED_SIZE)-1))); \
        pe_tex_copy_rgb4a3 = (((unsigned long)(pe_tex_copy_rgb4a3)) & ~PE_TEX_COPY_RGB4A3_RED_MASK) | (((unsigned long)(red)) << PE_TEX_COPY_RGB4A3_RED_SHIFT);\
}
#define PE_TEX_COPY_RGB4A3_ALPHA_SIZE   3
#define PE_TEX_COPY_RGB4A3_ALPHA_SHIFT  12
#define PE_TEX_COPY_RGB4A3_ALPHA_MASK   0x00007000
#define PE_TEX_COPY_RGB4A3_GET_ALPHA(pe_tex_copy_rgb4a3) \
        ((((unsigned long)(pe_tex_copy_rgb4a3)) & PE_TEX_COPY_RGB4A3_ALPHA_MASK) >> PE_TEX_COPY_RGB4A3_ALPHA_SHIFT)
#define PE_TEX_COPY_RGB4A3_SET_ALPHA(pe_tex_copy_rgb4a3, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_TEX_COPY_RGB4A3_ALPHA_SIZE)-1))); \
        pe_tex_copy_rgb4a3 = (((unsigned long)(pe_tex_copy_rgb4a3)) & ~PE_TEX_COPY_RGB4A3_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_TEX_COPY_RGB4A3_ALPHA_SHIFT);\
}
#define PE_TEX_COPY_RGB4A3_FORMAT_SIZE  1
#define PE_TEX_COPY_RGB4A3_FORMAT_SHIFT 15
#define PE_TEX_COPY_RGB4A3_FORMAT_MASK  0x00008000
#define PE_TEX_COPY_RGB4A3_GET_FORMAT(pe_tex_copy_rgb4a3) \
        ((((unsigned long)(pe_tex_copy_rgb4a3)) & PE_TEX_COPY_RGB4A3_FORMAT_MASK) >> PE_TEX_COPY_RGB4A3_FORMAT_SHIFT)
#define PE_TEX_COPY_RGB4A3_SET_FORMAT(pe_tex_copy_rgb4a3, format) { \
        FDL_ASSERT(!((format) & ~((1 << PE_TEX_COPY_RGB4A3_FORMAT_SIZE)-1))); \
        pe_tex_copy_rgb4a3 = (((unsigned long)(pe_tex_copy_rgb4a3)) & ~PE_TEX_COPY_RGB4A3_FORMAT_MASK) | (((unsigned long)(format)) << PE_TEX_COPY_RGB4A3_FORMAT_SHIFT);\
}
#define PE_TEX_COPY_RGB4A3_TOTAL_SIZE   16
#define PE_TEX_COPY_RGB4A3(blue, green, red, alpha, format) \
        ((((unsigned long)(blue)) << PE_TEX_COPY_RGB4A3_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_TEX_COPY_RGB4A3_GREEN_SHIFT) | \
         (((unsigned long)(red)) << PE_TEX_COPY_RGB4A3_RED_SHIFT) | \
         (((unsigned long)(alpha)) << PE_TEX_COPY_RGB4A3_ALPHA_SHIFT) | \
         (((unsigned long)(format)) << PE_TEX_COPY_RGB4A3_FORMAT_SHIFT))

/*
 *  pe_tex_copy_rgba8 struct
 */
#define PE_TEX_COPY_RGBA8_RED_SIZE      8
#define PE_TEX_COPY_RGBA8_RED_SHIFT     0
#define PE_TEX_COPY_RGBA8_RED_MASK      0x000000ff
#define PE_TEX_COPY_RGBA8_GET_RED(pe_tex_copy_rgba8) \
        ((((unsigned long)(pe_tex_copy_rgba8)) & PE_TEX_COPY_RGBA8_RED_MASK) >> PE_TEX_COPY_RGBA8_RED_SHIFT)
#define PE_TEX_COPY_RGBA8_SET_RED(pe_tex_copy_rgba8, red) { \
        FDL_ASSERT(!((red) & ~((1 << PE_TEX_COPY_RGBA8_RED_SIZE)-1))); \
        pe_tex_copy_rgba8 = (((unsigned long)(pe_tex_copy_rgba8)) & ~PE_TEX_COPY_RGBA8_RED_MASK) | (((unsigned long)(red)) << PE_TEX_COPY_RGBA8_RED_SHIFT);\
}
#define PE_TEX_COPY_RGBA8_ALPHA_SIZE    8
#define PE_TEX_COPY_RGBA8_ALPHA_SHIFT   8
#define PE_TEX_COPY_RGBA8_ALPHA_MASK    0x0000ff00
#define PE_TEX_COPY_RGBA8_GET_ALPHA(pe_tex_copy_rgba8) \
        ((((unsigned long)(pe_tex_copy_rgba8)) & PE_TEX_COPY_RGBA8_ALPHA_MASK) >> PE_TEX_COPY_RGBA8_ALPHA_SHIFT)
#define PE_TEX_COPY_RGBA8_SET_ALPHA(pe_tex_copy_rgba8, alpha) { \
        FDL_ASSERT(!((alpha) & ~((1 << PE_TEX_COPY_RGBA8_ALPHA_SIZE)-1))); \
        pe_tex_copy_rgba8 = (((unsigned long)(pe_tex_copy_rgba8)) & ~PE_TEX_COPY_RGBA8_ALPHA_MASK) | (((unsigned long)(alpha)) << PE_TEX_COPY_RGBA8_ALPHA_SHIFT);\
}
#define PE_TEX_COPY_RGBA8_BLUE_SIZE     8
#define PE_TEX_COPY_RGBA8_BLUE_SHIFT    16
#define PE_TEX_COPY_RGBA8_BLUE_MASK     0x00ff0000
#define PE_TEX_COPY_RGBA8_GET_BLUE(pe_tex_copy_rgba8) \
        ((((unsigned long)(pe_tex_copy_rgba8)) & PE_TEX_COPY_RGBA8_BLUE_MASK) >> PE_TEX_COPY_RGBA8_BLUE_SHIFT)
#define PE_TEX_COPY_RGBA8_SET_BLUE(pe_tex_copy_rgba8, blue) { \
        FDL_ASSERT(!((blue) & ~((1 << PE_TEX_COPY_RGBA8_BLUE_SIZE)-1))); \
        pe_tex_copy_rgba8 = (((unsigned long)(pe_tex_copy_rgba8)) & ~PE_TEX_COPY_RGBA8_BLUE_MASK) | (((unsigned long)(blue)) << PE_TEX_COPY_RGBA8_BLUE_SHIFT);\
}
#define PE_TEX_COPY_RGBA8_GREEN_SIZE    8
#define PE_TEX_COPY_RGBA8_GREEN_SHIFT   24
#define PE_TEX_COPY_RGBA8_GREEN_MASK    0xff000000
#define PE_TEX_COPY_RGBA8_GET_GREEN(pe_tex_copy_rgba8) \
        ((((unsigned long)(pe_tex_copy_rgba8)) & PE_TEX_COPY_RGBA8_GREEN_MASK) >> PE_TEX_COPY_RGBA8_GREEN_SHIFT)
#define PE_TEX_COPY_RGBA8_SET_GREEN(pe_tex_copy_rgba8, green) { \
        FDL_ASSERT(!((green) & ~((1 << PE_TEX_COPY_RGBA8_GREEN_SIZE)-1))); \
        pe_tex_copy_rgba8 = (((unsigned long)(pe_tex_copy_rgba8)) & ~PE_TEX_COPY_RGBA8_GREEN_MASK) | (((unsigned long)(green)) << PE_TEX_COPY_RGBA8_GREEN_SHIFT);\
}
#define PE_TEX_COPY_RGBA8_TOTAL_SIZE    32
#define PE_TEX_COPY_RGBA8(red, alpha, blue, green) \
        ((((unsigned long)(red)) << PE_TEX_COPY_RGBA8_RED_SHIFT) | \
         (((unsigned long)(alpha)) << PE_TEX_COPY_RGBA8_ALPHA_SHIFT) | \
         (((unsigned long)(blue)) << PE_TEX_COPY_RGBA8_BLUE_SHIFT) | \
         (((unsigned long)(green)) << PE_TEX_COPY_RGBA8_GREEN_SHIFT))

/*
 *  pe_mask struct
 */
#define PE_MASK_M0_SIZE 3
#define PE_MASK_M0_SHIFT        0
#define PE_MASK_M0_MASK 0x00000007
#define PE_MASK_GET_M0(pe_mask) \
        ((((unsigned long)(pe_mask)) & PE_MASK_M0_MASK) >> PE_MASK_M0_SHIFT)
#define PE_MASK_SET_M0(pe_mask, m0) { \
        FDL_ASSERT(!((m0) & ~((1 << PE_MASK_M0_SIZE)-1))); \
        pe_mask = (((unsigned long)(pe_mask)) & ~PE_MASK_M0_MASK) | (((unsigned long)(m0)) << PE_MASK_M0_SHIFT);\
}
#define PE_MASK_M1_SIZE 3
#define PE_MASK_M1_SHIFT        3
#define PE_MASK_M1_MASK 0x00000038
#define PE_MASK_GET_M1(pe_mask) \
        ((((unsigned long)(pe_mask)) & PE_MASK_M1_MASK) >> PE_MASK_M1_SHIFT)
#define PE_MASK_SET_M1(pe_mask, m1) { \
        FDL_ASSERT(!((m1) & ~((1 << PE_MASK_M1_SIZE)-1))); \
        pe_mask = (((unsigned long)(pe_mask)) & ~PE_MASK_M1_MASK) | (((unsigned long)(m1)) << PE_MASK_M1_SHIFT);\
}
#define PE_MASK_M2_SIZE 3
#define PE_MASK_M2_SHIFT        6
#define PE_MASK_M2_MASK 0x000001c0
#define PE_MASK_GET_M2(pe_mask) \
        ((((unsigned long)(pe_mask)) & PE_MASK_M2_MASK) >> PE_MASK_M2_SHIFT)
#define PE_MASK_SET_M2(pe_mask, m2) { \
        FDL_ASSERT(!((m2) & ~((1 << PE_MASK_M2_SIZE)-1))); \
        pe_mask = (((unsigned long)(pe_mask)) & ~PE_MASK_M2_MASK) | (((unsigned long)(m2)) << PE_MASK_M2_SHIFT);\
}
#define PE_MASK_M3_SIZE 3
#define PE_MASK_M3_SHIFT        9
#define PE_MASK_M3_MASK 0x00000e00
#define PE_MASK_GET_M3(pe_mask) \
        ((((unsigned long)(pe_mask)) & PE_MASK_M3_MASK) >> PE_MASK_M3_SHIFT)
#define PE_MASK_SET_M3(pe_mask, m3) { \
        FDL_ASSERT(!((m3) & ~((1 << PE_MASK_M3_SIZE)-1))); \
        pe_mask = (((unsigned long)(pe_mask)) & ~PE_MASK_M3_MASK) | (((unsigned long)(m3)) << PE_MASK_M3_SHIFT);\
}
#define PE_MASK_TOTAL_SIZE      12
#define PE_MASK(m0, m1, m2, m3) \
        ((((unsigned long)(m0)) << PE_MASK_M0_SHIFT) | \
         (((unsigned long)(m1)) << PE_MASK_M1_SHIFT) | \
         (((unsigned long)(m2)) << PE_MASK_M2_SHIFT) | \
         (((unsigned long)(m3)) << PE_MASK_M3_SHIFT))

/*
 *  chicken_bits value
 */
#define REVB_USE_PI_Z_FIX       0x1
#define REVB_USE_TXCPY_FMT      0x1
#define REVB_USE_CC_BIT 0x1
#define REVB_USE_BLEND_BIT      0x1

/*
 *  pe_copy_hd struct
 */
#define PE_COPY_HD_SCALE_RST_VALUE_SIZE 9
#define PE_COPY_HD_SCALE_RST_VALUE_SHIFT        0
#define PE_COPY_HD_SCALE_RST_VALUE_MASK 0x000001ff
#define PE_COPY_HD_GET_SCALE_RST_VALUE(pe_copy_hd) \
        ((((unsigned long)(pe_copy_hd)) & PE_COPY_HD_SCALE_RST_VALUE_MASK) >> PE_COPY_HD_SCALE_RST_VALUE_SHIFT)
#define PE_COPY_HD_SET_SCALE_RST_VALUE(pe_copy_hd, scale_rst_value) { \
        FDL_ASSERT(!((scale_rst_value) & ~((1 << PE_COPY_HD_SCALE_RST_VALUE_SIZE)-1))); \
        pe_copy_hd = (((unsigned long)(pe_copy_hd)) & ~PE_COPY_HD_SCALE_RST_VALUE_MASK) | (((unsigned long)(scale_rst_value)) << PE_COPY_HD_SCALE_RST_VALUE_SHIFT);\
}
#define PE_COPY_HD_ALPHA_RST_VALUE_SIZE 9
#define PE_COPY_HD_ALPHA_RST_VALUE_SHIFT        9
#define PE_COPY_HD_ALPHA_RST_VALUE_MASK 0x0003fe00
#define PE_COPY_HD_GET_ALPHA_RST_VALUE(pe_copy_hd) \
        ((((unsigned long)(pe_copy_hd)) & PE_COPY_HD_ALPHA_RST_VALUE_MASK) >> PE_COPY_HD_ALPHA_RST_VALUE_SHIFT)
#define PE_COPY_HD_SET_ALPHA_RST_VALUE(pe_copy_hd, alpha_rst_value) { \
        FDL_ASSERT(!((alpha_rst_value) & ~((1 << PE_COPY_HD_ALPHA_RST_VALUE_SIZE)-1))); \
        pe_copy_hd = (((unsigned long)(pe_copy_hd)) & ~PE_COPY_HD_ALPHA_RST_VALUE_MASK) | (((unsigned long)(alpha_rst_value)) << PE_COPY_HD_ALPHA_RST_VALUE_SHIFT);\
}
#define PE_COPY_HD_RST_VALUE_ENABLE_SIZE        1
#define PE_COPY_HD_RST_VALUE_ENABLE_SHIFT       18
#define PE_COPY_HD_RST_VALUE_ENABLE_MASK        0x00040000
#define PE_COPY_HD_GET_RST_VALUE_ENABLE(pe_copy_hd) \
        ((((unsigned long)(pe_copy_hd)) & PE_COPY_HD_RST_VALUE_ENABLE_MASK) >> PE_COPY_HD_RST_VALUE_ENABLE_SHIFT)
#define PE_COPY_HD_SET_RST_VALUE_ENABLE(pe_copy_hd, rst_value_enable) { \
        FDL_ASSERT(!((rst_value_enable) & ~((1 << PE_COPY_HD_RST_VALUE_ENABLE_SIZE)-1))); \
        pe_copy_hd = (((unsigned long)(pe_copy_hd)) & ~PE_COPY_HD_RST_VALUE_ENABLE_MASK) | (((unsigned long)(rst_value_enable)) << PE_COPY_HD_RST_VALUE_ENABLE_SHIFT);\
}
#define PE_COPY_HD_UV_HFILTER_DISABLE_SIZE      1
#define PE_COPY_HD_UV_HFILTER_DISABLE_SHIFT     19
#define PE_COPY_HD_UV_HFILTER_DISABLE_MASK      0x00080000
#define PE_COPY_HD_GET_UV_HFILTER_DISABLE(pe_copy_hd) \
        ((((unsigned long)(pe_copy_hd)) & PE_COPY_HD_UV_HFILTER_DISABLE_MASK) >> PE_COPY_HD_UV_HFILTER_DISABLE_SHIFT)
#define PE_COPY_HD_SET_UV_HFILTER_DISABLE(pe_copy_hd, uv_hfilter_disable) { \
        FDL_ASSERT(!((uv_hfilter_disable) & ~((1 << PE_COPY_HD_UV_HFILTER_DISABLE_SIZE)-1))); \
        pe_copy_hd = (((unsigned long)(pe_copy_hd)) & ~PE_COPY_HD_UV_HFILTER_DISABLE_MASK) | (((unsigned long)(uv_hfilter_disable)) << PE_COPY_HD_UV_HFILTER_DISABLE_SHIFT);\
}
#define PE_COPY_HD_TOTAL_SIZE   20
#define PE_COPY_HD(scale_rst_value, alpha_rst_value, rst_value_enable, uv_hfilter_disable) \
        ((((unsigned long)(scale_rst_value)) << PE_COPY_HD_SCALE_RST_VALUE_SHIFT) | \
         (((unsigned long)(alpha_rst_value)) << PE_COPY_HD_ALPHA_RST_VALUE_SHIFT) | \
         (((unsigned long)(rst_value_enable)) << PE_COPY_HD_RST_VALUE_ENABLE_SHIFT) | \
         (((unsigned long)(uv_hfilter_disable)) << PE_COPY_HD_UV_HFILTER_DISABLE_SHIFT))


#endif /* __FDL_PE_REG_H__ */
