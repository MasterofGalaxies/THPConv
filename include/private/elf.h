/*---------------------------------------------------------------------------*
  Project: ELF: Executable and Linkable Format
  File:    elf.h

  Copyright 2000 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  References:
  [1] System V Application Binary Interface, Third Edition, UNIX System
      Laboratories, 1994 (ISBN 0-13-100439-5).
  [2] System V Application Binary Interface, PowerPC Processor Supplement,
      Sun Microsystems and IBM, 1995.
  [3] PowerPC Embedded Application Binary Interface, 32-Bit Implementation,
      Motorola, 1995.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    1     4/13/00 10:39p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __ELF_H__
#define __ELF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>

/*---------------------------------------------------------------------------*
    32-Bit Data Types
 *---------------------------------------------------------------------------*/
                            // Purpose
typedef u32 Elf32_Addr;     // Unsigned program address
typedef u16 Elf32_Half;     // Unsigned medium integer
typedef u32 Elf32_Off;      // Unsigned file offset
typedef s32 Elf32_Sword;    // Signed large integer
typedef u32 Elf32_Word;     // Unsigned large integer

/*---------------------------------------------------------------------------*
    ELF Header
 *---------------------------------------------------------------------------*/

// e_ident[ ] Identification Indexes
#define EI_MAG0     0   // File identification
#define EI_MAG1     1   // File identification
#define EI_MAG2     2   // File identification
#define EI_MAG3     3   // File identification
#define EI_CLASS    4   // File class
#define EI_DATA     5   // Data encoding
#define EI_VERSION  6   // File version
#define EI_PAD      7   // Start of padding bytes
#define EI_NIDENT   16  // Size of e_ident[]

typedef struct Elf32_Ehdr
{
    unsigned char   e_ident[EI_NIDENT];
    Elf32_Half      e_type;
    Elf32_Half      e_machine;
    Elf32_Word      e_version;
    Elf32_Addr      e_entry;
    Elf32_Off       e_phoff;
    Elf32_Off       e_shoff;
    Elf32_Word      e_flags;
    Elf32_Half      e_ehsize;
    Elf32_Half      e_phentsize;
    Elf32_Half      e_phnum;
    Elf32_Half      e_shentsize;
    Elf32_Half      e_shnum;
    Elf32_Half      e_shstrndx;
} Elf32_Ehdr;

// Elf32_Ehdr.e_type
#define ET_NONE     0       // No file type
#define ET_REL      1       // Relocatable file
#define ET_EXEC     2       // Executable file
#define ET_DYN      3       // Shared object file
#define ET_CORE     4       // Core file
#define ET_LOPROC   0xff00  // Processor-specific
#define ET_HIPROC   0xffff  // Processor-specific

// Elf32_Ehdr.e_machine
#define EM_NONE     0       // No machine
#define EM_M32      1       // AT&T WE 32100
#define EM_SPARC    2       // SPARC
#define EM_386      3       // Intel 80386
#define EM_68K      4       // Motorola 68000
#define EM_88K      5       // Motorola 88000
#define EM_860      7       // Intel 80860
#define EM_MIPS     8       // MIPS RS3000
#define EM_PPC      20      // PowerPC              <<< EPPC EABI >>>

// Elf32_Ehdr.e_version
#define EV_NONE     0       // Invalid version
#define EV_CURRENT  1       // Current version

// e_flags
#define EF_PPC_EMB  0x80000000                  //  <<< EPPC EABI >>>

// e_ident[EI_MAGn]
#define ELFMAG0 0x7f        // e_ident[EI_MAG0]
#define ELFMAG1 'E'         // e_ident[EI_MAG1]
#define ELFMAG2 'L'         // e_ident[EI_MAG2]
#define ELFMAG3 'F'         // e_ident[EI_MAG3]

// e_ident[EI_CLASS]
#define ELFCLASSNONE    0   // Invalid class
#define ELFCLASS32      1   // 32-bit objects       <<< EPPC EABI >>>
#define ELFCLASS64      2   // 64-bit objects

// e_ident[EI_DATA]
#define ELFDATANONE     0   // Invalid data encoding
#define ELFDATA2LSB     1   // Little-Endian
#define ELFDATA2MSB     2   // Big-Endian           <<< EPPC EABI >>>

/*---------------------------------------------------------------------------*
    Sections
 *---------------------------------------------------------------------------*/

typedef struct Elf32_Shdr
{
    Elf32_Word  sh_name;
    Elf32_Word  sh_type;
    Elf32_Word  sh_flags;
    Elf32_Addr  sh_addr;
    Elf32_Off   sh_offset;
    Elf32_Word  sh_size;
    Elf32_Word  sh_link;
    Elf32_Word  sh_info;
    Elf32_Word  sh_addralign;
    Elf32_Word  sh_entsize;
} Elf32_Shdr;

