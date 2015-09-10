/*******************************************************************************
* File Name: UsPWM.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_UsPWM_H)
#define CY_PWM_UsPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 UsPWM_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define UsPWM_Resolution                     (16u)
#define UsPWM_UsingFixedFunction             (0u)
#define UsPWM_DeadBandMode                   (0u)
#define UsPWM_KillModeMinTime                (0u)
#define UsPWM_KillMode                       (0u)
#define UsPWM_PWMMode                        (0u)
#define UsPWM_PWMModeIsCenterAligned         (0u)
#define UsPWM_DeadBandUsed                   (0u)
#define UsPWM_DeadBand2_4                    (0u)

#if !defined(UsPWM_PWMUDB_genblk8_stsreg__REMOVED)
    #define UsPWM_UseStatus                  (1u)
#else
    #define UsPWM_UseStatus                  (0u)
#endif /* !defined(UsPWM_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(UsPWM_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define UsPWM_UseControl                 (1u)
#else
    #define UsPWM_UseControl                 (0u)
#endif /* !defined(UsPWM_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define UsPWM_UseOneCompareMode              (1u)
#define UsPWM_MinimumKillTime                (1u)
#define UsPWM_EnableMode                     (0u)

#define UsPWM_CompareMode1SW                 (0u)
#define UsPWM_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define UsPWM__B_PWM__DISABLED 0
#define UsPWM__B_PWM__ASYNCHRONOUS 1
#define UsPWM__B_PWM__SINGLECYCLE 2
#define UsPWM__B_PWM__LATCHED 3
#define UsPWM__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define UsPWM__B_PWM__DBMDISABLED 0
#define UsPWM__B_PWM__DBM_2_4_CLOCKS 1
#define UsPWM__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define UsPWM__B_PWM__ONE_OUTPUT 0
#define UsPWM__B_PWM__TWO_OUTPUTS 1
#define UsPWM__B_PWM__DUAL_EDGE 2
#define UsPWM__B_PWM__CENTER_ALIGN 3
#define UsPWM__B_PWM__DITHER 5
#define UsPWM__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define UsPWM__B_PWM__LESS_THAN 1
#define UsPWM__B_PWM__LESS_THAN_OR_EQUAL 2
#define UsPWM__B_PWM__GREATER_THAN 3
#define UsPWM__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define UsPWM__B_PWM__EQUAL 0
#define UsPWM__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!UsPWM_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!UsPWM_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!UsPWM_PWMModeIsCenterAligned) */
        #if (UsPWM_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (UsPWM_UseStatus) */

        /* Backup for Deadband parameters */
        #if(UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_256_CLOCKS || \
            UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(UsPWM_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (UsPWM_KillModeMinTime) */

        /* Backup control register */
        #if(UsPWM_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (UsPWM_UseControl) */

    #endif /* (!UsPWM_UsingFixedFunction) */

}UsPWM_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    UsPWM_Start(void) ;
void    UsPWM_Stop(void) ;

#if (UsPWM_UseStatus || UsPWM_UsingFixedFunction)
    void  UsPWM_SetInterruptMode(uint8 interruptMode) ;
    uint8 UsPWM_ReadStatusRegister(void) ;
#endif /* (UsPWM_UseStatus || UsPWM_UsingFixedFunction) */

#define UsPWM_GetInterruptSource() UsPWM_ReadStatusRegister()

#if (UsPWM_UseControl)
    uint8 UsPWM_ReadControlRegister(void) ;
    void  UsPWM_WriteControlRegister(uint8 control)
          ;
#endif /* (UsPWM_UseControl) */

#if (UsPWM_UseOneCompareMode)
   #if (UsPWM_CompareMode1SW)
       void    UsPWM_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (UsPWM_CompareMode1SW) */
#else
    #if (UsPWM_CompareMode1SW)
        void    UsPWM_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (UsPWM_CompareMode1SW) */
    #if (UsPWM_CompareMode2SW)
        void    UsPWM_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (UsPWM_CompareMode2SW) */
#endif /* (UsPWM_UseOneCompareMode) */

#if (!UsPWM_UsingFixedFunction)
    uint16   UsPWM_ReadCounter(void) ;
    uint16 UsPWM_ReadCapture(void) ;

    #if (UsPWM_UseStatus)
            void UsPWM_ClearFIFO(void) ;
    #endif /* (UsPWM_UseStatus) */

    void    UsPWM_WriteCounter(uint16 counter)
            ;
#endif /* (!UsPWM_UsingFixedFunction) */

void    UsPWM_WritePeriod(uint16 period)
        ;
uint16 UsPWM_ReadPeriod(void) ;

#if (UsPWM_UseOneCompareMode)
    void    UsPWM_WriteCompare(uint16 compare)
            ;
    uint16 UsPWM_ReadCompare(void) ;
