/*******************************************************************************
* File Name: ClockUsTimer.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ClockUsTimer_H)
#define CY_CLOCK_ClockUsTimer_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void ClockUsTimer_Start(void) ;
void ClockUsTimer_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockUsTimer_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockUsTimer_StandbyPower(uint8 state) ;
void ClockUsTimer_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockUsTimer_GetDividerRegister(void) ;
void ClockUsTimer_SetModeRegister(uint8 modeBitMask) ;
void ClockUsTimer_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockUsTimer_GetModeRegister(void) ;
void ClockUsTimer_SetSourceRegister(uint8 clkSource) ;
uint8 ClockUsTimer_GetSourceRegister(void) ;
#if defined(ClockUsTimer__CFG3)
void ClockUsTimer_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockUsTimer_GetPhaseRegister(void) ;
#endif /* defined(ClockUsTimer__CFG3) */

#define ClockUsTimer_Enable()                       ClockUsTimer_Start()
#define ClockUsTimer_Disable()                      ClockUsTimer_Stop()
#define ClockUsTimer_SetDivider(clkDivider)         ClockUsTimer_SetDividerRegister(clkDivider, 1u)
#define ClockUsTimer_SetDividerValue(clkDivider)    ClockUsTimer_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockUsTimer_SetMode(clkMode)               ClockUsTimer_SetModeRegister(clkMode)
#define ClockUsTimer_SetSource(clkSource)           ClockUsTimer_SetSourceRegister(clkSource)
#if defined(ClockUsTimer__CFG3)
#define ClockUsTimer_SetPhase(clkPhase)             ClockUsTimer_SetPhaseRegister(clkPhase)
#define ClockUsTimer_SetPhaseValue(clkPhase)        ClockUsTimer_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockUsTimer__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockUsTimer_CLKEN              (* (reg8 *) ClockUsTimer__PM_ACT_CFG)
#define ClockUsTimer_CLKEN_PTR          ((reg8 *) ClockUsTimer__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockUsTimer_CLKSTBY            (* (reg8 *) ClockUsTimer__PM_STBY_CFG)
#define ClockUsTimer_CLKSTBY_PTR        ((reg8 *) ClockUsTimer__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockUsTimer_DIV_LSB            (* (reg8 *) ClockUsTimer__CFG0)
#define ClockUsTimer_DIV_LSB_PTR        ((reg8 *) ClockUsTimer__CFG0)
#define ClockUsTimer_DIV_PTR            ((reg16 *) ClockUsTimer__CFG0)

/* Clock MSB divider configuration register. */
#define ClockUsTimer_DIV_MSB            (* (reg8 *) ClockUsTimer__CFG1)
#define ClockUsTimer_DIV_MSB_PTR        ((reg8 *) ClockUsTimer__CFG1)

/* Mode and source configuration register */
#define ClockUsTimer_MOD_SRC            (* (reg8 *) ClockUsTimer__CFG2)
#define ClockUsTimer_MOD_SRC_PTR        ((reg8 *) ClockUsTimer__CFG2)

#if defined(ClockUsTimer__CFG3)
/* Analog clock phase configuration register */
#define ClockUsTimer_PHASE              (* (reg8 *) ClockUsTimer__CFG3)
#define ClockUsTimer_PHASE_PTR          ((reg8 *) ClockUsTimer__CFG3)
#endif /* defined(ClockUsTimer__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockUsTimer_CLKEN_MASK         ClockUsTimer__PM_ACT_MSK
#define ClockUsTimer_CLKSTBY_MASK       ClockUsTimer__PM_STBY_MSK

/* CFG2 field masks */
#define ClockUsTimer_SRC_SEL_MSK        ClockUsTimer__CFG2_SRC_SEL_MASK
#define ClockUsTimer_MODE_MASK          (~(ClockUsTimer_SRC_SEL_MSK))

#if defined(ClockUsTimer__CFG3)
/* CFG3 phase mask */
#define ClockUsTimer_PHASE_MASK         ClockUsTimer__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockUsTimer__CFG3) */

#endif /* CY_CLOCK_ClockUsTimer_H */


/* [] END OF FILE */