#define SHN_UNDEF       0
#define SHN_LORESERVE   0xff00
#define SHN_LOPROC      0xff00
#define SHN_HIPROC      0xff1f
#define SHN_ABS         0xfff1
#define SHN_COMMON      0xfff2
#define SHN_HIRESERVE   0xffff

#define SHT_NULL        0
#define SHT_PROGBITS    1
#define SHT_SYMTAB      2
#define SHT_STRTAB      3
#define SHT_RELA        4
#define SHT_HASH        5
#define SHT_DYNAMIC     6
#define SHT_NOTE        7
#define SHT_NOBITS      8
#define SHT_REL         9
#define SHT_SHLIB       10
#define SHT_DYNSYM      11
#define SHT_LOPROC      0x70000000
#define SHT_HIPROC      0x7fffffff
#define SHT_LOUSER      0x80000000
#define SHT_HIUSER      0xffffffff

#define SHF_WRITE       0x1
#define SHF_ALLOC       0x2
#define SHF_EXECINSTR   0x4
#define SHF_MASKPROC    0xf0000000

/*---------------------------------------------------------------------------*
    Symbol Table
 *---------------------------------------------------------------------------*/

#define STN_UNDEF       0

typedef struct Elf32_Sym
{
    Elf32_Word      st_name;
    Elf32_Addr      st_value;
    Elf32_Word      st_size;
    unsigned char   st_info;
    unsigned char   st_other;
    Elf32_Half      st_shndx;
} Elf32_Sym;

#define ELF32_ST_BIND(i)    ((i)>>4)
#define ELF32_ST_TYPE(i)    ((i)&0xf)
#define ELF32_ST_INFO(b,t)  (((b)<<4)+((t)&0xf))

#define STB_LOCAL       0
#define STB_GLOBAL      1
#define STB_WEAK        2
#define STB_LOPROC      13
#define STB_HIPROC      15

#define STT_NOTYPE      0
#define STT_OBJECT      1
#define STT_FUNC        2
#define STT_SECTION     3
#define STT_FILE        4
#define STT_LOPROC      13
#define STT_HIPROC      15

/*---------------------------------------------------------------------------*
    Relocation
 *---------------------------------------------------------------------------*/

typedef struct Elf32_Rel
{
    Elf32_Addr      r_offset;
    Elf32_Word      r_info;
} Elf32_Rel;

// The PowerPC family uses only Elf32_Rela.         <<< EPPC EABI >>>
typedef struct Elf32_Rela
{
    Elf32_Addr      r_offset;
    Elf32_Word      r_info;
    Elf32_Sword     r_addend;
} Elf32_Rela;

#define ELF32_R_SYM(i)      ((i)>>8)
#define ELF32_R_TYPE(i)     ((unsigned char)(i))
#define ELF32_R_INFO(s,t)   (((s)<<8)+(unsigned char)(t))

//      Name                    Value       Field   Calculation
#define R_PPC_NONE              0       //  none    none
#define R_PPC_ADDR32            1       //  word32  S + A
#define R_PPC_ADDR24            2       //  low24*  (S + A) >> 2
#define R_PPC_ADDR16            3       //  half16* S + A
#define R_PPC_ADDR16_LO         4       //  half16  #lo(S + A)
#define R_PPC_ADDR16_HI         5       //  half16  #hi(S + A)
#define R_PPC_ADDR16_HA         6       //  half16  #ha(S + A)
#define R_PPC_ADDR14            7       //  low14*  (S + A) >> 2
#define R_PPC_ADDR14_BRTAKEN    8       //  low14*  (S + A) >> 2
#define R_PPC_ADDR14_BRNTAKEN   9       //  low14*  (S + A) >> 2
#define R_PPC_REL24             10      //  low24*  (S + A - P) >> 2
#define R_PPC_REL14             11      //  low14*  (S + A - P) >> 2
#define R_PPC_REL14_BRTAKEN     12      //  low14*  (S + A - P) >> 2
#define R_PPC_REL14_BRNTAKEN    13      //  low14*  (S + A - P) >> 2

#define R_PPC_GOT16             14      //  half16* G + A
#define R_PPC_GOT16_LO          15      //  half16  #lo(G + A)
#define R_PPC_GOT16_HI          16      //  half16  #hi(G + A)
#define R_PPC_GOT16_HA          17      //  half16  #ha(G + A)
#define R_PPC_PLTREL24          18      //  low24*  (L + A - P) >> 2
#define R_PPC_COPY              19      //  none    none
#define R_PPC_GLOB_DAT          20      //  word32  S + A
#define R_PPC_JMP_SLOT          21      //  none    see below
#define R_PPC_RELATIVE          22      //  word32  B + A

#define R_PPC_LOCAL24PC         23      //  low24*  see below

