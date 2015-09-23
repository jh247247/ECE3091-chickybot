/*******************************************************************************
* File Name: ClockUsPWM.h
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

#if !defined(CY_CLOCK_ClockUsPWM_H)
#define CY_CLOCK_ClockUsPWM_H

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

void ClockUsPWM_Start(void) ;
void ClockUsPWM_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockUsPWM_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockUsPWM_StandbyPower(uint8 state) ;
void ClockUsPWM_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockUsPWM_GetDividerRegister(void) ;
void ClockUsPWM_SetModeRegister(uint8 modeBitMask) ;
void ClockUsPWM_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockUsPWM_GetModeRegister(void) ;
void ClockUsPWM_SetSourceRegister(uint8 clkSource) ;
uint8 ClockUsPWM_GetSourceRegister(void) ;
#if defined(ClockUsPWM__CFG3)
void ClockUsPWM_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockUsPWM_GetPhaseRegister(void) ;
#endif /* defined(ClockUsPWM__CFG3) */

#define ClockUsPWM_Enable()                       ClockUsPWM_Start()
#define ClockUsPWM_Disable()                      ClockUsPWM_Stop()
#define ClockUsPWM_SetDivider(clkDivider)         ClockUsPWM_SetDividerRegister(clkDivider, 1u)
#define ClockUsPWM_SetDividerValue(clkDivider)    ClockUsPWM_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockUsPWM_SetMode(clkMode)               ClockUsPWM_SetModeRegister(clkMode)
#define ClockUsPWM_SetSource(clkSource)           ClockUsPWM_SetSourceRegister(clkSource)
#if defined(ClockUsPWM__CFG3)
#define ClockUsPWM_SetPhase(clkPhase)             ClockUsPWM_SetPhaseRegister(clkPhase)
#define ClockUsPWM_SetPhaseValue(clkPhase)        ClockUsPWM_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockUsPWM__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockUsPWM_CLKEN              (* (reg8 *) ClockUsPWM__PM_ACT_CFG)
#define ClockUsPWM_CLKEN_PTR          ((reg8 *) ClockUsPWM__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockUsPWM_CLKSTBY            (* (reg8 *) ClockUsPWM__PM_STBY_CFG)
#define ClockUsPWM_CLKSTBY_PTR        ((reg8 *) ClockUsPWM__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockUsPWM_DIV_LSB            (* (reg8 *) ClockUsPWM__CFG0)
#define ClockUsPWM_DIV_LSB_PTR        ((reg8 *) ClockUsPWM__CFG0)
#define ClockUsPWM_DIV_PTR            ((reg16 *) ClockUsPWM__CFG0)

/* Clock MSB divider configuration register. */
#define ClockUsPWM_DIV_MSB            (* (reg8 *) ClockUsPWM__CFG1)
#define ClockUsPWM_DIV_MSB_PTR        ((reg8 *) ClockUsPWM__CFG1)

/* Mode and source configuration register */
#define ClockUsPWM_MOD_SRC            (* (reg8 *) ClockUsPWM__CFG2)
#define ClockUsPWM_MOD_SRC_PTR        ((reg8 *) ClockUsPWM__CFG2)

#if defined(ClockUsPWM__CFG3)
/* Analog clock phase configuration register */
#define ClockUsPWM_PHASE              (* (reg8 *) ClockUsPWM__CFG3)
#define ClockUsPWM_PHASE_PTR          ((reg8 *) ClockUsPWM__CFG3)
#endif /* defined(ClockUsPWM__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockUsPWM_CLKEN_MASK         ClockUsPWM__PM_ACT_MSK
#define ClockUsPWM_CLKSTBY_MASK       ClockUsPWM__PM_STBY_MSK

/* CFG2 field masks */
#define ClockUsPWM_SRC_SEL_MSK        ClockUsPWM__CFG2_SRC_SEL_MASK
#define ClockUsPWM_MODE_MASK          (~(ClockUsPWM_SRC_SEL_MSK))

#if defined(ClockUsPWM__CFG3)
/* CFG3 phase mask */
#define ClockUsPWM_PHASE_MASK         ClockUsPWM__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockUsPWM__CFG3) */

#endif /* CY_CLOCK_ClockUsPWM_H */


/* [] END OF FILE */