#else
    void    UsPWM_WriteCompare1(uint16 compare)
            ;
    uint16 UsPWM_ReadCompare1(void) ;
    void    UsPWM_WriteCompare2(uint16 compare)
            ;
    uint16 UsPWM_ReadCompare2(void) ;
#endif /* (UsPWM_UseOneCompareMode) */


#if (UsPWM_DeadBandUsed)
    void    UsPWM_WriteDeadTime(uint8 deadtime) ;
    uint8   UsPWM_ReadDeadTime(void) ;
#endif /* (UsPWM_DeadBandUsed) */

#if ( UsPWM_KillModeMinTime)
    void UsPWM_WriteKillTime(uint8 killtime) ;
    uint8 UsPWM_ReadKillTime(void) ;
#endif /* ( UsPWM_KillModeMinTime) */

void UsPWM_Init(void) ;
void UsPWM_Enable(void) ;
void UsPWM_Sleep(void) ;
void UsPWM_Wakeup(void) ;
void UsPWM_SaveConfig(void) ;
void UsPWM_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define UsPWM_INIT_PERIOD_VALUE          (65535u)
#define UsPWM_INIT_COMPARE_VALUE1        (60u)
#define UsPWM_INIT_COMPARE_VALUE2        (63u)
#define UsPWM_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    UsPWM_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    UsPWM_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    UsPWM_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    UsPWM_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define UsPWM_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  UsPWM_CTRL_CMPMODE2_SHIFT)
#define UsPWM_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  UsPWM_CTRL_CMPMODE1_SHIFT)
#define UsPWM_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (UsPWM_UsingFixedFunction)
   #define UsPWM_PERIOD_LSB              (*(reg16 *) UsPWM_PWMHW__PER0)
   #define UsPWM_PERIOD_LSB_PTR          ( (reg16 *) UsPWM_PWMHW__PER0)
   #define UsPWM_COMPARE1_LSB            (*(reg16 *) UsPWM_PWMHW__CNT_CMP0)
   #define UsPWM_COMPARE1_LSB_PTR        ( (reg16 *) UsPWM_PWMHW__CNT_CMP0)
   #define UsPWM_COMPARE2_LSB            (0x00u)
   #define UsPWM_COMPARE2_LSB_PTR        (0x00u)
   #define UsPWM_COUNTER_LSB             (*(reg16 *) UsPWM_PWMHW__CNT_CMP0)
   #define UsPWM_COUNTER_LSB_PTR         ( (reg16 *) UsPWM_PWMHW__CNT_CMP0)
   #define UsPWM_CAPTURE_LSB             (*(reg16 *) UsPWM_PWMHW__CAP0)
   #define UsPWM_CAPTURE_LSB_PTR         ( (reg16 *) UsPWM_PWMHW__CAP0)
   #define UsPWM_RT1                     (*(reg8 *)  UsPWM_PWMHW__RT1)
   #define UsPWM_RT1_PTR                 ( (reg8 *)  UsPWM_PWMHW__RT1)

#else
   #if (UsPWM_Resolution == 8u) /* 8bit - PWM */

       #if(UsPWM_PWMModeIsCenterAligned)
           #define UsPWM_PERIOD_LSB      (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define UsPWM_PERIOD_LSB_PTR  ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define UsPWM_PERIOD_LSB      (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define UsPWM_PERIOD_LSB_PTR  ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (UsPWM_PWMModeIsCenterAligned) */

       #define UsPWM_COMPARE1_LSB        (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define UsPWM_COMPARE1_LSB_PTR    ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define UsPWM_COMPARE2_LSB        (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define UsPWM_COMPARE2_LSB_PTR    ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define UsPWM_COUNTERCAP_LSB      (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define UsPWM_COUNTERCAP_LSB_PTR  ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define UsPWM_COUNTER_LSB         (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define UsPWM_COUNTER_LSB_PTR     ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define UsPWM_CAPTURE_LSB         (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define UsPWM_CAPTURE_LSB_PTR     ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(UsPWM_PWMModeIsCenterAligned)
               #define UsPWM_PERIOD_LSB      (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define UsPWM_PERIOD_LSB_PTR  ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define UsPWM_PERIOD_LSB      (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define UsPWM_PERIOD_LSB_PTR  ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (UsPWM_PWMModeIsCenterAligned) */

            #define UsPWM_COMPARE1_LSB       (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define UsPWM_COMPARE1_LSB_PTR   ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define UsPWM_COMPARE2_LSB       (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define UsPWM_COMPARE2_LSB_PTR   ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define UsPWM_COUNTERCAP_LSB     (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define UsPWM_COUNTERCAP_LSB_PTR ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define UsPWM_COUNTER_LSB        (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define UsPWM_COUNTER_LSB_PTR    ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define UsPWM_CAPTURE_LSB        (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define UsPWM_CAPTURE_LSB_PTR    ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(UsPWM_PWMModeIsCenterAligned)
               #define UsPWM_PERIOD_LSB      (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define UsPWM_PERIOD_LSB_PTR  ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define UsPWM_PERIOD_LSB      (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define UsPWM_PERIOD_LSB_PTR  ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (UsPWM_PWMModeIsCenterAligned) */

            #define UsPWM_COMPARE1_LSB       (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define UsPWM_COMPARE1_LSB_PTR   ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define UsPWM_COMPARE2_LSB       (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define UsPWM_COMPARE2_LSB_PTR   ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define UsPWM_COUNTERCAP_LSB     (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define UsPWM_COUNTERCAP_LSB_PTR ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define UsPWM_COUNTER_LSB        (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define UsPWM_COUNTER_LSB_PTR    ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define UsPWM_CAPTURE_LSB        (*(reg16 *) UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define UsPWM_CAPTURE_LSB_PTR    ((reg16 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define UsPWM_AUX_CONTROLDP1          (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define UsPWM_AUX_CONTROLDP1_PTR      ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (UsPWM_Resolution == 8) */

   #define UsPWM_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define UsPWM_AUX_CONTROLDP0          (*(reg8 *)  UsPWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define UsPWM_AUX_CONTROLDP0_PTR      ((reg8 *)   UsPWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (UsPWM_UsingFixedFunction) */

