/* Based on CPU DB MC9S08MM128_81, version 3.00.011 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s08mm128.h
**     Processor : MC9S08MM128VMB
**     FileFormat: V2.32
**     DataSheet : MC9S08MM128RM Rev. 3 07/2010
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 13:53
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 25.6.2010, V3.00.0:
**              - Removed SOPT5 register from 0x180D. This location is reserved for internal testing.
**
**     File-Format-Revisions:
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08MM128_H
#define _MC9S08MM128_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55U, SRS = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vsci2tx            48U
#define VectorNumber_VReserved47        47U
#define VectorNumber_VReserved46        46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_VReserved43        43U
#define VectorNumber_VReserved42        42U
#define VectorNumber_VReserved41        41U
#define VectorNumber_VReserved40        40U
#define VectorNumber_VReserved39        39U
#define VectorNumber_VReserved38        38U
#define VectorNumber_VReserved37        37U
#define VectorNumber_VReserved36        36U
#define VectorNumber_VReserved35        35U
#define VectorNumber_VReserved34        34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_VReserved32        32U
#define VectorNumber_Vsci2rx            31U
#define VectorNumber_Vsci2err           30U
#define VectorNumber_Vtod               29U
#define VectorNumber_Vkeyboard2         28U
#define VectorNumber_Vkeyboard1         27U
#define VectorNumber_Vpracmp            26U
#define VectorNumber_Vadc               25U
#define VectorNumber_Viic               24U
#define VectorNumber_Vsci1tx            23U
#define VectorNumber_Vsci1rx            22U
#define VectorNumber_Vsci1err           21U
#define VectorNumber_Vcmt               20U
#define VectorNumber_Vspi2              19U
#define VectorNumber_Vtpm2ovf           18U
#define VectorNumber_Vtpm2ch3           17U
#define VectorNumber_Vtpm2ch2           16U
#define VectorNumber_Vtpm2ch1           15U
#define VectorNumber_Vtpm2ch0           14U
#define VectorNumber_Vtpm1ovf           13U
#define VectorNumber_Vtpm1ch3           12U
#define VectorNumber_Vtpm1ch2           11U
#define VectorNumber_Vtpm1ch1           10U
#define VectorNumber_Vtpm1ch0           9U
#define VectorNumber_Vdac               8U
#define VectorNumber_Vpdb               7U
#define VectorNumber_Vusb               6U
#define VectorNumber_Vspi1              5U
#define VectorNumber_Vlol               4U
#define VectorNumber_Vlvd               3U
#define VectorNumber_Virq               2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vsci2tx                         0xFF9EU
#define VReserved47                     0xFFA0U
#define VReserved46                     0xFFA2U
#define VReserved45                     0xFFA4U
#define VReserved44                     0xFFA6U
#define VReserved43                     0xFFA8U
#define VReserved42                     0xFFAAU
#define VReserved41                     0xFFACU
#define VReserved40                     0xFFAEU
#define VReserved39                     0xFFB0U
#define VReserved38                     0xFFB2U
#define VReserved37                     0xFFB4U
#define VReserved36                     0xFFB6U
#define VReserved35                     0xFFB8U
#define VReserved34                     0xFFBAU
#define VReserved33                     0xFFBCU
#define VReserved32                     0xFFBEU
#define Vsci2rx                         0xFFC0U
#define Vsci2err                        0xFFC2U
#define Vtod                            0xFFC4U
#define Vkeyboard2                      0xFFC6U
#define Vkeyboard1                      0xFFC8U
#define Vpracmp                         0xFFCAU
#define Vadc                            0xFFCCU
#define Viic                            0xFFCEU
#define Vsci1tx                         0xFFD0U
#define Vsci1rx                         0xFFD2U
#define Vsci1err                        0xFFD4U
#define Vcmt                            0xFFD6U
#define Vspi2                           0xFFD8U
#define Vtpm2ovf                        0xFFDAU
#define Vtpm2ch3                        0xFFDCU
#define Vtpm2ch2                        0xFFDEU
#define Vtpm2ch1                        0xFFE0U
#define Vtpm2ch0                        0xFFE2U
#define Vtpm1ovf                        0xFFE4U
#define Vtpm1ch3                        0xFFE6U
#define Vtpm1ch2                        0xFFE8U
#define Vtpm1ch1                        0xFFEAU
#define Vtpm1ch0                        0xFFECU
#define Vdac                            0xFFEEU
#define Vpdb                            0xFFF0U
#define Vusb                            0xFFF2U
#define Vspi1                           0xFFF4U
#define Vlol                            0xFFF6U
#define Vlvd                            0xFFF8U
#define Virq                            0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD7_MASK                 128U


/*** PTCDD - Port C Data Direction Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD7_MASK               128U


/*** PTDD - Port D Data Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
extern volatile PTDDSTR _PTDD @0x00000006;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1U
#define PTDD_PTDD1_MASK                 2U
#define PTDD_PTDD2_MASK                 4U
#define PTDD_PTDD3_MASK                 8U
#define PTDD_PTDD4_MASK                 16U
#define PTDD_PTDD5_MASK                 32U
#define PTDD_PTDD6_MASK                 64U
#define PTDD_PTDD7_MASK                 128U


/*** PTDDD - Port D Data Direction Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
extern volatile PTDDDSTR _PTDDD @0x00000007;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1U
#define PTDDD_PTDDD1_MASK               2U
#define PTDDD_PTDDD2_MASK               4U
#define PTDDD_PTDDD3_MASK               8U
#define PTDDD_PTDDD4_MASK               16U
#define PTDDD_PTDDD5_MASK               32U
#define PTDDD_PTDDD6_MASK               64U
#define PTDDD_PTDDD7_MASK               128U


/*** PPAGE - Program Page Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte XA14        :1;                                       /* Extended address, bit 14 */
    byte XA15        :1;                                       /* Extended address, bit 15 */
    byte XA16        :1;                                       /* Extended address, bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpXA_14 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @0x00000008;
#define PPAGE                           _PPAGE.Byte
#define PPAGE_XA14                      _PPAGE.Bits.XA14
#define PPAGE_XA15                      _PPAGE.Bits.XA15
#define PPAGE_XA16                      _PPAGE.Bits.XA16
#define PPAGE_XA_14                     _PPAGE.MergedBits.grpXA_14
#define PPAGE_XA                        PPAGE_XA_14

#define PPAGE_XA14_MASK                 1U
#define PPAGE_XA15_MASK                 2U
#define PPAGE_XA16_MASK                 4U
#define PPAGE_XA_14_MASK                7U
#define PPAGE_XA_14_BITNUM              0U


/*** LAP2 - Linear Address Pointer Register 2; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte LA16        :1;                                       /* Linear address pointer, bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LAP2STR;
extern volatile LAP2STR _LAP2 @0x00000009;
#define LAP2                            _LAP2.Byte
#define LAP2_LA16                       _LAP2.Bits.LA16

#define LAP2_LA16_MASK                  1U


/*** LAP1 - Linear Address Pointer Register 1; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte LA8         :1;                                       /* Linear address pointer, bit 8 */
    byte LA9         :1;                                       /* Linear address pointer, bit 9 */
    byte LA10        :1;                                       /* Linear address pointer, bit 10 */
    byte LA11        :1;                                       /* Linear address pointer, bit 11 */
    byte LA12        :1;                                       /* Linear address pointer, bit 12 */
    byte LA13        :1;                                       /* Linear address pointer, bit 13 */
    byte LA14        :1;                                       /* Linear address pointer, bit 14 */
    byte LA15        :1;                                       /* Linear address pointer, bit 15 */
  } Bits;
} LAP1STR;
extern volatile LAP1STR _LAP1 @0x0000000A;
#define LAP1                            _LAP1.Byte
#define LAP1_LA8                        _LAP1.Bits.LA8
#define LAP1_LA9                        _LAP1.Bits.LA9
#define LAP1_LA10                       _LAP1.Bits.LA10
#define LAP1_LA11                       _LAP1.Bits.LA11
#define LAP1_LA12                       _LAP1.Bits.LA12
#define LAP1_LA13                       _LAP1.Bits.LA13
#define LAP1_LA14                       _LAP1.Bits.LA14
#define LAP1_LA15                       _LAP1.Bits.LA15

#define LAP1_LA8_MASK                   1U
#define LAP1_LA9_MASK                   2U
#define LAP1_LA10_MASK                  4U
#define LAP1_LA11_MASK                  8U
#define LAP1_LA12_MASK                  16U
#define LAP1_LA13_MASK                  32U
#define LAP1_LA14_MASK                  64U
#define LAP1_LA15_MASK                  128U


/*** LAP0 - Linear Address Pointer Register 0; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte LA0         :1;                                       /* Linear address pointer, bit 0 */
    byte LA1         :1;                                       /* Linear address pointer, bit 1 */
    byte LA2         :1;                                       /* Linear address pointer, bit 2 */
    byte LA3         :1;                                       /* Linear address pointer, bit 3 */
    byte LA4         :1;                                       /* Linear address pointer, bit 4 */
    byte LA5         :1;                                       /* Linear address pointer, bit 5 */
    byte LA6         :1;                                       /* Linear address pointer, bit 6 */
    byte LA7         :1;                                       /* Linear address pointer, bit 7 */
  } Bits;
} LAP0STR;
extern volatile LAP0STR _LAP0 @0x0000000B;
#define LAP0                            _LAP0.Byte
#define LAP0_LA0                        _LAP0.Bits.LA0
#define LAP0_LA1                        _LAP0.Bits.LA1
#define LAP0_LA2                        _LAP0.Bits.LA2
#define LAP0_LA3                        _LAP0.Bits.LA3
#define LAP0_LA4                        _LAP0.Bits.LA4
#define LAP0_LA5                        _LAP0.Bits.LA5
#define LAP0_LA6                        _LAP0.Bits.LA6
#define LAP0_LA7                        _LAP0.Bits.LA7

#define LAP0_LA0_MASK                   1U
#define LAP0_LA1_MASK                   2U
#define LAP0_LA2_MASK                   4U
#define LAP0_LA3_MASK                   8U
#define LAP0_LA4_MASK                   16U
#define LAP0_LA5_MASK                   32U
#define LAP0_LA6_MASK                   64U
#define LAP0_LA7_MASK                   128U


/*** LWP - Linear Word Post Increment Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LWPSTR;
extern volatile LWPSTR _LWP @0x0000000C;
#define LWP                             _LWP.Byte
#define LWP_D0                          _LWP.Bits.D0
#define LWP_D1                          _LWP.Bits.D1
#define LWP_D2                          _LWP.Bits.D2
#define LWP_D3                          _LWP.Bits.D3
#define LWP_D4                          _LWP.Bits.D4
#define LWP_D5                          _LWP.Bits.D5
#define LWP_D6                          _LWP.Bits.D6
#define LWP_D7                          _LWP.Bits.D7

#define LWP_D0_MASK                     1U
#define LWP_D1_MASK                     2U
#define LWP_D2_MASK                     4U
#define LWP_D3_MASK                     8U
#define LWP_D4_MASK                     16U
#define LWP_D5_MASK                     32U
#define LWP_D6_MASK                     64U
#define LWP_D7_MASK                     128U


/*** LBP - Linear Byte Post Increment Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBPSTR;
extern volatile LBPSTR _LBP @0x0000000D;
#define LBP                             _LBP.Byte
#define LBP_D0                          _LBP.Bits.D0
#define LBP_D1                          _LBP.Bits.D1
#define LBP_D2                          _LBP.Bits.D2
#define LBP_D3                          _LBP.Bits.D3
#define LBP_D4                          _LBP.Bits.D4
#define LBP_D5                          _LBP.Bits.D5
#define LBP_D6                          _LBP.Bits.D6
#define LBP_D7                          _LBP.Bits.D7

#define LBP_D0_MASK                     1U
#define LBP_D1_MASK                     2U
#define LBP_D2_MASK                     4U
#define LBP_D3_MASK                     8U
#define LBP_D4_MASK                     16U
#define LBP_D5_MASK                     32U
#define LBP_D6_MASK                     64U
#define LBP_D7_MASK                     128U


/*** LB - Linear Byte Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBSTR;
extern volatile LBSTR _LB @0x0000000E;
#define LB                              _LB.Byte
#define LB_D0                           _LB.Bits.D0
#define LB_D1                           _LB.Bits.D1
#define LB_D2                           _LB.Bits.D2
#define LB_D3                           _LB.Bits.D3
#define LB_D4                           _LB.Bits.D4
#define LB_D5                           _LB.Bits.D5
#define LB_D6                           _LB.Bits.D6
#define LB_D7                           _LB.Bits.D7

#define LB_D0_MASK                      1U
#define LB_D1_MASK                      2U
#define LB_D2_MASK                      4U
#define LB_D3_MASK                      8U
#define LB_D4_MASK                      16U
#define LB_D5_MASK                      32U
#define LB_D6_MASK                      64U
#define LB_D7_MASK                      128U


/*** LAPAB - Linear Address Pointer Add Byte Register; 0x0000000F ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LAPABSTR;
extern volatile LAPABSTR _LAPAB @0x0000000F;
#define LAPAB                           _LAPAB.Byte
#define LAPAB_D0                        _LAPAB.Bits.D0
#define LAPAB_D1                        _LAPAB.Bits.D1
#define LAPAB_D2                        _LAPAB.Bits.D2
#define LAPAB_D3                        _LAPAB.Bits.D3
#define LAPAB_D4                        _LAPAB.Bits.D4
#define LAPAB_D5                        _LAPAB.Bits.D5
#define LAPAB_D6                        _LAPAB.Bits.D6
#define LAPAB_D7                        _LAPAB.Bits.D7

#define LAPAB_D0_MASK                   1U
#define LAPAB_D1_MASK                   2U
#define LAPAB_D2_MASK                   4U
#define LAPAB_D3_MASK                   8U
#define LAPAB_D4_MASK                   16U
#define LAPAB_D5_MASK                   32U
#define LAPAB_D6_MASK                   64U
#define LAPAB_D7_MASK                   128U


/*** DACDAT0 - DAC Data 0 Register; 0x00000010 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT0H - DAC Data 0 High Register; 0x00000010 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT08    :1;                                       /* Buffer Data 0 High, bit 8 */
        byte DACDAT09    :1;                                       /* Buffer Data 0 High, bit 9 */
        byte DACDAT010   :1;                                       /* Buffer Data 0 High, bit 10 */
        byte DACDAT011   :1;                                       /* Buffer Data 0 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT0_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT0HSTR;
    #define DACDAT0H                    _DACDAT0.Overlap_STR.DACDAT0HSTR.Byte
    #define DACDAT0H_DACDAT08           _DACDAT0.Overlap_STR.DACDAT0HSTR.Bits.DACDAT08
    #define DACDAT0H_DACDAT09           _DACDAT0.Overlap_STR.DACDAT0HSTR.Bits.DACDAT09
    #define DACDAT0H_DACDAT010          _DACDAT0.Overlap_STR.DACDAT0HSTR.Bits.DACDAT010
    #define DACDAT0H_DACDAT011          _DACDAT0.Overlap_STR.DACDAT0HSTR.Bits.DACDAT011
    #define DACDAT0H_DACDAT0_8          _DACDAT0.Overlap_STR.DACDAT0HSTR.MergedBits.grpDACDAT0_8
    #define DACDAT0H_DACDAT0            DACDAT0H_DACDAT0_8
    
    #define DACDAT0H_DACDAT08_MASK      1U
    #define DACDAT0H_DACDAT09_MASK      2U
    #define DACDAT0H_DACDAT010_MASK     4U
    #define DACDAT0H_DACDAT011_MASK     8U
    #define DACDAT0H_DACDAT0_8_MASK     15U
    #define DACDAT0H_DACDAT0_8_BITNUM   0U
    

    /*** DACDAT0L - DAC Data 0 Low Register; 0x00000011 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT00    :1;                                       /* Buffer Data 0 Low, bit 0 */
        byte DACDAT01    :1;                                       /* Buffer Data 0 Low, bit 1 */
        byte DACDAT02    :1;                                       /* Buffer Data 0 Low, bit 2 */
        byte DACDAT03    :1;                                       /* Buffer Data 0 Low, bit 3 */
        byte DACDAT04    :1;                                       /* Buffer Data 0 Low, bit 4 */
        byte DACDAT05    :1;                                       /* Buffer Data 0 Low, bit 5 */
        byte DACDAT06    :1;                                       /* Buffer Data 0 Low, bit 6 */
        byte DACDAT07    :1;                                       /* Buffer Data 0 Low, bit 7 */
      } Bits;
    } DACDAT0LSTR;
    #define DACDAT0L                    _DACDAT0.Overlap_STR.DACDAT0LSTR.Byte
    #define DACDAT0L_DACDAT00           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT00
    #define DACDAT0L_DACDAT01           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT01
    #define DACDAT0L_DACDAT02           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT02
    #define DACDAT0L_DACDAT03           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT03
    #define DACDAT0L_DACDAT04           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT04
    #define DACDAT0L_DACDAT05           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT05
    #define DACDAT0L_DACDAT06           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT06
    #define DACDAT0L_DACDAT07           _DACDAT0.Overlap_STR.DACDAT0LSTR.Bits.DACDAT07
    
    #define DACDAT0L_DACDAT00_MASK      1U
    #define DACDAT0L_DACDAT01_MASK      2U
    #define DACDAT0L_DACDAT02_MASK      4U
    #define DACDAT0L_DACDAT03_MASK      8U
    #define DACDAT0L_DACDAT04_MASK      16U
    #define DACDAT0L_DACDAT05_MASK      32U
    #define DACDAT0L_DACDAT06_MASK      64U
    #define DACDAT0L_DACDAT07_MASK      128U
    
  } Overlap_STR;

} DACDAT0STR;
extern volatile DACDAT0STR _DACDAT0 @0x00000010;
#define DACDAT0                         _DACDAT0.Word
/* DACDAT_ARR: Access 16 DACDATx registers in an array */
#define DACDAT_ARR                      ((volatile word * __far) &DACDAT0)


/*** DACDAT1 - DAC Data 1 Register; 0x00000012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT1H - DAC Data 1 High Register; 0x00000012 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT18    :1;                                       /* Buffer Data 1 High, bit 8 */
        byte DACDAT19    :1;                                       /* Buffer Data 1 High, bit 9 */
        byte DACDAT110   :1;                                       /* Buffer Data 1 High, bit 10 */
        byte DACDAT111   :1;                                       /* Buffer Data 1 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_18 :2;
        byte grpDACDAT1_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT1HSTR;
    #define DACDAT1H                    _DACDAT1.Overlap_STR.DACDAT1HSTR.Byte
    #define DACDAT1H_DACDAT18           _DACDAT1.Overlap_STR.DACDAT1HSTR.Bits.DACDAT18
    #define DACDAT1H_DACDAT19           _DACDAT1.Overlap_STR.DACDAT1HSTR.Bits.DACDAT19
    #define DACDAT1H_DACDAT110          _DACDAT1.Overlap_STR.DACDAT1HSTR.Bits.DACDAT110
    #define DACDAT1H_DACDAT111          _DACDAT1.Overlap_STR.DACDAT1HSTR.Bits.DACDAT111
    #define DACDAT1H_DACDAT_18          _DACDAT1.Overlap_STR.DACDAT1HSTR.MergedBits.grpDACDAT_18
    #define DACDAT1H_DACDAT1_10         _DACDAT1.Overlap_STR.DACDAT1HSTR.MergedBits.grpDACDAT1_10
    #define DACDAT1H_DACDAT             DACDAT1H_DACDAT_18
    #define DACDAT1H_DACDAT1            DACDAT1H_DACDAT1_10
    
    #define DACDAT1H_DACDAT18_MASK      1U
    #define DACDAT1H_DACDAT19_MASK      2U
    #define DACDAT1H_DACDAT110_MASK     4U
    #define DACDAT1H_DACDAT111_MASK     8U
    #define DACDAT1H_DACDAT_18_MASK     3U
    #define DACDAT1H_DACDAT_18_BITNUM   0U
    #define DACDAT1H_DACDAT1_10_MASK    12U
    #define DACDAT1H_DACDAT1_10_BITNUM  2U
    

    /*** DACDAT1L - DAC Data 1 Low Register; 0x00000013 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT10_bit :1;                                      /* Buffer Data 1 Low, bit 0 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT11_bit :1;                                      /* Buffer Data 1 Low, bit 1 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT12_bit :1;                                      /* Buffer Data 1 Low, bit 2 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT13_bit :1;                                      /* Buffer Data 1 Low, bit 3 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT14_bit :1;                                      /* Buffer Data 1 Low, bit 4 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT15_bit :1;                                      /* Buffer Data 1 Low, bit 5 */ /*Warning: bit name is duplicated with register name*/
        byte DACDAT16    :1;                                       /* Buffer Data 1 Low, bit 6 */
        byte DACDAT17    :1;                                       /* Buffer Data 1 Low, bit 7 */
      } Bits;
    } DACDAT1LSTR;
    #define DACDAT1L                    _DACDAT1.Overlap_STR.DACDAT1LSTR.Byte
    #define DACDAT1L_DACDAT10           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT10_bit
    #define DACDAT1L_DACDAT11           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT11_bit
    #define DACDAT1L_DACDAT12           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT12_bit
    #define DACDAT1L_DACDAT13           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT13_bit
    #define DACDAT1L_DACDAT14           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT14_bit
    #define DACDAT1L_DACDAT15           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT15_bit
    #define DACDAT1L_DACDAT16           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT16
    #define DACDAT1L_DACDAT17           _DACDAT1.Overlap_STR.DACDAT1LSTR.Bits.DACDAT17
    
    #define DACDAT1L_DACDAT10_MASK      1U
    #define DACDAT1L_DACDAT11_MASK      2U
    #define DACDAT1L_DACDAT12_MASK      4U
    #define DACDAT1L_DACDAT13_MASK      8U
    #define DACDAT1L_DACDAT14_MASK      16U
    #define DACDAT1L_DACDAT15_MASK      32U
    #define DACDAT1L_DACDAT16_MASK      64U
    #define DACDAT1L_DACDAT17_MASK      128U
    
  } Overlap_STR;

} DACDAT1STR;
extern volatile DACDAT1STR _DACDAT1 @0x00000012;
#define DACDAT1                         _DACDAT1.Word


/*** DACDAT2 - DAC Data 2 Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT2H - DAC Data 2 High Register; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT28    :1;                                       /* Buffer Data 2 High, bit 8 */
        byte DACDAT29    :1;                                       /* Buffer Data 2 High, bit 9 */
        byte DACDAT210   :1;                                       /* Buffer Data 2 High, bit 10 */
        byte DACDAT211   :1;                                       /* Buffer Data 2 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_28 :2;
        byte grpDACDAT2_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT2HSTR;
    #define DACDAT2H                    _DACDAT2.Overlap_STR.DACDAT2HSTR.Byte
    #define DACDAT2H_DACDAT28           _DACDAT2.Overlap_STR.DACDAT2HSTR.Bits.DACDAT28
    #define DACDAT2H_DACDAT29           _DACDAT2.Overlap_STR.DACDAT2HSTR.Bits.DACDAT29
    #define DACDAT2H_DACDAT210          _DACDAT2.Overlap_STR.DACDAT2HSTR.Bits.DACDAT210
    #define DACDAT2H_DACDAT211          _DACDAT2.Overlap_STR.DACDAT2HSTR.Bits.DACDAT211
    #define DACDAT2H_DACDAT_28          _DACDAT2.Overlap_STR.DACDAT2HSTR.MergedBits.grpDACDAT_28
    #define DACDAT2H_DACDAT2_10         _DACDAT2.Overlap_STR.DACDAT2HSTR.MergedBits.grpDACDAT2_10
    #define DACDAT2H_DACDAT             DACDAT2H_DACDAT_28
    #define DACDAT2H_DACDAT2            DACDAT2H_DACDAT2_10
    
    #define DACDAT2H_DACDAT28_MASK      1U
    #define DACDAT2H_DACDAT29_MASK      2U
    #define DACDAT2H_DACDAT210_MASK     4U
    #define DACDAT2H_DACDAT211_MASK     8U
    #define DACDAT2H_DACDAT_28_MASK     3U
    #define DACDAT2H_DACDAT_28_BITNUM   0U
    #define DACDAT2H_DACDAT2_10_MASK    12U
    #define DACDAT2H_DACDAT2_10_BITNUM  2U
    

    /*** DACDAT2L - DAC Data 2 Low Register; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT20    :1;                                       /* Buffer Data 2 Low, bit 0 */
        byte DACDAT21    :1;                                       /* Buffer Data 2 Low, bit 1 */
        byte DACDAT22    :1;                                       /* Buffer Data 2 Low, bit 2 */
        byte DACDAT23    :1;                                       /* Buffer Data 2 Low, bit 3 */
        byte DACDAT24    :1;                                       /* Buffer Data 2 Low, bit 4 */
        byte DACDAT25    :1;                                       /* Buffer Data 2 Low, bit 5 */
        byte DACDAT26    :1;                                       /* Buffer Data 2 Low, bit 6 */
        byte DACDAT27    :1;                                       /* Buffer Data 2 Low, bit 7 */
      } Bits;
    } DACDAT2LSTR;
    #define DACDAT2L                    _DACDAT2.Overlap_STR.DACDAT2LSTR.Byte
    #define DACDAT2L_DACDAT20           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT20
    #define DACDAT2L_DACDAT21           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT21
    #define DACDAT2L_DACDAT22           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT22
    #define DACDAT2L_DACDAT23           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT23
    #define DACDAT2L_DACDAT24           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT24
    #define DACDAT2L_DACDAT25           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT25
    #define DACDAT2L_DACDAT26           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT26
    #define DACDAT2L_DACDAT27           _DACDAT2.Overlap_STR.DACDAT2LSTR.Bits.DACDAT27
    
    #define DACDAT2L_DACDAT20_MASK      1U
    #define DACDAT2L_DACDAT21_MASK      2U
    #define DACDAT2L_DACDAT22_MASK      4U
    #define DACDAT2L_DACDAT23_MASK      8U
    #define DACDAT2L_DACDAT24_MASK      16U
    #define DACDAT2L_DACDAT25_MASK      32U
    #define DACDAT2L_DACDAT26_MASK      64U
    #define DACDAT2L_DACDAT27_MASK      128U
    
  } Overlap_STR;

} DACDAT2STR;
extern volatile DACDAT2STR _DACDAT2 @0x00000014;
#define DACDAT2                         _DACDAT2.Word


/*** DACDAT3 - DAC Data 3 Register; 0x00000016 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT3H - DAC Data 3 High Register; 0x00000016 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT38    :1;                                       /* Buffer Data 3 High, bit 8 */
        byte DACDAT39    :1;                                       /* Buffer Data 3 High, bit 9 */
        byte DACDAT310   :1;                                       /* Buffer Data 3 High, bit 10 */
        byte DACDAT311   :1;                                       /* Buffer Data 3 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_38 :2;
        byte grpDACDAT3_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT3HSTR;
    #define DACDAT3H                    _DACDAT3.Overlap_STR.DACDAT3HSTR.Byte
    #define DACDAT3H_DACDAT38           _DACDAT3.Overlap_STR.DACDAT3HSTR.Bits.DACDAT38
    #define DACDAT3H_DACDAT39           _DACDAT3.Overlap_STR.DACDAT3HSTR.Bits.DACDAT39
    #define DACDAT3H_DACDAT310          _DACDAT3.Overlap_STR.DACDAT3HSTR.Bits.DACDAT310
    #define DACDAT3H_DACDAT311          _DACDAT3.Overlap_STR.DACDAT3HSTR.Bits.DACDAT311
    #define DACDAT3H_DACDAT_38          _DACDAT3.Overlap_STR.DACDAT3HSTR.MergedBits.grpDACDAT_38
    #define DACDAT3H_DACDAT3_10         _DACDAT3.Overlap_STR.DACDAT3HSTR.MergedBits.grpDACDAT3_10
    #define DACDAT3H_DACDAT             DACDAT3H_DACDAT_38
    #define DACDAT3H_DACDAT3            DACDAT3H_DACDAT3_10
    
    #define DACDAT3H_DACDAT38_MASK      1U
    #define DACDAT3H_DACDAT39_MASK      2U
    #define DACDAT3H_DACDAT310_MASK     4U
    #define DACDAT3H_DACDAT311_MASK     8U
    #define DACDAT3H_DACDAT_38_MASK     3U
    #define DACDAT3H_DACDAT_38_BITNUM   0U
    #define DACDAT3H_DACDAT3_10_MASK    12U
    #define DACDAT3H_DACDAT3_10_BITNUM  2U
    

    /*** DACDAT3L - DAC Data 3 Low Register; 0x00000017 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT30    :1;                                       /* Buffer Data 3 Low, bit 0 */
        byte DACDAT31    :1;                                       /* Buffer Data 3 Low, bit 1 */
        byte DACDAT32    :1;                                       /* Buffer Data 3 Low, bit 2 */
        byte DACDAT33    :1;                                       /* Buffer Data 3 Low, bit 3 */
        byte DACDAT34    :1;                                       /* Buffer Data 3 Low, bit 4 */
        byte DACDAT35    :1;                                       /* Buffer Data 3 Low, bit 5 */
        byte DACDAT36    :1;                                       /* Buffer Data 3 Low, bit 6 */
        byte DACDAT37    :1;                                       /* Buffer Data 3 Low, bit 7 */
      } Bits;
    } DACDAT3LSTR;
    #define DACDAT3L                    _DACDAT3.Overlap_STR.DACDAT3LSTR.Byte
    #define DACDAT3L_DACDAT30           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT30
    #define DACDAT3L_DACDAT31           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT31
    #define DACDAT3L_DACDAT32           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT32
    #define DACDAT3L_DACDAT33           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT33
    #define DACDAT3L_DACDAT34           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT34
    #define DACDAT3L_DACDAT35           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT35
    #define DACDAT3L_DACDAT36           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT36
    #define DACDAT3L_DACDAT37           _DACDAT3.Overlap_STR.DACDAT3LSTR.Bits.DACDAT37
    
    #define DACDAT3L_DACDAT30_MASK      1U
    #define DACDAT3L_DACDAT31_MASK      2U
    #define DACDAT3L_DACDAT32_MASK      4U
    #define DACDAT3L_DACDAT33_MASK      8U
    #define DACDAT3L_DACDAT34_MASK      16U
    #define DACDAT3L_DACDAT35_MASK      32U
    #define DACDAT3L_DACDAT36_MASK      64U
    #define DACDAT3L_DACDAT37_MASK      128U
    
  } Overlap_STR;

} DACDAT3STR;
extern volatile DACDAT3STR _DACDAT3 @0x00000016;
#define DACDAT3                         _DACDAT3.Word


/*** DACDAT4 - DAC Data 4 Register; 0x00000018 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT4H - DAC Data 4 High Register; 0x00000018 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT48    :1;                                       /* Buffer Data 4 High, bit 8 */
        byte DACDAT49    :1;                                       /* Buffer Data 4 High, bit 9 */
        byte DACDAT410   :1;                                       /* Buffer Data 4 High, bit 10 */
        byte DACDAT411   :1;                                       /* Buffer Data 4 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_48 :2;
        byte grpDACDAT4_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT4HSTR;
    #define DACDAT4H                    _DACDAT4.Overlap_STR.DACDAT4HSTR.Byte
    #define DACDAT4H_DACDAT48           _DACDAT4.Overlap_STR.DACDAT4HSTR.Bits.DACDAT48
    #define DACDAT4H_DACDAT49           _DACDAT4.Overlap_STR.DACDAT4HSTR.Bits.DACDAT49
    #define DACDAT4H_DACDAT410          _DACDAT4.Overlap_STR.DACDAT4HSTR.Bits.DACDAT410
    #define DACDAT4H_DACDAT411          _DACDAT4.Overlap_STR.DACDAT4HSTR.Bits.DACDAT411
    #define DACDAT4H_DACDAT_48          _DACDAT4.Overlap_STR.DACDAT4HSTR.MergedBits.grpDACDAT_48
    #define DACDAT4H_DACDAT4_10         _DACDAT4.Overlap_STR.DACDAT4HSTR.MergedBits.grpDACDAT4_10
    #define DACDAT4H_DACDAT             DACDAT4H_DACDAT_48
    #define DACDAT4H_DACDAT4            DACDAT4H_DACDAT4_10
    
    #define DACDAT4H_DACDAT48_MASK      1U
    #define DACDAT4H_DACDAT49_MASK      2U
    #define DACDAT4H_DACDAT410_MASK     4U
    #define DACDAT4H_DACDAT411_MASK     8U
    #define DACDAT4H_DACDAT_48_MASK     3U
    #define DACDAT4H_DACDAT_48_BITNUM   0U
    #define DACDAT4H_DACDAT4_10_MASK    12U
    #define DACDAT4H_DACDAT4_10_BITNUM  2U
    

    /*** DACDAT4L - DAC Data 4 Low Register; 0x00000019 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT40    :1;                                       /* Buffer Data 4 Low, bit 0 */
        byte DACDAT41    :1;                                       /* Buffer Data 4 Low, bit 1 */
        byte DACDAT42    :1;                                       /* Buffer Data 4 Low, bit 2 */
        byte DACDAT43    :1;                                       /* Buffer Data 4 Low, bit 3 */
        byte DACDAT44    :1;                                       /* Buffer Data 4 Low, bit 4 */
        byte DACDAT45    :1;                                       /* Buffer Data 4 Low, bit 5 */
        byte DACDAT46    :1;                                       /* Buffer Data 4 Low, bit 6 */
        byte DACDAT47    :1;                                       /* Buffer Data 4 Low, bit 7 */
      } Bits;
    } DACDAT4LSTR;
    #define DACDAT4L                    _DACDAT4.Overlap_STR.DACDAT4LSTR.Byte
    #define DACDAT4L_DACDAT40           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT40
    #define DACDAT4L_DACDAT41           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT41
    #define DACDAT4L_DACDAT42           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT42
    #define DACDAT4L_DACDAT43           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT43
    #define DACDAT4L_DACDAT44           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT44
    #define DACDAT4L_DACDAT45           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT45
    #define DACDAT4L_DACDAT46           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT46
    #define DACDAT4L_DACDAT47           _DACDAT4.Overlap_STR.DACDAT4LSTR.Bits.DACDAT47
    
    #define DACDAT4L_DACDAT40_MASK      1U
    #define DACDAT4L_DACDAT41_MASK      2U
    #define DACDAT4L_DACDAT42_MASK      4U
    #define DACDAT4L_DACDAT43_MASK      8U
    #define DACDAT4L_DACDAT44_MASK      16U
    #define DACDAT4L_DACDAT45_MASK      32U
    #define DACDAT4L_DACDAT46_MASK      64U
    #define DACDAT4L_DACDAT47_MASK      128U
    
  } Overlap_STR;

} DACDAT4STR;
extern volatile DACDAT4STR _DACDAT4 @0x00000018;
#define DACDAT4                         _DACDAT4.Word


/*** DACDAT5 - DAC Data 5 Register; 0x0000001A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT5H - DAC Data 5 High Register; 0x0000001A ***/
    union {
      byte Byte;
      struct {
        byte DACDAT58    :1;                                       /* Buffer Data 5 High, bit 8 */
        byte DACDAT59    :1;                                       /* Buffer Data 5 High, bit 9 */
        byte DACDAT510   :1;                                       /* Buffer Data 5 High, bit 10 */
        byte DACDAT511   :1;                                       /* Buffer Data 5 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_58 :2;
        byte grpDACDAT5_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT5HSTR;
    #define DACDAT5H                    _DACDAT5.Overlap_STR.DACDAT5HSTR.Byte
    #define DACDAT5H_DACDAT58           _DACDAT5.Overlap_STR.DACDAT5HSTR.Bits.DACDAT58
    #define DACDAT5H_DACDAT59           _DACDAT5.Overlap_STR.DACDAT5HSTR.Bits.DACDAT59
    #define DACDAT5H_DACDAT510          _DACDAT5.Overlap_STR.DACDAT5HSTR.Bits.DACDAT510
    #define DACDAT5H_DACDAT511          _DACDAT5.Overlap_STR.DACDAT5HSTR.Bits.DACDAT511
    #define DACDAT5H_DACDAT_58          _DACDAT5.Overlap_STR.DACDAT5HSTR.MergedBits.grpDACDAT_58
    #define DACDAT5H_DACDAT5_10         _DACDAT5.Overlap_STR.DACDAT5HSTR.MergedBits.grpDACDAT5_10
    #define DACDAT5H_DACDAT             DACDAT5H_DACDAT_58
    #define DACDAT5H_DACDAT5            DACDAT5H_DACDAT5_10
    
    #define DACDAT5H_DACDAT58_MASK      1U
    #define DACDAT5H_DACDAT59_MASK      2U
    #define DACDAT5H_DACDAT510_MASK     4U
    #define DACDAT5H_DACDAT511_MASK     8U
    #define DACDAT5H_DACDAT_58_MASK     3U
    #define DACDAT5H_DACDAT_58_BITNUM   0U
    #define DACDAT5H_DACDAT5_10_MASK    12U
    #define DACDAT5H_DACDAT5_10_BITNUM  2U
    

    /*** DACDAT5L - DAC Data 5 Low Register; 0x0000001B ***/
    union {
      byte Byte;
      struct {
        byte DACDAT50    :1;                                       /* Buffer Data 5 Low, bit 0 */
        byte DACDAT51    :1;                                       /* Buffer Data 5 Low, bit 1 */
        byte DACDAT52    :1;                                       /* Buffer Data 5 Low, bit 2 */
        byte DACDAT53    :1;                                       /* Buffer Data 5 Low, bit 3 */
        byte DACDAT54    :1;                                       /* Buffer Data 5 Low, bit 4 */
        byte DACDAT55    :1;                                       /* Buffer Data 5 Low, bit 5 */
        byte DACDAT56    :1;                                       /* Buffer Data 5 Low, bit 6 */
        byte DACDAT57    :1;                                       /* Buffer Data 5 Low, bit 7 */
      } Bits;
    } DACDAT5LSTR;
    #define DACDAT5L                    _DACDAT5.Overlap_STR.DACDAT5LSTR.Byte
    #define DACDAT5L_DACDAT50           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT50
    #define DACDAT5L_DACDAT51           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT51
    #define DACDAT5L_DACDAT52           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT52
    #define DACDAT5L_DACDAT53           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT53
    #define DACDAT5L_DACDAT54           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT54
    #define DACDAT5L_DACDAT55           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT55
    #define DACDAT5L_DACDAT56           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT56
    #define DACDAT5L_DACDAT57           _DACDAT5.Overlap_STR.DACDAT5LSTR.Bits.DACDAT57
    
    #define DACDAT5L_DACDAT50_MASK      1U
    #define DACDAT5L_DACDAT51_MASK      2U
    #define DACDAT5L_DACDAT52_MASK      4U
    #define DACDAT5L_DACDAT53_MASK      8U
    #define DACDAT5L_DACDAT54_MASK      16U
    #define DACDAT5L_DACDAT55_MASK      32U
    #define DACDAT5L_DACDAT56_MASK      64U
    #define DACDAT5L_DACDAT57_MASK      128U
    
  } Overlap_STR;

} DACDAT5STR;
extern volatile DACDAT5STR _DACDAT5 @0x0000001A;
#define DACDAT5                         _DACDAT5.Word


/*** DACDAT6 - DAC Data 6 Register; 0x0000001C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT6H - DAC Data 6 High Register; 0x0000001C ***/
    union {
      byte Byte;
      struct {
        byte DACDAT68    :1;                                       /* Buffer Data 6 High, bit 8 */
        byte DACDAT69    :1;                                       /* Buffer Data 6 High, bit 9 */
        byte DACDAT610   :1;                                       /* Buffer Data 6 High, bit 10 */
        byte DACDAT611   :1;                                       /* Buffer Data 6 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_68 :2;
        byte grpDACDAT6_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT6HSTR;
    #define DACDAT6H                    _DACDAT6.Overlap_STR.DACDAT6HSTR.Byte
    #define DACDAT6H_DACDAT68           _DACDAT6.Overlap_STR.DACDAT6HSTR.Bits.DACDAT68
    #define DACDAT6H_DACDAT69           _DACDAT6.Overlap_STR.DACDAT6HSTR.Bits.DACDAT69
    #define DACDAT6H_DACDAT610          _DACDAT6.Overlap_STR.DACDAT6HSTR.Bits.DACDAT610
    #define DACDAT6H_DACDAT611          _DACDAT6.Overlap_STR.DACDAT6HSTR.Bits.DACDAT611
    #define DACDAT6H_DACDAT_68          _DACDAT6.Overlap_STR.DACDAT6HSTR.MergedBits.grpDACDAT_68
    #define DACDAT6H_DACDAT6_10         _DACDAT6.Overlap_STR.DACDAT6HSTR.MergedBits.grpDACDAT6_10
    #define DACDAT6H_DACDAT             DACDAT6H_DACDAT_68
    #define DACDAT6H_DACDAT6            DACDAT6H_DACDAT6_10
    
    #define DACDAT6H_DACDAT68_MASK      1U
    #define DACDAT6H_DACDAT69_MASK      2U
    #define DACDAT6H_DACDAT610_MASK     4U
    #define DACDAT6H_DACDAT611_MASK     8U
    #define DACDAT6H_DACDAT_68_MASK     3U
    #define DACDAT6H_DACDAT_68_BITNUM   0U
    #define DACDAT6H_DACDAT6_10_MASK    12U
    #define DACDAT6H_DACDAT6_10_BITNUM  2U
    

    /*** DACDAT6L - DAC Data 6 Low Register; 0x0000001D ***/
    union {
      byte Byte;
      struct {
        byte DACDAT60    :1;                                       /* Buffer Data 6 Low, bit 0 */
        byte DACDAT61    :1;                                       /* Buffer Data 6 Low, bit 1 */
        byte DACDAT62    :1;                                       /* Buffer Data 6 Low, bit 2 */
        byte DACDAT63    :1;                                       /* Buffer Data 6 Low, bit 3 */
        byte DACDAT64    :1;                                       /* Buffer Data 6 Low, bit 4 */
        byte DACDAT65    :1;                                       /* Buffer Data 6 Low, bit 5 */
        byte DACDAT66    :1;                                       /* Buffer Data 6 Low, bit 6 */
        byte DACDAT67    :1;                                       /* Buffer Data 6 Low, bit 7 */
      } Bits;
    } DACDAT6LSTR;
    #define DACDAT6L                    _DACDAT6.Overlap_STR.DACDAT6LSTR.Byte
    #define DACDAT6L_DACDAT60           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT60
    #define DACDAT6L_DACDAT61           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT61
    #define DACDAT6L_DACDAT62           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT62
    #define DACDAT6L_DACDAT63           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT63
    #define DACDAT6L_DACDAT64           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT64
    #define DACDAT6L_DACDAT65           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT65
    #define DACDAT6L_DACDAT66           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT66
    #define DACDAT6L_DACDAT67           _DACDAT6.Overlap_STR.DACDAT6LSTR.Bits.DACDAT67
    
    #define DACDAT6L_DACDAT60_MASK      1U
    #define DACDAT6L_DACDAT61_MASK      2U
    #define DACDAT6L_DACDAT62_MASK      4U
    #define DACDAT6L_DACDAT63_MASK      8U
    #define DACDAT6L_DACDAT64_MASK      16U
    #define DACDAT6L_DACDAT65_MASK      32U
    #define DACDAT6L_DACDAT66_MASK      64U
    #define DACDAT6L_DACDAT67_MASK      128U
    
  } Overlap_STR;

} DACDAT6STR;
extern volatile DACDAT6STR _DACDAT6 @0x0000001C;
#define DACDAT6                         _DACDAT6.Word


/*** DACDAT7 - DAC Data 7 Register; 0x0000001E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT7H - DAC Data 7 High Register; 0x0000001E ***/
    union {
      byte Byte;
      struct {
        byte DACDAT78    :1;                                       /* Buffer Data 7 High, bit 8 */
        byte DACDAT79    :1;                                       /* Buffer Data 7 High, bit 9 */
        byte DACDAT710   :1;                                       /* Buffer Data 7 High, bit 10 */
        byte DACDAT711   :1;                                       /* Buffer Data 7 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_78 :2;
        byte grpDACDAT7_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT7HSTR;
    #define DACDAT7H                    _DACDAT7.Overlap_STR.DACDAT7HSTR.Byte
    #define DACDAT7H_DACDAT78           _DACDAT7.Overlap_STR.DACDAT7HSTR.Bits.DACDAT78
    #define DACDAT7H_DACDAT79           _DACDAT7.Overlap_STR.DACDAT7HSTR.Bits.DACDAT79
    #define DACDAT7H_DACDAT710          _DACDAT7.Overlap_STR.DACDAT7HSTR.Bits.DACDAT710
    #define DACDAT7H_DACDAT711          _DACDAT7.Overlap_STR.DACDAT7HSTR.Bits.DACDAT711
    #define DACDAT7H_DACDAT_78          _DACDAT7.Overlap_STR.DACDAT7HSTR.MergedBits.grpDACDAT_78
    #define DACDAT7H_DACDAT7_10         _DACDAT7.Overlap_STR.DACDAT7HSTR.MergedBits.grpDACDAT7_10
    #define DACDAT7H_DACDAT             DACDAT7H_DACDAT_78
    #define DACDAT7H_DACDAT7            DACDAT7H_DACDAT7_10
    
    #define DACDAT7H_DACDAT78_MASK      1U
    #define DACDAT7H_DACDAT79_MASK      2U
    #define DACDAT7H_DACDAT710_MASK     4U
    #define DACDAT7H_DACDAT711_MASK     8U
    #define DACDAT7H_DACDAT_78_MASK     3U
    #define DACDAT7H_DACDAT_78_BITNUM   0U
    #define DACDAT7H_DACDAT7_10_MASK    12U
    #define DACDAT7H_DACDAT7_10_BITNUM  2U
    

    /*** DACDAT7L - DAC Data 7 Low Register; 0x0000001F ***/
    union {
      byte Byte;
      struct {
        byte DACDAT70    :1;                                       /* Buffer Data 7 Low, bit 0 */
        byte DACDAT71    :1;                                       /* Buffer Data 7 Low, bit 1 */
        byte DACDAT72    :1;                                       /* Buffer Data 7 Low, bit 2 */
        byte DACDAT73    :1;                                       /* Buffer Data 7 Low, bit 3 */
        byte DACDAT74    :1;                                       /* Buffer Data 7 Low, bit 4 */
        byte DACDAT75    :1;                                       /* Buffer Data 7 Low, bit 5 */
        byte DACDAT76    :1;                                       /* Buffer Data 7 Low, bit 6 */
        byte DACDAT77    :1;                                       /* Buffer Data 7 Low, bit 7 */
      } Bits;
    } DACDAT7LSTR;
    #define DACDAT7L                    _DACDAT7.Overlap_STR.DACDAT7LSTR.Byte
    #define DACDAT7L_DACDAT70           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT70
    #define DACDAT7L_DACDAT71           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT71
    #define DACDAT7L_DACDAT72           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT72
    #define DACDAT7L_DACDAT73           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT73
    #define DACDAT7L_DACDAT74           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT74
    #define DACDAT7L_DACDAT75           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT75
    #define DACDAT7L_DACDAT76           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT76
    #define DACDAT7L_DACDAT77           _DACDAT7.Overlap_STR.DACDAT7LSTR.Bits.DACDAT77
    
    #define DACDAT7L_DACDAT70_MASK      1U
    #define DACDAT7L_DACDAT71_MASK      2U
    #define DACDAT7L_DACDAT72_MASK      4U
    #define DACDAT7L_DACDAT73_MASK      8U
    #define DACDAT7L_DACDAT74_MASK      16U
    #define DACDAT7L_DACDAT75_MASK      32U
    #define DACDAT7L_DACDAT76_MASK      64U
    #define DACDAT7L_DACDAT77_MASK      128U
    
  } Overlap_STR;

} DACDAT7STR;
extern volatile DACDAT7STR _DACDAT7 @0x0000001E;
#define DACDAT7                         _DACDAT7.Word


/*** DACDAT8 - DAC Data 8 Register; 0x00000020 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT8H - DAC Data 8 High Register; 0x00000020 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT88    :1;                                       /* Buffer Data 8 High, bit 8 */
        byte DACDAT89    :1;                                       /* Buffer Data 8 High, bit 9 */
        byte DACDAT810   :1;                                       /* Buffer Data 8 High, bit 10 */
        byte DACDAT811   :1;                                       /* Buffer Data 8 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_88 :2;
        byte grpDACDAT8_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT8HSTR;
    #define DACDAT8H                    _DACDAT8.Overlap_STR.DACDAT8HSTR.Byte
    #define DACDAT8H_DACDAT88           _DACDAT8.Overlap_STR.DACDAT8HSTR.Bits.DACDAT88
    #define DACDAT8H_DACDAT89           _DACDAT8.Overlap_STR.DACDAT8HSTR.Bits.DACDAT89
    #define DACDAT8H_DACDAT810          _DACDAT8.Overlap_STR.DACDAT8HSTR.Bits.DACDAT810
    #define DACDAT8H_DACDAT811          _DACDAT8.Overlap_STR.DACDAT8HSTR.Bits.DACDAT811
    #define DACDAT8H_DACDAT_88          _DACDAT8.Overlap_STR.DACDAT8HSTR.MergedBits.grpDACDAT_88
    #define DACDAT8H_DACDAT8_10         _DACDAT8.Overlap_STR.DACDAT8HSTR.MergedBits.grpDACDAT8_10
    #define DACDAT8H_DACDAT             DACDAT8H_DACDAT_88
    #define DACDAT8H_DACDAT8            DACDAT8H_DACDAT8_10
    
    #define DACDAT8H_DACDAT88_MASK      1U
    #define DACDAT8H_DACDAT89_MASK      2U
    #define DACDAT8H_DACDAT810_MASK     4U
    #define DACDAT8H_DACDAT811_MASK     8U
    #define DACDAT8H_DACDAT_88_MASK     3U
    #define DACDAT8H_DACDAT_88_BITNUM   0U
    #define DACDAT8H_DACDAT8_10_MASK    12U
    #define DACDAT8H_DACDAT8_10_BITNUM  2U
    

    /*** DACDAT8L - DAC Data 8 Low Register; 0x00000021 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT80    :1;                                       /* Buffer Data 8 Low, bit 0 */
        byte DACDAT81    :1;                                       /* Buffer Data 8 Low, bit 1 */
        byte DACDAT82    :1;                                       /* Buffer Data 8 Low, bit 2 */
        byte DACDAT83    :1;                                       /* Buffer Data 8 Low, bit 3 */
        byte DACDAT84    :1;                                       /* Buffer Data 8 Low, bit 4 */
        byte DACDAT85    :1;                                       /* Buffer Data 8 Low, bit 5 */
        byte DACDAT86    :1;                                       /* Buffer Data 8 Low, bit 6 */
        byte DACDAT87    :1;                                       /* Buffer Data 8 Low, bit 7 */
      } Bits;
    } DACDAT8LSTR;
    #define DACDAT8L                    _DACDAT8.Overlap_STR.DACDAT8LSTR.Byte
    #define DACDAT8L_DACDAT80           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT80
    #define DACDAT8L_DACDAT81           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT81
    #define DACDAT8L_DACDAT82           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT82
    #define DACDAT8L_DACDAT83           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT83
    #define DACDAT8L_DACDAT84           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT84
    #define DACDAT8L_DACDAT85           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT85
    #define DACDAT8L_DACDAT86           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT86
    #define DACDAT8L_DACDAT87           _DACDAT8.Overlap_STR.DACDAT8LSTR.Bits.DACDAT87
    
    #define DACDAT8L_DACDAT80_MASK      1U
    #define DACDAT8L_DACDAT81_MASK      2U
    #define DACDAT8L_DACDAT82_MASK      4U
    #define DACDAT8L_DACDAT83_MASK      8U
    #define DACDAT8L_DACDAT84_MASK      16U
    #define DACDAT8L_DACDAT85_MASK      32U
    #define DACDAT8L_DACDAT86_MASK      64U
    #define DACDAT8L_DACDAT87_MASK      128U
    
  } Overlap_STR;

} DACDAT8STR;
extern volatile DACDAT8STR _DACDAT8 @0x00000020;
#define DACDAT8                         _DACDAT8.Word


/*** DACDAT9 - DAC Data 9 Register; 0x00000022 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT9H - DAC Data 9 High Register; 0x00000022 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT98    :1;                                       /* Buffer Data 9 High, bit 8 */
        byte DACDAT99    :1;                                       /* Buffer Data 9 High, bit 9 */
        byte DACDAT910   :1;                                       /* Buffer Data 9 High, bit 10 */
        byte DACDAT911   :1;                                       /* Buffer Data 9 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT_98 :2;
        byte     :1;
        byte grpDACDAT9_11 :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT9HSTR;
    #define DACDAT9H                    _DACDAT9.Overlap_STR.DACDAT9HSTR.Byte
    #define DACDAT9H_DACDAT98           _DACDAT9.Overlap_STR.DACDAT9HSTR.Bits.DACDAT98
    #define DACDAT9H_DACDAT99           _DACDAT9.Overlap_STR.DACDAT9HSTR.Bits.DACDAT99
    #define DACDAT9H_DACDAT910          _DACDAT9.Overlap_STR.DACDAT9HSTR.Bits.DACDAT910
    #define DACDAT9H_DACDAT911          _DACDAT9.Overlap_STR.DACDAT9HSTR.Bits.DACDAT911
    #define DACDAT9H_DACDAT_98          _DACDAT9.Overlap_STR.DACDAT9HSTR.MergedBits.grpDACDAT_98
    #define DACDAT9H_DACDAT             DACDAT9H_DACDAT_98
    
    #define DACDAT9H_DACDAT98_MASK      1U
    #define DACDAT9H_DACDAT99_MASK      2U
    #define DACDAT9H_DACDAT910_MASK     4U
    #define DACDAT9H_DACDAT911_MASK     8U
    #define DACDAT9H_DACDAT_98_MASK     3U
    #define DACDAT9H_DACDAT_98_BITNUM   0U
    

    /*** DACDAT9L - DAC Data 9 Low Register; 0x00000023 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT90    :1;                                       /* Buffer Data 9 Low, bit 0 */
        byte DACDAT91    :1;                                       /* Buffer Data 9 Low, bit 1 */
        byte DACDAT92    :1;                                       /* Buffer Data 9 Low, bit 2 */
        byte DACDAT93    :1;                                       /* Buffer Data 9 Low, bit 3 */
        byte DACDAT94    :1;                                       /* Buffer Data 9 Low, bit 4 */
        byte DACDAT95    :1;                                       /* Buffer Data 9 Low, bit 5 */
        byte DACDAT96    :1;                                       /* Buffer Data 9 Low, bit 6 */
        byte DACDAT97    :1;                                       /* Buffer Data 9 Low, bit 7 */
      } Bits;
    } DACDAT9LSTR;
    #define DACDAT9L                    _DACDAT9.Overlap_STR.DACDAT9LSTR.Byte
    #define DACDAT9L_DACDAT90           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT90
    #define DACDAT9L_DACDAT91           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT91
    #define DACDAT9L_DACDAT92           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT92
    #define DACDAT9L_DACDAT93           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT93
    #define DACDAT9L_DACDAT94           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT94
    #define DACDAT9L_DACDAT95           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT95
    #define DACDAT9L_DACDAT96           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT96
    #define DACDAT9L_DACDAT97           _DACDAT9.Overlap_STR.DACDAT9LSTR.Bits.DACDAT97
    
    #define DACDAT9L_DACDAT90_MASK      1U
    #define DACDAT9L_DACDAT91_MASK      2U
    #define DACDAT9L_DACDAT92_MASK      4U
    #define DACDAT9L_DACDAT93_MASK      8U
    #define DACDAT9L_DACDAT94_MASK      16U
    #define DACDAT9L_DACDAT95_MASK      32U
    #define DACDAT9L_DACDAT96_MASK      64U
    #define DACDAT9L_DACDAT97_MASK      128U
    
  } Overlap_STR;

} DACDAT9STR;
extern volatile DACDAT9STR _DACDAT9 @0x00000022;
#define DACDAT9                         _DACDAT9.Word


/*** DACDAT10 - DAC Data 10 Register; 0x00000024 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT10H - DAC Data 10 High Register; 0x00000024 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT108   :1;                                       /* Buffer Data 10 High, bit 8 */
        byte DACDAT109   :1;                                       /* Buffer Data 10 High, bit 9 */
        byte DACDAT1010  :1;                                       /* Buffer Data 10 High, bit 10 */
        byte DACDAT1011  :1;                                       /* Buffer Data 10 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT10_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT10HSTR;
    #define DACDAT10H                   _DACDAT10.Overlap_STR.DACDAT10HSTR.Byte
    #define DACDAT10H_DACDAT108         _DACDAT10.Overlap_STR.DACDAT10HSTR.Bits.DACDAT108
    #define DACDAT10H_DACDAT109         _DACDAT10.Overlap_STR.DACDAT10HSTR.Bits.DACDAT109
    #define DACDAT10H_DACDAT1010        _DACDAT10.Overlap_STR.DACDAT10HSTR.Bits.DACDAT1010
    #define DACDAT10H_DACDAT1011        _DACDAT10.Overlap_STR.DACDAT10HSTR.Bits.DACDAT1011
    #define DACDAT10H_DACDAT10_8        _DACDAT10.Overlap_STR.DACDAT10HSTR.MergedBits.grpDACDAT10_8
    #define DACDAT10H_DACDAT10          DACDAT10H_DACDAT10_8
    
    #define DACDAT10H_DACDAT108_MASK    1U
    #define DACDAT10H_DACDAT109_MASK    2U
    #define DACDAT10H_DACDAT1010_MASK   4U
    #define DACDAT10H_DACDAT1011_MASK   8U
    #define DACDAT10H_DACDAT10_8_MASK   15U
    #define DACDAT10H_DACDAT10_8_BITNUM 0U
    

    /*** DACDAT10L - DAC Data 10 Low Register; 0x00000025 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT100   :1;                                       /* Buffer Data 10 Low, bit 0 */
        byte DACDAT101   :1;                                       /* Buffer Data 10 Low, bit 1 */
        byte DACDAT102   :1;                                       /* Buffer Data 10 Low, bit 2 */
        byte DACDAT103   :1;                                       /* Buffer Data 10 Low, bit 3 */
        byte DACDAT104   :1;                                       /* Buffer Data 10 Low, bit 4 */
        byte DACDAT105   :1;                                       /* Buffer Data 10 Low, bit 5 */
        byte DACDAT106   :1;                                       /* Buffer Data 10 Low, bit 6 */
        byte DACDAT107   :1;                                       /* Buffer Data 10 Low, bit 7 */
      } Bits;
    } DACDAT10LSTR;
    #define DACDAT10L                   _DACDAT10.Overlap_STR.DACDAT10LSTR.Byte
    #define DACDAT10L_DACDAT100         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT100
    #define DACDAT10L_DACDAT101         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT101
    #define DACDAT10L_DACDAT102         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT102
    #define DACDAT10L_DACDAT103         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT103
    #define DACDAT10L_DACDAT104         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT104
    #define DACDAT10L_DACDAT105         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT105
    #define DACDAT10L_DACDAT106         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT106
    #define DACDAT10L_DACDAT107         _DACDAT10.Overlap_STR.DACDAT10LSTR.Bits.DACDAT107
    
    #define DACDAT10L_DACDAT100_MASK    1U
    #define DACDAT10L_DACDAT101_MASK    2U
    #define DACDAT10L_DACDAT102_MASK    4U
    #define DACDAT10L_DACDAT103_MASK    8U
    #define DACDAT10L_DACDAT104_MASK    16U
    #define DACDAT10L_DACDAT105_MASK    32U
    #define DACDAT10L_DACDAT106_MASK    64U
    #define DACDAT10L_DACDAT107_MASK    128U
    
  } Overlap_STR;

} DACDAT10STR;
extern volatile DACDAT10STR _DACDAT10 @0x00000024;
#define DACDAT10                        _DACDAT10.Word


/*** DACDAT11 - DAC Data 11 Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT11H - DAC Data 11 High Register; 0x00000026 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT118   :1;                                       /* Buffer Data 11 High, bit 8 */
        byte DACDAT119   :1;                                       /* Buffer Data 11 High, bit 9 */
        byte DACDAT1110  :1;                                       /* Buffer Data 11 High, bit 10 */
        byte DACDAT1111  :1;                                       /* Buffer Data 11 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT1_18 :2;
        byte grpDACDAT11_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT11HSTR;
    #define DACDAT11H                   _DACDAT11.Overlap_STR.DACDAT11HSTR.Byte
    #define DACDAT11H_DACDAT118         _DACDAT11.Overlap_STR.DACDAT11HSTR.Bits.DACDAT118
    #define DACDAT11H_DACDAT119         _DACDAT11.Overlap_STR.DACDAT11HSTR.Bits.DACDAT119
    #define DACDAT11H_DACDAT1110        _DACDAT11.Overlap_STR.DACDAT11HSTR.Bits.DACDAT1110
    #define DACDAT11H_DACDAT1111        _DACDAT11.Overlap_STR.DACDAT11HSTR.Bits.DACDAT1111
    #define DACDAT11H_DACDAT1_18        _DACDAT11.Overlap_STR.DACDAT11HSTR.MergedBits.grpDACDAT1_18
    #define DACDAT11H_DACDAT11_10       _DACDAT11.Overlap_STR.DACDAT11HSTR.MergedBits.grpDACDAT11_10
    #define DACDAT11H_DACDAT1           DACDAT11H_DACDAT1_18
    #define DACDAT11H_DACDAT11          DACDAT11H_DACDAT11_10
    
    #define DACDAT11H_DACDAT118_MASK    1U
    #define DACDAT11H_DACDAT119_MASK    2U
    #define DACDAT11H_DACDAT1110_MASK   4U
    #define DACDAT11H_DACDAT1111_MASK   8U
    #define DACDAT11H_DACDAT1_18_MASK   3U
    #define DACDAT11H_DACDAT1_18_BITNUM 0U
    #define DACDAT11H_DACDAT11_10_MASK  12U
    #define DACDAT11H_DACDAT11_10_BITNUM 2U
    

    /*** DACDAT11L - DAC Data 11 Low Register; 0x00000027 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT110   :1;                                       /* Buffer Data 11 Low, bit 0 */
        byte DACDAT111   :1;                                       /* Buffer Data 11 Low, bit 1 */
        byte DACDAT112   :1;                                       /* Buffer Data 11 Low, bit 2 */
        byte DACDAT113   :1;                                       /* Buffer Data 11 Low, bit 3 */
        byte DACDAT114   :1;                                       /* Buffer Data 11 Low, bit 4 */
        byte DACDAT115   :1;                                       /* Buffer Data 11 Low, bit 5 */
        byte DACDAT116   :1;                                       /* Buffer Data 11 Low, bit 6 */
        byte DACDAT117   :1;                                       /* Buffer Data 11 Low, bit 7 */
      } Bits;
    } DACDAT11LSTR;
    #define DACDAT11L                   _DACDAT11.Overlap_STR.DACDAT11LSTR.Byte
    #define DACDAT11L_DACDAT110         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT110
    #define DACDAT11L_DACDAT111         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT111
    #define DACDAT11L_DACDAT112         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT112
    #define DACDAT11L_DACDAT113         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT113
    #define DACDAT11L_DACDAT114         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT114
    #define DACDAT11L_DACDAT115         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT115
    #define DACDAT11L_DACDAT116         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT116
    #define DACDAT11L_DACDAT117         _DACDAT11.Overlap_STR.DACDAT11LSTR.Bits.DACDAT117
    
    #define DACDAT11L_DACDAT110_MASK    1U
    #define DACDAT11L_DACDAT111_MASK    2U
    #define DACDAT11L_DACDAT112_MASK    4U
    #define DACDAT11L_DACDAT113_MASK    8U
    #define DACDAT11L_DACDAT114_MASK    16U
    #define DACDAT11L_DACDAT115_MASK    32U
    #define DACDAT11L_DACDAT116_MASK    64U
    #define DACDAT11L_DACDAT117_MASK    128U
    
  } Overlap_STR;

} DACDAT11STR;
extern volatile DACDAT11STR _DACDAT11 @0x00000026;
#define DACDAT11                        _DACDAT11.Word


/*** DACDAT12 - DAC Data 12 Register; 0x00000028 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT12H - DAC Data 12 High Register; 0x00000028 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT128   :1;                                       /* Buffer Data 12 High, bit 8 */
        byte DACDAT129   :1;                                       /* Buffer Data 12 High, bit 9 */
        byte DACDAT1210  :1;                                       /* Buffer Data 12 High, bit 10 */
        byte DACDAT1211  :1;                                       /* Buffer Data 12 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT1_28 :2;
        byte grpDACDAT12_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT12HSTR;
    #define DACDAT12H                   _DACDAT12.Overlap_STR.DACDAT12HSTR.Byte
    #define DACDAT12H_DACDAT128         _DACDAT12.Overlap_STR.DACDAT12HSTR.Bits.DACDAT128
    #define DACDAT12H_DACDAT129         _DACDAT12.Overlap_STR.DACDAT12HSTR.Bits.DACDAT129
    #define DACDAT12H_DACDAT1210        _DACDAT12.Overlap_STR.DACDAT12HSTR.Bits.DACDAT1210
    #define DACDAT12H_DACDAT1211        _DACDAT12.Overlap_STR.DACDAT12HSTR.Bits.DACDAT1211
    #define DACDAT12H_DACDAT1_28        _DACDAT12.Overlap_STR.DACDAT12HSTR.MergedBits.grpDACDAT1_28
    #define DACDAT12H_DACDAT12_10       _DACDAT12.Overlap_STR.DACDAT12HSTR.MergedBits.grpDACDAT12_10
    #define DACDAT12H_DACDAT1           DACDAT12H_DACDAT1_28
    #define DACDAT12H_DACDAT12          DACDAT12H_DACDAT12_10
    
    #define DACDAT12H_DACDAT128_MASK    1U
    #define DACDAT12H_DACDAT129_MASK    2U
    #define DACDAT12H_DACDAT1210_MASK   4U
    #define DACDAT12H_DACDAT1211_MASK   8U
    #define DACDAT12H_DACDAT1_28_MASK   3U
    #define DACDAT12H_DACDAT1_28_BITNUM 0U
    #define DACDAT12H_DACDAT12_10_MASK  12U
    #define DACDAT12H_DACDAT12_10_BITNUM 2U
    

    /*** DACDAT12L - DAC Data 12 Low Register; 0x00000029 ***/
    union {
      byte Byte;
      struct {
        byte DACDAT120   :1;                                       /* Buffer Data 12 Low, bit 0 */
        byte DACDAT121   :1;                                       /* Buffer Data 12 Low, bit 1 */
        byte DACDAT122   :1;                                       /* Buffer Data 12 Low, bit 2 */
        byte DACDAT123   :1;                                       /* Buffer Data 12 Low, bit 3 */
        byte DACDAT124   :1;                                       /* Buffer Data 12 Low, bit 4 */
        byte DACDAT125   :1;                                       /* Buffer Data 12 Low, bit 5 */
        byte DACDAT126   :1;                                       /* Buffer Data 12 Low, bit 6 */
        byte DACDAT127   :1;                                       /* Buffer Data 12 Low, bit 7 */
      } Bits;
    } DACDAT12LSTR;
    #define DACDAT12L                   _DACDAT12.Overlap_STR.DACDAT12LSTR.Byte
    #define DACDAT12L_DACDAT120         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT120
    #define DACDAT12L_DACDAT121         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT121
    #define DACDAT12L_DACDAT122         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT122
    #define DACDAT12L_DACDAT123         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT123
    #define DACDAT12L_DACDAT124         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT124
    #define DACDAT12L_DACDAT125         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT125
    #define DACDAT12L_DACDAT126         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT126
    #define DACDAT12L_DACDAT127         _DACDAT12.Overlap_STR.DACDAT12LSTR.Bits.DACDAT127
    
    #define DACDAT12L_DACDAT120_MASK    1U
    #define DACDAT12L_DACDAT121_MASK    2U
    #define DACDAT12L_DACDAT122_MASK    4U
    #define DACDAT12L_DACDAT123_MASK    8U
    #define DACDAT12L_DACDAT124_MASK    16U
    #define DACDAT12L_DACDAT125_MASK    32U
    #define DACDAT12L_DACDAT126_MASK    64U
    #define DACDAT12L_DACDAT127_MASK    128U
    
  } Overlap_STR;

} DACDAT12STR;
extern volatile DACDAT12STR _DACDAT12 @0x00000028;
#define DACDAT12                        _DACDAT12.Word


/*** DACDAT13 - DAC Data 13 Register; 0x0000002A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT13H - DAC Data 13 High Register; 0x0000002A ***/
    union {
      byte Byte;
      struct {
        byte DACDAT138   :1;                                       /* Buffer Data 13 High, bit 8 */
        byte DACDAT139   :1;                                       /* Buffer Data 13 High, bit 9 */
        byte DACDAT1310  :1;                                       /* Buffer Data 13 High, bit 10 */
        byte DACDAT1311  :1;                                       /* Buffer Data 13 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT1_38 :2;
        byte grpDACDAT13_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT13HSTR;
    #define DACDAT13H                   _DACDAT13.Overlap_STR.DACDAT13HSTR.Byte
    #define DACDAT13H_DACDAT138         _DACDAT13.Overlap_STR.DACDAT13HSTR.Bits.DACDAT138
    #define DACDAT13H_DACDAT139         _DACDAT13.Overlap_STR.DACDAT13HSTR.Bits.DACDAT139
    #define DACDAT13H_DACDAT1310        _DACDAT13.Overlap_STR.DACDAT13HSTR.Bits.DACDAT1310
    #define DACDAT13H_DACDAT1311        _DACDAT13.Overlap_STR.DACDAT13HSTR.Bits.DACDAT1311
    #define DACDAT13H_DACDAT1_38        _DACDAT13.Overlap_STR.DACDAT13HSTR.MergedBits.grpDACDAT1_38
    #define DACDAT13H_DACDAT13_10       _DACDAT13.Overlap_STR.DACDAT13HSTR.MergedBits.grpDACDAT13_10
    #define DACDAT13H_DACDAT1           DACDAT13H_DACDAT1_38
    #define DACDAT13H_DACDAT13          DACDAT13H_DACDAT13_10
    
    #define DACDAT13H_DACDAT138_MASK    1U
    #define DACDAT13H_DACDAT139_MASK    2U
    #define DACDAT13H_DACDAT1310_MASK   4U
    #define DACDAT13H_DACDAT1311_MASK   8U
    #define DACDAT13H_DACDAT1_38_MASK   3U
    #define DACDAT13H_DACDAT1_38_BITNUM 0U
    #define DACDAT13H_DACDAT13_10_MASK  12U
    #define DACDAT13H_DACDAT13_10_BITNUM 2U
    

    /*** DACDAT13L - DAC Data 13 Low Register; 0x0000002B ***/
    union {
      byte Byte;
      struct {
        byte DACDAT130   :1;                                       /* Buffer Data 13 Low, bit 0 */
        byte DACDAT131   :1;                                       /* Buffer Data 13 Low, bit 1 */
        byte DACDAT132   :1;                                       /* Buffer Data 13 Low, bit 2 */
        byte DACDAT133   :1;                                       /* Buffer Data 13 Low, bit 3 */
        byte DACDAT134   :1;                                       /* Buffer Data 13 Low, bit 4 */
        byte DACDAT135   :1;                                       /* Buffer Data 13 Low, bit 5 */
        byte DACDAT136   :1;                                       /* Buffer Data 13 Low, bit 6 */
        byte DACDAT137   :1;                                       /* Buffer Data 13 Low, bit 7 */
      } Bits;
    } DACDAT13LSTR;
    #define DACDAT13L                   _DACDAT13.Overlap_STR.DACDAT13LSTR.Byte
    #define DACDAT13L_DACDAT130         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT130
    #define DACDAT13L_DACDAT131         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT131
    #define DACDAT13L_DACDAT132         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT132
    #define DACDAT13L_DACDAT133         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT133
    #define DACDAT13L_DACDAT134         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT134
    #define DACDAT13L_DACDAT135         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT135
    #define DACDAT13L_DACDAT136         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT136
    #define DACDAT13L_DACDAT137         _DACDAT13.Overlap_STR.DACDAT13LSTR.Bits.DACDAT137
    
    #define DACDAT13L_DACDAT130_MASK    1U
    #define DACDAT13L_DACDAT131_MASK    2U
    #define DACDAT13L_DACDAT132_MASK    4U
    #define DACDAT13L_DACDAT133_MASK    8U
    #define DACDAT13L_DACDAT134_MASK    16U
    #define DACDAT13L_DACDAT135_MASK    32U
    #define DACDAT13L_DACDAT136_MASK    64U
    #define DACDAT13L_DACDAT137_MASK    128U
    
  } Overlap_STR;

} DACDAT13STR;
extern volatile DACDAT13STR _DACDAT13 @0x0000002A;
#define DACDAT13                        _DACDAT13.Word


/*** DACDAT14 - DAC Data 14 Register; 0x0000002C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT14H - DAC Data 14 High Register; 0x0000002C ***/
    union {
      byte Byte;
      struct {
        byte DACDAT148   :1;                                       /* Buffer Data 14 High, bit 8 */
        byte DACDAT149   :1;                                       /* Buffer Data 14 High, bit 9 */
        byte DACDAT1410  :1;                                       /* Buffer Data 14 High, bit 10 */
        byte DACDAT1411  :1;                                       /* Buffer Data 14 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT1_48 :2;
        byte grpDACDAT14_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT14HSTR;
    #define DACDAT14H                   _DACDAT14.Overlap_STR.DACDAT14HSTR.Byte
    #define DACDAT14H_DACDAT148         _DACDAT14.Overlap_STR.DACDAT14HSTR.Bits.DACDAT148
    #define DACDAT14H_DACDAT149         _DACDAT14.Overlap_STR.DACDAT14HSTR.Bits.DACDAT149
    #define DACDAT14H_DACDAT1410        _DACDAT14.Overlap_STR.DACDAT14HSTR.Bits.DACDAT1410
    #define DACDAT14H_DACDAT1411        _DACDAT14.Overlap_STR.DACDAT14HSTR.Bits.DACDAT1411
    #define DACDAT14H_DACDAT1_48        _DACDAT14.Overlap_STR.DACDAT14HSTR.MergedBits.grpDACDAT1_48
    #define DACDAT14H_DACDAT14_10       _DACDAT14.Overlap_STR.DACDAT14HSTR.MergedBits.grpDACDAT14_10
    #define DACDAT14H_DACDAT1           DACDAT14H_DACDAT1_48
    #define DACDAT14H_DACDAT14          DACDAT14H_DACDAT14_10
    
    #define DACDAT14H_DACDAT148_MASK    1U
    #define DACDAT14H_DACDAT149_MASK    2U
    #define DACDAT14H_DACDAT1410_MASK   4U
    #define DACDAT14H_DACDAT1411_MASK   8U
    #define DACDAT14H_DACDAT1_48_MASK   3U
    #define DACDAT14H_DACDAT1_48_BITNUM 0U
    #define DACDAT14H_DACDAT14_10_MASK  12U
    #define DACDAT14H_DACDAT14_10_BITNUM 2U
    

    /*** DACDAT14L - DAC Data 14 Low Register; 0x0000002D ***/
    union {
      byte Byte;
      struct {
        byte DACDAT140   :1;                                       /* Buffer Data 14 Low, bit 0 */
        byte DACDAT141   :1;                                       /* Buffer Data 14 Low, bit 1 */
        byte DACDAT142   :1;                                       /* Buffer Data 14 Low, bit 2 */
        byte DACDAT143   :1;                                       /* Buffer Data 14 Low, bit 3 */
        byte DACDAT144   :1;                                       /* Buffer Data 14 Low, bit 4 */
        byte DACDAT145   :1;                                       /* Buffer Data 14 Low, bit 5 */
        byte DACDAT146   :1;                                       /* Buffer Data 14 Low, bit 6 */
        byte DACDAT147   :1;                                       /* Buffer Data 14 Low, bit 7 */
      } Bits;
    } DACDAT14LSTR;
    #define DACDAT14L                   _DACDAT14.Overlap_STR.DACDAT14LSTR.Byte
    #define DACDAT14L_DACDAT140         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT140
    #define DACDAT14L_DACDAT141         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT141
    #define DACDAT14L_DACDAT142         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT142
    #define DACDAT14L_DACDAT143         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT143
    #define DACDAT14L_DACDAT144         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT144
    #define DACDAT14L_DACDAT145         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT145
    #define DACDAT14L_DACDAT146         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT146
    #define DACDAT14L_DACDAT147         _DACDAT14.Overlap_STR.DACDAT14LSTR.Bits.DACDAT147
    
    #define DACDAT14L_DACDAT140_MASK    1U
    #define DACDAT14L_DACDAT141_MASK    2U
    #define DACDAT14L_DACDAT142_MASK    4U
    #define DACDAT14L_DACDAT143_MASK    8U
    #define DACDAT14L_DACDAT144_MASK    16U
    #define DACDAT14L_DACDAT145_MASK    32U
    #define DACDAT14L_DACDAT146_MASK    64U
    #define DACDAT14L_DACDAT147_MASK    128U
    
  } Overlap_STR;

} DACDAT14STR;
extern volatile DACDAT14STR _DACDAT14 @0x0000002C;
#define DACDAT14                        _DACDAT14.Word


/*** DACDAT15 - DAC Data 15 Register; 0x0000002E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACDAT15H - DAC Data 15 High Register; 0x0000002E ***/
    union {
      byte Byte;
      struct {
        byte DACDAT158   :1;                                       /* Buffer Data 15 High, bit 8 */
        byte DACDAT159   :1;                                       /* Buffer Data 15 High, bit 9 */
        byte DACDAT1510  :1;                                       /* Buffer Data 15 High, bit 10 */
        byte DACDAT1511  :1;                                       /* Buffer Data 15 High, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDACDAT1_58 :2;
        byte grpDACDAT15_10 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DACDAT15HSTR;
    #define DACDAT15H                   _DACDAT15.Overlap_STR.DACDAT15HSTR.Byte
    #define DACDAT15H_DACDAT158         _DACDAT15.Overlap_STR.DACDAT15HSTR.Bits.DACDAT158
    #define DACDAT15H_DACDAT159         _DACDAT15.Overlap_STR.DACDAT15HSTR.Bits.DACDAT159
    #define DACDAT15H_DACDAT1510        _DACDAT15.Overlap_STR.DACDAT15HSTR.Bits.DACDAT1510
    #define DACDAT15H_DACDAT1511        _DACDAT15.Overlap_STR.DACDAT15HSTR.Bits.DACDAT1511
    #define DACDAT15H_DACDAT1_58        _DACDAT15.Overlap_STR.DACDAT15HSTR.MergedBits.grpDACDAT1_58
    #define DACDAT15H_DACDAT15_10       _DACDAT15.Overlap_STR.DACDAT15HSTR.MergedBits.grpDACDAT15_10
    #define DACDAT15H_DACDAT1           DACDAT15H_DACDAT1_58
    #define DACDAT15H_DACDAT15          DACDAT15H_DACDAT15_10
    
    #define DACDAT15H_DACDAT158_MASK    1U
    #define DACDAT15H_DACDAT159_MASK    2U
    #define DACDAT15H_DACDAT1510_MASK   4U
    #define DACDAT15H_DACDAT1511_MASK   8U
    #define DACDAT15H_DACDAT1_58_MASK   3U
    #define DACDAT15H_DACDAT1_58_BITNUM 0U
    #define DACDAT15H_DACDAT15_10_MASK  12U
    #define DACDAT15H_DACDAT15_10_BITNUM 2U
    

    /*** DACDAT15L - DAC Data 15 Low Register; 0x0000002F ***/
    union {
      byte Byte;
      struct {
        byte DACDAT150   :1;                                       /* Buffer Data 15 Low, bit 0 */
        byte DACDAT151   :1;                                       /* Buffer Data 15 Low, bit 1 */
        byte DACDAT152   :1;                                       /* Buffer Data 15 Low, bit 2 */
        byte DACDAT153   :1;                                       /* Buffer Data 15 Low, bit 3 */
        byte DACDAT154   :1;                                       /* Buffer Data 15 Low, bit 4 */
        byte DACDAT155   :1;                                       /* Buffer Data 15 Low, bit 5 */
        byte DACDAT156   :1;                                       /* Buffer Data 15 Low, bit 6 */
        byte DACDAT157   :1;                                       /* Buffer Data 15 Low, bit 7 */
      } Bits;
    } DACDAT15LSTR;
    #define DACDAT15L                   _DACDAT15.Overlap_STR.DACDAT15LSTR.Byte
    #define DACDAT15L_DACDAT150         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT150
    #define DACDAT15L_DACDAT151         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT151
    #define DACDAT15L_DACDAT152         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT152
    #define DACDAT15L_DACDAT153         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT153
    #define DACDAT15L_DACDAT154         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT154
    #define DACDAT15L_DACDAT155         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT155
    #define DACDAT15L_DACDAT156         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT156
    #define DACDAT15L_DACDAT157         _DACDAT15.Overlap_STR.DACDAT15LSTR.Bits.DACDAT157
    
    #define DACDAT15L_DACDAT150_MASK    1U
    #define DACDAT15L_DACDAT151_MASK    2U
    #define DACDAT15L_DACDAT152_MASK    4U
    #define DACDAT15L_DACDAT153_MASK    8U
    #define DACDAT15L_DACDAT154_MASK    16U
    #define DACDAT15L_DACDAT155_MASK    32U
    #define DACDAT15L_DACDAT156_MASK    64U
    #define DACDAT15L_DACDAT157_MASK    128U
    
  } Overlap_STR;

} DACDAT15STR;
extern volatile DACDAT15STR _DACDAT15 @0x0000002E;
#define DACDAT15                        _DACDAT15.Word


/*** DACS - DAC Status Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte DACRPB      :1;                                       /* DAC buffer read pointer bottom position flag */
    byte DACRPT      :1;                                       /* DAC buffer read pointer top position flag */
    byte DACWM       :1;                                       /* DAC buffer watermark flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DACSSTR;
extern volatile DACSSTR _DACS @0x00000030;
#define DACS                            _DACS.Byte
#define DACS_DACRPB                     _DACS.Bits.DACRPB
#define DACS_DACRPT                     _DACS.Bits.DACRPT
#define DACS_DACWM                      _DACS.Bits.DACWM

#define DACS_DACRPB_MASK                1U
#define DACS_DACRPT_MASK                2U
#define DACS_DACWM_MASK                 4U


/*** DACC0 - DAC Control 0 Register; 0x00000031 ***/
typedef union {
  byte Byte;
  struct {
    byte DACBIE      :1;                                       /* DAC buffer read pointer bottom flag interrupt enable */
    byte DACTIE      :1;                                       /* DAC buffer read pointer top flag interrupt enable */
    byte DACWIE      :1;                                       /* DAC buffer watermark interrupt enable */
    byte LPEN        :1;                                       /* DAC low power control */
    byte DACSTRG     :1;                                       /* DAC software trigger - active high */
    byte DACTSEL     :1;                                       /* DAC trigger select */
    byte DACRFS      :1;                                       /* DAC Reference Select */
    byte DACEN       :1;                                       /* DAC enable - The DACEN bit starts the Programmable Reference Generator operation */
  } Bits;
} DACC0STR;
extern volatile DACC0STR _DACC0 @0x00000031;
#define DACC0                           _DACC0.Byte
#define DACC0_DACBIE                    _DACC0.Bits.DACBIE
#define DACC0_DACTIE                    _DACC0.Bits.DACTIE
#define DACC0_DACWIE                    _DACC0.Bits.DACWIE
#define DACC0_LPEN                      _DACC0.Bits.LPEN
#define DACC0_DACSTRG                   _DACC0.Bits.DACSTRG
#define DACC0_DACTSEL                   _DACC0.Bits.DACTSEL
#define DACC0_DACRFS                    _DACC0.Bits.DACRFS
#define DACC0_DACEN                     _DACC0.Bits.DACEN
/* DACC_ARR: Access 3 DACCx registers in an array */
#define DACC_ARR                        ((volatile byte * __far) &DACC0)

#define DACC0_DACBIE_MASK               1U
#define DACC0_DACTIE_MASK               2U
#define DACC0_DACWIE_MASK               4U
#define DACC0_LPEN_MASK                 8U
#define DACC0_DACSTRG_MASK              16U
#define DACC0_DACTSEL_MASK              32U
#define DACC0_DACRFS_MASK               64U
#define DACC0_DACEN_MASK                128U


/*** DACC1 - DAC Control 1 Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte DACBFE      :1;                                       /* DAC Buffer Enable */
    byte DACBFMD0    :1;                                       /* DAC Buffer Work Mode Select, bit 0 */
    byte DACBFMD1    :1;                                       /* DAC Buffer Work Mode Select, bit 1 */
    byte DACBFWM0    :1;                                       /* DAC Buffer Watermark Select, bit 0 */
    byte DACBFWM1    :1;                                       /* DAC Buffer Watermark Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpDACBFMD :2;
    byte grpDACBFWM :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DACC1STR;
extern volatile DACC1STR _DACC1 @0x00000032;
#define DACC1                           _DACC1.Byte
#define DACC1_DACBFE                    _DACC1.Bits.DACBFE
#define DACC1_DACBFMD0                  _DACC1.Bits.DACBFMD0
#define DACC1_DACBFMD1                  _DACC1.Bits.DACBFMD1
#define DACC1_DACBFWM0                  _DACC1.Bits.DACBFWM0
#define DACC1_DACBFWM1                  _DACC1.Bits.DACBFWM1
#define DACC1_DACBFMD                   _DACC1.MergedBits.grpDACBFMD
#define DACC1_DACBFWM                   _DACC1.MergedBits.grpDACBFWM

#define DACC1_DACBFE_MASK               1U
#define DACC1_DACBFMD0_MASK             2U
#define DACC1_DACBFMD1_MASK             4U
#define DACC1_DACBFWM0_MASK             8U
#define DACC1_DACBFWM1_MASK             16U
#define DACC1_DACBFMD_MASK              6U
#define DACC1_DACBFMD_BITNUM            1U
#define DACC1_DACBFWM_MASK              24U
#define DACC1_DACBFWM_BITNUM            3U


/*** DACC2 - DAC Control 2 Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte DACBFUP     :4;                                       /* DAC Buffer Upper Limit */
    byte DACBFRP     :4;                                       /* DAC Buffer Read Pointer */
  } Bits;
} DACC2STR;
extern volatile DACC2STR _DACC2 @0x00000033;
#define DACC2                           _DACC2.Byte
#define DACC2_DACBFUP                   _DACC2.Bits.DACBFUP
#define DACC2_DACBFRP                   _DACC2.Bits.DACBFRP

#define DACC2_DACBFUP_MASK              15U
#define DACC2_DACBFUP_BITNUM            0U
#define DACC2_DACBFRP_MASK              240U
#define DACC2_DACBFRP_BITNUM            4U


/*** PRACMPCS - PRACMP Control and Status Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIEN       :1;                                       /* ACMP Interrupt Enable */
    byte ACINTS0     :1;                                       /* ACMP Interrupt Select, bit 0 */
    byte ACINTS1     :1;                                       /* ACMP Interrupt Select, bit 1 */
    byte ACMPO       :1;                                       /* ACMP Output Bit */
    byte ACOPE       :1;                                       /* ACMP Output Pin Enable */
    byte             :1; 
    byte ACMPF       :1;                                       /* ACMP Interrupt Flag */
    byte ACEN        :1;                                       /* ACMP Module Enable */
  } Bits;
  struct {
    byte         :1;
    byte grpACINTS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PRACMPCSSTR;
extern volatile PRACMPCSSTR _PRACMPCS @0x00000034;
#define PRACMPCS                        _PRACMPCS.Byte
#define PRACMPCS_ACIEN                  _PRACMPCS.Bits.ACIEN
#define PRACMPCS_ACINTS0                _PRACMPCS.Bits.ACINTS0
#define PRACMPCS_ACINTS1                _PRACMPCS.Bits.ACINTS1
#define PRACMPCS_ACMPO                  _PRACMPCS.Bits.ACMPO
#define PRACMPCS_ACOPE                  _PRACMPCS.Bits.ACOPE
#define PRACMPCS_ACMPF                  _PRACMPCS.Bits.ACMPF
#define PRACMPCS_ACEN                   _PRACMPCS.Bits.ACEN
#define PRACMPCS_ACINTS                 _PRACMPCS.MergedBits.grpACINTS

#define PRACMPCS_ACIEN_MASK             1U
#define PRACMPCS_ACINTS0_MASK           2U
#define PRACMPCS_ACINTS1_MASK           4U
#define PRACMPCS_ACMPO_MASK             8U
#define PRACMPCS_ACOPE_MASK             16U
#define PRACMPCS_ACMPF_MASK             64U
#define PRACMPCS_ACEN_MASK              128U
#define PRACMPCS_ACINTS_MASK            6U
#define PRACMPCS_ACINTS_BITNUM          1U


/*** PRACMPC0 - PRACMP Control 0 Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte ACNSEL0     :1;                                       /* ACMP Negative Input Select, bit 0 */
    byte ACNSEL1     :1;                                       /* ACMP Negative Input Select, bit 1 */
    byte ACNSEL2     :1;                                       /* ACMP Negative Input Select, bit 2 */
    byte             :1; 
    byte ACPSEL0     :1;                                       /* ACMP Positive Input Select, bit 0 */
    byte ACPSEL1     :1;                                       /* ACMP Positive Input Select, bit 1 */
    byte ACPSEL2     :1;                                       /* ACMP Positive Input Select, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpACNSEL :3;
    byte         :1;
    byte grpACPSEL :3;
    byte         :1;
  } MergedBits;
} PRACMPC0STR;
extern volatile PRACMPC0STR _PRACMPC0 @0x00000035;
#define PRACMPC0                        _PRACMPC0.Byte
#define PRACMPC0_ACNSEL0                _PRACMPC0.Bits.ACNSEL0
#define PRACMPC0_ACNSEL1                _PRACMPC0.Bits.ACNSEL1
#define PRACMPC0_ACNSEL2                _PRACMPC0.Bits.ACNSEL2
#define PRACMPC0_ACPSEL0                _PRACMPC0.Bits.ACPSEL0
#define PRACMPC0_ACPSEL1                _PRACMPC0.Bits.ACPSEL1
#define PRACMPC0_ACPSEL2                _PRACMPC0.Bits.ACPSEL2
/* PRACMPC_ARR: Access 3 PRACMPCx registers in an array */
#define PRACMPC_ARR                     ((volatile byte * __far) &PRACMPC0)
#define PRACMPC0_ACNSEL                 _PRACMPC0.MergedBits.grpACNSEL
#define PRACMPC0_ACPSEL                 _PRACMPC0.MergedBits.grpACPSEL

#define PRACMPC0_ACNSEL0_MASK           1U
#define PRACMPC0_ACNSEL1_MASK           2U
#define PRACMPC0_ACNSEL2_MASK           4U
#define PRACMPC0_ACPSEL0_MASK           16U
#define PRACMPC0_ACPSEL1_MASK           32U
#define PRACMPC0_ACPSEL2_MASK           64U
#define PRACMPC0_ACNSEL_MASK            7U
#define PRACMPC0_ACNSEL_BITNUM          0U
#define PRACMPC0_ACPSEL_MASK            112U
#define PRACMPC0_ACPSEL_BITNUM          4U


/*** PRACMPC1 - PRACMP Control 1 Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte PRGOS0      :1;                                       /* Programmable Reference Generator Output Selection, bit 0 */
    byte PRGOS1      :1;                                       /* Programmable Reference Generator Output Selection, bit 1 */
    byte PRGOS2      :1;                                       /* Programmable Reference Generator Output Selection, bit 2 */
    byte PRGOS3      :1;                                       /* Programmable Reference Generator Output Selection, bit 3 */
    byte PRGOS4      :1;                                       /* Programmable Reference Generator Output Selection, bit 4 */
    byte             :1; 
    byte PRGINS      :1;                                       /* Programmable Reference Generator Input Selection */
    byte PRGEN       :1;                                       /* Programmable Reference Generator Enable */
  } Bits;
  struct {
    byte grpPRGOS :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PRACMPC1STR;
extern volatile PRACMPC1STR _PRACMPC1 @0x00000036;
#define PRACMPC1                        _PRACMPC1.Byte
#define PRACMPC1_PRGOS0                 _PRACMPC1.Bits.PRGOS0
#define PRACMPC1_PRGOS1                 _PRACMPC1.Bits.PRGOS1
#define PRACMPC1_PRGOS2                 _PRACMPC1.Bits.PRGOS2
#define PRACMPC1_PRGOS3                 _PRACMPC1.Bits.PRGOS3
#define PRACMPC1_PRGOS4                 _PRACMPC1.Bits.PRGOS4
#define PRACMPC1_PRGINS                 _PRACMPC1.Bits.PRGINS
#define PRACMPC1_PRGEN                  _PRACMPC1.Bits.PRGEN
#define PRACMPC1_PRGOS                  _PRACMPC1.MergedBits.grpPRGOS

#define PRACMPC1_PRGOS0_MASK            1U
#define PRACMPC1_PRGOS1_MASK            2U
#define PRACMPC1_PRGOS2_MASK            4U
#define PRACMPC1_PRGOS3_MASK            8U
#define PRACMPC1_PRGOS4_MASK            16U
#define PRACMPC1_PRGINS_MASK            64U
#define PRACMPC1_PRGEN_MASK             128U
#define PRACMPC1_PRGOS_MASK             31U
#define PRACMPC1_PRGOS_BITNUM           0U


/*** PRACMPC2 - PRACMP Control 2 Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIPE0      :1;                                       /* ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0 as analog input */
    byte ACIPE1      :1;                                       /* ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1 as analog input */
    byte ACIPE2      :1;                                       /* ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2 as analog input */
    byte ACIPE3      :1;                                       /* ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3 as analog input */
    byte ACIPE4      :1;                                       /* ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4 as analog input */
    byte ACIPE5      :1;                                       /* ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5 as analog input */
    byte ACIPE6      :1;                                       /* ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6 as analog input */
    byte             :1; 
  } Bits;
  struct {
    byte grpACIPE :7;
    byte         :1;
  } MergedBits;
} PRACMPC2STR;
extern volatile PRACMPC2STR _PRACMPC2 @0x00000037;
#define PRACMPC2                        _PRACMPC2.Byte
#define PRACMPC2_ACIPE0                 _PRACMPC2.Bits.ACIPE0
#define PRACMPC2_ACIPE1                 _PRACMPC2.Bits.ACIPE1
#define PRACMPC2_ACIPE2                 _PRACMPC2.Bits.ACIPE2
#define PRACMPC2_ACIPE3                 _PRACMPC2.Bits.ACIPE3
#define PRACMPC2_ACIPE4                 _PRACMPC2.Bits.ACIPE4
#define PRACMPC2_ACIPE5                 _PRACMPC2.Bits.ACIPE5
#define PRACMPC2_ACIPE6                 _PRACMPC2.Bits.ACIPE6
#define PRACMPC2_ACIPE                  _PRACMPC2.MergedBits.grpACIPE

#define PRACMPC2_ACIPE0_MASK            1U
#define PRACMPC2_ACIPE1_MASK            2U
#define PRACMPC2_ACIPE2_MASK            4U
#define PRACMPC2_ACIPE3_MASK            8U
#define PRACMPC2_ACIPE4_MASK            16U
#define PRACMPC2_ACIPE5_MASK            32U
#define PRACMPC2_ACIPE6_MASK            64U
#define PRACMPC2_ACIPE_MASK             127U
#define PRACMPC2_ACIPE_BITNUM           0U


/*** MCGC1 - MCG Control Register 1; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} MCGC1STR;
extern volatile MCGC1STR _MCGC1 @0x00000038;
#define MCGC1                           _MCGC1.Byte
#define MCGC1_IREFSTEN                  _MCGC1.Bits.IREFSTEN
#define MCGC1_IRCLKEN                   _MCGC1.Bits.IRCLKEN
#define MCGC1_IREFS                     _MCGC1.Bits.IREFS
#define MCGC1_RDIV0                     _MCGC1.Bits.RDIV0
#define MCGC1_RDIV1                     _MCGC1.Bits.RDIV1
#define MCGC1_RDIV2                     _MCGC1.Bits.RDIV2
#define MCGC1_CLKS0                     _MCGC1.Bits.CLKS0
#define MCGC1_CLKS1                     _MCGC1.Bits.CLKS1
#define MCGC1_RDIV                      _MCGC1.MergedBits.grpRDIV
#define MCGC1_CLKS                      _MCGC1.MergedBits.grpCLKS

#define MCGC1_IREFSTEN_MASK             1U
#define MCGC1_IRCLKEN_MASK              2U
#define MCGC1_IREFS_MASK                4U
#define MCGC1_RDIV0_MASK                8U
#define MCGC1_RDIV1_MASK                16U
#define MCGC1_RDIV2_MASK                32U
#define MCGC1_CLKS0_MASK                64U
#define MCGC1_CLKS1_MASK                128U
#define MCGC1_RDIV_MASK                 56U
#define MCGC1_RDIV_BITNUM               3U
#define MCGC1_CLKS_MASK                 192U
#define MCGC1_CLKS_BITNUM               6U


/*** MCGC2 - MCG Control Register 2; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} MCGC2STR;
extern volatile MCGC2STR _MCGC2 @0x00000039;
#define MCGC2                           _MCGC2.Byte
#define MCGC2_EREFSTEN                  _MCGC2.Bits.EREFSTEN
#define MCGC2_ERCLKEN                   _MCGC2.Bits.ERCLKEN
#define MCGC2_EREFS                     _MCGC2.Bits.EREFS
#define MCGC2_LP                        _MCGC2.Bits.LP
#define MCGC2_HGO                       _MCGC2.Bits.HGO
#define MCGC2_RANGE                     _MCGC2.Bits.RANGE
#define MCGC2_BDIV0                     _MCGC2.Bits.BDIV0
#define MCGC2_BDIV1                     _MCGC2.Bits.BDIV1
#define MCGC2_BDIV                      _MCGC2.MergedBits.grpBDIV

#define MCGC2_EREFSTEN_MASK             1U
#define MCGC2_ERCLKEN_MASK              2U
#define MCGC2_EREFS_MASK                4U
#define MCGC2_LP_MASK                   8U
#define MCGC2_HGO_MASK                  16U
#define MCGC2_RANGE_MASK                32U
#define MCGC2_BDIV0_MASK                64U
#define MCGC2_BDIV1_MASK                128U
#define MCGC2_BDIV_MASK                 192U
#define MCGC2_BDIV_BITNUM               6U


/*** MCGTRM - MCG Trim Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} MCGTRMSTR;
extern volatile MCGTRMSTR _MCGTRM @0x0000003A;
#define MCGTRM                          _MCGTRM.Byte
#define MCGTRM_TRIM0                    _MCGTRM.Bits.TRIM0
#define MCGTRM_TRIM1                    _MCGTRM.Bits.TRIM1
#define MCGTRM_TRIM2                    _MCGTRM.Bits.TRIM2
#define MCGTRM_TRIM3                    _MCGTRM.Bits.TRIM3
#define MCGTRM_TRIM4                    _MCGTRM.Bits.TRIM4
#define MCGTRM_TRIM5                    _MCGTRM.Bits.TRIM5
#define MCGTRM_TRIM6                    _MCGTRM.Bits.TRIM6
#define MCGTRM_TRIM7                    _MCGTRM.Bits.TRIM7

#define MCGTRM_TRIM0_MASK               1U
#define MCGTRM_TRIM1_MASK               2U
#define MCGTRM_TRIM2_MASK               4U
#define MCGTRM_TRIM3_MASK               8U
#define MCGTRM_TRIM4_MASK               16U
#define MCGTRM_TRIM5_MASK               32U
#define MCGTRM_TRIM6_MASK               64U
#define MCGTRM_TRIM7_MASK               128U


/*** MCGSC - MCG Status and Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte PLLST       :1;                                       /* PLL Select Status */
    byte LOCK        :1;                                       /* Lock Status */
    byte LOLS        :1;                                       /* Loss of Lock Status */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGSCSTR;
extern volatile MCGSCSTR _MCGSC @0x0000003B;
#define MCGSC                           _MCGSC.Byte
#define MCGSC_FTRIM                     _MCGSC.Bits.FTRIM
#define MCGSC_OSCINIT                   _MCGSC.Bits.OSCINIT
#define MCGSC_CLKST0                    _MCGSC.Bits.CLKST0
#define MCGSC_CLKST1                    _MCGSC.Bits.CLKST1
#define MCGSC_IREFST                    _MCGSC.Bits.IREFST
#define MCGSC_PLLST                     _MCGSC.Bits.PLLST
#define MCGSC_LOCK                      _MCGSC.Bits.LOCK
#define MCGSC_LOLS                      _MCGSC.Bits.LOLS
#define MCGSC_CLKST                     _MCGSC.MergedBits.grpCLKST

#define MCGSC_FTRIM_MASK                1U
#define MCGSC_OSCINIT_MASK              2U
#define MCGSC_CLKST0_MASK               4U
#define MCGSC_CLKST1_MASK               8U
#define MCGSC_IREFST_MASK               16U
#define MCGSC_PLLST_MASK                32U
#define MCGSC_LOCK_MASK                 64U
#define MCGSC_LOLS_MASK                 128U
#define MCGSC_CLKST_MASK                12U
#define MCGSC_CLKST_BITNUM              2U


/*** MCGC3 - MCG Control Register 3; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte VDIV0       :1;                                       /* VCO Divider, bit 0 */
    byte VDIV1       :1;                                       /* VCO Divider, bit 1 */
    byte VDIV2       :1;                                       /* VCO Divider, bit 2 */
    byte VDIV3       :1;                                       /* VCO Divider, bit 3 */
    byte DIV32       :1;                                       /* Divide-by-32 Enable */
    byte CME         :1;                                       /* Clock Monitor Enable */
    byte PLLS        :1;                                       /* PLL Select */
    byte LOLIE       :1;                                       /* Loss of Lock Interrupt Enable */
  } Bits;
  struct {
    byte grpVDIV :4;
    byte grpDIV_32 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC3STR;
extern volatile MCGC3STR _MCGC3 @0x0000003C;
#define MCGC3                           _MCGC3.Byte
#define MCGC3_VDIV0                     _MCGC3.Bits.VDIV0
#define MCGC3_VDIV1                     _MCGC3.Bits.VDIV1
#define MCGC3_VDIV2                     _MCGC3.Bits.VDIV2
#define MCGC3_VDIV3                     _MCGC3.Bits.VDIV3
#define MCGC3_DIV32                     _MCGC3.Bits.DIV32
#define MCGC3_CME                       _MCGC3.Bits.CME
#define MCGC3_PLLS                      _MCGC3.Bits.PLLS
#define MCGC3_LOLIE                     _MCGC3.Bits.LOLIE
#define MCGC3_VDIV                      _MCGC3.MergedBits.grpVDIV

#define MCGC3_VDIV0_MASK                1U
#define MCGC3_VDIV1_MASK                2U
#define MCGC3_VDIV2_MASK                4U
#define MCGC3_VDIV3_MASK                8U
#define MCGC3_DIV32_MASK                16U
#define MCGC3_CME_MASK                  32U
#define MCGC3_PLLS_MASK                 64U
#define MCGC3_LOLIE_MASK                128U
#define MCGC3_VDIV_MASK                 15U
#define MCGC3_VDIV_BITNUM               0U


/*** MCGC4 - MCG Control Register 4; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte DRST_DRS0   :1;                                       /* DCO Range Status / DCO Range Select, bit 0 */
    byte DRST_DRS1   :1;                                       /* DCO Range Status / DCO Range Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DMX32       :1;                                       /* DCO Maximum frequency with 32.768 kHz reference */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDRST_DRS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDMX_32 :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC4STR;
extern volatile MCGC4STR _MCGC4 @0x0000003D;
#define MCGC4                           _MCGC4.Byte
#define MCGC4_DRST_DRS0                 _MCGC4.Bits.DRST_DRS0
#define MCGC4_DRST_DRS1                 _MCGC4.Bits.DRST_DRS1
#define MCGC4_DMX32                     _MCGC4.Bits.DMX32
#define MCGC4_DRST_DRS                  _MCGC4.MergedBits.grpDRST_DRS

#define MCGC4_DRST_DRS0_MASK            1U
#define MCGC4_DRST_DRS1_MASK            2U
#define MCGC4_DMX32_MASK                32U
#define MCGC4_DRST_DRS_MASK             3U
#define MCGC4_DRST_DRS_BITNUM           0U


/*** ADCSC1A - Status and Control Register 1A; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHA0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHA1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHA2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHA3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHA4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFA       :1;                                       /* Differential Mode Enable - DIFFA configures the ADC to operate in differential mode */
    byte AIENA       :1;                                       /* Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted */
    byte COCOA       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHA :5;
    byte grpDIFFx :1;
    byte grpAIENx :1;
    byte grpCOCOx :1;
  } MergedBits;
} ADCSC1ASTR;
extern volatile ADCSC1ASTR _ADCSC1A @0x00000040;
#define ADCSC1A                         _ADCSC1A.Byte
#define ADCSC1A_ADCHA0                  _ADCSC1A.Bits.ADCHA0
#define ADCSC1A_ADCHA1                  _ADCSC1A.Bits.ADCHA1
#define ADCSC1A_ADCHA2                  _ADCSC1A.Bits.ADCHA2
#define ADCSC1A_ADCHA3                  _ADCSC1A.Bits.ADCHA3
#define ADCSC1A_ADCHA4                  _ADCSC1A.Bits.ADCHA4
#define ADCSC1A_DIFFA                   _ADCSC1A.Bits.DIFFA
#define ADCSC1A_AIENA                   _ADCSC1A.Bits.AIENA
#define ADCSC1A_COCOA                   _ADCSC1A.Bits.COCOA
#define ADCSC1A_ADCHA                   _ADCSC1A.MergedBits.grpADCHA

#define ADCSC1A_ADCHA0_MASK             1U
#define ADCSC1A_ADCHA1_MASK             2U
#define ADCSC1A_ADCHA2_MASK             4U
#define ADCSC1A_ADCHA3_MASK             8U
#define ADCSC1A_ADCHA4_MASK             16U
#define ADCSC1A_DIFFA_MASK              32U
#define ADCSC1A_AIENA_MASK              64U
#define ADCSC1A_COCOA_MASK              128U
#define ADCSC1A_ADCHA_MASK              31U
#define ADCSC1A_ADCHA_BITNUM            0U


/*** ADCSC1B - Status and Control Register 1B; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHB0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHB1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHB2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHB3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHB4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFB       :1;                                       /* Differential Mode Enable - DIFFB configures the ADC to operate in differential mode */
    byte AIENB       :1;                                       /* Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted */
    byte COCOB       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHB :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1BSTR;
extern volatile ADCSC1BSTR _ADCSC1B @0x00000041;
#define ADCSC1B                         _ADCSC1B.Byte
#define ADCSC1B_ADCHB0                  _ADCSC1B.Bits.ADCHB0
#define ADCSC1B_ADCHB1                  _ADCSC1B.Bits.ADCHB1
#define ADCSC1B_ADCHB2                  _ADCSC1B.Bits.ADCHB2
#define ADCSC1B_ADCHB3                  _ADCSC1B.Bits.ADCHB3
#define ADCSC1B_ADCHB4                  _ADCSC1B.Bits.ADCHB4
#define ADCSC1B_DIFFB                   _ADCSC1B.Bits.DIFFB
#define ADCSC1B_AIENB                   _ADCSC1B.Bits.AIENB
#define ADCSC1B_COCOB                   _ADCSC1B.Bits.COCOB
#define ADCSC1B_ADCHB                   _ADCSC1B.MergedBits.grpADCHB

#define ADCSC1B_ADCHB0_MASK             1U
#define ADCSC1B_ADCHB1_MASK             2U
#define ADCSC1B_ADCHB2_MASK             4U
#define ADCSC1B_ADCHB3_MASK             8U
#define ADCSC1B_ADCHB4_MASK             16U
#define ADCSC1B_DIFFB_MASK              32U
#define ADCSC1B_AIENB_MASK              64U
#define ADCSC1B_COCOB_MASK              128U
#define ADCSC1B_ADCHB_MASK              31U
#define ADCSC1B_ADCHB_BITNUM            0U


/*** ADCSC1C - Status and Control Register 1C; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHC0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHC1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHC2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHC3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHC4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFC       :1;                                       /* Differential Mode Enable - DIFFC configures the ADC to operate in differential mode */
    byte AIENC       :1;                                       /* Interrupt Enable - AIENC enables conversion complete interrupts. When COCOC becomes set while the respective AIENC is high, an interrupt is asserted */
    byte COCOC       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHC :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1CSTR;
extern volatile ADCSC1CSTR _ADCSC1C @0x00000042;
#define ADCSC1C                         _ADCSC1C.Byte
#define ADCSC1C_ADCHC0                  _ADCSC1C.Bits.ADCHC0
#define ADCSC1C_ADCHC1                  _ADCSC1C.Bits.ADCHC1
#define ADCSC1C_ADCHC2                  _ADCSC1C.Bits.ADCHC2
#define ADCSC1C_ADCHC3                  _ADCSC1C.Bits.ADCHC3
#define ADCSC1C_ADCHC4                  _ADCSC1C.Bits.ADCHC4
#define ADCSC1C_DIFFC                   _ADCSC1C.Bits.DIFFC
#define ADCSC1C_AIENC                   _ADCSC1C.Bits.AIENC
#define ADCSC1C_COCOC                   _ADCSC1C.Bits.COCOC
#define ADCSC1C_ADCHC                   _ADCSC1C.MergedBits.grpADCHC

#define ADCSC1C_ADCHC0_MASK             1U
#define ADCSC1C_ADCHC1_MASK             2U
#define ADCSC1C_ADCHC2_MASK             4U
#define ADCSC1C_ADCHC3_MASK             8U
#define ADCSC1C_ADCHC4_MASK             16U
#define ADCSC1C_DIFFC_MASK              32U
#define ADCSC1C_AIENC_MASK              64U
#define ADCSC1C_COCOC_MASK              128U
#define ADCSC1C_ADCHC_MASK              31U
#define ADCSC1C_ADCHC_BITNUM            0U


/*** ADCSC1D - Status and Control Register 1D; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHD0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHD1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHD2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHD3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHD4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFD       :1;                                       /* Differential Mode Enable - DIFFD configures the ADC to operate in differential mode */
    byte AIEND       :1;                                       /* Interrupt Enable - AIEND enables conversion complete interrupts. When COCOD becomes set while the respective AIEND is high, an interrupt is asserted */
    byte COCOD       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1DSTR;
extern volatile ADCSC1DSTR _ADCSC1D @0x00000043;
#define ADCSC1D                         _ADCSC1D.Byte
#define ADCSC1D_ADCHD0                  _ADCSC1D.Bits.ADCHD0
#define ADCSC1D_ADCHD1                  _ADCSC1D.Bits.ADCHD1
#define ADCSC1D_ADCHD2                  _ADCSC1D.Bits.ADCHD2
#define ADCSC1D_ADCHD3                  _ADCSC1D.Bits.ADCHD3
#define ADCSC1D_ADCHD4                  _ADCSC1D.Bits.ADCHD4
#define ADCSC1D_DIFFD                   _ADCSC1D.Bits.DIFFD
#define ADCSC1D_AIEND                   _ADCSC1D.Bits.AIEND
#define ADCSC1D_COCOD                   _ADCSC1D.Bits.COCOD
#define ADCSC1D_ADCHD                   _ADCSC1D.MergedBits.grpADCHD

#define ADCSC1D_ADCHD0_MASK             1U
#define ADCSC1D_ADCHD1_MASK             2U
#define ADCSC1D_ADCHD2_MASK             4U
#define ADCSC1D_ADCHD3_MASK             8U
#define ADCSC1D_ADCHD4_MASK             16U
#define ADCSC1D_DIFFD_MASK              32U
#define ADCSC1D_AIEND_MASK              64U
#define ADCSC1D_COCOD_MASK              128U
#define ADCSC1D_ADCHD_MASK              31U
#define ADCSC1D_ADCHD_BITNUM            0U


/*** ADCSC1E - Status and Control Register 1E; 0x00000044 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHE0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHE1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHE2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHE3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHE4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFE       :1;                                       /* Differential Mode Enable - DIFFE configures the ADC to operate in differential mode */
    byte AIENE       :1;                                       /* Interrupt Enable - AIENE enables conversion complete interrupts. When COCOE becomes set while the respective AIENE is high, an interrupt is asserted */
    byte COCOE       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1ESTR;
extern volatile ADCSC1ESTR _ADCSC1E @0x00000044;
#define ADCSC1E                         _ADCSC1E.Byte
#define ADCSC1E_ADCHE0                  _ADCSC1E.Bits.ADCHE0
#define ADCSC1E_ADCHE1                  _ADCSC1E.Bits.ADCHE1
#define ADCSC1E_ADCHE2                  _ADCSC1E.Bits.ADCHE2
#define ADCSC1E_ADCHE3                  _ADCSC1E.Bits.ADCHE3
#define ADCSC1E_ADCHE4                  _ADCSC1E.Bits.ADCHE4
#define ADCSC1E_DIFFE                   _ADCSC1E.Bits.DIFFE
#define ADCSC1E_AIENE                   _ADCSC1E.Bits.AIENE
#define ADCSC1E_COCOE                   _ADCSC1E.Bits.COCOE
#define ADCSC1E_ADCHE                   _ADCSC1E.MergedBits.grpADCHE

#define ADCSC1E_ADCHE0_MASK             1U
#define ADCSC1E_ADCHE1_MASK             2U
#define ADCSC1E_ADCHE2_MASK             4U
#define ADCSC1E_ADCHE3_MASK             8U
#define ADCSC1E_ADCHE4_MASK             16U
#define ADCSC1E_DIFFE_MASK              32U
#define ADCSC1E_AIENE_MASK              64U
#define ADCSC1E_COCOE_MASK              128U
#define ADCSC1E_ADCHE_MASK              31U
#define ADCSC1E_ADCHE_BITNUM            0U


/*** ADCSC1F - Status and Control Register 1F; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHF0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHF1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHF2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHF3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHF4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFF       :1;                                       /* Differential Mode Enable - DIFFF configures the ADC to operate in differential mode */
    byte AIENF       :1;                                       /* Interrupt Enable - AIENF enables conversion complete interrupts. When COCOF becomes set while the respective AIENF is high, an interrupt is asserted */
    byte COCOF       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHF :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1FSTR;
extern volatile ADCSC1FSTR _ADCSC1F @0x00000045;
#define ADCSC1F                         _ADCSC1F.Byte
#define ADCSC1F_ADCHF0                  _ADCSC1F.Bits.ADCHF0
#define ADCSC1F_ADCHF1                  _ADCSC1F.Bits.ADCHF1
#define ADCSC1F_ADCHF2                  _ADCSC1F.Bits.ADCHF2
#define ADCSC1F_ADCHF3                  _ADCSC1F.Bits.ADCHF3
#define ADCSC1F_ADCHF4                  _ADCSC1F.Bits.ADCHF4
#define ADCSC1F_DIFFF                   _ADCSC1F.Bits.DIFFF
#define ADCSC1F_AIENF                   _ADCSC1F.Bits.AIENF
#define ADCSC1F_COCOF                   _ADCSC1F.Bits.COCOF
#define ADCSC1F_ADCHF                   _ADCSC1F.MergedBits.grpADCHF

#define ADCSC1F_ADCHF0_MASK             1U
#define ADCSC1F_ADCHF1_MASK             2U
#define ADCSC1F_ADCHF2_MASK             4U
#define ADCSC1F_ADCHF3_MASK             8U
#define ADCSC1F_ADCHF4_MASK             16U
#define ADCSC1F_DIFFF_MASK              32U
#define ADCSC1F_AIENF_MASK              64U
#define ADCSC1F_COCOF_MASK              128U
#define ADCSC1F_ADCHF_MASK              31U
#define ADCSC1F_ADCHF_BITNUM            0U


/*** ADCSC1G - Status and Control Register 1G; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHG0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHG1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHG2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHG3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHG4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFG       :1;                                       /* Differential Mode Enable - DIFFG configures the ADC to operate in differential mode */
    byte AIENG       :1;                                       /* Interrupt Enable - AIENG enables conversion complete interrupts. When COCOG becomes set while the respective AIENG is high, an interrupt is asserted */
    byte COCOG       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHG :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1GSTR;
extern volatile ADCSC1GSTR _ADCSC1G @0x00000046;
#define ADCSC1G                         _ADCSC1G.Byte
#define ADCSC1G_ADCHG0                  _ADCSC1G.Bits.ADCHG0
#define ADCSC1G_ADCHG1                  _ADCSC1G.Bits.ADCHG1
#define ADCSC1G_ADCHG2                  _ADCSC1G.Bits.ADCHG2
#define ADCSC1G_ADCHG3                  _ADCSC1G.Bits.ADCHG3
#define ADCSC1G_ADCHG4                  _ADCSC1G.Bits.ADCHG4
#define ADCSC1G_DIFFG                   _ADCSC1G.Bits.DIFFG
#define ADCSC1G_AIENG                   _ADCSC1G.Bits.AIENG
#define ADCSC1G_COCOG                   _ADCSC1G.Bits.COCOG
#define ADCSC1G_ADCHG                   _ADCSC1G.MergedBits.grpADCHG

#define ADCSC1G_ADCHG0_MASK             1U
#define ADCSC1G_ADCHG1_MASK             2U
#define ADCSC1G_ADCHG2_MASK             4U
#define ADCSC1G_ADCHG3_MASK             8U
#define ADCSC1G_ADCHG4_MASK             16U
#define ADCSC1G_DIFFG_MASK              32U
#define ADCSC1G_AIENG_MASK              64U
#define ADCSC1G_COCOG_MASK              128U
#define ADCSC1G_ADCHG_MASK              31U
#define ADCSC1G_ADCHG_BITNUM            0U


/*** ADCSC1H - Status and Control Register 1H; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCHH0      :1;                                       /* Input Channel Select Bit 0 */
    byte ADCHH1      :1;                                       /* Input Channel Select Bit 1 */
    byte ADCHH2      :1;                                       /* Input Channel Select Bit 2 */
    byte ADCHH3      :1;                                       /* Input Channel Select Bit 3 */
    byte ADCHH4      :1;                                       /* Input Channel Select Bit 4 */
    byte DIFFH       :1;                                       /* Differential Mode Enable - DIFFH configures the ADC to operate in differential mode */
    byte AIENH       :1;                                       /* Interrupt Enable - AIENH enables conversion complete interrupts. When COCOH becomes set while the respective AIENH is high, an interrupt is asserted */
    byte COCOH       :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCHH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1HSTR;
extern volatile ADCSC1HSTR _ADCSC1H @0x00000047;
#define ADCSC1H                         _ADCSC1H.Byte
#define ADCSC1H_ADCHH0                  _ADCSC1H.Bits.ADCHH0
#define ADCSC1H_ADCHH1                  _ADCSC1H.Bits.ADCHH1
#define ADCSC1H_ADCHH2                  _ADCSC1H.Bits.ADCHH2
#define ADCSC1H_ADCHH3                  _ADCSC1H.Bits.ADCHH3
#define ADCSC1H_ADCHH4                  _ADCSC1H.Bits.ADCHH4
#define ADCSC1H_DIFFH                   _ADCSC1H.Bits.DIFFH
#define ADCSC1H_AIENH                   _ADCSC1H.Bits.AIENH
#define ADCSC1H_COCOH                   _ADCSC1H.Bits.COCOH
#define ADCSC1H_ADCHH                   _ADCSC1H.MergedBits.grpADCHH

#define ADCSC1H_ADCHH0_MASK             1U
#define ADCSC1H_ADCHH1_MASK             2U
#define ADCSC1H_ADCHH2_MASK             4U
#define ADCSC1H_ADCHH3_MASK             8U
#define ADCSC1H_ADCHH4_MASK             16U
#define ADCSC1H_DIFFH_MASK              32U
#define ADCSC1H_AIENH_MASK              64U
#define ADCSC1H_COCOH_MASK              128U
#define ADCSC1H_ADCHH_MASK              31U
#define ADCSC1H_ADCHH_BITNUM            0U


/*** ADCCFG1 - Configuration Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFG1STR;
extern volatile ADCCFG1STR _ADCCFG1 @0x00000048;
#define ADCCFG1                         _ADCCFG1.Byte
#define ADCCFG1_ADICLK0                 _ADCCFG1.Bits.ADICLK0
#define ADCCFG1_ADICLK1                 _ADCCFG1.Bits.ADICLK1
#define ADCCFG1_MODE0                   _ADCCFG1.Bits.MODE0
#define ADCCFG1_MODE1                   _ADCCFG1.Bits.MODE1
#define ADCCFG1_ADLSMP                  _ADCCFG1.Bits.ADLSMP
#define ADCCFG1_ADIV0                   _ADCCFG1.Bits.ADIV0
#define ADCCFG1_ADIV1                   _ADCCFG1.Bits.ADIV1
#define ADCCFG1_ADLPC                   _ADCCFG1.Bits.ADLPC
#define ADCCFG1_ADICLK                  _ADCCFG1.MergedBits.grpADICLK
#define ADCCFG1_MODE                    _ADCCFG1.MergedBits.grpMODE
#define ADCCFG1_ADIV                    _ADCCFG1.MergedBits.grpADIV

#define ADCCFG1_ADICLK0_MASK            1U
#define ADCCFG1_ADICLK1_MASK            2U
#define ADCCFG1_MODE0_MASK              4U
#define ADCCFG1_MODE1_MASK              8U
#define ADCCFG1_ADLSMP_MASK             16U
#define ADCCFG1_ADIV0_MASK              32U
#define ADCCFG1_ADIV1_MASK              64U
#define ADCCFG1_ADLPC_MASK              128U
#define ADCCFG1_ADICLK_MASK             3U
#define ADCCFG1_ADICLK_BITNUM           0U
#define ADCCFG1_MODE_MASK               12U
#define ADCCFG1_MODE_BITNUM             2U
#define ADCCFG1_ADIV_MASK               96U
#define ADCCFG1_ADIV_BITNUM             5U


/*** ADCCFG2 - Configuration Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte ADLSTS0     :1;                                       /* Long Sample Time Select Bit 0 */
    byte ADLSTS1     :1;                                       /* Long Sample Time Select Bit 1 */
    byte ADHSC       :1;                                       /* High Speed Configuration */
    byte ADACKEN     :1;                                       /* Asynchronous Clock Output Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADLSTS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCFG2STR;
extern volatile ADCCFG2STR _ADCCFG2 @0x00000049;
#define ADCCFG2                         _ADCCFG2.Byte
#define ADCCFG2_ADLSTS0                 _ADCCFG2.Bits.ADLSTS0
#define ADCCFG2_ADLSTS1                 _ADCCFG2.Bits.ADLSTS1
#define ADCCFG2_ADHSC                   _ADCCFG2.Bits.ADHSC
#define ADCCFG2_ADACKEN                 _ADCCFG2.Bits.ADACKEN
#define ADCCFG2_ADLSTS                  _ADCCFG2.MergedBits.grpADLSTS

#define ADCCFG2_ADLSTS0_MASK            1U
#define ADCCFG2_ADLSTS1_MASK            2U
#define ADCCFG2_ADHSC_MASK              4U
#define ADCCFG2_ADACKEN_MASK            8U
#define ADCCFG2_ADLSTS_MASK             3U
#define ADCCFG2_ADLSTS_BITNUM           0U


/*** ADCRA - Data Result Register A; 0x0000004A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHA - Data Result High Register A; 0x0000004A ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHASTR;
    #define ADCRHA                      _ADCRA.Overlap_STR.ADCRHASTR.Byte
    #define ADCRHA_D8                   _ADCRA.Overlap_STR.ADCRHASTR.Bits.D8
    #define ADCRHA_D9                   _ADCRA.Overlap_STR.ADCRHASTR.Bits.D9
    #define ADCRHA_D10                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D10
    #define ADCRHA_D11                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D11
    #define ADCRHA_D12                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D12
    #define ADCRHA_D13                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D13
    #define ADCRHA_D14                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D14
    #define ADCRHA_D15                  _ADCRA.Overlap_STR.ADCRHASTR.Bits.D15
    
    #define ADCRHA_D8_MASK              1U
    #define ADCRHA_D9_MASK              2U
    #define ADCRHA_D10_MASK             4U
    #define ADCRHA_D11_MASK             8U
    #define ADCRHA_D12_MASK             16U
    #define ADCRHA_D13_MASK             32U
    #define ADCRHA_D14_MASK             64U
    #define ADCRHA_D15_MASK             128U
    

    /*** ADCRLA - Data Result Low Register A; 0x0000004B ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLASTR;
    #define ADCRLA                      _ADCRA.Overlap_STR.ADCRLASTR.Byte
    #define ADCRLA_D0                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D0
    #define ADCRLA_D1                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D1
    #define ADCRLA_D2                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D2
    #define ADCRLA_D3                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D3
    #define ADCRLA_D4                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D4
    #define ADCRLA_D5                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D5
    #define ADCRLA_D6                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D6
    #define ADCRLA_D7                   _ADCRA.Overlap_STR.ADCRLASTR.Bits.D7
    
    #define ADCRLA_D0_MASK              1U
    #define ADCRLA_D1_MASK              2U
    #define ADCRLA_D2_MASK              4U
    #define ADCRLA_D3_MASK              8U
    #define ADCRLA_D4_MASK              16U
    #define ADCRLA_D5_MASK              32U
    #define ADCRLA_D6_MASK              64U
    #define ADCRLA_D7_MASK              128U
    
  } Overlap_STR;

} ADCRASTR;
extern volatile ADCRASTR _ADCRA @0x0000004A;
#define ADCRA                           _ADCRA.Word


/*** ADCRB - Data Result Register B; 0x0000004C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHB - Data Result High Register B; 0x0000004C ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHBSTR;
    #define ADCRHB                      _ADCRB.Overlap_STR.ADCRHBSTR.Byte
    #define ADCRHB_D8                   _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D8
    #define ADCRHB_D9                   _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D9
    #define ADCRHB_D10                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D10
    #define ADCRHB_D11                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D11
    #define ADCRHB_D12                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D12
    #define ADCRHB_D13                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D13
    #define ADCRHB_D14                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D14
    #define ADCRHB_D15                  _ADCRB.Overlap_STR.ADCRHBSTR.Bits.D15
    
    #define ADCRHB_D8_MASK              1U
    #define ADCRHB_D9_MASK              2U
    #define ADCRHB_D10_MASK             4U
    #define ADCRHB_D11_MASK             8U
    #define ADCRHB_D12_MASK             16U
    #define ADCRHB_D13_MASK             32U
    #define ADCRHB_D14_MASK             64U
    #define ADCRHB_D15_MASK             128U
    

    /*** ADCRLB - Data Result Low Register B; 0x0000004D ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLBSTR;
    #define ADCRLB                      _ADCRB.Overlap_STR.ADCRLBSTR.Byte
    #define ADCRLB_D0                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D0
    #define ADCRLB_D1                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D1
    #define ADCRLB_D2                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D2
    #define ADCRLB_D3                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D3
    #define ADCRLB_D4                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D4
    #define ADCRLB_D5                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D5
    #define ADCRLB_D6                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D6
    #define ADCRLB_D7                   _ADCRB.Overlap_STR.ADCRLBSTR.Bits.D7
    
    #define ADCRLB_D0_MASK              1U
    #define ADCRLB_D1_MASK              2U
    #define ADCRLB_D2_MASK              4U
    #define ADCRLB_D3_MASK              8U
    #define ADCRLB_D4_MASK              16U
    #define ADCRLB_D5_MASK              32U
    #define ADCRLB_D6_MASK              64U
    #define ADCRLB_D7_MASK              128U
    
  } Overlap_STR;

} ADCRBSTR;
extern volatile ADCRBSTR _ADCRB @0x0000004C;
#define ADCRB                           _ADCRB.Word


/*** ADCRC - Data Result Register C; 0x0000004E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHC - Data Result High Register C; 0x0000004E ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHCSTR;
    #define ADCRHC                      _ADCRC.Overlap_STR.ADCRHCSTR.Byte
    #define ADCRHC_D8                   _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D8
    #define ADCRHC_D9                   _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D9
    #define ADCRHC_D10                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D10
    #define ADCRHC_D11                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D11
    #define ADCRHC_D12                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D12
    #define ADCRHC_D13                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D13
    #define ADCRHC_D14                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D14
    #define ADCRHC_D15                  _ADCRC.Overlap_STR.ADCRHCSTR.Bits.D15
    
    #define ADCRHC_D8_MASK              1U
    #define ADCRHC_D9_MASK              2U
    #define ADCRHC_D10_MASK             4U
    #define ADCRHC_D11_MASK             8U
    #define ADCRHC_D12_MASK             16U
    #define ADCRHC_D13_MASK             32U
    #define ADCRHC_D14_MASK             64U
    #define ADCRHC_D15_MASK             128U
    

    /*** ADCRLC - Data Result Low Register C; 0x0000004F ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLCSTR;
    #define ADCRLC                      _ADCRC.Overlap_STR.ADCRLCSTR.Byte
    #define ADCRLC_D0                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D0
    #define ADCRLC_D1                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D1
    #define ADCRLC_D2                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D2
    #define ADCRLC_D3                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D3
    #define ADCRLC_D4                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D4
    #define ADCRLC_D5                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D5
    #define ADCRLC_D6                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D6
    #define ADCRLC_D7                   _ADCRC.Overlap_STR.ADCRLCSTR.Bits.D7
    
    #define ADCRLC_D0_MASK              1U
    #define ADCRLC_D1_MASK              2U
    #define ADCRLC_D2_MASK              4U
    #define ADCRLC_D3_MASK              8U
    #define ADCRLC_D4_MASK              16U
    #define ADCRLC_D5_MASK              32U
    #define ADCRLC_D6_MASK              64U
    #define ADCRLC_D7_MASK              128U
    
  } Overlap_STR;

} ADCRCSTR;
extern volatile ADCRCSTR _ADCRC @0x0000004E;
#define ADCRC                           _ADCRC.Word


/*** ADCRD - Data Result Register D; 0x00000050 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHD - Data Result High Register D; 0x00000050 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHDSTR;
    #define ADCRHD                      _ADCRD.Overlap_STR.ADCRHDSTR.Byte
    #define ADCRHD_D8                   _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D8
    #define ADCRHD_D9                   _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D9
    #define ADCRHD_D10                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D10
    #define ADCRHD_D11                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D11
    #define ADCRHD_D12                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D12
    #define ADCRHD_D13                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D13
    #define ADCRHD_D14                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D14
    #define ADCRHD_D15                  _ADCRD.Overlap_STR.ADCRHDSTR.Bits.D15
    
    #define ADCRHD_D8_MASK              1U
    #define ADCRHD_D9_MASK              2U
    #define ADCRHD_D10_MASK             4U
    #define ADCRHD_D11_MASK             8U
    #define ADCRHD_D12_MASK             16U
    #define ADCRHD_D13_MASK             32U
    #define ADCRHD_D14_MASK             64U
    #define ADCRHD_D15_MASK             128U
    

    /*** ADCRLD - Data Result Low Register D; 0x00000051 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLDSTR;
    #define ADCRLD                      _ADCRD.Overlap_STR.ADCRLDSTR.Byte
    #define ADCRLD_D0                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D0
    #define ADCRLD_D1                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D1
    #define ADCRLD_D2                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D2
    #define ADCRLD_D3                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D3
    #define ADCRLD_D4                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D4
    #define ADCRLD_D5                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D5
    #define ADCRLD_D6                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D6
    #define ADCRLD_D7                   _ADCRD.Overlap_STR.ADCRLDSTR.Bits.D7
    
    #define ADCRLD_D0_MASK              1U
    #define ADCRLD_D1_MASK              2U
    #define ADCRLD_D2_MASK              4U
    #define ADCRLD_D3_MASK              8U
    #define ADCRLD_D4_MASK              16U
    #define ADCRLD_D5_MASK              32U
    #define ADCRLD_D6_MASK              64U
    #define ADCRLD_D7_MASK              128U
    
  } Overlap_STR;

} ADCRDSTR;
extern volatile ADCRDSTR _ADCRD @0x00000050;
#define ADCRD                           _ADCRD.Word


/*** ADCRE - Data Result Register E; 0x00000052 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHE - Data Result High Register E; 0x00000052 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHESTR;
    #define ADCRHE                      _ADCRE.Overlap_STR.ADCRHESTR.Byte
    #define ADCRHE_D8                   _ADCRE.Overlap_STR.ADCRHESTR.Bits.D8
    #define ADCRHE_D9                   _ADCRE.Overlap_STR.ADCRHESTR.Bits.D9
    #define ADCRHE_D10                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D10
    #define ADCRHE_D11                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D11
    #define ADCRHE_D12                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D12
    #define ADCRHE_D13                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D13
    #define ADCRHE_D14                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D14
    #define ADCRHE_D15                  _ADCRE.Overlap_STR.ADCRHESTR.Bits.D15
    
    #define ADCRHE_D8_MASK              1U
    #define ADCRHE_D9_MASK              2U
    #define ADCRHE_D10_MASK             4U
    #define ADCRHE_D11_MASK             8U
    #define ADCRHE_D12_MASK             16U
    #define ADCRHE_D13_MASK             32U
    #define ADCRHE_D14_MASK             64U
    #define ADCRHE_D15_MASK             128U
    

    /*** ADCRLE - Data Result Low Register E; 0x00000053 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLESTR;
    #define ADCRLE                      _ADCRE.Overlap_STR.ADCRLESTR.Byte
    #define ADCRLE_D0                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D0
    #define ADCRLE_D1                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D1
    #define ADCRLE_D2                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D2
    #define ADCRLE_D3                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D3
    #define ADCRLE_D4                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D4
    #define ADCRLE_D5                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D5
    #define ADCRLE_D6                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D6
    #define ADCRLE_D7                   _ADCRE.Overlap_STR.ADCRLESTR.Bits.D7
    
    #define ADCRLE_D0_MASK              1U
    #define ADCRLE_D1_MASK              2U
    #define ADCRLE_D2_MASK              4U
    #define ADCRLE_D3_MASK              8U
    #define ADCRLE_D4_MASK              16U
    #define ADCRLE_D5_MASK              32U
    #define ADCRLE_D6_MASK              64U
    #define ADCRLE_D7_MASK              128U
    
  } Overlap_STR;

} ADCRESTR;
extern volatile ADCRESTR _ADCRE @0x00000052;
#define ADCRE                           _ADCRE.Word


/*** ADCRF - Data Result Register F; 0x00000054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHF - Data Result High Register F; 0x00000054 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHFSTR;
    #define ADCRHF                      _ADCRF.Overlap_STR.ADCRHFSTR.Byte
    #define ADCRHF_D8                   _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D8
    #define ADCRHF_D9                   _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D9
    #define ADCRHF_D10                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D10
    #define ADCRHF_D11                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D11
    #define ADCRHF_D12                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D12
    #define ADCRHF_D13                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D13
    #define ADCRHF_D14                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D14
    #define ADCRHF_D15                  _ADCRF.Overlap_STR.ADCRHFSTR.Bits.D15
    
    #define ADCRHF_D8_MASK              1U
    #define ADCRHF_D9_MASK              2U
    #define ADCRHF_D10_MASK             4U
    #define ADCRHF_D11_MASK             8U
    #define ADCRHF_D12_MASK             16U
    #define ADCRHF_D13_MASK             32U
    #define ADCRHF_D14_MASK             64U
    #define ADCRHF_D15_MASK             128U
    

    /*** ADCRLF - Data Result Low Register F; 0x00000055 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLFSTR;
    #define ADCRLF                      _ADCRF.Overlap_STR.ADCRLFSTR.Byte
    #define ADCRLF_D0                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D0
    #define ADCRLF_D1                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D1
    #define ADCRLF_D2                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D2
    #define ADCRLF_D3                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D3
    #define ADCRLF_D4                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D4
    #define ADCRLF_D5                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D5
    #define ADCRLF_D6                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D6
    #define ADCRLF_D7                   _ADCRF.Overlap_STR.ADCRLFSTR.Bits.D7
    
    #define ADCRLF_D0_MASK              1U
    #define ADCRLF_D1_MASK              2U
    #define ADCRLF_D2_MASK              4U
    #define ADCRLF_D3_MASK              8U
    #define ADCRLF_D4_MASK              16U
    #define ADCRLF_D5_MASK              32U
    #define ADCRLF_D6_MASK              64U
    #define ADCRLF_D7_MASK              128U
    
  } Overlap_STR;

} ADCRFSTR;
extern volatile ADCRFSTR _ADCRF @0x00000054;
#define ADCRF                           _ADCRF.Word


/*** ADCRG - Data Result Register G; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHG - Data Result High Register G; 0x00000056 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHGSTR;
    #define ADCRHG                      _ADCRG.Overlap_STR.ADCRHGSTR.Byte
    #define ADCRHG_D8                   _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D8
    #define ADCRHG_D9                   _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D9
    #define ADCRHG_D10                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D10
    #define ADCRHG_D11                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D11
    #define ADCRHG_D12                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D12
    #define ADCRHG_D13                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D13
    #define ADCRHG_D14                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D14
    #define ADCRHG_D15                  _ADCRG.Overlap_STR.ADCRHGSTR.Bits.D15
    
    #define ADCRHG_D8_MASK              1U
    #define ADCRHG_D9_MASK              2U
    #define ADCRHG_D10_MASK             4U
    #define ADCRHG_D11_MASK             8U
    #define ADCRHG_D12_MASK             16U
    #define ADCRHG_D13_MASK             32U
    #define ADCRHG_D14_MASK             64U
    #define ADCRHG_D15_MASK             128U
    

    /*** ADCRLG - Data Result Low Register G; 0x00000057 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLGSTR;
    #define ADCRLG                      _ADCRG.Overlap_STR.ADCRLGSTR.Byte
    #define ADCRLG_D0                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D0
    #define ADCRLG_D1                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D1
    #define ADCRLG_D2                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D2
    #define ADCRLG_D3                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D3
    #define ADCRLG_D4                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D4
    #define ADCRLG_D5                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D5
    #define ADCRLG_D6                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D6
    #define ADCRLG_D7                   _ADCRG.Overlap_STR.ADCRLGSTR.Bits.D7
    
    #define ADCRLG_D0_MASK              1U
    #define ADCRLG_D1_MASK              2U
    #define ADCRLG_D2_MASK              4U
    #define ADCRLG_D3_MASK              8U
    #define ADCRLG_D4_MASK              16U
    #define ADCRLG_D5_MASK              32U
    #define ADCRLG_D6_MASK              64U
    #define ADCRLG_D7_MASK              128U
    
  } Overlap_STR;

} ADCRGSTR;
extern volatile ADCRGSTR _ADCRG @0x00000056;
#define ADCRG                           _ADCRG.Word


/*** ADCRH - Data Result Register H; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRHH - Data Result High Register H; 0x00000058 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte D12         :1;                                       /* ADC Result Data Bit 12 */
        byte D13         :1;                                       /* ADC Result Data Bit 13 */
        byte D14         :1;                                       /* ADC Result Data Bit 14 */
        byte D15         :1;                                       /* ADC Result Data Bit 15 */
      } Bits;
    } ADCRHHSTR;
    #define ADCRHH                      _ADCRH.Overlap_STR.ADCRHHSTR.Byte
    #define ADCRHH_D8                   _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D8
    #define ADCRHH_D9                   _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D9
    #define ADCRHH_D10                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D10
    #define ADCRHH_D11                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D11
    #define ADCRHH_D12                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D12
    #define ADCRHH_D13                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D13
    #define ADCRHH_D14                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D14
    #define ADCRHH_D15                  _ADCRH.Overlap_STR.ADCRHHSTR.Bits.D15
    
    #define ADCRHH_D8_MASK              1U
    #define ADCRHH_D9_MASK              2U
    #define ADCRHH_D10_MASK             4U
    #define ADCRHH_D11_MASK             8U
    #define ADCRHH_D12_MASK             16U
    #define ADCRHH_D13_MASK             32U
    #define ADCRHH_D14_MASK             64U
    #define ADCRHH_D15_MASK             128U
    

    /*** ADCRLH - Data Result Low Register H; 0x00000059 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLHSTR;
    #define ADCRLH                      _ADCRH.Overlap_STR.ADCRLHSTR.Byte
    #define ADCRLH_D0                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D0
    #define ADCRLH_D1                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D1
    #define ADCRLH_D2                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D2
    #define ADCRLH_D3                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D3
    #define ADCRLH_D4                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D4
    #define ADCRLH_D5                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D5
    #define ADCRLH_D6                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D6
    #define ADCRLH_D7                   _ADCRH.Overlap_STR.ADCRLHSTR.Bits.D7
    
    #define ADCRLH_D0_MASK              1U
    #define ADCRLH_D1_MASK              2U
    #define ADCRLH_D2_MASK              4U
    #define ADCRLH_D3_MASK              8U
    #define ADCRLH_D4_MASK              16U
    #define ADCRLH_D5_MASK              32U
    #define ADCRLH_D6_MASK              64U
    #define ADCRLH_D7_MASK              128U
    
  } Overlap_STR;

} ADCRHSTR;
extern volatile ADCRHSTR _ADCRH @0x00000058;
#define ADCRH                           _ADCRH.Word


/*** VREFTRM - VREF Trim Register; 0x0000005C ***/
typedef union {
  byte Byte;
  struct {
    byte TRM0        :1;                                       /* Trim Bits, bit 0 */
    byte TRM1        :1;                                       /* Trim Bits, bit 1 */
    byte TRM2        :1;                                       /* Trim Bits, bit 2 */
    byte TRM3        :1;                                       /* Trim Bits, bit 3 */
    byte TRM4        :1;                                       /* Trim Bits, bit 4 */
    byte TRM5        :1;                                       /* Trim Bits, bit 5 */
    byte TRM6        :1;                                       /* Trim Bits, bit 6 */
    byte TRM7        :1;                                       /* Trim Bits, bit 7 */
  } Bits;
} VREFTRMSTR;
extern volatile VREFTRMSTR _VREFTRM @0x0000005C;
#define VREFTRM                         _VREFTRM.Byte
#define VREFTRM_TRM0                    _VREFTRM.Bits.TRM0
#define VREFTRM_TRM1                    _VREFTRM.Bits.TRM1
#define VREFTRM_TRM2                    _VREFTRM.Bits.TRM2
#define VREFTRM_TRM3                    _VREFTRM.Bits.TRM3
#define VREFTRM_TRM4                    _VREFTRM.Bits.TRM4
#define VREFTRM_TRM5                    _VREFTRM.Bits.TRM5
#define VREFTRM_TRM6                    _VREFTRM.Bits.TRM6
#define VREFTRM_TRM7                    _VREFTRM.Bits.TRM7

#define VREFTRM_TRM0_MASK               1U
#define VREFTRM_TRM1_MASK               2U
#define VREFTRM_TRM2_MASK               4U
#define VREFTRM_TRM3_MASK               8U
#define VREFTRM_TRM4_MASK               16U
#define VREFTRM_TRM5_MASK               32U
#define VREFTRM_TRM6_MASK               64U
#define VREFTRM_TRM7_MASK               128U


/*** VREFSC - VREF Control Register; 0x0000005D ***/
typedef union {
  byte Byte;
  struct {
    byte MODE0       :1;                                       /* Mode selection, bit 0 */
    byte MODE1       :1;                                       /* Mode selection, bit 1 */
    byte VREFST      :1;                                       /* Internal Voltage Reference Stable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte VREFEN      :1;                                       /* Internal Voltage Reference Enable */
  } Bits;
  struct {
    byte grpMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} VREFSCSTR;
extern volatile VREFSCSTR _VREFSC @0x0000005D;
#define VREFSC                          _VREFSC.Byte
#define VREFSC_MODE0                    _VREFSC.Bits.MODE0
#define VREFSC_MODE1                    _VREFSC.Bits.MODE1
#define VREFSC_VREFST                   _VREFSC.Bits.VREFST
#define VREFSC_VREFEN                   _VREFSC.Bits.VREFEN
#define VREFSC_MODE                     _VREFSC.MergedBits.grpMODE

#define VREFSC_MODE0_MASK               1U
#define VREFSC_MODE1_MASK               2U
#define VREFSC_VREFST_MASK              4U
#define VREFSC_VREFEN_MASK              128U
#define VREFSC_MODE_MASK                3U
#define VREFSC_MODE_BITNUM              0U


/*** IRQSC - Interrupt request status and control register; 0x0000005F ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC @0x0000005F;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1U
#define IRQSC_IRQIE_MASK                2U
#define IRQSC_IRQACK_MASK               4U
#define IRQSC_IRQF_MASK                 8U
#define IRQSC_IRQPE_MASK                16U
#define IRQSC_IRQEDG_MASK               32U
#define IRQSC_IRQPDD_MASK               64U


/*** IICA1 - IIC Address Register; 0x00000060 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICA1 - IIC Address Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte AD1         :1;                                       /* Slave Address Bit 1 */
        byte AD2         :1;                                       /* Slave Address Bit 2 */
        byte AD3         :1;                                       /* Slave Address Bit 3 */
        byte AD4         :1;                                       /* Slave Address Bit 4 */
        byte AD5         :1;                                       /* Slave Address Bit 5 */
        byte AD6         :1;                                       /* Slave Address Bit 6 */
        byte AD7         :1;                                       /* Slave Address Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IICA1STR;
    #define IICA1                       _IICA1.Byte
    #define IICA1_AD1                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD1
    #define IICA1_AD2                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD2
    #define IICA1_AD3                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD3
    #define IICA1_AD4                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD4
    #define IICA1_AD5                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD5
    #define IICA1_AD6                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD6
    #define IICA1_AD7                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD7
    #define IICA1_AD_1                  _IICA1.SameAddr_STR.IICA1STR.MergedBits.grpAD_1
    #define IICA1_AD                    IICA1_AD_1
    
    #define IICA1_AD1_MASK              2U
    #define IICA1_AD2_MASK              4U
    #define IICA1_AD3_MASK              8U
    #define IICA1_AD4_MASK              16U
    #define IICA1_AD5_MASK              32U
    #define IICA1_AD6_MASK              64U
    #define IICA1_AD7_MASK              128U
    #define IICA1_AD_1_MASK             254U
    #define IICA1_AD_1_BITNUM           1U
    
    /*** IICA - IIC Address Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte AD1         :1;                                       /* Slave Address Bit 1 */
        byte AD2         :1;                                       /* Slave Address Bit 2 */
        byte AD3         :1;                                       /* Slave Address Bit 3 */
        byte AD4         :1;                                       /* Slave Address Bit 4 */
        byte AD5         :1;                                       /* Slave Address Bit 5 */
        byte AD6         :1;                                       /* Slave Address Bit 6 */
        byte AD7         :1;                                       /* Slave Address Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IICASTR;
    #define IICA                        _IICA1.Byte
    #define IICA_AD1                    _IICA1.SameAddr_STR.IICASTR.Bits.AD1
    #define IICA_AD2                    _IICA1.SameAddr_STR.IICASTR.Bits.AD2
    #define IICA_AD3                    _IICA1.SameAddr_STR.IICASTR.Bits.AD3
    #define IICA_AD4                    _IICA1.SameAddr_STR.IICASTR.Bits.AD4
    #define IICA_AD5                    _IICA1.SameAddr_STR.IICASTR.Bits.AD5
    #define IICA_AD6                    _IICA1.SameAddr_STR.IICASTR.Bits.AD6
    #define IICA_AD7                    _IICA1.SameAddr_STR.IICASTR.Bits.AD7
    #define IICA_AD_1                   _IICA1.SameAddr_STR.IICASTR.MergedBits.grpAD_1
    #define IICA_AD                     IICA_AD_1
    
    #define IICA_AD1_MASK               2U
    #define IICA_AD2_MASK               4U
    #define IICA_AD3_MASK               8U
    #define IICA_AD4_MASK               16U
    #define IICA_AD5_MASK               32U
    #define IICA_AD6_MASK               64U
    #define IICA_AD7_MASK               128U
    #define IICA_AD_1_MASK              254U
    #define IICA_AD_1_BITNUM            1U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICA1STR;
extern volatile IICA1STR _IICA1 @0x00000060;


/*** IICF - IIC Frequency Divider Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x00000061;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1U
#define IICF_ICR1_MASK                  2U
#define IICF_ICR2_MASK                  4U
#define IICF_ICR3_MASK                  8U
#define IICF_ICR4_MASK                  16U
#define IICF_ICR5_MASK                  32U
#define IICF_MULT0_MASK                 64U
#define IICF_MULT1_MASK                 128U
#define IICF_ICR_MASK                   63U
#define IICF_ICR_BITNUM                 0U
#define IICF_MULT_MASK                  192U
#define IICF_MULT_BITNUM                6U


/*** IICC1 - IIC Control Register 1; 0x00000062 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4U
    #define IICC1_TXAK_MASK             8U
    #define IICC1_TX_MASK               16U
    #define IICC1_MST_MASK              32U
    #define IICC1_IICIE_MASK            64U
    #define IICC1_IICEN_MASK            128U
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4U
    #define IICC_TXAK_MASK              8U
    #define IICC_TX_MASK                16U
    #define IICC_MST_MASK               32U
    #define IICC_IICIE_MASK             64U
    #define IICC_IICEN_MASK             128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0x00000062;


/*** IICS - IIC Status Register; 0x00000063 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x00000063;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1U
#define IICS_IICIF_MASK                 2U
#define IICS_SRW_MASK                   4U
#define IICS_ARBL_MASK                  16U
#define IICS_BUSY_MASK                  32U
#define IICS_IAAS_MASK                  64U
#define IICS_TCF_MASK                   128U


/*** IICD - IIC Data I/O Register; 0x00000064 ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x00000064;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1U
#define IICD_DATA1_MASK                 2U
#define IICD_DATA2_MASK                 4U
#define IICD_DATA3_MASK                 8U
#define IICD_DATA4_MASK                 16U
#define IICD_DATA5_MASK                 32U
#define IICD_DATA6_MASK                 64U
#define IICD_DATA7_MASK                 128U


/*** IICC2 - IIC Control Register 2; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0x00000065;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1U
#define IICC2_AD9_MASK                  2U
#define IICC2_AD10_MASK                 4U
#define IICC2_ADEXT_MASK                64U
#define IICC2_GCAEN_MASK                128U
#define IICC2_AD_8_MASK                 7U
#define IICC2_AD_8_BITNUM               0U


/*** IICSMB - SMBus Control and Status Register; 0x00000066 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte SHTF        :1;                                       /* SCL High Timeout Flag */
    byte SLTF        :1;                                       /* SCL Low Timeout Flag */
    byte TCKSEL      :1;                                       /* Time Out Counter Clock Select */
    byte SIICAEN     :1;                                       /* Second IIC Address Enable */
    byte ALERTEN     :1;                                       /* SMBus Alert Response Address Enable */
    byte FACK        :1;                                       /* Fast NACK/ACK enable */
  } Bits;
} IICSMBSTR;
extern volatile IICSMBSTR _IICSMB @0x00000066;
#define IICSMB                          _IICSMB.Byte
#define IICSMB_SHTF                     _IICSMB.Bits.SHTF
#define IICSMB_SLTF                     _IICSMB.Bits.SLTF
#define IICSMB_TCKSEL                   _IICSMB.Bits.TCKSEL
#define IICSMB_SIICAEN                  _IICSMB.Bits.SIICAEN
#define IICSMB_ALERTEN                  _IICSMB.Bits.ALERTEN
#define IICSMB_FACK                     _IICSMB.Bits.FACK

#define IICSMB_SHTF_MASK                4U
#define IICSMB_SLTF_MASK                8U
#define IICSMB_TCKSEL_MASK              16U
#define IICSMB_SIICAEN_MASK             32U
#define IICSMB_ALERTEN_MASK             64U
#define IICSMB_FACK_MASK                128U


/*** IICA2 - IIC Address Register 2; 0x00000067 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SAD1        :1;                                       /* SMBus Address Bit 1 */
    byte SAD2        :1;                                       /* SMBus Address Bit 2 */
    byte SAD3        :1;                                       /* SMBus Address Bit 3 */
    byte SAD4        :1;                                       /* SMBus Address Bit 4 */
    byte SAD5        :1;                                       /* SMBus Address Bit 5 */
    byte SAD6        :1;                                       /* SMBus Address Bit 6 */
    byte SAD7        :1;                                       /* SMBus Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpSAD_1 :7;
  } MergedBits;
} IICA2STR;
extern volatile IICA2STR _IICA2 @0x00000067;
#define IICA2                           _IICA2.Byte
#define IICA2_SAD1                      _IICA2.Bits.SAD1
#define IICA2_SAD2                      _IICA2.Bits.SAD2
#define IICA2_SAD3                      _IICA2.Bits.SAD3
#define IICA2_SAD4                      _IICA2.Bits.SAD4
#define IICA2_SAD5                      _IICA2.Bits.SAD5
#define IICA2_SAD6                      _IICA2.Bits.SAD6
#define IICA2_SAD7                      _IICA2.Bits.SAD7
#define IICA2_SAD_1                     _IICA2.MergedBits.grpSAD_1
#define IICA2_SAD                       IICA2_SAD_1

#define IICA2_SAD1_MASK                 2U
#define IICA2_SAD2_MASK                 4U
#define IICA2_SAD3_MASK                 8U
#define IICA2_SAD4_MASK                 16U
#define IICA2_SAD5_MASK                 32U
#define IICA2_SAD6_MASK                 64U
#define IICA2_SAD7_MASK                 128U
#define IICA2_SAD_1_MASK                254U
#define IICA2_SAD_1_BITNUM              1U


/*** IICSLT - IIC SCL Low Time Out register; 0x00000068 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** IICSLTH - IIC SCL Low Time Out register - High byte; 0x00000068 ***/
    union {
      byte Byte;
      struct {
        byte SSLT8       :1;                                       /* SCL Low Time Out Bit 8 */
        byte SSLT9       :1;                                       /* SCL Low Time Out Bit 9 */
        byte SSLT10      :1;                                       /* SCL Low Time Out Bit 10 */
        byte SSLT11      :1;                                       /* SCL Low Time Out Bit 11 */
        byte SSLT12      :1;                                       /* SCL Low Time Out Bit 12 */
        byte SSLT13      :1;                                       /* SCL Low Time Out Bit 13 */
        byte SSLT14      :1;                                       /* SCL Low Time Out Bit 14 */
        byte SSLT15      :1;                                       /* SCL Low Time Out Bit 15 */
      } Bits;
    } IICSLTHSTR;
    #define IICSLTH                     _IICSLT.Overlap_STR.IICSLTHSTR.Byte
    #define IICSLTH_SSLT8               _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT8
    #define IICSLTH_SSLT9               _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT9
    #define IICSLTH_SSLT10              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT10
    #define IICSLTH_SSLT11              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT11
    #define IICSLTH_SSLT12              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT12
    #define IICSLTH_SSLT13              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT13
    #define IICSLTH_SSLT14              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT14
    #define IICSLTH_SSLT15              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT15
    
    #define IICSLTH_SSLT8_MASK          1U
    #define IICSLTH_SSLT9_MASK          2U
    #define IICSLTH_SSLT10_MASK         4U
    #define IICSLTH_SSLT11_MASK         8U
    #define IICSLTH_SSLT12_MASK         16U
    #define IICSLTH_SSLT13_MASK         32U
    #define IICSLTH_SSLT14_MASK         64U
    #define IICSLTH_SSLT15_MASK         128U
    

    /*** IICSLTL - IIC SCL Low Time Out register - Low byte; 0x00000069 ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
        byte SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
        byte SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
        byte SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
        byte SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
        byte SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
        byte SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
        byte SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
      } Bits;
    } IICSLTLSTR;
    #define IICSLTL                     _IICSLT.Overlap_STR.IICSLTLSTR.Byte
    #define IICSLTL_SSLT0               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT0
    #define IICSLTL_SSLT1               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT1
    #define IICSLTL_SSLT2               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT2
    #define IICSLTL_SSLT3               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT3
    #define IICSLTL_SSLT4               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT4
    #define IICSLTL_SSLT5               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT5
    #define IICSLTL_SSLT6               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT6
    #define IICSLTL_SSLT7               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT7
    
    #define IICSLTL_SSLT0_MASK          1U
    #define IICSLTL_SSLT1_MASK          2U
    #define IICSLTL_SSLT2_MASK          4U
    #define IICSLTL_SSLT3_MASK          8U
    #define IICSLTL_SSLT4_MASK          16U
    #define IICSLTL_SSLT5_MASK          32U
    #define IICSLTL_SSLT6_MASK          64U
    #define IICSLTL_SSLT7_MASK          128U
    
  } Overlap_STR;

} IICSLTSTR;
extern volatile IICSLTSTR _IICSLT @0x00000068;
#define IICSLT                          _IICSLT.Word


/*** IICFLT - IIC Filter register; 0x0000006A ***/
typedef union {
  byte Byte;
  struct {
    byte FLT0        :1;                                       /* Filter value bit 0 */
    byte FLT1        :1;                                       /* Filter value bit 1 */
    byte FLT2        :1;                                       /* Filter value bit 2 */
    byte FLT3        :1;                                       /* Filter value bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICFLTSTR;
extern volatile IICFLTSTR _IICFLT @0x0000006A;
#define IICFLT                          _IICFLT.Byte
#define IICFLT_FLT0                     _IICFLT.Bits.FLT0
#define IICFLT_FLT1                     _IICFLT.Bits.FLT1
#define IICFLT_FLT2                     _IICFLT.Bits.FLT2
#define IICFLT_FLT3                     _IICFLT.Bits.FLT3
#define IICFLT_FLT                      _IICFLT.MergedBits.grpFLT

#define IICFLT_FLT0_MASK                1U
#define IICFLT_FLT1_MASK                2U
#define IICFLT_FLT2_MASK                4U
#define IICFLT_FLT3_MASK                8U
#define IICFLT_FLT_MASK                 15U
#define IICFLT_FLT_BITNUM               0U


/*** KBI1SC - KBI1 Status and Control Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte KBI1MOD     :1;                                       /* Keyboard Detection Mode */
    byte KB1IE       :1;                                       /* Keyboard Interrupt Enable */
    byte KB1ACK      :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KB1F        :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1SCSTR;
extern volatile KBI1SCSTR _KBI1SC @0x0000006C;
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBI1MOD                  _KBI1SC.Bits.KBI1MOD
#define KBI1SC_KB1IE                    _KBI1SC.Bits.KB1IE
#define KBI1SC_KB1ACK                   _KBI1SC.Bits.KB1ACK
#define KBI1SC_KB1F                     _KBI1SC.Bits.KB1F

#define KBI1SC_KBI1MOD_MASK             1U
#define KBI1SC_KB1IE_MASK               2U
#define KBI1SC_KB1ACK_MASK              4U
#define KBI1SC_KB1F_MASK                8U


/*** KBI1PE - KBI1 Pin Enable Register; 0x0000006D ***/
typedef union {
  byte Byte;
  struct {
    byte KBI1PE0     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBI1PE1     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBI1PE2     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBI1PE3     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBI1PE4     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBI1PE5     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBI1PE6     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBI1PE7     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI1PESTR;
extern volatile KBI1PESTR _KBI1PE @0x0000006D;
#define KBI1PE                          _KBI1PE.Byte
#define KBI1PE_KBI1PE0                  _KBI1PE.Bits.KBI1PE0
#define KBI1PE_KBI1PE1                  _KBI1PE.Bits.KBI1PE1
#define KBI1PE_KBI1PE2                  _KBI1PE.Bits.KBI1PE2
#define KBI1PE_KBI1PE3                  _KBI1PE.Bits.KBI1PE3
#define KBI1PE_KBI1PE4                  _KBI1PE.Bits.KBI1PE4
#define KBI1PE_KBI1PE5                  _KBI1PE.Bits.KBI1PE5
#define KBI1PE_KBI1PE6                  _KBI1PE.Bits.KBI1PE6
#define KBI1PE_KBI1PE7                  _KBI1PE.Bits.KBI1PE7

#define KBI1PE_KBI1PE0_MASK             1U
#define KBI1PE_KBI1PE1_MASK             2U
#define KBI1PE_KBI1PE2_MASK             4U
#define KBI1PE_KBI1PE3_MASK             8U
#define KBI1PE_KBI1PE4_MASK             16U
#define KBI1PE_KBI1PE5_MASK             32U
#define KBI1PE_KBI1PE6_MASK             64U
#define KBI1PE_KBI1PE7_MASK             128U


/*** KBI1ES - KBI1 Edge Select Register; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte KB1EDG0     :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KB1EDG1     :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KB1EDG2     :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KB1EDG3     :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KB1EDG4     :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KB1EDG5     :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KB1EDG6     :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KB1EDG7     :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI1ESSTR;
extern volatile KBI1ESSTR _KBI1ES @0x0000006E;
#define KBI1ES                          _KBI1ES.Byte
#define KBI1ES_KB1EDG0                  _KBI1ES.Bits.KB1EDG0
#define KBI1ES_KB1EDG1                  _KBI1ES.Bits.KB1EDG1
#define KBI1ES_KB1EDG2                  _KBI1ES.Bits.KB1EDG2
#define KBI1ES_KB1EDG3                  _KBI1ES.Bits.KB1EDG3
#define KBI1ES_KB1EDG4                  _KBI1ES.Bits.KB1EDG4
#define KBI1ES_KB1EDG5                  _KBI1ES.Bits.KB1EDG5
#define KBI1ES_KB1EDG6                  _KBI1ES.Bits.KB1EDG6
#define KBI1ES_KB1EDG7                  _KBI1ES.Bits.KB1EDG7

#define KBI1ES_KB1EDG0_MASK             1U
#define KBI1ES_KB1EDG1_MASK             2U
#define KBI1ES_KB1EDG2_MASK             4U
#define KBI1ES_KB1EDG3_MASK             8U
#define KBI1ES_KB1EDG4_MASK             16U
#define KBI1ES_KB1EDG5_MASK             32U
#define KBI1ES_KB1EDG6_MASK             64U
#define KBI1ES_KB1EDG7_MASK             128U


/*** SPI1C1 - SPI1 Control Register 1; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI1C1STR;
extern volatile SPI1C1STR _SPI1C1 @0x00000070;
#define SPI1C1                          _SPI1C1.Byte
#define SPI1C1_LSBFE                    _SPI1C1.Bits.LSBFE
#define SPI1C1_SSOE                     _SPI1C1.Bits.SSOE
#define SPI1C1_CPHA                     _SPI1C1.Bits.CPHA
#define SPI1C1_CPOL                     _SPI1C1.Bits.CPOL
#define SPI1C1_MSTR                     _SPI1C1.Bits.MSTR
#define SPI1C1_SPTIE                    _SPI1C1.Bits.SPTIE
#define SPI1C1_SPE                      _SPI1C1.Bits.SPE
#define SPI1C1_SPIE                     _SPI1C1.Bits.SPIE

#define SPI1C1_LSBFE_MASK               1U
#define SPI1C1_SSOE_MASK                2U
#define SPI1C1_CPHA_MASK                4U
#define SPI1C1_CPOL_MASK                8U
#define SPI1C1_MSTR_MASK                16U
#define SPI1C1_SPTIE_MASK               32U
#define SPI1C1_SPE_MASK                 64U
#define SPI1C1_SPIE_MASK                128U


/*** SPI1C2 - SPI1 Control Register 2; 0x00000071 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8- or 16-bit Mode Select */
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPI1C2STR;
extern volatile SPI1C2STR _SPI1C2 @0x00000071;
#define SPI1C2                          _SPI1C2.Byte
#define SPI1C2_SPC0                     _SPI1C2.Bits.SPC0
#define SPI1C2_SPISWAI                  _SPI1C2.Bits.SPISWAI
#define SPI1C2_BIDIROE                  _SPI1C2.Bits.BIDIROE
#define SPI1C2_MODFEN                   _SPI1C2.Bits.MODFEN
#define SPI1C2_SPIMODE                  _SPI1C2.Bits.SPIMODE
#define SPI1C2_SPMIE                    _SPI1C2.Bits.SPMIE

#define SPI1C2_SPC0_MASK                1U
#define SPI1C2_SPISWAI_MASK             2U
#define SPI1C2_BIDIROE_MASK             8U
#define SPI1C2_MODFEN_MASK              16U
#define SPI1C2_SPIMODE_MASK             64U
#define SPI1C2_SPMIE_MASK               128U


/*** SPI1BR - SPI1 Baud Rate Register; 0x00000072 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte SPR3        :1;                                       /* SPI Baud Rate Divisor Bit 3 */
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI1BRSTR;
extern volatile SPI1BRSTR _SPI1BR @0x00000072;
#define SPI1BR                          _SPI1BR.Byte
#define SPI1BR_SPR0                     _SPI1BR.Bits.SPR0
#define SPI1BR_SPR1                     _SPI1BR.Bits.SPR1
#define SPI1BR_SPR2                     _SPI1BR.Bits.SPR2
#define SPI1BR_SPR3                     _SPI1BR.Bits.SPR3
#define SPI1BR_SPPR0                    _SPI1BR.Bits.SPPR0
#define SPI1BR_SPPR1                    _SPI1BR.Bits.SPPR1
#define SPI1BR_SPPR2                    _SPI1BR.Bits.SPPR2
#define SPI1BR_SPR                      _SPI1BR.MergedBits.grpSPR
#define SPI1BR_SPPR                     _SPI1BR.MergedBits.grpSPPR

#define SPI1BR_SPR0_MASK                1U
#define SPI1BR_SPR1_MASK                2U
#define SPI1BR_SPR2_MASK                4U
#define SPI1BR_SPR3_MASK                8U
#define SPI1BR_SPPR0_MASK               16U
#define SPI1BR_SPPR1_MASK               32U
#define SPI1BR_SPPR2_MASK               64U
#define SPI1BR_SPR_MASK                 15U
#define SPI1BR_SPR_BITNUM               0U
#define SPI1BR_SPPR_MASK                112U
#define SPI1BR_SPPR_BITNUM              4U


/*** SPI1S - SPI1 Status Register; 0x00000073 ***/
typedef union {
  byte Byte;
  struct {
    byte RFIFOEF     :1;                                       /* SPI Read FIFO Empty Flag */
    byte TXFULLF     :1;                                       /* SPI Transmit FIFO Full Flag */
    byte TNEAREF     :1;                                       /* SPI Transmit FIFO Nearly Empty Flag */
    byte RNFULLF     :1;                                       /* SPI Receive FIFO Nearly Full Flag */
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI1SSTR;
extern volatile SPI1SSTR _SPI1S @0x00000073;
#define SPI1S                           _SPI1S.Byte
#define SPI1S_RFIFOEF                   _SPI1S.Bits.RFIFOEF
#define SPI1S_TXFULLF                   _SPI1S.Bits.TXFULLF
#define SPI1S_TNEAREF                   _SPI1S.Bits.TNEAREF
#define SPI1S_RNFULLF                   _SPI1S.Bits.RNFULLF
#define SPI1S_MODF                      _SPI1S.Bits.MODF
#define SPI1S_SPTEF                     _SPI1S.Bits.SPTEF
#define SPI1S_SPMF                      _SPI1S.Bits.SPMF
#define SPI1S_SPRF                      _SPI1S.Bits.SPRF

#define SPI1S_RFIFOEF_MASK              1U
#define SPI1S_TXFULLF_MASK              2U
#define SPI1S_TNEAREF_MASK              4U
#define SPI1S_RNFULLF_MASK              8U
#define SPI1S_MODF_MASK                 16U
#define SPI1S_SPTEF_MASK                32U
#define SPI1S_SPMF_MASK                 64U
#define SPI1S_SPRF_MASK                 128U


/*** SPI1D16 - SPI1 Data Register; 0x00000074 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1DH - SPI1 Data Register High; 0x00000074 ***/
    union {
      byte Byte;
    } SPI1DHSTR;
    #define SPI1DH                      _SPI1D16.Overlap_STR.SPI1DHSTR.Byte
    

    /*** SPI1DL - SPI1 Data Register Low; 0x00000075 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SPI1DL - SPI1 Data Register Low; Several registers at the same address ***/
        #define SPI1DL                  _SPI1D16.Overlap_STR.SPI1DLSTR.Byte
        
        /*** SPI1D - SPI1 Data Register Low; Several registers at the same address ***/
        union {
          struct {
            byte Bit0        :1;                                       /* SPI Data Bit 0 */
            byte Bit1        :1;                                       /* SPI Data Bit 1 */
            byte Bit2        :1;                                       /* SPI Data Bit 2 */
            byte Bit3        :1;                                       /* SPI Data Bit 3 */
            byte Bit4        :1;                                       /* SPI Data Bit 4 */
            byte Bit5        :1;                                       /* SPI Data Bit 5 */
            byte Bit6        :1;                                       /* SPI Data Bit 6 */
            byte Bit7        :1;                                       /* SPI Data Bit 7 */
          } Bits;
        } SPI1DSTR;
        #define SPI1D                   _SPI1D16.Overlap_STR.SPI1DLSTR.Byte
        #define SPI1D_Bit0              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit0
        #define SPI1D_Bit1              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit1
        #define SPI1D_Bit2              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit2
        #define SPI1D_Bit3              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit3
        #define SPI1D_Bit4              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit4
        #define SPI1D_Bit5              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit5
        #define SPI1D_Bit6              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit6
        #define SPI1D_Bit7              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit7
        
        #define SPI1D_Bit0_MASK         1U
        #define SPI1D_Bit1_MASK         2U
        #define SPI1D_Bit2_MASK         4U
        #define SPI1D_Bit3_MASK         8U
        #define SPI1D_Bit4_MASK         16U
        #define SPI1D_Bit5_MASK         32U
        #define SPI1D_Bit6_MASK         64U
        #define SPI1D_Bit7_MASK         128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SPI1DLSTR;
    
  } Overlap_STR;

} SPI1D16STR;
extern volatile SPI1D16STR _SPI1D16 @0x00000074;
#define SPI1D16                         _SPI1D16.Word


/*** SPI1M - SPI1 Match Register; 0x00000076 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1MH - SPI1 Match Register High; 0x00000076 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* SPI Match Value Bit 8 */
        byte Bit9        :1;                                       /* SPI Match Value Bit 9 */
        byte Bit10       :1;                                       /* SPI Match Value Bit 10 */
        byte Bit11       :1;                                       /* SPI Match Value Bit 11 */
        byte Bit12       :1;                                       /* SPI Match Value Bit 12 */
        byte Bit13       :1;                                       /* SPI Match Value Bit 13 */
        byte Bit14       :1;                                       /* SPI Match Value Bit 14 */
        byte Bit15       :1;                                       /* SPI Match Value Bit 15 */
      } Bits;
    } SPI1MHSTR;
    #define SPI1MH                      _SPI1M.Overlap_STR.SPI1MHSTR.Byte
    #define SPI1MH_Bit8                 _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit8
    #define SPI1MH_Bit9                 _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit9
    #define SPI1MH_Bit10                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit10
    #define SPI1MH_Bit11                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit11
    #define SPI1MH_Bit12                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit12
    #define SPI1MH_Bit13                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit13
    #define SPI1MH_Bit14                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit14
    #define SPI1MH_Bit15                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit15
    
    #define SPI1MH_Bit8_MASK            1U
    #define SPI1MH_Bit9_MASK            2U
    #define SPI1MH_Bit10_MASK           4U
    #define SPI1MH_Bit11_MASK           8U
    #define SPI1MH_Bit12_MASK           16U
    #define SPI1MH_Bit13_MASK           32U
    #define SPI1MH_Bit14_MASK           64U
    #define SPI1MH_Bit15_MASK           128U
    

    /*** SPI1ML - SPI1 Match Register Low; 0x00000077 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
        byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
        byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
        byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
        byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
        byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
        byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
        byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
      } Bits;
    } SPI1MLSTR;
    #define SPI1ML                      _SPI1M.Overlap_STR.SPI1MLSTR.Byte
    #define SPI1ML_Bit0                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit0
    #define SPI1ML_Bit1                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit1
    #define SPI1ML_Bit2                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit2
    #define SPI1ML_Bit3                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit3
    #define SPI1ML_Bit4                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit4
    #define SPI1ML_Bit5                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit5
    #define SPI1ML_Bit6                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit6
    #define SPI1ML_Bit7                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit7
    
    #define SPI1ML_Bit0_MASK            1U
    #define SPI1ML_Bit1_MASK            2U
    #define SPI1ML_Bit2_MASK            4U
    #define SPI1ML_Bit3_MASK            8U
    #define SPI1ML_Bit4_MASK            16U
    #define SPI1ML_Bit5_MASK            32U
    #define SPI1ML_Bit6_MASK            64U
    #define SPI1ML_Bit7_MASK            128U
    
  } Overlap_STR;

} SPI1MSTR;
extern volatile SPI1MSTR _SPI1M @0x00000076;
#define SPI1M                           _SPI1M.Word


/*** SPI1C3 - SPI1 Control Register 3; 0x00000078 ***/
typedef union {
  byte Byte;
  struct {
    byte FIFOMODE    :1;                                       /* SPI FIFO Mode Enable */
    byte RNFULLIEN   :1;                                       /* Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPIE in the SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte TNEARIEN    :1;                                       /* Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPTIE in the <br/>SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte INTCLR      :1;                                       /* Interrupt Clearing Mechanism Select - This bit selects the mechanism by which SPRF, SPTEF, TNEAREF, RNFULLF interrupts gets cleared */
    byte RNFULLF_MARK :1;                                      /* Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag is asserted */
    byte TNEAREF_MARK :1;                                      /* Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag is asserted */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI1C3STR;
extern volatile SPI1C3STR _SPI1C3 @0x00000078;
#define SPI1C3                          _SPI1C3.Byte
#define SPI1C3_FIFOMODE                 _SPI1C3.Bits.FIFOMODE
#define SPI1C3_RNFULLIEN                _SPI1C3.Bits.RNFULLIEN
#define SPI1C3_TNEARIEN                 _SPI1C3.Bits.TNEARIEN
#define SPI1C3_INTCLR                   _SPI1C3.Bits.INTCLR
#define SPI1C3_RNFULLF_MARK             _SPI1C3.Bits.RNFULLF_MARK
#define SPI1C3_TNEAREF_MARK             _SPI1C3.Bits.TNEAREF_MARK

#define SPI1C3_FIFOMODE_MASK            1U
#define SPI1C3_RNFULLIEN_MASK           2U
#define SPI1C3_TNEARIEN_MASK            4U
#define SPI1C3_INTCLR_MASK              8U
#define SPI1C3_RNFULLF_MARK_MASK        16U
#define SPI1C3_TNEAREF_MARK_MASK        32U


/*** SPI1CI - SPI1 Clear Interrupt Register; 0x00000079 ***/
typedef union {
  byte Byte;
  struct {
    byte SPRFCI      :1;                                       /* Receive FIFO Full Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt provided SPIxC3[3] is set */
    byte SPTEFCI     :1;                                       /* Transmit FIFO Empty Flag Clear Interrupt Bit - Write of 1 clears the SPTEF interrupt provided SPIxC3[3] SPTEFCI is set */
    byte RNFULLFCI   :1;                                       /* Receive FIFO Nearly Full Flag Clear Interrupt - Write of 1 clears the RNFULLF interrupt provided SPIxC3[3] is set */
    byte TNEAREFCI   :1;                                       /* Transmit FIFO Nearly Empty Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt provided SPIxC3[3] is set */
    byte RXFOF       :1;                                       /* RX FIFO Overflow Flag - This Flag indicates that RX FIFO overflow condition has occured */
    byte TXFOF       :1;                                       /* TX FIFO Overflow Flag - This Flag indicates that TX FIFO overflow condition has occured */
    byte RXFERR      :1;                                       /* Receive FIFO Error Flag - This flag indicates that RX FIFO error occured because entries in fifo goes above 8 */
    byte TXFERR      :1;                                       /* Transmit FIFO ErrorFlag - This flag indicates that TX FIFO error occured because entries in fifo goes above 8 */
  } Bits;
} SPI1CISTR;
extern volatile SPI1CISTR _SPI1CI @0x00000079;
#define SPI1CI                          _SPI1CI.Byte
#define SPI1CI_SPRFCI                   _SPI1CI.Bits.SPRFCI
#define SPI1CI_SPTEFCI                  _SPI1CI.Bits.SPTEFCI
#define SPI1CI_RNFULLFCI                _SPI1CI.Bits.RNFULLFCI
#define SPI1CI_TNEAREFCI                _SPI1CI.Bits.TNEAREFCI
#define SPI1CI_RXFOF                    _SPI1CI.Bits.RXFOF
#define SPI1CI_TXFOF                    _SPI1CI.Bits.TXFOF
#define SPI1CI_RXFERR                   _SPI1CI.Bits.RXFERR
#define SPI1CI_TXFERR                   _SPI1CI.Bits.TXFERR

#define SPI1CI_SPRFCI_MASK              1U
#define SPI1CI_SPTEFCI_MASK             2U
#define SPI1CI_RNFULLFCI_MASK           4U
#define SPI1CI_TNEAREFCI_MASK           8U
#define SPI1CI_RXFOF_MASK               16U
#define SPI1CI_TXFOF_MASK               32U
#define SPI1CI_RXFERR_MASK              64U
#define SPI1CI_TXFERR_MASK              128U


/*** KBI2SC - KBI2 Status and Control Register; 0x0000007C ***/
typedef union {
  byte Byte;
  struct {
    byte KBI2MOD     :1;                                       /* Keyboard Detection Mode */
    byte KB2IE       :1;                                       /* Keyboard Interrupt Enable */
    byte KB2ACK      :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KB2F        :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI2SCSTR;
extern volatile KBI2SCSTR _KBI2SC @0x0000007C;
#define KBI2SC                          _KBI2SC.Byte
#define KBI2SC_KBI2MOD                  _KBI2SC.Bits.KBI2MOD
#define KBI2SC_KB2IE                    _KBI2SC.Bits.KB2IE
#define KBI2SC_KB2ACK                   _KBI2SC.Bits.KB2ACK
#define KBI2SC_KB2F                     _KBI2SC.Bits.KB2F

#define KBI2SC_KBI2MOD_MASK             1U
#define KBI2SC_KB2IE_MASK               2U
#define KBI2SC_KB2ACK_MASK              4U
#define KBI2SC_KB2F_MASK                8U


/*** KBI2PE - KBI2 Pin Enable Register; 0x0000007D ***/
typedef union {
  byte Byte;
  struct {
    byte KBI2PE0     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBI2PE1     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBI2PE2     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBI2PE3     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBI2PE4     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBI2PE5     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBI2PE6     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBI2PE7     :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI2PESTR;
extern volatile KBI2PESTR _KBI2PE @0x0000007D;
#define KBI2PE                          _KBI2PE.Byte
#define KBI2PE_KBI2PE0                  _KBI2PE.Bits.KBI2PE0
#define KBI2PE_KBI2PE1                  _KBI2PE.Bits.KBI2PE1
#define KBI2PE_KBI2PE2                  _KBI2PE.Bits.KBI2PE2
#define KBI2PE_KBI2PE3                  _KBI2PE.Bits.KBI2PE3
#define KBI2PE_KBI2PE4                  _KBI2PE.Bits.KBI2PE4
#define KBI2PE_KBI2PE5                  _KBI2PE.Bits.KBI2PE5
#define KBI2PE_KBI2PE6                  _KBI2PE.Bits.KBI2PE6
#define KBI2PE_KBI2PE7                  _KBI2PE.Bits.KBI2PE7

#define KBI2PE_KBI2PE0_MASK             1U
#define KBI2PE_KBI2PE1_MASK             2U
#define KBI2PE_KBI2PE2_MASK             4U
#define KBI2PE_KBI2PE3_MASK             8U
#define KBI2PE_KBI2PE4_MASK             16U
#define KBI2PE_KBI2PE5_MASK             32U
#define KBI2PE_KBI2PE6_MASK             64U
#define KBI2PE_KBI2PE7_MASK             128U


/*** KBI2ES - KBI2 Edge Select Register; 0x0000007E ***/
typedef union {
  byte Byte;
  struct {
    byte KB2EDG0     :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KB2EDG1     :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KB2EDG2     :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KB2EDG3     :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KB2EDG4     :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KB2EDG5     :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KB2EDG6     :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KB2EDG7     :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI2ESSTR;
extern volatile KBI2ESSTR _KBI2ES @0x0000007E;
#define KBI2ES                          _KBI2ES.Byte
#define KBI2ES_KB2EDG0                  _KBI2ES.Bits.KB2EDG0
#define KBI2ES_KB2EDG1                  _KBI2ES.Bits.KB2EDG1
#define KBI2ES_KB2EDG2                  _KBI2ES.Bits.KB2EDG2
#define KBI2ES_KB2EDG3                  _KBI2ES.Bits.KB2EDG3
#define KBI2ES_KB2EDG4                  _KBI2ES.Bits.KB2EDG4
#define KBI2ES_KB2EDG5                  _KBI2ES.Bits.KB2EDG5
#define KBI2ES_KB2EDG6                  _KBI2ES.Bits.KB2EDG6
#define KBI2ES_KB2EDG7                  _KBI2ES.Bits.KB2EDG7

#define KBI2ES_KB2EDG0_MASK             1U
#define KBI2ES_KB2EDG1_MASK             2U
#define KBI2ES_KB2EDG2_MASK             4U
#define KBI2ES_KB2EDG3_MASK             8U
#define KBI2ES_KB2EDG4_MASK             16U
#define KBI2ES_KB2EDG5_MASK             32U
#define KBI2ES_KB2EDG6_MASK             64U
#define KBI2ES_KB2EDG7_MASK             128U


/*** USBCTL0 - USB Control Register 0; 0x00000080 ***/
typedef union {
  byte Byte;
  struct {
    byte USBPHYEN    :1;                                       /* USB PHY Tranceiver Enable */
    byte             :1; 
    byte USBVREN     :1;                                       /* USB Voltage Regulator Enable */
    byte             :1; 
    byte LPRESF      :1;                                       /* Low-Power Resume Flag */
    byte USBRESMEN   :1;                                       /* USB Low-Power Resume Event Enable */
    byte USBPU       :1;                                       /* Pull Up Source */
    byte USBRESET    :1;                                       /* USB Reset */
  } Bits;
} USBCTL0STR;
extern volatile USBCTL0STR _USBCTL0 @0x00000080;
#define USBCTL0                         _USBCTL0.Byte
#define USBCTL0_USBPHYEN                _USBCTL0.Bits.USBPHYEN
#define USBCTL0_USBVREN                 _USBCTL0.Bits.USBVREN
#define USBCTL0_LPRESF                  _USBCTL0.Bits.LPRESF
#define USBCTL0_USBRESMEN               _USBCTL0.Bits.USBRESMEN
#define USBCTL0_USBPU                   _USBCTL0.Bits.USBPU
#define USBCTL0_USBRESET                _USBCTL0.Bits.USBRESET

#define USBCTL0_USBPHYEN_MASK           1U
#define USBCTL0_USBVREN_MASK            4U
#define USBCTL0_LPRESF_MASK             16U
#define USBCTL0_USBRESMEN_MASK          32U
#define USBCTL0_USBPU_MASK              64U
#define USBCTL0_USBRESET_MASK           128U


/*** PERID - Peripheral ID Register; 0x00000088 ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Peripheral Configuration Number Bit 0 */
    byte ID1         :1;                                       /* Peripheral Configuration Number Bit 1 */
    byte ID2         :1;                                       /* Peripheral Configuration Number Bit 2 */
    byte ID3         :1;                                       /* Peripheral Configuration Number Bit 3 */
    byte ID4         :1;                                       /* Peripheral Configuration Number Bit 4 */
    byte ID5         :1;                                       /* Peripheral Configuration Number Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpID   :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERIDSTR;
extern volatile PERIDSTR _PERID @0x00000088;
#define PERID                           _PERID.Byte
#define PERID_ID0                       _PERID.Bits.ID0
#define PERID_ID1                       _PERID.Bits.ID1
#define PERID_ID2                       _PERID.Bits.ID2
#define PERID_ID3                       _PERID.Bits.ID3
#define PERID_ID4                       _PERID.Bits.ID4
#define PERID_ID5                       _PERID.Bits.ID5
#define PERID_ID                        _PERID.MergedBits.grpID

#define PERID_ID0_MASK                  1U
#define PERID_ID1_MASK                  2U
#define PERID_ID2_MASK                  4U
#define PERID_ID3_MASK                  8U
#define PERID_ID4_MASK                  16U
#define PERID_ID5_MASK                  32U
#define PERID_ID_MASK                   63U
#define PERID_ID_BITNUM                 0U


/*** IDCOMP - Peripheral ID Complement Register; 0x00000089 ***/
typedef union {
  byte Byte;
  struct {
    byte NID0        :1;                                       /* Complement ID Number Bit 0 */
    byte NID1        :1;                                       /* Complement ID Number Bit 1 */
    byte NID2        :1;                                       /* Complement ID Number Bit 2 */
    byte NID3        :1;                                       /* Complement ID Number Bit 3 */
    byte NID4        :1;                                       /* Complement ID Number Bit 4 */
    byte NID5        :1;                                       /* Complement ID Number Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpNID  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} IDCOMPSTR;
extern volatile IDCOMPSTR _IDCOMP @0x00000089;
#define IDCOMP                          _IDCOMP.Byte
#define IDCOMP_NID0                     _IDCOMP.Bits.NID0
#define IDCOMP_NID1                     _IDCOMP.Bits.NID1
#define IDCOMP_NID2                     _IDCOMP.Bits.NID2
#define IDCOMP_NID3                     _IDCOMP.Bits.NID3
#define IDCOMP_NID4                     _IDCOMP.Bits.NID4
#define IDCOMP_NID5                     _IDCOMP.Bits.NID5
#define IDCOMP_NID                      _IDCOMP.MergedBits.grpNID

#define IDCOMP_NID0_MASK                1U
#define IDCOMP_NID1_MASK                2U
#define IDCOMP_NID2_MASK                4U
#define IDCOMP_NID3_MASK                8U
#define IDCOMP_NID4_MASK                16U
#define IDCOMP_NID5_MASK                32U
#define IDCOMP_NID_MASK                 63U
#define IDCOMP_NID_BITNUM               0U


/*** REV - Peripheral Revision Register; 0x0000008A ***/
typedef union {
  byte Byte;
  struct {
    byte REV0        :1;                                       /* Revision Bit 0 */
    byte REV1        :1;                                       /* Revision Bit 1 */
    byte REV2        :1;                                       /* Revision Bit 2 */
    byte REV3        :1;                                       /* Revision Bit 3 */
    byte REV4        :1;                                       /* Revision Bit 4 */
    byte REV5        :1;                                       /* Revision Bit 5 */
    byte REV6        :1;                                       /* Revision Bit 6 */
    byte REV7        :1;                                       /* Revision Bit 7 */
  } Bits;
} REVSTR;
extern volatile REVSTR _REV @0x0000008A;
#define REV                             _REV.Byte
#define REV_REV0                        _REV.Bits.REV0
#define REV_REV1                        _REV.Bits.REV1
#define REV_REV2                        _REV.Bits.REV2
#define REV_REV3                        _REV.Bits.REV3
#define REV_REV4                        _REV.Bits.REV4
#define REV_REV5                        _REV.Bits.REV5
#define REV_REV6                        _REV.Bits.REV6
#define REV_REV7                        _REV.Bits.REV7

#define REV_REV0_MASK                   1U
#define REV_REV1_MASK                   2U
#define REV_REV2_MASK                   4U
#define REV_REV3_MASK                   8U
#define REV_REV4_MASK                   16U
#define REV_REV5_MASK                   32U
#define REV_REV6_MASK                   64U
#define REV_REV7_MASK                   128U


/*** INTSTAT - Interrupt Status Register; 0x00000090 ***/
typedef union {
  byte Byte;
  struct {
    byte USBRSTF     :1;                                       /* USB Reset Flag */
    byte ERRORF      :1;                                       /* Error Flag */
    byte SOFTOKF     :1;                                       /* SOF Token Flag */
    byte TOKDNEF     :1;                                       /* Token Complete Flag */
    byte SLEEPF      :1;                                       /* Sleep Flag */
    byte RESUMEF     :1;                                       /* Resume Flag */
    byte             :1; 
    byte STALLF      :1;                                       /* Stall Flag */
  } Bits;
} INTSTATSTR;
extern volatile INTSTATSTR _INTSTAT @0x00000090;
#define INTSTAT                         _INTSTAT.Byte
#define INTSTAT_USBRSTF                 _INTSTAT.Bits.USBRSTF
#define INTSTAT_ERRORF                  _INTSTAT.Bits.ERRORF
#define INTSTAT_SOFTOKF                 _INTSTAT.Bits.SOFTOKF
#define INTSTAT_TOKDNEF                 _INTSTAT.Bits.TOKDNEF
#define INTSTAT_SLEEPF                  _INTSTAT.Bits.SLEEPF
#define INTSTAT_RESUMEF                 _INTSTAT.Bits.RESUMEF
#define INTSTAT_STALLF                  _INTSTAT.Bits.STALLF

#define INTSTAT_USBRSTF_MASK            1U
#define INTSTAT_ERRORF_MASK             2U
#define INTSTAT_SOFTOKF_MASK            4U
#define INTSTAT_TOKDNEF_MASK            8U
#define INTSTAT_SLEEPF_MASK             16U
#define INTSTAT_RESUMEF_MASK            32U
#define INTSTAT_STALLF_MASK             128U


/*** INTENB - Interrupt Enable Register; 0x00000091 ***/
typedef union {
  byte Byte;
  struct {
    byte USBRST      :1;                                       /* USBRST Interrupt Enable */
    byte ERROR       :1;                                       /* ERROR Interrupt Enable */
    byte SOFTOK      :1;                                       /* SOFTOK Interrupt Enable */
    byte TOKDNE      :1;                                       /* TOKDNE Interrupt Enable */
    byte SLEEP       :1;                                       /* SLEEP Interrupt Enable */
    byte RESUME      :1;                                       /* RESUME Interrupt Enable */
    byte             :1; 
    byte STALL       :1;                                       /* STALL Interrupt Enable */
  } Bits;
} INTENBSTR;
extern volatile INTENBSTR _INTENB @0x00000091;
#define INTENB                          _INTENB.Byte
#define INTENB_USBRST                   _INTENB.Bits.USBRST
#define INTENB_ERROR                    _INTENB.Bits.ERROR
#define INTENB_SOFTOK                   _INTENB.Bits.SOFTOK
#define INTENB_TOKDNE                   _INTENB.Bits.TOKDNE
#define INTENB_SLEEP                    _INTENB.Bits.SLEEP
#define INTENB_RESUME                   _INTENB.Bits.RESUME
#define INTENB_STALL                    _INTENB.Bits.STALL

#define INTENB_USBRST_MASK              1U
#define INTENB_ERROR_MASK               2U
#define INTENB_SOFTOK_MASK              4U
#define INTENB_TOKDNE_MASK              8U
#define INTENB_SLEEP_MASK               16U
#define INTENB_RESUME_MASK              32U
#define INTENB_STALL_MASK               128U


/*** ERRSTAT - Error Interrupt Status Register; 0x00000092 ***/
typedef union {
  byte Byte;
  struct {
    byte PIDERRF     :1;                                       /* PID Error Flag */
    byte CRC5F       :1;                                       /* CRC5 Error Flag */
    byte CRC16F      :1;                                       /* CRC16 Error Flag */
    byte DFN8F       :1;                                       /* Data Field Error Flag */
    byte BTOERRF     :1;                                       /* Bus Turnaround Error Timeout Flag */
    byte BUFERRF     :1;                                       /* Buffer Error Flag */
    byte             :1; 
    byte BTSERRF     :1;                                       /* Bit Stuff Error Flag */
  } Bits;
} ERRSTATSTR;
extern volatile ERRSTATSTR _ERRSTAT @0x00000092;
#define ERRSTAT                         _ERRSTAT.Byte
#define ERRSTAT_PIDERRF                 _ERRSTAT.Bits.PIDERRF
#define ERRSTAT_CRC5F                   _ERRSTAT.Bits.CRC5F
#define ERRSTAT_CRC16F                  _ERRSTAT.Bits.CRC16F
#define ERRSTAT_DFN8F                   _ERRSTAT.Bits.DFN8F
#define ERRSTAT_BTOERRF                 _ERRSTAT.Bits.BTOERRF
#define ERRSTAT_BUFERRF                 _ERRSTAT.Bits.BUFERRF
#define ERRSTAT_BTSERRF                 _ERRSTAT.Bits.BTSERRF

#define ERRSTAT_PIDERRF_MASK            1U
#define ERRSTAT_CRC5F_MASK              2U
#define ERRSTAT_CRC16F_MASK             4U
#define ERRSTAT_DFN8F_MASK              8U
#define ERRSTAT_BTOERRF_MASK            16U
#define ERRSTAT_BUFERRF_MASK            32U
#define ERRSTAT_BTSERRF_MASK            128U


/*** ERRENB - Error Interrupt Enable Register; 0x00000093 ***/
typedef union {
  byte Byte;
  struct {
    byte PIDERR      :1;                                       /* PIDERR Interrupt Enable */
    byte CRC5        :1;                                       /* CRC5 Interrupt Enable */
    byte CRC16       :1;                                       /* CRC16 Interrupt Enable */
    byte DFN8        :1;                                       /* DFN8 Interrupt Enable */
    byte BTOERR      :1;                                       /* BTOERR Interrupt Enable */
    byte BUFERR      :1;                                       /* BUFERR Interrupt Enable */
    byte             :1; 
    byte BTSERR      :1;                                       /* BTSERR Interrupt Enable */
  } Bits;
} ERRENBSTR;
extern volatile ERRENBSTR _ERRENB @0x00000093;
#define ERRENB                          _ERRENB.Byte
#define ERRENB_PIDERR                   _ERRENB.Bits.PIDERR
#define ERRENB_CRC5                     _ERRENB.Bits.CRC5
#define ERRENB_CRC16                    _ERRENB.Bits.CRC16
#define ERRENB_DFN8                     _ERRENB.Bits.DFN8
#define ERRENB_BTOERR                   _ERRENB.Bits.BTOERR
#define ERRENB_BUFERR                   _ERRENB.Bits.BUFERR
#define ERRENB_BTSERR                   _ERRENB.Bits.BTSERR

#define ERRENB_PIDERR_MASK              1U
#define ERRENB_CRC5_MASK                2U
#define ERRENB_CRC16_MASK               4U
#define ERRENB_DFN8_MASK                8U
#define ERRENB_BTOERR_MASK              16U
#define ERRENB_BUFERR_MASK              32U
#define ERRENB_BTSERR_MASK              128U


/*** STAT - Status Register; 0x00000094 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ODD         :1;                                       /* Odd/Even Transaction */
    byte IN          :1;                                       /* In/Out Transaction */
    byte ENDP0       :1;                                       /* Endpoint Number Bit 0 */
    byte ENDP1       :1;                                       /* Endpoint Number Bit 1 */
    byte ENDP2       :1;                                       /* Endpoint Number Bit 2 */
    byte ENDP3       :1;                                       /* Endpoint Number Bit 3 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpENDP :4;
  } MergedBits;
} STATSTR;
extern volatile STATSTR _STAT @0x00000094;
#define STAT                            _STAT.Byte
#define STAT_ODD                        _STAT.Bits.ODD
#define STAT_IN                         _STAT.Bits.IN
#define STAT_ENDP0                      _STAT.Bits.ENDP0
#define STAT_ENDP1                      _STAT.Bits.ENDP1
#define STAT_ENDP2                      _STAT.Bits.ENDP2
#define STAT_ENDP3                      _STAT.Bits.ENDP3
#define STAT_ENDP                       _STAT.MergedBits.grpENDP

#define STAT_ODD_MASK                   4U
#define STAT_IN_MASK                    8U
#define STAT_ENDP0_MASK                 16U
#define STAT_ENDP1_MASK                 32U
#define STAT_ENDP2_MASK                 64U
#define STAT_ENDP3_MASK                 128U
#define STAT_ENDP_MASK                  240U
#define STAT_ENDP_BITNUM                4U


/*** CTL - Control Register; 0x00000095 ***/
typedef union {
  byte Byte;
  struct {
    byte USBEN       :1;                                       /* USB Enable */
    byte ODDRST      :1;                                       /* Odd Reset */
    byte CRESUME     :1;                                       /* Resume Signaling */
    byte             :1; 
    byte             :1; 
    byte TSUSPEND    :1;                                       /* Transaction Suspend */
    byte             :1; 
    byte             :1; 
  } Bits;
} CTLSTR;
extern volatile CTLSTR _CTL @0x00000095;
#define CTL                             _CTL.Byte
#define CTL_USBEN                       _CTL.Bits.USBEN
#define CTL_ODDRST                      _CTL.Bits.ODDRST
#define CTL_CRESUME                     _CTL.Bits.CRESUME
#define CTL_TSUSPEND                    _CTL.Bits.TSUSPEND

#define CTL_USBEN_MASK                  1U
#define CTL_ODDRST_MASK                 2U
#define CTL_CRESUME_MASK                4U
#define CTL_TSUSPEND_MASK               32U


/*** ADDR - Address Register; 0x00000096 ***/
typedef union {
  byte Byte;
  struct {
    byte ADDR0       :1;                                       /* USB Address Bit 0 */
    byte ADDR1       :1;                                       /* USB Address Bit 1 */
    byte ADDR2       :1;                                       /* USB Address Bit 2 */
    byte ADDR3       :1;                                       /* USB Address Bit 3 */
    byte ADDR4       :1;                                       /* USB Address Bit 4 */
    byte ADDR5       :1;                                       /* USB Address Bit 5 */
    byte ADDR6       :1;                                       /* USB Address Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpADDR :7;
    byte         :1;
  } MergedBits;
} ADDRSTR;
extern volatile ADDRSTR _ADDR @0x00000096;
#define ADDR                            _ADDR.Byte
#define ADDR_ADDR0                      _ADDR.Bits.ADDR0
#define ADDR_ADDR1                      _ADDR.Bits.ADDR1
#define ADDR_ADDR2                      _ADDR.Bits.ADDR2
#define ADDR_ADDR3                      _ADDR.Bits.ADDR3
#define ADDR_ADDR4                      _ADDR.Bits.ADDR4
#define ADDR_ADDR5                      _ADDR.Bits.ADDR5
#define ADDR_ADDR6                      _ADDR.Bits.ADDR6
#define ADDR_ADDR                       _ADDR.MergedBits.grpADDR

#define ADDR_ADDR0_MASK                 1U
#define ADDR_ADDR1_MASK                 2U
#define ADDR_ADDR2_MASK                 4U
#define ADDR_ADDR3_MASK                 8U
#define ADDR_ADDR4_MASK                 16U
#define ADDR_ADDR5_MASK                 32U
#define ADDR_ADDR6_MASK                 64U
#define ADDR_ADDR_MASK                  127U
#define ADDR_ADDR_BITNUM                0U


/*** FRMNUML - Frame Number Register Low; 0x00000097 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM0        :1;                                       /* Frame Number Bit 0 */
    byte FRM1        :1;                                       /* Frame Number Bit 1 */
    byte FRM2        :1;                                       /* Frame Number Bit 2 */
    byte FRM3        :1;                                       /* Frame Number Bit 3 */
    byte FRM4        :1;                                       /* Frame Number Bit 4 */
    byte FRM5        :1;                                       /* Frame Number Bit 5 */
    byte FRM6        :1;                                       /* Frame Number Bit 6 */
    byte FRM7        :1;                                       /* Frame Number Bit 7 */
  } Bits;
} FRMNUMLSTR;
extern volatile FRMNUMLSTR _FRMNUML @0x00000097;
#define FRMNUML                         _FRMNUML.Byte
#define FRMNUML_FRM0                    _FRMNUML.Bits.FRM0
#define FRMNUML_FRM1                    _FRMNUML.Bits.FRM1
#define FRMNUML_FRM2                    _FRMNUML.Bits.FRM2
#define FRMNUML_FRM3                    _FRMNUML.Bits.FRM3
#define FRMNUML_FRM4                    _FRMNUML.Bits.FRM4
#define FRMNUML_FRM5                    _FRMNUML.Bits.FRM5
#define FRMNUML_FRM6                    _FRMNUML.Bits.FRM6
#define FRMNUML_FRM7                    _FRMNUML.Bits.FRM7

#define FRMNUML_FRM0_MASK               1U
#define FRMNUML_FRM1_MASK               2U
#define FRMNUML_FRM2_MASK               4U
#define FRMNUML_FRM3_MASK               8U
#define FRMNUML_FRM4_MASK               16U
#define FRMNUML_FRM5_MASK               32U
#define FRMNUML_FRM6_MASK               64U
#define FRMNUML_FRM7_MASK               128U


/*** FRMNUMH - Frame Number Register High; 0x00000098 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM8        :1;                                       /* Frame Number Bit 8 */
    byte FRM9        :1;                                       /* Frame Number Bit 9 */
    byte FRM10       :1;                                       /* Frame Number Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFRM_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FRMNUMHSTR;
extern volatile FRMNUMHSTR _FRMNUMH @0x00000098;
#define FRMNUMH                         _FRMNUMH.Byte
#define FRMNUMH_FRM8                    _FRMNUMH.Bits.FRM8
#define FRMNUMH_FRM9                    _FRMNUMH.Bits.FRM9
#define FRMNUMH_FRM10                   _FRMNUMH.Bits.FRM10
#define FRMNUMH_FRM_8                   _FRMNUMH.MergedBits.grpFRM_8
#define FRMNUMH_FRM                     FRMNUMH_FRM_8

#define FRMNUMH_FRM8_MASK               1U
#define FRMNUMH_FRM9_MASK               2U
#define FRMNUMH_FRM10_MASK              4U
#define FRMNUMH_FRM_8_MASK              7U
#define FRMNUMH_FRM_8_BITNUM            0U


/*** EPCTL0 - Endpoint Control Register 0; 0x0000009D ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL0STR;
extern volatile EPCTL0STR _EPCTL0 @0x0000009D;
#define EPCTL0                          _EPCTL0.Byte
#define EPCTL0_EPHSHK                   _EPCTL0.Bits.EPHSHK
#define EPCTL0_EPSTALL                  _EPCTL0.Bits.EPSTALL
#define EPCTL0_EPTXEN                   _EPCTL0.Bits.EPTXEN
#define EPCTL0_EPRXEN                   _EPCTL0.Bits.EPRXEN
#define EPCTL0_EPCTLDIS                 _EPCTL0.Bits.EPCTLDIS
/* EPCTL_ARR: Access 7 EPCTLx registers in an array */
#define EPCTL_ARR                       ((volatile byte * __far) &EPCTL0)

#define EPCTL0_EPHSHK_MASK              1U
#define EPCTL0_EPSTALL_MASK             2U
#define EPCTL0_EPTXEN_MASK              4U
#define EPCTL0_EPRXEN_MASK              8U
#define EPCTL0_EPCTLDIS_MASK            16U


/*** EPCTL1 - Endpoint Control Register 1; 0x0000009E ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL1STR;
extern volatile EPCTL1STR _EPCTL1 @0x0000009E;
#define EPCTL1                          _EPCTL1.Byte
#define EPCTL1_EPHSHK                   _EPCTL1.Bits.EPHSHK
#define EPCTL1_EPSTALL                  _EPCTL1.Bits.EPSTALL
#define EPCTL1_EPTXEN                   _EPCTL1.Bits.EPTXEN
#define EPCTL1_EPRXEN                   _EPCTL1.Bits.EPRXEN
#define EPCTL1_EPCTLDIS                 _EPCTL1.Bits.EPCTLDIS

#define EPCTL1_EPHSHK_MASK              1U
#define EPCTL1_EPSTALL_MASK             2U
#define EPCTL1_EPTXEN_MASK              4U
#define EPCTL1_EPRXEN_MASK              8U
#define EPCTL1_EPCTLDIS_MASK            16U


/*** EPCTL2 - Endpoint Control Register 2; 0x0000009F ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL2STR;
extern volatile EPCTL2STR _EPCTL2 @0x0000009F;
#define EPCTL2                          _EPCTL2.Byte
#define EPCTL2_EPHSHK                   _EPCTL2.Bits.EPHSHK
#define EPCTL2_EPSTALL                  _EPCTL2.Bits.EPSTALL
#define EPCTL2_EPTXEN                   _EPCTL2.Bits.EPTXEN
#define EPCTL2_EPRXEN                   _EPCTL2.Bits.EPRXEN
#define EPCTL2_EPCTLDIS                 _EPCTL2.Bits.EPCTLDIS

#define EPCTL2_EPHSHK_MASK              1U
#define EPCTL2_EPSTALL_MASK             2U
#define EPCTL2_EPTXEN_MASK              4U
#define EPCTL2_EPRXEN_MASK              8U
#define EPCTL2_EPCTLDIS_MASK            16U


/*** EPCTL3 - Endpoint Control Register 3; 0x000000A0 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL3STR;
extern volatile EPCTL3STR _EPCTL3 @0x000000A0;
#define EPCTL3                          _EPCTL3.Byte
#define EPCTL3_EPHSHK                   _EPCTL3.Bits.EPHSHK
#define EPCTL3_EPSTALL                  _EPCTL3.Bits.EPSTALL
#define EPCTL3_EPTXEN                   _EPCTL3.Bits.EPTXEN
#define EPCTL3_EPRXEN                   _EPCTL3.Bits.EPRXEN
#define EPCTL3_EPCTLDIS                 _EPCTL3.Bits.EPCTLDIS

#define EPCTL3_EPHSHK_MASK              1U
#define EPCTL3_EPSTALL_MASK             2U
#define EPCTL3_EPTXEN_MASK              4U
#define EPCTL3_EPRXEN_MASK              8U
#define EPCTL3_EPCTLDIS_MASK            16U


/*** EPCTL4 - Endpoint Control Register 4; 0x000000A1 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL4STR;
extern volatile EPCTL4STR _EPCTL4 @0x000000A1;
#define EPCTL4                          _EPCTL4.Byte
#define EPCTL4_EPHSHK                   _EPCTL4.Bits.EPHSHK
#define EPCTL4_EPSTALL                  _EPCTL4.Bits.EPSTALL
#define EPCTL4_EPTXEN                   _EPCTL4.Bits.EPTXEN
#define EPCTL4_EPRXEN                   _EPCTL4.Bits.EPRXEN
#define EPCTL4_EPCTLDIS                 _EPCTL4.Bits.EPCTLDIS

#define EPCTL4_EPHSHK_MASK              1U
#define EPCTL4_EPSTALL_MASK             2U
#define EPCTL4_EPTXEN_MASK              4U
#define EPCTL4_EPRXEN_MASK              8U
#define EPCTL4_EPCTLDIS_MASK            16U


/*** EPCTL5 - Endpoint Control Register 5; 0x000000A2 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL5STR;
extern volatile EPCTL5STR _EPCTL5 @0x000000A2;
#define EPCTL5                          _EPCTL5.Byte
#define EPCTL5_EPHSHK                   _EPCTL5.Bits.EPHSHK
#define EPCTL5_EPSTALL                  _EPCTL5.Bits.EPSTALL
#define EPCTL5_EPTXEN                   _EPCTL5.Bits.EPTXEN
#define EPCTL5_EPRXEN                   _EPCTL5.Bits.EPRXEN
#define EPCTL5_EPCTLDIS                 _EPCTL5.Bits.EPCTLDIS

#define EPCTL5_EPHSHK_MASK              1U
#define EPCTL5_EPSTALL_MASK             2U
#define EPCTL5_EPTXEN_MASK              4U
#define EPCTL5_EPRXEN_MASK              8U
#define EPCTL5_EPCTLDIS_MASK            16U


/*** EPCTL6 - Endpoint Control Register 6; 0x000000A3 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL6STR;
extern volatile EPCTL6STR _EPCTL6 @0x000000A3;
#define EPCTL6                          _EPCTL6.Byte
#define EPCTL6_EPHSHK                   _EPCTL6.Bits.EPHSHK
#define EPCTL6_EPSTALL                  _EPCTL6.Bits.EPSTALL
#define EPCTL6_EPTXEN                   _EPCTL6.Bits.EPTXEN
#define EPCTL6_EPRXEN                   _EPCTL6.Bits.EPRXEN
#define EPCTL6_EPCTLDIS                 _EPCTL6.Bits.EPCTLDIS

#define EPCTL6_EPHSHK_MASK              1U
#define EPCTL6_EPSTALL_MASK             2U
#define EPCTL6_EPTXEN_MASK              4U
#define EPCTL6_EPRXEN_MASK              8U
#define EPCTL6_EPCTLDIS_MASK            16U


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte LOC         :1;                                       /* Loss-of-Clock Reset */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_LOC                         _SRS.Bits.LOC
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_LOC_MASK                    4U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte RSTPE       :1;                                       /* RESET Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte             :1; 
    byte BLMSS       :1;                                       /* Boot Loader Mode Select Status */
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_RSTPE                     _SOPT1.Bits.RSTPE
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_BLMSS                     _SOPT1.Bits.BLMSS
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_RSTPE_MASK                1U
#define SOPT1_BKGDPE_MASK               2U
#define SOPT1_BLMSS_MASK                8U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT0_MASK                64U
#define SOPT1_COPT1_MASK                128U
#define SOPT1_COPT_MASK                 192U
#define SOPT1_COPT_BITNUM               6U


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CLKOUT_EN   :1;                                       /* Clock Output Enable */
    byte             :1; 
    byte COPW        :1;                                       /* COP Window */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_ACIC                      _SOPT2.Bits.ACIC
#define SOPT2_CLKOUT_EN                 _SOPT2.Bits.CLKOUT_EN
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_ACIC_MASK                 1U
#define SOPT2_CLKOUT_EN_MASK            16U
#define SOPT2_COPW_MASK                 64U
#define SOPT2_COPCLKS_MASK              128U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte REV0        :1;                                       /* Revision Number, bit 0 */
        byte REV1        :1;                                       /* Revision Number, bit 1 */
        byte REV2        :1;                                       /* Revision Number, bit 2 */
        byte REV3        :1;                                       /* Revision Number, bit 3 */
      } Bits;
      struct {
        byte grpID_8 :4;
        byte grpREV :4;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_REV0                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV0
    #define SDIDH_REV1                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV1
    #define SDIDH_REV2                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV2
    #define SDIDH_REV3                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV3
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_REV                   _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpREV
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_REV0_MASK             16U
    #define SDIDH_REV1_MASK             32U
    #define SDIDH_REV2_MASK             64U
    #define SDIDH_REV3_MASK             128U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    #define SDIDH_REV_MASK              240U
    #define SDIDH_REV_BITNUM            4U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SCGC1 - System Clock Gating Control 1 Register; 0x00001808 ***/
typedef union {
  byte Byte;
  struct {
    byte SCI1        :1;                                       /* SCI1 Clock Gate Control */
    byte SCI2        :1;                                       /* SCI2 Clock Gate Control */
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte DAC         :1;                                       /* DAC Clock Gate Control */
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte TPM1        :1;                                       /* TPM1 Clock Gate Control */
    byte TPM2        :1;                                       /* TPM2 Clock Gate Control */
    byte CMT         :1;                                       /* CMT Clock Gate Control */
  } Bits;
  struct {
    byte grpSCI_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTPM_1 :2;
    byte         :1;
  } MergedBits;
} SCGC1STR;
extern volatile SCGC1STR _SCGC1 @0x00001808;
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI1                      _SCGC1.Bits.SCI1
#define SCGC1_SCI2                      _SCGC1.Bits.SCI2
#define SCGC1_IIC                       _SCGC1.Bits.IIC
#define SCGC1_DAC                       _SCGC1.Bits.DAC
#define SCGC1_ADC                       _SCGC1.Bits.ADC
#define SCGC1_TPM1                      _SCGC1.Bits.TPM1
#define SCGC1_TPM2                      _SCGC1.Bits.TPM2
#define SCGC1_CMT                       _SCGC1.Bits.CMT
#define SCGC1_SCI_1                     _SCGC1.MergedBits.grpSCI_1
#define SCGC1_TPM_1                     _SCGC1.MergedBits.grpTPM_1
#define SCGC1_SCI                       SCGC1_SCI_1
#define SCGC1_TPM                       SCGC1_TPM_1

#define SCGC1_SCI1_MASK                 1U
#define SCGC1_SCI2_MASK                 2U
#define SCGC1_IIC_MASK                  4U
#define SCGC1_DAC_MASK                  8U
#define SCGC1_ADC_MASK                  16U
#define SCGC1_TPM1_MASK                 32U
#define SCGC1_TPM2_MASK                 64U
#define SCGC1_CMT_MASK                  128U
#define SCGC1_SCI_1_MASK                3U
#define SCGC1_SCI_1_BITNUM              0U
#define SCGC1_TPM_1_MASK                96U
#define SCGC1_TPM_1_BITNUM              5U


/*** SCGC2 - System Clock Gating Control 2 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte SPI1        :1;                                       /* SPI1 Clock Gate Control */
    byte SPI2        :1;                                       /* SPI2 Clock Gate Control */
    byte TOD         :1;                                       /* TOD Clock Gate Control */
    byte PRACMP      :1;                                       /* PRACMP Clock Gate Control */
    byte KBI         :1;                                       /* KBI Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte PDB         :1;                                       /* PDB Register Clock Gate Control */
    byte USB         :1;                                       /* USB Clock Gate Control */
  } Bits;
  struct {
    byte grpSPI_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCGC2STR;
extern volatile SCGC2STR _SCGC2 @0x00001809;
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI1                      _SCGC2.Bits.SPI1
#define SCGC2_SPI2                      _SCGC2.Bits.SPI2
#define SCGC2_TOD                       _SCGC2.Bits.TOD
#define SCGC2_PRACMP                    _SCGC2.Bits.PRACMP
#define SCGC2_KBI                       _SCGC2.Bits.KBI
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_PDB                       _SCGC2.Bits.PDB
#define SCGC2_USB                       _SCGC2.Bits.USB
#define SCGC2_SPI_1                     _SCGC2.MergedBits.grpSPI_1
#define SCGC2_SPI                       SCGC2_SPI_1

#define SCGC2_SPI1_MASK                 1U
#define SCGC2_SPI2_MASK                 2U
#define SCGC2_TOD_MASK                  4U
#define SCGC2_PRACMP_MASK               8U
#define SCGC2_KBI_MASK                  16U
#define SCGC2_IRQ_MASK                  32U
#define SCGC2_PDB_MASK                  64U
#define SCGC2_USB_MASK                  128U
#define SCGC2_SPI_1_MASK                3U
#define SCGC2_SPI_1_BITNUM              0U


/*** SCGC3 - System Clock Gating Control 3 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte GPOA1       :1;                                       /* GPOA1 Clock Gate Control */
    byte GPOA2       :1;                                       /* GPOA2 Clock Gate Control */
    byte TRIAMP1     :1;                                       /* TRIAMP1 Clock Gate Control */
    byte TRIAMP2     :1;                                       /* TRIAMP2 Clock Gate Control */
    byte FLS1        :1;                                       /* FLS1 Clock Gate Control */
    byte             :1; 
    byte CRC         :1;                                       /* CRC Clock Gate Control */
    byte VREF        :1;                                       /* VREF Clock Gate Control */
  } Bits;
  struct {
    byte grpGPOA_1 :2;
    byte grpTRIAMP_1 :2;
    byte grpFLS_1 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCGC3STR;
extern volatile SCGC3STR _SCGC3 @0x0000180A;
#define SCGC3                           _SCGC3.Byte
#define SCGC3_GPOA1                     _SCGC3.Bits.GPOA1
#define SCGC3_GPOA2                     _SCGC3.Bits.GPOA2
#define SCGC3_TRIAMP1                   _SCGC3.Bits.TRIAMP1
#define SCGC3_TRIAMP2                   _SCGC3.Bits.TRIAMP2
#define SCGC3_FLS1                      _SCGC3.Bits.FLS1
#define SCGC3_CRC                       _SCGC3.Bits.CRC
#define SCGC3_VREF                      _SCGC3.Bits.VREF
#define SCGC3_GPOA_1                    _SCGC3.MergedBits.grpGPOA_1
#define SCGC3_TRIAMP_1                  _SCGC3.MergedBits.grpTRIAMP_1
#define SCGC3_GPOA                      SCGC3_GPOA_1
#define SCGC3_TRIAMP                    SCGC3_TRIAMP_1

#define SCGC3_GPOA1_MASK                1U
#define SCGC3_GPOA2_MASK                2U
#define SCGC3_TRIAMP1_MASK              4U
#define SCGC3_TRIAMP2_MASK              8U
#define SCGC3_FLS1_MASK                 16U
#define SCGC3_CRC_MASK                  64U
#define SCGC3_VREF_MASK                 128U
#define SCGC3_GPOA_1_MASK               3U
#define SCGC3_GPOA_1_BITNUM             0U
#define SCGC3_TRIAMP_1_MASK             12U
#define SCGC3_TRIAMP_1_BITNUM           2U


/*** SOPT3 - System Options 3 Register; 0x0000180B ***/
typedef union {
  byte Byte;
  struct {
    byte CMT_PAD     :1;                                       /* CMT pad drive strength */
    byte SCI1_PAD    :1;                                       /* SCI_PAD pad drive strength */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IICPS       :1;                                       /* IIC Pin Select */
    byte SCI1PS      :1;                                       /* SCI1 Pin Select */
    byte SCI2PS      :1;                                       /* SCI2 Pin Select */
  } Bits;
} SOPT3STR;
extern volatile SOPT3STR _SOPT3 @0x0000180B;
#define SOPT3                           _SOPT3.Byte
#define SOPT3_CMT_PAD                   _SOPT3.Bits.CMT_PAD
#define SOPT3_SCI1_PAD                  _SOPT3.Bits.SCI1_PAD
#define SOPT3_IICPS                     _SOPT3.Bits.IICPS
#define SOPT3_SCI1PS                    _SOPT3.Bits.SCI1PS
#define SOPT3_SCI2PS                    _SOPT3.Bits.SCI2PS

#define SOPT3_CMT_PAD_MASK              1U
#define SOPT3_SCI1_PAD_MASK             2U
#define SOPT3_IICPS_MASK                32U
#define SOPT3_SCI1PS_MASK               64U
#define SOPT3_SCI2PS_MASK               128U


/*** SOPT4 - System Options 4 Register; 0x0000180C ***/
typedef union {
  byte Byte;
  struct {
    byte IRODSE      :1;                                       /* Drive Strength Control Enable for IRO pin */
    byte IROSRE      :1;                                       /* Output Slew Rate Control Enable for IRO pin */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SOPT4STR;
extern volatile SOPT4STR _SOPT4 @0x0000180C;
#define SOPT4                           _SOPT4.Byte
#define SOPT4_IRODSE                    _SOPT4.Bits.IRODSE
#define SOPT4_IROSRE                    _SOPT4.Bits.IROSRE

#define SOPT4_IRODSE_MASK               1U
#define SOPT4_IROSRE_MASK               2U


/*** SIMIPS - SIM Internal Peripheral Select Register; 0x0000180E ***/
typedef union {
  byte Byte;
  struct {
    byte MODTX1      :1;                                       /* Modulate TX1 */
    byte             :1; 
    byte MTBASE10    :1;                                       /* SCI1 TX Modulation Time Base Select, bit 0 */
    byte MTBASE11    :1;                                       /* SCI1 TX Modulation Time Base Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte RX1IN       :1;                                       /* SCI1 RX Input Pin Select */
    byte ADCTRS      :1;                                       /* ADC HWTRG Select */
  } Bits;
  struct {
    byte grpMODTX_1 :1;
    byte         :1;
    byte grpMTBASE1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SIMIPSSTR;
extern volatile SIMIPSSTR _SIMIPS @0x0000180E;
#define SIMIPS                          _SIMIPS.Byte
#define SIMIPS_MODTX1                   _SIMIPS.Bits.MODTX1
#define SIMIPS_MTBASE10                 _SIMIPS.Bits.MTBASE10
#define SIMIPS_MTBASE11                 _SIMIPS.Bits.MTBASE11
#define SIMIPS_RX1IN                    _SIMIPS.Bits.RX1IN
#define SIMIPS_ADCTRS                   _SIMIPS.Bits.ADCTRS
#define SIMIPS_MTBASE1                  _SIMIPS.MergedBits.grpMTBASE1

#define SIMIPS_MODTX1_MASK              1U
#define SIMIPS_MTBASE10_MASK            4U
#define SIMIPS_MTBASE11_MASK            8U
#define SIMIPS_RX1IN_MASK               64U
#define SIMIPS_ADCTRS_MASK              128U
#define SIMIPS_MTBASE1_MASK             12U
#define SIMIPS_MTBASE1_BITNUM           2U


/*** SIGNATURE - SIGNATURE Register; 0x0000180F ***/
typedef union {
  byte Byte;
} SIGNATURESTR;
extern volatile SIGNATURESTR _SIGNATURE @0x0000180F;
#define SIGNATURE                       _SIGNATURE.Byte


/*** CCSCTRL - Clock Check & Select Control; 0x00001810 ***/
typedef union {
  byte Byte;
  struct {
    byte SEL         :1;                                       /* External Clock Select */
    byte TEST        :1;                                       /* TEST */
    byte EN          :1;                                       /* Enable clock for CCS */
    byte EREFS1      :1;                                       /* External Reference Select */
    byte OSCINIT1    :1;                                       /* Oscillator Initialization */
    byte ERCLKEN1    :1;                                       /* External Clock Enable */
    byte HGO1        :1;                                       /* High-Gain Oscillator Select */
    byte RANGE1      :1;                                       /* Frequency Range Select */
  } Bits;
} CCSCTRLSTR;
extern volatile CCSCTRLSTR _CCSCTRL @0x00001810;
#define CCSCTRL                         _CCSCTRL.Byte
#define CCSCTRL_SEL                     _CCSCTRL.Bits.SEL
#define CCSCTRL_TEST                    _CCSCTRL.Bits.TEST
#define CCSCTRL_EN                      _CCSCTRL.Bits.EN
#define CCSCTRL_EREFS1                  _CCSCTRL.Bits.EREFS1
#define CCSCTRL_OSCINIT1                _CCSCTRL.Bits.OSCINIT1
#define CCSCTRL_ERCLKEN1                _CCSCTRL.Bits.ERCLKEN1
#define CCSCTRL_HGO1                    _CCSCTRL.Bits.HGO1
#define CCSCTRL_RANGE1                  _CCSCTRL.Bits.RANGE1

#define CCSCTRL_SEL_MASK                1U
#define CCSCTRL_TEST_MASK               2U
#define CCSCTRL_EN_MASK                 4U
#define CCSCTRL_EREFS1_MASK             8U
#define CCSCTRL_OSCINIT1_MASK           16U
#define CCSCTRL_ERCLKEN1_MASK           32U
#define CCSCTRL_HGO1_MASK               64U
#define CCSCTRL_RANGE1_MASK             128U


/*** CCSTMR1 - CCS XOSC1 Timer Register; 0x00001811 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT10       :1;                                       /* CNT1, bit 0 */
    byte CNT11       :1;                                       /* CNT1, bit 1 */
    byte CNT12       :1;                                       /* CNT1, bit 2 */
    byte CNT13       :1;                                       /* CNT1, bit 3 */
    byte CNT14       :1;                                       /* CNT1, bit 4 */
    byte CNT15       :1;                                       /* CNT1, bit 5 */
    byte CNT16       :1;                                       /* CNT1, bit 6 */
    byte CNT17       :1;                                       /* CNT1, bit 7 */
  } Bits;
} CCSTMR1STR;
extern volatile CCSTMR1STR _CCSTMR1 @0x00001811;
#define CCSTMR1                         _CCSTMR1.Byte
#define CCSTMR1_CNT10                   _CCSTMR1.Bits.CNT10
#define CCSTMR1_CNT11                   _CCSTMR1.Bits.CNT11
#define CCSTMR1_CNT12                   _CCSTMR1.Bits.CNT12
#define CCSTMR1_CNT13                   _CCSTMR1.Bits.CNT13
#define CCSTMR1_CNT14                   _CCSTMR1.Bits.CNT14
#define CCSTMR1_CNT15                   _CCSTMR1.Bits.CNT15
#define CCSTMR1_CNT16                   _CCSTMR1.Bits.CNT16
#define CCSTMR1_CNT17                   _CCSTMR1.Bits.CNT17

#define CCSTMR1_CNT10_MASK              1U
#define CCSTMR1_CNT11_MASK              2U
#define CCSTMR1_CNT12_MASK              4U
#define CCSTMR1_CNT13_MASK              8U
#define CCSTMR1_CNT14_MASK              16U
#define CCSTMR1_CNT15_MASK              32U
#define CCSTMR1_CNT16_MASK              64U
#define CCSTMR1_CNT17_MASK              128U


/*** CCSTMR2 - CCS XOSC2 Timer Register; 0x00001812 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT20       :1;                                       /* CNT2, bit 0 */
    byte CNT21       :1;                                       /* CNT2, bit 1 */
    byte CNT22       :1;                                       /* CNT2, bit 2 */
    byte CNT23       :1;                                       /* CNT2, bit 3 */
    byte CNT24       :1;                                       /* CNT2, bit 4 */
    byte CNT25       :1;                                       /* CNT2, bit 5 */
    byte CNT26       :1;                                       /* CNT2, bit 6 */
    byte CNT27       :1;                                       /* CNT2, bit 7 */
  } Bits;
} CCSTMR2STR;
extern volatile CCSTMR2STR _CCSTMR2 @0x00001812;
#define CCSTMR2                         _CCSTMR2.Byte
#define CCSTMR2_CNT20                   _CCSTMR2.Bits.CNT20
#define CCSTMR2_CNT21                   _CCSTMR2.Bits.CNT21
#define CCSTMR2_CNT22                   _CCSTMR2.Bits.CNT22
#define CCSTMR2_CNT23                   _CCSTMR2.Bits.CNT23
#define CCSTMR2_CNT24                   _CCSTMR2.Bits.CNT24
#define CCSTMR2_CNT25                   _CCSTMR2.Bits.CNT25
#define CCSTMR2_CNT26                   _CCSTMR2.Bits.CNT26
#define CCSTMR2_CNT27                   _CCSTMR2.Bits.CNT27

#define CCSTMR2_CNT20_MASK              1U
#define CCSTMR2_CNT21_MASK              2U
#define CCSTMR2_CNT22_MASK              4U
#define CCSTMR2_CNT23_MASK              8U
#define CCSTMR2_CNT24_MASK              16U
#define CCSTMR2_CNT25_MASK              32U
#define CCSTMR2_CNT26_MASK              64U
#define CCSTMR2_CNT27_MASK              128U


/*** CCSTMRIR - CCS Internal Reference Clock Timer Register; 0x00001813 ***/
typedef union {
  byte Byte;
  struct {
    byte CNTIR0      :1;                                       /* CNTIR, bit 0 */
    byte CNTIR1      :1;                                       /* CNTIR, bit 1 */
    byte CNTIR2      :1;                                       /* CNTIR, bit 2 */
    byte CNTIR3      :1;                                       /* CNTIR, bit 3 */
    byte CNTIR4      :1;                                       /* CNTIR, bit 4 */
    byte CNTIR5      :1;                                       /* CNTIR, bit 5 */
    byte CNTIR6      :1;                                       /* CNTIR, bit 6 */
    byte CNTIR7      :1;                                       /* CNTIR, bit 7 */
  } Bits;
} CCSTMRIRSTR;
extern volatile CCSTMRIRSTR _CCSTMRIR @0x00001813;
#define CCSTMRIR                        _CCSTMRIR.Byte
#define CCSTMRIR_CNTIR0                 _CCSTMRIR.Bits.CNTIR0
#define CCSTMRIR_CNTIR1                 _CCSTMRIR.Bits.CNTIR1
#define CCSTMRIR_CNTIR2                 _CCSTMRIR.Bits.CNTIR2
#define CCSTMRIR_CNTIR3                 _CCSTMRIR.Bits.CNTIR3
#define CCSTMRIR_CNTIR4                 _CCSTMRIR.Bits.CNTIR4
#define CCSTMRIR_CNTIR5                 _CCSTMRIR.Bits.CNTIR5
#define CCSTMRIR_CNTIR6                 _CCSTMRIR.Bits.CNTIR6
#define CCSTMRIR_CNTIR7                 _CCSTMRIR.Bits.CNTIR7

#define CCSTMRIR_CNTIR0_MASK            1U
#define CCSTMRIR_CNTIR1_MASK            2U
#define CCSTMRIR_CNTIR2_MASK            4U
#define CCSTMRIR_CNTIR3_MASK            8U
#define CCSTMRIR_CNTIR4_MASK            16U
#define CCSTMRIR_CNTIR5_MASK            32U
#define CCSTMRIR_CNTIR6_MASK            64U
#define CCSTMRIR_CNTIR7_MASK            128U


/*** FPROTD - Flash Protection Disable Register; 0x00001814 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* Disable Flash protection */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FPROTDSTR;
extern volatile FPROTDSTR _FPROTD @0x00001814;
#define FPROTD                          _FPROTD.Byte
#define FPROTD_FPDIS                    _FPROTD.Bits.FPDIS

#define FPROTD_FPDIS_MASK               1U


/*** SIMCO - SIM Clock Set and Select Register; 0x00001819 ***/
typedef union {
  byte Byte;
  struct {
    byte CS0         :1;                                       /* CLKOUT Select, bit 0 */
    byte CS1         :1;                                       /* CLKOUT Select, bit 1 */
    byte CS2         :1;                                       /* CLKOUT Select, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCS   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SIMCOSTR;
extern volatile SIMCOSTR _SIMCO @0x00001819;
#define SIMCO                           _SIMCO.Byte
#define SIMCO_CS0                       _SIMCO.Bits.CS0
#define SIMCO_CS1                       _SIMCO.Bits.CS1
#define SIMCO_CS2                       _SIMCO.Bits.CS2
#define SIMCO_CS                        _SIMCO.MergedBits.grpCS

#define SIMCO_CS0_MASK                  1U
#define SIMCO_CS1_MASK                  2U
#define SIMCO_CS2_MASK                  4U
#define SIMCO_CS_MASK                   7U
#define SIMCO_CS_BITNUM                 0U


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x0000181C ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x0000181C;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVDIE_MASK               32U
#define SPMSC1_LVDACK_MASK              64U
#define SPMSC1_LVDF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000181D ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte PPDE        :1;                                       /* Partial Power-Down Enable */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte             :1; 
    byte LPWUI       :1;                                       /* Low Power Wake Up on Interrupt */
    byte LPRS        :1;                                       /* Low Power Regulator Status */
    byte LPR         :1;                                       /* Low Power Regulator Control */
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x0000181D;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDE                     _SPMSC2.Bits.PPDE
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LPWUI                    _SPMSC2.Bits.LPWUI
#define SPMSC2_LPRS                     _SPMSC2.Bits.LPRS
#define SPMSC2_LPR                      _SPMSC2.Bits.LPR

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDE_MASK                2U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LPWUI_MASK               32U
#define SPMSC2_LPRS_MASK                64U
#define SPMSC2_LPR_MASK                 128U


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000181F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
extern volatile SPMSC3STR _SPMSC3 @0x0000181F;
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWIE                    _SPMSC3.Bits.LVWIE
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWIE_MASK               8U
#define SPMSC3_LVWV_MASK                16U
#define SPMSC3_LVDV_MASK                32U
#define SPMSC3_LVWACK_MASK              64U
#define SPMSC3_LVWF_MASK                128U


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte FDIV1       :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte FDIV2       :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte FDIV3       :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte FDIV4       :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte FDIV5       :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte FDIVLD      :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_FDIV0                     _FCDIV.Bits.FDIV0
#define FCDIV_FDIV1                     _FCDIV.Bits.FDIV1
#define FCDIV_FDIV2                     _FCDIV.Bits.FDIV2
#define FCDIV_FDIV3                     _FCDIV.Bits.FDIV3
#define FCDIV_FDIV4                     _FCDIV.Bits.FDIV4
#define FCDIV_FDIV5                     _FCDIV.Bits.FDIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_FDIVLD                    _FCDIV.Bits.FDIVLD
#define FCDIV_FDIV                      _FCDIV.MergedBits.grpFDIV

#define FCDIV_FDIV0_MASK                1U
#define FCDIV_FDIV1_MASK                2U
#define FCDIV_FDIV2_MASK                4U
#define FCDIV_FDIV3_MASK                8U
#define FCDIV_FDIV4_MASK                16U
#define FCDIV_FDIV5_MASK                32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_FDIVLD_MASK               128U
#define FCDIV_FDIV_MASK                 63U
#define FCDIV_FDIV_BITNUM               0U


/*** FOPT - Flash Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_KEYEN0                     _FOPT.Bits.KEYEN0
#define FOPT_KEYEN1                     _FOPT.Bits.KEYEN1
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC
#define FOPT_KEYEN                      _FOPT.MergedBits.grpKEYEN

#define FOPT_SEC0_MASK                  1U
#define FOPT_SEC1_MASK                  2U
#define FOPT_KEYEN0_MASK                64U
#define FOPT_KEYEN1_MASK                128U
#define FOPT_SEC_MASK                   3U
#define FOPT_SEC_BITNUM                 0U
#define FOPT_KEYEN_MASK                 192U
#define FOPT_KEYEN_BITNUM               6U


/*** FCNFG - Flash Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - Flash Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS

#define FPROT_FPOPEN_MASK               1U
#define FPROT_FPS0_MASK                 2U
#define FPROT_FPS1_MASK                 4U
#define FPROT_FPS2_MASK                 8U
#define FPROT_FPS3_MASK                 16U
#define FPROT_FPS4_MASK                 32U
#define FPROT_FPS5_MASK                 64U
#define FPROT_FPS6_MASK                 128U
#define FPROT_FPS_MASK                  254U
#define FPROT_FPS_BITNUM                1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - Flash Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* Flash Command, bit 0 */
    byte FCMD1       :1;                                       /* Flash Command, bit 1 */
    byte FCMD2       :1;                                       /* Flash Command, bit 2 */
    byte FCMD3       :1;                                       /* Flash Command, bit 3 */
    byte FCMD4       :1;                                       /* Flash Command, bit 4 */
    byte FCMD5       :1;                                       /* Flash Command, bit 5 */
    byte FCMD6       :1;                                       /* Flash Command, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpFCMD :7;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD                       _FCMD.MergedBits.grpFCMD

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD_MASK                  127U
#define FCMD_FCMD_BITNUM                0U


/*** PTED - Port E Data Register; 0x00001830 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       /* Port E Data Register Bit 0 */
    byte PTED1       :1;                                       /* Port E Data Register Bit 1 */
    byte PTED2       :1;                                       /* Port E Data Register Bit 2 */
    byte PTED3       :1;                                       /* Port E Data Register Bit 3 */
    byte PTED4       :1;                                       /* Port E Data Register Bit 4 */
    byte PTED5       :1;                                       /* Port E Data Register Bit 5 */
    byte PTED6       :1;                                       /* Port E Data Register Bit 6 */
    byte PTED7       :1;                                       /* Port E Data Register Bit 7 */
  } Bits;
} PTEDSTR;
extern volatile PTEDSTR _PTED @0x00001830;
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED7                      _PTED.Bits.PTED7

#define PTED_PTED0_MASK                 1U
#define PTED_PTED1_MASK                 2U
#define PTED_PTED2_MASK                 4U
#define PTED_PTED3_MASK                 8U
#define PTED_PTED4_MASK                 16U
#define PTED_PTED5_MASK                 32U
#define PTED_PTED6_MASK                 64U
#define PTED_PTED7_MASK                 128U


/*** PTEDD - Port E Data Direction Register; 0x00001831 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       /* Data Direction for Port E Bit 0 */
    byte PTEDD1      :1;                                       /* Data Direction for Port E Bit 1 */
    byte PTEDD2      :1;                                       /* Data Direction for Port E Bit 2 */
    byte PTEDD3      :1;                                       /* Data Direction for Port E Bit 3 */
    byte             :1; 
    byte PTEDD5      :1;                                       /* Data Direction for Port E Bit 5 */
    byte PTEDD6      :1;                                       /* Data Direction for Port E Bit 6 */
    byte PTEDD7      :1;                                       /* Data Direction for Port E Bit 7 */
  } Bits;
  struct {
    byte grpPTEDD :4;
    byte         :1;
    byte grpPTEDD_5 :3;
  } MergedBits;
} PTEDDSTR;
extern volatile PTEDDSTR _PTEDD @0x00001831;
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD7                    _PTEDD.Bits.PTEDD7
#define PTEDD_PTEDD                     _PTEDD.MergedBits.grpPTEDD
#define PTEDD_PTEDD_5                   _PTEDD.MergedBits.grpPTEDD_5

#define PTEDD_PTEDD0_MASK               1U
#define PTEDD_PTEDD1_MASK               2U
#define PTEDD_PTEDD2_MASK               4U
#define PTEDD_PTEDD3_MASK               8U
#define PTEDD_PTEDD5_MASK               32U
#define PTEDD_PTEDD6_MASK               64U
#define PTEDD_PTEDD7_MASK               128U
#define PTEDD_PTEDD_MASK                15U
#define PTEDD_PTEDD_BITNUM              0U
#define PTEDD_PTEDD_5_MASK              224U
#define PTEDD_PTEDD_5_BITNUM            5U


/*** PTFD - Port F Data Register; 0x00001832 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1;                                       /* Port F Data Register Bit 0 */
    byte PTFD1       :1;                                       /* Port F Data Register Bit 1 */
    byte PTFD2       :1;                                       /* Port F Data Register Bit 2 */
    byte PTFD3       :1;                                       /* Port F Data Register Bit 3 */
    byte PTFD4       :1;                                       /* Port F Data Register Bit 4 */
    byte PTFD5       :1;                                       /* Port F Data Register Bit 5 */
    byte PTFD6       :1;                                       /* Port F Data Register Bit 6 */
    byte PTFD7       :1;                                       /* Port F Data Register Bit 7 */
  } Bits;
} PTFDSTR;
extern volatile PTFDSTR _PTFD @0x00001832;
#define PTFD                            _PTFD.Byte
#define PTFD_PTFD0                      _PTFD.Bits.PTFD0
#define PTFD_PTFD1                      _PTFD.Bits.PTFD1
#define PTFD_PTFD2                      _PTFD.Bits.PTFD2
#define PTFD_PTFD3                      _PTFD.Bits.PTFD3
#define PTFD_PTFD4                      _PTFD.Bits.PTFD4
#define PTFD_PTFD5                      _PTFD.Bits.PTFD5
#define PTFD_PTFD6                      _PTFD.Bits.PTFD6
#define PTFD_PTFD7                      _PTFD.Bits.PTFD7

#define PTFD_PTFD0_MASK                 1U
#define PTFD_PTFD1_MASK                 2U
#define PTFD_PTFD2_MASK                 4U
#define PTFD_PTFD3_MASK                 8U
#define PTFD_PTFD4_MASK                 16U
#define PTFD_PTFD5_MASK                 32U
#define PTFD_PTFD6_MASK                 64U
#define PTFD_PTFD7_MASK                 128U


/*** PTFDD - Port F Data Direction Register; 0x00001833 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDD0      :1;                                       /* Data Direction for Port F Bit 0 */
    byte PTFDD1      :1;                                       /* Data Direction for Port F Bit 1 */
    byte PTFDD2      :1;                                       /* Data Direction for Port F Bit 2 */
    byte PTFDD3      :1;                                       /* Data Direction for Port F Bit 3 */
    byte PTFDD4      :1;                                       /* Data Direction for Port F Bit 4 */
    byte PTFDD5      :1;                                       /* Data Direction for Port F Bit 5 */
    byte PTFDD6      :1;                                       /* Data Direction for Port F Bit 6 */
    byte PTFDD7      :1;                                       /* Data Direction for Port F Bit 7 */
  } Bits;
} PTFDDSTR;
extern volatile PTFDDSTR _PTFDD @0x00001833;
#define PTFDD                           _PTFDD.Byte
#define PTFDD_PTFDD0                    _PTFDD.Bits.PTFDD0
#define PTFDD_PTFDD1                    _PTFDD.Bits.PTFDD1
#define PTFDD_PTFDD2                    _PTFDD.Bits.PTFDD2
#define PTFDD_PTFDD3                    _PTFDD.Bits.PTFDD3
#define PTFDD_PTFDD4                    _PTFDD.Bits.PTFDD4
#define PTFDD_PTFDD5                    _PTFDD.Bits.PTFDD5
#define PTFDD_PTFDD6                    _PTFDD.Bits.PTFDD6
#define PTFDD_PTFDD7                    _PTFDD.Bits.PTFDD7

#define PTFDD_PTFDD0_MASK               1U
#define PTFDD_PTFDD1_MASK               2U
#define PTFDD_PTFDD2_MASK               4U
#define PTFDD_PTFDD3_MASK               8U
#define PTFDD_PTFDD4_MASK               16U
#define PTFDD_PTFDD5_MASK               32U
#define PTFDD_PTFDD6_MASK               64U
#define PTFDD_PTFDD7_MASK               128U


/*** SCI2BD - SCI2 Baud Rate Register; 0x00001838 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2BDH - SCI2 Baud Rate Register High; 0x00001838 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2BDHSTR;
    #define SCI2BDH                     _SCI2BD.Overlap_STR.SCI2BDHSTR.Byte
    #define SCI2BDH_SBR8                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR8
    #define SCI2BDH_SBR9                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR9
    #define SCI2BDH_SBR10               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR10
    #define SCI2BDH_SBR11               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR11
    #define SCI2BDH_SBR12               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR12
    #define SCI2BDH_RXEDGIE             _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.RXEDGIE
    #define SCI2BDH_LBKDIE              _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.LBKDIE
    #define SCI2BDH_SBR_8               _SCI2BD.Overlap_STR.SCI2BDHSTR.MergedBits.grpSBR_8
    #define SCI2BDH_SBR                 SCI2BDH_SBR_8
    
    #define SCI2BDH_SBR8_MASK           1U
    #define SCI2BDH_SBR9_MASK           2U
    #define SCI2BDH_SBR10_MASK          4U
    #define SCI2BDH_SBR11_MASK          8U
    #define SCI2BDH_SBR12_MASK          16U
    #define SCI2BDH_RXEDGIE_MASK        64U
    #define SCI2BDH_LBKDIE_MASK         128U
    #define SCI2BDH_SBR_8_MASK          31U
    #define SCI2BDH_SBR_8_BITNUM        0U
    

    /*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00001839 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI2BDLSTR;
    #define SCI2BDL                     _SCI2BD.Overlap_STR.SCI2BDLSTR.Byte
    #define SCI2BDL_SBR0                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR0
    #define SCI2BDL_SBR1                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR1
    #define SCI2BDL_SBR2                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR2
    #define SCI2BDL_SBR3                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR3
    #define SCI2BDL_SBR4                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR4
    #define SCI2BDL_SBR5                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR5
    #define SCI2BDL_SBR6                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR6
    #define SCI2BDL_SBR7                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR7
    
    #define SCI2BDL_SBR0_MASK           1U
    #define SCI2BDL_SBR1_MASK           2U
    #define SCI2BDL_SBR2_MASK           4U
    #define SCI2BDL_SBR3_MASK           8U
    #define SCI2BDL_SBR4_MASK           16U
    #define SCI2BDL_SBR5_MASK           32U
    #define SCI2BDL_SBR6_MASK           64U
    #define SCI2BDL_SBR7_MASK           128U
    
  } Overlap_STR;

} SCI2BDSTR;
extern volatile SCI2BDSTR _SCI2BD @0x00001838;
#define SCI2BD                          _SCI2BD.Word


/*** SCI2C1 - SCI2 Control Register 1; 0x0000183A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI2C1STR;
extern volatile SCI2C1STR _SCI2C1 @0x0000183A;
#define SCI2C1                          _SCI2C1.Byte
#define SCI2C1_PT                       _SCI2C1.Bits.PT
#define SCI2C1_PE                       _SCI2C1.Bits.PE
#define SCI2C1_ILT                      _SCI2C1.Bits.ILT
#define SCI2C1_WAKE                     _SCI2C1.Bits.WAKE
#define SCI2C1_M                        _SCI2C1.Bits.M
#define SCI2C1_RSRC                     _SCI2C1.Bits.RSRC
#define SCI2C1_SCISWAI                  _SCI2C1.Bits.SCISWAI
#define SCI2C1_LOOPS                    _SCI2C1.Bits.LOOPS

#define SCI2C1_PT_MASK                  1U
#define SCI2C1_PE_MASK                  2U
#define SCI2C1_ILT_MASK                 4U
#define SCI2C1_WAKE_MASK                8U
#define SCI2C1_M_MASK                   16U
#define SCI2C1_RSRC_MASK                32U
#define SCI2C1_SCISWAI_MASK             64U
#define SCI2C1_LOOPS_MASK               128U


/*** SCI2C2 - SCI2 Control Register 2; 0x0000183B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI2C2STR;
extern volatile SCI2C2STR _SCI2C2 @0x0000183B;
#define SCI2C2                          _SCI2C2.Byte
#define SCI2C2_SBK                      _SCI2C2.Bits.SBK
#define SCI2C2_RWU                      _SCI2C2.Bits.RWU
#define SCI2C2_RE                       _SCI2C2.Bits.RE
#define SCI2C2_TE                       _SCI2C2.Bits.TE
#define SCI2C2_ILIE                     _SCI2C2.Bits.ILIE
#define SCI2C2_RIE                      _SCI2C2.Bits.RIE
#define SCI2C2_TCIE                     _SCI2C2.Bits.TCIE
#define SCI2C2_TIE                      _SCI2C2.Bits.TIE

#define SCI2C2_SBK_MASK                 1U
#define SCI2C2_RWU_MASK                 2U
#define SCI2C2_RE_MASK                  4U
#define SCI2C2_TE_MASK                  8U
#define SCI2C2_ILIE_MASK                16U
#define SCI2C2_RIE_MASK                 32U
#define SCI2C2_TCIE_MASK                64U
#define SCI2C2_TIE_MASK                 128U


/*** SCI2S1 - SCI2 Status Register 1; 0x0000183C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI2S1STR;
extern volatile SCI2S1STR _SCI2S1 @0x0000183C;
#define SCI2S1                          _SCI2S1.Byte
#define SCI2S1_PF                       _SCI2S1.Bits.PF
#define SCI2S1_FE                       _SCI2S1.Bits.FE
#define SCI2S1_NF                       _SCI2S1.Bits.NF
#define SCI2S1_OR                       _SCI2S1.Bits.OR
#define SCI2S1_IDLE                     _SCI2S1.Bits.IDLE
#define SCI2S1_RDRF                     _SCI2S1.Bits.RDRF
#define SCI2S1_TC                       _SCI2S1.Bits.TC
#define SCI2S1_TDRE                     _SCI2S1.Bits.TDRE

#define SCI2S1_PF_MASK                  1U
#define SCI2S1_FE_MASK                  2U
#define SCI2S1_NF_MASK                  4U
#define SCI2S1_OR_MASK                  8U
#define SCI2S1_IDLE_MASK                16U
#define SCI2S1_RDRF_MASK                32U
#define SCI2S1_TC_MASK                  64U
#define SCI2S1_TDRE_MASK                128U


/*** SCI2S2 - SCI2 Status Register 2; 0x0000183D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI2S2STR;
extern volatile SCI2S2STR _SCI2S2 @0x0000183D;
#define SCI2S2                          _SCI2S2.Byte
#define SCI2S2_RAF                      _SCI2S2.Bits.RAF
#define SCI2S2_LBKDE                    _SCI2S2.Bits.LBKDE
#define SCI2S2_BRK13                    _SCI2S2.Bits.BRK13
#define SCI2S2_RWUID                    _SCI2S2.Bits.RWUID
#define SCI2S2_RXINV                    _SCI2S2.Bits.RXINV
#define SCI2S2_RXEDGIF                  _SCI2S2.Bits.RXEDGIF
#define SCI2S2_LBKDIF                   _SCI2S2.Bits.LBKDIF

#define SCI2S2_RAF_MASK                 1U
#define SCI2S2_LBKDE_MASK               2U
#define SCI2S2_BRK13_MASK               4U
#define SCI2S2_RWUID_MASK               8U
#define SCI2S2_RXINV_MASK               16U
#define SCI2S2_RXEDGIF_MASK             64U
#define SCI2S2_LBKDIF_MASK              128U


/*** SCI2C3 - SCI2 Control Register 3; 0x0000183E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI2C3STR;
extern volatile SCI2C3STR _SCI2C3 @0x0000183E;
#define SCI2C3                          _SCI2C3.Byte
#define SCI2C3_PEIE                     _SCI2C3.Bits.PEIE
#define SCI2C3_FEIE                     _SCI2C3.Bits.FEIE
#define SCI2C3_NEIE                     _SCI2C3.Bits.NEIE
#define SCI2C3_ORIE                     _SCI2C3.Bits.ORIE
#define SCI2C3_TXINV                    _SCI2C3.Bits.TXINV
#define SCI2C3_TXDIR                    _SCI2C3.Bits.TXDIR
#define SCI2C3_T8                       _SCI2C3.Bits.T8
#define SCI2C3_R8                       _SCI2C3.Bits.R8

#define SCI2C3_PEIE_MASK                1U
#define SCI2C3_FEIE_MASK                2U
#define SCI2C3_NEIE_MASK                4U
#define SCI2C3_ORIE_MASK                8U
#define SCI2C3_TXINV_MASK               16U
#define SCI2C3_TXDIR_MASK               32U
#define SCI2C3_T8_MASK                  64U
#define SCI2C3_R8_MASK                  128U


/*** SCI2D - SCI2 Data Register; 0x0000183F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI2DSTR;
extern volatile SCI2DSTR _SCI2D @0x0000183F;
#define SCI2D                           _SCI2D.Byte
#define SCI2D_R0_T0                     _SCI2D.Bits.R0_T0
#define SCI2D_R1_T1                     _SCI2D.Bits.R1_T1
#define SCI2D_R2_T2                     _SCI2D.Bits.R2_T2
#define SCI2D_R3_T3                     _SCI2D.Bits.R3_T3
#define SCI2D_R4_T4                     _SCI2D.Bits.R4_T4
#define SCI2D_R5_T5                     _SCI2D.Bits.R5_T5
#define SCI2D_R6_T6                     _SCI2D.Bits.R6_T6
#define SCI2D_R7_T7                     _SCI2D.Bits.R7_T7

#define SCI2D_R0_T0_MASK                1U
#define SCI2D_R1_T1_MASK                2U
#define SCI2D_R2_T2_MASK                4U
#define SCI2D_R3_T3_MASK                8U
#define SCI2D_R4_T4_MASK                16U
#define SCI2D_R5_T5_MASK                32U
#define SCI2D_R6_T6_MASK                64U
#define SCI2D_R7_T7_MASK                128U


/*** SPI2C1 - SPI2 Control Register 1; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI2C1STR;
extern volatile SPI2C1STR _SPI2C1 @0x00001840;
#define SPI2C1                          _SPI2C1.Byte
#define SPI2C1_LSBFE                    _SPI2C1.Bits.LSBFE
#define SPI2C1_SSOE                     _SPI2C1.Bits.SSOE
#define SPI2C1_CPHA                     _SPI2C1.Bits.CPHA
#define SPI2C1_CPOL                     _SPI2C1.Bits.CPOL
#define SPI2C1_MSTR                     _SPI2C1.Bits.MSTR
#define SPI2C1_SPTIE                    _SPI2C1.Bits.SPTIE
#define SPI2C1_SPE                      _SPI2C1.Bits.SPE
#define SPI2C1_SPIE                     _SPI2C1.Bits.SPIE

#define SPI2C1_LSBFE_MASK               1U
#define SPI2C1_SSOE_MASK                2U
#define SPI2C1_CPHA_MASK                4U
#define SPI2C1_CPOL_MASK                8U
#define SPI2C1_MSTR_MASK                16U
#define SPI2C1_SPTIE_MASK               32U
#define SPI2C1_SPE_MASK                 64U
#define SPI2C1_SPIE_MASK                128U


/*** SPI2C2 - SPI2 Control Register 2; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPI2C2STR;
extern volatile SPI2C2STR _SPI2C2 @0x00001841;
#define SPI2C2                          _SPI2C2.Byte
#define SPI2C2_SPC0                     _SPI2C2.Bits.SPC0
#define SPI2C2_SPISWAI                  _SPI2C2.Bits.SPISWAI
#define SPI2C2_BIDIROE                  _SPI2C2.Bits.BIDIROE
#define SPI2C2_MODFEN                   _SPI2C2.Bits.MODFEN
#define SPI2C2_SPMIE                    _SPI2C2.Bits.SPMIE

#define SPI2C2_SPC0_MASK                1U
#define SPI2C2_SPISWAI_MASK             2U
#define SPI2C2_BIDIROE_MASK             8U
#define SPI2C2_MODFEN_MASK              16U
#define SPI2C2_SPMIE_MASK               128U


/*** SPI2BR - SPI2 Baud Rate Register; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte SPR3        :1;                                       /* SPI Baud Rate Divisor Bit 3 */
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI2BRSTR;
extern volatile SPI2BRSTR _SPI2BR @0x00001842;
#define SPI2BR                          _SPI2BR.Byte
#define SPI2BR_SPR0                     _SPI2BR.Bits.SPR0
#define SPI2BR_SPR1                     _SPI2BR.Bits.SPR1
#define SPI2BR_SPR2                     _SPI2BR.Bits.SPR2
#define SPI2BR_SPR3                     _SPI2BR.Bits.SPR3
#define SPI2BR_SPPR0                    _SPI2BR.Bits.SPPR0
#define SPI2BR_SPPR1                    _SPI2BR.Bits.SPPR1
#define SPI2BR_SPPR2                    _SPI2BR.Bits.SPPR2
#define SPI2BR_SPR                      _SPI2BR.MergedBits.grpSPR
#define SPI2BR_SPPR                     _SPI2BR.MergedBits.grpSPPR

#define SPI2BR_SPR0_MASK                1U
#define SPI2BR_SPR1_MASK                2U
#define SPI2BR_SPR2_MASK                4U
#define SPI2BR_SPR3_MASK                8U
#define SPI2BR_SPPR0_MASK               16U
#define SPI2BR_SPPR1_MASK               32U
#define SPI2BR_SPPR2_MASK               64U
#define SPI2BR_SPR_MASK                 15U
#define SPI2BR_SPR_BITNUM               0U
#define SPI2BR_SPPR_MASK                112U
#define SPI2BR_SPPR_BITNUM              4U


/*** SPI2S - SPI2 Status Register; 0x00001843 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI2SSTR;
extern volatile SPI2SSTR _SPI2S @0x00001843;
#define SPI2S                           _SPI2S.Byte
#define SPI2S_MODF                      _SPI2S.Bits.MODF
#define SPI2S_SPTEF                     _SPI2S.Bits.SPTEF
#define SPI2S_SPMF                      _SPI2S.Bits.SPMF
#define SPI2S_SPRF                      _SPI2S.Bits.SPRF

#define SPI2S_MODF_MASK                 16U
#define SPI2S_SPTEF_MASK                32U
#define SPI2S_SPMF_MASK                 64U
#define SPI2S_SPRF_MASK                 128U


/*** SPI2D - SPI2 Data Register; 0x00001845 ***/
typedef union {
  byte Byte;
} SPI2DSTR;
extern volatile SPI2DSTR _SPI2D @0x00001845;
#define SPI2D                           _SPI2D.Byte


/*** SPI2M - SPI2 Match Register; 0x00001847 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
    byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
    byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
    byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
    byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
    byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
    byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
    byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
  } Bits;
} SPI2MSTR;
extern volatile SPI2MSTR _SPI2M @0x00001847;
#define SPI2M                           _SPI2M.Byte
#define SPI2M_Bit0                      _SPI2M.Bits.Bit0
#define SPI2M_Bit1                      _SPI2M.Bits.Bit1
#define SPI2M_Bit2                      _SPI2M.Bits.Bit2
#define SPI2M_Bit3                      _SPI2M.Bits.Bit3
#define SPI2M_Bit4                      _SPI2M.Bits.Bit4
#define SPI2M_Bit5                      _SPI2M.Bits.Bit5
#define SPI2M_Bit6                      _SPI2M.Bits.Bit6
#define SPI2M_Bit7                      _SPI2M.Bits.Bit7

#define SPI2M_Bit0_MASK                 1U
#define SPI2M_Bit1_MASK                 2U
#define SPI2M_Bit2_MASK                 4U
#define SPI2M_Bit3_MASK                 8U
#define SPI2M_Bit4_MASK                 16U
#define SPI2M_Bit5_MASK                 32U
#define SPI2M_Bit6_MASK                 64U
#define SPI2M_Bit7_MASK                 128U


/*** PTGD - Port G Data Register; 0x00001848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGD0       :1;                                       /* Port G Data Register Bit 0 */
    byte PTGD1       :1;                                       /* Port G Data Register Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDSTR;
extern volatile PTGDSTR _PTGD @0x00001848;
#define PTGD                            _PTGD.Byte
#define PTGD_PTGD0                      _PTGD.Bits.PTGD0
#define PTGD_PTGD1                      _PTGD.Bits.PTGD1
#define PTGD_PTGD                       _PTGD.MergedBits.grpPTGD

#define PTGD_PTGD0_MASK                 1U
#define PTGD_PTGD1_MASK                 2U
#define PTGD_PTGD_MASK                  3U
#define PTGD_PTGD_BITNUM                0U


/*** PTGDD - Port G Data Direction Register; 0x00001849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDD0      :1;                                       /* Data Direction for Port G Bit 0 */
    byte PTGDD1      :1;                                       /* Data Direction for Port G Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDDSTR;
extern volatile PTGDDSTR _PTGDD @0x00001849;
#define PTGDD                           _PTGDD.Byte
#define PTGDD_PTGDD0                    _PTGDD.Bits.PTGDD0
#define PTGDD_PTGDD1                    _PTGDD.Bits.PTGDD1
#define PTGDD_PTGDD                     _PTGDD.MergedBits.grpPTGDD

#define PTGDD_PTGDD0_MASK               1U
#define PTGDD_PTGDD1_MASK               2U
#define PTGDD_PTGDD_MASK                3U
#define PTGDD_PTGDD_BITNUM              0U


/*** PTAPE - Port A Pull Enable Register; 0x00001850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001850;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0x00001851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001851;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0x00001852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001852;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTAIFE - Port A Input Filter Enable Register; 0x00001853 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAIFE0     :1;                                       /* Port A Input Filter Enable Bit 0 */
    byte PTAIFE1     :1;                                       /* Port A Input Filter Enable Bit 1 */
    byte PTAIFE2     :1;                                       /* Port A Input Filter Enable Bit 2 */
    byte PTAIFE3     :1;                                       /* Port A Input Filter Enable Bit 3 */
    byte PTAIFE4     :1;                                       /* Port A Input Filter Enable Bit 4 */
    byte PTAIFE5     :1;                                       /* Port A Input Filter Enable Bit 5 */
    byte PTAIFE6     :1;                                       /* Port A Input Filter Enable Bit 6 */
    byte PTAIFE7     :1;                                       /* Port A Input Filter Enable Bit 7 */
  } Bits;
} PTAIFESTR;
extern volatile PTAIFESTR _PTAIFE @0x00001853;
#define PTAIFE                          _PTAIFE.Byte
#define PTAIFE_PTAIFE0                  _PTAIFE.Bits.PTAIFE0
#define PTAIFE_PTAIFE1                  _PTAIFE.Bits.PTAIFE1
#define PTAIFE_PTAIFE2                  _PTAIFE.Bits.PTAIFE2
#define PTAIFE_PTAIFE3                  _PTAIFE.Bits.PTAIFE3
#define PTAIFE_PTAIFE4                  _PTAIFE.Bits.PTAIFE4
#define PTAIFE_PTAIFE5                  _PTAIFE.Bits.PTAIFE5
#define PTAIFE_PTAIFE6                  _PTAIFE.Bits.PTAIFE6
#define PTAIFE_PTAIFE7                  _PTAIFE.Bits.PTAIFE7

#define PTAIFE_PTAIFE0_MASK             1U
#define PTAIFE_PTAIFE1_MASK             2U
#define PTAIFE_PTAIFE2_MASK             4U
#define PTAIFE_PTAIFE3_MASK             8U
#define PTAIFE_PTAIFE4_MASK             16U
#define PTAIFE_PTAIFE5_MASK             32U
#define PTAIFE_PTAIFE6_MASK             64U
#define PTAIFE_PTAIFE7_MASK             128U


/*** PTBPE - Port B Pull Enable Register; 0x00001854 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001854;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001855 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001855;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0x00001856 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x00001856;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTBIFE - Port B Input Filter Enable Register; 0x00001857 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBIFE0     :1;                                       /* Port B Input Filter Enable Bit 0 */
    byte PTBIFE1     :1;                                       /* Port B Input Filter Enable Bit 1 */
    byte PTBIFE2     :1;                                       /* Port B Input Filter Enable Bit 2 */
    byte PTBIFE3     :1;                                       /* Port B Input Filter Enable Bit 3 */
    byte PTBIFE4     :1;                                       /* Port B Input Filter Enable Bit 4 */
    byte PTBIFE5     :1;                                       /* Port B Input Filter Enable Bit 5 */
    byte PTBIFE6     :1;                                       /* Port B Input Filter Enable Bit 6 */
    byte PTBIFE7     :1;                                       /* Port B Input Filter Enable Bit 7 */
  } Bits;
} PTBIFESTR;
extern volatile PTBIFESTR _PTBIFE @0x00001857;
#define PTBIFE                          _PTBIFE.Byte
#define PTBIFE_PTBIFE0                  _PTBIFE.Bits.PTBIFE0
#define PTBIFE_PTBIFE1                  _PTBIFE.Bits.PTBIFE1
#define PTBIFE_PTBIFE2                  _PTBIFE.Bits.PTBIFE2
#define PTBIFE_PTBIFE3                  _PTBIFE.Bits.PTBIFE3
#define PTBIFE_PTBIFE4                  _PTBIFE.Bits.PTBIFE4
#define PTBIFE_PTBIFE5                  _PTBIFE.Bits.PTBIFE5
#define PTBIFE_PTBIFE6                  _PTBIFE.Bits.PTBIFE6
#define PTBIFE_PTBIFE7                  _PTBIFE.Bits.PTBIFE7

#define PTBIFE_PTBIFE0_MASK             1U
#define PTBIFE_PTBIFE1_MASK             2U
#define PTBIFE_PTBIFE2_MASK             4U
#define PTBIFE_PTBIFE3_MASK             8U
#define PTBIFE_PTBIFE4_MASK             16U
#define PTBIFE_PTBIFE5_MASK             32U
#define PTBIFE_PTBIFE6_MASK             64U
#define PTBIFE_PTBIFE7_MASK             128U


/*** PTCPE - Port C Pull Enable Register; 0x00001858 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001858;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE7_MASK               128U


/*** PTCSE - Port C Slew Rate Enable Register; 0x00001859 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001859;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE7_MASK               128U


/*** PTCDS - Port C Drive Strength Selection Register; 0x0000185A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x0000185A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS7_MASK               128U


/*** PTCIFE - Port C Input Filter Enable Register; 0x0000185B ***/
typedef union {
  byte Byte;
  struct {
    byte PTCIFE0     :1;                                       /* Port C Input Filter Enable Bit 0 */
    byte PTCIFE1     :1;                                       /* Port C Input Filter Enable Bit 1 */
    byte PTCIFE2     :1;                                       /* Port C Input Filter Enable Bit 2 */
    byte PTCIFE3     :1;                                       /* Port C Input Filter Enable Bit 3 */
    byte PTCIFE4     :1;                                       /* Port C Input Filter Enable Bit 4 */
    byte PTCIFE5     :1;                                       /* Port C Input Filter Enable Bit 5 */
    byte PTCIFE6     :1;                                       /* Port C Input Filter Enable Bit 6 */
    byte PTCIFE7     :1;                                       /* Port C Input Filter Enable Bit 7 */
  } Bits;
} PTCIFESTR;
extern volatile PTCIFESTR _PTCIFE @0x0000185B;
#define PTCIFE                          _PTCIFE.Byte
#define PTCIFE_PTCIFE0                  _PTCIFE.Bits.PTCIFE0
#define PTCIFE_PTCIFE1                  _PTCIFE.Bits.PTCIFE1
#define PTCIFE_PTCIFE2                  _PTCIFE.Bits.PTCIFE2
#define PTCIFE_PTCIFE3                  _PTCIFE.Bits.PTCIFE3
#define PTCIFE_PTCIFE4                  _PTCIFE.Bits.PTCIFE4
#define PTCIFE_PTCIFE5                  _PTCIFE.Bits.PTCIFE5
#define PTCIFE_PTCIFE6                  _PTCIFE.Bits.PTCIFE6
#define PTCIFE_PTCIFE7                  _PTCIFE.Bits.PTCIFE7

#define PTCIFE_PTCIFE0_MASK             1U
#define PTCIFE_PTCIFE1_MASK             2U
#define PTCIFE_PTCIFE2_MASK             4U
#define PTCIFE_PTCIFE3_MASK             8U
#define PTCIFE_PTCIFE4_MASK             16U
#define PTCIFE_PTCIFE5_MASK             32U
#define PTCIFE_PTCIFE6_MASK             64U
#define PTCIFE_PTCIFE7_MASK             128U


/*** PTDPE - Port D Pull Enable Register; 0x0000185C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
extern volatile PTDPESTR _PTDPE @0x0000185C;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1U
#define PTDPE_PTDPE1_MASK               2U
#define PTDPE_PTDPE2_MASK               4U
#define PTDPE_PTDPE3_MASK               8U
#define PTDPE_PTDPE4_MASK               16U
#define PTDPE_PTDPE5_MASK               32U
#define PTDPE_PTDPE6_MASK               64U
#define PTDPE_PTDPE7_MASK               128U


/*** PTDSE - Port D Slew Rate Enable Register; 0x0000185D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
extern volatile PTDSESTR _PTDSE @0x0000185D;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1U
#define PTDSE_PTDSE1_MASK               2U
#define PTDSE_PTDSE2_MASK               4U
#define PTDSE_PTDSE3_MASK               8U
#define PTDSE_PTDSE4_MASK               16U
#define PTDSE_PTDSE5_MASK               32U
#define PTDSE_PTDSE6_MASK               64U
#define PTDSE_PTDSE7_MASK               128U


/*** PTDDS - Port D Drive Strength Selection Register; 0x0000185E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
extern volatile PTDDSSTR _PTDDS @0x0000185E;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1U
#define PTDDS_PTDDS1_MASK               2U
#define PTDDS_PTDDS2_MASK               4U
#define PTDDS_PTDDS3_MASK               8U
#define PTDDS_PTDDS4_MASK               16U
#define PTDDS_PTDDS5_MASK               32U
#define PTDDS_PTDDS6_MASK               64U
#define PTDDS_PTDDS7_MASK               128U


/*** PTDIFE - Port D Input Filter Enable Register; 0x0000185F ***/
typedef union {
  byte Byte;
  struct {
    byte PTDIFE0     :1;                                       /* Port D Input Filter Enable Bit 0 */
    byte PTDIFE1     :1;                                       /* Port D Input Filter Enable Bit 1 */
    byte PTDIFE2     :1;                                       /* Port D Input Filter Enable Bit 2 */
    byte PTDIFE3     :1;                                       /* Port D Input Filter Enable Bit 3 */
    byte PTDIFE4     :1;                                       /* Port D Input Filter Enable Bit 4 */
    byte PTDIFE5     :1;                                       /* Port D Input Filter Enable Bit 5 */
    byte PTDIFE6     :1;                                       /* Port D Input Filter Enable Bit 6 */
    byte PTDIFE7     :1;                                       /* Port D Input Filter Enable Bit 7 */
  } Bits;
} PTDIFESTR;
extern volatile PTDIFESTR _PTDIFE @0x0000185F;
#define PTDIFE                          _PTDIFE.Byte
#define PTDIFE_PTDIFE0                  _PTDIFE.Bits.PTDIFE0
#define PTDIFE_PTDIFE1                  _PTDIFE.Bits.PTDIFE1
#define PTDIFE_PTDIFE2                  _PTDIFE.Bits.PTDIFE2
#define PTDIFE_PTDIFE3                  _PTDIFE.Bits.PTDIFE3
#define PTDIFE_PTDIFE4                  _PTDIFE.Bits.PTDIFE4
#define PTDIFE_PTDIFE5                  _PTDIFE.Bits.PTDIFE5
#define PTDIFE_PTDIFE6                  _PTDIFE.Bits.PTDIFE6
#define PTDIFE_PTDIFE7                  _PTDIFE.Bits.PTDIFE7

#define PTDIFE_PTDIFE0_MASK             1U
#define PTDIFE_PTDIFE1_MASK             2U
#define PTDIFE_PTDIFE2_MASK             4U
#define PTDIFE_PTDIFE3_MASK             8U
#define PTDIFE_PTDIFE4_MASK             16U
#define PTDIFE_PTDIFE5_MASK             32U
#define PTDIFE_PTDIFE6_MASK             64U
#define PTDIFE_PTDIFE7_MASK             128U


/*** PTEPE - Port E Pull Enable Register; 0x00001860 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Internal Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Internal Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Internal Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Internal Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Internal Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Internal Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Internal Pull Enable for Port E Bit 6 */
    byte PTEPE7      :1;                                       /* Internal Pull Enable for Port E Bit 7 */
  } Bits;
} PTEPESTR;
extern volatile PTEPESTR _PTEPE @0x00001860;
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE7                    _PTEPE.Bits.PTEPE7

#define PTEPE_PTEPE0_MASK               1U
#define PTEPE_PTEPE1_MASK               2U
#define PTEPE_PTEPE2_MASK               4U
#define PTEPE_PTEPE3_MASK               8U
#define PTEPE_PTEPE4_MASK               16U
#define PTEPE_PTEPE5_MASK               32U
#define PTEPE_PTEPE6_MASK               64U
#define PTEPE_PTEPE7_MASK               128U


/*** PTESE - Port E Slew Rate Enable Register; 0x00001861 ***/
typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       /* Output Slew Rate Enable for Port E Bit 0 */
    byte PTESE1      :1;                                       /* Output Slew Rate Enable for Port E Bit 1 */
    byte PTESE2      :1;                                       /* Output Slew Rate Enable for Port E Bit 2 */
    byte PTESE3      :1;                                       /* Output Slew Rate Enable for Port E Bit 3 */
    byte PTESE4      :1;                                       /* Output Slew Rate Enable for Port E Bit 4 */
    byte PTESE5      :1;                                       /* Output Slew Rate Enable for Port E Bit 5 */
    byte PTESE6      :1;                                       /* Output Slew Rate Enable for Port E Bit 6 */
    byte PTESE7      :1;                                       /* Output Slew Rate Enable for Port E Bit 7 */
  } Bits;
} PTESESTR;
extern volatile PTESESTR _PTESE @0x00001861;
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE7                    _PTESE.Bits.PTESE7

#define PTESE_PTESE0_MASK               1U
#define PTESE_PTESE1_MASK               2U
#define PTESE_PTESE2_MASK               4U
#define PTESE_PTESE3_MASK               8U
#define PTESE_PTESE4_MASK               16U
#define PTESE_PTESE5_MASK               32U
#define PTESE_PTESE6_MASK               64U
#define PTESE_PTESE7_MASK               128U


/*** PTEDS - Port E Drive Strength Selection Register; 0x00001862 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       /* Output Drive Strength Selection for Port E Bit 0 */
    byte PTEDS1      :1;                                       /* Output Drive Strength Selection for Port E Bit 1 */
    byte PTEDS2      :1;                                       /* Output Drive Strength Selection for Port E Bit 2 */
    byte PTEDS3      :1;                                       /* Output Drive Strength Selection for Port E Bit 3 */
    byte PTEDS4      :1;                                       /* Output Drive Strength Selection for Port E Bit 4 */
    byte PTEDS5      :1;                                       /* Output Drive Strength Selection for Port E Bit 5 */
    byte PTEDS6      :1;                                       /* Output Drive Strength Selection for Port E Bit 6 */
    byte PTEDS7      :1;                                       /* Output Drive Strength Selection for Port E Bit 7 */
  } Bits;
} PTEDSSTR;
extern volatile PTEDSSTR _PTEDS @0x00001862;
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS7                    _PTEDS.Bits.PTEDS7

#define PTEDS_PTEDS0_MASK               1U
#define PTEDS_PTEDS1_MASK               2U
#define PTEDS_PTEDS2_MASK               4U
#define PTEDS_PTEDS3_MASK               8U
#define PTEDS_PTEDS4_MASK               16U
#define PTEDS_PTEDS5_MASK               32U
#define PTEDS_PTEDS6_MASK               64U
#define PTEDS_PTEDS7_MASK               128U


/*** PTEIFE - Port E Input Filter Enable Register; 0x00001863 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEIFE0     :1;                                       /* Port E Input Filter Enable Bit 0 */
    byte PTEIFE1     :1;                                       /* Port E Input Filter Enable Bit 1 */
    byte PTEIFE2     :1;                                       /* Port E Input Filter Enable Bit 2 */
    byte PTEIFE3     :1;                                       /* Port E Input Filter Enable Bit 3 */
    byte PTEIFE4     :1;                                       /* Port E Input Filter Enable Bit 4 */
    byte PTEIFE5     :1;                                       /* Port E Input Filter Enable Bit 5 */
    byte PTEIFE6     :1;                                       /* Port E Input Filter Enable Bit 6 */
    byte PTEIFE7     :1;                                       /* Port E Input Filter Enable Bit 7 */
  } Bits;
} PTEIFESTR;
extern volatile PTEIFESTR _PTEIFE @0x00001863;
#define PTEIFE                          _PTEIFE.Byte
#define PTEIFE_PTEIFE0                  _PTEIFE.Bits.PTEIFE0
#define PTEIFE_PTEIFE1                  _PTEIFE.Bits.PTEIFE1
#define PTEIFE_PTEIFE2                  _PTEIFE.Bits.PTEIFE2
#define PTEIFE_PTEIFE3                  _PTEIFE.Bits.PTEIFE3
#define PTEIFE_PTEIFE4                  _PTEIFE.Bits.PTEIFE4
#define PTEIFE_PTEIFE5                  _PTEIFE.Bits.PTEIFE5
#define PTEIFE_PTEIFE6                  _PTEIFE.Bits.PTEIFE6
#define PTEIFE_PTEIFE7                  _PTEIFE.Bits.PTEIFE7

#define PTEIFE_PTEIFE0_MASK             1U
#define PTEIFE_PTEIFE1_MASK             2U
#define PTEIFE_PTEIFE2_MASK             4U
#define PTEIFE_PTEIFE3_MASK             8U
#define PTEIFE_PTEIFE4_MASK             16U
#define PTEIFE_PTEIFE5_MASK             32U
#define PTEIFE_PTEIFE6_MASK             64U
#define PTEIFE_PTEIFE7_MASK             128U


/*** PTFPE - Port F Pull Enable Register; 0x00001864 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       /* Internal Pull Enable for Port F Bit 0 */
    byte PTFPE1      :1;                                       /* Internal Pull Enable for Port F Bit 1 */
    byte PTFPE2      :1;                                       /* Internal Pull Enable for Port F Bit 2 */
    byte PTFPE3      :1;                                       /* Internal Pull Enable for Port F Bit 3 */
    byte PTFPE4      :1;                                       /* Internal Pull Enable for Port F Bit 4 */
    byte PTFPE5      :1;                                       /* Internal Pull Enable for Port F Bit 5 */
    byte PTFPE6      :1;                                       /* Internal Pull Enable for Port F Bit 6 */
    byte PTFPE7      :1;                                       /* Internal Pull Enable for Port F Bit 7 */
  } Bits;
} PTFPESTR;
extern volatile PTFPESTR _PTFPE @0x00001864;
#define PTFPE                           _PTFPE.Byte
#define PTFPE_PTFPE0                    _PTFPE.Bits.PTFPE0
#define PTFPE_PTFPE1                    _PTFPE.Bits.PTFPE1
#define PTFPE_PTFPE2                    _PTFPE.Bits.PTFPE2
#define PTFPE_PTFPE3                    _PTFPE.Bits.PTFPE3
#define PTFPE_PTFPE4                    _PTFPE.Bits.PTFPE4
#define PTFPE_PTFPE5                    _PTFPE.Bits.PTFPE5
#define PTFPE_PTFPE6                    _PTFPE.Bits.PTFPE6
#define PTFPE_PTFPE7                    _PTFPE.Bits.PTFPE7

#define PTFPE_PTFPE0_MASK               1U
#define PTFPE_PTFPE1_MASK               2U
#define PTFPE_PTFPE2_MASK               4U
#define PTFPE_PTFPE3_MASK               8U
#define PTFPE_PTFPE4_MASK               16U
#define PTFPE_PTFPE5_MASK               32U
#define PTFPE_PTFPE6_MASK               64U
#define PTFPE_PTFPE7_MASK               128U


/*** PTFSE - Port F Slew Rate Enable Register; 0x00001865 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFSE0      :1;                                       /* Output Slew Rate Enable for Port F Bit 0 */
    byte PTFSE1      :1;                                       /* Output Slew Rate Enable for Port F Bit 1 */
    byte PTFSE2      :1;                                       /* Output Slew Rate Enable for Port F Bit 2 */
    byte PTFSE3      :1;                                       /* Output Slew Rate Enable for Port F Bit 3 */
    byte PTFSE4      :1;                                       /* Output Slew Rate Enable for Port F Bit 4 */
    byte PTFSE5      :1;                                       /* Output Slew Rate Enable for Port F Bit 5 */
    byte PTFSE6      :1;                                       /* Output Slew Rate Enable for Port F Bit 6 */
    byte PTFSE7      :1;                                       /* Output Slew Rate Enable for Port F Bit 7 */
  } Bits;
} PTFSESTR;
extern volatile PTFSESTR _PTFSE @0x00001865;
#define PTFSE                           _PTFSE.Byte
#define PTFSE_PTFSE0                    _PTFSE.Bits.PTFSE0
#define PTFSE_PTFSE1                    _PTFSE.Bits.PTFSE1
#define PTFSE_PTFSE2                    _PTFSE.Bits.PTFSE2
#define PTFSE_PTFSE3                    _PTFSE.Bits.PTFSE3
#define PTFSE_PTFSE4                    _PTFSE.Bits.PTFSE4
#define PTFSE_PTFSE5                    _PTFSE.Bits.PTFSE5
#define PTFSE_PTFSE6                    _PTFSE.Bits.PTFSE6
#define PTFSE_PTFSE7                    _PTFSE.Bits.PTFSE7

#define PTFSE_PTFSE0_MASK               1U
#define PTFSE_PTFSE1_MASK               2U
#define PTFSE_PTFSE2_MASK               4U
#define PTFSE_PTFSE3_MASK               8U
#define PTFSE_PTFSE4_MASK               16U
#define PTFSE_PTFSE5_MASK               32U
#define PTFSE_PTFSE6_MASK               64U
#define PTFSE_PTFSE7_MASK               128U


/*** PTFDS - Port F Drive Strength Selection Register; 0x00001866 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDS0      :1;                                       /* Output Drive Strength Selection for Port F Bit 0 */
    byte PTFDS1      :1;                                       /* Output Drive Strength Selection for Port F Bit 1 */
    byte PTFDS2      :1;                                       /* Output Drive Strength Selection for Port F Bit 2 */
    byte PTFDS3      :1;                                       /* Output Drive Strength Selection for Port F Bit 3 */
    byte PTFDS4      :1;                                       /* Output Drive Strength Selection for Port F Bit 4 */
    byte PTFDS5      :1;                                       /* Output Drive Strength Selection for Port F Bit 5 */
    byte PTFDS6      :1;                                       /* Output Drive Strength Selection for Port F Bit 6 */
    byte PTFDS7      :1;                                       /* Output Drive Strength Selection for Port F Bit 7 */
  } Bits;
} PTFDSSTR;
extern volatile PTFDSSTR _PTFDS @0x00001866;
#define PTFDS                           _PTFDS.Byte
#define PTFDS_PTFDS0                    _PTFDS.Bits.PTFDS0
#define PTFDS_PTFDS1                    _PTFDS.Bits.PTFDS1
#define PTFDS_PTFDS2                    _PTFDS.Bits.PTFDS2
#define PTFDS_PTFDS3                    _PTFDS.Bits.PTFDS3
#define PTFDS_PTFDS4                    _PTFDS.Bits.PTFDS4
#define PTFDS_PTFDS5                    _PTFDS.Bits.PTFDS5
#define PTFDS_PTFDS6                    _PTFDS.Bits.PTFDS6
#define PTFDS_PTFDS7                    _PTFDS.Bits.PTFDS7

#define PTFDS_PTFDS0_MASK               1U
#define PTFDS_PTFDS1_MASK               2U
#define PTFDS_PTFDS2_MASK               4U
#define PTFDS_PTFDS3_MASK               8U
#define PTFDS_PTFDS4_MASK               16U
#define PTFDS_PTFDS5_MASK               32U
#define PTFDS_PTFDS6_MASK               64U
#define PTFDS_PTFDS7_MASK               128U


/*** PTFIFE - Port F Input Filter Enable Register; 0x00001867 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFIFE0     :1;                                       /* Port F Input Filter Enable Bit 0 */
    byte PTFIFE1     :1;                                       /* Port F Input Filter Enable Bit 1 */
    byte PTFIFE2     :1;                                       /* Port F Input Filter Enable Bit 2 */
    byte PTFIFE3     :1;                                       /* Port F Input Filter Enable Bit 3 */
    byte PTFIFE4     :1;                                       /* Port F Input Filter Enable Bit 4 */
    byte PTFIFE5     :1;                                       /* Port F Input Filter Enable Bit 5 */
    byte PTFIFE6     :1;                                       /* Port F Input Filter Enable Bit 6 */
    byte PTFIFE7     :1;                                       /* Port F Input Filter Enable Bit 7 */
  } Bits;
} PTFIFESTR;
extern volatile PTFIFESTR _PTFIFE @0x00001867;
#define PTFIFE                          _PTFIFE.Byte
#define PTFIFE_PTFIFE0                  _PTFIFE.Bits.PTFIFE0
#define PTFIFE_PTFIFE1                  _PTFIFE.Bits.PTFIFE1
#define PTFIFE_PTFIFE2                  _PTFIFE.Bits.PTFIFE2
#define PTFIFE_PTFIFE3                  _PTFIFE.Bits.PTFIFE3
#define PTFIFE_PTFIFE4                  _PTFIFE.Bits.PTFIFE4
#define PTFIFE_PTFIFE5                  _PTFIFE.Bits.PTFIFE5
#define PTFIFE_PTFIFE6                  _PTFIFE.Bits.PTFIFE6
#define PTFIFE_PTFIFE7                  _PTFIFE.Bits.PTFIFE7

#define PTFIFE_PTFIFE0_MASK             1U
#define PTFIFE_PTFIFE1_MASK             2U
#define PTFIFE_PTFIFE2_MASK             4U
#define PTFIFE_PTFIFE3_MASK             8U
#define PTFIFE_PTFIFE4_MASK             16U
#define PTFIFE_PTFIFE5_MASK             32U
#define PTFIFE_PTFIFE6_MASK             64U
#define PTFIFE_PTFIFE7_MASK             128U


/*** PTGPE - Port G Pull Enable Register; 0x00001868 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGPE0      :1;                                       /* Internal Pull Enable for Port G Bit 0 */
    byte PTGPE1      :1;                                       /* Internal Pull Enable for Port G Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGPE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGPESTR;
extern volatile PTGPESTR _PTGPE @0x00001868;
#define PTGPE                           _PTGPE.Byte
#define PTGPE_PTGPE0                    _PTGPE.Bits.PTGPE0
#define PTGPE_PTGPE1                    _PTGPE.Bits.PTGPE1
#define PTGPE_PTGPE                     _PTGPE.MergedBits.grpPTGPE

#define PTGPE_PTGPE0_MASK               1U
#define PTGPE_PTGPE1_MASK               2U
#define PTGPE_PTGPE_MASK                3U
#define PTGPE_PTGPE_BITNUM              0U


/*** PTGSE - Port G Slew Rate Enable Register; 0x00001869 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGSE0      :1;                                       /* Output Slew Rate Enable for Port G Bit 0 */
    byte PTGSE1      :1;                                       /* Output Slew Rate Enable for Port G Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGSE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGSESTR;
extern volatile PTGSESTR _PTGSE @0x00001869;
#define PTGSE                           _PTGSE.Byte
#define PTGSE_PTGSE0                    _PTGSE.Bits.PTGSE0
#define PTGSE_PTGSE1                    _PTGSE.Bits.PTGSE1
#define PTGSE_PTGSE                     _PTGSE.MergedBits.grpPTGSE

#define PTGSE_PTGSE0_MASK               1U
#define PTGSE_PTGSE1_MASK               2U
#define PTGSE_PTGSE_MASK                3U
#define PTGSE_PTGSE_BITNUM              0U


/*** PTGDS - Port G Drive Strength Selection Register; 0x0000186A ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDS0      :1;                                       /* Output Drive Strength Selection for Port G Bit 0 */
    byte PTGDS1      :1;                                       /* Output Drive Strength Selection for Port G Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGDSSTR;
extern volatile PTGDSSTR _PTGDS @0x0000186A;
#define PTGDS                           _PTGDS.Byte
#define PTGDS_PTGDS0                    _PTGDS.Bits.PTGDS0
#define PTGDS_PTGDS1                    _PTGDS.Bits.PTGDS1
#define PTGDS_PTGDS                     _PTGDS.MergedBits.grpPTGDS

#define PTGDS_PTGDS0_MASK               1U
#define PTGDS_PTGDS1_MASK               2U
#define PTGDS_PTGDS_MASK                3U
#define PTGDS_PTGDS_BITNUM              0U


/*** PTGIFE - Port G Input Filter Enable Register; 0x0000186B ***/
typedef union {
  byte Byte;
  struct {
    byte PTGIFE0     :1;                                       /* Port G Input Filter Enable Bit 0 */
    byte PTGIFE1     :1;                                       /* Port G Input Filter Enable Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGIFE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTGIFESTR;
extern volatile PTGIFESTR _PTGIFE @0x0000186B;
#define PTGIFE                          _PTGIFE.Byte
#define PTGIFE_PTGIFE0                  _PTGIFE.Bits.PTGIFE0
#define PTGIFE_PTGIFE1                  _PTGIFE.Bits.PTGIFE1
#define PTGIFE_PTGIFE                   _PTGIFE.MergedBits.grpPTGIFE

#define PTGIFE_PTGIFE0_MASK             1U
#define PTGIFE_PTGIFE1_MASK             2U
#define PTGIFE_PTGIFE_MASK              3U
#define PTGIFE_PTGIFE_BITNUM            0U


/*** TIAMP1C0 - TIAMP1 Control Register 0; 0x0000186C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPEN        :1;                                       /* Low-Power Enable */
    byte TIAMPEN     :1;                                       /* Trans-Impedance Amplifier Enable */
  } Bits;
} TIAMP1C0STR;
extern volatile TIAMP1C0STR _TIAMP1C0 @0x0000186C;
#define TIAMP1C0                        _TIAMP1C0.Byte
#define TIAMP1C0_LPEN                   _TIAMP1C0.Bits.LPEN
#define TIAMP1C0_TIAMPEN                _TIAMP1C0.Bits.TIAMPEN

#define TIAMP1C0_LPEN_MASK              64U
#define TIAMP1C0_TIAMPEN_MASK           128U


/*** TIAMP2C0 - TIAMP2 Control Register 0; 0x0000186E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPEN        :1;                                       /* Low-Power Enable */
    byte TIAMPEN     :1;                                       /* Trans-Impedance Amplifier Enable */
  } Bits;
} TIAMP2C0STR;
extern volatile TIAMP2C0STR _TIAMP2C0 @0x0000186E;
#define TIAMP2C0                        _TIAMP2C0.Byte
#define TIAMP2C0_LPEN                   _TIAMP2C0.Bits.LPEN
#define TIAMP2C0_TIAMPEN                _TIAMP2C0.Bits.TIAMPEN

#define TIAMP2C0_LPEN_MASK              64U
#define TIAMP2C0_TIAMPEN_MASK           128U


/*** CMTCG1 - Carrier Generator Data Register 1; 0x00001870 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte; 0x00001870 ***/
    union {
      byte Byte;
    } CMTCGH1STR;
    #define CMTCGH1                     _CMTCG1.Overlap_STR.CMTCGH1STR.Byte
    

    /*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte; 0x00001871 ***/
    union {
      byte Byte;
    } CMTCGL1STR;
    #define CMTCGL1                     _CMTCG1.Overlap_STR.CMTCGL1STR.Byte
    
  } Overlap_STR;

} CMTCG1STR;
extern volatile CMTCG1STR _CMTCG1 @0x00001870;
#define CMTCG1                          _CMTCG1.Word


/*** CMTCG2 - Carrier Generator Data Register 2; 0x00001872 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte; 0x00001872 ***/
    union {
      byte Byte;
    } CMTCGH2STR;
    #define CMTCGH2                     _CMTCG2.Overlap_STR.CMTCGH2STR.Byte
    

    /*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte; 0x00001873 ***/
    union {
      byte Byte;
    } CMTCGL2STR;
    #define CMTCGL2                     _CMTCG2.Overlap_STR.CMTCGL2STR.Byte
    
  } Overlap_STR;

} CMTCG2STR;
extern volatile CMTCG2STR _CMTCG2 @0x00001872;
#define CMTCG2                          _CMTCG2.Word


/*** CMTOC - CMT Output Control Register; 0x00001874 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IROPEN      :1;                                       /* IRO pin enable */
    byte CMTPOL      :1;                                       /* CMT output polarity */
    byte IROL        :1;                                       /* IRO latch control */
  } Bits;
} CMTOCSTR;
extern volatile CMTOCSTR _CMTOC @0x00001874;
#define CMTOC                           _CMTOC.Byte
#define CMTOC_IROPEN                    _CMTOC.Bits.IROPEN
#define CMTOC_CMTPOL                    _CMTOC.Bits.CMTPOL
#define CMTOC_IROL                      _CMTOC.Bits.IROL

#define CMTOC_IROPEN_MASK               32U
#define CMTOC_CMTPOL_MASK               64U
#define CMTOC_IROL_MASK                 128U


/*** CMTMSC - CMT Modulator Status and Control Register; 0x00001875 ***/
typedef union {
  byte Byte;
  struct {
    byte MCGEN       :1;                                       /* Modulator and Carrier Generator Enable */
    byte EOCIE       :1;                                       /* End of Cycle Interrupt Enable */
    byte FSK         :1;                                       /* FSK Mode Select */
    byte BASE        :1;                                       /* Baseband Mode Enable */
    byte EXSPC       :1;                                       /* Extended Space Enable */
    byte CMTDIV0     :1;                                       /* CMT Clock Divide Prescaler Bit 0 */
    byte CMTDIV1     :1;                                       /* CMT Clock Divide Prescaler Bit 1 */
    byte EOCF        :1;                                       /* End of Cycle Status Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCMTDIV :2;
    byte         :1;
  } MergedBits;
} CMTMSCSTR;
extern volatile CMTMSCSTR _CMTMSC @0x00001875;
#define CMTMSC                          _CMTMSC.Byte
#define CMTMSC_MCGEN                    _CMTMSC.Bits.MCGEN
#define CMTMSC_EOCIE                    _CMTMSC.Bits.EOCIE
#define CMTMSC_FSK                      _CMTMSC.Bits.FSK
#define CMTMSC_BASE                     _CMTMSC.Bits.BASE
#define CMTMSC_EXSPC                    _CMTMSC.Bits.EXSPC
#define CMTMSC_CMTDIV0                  _CMTMSC.Bits.CMTDIV0
#define CMTMSC_CMTDIV1                  _CMTMSC.Bits.CMTDIV1
#define CMTMSC_EOCF                     _CMTMSC.Bits.EOCF
#define CMTMSC_CMTDIV                   _CMTMSC.MergedBits.grpCMTDIV

#define CMTMSC_MCGEN_MASK               1U
#define CMTMSC_EOCIE_MASK               2U
#define CMTMSC_FSK_MASK                 4U
#define CMTMSC_BASE_MASK                8U
#define CMTMSC_EXSPC_MASK               16U
#define CMTMSC_CMTDIV0_MASK             32U
#define CMTMSC_CMTDIV1_MASK             64U
#define CMTMSC_EOCF_MASK                128U
#define CMTMSC_CMTDIV_MASK              96U
#define CMTMSC_CMTDIV_BITNUM            5U


/*** CMTCMD12 - CMT Modulator Data Register 12; 0x00001876 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD1 - CMT Modulator Data Register 1; 0x00001876 ***/
    union {
      byte Byte;
    } CMTCMD1STR;
    #define CMTCMD1                     _CMTCMD12.Overlap_STR.CMTCMD1STR.Byte
    

    /*** CMTCMD2 - CMT Modulator Data Register 2; 0x00001877 ***/
    union {
      byte Byte;
      struct {
        byte MB0         :1;                                       /* Data Value Bit 0 */
        byte MB1         :1;                                       /* Data Value Bit 1 */
        byte MB2         :1;                                       /* Data Value Bit 2 */
        byte MB3         :1;                                       /* Data Value Bit 3 */
        byte MB4         :1;                                       /* Data Value Bit 4 */
        byte MB5         :1;                                       /* Data Value Bit 5 */
        byte MB6         :1;                                       /* Data Value Bit 6 */
        byte MB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD2STR;
    #define CMTCMD2                     _CMTCMD12.Overlap_STR.CMTCMD2STR.Byte
    #define CMTCMD2_MB0                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB0
    #define CMTCMD2_MB1                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB1
    #define CMTCMD2_MB2                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB2
    #define CMTCMD2_MB3                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB3
    #define CMTCMD2_MB4                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB4
    #define CMTCMD2_MB5                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB5
    #define CMTCMD2_MB6                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB6
    #define CMTCMD2_MB7                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB7
    
    #define CMTCMD2_MB0_MASK            1U
    #define CMTCMD2_MB1_MASK            2U
    #define CMTCMD2_MB2_MASK            4U
    #define CMTCMD2_MB3_MASK            8U
    #define CMTCMD2_MB4_MASK            16U
    #define CMTCMD2_MB5_MASK            32U
    #define CMTCMD2_MB6_MASK            64U
    #define CMTCMD2_MB7_MASK            128U
    
  } Overlap_STR;

} CMTCMD12STR;
extern volatile CMTCMD12STR _CMTCMD12 @0x00001876;
#define CMTCMD12                        _CMTCMD12.Word


/*** CMTCMD34 - CMT Modulator Data Register 34; 0x00001878 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD3 - CMT Modulator Data Register 3; 0x00001878 ***/
    union {
      byte Byte;
    } CMTCMD3STR;
    #define CMTCMD3                     _CMTCMD34.Overlap_STR.CMTCMD3STR.Byte
    

    /*** CMTCMD4 - CMT Modulator Data Register 4; 0x00001879 ***/
    union {
      byte Byte;
      struct {
        byte SB0         :1;                                       /* Data Value Bit 0 */
        byte SB1         :1;                                       /* Data Value Bit 1 */
        byte SB2         :1;                                       /* Data Value Bit 2 */
        byte SB3         :1;                                       /* Data Value Bit 3 */
        byte SB4         :1;                                       /* Data Value Bit 4 */
        byte SB5         :1;                                       /* Data Value Bit 5 */
        byte SB6         :1;                                       /* Data Value Bit 6 */
        byte SB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD4STR;
    #define CMTCMD4                     _CMTCMD34.Overlap_STR.CMTCMD4STR.Byte
    #define CMTCMD4_SB0                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB0
    #define CMTCMD4_SB1                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB1
    #define CMTCMD4_SB2                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB2
    #define CMTCMD4_SB3                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB3
    #define CMTCMD4_SB4                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB4
    #define CMTCMD4_SB5                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB5
    #define CMTCMD4_SB6                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB6
    #define CMTCMD4_SB7                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB7
    
    #define CMTCMD4_SB0_MASK            1U
    #define CMTCMD4_SB1_MASK            2U
    #define CMTCMD4_SB2_MASK            4U
    #define CMTCMD4_SB3_MASK            8U
    #define CMTCMD4_SB4_MASK            16U
    #define CMTCMD4_SB5_MASK            32U
    #define CMTCMD4_SB6_MASK            64U
    #define CMTCMD4_SB7_MASK            128U
    
  } Overlap_STR;

} CMTCMD34STR;
extern volatile CMTCMD34STR _CMTCMD34 @0x00001878;
#define CMTCMD34                        _CMTCMD34.Word


/*** GPAMP1C0 - GPAMP1 Control Register 0; 0x0000187C ***/
typedef union {
  byte Byte;
  struct {
    byte MODE0       :1;                                       /* Mode selection bits, bit 0 */
    byte MODE1       :1;                                       /* Mode selection bits, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPEN        :1;                                       /* Low-power mode enable */
    byte GPAMPEN     :1;                                       /* OPAMP enable */
  } Bits;
  struct {
    byte grpMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GPAMP1C0STR;
extern volatile GPAMP1C0STR _GPAMP1C0 @0x0000187C;
#define GPAMP1C0                        _GPAMP1C0.Byte
#define GPAMP1C0_MODE0                  _GPAMP1C0.Bits.MODE0
#define GPAMP1C0_MODE1                  _GPAMP1C0.Bits.MODE1
#define GPAMP1C0_LPEN                   _GPAMP1C0.Bits.LPEN
#define GPAMP1C0_GPAMPEN                _GPAMP1C0.Bits.GPAMPEN
/* GPAMP1C_ARR: Access 3 GPAMP1Cx registers in an array */
#define GPAMP1C_ARR                     ((volatile byte * __far) &GPAMP1C0)
#define GPAMP1C0_MODE                   _GPAMP1C0.MergedBits.grpMODE

#define GPAMP1C0_MODE0_MASK             1U
#define GPAMP1C0_MODE1_MASK             2U
#define GPAMP1C0_LPEN_MASK              64U
#define GPAMP1C0_GPAMPEN_MASK           128U
#define GPAMP1C0_MODE_MASK              3U
#define GPAMP1C0_MODE_BITNUM            0U


/*** GPAMP1C1 - GPAMP1 Control Register 1; 0x0000187D ***/
typedef union {
  byte Byte;
  struct {
    byte AMPRI0      :1;                                       /* OPAMP Gains Selector, bit 0 */
    byte AMPRI1      :1;                                       /* OPAMP Gains Selector, bit 1 */
    byte AMPRF0      :1;                                       /* OPAMP Gains Selector, bit 0 */
    byte AMPRF1      :1;                                       /* OPAMP Gains Selector, bit 1 */
    byte AMPRF2      :1;                                       /* OPAMP Gains Selector, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpAMPRI :2;
    byte grpAMPRF :3;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GPAMP1C1STR;
extern volatile GPAMP1C1STR _GPAMP1C1 @0x0000187D;
#define GPAMP1C1                        _GPAMP1C1.Byte
#define GPAMP1C1_AMPRI0                 _GPAMP1C1.Bits.AMPRI0
#define GPAMP1C1_AMPRI1                 _GPAMP1C1.Bits.AMPRI1
#define GPAMP1C1_AMPRF0                 _GPAMP1C1.Bits.AMPRF0
#define GPAMP1C1_AMPRF1                 _GPAMP1C1.Bits.AMPRF1
#define GPAMP1C1_AMPRF2                 _GPAMP1C1.Bits.AMPRF2
#define GPAMP1C1_AMPRI                  _GPAMP1C1.MergedBits.grpAMPRI
#define GPAMP1C1_AMPRF                  _GPAMP1C1.MergedBits.grpAMPRF

#define GPAMP1C1_AMPRI0_MASK            1U
#define GPAMP1C1_AMPRI1_MASK            2U
#define GPAMP1C1_AMPRF0_MASK            4U
#define GPAMP1C1_AMPRF1_MASK            8U
#define GPAMP1C1_AMPRF2_MASK            16U
#define GPAMP1C1_AMPRI_MASK             3U
#define GPAMP1C1_AMPRI_BITNUM           0U
#define GPAMP1C1_AMPRF_MASK             28U
#define GPAMP1C1_AMPRF_BITNUM           2U


/*** GPAMP1C2 - GPAMP1 Control Register 2; 0x0000187E ***/
typedef union {
  byte Byte;
  struct {
    byte AMPNSEL0    :1;                                       /* Amplifier negative input terminal selector bits, bit 0 */
    byte AMPNSEL1    :1;                                       /* Amplifier negative input terminal selector bits, bit 1 */
    byte AMPNSEL2    :1;                                       /* Amplifier negative input terminal selector bits, bit 2 */
    byte             :1; 
    byte AMPPSEL0    :1;                                       /* Amplifier positive input terminal selector bits, bit 0 */
    byte AMPPSEL1    :1;                                       /* Amplifier positive input terminal selector bits, bit 1 */
    byte AMPPSEL2    :1;                                       /* Amplifier positive input terminal selector bits, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpAMPNSEL :3;
    byte         :1;
    byte grpAMPPSEL :3;
    byte         :1;
  } MergedBits;
} GPAMP1C2STR;
extern volatile GPAMP1C2STR _GPAMP1C2 @0x0000187E;
#define GPAMP1C2                        _GPAMP1C2.Byte
#define GPAMP1C2_AMPNSEL0               _GPAMP1C2.Bits.AMPNSEL0
#define GPAMP1C2_AMPNSEL1               _GPAMP1C2.Bits.AMPNSEL1
#define GPAMP1C2_AMPNSEL2               _GPAMP1C2.Bits.AMPNSEL2
#define GPAMP1C2_AMPPSEL0               _GPAMP1C2.Bits.AMPPSEL0
#define GPAMP1C2_AMPPSEL1               _GPAMP1C2.Bits.AMPPSEL1
#define GPAMP1C2_AMPPSEL2               _GPAMP1C2.Bits.AMPPSEL2
#define GPAMP1C2_AMPNSEL                _GPAMP1C2.MergedBits.grpAMPNSEL
#define GPAMP1C2_AMPPSEL                _GPAMP1C2.MergedBits.grpAMPPSEL

#define GPAMP1C2_AMPNSEL0_MASK          1U
#define GPAMP1C2_AMPNSEL1_MASK          2U
#define GPAMP1C2_AMPNSEL2_MASK          4U
#define GPAMP1C2_AMPPSEL0_MASK          16U
#define GPAMP1C2_AMPPSEL1_MASK          32U
#define GPAMP1C2_AMPPSEL2_MASK          64U
#define GPAMP1C2_AMPNSEL_MASK           7U
#define GPAMP1C2_AMPNSEL_BITNUM         0U
#define GPAMP1C2_AMPPSEL_MASK           112U
#define GPAMP1C2_AMPPSEL_BITNUM         4U


/*** DBGCA - Debug Comparator A Register; 0x00001880 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001880 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1U
    #define DBGCAH_Bit9_MASK            2U
    #define DBGCAH_Bit10_MASK           4U
    #define DBGCAH_Bit11_MASK           8U
    #define DBGCAH_Bit12_MASK           16U
    #define DBGCAH_Bit13_MASK           32U
    #define DBGCAH_Bit14_MASK           64U
    #define DBGCAH_Bit15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001881 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1U
    #define DBGCAL_Bit1_MASK            2U
    #define DBGCAL_Bit2_MASK            4U
    #define DBGCAL_Bit3_MASK            8U
    #define DBGCAL_Bit4_MASK            16U
    #define DBGCAL_Bit5_MASK            32U
    #define DBGCAL_Bit6_MASK            64U
    #define DBGCAL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA @0x00001880;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001882 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001882 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1U
    #define DBGCBH_Bit9_MASK            2U
    #define DBGCBH_Bit10_MASK           4U
    #define DBGCBH_Bit11_MASK           8U
    #define DBGCBH_Bit12_MASK           16U
    #define DBGCBH_Bit13_MASK           32U
    #define DBGCBH_Bit14_MASK           64U
    #define DBGCBH_Bit15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001883 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1U
    #define DBGCBL_Bit1_MASK            2U
    #define DBGCBL_Bit2_MASK            4U
    #define DBGCBL_Bit3_MASK            8U
    #define DBGCBL_Bit4_MASK            16U
    #define DBGCBL_Bit5_MASK            32U
    #define DBGCBL_Bit6_MASK            64U
    #define DBGCBL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @0x00001882;
#define DBGCB                           _DBGCB.Word


/*** DBGCC - Debug Comparator C Register; 0x00001884 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C High Register; 0x00001884 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator C High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator C High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator C High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator C High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator C High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator C High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator C High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator C High Compare Bit 15 */
      } Bits;
    } DBGCCHSTR;
    #define DBGCCH                      _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_Bit8                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit8
    #define DBGCCH_Bit9                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit9
    #define DBGCCH_Bit10                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit10
    #define DBGCCH_Bit11                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit11
    #define DBGCCH_Bit12                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit12
    #define DBGCCH_Bit13                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit13
    #define DBGCCH_Bit14                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit14
    #define DBGCCH_Bit15                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit15
    
    #define DBGCCH_Bit8_MASK            1U
    #define DBGCCH_Bit9_MASK            2U
    #define DBGCCH_Bit10_MASK           4U
    #define DBGCCH_Bit11_MASK           8U
    #define DBGCCH_Bit12_MASK           16U
    #define DBGCCH_Bit13_MASK           32U
    #define DBGCCH_Bit14_MASK           64U
    #define DBGCCH_Bit15_MASK           128U
    

    /*** DBGCCL - Debug Comparator C Low Register; 0x00001885 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator C Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator C Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator C Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator C Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator C Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator C Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator C Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator C Low Compare Bit 7 */
      } Bits;
    } DBGCCLSTR;
    #define DBGCCL                      _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_Bit0                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit0
    #define DBGCCL_Bit1                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit1
    #define DBGCCL_Bit2                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit2
    #define DBGCCL_Bit3                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit3
    #define DBGCCL_Bit4                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit4
    #define DBGCCL_Bit5                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit5
    #define DBGCCL_Bit6                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit6
    #define DBGCCL_Bit7                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit7
    
    #define DBGCCL_Bit0_MASK            1U
    #define DBGCCL_Bit1_MASK            2U
    #define DBGCCL_Bit2_MASK            4U
    #define DBGCCL_Bit3_MASK            8U
    #define DBGCCL_Bit4_MASK            16U
    #define DBGCCL_Bit5_MASK            32U
    #define DBGCCL_Bit6_MASK            64U
    #define DBGCCL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @0x00001884;
#define DBGCC                           _DBGCC.Word


/*** DBGF - Debug FIFO Register; 0x00001886 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001886 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1U
    #define DBGFH_Bit9_MASK             2U
    #define DBGFH_Bit10_MASK            4U
    #define DBGFH_Bit11_MASK            8U
    #define DBGFH_Bit12_MASK            16U
    #define DBGFH_Bit13_MASK            32U
    #define DBGFH_Bit14_MASK            64U
    #define DBGFH_Bit15_MASK            128U
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001887 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1U
    #define DBGFL_Bit1_MASK             2U
    #define DBGFL_Bit2_MASK             4U
    #define DBGFL_Bit3_MASK             8U
    #define DBGFL_Bit4_MASK             16U
    #define DBGFL_Bit5_MASK             32U
    #define DBGFL_Bit6_MASK             64U
    #define DBGFL_Bit7_MASK             128U
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001886;
#define DBGF                            _DBGF.Word


/*** DBGCAX - Debug Comparator A Extension Register; 0x00001888 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator A Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator A Page Select Bit */
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
  } Bits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @0x00001888;
#define DBGCAX                          _DBGCAX.Byte
#define DBGCAX_Bit16                    _DBGCAX.Bits.Bit16
#define DBGCAX_PAGSEL                   _DBGCAX.Bits.PAGSEL
#define DBGCAX_RWA                      _DBGCAX.Bits.RWA
#define DBGCAX_RWAEN                    _DBGCAX.Bits.RWAEN

#define DBGCAX_Bit16_MASK               1U
#define DBGCAX_PAGSEL_MASK              32U
#define DBGCAX_RWA_MASK                 64U
#define DBGCAX_RWAEN_MASK               128U


/*** DBGCBX - Debug Comparator B Extension Register; 0x00001889 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator B Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator B Page Select Bit */
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
  } Bits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @0x00001889;
#define DBGCBX                          _DBGCBX.Byte
#define DBGCBX_Bit16                    _DBGCBX.Bits.Bit16
#define DBGCBX_PAGSEL                   _DBGCBX.Bits.PAGSEL
#define DBGCBX_RWB                      _DBGCBX.Bits.RWB
#define DBGCBX_RWBEN                    _DBGCBX.Bits.RWBEN

#define DBGCBX_Bit16_MASK               1U
#define DBGCBX_PAGSEL_MASK              32U
#define DBGCBX_RWB_MASK                 64U
#define DBGCBX_RWBEN_MASK               128U


/*** DBGCCX - Debug Comparator C Extension Register; 0x0000188A ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator C Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator C Page Select Bit */
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
  } Bits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @0x0000188A;
#define DBGCCX                          _DBGCCX.Byte
#define DBGCCX_Bit16                    _DBGCCX.Bits.Bit16
#define DBGCCX_PAGSEL                   _DBGCCX.Bits.PAGSEL
#define DBGCCX_RWC                      _DBGCCX.Bits.RWC
#define DBGCCX_RWCEN                    _DBGCCX.Bits.RWCEN

#define DBGCCX_Bit16_MASK               1U
#define DBGCCX_PAGSEL_MASK              32U
#define DBGCCX_RWC_MASK                 64U
#define DBGCCX_RWCEN_MASK               128U


/*** DBGFX - Debug FIFO Extended Information Register; 0x0000188B ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* Extended Address Bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPACC       :1;                                       /* PPAGE Access Indicator Bit */
  } Bits;
} DBGFXSTR;
extern volatile DBGFXSTR _DBGFX @0x0000188B;
#define DBGFX                           _DBGFX.Byte
#define DBGFX_Bit16                     _DBGFX.Bits.Bit16
#define DBGFX_PPACC                     _DBGFX.Bits.PPACC

#define DBGFX_Bit16_MASK                1U
#define DBGFX_PPACC_MASK                128U


/*** DBGC - Debug Control Register; 0x0000188C ***/
typedef union {
  byte Byte;
  struct {
    byte LOOP1       :1;                                       /* Select LOOP1 Capture Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BRKEN       :1;                                       /* Break Enable Bit */
    byte TAG         :1;                                       /* Tag or Force Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Module Enable Bit */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x0000188C;
#define DBGC                            _DBGC.Byte
#define DBGC_LOOP1                      _DBGC.Bits.LOOP1
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_LOOP1_MASK                 1U
#define DBGC_BRKEN_MASK                 16U
#define DBGC_TAG_MASK                   32U
#define DBGC_ARM_MASK                   64U
#define DBGC_DBGEN_MASK                 128U


/*** DBGT - Debug Trigger Register; 0x0000188D ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x0000188D;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1U
#define DBGT_TRG1_MASK                  2U
#define DBGT_TRG2_MASK                  4U
#define DBGT_TRG3_MASK                  8U
#define DBGT_BEGIN_MASK                 64U
#define DBGT_TRGSEL_MASK                128U
#define DBGT_TRG_MASK                   15U
#define DBGT_TRG_BITNUM                 0U


/*** DBGS - Debug Status Register; 0x0000188E ***/
typedef union {
  byte Byte;
  struct {
    byte ARMF        :1;                                       /* Arm Flag Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CF          :1;                                       /* Trigger C Match Bit */
    byte BF          :1;                                       /* Trigger B Match Bit */
    byte AF          :1;                                       /* Trigger A Match Bit */
  } Bits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x0000188E;
#define DBGS                            _DBGS.Byte
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_CF                         _DBGS.Bits.CF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF

#define DBGS_ARMF_MASK                  1U
#define DBGS_CF_MASK                    32U
#define DBGS_BF_MASK                    64U
#define DBGS_AF_MASK                    128U


/*** DBGCNT - Debug Count Status Register; 0x0000188F ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bits, bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bits, bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bits, bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x0000188F;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT_MASK                 15U
#define DBGCNT_CNT_BITNUM               0U


/*** CRCH - CRC High Register; 0x00001890 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* High byte of CRC register ,bit 8 */
    byte BIT9        :1;                                       /* High byte of CRC register ,bit 9 */
    byte BIT10       :1;                                       /* High byte of CRC register ,bit 10 */
    byte BIT11       :1;                                       /* High byte of CRC register ,bit 11 */
    byte BIT12       :1;                                       /* High byte of CRC register ,bit 12 */
    byte BIT13       :1;                                       /* High byte of CRC register ,bit 13 */
    byte BIT14       :1;                                       /* High byte of CRC register ,bit 14 */
    byte BIT15       :1;                                       /* High byte of CRC register ,bit 15 */
  } Bits;
} CRCHSTR;
extern volatile CRCHSTR _CRCH @0x00001890;
#define CRCH                            _CRCH.Byte
#define CRCH_BIT8                       _CRCH.Bits.BIT8
#define CRCH_BIT9                       _CRCH.Bits.BIT9
#define CRCH_BIT10                      _CRCH.Bits.BIT10
#define CRCH_BIT11                      _CRCH.Bits.BIT11
#define CRCH_BIT12                      _CRCH.Bits.BIT12
#define CRCH_BIT13                      _CRCH.Bits.BIT13
#define CRCH_BIT14                      _CRCH.Bits.BIT14
#define CRCH_BIT15                      _CRCH.Bits.BIT15

#define CRCH_BIT8_MASK                  1U
#define CRCH_BIT9_MASK                  2U
#define CRCH_BIT10_MASK                 4U
#define CRCH_BIT11_MASK                 8U
#define CRCH_BIT12_MASK                 16U
#define CRCH_BIT13_MASK                 32U
#define CRCH_BIT14_MASK                 64U
#define CRCH_BIT15_MASK                 128U


/*** CRCL - CRC Low Register; 0x00001891 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCLSTR;
extern volatile CRCLSTR _CRCL @0x00001891;
#define CRCL                            _CRCL.Byte
#define CRCL_BIT0                       _CRCL.Bits.BIT0
#define CRCL_BIT1                       _CRCL.Bits.BIT1
#define CRCL_BIT2                       _CRCL.Bits.BIT2
#define CRCL_BIT3                       _CRCL.Bits.BIT3
#define CRCL_BIT4                       _CRCL.Bits.BIT4
#define CRCL_BIT5                       _CRCL.Bits.BIT5
#define CRCL_BIT6                       _CRCL.Bits.BIT6
#define CRCL_BIT7                       _CRCL.Bits.BIT7

#define CRCL_BIT0_MASK                  1U
#define CRCL_BIT1_MASK                  2U
#define CRCL_BIT2_MASK                  4U
#define CRCL_BIT3_MASK                  8U
#define CRCL_BIT4_MASK                  16U
#define CRCL_BIT5_MASK                  32U
#define CRCL_BIT6_MASK                  64U
#define CRCL_BIT7_MASK                  128U


/*** TRANSPOSE - CRC Transpose Register; 0x00001892 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRC transpose register, bit 0 */
    byte BIT1        :1;                                       /* CRC transpose register, bit 1 */
    byte BIT2        :1;                                       /* CRC transpose register, bit 2 */
    byte BIT3        :1;                                       /* CRC transpose register, bit 3 */
    byte BIT4        :1;                                       /* CRC transpose register, bit 4 */
    byte BIT5        :1;                                       /* CRC transpose register, bit 5 */
    byte BIT6        :1;                                       /* CRC transpose register, bit 6 */
    byte BIT7        :1;                                       /* CRC transpose register, bit 7 */
  } Bits;
} TRANSPOSESTR;
extern volatile TRANSPOSESTR _TRANSPOSE @0x00001892;
#define TRANSPOSE                       _TRANSPOSE.Byte
#define TRANSPOSE_BIT0                  _TRANSPOSE.Bits.BIT0
#define TRANSPOSE_BIT1                  _TRANSPOSE.Bits.BIT1
#define TRANSPOSE_BIT2                  _TRANSPOSE.Bits.BIT2
#define TRANSPOSE_BIT3                  _TRANSPOSE.Bits.BIT3
#define TRANSPOSE_BIT4                  _TRANSPOSE.Bits.BIT4
#define TRANSPOSE_BIT5                  _TRANSPOSE.Bits.BIT5
#define TRANSPOSE_BIT6                  _TRANSPOSE.Bits.BIT6
#define TRANSPOSE_BIT7                  _TRANSPOSE.Bits.BIT7

#define TRANSPOSE_BIT0_MASK             1U
#define TRANSPOSE_BIT1_MASK             2U
#define TRANSPOSE_BIT2_MASK             4U
#define TRANSPOSE_BIT3_MASK             8U
#define TRANSPOSE_BIT4_MASK             16U
#define TRANSPOSE_BIT5_MASK             32U
#define TRANSPOSE_BIT6_MASK             64U
#define TRANSPOSE_BIT7_MASK             128U


/*** GPAMP2C0 - GPAMP2 Control Register 0; 0x00001898 ***/
typedef union {
  byte Byte;
  struct {
    byte MODE0       :1;                                       /* Mode selection bits, bit 0 */
    byte MODE1       :1;                                       /* Mode selection bits, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPEN        :1;                                       /* Low-power mode enable */
    byte GPAMPEN     :1;                                       /* OPAMP enable */
  } Bits;
  struct {
    byte grpMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GPAMP2C0STR;
extern volatile GPAMP2C0STR _GPAMP2C0 @0x00001898;
#define GPAMP2C0                        _GPAMP2C0.Byte
#define GPAMP2C0_MODE0                  _GPAMP2C0.Bits.MODE0
#define GPAMP2C0_MODE1                  _GPAMP2C0.Bits.MODE1
#define GPAMP2C0_LPEN                   _GPAMP2C0.Bits.LPEN
#define GPAMP2C0_GPAMPEN                _GPAMP2C0.Bits.GPAMPEN
/* GPAMP2C_ARR: Access 3 GPAMP2Cx registers in an array */
#define GPAMP2C_ARR                     ((volatile byte * __far) &GPAMP2C0)
#define GPAMP2C0_MODE                   _GPAMP2C0.MergedBits.grpMODE

#define GPAMP2C0_MODE0_MASK             1U
#define GPAMP2C0_MODE1_MASK             2U
#define GPAMP2C0_LPEN_MASK              64U
#define GPAMP2C0_GPAMPEN_MASK           128U
#define GPAMP2C0_MODE_MASK              3U
#define GPAMP2C0_MODE_BITNUM            0U


/*** GPAMP2C1 - GPAMP2 Control Register 1; 0x00001899 ***/
typedef union {
  byte Byte;
  struct {
    byte AMPRI0      :1;                                       /* OPAMP Gains Selector, bit 0 */
    byte AMPRI1      :1;                                       /* OPAMP Gains Selector, bit 1 */
    byte AMPRF0      :1;                                       /* OPAMP Gains Selector, bit 0 */
    byte AMPRF1      :1;                                       /* OPAMP Gains Selector, bit 1 */
    byte AMPRF2      :1;                                       /* OPAMP Gains Selector, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpAMPRI :2;
    byte grpAMPRF :3;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GPAMP2C1STR;
extern volatile GPAMP2C1STR _GPAMP2C1 @0x00001899;
#define GPAMP2C1                        _GPAMP2C1.Byte
#define GPAMP2C1_AMPRI0                 _GPAMP2C1.Bits.AMPRI0
#define GPAMP2C1_AMPRI1                 _GPAMP2C1.Bits.AMPRI1
#define GPAMP2C1_AMPRF0                 _GPAMP2C1.Bits.AMPRF0
#define GPAMP2C1_AMPRF1                 _GPAMP2C1.Bits.AMPRF1
#define GPAMP2C1_AMPRF2                 _GPAMP2C1.Bits.AMPRF2
#define GPAMP2C1_AMPRI                  _GPAMP2C1.MergedBits.grpAMPRI
#define GPAMP2C1_AMPRF                  _GPAMP2C1.MergedBits.grpAMPRF

#define GPAMP2C1_AMPRI0_MASK            1U
#define GPAMP2C1_AMPRI1_MASK            2U
#define GPAMP2C1_AMPRF0_MASK            4U
#define GPAMP2C1_AMPRF1_MASK            8U
#define GPAMP2C1_AMPRF2_MASK            16U
#define GPAMP2C1_AMPRI_MASK             3U
#define GPAMP2C1_AMPRI_BITNUM           0U
#define GPAMP2C1_AMPRF_MASK             28U
#define GPAMP2C1_AMPRF_BITNUM           2U


/*** GPAMP2C2 - GPAMP2 Control Register 2; 0x0000189A ***/
typedef union {
  byte Byte;
  struct {
    byte AMPNSEL0    :1;                                       /* Amplifier negative input terminal selector bits, bit 0 */
    byte AMPNSEL1    :1;                                       /* Amplifier negative input terminal selector bits, bit 1 */
    byte AMPNSEL2    :1;                                       /* Amplifier negative input terminal selector bits, bit 2 */
    byte             :1; 
    byte AMPPSEL0    :1;                                       /* Amplifier positive input terminal selector bits, bit 0 */
    byte AMPPSEL1    :1;                                       /* Amplifier positive input terminal selector bits, bit 1 */
    byte AMPPSEL2    :1;                                       /* Amplifier positive input terminal selector bits, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpAMPNSEL :3;
    byte         :1;
    byte grpAMPPSEL :3;
    byte         :1;
  } MergedBits;
} GPAMP2C2STR;
extern volatile GPAMP2C2STR _GPAMP2C2 @0x0000189A;
#define GPAMP2C2                        _GPAMP2C2.Byte
#define GPAMP2C2_AMPNSEL0               _GPAMP2C2.Bits.AMPNSEL0
#define GPAMP2C2_AMPNSEL1               _GPAMP2C2.Bits.AMPNSEL1
#define GPAMP2C2_AMPNSEL2               _GPAMP2C2.Bits.AMPNSEL2
#define GPAMP2C2_AMPPSEL0               _GPAMP2C2.Bits.AMPPSEL0
#define GPAMP2C2_AMPPSEL1               _GPAMP2C2.Bits.AMPPSEL1
#define GPAMP2C2_AMPPSEL2               _GPAMP2C2.Bits.AMPPSEL2
#define GPAMP2C2_AMPNSEL                _GPAMP2C2.MergedBits.grpAMPNSEL
#define GPAMP2C2_AMPPSEL                _GPAMP2C2.MergedBits.grpAMPPSEL

#define GPAMP2C2_AMPNSEL0_MASK          1U
#define GPAMP2C2_AMPNSEL1_MASK          2U
#define GPAMP2C2_AMPNSEL2_MASK          4U
#define GPAMP2C2_AMPPSEL0_MASK          16U
#define GPAMP2C2_AMPPSEL1_MASK          32U
#define GPAMP2C2_AMPPSEL2_MASK          64U
#define GPAMP2C2_AMPNSEL_MASK           7U
#define GPAMP2C2_AMPNSEL_BITNUM         0U
#define GPAMP2C2_AMPPSEL_MASK           112U
#define GPAMP2C2_AMPPSEL_BITNUM         4U


/*** TODC - TOD Control Register; 0x0000189C ***/
typedef union {
  byte Byte;
  struct {
    byte TODPS0      :1;                                       /* TOD Prescaler Bits, bit 0 */
    byte TODPS1      :1;                                       /* TOD Prescaler Bits, bit 1 */
    byte TODPS2      :1;                                       /* TOD Prescaler Bits, bit 2 */
    byte TODCLKEN    :1;                                       /* TOD Clock Enable */
    byte TODR        :1;                                       /* TOD Reset */
    byte TODCLKS0    :1;                                       /* TOD Clock Source, bit 0 */
    byte TODCLKS1    :1;                                       /* TOD Clock Source, bit 1 */
    byte TODEN       :1;                                       /* Time of Day Enable */
  } Bits;
  struct {
    byte grpTODPS :3;
    byte         :1;
    byte         :1;
    byte grpTODCLKS :2;
    byte         :1;
  } MergedBits;
} TODCSTR;
extern volatile TODCSTR _TODC @0x0000189C;
#define TODC                            _TODC.Byte
#define TODC_TODPS0                     _TODC.Bits.TODPS0
#define TODC_TODPS1                     _TODC.Bits.TODPS1
#define TODC_TODPS2                     _TODC.Bits.TODPS2
#define TODC_TODCLKEN                   _TODC.Bits.TODCLKEN
#define TODC_TODR                       _TODC.Bits.TODR
#define TODC_TODCLKS0                   _TODC.Bits.TODCLKS0
#define TODC_TODCLKS1                   _TODC.Bits.TODCLKS1
#define TODC_TODEN                      _TODC.Bits.TODEN
#define TODC_TODPS                      _TODC.MergedBits.grpTODPS
#define TODC_TODCLKS                    _TODC.MergedBits.grpTODCLKS

#define TODC_TODPS0_MASK                1U
#define TODC_TODPS1_MASK                2U
#define TODC_TODPS2_MASK                4U
#define TODC_TODCLKEN_MASK              8U
#define TODC_TODR_MASK                  16U
#define TODC_TODCLKS0_MASK              32U
#define TODC_TODCLKS1_MASK              64U
#define TODC_TODEN_MASK                 128U
#define TODC_TODPS_MASK                 7U
#define TODC_TODPS_BITNUM               0U
#define TODC_TODCLKS_MASK               96U
#define TODC_TODCLKS_BITNUM             5U


/*** TODSC - TOD Status and Control Register; 0x0000189D ***/
typedef union {
  byte Byte;
  struct {
    byte MTCHWC      :1;                                       /* Match Write Complete */
    byte MTCHEN      :1;                                       /* Match Function Enable */
    byte MTCHIE      :1;                                       /* Match Interrupt Enable */
    byte SECIE       :1;                                       /* Second Interrupt Enable */
    byte QSECIE      :1;                                       /* Quarter-Second Interrupt Enable */
    byte MTCHF       :1;                                       /* Match Interrupt Flag */
    byte SECF        :1;                                       /* Second Interrupt Flag */
    byte QSECF       :1;                                       /* Quarter-Second Interrupt Flag */
  } Bits;
} TODSCSTR;
extern volatile TODSCSTR _TODSC @0x0000189D;
#define TODSC                           _TODSC.Byte
#define TODSC_MTCHWC                    _TODSC.Bits.MTCHWC
#define TODSC_MTCHEN                    _TODSC.Bits.MTCHEN
#define TODSC_MTCHIE                    _TODSC.Bits.MTCHIE
#define TODSC_SECIE                     _TODSC.Bits.SECIE
#define TODSC_QSECIE                    _TODSC.Bits.QSECIE
#define TODSC_MTCHF                     _TODSC.Bits.MTCHF
#define TODSC_SECF                      _TODSC.Bits.SECF
#define TODSC_QSECF                     _TODSC.Bits.QSECF

#define TODSC_MTCHWC_MASK               1U
#define TODSC_MTCHEN_MASK               2U
#define TODSC_MTCHIE_MASK               4U
#define TODSC_SECIE_MASK                8U
#define TODSC_QSECIE_MASK               16U
#define TODSC_MTCHF_MASK                32U
#define TODSC_SECF_MASK                 64U
#define TODSC_QSECF_MASK                128U


/*** TODM - TOD Match Register; 0x0000189E ***/
typedef union {
  byte Byte;
  struct {
    byte MQSEC0      :1;                                       /* Match Quarter-Second Bits, bit 0 */
    byte MQSEC1      :1;                                       /* Match Quarter-Second Bits, bit 1 */
    byte TODM0       :1;                                       /* TOD Match Value, bit 0 */
    byte TODM1       :1;                                       /* TOD Match Value, bit 1 */
    byte TODM2       :1;                                       /* TOD Match Value, bit 2 */
    byte TODM3       :1;                                       /* TOD Match Value, bit 3 */
    byte TODM4       :1;                                       /* TOD Match Value, bit 4 */
    byte TODM5       :1;                                       /* TOD Match Value, bit 5 */
  } Bits;
  struct {
    byte grpMQSEC :2;
    byte grpTODM :6;
  } MergedBits;
} TODMSTR;
extern volatile TODMSTR _TODM @0x0000189E;
#define TODM                            _TODM.Byte
#define TODM_MQSEC0                     _TODM.Bits.MQSEC0
#define TODM_MQSEC1                     _TODM.Bits.MQSEC1
#define TODM_TODM0                      _TODM.Bits.TODM0
#define TODM_TODM1                      _TODM.Bits.TODM1
#define TODM_TODM2                      _TODM.Bits.TODM2
#define TODM_TODM3                      _TODM.Bits.TODM3
#define TODM_TODM4                      _TODM.Bits.TODM4
#define TODM_TODM5                      _TODM.Bits.TODM5
#define TODM_MQSEC                      _TODM.MergedBits.grpMQSEC
#define TODM_TODM                       _TODM.MergedBits.grpTODM

#define TODM_MQSEC0_MASK                1U
#define TODM_MQSEC1_MASK                2U
#define TODM_TODM0_MASK                 4U
#define TODM_TODM1_MASK                 8U
#define TODM_TODM2_MASK                 16U
#define TODM_TODM3_MASK                 32U
#define TODM_TODM4_MASK                 64U
#define TODM_TODM5_MASK                 128U
#define TODM_MQSEC_MASK                 3U
#define TODM_MQSEC_BITNUM               0U
#define TODM_TODM_MASK                  252U
#define TODM_TODM_BITNUM                2U


/*** TODCNT - TOD Counter Register; 0x0000189F ***/
typedef union {
  byte Byte;
} TODCNTSTR;
extern volatile TODCNTSTR _TODCNT @0x0000189F;
#define TODCNT                          _TODCNT.Byte


/*** TPM2SC - TPM2 Status and Control Register; 0x000018A0 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
extern volatile TPM2SCSTR _TPM2SC @0x000018A0;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1U
#define TPM2SC_PS1_MASK                 2U
#define TPM2SC_PS2_MASK                 4U
#define TPM2SC_CLKSA_MASK               8U
#define TPM2SC_CLKSB_MASK               16U
#define TPM2SC_CPWMS_MASK               32U
#define TPM2SC_TOIE_MASK                64U
#define TPM2SC_TOF_MASK                 128U
#define TPM2SC_PS_MASK                  7U
#define TPM2SC_PS_BITNUM                0U
#define TPM2SC_CLKSx_MASK               24U
#define TPM2SC_CLKSx_BITNUM             3U


/*** TPM2CNT - TPM2 Timer Counter Register; 0x000018A1 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0x000018A1 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x000018A2 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
extern volatile TPM2CNTSTR _TPM2CNT @0x000018A1;
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x000018A3 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x000018A3 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x000018A4 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
extern volatile TPM2MODSTR _TPM2MOD @0x000018A3;
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x000018A5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
extern volatile TPM2C0SCSTR _TPM2C0SC @0x000018A5;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4U
#define TPM2C0SC_ELS0B_MASK             8U
#define TPM2C0SC_MS0A_MASK              16U
#define TPM2C0SC_MS0B_MASK              32U
#define TPM2C0SC_CH0IE_MASK             64U
#define TPM2C0SC_CH0F_MASK              128U
#define TPM2C0SC_ELS0x_MASK             12U
#define TPM2C0SC_ELS0x_BITNUM           2U
#define TPM2C0SC_MS0x_MASK              48U
#define TPM2C0SC_MS0x_BITNUM            4U


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x000018A6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x000018A6 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x000018A7 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
extern volatile TPM2C0VSTR _TPM2C0V @0x000018A6;
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0x000018A8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
extern volatile TPM2C1SCSTR _TPM2C1SC @0x000018A8;
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4U
#define TPM2C1SC_ELS1B_MASK             8U
#define TPM2C1SC_MS1A_MASK              16U
#define TPM2C1SC_MS1B_MASK              32U
#define TPM2C1SC_CH1IE_MASK             64U
#define TPM2C1SC_CH1F_MASK              128U
#define TPM2C1SC_ELS1x_MASK             12U
#define TPM2C1SC_ELS1x_BITNUM           2U
#define TPM2C1SC_MS1x_MASK              48U
#define TPM2C1SC_MS1x_BITNUM            4U


/*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0x000018A9 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0x000018A9 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    

    /*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0x000018AA ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
  } Overlap_STR;

} TPM2C1VSTR;
extern volatile TPM2C1VSTR _TPM2C1V @0x000018A9;
#define TPM2C1V                         _TPM2C1V.Word


/*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register; 0x000018AB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for TPM Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for TPM Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C2SCSTR;
extern volatile TPM2C2SCSTR _TPM2C2SC @0x000018AB;
#define TPM2C2SC                        _TPM2C2SC.Byte
#define TPM2C2SC_ELS2A                  _TPM2C2SC.Bits.ELS2A
#define TPM2C2SC_ELS2B                  _TPM2C2SC.Bits.ELS2B
#define TPM2C2SC_MS2A                   _TPM2C2SC.Bits.MS2A
#define TPM2C2SC_MS2B                   _TPM2C2SC.Bits.MS2B
#define TPM2C2SC_CH2IE                  _TPM2C2SC.Bits.CH2IE
#define TPM2C2SC_CH2F                   _TPM2C2SC.Bits.CH2F
#define TPM2C2SC_ELS2x                  _TPM2C2SC.MergedBits.grpELS2x
#define TPM2C2SC_MS2x                   _TPM2C2SC.MergedBits.grpMS2x

#define TPM2C2SC_ELS2A_MASK             4U
#define TPM2C2SC_ELS2B_MASK             8U
#define TPM2C2SC_MS2A_MASK              16U
#define TPM2C2SC_MS2B_MASK              32U
#define TPM2C2SC_CH2IE_MASK             64U
#define TPM2C2SC_CH2F_MASK              128U
#define TPM2C2SC_ELS2x_MASK             12U
#define TPM2C2SC_ELS2x_BITNUM           2U
#define TPM2C2SC_MS2x_MASK              48U
#define TPM2C2SC_MS2x_BITNUM            4U


/*** TPM2C2V - TPM2 Timer Channel 2 Value Register; 0x000018AC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High; 0x000018AC ***/
    union {
      byte Byte;
    } TPM2C2VHSTR;
    #define TPM2C2VH                    _TPM2C2V.Overlap_STR.TPM2C2VHSTR.Byte
    

    /*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low; 0x000018AD ***/
    union {
      byte Byte;
    } TPM2C2VLSTR;
    #define TPM2C2VL                    _TPM2C2V.Overlap_STR.TPM2C2VLSTR.Byte
    
  } Overlap_STR;

} TPM2C2VSTR;
extern volatile TPM2C2VSTR _TPM2C2V @0x000018AC;
#define TPM2C2V                         _TPM2C2V.Word


/*** TPM2C3SC - TPM2 Timer Channel 3 Status and Control Register; 0x000018AE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for TPM Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for TPM Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C3SCSTR;
extern volatile TPM2C3SCSTR _TPM2C3SC @0x000018AE;
#define TPM2C3SC                        _TPM2C3SC.Byte
#define TPM2C3SC_ELS3A                  _TPM2C3SC.Bits.ELS3A
#define TPM2C3SC_ELS3B                  _TPM2C3SC.Bits.ELS3B
#define TPM2C3SC_MS3A                   _TPM2C3SC.Bits.MS3A
#define TPM2C3SC_MS3B                   _TPM2C3SC.Bits.MS3B
#define TPM2C3SC_CH3IE                  _TPM2C3SC.Bits.CH3IE
#define TPM2C3SC_CH3F                   _TPM2C3SC.Bits.CH3F
#define TPM2C3SC_ELS3x                  _TPM2C3SC.MergedBits.grpELS3x
#define TPM2C3SC_MS3x                   _TPM2C3SC.MergedBits.grpMS3x

#define TPM2C3SC_ELS3A_MASK             4U
#define TPM2C3SC_ELS3B_MASK             8U
#define TPM2C3SC_MS3A_MASK              16U
#define TPM2C3SC_MS3B_MASK              32U
#define TPM2C3SC_CH3IE_MASK             64U
#define TPM2C3SC_CH3F_MASK              128U
#define TPM2C3SC_ELS3x_MASK             12U
#define TPM2C3SC_ELS3x_BITNUM           2U
#define TPM2C3SC_MS3x_MASK              48U
#define TPM2C3SC_MS3x_BITNUM            4U


/*** TPM2C3V - TPM2 Timer Channel 3 Value Register; 0x000018AF ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C3VH - TPM2 Timer Channel 3 Value Register High; 0x000018AF ***/
    union {
      byte Byte;
    } TPM2C3VHSTR;
    #define TPM2C3VH                    _TPM2C3V.Overlap_STR.TPM2C3VHSTR.Byte
    

    /*** TPM2C3VL - TPM2 Timer Channel 3 Value Register Low; 0x000018B0 ***/
    union {
      byte Byte;
    } TPM2C3VLSTR;
    #define TPM2C3VL                    _TPM2C3V.Overlap_STR.TPM2C3VLSTR.Byte
    
  } Overlap_STR;

} TPM2C3VSTR;
extern volatile TPM2C3VSTR _TPM2C3V @0x000018AF;
#define TPM2C3V                         _TPM2C3V.Word


/*** SCI1BD - SCI1 Baud Rate Register; 0x000018B8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI1 Baud Rate Register High; 0x000018B8 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH                     _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_RXEDGIE             _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.RXEDGIE
    #define SCI1BDH_LBKDIE              _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.LBKDIE
    #define SCI1BDH_SBR_8               _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_SBR                 SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK           1U
    #define SCI1BDH_SBR9_MASK           2U
    #define SCI1BDH_SBR10_MASK          4U
    #define SCI1BDH_SBR11_MASK          8U
    #define SCI1BDH_SBR12_MASK          16U
    #define SCI1BDH_RXEDGIE_MASK        64U
    #define SCI1BDH_LBKDIE_MASK         128U
    #define SCI1BDH_SBR_8_MASK          31U
    #define SCI1BDH_SBR_8_BITNUM        0U
    

    /*** SCI1BDL - SCI1 Baud Rate Register Low; 0x000018B9 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI1BDLSTR;
    #define SCI1BDL                     _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    #define SCI1BDL_SBR0_MASK           1U
    #define SCI1BDL_SBR1_MASK           2U
    #define SCI1BDL_SBR2_MASK           4U
    #define SCI1BDL_SBR3_MASK           8U
    #define SCI1BDL_SBR4_MASK           16U
    #define SCI1BDL_SBR5_MASK           32U
    #define SCI1BDL_SBR6_MASK           64U
    #define SCI1BDL_SBR7_MASK           128U
    
  } Overlap_STR;

} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @0x000018B8;
#define SCI1BD                          _SCI1BD.Word


/*** SCI1C1 - SCI1 Control Register 1; 0x000018BA ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI1C1STR;
extern volatile SCI1C1STR _SCI1C1 @0x000018BA;
#define SCI1C1                          _SCI1C1.Byte
#define SCI1C1_PT                       _SCI1C1.Bits.PT
#define SCI1C1_PE                       _SCI1C1.Bits.PE
#define SCI1C1_ILT                      _SCI1C1.Bits.ILT
#define SCI1C1_WAKE                     _SCI1C1.Bits.WAKE
#define SCI1C1_M                        _SCI1C1.Bits.M
#define SCI1C1_RSRC                     _SCI1C1.Bits.RSRC
#define SCI1C1_SCISWAI                  _SCI1C1.Bits.SCISWAI
#define SCI1C1_LOOPS                    _SCI1C1.Bits.LOOPS

#define SCI1C1_PT_MASK                  1U
#define SCI1C1_PE_MASK                  2U
#define SCI1C1_ILT_MASK                 4U
#define SCI1C1_WAKE_MASK                8U
#define SCI1C1_M_MASK                   16U
#define SCI1C1_RSRC_MASK                32U
#define SCI1C1_SCISWAI_MASK             64U
#define SCI1C1_LOOPS_MASK               128U


/*** SCI1C2 - SCI1 Control Register 2; 0x000018BB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI1C2STR;
extern volatile SCI1C2STR _SCI1C2 @0x000018BB;
#define SCI1C2                          _SCI1C2.Byte
#define SCI1C2_SBK                      _SCI1C2.Bits.SBK
#define SCI1C2_RWU                      _SCI1C2.Bits.RWU
#define SCI1C2_RE                       _SCI1C2.Bits.RE
#define SCI1C2_TE                       _SCI1C2.Bits.TE
#define SCI1C2_ILIE                     _SCI1C2.Bits.ILIE
#define SCI1C2_RIE                      _SCI1C2.Bits.RIE
#define SCI1C2_TCIE                     _SCI1C2.Bits.TCIE
#define SCI1C2_TIE                      _SCI1C2.Bits.TIE

#define SCI1C2_SBK_MASK                 1U
#define SCI1C2_RWU_MASK                 2U
#define SCI1C2_RE_MASK                  4U
#define SCI1C2_TE_MASK                  8U
#define SCI1C2_ILIE_MASK                16U
#define SCI1C2_RIE_MASK                 32U
#define SCI1C2_TCIE_MASK                64U
#define SCI1C2_TIE_MASK                 128U


/*** SCI1S1 - SCI1 Status Register 1; 0x000018BC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1S1STR;
extern volatile SCI1S1STR _SCI1S1 @0x000018BC;
#define SCI1S1                          _SCI1S1.Byte
#define SCI1S1_PF                       _SCI1S1.Bits.PF
#define SCI1S1_FE                       _SCI1S1.Bits.FE
#define SCI1S1_NF                       _SCI1S1.Bits.NF
#define SCI1S1_OR                       _SCI1S1.Bits.OR
#define SCI1S1_IDLE                     _SCI1S1.Bits.IDLE
#define SCI1S1_RDRF                     _SCI1S1.Bits.RDRF
#define SCI1S1_TC                       _SCI1S1.Bits.TC
#define SCI1S1_TDRE                     _SCI1S1.Bits.TDRE

#define SCI1S1_PF_MASK                  1U
#define SCI1S1_FE_MASK                  2U
#define SCI1S1_NF_MASK                  4U
#define SCI1S1_OR_MASK                  8U
#define SCI1S1_IDLE_MASK                16U
#define SCI1S1_RDRF_MASK                32U
#define SCI1S1_TC_MASK                  64U
#define SCI1S1_TDRE_MASK                128U


/*** SCI1S2 - SCI1 Status Register 2; 0x000018BD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI1S2STR;
extern volatile SCI1S2STR _SCI1S2 @0x000018BD;
#define SCI1S2                          _SCI1S2.Byte
#define SCI1S2_RAF                      _SCI1S2.Bits.RAF
#define SCI1S2_LBKDE                    _SCI1S2.Bits.LBKDE
#define SCI1S2_BRK13                    _SCI1S2.Bits.BRK13
#define SCI1S2_RWUID                    _SCI1S2.Bits.RWUID
#define SCI1S2_RXINV                    _SCI1S2.Bits.RXINV
#define SCI1S2_RXEDGIF                  _SCI1S2.Bits.RXEDGIF
#define SCI1S2_LBKDIF                   _SCI1S2.Bits.LBKDIF

#define SCI1S2_RAF_MASK                 1U
#define SCI1S2_LBKDE_MASK               2U
#define SCI1S2_BRK13_MASK               4U
#define SCI1S2_RWUID_MASK               8U
#define SCI1S2_RXINV_MASK               16U
#define SCI1S2_RXEDGIF_MASK             64U
#define SCI1S2_LBKDIF_MASK              128U


/*** SCI1C3 - SCI1 Control Register 3; 0x000018BE ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI1C3STR;
extern volatile SCI1C3STR _SCI1C3 @0x000018BE;
#define SCI1C3                          _SCI1C3.Byte
#define SCI1C3_PEIE                     _SCI1C3.Bits.PEIE
#define SCI1C3_FEIE                     _SCI1C3.Bits.FEIE
#define SCI1C3_NEIE                     _SCI1C3.Bits.NEIE
#define SCI1C3_ORIE                     _SCI1C3.Bits.ORIE
#define SCI1C3_TXINV                    _SCI1C3.Bits.TXINV
#define SCI1C3_TXDIR                    _SCI1C3.Bits.TXDIR
#define SCI1C3_T8                       _SCI1C3.Bits.T8
#define SCI1C3_R8                       _SCI1C3.Bits.R8

#define SCI1C3_PEIE_MASK                1U
#define SCI1C3_FEIE_MASK                2U
#define SCI1C3_NEIE_MASK                4U
#define SCI1C3_ORIE_MASK                8U
#define SCI1C3_TXINV_MASK               16U
#define SCI1C3_TXDIR_MASK               32U
#define SCI1C3_T8_MASK                  64U
#define SCI1C3_R8_MASK                  128U


/*** SCI1D - SCI1 Data Register; 0x000018BF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI1DSTR;
extern volatile SCI1DSTR _SCI1D @0x000018BF;
#define SCI1D                           _SCI1D.Byte
#define SCI1D_R0_T0                     _SCI1D.Bits.R0_T0
#define SCI1D_R1_T1                     _SCI1D.Bits.R1_T1
#define SCI1D_R2_T2                     _SCI1D.Bits.R2_T2
#define SCI1D_R3_T3                     _SCI1D.Bits.R3_T3
#define SCI1D_R4_T4                     _SCI1D.Bits.R4_T4
#define SCI1D_R5_T5                     _SCI1D.Bits.R5_T5
#define SCI1D_R6_T6                     _SCI1D.Bits.R6_T6
#define SCI1D_R7_T7                     _SCI1D.Bits.R7_T7

#define SCI1D_R0_T0_MASK                1U
#define SCI1D_R1_T1_MASK                2U
#define SCI1D_R2_T2_MASK                4U
#define SCI1D_R3_T3_MASK                8U
#define SCI1D_R4_T4_MASK                16U
#define SCI1D_R5_T5_MASK                32U
#define SCI1D_R6_T6_MASK                64U
#define SCI1D_R7_T7_MASK                128U


/*** PDBSC - PDB Status and Control Register; 0x000018C0 ***/
typedef union {
  byte Byte;
  struct {
    byte LDOK        :1;                                       /* Load OK */
    byte DACTOE      :1;                                       /* DAC Trigger Output Enable */
    byte TOS0        :1;                                       /* Trigger Output Select, bit 0 */
    byte TOS1        :1;                                       /* Trigger Output Select, bit 1 */
    byte LDMOD       :1;                                       /* Load Mode Select */
    byte PDBIE       :1;                                       /* PDB Interrupt Enable */
    byte PDBIF       :1;                                       /* PDB Interrupt Flag */
    byte PDBEN       :1;                                       /* PDB module Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTOS  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PDBSCSTR;
extern volatile PDBSCSTR _PDBSC @0x000018C0;
#define PDBSC                           _PDBSC.Byte
#define PDBSC_LDOK                      _PDBSC.Bits.LDOK
#define PDBSC_DACTOE                    _PDBSC.Bits.DACTOE
#define PDBSC_TOS0                      _PDBSC.Bits.TOS0
#define PDBSC_TOS1                      _PDBSC.Bits.TOS1
#define PDBSC_LDMOD                     _PDBSC.Bits.LDMOD
#define PDBSC_PDBIE                     _PDBSC.Bits.PDBIE
#define PDBSC_PDBIF                     _PDBSC.Bits.PDBIF
#define PDBSC_PDBEN                     _PDBSC.Bits.PDBEN
#define PDBSC_TOS                       _PDBSC.MergedBits.grpTOS

#define PDBSC_LDOK_MASK                 1U
#define PDBSC_DACTOE_MASK               2U
#define PDBSC_TOS0_MASK                 4U
#define PDBSC_TOS1_MASK                 8U
#define PDBSC_LDMOD_MASK                16U
#define PDBSC_PDBIE_MASK                32U
#define PDBSC_PDBIF_MASK                64U
#define PDBSC_PDBEN_MASK                128U
#define PDBSC_TOS_MASK                  12U
#define PDBSC_TOS_BITNUM                2U


/*** PDBC1 - PDB Control Register 1; 0x000018C1 ***/
typedef union {
  byte Byte;
  struct {
    byte MULT        :1;                                       /* Multiply prescaler bit */
    byte CONT        :1;                                       /* Continuous Mode Enable */
    byte TRIGSEL0    :1;                                       /* Input Trigger Select, bit 0 */
    byte TRIGSEL1    :1;                                       /* Input Trigger Select, bit 1 */
    byte TRIGSEL2    :1;                                       /* Input Trigger Select, bit 2 */
    byte PRESCALER0  :1;                                       /* Clock Prescaler Select, bit 0 */
    byte PRESCALER1  :1;                                       /* Clock Prescaler Select, bit 1 */
    byte PRESCALER2  :1;                                       /* Clock Prescaler Select, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTRIGSEL :3;
    byte grpPRESCALER :3;
  } MergedBits;
} PDBC1STR;
extern volatile PDBC1STR _PDBC1 @0x000018C1;
#define PDBC1                           _PDBC1.Byte
#define PDBC1_MULT                      _PDBC1.Bits.MULT
#define PDBC1_CONT                      _PDBC1.Bits.CONT
#define PDBC1_TRIGSEL0                  _PDBC1.Bits.TRIGSEL0
#define PDBC1_TRIGSEL1                  _PDBC1.Bits.TRIGSEL1
#define PDBC1_TRIGSEL2                  _PDBC1.Bits.TRIGSEL2
#define PDBC1_PRESCALER0                _PDBC1.Bits.PRESCALER0
#define PDBC1_PRESCALER1                _PDBC1.Bits.PRESCALER1
#define PDBC1_PRESCALER2                _PDBC1.Bits.PRESCALER2
#define PDBC1_TRIGSEL                   _PDBC1.MergedBits.grpTRIGSEL
#define PDBC1_PRESCALER                 _PDBC1.MergedBits.grpPRESCALER

#define PDBC1_MULT_MASK                 1U
#define PDBC1_CONT_MASK                 2U
#define PDBC1_TRIGSEL0_MASK             4U
#define PDBC1_TRIGSEL1_MASK             8U
#define PDBC1_TRIGSEL2_MASK             16U
#define PDBC1_PRESCALER0_MASK           32U
#define PDBC1_PRESCALER1_MASK           64U
#define PDBC1_PRESCALER2_MASK           128U
#define PDBC1_TRIGSEL_MASK              28U
#define PDBC1_TRIGSEL_BITNUM            2U
#define PDBC1_PRESCALER_MASK            224U
#define PDBC1_PRESCALER_BITNUM          5U


/*** PDBC2 - PDB Control Register 2; 0x000018C2 ***/
typedef union {
  byte Byte;
  struct {
    byte SWTRIG      :1;                                       /* SoftwareTrigger */
    byte BB1         :1;                                       /* Back to Back enable, bit 1 */
    byte BB2         :1;                                       /* Back to Back enable, bit 2 */
    byte BB3         :1;                                       /* Back to Back enable, bit 3 */
    byte BB4         :1;                                       /* Back to Back enable, bit 4 */
    byte BB5         :1;                                       /* Back to Back enable, bit 5 */
    byte BB6         :1;                                       /* Back to Back enable, bit 6 */
    byte BB7         :1;                                       /* Back to Back enable, bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpBB_1 :7;
  } MergedBits;
} PDBC2STR;
extern volatile PDBC2STR _PDBC2 @0x000018C2;
#define PDBC2                           _PDBC2.Byte
#define PDBC2_SWTRIG                    _PDBC2.Bits.SWTRIG
#define PDBC2_BB1                       _PDBC2.Bits.BB1
#define PDBC2_BB2                       _PDBC2.Bits.BB2
#define PDBC2_BB3                       _PDBC2.Bits.BB3
#define PDBC2_BB4                       _PDBC2.Bits.BB4
#define PDBC2_BB5                       _PDBC2.Bits.BB5
#define PDBC2_BB6                       _PDBC2.Bits.BB6
#define PDBC2_BB7                       _PDBC2.Bits.BB7
#define PDBC2_BB_1                      _PDBC2.MergedBits.grpBB_1
#define PDBC2_BB                        PDBC2_BB_1

#define PDBC2_SWTRIG_MASK               1U
#define PDBC2_BB1_MASK                  2U
#define PDBC2_BB2_MASK                  4U
#define PDBC2_BB3_MASK                  8U
#define PDBC2_BB4_MASK                  16U
#define PDBC2_BB5_MASK                  32U
#define PDBC2_BB6_MASK                  64U
#define PDBC2_BB7_MASK                  128U
#define PDBC2_BB_1_MASK                 254U
#define PDBC2_BB_1_BITNUM               1U


/*** PDBCHEN - PDB Channel Enable; 0x000018C3 ***/
typedef union {
  byte Byte;
  struct {
    byte CHEN0       :1;                                       /* PDB channel enable, bit 0 */
    byte CHEN1       :1;                                       /* PDB channel enable, bit 1 */
    byte CHEN2       :1;                                       /* PDB channel enable, bit 2 */
    byte CHEN3       :1;                                       /* PDB channel enable, bit 3 */
    byte CHEN4       :1;                                       /* PDB channel enable, bit 4 */
    byte CHEN5       :1;                                       /* PDB channel enable, bit 5 */
    byte CHEN6       :1;                                       /* PDB channel enable, bit 6 */
    byte CHEN7       :1;                                       /* PDB channel enable, bit 7 */
  } Bits;
} PDBCHENSTR;
extern volatile PDBCHENSTR _PDBCHEN @0x000018C3;
#define PDBCHEN                         _PDBCHEN.Byte
#define PDBCHEN_CHEN0                   _PDBCHEN.Bits.CHEN0
#define PDBCHEN_CHEN1                   _PDBCHEN.Bits.CHEN1
#define PDBCHEN_CHEN2                   _PDBCHEN.Bits.CHEN2
#define PDBCHEN_CHEN3                   _PDBCHEN.Bits.CHEN3
#define PDBCHEN_CHEN4                   _PDBCHEN.Bits.CHEN4
#define PDBCHEN_CHEN5                   _PDBCHEN.Bits.CHEN5
#define PDBCHEN_CHEN6                   _PDBCHEN.Bits.CHEN6
#define PDBCHEN_CHEN7                   _PDBCHEN.Bits.CHEN7

#define PDBCHEN_CHEN0_MASK              1U
#define PDBCHEN_CHEN1_MASK              2U
#define PDBCHEN_CHEN2_MASK              4U
#define PDBCHEN_CHEN3_MASK              8U
#define PDBCHEN_CHEN4_MASK              16U
#define PDBCHEN_CHEN5_MASK              32U
#define PDBCHEN_CHEN6_MASK              64U
#define PDBCHEN_CHEN7_MASK              128U


/*** PDBMOD - PDB Modulus Register; 0x000018C4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBMODH - PDB Modulus Register High; 0x000018C4 ***/
    union {
      byte Byte;
    } PDBMODHSTR;
    #define PDBMODH                     _PDBMOD.Overlap_STR.PDBMODHSTR.Byte
    

    /*** PDBMODL - PDB Modulus Register Low; 0x000018C5 ***/
    union {
      byte Byte;
    } PDBMODLSTR;
    #define PDBMODL                     _PDBMOD.Overlap_STR.PDBMODLSTR.Byte
    
  } Overlap_STR;

} PDBMODSTR;
extern volatile PDBMODSTR _PDBMOD @0x000018C4;
#define PDBMOD                          _PDBMOD.Word


/*** PDBCNT - PDB Counter Register; 0x000018C6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBCNTH - PDB Counter Register High; 0x000018C6 ***/
    union {
      byte Byte;
    } PDBCNTHSTR;
    #define PDBCNTH                     _PDBCNT.Overlap_STR.PDBCNTHSTR.Byte
    

    /*** PDBCNTL - PDB Counter Register Low; 0x000018C7 ***/
    union {
      byte Byte;
    } PDBCNTLSTR;
    #define PDBCNTL                     _PDBCNT.Overlap_STR.PDBCNTLSTR.Byte
    
  } Overlap_STR;

} PDBCNTSTR;
extern volatile PDBCNTSTR _PDBCNT @0x000018C6;
#define PDBCNT                          _PDBCNT.Word


/*** PDBIDLY - PDB Interrupt Delay Register; 0x000018C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBIDLYH - PDB Interrupt Delay Register High; 0x000018C8 ***/
    union {
      byte Byte;
      struct {
        byte IDELAY8     :1;                                       /* Interrupt Delay, bit 8 */
        byte IDELAY9     :1;                                       /* Interrupt Delay, bit 9 */
        byte IDELAY10    :1;                                       /* Interrupt Delay, bit 10 */
        byte IDELAY11    :1;                                       /* Interrupt Delay, bit 11 */
        byte IDELAY12    :1;                                       /* Interrupt Delay, bit 12 */
        byte IDELAY13    :1;                                       /* Interrupt Delay, bit 13 */
        byte IDELAY14    :1;                                       /* Interrupt Delay, bit 14 */
        byte IDELAY15    :1;                                       /* Interrupt Delay, bit 15 */
      } Bits;
    } PDBIDLYHSTR;
    #define PDBIDLYH                    _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Byte
    #define PDBIDLYH_IDELAY8            _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY8
    #define PDBIDLYH_IDELAY9            _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY9
    #define PDBIDLYH_IDELAY10           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY10
    #define PDBIDLYH_IDELAY11           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY11
    #define PDBIDLYH_IDELAY12           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY12
    #define PDBIDLYH_IDELAY13           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY13
    #define PDBIDLYH_IDELAY14           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY14
    #define PDBIDLYH_IDELAY15           _PDBIDLY.Overlap_STR.PDBIDLYHSTR.Bits.IDELAY15
    
    #define PDBIDLYH_IDELAY8_MASK       1U
    #define PDBIDLYH_IDELAY9_MASK       2U
    #define PDBIDLYH_IDELAY10_MASK      4U
    #define PDBIDLYH_IDELAY11_MASK      8U
    #define PDBIDLYH_IDELAY12_MASK      16U
    #define PDBIDLYH_IDELAY13_MASK      32U
    #define PDBIDLYH_IDELAY14_MASK      64U
    #define PDBIDLYH_IDELAY15_MASK      128U
    

    /*** PDBIDLYL - PDB Interrupt Delay Register Low; 0x000018C9 ***/
    union {
      byte Byte;
      struct {
        byte IDELAY0     :1;                                       /* Interrupt Delay, bit 0 */
        byte IDELAY1     :1;                                       /* Interrupt Delay, bit 1 */
        byte IDELAY2     :1;                                       /* Interrupt Delay, bit 2 */
        byte IDELAY3     :1;                                       /* Interrupt Delay, bit 3 */
        byte IDELAY4     :1;                                       /* Interrupt Delay, bit 4 */
        byte IDELAY5     :1;                                       /* Interrupt Delay, bit 5 */
        byte IDELAY6     :1;                                       /* Interrupt Delay, bit 6 */
        byte IDELAY7     :1;                                       /* Interrupt Delay, bit 7 */
      } Bits;
    } PDBIDLYLSTR;
    #define PDBIDLYL                    _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Byte
    #define PDBIDLYL_IDELAY0            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY0
    #define PDBIDLYL_IDELAY1            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY1
    #define PDBIDLYL_IDELAY2            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY2
    #define PDBIDLYL_IDELAY3            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY3
    #define PDBIDLYL_IDELAY4            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY4
    #define PDBIDLYL_IDELAY5            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY5
    #define PDBIDLYL_IDELAY6            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY6
    #define PDBIDLYL_IDELAY7            _PDBIDLY.Overlap_STR.PDBIDLYLSTR.Bits.IDELAY7
    
    #define PDBIDLYL_IDELAY0_MASK       1U
    #define PDBIDLYL_IDELAY1_MASK       2U
    #define PDBIDLYL_IDELAY2_MASK       4U
    #define PDBIDLYL_IDELAY3_MASK       8U
    #define PDBIDLYL_IDELAY4_MASK       16U
    #define PDBIDLYL_IDELAY5_MASK       32U
    #define PDBIDLYL_IDELAY6_MASK       64U
    #define PDBIDLYL_IDELAY7_MASK       128U
    
  } Overlap_STR;

} PDBIDLYSTR;
extern volatile PDBIDLYSTR _PDBIDLY @0x000018C8;
#define PDBIDLY                         _PDBIDLY.Word


/*** DACINT - DAC Trigger Interval Register; 0x000018CA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DACINTH - DAC Trigger Interval Register High; 0x000018CA ***/
    union {
      byte Byte;
      struct {
        byte DACINT8     :1;                                       /* DAC Interval, bit 8 */
        byte DACINT9     :1;                                       /* DAC Interval, bit 9 */
        byte DACINT10    :1;                                       /* DAC Interval, bit 10 */
        byte DACINT11    :1;                                       /* DAC Interval, bit 11 */
        byte DACINT12    :1;                                       /* DAC Interval, bit 12 */
        byte DACINT13    :1;                                       /* DAC Interval, bit 13 */
        byte DACINT14    :1;                                       /* DAC Interval, bit 14 */
        byte DACINT15    :1;                                       /* DAC Interval, bit 15 */
      } Bits;
    } DACINTHSTR;
    #define DACINTH                     _DACINT.Overlap_STR.DACINTHSTR.Byte
    #define DACINTH_DACINT8             _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT8
    #define DACINTH_DACINT9             _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT9
    #define DACINTH_DACINT10            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT10
    #define DACINTH_DACINT11            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT11
    #define DACINTH_DACINT12            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT12
    #define DACINTH_DACINT13            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT13
    #define DACINTH_DACINT14            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT14
    #define DACINTH_DACINT15            _DACINT.Overlap_STR.DACINTHSTR.Bits.DACINT15
    
    #define DACINTH_DACINT8_MASK        1U
    #define DACINTH_DACINT9_MASK        2U
    #define DACINTH_DACINT10_MASK       4U
    #define DACINTH_DACINT11_MASK       8U
    #define DACINTH_DACINT12_MASK       16U
    #define DACINTH_DACINT13_MASK       32U
    #define DACINTH_DACINT14_MASK       64U
    #define DACINTH_DACINT15_MASK       128U
    

    /*** DACINTL - DAC Trigger Interval Register Low; 0x000018CB ***/
    union {
      byte Byte;
      struct {
        byte DACINT0     :1;                                       /* DAC Interval, bit 0 */
        byte DACINT1     :1;                                       /* DAC Interval, bit 1 */
        byte DACINT2     :1;                                       /* DAC Interval, bit 2 */
        byte DACINT3     :1;                                       /* DAC Interval, bit 3 */
        byte DACINT4     :1;                                       /* DAC Interval, bit 4 */
        byte DACINT5     :1;                                       /* DAC Interval, bit 5 */
        byte DACINT6     :1;                                       /* DAC Interval, bit 6 */
        byte DACINT7     :1;                                       /* DAC Interval, bit 7 */
      } Bits;
    } DACINTLSTR;
    #define DACINTL                     _DACINT.Overlap_STR.DACINTLSTR.Byte
    #define DACINTL_DACINT0             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT0
    #define DACINTL_DACINT1             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT1
    #define DACINTL_DACINT2             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT2
    #define DACINTL_DACINT3             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT3
    #define DACINTL_DACINT4             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT4
    #define DACINTL_DACINT5             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT5
    #define DACINTL_DACINT6             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT6
    #define DACINTL_DACINT7             _DACINT.Overlap_STR.DACINTLSTR.Bits.DACINT7
    
    #define DACINTL_DACINT0_MASK        1U
    #define DACINTL_DACINT1_MASK        2U
    #define DACINTL_DACINT2_MASK        4U
    #define DACINTL_DACINT3_MASK        8U
    #define DACINTL_DACINT4_MASK        16U
    #define DACINTL_DACINT5_MASK        32U
    #define DACINTL_DACINT6_MASK        64U
    #define DACINTL_DACINT7_MASK        128U
    
  } Overlap_STR;

} DACINTSTR;
extern volatile DACINTSTR _DACINT @0x000018CA;
#define DACINT                          _DACINT.Word


/*** PDBDLYA - PDB Delay A Register; 0x000018CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYAH - PDB Delay A Register High; 0x000018CC ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYAHSTR;
    #define PDBDLYAH                    _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Byte
    #define PDBDLYAH_DELAY8             _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY8
    #define PDBDLYAH_DELAY9             _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY9
    #define PDBDLYAH_DELAY10            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY10
    #define PDBDLYAH_DELAY11            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY11
    #define PDBDLYAH_DELAY12            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY12
    #define PDBDLYAH_DELAY13            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY13
    #define PDBDLYAH_DELAY14            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY14
    #define PDBDLYAH_DELAY15            _PDBDLYA.Overlap_STR.PDBDLYAHSTR.Bits.DELAY15
    
    #define PDBDLYAH_DELAY8_MASK        1U
    #define PDBDLYAH_DELAY9_MASK        2U
    #define PDBDLYAH_DELAY10_MASK       4U
    #define PDBDLYAH_DELAY11_MASK       8U
    #define PDBDLYAH_DELAY12_MASK       16U
    #define PDBDLYAH_DELAY13_MASK       32U
    #define PDBDLYAH_DELAY14_MASK       64U
    #define PDBDLYAH_DELAY15_MASK       128U
    

    /*** PDBDLYAL - PDB Delay A Register Low; 0x000018CD ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYALSTR;
    #define PDBDLYAL                    _PDBDLYA.Overlap_STR.PDBDLYALSTR.Byte
    #define PDBDLYAL_DELAY0             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY0
    #define PDBDLYAL_DELAY1             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY1
    #define PDBDLYAL_DELAY2             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY2
    #define PDBDLYAL_DELAY3             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY3
    #define PDBDLYAL_DELAY4             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY4
    #define PDBDLYAL_DELAY5             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY5
    #define PDBDLYAL_DELAY6             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY6
    #define PDBDLYAL_DELAY7             _PDBDLYA.Overlap_STR.PDBDLYALSTR.Bits.DELAY7
    
    #define PDBDLYAL_DELAY0_MASK        1U
    #define PDBDLYAL_DELAY1_MASK        2U
    #define PDBDLYAL_DELAY2_MASK        4U
    #define PDBDLYAL_DELAY3_MASK        8U
    #define PDBDLYAL_DELAY4_MASK        16U
    #define PDBDLYAL_DELAY5_MASK        32U
    #define PDBDLYAL_DELAY6_MASK        64U
    #define PDBDLYAL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYASTR;
extern volatile PDBDLYASTR _PDBDLYA @0x000018CC;
#define PDBDLYA                         _PDBDLYA.Word


/*** PDBDLYB - PDB Delay B Register; 0x000018CE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYBH - PDB Delay B Register High; 0x000018CE ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYBHSTR;
    #define PDBDLYBH                    _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Byte
    #define PDBDLYBH_DELAY8             _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY8
    #define PDBDLYBH_DELAY9             _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY9
    #define PDBDLYBH_DELAY10            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY10
    #define PDBDLYBH_DELAY11            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY11
    #define PDBDLYBH_DELAY12            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY12
    #define PDBDLYBH_DELAY13            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY13
    #define PDBDLYBH_DELAY14            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY14
    #define PDBDLYBH_DELAY15            _PDBDLYB.Overlap_STR.PDBDLYBHSTR.Bits.DELAY15
    
    #define PDBDLYBH_DELAY8_MASK        1U
    #define PDBDLYBH_DELAY9_MASK        2U
    #define PDBDLYBH_DELAY10_MASK       4U
    #define PDBDLYBH_DELAY11_MASK       8U
    #define PDBDLYBH_DELAY12_MASK       16U
    #define PDBDLYBH_DELAY13_MASK       32U
    #define PDBDLYBH_DELAY14_MASK       64U
    #define PDBDLYBH_DELAY15_MASK       128U
    

    /*** PDBDLYBL - PDB Delay B Register Low; 0x000018CF ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYBLSTR;
    #define PDBDLYBL                    _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Byte
    #define PDBDLYBL_DELAY0             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY0
    #define PDBDLYBL_DELAY1             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY1
    #define PDBDLYBL_DELAY2             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY2
    #define PDBDLYBL_DELAY3             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY3
    #define PDBDLYBL_DELAY4             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY4
    #define PDBDLYBL_DELAY5             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY5
    #define PDBDLYBL_DELAY6             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY6
    #define PDBDLYBL_DELAY7             _PDBDLYB.Overlap_STR.PDBDLYBLSTR.Bits.DELAY7
    
    #define PDBDLYBL_DELAY0_MASK        1U
    #define PDBDLYBL_DELAY1_MASK        2U
    #define PDBDLYBL_DELAY2_MASK        4U
    #define PDBDLYBL_DELAY3_MASK        8U
    #define PDBDLYBL_DELAY4_MASK        16U
    #define PDBDLYBL_DELAY5_MASK        32U
    #define PDBDLYBL_DELAY6_MASK        64U
    #define PDBDLYBL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYBSTR;
extern volatile PDBDLYBSTR _PDBDLYB @0x000018CE;
#define PDBDLYB                         _PDBDLYB.Word


/*** PDBDLYC - PDB Delay C Register; 0x000018D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYCH - PDB Delay C Register High; 0x000018D0 ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYCHSTR;
    #define PDBDLYCH                    _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Byte
    #define PDBDLYCH_DELAY8             _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY8
    #define PDBDLYCH_DELAY9             _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY9
    #define PDBDLYCH_DELAY10            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY10
    #define PDBDLYCH_DELAY11            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY11
    #define PDBDLYCH_DELAY12            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY12
    #define PDBDLYCH_DELAY13            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY13
    #define PDBDLYCH_DELAY14            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY14
    #define PDBDLYCH_DELAY15            _PDBDLYC.Overlap_STR.PDBDLYCHSTR.Bits.DELAY15
    
    #define PDBDLYCH_DELAY8_MASK        1U
    #define PDBDLYCH_DELAY9_MASK        2U
    #define PDBDLYCH_DELAY10_MASK       4U
    #define PDBDLYCH_DELAY11_MASK       8U
    #define PDBDLYCH_DELAY12_MASK       16U
    #define PDBDLYCH_DELAY13_MASK       32U
    #define PDBDLYCH_DELAY14_MASK       64U
    #define PDBDLYCH_DELAY15_MASK       128U
    

    /*** PDBDLYCL - PDB Delay C Register Low; 0x000018D1 ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYCLSTR;
    #define PDBDLYCL                    _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Byte
    #define PDBDLYCL_DELAY0             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY0
    #define PDBDLYCL_DELAY1             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY1
    #define PDBDLYCL_DELAY2             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY2
    #define PDBDLYCL_DELAY3             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY3
    #define PDBDLYCL_DELAY4             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY4
    #define PDBDLYCL_DELAY5             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY5
    #define PDBDLYCL_DELAY6             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY6
    #define PDBDLYCL_DELAY7             _PDBDLYC.Overlap_STR.PDBDLYCLSTR.Bits.DELAY7
    
    #define PDBDLYCL_DELAY0_MASK        1U
    #define PDBDLYCL_DELAY1_MASK        2U
    #define PDBDLYCL_DELAY2_MASK        4U
    #define PDBDLYCL_DELAY3_MASK        8U
    #define PDBDLYCL_DELAY4_MASK        16U
    #define PDBDLYCL_DELAY5_MASK        32U
    #define PDBDLYCL_DELAY6_MASK        64U
    #define PDBDLYCL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYCSTR;
extern volatile PDBDLYCSTR _PDBDLYC @0x000018D0;
#define PDBDLYC                         _PDBDLYC.Word


/*** PDBDLYD - PDB Delay D Register; 0x000018D2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYDH - PDB Delay D Register High; 0x000018D2 ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYDHSTR;
    #define PDBDLYDH                    _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Byte
    #define PDBDLYDH_DELAY8             _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY8
    #define PDBDLYDH_DELAY9             _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY9
    #define PDBDLYDH_DELAY10            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY10
    #define PDBDLYDH_DELAY11            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY11
    #define PDBDLYDH_DELAY12            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY12
    #define PDBDLYDH_DELAY13            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY13
    #define PDBDLYDH_DELAY14            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY14
    #define PDBDLYDH_DELAY15            _PDBDLYD.Overlap_STR.PDBDLYDHSTR.Bits.DELAY15
    
    #define PDBDLYDH_DELAY8_MASK        1U
    #define PDBDLYDH_DELAY9_MASK        2U
    #define PDBDLYDH_DELAY10_MASK       4U
    #define PDBDLYDH_DELAY11_MASK       8U
    #define PDBDLYDH_DELAY12_MASK       16U
    #define PDBDLYDH_DELAY13_MASK       32U
    #define PDBDLYDH_DELAY14_MASK       64U
    #define PDBDLYDH_DELAY15_MASK       128U
    

    /*** PDBDLYDL - PDB Delay D Register Low; 0x000018D3 ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYDLSTR;
    #define PDBDLYDL                    _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Byte
    #define PDBDLYDL_DELAY0             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY0
    #define PDBDLYDL_DELAY1             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY1
    #define PDBDLYDL_DELAY2             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY2
    #define PDBDLYDL_DELAY3             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY3
    #define PDBDLYDL_DELAY4             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY4
    #define PDBDLYDL_DELAY5             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY5
    #define PDBDLYDL_DELAY6             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY6
    #define PDBDLYDL_DELAY7             _PDBDLYD.Overlap_STR.PDBDLYDLSTR.Bits.DELAY7
    
    #define PDBDLYDL_DELAY0_MASK        1U
    #define PDBDLYDL_DELAY1_MASK        2U
    #define PDBDLYDL_DELAY2_MASK        4U
    #define PDBDLYDL_DELAY3_MASK        8U
    #define PDBDLYDL_DELAY4_MASK        16U
    #define PDBDLYDL_DELAY5_MASK        32U
    #define PDBDLYDL_DELAY6_MASK        64U
    #define PDBDLYDL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYDSTR;
extern volatile PDBDLYDSTR _PDBDLYD @0x000018D2;
#define PDBDLYD                         _PDBDLYD.Word


/*** PDBDLYE - PDB Delay E Register; 0x000018D4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYEH - PDB Delay E Register High; 0x000018D4 ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYEHSTR;
    #define PDBDLYEH                    _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Byte
    #define PDBDLYEH_DELAY8             _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY8
    #define PDBDLYEH_DELAY9             _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY9
    #define PDBDLYEH_DELAY10            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY10
    #define PDBDLYEH_DELAY11            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY11
    #define PDBDLYEH_DELAY12            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY12
    #define PDBDLYEH_DELAY13            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY13
    #define PDBDLYEH_DELAY14            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY14
    #define PDBDLYEH_DELAY15            _PDBDLYE.Overlap_STR.PDBDLYEHSTR.Bits.DELAY15
    
    #define PDBDLYEH_DELAY8_MASK        1U
    #define PDBDLYEH_DELAY9_MASK        2U
    #define PDBDLYEH_DELAY10_MASK       4U
    #define PDBDLYEH_DELAY11_MASK       8U
    #define PDBDLYEH_DELAY12_MASK       16U
    #define PDBDLYEH_DELAY13_MASK       32U
    #define PDBDLYEH_DELAY14_MASK       64U
    #define PDBDLYEH_DELAY15_MASK       128U
    

    /*** PDBDLYEL - PDB Delay E Register Low; 0x000018D5 ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYELSTR;
    #define PDBDLYEL                    _PDBDLYE.Overlap_STR.PDBDLYELSTR.Byte
    #define PDBDLYEL_DELAY0             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY0
    #define PDBDLYEL_DELAY1             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY1
    #define PDBDLYEL_DELAY2             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY2
    #define PDBDLYEL_DELAY3             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY3
    #define PDBDLYEL_DELAY4             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY4
    #define PDBDLYEL_DELAY5             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY5
    #define PDBDLYEL_DELAY6             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY6
    #define PDBDLYEL_DELAY7             _PDBDLYE.Overlap_STR.PDBDLYELSTR.Bits.DELAY7
    
    #define PDBDLYEL_DELAY0_MASK        1U
    #define PDBDLYEL_DELAY1_MASK        2U
    #define PDBDLYEL_DELAY2_MASK        4U
    #define PDBDLYEL_DELAY3_MASK        8U
    #define PDBDLYEL_DELAY4_MASK        16U
    #define PDBDLYEL_DELAY5_MASK        32U
    #define PDBDLYEL_DELAY6_MASK        64U
    #define PDBDLYEL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYESTR;
extern volatile PDBDLYESTR _PDBDLYE @0x000018D4;
#define PDBDLYE                         _PDBDLYE.Word


/*** PDBDLYF - PDB Delay F Register; 0x000018D6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYFH - PDB Delay F Register High; 0x000018D6 ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYFHSTR;
    #define PDBDLYFH                    _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Byte
    #define PDBDLYFH_DELAY8             _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY8
    #define PDBDLYFH_DELAY9             _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY9
    #define PDBDLYFH_DELAY10            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY10
    #define PDBDLYFH_DELAY11            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY11
    #define PDBDLYFH_DELAY12            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY12
    #define PDBDLYFH_DELAY13            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY13
    #define PDBDLYFH_DELAY14            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY14
    #define PDBDLYFH_DELAY15            _PDBDLYF.Overlap_STR.PDBDLYFHSTR.Bits.DELAY15
    
    #define PDBDLYFH_DELAY8_MASK        1U
    #define PDBDLYFH_DELAY9_MASK        2U
    #define PDBDLYFH_DELAY10_MASK       4U
    #define PDBDLYFH_DELAY11_MASK       8U
    #define PDBDLYFH_DELAY12_MASK       16U
    #define PDBDLYFH_DELAY13_MASK       32U
    #define PDBDLYFH_DELAY14_MASK       64U
    #define PDBDLYFH_DELAY15_MASK       128U
    

    /*** PDBDLYFL - PDB Delay F Register Low; 0x000018D7 ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYFLSTR;
    #define PDBDLYFL                    _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Byte
    #define PDBDLYFL_DELAY0             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY0
    #define PDBDLYFL_DELAY1             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY1
    #define PDBDLYFL_DELAY2             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY2
    #define PDBDLYFL_DELAY3             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY3
    #define PDBDLYFL_DELAY4             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY4
    #define PDBDLYFL_DELAY5             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY5
    #define PDBDLYFL_DELAY6             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY6
    #define PDBDLYFL_DELAY7             _PDBDLYF.Overlap_STR.PDBDLYFLSTR.Bits.DELAY7
    
    #define PDBDLYFL_DELAY0_MASK        1U
    #define PDBDLYFL_DELAY1_MASK        2U
    #define PDBDLYFL_DELAY2_MASK        4U
    #define PDBDLYFL_DELAY3_MASK        8U
    #define PDBDLYFL_DELAY4_MASK        16U
    #define PDBDLYFL_DELAY5_MASK        32U
    #define PDBDLYFL_DELAY6_MASK        64U
    #define PDBDLYFL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYFSTR;
extern volatile PDBDLYFSTR _PDBDLYF @0x000018D6;
#define PDBDLYF                         _PDBDLYF.Word


/*** PDBDLYG - PDB Delay G Register; 0x000018D8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYGH - PDB Delay G Register High; 0x000018D8 ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYGHSTR;
    #define PDBDLYGH                    _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Byte
    #define PDBDLYGH_DELAY8             _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY8
    #define PDBDLYGH_DELAY9             _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY9
    #define PDBDLYGH_DELAY10            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY10
    #define PDBDLYGH_DELAY11            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY11
    #define PDBDLYGH_DELAY12            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY12
    #define PDBDLYGH_DELAY13            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY13
    #define PDBDLYGH_DELAY14            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY14
    #define PDBDLYGH_DELAY15            _PDBDLYG.Overlap_STR.PDBDLYGHSTR.Bits.DELAY15
    
    #define PDBDLYGH_DELAY8_MASK        1U
    #define PDBDLYGH_DELAY9_MASK        2U
    #define PDBDLYGH_DELAY10_MASK       4U
    #define PDBDLYGH_DELAY11_MASK       8U
    #define PDBDLYGH_DELAY12_MASK       16U
    #define PDBDLYGH_DELAY13_MASK       32U
    #define PDBDLYGH_DELAY14_MASK       64U
    #define PDBDLYGH_DELAY15_MASK       128U
    

    /*** PDBDLYGL - PDB Delay G Register Low; 0x000018D9 ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYGLSTR;
    #define PDBDLYGL                    _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Byte
    #define PDBDLYGL_DELAY0             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY0
    #define PDBDLYGL_DELAY1             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY1
    #define PDBDLYGL_DELAY2             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY2
    #define PDBDLYGL_DELAY3             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY3
    #define PDBDLYGL_DELAY4             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY4
    #define PDBDLYGL_DELAY5             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY5
    #define PDBDLYGL_DELAY6             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY6
    #define PDBDLYGL_DELAY7             _PDBDLYG.Overlap_STR.PDBDLYGLSTR.Bits.DELAY7
    
    #define PDBDLYGL_DELAY0_MASK        1U
    #define PDBDLYGL_DELAY1_MASK        2U
    #define PDBDLYGL_DELAY2_MASK        4U
    #define PDBDLYGL_DELAY3_MASK        8U
    #define PDBDLYGL_DELAY4_MASK        16U
    #define PDBDLYGL_DELAY5_MASK        32U
    #define PDBDLYGL_DELAY6_MASK        64U
    #define PDBDLYGL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYGSTR;
extern volatile PDBDLYGSTR _PDBDLYG @0x000018D8;
#define PDBDLYG                         _PDBDLYG.Word


/*** PDBDLYH - PDB Delay H Register; 0x000018DA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDBDLYHH - PDB Delay H Register High; 0x000018DA ***/
    union {
      byte Byte;
      struct {
        byte DELAY8      :1;                                       /* Delay, bit 8 */
        byte DELAY9      :1;                                       /* Delay, bit 9 */
        byte DELAY10     :1;                                       /* Delay, bit 10 */
        byte DELAY11     :1;                                       /* Delay, bit 11 */
        byte DELAY12     :1;                                       /* Delay, bit 12 */
        byte DELAY13     :1;                                       /* Delay, bit 13 */
        byte DELAY14     :1;                                       /* Delay, bit 14 */
        byte DELAY15     :1;                                       /* Delay, bit 15 */
      } Bits;
    } PDBDLYHHSTR;
    #define PDBDLYHH                    _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Byte
    #define PDBDLYHH_DELAY8             _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY8
    #define PDBDLYHH_DELAY9             _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY9
    #define PDBDLYHH_DELAY10            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY10
    #define PDBDLYHH_DELAY11            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY11
    #define PDBDLYHH_DELAY12            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY12
    #define PDBDLYHH_DELAY13            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY13
    #define PDBDLYHH_DELAY14            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY14
    #define PDBDLYHH_DELAY15            _PDBDLYH.Overlap_STR.PDBDLYHHSTR.Bits.DELAY15
    
    #define PDBDLYHH_DELAY8_MASK        1U
    #define PDBDLYHH_DELAY9_MASK        2U
    #define PDBDLYHH_DELAY10_MASK       4U
    #define PDBDLYHH_DELAY11_MASK       8U
    #define PDBDLYHH_DELAY12_MASK       16U
    #define PDBDLYHH_DELAY13_MASK       32U
    #define PDBDLYHH_DELAY14_MASK       64U
    #define PDBDLYHH_DELAY15_MASK       128U
    

    /*** PDBDLYHL - PDB Delay H Register Low; 0x000018DB ***/
    union {
      byte Byte;
      struct {
        byte DELAY0      :1;                                       /* Delay, bit 0 */
        byte DELAY1      :1;                                       /* Delay, bit 1 */
        byte DELAY2      :1;                                       /* Delay, bit 2 */
        byte DELAY3      :1;                                       /* Delay, bit 3 */
        byte DELAY4      :1;                                       /* Delay, bit 4 */
        byte DELAY5      :1;                                       /* Delay, bit 5 */
        byte DELAY6      :1;                                       /* Delay, bit 6 */
        byte DELAY7      :1;                                       /* Delay, bit 7 */
      } Bits;
    } PDBDLYHLSTR;
    #define PDBDLYHL                    _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Byte
    #define PDBDLYHL_DELAY0             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY0
    #define PDBDLYHL_DELAY1             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY1
    #define PDBDLYHL_DELAY2             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY2
    #define PDBDLYHL_DELAY3             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY3
    #define PDBDLYHL_DELAY4             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY4
    #define PDBDLYHL_DELAY5             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY5
    #define PDBDLYHL_DELAY6             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY6
    #define PDBDLYHL_DELAY7             _PDBDLYH.Overlap_STR.PDBDLYHLSTR.Bits.DELAY7
    
    #define PDBDLYHL_DELAY0_MASK        1U
    #define PDBDLYHL_DELAY1_MASK        2U
    #define PDBDLYHL_DELAY2_MASK        4U
    #define PDBDLYHL_DELAY3_MASK        8U
    #define PDBDLYHL_DELAY4_MASK        16U
    #define PDBDLYHL_DELAY5_MASK        32U
    #define PDBDLYHL_DELAY6_MASK        64U
    #define PDBDLYHL_DELAY7_MASK        128U
    
  } Overlap_STR;

} PDBDLYHSTR;
extern volatile PDBDLYHSTR _PDBDLYH @0x000018DA;
#define PDBDLYH                         _PDBDLYH.Word


/*** TPM1SC - TPM1 Status and Control Register; 0x000018E0 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x000018E0;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1U
#define TPM1SC_PS1_MASK                 2U
#define TPM1SC_PS2_MASK                 4U
#define TPM1SC_CLKSA_MASK               8U
#define TPM1SC_CLKSB_MASK               16U
#define TPM1SC_CPWMS_MASK               32U
#define TPM1SC_TOIE_MASK                64U
#define TPM1SC_TOF_MASK                 128U
#define TPM1SC_PS_MASK                  7U
#define TPM1SC_PS_BITNUM                0U
#define TPM1SC_CLKSx_MASK               24U
#define TPM1SC_CLKSx_BITNUM             3U


/*** TPM1CNT - TPM1 Timer Counter Register; 0x000018E1 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0x000018E1 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x000018E2 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x000018E1;
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x000018E3 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x000018E3 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x000018E4 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x000018E3;
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x000018E5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x000018E5;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4U
#define TPM1C0SC_ELS0B_MASK             8U
#define TPM1C0SC_MS0A_MASK              16U
#define TPM1C0SC_MS0B_MASK              32U
#define TPM1C0SC_CH0IE_MASK             64U
#define TPM1C0SC_CH0F_MASK              128U
#define TPM1C0SC_ELS0x_MASK             12U
#define TPM1C0SC_ELS0x_BITNUM           2U
#define TPM1C0SC_MS0x_MASK              48U
#define TPM1C0SC_MS0x_BITNUM            4U


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x000018E6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x000018E6 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x000018E7 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x000018E6;
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x000018E8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
extern volatile TPM1C1SCSTR _TPM1C1SC @0x000018E8;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4U
#define TPM1C1SC_ELS1B_MASK             8U
#define TPM1C1SC_MS1A_MASK              16U
#define TPM1C1SC_MS1B_MASK              32U
#define TPM1C1SC_CH1IE_MASK             64U
#define TPM1C1SC_CH1F_MASK              128U
#define TPM1C1SC_ELS1x_MASK             12U
#define TPM1C1SC_ELS1x_BITNUM           2U
#define TPM1C1SC_MS1x_MASK              48U
#define TPM1C1SC_MS1x_BITNUM            4U


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x000018E9 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x000018E9 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x000018EA ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
extern volatile TPM1C1VSTR _TPM1C1V @0x000018E9;
#define TPM1C1V                         _TPM1C1V.Word


/*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0x000018EB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for TPM Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for TPM Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C2SCSTR;
extern volatile TPM1C2SCSTR _TPM1C2SC @0x000018EB;
#define TPM1C2SC                        _TPM1C2SC.Byte
#define TPM1C2SC_ELS2A                  _TPM1C2SC.Bits.ELS2A
#define TPM1C2SC_ELS2B                  _TPM1C2SC.Bits.ELS2B
#define TPM1C2SC_MS2A                   _TPM1C2SC.Bits.MS2A
#define TPM1C2SC_MS2B                   _TPM1C2SC.Bits.MS2B
#define TPM1C2SC_CH2IE                  _TPM1C2SC.Bits.CH2IE
#define TPM1C2SC_CH2F                   _TPM1C2SC.Bits.CH2F
#define TPM1C2SC_ELS2x                  _TPM1C2SC.MergedBits.grpELS2x
#define TPM1C2SC_MS2x                   _TPM1C2SC.MergedBits.grpMS2x

#define TPM1C2SC_ELS2A_MASK             4U
#define TPM1C2SC_ELS2B_MASK             8U
#define TPM1C2SC_MS2A_MASK              16U
#define TPM1C2SC_MS2B_MASK              32U
#define TPM1C2SC_CH2IE_MASK             64U
#define TPM1C2SC_CH2F_MASK              128U
#define TPM1C2SC_ELS2x_MASK             12U
#define TPM1C2SC_ELS2x_BITNUM           2U
#define TPM1C2SC_MS2x_MASK              48U
#define TPM1C2SC_MS2x_BITNUM            4U


/*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0x000018EC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0x000018EC ***/
    union {
      byte Byte;
    } TPM1C2VHSTR;
    #define TPM1C2VH                    _TPM1C2V.Overlap_STR.TPM1C2VHSTR.Byte
    

    /*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0x000018ED ***/
    union {
      byte Byte;
    } TPM1C2VLSTR;
    #define TPM1C2VL                    _TPM1C2V.Overlap_STR.TPM1C2VLSTR.Byte
    
  } Overlap_STR;

} TPM1C2VSTR;
extern volatile TPM1C2VSTR _TPM1C2V @0x000018EC;
#define TPM1C2V                         _TPM1C2V.Word


/*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register; 0x000018EE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for TPM Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for TPM Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C3SCSTR;
extern volatile TPM1C3SCSTR _TPM1C3SC @0x000018EE;
#define TPM1C3SC                        _TPM1C3SC.Byte
#define TPM1C3SC_ELS3A                  _TPM1C3SC.Bits.ELS3A
#define TPM1C3SC_ELS3B                  _TPM1C3SC.Bits.ELS3B
#define TPM1C3SC_MS3A                   _TPM1C3SC.Bits.MS3A
#define TPM1C3SC_MS3B                   _TPM1C3SC.Bits.MS3B
#define TPM1C3SC_CH3IE                  _TPM1C3SC.Bits.CH3IE
#define TPM1C3SC_CH3F                   _TPM1C3SC.Bits.CH3F
#define TPM1C3SC_ELS3x                  _TPM1C3SC.MergedBits.grpELS3x
#define TPM1C3SC_MS3x                   _TPM1C3SC.MergedBits.grpMS3x

#define TPM1C3SC_ELS3A_MASK             4U
#define TPM1C3SC_ELS3B_MASK             8U
#define TPM1C3SC_MS3A_MASK              16U
#define TPM1C3SC_MS3B_MASK              32U
#define TPM1C3SC_CH3IE_MASK             64U
#define TPM1C3SC_CH3F_MASK              128U
#define TPM1C3SC_ELS3x_MASK             12U
#define TPM1C3SC_ELS3x_BITNUM           2U
#define TPM1C3SC_MS3x_MASK              48U
#define TPM1C3SC_MS3x_BITNUM            4U


/*** TPM1C3V - TPM1 Timer Channel 3 Value Register; 0x000018EF ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High; 0x000018EF ***/
    union {
      byte Byte;
    } TPM1C3VHSTR;
    #define TPM1C3VH                    _TPM1C3V.Overlap_STR.TPM1C3VHSTR.Byte
    

    /*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low; 0x000018F0 ***/
    union {
      byte Byte;
    } TPM1C3VLSTR;
    #define TPM1C3VL                    _TPM1C3V.Overlap_STR.TPM1C3VLSTR.Byte
    
  } Overlap_STR;

} TPM1C3VSTR;
extern volatile TPM1C3VSTR _TPM1C3V @0x000018EF;
#define TPM1C3V                         _TPM1C3V.Word


/*** ADCCV1 - Compare Value 1 Register; 0x000018F8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCV1H - Compare Value 1 High Register; 0x000018F8 ***/
    union {
      byte Byte;
      struct {
        byte CV18        :1;                                       /* Compare Function Value 8 */
        byte CV19        :1;                                       /* Compare Function Value 9 */
        byte CV110       :1;                                       /* Compare Function Value 10 */
        byte CV111       :1;                                       /* Compare Function Value 11 */
        byte CV112       :1;                                       /* Compare Function Value 12 */
        byte CV113       :1;                                       /* Compare Function Value 13 */
        byte CV114       :1;                                       /* Compare Function Value 14 */
        byte CV115       :1;                                       /* Compare Function Value 15 */
      } Bits;
      struct {
        byte grpCV_18 :2;
        byte grpCV1_10 :6;
      } MergedBits;
    } ADCCV1HSTR;
    #define ADCCV1H                     _ADCCV1.Overlap_STR.ADCCV1HSTR.Byte
    #define ADCCV1H_CV18                _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV18
    #define ADCCV1H_CV19                _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV19
    #define ADCCV1H_CV110               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV110
    #define ADCCV1H_CV111               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV111
    #define ADCCV1H_CV112               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV112
    #define ADCCV1H_CV113               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV113
    #define ADCCV1H_CV114               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV114
    #define ADCCV1H_CV115               _ADCCV1.Overlap_STR.ADCCV1HSTR.Bits.CV115
    #define ADCCV1H_CV_18               _ADCCV1.Overlap_STR.ADCCV1HSTR.MergedBits.grpCV_18
    #define ADCCV1H_CV1_10              _ADCCV1.Overlap_STR.ADCCV1HSTR.MergedBits.grpCV1_10
    #define ADCCV1H_CV                  ADCCV1H_CV_18
    #define ADCCV1H_CV1                 ADCCV1H_CV1_10
    
    #define ADCCV1H_CV18_MASK           1U
    #define ADCCV1H_CV19_MASK           2U
    #define ADCCV1H_CV110_MASK          4U
    #define ADCCV1H_CV111_MASK          8U
    #define ADCCV1H_CV112_MASK          16U
    #define ADCCV1H_CV113_MASK          32U
    #define ADCCV1H_CV114_MASK          64U
    #define ADCCV1H_CV115_MASK          128U
    #define ADCCV1H_CV_18_MASK          3U
    #define ADCCV1H_CV_18_BITNUM        0U
    #define ADCCV1H_CV1_10_MASK         252U
    #define ADCCV1H_CV1_10_BITNUM       2U
    

    /*** ADCCV1L - Compare Value 1 Low Register; 0x000018F9 ***/
    union {
      byte Byte;
      struct {
        byte CV10        :1;                                       /* Compare Function Value 0 */
        byte CV11        :1;                                       /* Compare Function Value 1 */
        byte CV12        :1;                                       /* Compare Function Value 2 */
        byte CV13        :1;                                       /* Compare Function Value 3 */
        byte CV14        :1;                                       /* Compare Function Value 4 */
        byte CV15        :1;                                       /* Compare Function Value 5 */
        byte CV16        :1;                                       /* Compare Function Value 6 */
        byte CV17        :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCV1LSTR;
    #define ADCCV1L                     _ADCCV1.Overlap_STR.ADCCV1LSTR.Byte
    #define ADCCV1L_CV10                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV10
    #define ADCCV1L_CV11                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV11
    #define ADCCV1L_CV12                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV12
    #define ADCCV1L_CV13                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV13
    #define ADCCV1L_CV14                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV14
    #define ADCCV1L_CV15                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV15
    #define ADCCV1L_CV16                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV16
    #define ADCCV1L_CV17                _ADCCV1.Overlap_STR.ADCCV1LSTR.Bits.CV17
    
    #define ADCCV1L_CV10_MASK           1U
    #define ADCCV1L_CV11_MASK           2U
    #define ADCCV1L_CV12_MASK           4U
    #define ADCCV1L_CV13_MASK           8U
    #define ADCCV1L_CV14_MASK           16U
    #define ADCCV1L_CV15_MASK           32U
    #define ADCCV1L_CV16_MASK           64U
    #define ADCCV1L_CV17_MASK           128U
    
  } Overlap_STR;

} ADCCV1STR;
extern volatile ADCCV1STR _ADCCV1 @0x000018F8;
#define ADCCV1                          _ADCCV1.Word


/*** ADCCV2 - Compare Value 2 Register; 0x000018FA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCV2H - Compare Value 2 High Register; 0x000018FA ***/
    union {
      byte Byte;
      struct {
        byte CV28        :1;                                       /* Compare Function Value 8 */
        byte CV29        :1;                                       /* Compare Function Value 9 */
        byte CV210       :1;                                       /* Compare Function Value 10 */
        byte CV211       :1;                                       /* Compare Function Value 11 */
        byte CV212       :1;                                       /* Compare Function Value 12 */
        byte CV213       :1;                                       /* Compare Function Value 13 */
        byte CV214       :1;                                       /* Compare Function Value 14 */
        byte CV215       :1;                                       /* Compare Function Value 15 */
      } Bits;
      struct {
        byte grpCV_28 :2;
        byte grpCV2_10 :6;
      } MergedBits;
    } ADCCV2HSTR;
    #define ADCCV2H                     _ADCCV2.Overlap_STR.ADCCV2HSTR.Byte
    #define ADCCV2H_CV28                _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV28
    #define ADCCV2H_CV29                _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV29
    #define ADCCV2H_CV210               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV210
    #define ADCCV2H_CV211               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV211
    #define ADCCV2H_CV212               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV212
    #define ADCCV2H_CV213               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV213
    #define ADCCV2H_CV214               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV214
    #define ADCCV2H_CV215               _ADCCV2.Overlap_STR.ADCCV2HSTR.Bits.CV215
    #define ADCCV2H_CV_28               _ADCCV2.Overlap_STR.ADCCV2HSTR.MergedBits.grpCV_28
    #define ADCCV2H_CV2_10              _ADCCV2.Overlap_STR.ADCCV2HSTR.MergedBits.grpCV2_10
    #define ADCCV2H_CV                  ADCCV2H_CV_28
    #define ADCCV2H_CV2                 ADCCV2H_CV2_10
    
    #define ADCCV2H_CV28_MASK           1U
    #define ADCCV2H_CV29_MASK           2U
    #define ADCCV2H_CV210_MASK          4U
    #define ADCCV2H_CV211_MASK          8U
    #define ADCCV2H_CV212_MASK          16U
    #define ADCCV2H_CV213_MASK          32U
    #define ADCCV2H_CV214_MASK          64U
    #define ADCCV2H_CV215_MASK          128U
    #define ADCCV2H_CV_28_MASK          3U
    #define ADCCV2H_CV_28_BITNUM        0U
    #define ADCCV2H_CV2_10_MASK         252U
    #define ADCCV2H_CV2_10_BITNUM       2U
    

    /*** ADCCV2L - Compare Value 2 Low Register; 0x000018FB ***/
    union {
      byte Byte;
      struct {
        byte CV20        :1;                                       /* Compare Function Value 0 */
        byte CV21        :1;                                       /* Compare Function Value 1 */
        byte CV22        :1;                                       /* Compare Function Value 2 */
        byte CV23        :1;                                       /* Compare Function Value 3 */
        byte CV24        :1;                                       /* Compare Function Value 4 */
        byte CV25        :1;                                       /* Compare Function Value 5 */
        byte CV26        :1;                                       /* Compare Function Value 6 */
        byte CV27        :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCV2LSTR;
    #define ADCCV2L                     _ADCCV2.Overlap_STR.ADCCV2LSTR.Byte
    #define ADCCV2L_CV20                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV20
    #define ADCCV2L_CV21                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV21
    #define ADCCV2L_CV22                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV22
    #define ADCCV2L_CV23                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV23
    #define ADCCV2L_CV24                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV24
    #define ADCCV2L_CV25                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV25
    #define ADCCV2L_CV26                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV26
    #define ADCCV2L_CV27                _ADCCV2.Overlap_STR.ADCCV2LSTR.Bits.CV27
    
    #define ADCCV2L_CV20_MASK           1U
    #define ADCCV2L_CV21_MASK           2U
    #define ADCCV2L_CV22_MASK           4U
    #define ADCCV2L_CV23_MASK           8U
    #define ADCCV2L_CV24_MASK           16U
    #define ADCCV2L_CV25_MASK           32U
    #define ADCCV2L_CV26_MASK           64U
    #define ADCCV2L_CV27_MASK           128U
    
  } Overlap_STR;

} ADCCV2STR;
extern volatile ADCCV2STR _ADCCV2 @0x000018FA;
#define ADCCV2                          _ADCCV2.Word


/*** ADCSC2 - Status and Control Register 2; 0x000018FC ***/
typedef union {
  byte Byte;
  struct {
    byte REFSEL0     :1;                                       /* Voltage Reference Selection, bit 0 */
    byte REFSEL1     :1;                                       /* Voltage Reference Selection, bit 1 */
    byte             :1; 
    byte ACREN       :1;                                       /* Compare Function Range Enable */
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
  struct {
    byte grpREFSEL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0x000018FC;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_REFSEL0                  _ADCSC2.Bits.REFSEL0
#define ADCSC2_REFSEL1                  _ADCSC2.Bits.REFSEL1
#define ADCSC2_ACREN                    _ADCSC2.Bits.ACREN
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT
#define ADCSC2_REFSEL                   _ADCSC2.MergedBits.grpREFSEL

#define ADCSC2_REFSEL0_MASK             1U
#define ADCSC2_REFSEL1_MASK             2U
#define ADCSC2_ACREN_MASK               8U
#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U
#define ADCSC2_REFSEL_MASK              3U
#define ADCSC2_REFSEL_BITNUM            0U


/*** ADCSC3 - Status and Control Register 3; 0x000018FD ***/
typedef union {
  byte Byte;
  struct {
    byte AVGS0       :1;                                       /* Hardware Average select, bit 0 */
    byte AVGS1       :1;                                       /* Hardware Average select, bit 1 */
    byte AVGE        :1;                                       /* Hardware average enable - AVGE enables the hardware average function of the ADC */
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO enables continuous conversions */
    byte             :1; 
    byte             :1; 
    byte CALF        :1;                                       /* Calibration Failed Flag - CALF displays the result of the calibration sequence */
    byte CAL         :1;                                       /* Calibration - CAL begins the calibration sequence when set */
  } Bits;
  struct {
    byte grpAVGS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC3STR;
extern volatile ADCSC3STR _ADCSC3 @0x000018FD;
#define ADCSC3                          _ADCSC3.Byte
#define ADCSC3_AVGS0                    _ADCSC3.Bits.AVGS0
#define ADCSC3_AVGS1                    _ADCSC3.Bits.AVGS1
#define ADCSC3_AVGE                     _ADCSC3.Bits.AVGE
#define ADCSC3_ADCO                     _ADCSC3.Bits.ADCO
#define ADCSC3_CALF                     _ADCSC3.Bits.CALF
#define ADCSC3_CAL                      _ADCSC3.Bits.CAL
#define ADCSC3_AVGS                     _ADCSC3.MergedBits.grpAVGS

#define ADCSC3_AVGS0_MASK               1U
#define ADCSC3_AVGS1_MASK               2U
#define ADCSC3_AVGE_MASK                4U
#define ADCSC3_ADCO_MASK                8U
#define ADCSC3_CALF_MASK                64U
#define ADCSC3_CAL_MASK                 128U
#define ADCSC3_AVGS_MASK                3U
#define ADCSC3_AVGS_BITNUM              0U


/*** ADCOFS - Offset Correction Register; 0x000018FE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCOFSH - Offset Correction High Register; 0x000018FE ***/
    union {
      byte Byte;
      struct {
        byte OFS8        :1;                                       /* Offset error correction value bit 8 */
        byte OFS9        :1;                                       /* Offset error correction value bit 9 */
        byte OFS10       :1;                                       /* Offset error correction value bit 10 */
        byte OFS11       :1;                                       /* Offset error correction value bit 11 */
        byte OFS12       :1;                                       /* Offset error correction value bit 12 */
        byte OFS13       :1;                                       /* Offset error correction value bit 13 */
        byte OFS14       :1;                                       /* Offset error correction value bit 14 */
        byte OFS15       :1;                                       /* Offset error correction value bit 15 */
      } Bits;
    } ADCOFSHSTR;
    #define ADCOFSH                     _ADCOFS.Overlap_STR.ADCOFSHSTR.Byte
    #define ADCOFSH_OFS8                _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS8
    #define ADCOFSH_OFS9                _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS9
    #define ADCOFSH_OFS10               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS10
    #define ADCOFSH_OFS11               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS11
    #define ADCOFSH_OFS12               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS12
    #define ADCOFSH_OFS13               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS13
    #define ADCOFSH_OFS14               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS14
    #define ADCOFSH_OFS15               _ADCOFS.Overlap_STR.ADCOFSHSTR.Bits.OFS15
    
    #define ADCOFSH_OFS8_MASK           1U
    #define ADCOFSH_OFS9_MASK           2U
    #define ADCOFSH_OFS10_MASK          4U
    #define ADCOFSH_OFS11_MASK          8U
    #define ADCOFSH_OFS12_MASK          16U
    #define ADCOFSH_OFS13_MASK          32U
    #define ADCOFSH_OFS14_MASK          64U
    #define ADCOFSH_OFS15_MASK          128U
    

    /*** ADCOFSL - Offset Correction Low Register; 0x000018FF ***/
    union {
      byte Byte;
      struct {
        byte OFS0        :1;                                       /* Offset error correction value bit 0 */
        byte OFS1        :1;                                       /* Offset error correction value bit 1 */
        byte OFS2        :1;                                       /* Offset error correction value bit 2 */
        byte OFS3        :1;                                       /* Offset error correction value bit 3 */
        byte OFS4        :1;                                       /* Offset error correction value bit 4 */
        byte OFS5        :1;                                       /* Offset error correction value bit 5 */
        byte OFS6        :1;                                       /* Offset error correction value bit 6 */
        byte OFS7        :1;                                       /* Offset error correction value bit 7 */
      } Bits;
    } ADCOFSLSTR;
    #define ADCOFSL                     _ADCOFS.Overlap_STR.ADCOFSLSTR.Byte
    #define ADCOFSL_OFS0                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS0
    #define ADCOFSL_OFS1                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS1
    #define ADCOFSL_OFS2                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS2
    #define ADCOFSL_OFS3                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS3
    #define ADCOFSL_OFS4                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS4
    #define ADCOFSL_OFS5                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS5
    #define ADCOFSL_OFS6                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS6
    #define ADCOFSL_OFS7                _ADCOFS.Overlap_STR.ADCOFSLSTR.Bits.OFS7
    
    #define ADCOFSL_OFS0_MASK           1U
    #define ADCOFSL_OFS1_MASK           2U
    #define ADCOFSL_OFS2_MASK           4U
    #define ADCOFSL_OFS3_MASK           8U
    #define ADCOFSL_OFS4_MASK           16U
    #define ADCOFSL_OFS5_MASK           32U
    #define ADCOFSL_OFS6_MASK           64U
    #define ADCOFSL_OFS7_MASK           128U
    
  } Overlap_STR;

} ADCOFSSTR;
extern volatile ADCOFSSTR _ADCOFS @0x000018FE;
#define ADCOFS                          _ADCOFS.Word


/*** ADCPG - Plus-Side Gain Register; 0x00001900 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCPGH - Plus-Side Gain High Register; 0x00001900 ***/
    union {
      byte Byte;
      struct {
        byte PG8         :1;                                       /* Gain error correction for the plus-side input value bit 8 */
        byte PG9         :1;                                       /* Gain error correction for the plus-side input value bit 9 */
        byte PG10        :1;                                       /* Gain error correction for the plus-side input value bit 10 */
        byte PG11        :1;                                       /* Gain error correction for the plus-side input value bit 11 */
        byte PG12        :1;                                       /* Gain error correction for the plus-side input value bit 12 */
        byte PG13        :1;                                       /* Gain error correction for the plus-side input value bit 13 */
        byte PG14        :1;                                       /* Gain error correction for the plus-side input value bit 14 */
        byte PG15        :1;                                       /* Gain error correction for the plus-side input value bit 15 */
      } Bits;
    } ADCPGHSTR;
    #define ADCPGH                      _ADCPG.Overlap_STR.ADCPGHSTR.Byte
    #define ADCPGH_PG8                  _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG8
    #define ADCPGH_PG9                  _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG9
    #define ADCPGH_PG10                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG10
    #define ADCPGH_PG11                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG11
    #define ADCPGH_PG12                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG12
    #define ADCPGH_PG13                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG13
    #define ADCPGH_PG14                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG14
    #define ADCPGH_PG15                 _ADCPG.Overlap_STR.ADCPGHSTR.Bits.PG15
    
    #define ADCPGH_PG8_MASK             1U
    #define ADCPGH_PG9_MASK             2U
    #define ADCPGH_PG10_MASK            4U
    #define ADCPGH_PG11_MASK            8U
    #define ADCPGH_PG12_MASK            16U
    #define ADCPGH_PG13_MASK            32U
    #define ADCPGH_PG14_MASK            64U
    #define ADCPGH_PG15_MASK            128U
    

    /*** ADCPGL - Plus-Side Gain Low Register; 0x00001901 ***/
    union {
      byte Byte;
      struct {
        byte PG0         :1;                                       /* Gain error correction for the plus-side input value bit 0 */
        byte PG1         :1;                                       /* Gain error correction for the plus-side input value bit 1 */
        byte PG2         :1;                                       /* Gain error correction for the plus-side input value bit 2 */
        byte PG3         :1;                                       /* Gain error correction for the plus-side input value bit 3 */
        byte PG4         :1;                                       /* Gain error correction for the plus-side input value bit 4 */
        byte PG5         :1;                                       /* Gain error correction for the plus-side input value bit 5 */
        byte PG6         :1;                                       /* Gain error correction for the plus-side input value bit 6 */
        byte PG7         :1;                                       /* Gain error correction for the plus-side input value bit 7 */
      } Bits;
    } ADCPGLSTR;
    #define ADCPGL                      _ADCPG.Overlap_STR.ADCPGLSTR.Byte
    #define ADCPGL_PG0                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG0
    #define ADCPGL_PG1                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG1
    #define ADCPGL_PG2                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG2
    #define ADCPGL_PG3                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG3
    #define ADCPGL_PG4                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG4
    #define ADCPGL_PG5                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG5
    #define ADCPGL_PG6                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG6
    #define ADCPGL_PG7                  _ADCPG.Overlap_STR.ADCPGLSTR.Bits.PG7
    
    #define ADCPGL_PG0_MASK             1U
    #define ADCPGL_PG1_MASK             2U
    #define ADCPGL_PG2_MASK             4U
    #define ADCPGL_PG3_MASK             8U
    #define ADCPGL_PG4_MASK             16U
    #define ADCPGL_PG5_MASK             32U
    #define ADCPGL_PG6_MASK             64U
    #define ADCPGL_PG7_MASK             128U
    
  } Overlap_STR;

} ADCPGSTR;
extern volatile ADCPGSTR _ADCPG @0x00001900;
#define ADCPG                           _ADCPG.Word


/*** ADCMG - Minus-Side Gain Register; 0x00001902 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCMGH - Minus-Side Gain High Register; 0x00001902 ***/
    union {
      byte Byte;
      struct {
        byte MG8         :1;                                       /* Gain error correction for the minus-side input value bit 8 */
        byte MG9         :1;                                       /* Gain error correction for the minus-side input value bit 9 */
        byte MG10        :1;                                       /* Gain error correction for the minus-side input value bit 10 */
        byte MG11        :1;                                       /* Gain error correction for the minus-side input value bit 11 */
        byte MG12        :1;                                       /* Gain error correction for the minus-side input value bit 12 */
        byte MG13        :1;                                       /* Gain error correction for the minus-side input value bit 13 */
        byte MG14        :1;                                       /* Gain error correction for the minus-side input value bit 14 */
        byte MG15        :1;                                       /* Gain error correction for the minus-side input value bit 15 */
      } Bits;
    } ADCMGHSTR;
    #define ADCMGH                      _ADCMG.Overlap_STR.ADCMGHSTR.Byte
    #define ADCMGH_MG8                  _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG8
    #define ADCMGH_MG9                  _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG9
    #define ADCMGH_MG10                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG10
    #define ADCMGH_MG11                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG11
    #define ADCMGH_MG12                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG12
    #define ADCMGH_MG13                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG13
    #define ADCMGH_MG14                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG14
    #define ADCMGH_MG15                 _ADCMG.Overlap_STR.ADCMGHSTR.Bits.MG15
    
    #define ADCMGH_MG8_MASK             1U
    #define ADCMGH_MG9_MASK             2U
    #define ADCMGH_MG10_MASK            4U
    #define ADCMGH_MG11_MASK            8U
    #define ADCMGH_MG12_MASK            16U
    #define ADCMGH_MG13_MASK            32U
    #define ADCMGH_MG14_MASK            64U
    #define ADCMGH_MG15_MASK            128U
    

    /*** ADCMGL - Minus-Side Gain Low Register; 0x00001903 ***/
    union {
      byte Byte;
      struct {
        byte MG0         :1;                                       /* Gain error correction for the minus-side input value bit 0 */
        byte MG1         :1;                                       /* Gain error correction for the minus-side input value bit 1 */
        byte MG2         :1;                                       /* Gain error correction for the minus-side input value bit 2 */
        byte MG3         :1;                                       /* Gain error correction for the minus-side input value bit 3 */
        byte MG4         :1;                                       /* Gain error correction for the minus-side input value bit 4 */
        byte MG5         :1;                                       /* Gain error correction for the minus-side input value bit 5 */
        byte MG6         :1;                                       /* Gain error correction for the minus-side input value bit 6 */
        byte MG7         :1;                                       /* Gain error correction for the minus-side input value bit 7 */
      } Bits;
    } ADCMGLSTR;
    #define ADCMGL                      _ADCMG.Overlap_STR.ADCMGLSTR.Byte
    #define ADCMGL_MG0                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG0
    #define ADCMGL_MG1                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG1
    #define ADCMGL_MG2                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG2
    #define ADCMGL_MG3                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG3
    #define ADCMGL_MG4                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG4
    #define ADCMGL_MG5                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG5
    #define ADCMGL_MG6                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG6
    #define ADCMGL_MG7                  _ADCMG.Overlap_STR.ADCMGLSTR.Bits.MG7
    
    #define ADCMGL_MG0_MASK             1U
    #define ADCMGL_MG1_MASK             2U
    #define ADCMGL_MG2_MASK             4U
    #define ADCMGL_MG3_MASK             8U
    #define ADCMGL_MG4_MASK             16U
    #define ADCMGL_MG5_MASK             32U
    #define ADCMGL_MG6_MASK             64U
    #define ADCMGL_MG7_MASK             128U
    
  } Overlap_STR;

} ADCMGSTR;
extern volatile ADCMGSTR _ADCMG @0x00001902;
#define ADCMG                           _ADCMG.Word


/*** ADCCLPD - Plus-Side General Calibration Value D Register; 0x00001904 ***/
typedef union {
  byte Byte;
  struct {
    byte CLPD0       :1;                                       /* Plus-Side General Calibration Value D bit 0 */
    byte CLPD1       :1;                                       /* Plus-Side General Calibration Value D bit 1 */
    byte CLPD2       :1;                                       /* Plus-Side General Calibration Value D bit 2 */
    byte CLPD3       :1;                                       /* Plus-Side General Calibration Value D bit 3 */
    byte CLPD4       :1;                                       /* Plus-Side General Calibration Value D bit 4 */
    byte CLPD5       :1;                                       /* Plus-Side General Calibration Value D bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLPD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLPDSTR;
extern volatile ADCCLPDSTR _ADCCLPD @0x00001904;
#define ADCCLPD                         _ADCCLPD.Byte
#define ADCCLPD_CLPD0                   _ADCCLPD.Bits.CLPD0
#define ADCCLPD_CLPD1                   _ADCCLPD.Bits.CLPD1
#define ADCCLPD_CLPD2                   _ADCCLPD.Bits.CLPD2
#define ADCCLPD_CLPD3                   _ADCCLPD.Bits.CLPD3
#define ADCCLPD_CLPD4                   _ADCCLPD.Bits.CLPD4
#define ADCCLPD_CLPD5                   _ADCCLPD.Bits.CLPD5
#define ADCCLPD_CLPD                    _ADCCLPD.MergedBits.grpCLPD

#define ADCCLPD_CLPD0_MASK              1U
#define ADCCLPD_CLPD1_MASK              2U
#define ADCCLPD_CLPD2_MASK              4U
#define ADCCLPD_CLPD3_MASK              8U
#define ADCCLPD_CLPD4_MASK              16U
#define ADCCLPD_CLPD5_MASK              32U
#define ADCCLPD_CLPD_MASK               63U
#define ADCCLPD_CLPD_BITNUM             0U


/*** ADCCLPS - Plus-Side General Calibration Value S Register; 0x00001905 ***/
typedef union {
  byte Byte;
  struct {
    byte CLPS0       :1;                                       /* Plus-Side General Calibration Value S bit 0 */
    byte CLPS1       :1;                                       /* Plus-Side General Calibration Value S bit 1 */
    byte CLPS2       :1;                                       /* Plus-Side General Calibration Value S bit 2 */
    byte CLPS3       :1;                                       /* Plus-Side General Calibration Value S bit 3 */
    byte CLPS4       :1;                                       /* Plus-Side General Calibration Value S bit 4 */
    byte CLPS5       :1;                                       /* Plus-Side General Calibration Value S bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLPS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLPSSTR;
extern volatile ADCCLPSSTR _ADCCLPS @0x00001905;
#define ADCCLPS                         _ADCCLPS.Byte
#define ADCCLPS_CLPS0                   _ADCCLPS.Bits.CLPS0
#define ADCCLPS_CLPS1                   _ADCCLPS.Bits.CLPS1
#define ADCCLPS_CLPS2                   _ADCCLPS.Bits.CLPS2
#define ADCCLPS_CLPS3                   _ADCCLPS.Bits.CLPS3
#define ADCCLPS_CLPS4                   _ADCCLPS.Bits.CLPS4
#define ADCCLPS_CLPS5                   _ADCCLPS.Bits.CLPS5
#define ADCCLPS_CLPS                    _ADCCLPS.MergedBits.grpCLPS

#define ADCCLPS_CLPS0_MASK              1U
#define ADCCLPS_CLPS1_MASK              2U
#define ADCCLPS_CLPS2_MASK              4U
#define ADCCLPS_CLPS3_MASK              8U
#define ADCCLPS_CLPS4_MASK              16U
#define ADCCLPS_CLPS5_MASK              32U
#define ADCCLPS_CLPS_MASK               63U
#define ADCCLPS_CLPS_BITNUM             0U


/*** ADCCLP4 - Plus-Side General Calibration Value 4 Register; 0x00001906 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCLP4H - Plus-Side General Calibration Value 4 High Register; 0x00001906 ***/
    union {
      byte Byte;
      struct {
        byte CLP48       :1;                                       /* Plus-Side General Calibration Value 4 bit 8 */
        byte CLP49       :1;                                       /* Plus-Side General Calibration Value 4 bit 9 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCLP_48 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCLP4HSTR;
    #define ADCCLP4H                    _ADCCLP4.Overlap_STR.ADCCLP4HSTR.Byte
    #define ADCCLP4H_CLP48              _ADCCLP4.Overlap_STR.ADCCLP4HSTR.Bits.CLP48
    #define ADCCLP4H_CLP49              _ADCCLP4.Overlap_STR.ADCCLP4HSTR.Bits.CLP49
    #define ADCCLP4H_CLP_48             _ADCCLP4.Overlap_STR.ADCCLP4HSTR.MergedBits.grpCLP_48
    #define ADCCLP4H_CLP                ADCCLP4H_CLP_48
    
    #define ADCCLP4H_CLP48_MASK         1U
    #define ADCCLP4H_CLP49_MASK         2U
    #define ADCCLP4H_CLP_48_MASK        3U
    #define ADCCLP4H_CLP_48_BITNUM      0U
    

    /*** ADCCLP4L - Plus-Side General Calibration Value 4 Low Register; 0x00001907 ***/
    union {
      byte Byte;
      struct {
        byte CLP40       :1;                                       /* Plus-Side General Calibration Value 4 bit 0 */
        byte CLP41       :1;                                       /* Plus-Side General Calibration Value 4 bit 1 */
        byte CLP42       :1;                                       /* Plus-Side General Calibration Value 4 bit 2 */
        byte CLP43       :1;                                       /* Plus-Side General Calibration Value 4 bit 3 */
        byte CLP44       :1;                                       /* Plus-Side General Calibration Value 4 bit 4 */
        byte CLP45       :1;                                       /* Plus-Side General Calibration Value 4 bit 5 */
        byte CLP46       :1;                                       /* Plus-Side General Calibration Value 4 bit 6 */
        byte CLP47       :1;                                       /* Plus-Side General Calibration Value 4 bit 7 */
      } Bits;
    } ADCCLP4LSTR;
    #define ADCCLP4L                    _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Byte
    #define ADCCLP4L_CLP40              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP40
    #define ADCCLP4L_CLP41              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP41
    #define ADCCLP4L_CLP42              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP42
    #define ADCCLP4L_CLP43              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP43
    #define ADCCLP4L_CLP44              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP44
    #define ADCCLP4L_CLP45              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP45
    #define ADCCLP4L_CLP46              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP46
    #define ADCCLP4L_CLP47              _ADCCLP4.Overlap_STR.ADCCLP4LSTR.Bits.CLP47
    
    #define ADCCLP4L_CLP40_MASK         1U
    #define ADCCLP4L_CLP41_MASK         2U
    #define ADCCLP4L_CLP42_MASK         4U
    #define ADCCLP4L_CLP43_MASK         8U
    #define ADCCLP4L_CLP44_MASK         16U
    #define ADCCLP4L_CLP45_MASK         32U
    #define ADCCLP4L_CLP46_MASK         64U
    #define ADCCLP4L_CLP47_MASK         128U
    
  } Overlap_STR;

} ADCCLP4STR;
extern volatile ADCCLP4STR _ADCCLP4 @0x00001906;
#define ADCCLP4                         _ADCCLP4.Word


/*** ADCCLP3 - Plus-Side General Calibration Value 3 Register; 0x00001908 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCLP3H - Plus-Side General Calibration Value 3 High Register; 0x00001908 ***/
    union {
      byte Byte;
      struct {
        byte CLP38       :1;                                       /* Plus-Side General Calibration Value 3 bits */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ADCCLP3HSTR;
    #define ADCCLP3H                    _ADCCLP3.Overlap_STR.ADCCLP3HSTR.Byte
    #define ADCCLP3H_CLP38              _ADCCLP3.Overlap_STR.ADCCLP3HSTR.Bits.CLP38
    
    #define ADCCLP3H_CLP38_MASK         1U
    

    /*** ADCCLP3L - Plus-Side General Calibration Value 3 Low Register; 0x00001909 ***/
    union {
      byte Byte;
      struct {
        byte CLP30       :1;                                       /* Plus-Side General Calibration Value 3 bit 0 */
        byte CLP31       :1;                                       /* Plus-Side General Calibration Value 3 bit 1 */
        byte CLP32       :1;                                       /* Plus-Side General Calibration Value 3 bit 2 */
        byte CLP33       :1;                                       /* Plus-Side General Calibration Value 3 bit 3 */
        byte CLP34       :1;                                       /* Plus-Side General Calibration Value 3 bit 4 */
        byte CLP35       :1;                                       /* Plus-Side General Calibration Value 3 bit 5 */
        byte CLP36       :1;                                       /* Plus-Side General Calibration Value 3 bit 6 */
        byte CLP37       :1;                                       /* Plus-Side General Calibration Value 3 bit 7 */
      } Bits;
    } ADCCLP3LSTR;
    #define ADCCLP3L                    _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Byte
    #define ADCCLP3L_CLP30              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP30
    #define ADCCLP3L_CLP31              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP31
    #define ADCCLP3L_CLP32              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP32
    #define ADCCLP3L_CLP33              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP33
    #define ADCCLP3L_CLP34              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP34
    #define ADCCLP3L_CLP35              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP35
    #define ADCCLP3L_CLP36              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP36
    #define ADCCLP3L_CLP37              _ADCCLP3.Overlap_STR.ADCCLP3LSTR.Bits.CLP37
    
    #define ADCCLP3L_CLP30_MASK         1U
    #define ADCCLP3L_CLP31_MASK         2U
    #define ADCCLP3L_CLP32_MASK         4U
    #define ADCCLP3L_CLP33_MASK         8U
    #define ADCCLP3L_CLP34_MASK         16U
    #define ADCCLP3L_CLP35_MASK         32U
    #define ADCCLP3L_CLP36_MASK         64U
    #define ADCCLP3L_CLP37_MASK         128U
    
  } Overlap_STR;

} ADCCLP3STR;
extern volatile ADCCLP3STR _ADCCLP3 @0x00001908;
#define ADCCLP3                         _ADCCLP3.Word


/*** ADCCLP2 - Plus-Side General Calibration Value 2 Register; 0x0000190A ***/
typedef union {
  byte Byte;
  struct {
    byte CLP20       :1;                                       /* Plus-Side General Calibration Value 2 bit 0 */
    byte CLP21       :1;                                       /* Plus-Side General Calibration Value 2 bit 1 */
    byte CLP22       :1;                                       /* Plus-Side General Calibration Value 2 bit 2 */
    byte CLP23       :1;                                       /* Plus-Side General Calibration Value 2 bit 3 */
    byte CLP24       :1;                                       /* Plus-Side General Calibration Value 2 bit 4 */
    byte CLP25       :1;                                       /* Plus-Side General Calibration Value 2 bit 5 */
    byte CLP26       :1;                                       /* Plus-Side General Calibration Value 2 bit 6 */
    byte CLP27       :1;                                       /* Plus-Side General Calibration Value 2 bit 7 */
  } Bits;
} ADCCLP2STR;
extern volatile ADCCLP2STR _ADCCLP2 @0x0000190A;
#define ADCCLP2                         _ADCCLP2.Byte
#define ADCCLP2_CLP20                   _ADCCLP2.Bits.CLP20
#define ADCCLP2_CLP21                   _ADCCLP2.Bits.CLP21
#define ADCCLP2_CLP22                   _ADCCLP2.Bits.CLP22
#define ADCCLP2_CLP23                   _ADCCLP2.Bits.CLP23
#define ADCCLP2_CLP24                   _ADCCLP2.Bits.CLP24
#define ADCCLP2_CLP25                   _ADCCLP2.Bits.CLP25
#define ADCCLP2_CLP26                   _ADCCLP2.Bits.CLP26
#define ADCCLP2_CLP27                   _ADCCLP2.Bits.CLP27

#define ADCCLP2_CLP20_MASK              1U
#define ADCCLP2_CLP21_MASK              2U
#define ADCCLP2_CLP22_MASK              4U
#define ADCCLP2_CLP23_MASK              8U
#define ADCCLP2_CLP24_MASK              16U
#define ADCCLP2_CLP25_MASK              32U
#define ADCCLP2_CLP26_MASK              64U
#define ADCCLP2_CLP27_MASK              128U


/*** ADCCLP1 - Plus-Side General Calibration Value 1 Register; 0x0000190B ***/
typedef union {
  byte Byte;
  struct {
    byte CLP10       :1;                                       /* Plus-Side General Calibration Value 1 bit 0 */
    byte CLP11       :1;                                       /* Plus-Side General Calibration Value 1 bit 1 */
    byte CLP12       :1;                                       /* Plus-Side General Calibration Value 1 bit 2 */
    byte CLP13       :1;                                       /* Plus-Side General Calibration Value 1 bit 3 */
    byte CLP14       :1;                                       /* Plus-Side General Calibration Value 1 bit 4 */
    byte CLP15       :1;                                       /* Plus-Side General Calibration Value 1 bit 5 */
    byte CLP16       :1;                                       /* Plus-Side General Calibration Value 1 bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpCLP_10 :7;
    byte         :1;
  } MergedBits;
} ADCCLP1STR;
extern volatile ADCCLP1STR _ADCCLP1 @0x0000190B;
#define ADCCLP1                         _ADCCLP1.Byte
#define ADCCLP1_CLP10                   _ADCCLP1.Bits.CLP10
#define ADCCLP1_CLP11                   _ADCCLP1.Bits.CLP11
#define ADCCLP1_CLP12                   _ADCCLP1.Bits.CLP12
#define ADCCLP1_CLP13                   _ADCCLP1.Bits.CLP13
#define ADCCLP1_CLP14                   _ADCCLP1.Bits.CLP14
#define ADCCLP1_CLP15                   _ADCCLP1.Bits.CLP15
#define ADCCLP1_CLP16                   _ADCCLP1.Bits.CLP16
#define ADCCLP1_CLP_10                  _ADCCLP1.MergedBits.grpCLP_10
#define ADCCLP1_CLP                     ADCCLP1_CLP_10

#define ADCCLP1_CLP10_MASK              1U
#define ADCCLP1_CLP11_MASK              2U
#define ADCCLP1_CLP12_MASK              4U
#define ADCCLP1_CLP13_MASK              8U
#define ADCCLP1_CLP14_MASK              16U
#define ADCCLP1_CLP15_MASK              32U
#define ADCCLP1_CLP16_MASK              64U
#define ADCCLP1_CLP_10_MASK             127U
#define ADCCLP1_CLP_10_BITNUM           0U


/*** ADCCLP0 - Plus-Side General Calibration Value 0 Register; 0x0000190C ***/
typedef union {
  byte Byte;
  struct {
    byte CLP00       :1;                                       /* Plus-Side General Calibration Value 0 bit 0 */
    byte CLP01       :1;                                       /* Plus-Side General Calibration Value 0 bit 1 */
    byte CLP02       :1;                                       /* Plus-Side General Calibration Value 0 bit 2 */
    byte CLP03       :1;                                       /* Plus-Side General Calibration Value 0 bit 3 */
    byte CLP04       :1;                                       /* Plus-Side General Calibration Value 0 bit 4 */
    byte CLP05       :1;                                       /* Plus-Side General Calibration Value 0 bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLP0 :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLP0STR;
extern volatile ADCCLP0STR _ADCCLP0 @0x0000190C;
#define ADCCLP0                         _ADCCLP0.Byte
#define ADCCLP0_CLP00                   _ADCCLP0.Bits.CLP00
#define ADCCLP0_CLP01                   _ADCCLP0.Bits.CLP01
#define ADCCLP0_CLP02                   _ADCCLP0.Bits.CLP02
#define ADCCLP0_CLP03                   _ADCCLP0.Bits.CLP03
#define ADCCLP0_CLP04                   _ADCCLP0.Bits.CLP04
#define ADCCLP0_CLP05                   _ADCCLP0.Bits.CLP05
#define ADCCLP0_CLP0                    _ADCCLP0.MergedBits.grpCLP0

#define ADCCLP0_CLP00_MASK              1U
#define ADCCLP0_CLP01_MASK              2U
#define ADCCLP0_CLP02_MASK              4U
#define ADCCLP0_CLP03_MASK              8U
#define ADCCLP0_CLP04_MASK              16U
#define ADCCLP0_CLP05_MASK              32U
#define ADCCLP0_CLP0_MASK               63U
#define ADCCLP0_CLP0_BITNUM             0U


/*** ADCCLMD - Minus-Side General Calibration Value D Register; 0x0000190E ***/
typedef union {
  byte Byte;
  struct {
    byte CLMD0       :1;                                       /* Minus-Side General Calibration Value D bit 0 */
    byte CLMD1       :1;                                       /* Minus-Side General Calibration Value D bit 1 */
    byte CLMD2       :1;                                       /* Minus-Side General Calibration Value D bit 2 */
    byte CLMD3       :1;                                       /* Minus-Side General Calibration Value D bit 3 */
    byte CLMD4       :1;                                       /* Minus-Side General Calibration Value D bit 4 */
    byte CLMD5       :1;                                       /* Minus-Side General Calibration Value D bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLMD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLMDSTR;
extern volatile ADCCLMDSTR _ADCCLMD @0x0000190E;
#define ADCCLMD                         _ADCCLMD.Byte
#define ADCCLMD_CLMD0                   _ADCCLMD.Bits.CLMD0
#define ADCCLMD_CLMD1                   _ADCCLMD.Bits.CLMD1
#define ADCCLMD_CLMD2                   _ADCCLMD.Bits.CLMD2
#define ADCCLMD_CLMD3                   _ADCCLMD.Bits.CLMD3
#define ADCCLMD_CLMD4                   _ADCCLMD.Bits.CLMD4
#define ADCCLMD_CLMD5                   _ADCCLMD.Bits.CLMD5
#define ADCCLMD_CLMD                    _ADCCLMD.MergedBits.grpCLMD

#define ADCCLMD_CLMD0_MASK              1U
#define ADCCLMD_CLMD1_MASK              2U
#define ADCCLMD_CLMD2_MASK              4U
#define ADCCLMD_CLMD3_MASK              8U
#define ADCCLMD_CLMD4_MASK              16U
#define ADCCLMD_CLMD5_MASK              32U
#define ADCCLMD_CLMD_MASK               63U
#define ADCCLMD_CLMD_BITNUM             0U


/*** ADCCLMS - Minus-Side General Calibration Value S Register; 0x0000190F ***/
typedef union {
  byte Byte;
  struct {
    byte CLMS0       :1;                                       /* Minus-Side General Calibration Value S bit 0 */
    byte CLMS1       :1;                                       /* Minus-Side General Calibration Value S bit 1 */
    byte CLMS2       :1;                                       /* Minus-Side General Calibration Value S bit 2 */
    byte CLMS3       :1;                                       /* Minus-Side General Calibration Value S bit 3 */
    byte CLMS4       :1;                                       /* Minus-Side General Calibration Value S bit 4 */
    byte CLMS5       :1;                                       /* Minus-Side General Calibration Value S bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLMS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLMSSTR;
extern volatile ADCCLMSSTR _ADCCLMS @0x0000190F;
#define ADCCLMS                         _ADCCLMS.Byte
#define ADCCLMS_CLMS0                   _ADCCLMS.Bits.CLMS0
#define ADCCLMS_CLMS1                   _ADCCLMS.Bits.CLMS1
#define ADCCLMS_CLMS2                   _ADCCLMS.Bits.CLMS2
#define ADCCLMS_CLMS3                   _ADCCLMS.Bits.CLMS3
#define ADCCLMS_CLMS4                   _ADCCLMS.Bits.CLMS4
#define ADCCLMS_CLMS5                   _ADCCLMS.Bits.CLMS5
#define ADCCLMS_CLMS                    _ADCCLMS.MergedBits.grpCLMS

#define ADCCLMS_CLMS0_MASK              1U
#define ADCCLMS_CLMS1_MASK              2U
#define ADCCLMS_CLMS2_MASK              4U
#define ADCCLMS_CLMS3_MASK              8U
#define ADCCLMS_CLMS4_MASK              16U
#define ADCCLMS_CLMS5_MASK              32U
#define ADCCLMS_CLMS_MASK               63U
#define ADCCLMS_CLMS_BITNUM             0U


/*** ADCCLM4 - Minus-Side General Calibration Value 4 Register; 0x00001910 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCLM4H - Minus-Side General Calibration Value 4 High Register; 0x00001910 ***/
    union {
      byte Byte;
      struct {
        byte CLM48       :1;                                       /* Minus-Side General Calibration Value 4 bit 8 */
        byte CLM49       :1;                                       /* Minus-Side General Calibration Value 4 bit 9 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCLM_48 :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCLM4HSTR;
    #define ADCCLM4H                    _ADCCLM4.Overlap_STR.ADCCLM4HSTR.Byte
    #define ADCCLM4H_CLM48              _ADCCLM4.Overlap_STR.ADCCLM4HSTR.Bits.CLM48
    #define ADCCLM4H_CLM49              _ADCCLM4.Overlap_STR.ADCCLM4HSTR.Bits.CLM49
    #define ADCCLM4H_CLM_48             _ADCCLM4.Overlap_STR.ADCCLM4HSTR.MergedBits.grpCLM_48
    #define ADCCLM4H_CLM                ADCCLM4H_CLM_48
    
    #define ADCCLM4H_CLM48_MASK         1U
    #define ADCCLM4H_CLM49_MASK         2U
    #define ADCCLM4H_CLM_48_MASK        3U
    #define ADCCLM4H_CLM_48_BITNUM      0U
    

    /*** ADCCLM4L - Minus-Side General Calibration Value 4 Low Register; 0x00001911 ***/
    union {
      byte Byte;
      struct {
        byte CLM40       :1;                                       /* Minus-Side General Calibration Value 4 bit 0 */
        byte CLM41       :1;                                       /* Minus-Side General Calibration Value 4 bit 1 */
        byte CLM42       :1;                                       /* Minus-Side General Calibration Value 4 bit 2 */
        byte CLM43       :1;                                       /* Minus-Side General Calibration Value 4 bit 3 */
        byte CLM44       :1;                                       /* Minus-Side General Calibration Value 4 bit 4 */
        byte CLM45       :1;                                       /* Minus-Side General Calibration Value 4 bit 5 */
        byte CLM46       :1;                                       /* Minus-Side General Calibration Value 4 bit 6 */
        byte CLM47       :1;                                       /* Minus-Side General Calibration Value 4 bit 7 */
      } Bits;
    } ADCCLM4LSTR;
    #define ADCCLM4L                    _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Byte
    #define ADCCLM4L_CLM40              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM40
    #define ADCCLM4L_CLM41              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM41
    #define ADCCLM4L_CLM42              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM42
    #define ADCCLM4L_CLM43              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM43
    #define ADCCLM4L_CLM44              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM44
    #define ADCCLM4L_CLM45              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM45
    #define ADCCLM4L_CLM46              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM46
    #define ADCCLM4L_CLM47              _ADCCLM4.Overlap_STR.ADCCLM4LSTR.Bits.CLM47
    
    #define ADCCLM4L_CLM40_MASK         1U
    #define ADCCLM4L_CLM41_MASK         2U
    #define ADCCLM4L_CLM42_MASK         4U
    #define ADCCLM4L_CLM43_MASK         8U
    #define ADCCLM4L_CLM44_MASK         16U
    #define ADCCLM4L_CLM45_MASK         32U
    #define ADCCLM4L_CLM46_MASK         64U
    #define ADCCLM4L_CLM47_MASK         128U
    
  } Overlap_STR;

} ADCCLM4STR;
extern volatile ADCCLM4STR _ADCCLM4 @0x00001910;
#define ADCCLM4                         _ADCCLM4.Word


/*** ADCCLM3 - Minus-Side General Calibration Value 3 Register; 0x00001912 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCLM3H - Minus-Side General Calibration Value 3 High Register; 0x00001912 ***/
    union {
      byte Byte;
      struct {
        byte CLM38       :1;                                       /* Minus-Side General Calibration Value 3 bits */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ADCCLM3HSTR;
    #define ADCCLM3H                    _ADCCLM3.Overlap_STR.ADCCLM3HSTR.Byte
    #define ADCCLM3H_CLM38              _ADCCLM3.Overlap_STR.ADCCLM3HSTR.Bits.CLM38
    
    #define ADCCLM3H_CLM38_MASK         1U
    

    /*** ADCCLM3L - Minus-Side General Calibration Value 3 Low Register; 0x00001913 ***/
    union {
      byte Byte;
      struct {
        byte CLM30       :1;                                       /* Minus-Side General Calibration Value 3 bit 0 */
        byte CLM31       :1;                                       /* Minus-Side General Calibration Value 3 bit 1 */
        byte CLM32       :1;                                       /* Minus-Side General Calibration Value 3 bit 2 */
        byte CLM33       :1;                                       /* Minus-Side General Calibration Value 3 bit 3 */
        byte CLM34       :1;                                       /* Minus-Side General Calibration Value 3 bit 4 */
        byte CLM35       :1;                                       /* Minus-Side General Calibration Value 3 bit 5 */
        byte CLM36       :1;                                       /* Minus-Side General Calibration Value 3 bit 6 */
        byte CLM37       :1;                                       /* Minus-Side General Calibration Value 3 bit 7 */
      } Bits;
    } ADCCLM3LSTR;
    #define ADCCLM3L                    _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Byte
    #define ADCCLM3L_CLM30              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM30
    #define ADCCLM3L_CLM31              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM31
    #define ADCCLM3L_CLM32              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM32
    #define ADCCLM3L_CLM33              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM33
    #define ADCCLM3L_CLM34              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM34
    #define ADCCLM3L_CLM35              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM35
    #define ADCCLM3L_CLM36              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM36
    #define ADCCLM3L_CLM37              _ADCCLM3.Overlap_STR.ADCCLM3LSTR.Bits.CLM37
    
    #define ADCCLM3L_CLM30_MASK         1U
    #define ADCCLM3L_CLM31_MASK         2U
    #define ADCCLM3L_CLM32_MASK         4U
    #define ADCCLM3L_CLM33_MASK         8U
    #define ADCCLM3L_CLM34_MASK         16U
    #define ADCCLM3L_CLM35_MASK         32U
    #define ADCCLM3L_CLM36_MASK         64U
    #define ADCCLM3L_CLM37_MASK         128U
    
  } Overlap_STR;

} ADCCLM3STR;
extern volatile ADCCLM3STR _ADCCLM3 @0x00001912;
#define ADCCLM3                         _ADCCLM3.Word


/*** ADCCLM2 - Minus-Side General Calibration Value 2 Register; 0x00001914 ***/
typedef union {
  byte Byte;
  struct {
    byte CLM20       :1;                                       /* Minus-Side General Calibration Value 2 bit 0 */
    byte CLM21       :1;                                       /* Minus-Side General Calibration Value 2 bit 1 */
    byte CLM22       :1;                                       /* Minus-Side General Calibration Value 2 bit 2 */
    byte CLM23       :1;                                       /* Minus-Side General Calibration Value 2 bit 3 */
    byte CLM24       :1;                                       /* Minus-Side General Calibration Value 2 bit 4 */
    byte CLM25       :1;                                       /* Minus-Side General Calibration Value 2 bit 5 */
    byte CLM26       :1;                                       /* Minus-Side General Calibration Value 2 bit 6 */
    byte CLM27       :1;                                       /* Minus-Side General Calibration Value 2 bit 7 */
  } Bits;
} ADCCLM2STR;
extern volatile ADCCLM2STR _ADCCLM2 @0x00001914;
#define ADCCLM2                         _ADCCLM2.Byte
#define ADCCLM2_CLM20                   _ADCCLM2.Bits.CLM20
#define ADCCLM2_CLM21                   _ADCCLM2.Bits.CLM21
#define ADCCLM2_CLM22                   _ADCCLM2.Bits.CLM22
#define ADCCLM2_CLM23                   _ADCCLM2.Bits.CLM23
#define ADCCLM2_CLM24                   _ADCCLM2.Bits.CLM24
#define ADCCLM2_CLM25                   _ADCCLM2.Bits.CLM25
#define ADCCLM2_CLM26                   _ADCCLM2.Bits.CLM26
#define ADCCLM2_CLM27                   _ADCCLM2.Bits.CLM27

#define ADCCLM2_CLM20_MASK              1U
#define ADCCLM2_CLM21_MASK              2U
#define ADCCLM2_CLM22_MASK              4U
#define ADCCLM2_CLM23_MASK              8U
#define ADCCLM2_CLM24_MASK              16U
#define ADCCLM2_CLM25_MASK              32U
#define ADCCLM2_CLM26_MASK              64U
#define ADCCLM2_CLM27_MASK              128U


/*** ADCCLM1 - Minus-Side General Calibration Value 1 Register; 0x00001915 ***/
typedef union {
  byte Byte;
  struct {
    byte CLM10       :1;                                       /* Minus-Side General Calibration Value 1 bit 0 */
    byte CLM11       :1;                                       /* Minus-Side General Calibration Value 1 bit 1 */
    byte CLM12       :1;                                       /* Minus-Side General Calibration Value 1 bit 2 */
    byte CLM13       :1;                                       /* Minus-Side General Calibration Value 1 bit 3 */
    byte CLM14       :1;                                       /* Minus-Side General Calibration Value 1 bit 4 */
    byte CLM15       :1;                                       /* Minus-Side General Calibration Value 1 bit 5 */
    byte CLM16       :1;                                       /* Minus-Side General Calibration Value 1 bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpCLM_10 :7;
    byte         :1;
  } MergedBits;
} ADCCLM1STR;
extern volatile ADCCLM1STR _ADCCLM1 @0x00001915;
#define ADCCLM1                         _ADCCLM1.Byte
#define ADCCLM1_CLM10                   _ADCCLM1.Bits.CLM10
#define ADCCLM1_CLM11                   _ADCCLM1.Bits.CLM11
#define ADCCLM1_CLM12                   _ADCCLM1.Bits.CLM12
#define ADCCLM1_CLM13                   _ADCCLM1.Bits.CLM13
#define ADCCLM1_CLM14                   _ADCCLM1.Bits.CLM14
#define ADCCLM1_CLM15                   _ADCCLM1.Bits.CLM15
#define ADCCLM1_CLM16                   _ADCCLM1.Bits.CLM16
#define ADCCLM1_CLM_10                  _ADCCLM1.MergedBits.grpCLM_10
#define ADCCLM1_CLM                     ADCCLM1_CLM_10

#define ADCCLM1_CLM10_MASK              1U
#define ADCCLM1_CLM11_MASK              2U
#define ADCCLM1_CLM12_MASK              4U
#define ADCCLM1_CLM13_MASK              8U
#define ADCCLM1_CLM14_MASK              16U
#define ADCCLM1_CLM15_MASK              32U
#define ADCCLM1_CLM16_MASK              64U
#define ADCCLM1_CLM_10_MASK             127U
#define ADCCLM1_CLM_10_BITNUM           0U


/*** ADCCLM0 - Minus-Side General Calibration Value 0 Register; 0x00001916 ***/
typedef union {
  byte Byte;
  struct {
    byte CLM00       :1;                                       /* Minus-Side General Calibration Value 0 bit 0 */
    byte CLM01       :1;                                       /* Minus-Side General Calibration Value 0 bit 1 */
    byte CLM02       :1;                                       /* Minus-Side General Calibration Value 0 bit 2 */
    byte CLM03       :1;                                       /* Minus-Side General Calibration Value 0 bit 3 */
    byte CLM04       :1;                                       /* Minus-Side General Calibration Value 0 bit 4 */
    byte CLM05       :1;                                       /* Minus-Side General Calibration Value 0 bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLM0 :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCLM0STR;
extern volatile ADCCLM0STR _ADCCLM0 @0x00001916;
#define ADCCLM0                         _ADCCLM0.Byte
#define ADCCLM0_CLM00                   _ADCCLM0.Bits.CLM00
#define ADCCLM0_CLM01                   _ADCCLM0.Bits.CLM01
#define ADCCLM0_CLM02                   _ADCCLM0.Bits.CLM02
#define ADCCLM0_CLM03                   _ADCCLM0.Bits.CLM03
#define ADCCLM0_CLM04                   _ADCCLM0.Bits.CLM04
#define ADCCLM0_CLM05                   _ADCCLM0.Bits.CLM05
#define ADCCLM0_CLM0                    _ADCCLM0.MergedBits.grpCLM0

#define ADCCLM0_CLM00_MASK              1U
#define ADCCLM0_CLM01_MASK              2U
#define ADCCLM0_CLM02_MASK              4U
#define ADCCLM0_CLM03_MASK              8U
#define ADCCLM0_CLM04_MASK              16U
#define ADCCLM0_CLM05_MASK              32U
#define ADCCLM0_CLM0_MASK               63U
#define ADCCLM0_CLM0_BITNUM             0U


/*** APCTL1 - Pin Control 1 Register; 0x00001917 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0x00001917;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1U
#define APCTL1_ADPC1_MASK               2U
#define APCTL1_ADPC2_MASK               4U
#define APCTL1_ADPC3_MASK               8U
#define APCTL1_ADPC4_MASK               16U
#define APCTL1_ADPC5_MASK               32U
#define APCTL1_ADPC6_MASK               64U
#define APCTL1_ADPC7_MASK               128U


/*** APCTL2 - Pin Control 2 Register; 0x00001918 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADPC_8 :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} APCTL2STR;
extern volatile APCTL2STR _APCTL2 @0x00001918;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC_8                   _APCTL2.MergedBits.grpADPC_8
#define APCTL2_ADPC                     APCTL2_ADPC_8

#define APCTL2_ADPC8_MASK               1U
#define APCTL2_ADPC9_MASK               2U
#define APCTL2_ADPC10_MASK              4U
#define APCTL2_ADPC11_MASK              8U
#define APCTL2_ADPC_8_MASK              15U
#define APCTL2_ADPC_8_BITNUM            0U


/*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x0000FFAE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR * __far)0x0000FFAE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1U


/*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x0000FFAF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} NVMCGTRMSTR;
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT @0x0000FFAF = <NVMCGTRM_INITVAL>; */
#define _NVMCGTRM (*(const NVMCGTRMSTR * __far)0x0000FFAF)
#define NVMCGTRM                        _NVMCGTRM.Byte
#define NVMCGTRM_TRIM0                  _NVMCGTRM.Bits.TRIM0
#define NVMCGTRM_TRIM1                  _NVMCGTRM.Bits.TRIM1
#define NVMCGTRM_TRIM2                  _NVMCGTRM.Bits.TRIM2
#define NVMCGTRM_TRIM3                  _NVMCGTRM.Bits.TRIM3
#define NVMCGTRM_TRIM4                  _NVMCGTRM.Bits.TRIM4
#define NVMCGTRM_TRIM5                  _NVMCGTRM.Bits.TRIM5
#define NVMCGTRM_TRIM6                  _NVMCGTRM.Bits.TRIM6
#define NVMCGTRM_TRIM7                  _NVMCGTRM.Bits.TRIM7

#define NVMCGTRM_TRIM0_MASK             1U
#define NVMCGTRM_TRIM1_MASK             2U
#define NVMCGTRM_TRIM2_MASK             4U
#define NVMCGTRM_TRIM3_MASK             8U
#define NVMCGTRM_TRIM4_MASK             16U
#define NVMCGTRM_TRIM5_MASK             32U
#define NVMCGTRM_TRIM6_MASK             64U
#define NVMCGTRM_TRIM7_MASK             128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** FCHKS - Flash Checksum Register; 0x0000FFB8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCHKSH - Flash Checksum Register High Byte; 0x0000FFB8 ***/
    union {
      byte Byte;
      struct {
        byte CHECKSUM8   :1;                                       /* Flash checksum bit 8 */
        byte CHECKSUM9   :1;                                       /* Flash checksum bit 9 */
        byte CHECKSUM10  :1;                                       /* Flash checksum bit 10 */
        byte CHECKSUM11  :1;                                       /* Flash checksum bit 11 */
        byte CHECKSUM12  :1;                                       /* Flash checksum bit 12 */
        byte CHECKSUM13  :1;                                       /* Flash checksum bit 13 */
        byte CHECKSUM14  :1;                                       /* Flash checksum bit 14 */
        byte CHECKSUM15  :1;                                       /* Flash checksum bit 15 */
      } Bits;
    } FCHKSHSTR;
    #define FCHKSH                      _FCHKS.Overlap_STR.FCHKSHSTR.Byte
    #define FCHKSH_CHECKSUM8            _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM8
    #define FCHKSH_CHECKSUM9            _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM9
    #define FCHKSH_CHECKSUM10           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM10
    #define FCHKSH_CHECKSUM11           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM11
    #define FCHKSH_CHECKSUM12           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM12
    #define FCHKSH_CHECKSUM13           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM13
    #define FCHKSH_CHECKSUM14           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM14
    #define FCHKSH_CHECKSUM15           _FCHKS.Overlap_STR.FCHKSHSTR.Bits.CHECKSUM15
    
    #define FCHKSH_CHECKSUM8_MASK       1U
    #define FCHKSH_CHECKSUM9_MASK       2U
    #define FCHKSH_CHECKSUM10_MASK      4U
    #define FCHKSH_CHECKSUM11_MASK      8U
    #define FCHKSH_CHECKSUM12_MASK      16U
    #define FCHKSH_CHECKSUM13_MASK      32U
    #define FCHKSH_CHECKSUM14_MASK      64U
    #define FCHKSH_CHECKSUM15_MASK      128U
    

    /*** FCHKSL - Flash Checksum Register Low Byte; 0x0000FFB9 ***/
    union {
      byte Byte;
      struct {
        byte CHECKSUM0   :1;                                       /* Flash checksum bits, bit 0 */
        byte CHECKSUM1   :1;                                       /* Flash checksum bits, bit 1 */
        byte CHECKSUM2   :1;                                       /* Flash checksum bits, bit 2 */
        byte CHECKSUM3   :1;                                       /* Flash checksum bits, bit 3 */
        byte CHECKSUM4   :1;                                       /* Flash checksum bits, bit 4 */
        byte CHECKSUM5   :1;                                       /* Flash checksum bits, bit 5 */
        byte CHECKSUM6   :1;                                       /* Flash checksum bits, bit 6 */
        byte CHECKSUM7   :1;                                       /* Flash checksum bits, bit 7 */
      } Bits;
    } FCHKSLSTR;
    #define FCHKSL                      _FCHKS.Overlap_STR.FCHKSLSTR.Byte
    #define FCHKSL_CHECKSUM0            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM0
    #define FCHKSL_CHECKSUM1            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM1
    #define FCHKSL_CHECKSUM2            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM2
    #define FCHKSL_CHECKSUM3            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM3
    #define FCHKSL_CHECKSUM4            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM4
    #define FCHKSL_CHECKSUM5            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM5
    #define FCHKSL_CHECKSUM6            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM6
    #define FCHKSL_CHECKSUM7            _FCHKS.Overlap_STR.FCHKSLSTR.Bits.CHECKSUM7
    
    #define FCHKSL_CHECKSUM0_MASK       1U
    #define FCHKSL_CHECKSUM1_MASK       2U
    #define FCHKSL_CHECKSUM2_MASK       4U
    #define FCHKSL_CHECKSUM3_MASK       8U
    #define FCHKSL_CHECKSUM4_MASK       16U
    #define FCHKSL_CHECKSUM5_MASK       32U
    #define FCHKSL_CHECKSUM6_MASK       64U
    #define FCHKSL_CHECKSUM7_MASK       128U
    
  } Overlap_STR;

} FCHKSSTR;
/* Tip for register initialization in the user code:  const word FCHKS_INIT @0x0000FFB8 = <FCHKS_INITVAL>; */
#define _FCHKS (*(const FCHKSSTR * __far)0x0000FFB8)
#define FCHKS                           _FCHKS.Word


/*** CHKSBYP - Checksum Bypass Register; 0x0000FFBA ***/
typedef union {
  byte Byte;
} CHKSBYPSTR;
/* Tip for register initialization in the user code:  const byte CHKSBYP_INIT @0x0000FFBA = <CHKSBYP_INITVAL>; */
#define _CHKSBYP (*(const CHKSBYPSTR * __far)0x0000FFBA)
#define CHKSBYP                         _CHKSBYP.Byte


/*** Partial_Erase_Semaphore - Flash partial erase semaphore; 0x0000FFBC ***/
typedef union {
  byte Byte;
} Partial_Erase_SemaphoreSTR;
/* Tip for register initialization in the user code:  const byte Partial_Erase_Semaphore_INIT @0x0000FFBC = <Partial_Erase_Semaphore_INITVAL>; */
#define _Partial_Erase_Semaphore (*(const Partial_Erase_SemaphoreSTR * __far)0x0000FFBC)
#define Partial_Erase_Semaphore         _Partial_Erase_Semaphore.Byte


/*** NVPROT - Nonvolatile Flash Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPOPEN                   _NVPROT.Bits.FPOPEN
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS

#define NVPROT_FPOPEN_MASK              1U
#define NVPROT_FPS0_MASK                2U
#define NVPROT_FPS1_MASK                4U
#define NVPROT_FPS2_MASK                8U
#define NVPROT_FPS3_MASK                16U
#define NVPROT_FPS4_MASK                32U
#define NVPROT_FPS5_MASK                64U
#define NVPROT_FPS6_MASK                128U
#define NVPROT_FPS_MASK                 254U
#define NVPROT_FPS_BITNUM               1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_KEYEN0                    _NVOPT.Bits.KEYEN0
#define NVOPT_KEYEN1                    _NVOPT.Bits.KEYEN1
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC
#define NVOPT_KEYEN                     _NVOPT.MergedBits.grpKEYEN

#define NVOPT_SEC0_MASK                 1U
#define NVOPT_SEC1_MASK                 2U
#define NVOPT_KEYEN0_MASK               64U
#define NVOPT_KEYEN1_MASK               128U
#define NVOPT_SEC_MASK                  3U
#define NVOPT_SEC_BITNUM                0U
#define NVOPT_KEYEN_MASK                192U
#define NVOPT_KEYEN_BITNUM              6U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 25.6.2010 10:51:52 */

/*** SOPT5 - System Options Register 5; 0x0000180D ***/
typedef union {
  byte Byte;
  struct {
    byte PMC_LVD_TRIM0 :1;                                     /* PMC LVD TRIM, bit 0 */
    byte PMC_LVD_TRIM1 :1;                                     /* PMC LVD TRIM, bit 1 */
    byte PMC_LVD_TRIM2 :1;                                     /* PMC LVD TRIM, bit 2 */
    byte PMC_LVD_TRIM3 :1;                                     /* PMC LVD TRIM, bit 3 */
    byte PMC_LVD_TRIM4 :1;                                     /* PMC LVD TRIM, bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPMC_LVD_TRIM :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT5STR;
extern volatile SOPT5STR _SOPT5 @0x0000180D;
#define SOPT5                           _SOPT5.Byte
#define SOPT5_PMC_LVD_TRIM0             _SOPT5.Bits.PMC_LVD_TRIM0
#define SOPT5_PMC_LVD_TRIM1             _SOPT5.Bits.PMC_LVD_TRIM1
#define SOPT5_PMC_LVD_TRIM2             _SOPT5.Bits.PMC_LVD_TRIM2
#define SOPT5_PMC_LVD_TRIM3             _SOPT5.Bits.PMC_LVD_TRIM3
#define SOPT5_PMC_LVD_TRIM4             _SOPT5.Bits.PMC_LVD_TRIM4
#define SOPT5_PMC_LVD_TRIM              _SOPT5.MergedBits.grpPMC_LVD_TRIM

#define SOPT5_PMC_LVD_TRIM0_MASK        1
#define SOPT5_PMC_LVD_TRIM1_MASK        2
#define SOPT5_PMC_LVD_TRIM2_MASK        4
#define SOPT5_PMC_LVD_TRIM3_MASK        8
#define SOPT5_PMC_LVD_TRIM4_MASK        16
#define SOPT5_PMC_LVD_TRIM_MASK         31
#define SOPT5_PMC_LVD_TRIM_BITNUM       0
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
