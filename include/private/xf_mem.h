/*
 *  xf_mem.h
 *
 *  NOTE: This is a generated file.  DO NOT HAND EDIT.
 *
 *  Generated from xf_mem.fdl
 */

#ifndef __XF_MEM_H__
#define __XF_MEM_H__


#ifdef EPPC
#include <private/fdl_assert.h>
#else
#define FDL_ASSERT(c) 
#endif
/*
 *  xf_regs_wa value
 */
#define XF_MATRIX_BASE	0x0000
#define XF_NORMAL_MATRIX_BASE	0x0400
#define XF_NORMAL_MATRIX_LAST	0x045f
#define XF_DUALTEX_MATRIX_BASE	0x0500
#define XF_DUALTEX_MATRIX_LAST	0x05ff
#define XF_LIGHT_BASE	0x0600
#define XF_LIGHT_SIZE	0x0010
#define XF_LIGHT0COLOR	0x0603
#define XF_LIGHT0A0	0x0604
#define XF_LIGHT0A1	0x0605
#define XF_LIGHT0A2	0x0606
#define XF_LIGHT0K0	0x0607
#define XF_LIGHT0K1	0x0608
#define XF_LIGHT0K2	0x0609
#define XF_LIGHT0LPX	0x060a
#define XF_LIGHT0LPY	0x060b
#define XF_LIGHT0LPZ	0x060c
#define XF_LIGHT0DX	0x060d
#define XF_LIGHT0HX	0x060d
#define XF_LIGHT0DY	0x060e
#define XF_LIGHT0HY	0x060e
#define XF_LIGHT0DZ	0x060f
#define XF_LIGHT0HZ	0x060f
#define XF_LIGHT1COLOR	0x0613
#define XF_LIGHT1A0	0x0614
#define XF_LIGHT1A1	0x0615
#define XF_LIGHT1A2	0x0616
#define XF_LIGHT1K0	0x0617
#define XF_LIGHT1K1	0x0618
#define XF_LIGHT1K2	0x0619
#define XF_LIGHT1LPX	0x061a
#define XF_LIGHT1LPY	0x061b
#define XF_LIGHT1LPZ	0x061c
#define XF_LIGHT1DX	0x061d
#define XF_LIGHT1HX	0x061d
#define XF_LIGHT1DY	0x061e
#define XF_LIGHT1HY	0x061e
#define XF_LIGHT1DZ	0x061f
#define XF_LIGHT1HZ	0x061f
#define XF_LIGHT2COLOR	0x0623
#define XF_LIGHT2A0	0x0624
#define XF_LIGHT2A1	0x0625
#define XF_LIGHT2A2	0x0626
#define XF_LIGHT2K0	0x0627
#define XF_LIGHT2K1	0x0628
#define XF_LIGHT2K2	0x0629
#define XF_LIGHT2LPX	0x062a
#define XF_LIGHT2LPY	0x062b
#define XF_LIGHT2LPZ	0x062c
#define XF_LIGHT2DX	0x062d
#define XF_LIGHT2HX	0x062d
#define XF_LIGHT2DY	0x062e
#define XF_LIGHT2HY	0x062e
#define XF_LIGHT2DZ	0x062f
#define XF_LIGHT2HZ	0x062f
#define XF_LIGHT3COLOR	0x0633
#define XF_LIGHT3A0	0x0634
#define XF_LIGHT3A1	0x0635
#define XF_LIGHT3A2	0x0636
#define XF_LIGHT3K0	0x0637
#define XF_LIGHT3K1	0x0638
#define XF_LIGHT3K2	0x0639
#define XF_LIGHT3LPX	0x063a
#define XF_LIGHT3LPY	0x063b
#define XF_LIGHT3LPZ	0x063c
#define XF_LIGHT3DX	0x063d
#define XF_LIGHT3HX	0x063d
#define XF_LIGHT3DY	0x063e
#define XF_LIGHT3HY	0x063e
#define XF_LIGHT3DZ	0x063f
#define XF_LIGHT3HZ	0x063f
#define XF_LIGHT4COLOR	0x0643
#define XF_LIGHT4A0	0x0644
#define XF_LIGHT4A1	0x0645
#define XF_LIGHT4A2	0x0646
#define XF_LIGHT4K0	0x0647
#define XF_LIGHT4K1	0x0648
#define XF_LIGHT4K2	0x0649
#define XF_LIGHT4LPX	0x064a
#define XF_LIGHT4LPY	0x064b
#define XF_LIGHT4LPZ	0x064c
#define XF_LIGHT4DX	0x064d
#define XF_LIGHT4HX	0x064d
#define XF_LIGHT4DY	0x064e
#define XF_LIGHT4HY	0x064e
#define XF_LIGHT4DZ	0x064f
#define XF_LIGHT4HZ	0x064f
#define XF_LIGHT5COLOR	0x0653
#define XF_LIGHT5A0	0x0654
#define XF_LIGHT5A1	0x0655
#define XF_LIGHT5A2	0x0656
#define XF_LIGHT5K0	0x0657
#define XF_LIGHT5K1	0x0658
#define XF_LIGHT5K2	0x0659
#define XF_LIGHT5LPX	0x065a
#define XF_LIGHT5LPY	0x065b
#define XF_LIGHT5LPZ	0x065c
#define XF_LIGHT5DX	0x065d
#define XF_LIGHT5HX	0x065d
#define XF_LIGHT5DY	0x065e
#define XF_LIGHT5HY	0x065e
#define XF_LIGHT5DZ	0x065f
#define XF_LIGHT5HZ	0x065f
#define XF_LIGHT6COLOR	0x0663
#define XF_LIGHT6A0	0x0664
#define XF_LIGHT6A1	0x0665
#define XF_LIGHT6A2	0x0666
#define XF_LIGHT6K0	0x0667
#define XF_LIGHT6K1	0x0668
#define XF_LIGHT6K2	0x0669
#define XF_LIGHT6LPX	0x066a
#define XF_LIGHT6LPY	0x066b
#define XF_LIGHT6LPZ	0x066c
#define XF_LIGHT6DX	0x066d
#define XF_LIGHT6HX	0x066d
#define XF_LIGHT6DY	0x066e
#define XF_LIGHT6HY	0x066e
#define XF_LIGHT6DZ	0x066f
#define XF_LIGHT6HZ	0x066f
#define XF_LIGHT7COLOR	0x0673
#define XF_LIGHT7A0	0x0674
#define XF_LIGHT7A1	0x0675
#define XF_LIGHT7A2	0x0676
#define XF_LIGHT7K0	0x0677
#define XF_LIGHT7K1	0x0678
#define XF_LIGHT7K2	0x0679
#define XF_LIGHT7LPX	0x067a
#define XF_LIGHT7LPY	0x067b
#define XF_LIGHT7LPZ	0x067c
#define XF_LIGHT7DX	0x067d
#define XF_LIGHT7HX	0x067d
#define XF_LIGHT7DY	0x067e
#define XF_LIGHT7HY	0x067e
#define XF_LIGHT7DZ	0x067f
#define XF_LIGHT7HZ	0x067f
#define XF_VERTEX_BUFFER_BASE	0x0800
#define XF_REG_BASE	0x1000
#define XF_ERROR	0x1000
#define XF_DIAG	0x1001
#define XF_STATE0	0x1002
#define XF_STATE1	0x1003
#define XF_CLOCK	0x1004
#define XF_CLIPDISABLE	0x1005
#define XF_PERF0	0x1006
#define XF_PERF1	0x1007
#define XF_INVERTEXSPEC	0x1008
#define XF_NUMCOLORS	0x1009
#define XF_AMBIENT0	0x100a
#define XF_AMBIENT1	0x100b
#define XF_MATERIAL0	0x100c
#define XF_MATERIAL1	0x100d
#define XF_COLOR0CNTRL	0x100e
#define XF_COLOR1CNTRL	0x100f
#define XF_ALPHA0CNTRL	0x1010
#define XF_ALPHA1CNTRL	0x1011
#define XF_DUALTEXTRAN	0x1012
#define XF_MATRIXINDEX0	0x1018
#define XF_MATRIXINDEX1	0x1019
#define XF_SCALEX	0x101a
#define XF_SCALEY	0x101b
#define XF_SCALEZ	0x101c
#define XF_OFFSETX	0x101d
#define XF_OFFSETY	0x101e
#define XF_OFFSETZ	0x101f
#define XF_PROJECTIONA	0x1020
#define XF_PROJECTIONB	0x1021
#define XF_PROJECTIONC	0x1022
#define XF_PROJECTIOND	0x1023
#define XF_PROJECTIONE	0x1024
#define XF_PROJECTIONF	0x1025
#define XF_PROJECTORTHO	0x1026
#define XF_NUMTEX	0x103f
#define XF_TEX0	0x1040
#define XF_TEX1	0x1041
#define XF_TEX2	0x1042
#define XF_TEX3	0x1043
#define XF_TEX4	0x1044
#define XF_TEX5	0x1045
#define XF_TEX6	0x1046
#define XF_TEX7	0x1047
#define XF_DUALTEX0	0x1050
#define XF_DUALTEX1	0x1051
#define XF_DUALTEX2	0x1052
#define XF_DUALTEX3	0x1053
#define XF_DUALTEX4	0x1054
#define XF_DUALTEX5	0x1055
#define XF_DUALTEX6	0x1056
#define XF_DUALTEX7	0x1057

/*
 *  xf_ambient0_f struct
 */
#define XF_AMBIENT0_F_ALPHA_SIZE	8
#define XF_AMBIENT0_F_ALPHA_SHIFT	0
#define XF_AMBIENT0_F_ALPHA_MASK	0x000000ff
#define XF_AMBIENT0_F_GET_ALPHA(xf_ambient0_f) \
	((((unsigned long)(xf_ambient0_f)) & XF_AMBIENT0_F_ALPHA_MASK) >> XF_AMBIENT0_F_ALPHA_SHIFT)
#define XF_AMBIENT0_F_SET_ALPHA(xf_ambient0_f, alpha) { \
	FDL_ASSERT(!((alpha) & ~((1 << XF_AMBIENT0_F_ALPHA_SIZE)-1))); \
	xf_ambient0_f = (((unsigned long)(xf_ambient0_f)) & ~XF_AMBIENT0_F_ALPHA_MASK) | (((unsigned long)(alpha)) << XF_AMBIENT0_F_ALPHA_SHIFT);\
}
#define XF_AMBIENT0_F_BLUE_SIZE	8
#define XF_AMBIENT0_F_BLUE_SHIFT	8
#define XF_AMBIENT0_F_BLUE_MASK	0x0000ff00
#define XF_AMBIENT0_F_GET_BLUE(xf_ambient0_f) \
	((((unsigned long)(xf_ambient0_f)) & XF_AMBIENT0_F_BLUE_MASK) >> XF_AMBIENT0_F_BLUE_SHIFT)
#define XF_AMBIENT0_F_SET_BLUE(xf_ambient0_f, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << XF_AMBIENT0_F_BLUE_SIZE)-1))); \
	xf_ambient0_f = (((unsigned long)(xf_ambient0_f)) & ~XF_AMBIENT0_F_BLUE_MASK) | (((unsigned long)(blue)) << XF_AMBIENT0_F_BLUE_SHIFT);\
}
#define XF_AMBIENT0_F_GREEN_SIZE	8
#define XF_AMBIENT0_F_GREEN_SHIFT	16
#define XF_AMBIENT0_F_GREEN_MASK	0x00ff0000
#define XF_AMBIENT0_F_GET_GREEN(xf_ambient0_f) \
	((((unsigned long)(xf_ambient0_f)) & XF_AMBIENT0_F_GREEN_MASK) >> XF_AMBIENT0_F_GREEN_SHIFT)
#define XF_AMBIENT0_F_SET_GREEN(xf_ambient0_f, green) { \
	FDL_ASSERT(!((green) & ~((1 << XF_AMBIENT0_F_GREEN_SIZE)-1))); \
	xf_ambient0_f = (((unsigned long)(xf_ambient0_f)) & ~XF_AMBIENT0_F_GREEN_MASK) | (((unsigned long)(green)) << XF_AMBIENT0_F_GREEN_SHIFT);\
}
#define XF_AMBIENT0_F_RED_SIZE	8
#define XF_AMBIENT0_F_RED_SHIFT	24
#define XF_AMBIENT0_F_RED_MASK	0xff000000
#define XF_AMBIENT0_F_GET_RED(xf_ambient0_f) \
	((((unsigned long)(xf_ambient0_f)) & XF_AMBIENT0_F_RED_MASK) >> XF_AMBIENT0_F_RED_SHIFT)
#define XF_AMBIENT0_F_SET_RED(xf_ambient0_f, red) { \
	FDL_ASSERT(!((red) & ~((1 << XF_AMBIENT0_F_RED_SIZE)-1))); \
	xf_ambient0_f = (((unsigned long)(xf_ambient0_f)) & ~XF_AMBIENT0_F_RED_MASK) | (((unsigned long)(red)) << XF_AMBIENT0_F_RED_SHIFT);\
}
#define XF_AMBIENT0_F_TOTAL_SIZE	32
#define XF_AMBIENT0_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_AMBIENT0_F_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_AMBIENT0_F_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_AMBIENT0_F_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_AMBIENT0_F_RED_SHIFT))

typedef struct {
    unsigned long red:XF_AMBIENT0_F_RED_SIZE;
    unsigned long green:XF_AMBIENT0_F_GREEN_SIZE;
    unsigned long blue:XF_AMBIENT0_F_BLUE_SIZE;
    unsigned long alpha:XF_AMBIENT0_F_ALPHA_SIZE;
} xf_ambient0_f_t;

typedef union {
    unsigned long val;
    xf_ambient0_f_t f;
} xf_ambient0_f_u;

/*
 *  xf_ambient1_f struct
 */
#define XF_AMBIENT1_F_ALPHA_SIZE	8
#define XF_AMBIENT1_F_ALPHA_SHIFT	0
#define XF_AMBIENT1_F_ALPHA_MASK	0x000000ff
#define XF_AMBIENT1_F_GET_ALPHA(xf_ambient1_f) \
	((((unsigned long)(xf_ambient1_f)) & XF_AMBIENT1_F_ALPHA_MASK) >> XF_AMBIENT1_F_ALPHA_SHIFT)
#define XF_AMBIENT1_F_SET_ALPHA(xf_ambient1_f, alpha) { \
	FDL_ASSERT(!((alpha) & ~((1 << XF_AMBIENT1_F_ALPHA_SIZE)-1))); \
	xf_ambient1_f = (((unsigned long)(xf_ambient1_f)) & ~XF_AMBIENT1_F_ALPHA_MASK) | (((unsigned long)(alpha)) << XF_AMBIENT1_F_ALPHA_SHIFT);\
}
#define XF_AMBIENT1_F_BLUE_SIZE	8
#define XF_AMBIENT1_F_BLUE_SHIFT	8
#define XF_AMBIENT1_F_BLUE_MASK	0x0000ff00
#define XF_AMBIENT1_F_GET_BLUE(xf_ambient1_f) \
	((((unsigned long)(xf_ambient1_f)) & XF_AMBIENT1_F_BLUE_MASK) >> XF_AMBIENT1_F_BLUE_SHIFT)
#define XF_AMBIENT1_F_SET_BLUE(xf_ambient1_f, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << XF_AMBIENT1_F_BLUE_SIZE)-1))); \
	xf_ambient1_f = (((unsigned long)(xf_ambient1_f)) & ~XF_AMBIENT1_F_BLUE_MASK) | (((unsigned long)(blue)) << XF_AMBIENT1_F_BLUE_SHIFT);\
}
#define XF_AMBIENT1_F_GREEN_SIZE	8
#define XF_AMBIENT1_F_GREEN_SHIFT	16
#define XF_AMBIENT1_F_GREEN_MASK	0x00ff0000
#define XF_AMBIENT1_F_GET_GREEN(xf_ambient1_f) \
	((((unsigned long)(xf_ambient1_f)) & XF_AMBIENT1_F_GREEN_MASK) >> XF_AMBIENT1_F_GREEN_SHIFT)
#define XF_AMBIENT1_F_SET_GREEN(xf_ambient1_f, green) { \
	FDL_ASSERT(!((green) & ~((1 << XF_AMBIENT1_F_GREEN_SIZE)-1))); \
	xf_ambient1_f = (((unsigned long)(xf_ambient1_f)) & ~XF_AMBIENT1_F_GREEN_MASK) | (((unsigned long)(green)) << XF_AMBIENT1_F_GREEN_SHIFT);\
}
#define XF_AMBIENT1_F_RED_SIZE	8
#define XF_AMBIENT1_F_RED_SHIFT	24
#define XF_AMBIENT1_F_RED_MASK	0xff000000
#define XF_AMBIENT1_F_GET_RED(xf_ambient1_f) \
	((((unsigned long)(xf_ambient1_f)) & XF_AMBIENT1_F_RED_MASK) >> XF_AMBIENT1_F_RED_SHIFT)
