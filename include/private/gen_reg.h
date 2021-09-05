/*
 *  gen_reg.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from gen_reg.fdl
 */

#ifndef __GEN_REG_H__
#define __GEN_REG_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  gen_reject enum
 */
#define GEN_REJECT_NONE	0x00000000
#define GEN_REJECT_FRONT	0x00000001
#define GEN_REJECT_BACK	0x00000002
#define GEN_REJECT_ALL	0x00000003

/*
 *  gen_mode struct
 */
#define GEN_MODE_NTEX_SIZE	4
#define GEN_MODE_NTEX_SHIFT	0
#define GEN_MODE_NTEX_MASK	0x0000000f
#define GEN_MODE_GET_NTEX(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_NTEX_MASK) >> GEN_MODE_NTEX_SHIFT)
#define GEN_MODE_SET_NTEX(gen_mode, ntex) { \
	FDL_ASSERT(!((ntex) & ~((1 << GEN_MODE_NTEX_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_NTEX_MASK) | (((unsigned long)(ntex)) << GEN_MODE_NTEX_SHIFT);\
}
#define GEN_MODE_NCOL_SIZE	3
#define GEN_MODE_NCOL_SHIFT	4
#define GEN_MODE_NCOL_MASK	0x00000070
#define GEN_MODE_GET_NCOL(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_NCOL_MASK) >> GEN_MODE_NCOL_SHIFT)
#define GEN_MODE_SET_NCOL(gen_mode, ncol) { \
	FDL_ASSERT(!((ncol) & ~((1 << GEN_MODE_NCOL_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_NCOL_MASK) | (((unsigned long)(ncol)) << GEN_MODE_NCOL_SHIFT);\
}
#define GEN_MODE_PAD0_SIZE	1
#define GEN_MODE_PAD0_SHIFT	7
#define GEN_MODE_PAD0_MASK	0x00000080
#define GEN_MODE_GET_PAD0(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_PAD0_MASK) >> GEN_MODE_PAD0_SHIFT)
#define GEN_MODE_SET_PAD0(gen_mode, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << GEN_MODE_PAD0_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_PAD0_MASK) | (((unsigned long)(pad0)) << GEN_MODE_PAD0_SHIFT);\
}
#define GEN_MODE_FLAT_EN_SIZE	1
#define GEN_MODE_FLAT_EN_SHIFT	8
#define GEN_MODE_FLAT_EN_MASK	0x00000100
#define GEN_MODE_GET_FLAT_EN(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_FLAT_EN_MASK) >> GEN_MODE_FLAT_EN_SHIFT)
#define GEN_MODE_SET_FLAT_EN(gen_mode, flat_en) { \
	FDL_ASSERT(!((flat_en) & ~((1 << GEN_MODE_FLAT_EN_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_FLAT_EN_MASK) | (((unsigned long)(flat_en)) << GEN_MODE_FLAT_EN_SHIFT);\
}
#define GEN_MODE_MS_EN_SIZE	1
#define GEN_MODE_MS_EN_SHIFT	9
#define GEN_MODE_MS_EN_MASK	0x00000200
#define GEN_MODE_GET_MS_EN(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_MS_EN_MASK) >> GEN_MODE_MS_EN_SHIFT)
#define GEN_MODE_SET_MS_EN(gen_mode, ms_en) { \
	FDL_ASSERT(!((ms_en) & ~((1 << GEN_MODE_MS_EN_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_MS_EN_MASK) | (((unsigned long)(ms_en)) << GEN_MODE_MS_EN_SHIFT);\
}
#define GEN_MODE_NTEV_SIZE	4
#define GEN_MODE_NTEV_SHIFT	10
#define GEN_MODE_NTEV_MASK	0x00003c00
#define GEN_MODE_GET_NTEV(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_NTEV_MASK) >> GEN_MODE_NTEV_SHIFT)
#define GEN_MODE_SET_NTEV(gen_mode, ntev) { \
	FDL_ASSERT(!((ntev) & ~((1 << GEN_MODE_NTEV_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_NTEV_MASK) | (((unsigned long)(ntev)) << GEN_MODE_NTEV_SHIFT);\
}
#define GEN_MODE_REJECT_EN_SIZE	2
#define GEN_MODE_REJECT_EN_SHIFT	14
#define GEN_MODE_REJECT_EN_MASK	0x0000c000
#define GEN_MODE_GET_REJECT_EN(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_REJECT_EN_MASK) >> GEN_MODE_REJECT_EN_SHIFT)
#define GEN_MODE_SET_REJECT_EN(gen_mode, reject_en) { \
	FDL_ASSERT(!((reject_en) & ~((1 << GEN_MODE_REJECT_EN_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_REJECT_EN_MASK) | (((unsigned long)(reject_en)) << GEN_MODE_REJECT_EN_SHIFT);\
}
#define GEN_MODE_NBMP_SIZE	3
#define GEN_MODE_NBMP_SHIFT	16
#define GEN_MODE_NBMP_MASK	0x00070000
#define GEN_MODE_GET_NBMP(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_NBMP_MASK) >> GEN_MODE_NBMP_SHIFT)
#define GEN_MODE_SET_NBMP(gen_mode, nbmp) { \
	FDL_ASSERT(!((nbmp) & ~((1 << GEN_MODE_NBMP_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_NBMP_MASK) | (((unsigned long)(nbmp)) << GEN_MODE_NBMP_SHIFT);\
}
#define GEN_MODE_ZFREEZE_SIZE	1
#define GEN_MODE_ZFREEZE_SHIFT	19
#define GEN_MODE_ZFREEZE_MASK	0x00080000
#define GEN_MODE_GET_ZFREEZE(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_ZFREEZE_MASK) >> GEN_MODE_ZFREEZE_SHIFT)
#define GEN_MODE_SET_ZFREEZE(gen_mode, zfreeze) { \
	FDL_ASSERT(!((zfreeze) & ~((1 << GEN_MODE_ZFREEZE_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_ZFREEZE_MASK) | (((unsigned long)(zfreeze)) << GEN_MODE_ZFREEZE_SHIFT);\
}
#define GEN_MODE_PAD1_SIZE	4
#define GEN_MODE_PAD1_SHIFT	20
#define GEN_MODE_PAD1_MASK	0x00f00000
#define GEN_MODE_GET_PAD1(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_PAD1_MASK) >> GEN_MODE_PAD1_SHIFT)
#define GEN_MODE_SET_PAD1(gen_mode, pad1) { \
	FDL_ASSERT(!((pad1) & ~((1 << GEN_MODE_PAD1_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_PAD1_MASK) | (((unsigned long)(pad1)) << GEN_MODE_PAD1_SHIFT);\
}
#define GEN_MODE_RID_SIZE	8
#define GEN_MODE_RID_SHIFT	24
#define GEN_MODE_RID_MASK	0xff000000
#define GEN_MODE_GET_RID(gen_mode) \
	((((unsigned long)(gen_mode)) & GEN_MODE_RID_MASK) >> GEN_MODE_RID_SHIFT)
#define GEN_MODE_SET_RID(gen_mode, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << GEN_MODE_RID_SIZE)-1))); \
	gen_mode = (((unsigned long)(gen_mode)) & ~GEN_MODE_RID_MASK) | (((unsigned long)(rid)) << GEN_MODE_RID_SHIFT);\
}
#define GEN_MODE_TOTAL_SIZE	32
#define GEN_MODE(ntex, ncol, flat_en, ms_en, ntev, reject_en, nbmp, zfreeze, rid) \
	((((unsigned long)(ntex)) << GEN_MODE_NTEX_SHIFT) | \
	 (((unsigned long)(ncol)) << GEN_MODE_NCOL_SHIFT) | \
	 (((unsigned long)(flat_en)) << GEN_MODE_FLAT_EN_SHIFT) | \
	 (((unsigned long)(ms_en)) << GEN_MODE_MS_EN_SHIFT) | \
	 (((unsigned long)(ntev)) << GEN_MODE_NTEV_SHIFT) | \
	 (((unsigned long)(reject_en)) << GEN_MODE_REJECT_EN_SHIFT) | \
	 (((unsigned long)(nbmp)) << GEN_MODE_NBMP_SHIFT) | \
	 (((unsigned long)(zfreeze)) << GEN_MODE_ZFREEZE_SHIFT) | \
	 (((unsigned long)(rid)) << GEN_MODE_RID_SHIFT))

typedef struct {
    unsigned long rid:GEN_MODE_RID_SIZE;
    unsigned long pad1:GEN_MODE_PAD1_SIZE;
    unsigned long zfreeze:GEN_MODE_ZFREEZE_SIZE;
    unsigned long nbmp:GEN_MODE_NBMP_SIZE;
    unsigned long reject_en:GEN_MODE_REJECT_EN_SIZE;
    unsigned long ntev:GEN_MODE_NTEV_SIZE;
    unsigned long ms_en:GEN_MODE_MS_EN_SIZE;
    unsigned long flat_en:GEN_MODE_FLAT_EN_SIZE;
    unsigned long pad0:GEN_MODE_PAD0_SIZE;
    unsigned long ncol:GEN_MODE_NCOL_SIZE;
    unsigned long ntex:GEN_MODE_NTEX_SIZE;
} gen_mode_t;

typedef union {
    unsigned long val;
    gen_mode_t f;
} gen_mode_u;

/*
 *  gen_msloc struct
 */
#define GEN_MSLOC_XS0_SIZE	4
#define GEN_MSLOC_XS0_SHIFT	0
#define GEN_MSLOC_XS0_MASK	0x0000000f
#define GEN_MSLOC_GET_XS0(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_XS0_MASK) >> GEN_MSLOC_XS0_SHIFT)
#define GEN_MSLOC_SET_XS0(gen_msloc, xs0) { \
	FDL_ASSERT(!((xs0) & ~((1 << GEN_MSLOC_XS0_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_XS0_MASK) | (((unsigned long)(xs0)) << GEN_MSLOC_XS0_SHIFT);\
}
#define GEN_MSLOC_YS0_SIZE	4
#define GEN_MSLOC_YS0_SHIFT	4
#define GEN_MSLOC_YS0_MASK	0x000000f0
#define GEN_MSLOC_GET_YS0(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_YS0_MASK) >> GEN_MSLOC_YS0_SHIFT)
#define GEN_MSLOC_SET_YS0(gen_msloc, ys0) { \
	FDL_ASSERT(!((ys0) & ~((1 << GEN_MSLOC_YS0_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_YS0_MASK) | (((unsigned long)(ys0)) << GEN_MSLOC_YS0_SHIFT);\
}
#define GEN_MSLOC_XS1_SIZE	4
#define GEN_MSLOC_XS1_SHIFT	8
#define GEN_MSLOC_XS1_MASK	0x00000f00
#define GEN_MSLOC_GET_XS1(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_XS1_MASK) >> GEN_MSLOC_XS1_SHIFT)
#define GEN_MSLOC_SET_XS1(gen_msloc, xs1) { \
	FDL_ASSERT(!((xs1) & ~((1 << GEN_MSLOC_XS1_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_XS1_MASK) | (((unsigned long)(xs1)) << GEN_MSLOC_XS1_SHIFT);\
}
#define GEN_MSLOC_YS1_SIZE	4
#define GEN_MSLOC_YS1_SHIFT	12
#define GEN_MSLOC_YS1_MASK	0x0000f000
#define GEN_MSLOC_GET_YS1(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_YS1_MASK) >> GEN_MSLOC_YS1_SHIFT)
#define GEN_MSLOC_SET_YS1(gen_msloc, ys1) { \
	FDL_ASSERT(!((ys1) & ~((1 << GEN_MSLOC_YS1_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_YS1_MASK) | (((unsigned long)(ys1)) << GEN_MSLOC_YS1_SHIFT);\
}
#define GEN_MSLOC_XS2_SIZE	4
#define GEN_MSLOC_XS2_SHIFT	16
#define GEN_MSLOC_XS2_MASK	0x000f0000
#define GEN_MSLOC_GET_XS2(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_XS2_MASK) >> GEN_MSLOC_XS2_SHIFT)
#define GEN_MSLOC_SET_XS2(gen_msloc, xs2) { \
	FDL_ASSERT(!((xs2) & ~((1 << GEN_MSLOC_XS2_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_XS2_MASK) | (((unsigned long)(xs2)) << GEN_MSLOC_XS2_SHIFT);\
}
#define GEN_MSLOC_YS2_SIZE	4
#define GEN_MSLOC_YS2_SHIFT	20
#define GEN_MSLOC_YS2_MASK	0x00f00000
#define GEN_MSLOC_GET_YS2(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_YS2_MASK) >> GEN_MSLOC_YS2_SHIFT)
#define GEN_MSLOC_SET_YS2(gen_msloc, ys2) { \
	FDL_ASSERT(!((ys2) & ~((1 << GEN_MSLOC_YS2_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_YS2_MASK) | (((unsigned long)(ys2)) << GEN_MSLOC_YS2_SHIFT);\
}
#define GEN_MSLOC_RID_SIZE	8
#define GEN_MSLOC_RID_SHIFT	24
#define GEN_MSLOC_RID_MASK	0xff000000
#define GEN_MSLOC_GET_RID(gen_msloc) \
	((((unsigned long)(gen_msloc)) & GEN_MSLOC_RID_MASK) >> GEN_MSLOC_RID_SHIFT)
#define GEN_MSLOC_SET_RID(gen_msloc, rid) { \
	FDL_ASSERT(!((rid) & ~((1 << GEN_MSLOC_RID_SIZE)-1))); \
	gen_msloc = (((unsigned long)(gen_msloc)) & ~GEN_MSLOC_RID_MASK) | (((unsigned long)(rid)) << GEN_MSLOC_RID_SHIFT);\
}
#define GEN_MSLOC_TOTAL_SIZE	32
#define GEN_MSLOC(xs0, ys0, xs1, ys1, xs2, ys2, rid) \
	((((unsigned long)(xs0)) << GEN_MSLOC_XS0_SHIFT) | \
	 (((unsigned long)(ys0)) << GEN_MSLOC_YS0_SHIFT) | \
	 (((unsigned long)(xs1)) << GEN_MSLOC_XS1_SHIFT) | \
	 (((unsigned long)(ys1)) << GEN_MSLOC_YS1_SHIFT) | \
	 (((unsigned long)(xs2)) << GEN_MSLOC_XS2_SHIFT) | \
	 (((unsigned long)(ys2)) << GEN_MSLOC_YS2_SHIFT) | \
	 (((unsigned long)(rid)) << GEN_MSLOC_RID_SHIFT))

typedef struct {
    unsigned long rid:GEN_MSLOC_RID_SIZE;
    unsigned long ys2:GEN_MSLOC_YS2_SIZE;
    unsigned long xs2:GEN_MSLOC_XS2_SIZE;
    unsigned long ys1:GEN_MSLOC_YS1_SIZE;
    unsigned long xs1:GEN_MSLOC_XS1_SIZE;
    unsigned long ys0:GEN_MSLOC_YS0_SIZE;
    unsigned long xs0:GEN_MSLOC_XS0_SIZE;
} gen_msloc_t;

typedef union {
    unsigned long val;
    gen_msloc_t f;
} gen_msloc_u;

/*
 *  gen_color struct
 */
#define GEN_COLOR_ALPHA_SIZE	8
#define GEN_COLOR_ALPHA_SHIFT	0
#define GEN_COLOR_ALPHA_MASK	0x000000ff
#define GEN_COLOR_GET_ALPHA(gen_color) \
	((((unsigned long)(gen_color)) & GEN_COLOR_ALPHA_MASK) >> GEN_COLOR_ALPHA_SHIFT)
#define GEN_COLOR_SET_ALPHA(gen_color, alpha) { \
	FDL_ASSERT(!((alpha) & ~((1 << GEN_COLOR_ALPHA_SIZE)-1))); \
	gen_color = (((unsigned long)(gen_color)) & ~GEN_COLOR_ALPHA_MASK) | (((unsigned long)(alpha)) << GEN_COLOR_ALPHA_SHIFT);\
}
#define GEN_COLOR_BLUE_SIZE	8
#define GEN_COLOR_BLUE_SHIFT	8
#define GEN_COLOR_BLUE_MASK	0x0000ff00
#define GEN_COLOR_GET_BLUE(gen_color) \
	((((unsigned long)(gen_color)) & GEN_COLOR_BLUE_MASK) >> GEN_COLOR_BLUE_SHIFT)
#define GEN_COLOR_SET_BLUE(gen_color, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << GEN_COLOR_BLUE_SIZE)-1))); \
	gen_color = (((unsigned long)(gen_color)) & ~GEN_COLOR_BLUE_MASK) | (((unsigned long)(blue)) << GEN_COLOR_BLUE_SHIFT);\
}
#define GEN_COLOR_GREEN_SIZE	8
#define GEN_COLOR_GREEN_SHIFT	16
#define GEN_COLOR_GREEN_MASK	0x00ff0000
#define GEN_COLOR_GET_GREEN(gen_color) \
	((((unsigned long)(gen_color)) & GEN_COLOR_GREEN_MASK) >> GEN_COLOR_GREEN_SHIFT)
#define GEN_COLOR_SET_GREEN(gen_color, green) { \
	FDL_ASSERT(!((green) & ~((1 << GEN_COLOR_GREEN_SIZE)-1))); \
	gen_color = (((unsigned long)(gen_color)) & ~GEN_COLOR_GREEN_MASK) | (((unsigned long)(green)) << GEN_COLOR_GREEN_SHIFT);\
}
#define GEN_COLOR_RED_SIZE	8
#define GEN_COLOR_RED_SHIFT	24
#define GEN_COLOR_RED_MASK	0xff000000
#define GEN_COLOR_GET_RED(gen_color) \
	((((unsigned long)(gen_color)) & GEN_COLOR_RED_MASK) >> GEN_COLOR_RED_SHIFT)
#define GEN_COLOR_SET_RED(gen_color, red) { \
	FDL_ASSERT(!((red) & ~((1 << GEN_COLOR_RED_SIZE)-1))); \
	gen_color = (((unsigned long)(gen_color)) & ~GEN_COLOR_RED_MASK) | (((unsigned long)(red)) << GEN_COLOR_RED_SHIFT);\
}
#define GEN_COLOR_TOTAL_SIZE	32
#define GEN_COLOR(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << GEN_COLOR_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << GEN_COLOR_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << GEN_COLOR_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << GEN_COLOR_RED_SHIFT))

typedef struct {
    unsigned long red:GEN_COLOR_RED_SIZE;
    unsigned long green:GEN_COLOR_GREEN_SIZE;
    unsigned long blue:GEN_COLOR_BLUE_SIZE;
    unsigned long alpha:GEN_COLOR_ALPHA_SIZE;
} gen_color_t;

typedef union {
    unsigned long val;
    gen_color_t f;
} gen_color_u;

/*
 *  gen_z24_color struct
 */
#define GEN_Z24_COLOR_BLUE_SIZE	8
#define GEN_Z24_COLOR_BLUE_SHIFT	0
#define GEN_Z24_COLOR_BLUE_MASK	0x000000ff
#define GEN_Z24_COLOR_GET_BLUE(gen_z24_color) \
	((((unsigned long)(gen_z24_color)) & GEN_Z24_COLOR_BLUE_MASK) >> GEN_Z24_COLOR_BLUE_SHIFT)
#define GEN_Z24_COLOR_SET_BLUE(gen_z24_color, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << GEN_Z24_COLOR_BLUE_SIZE)-1))); \
	gen_z24_color = (((unsigned long)(gen_z24_color)) & ~GEN_Z24_COLOR_BLUE_MASK) | (((unsigned long)(blue)) << GEN_Z24_COLOR_BLUE_SHIFT);\
}
#define GEN_Z24_COLOR_GREEN_SIZE	8
#define GEN_Z24_COLOR_GREEN_SHIFT	8
#define GEN_Z24_COLOR_GREEN_MASK	0x0000ff00
#define GEN_Z24_COLOR_GET_GREEN(gen_z24_color) \
	((((unsigned long)(gen_z24_color)) & GEN_Z24_COLOR_GREEN_MASK) >> GEN_Z24_COLOR_GREEN_SHIFT)
#define GEN_Z24_COLOR_SET_GREEN(gen_z24_color, green) { \
	FDL_ASSERT(!((green) & ~((1 << GEN_Z24_COLOR_GREEN_SIZE)-1))); \
	gen_z24_color = (((unsigned long)(gen_z24_color)) & ~GEN_Z24_COLOR_GREEN_MASK) | (((unsigned long)(green)) << GEN_Z24_COLOR_GREEN_SHIFT);\
}
#define GEN_Z24_COLOR_RED_SIZE	8
#define GEN_Z24_COLOR_RED_SHIFT	16
#define GEN_Z24_COLOR_RED_MASK	0x00ff0000
#define GEN_Z24_COLOR_GET_RED(gen_z24_color) \
	((((unsigned long)(gen_z24_color)) & GEN_Z24_COLOR_RED_MASK) >> GEN_Z24_COLOR_RED_SHIFT)
#define GEN_Z24_COLOR_SET_RED(gen_z24_color, red) { \
	FDL_ASSERT(!((red) & ~((1 << GEN_Z24_COLOR_RED_SIZE)-1))); \
	gen_z24_color = (((unsigned long)(gen_z24_color)) & ~GEN_Z24_COLOR_RED_MASK) | (((unsigned long)(red)) << GEN_Z24_COLOR_RED_SHIFT);\
}
#define GEN_Z24_COLOR_PAD0_SIZE	8
#define GEN_Z24_COLOR_PAD0_SHIFT	24
#define GEN_Z24_COLOR_PAD0_MASK	0xff000000
#define GEN_Z24_COLOR_GET_PAD0(gen_z24_color) \
	((((unsigned long)(gen_z24_color)) & GEN_Z24_COLOR_PAD0_MASK) >> GEN_Z24_COLOR_PAD0_SHIFT)
#define GEN_Z24_COLOR_SET_PAD0(gen_z24_color, pad0) { \
	FDL_ASSERT(!((pad0) & ~((1 << GEN_Z24_COLOR_PAD0_SIZE)-1))); \
	gen_z24_color = (((unsigned long)(gen_z24_color)) & ~GEN_Z24_COLOR_PAD0_MASK) | (((unsigned long)(pad0)) << GEN_Z24_COLOR_PAD0_SHIFT);\
}
#define GEN_Z24_COLOR_TOTAL_SIZE	32
#define GEN_Z24_COLOR(blue, green, red) \
	((((unsigned long)(blue)) << GEN_Z24_COLOR_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << GEN_Z24_COLOR_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << GEN_Z24_COLOR_RED_SHIFT))

typedef struct {
    unsigned long pad0:GEN_Z24_COLOR_PAD0_SIZE;
    unsigned long red:GEN_Z24_COLOR_RED_SIZE;
    unsigned long green:GEN_Z24_COLOR_GREEN_SIZE;
    unsigned long blue:GEN_Z24_COLOR_BLUE_SIZE;
} gen_z24_color_t;

typedef union {
    unsigned long val;
    gen_z24_color_t f;
} gen_z24_color_u;


#endif /* __GEN_REG_H__ */