#define R_PPC_UADDR32           24      //  word32  S + A
#define R_PPC_UADDR16           25      //  half16* S + A
#define R_PPC_REL32             26      //  word32  S + A - P

#define R_PPC_PLT32             27      //  word32  L + A
#define R_PPC_PLTREL32          28      //  word32  L + A - P
#define R_PPC_PLT16_LO          29      //  half16  #lo(L + A)
#define R_PPL_PLT16_HI          30      //  half16  #hi(L + A)
#define R_PPC_PLT16_HA          31      //  half16  #ha(L + A)

#define R_PPC_SDAREL16          32      //  half16* S + A - _SDA_BASE_
#define R_PPC_SECTOFF           33      //  half16* R + A
#define R_PPC_SECTOFF_LO        34      //  half16  #lo(R + A)
#define R_PPC_SECTOFF_HI        35      //  half16  #hi(R + A)
#define R_PPC_SECTOFF_HA        36      //  half16  #ha(R + A)
#define R_PPC_ADDR30            37      //  word30  (S + A - P) >> 2

//      Relocation Type         Value       Field   Check   Calculation
#define R_PPC_EMB_NADDR32       101     //  uword32 N       (A - S)
#define R_PPC_EMB_NADDR16       102     //  uhalf16 Y       (A - S)
#define R_PPC_EMB_NADDR16_LO    103     //  uhalf16 N       #lo(A - S)
#define R_PPC_EMB_NADDR16_HI    104     //  uhalf16 N       #hi(A - S)
#define R_PPC_EMB_NADDR16_HA    105     //  uhalf16 N       #ha(A - S)
#define R_PPC_EMB_SDAI16        106     //  uhalf16 Y       T
#define R_PPC_EMB_SDA2I16       107     //  uhalf16 Y       U
#define R_PPC_EMB_SDA2REL       108     //  uhalf16 Y       S + A - _SDA2_BASE_
#define R_PPC_EMB_SDA21         109     //  ulow21  N       See below
#define R_PPC_EMB_MRKREF        110     //  none    N       See below
#define R_PPC_EMB_RELSEC16      111     //  uhalf16 Y       V + A
#define R_PPC_EMB_RELST_LO      112     //  uhalf16 N       #lo(W + A)
#define R_PPC_EMB_RELST_HI      113     //  uhalf16 N       #hi(W + A)
#define R_PPC_EMB_RELST_HA      114     //  uhalf16 N       #ha(W + A)
#define R_PPC_EMB_BIT_FLD       115     //  uword32 Y       See below
#define R_PPC_EMB_RELSDA        116     //  uhalf16 Y       See below

/*---------------------------------------------------------------------------*
    Program Header
 *---------------------------------------------------------------------------*/

typedef struct Elf32_Phdr
{
    Elf32_Word  p_type;
    Elf32_Off   p_offset;
    Elf32_Addr  p_vaddr;
    Elf32_Addr  p_paddr;
    Elf32_Word  p_filesz;
    Elf32_Word  p_memsz;
    Elf32_Word  p_flags;
    Elf32_Word  p_align;
} Elf32_Phdr;

#define PT_NULL         0
#define PT_LOAD         1
#define PT_DYNAMIC      2
#define PT_INTERP       3
#define PT_NOTE         4
#define PT_SHLIB        5
#define PT_PHDR         6
#define PT_LOPROC       0x70000000
#define PT_HIPROC       0x7fffffff

#define PF_X            (1 << 0)    // Segment is executable
#define PF_W            (1 << 1)    // Segment is writable
#define PF_R            (1 << 2)    // Segment is readable
#define PF_MASKPROC     0xF0000000  // Processor-specific reserved bits

/*---------------------------------------------------------------------------*
    Dynamic Linking
 *---------------------------------------------------------------------------*/

typedef struct Elf32_Dyn
{
    Elf32_Sword     d_tag;
    union
    {
        Elf32_Word  d_val;
        Elf32_Addr  d_ptr;
    } d_un;
} Elf32_Dyn;

#define DT_NULL     0
#define DT_NEEDED   1
#define DT_PLTRELSZ 2
#define DT_PLTGOT   3
#define DT_HASH     4
#define DT_STRTAB   5
#define DT_SYMTAB   6
#define DT_RELA     7
#define DT_RELASZ   8
#define DT_RELAENT  9
#define DT_STRSZ    10
#define DT_SYMENT   11
#define DT_INIT     12
#define DT_FINI     13
#define DT_SONAME   14
#define DT_RPATH    15
#define DT_SYMBOLIC 16
#define DT_REL      17
#define DT_RELSZ    18
#define DT_RELENT   19
#define DT_PLTREL   20
#define DT_DEBUG    21
#define DT_TEXTREL  22
#define DT_JMPREL   23
#define DT_LOPROC   0x70000000
#define DT_HIPROC   0x7fffffff

#ifdef __cplusplus
}
#endif

#endif//__ELF_H__
