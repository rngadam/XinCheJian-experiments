/* Based on CPU DB MC9S08MM128_81, version 3.00.011 (RegistersPrg V2.32) */
/* DataSheet : MC9S08MM128RM Rev. 3 07/2010 */

#include <mc9s08mm128.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0x00000001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000002 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0x00000003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0x00000004 */
volatile PTCDDSTR _PTCDD;                                  /* Port C Data Direction Register; 0x00000005 */
volatile PTDDSTR _PTDD;                                    /* Port D Data Register; 0x00000006 */
volatile PTDDDSTR _PTDDD;                                  /* Port D Data Direction Register; 0x00000007 */
volatile PPAGESTR _PPAGE;                                  /* Program Page Register; 0x00000008 */
volatile LAP2STR _LAP2;                                    /* Linear Address Pointer Register 2; 0x00000009 */
volatile LAP1STR _LAP1;                                    /* Linear Address Pointer Register 1; 0x0000000A */
volatile LAP0STR _LAP0;                                    /* Linear Address Pointer Register 0; 0x0000000B */
volatile LWPSTR _LWP;                                      /* Linear Word Post Increment Register; 0x0000000C */
volatile LBPSTR _LBP;                                      /* Linear Byte Post Increment Register; 0x0000000D */
volatile LBSTR _LB;                                        /* Linear Byte Register; 0x0000000E */
volatile LAPABSTR _LAPAB;                                  /* Linear Address Pointer Add Byte Register; 0x0000000F */
volatile DACSSTR _DACS;                                    /* DAC Status Register; 0x00000030 */
volatile DACC0STR _DACC0;                                  /* DAC Control 0 Register; 0x00000031 */
volatile DACC1STR _DACC1;                                  /* DAC Control 1 Register; 0x00000032 */
volatile DACC2STR _DACC2;                                  /* DAC Control 2 Register; 0x00000033 */
volatile PRACMPCSSTR _PRACMPCS;                            /* PRACMP Control and Status Register; 0x00000034 */
volatile PRACMPC0STR _PRACMPC0;                            /* PRACMP Control 0 Register; 0x00000035 */
volatile PRACMPC1STR _PRACMPC1;                            /* PRACMP Control 1 Register; 0x00000036 */
volatile PRACMPC2STR _PRACMPC2;                            /* PRACMP Control 2 Register; 0x00000037 */
volatile MCGC1STR _MCGC1;                                  /* MCG Control Register 1; 0x00000038 */
volatile MCGC2STR _MCGC2;                                  /* MCG Control Register 2; 0x00000039 */
volatile MCGTRMSTR _MCGTRM;                                /* MCG Trim Register; 0x0000003A */
volatile MCGSCSTR _MCGSC;                                  /* MCG Status and Control Register; 0x0000003B */
volatile MCGC3STR _MCGC3;                                  /* MCG Control Register 3; 0x0000003C */
volatile MCGC4STR _MCGC4;                                  /* MCG Control Register 4; 0x0000003D */
volatile ADCSC1ASTR _ADCSC1A;                              /* Status and Control Register 1A; 0x00000040 */
volatile ADCSC1BSTR _ADCSC1B;                              /* Status and Control Register 1B; 0x00000041 */
volatile ADCSC1CSTR _ADCSC1C;                              /* Status and Control Register 1C; 0x00000042 */
volatile ADCSC1DSTR _ADCSC1D;                              /* Status and Control Register 1D; 0x00000043 */
volatile ADCSC1ESTR _ADCSC1E;                              /* Status and Control Register 1E; 0x00000044 */
volatile ADCSC1FSTR _ADCSC1F;                              /* Status and Control Register 1F; 0x00000045 */
volatile ADCSC1GSTR _ADCSC1G;                              /* Status and Control Register 1G; 0x00000046 */
volatile ADCSC1HSTR _ADCSC1H;                              /* Status and Control Register 1H; 0x00000047 */
volatile ADCCFG1STR _ADCCFG1;                              /* Configuration Register 1; 0x00000048 */
volatile ADCCFG2STR _ADCCFG2;                              /* Configuration Register 2; 0x00000049 */
volatile VREFTRMSTR _VREFTRM;                              /* VREF Trim Register; 0x0000005C */
volatile VREFSCSTR _VREFSC;                                /* VREF Control Register; 0x0000005D */
volatile IRQSCSTR _IRQSC;                                  /* Interrupt request status and control register; 0x0000005F */
volatile IICA1STR _IICA1;                                  /* IIC Address Register; 0x00000060 */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0x00000061 */
volatile IICC1STR _IICC1;                                  /* IIC Control Register 1; 0x00000062 */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0x00000063 */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0x00000064 */
volatile IICC2STR _IICC2;                                  /* IIC Control Register 2; 0x00000065 */
volatile IICSMBSTR _IICSMB;                                /* SMBus Control and Status Register; 0x00000066 */
volatile IICA2STR _IICA2;                                  /* IIC Address Register 2; 0x00000067 */
volatile IICFLTSTR _IICFLT;                                /* IIC Filter register; 0x0000006A */
volatile KBI1SCSTR _KBI1SC;                                /* KBI1 Status and Control Register; 0x0000006C */
volatile KBI1PESTR _KBI1PE;                                /* KBI1 Pin Enable Register; 0x0000006D */
volatile KBI1ESSTR _KBI1ES;                                /* KBI1 Edge Select Register; 0x0000006E */
volatile SPI1C1STR _SPI1C1;                                /* SPI1 Control Register 1; 0x00000070 */
volatile SPI1C2STR _SPI1C2;                                /* SPI1 Control Register 2; 0x00000071 */
volatile SPI1BRSTR _SPI1BR;                                /* SPI1 Baud Rate Register; 0x00000072 */
volatile SPI1SSTR _SPI1S;                                  /* SPI1 Status Register; 0x00000073 */
volatile SPI1C3STR _SPI1C3;                                /* SPI1 Control Register 3; 0x00000078 */
volatile SPI1CISTR _SPI1CI;                                /* SPI1 Clear Interrupt Register; 0x00000079 */
volatile KBI2SCSTR _KBI2SC;                                /* KBI2 Status and Control Register; 0x0000007C */
volatile KBI2PESTR _KBI2PE;                                /* KBI2 Pin Enable Register; 0x0000007D */
volatile KBI2ESSTR _KBI2ES;                                /* KBI2 Edge Select Register; 0x0000007E */
volatile USBCTL0STR _USBCTL0;                              /* USB Control Register 0; 0x00000080 */
volatile PERIDSTR _PERID;                                  /* Peripheral ID Register; 0x00000088 */
volatile IDCOMPSTR _IDCOMP;                                /* Peripheral ID Complement Register; 0x00000089 */
volatile REVSTR _REV;                                      /* Peripheral Revision Register; 0x0000008A */
volatile INTSTATSTR _INTSTAT;                              /* Interrupt Status Register; 0x00000090 */
volatile INTENBSTR _INTENB;                                /* Interrupt Enable Register; 0x00000091 */
volatile ERRSTATSTR _ERRSTAT;                              /* Error Interrupt Status Register; 0x00000092 */
volatile ERRENBSTR _ERRENB;                                /* Error Interrupt Enable Register; 0x00000093 */
volatile STATSTR _STAT;                                    /* Status Register; 0x00000094 */
volatile CTLSTR _CTL;                                      /* Control Register; 0x00000095 */
volatile ADDRSTR _ADDR;                                    /* Address Register; 0x00000096 */
volatile FRMNUMLSTR _FRMNUML;                              /* Frame Number Register Low; 0x00000097 */
volatile FRMNUMHSTR _FRMNUMH;                              /* Frame Number Register High; 0x00000098 */
volatile EPCTL0STR _EPCTL0;                                /* Endpoint Control Register 0; 0x0000009D */
volatile EPCTL1STR _EPCTL1;                                /* Endpoint Control Register 1; 0x0000009E */
volatile EPCTL2STR _EPCTL2;                                /* Endpoint Control Register 2; 0x0000009F */
volatile EPCTL3STR _EPCTL3;                                /* Endpoint Control Register 3; 0x000000A0 */
volatile EPCTL4STR _EPCTL4;                                /* Endpoint Control Register 4; 0x000000A1 */
volatile EPCTL5STR _EPCTL5;                                /* Endpoint Control Register 5; 0x000000A2 */
volatile EPCTL6STR _EPCTL6;                                /* Endpoint Control Register 6; 0x000000A3 */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SOPT1STR _SOPT1;                                  /* System Options Register 1; 0x00001802 */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0x00001803 */
volatile SCGC1STR _SCGC1;                                  /* System Clock Gating Control 1 Register; 0x00001808 */
volatile SCGC2STR _SCGC2;                                  /* System Clock Gating Control 2 Register; 0x00001809 */
volatile SCGC3STR _SCGC3;                                  /* System Clock Gating Control 3 Register; 0x0000180A */
volatile SOPT3STR _SOPT3;                                  /* System Options 3 Register; 0x0000180B */
volatile SOPT4STR _SOPT4;                                  /* System Options 4 Register; 0x0000180C */
volatile SIMIPSSTR _SIMIPS;                                /* SIM Internal Peripheral Select Register; 0x0000180E */
volatile SIGNATURESTR _SIGNATURE;                          /* SIGNATURE Register; 0x0000180F */
volatile CCSCTRLSTR _CCSCTRL;                              /* Clock Check & Select Control; 0x00001810 */
volatile CCSTMR1STR _CCSTMR1;                              /* CCS XOSC1 Timer Register; 0x00001811 */
volatile CCSTMR2STR _CCSTMR2;                              /* CCS XOSC2 Timer Register; 0x00001812 */
volatile CCSTMRIRSTR _CCSTMRIR;                            /* CCS Internal Reference Clock Timer Register; 0x00001813 */
volatile FPROTDSTR _FPROTD;                                /* Flash Protection Disable Register; 0x00001814 */
volatile SIMCOSTR _SIMCO;                                  /* SIM Clock Set and Select Register; 0x00001819 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x0000181C */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x0000181D */
volatile SPMSC3STR _SPMSC3;                                /* System Power Management Status and Control 3 Register; 0x0000181F */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0x00001820 */
volatile FOPTSTR _FOPT;                                    /* Flash Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* Flash Command Register; 0x00001826 */
volatile PTEDSTR _PTED;                                    /* Port E Data Register; 0x00001830 */
volatile PTEDDSTR _PTEDD;                                  /* Port E Data Direction Register; 0x00001831 */
volatile PTFDSTR _PTFD;                                    /* Port F Data Register; 0x00001832 */
volatile PTFDDSTR _PTFDD;                                  /* Port F Data Direction Register; 0x00001833 */
volatile SCI2C1STR _SCI2C1;                                /* SCI2 Control Register 1; 0x0000183A */
volatile SCI2C2STR _SCI2C2;                                /* SCI2 Control Register 2; 0x0000183B */
volatile SCI2S1STR _SCI2S1;                                /* SCI2 Status Register 1; 0x0000183C */
volatile SCI2S2STR _SCI2S2;                                /* SCI2 Status Register 2; 0x0000183D */
volatile SCI2C3STR _SCI2C3;                                /* SCI2 Control Register 3; 0x0000183E */
volatile SCI2DSTR _SCI2D;                                  /* SCI2 Data Register; 0x0000183F */
volatile SPI2C1STR _SPI2C1;                                /* SPI2 Control Register 1; 0x00001840 */
volatile SPI2C2STR _SPI2C2;                                /* SPI2 Control Register 2; 0x00001841 */
volatile SPI2BRSTR _SPI2BR;                                /* SPI2 Baud Rate Register; 0x00001842 */
volatile SPI2SSTR _SPI2S;                                  /* SPI2 Status Register; 0x00001843 */
volatile SPI2DSTR _SPI2D;                                  /* SPI2 Data Register; 0x00001845 */
volatile SPI2MSTR _SPI2M;                                  /* SPI2 Match Register; 0x00001847 */
volatile PTGDSTR _PTGD;                                    /* Port G Data Register; 0x00001848 */
volatile PTGDDSTR _PTGDD;                                  /* Port G Data Direction Register; 0x00001849 */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0x00001850 */
volatile PTASESTR _PTASE;                                  /* Port A Slew Rate Enable Register; 0x00001851 */
volatile PTADSSTR _PTADS;                                  /* Port A Drive Strength Selection Register; 0x00001852 */
volatile PTAIFESTR _PTAIFE;                                /* Port A Input Filter Enable Register; 0x00001853 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0x00001854 */
volatile PTBSESTR _PTBSE;                                  /* Port B Slew Rate Enable Register; 0x00001855 */
volatile PTBDSSTR _PTBDS;                                  /* Port B Drive Strength Selection Register; 0x00001856 */
volatile PTBIFESTR _PTBIFE;                                /* Port B Input Filter Enable Register; 0x00001857 */
volatile PTCPESTR _PTCPE;                                  /* Port C Pull Enable Register; 0x00001858 */
volatile PTCSESTR _PTCSE;                                  /* Port C Slew Rate Enable Register; 0x00001859 */
volatile PTCDSSTR _PTCDS;                                  /* Port C Drive Strength Selection Register; 0x0000185A */
volatile PTCIFESTR _PTCIFE;                                /* Port C Input Filter Enable Register; 0x0000185B */
volatile PTDPESTR _PTDPE;                                  /* Port D Pull Enable Register; 0x0000185C */
volatile PTDSESTR _PTDSE;                                  /* Port D Slew Rate Enable Register; 0x0000185D */
volatile PTDDSSTR _PTDDS;                                  /* Port D Drive Strength Selection Register; 0x0000185E */
volatile PTDIFESTR _PTDIFE;                                /* Port D Input Filter Enable Register; 0x0000185F */
volatile PTEPESTR _PTEPE;                                  /* Port E Pull Enable Register; 0x00001860 */
volatile PTESESTR _PTESE;                                  /* Port E Slew Rate Enable Register; 0x00001861 */
volatile PTEDSSTR _PTEDS;                                  /* Port E Drive Strength Selection Register; 0x00001862 */
volatile PTEIFESTR _PTEIFE;                                /* Port E Input Filter Enable Register; 0x00001863 */
volatile PTFPESTR _PTFPE;                                  /* Port F Pull Enable Register; 0x00001864 */
volatile PTFSESTR _PTFSE;                                  /* Port F Slew Rate Enable Register; 0x00001865 */
volatile PTFDSSTR _PTFDS;                                  /* Port F Drive Strength Selection Register; 0x00001866 */
volatile PTFIFESTR _PTFIFE;                                /* Port F Input Filter Enable Register; 0x00001867 */
volatile PTGPESTR _PTGPE;                                  /* Port G Pull Enable Register; 0x00001868 */
volatile PTGSESTR _PTGSE;                                  /* Port G Slew Rate Enable Register; 0x00001869 */
volatile PTGDSSTR _PTGDS;                                  /* Port G Drive Strength Selection Register; 0x0000186A */
volatile PTGIFESTR _PTGIFE;                                /* Port G Input Filter Enable Register; 0x0000186B */
volatile TIAMP1C0STR _TIAMP1C0;                            /* TIAMP1 Control Register 0; 0x0000186C */
volatile TIAMP2C0STR _TIAMP2C0;                            /* TIAMP2 Control Register 0; 0x0000186E */
volatile CMTOCSTR _CMTOC;                                  /* CMT Output Control Register; 0x00001874 */
volatile CMTMSCSTR _CMTMSC;                                /* CMT Modulator Status and Control Register; 0x00001875 */
volatile GPAMP1C0STR _GPAMP1C0;                            /* GPAMP1 Control Register 0; 0x0000187C */
volatile GPAMP1C1STR _GPAMP1C1;                            /* GPAMP1 Control Register 1; 0x0000187D */
volatile GPAMP1C2STR _GPAMP1C2;                            /* GPAMP1 Control Register 2; 0x0000187E */
volatile DBGCAXSTR _DBGCAX;                                /* Debug Comparator A Extension Register; 0x00001888 */
volatile DBGCBXSTR _DBGCBX;                                /* Debug Comparator B Extension Register; 0x00001889 */
volatile DBGCCXSTR _DBGCCX;                                /* Debug Comparator C Extension Register; 0x0000188A */
volatile DBGFXSTR _DBGFX;                                  /* Debug FIFO Extended Information Register; 0x0000188B */
volatile DBGCSTR _DBGC;                                    /* Debug Control Register; 0x0000188C */
volatile DBGTSTR _DBGT;                                    /* Debug Trigger Register; 0x0000188D */
volatile DBGSSTR _DBGS;                                    /* Debug Status Register; 0x0000188E */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Status Register; 0x0000188F */
volatile CRCHSTR _CRCH;                                    /* CRC High Register; 0x00001890 */
volatile CRCLSTR _CRCL;                                    /* CRC Low Register; 0x00001891 */
volatile TRANSPOSESTR _TRANSPOSE;                          /* CRC Transpose Register; 0x00001892 */
volatile GPAMP2C0STR _GPAMP2C0;                            /* GPAMP2 Control Register 0; 0x00001898 */
volatile GPAMP2C1STR _GPAMP2C1;                            /* GPAMP2 Control Register 1; 0x00001899 */
volatile GPAMP2C2STR _GPAMP2C2;                            /* GPAMP2 Control Register 2; 0x0000189A */
volatile TODCSTR _TODC;                                    /* TOD Control Register; 0x0000189C */
volatile TODSCSTR _TODSC;                                  /* TOD Status and Control Register; 0x0000189D */
volatile TODMSTR _TODM;                                    /* TOD Match Register; 0x0000189E */
volatile TODCNTSTR _TODCNT;                                /* TOD Counter Register; 0x0000189F */
volatile TPM2SCSTR _TPM2SC;                                /* TPM2 Status and Control Register; 0x000018A0 */
volatile TPM2C0SCSTR _TPM2C0SC;                            /* TPM2 Timer Channel 0 Status and Control Register; 0x000018A5 */
volatile TPM2C1SCSTR _TPM2C1SC;                            /* TPM2 Timer Channel 1 Status and Control Register; 0x000018A8 */
volatile TPM2C2SCSTR _TPM2C2SC;                            /* TPM2 Timer Channel 2 Status and Control Register; 0x000018AB */
volatile TPM2C3SCSTR _TPM2C3SC;                            /* TPM2 Timer Channel 3 Status and Control Register; 0x000018AE */
volatile SCI1C1STR _SCI1C1;                                /* SCI1 Control Register 1; 0x000018BA */
volatile SCI1C2STR _SCI1C2;                                /* SCI1 Control Register 2; 0x000018BB */
volatile SCI1S1STR _SCI1S1;                                /* SCI1 Status Register 1; 0x000018BC */
volatile SCI1S2STR _SCI1S2;                                /* SCI1 Status Register 2; 0x000018BD */
volatile SCI1C3STR _SCI1C3;                                /* SCI1 Control Register 3; 0x000018BE */
volatile SCI1DSTR _SCI1D;                                  /* SCI1 Data Register; 0x000018BF */
volatile PDBSCSTR _PDBSC;                                  /* PDB Status and Control Register; 0x000018C0 */
volatile PDBC1STR _PDBC1;                                  /* PDB Control Register 1; 0x000018C1 */
volatile PDBC2STR _PDBC2;                                  /* PDB Control Register 2; 0x000018C2 */
volatile PDBCHENSTR _PDBCHEN;                              /* PDB Channel Enable; 0x000018C3 */
volatile TPM1SCSTR _TPM1SC;                                /* TPM1 Status and Control Register; 0x000018E0 */
volatile TPM1C0SCSTR _TPM1C0SC;                            /* TPM1 Timer Channel 0 Status and Control Register; 0x000018E5 */
volatile TPM1C1SCSTR _TPM1C1SC;                            /* TPM1 Timer Channel 1 Status and Control Register; 0x000018E8 */
volatile TPM1C2SCSTR _TPM1C2SC;                            /* TPM1 Timer Channel 2 Status and Control Register; 0x000018EB */
volatile TPM1C3SCSTR _TPM1C3SC;                            /* TPM1 Timer Channel 3 Status and Control Register; 0x000018EE */
volatile ADCSC2STR _ADCSC2;                                /* Status and Control Register 2; 0x000018FC */
volatile ADCSC3STR _ADCSC3;                                /* Status and Control Register 3; 0x000018FD */
volatile ADCCLPDSTR _ADCCLPD;                              /* Plus-Side General Calibration Value D Register; 0x00001904 */
volatile ADCCLPSSTR _ADCCLPS;                              /* Plus-Side General Calibration Value S Register; 0x00001905 */
volatile ADCCLP2STR _ADCCLP2;                              /* Plus-Side General Calibration Value 2 Register; 0x0000190A */
volatile ADCCLP1STR _ADCCLP1;                              /* Plus-Side General Calibration Value 1 Register; 0x0000190B */
volatile ADCCLP0STR _ADCCLP0;                              /* Plus-Side General Calibration Value 0 Register; 0x0000190C */
volatile ADCCLMDSTR _ADCCLMD;                              /* Minus-Side General Calibration Value D Register; 0x0000190E */
volatile ADCCLMSSTR _ADCCLMS;                              /* Minus-Side General Calibration Value S Register; 0x0000190F */
volatile ADCCLM2STR _ADCCLM2;                              /* Minus-Side General Calibration Value 2 Register; 0x00001914 */
volatile ADCCLM1STR _ADCCLM1;                              /* Minus-Side General Calibration Value 1 Register; 0x00001915 */
volatile ADCCLM0STR _ADCCLM0;                              /* Minus-Side General Calibration Value 0 Register; 0x00001916 */
volatile APCTL1STR _APCTL1;                                /* Pin Control 1 Register; 0x00001917 */
volatile APCTL2STR _APCTL2;                                /* Pin Control 2 Register; 0x00001918 */
/* NVFTRIM - macro for reading non volatile register       Nonvolatile MCG Fine Trim; 0x0000FFAE */
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
/* NVMCGTRM - macro for reading non volatile register      Nonvolatile MCG Trim Register; 0x0000FFAF */
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT @0x0000FFAF = <NVMCGTRM_INITVAL>; */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* CHKSBYP - macro for reading non volatile register       Checksum Bypass Register; 0x0000FFBA */
/* Tip for register initialization in the user code:  const byte CHKSBYP_INIT @0x0000FFBA = <CHKSBYP_INITVAL>; */
/* Partial_Erase_Semaphore - macro for reading non volatile register Flash partial erase semaphore; 0x0000FFBC */
/* Tip for register initialization in the user code:  const byte Partial_Erase_Semaphore_INIT @0x0000FFBC = <Partial_Erase_Semaphore_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile Flash Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile DACDAT0STR _DACDAT0;                              /* DAC Data 0 Register; 0x00000010 */
volatile DACDAT1STR _DACDAT1;                              /* DAC Data 1 Register; 0x00000012 */
volatile DACDAT2STR _DACDAT2;                              /* DAC Data 2 Register; 0x00000014 */
volatile DACDAT3STR _DACDAT3;                              /* DAC Data 3 Register; 0x00000016 */
volatile DACDAT4STR _DACDAT4;                              /* DAC Data 4 Register; 0x00000018 */
volatile DACDAT5STR _DACDAT5;                              /* DAC Data 5 Register; 0x0000001A */
volatile DACDAT6STR _DACDAT6;                              /* DAC Data 6 Register; 0x0000001C */
volatile DACDAT7STR _DACDAT7;                              /* DAC Data 7 Register; 0x0000001E */
volatile DACDAT8STR _DACDAT8;                              /* DAC Data 8 Register; 0x00000020 */
volatile DACDAT9STR _DACDAT9;                              /* DAC Data 9 Register; 0x00000022 */
volatile DACDAT10STR _DACDAT10;                            /* DAC Data 10 Register; 0x00000024 */
volatile DACDAT11STR _DACDAT11;                            /* DAC Data 11 Register; 0x00000026 */
volatile DACDAT12STR _DACDAT12;                            /* DAC Data 12 Register; 0x00000028 */
volatile DACDAT13STR _DACDAT13;                            /* DAC Data 13 Register; 0x0000002A */
volatile DACDAT14STR _DACDAT14;                            /* DAC Data 14 Register; 0x0000002C */
volatile DACDAT15STR _DACDAT15;                            /* DAC Data 15 Register; 0x0000002E */
volatile ADCRASTR _ADCRA;                                  /* Data Result Register A; 0x0000004A */
volatile ADCRBSTR _ADCRB;                                  /* Data Result Register B; 0x0000004C */
volatile ADCRCSTR _ADCRC;                                  /* Data Result Register C; 0x0000004E */
volatile ADCRDSTR _ADCRD;                                  /* Data Result Register D; 0x00000050 */
volatile ADCRESTR _ADCRE;                                  /* Data Result Register E; 0x00000052 */
volatile ADCRFSTR _ADCRF;                                  /* Data Result Register F; 0x00000054 */
volatile ADCRGSTR _ADCRG;                                  /* Data Result Register G; 0x00000056 */
volatile ADCRHSTR _ADCRH;                                  /* Data Result Register H; 0x00000058 */
volatile IICSLTSTR _IICSLT;                                /* IIC SCL Low Time Out register; 0x00000068 */
volatile SPI1D16STR _SPI1D16;                              /* SPI1 Data Register; 0x00000074 */
volatile SPI1MSTR _SPI1M;                                  /* SPI1 Match Register; 0x00000076 */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0x00001806 */
volatile SCI2BDSTR _SCI2BD;                                /* SCI2 Baud Rate Register; 0x00001838 */
volatile CMTCG1STR _CMTCG1;                                /* Carrier Generator Data Register 1; 0x00001870 */
volatile CMTCG2STR _CMTCG2;                                /* Carrier Generator Data Register 2; 0x00001872 */
volatile CMTCMD12STR _CMTCMD12;                            /* CMT Modulator Data Register 12; 0x00001876 */
volatile CMTCMD34STR _CMTCMD34;                            /* CMT Modulator Data Register 34; 0x00001878 */
volatile DBGCASTR _DBGCA;                                  /* Debug Comparator A Register; 0x00001880 */
volatile DBGCBSTR _DBGCB;                                  /* Debug Comparator B Register; 0x00001882 */
volatile DBGCCSTR _DBGCC;                                  /* Debug Comparator C Register; 0x00001884 */
volatile DBGFSTR _DBGF;                                    /* Debug FIFO Register; 0x00001886 */
volatile TPM2CNTSTR _TPM2CNT;                              /* TPM2 Timer Counter Register; 0x000018A1 */
volatile TPM2MODSTR _TPM2MOD;                              /* TPM2 Timer Counter Modulo Register; 0x000018A3 */
volatile TPM2C0VSTR _TPM2C0V;                              /* TPM2 Timer Channel 0 Value Register; 0x000018A6 */
volatile TPM2C1VSTR _TPM2C1V;                              /* TPM2 Timer Channel 1 Value Register; 0x000018A9 */
volatile TPM2C2VSTR _TPM2C2V;                              /* TPM2 Timer Channel 2 Value Register; 0x000018AC */
volatile TPM2C3VSTR _TPM2C3V;                              /* TPM2 Timer Channel 3 Value Register; 0x000018AF */
volatile SCI1BDSTR _SCI1BD;                                /* SCI1 Baud Rate Register; 0x000018B8 */
volatile PDBMODSTR _PDBMOD;                                /* PDB Modulus Register; 0x000018C4 */
volatile PDBCNTSTR _PDBCNT;                                /* PDB Counter Register; 0x000018C6 */
volatile PDBIDLYSTR _PDBIDLY;                              /* PDB Interrupt Delay Register; 0x000018C8 */
volatile DACINTSTR _DACINT;                                /* DAC Trigger Interval Register; 0x000018CA */
volatile PDBDLYASTR _PDBDLYA;                              /* PDB Delay A Register; 0x000018CC */
volatile PDBDLYBSTR _PDBDLYB;                              /* PDB Delay B Register; 0x000018CE */
volatile PDBDLYCSTR _PDBDLYC;                              /* PDB Delay C Register; 0x000018D0 */
volatile PDBDLYDSTR _PDBDLYD;                              /* PDB Delay D Register; 0x000018D2 */
volatile PDBDLYESTR _PDBDLYE;                              /* PDB Delay E Register; 0x000018D4 */
volatile PDBDLYFSTR _PDBDLYF;                              /* PDB Delay F Register; 0x000018D6 */
volatile PDBDLYGSTR _PDBDLYG;                              /* PDB Delay G Register; 0x000018D8 */
volatile PDBDLYHSTR _PDBDLYH;                              /* PDB Delay H Register; 0x000018DA */
volatile TPM1CNTSTR _TPM1CNT;                              /* TPM1 Timer Counter Register; 0x000018E1 */
volatile TPM1MODSTR _TPM1MOD;                              /* TPM1 Timer Counter Modulo Register; 0x000018E3 */
volatile TPM1C0VSTR _TPM1C0V;                              /* TPM1 Timer Channel 0 Value Register; 0x000018E6 */
volatile TPM1C1VSTR _TPM1C1V;                              /* TPM1 Timer Channel 1 Value Register; 0x000018E9 */
volatile TPM1C2VSTR _TPM1C2V;                              /* TPM1 Timer Channel 2 Value Register; 0x000018EC */
volatile TPM1C3VSTR _TPM1C3V;                              /* TPM1 Timer Channel 3 Value Register; 0x000018EF */
volatile ADCCV1STR _ADCCV1;                                /* Compare Value 1 Register; 0x000018F8 */
volatile ADCCV2STR _ADCCV2;                                /* Compare Value 2 Register; 0x000018FA */
volatile ADCOFSSTR _ADCOFS;                                /* Offset Correction Register; 0x000018FE */
volatile ADCPGSTR _ADCPG;                                  /* Plus-Side Gain Register; 0x00001900 */
volatile ADCMGSTR _ADCMG;                                  /* Minus-Side Gain Register; 0x00001902 */
volatile ADCCLP4STR _ADCCLP4;                              /* Plus-Side General Calibration Value 4 Register; 0x00001906 */
volatile ADCCLP3STR _ADCCLP3;                              /* Plus-Side General Calibration Value 3 Register; 0x00001908 */
volatile ADCCLM4STR _ADCCLM4;                              /* Minus-Side General Calibration Value 4 Register; 0x00001910 */
volatile ADCCLM3STR _ADCCLM3;                              /* Minus-Side General Calibration Value 3 Register; 0x00001912 */
/* FCHKS - macro for reading non volatile register         Flash Checksum Register; 0x0000FFB8 */
/* Tip for register initialization in the user code:  const byte FCHKS_INIT @0x0000FFB8 = <FCHKS_INITVAL>; */

/*lint -restore */

/* EOF */