#define XF_AMBIENT1_F_SET_RED(xf_ambient1_f, red) { \
	FDL_ASSERT(!((red) & ~((1 << XF_AMBIENT1_F_RED_SIZE)-1))); \
	xf_ambient1_f = (((unsigned long)(xf_ambient1_f)) & ~XF_AMBIENT1_F_RED_MASK) | (((unsigned long)(red)) << XF_AMBIENT1_F_RED_SHIFT);\
}
#define XF_AMBIENT1_F_TOTAL_SIZE	32
#define XF_AMBIENT1_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_AMBIENT1_F_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_AMBIENT1_F_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_AMBIENT1_F_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_AMBIENT1_F_RED_SHIFT))

typedef struct {
    unsigned long red:XF_AMBIENT1_F_RED_SIZE;
    unsigned long green:XF_AMBIENT1_F_GREEN_SIZE;
    unsigned long blue:XF_AMBIENT1_F_BLUE_SIZE;
    unsigned long alpha:XF_AMBIENT1_F_ALPHA_SIZE;
} xf_ambient1_f_t;

typedef union {
    unsigned long val;
    xf_ambient1_f_t f;
} xf_ambient1_f_u;

/*
 *  xf_material0_f struct
 */
#define XF_MATERIAL0_F_ALPHA_SIZE	8
#define XF_MATERIAL0_F_ALPHA_SHIFT	0
#define XF_MATERIAL0_F_ALPHA_MASK	0x000000ff
#define XF_MATERIAL0_F_GET_ALPHA(xf_material0_f) \
	((((unsigned long)(xf_material0_f)) & XF_MATERIAL0_F_ALPHA_MASK) >> XF_MATERIAL0_F_ALPHA_SHIFT)
#define XF_MATERIAL0_F_SET_ALPHA(xf_material0_f, alpha) { \
	FDL_ASSERT(!((alpha) & ~((1 << XF_MATERIAL0_F_ALPHA_SIZE)-1))); \
	xf_material0_f = (((unsigned long)(xf_material0_f)) & ~XF_MATERIAL0_F_ALPHA_MASK) | (((unsigned long)(alpha)) << XF_MATERIAL0_F_ALPHA_SHIFT);\
}
#define XF_MATERIAL0_F_BLUE_SIZE	8
#define XF_MATERIAL0_F_BLUE_SHIFT	8
#define XF_MATERIAL0_F_BLUE_MASK	0x0000ff00
#define XF_MATERIAL0_F_GET_BLUE(xf_material0_f) \
	((((unsigned long)(xf_material0_f)) & XF_MATERIAL0_F_BLUE_MASK) >> XF_MATERIAL0_F_BLUE_SHIFT)
#define XF_MATERIAL0_F_SET_BLUE(xf_material0_f, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << XF_MATERIAL0_F_BLUE_SIZE)-1))); \
	xf_material0_f = (((unsigned long)(xf_material0_f)) & ~XF_MATERIAL0_F_BLUE_MASK) | (((unsigned long)(blue)) << XF_MATERIAL0_F_BLUE_SHIFT);\
}
#define XF_MATERIAL0_F_GREEN_SIZE	8
#define XF_MATERIAL0_F_GREEN_SHIFT	16
#define XF_MATERIAL0_F_GREEN_MASK	0x00ff0000
#define XF_MATERIAL0_F_GET_GREEN(xf_material0_f) \
	((((unsigned long)(xf_material0_f)) & XF_MATERIAL0_F_GREEN_MASK) >> XF_MATERIAL0_F_GREEN_SHIFT)
#define XF_MATERIAL0_F_SET_GREEN(xf_material0_f, green) { \
	FDL_ASSERT(!((green) & ~((1 << XF_MATERIAL0_F_GREEN_SIZE)-1))); \
	xf_material0_f = (((unsigned long)(xf_material0_f)) & ~XF_MATERIAL0_F_GREEN_MASK) | (((unsigned long)(green)) << XF_MATERIAL0_F_GREEN_SHIFT);\
}
#define XF_MATERIAL0_F_RED_SIZE	8
#define XF_MATERIAL0_F_RED_SHIFT	24
#define XF_MATERIAL0_F_RED_MASK	0xff000000
#define XF_MATERIAL0_F_GET_RED(xf_material0_f) \
	((((unsigned long)(xf_material0_f)) & XF_MATERIAL0_F_RED_MASK) >> XF_MATERIAL0_F_RED_SHIFT)
#define XF_MATERIAL0_F_SET_RED(xf_material0_f, red) { \
	FDL_ASSERT(!((red) & ~((1 << XF_MATERIAL0_F_RED_SIZE)-1))); \
	xf_material0_f = (((unsigned long)(xf_material0_f)) & ~XF_MATERIAL0_F_RED_MASK) | (((unsigned long)(red)) << XF_MATERIAL0_F_RED_SHIFT);\
}
#define XF_MATERIAL0_F_TOTAL_SIZE	32
#define XF_MATERIAL0_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_MATERIAL0_F_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_MATERIAL0_F_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_MATERIAL0_F_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_MATERIAL0_F_RED_SHIFT))

typedef struct {
    unsigned long red:XF_MATERIAL0_F_RED_SIZE;
    unsigned long green:XF_MATERIAL0_F_GREEN_SIZE;
    unsigned long blue:XF_MATERIAL0_F_BLUE_SIZE;
    unsigned long alpha:XF_MATERIAL0_F_ALPHA_SIZE;
} xf_material0_f_t;

typedef union {
    unsigned long val;
    xf_material0_f_t f;
} xf_material0_f_u;

/*
 *  xf_material1_f struct
 */
#define XF_MATERIAL1_F_ALPHA_SIZE	8
#define XF_MATERIAL1_F_ALPHA_SHIFT	0
#define XF_MATERIAL1_F_ALPHA_MASK	0x000000ff
#define XF_MATERIAL1_F_GET_ALPHA(xf_material1_f) \
	((((unsigned long)(xf_material1_f)) & XF_MATERIAL1_F_ALPHA_MASK) >> XF_MATERIAL1_F_ALPHA_SHIFT)
#define XF_MATERIAL1_F_SET_ALPHA(xf_material1_f, alpha) { \
	FDL_ASSERT(!((alpha) & ~((1 << XF_MATERIAL1_F_ALPHA_SIZE)-1))); \
	xf_material1_f = (((unsigned long)(xf_material1_f)) & ~XF_MATERIAL1_F_ALPHA_MASK) | (((unsigned long)(alpha)) << XF_MATERIAL1_F_ALPHA_SHIFT);\
}
#define XF_MATERIAL1_F_BLUE_SIZE	8
#define XF_MATERIAL1_F_BLUE_SHIFT	8
#define XF_MATERIAL1_F_BLUE_MASK	0x0000ff00
#define XF_MATERIAL1_F_GET_BLUE(xf_material1_f) \
	((((unsigned long)(xf_material1_f)) & XF_MATERIAL1_F_BLUE_MASK) >> XF_MATERIAL1_F_BLUE_SHIFT)
#define XF_MATERIAL1_F_SET_BLUE(xf_material1_f, blue) { \
	FDL_ASSERT(!((blue) & ~((1 << XF_MATERIAL1_F_BLUE_SIZE)-1))); \
	xf_material1_f = (((unsigned long)(xf_material1_f)) & ~XF_MATERIAL1_F_BLUE_MASK) | (((unsigned long)(blue)) << XF_MATERIAL1_F_BLUE_SHIFT);\
}
#define XF_MATERIAL1_F_GREEN_SIZE	8
#define XF_MATERIAL1_F_GREEN_SHIFT	16
#define XF_MATERIAL1_F_GREEN_MASK	0x00ff0000
#define XF_MATERIAL1_F_GET_GREEN(xf_material1_f) \
	((((unsigned long)(xf_material1_f)) & XF_MATERIAL1_F_GREEN_MASK) >> XF_MATERIAL1_F_GREEN_SHIFT)
#define XF_MATERIAL1_F_SET_GREEN(xf_material1_f, green) { \
	FDL_ASSERT(!((green) & ~((1 << XF_MATERIAL1_F_GREEN_SIZE)-1))); \
	xf_material1_f = (((unsigned long)(xf_material1_f)) & ~XF_MATERIAL1_F_GREEN_MASK) | (((unsigned long)(green)) << XF_MATERIAL1_F_GREEN_SHIFT);\
}
#define XF_MATERIAL1_F_RED_SIZE	8
#define XF_MATERIAL1_F_RED_SHIFT	24
#define XF_MATERIAL1_F_RED_MASK	0xff000000
#define XF_MATERIAL1_F_GET_RED(xf_material1_f) \
	((((unsigned long)(xf_material1_f)) & XF_MATERIAL1_F_RED_MASK) >> XF_MATERIAL1_F_RED_SHIFT)
#define XF_MATERIAL1_F_SET_RED(xf_material1_f, red) { \
	FDL_ASSERT(!((red) & ~((1 << XF_MATERIAL1_F_RED_SIZE)-1))); \
	xf_material1_f = (((unsigned long)(xf_material1_f)) & ~XF_MATERIAL1_F_RED_MASK) | (((unsigned long)(red)) << XF_MATERIAL1_F_RED_SHIFT);\
}
#define XF_MATERIAL1_F_TOTAL_SIZE	32
#define XF_MATERIAL1_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_MATERIAL1_F_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_MATERIAL1_F_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_MATERIAL1_F_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_MATERIAL1_F_RED_SHIFT))

typedef struct {
    unsigned long red:XF_MATERIAL1_F_RED_SIZE;
    unsigned long green:XF_MATERIAL1_F_GREEN_SIZE;
    unsigned long blue:XF_MATERIAL1_F_BLUE_SIZE;
    unsigned long alpha:XF_MATERIAL1_F_ALPHA_SIZE;
} xf_material1_f_t;

typedef union {
    unsigned long val;
    xf_material1_f_t f;
} xf_material1_f_u;

/*
 *  xf_matrixindex0_f struct
 */
#define XF_MATRIXINDEX0_F_GEOM_SIZE	6
#define XF_MATRIXINDEX0_F_GEOM_SHIFT	0
#define XF_MATRIXINDEX0_F_GEOM_MASK	0x0000003f
#define XF_MATRIXINDEX0_F_GET_GEOM(xf_matrixindex0_f) \
	((((unsigned long)(xf_matrixindex0_f)) & XF_MATRIXINDEX0_F_GEOM_MASK) >> XF_MATRIXINDEX0_F_GEOM_SHIFT)
#define XF_MATRIXINDEX0_F_SET_GEOM(xf_matrixindex0_f, geom) { \
	FDL_ASSERT(!((geom) & ~((1 << XF_MATRIXINDEX0_F_GEOM_SIZE)-1))); \
	xf_matrixindex0_f = (((unsigned long)(xf_matrixindex0_f)) & ~XF_MATRIXINDEX0_F_GEOM_MASK) | (((unsigned long)(geom)) << XF_MATRIXINDEX0_F_GEOM_SHIFT);\
}
#define XF_MATRIXINDEX0_F_TEX0_SIZE	6
#define XF_MATRIXINDEX0_F_TEX0_SHIFT	6
#define XF_MATRIXINDEX0_F_TEX0_MASK	0x00000fc0
#define XF_MATRIXINDEX0_F_GET_TEX0(xf_matrixindex0_f) \
	((((unsigned long)(xf_matrixindex0_f)) & XF_MATRIXINDEX0_F_TEX0_MASK) >> XF_MATRIXINDEX0_F_TEX0_SHIFT)
#define XF_MATRIXINDEX0_F_SET_TEX0(xf_matrixindex0_f, tex0) { \
	FDL_ASSERT(!((tex0) & ~((1 << XF_MATRIXINDEX0_F_TEX0_SIZE)-1))); \
	xf_matrixindex0_f = (((unsigned long)(xf_matrixindex0_f)) & ~XF_MATRIXINDEX0_F_TEX0_MASK) | (((unsigned long)(tex0)) << XF_MATRIXINDEX0_F_TEX0_SHIFT);\
}
#define XF_MATRIXINDEX0_F_TEX1_SIZE	6
#define XF_MATRIXINDEX0_F_TEX1_SHIFT	12
#define XF_MATRIXINDEX0_F_TEX1_MASK	0x0003f000
#define XF_MATRIXINDEX0_F_GET_TEX1(xf_matrixindex0_f) \
	((((unsigned long)(xf_matrixindex0_f)) & XF_MATRIXINDEX0_F_TEX1_MASK) >> XF_MATRIXINDEX0_F_TEX1_SHIFT)
#define XF_MATRIXINDEX0_F_SET_TEX1(xf_matrixindex0_f, tex1) { \
	FDL_ASSERT(!((tex1) & ~((1 << XF_MATRIXINDEX0_F_TEX1_SIZE)-1))); \
	xf_matrixindex0_f = (((unsigned long)(xf_matrixindex0_f)) & ~XF_MATRIXINDEX0_F_TEX1_MASK) | (((unsigned long)(tex1)) << XF_MATRIXINDEX0_F_TEX1_SHIFT);\
}
#define XF_MATRIXINDEX0_F_TEX2_SIZE	6
#define XF_MATRIXINDEX0_F_TEX2_SHIFT	18
#define XF_MATRIXINDEX0_F_TEX2_MASK	0x00fc0000
#define XF_MATRIXINDEX0_F_GET_TEX2(xf_matrixindex0_f) \
	((((unsigned long)(xf_matrixindex0_f)) & XF_MATRIXINDEX0_F_TEX2_MASK) >> XF_MATRIXINDEX0_F_TEX2_SHIFT)
#define XF_MATRIXINDEX0_F_SET_TEX2(xf_matrixindex0_f, tex2) { \
	FDL_ASSERT(!((tex2) & ~((1 << XF_MATRIXINDEX0_F_TEX2_SIZE)-1))); \
	xf_matrixindex0_f = (((unsigned long)(xf_matrixindex0_f)) & ~XF_MATRIXINDEX0_F_TEX2_MASK) | (((unsigned long)(tex2)) << XF_MATRIXINDEX0_F_TEX2_SHIFT);\
}
#define XF_MATRIXINDEX0_F_TEX3_SIZE	6
#define XF_MATRIXINDEX0_F_TEX3_SHIFT	24
#define XF_MATRIXINDEX0_F_TEX3_MASK	0x3f000000
#define XF_MATRIXINDEX0_F_GET_TEX3(xf_matrixindex0_f) \
	((((unsigned long)(xf_matrixindex0_f)) & XF_MATRIXINDEX0_F_TEX3_MASK) >> XF_MATRIXINDEX0_F_TEX3_SHIFT)
#define XF_MATRIXINDEX0_F_SET_TEX3(xf_matrixindex0_f, tex3) { \
	FDL_ASSERT(!((tex3) & ~((1 << XF_MATRIXINDEX0_F_TEX3_SIZE)-1))); \
	xf_matrixindex0_f = (((unsigned long)(xf_matrixindex0_f)) & ~XF_MATRIXINDEX0_F_TEX3_MASK) | (((unsigned long)(tex3)) << XF_MATRIXINDEX0_F_TEX3_SHIFT);\
}
#define XF_MATRIXINDEX0_F_TOTAL_SIZE	30
#define XF_MATRIXINDEX0_F_UNUSED_SIZE	2

#define XF_MATRIXINDEX0_F(geom, tex0, tex1, tex2, tex3) \
	((((unsigned long)(geom)) << XF_MATRIXINDEX0_F_GEOM_SHIFT) | \
	 (((unsigned long)(tex0)) << XF_MATRIXINDEX0_F_TEX0_SHIFT) | \
	 (((unsigned long)(tex1)) << XF_MATRIXINDEX0_F_TEX1_SHIFT) | \
	 (((unsigned long)(tex2)) << XF_MATRIXINDEX0_F_TEX2_SHIFT) | \
	 (((unsigned long)(tex3)) << XF_MATRIXINDEX0_F_TEX3_SHIFT))

typedef struct {
    unsigned long unused:XF_MATRIXINDEX0_F_UNUSED_SIZE;
    unsigned long tex3:XF_MATRIXINDEX0_F_TEX3_SIZE;
    unsigned long tex2:XF_MATRIXINDEX0_F_TEX2_SIZE;
    unsigned long tex1:XF_MATRIXINDEX0_F_TEX1_SIZE;
    unsigned long tex0:XF_MATRIXINDEX0_F_TEX0_SIZE;
    unsigned long geom:XF_MATRIXINDEX0_F_GEOM_SIZE;
} xf_matrixindex0_f_t;

