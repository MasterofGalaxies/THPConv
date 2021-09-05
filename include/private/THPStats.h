/*---------------------------------------------------------------------------*
  Project: Dolphin
  File:    THPStats.h

  Copyright 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    1     02/01/16 12:02p Akagi
    moved from tests. cleanup.
    
    3     7/06/01 3:04p Tian
    More statistics
    
    2     4/25/01 2:07p Tian
    IDCT optimizations.
    
    1     4/15/01 8:39p Tian
    Optimizations complete.  Currently hardcoded for 512x448 decoding, 60%
    of 60hz frame for 1bpp pictures.  Simple movie player added.  
    
    1     4/12/01 11:01p Tian
    Move to THP tree.  Massive optimizations : Hirose-san's new IDCT with
    swizzle, table-driven huffman decoding, speculative execution of common
    case code, etc.
    
    4     4/09/01 11:22a Tian
    Huffman optimizations.  Integrated Hirose-san's IDCT.
    
    3     3/30/01 2:21a Tian
    Major optimizations for TEV-based YUV conversion (code ported from hvqm
    tree), 640x480 decode in one pass for all render modes, TEV konstant
    calibration, zoom/pan controls tweaked.
    
    2     3/29/01 4:44p Tian
    Cleanup.  Optimizations.  More stats.
    
    1     3/28/01 10:03p Tian
    Initial checkin
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __THPSTATS_H__
#define __THPSTATS_H__
#ifdef __cplusplus
extern "C" {
#endif
  
/*---------------------------------------------------------------------------*
    Public Types...
 *---------------------------------------------------------------------------*/
  
typedef struct _THPStats
{
    // start/stop times
    u32 cycles[2];
    u32 loadStores[2];
    u32 missCycles[2];
    u32 instructions[2];

    // totals
    u32 cycleTotal;
    u32 loadStoreTotal;
    u32 missCycleTotal;
    u32 instructionTotal;

    // maxes
    u32 cycleMax;

    u32 hits;
    
} THPStats;

/*---------------------------------------------------------------------------*
  Performance monitor macros
 *---------------------------------------------------------------------------*/

// STARTPMC sets both MMCRs (monitor control registers) going.
// PMC1 measures instruction count
// PMC2 measures # of loads and stores
// PMC3 measures # of cycles lost to L1 misses
// PMC4 measures cycle count
// Note : cycle counter is turned on last
#define THPStartPmc              PPCMtmmcr0(MMCR0_PMC1_INSTRUCTION |   \
                                            MMCR0_PMC2_LOAD_STORE);    \
                                 PPCMtmmcr1(MMCR1_PMC3_L1_MISS_CYCLE | \
                                            MMCR1_PMC4_CYCLE);
                            
// STOPPMC pauses all performance counters by writing 0 to the MMCRs.  
// Note that cycle counter is turned off first.
#define THPStopPmc               PPCMtmmcr1(0); \
                                 PPCMtmmcr0(0);

#ifdef _DEBUG
#define THPPrintPmc              OSReport("<%d loadstores / %d miss cycles / %d cycles / %d Instructions>\n", \
                                 PPCMfpmc2(), PPCMfpmc3(), PPCMfpmc4(), PPCMfpmc1());
#else
#define THPPrintPmc
#endif
  
#define THPResetPmc              PPCMtpmc1(0); \
                                 PPCMtpmc2(0); \
                                 PPCMtpmc3(0); \
                                 PPCMtpmc4(0);

#define THP_STATS_EFB_CONVERT 0
#define THP_STATS_EFB_THP     1
#define THP_STATS_EFB_FLUSH   2
#define THP_STATS_EFB_TILE    3
#define THP_STATS_EFB_SWIZ    4
#define THP_STATS_EFB_TILE_DE 5
#define THP_STATS_EFB_TILE_DC 6
#define THP_STATS_EFB_TILE_PP 7
#define THP_STATS_XFB_CONVERT 8
#define THP_STATS_XFB_FLUSH   9
#define THP_STATS_IDCT        10
#define THP_STATS_Z_INV       11
#define THP_STATS_Z_DEC       12
#define THP_STATS_Z_SWIZ      13
#define THP_STATS_Z_FLUSH     14
#define THP_STATS_Z_MEMSET    15
#define THP_STATS_Z_READ      16
#define THP_STATS_Z_RECONL    17
#define THP_STATS_Z_DECEDGE   18
#define THP_STATS_Z_RECONZ    19

#define THP_STATS_MAX         20

extern THPStats THPStatistics[THP_STATS_MAX];

#ifndef THP_NOSTATS

#define THPStartStats(s) \
  THPStopPmc\
  THPStatistics[s].cycles[0]       = PPCMfpmc4();\
  THPStatistics[s].missCycles[0]   = PPCMfpmc3();\
  THPStatistics[s].loadStores[0]   = PPCMfpmc2();\
  THPStatistics[s].instructions[0] = PPCMfpmc1();\
  THPStartPmc
    
#define THPDiffStats(s,f) (THPStatistics[s].##f[1] - THPStatistics[s].##f[0])

#define THPStopStats(s)\
  THPStopPmc\
  THPStatistics[s].hits++;\
  THPStatistics[s].cycles[1]         = PPCMfpmc4();\
  THPStatistics[s].missCycles[1]     = PPCMfpmc3();\
  THPStatistics[s].loadStores[1]     = PPCMfpmc2();\
  THPStatistics[s].instructions[1]   = PPCMfpmc1();\
  { u32 temp = THPDiffStats(s,cycles); THPStatistics[s].cycleMax = (temp>THPStatistics[s].cycleMax)?temp:THPStatistics[s].cycleMax;};\
  THPStatistics[s].cycleTotal       += THPDiffStats(s,cycles);\
  THPStatistics[s].missCycleTotal   += THPDiffStats(s,missCycles);\
  THPStatistics[s].loadStoreTotal   += THPDiffStats(s,loadStores);\
  THPStatistics[s].instructionTotal += THPDiffStats(s,instructions);\
  THPStartPmc
  
#else   // THP_NOSTATS
  
#define THPStartStats(s)
#define THPDiffStats(s, f)
#define THPStopStats(s)
  
#endif  // THP_NOSTATS

/*---------------------------------------------------------------------------*
    Prototypes...
 *---------------------------------------------------------------------------*/

void  THPPrintStats  ( void );
void  THPResetStats  ( void );
f32   THPGetFrameMax ( u32 s );
    
#ifdef __cplusplus
}
#endif

#endif 