#if(UsPWM_KillModeMinTime )
    #define UsPWM_KILLMODEMINTIME        (*(reg8 *)  UsPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define UsPWM_KILLMODEMINTIME_PTR    ((reg8 *)   UsPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (UsPWM_KillModeMinTime ) */

#if(UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_256_CLOCKS)
    #define UsPWM_DEADBAND_COUNT         (*(reg8 *)  UsPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define UsPWM_DEADBAND_COUNT_PTR     ((reg8 *)   UsPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define UsPWM_DEADBAND_LSB_PTR       ((reg8 *)   UsPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define UsPWM_DEADBAND_LSB           (*(reg8 *)  UsPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (UsPWM_UsingFixedFunction)
        #define UsPWM_DEADBAND_COUNT         (*(reg8 *)  UsPWM_PWMHW__CFG0)
        #define UsPWM_DEADBAND_COUNT_PTR     ((reg8 *)   UsPWM_PWMHW__CFG0)
        #define UsPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << UsPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define UsPWM_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define UsPWM_DEADBAND_COUNT         (*(reg8 *)  UsPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define UsPWM_DEADBAND_COUNT_PTR     ((reg8 *)   UsPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define UsPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << UsPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define UsPWM_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (UsPWM_UsingFixedFunction) */
#endif /* (UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_256_CLOCKS) */



#if (UsPWM_UsingFixedFunction)
    #define UsPWM_STATUS                 (*(reg8 *) UsPWM_PWMHW__SR0)
    #define UsPWM_STATUS_PTR             ((reg8 *) UsPWM_PWMHW__SR0)
    #define UsPWM_STATUS_MASK            (*(reg8 *) UsPWM_PWMHW__SR0)
    #define UsPWM_STATUS_MASK_PTR        ((reg8 *) UsPWM_PWMHW__SR0)
    #define UsPWM_CONTROL                (*(reg8 *) UsPWM_PWMHW__CFG0)
    #define UsPWM_CONTROL_PTR            ((reg8 *) UsPWM_PWMHW__CFG0)
    #define UsPWM_CONTROL2               (*(reg8 *) UsPWM_PWMHW__CFG1)
    #define UsPWM_CONTROL3               (*(reg8 *) UsPWM_PWMHW__CFG2)
    #define UsPWM_GLOBAL_ENABLE          (*(reg8 *) UsPWM_PWMHW__PM_ACT_CFG)
    #define UsPWM_GLOBAL_ENABLE_PTR      ( (reg8 *) UsPWM_PWMHW__PM_ACT_CFG)
    #define UsPWM_GLOBAL_STBY_ENABLE     (*(reg8 *) UsPWM_PWMHW__PM_STBY_CFG)
    #define UsPWM_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) UsPWM_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define UsPWM_BLOCK_EN_MASK          (UsPWM_PWMHW__PM_ACT_MSK)
    #define UsPWM_BLOCK_STBY_EN_MASK     (UsPWM_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define UsPWM_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define UsPWM_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define UsPWM_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define UsPWM_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define UsPWM_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define UsPWM_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define UsPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << UsPWM_CTRL_ENABLE_SHIFT)
    #define UsPWM_CTRL_RESET             (uint8)((uint8)0x01u << UsPWM_CTRL_RESET_SHIFT)
    #define UsPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << UsPWM_CTRL_CMPMODE2_SHIFT)
    #define UsPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << UsPWM_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define UsPWM_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define UsPWM_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << UsPWM_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define UsPWM_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define UsPWM_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define UsPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define UsPWM_STATUS_TC_INT_EN_MASK_SHIFT            (UsPWM_STATUS_TC_SHIFT - 4u)
    #define UsPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define UsPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (UsPWM_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define UsPWM_STATUS_TC              (uint8)((uint8)0x01u << UsPWM_STATUS_TC_SHIFT)
    #define UsPWM_STATUS_CMP1            (uint8)((uint8)0x01u << UsPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define UsPWM_STATUS_TC_INT_EN_MASK              (uint8)((uint8)UsPWM_STATUS_TC >> 4u)
    #define UsPWM_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)UsPWM_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define UsPWM_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define UsPWM_RT1_MASK              (uint8)((uint8)0x03u << UsPWM_RT1_SHIFT)
    #define UsPWM_SYNC                  (uint8)((uint8)0x03u << UsPWM_RT1_SHIFT)
    #define UsPWM_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define UsPWM_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << UsPWM_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define UsPWM_SYNCDSI_EN            (uint8)((uint8)0x0Fu << UsPWM_SYNCDSI_SHIFT)