typedef union {
    unsigned long val;
    xf_matrixindex0_f_t f;
} xf_matrixindex0_f_u;

/*
 *  xf_matrixindex1_f struct
 */
#define XF_MATRIXINDEX1_F_TEX4_SIZE	6
#define XF_MATRIXINDEX1_F_TEX4_SHIFT	0
#define XF_MATRIXINDEX1_F_TEX4_MASK	0x0000003f
#define XF_MATRIXINDEX1_F_GET_TEX4(xf_matrixindex1_f) \
	((((unsigned long)(xf_matrixindex1_f)) & XF_MATRIXINDEX1_F_TEX4_MASK) >> XF_MATRIXINDEX1_F_TEX4_SHIFT)
#define XF_MATRIXINDEX1_F_SET_TEX4(xf_matrixindex1_f, tex4) { \
	FDL_ASSERT(!((tex4) & ~((1 << XF_MATRIXINDEX1_F_TEX4_SIZE)-1))); \
	xf_matrixindex1_f = (((unsigned long)(xf_matrixindex1_f)) & ~XF_MATRIXINDEX1_F_TEX4_MASK) | (((unsigned long)(tex4)) << XF_MATRIXINDEX1_F_TEX4_SHIFT);\
}
#define XF_MATRIXINDEX1_F_TEX5_SIZE	6
#define XF_MATRIXINDEX1_F_TEX5_SHIFT	6
#define XF_MATRIXINDEX1_F_TEX5_MASK	0x00000fc0
#define XF_MATRIXINDEX1_F_GET_TEX5(xf_matrixindex1_f) \
	((((unsigned long)(xf_matrixindex1_f)) & XF_MATRIXINDEX1_F_TEX5_MASK) >> XF_MATRIXINDEX1_F_TEX5_SHIFT)
#define XF_MATRIXINDEX1_F_SET_TEX5(xf_matrixindex1_f, tex5) { \
	FDL_ASSERT(!((tex5) & ~((1 << XF_MATRIXINDEX1_F_TEX5_SIZE)-1))); \
	xf_matrixindex1_f = (((unsigned long)(xf_matrixindex1_f)) & ~XF_MATRIXINDEX1_F_TEX5_MASK) | (((unsigned long)(tex5)) << XF_MATRIXINDEX1_F_TEX5_SHIFT);\
}
#define XF_MATRIXINDEX1_F_TEX6_SIZE	6
#define XF_MATRIXINDEX1_F_TEX6_SHIFT	12
#define XF_MATRIXINDEX1_F_TEX6_MASK	0x0003f000
#define XF_MATRIXINDEX1_F_GET_TEX6(xf_matrixindex1_f) \
	((((unsigned long)(xf_matrixindex1_f)) & XF_MATRIXINDEX1_F_TEX6_MASK) >> XF_MATRIXINDEX1_F_TEX6_SHIFT)
#define XF_MATRIXINDEX1_F_SET_TEX6(xf_matrixindex1_f, tex6) { \
	FDL_ASSERT(!((tex6) & ~((1 << XF_MATRIXINDEX1_F_TEX6_SIZE)-1))); \
	xf_matrixindex1_f = (((unsigned long)(xf_matrixindex1_f)) & ~XF_MATRIXINDEX1_F_TEX6_MASK) | (((unsigned long)(tex6)) << XF_MATRIXINDEX1_F_TEX6_SHIFT);\
}
#define XF_MATRIXINDEX1_F_TEX7_SIZE	6
#define XF_MATRIXINDEX1_F_TEX7_SHIFT	18
#define XF_MATRIXINDEX1_F_TEX7_MASK	0x00fc0000
#define XF_MATRIXINDEX1_F_GET_TEX7(xf_matrixindex1_f) \
	((((unsigned long)(xf_matrixindex1_f)) & XF_MATRIXINDEX1_F_TEX7_MASK) >> XF_MATRIXINDEX1_F_TEX7_SHIFT)
#define XF_MATRIXINDEX1_F_SET_TEX7(xf_matrixindex1_f, tex7) { \
	FDL_ASSERT(!((tex7) & ~((1 << XF_MATRIXINDEX1_F_TEX7_SIZE)-1))); \
	xf_matrixindex1_f = (((unsigned long)(xf_matrixindex1_f)) & ~XF_MATRIXINDEX1_F_TEX7_MASK) | (((unsigned long)(tex7)) << XF_MATRIXINDEX1_F_TEX7_SHIFT);\
}
#define XF_MATRIXINDEX1_F_TOTAL_SIZE	24
#define XF_MATRIXINDEX1_F_UNUSED_SIZE	8

#define XF_MATRIXINDEX1_F(tex4, tex5, tex6, tex7) \
	((((unsigned long)(tex4)) << XF_MATRIXINDEX1_F_TEX4_SHIFT) | \
	 (((unsigned long)(tex5)) << XF_MATRIXINDEX1_F_TEX5_SHIFT) | \
	 (((unsigned long)(tex6)) << XF_MATRIXINDEX1_F_TEX6_SHIFT) | \
	 (((unsigned long)(tex7)) << XF_MATRIXINDEX1_F_TEX7_SHIFT))

typedef struct {
    unsigned long unused:XF_MATRIXINDEX1_F_UNUSED_SIZE;
    unsigned long tex7:XF_MATRIXINDEX1_F_TEX7_SIZE;
    unsigned long tex6:XF_MATRIXINDEX1_F_TEX6_SIZE;
    unsigned long tex5:XF_MATRIXINDEX1_F_TEX5_SIZE;
    unsigned long tex4:XF_MATRIXINDEX1_F_TEX4_SIZE;
} xf_matrixindex1_f_t;

typedef union {
    unsigned long val;
    xf_matrixindex1_f_t f;
} xf_matrixindex1_f_u;

/*
 *  xf_invertexspec_f struct
 */
#define XF_INVERTEXSPEC_F_HOST_COLORS_SIZE	2
#define XF_INVERTEXSPEC_F_HOST_COLORS_SHIFT	0
#define XF_INVERTEXSPEC_F_HOST_COLORS_MASK	0x00000003
#define XF_INVERTEXSPEC_F_GET_HOST_COLORS(xf_invertexspec_f) \
	((((unsigned long)(xf_invertexspec_f)) & XF_INVERTEXSPEC_F_HOST_COLORS_MASK) >> XF_INVERTEXSPEC_F_HOST_COLORS_SHIFT)
#define XF_INVERTEXSPEC_F_SET_HOST_COLORS(xf_invertexspec_f, host_colors) { \
	FDL_ASSERT(!((host_colors) & ~((1 << XF_INVERTEXSPEC_F_HOST_COLORS_SIZE)-1))); \
	xf_invertexspec_f = (((unsigned long)(xf_invertexspec_f)) & ~XF_INVERTEXSPEC_F_HOST_COLORS_MASK) | (((unsigned long)(host_colors)) << XF_INVERTEXSPEC_F_HOST_COLORS_SHIFT);\
}
#define XF_INVERTEXSPEC_F_HOST_NORMAL_SIZE	2
#define XF_INVERTEXSPEC_F_HOST_NORMAL_SHIFT	2
#define XF_INVERTEXSPEC_F_HOST_NORMAL_MASK	0x0000000c
#define XF_INVERTEXSPEC_F_GET_HOST_NORMAL(xf_invertexspec_f) \
	((((unsigned long)(xf_invertexspec_f)) & XF_INVERTEXSPEC_F_HOST_NORMAL_MASK) >> XF_INVERTEXSPEC_F_HOST_NORMAL_SHIFT)
#define XF_INVERTEXSPEC_F_SET_HOST_NORMAL(xf_invertexspec_f, host_normal) { \
	FDL_ASSERT(!((host_normal) & ~((1 << XF_INVERTEXSPEC_F_HOST_NORMAL_SIZE)-1))); \
	xf_invertexspec_f = (((unsigned long)(xf_invertexspec_f)) & ~XF_INVERTEXSPEC_F_HOST_NORMAL_MASK) | (((unsigned long)(host_normal)) << XF_INVERTEXSPEC_F_HOST_NORMAL_SHIFT);\
}
#define XF_INVERTEXSPEC_F_HOST_TEXTURES_SIZE	4
#define XF_INVERTEXSPEC_F_HOST_TEXTURES_SHIFT	4
#define XF_INVERTEXSPEC_F_HOST_TEXTURES_MASK	0x000000f0
#define XF_INVERTEXSPEC_F_GET_HOST_TEXTURES(xf_invertexspec_f) \
	((((unsigned long)(xf_invertexspec_f)) & XF_INVERTEXSPEC_F_HOST_TEXTURES_MASK) >> XF_INVERTEXSPEC_F_HOST_TEXTURES_SHIFT)
#define XF_INVERTEXSPEC_F_SET_HOST_TEXTURES(xf_invertexspec_f, host_textures) { \
	FDL_ASSERT(!((host_textures) & ~((1 << XF_INVERTEXSPEC_F_HOST_TEXTURES_SIZE)-1))); \
	xf_invertexspec_f = (((unsigned long)(xf_invertexspec_f)) & ~XF_INVERTEXSPEC_F_HOST_TEXTURES_MASK) | (((unsigned long)(host_textures)) << XF_INVERTEXSPEC_F_HOST_TEXTURES_SHIFT);\
}
#define XF_INVERTEXSPEC_F_TOTAL_SIZE	8
#define XF_INVERTEXSPEC_F_UNUSED_SIZE	24

#define XF_INVERTEXSPEC_F(host_colors, host_normal, host_textures) \
	((((unsigned long)(host_colors)) << XF_INVERTEXSPEC_F_HOST_COLORS_SHIFT) | \
	 (((unsigned long)(host_normal)) << XF_INVERTEXSPEC_F_HOST_NORMAL_SHIFT) | \
	 (((unsigned long)(host_textures)) << XF_INVERTEXSPEC_F_HOST_TEXTURES_SHIFT))

typedef struct {
    unsigned long unused:XF_INVERTEXSPEC_F_UNUSED_SIZE;
    unsigned long host_textures:XF_INVERTEXSPEC_F_HOST_TEXTURES_SIZE;
    unsigned long host_normal:XF_INVERTEXSPEC_F_HOST_NORMAL_SIZE;
    unsigned long host_colors:XF_INVERTEXSPEC_F_HOST_COLORS_SIZE;
} xf_invertexspec_f_t;

typedef union {
    unsigned long val;
    xf_invertexspec_f_t f;
} xf_invertexspec_f_u;

/*
 *  xf_host_colors enum
 */
#define NO_COLORS	0x00000000
#define HOST_COLOR0	0x00000001
#define HOST_COLORS01	0x00000002
#define XF_HOST_COLORS_UNUSED_3	0x00000003

/*
 *  xf_host_normal enum
 */
#define NO_NORMALS	0x00000000
#define HOST_NORMAL	0x00000001
#define HOST_NORMAL_BINORMALS	0x00000002
#define XF_HOST_NORMAL_UNUSED_3	0x00000003

/*
 *  xf_numcolors_f struct
 */
#define XF_NUMCOLORS_F_GEN_NUMCOLORS_SIZE	2
#define XF_NUMCOLORS_F_GEN_NUMCOLORS_SHIFT	0
#define XF_NUMCOLORS_F_GEN_NUMCOLORS_MASK	0x00000003
#define XF_NUMCOLORS_F_GET_GEN_NUMCOLORS(xf_numcolors_f) \
	((((unsigned long)(xf_numcolors_f)) & XF_NUMCOLORS_F_GEN_NUMCOLORS_MASK) >> XF_NUMCOLORS_F_GEN_NUMCOLORS_SHIFT)
#define XF_NUMCOLORS_F_SET_GEN_NUMCOLORS(xf_numcolors_f, gen_numcolors) { \
	FDL_ASSERT(!((gen_numcolors) & ~((1 << XF_NUMCOLORS_F_GEN_NUMCOLORS_SIZE)-1))); \
	xf_numcolors_f = (((unsigned long)(xf_numcolors_f)) & ~XF_NUMCOLORS_F_GEN_NUMCOLORS_MASK) | (((unsigned long)(gen_numcolors)) << XF_NUMCOLORS_F_GEN_NUMCOLORS_SHIFT);\
}
#define XF_NUMCOLORS_F_TOTAL_SIZE	2
#define XF_NUMCOLORS_F_UNUSED_SIZE	30

#define XF_NUMCOLORS_F(gen_numcolors) \
	((((unsigned long)(gen_numcolors)) << XF_NUMCOLORS_F_GEN_NUMCOLORS_SHIFT))

typedef struct {
    unsigned long unused:XF_NUMCOLORS_F_UNUSED_SIZE;
    unsigned long gen_numcolors:XF_NUMCOLORS_F_GEN_NUMCOLORS_SIZE;
} xf_numcolors_f_t;

typedef union {
    unsigned long val;
    xf_numcolors_f_t f;
} xf_numcolors_f_u;

/*
 *  xf_color0cntrl_f struct
 */
#define XF_COLOR0CNTRL_F_MATERIAL_SRC_SIZE	1
#define XF_COLOR0CNTRL_F_MATERIAL_SRC_SHIFT	0
#define XF_COLOR0CNTRL_F_MATERIAL_SRC_MASK	0x00000001
#define XF_COLOR0CNTRL_F_GET_MATERIAL_SRC(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_MATERIAL_SRC_MASK) >> XF_COLOR0CNTRL_F_MATERIAL_SRC_SHIFT)
#define XF_COLOR0CNTRL_F_SET_MATERIAL_SRC(xf_color0cntrl_f, material_src) { \
	FDL_ASSERT(!((material_src) & ~((1 << XF_COLOR0CNTRL_F_MATERIAL_SRC_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_MATERIAL_SRC_MASK) | (((unsigned long)(material_src)) << XF_COLOR0CNTRL_F_MATERIAL_SRC_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHTFUNC_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHTFUNC_SHIFT	1
#define XF_COLOR0CNTRL_F_LIGHTFUNC_MASK	0x00000002
#define XF_COLOR0CNTRL_F_GET_LIGHTFUNC(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHTFUNC_MASK) >> XF_COLOR0CNTRL_F_LIGHTFUNC_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHTFUNC(xf_color0cntrl_f, lightfunc) { \
	FDL_ASSERT(!((lightfunc) & ~((1 << XF_COLOR0CNTRL_F_LIGHTFUNC_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHTFUNC_MASK) | (((unsigned long)(lightfunc)) << XF_COLOR0CNTRL_F_LIGHTFUNC_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT0_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT0_SHIFT	2
#define XF_COLOR0CNTRL_F_LIGHT0_MASK	0x00000004
#define XF_COLOR0CNTRL_F_GET_LIGHT0(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT0_MASK) >> XF_COLOR0CNTRL_F_LIGHT0_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT0(xf_color0cntrl_f, light0) { \
	FDL_ASSERT(!((light0) & ~((1 << XF_COLOR0CNTRL_F_LIGHT0_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT0_MASK) | (((unsigned long)(light0)) << XF_COLOR0CNTRL_F_LIGHT0_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT1_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT1_SHIFT	3
#define XF_COLOR0CNTRL_F_LIGHT1_MASK	0x00000008
#define XF_COLOR0CNTRL_F_GET_LIGHT1(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT1_MASK) >> XF_COLOR0CNTRL_F_LIGHT1_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT1(xf_color0cntrl_f, light1) { \
	FDL_ASSERT(!((light1) & ~((1 << XF_COLOR0CNTRL_F_LIGHT1_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT1_MASK) | (((unsigned long)(light1)) << XF_COLOR0CNTRL_F_LIGHT1_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT2_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT2_SHIFT	4
#define XF_COLOR0CNTRL_F_LIGHT2_MASK	0x00000010
#define XF_COLOR0CNTRL_F_GET_LIGHT2(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT2_MASK) >> XF_COLOR0CNTRL_F_LIGHT2_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT2(xf_color0cntrl_f, light2) { \
	FDL_ASSERT(!((light2) & ~((1 << XF_COLOR0CNTRL_F_LIGHT2_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT2_MASK) | (((unsigned long)(light2)) << XF_COLOR0CNTRL_F_LIGHT2_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT3_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT3_SHIFT	5
#define XF_COLOR0CNTRL_F_LIGHT3_MASK	0x00000020
#define XF_COLOR0CNTRL_F_GET_LIGHT3(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT3_MASK) >> XF_COLOR0CNTRL_F_LIGHT3_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT3(xf_color0cntrl_f, light3) { \
	FDL_ASSERT(!((light3) & ~((1 << XF_COLOR0CNTRL_F_LIGHT3_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT3_MASK) | (((unsigned long)(light3)) << XF_COLOR0CNTRL_F_LIGHT3_SHIFT);\
}
#define XF_COLOR0CNTRL_F_AMBIENT_SRC_SIZE	1
#define XF_COLOR0CNTRL_F_AMBIENT_SRC_SHIFT	6
#define XF_COLOR0CNTRL_F_AMBIENT_SRC_MASK	0x00000040
#define XF_COLOR0CNTRL_F_GET_AMBIENT_SRC(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_AMBIENT_SRC_MASK) >> XF_COLOR0CNTRL_F_AMBIENT_SRC_SHIFT)
#define XF_COLOR0CNTRL_F_SET_AMBIENT_SRC(xf_color0cntrl_f, ambient_src) { \
	FDL_ASSERT(!((ambient_src) & ~((1 << XF_COLOR0CNTRL_F_AMBIENT_SRC_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_AMBIENT_SRC_MASK) | (((unsigned long)(ambient_src)) << XF_COLOR0CNTRL_F_AMBIENT_SRC_SHIFT);\
}
#define XF_COLOR0CNTRL_F_DIFFUSEATTEN_SIZE	2
#define XF_COLOR0CNTRL_F_DIFFUSEATTEN_SHIFT	7
#define XF_COLOR0CNTRL_F_DIFFUSEATTEN_MASK	0x00000180
#define XF_COLOR0CNTRL_F_GET_DIFFUSEATTEN(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_DIFFUSEATTEN_MASK) >> XF_COLOR0CNTRL_F_DIFFUSEATTEN_SHIFT)
#define XF_COLOR0CNTRL_F_SET_DIFFUSEATTEN(xf_color0cntrl_f, diffuseatten) { \
	FDL_ASSERT(!((diffuseatten) & ~((1 << XF_COLOR0CNTRL_F_DIFFUSEATTEN_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_DIFFUSEATTEN_MASK) | (((unsigned long)(diffuseatten)) << XF_COLOR0CNTRL_F_DIFFUSEATTEN_SHIFT);\
}
#define XF_COLOR0CNTRL_F_ATTENENABLE_SIZE	1
#define XF_COLOR0CNTRL_F_ATTENENABLE_SHIFT	9
#define XF_COLOR0CNTRL_F_ATTENENABLE_MASK	0x00000200
#define XF_COLOR0CNTRL_F_GET_ATTENENABLE(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_ATTENENABLE_MASK) >> XF_COLOR0CNTRL_F_ATTENENABLE_SHIFT)
#define XF_COLOR0CNTRL_F_SET_ATTENENABLE(xf_color0cntrl_f, attenenable) { \
	FDL_ASSERT(!((attenenable) & ~((1 << XF_COLOR0CNTRL_F_ATTENENABLE_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_ATTENENABLE_MASK) | (((unsigned long)(attenenable)) << XF_COLOR0CNTRL_F_ATTENENABLE_SHIFT);\
}
#define XF_COLOR0CNTRL_F_ATTENSELECT_SIZE	1
#define XF_COLOR0CNTRL_F_ATTENSELECT_SHIFT	10
#define XF_COLOR0CNTRL_F_ATTENSELECT_MASK	0x00000400
#define XF_COLOR0CNTRL_F_GET_ATTENSELECT(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_ATTENSELECT_MASK) >> XF_COLOR0CNTRL_F_ATTENSELECT_SHIFT)
#define XF_COLOR0CNTRL_F_SET_ATTENSELECT(xf_color0cntrl_f, attenselect) { \
	FDL_ASSERT(!((attenselect) & ~((1 << XF_COLOR0CNTRL_F_ATTENSELECT_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_ATTENSELECT_MASK) | (((unsigned long)(attenselect)) << XF_COLOR0CNTRL_F_ATTENSELECT_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT4_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT4_SHIFT	11
#define XF_COLOR0CNTRL_F_LIGHT4_MASK	0x00000800
#define XF_COLOR0CNTRL_F_GET_LIGHT4(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT4_MASK) >> XF_COLOR0CNTRL_F_LIGHT4_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT4(xf_color0cntrl_f, light4) { \
	FDL_ASSERT(!((light4) & ~((1 << XF_COLOR0CNTRL_F_LIGHT4_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT4_MASK) | (((unsigned long)(light4)) << XF_COLOR0CNTRL_F_LIGHT4_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT5_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT5_SHIFT	12
#define XF_COLOR0CNTRL_F_LIGHT5_MASK	0x00001000
#define XF_COLOR0CNTRL_F_GET_LIGHT5(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT5_MASK) >> XF_COLOR0CNTRL_F_LIGHT5_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT5(xf_color0cntrl_f, light5) { \
	FDL_ASSERT(!((light5) & ~((1 << XF_COLOR0CNTRL_F_LIGHT5_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT5_MASK) | (((unsigned long)(light5)) << XF_COLOR0CNTRL_F_LIGHT5_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT6_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT6_SHIFT	13
#define XF_COLOR0CNTRL_F_LIGHT6_MASK	0x00002000
#define XF_COLOR0CNTRL_F_GET_LIGHT6(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT6_MASK) >> XF_COLOR0CNTRL_F_LIGHT6_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT6(xf_color0cntrl_f, light6) { \
	FDL_ASSERT(!((light6) & ~((1 << XF_COLOR0CNTRL_F_LIGHT6_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT6_MASK) | (((unsigned long)(light6)) << XF_COLOR0CNTRL_F_LIGHT6_SHIFT);\
}
#define XF_COLOR0CNTRL_F_LIGHT7_SIZE	1
#define XF_COLOR0CNTRL_F_LIGHT7_SHIFT	14
#define XF_COLOR0CNTRL_F_LIGHT7_MASK	0x00004000
#define XF_COLOR0CNTRL_F_GET_LIGHT7(xf_color0cntrl_f) \
	((((unsigned long)(xf_color0cntrl_f)) & XF_COLOR0CNTRL_F_LIGHT7_MASK) >> XF_COLOR0CNTRL_F_LIGHT7_SHIFT)
#define XF_COLOR0CNTRL_F_SET_LIGHT7(xf_color0cntrl_f, light7) { \
	FDL_ASSERT(!((light7) & ~((1 << XF_COLOR0CNTRL_F_LIGHT7_SIZE)-1))); \
	xf_color0cntrl_f = (((unsigned long)(xf_color0cntrl_f)) & ~XF_COLOR0CNTRL_F_LIGHT7_MASK) | (((unsigned long)(light7)) << XF_COLOR0CNTRL_F_LIGHT7_SHIFT);\
}
#define XF_COLOR0CNTRL_F_TOTAL_SIZE	15
#define XF_COLOR0CNTRL_F_UNUSED_SIZE	17

#define XF_COLOR0CNTRL_F(material_src, lightfunc, light0, light1, light2, light3, ambient_src, diffuseatten, attenenable, attenselect, light4, light5, light6, light7) \
	((((unsigned long)(material_src)) << XF_COLOR0CNTRL_F_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_COLOR0CNTRL_F_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light0)) << XF_COLOR0CNTRL_F_LIGHT0_SHIFT) | \
	 (((unsigned long)(light1)) << XF_COLOR0CNTRL_F_LIGHT1_SHIFT) | \
	 (((unsigned long)(light2)) << XF_COLOR0CNTRL_F_LIGHT2_SHIFT) | \
	 (((unsigned long)(light3)) << XF_COLOR0CNTRL_F_LIGHT3_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_COLOR0CNTRL_F_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_COLOR0CNTRL_F_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_COLOR0CNTRL_F_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_COLOR0CNTRL_F_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light4)) << XF_COLOR0CNTRL_F_LIGHT4_SHIFT) | \
	 (((unsigned long)(light5)) << XF_COLOR0CNTRL_F_LIGHT5_SHIFT) | \
	 (((unsigned long)(light6)) << XF_COLOR0CNTRL_F_LIGHT6_SHIFT) | \
	 (((unsigned long)(light7)) << XF_COLOR0CNTRL_F_LIGHT7_SHIFT))

typedef struct {
    unsigned long unused:XF_COLOR0CNTRL_F_UNUSED_SIZE;
    unsigned long light7:XF_COLOR0CNTRL_F_LIGHT7_SIZE;
    unsigned long light6:XF_COLOR0CNTRL_F_LIGHT6_SIZE;
    unsigned long light5:XF_COLOR0CNTRL_F_LIGHT5_SIZE;
    unsigned long light4:XF_COLOR0CNTRL_F_LIGHT4_SIZE;
    unsigned long attenselect:XF_COLOR0CNTRL_F_ATTENSELECT_SIZE;
    unsigned long attenenable:XF_COLOR0CNTRL_F_ATTENENABLE_SIZE;
    unsigned long diffuseatten:XF_COLOR0CNTRL_F_DIFFUSEATTEN_SIZE;
    unsigned long ambient_src:XF_COLOR0CNTRL_F_AMBIENT_SRC_SIZE;
    unsigned long light3:XF_COLOR0CNTRL_F_LIGHT3_SIZE;
    unsigned long light2:XF_COLOR0CNTRL_F_LIGHT2_SIZE;
    unsigned long light1:XF_COLOR0CNTRL_F_LIGHT1_SIZE;
    unsigned long light0:XF_COLOR0CNTRL_F_LIGHT0_SIZE;
    unsigned long lightfunc:XF_COLOR0CNTRL_F_LIGHTFUNC_SIZE;
    unsigned long material_src:XF_COLOR0CNTRL_F_MATERIAL_SRC_SIZE;
} xf_color0cntrl_f_t;

typedef union {
    unsigned long val;
    xf_color0cntrl_f_t f;
} xf_color0cntrl_f_u;

/*
 *  xf_color1cntrl_f struct
 */
#define XF_COLOR1CNTRL_F_MATERIAL_SRC_SIZE	1
#define XF_COLOR1CNTRL_F_MATERIAL_SRC_SHIFT	0
#define XF_COLOR1CNTRL_F_MATERIAL_SRC_MASK	0x00000001
#define XF_COLOR1CNTRL_F_GET_MATERIAL_SRC(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_MATERIAL_SRC_MASK) >> XF_COLOR1CNTRL_F_MATERIAL_SRC_SHIFT)
#define XF_COLOR1CNTRL_F_SET_MATERIAL_SRC(xf_color1cntrl_f, material_src) { \
	FDL_ASSERT(!((material_src) & ~((1 << XF_COLOR1CNTRL_F_MATERIAL_SRC_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_MATERIAL_SRC_MASK) | (((unsigned long)(material_src)) << XF_COLOR1CNTRL_F_MATERIAL_SRC_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHTFUNC_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHTFUNC_SHIFT	1
#define XF_COLOR1CNTRL_F_LIGHTFUNC_MASK	0x00000002
#define XF_COLOR1CNTRL_F_GET_LIGHTFUNC(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHTFUNC_MASK) >> XF_COLOR1CNTRL_F_LIGHTFUNC_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHTFUNC(xf_color1cntrl_f, lightfunc) { \
	FDL_ASSERT(!((lightfunc) & ~((1 << XF_COLOR1CNTRL_F_LIGHTFUNC_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHTFUNC_MASK) | (((unsigned long)(lightfunc)) << XF_COLOR1CNTRL_F_LIGHTFUNC_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT0_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT0_SHIFT	2
#define XF_COLOR1CNTRL_F_LIGHT0_MASK	0x00000004
#define XF_COLOR1CNTRL_F_GET_LIGHT0(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT0_MASK) >> XF_COLOR1CNTRL_F_LIGHT0_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT0(xf_color1cntrl_f, light0) { \
	FDL_ASSERT(!((light0) & ~((1 << XF_COLOR1CNTRL_F_LIGHT0_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT0_MASK) | (((unsigned long)(light0)) << XF_COLOR1CNTRL_F_LIGHT0_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT1_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT1_SHIFT	3
#define XF_COLOR1CNTRL_F_LIGHT1_MASK	0x00000008
#define XF_COLOR1CNTRL_F_GET_LIGHT1(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT1_MASK) >> XF_COLOR1CNTRL_F_LIGHT1_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT1(xf_color1cntrl_f, light1) { \
	FDL_ASSERT(!((light1) & ~((1 << XF_COLOR1CNTRL_F_LIGHT1_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT1_MASK) | (((unsigned long)(light1)) << XF_COLOR1CNTRL_F_LIGHT1_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT2_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT2_SHIFT	4
#define XF_COLOR1CNTRL_F_LIGHT2_MASK	0x00000010
#define XF_COLOR1CNTRL_F_GET_LIGHT2(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT2_MASK) >> XF_COLOR1CNTRL_F_LIGHT2_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT2(xf_color1cntrl_f, light2) { \
	FDL_ASSERT(!((light2) & ~((1 << XF_COLOR1CNTRL_F_LIGHT2_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT2_MASK) | (((unsigned long)(light2)) << XF_COLOR1CNTRL_F_LIGHT2_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT3_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT3_SHIFT	5
#define XF_COLOR1CNTRL_F_LIGHT3_MASK	0x00000020
#define XF_COLOR1CNTRL_F_GET_LIGHT3(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT3_MASK) >> XF_COLOR1CNTRL_F_LIGHT3_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT3(xf_color1cntrl_f, light3) { \
	FDL_ASSERT(!((light3) & ~((1 << XF_COLOR1CNTRL_F_LIGHT3_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT3_MASK) | (((unsigned long)(light3)) << XF_COLOR1CNTRL_F_LIGHT3_SHIFT);\
}
#define XF_COLOR1CNTRL_F_AMBIENT_SRC_SIZE	1
#define XF_COLOR1CNTRL_F_AMBIENT_SRC_SHIFT	6
#define XF_COLOR1CNTRL_F_AMBIENT_SRC_MASK	0x00000040
#define XF_COLOR1CNTRL_F_GET_AMBIENT_SRC(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_AMBIENT_SRC_MASK) >> XF_COLOR1CNTRL_F_AMBIENT_SRC_SHIFT)
#define XF_COLOR1CNTRL_F_SET_AMBIENT_SRC(xf_color1cntrl_f, ambient_src) { \
	FDL_ASSERT(!((ambient_src) & ~((1 << XF_COLOR1CNTRL_F_AMBIENT_SRC_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_AMBIENT_SRC_MASK) | (((unsigned long)(ambient_src)) << XF_COLOR1CNTRL_F_AMBIENT_SRC_SHIFT);\
}
#define XF_COLOR1CNTRL_F_DIFFUSEATTEN_SIZE	2
#define XF_COLOR1CNTRL_F_DIFFUSEATTEN_SHIFT	7
#define XF_COLOR1CNTRL_F_DIFFUSEATTEN_MASK	0x00000180
#define XF_COLOR1CNTRL_F_GET_DIFFUSEATTEN(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_DIFFUSEATTEN_MASK) >> XF_COLOR1CNTRL_F_DIFFUSEATTEN_SHIFT)
#define XF_COLOR1CNTRL_F_SET_DIFFUSEATTEN(xf_color1cntrl_f, diffuseatten) { \
	FDL_ASSERT(!((diffuseatten) & ~((1 << XF_COLOR1CNTRL_F_DIFFUSEATTEN_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_DIFFUSEATTEN_MASK) | (((unsigned long)(diffuseatten)) << XF_COLOR1CNTRL_F_DIFFUSEATTEN_SHIFT);\
}
#define XF_COLOR1CNTRL_F_ATTENENABLE_SIZE	1
#define XF_COLOR1CNTRL_F_ATTENENABLE_SHIFT	9
#define XF_COLOR1CNTRL_F_ATTENENABLE_MASK	0x00000200
#define XF_COLOR1CNTRL_F_GET_ATTENENABLE(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_ATTENENABLE_MASK) >> XF_COLOR1CNTRL_F_ATTENENABLE_SHIFT)
#define XF_COLOR1CNTRL_F_SET_ATTENENABLE(xf_color1cntrl_f, attenenable) { \
	FDL_ASSERT(!((attenenable) & ~((1 << XF_COLOR1CNTRL_F_ATTENENABLE_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_ATTENENABLE_MASK) | (((unsigned long)(attenenable)) << XF_COLOR1CNTRL_F_ATTENENABLE_SHIFT);\
}
#define XF_COLOR1CNTRL_F_ATTENSELECT_SIZE	1
#define XF_COLOR1CNTRL_F_ATTENSELECT_SHIFT	10
#define XF_COLOR1CNTRL_F_ATTENSELECT_MASK	0x00000400
#define XF_COLOR1CNTRL_F_GET_ATTENSELECT(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_ATTENSELECT_MASK) >> XF_COLOR1CNTRL_F_ATTENSELECT_SHIFT)
#define XF_COLOR1CNTRL_F_SET_ATTENSELECT(xf_color1cntrl_f, attenselect) { \
	FDL_ASSERT(!((attenselect) & ~((1 << XF_COLOR1CNTRL_F_ATTENSELECT_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_ATTENSELECT_MASK) | (((unsigned long)(attenselect)) << XF_COLOR1CNTRL_F_ATTENSELECT_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT4_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT4_SHIFT	11
#define XF_COLOR1CNTRL_F_LIGHT4_MASK	0x00000800
#define XF_COLOR1CNTRL_F_GET_LIGHT4(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT4_MASK) >> XF_COLOR1CNTRL_F_LIGHT4_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT4(xf_color1cntrl_f, light4) { \
	FDL_ASSERT(!((light4) & ~((1 << XF_COLOR1CNTRL_F_LIGHT4_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT4_MASK) | (((unsigned long)(light4)) << XF_COLOR1CNTRL_F_LIGHT4_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT5_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT5_SHIFT	12
#define XF_COLOR1CNTRL_F_LIGHT5_MASK	0x00001000
#define XF_COLOR1CNTRL_F_GET_LIGHT5(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT5_MASK) >> XF_COLOR1CNTRL_F_LIGHT5_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT5(xf_color1cntrl_f, light5) { \
	FDL_ASSERT(!((light5) & ~((1 << XF_COLOR1CNTRL_F_LIGHT5_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT5_MASK) | (((unsigned long)(light5)) << XF_COLOR1CNTRL_F_LIGHT5_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT6_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT6_SHIFT	13
#define XF_COLOR1CNTRL_F_LIGHT6_MASK	0x00002000
#define XF_COLOR1CNTRL_F_GET_LIGHT6(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT6_MASK) >> XF_COLOR1CNTRL_F_LIGHT6_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT6(xf_color1cntrl_f, light6) { \
	FDL_ASSERT(!((light6) & ~((1 << XF_COLOR1CNTRL_F_LIGHT6_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT6_MASK) | (((unsigned long)(light6)) << XF_COLOR1CNTRL_F_LIGHT6_SHIFT);\
}
#define XF_COLOR1CNTRL_F_LIGHT7_SIZE	1
#define XF_COLOR1CNTRL_F_LIGHT7_SHIFT	14
#define XF_COLOR1CNTRL_F_LIGHT7_MASK	0x00004000
#define XF_COLOR1CNTRL_F_GET_LIGHT7(xf_color1cntrl_f) \
	((((unsigned long)(xf_color1cntrl_f)) & XF_COLOR1CNTRL_F_LIGHT7_MASK) >> XF_COLOR1CNTRL_F_LIGHT7_SHIFT)
#define XF_COLOR1CNTRL_F_SET_LIGHT7(xf_color1cntrl_f, light7) { \
	FDL_ASSERT(!((light7) & ~((1 << XF_COLOR1CNTRL_F_LIGHT7_SIZE)-1))); \
	xf_color1cntrl_f = (((unsigned long)(xf_color1cntrl_f)) & ~XF_COLOR1CNTRL_F_LIGHT7_MASK) | (((unsigned long)(light7)) << XF_COLOR1CNTRL_F_LIGHT7_SHIFT);\
}
#define XF_COLOR1CNTRL_F_TOTAL_SIZE	15
#define XF_COLOR1CNTRL_F_UNUSED_SIZE	17

#define XF_COLOR1CNTRL_F(material_src, lightfunc, light0, light1, light2, light3, ambient_src, diffuseatten, attenenable, attenselect, light4, light5, light6, light7) \
	((((unsigned long)(material_src)) << XF_COLOR1CNTRL_F_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_COLOR1CNTRL_F_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light0)) << XF_COLOR1CNTRL_F_LIGHT0_SHIFT) | \
	 (((unsigned long)(light1)) << XF_COLOR1CNTRL_F_LIGHT1_SHIFT) | \
	 (((unsigned long)(light2)) << XF_COLOR1CNTRL_F_LIGHT2_SHIFT) | \
	 (((unsigned long)(light3)) << XF_COLOR1CNTRL_F_LIGHT3_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_COLOR1CNTRL_F_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_COLOR1CNTRL_F_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_COLOR1CNTRL_F_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_COLOR1CNTRL_F_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light4)) << XF_COLOR1CNTRL_F_LIGHT4_SHIFT) | \
	 (((unsigned long)(light5)) << XF_COLOR1CNTRL_F_LIGHT5_SHIFT) | \
	 (((unsigned long)(light6)) << XF_COLOR1CNTRL_F_LIGHT6_SHIFT) | \
	 (((unsigned long)(light7)) << XF_COLOR1CNTRL_F_LIGHT7_SHIFT))

typedef struct {
    unsigned long unused:XF_COLOR1CNTRL_F_UNUSED_SIZE;
    unsigned long light7:XF_COLOR1CNTRL_F_LIGHT7_SIZE;
    unsigned long light6:XF_COLOR1CNTRL_F_LIGHT6_SIZE;
    unsigned long light5:XF_COLOR1CNTRL_F_LIGHT5_SIZE;
    unsigned long light4:XF_COLOR1CNTRL_F_LIGHT4_SIZE;
    unsigned long attenselect:XF_COLOR1CNTRL_F_ATTENSELECT_SIZE;
    unsigned long attenenable:XF_COLOR1CNTRL_F_ATTENENABLE_SIZE;
    unsigned long diffuseatten:XF_COLOR1CNTRL_F_DIFFUSEATTEN_SIZE;
    unsigned long ambient_src:XF_COLOR1CNTRL_F_AMBIENT_SRC_SIZE;
    unsigned long light3:XF_COLOR1CNTRL_F_LIGHT3_SIZE;
    unsigned long light2:XF_COLOR1CNTRL_F_LIGHT2_SIZE;
    unsigned long light1:XF_COLOR1CNTRL_F_LIGHT1_SIZE;
    unsigned long light0:XF_COLOR1CNTRL_F_LIGHT0_SIZE;
    unsigned long lightfunc:XF_COLOR1CNTRL_F_LIGHTFUNC_SIZE;
    unsigned long material_src:XF_COLOR1CNTRL_F_MATERIAL_SRC_SIZE;
} xf_color1cntrl_f_t;

typedef union {
    unsigned long val;
    xf_color1cntrl_f_t f;
} xf_color1cntrl_f_u;

/*
 *  xf_alpha0cntrl_f struct
 */
#define XF_ALPHA0CNTRL_F_MATERIAL_SRC_SIZE	1
#define XF_ALPHA0CNTRL_F_MATERIAL_SRC_SHIFT	0
#define XF_ALPHA0CNTRL_F_MATERIAL_SRC_MASK	0x00000001
#define XF_ALPHA0CNTRL_F_GET_MATERIAL_SRC(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_MATERIAL_SRC_MASK) >> XF_ALPHA0CNTRL_F_MATERIAL_SRC_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_MATERIAL_SRC(xf_alpha0cntrl_f, material_src) { \
	FDL_ASSERT(!((material_src) & ~((1 << XF_ALPHA0CNTRL_F_MATERIAL_SRC_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_MATERIAL_SRC_MASK) | (((unsigned long)(material_src)) << XF_ALPHA0CNTRL_F_MATERIAL_SRC_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHTFUNC_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHTFUNC_SHIFT	1
#define XF_ALPHA0CNTRL_F_LIGHTFUNC_MASK	0x00000002
#define XF_ALPHA0CNTRL_F_GET_LIGHTFUNC(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHTFUNC_MASK) >> XF_ALPHA0CNTRL_F_LIGHTFUNC_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHTFUNC(xf_alpha0cntrl_f, lightfunc) { \
	FDL_ASSERT(!((lightfunc) & ~((1 << XF_ALPHA0CNTRL_F_LIGHTFUNC_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHTFUNC_MASK) | (((unsigned long)(lightfunc)) << XF_ALPHA0CNTRL_F_LIGHTFUNC_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT0_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT0_SHIFT	2
#define XF_ALPHA0CNTRL_F_LIGHT0_MASK	0x00000004
#define XF_ALPHA0CNTRL_F_GET_LIGHT0(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT0_MASK) >> XF_ALPHA0CNTRL_F_LIGHT0_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT0(xf_alpha0cntrl_f, light0) { \
	FDL_ASSERT(!((light0) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT0_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT0_MASK) | (((unsigned long)(light0)) << XF_ALPHA0CNTRL_F_LIGHT0_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT1_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT1_SHIFT	3
#define XF_ALPHA0CNTRL_F_LIGHT1_MASK	0x00000008
#define XF_ALPHA0CNTRL_F_GET_LIGHT1(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT1_MASK) >> XF_ALPHA0CNTRL_F_LIGHT1_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT1(xf_alpha0cntrl_f, light1) { \
	FDL_ASSERT(!((light1) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT1_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT1_MASK) | (((unsigned long)(light1)) << XF_ALPHA0CNTRL_F_LIGHT1_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT2_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT2_SHIFT	4
#define XF_ALPHA0CNTRL_F_LIGHT2_MASK	0x00000010
#define XF_ALPHA0CNTRL_F_GET_LIGHT2(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT2_MASK) >> XF_ALPHA0CNTRL_F_LIGHT2_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT2(xf_alpha0cntrl_f, light2) { \
	FDL_ASSERT(!((light2) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT2_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT2_MASK) | (((unsigned long)(light2)) << XF_ALPHA0CNTRL_F_LIGHT2_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT3_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT3_SHIFT	5
#define XF_ALPHA0CNTRL_F_LIGHT3_MASK	0x00000020
#define XF_ALPHA0CNTRL_F_GET_LIGHT3(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT3_MASK) >> XF_ALPHA0CNTRL_F_LIGHT3_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT3(xf_alpha0cntrl_f, light3) { \
	FDL_ASSERT(!((light3) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT3_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT3_MASK) | (((unsigned long)(light3)) << XF_ALPHA0CNTRL_F_LIGHT3_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_AMBIENT_SRC_SIZE	1
#define XF_ALPHA0CNTRL_F_AMBIENT_SRC_SHIFT	6
#define XF_ALPHA0CNTRL_F_AMBIENT_SRC_MASK	0x00000040
#define XF_ALPHA0CNTRL_F_GET_AMBIENT_SRC(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_AMBIENT_SRC_MASK) >> XF_ALPHA0CNTRL_F_AMBIENT_SRC_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_AMBIENT_SRC(xf_alpha0cntrl_f, ambient_src) { \
	FDL_ASSERT(!((ambient_src) & ~((1 << XF_ALPHA0CNTRL_F_AMBIENT_SRC_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_AMBIENT_SRC_MASK) | (((unsigned long)(ambient_src)) << XF_ALPHA0CNTRL_F_AMBIENT_SRC_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SIZE	2
#define XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SHIFT	7
#define XF_ALPHA0CNTRL_F_DIFFUSEATTEN_MASK	0x00000180
#define XF_ALPHA0CNTRL_F_GET_DIFFUSEATTEN(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_DIFFUSEATTEN_MASK) >> XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_DIFFUSEATTEN(xf_alpha0cntrl_f, diffuseatten) { \
	FDL_ASSERT(!((diffuseatten) & ~((1 << XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_DIFFUSEATTEN_MASK) | (((unsigned long)(diffuseatten)) << XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_ATTENENABLE_SIZE	1
#define XF_ALPHA0CNTRL_F_ATTENENABLE_SHIFT	9
#define XF_ALPHA0CNTRL_F_ATTENENABLE_MASK	0x00000200
#define XF_ALPHA0CNTRL_F_GET_ATTENENABLE(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_ATTENENABLE_MASK) >> XF_ALPHA0CNTRL_F_ATTENENABLE_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_ATTENENABLE(xf_alpha0cntrl_f, attenenable) { \
	FDL_ASSERT(!((attenenable) & ~((1 << XF_ALPHA0CNTRL_F_ATTENENABLE_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_ATTENENABLE_MASK) | (((unsigned long)(attenenable)) << XF_ALPHA0CNTRL_F_ATTENENABLE_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_ATTENSELECT_SIZE	1
#define XF_ALPHA0CNTRL_F_ATTENSELECT_SHIFT	10
#define XF_ALPHA0CNTRL_F_ATTENSELECT_MASK	0x00000400
#define XF_ALPHA0CNTRL_F_GET_ATTENSELECT(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_ATTENSELECT_MASK) >> XF_ALPHA0CNTRL_F_ATTENSELECT_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_ATTENSELECT(xf_alpha0cntrl_f, attenselect) { \
	FDL_ASSERT(!((attenselect) & ~((1 << XF_ALPHA0CNTRL_F_ATTENSELECT_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_ATTENSELECT_MASK) | (((unsigned long)(attenselect)) << XF_ALPHA0CNTRL_F_ATTENSELECT_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT4_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT4_SHIFT	11
#define XF_ALPHA0CNTRL_F_LIGHT4_MASK	0x00000800
#define XF_ALPHA0CNTRL_F_GET_LIGHT4(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT4_MASK) >> XF_ALPHA0CNTRL_F_LIGHT4_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT4(xf_alpha0cntrl_f, light4) { \
	FDL_ASSERT(!((light4) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT4_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT4_MASK) | (((unsigned long)(light4)) << XF_ALPHA0CNTRL_F_LIGHT4_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT5_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT5_SHIFT	12
#define XF_ALPHA0CNTRL_F_LIGHT5_MASK	0x00001000
#define XF_ALPHA0CNTRL_F_GET_LIGHT5(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT5_MASK) >> XF_ALPHA0CNTRL_F_LIGHT5_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT5(xf_alpha0cntrl_f, light5) { \
	FDL_ASSERT(!((light5) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT5_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT5_MASK) | (((unsigned long)(light5)) << XF_ALPHA0CNTRL_F_LIGHT5_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT6_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT6_SHIFT	13
#define XF_ALPHA0CNTRL_F_LIGHT6_MASK	0x00002000
#define XF_ALPHA0CNTRL_F_GET_LIGHT6(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT6_MASK) >> XF_ALPHA0CNTRL_F_LIGHT6_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT6(xf_alpha0cntrl_f, light6) { \
	FDL_ASSERT(!((light6) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT6_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT6_MASK) | (((unsigned long)(light6)) << XF_ALPHA0CNTRL_F_LIGHT6_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_LIGHT7_SIZE	1
#define XF_ALPHA0CNTRL_F_LIGHT7_SHIFT	14
#define XF_ALPHA0CNTRL_F_LIGHT7_MASK	0x00004000
#define XF_ALPHA0CNTRL_F_GET_LIGHT7(xf_alpha0cntrl_f) \
	((((unsigned long)(xf_alpha0cntrl_f)) & XF_ALPHA0CNTRL_F_LIGHT7_MASK) >> XF_ALPHA0CNTRL_F_LIGHT7_SHIFT)
#define XF_ALPHA0CNTRL_F_SET_LIGHT7(xf_alpha0cntrl_f, light7) { \
	FDL_ASSERT(!((light7) & ~((1 << XF_ALPHA0CNTRL_F_LIGHT7_SIZE)-1))); \
	xf_alpha0cntrl_f = (((unsigned long)(xf_alpha0cntrl_f)) & ~XF_ALPHA0CNTRL_F_LIGHT7_MASK) | (((unsigned long)(light7)) << XF_ALPHA0CNTRL_F_LIGHT7_SHIFT);\
}
#define XF_ALPHA0CNTRL_F_TOTAL_SIZE	15
#define XF_ALPHA0CNTRL_F_UNUSED_SIZE	17

#define XF_ALPHA0CNTRL_F(material_src, lightfunc, light0, light1, light2, light3, ambient_src, diffuseatten, attenenable, attenselect, light4, light5, light6, light7) \
	((((unsigned long)(material_src)) << XF_ALPHA0CNTRL_F_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_ALPHA0CNTRL_F_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light0)) << XF_ALPHA0CNTRL_F_LIGHT0_SHIFT) | \
	 (((unsigned long)(light1)) << XF_ALPHA0CNTRL_F_LIGHT1_SHIFT) | \
	 (((unsigned long)(light2)) << XF_ALPHA0CNTRL_F_LIGHT2_SHIFT) | \
	 (((unsigned long)(light3)) << XF_ALPHA0CNTRL_F_LIGHT3_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_ALPHA0CNTRL_F_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_ALPHA0CNTRL_F_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_ALPHA0CNTRL_F_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light4)) << XF_ALPHA0CNTRL_F_LIGHT4_SHIFT) | \
	 (((unsigned long)(light5)) << XF_ALPHA0CNTRL_F_LIGHT5_SHIFT) | \
	 (((unsigned long)(light6)) << XF_ALPHA0CNTRL_F_LIGHT6_SHIFT) | \
	 (((unsigned long)(light7)) << XF_ALPHA0CNTRL_F_LIGHT7_SHIFT))

typedef struct {
    unsigned long unused:XF_ALPHA0CNTRL_F_UNUSED_SIZE;
    unsigned long light7:XF_ALPHA0CNTRL_F_LIGHT7_SIZE;
    unsigned long light6:XF_ALPHA0CNTRL_F_LIGHT6_SIZE;
    unsigned long light5:XF_ALPHA0CNTRL_F_LIGHT5_SIZE;
    unsigned long light4:XF_ALPHA0CNTRL_F_LIGHT4_SIZE;
    unsigned long attenselect:XF_ALPHA0CNTRL_F_ATTENSELECT_SIZE;
    unsigned long attenenable:XF_ALPHA0CNTRL_F_ATTENENABLE_SIZE;
    unsigned long diffuseatten:XF_ALPHA0CNTRL_F_DIFFUSEATTEN_SIZE;
    unsigned long ambient_src:XF_ALPHA0CNTRL_F_AMBIENT_SRC_SIZE;
    unsigned long light3:XF_ALPHA0CNTRL_F_LIGHT3_SIZE;
    unsigned long light2:XF_ALPHA0CNTRL_F_LIGHT2_SIZE;
    unsigned long light1:XF_ALPHA0CNTRL_F_LIGHT1_SIZE;
    unsigned long light0:XF_ALPHA0CNTRL_F_LIGHT0_SIZE;
    unsigned long lightfunc:XF_ALPHA0CNTRL_F_LIGHTFUNC_SIZE;
    unsigned long material_src:XF_ALPHA0CNTRL_F_MATERIAL_SRC_SIZE;
} xf_alpha0cntrl_f_t;

typedef union {
    unsigned long val;
    xf_alpha0cntrl_f_t f;
} xf_alpha0cntrl_f_u;

/*
 *  xf_alpha1cntrl_f struct
 */
#define XF_ALPHA1CNTRL_F_MATERIAL_SRC_SIZE	1
#define XF_ALPHA1CNTRL_F_MATERIAL_SRC_SHIFT	0
#define XF_ALPHA1CNTRL_F_MATERIAL_SRC_MASK	0x00000001
#define XF_ALPHA1CNTRL_F_GET_MATERIAL_SRC(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_MATERIAL_SRC_MASK) >> XF_ALPHA1CNTRL_F_MATERIAL_SRC_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_MATERIAL_SRC(xf_alpha1cntrl_f, material_src) { \
	FDL_ASSERT(!((material_src) & ~((1 << XF_ALPHA1CNTRL_F_MATERIAL_SRC_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_MATERIAL_SRC_MASK) | (((unsigned long)(material_src)) << XF_ALPHA1CNTRL_F_MATERIAL_SRC_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHTFUNC_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHTFUNC_SHIFT	1
#define XF_ALPHA1CNTRL_F_LIGHTFUNC_MASK	0x00000002
#define XF_ALPHA1CNTRL_F_GET_LIGHTFUNC(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHTFUNC_MASK) >> XF_ALPHA1CNTRL_F_LIGHTFUNC_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHTFUNC(xf_alpha1cntrl_f, lightfunc) { \
	FDL_ASSERT(!((lightfunc) & ~((1 << XF_ALPHA1CNTRL_F_LIGHTFUNC_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHTFUNC_MASK) | (((unsigned long)(lightfunc)) << XF_ALPHA1CNTRL_F_LIGHTFUNC_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT0_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT0_SHIFT	2
#define XF_ALPHA1CNTRL_F_LIGHT0_MASK	0x00000004
#define XF_ALPHA1CNTRL_F_GET_LIGHT0(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT0_MASK) >> XF_ALPHA1CNTRL_F_LIGHT0_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT0(xf_alpha1cntrl_f, light0) { \
	FDL_ASSERT(!((light0) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT0_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT0_MASK) | (((unsigned long)(light0)) << XF_ALPHA1CNTRL_F_LIGHT0_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT1_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT1_SHIFT	3
#define XF_ALPHA1CNTRL_F_LIGHT1_MASK	0x00000008
#define XF_ALPHA1CNTRL_F_GET_LIGHT1(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT1_MASK) >> XF_ALPHA1CNTRL_F_LIGHT1_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT1(xf_alpha1cntrl_f, light1) { \
	FDL_ASSERT(!((light1) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT1_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT1_MASK) | (((unsigned long)(light1)) << XF_ALPHA1CNTRL_F_LIGHT1_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT2_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT2_SHIFT	4
#define XF_ALPHA1CNTRL_F_LIGHT2_MASK	0x00000010
#define XF_ALPHA1CNTRL_F_GET_LIGHT2(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT2_MASK) >> XF_ALPHA1CNTRL_F_LIGHT2_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT2(xf_alpha1cntrl_f, light2) { \
	FDL_ASSERT(!((light2) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT2_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT2_MASK) | (((unsigned long)(light2)) << XF_ALPHA1CNTRL_F_LIGHT2_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT3_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT3_SHIFT	5
#define XF_ALPHA1CNTRL_F_LIGHT3_MASK	0x00000020
#define XF_ALPHA1CNTRL_F_GET_LIGHT3(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT3_MASK) >> XF_ALPHA1CNTRL_F_LIGHT3_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT3(xf_alpha1cntrl_f, light3) { \
	FDL_ASSERT(!((light3) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT3_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT3_MASK) | (((unsigned long)(light3)) << XF_ALPHA1CNTRL_F_LIGHT3_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_AMBIENT_SRC_SIZE	1
#define XF_ALPHA1CNTRL_F_AMBIENT_SRC_SHIFT	6
#define XF_ALPHA1CNTRL_F_AMBIENT_SRC_MASK	0x00000040
#define XF_ALPHA1CNTRL_F_GET_AMBIENT_SRC(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_AMBIENT_SRC_MASK) >> XF_ALPHA1CNTRL_F_AMBIENT_SRC_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_AMBIENT_SRC(xf_alpha1cntrl_f, ambient_src) { \
	FDL_ASSERT(!((ambient_src) & ~((1 << XF_ALPHA1CNTRL_F_AMBIENT_SRC_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_AMBIENT_SRC_MASK) | (((unsigned long)(ambient_src)) << XF_ALPHA1CNTRL_F_AMBIENT_SRC_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SIZE	2
#define XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SHIFT	7
#define XF_ALPHA1CNTRL_F_DIFFUSEATTEN_MASK	0x00000180
#define XF_ALPHA1CNTRL_F_GET_DIFFUSEATTEN(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_DIFFUSEATTEN_MASK) >> XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_DIFFUSEATTEN(xf_alpha1cntrl_f, diffuseatten) { \
	FDL_ASSERT(!((diffuseatten) & ~((1 << XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_DIFFUSEATTEN_MASK) | (((unsigned long)(diffuseatten)) << XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_ATTENENABLE_SIZE	1
#define XF_ALPHA1CNTRL_F_ATTENENABLE_SHIFT	9
#define XF_ALPHA1CNTRL_F_ATTENENABLE_MASK	0x00000200
#define XF_ALPHA1CNTRL_F_GET_ATTENENABLE(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_ATTENENABLE_MASK) >> XF_ALPHA1CNTRL_F_ATTENENABLE_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_ATTENENABLE(xf_alpha1cntrl_f, attenenable) { \
	FDL_ASSERT(!((attenenable) & ~((1 << XF_ALPHA1CNTRL_F_ATTENENABLE_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_ATTENENABLE_MASK) | (((unsigned long)(attenenable)) << XF_ALPHA1CNTRL_F_ATTENENABLE_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_ATTENSELECT_SIZE	1
#define XF_ALPHA1CNTRL_F_ATTENSELECT_SHIFT	10
#define XF_ALPHA1CNTRL_F_ATTENSELECT_MASK	0x00000400
#define XF_ALPHA1CNTRL_F_GET_ATTENSELECT(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_ATTENSELECT_MASK) >> XF_ALPHA1CNTRL_F_ATTENSELECT_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_ATTENSELECT(xf_alpha1cntrl_f, attenselect) { \
	FDL_ASSERT(!((attenselect) & ~((1 << XF_ALPHA1CNTRL_F_ATTENSELECT_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_ATTENSELECT_MASK) | (((unsigned long)(attenselect)) << XF_ALPHA1CNTRL_F_ATTENSELECT_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT4_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT4_SHIFT	11
#define XF_ALPHA1CNTRL_F_LIGHT4_MASK	0x00000800
#define XF_ALPHA1CNTRL_F_GET_LIGHT4(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT4_MASK) >> XF_ALPHA1CNTRL_F_LIGHT4_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT4(xf_alpha1cntrl_f, light4) { \
	FDL_ASSERT(!((light4) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT4_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT4_MASK) | (((unsigned long)(light4)) << XF_ALPHA1CNTRL_F_LIGHT4_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT5_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT5_SHIFT	12
#define XF_ALPHA1CNTRL_F_LIGHT5_MASK	0x00001000
#define XF_ALPHA1CNTRL_F_GET_LIGHT5(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT5_MASK) >> XF_ALPHA1CNTRL_F_LIGHT5_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT5(xf_alpha1cntrl_f, light5) { \
	FDL_ASSERT(!((light5) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT5_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT5_MASK) | (((unsigned long)(light5)) << XF_ALPHA1CNTRL_F_LIGHT5_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT6_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT6_SHIFT	13
#define XF_ALPHA1CNTRL_F_LIGHT6_MASK	0x00002000
#define XF_ALPHA1CNTRL_F_GET_LIGHT6(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT6_MASK) >> XF_ALPHA1CNTRL_F_LIGHT6_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT6(xf_alpha1cntrl_f, light6) { \
	FDL_ASSERT(!((light6) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT6_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT6_MASK) | (((unsigned long)(light6)) << XF_ALPHA1CNTRL_F_LIGHT6_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_LIGHT7_SIZE	1
#define XF_ALPHA1CNTRL_F_LIGHT7_SHIFT	14
#define XF_ALPHA1CNTRL_F_LIGHT7_MASK	0x00004000
#define XF_ALPHA1CNTRL_F_GET_LIGHT7(xf_alpha1cntrl_f) \
	((((unsigned long)(xf_alpha1cntrl_f)) & XF_ALPHA1CNTRL_F_LIGHT7_MASK) >> XF_ALPHA1CNTRL_F_LIGHT7_SHIFT)
#define XF_ALPHA1CNTRL_F_SET_LIGHT7(xf_alpha1cntrl_f, light7) { \
	FDL_ASSERT(!((light7) & ~((1 << XF_ALPHA1CNTRL_F_LIGHT7_SIZE)-1))); \
	xf_alpha1cntrl_f = (((unsigned long)(xf_alpha1cntrl_f)) & ~XF_ALPHA1CNTRL_F_LIGHT7_MASK) | (((unsigned long)(light7)) << XF_ALPHA1CNTRL_F_LIGHT7_SHIFT);\
}
#define XF_ALPHA1CNTRL_F_TOTAL_SIZE	15
#define XF_ALPHA1CNTRL_F_UNUSED_SIZE	17

#define XF_ALPHA1CNTRL_F(material_src, lightfunc, light0, light1, light2, light3, ambient_src, diffuseatten, attenenable, attenselect, light4, light5, light6, light7) \
	((((unsigned long)(material_src)) << XF_ALPHA1CNTRL_F_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_ALPHA1CNTRL_F_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light0)) << XF_ALPHA1CNTRL_F_LIGHT0_SHIFT) | \
	 (((unsigned long)(light1)) << XF_ALPHA1CNTRL_F_LIGHT1_SHIFT) | \
	 (((unsigned long)(light2)) << XF_ALPHA1CNTRL_F_LIGHT2_SHIFT) | \
	 (((unsigned long)(light3)) << XF_ALPHA1CNTRL_F_LIGHT3_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_ALPHA1CNTRL_F_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_ALPHA1CNTRL_F_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_ALPHA1CNTRL_F_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light4)) << XF_ALPHA1CNTRL_F_LIGHT4_SHIFT) | \
	 (((unsigned long)(light5)) << XF_ALPHA1CNTRL_F_LIGHT5_SHIFT) | \
	 (((unsigned long)(light6)) << XF_ALPHA1CNTRL_F_LIGHT6_SHIFT) | \
	 (((unsigned long)(light7)) << XF_ALPHA1CNTRL_F_LIGHT7_SHIFT))

typedef struct {
    unsigned long unused:XF_ALPHA1CNTRL_F_UNUSED_SIZE;
    unsigned long light7:XF_ALPHA1CNTRL_F_LIGHT7_SIZE;
    unsigned long light6:XF_ALPHA1CNTRL_F_LIGHT6_SIZE;
    unsigned long light5:XF_ALPHA1CNTRL_F_LIGHT5_SIZE;
    unsigned long light4:XF_ALPHA1CNTRL_F_LIGHT4_SIZE;
    unsigned long attenselect:XF_ALPHA1CNTRL_F_ATTENSELECT_SIZE;
    unsigned long attenenable:XF_ALPHA1CNTRL_F_ATTENENABLE_SIZE;
    unsigned long diffuseatten:XF_ALPHA1CNTRL_F_DIFFUSEATTEN_SIZE;
    unsigned long ambient_src:XF_ALPHA1CNTRL_F_AMBIENT_SRC_SIZE;
    unsigned long light3:XF_ALPHA1CNTRL_F_LIGHT3_SIZE;
    unsigned long light2:XF_ALPHA1CNTRL_F_LIGHT2_SIZE;
    unsigned long light1:XF_ALPHA1CNTRL_F_LIGHT1_SIZE;
    unsigned long light0:XF_ALPHA1CNTRL_F_LIGHT0_SIZE;
    unsigned long lightfunc:XF_ALPHA1CNTRL_F_LIGHTFUNC_SIZE;
    unsigned long material_src:XF_ALPHA1CNTRL_F_MATERIAL_SRC_SIZE;
} xf_alpha1cntrl_f_t;

typedef union {
    unsigned long val;
    xf_alpha1cntrl_f_t f;
} xf_alpha1cntrl_f_u;

/*
 *  xf_material_src_f enum
 */
#define REGISTER	0x00000000
#define CP_SUPPLIED	0x00000001

/*
 *  xf_lightfunc_f enum
 */
#define LF_ONE	0x00000000
#define LF_ILLUM	0x00000001

/*
 *  xf_light0_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light1_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light2_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light3_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light4_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light5_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light6_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_light7_f enum
 */
#define NOT_USED	0x00000000
#define USE	0x00000001

/*
 *  xf_ambient_src_f enum
 */
#define REGISTER	0x00000000
#define CP_SUPPLIED	0x00000001

/*
 *  xf_diffuseatten_f enum
 */
#define NL_ONE	0x00000000
#define NL_SIGNED	0x00000001
#define NL_CLAMP	0x00000002
#define XF_DIFFUSEATTEN_F_UNUSED_3	0x00000003

/*
 *  xf_attenenable_f enum
 */
#define ATTEN_ONE	0x00000000
#define ATTEN_FRAC	0x00000001

/*
 *  xf_attenselect_f enum
 */
#define SPECULAR	0x00000000
#define SPOTLIGHT	0x00000001

/*
 *  xf_tex struct
 */
#define XF_TEX_RESERVED0_SIZE	1
#define XF_TEX_RESERVED0_SHIFT	0
#define XF_TEX_RESERVED0_MASK	0x00000001
#define XF_TEX_GET_RESERVED0(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_RESERVED0_MASK) >> XF_TEX_RESERVED0_SHIFT)
#define XF_TEX_SET_RESERVED0(xf_tex, reserved0) { \
	FDL_ASSERT(!((reserved0) & ~((1 << XF_TEX_RESERVED0_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_RESERVED0_MASK) | (((unsigned long)(reserved0)) << XF_TEX_RESERVED0_SHIFT);\
}
#define XF_TEX_PROJECTION_SIZE	1
#define XF_TEX_PROJECTION_SHIFT	1
#define XF_TEX_PROJECTION_MASK	0x00000002
#define XF_TEX_GET_PROJECTION(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_PROJECTION_MASK) >> XF_TEX_PROJECTION_SHIFT)
#define XF_TEX_SET_PROJECTION(xf_tex, projection) { \
	FDL_ASSERT(!((projection) & ~((1 << XF_TEX_PROJECTION_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_PROJECTION_MASK) | (((unsigned long)(projection)) << XF_TEX_PROJECTION_SHIFT);\
}
#define XF_TEX_INPUT_FORM_SIZE	1
#define XF_TEX_INPUT_FORM_SHIFT	2
#define XF_TEX_INPUT_FORM_MASK	0x00000004
#define XF_TEX_GET_INPUT_FORM(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_INPUT_FORM_MASK) >> XF_TEX_INPUT_FORM_SHIFT)
#define XF_TEX_SET_INPUT_FORM(xf_tex, input_form) { \
	FDL_ASSERT(!((input_form) & ~((1 << XF_TEX_INPUT_FORM_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_INPUT_FORM_MASK) | (((unsigned long)(input_form)) << XF_TEX_INPUT_FORM_SHIFT);\
}
#define XF_TEX_RESERVED1_SIZE	1
#define XF_TEX_RESERVED1_SHIFT	3
#define XF_TEX_RESERVED1_MASK	0x00000008
#define XF_TEX_GET_RESERVED1(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_RESERVED1_MASK) >> XF_TEX_RESERVED1_SHIFT)
#define XF_TEX_SET_RESERVED1(xf_tex, reserved1) { \
	FDL_ASSERT(!((reserved1) & ~((1 << XF_TEX_RESERVED1_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_RESERVED1_MASK) | (((unsigned long)(reserved1)) << XF_TEX_RESERVED1_SHIFT);\
}
#define XF_TEX_TEXGEN_TYPE_SIZE	3
#define XF_TEX_TEXGEN_TYPE_SHIFT	4
#define XF_TEX_TEXGEN_TYPE_MASK	0x00000070
#define XF_TEX_GET_TEXGEN_TYPE(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_TEXGEN_TYPE_MASK) >> XF_TEX_TEXGEN_TYPE_SHIFT)
#define XF_TEX_SET_TEXGEN_TYPE(xf_tex, texgen_type) { \
	FDL_ASSERT(!((texgen_type) & ~((1 << XF_TEX_TEXGEN_TYPE_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_TEXGEN_TYPE_MASK) | (((unsigned long)(texgen_type)) << XF_TEX_TEXGEN_TYPE_SHIFT);\
}
#define XF_TEX_SOURCE_ROW_SIZE	5
#define XF_TEX_SOURCE_ROW_SHIFT	7
#define XF_TEX_SOURCE_ROW_MASK	0x00000f80
#define XF_TEX_GET_SOURCE_ROW(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_SOURCE_ROW_MASK) >> XF_TEX_SOURCE_ROW_SHIFT)
#define XF_TEX_SET_SOURCE_ROW(xf_tex, source_row) { \
	FDL_ASSERT(!((source_row) & ~((1 << XF_TEX_SOURCE_ROW_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_SOURCE_ROW_MASK) | (((unsigned long)(source_row)) << XF_TEX_SOURCE_ROW_SHIFT);\
}
#define XF_TEX_BUMP_MAP_SOURCE_SIZE	3
#define XF_TEX_BUMP_MAP_SOURCE_SHIFT	12
#define XF_TEX_BUMP_MAP_SOURCE_MASK	0x00007000
#define XF_TEX_GET_BUMP_MAP_SOURCE(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_BUMP_MAP_SOURCE_MASK) >> XF_TEX_BUMP_MAP_SOURCE_SHIFT)
#define XF_TEX_SET_BUMP_MAP_SOURCE(xf_tex, bump_map_source) { \
	FDL_ASSERT(!((bump_map_source) & ~((1 << XF_TEX_BUMP_MAP_SOURCE_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_BUMP_MAP_SOURCE_MASK) | (((unsigned long)(bump_map_source)) << XF_TEX_BUMP_MAP_SOURCE_SHIFT);\
}
#define XF_TEX_BUMP_MAP_LIGHT_SIZE	3
#define XF_TEX_BUMP_MAP_LIGHT_SHIFT	15
#define XF_TEX_BUMP_MAP_LIGHT_MASK	0x00038000
#define XF_TEX_GET_BUMP_MAP_LIGHT(xf_tex) \
	((((unsigned long)(xf_tex)) & XF_TEX_BUMP_MAP_LIGHT_MASK) >> XF_TEX_BUMP_MAP_LIGHT_SHIFT)
#define XF_TEX_SET_BUMP_MAP_LIGHT(xf_tex, bump_map_light) { \
	FDL_ASSERT(!((bump_map_light) & ~((1 << XF_TEX_BUMP_MAP_LIGHT_SIZE)-1))); \
	xf_tex = (((unsigned long)(xf_tex)) & ~XF_TEX_BUMP_MAP_LIGHT_MASK) | (((unsigned long)(bump_map_light)) << XF_TEX_BUMP_MAP_LIGHT_SHIFT);\
}
#define XF_TEX_TOTAL_SIZE	18
#define XF_TEX_UNUSED_SIZE	14

#define XF_TEX(reserved0, projection, input_form, reserved1, texgen_type, source_row, bump_map_source, bump_map_light) \
	((((unsigned long)(reserved0)) << XF_TEX_RESERVED0_SHIFT) | \
	 (((unsigned long)(projection)) << XF_TEX_PROJECTION_SHIFT) | \
	 (((unsigned long)(input_form)) << XF_TEX_INPUT_FORM_SHIFT) | \
	 (((unsigned long)(reserved1)) << XF_TEX_RESERVED1_SHIFT) | \
	 (((unsigned long)(texgen_type)) << XF_TEX_TEXGEN_TYPE_SHIFT) | \
	 (((unsigned long)(source_row)) << XF_TEX_SOURCE_ROW_SHIFT) | \
	 (((unsigned long)(bump_map_source)) << XF_TEX_BUMP_MAP_SOURCE_SHIFT) | \
	 (((unsigned long)(bump_map_light)) << XF_TEX_BUMP_MAP_LIGHT_SHIFT))

typedef struct {
    unsigned long unused:XF_TEX_UNUSED_SIZE;
    unsigned long bump_map_light:XF_TEX_BUMP_MAP_LIGHT_SIZE;
    unsigned long bump_map_source:XF_TEX_BUMP_MAP_SOURCE_SIZE;
    unsigned long source_row:XF_TEX_SOURCE_ROW_SIZE;
    unsigned long texgen_type:XF_TEX_TEXGEN_TYPE_SIZE;
    unsigned long reserved1:XF_TEX_RESERVED1_SIZE;
    unsigned long input_form:XF_TEX_INPUT_FORM_SIZE;
    unsigned long projection:XF_TEX_PROJECTION_SIZE;
    unsigned long reserved0:XF_TEX_RESERVED0_SIZE;
} xf_tex_t;

typedef union {
    unsigned long val;
    xf_tex_t f;
} xf_tex_u;

/*
 *  xf_tex_projection_f enum
 */
#define XF_TEX_ST	0x00000000
#define XF_TEX_STQ	0x00000001

/*
 *  xf_tex_input_form_f enum
 */
#define XF_TEX_AB01	0x00000000
#define XF_TEX_ABC1	0x00000001

/*
 *  xf_tex_texgen_type_f enum
 */
#define XF_TEXGEN_REGULAR	0x00000000
#define XF_TEXGEN_BUMP_MAP	0x00000001
#define XF_TEXGEN_COLOR_STRGBC0	0x00000002
#define XF_TEXGEN_COLOR_STRGBC1	0x00000003
#define XF_TEX_TEXGEN_TYPE_F_UNUSED_4	0x00000004
#define XF_TEX_TEXGEN_TYPE_F_UNUSED_5	0x00000005
#define XF_TEX_TEXGEN_TYPE_F_UNUSED_6	0x00000006
#define XF_TEX_TEXGEN_TYPE_F_UNUSED_7	0x00000007

/*
 *  xf_vbg_offset enum
 */
#define XF_VB_W_OFF	0x00000000
#define XF_VB_X_OFF	0x00000001
#define XF_VB_Y_OFF	0x00000002
#define XF_VB_Z_OFF	0x00000003
#define XF_VB_Q0_OFF	0x00000004
#define XF_VB_S0_OFF	0x00000005
#define XF_VB_T0_OFF	0x00000006
#define XF_VB_Q1_OFF	0x00000007
#define XF_VB_S1_OFF	0x00000008
#define XF_VB_T1_OFF	0x00000009
#define XF_VB_Q2_OFF	0x0000000a
#define XF_VB_S2_OFF	0x0000000b
#define XF_VB_T2_OFF	0x0000000c
#define XF_VB_Q3_OFF	0x0000000d
#define XF_VB_S3_OFF	0x0000000e
#define XF_VB_T3_OFF	0x0000000f
#define XF_VB_Q4_OFF	0x00000010
#define XF_VB_S4_OFF	0x00000011
#define XF_VB_T4_OFF	0x00000012
#define XF_VB_Q5_OFF	0x00000013
#define XF_VB_S5_OFF	0x00000014
#define XF_VB_T5_OFF	0x00000015
#define XF_VB_Q6_OFF	0x00000016
#define XF_VB_S6_OFF	0x00000017
#define XF_VB_T6_OFF	0x00000018
#define XF_VB_Q7_OFF	0x00000019
#define XF_VB_S7_OFF	0x0000001a
#define XF_VB_T7_OFF	0x0000001b
#define XF_VBG_OFFSET_UNUSED_28	0x0000001c
#define XF_VBG_OFFSET_UNUSED_29	0x0000001d
#define XF_VBG_OFFSET_UNUSED_30	0x0000001e
#define XF_VBG_OFFSET_UNUSED_31	0x0000001f

/*
 *  xf_vbg_fast_offset enum
 */
#define XF_VB_FAST_W_OFF	0x00000000
#define XF_VB_FAST_X_OFF	0x00000001
#define XF_VB_FAST_Y_OFF	0x00000002
#define XF_VB_FAST_Z_OFF	0x00000003
#define XF_VB_FAST_S0_OFF	0x00000004
#define XF_VB_FAST_T0_OFF	0x00000005
#define XF_VBG_FAST_OFFSET_UNUSED_6	0x00000006
#define XF_VBG_FAST_OFFSET_UNUSED_7	0x00000007

/*
 *  xf_vbc_offset enum
 */
#define XF_VB_CD_OFF	0x00000000
#define XF_VB_CS_OFF	0x00000001
#define XF_VB_SC0_OFF	0x00000002
#define XF_VB_TC0_OFF	0x00000003
#define XF_VB_SC1_OFF	0x00000004
#define XF_VB_TC1_OFF	0x00000005
#define XF_VBC_OFFSET_UNUSED_6	0x00000006
#define XF_VBC_OFFSET_UNUSED_7	0x00000007

/*
 *  xf_vbb_offset enum
 */
#define XF_VB_SBM0_OFF	0x00000000
#define XF_VB_TBM0_OFF	0x00000001
#define XF_VB_SBM1_OFF	0x00000002
#define XF_VB_TBM1_OFF	0x00000003
#define XF_VB_SBM2_OFF	0x00000004
#define XF_VB_TBM2_OFF	0x00000005
#define XF_VBB_OFFSET_UNUSED_6	0x00000006
#define XF_VBB_OFFSET_UNUSED_7	0x00000007

/*
 *  xf_perf0_f struct
 */
#define XF_PERF0_F_PERF_A_SIZE	5
#define XF_PERF0_F_PERF_A_SHIFT	0
#define XF_PERF0_F_PERF_A_MASK	0x0000001f
#define XF_PERF0_F_GET_PERF_A(xf_perf0_f) \
	((((unsigned long)(xf_perf0_f)) & XF_PERF0_F_PERF_A_MASK) >> XF_PERF0_F_PERF_A_SHIFT)
#define XF_PERF0_F_SET_PERF_A(xf_perf0_f, perf_a) { \
	FDL_ASSERT(!((perf_a) & ~((1 << XF_PERF0_F_PERF_A_SIZE)-1))); \
	xf_perf0_f = (((unsigned long)(xf_perf0_f)) & ~XF_PERF0_F_PERF_A_MASK) | (((unsigned long)(perf_a)) << XF_PERF0_F_PERF_A_SHIFT);\
}
#define XF_PERF0_F_PERF_B_SIZE	5
#define XF_PERF0_F_PERF_B_SHIFT	5
#define XF_PERF0_F_PERF_B_MASK	0x000003e0
#define XF_PERF0_F_GET_PERF_B(xf_perf0_f) \
	((((unsigned long)(xf_perf0_f)) & XF_PERF0_F_PERF_B_MASK) >> XF_PERF0_F_PERF_B_SHIFT)
#define XF_PERF0_F_SET_PERF_B(xf_perf0_f, perf_b) { \
	FDL_ASSERT(!((perf_b) & ~((1 << XF_PERF0_F_PERF_B_SIZE)-1))); \
	xf_perf0_f = (((unsigned long)(xf_perf0_f)) & ~XF_PERF0_F_PERF_B_MASK) | (((unsigned long)(perf_b)) << XF_PERF0_F_PERF_B_SHIFT);\
}
#define XF_PERF0_F_PERF_C_SIZE	5
#define XF_PERF0_F_PERF_C_SHIFT	10
#define XF_PERF0_F_PERF_C_MASK	0x00007c00
#define XF_PERF0_F_GET_PERF_C(xf_perf0_f) \
	((((unsigned long)(xf_perf0_f)) & XF_PERF0_F_PERF_C_MASK) >> XF_PERF0_F_PERF_C_SHIFT)
#define XF_PERF0_F_SET_PERF_C(xf_perf0_f, perf_c) { \
	FDL_ASSERT(!((perf_c) & ~((1 << XF_PERF0_F_PERF_C_SIZE)-1))); \
	xf_perf0_f = (((unsigned long)(xf_perf0_f)) & ~XF_PERF0_F_PERF_C_MASK) | (((unsigned long)(perf_c)) << XF_PERF0_F_PERF_C_SHIFT);\
}
#define XF_PERF0_F_PERF_D_SIZE	5
#define XF_PERF0_F_PERF_D_SHIFT	15
#define XF_PERF0_F_PERF_D_MASK	0x000f8000
#define XF_PERF0_F_GET_PERF_D(xf_perf0_f) \
	((((unsigned long)(xf_perf0_f)) & XF_PERF0_F_PERF_D_MASK) >> XF_PERF0_F_PERF_D_SHIFT)
#define XF_PERF0_F_SET_PERF_D(xf_perf0_f, perf_d) { \
	FDL_ASSERT(!((perf_d) & ~((1 << XF_PERF0_F_PERF_D_SIZE)-1))); \
	xf_perf0_f = (((unsigned long)(xf_perf0_f)) & ~XF_PERF0_F_PERF_D_MASK) | (((unsigned long)(perf_d)) << XF_PERF0_F_PERF_D_SHIFT);\
}
#define XF_PERF0_F_TOTAL_SIZE	20
#define XF_PERF0_F_UNUSED_SIZE	12

#define XF_PERF0_F(perf_a, perf_b, perf_c, perf_d) \
	((((unsigned long)(perf_a)) << XF_PERF0_F_PERF_A_SHIFT) | \
	 (((unsigned long)(perf_b)) << XF_PERF0_F_PERF_B_SHIFT) | \
	 (((unsigned long)(perf_c)) << XF_PERF0_F_PERF_C_SHIFT) | \
	 (((unsigned long)(perf_d)) << XF_PERF0_F_PERF_D_SHIFT))

typedef struct {
    unsigned long unused:XF_PERF0_F_UNUSED_SIZE;
    unsigned long perf_d:XF_PERF0_F_PERF_D_SIZE;
    unsigned long perf_c:XF_PERF0_F_PERF_C_SIZE;
    unsigned long perf_b:XF_PERF0_F_PERF_B_SIZE;
    unsigned long perf_a:XF_PERF0_F_PERF_A_SIZE;
} xf_perf0_f_t;

typedef union {
    unsigned long val;
    xf_perf0_f_t f;
} xf_perf0_f_u;

/*
 *  xf_perf_f enum
 */
#define PERF_NEVER	0x00000000
#define PERF_ALWAYS	0x00000001
#define PERF_FROZEN	0x00000002
#define PERF_INPUT_FULL	0x00000003
#define PERF_INPUT_EMPTY	0x00000004
#define PERF_CP_VALID	0x00000005
#define PERF_OUTPUT_FULL	0x00000006
#define PERF_OUTPUT_EMPTY	0x00000007
#define PERF_SU_READY	0x00000008
#define PERF_VERTEX_CNT	0x00000009
#define PERF_CLIP_VERTEX_CNT	0x0000000a
#define PERF_CLIP_FREEZE	0x0000000b
#define PERF_LIT_VERTEX_CNT	0x0000000c
#define PERF_REG_LOAD_CNT	0x0000000d
#define PERF_REG_READ_CNT	0x0000000e
#define PERF_BYPASS_CNT	0x0000000f
#define PERF_TOP_BUSY	0x00000010
#define PERF_BOP_BUSY	0x00000011
#define PERF_LIGHT_BUSY	0x00000012
#define PERF_VERTEX_GEOM_CNT	0x00000013
#define PERF_BYPASS_FIFO_STALL	0x00000014
#define XF_PERF_F_UNUSED_21	0x00000015
#define XF_PERF_F_UNUSED_22	0x00000016
#define XF_PERF_F_UNUSED_23	0x00000017
#define XF_PERF_F_UNUSED_24	0x00000018
#define XF_PERF_F_UNUSED_25	0x00000019
#define XF_PERF_F_UNUSED_26	0x0000001a
#define XF_PERF_F_UNUSED_27	0x0000001b
#define XF_PERF_F_UNUSED_28	0x0000001c
#define XF_PERF_F_UNUSED_29	0x0000001d
#define XF_PERF_F_UNUSED_30	0x0000001e
#define XF_PERF_F_UNUSED_31	0x0000001f

/*
 *  xf_perf1_f struct
 */
#define XF_PERF1_F_PERF_TARGET_SIZE	7
#define XF_PERF1_F_PERF_TARGET_SHIFT	0
#define XF_PERF1_F_PERF_TARGET_MASK	0x0000007f
#define XF_PERF1_F_GET_PERF_TARGET(xf_perf1_f) \
	((((unsigned long)(xf_perf1_f)) & XF_PERF1_F_PERF_TARGET_MASK) >> XF_PERF1_F_PERF_TARGET_SHIFT)
#define XF_PERF1_F_SET_PERF_TARGET(xf_perf1_f, perf_target) { \
	FDL_ASSERT(!((perf_target) & ~((1 << XF_PERF1_F_PERF_TARGET_SIZE)-1))); \
	xf_perf1_f = (((unsigned long)(xf_perf1_f)) & ~XF_PERF1_F_PERF_TARGET_MASK) | (((unsigned long)(perf_target)) << XF_PERF1_F_PERF_TARGET_SHIFT);\
}
#define XF_PERF1_F_TOTAL_SIZE	7
#define XF_PERF1_F_UNUSED_SIZE	25

#define XF_PERF1_F(perf_target) \
	((((unsigned long)(perf_target)) << XF_PERF1_F_PERF_TARGET_SHIFT))

typedef struct {
    unsigned long unused:XF_PERF1_F_UNUSED_SIZE;
    unsigned long perf_target:XF_PERF1_F_PERF_TARGET_SIZE;
} xf_perf1_f_t;

typedef union {
    unsigned long val;
    xf_perf1_f_t f;
} xf_perf1_f_u;

/*
 *  xf_error_f struct
 */
#define XF_ERROR_F_CTEX_BUG_ENABLE_SIZE	1
#define XF_ERROR_F_CTEX_BUG_ENABLE_SHIFT	0
#define XF_ERROR_F_CTEX_BUG_ENABLE_MASK	0x00000001
#define XF_ERROR_F_GET_CTEX_BUG_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_CTEX_BUG_ENABLE_MASK) >> XF_ERROR_F_CTEX_BUG_ENABLE_SHIFT)
#define XF_ERROR_F_SET_CTEX_BUG_ENABLE(xf_error_f, ctex_bug_enable) { \
	FDL_ASSERT(!((ctex_bug_enable) & ~((1 << XF_ERROR_F_CTEX_BUG_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_CTEX_BUG_ENABLE_MASK) | (((unsigned long)(ctex_bug_enable)) << XF_ERROR_F_CTEX_BUG_ENABLE_SHIFT);\
}
#define XF_ERROR_F_TFAN4_BUG_ENABLE_SIZE	1
#define XF_ERROR_F_TFAN4_BUG_ENABLE_SHIFT	1
#define XF_ERROR_F_TFAN4_BUG_ENABLE_MASK	0x00000002
#define XF_ERROR_F_GET_TFAN4_BUG_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_TFAN4_BUG_ENABLE_MASK) >> XF_ERROR_F_TFAN4_BUG_ENABLE_SHIFT)
#define XF_ERROR_F_SET_TFAN4_BUG_ENABLE(xf_error_f, tfan4_bug_enable) { \
	FDL_ASSERT(!((tfan4_bug_enable) & ~((1 << XF_ERROR_F_TFAN4_BUG_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_TFAN4_BUG_ENABLE_MASK) | (((unsigned long)(tfan4_bug_enable)) << XF_ERROR_F_TFAN4_BUG_ENABLE_SHIFT);\
}
#define XF_ERROR_F_TFAN16_BUG_ENABLE_SIZE	1
#define XF_ERROR_F_TFAN16_BUG_ENABLE_SHIFT	2
#define XF_ERROR_F_TFAN16_BUG_ENABLE_MASK	0x00000004
#define XF_ERROR_F_GET_TFAN16_BUG_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_TFAN16_BUG_ENABLE_MASK) >> XF_ERROR_F_TFAN16_BUG_ENABLE_SHIFT)
#define XF_ERROR_F_SET_TFAN16_BUG_ENABLE(xf_error_f, tfan16_bug_enable) { \
	FDL_ASSERT(!((tfan16_bug_enable) & ~((1 << XF_ERROR_F_TFAN16_BUG_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_TFAN16_BUG_ENABLE_MASK) | (((unsigned long)(tfan16_bug_enable)) << XF_ERROR_F_TFAN16_BUG_ENABLE_SHIFT);\
}
#define XF_ERROR_F_DUALTRAN_REG_ENABLE_SIZE	1
#define XF_ERROR_F_DUALTRAN_REG_ENABLE_SHIFT	3
#define XF_ERROR_F_DUALTRAN_REG_ENABLE_MASK	0x00000008
#define XF_ERROR_F_GET_DUALTRAN_REG_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_DUALTRAN_REG_ENABLE_MASK) >> XF_ERROR_F_DUALTRAN_REG_ENABLE_SHIFT)
#define XF_ERROR_F_SET_DUALTRAN_REG_ENABLE(xf_error_f, dualtran_reg_enable) { \
	FDL_ASSERT(!((dualtran_reg_enable) & ~((1 << XF_ERROR_F_DUALTRAN_REG_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_DUALTRAN_REG_ENABLE_MASK) | (((unsigned long)(dualtran_reg_enable)) << XF_ERROR_F_DUALTRAN_REG_ENABLE_SHIFT);\
}
#define XF_ERROR_F_BYPASS_BUG_ENABLE_SIZE	1
#define XF_ERROR_F_BYPASS_BUG_ENABLE_SHIFT	4
#define XF_ERROR_F_BYPASS_BUG_ENABLE_MASK	0x00000010
#define XF_ERROR_F_GET_BYPASS_BUG_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_BYPASS_BUG_ENABLE_MASK) >> XF_ERROR_F_BYPASS_BUG_ENABLE_SHIFT)
#define XF_ERROR_F_SET_BYPASS_BUG_ENABLE(xf_error_f, bypass_bug_enable) { \
	FDL_ASSERT(!((bypass_bug_enable) & ~((1 << XF_ERROR_F_BYPASS_BUG_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_BYPASS_BUG_ENABLE_MASK) | (((unsigned long)(bypass_bug_enable)) << XF_ERROR_F_BYPASS_BUG_ENABLE_SHIFT);\
}
#define XF_ERROR_F_FAST_MATRIX_ENABLE_SIZE	1
#define XF_ERROR_F_FAST_MATRIX_ENABLE_SHIFT	5
#define XF_ERROR_F_FAST_MATRIX_ENABLE_MASK	0x00000020
#define XF_ERROR_F_GET_FAST_MATRIX_ENABLE(xf_error_f) \
	((((unsigned long)(xf_error_f)) & XF_ERROR_F_FAST_MATRIX_ENABLE_MASK) >> XF_ERROR_F_FAST_MATRIX_ENABLE_SHIFT)
#define XF_ERROR_F_SET_FAST_MATRIX_ENABLE(xf_error_f, fast_matrix_enable) { \
	FDL_ASSERT(!((fast_matrix_enable) & ~((1 << XF_ERROR_F_FAST_MATRIX_ENABLE_SIZE)-1))); \
	xf_error_f = (((unsigned long)(xf_error_f)) & ~XF_ERROR_F_FAST_MATRIX_ENABLE_MASK) | (((unsigned long)(fast_matrix_enable)) << XF_ERROR_F_FAST_MATRIX_ENABLE_SHIFT);\
}
#define XF_ERROR_F_TOTAL_SIZE	6
#define XF_ERROR_F_UNUSED_SIZE	26

#define XF_ERROR_F(ctex_bug_enable, tfan4_bug_enable, tfan16_bug_enable, dualtran_reg_enable, bypass_bug_enable, fast_matrix_enable) \
	((((unsigned long)(ctex_bug_enable)) << XF_ERROR_F_CTEX_BUG_ENABLE_SHIFT) | \
	 (((unsigned long)(tfan4_bug_enable)) << XF_ERROR_F_TFAN4_BUG_ENABLE_SHIFT) | \
	 (((unsigned long)(tfan16_bug_enable)) << XF_ERROR_F_TFAN16_BUG_ENABLE_SHIFT) | \
	 (((unsigned long)(dualtran_reg_enable)) << XF_ERROR_F_DUALTRAN_REG_ENABLE_SHIFT) | \
	 (((unsigned long)(bypass_bug_enable)) << XF_ERROR_F_BYPASS_BUG_ENABLE_SHIFT) | \
	 (((unsigned long)(fast_matrix_enable)) << XF_ERROR_F_FAST_MATRIX_ENABLE_SHIFT))

typedef struct {
    unsigned long unused:XF_ERROR_F_UNUSED_SIZE;
    unsigned long fast_matrix_enable:XF_ERROR_F_FAST_MATRIX_ENABLE_SIZE;
    unsigned long bypass_bug_enable:XF_ERROR_F_BYPASS_BUG_ENABLE_SIZE;
    unsigned long dualtran_reg_enable:XF_ERROR_F_DUALTRAN_REG_ENABLE_SIZE;
    unsigned long tfan16_bug_enable:XF_ERROR_F_TFAN16_BUG_ENABLE_SIZE;
    unsigned long tfan4_bug_enable:XF_ERROR_F_TFAN4_BUG_ENABLE_SIZE;
    unsigned long ctex_bug_enable:XF_ERROR_F_CTEX_BUG_ENABLE_SIZE;
} xf_error_f_t;

typedef union {
    unsigned long val;
    xf_error_f_t f;
} xf_error_f_u;

/*
 *  xf_dualtextran_f struct
 */
#define XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SIZE	1
#define XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SHIFT	0
#define XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_MASK	0x00000001
#define XF_DUALTEXTRAN_F_GET_DUALTEXTRAN_ENABLE(xf_dualtextran_f) \
	((((unsigned long)(xf_dualtextran_f)) & XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_MASK) >> XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SHIFT)
#define XF_DUALTEXTRAN_F_SET_DUALTEXTRAN_ENABLE(xf_dualtextran_f, dualtextran_enable) { \
	FDL_ASSERT(!((dualtextran_enable) & ~((1 << XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SIZE)-1))); \
	xf_dualtextran_f = (((unsigned long)(xf_dualtextran_f)) & ~XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_MASK) | (((unsigned long)(dualtextran_enable)) << XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SHIFT);\
}
#define XF_DUALTEXTRAN_F_TOTAL_SIZE	1
#define XF_DUALTEXTRAN_F_UNUSED_SIZE	31

#define XF_DUALTEXTRAN_F(dualtextran_enable) \
	((((unsigned long)(dualtextran_enable)) << XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SHIFT))

typedef struct {
    unsigned long unused:XF_DUALTEXTRAN_F_UNUSED_SIZE;
    unsigned long dualtextran_enable:XF_DUALTEXTRAN_F_DUALTEXTRAN_ENABLE_SIZE;
} xf_dualtextran_f_t;

typedef union {
    unsigned long val;
    xf_dualtextran_f_t f;
} xf_dualtextran_f_u;

/*
 *  xf_dualtex_f struct
 */
#define XF_DUALTEX_F_DUALMATRIX_ADRS_SIZE	6
#define XF_DUALTEX_F_DUALMATRIX_ADRS_SHIFT	0
#define XF_DUALTEX_F_DUALMATRIX_ADRS_MASK	0x0000003f
#define XF_DUALTEX_F_GET_DUALMATRIX_ADRS(xf_dualtex_f) \
	((((unsigned long)(xf_dualtex_f)) & XF_DUALTEX_F_DUALMATRIX_ADRS_MASK) >> XF_DUALTEX_F_DUALMATRIX_ADRS_SHIFT)
#define XF_DUALTEX_F_SET_DUALMATRIX_ADRS(xf_dualtex_f, dualmatrix_adrs) { \
	FDL_ASSERT(!((dualmatrix_adrs) & ~((1 << XF_DUALTEX_F_DUALMATRIX_ADRS_SIZE)-1))); \
	xf_dualtex_f = (((unsigned long)(xf_dualtex_f)) & ~XF_DUALTEX_F_DUALMATRIX_ADRS_MASK) | (((unsigned long)(dualmatrix_adrs)) << XF_DUALTEX_F_DUALMATRIX_ADRS_SHIFT);\
}
#define XF_DUALTEX_F_RESERVED0_SIZE	2
#define XF_DUALTEX_F_RESERVED0_SHIFT	6
#define XF_DUALTEX_F_RESERVED0_MASK	0x000000c0
#define XF_DUALTEX_F_GET_RESERVED0(xf_dualtex_f) \
	((((unsigned long)(xf_dualtex_f)) & XF_DUALTEX_F_RESERVED0_MASK) >> XF_DUALTEX_F_RESERVED0_SHIFT)
#define XF_DUALTEX_F_SET_RESERVED0(xf_dualtex_f, reserved0) { \
	FDL_ASSERT(!((reserved0) & ~((1 << XF_DUALTEX_F_RESERVED0_SIZE)-1))); \
	xf_dualtex_f = (((unsigned long)(xf_dualtex_f)) & ~XF_DUALTEX_F_RESERVED0_MASK) | (((unsigned long)(reserved0)) << XF_DUALTEX_F_RESERVED0_SHIFT);\
}
#define XF_DUALTEX_F_NORMAL_ENABLE_SIZE	1
#define XF_DUALTEX_F_NORMAL_ENABLE_SHIFT	8
#define XF_DUALTEX_F_NORMAL_ENABLE_MASK	0x00000100
#define XF_DUALTEX_F_GET_NORMAL_ENABLE(xf_dualtex_f) \
	((((unsigned long)(xf_dualtex_f)) & XF_DUALTEX_F_NORMAL_ENABLE_MASK) >> XF_DUALTEX_F_NORMAL_ENABLE_SHIFT)
#define XF_DUALTEX_F_SET_NORMAL_ENABLE(xf_dualtex_f, normal_enable) { \
	FDL_ASSERT(!((normal_enable) & ~((1 << XF_DUALTEX_F_NORMAL_ENABLE_SIZE)-1))); \
	xf_dualtex_f = (((unsigned long)(xf_dualtex_f)) & ~XF_DUALTEX_F_NORMAL_ENABLE_MASK) | (((unsigned long)(normal_enable)) << XF_DUALTEX_F_NORMAL_ENABLE_SHIFT);\
}
#define XF_DUALTEX_F_TOTAL_SIZE	9
#define XF_DUALTEX_F_UNUSED_SIZE	23

#define XF_DUALTEX_F(dualmatrix_adrs, reserved0, normal_enable) \
	((((unsigned long)(dualmatrix_adrs)) << XF_DUALTEX_F_DUALMATRIX_ADRS_SHIFT) | \
	 (((unsigned long)(reserved0)) << XF_DUALTEX_F_RESERVED0_SHIFT) | \
	 (((unsigned long)(normal_enable)) << XF_DUALTEX_F_NORMAL_ENABLE_SHIFT))

typedef struct {
    unsigned long unused:XF_DUALTEX_F_UNUSED_SIZE;
    unsigned long normal_enable:XF_DUALTEX_F_NORMAL_ENABLE_SIZE;
    unsigned long reserved0:XF_DUALTEX_F_RESERVED0_SIZE;
    unsigned long dualmatrix_adrs:XF_DUALTEX_F_DUALMATRIX_ADRS_SIZE;
} xf_dualtex_f_t;

typedef union {
    unsigned long val;
    xf_dualtex_f_t f;
} xf_dualtex_f_u;


#endif /* __XF_MEM_H__ */