#else
    #define UsPWM_STATUS                (*(reg8 *)   UsPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define UsPWM_STATUS_PTR            ((reg8 *)    UsPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define UsPWM_STATUS_MASK           (*(reg8 *)   UsPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define UsPWM_STATUS_MASK_PTR       ((reg8 *)    UsPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define UsPWM_STATUS_AUX_CTRL       (*(reg8 *)   UsPWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define UsPWM_CONTROL               (*(reg8 *)   UsPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define UsPWM_CONTROL_PTR           ((reg8 *)    UsPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define UsPWM_CTRL_ENABLE_SHIFT      (0x07u)
    #define UsPWM_CTRL_RESET_SHIFT       (0x06u)
    #define UsPWM_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define UsPWM_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define UsPWM_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define UsPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << UsPWM_CTRL_ENABLE_SHIFT)
    #define UsPWM_CTRL_RESET             (uint8)((uint8)0x01u << UsPWM_CTRL_RESET_SHIFT)
    #define UsPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << UsPWM_CTRL_CMPMODE2_SHIFT)
    #define UsPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << UsPWM_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define UsPWM_STATUS_KILL_SHIFT          (0x05u)
    #define UsPWM_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define UsPWM_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define UsPWM_STATUS_TC_SHIFT            (0x02u)
    #define UsPWM_STATUS_CMP2_SHIFT          (0x01u)
    #define UsPWM_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define UsPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (UsPWM_STATUS_KILL_SHIFT)
    #define UsPWM_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (UsPWM_STATUS_FIFONEMPTY_SHIFT)
    #define UsPWM_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (UsPWM_STATUS_FIFOFULL_SHIFT)
    #define UsPWM_STATUS_TC_INT_EN_MASK_SHIFT            (UsPWM_STATUS_TC_SHIFT)
    #define UsPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (UsPWM_STATUS_CMP2_SHIFT)
    #define UsPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (UsPWM_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define UsPWM_STATUS_KILL            (uint8)((uint8)0x00u << UsPWM_STATUS_KILL_SHIFT )
    #define UsPWM_STATUS_FIFOFULL        (uint8)((uint8)0x01u << UsPWM_STATUS_FIFOFULL_SHIFT)
    #define UsPWM_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << UsPWM_STATUS_FIFONEMPTY_SHIFT)
    #define UsPWM_STATUS_TC              (uint8)((uint8)0x01u << UsPWM_STATUS_TC_SHIFT)
    #define UsPWM_STATUS_CMP2            (uint8)((uint8)0x01u << UsPWM_STATUS_CMP2_SHIFT)
    #define UsPWM_STATUS_CMP1            (uint8)((uint8)0x01u << UsPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define UsPWM_STATUS_KILL_INT_EN_MASK            (UsPWM_STATUS_KILL)
    #define UsPWM_STATUS_FIFOFULL_INT_EN_MASK        (UsPWM_STATUS_FIFOFULL)
    #define UsPWM_STATUS_FIFONEMPTY_INT_EN_MASK      (UsPWM_STATUS_FIFONEMPTY)
    #define UsPWM_STATUS_TC_INT_EN_MASK              (UsPWM_STATUS_TC)
    #define UsPWM_STATUS_CMP2_INT_EN_MASK            (UsPWM_STATUS_CMP2)
    #define UsPWM_STATUS_CMP1_INT_EN_MASK            (UsPWM_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define UsPWM_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define UsPWM_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define UsPWM_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define UsPWM_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define UsPWM_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* UsPWM_UsingFixedFunction */

#endif  /* CY_PWM_UsPWM_H */


/* [] END OF FILE */
