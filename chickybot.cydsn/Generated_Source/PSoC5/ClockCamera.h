/*******************************************************************************
* File Name: ClockCamera.h
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

#if !defined(CY_CLOCK_ClockCamera_H)
#define CY_CLOCK_ClockCamera_H

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

void ClockCamera_Start(void) ;
void ClockCamera_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockCamera_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockCamera_StandbyPower(uint8 state) ;
void ClockCamera_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockCamera_GetDividerRegister(void) ;
void ClockCamera_SetModeRegister(uint8 modeBitMask) ;
void ClockCamera_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockCamera_GetModeRegister(void) ;
void ClockCamera_SetSourceRegister(uint8 clkSource) ;
uint8 ClockCamera_GetSourceRegister(void) ;
#if defined(ClockCamera__CFG3)
void ClockCamera_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockCamera_GetPhaseRegister(void) ;
#endif /* defined(ClockCamera__CFG3) */

#define ClockCamera_Enable()                       ClockCamera_Start()
#define ClockCamera_Disable()                      ClockCamera_Stop()
#define ClockCamera_SetDivider(clkDivider)         ClockCamera_SetDividerRegister(clkDivider, 1u)
#define ClockCamera_SetDividerValue(clkDivider)    ClockCamera_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockCamera_SetMode(clkMode)               ClockCamera_SetModeRegister(clkMode)
#define ClockCamera_SetSource(clkSource)           ClockCamera_SetSourceRegister(clkSource)
#if defined(ClockCamera__CFG3)
#define ClockCamera_SetPhase(clkPhase)             ClockCamera_SetPhaseRegister(clkPhase)
#define ClockCamera_SetPhaseValue(clkPhase)        ClockCamera_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockCamera__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockCamera_CLKEN              (* (reg8 *) ClockCamera__PM_ACT_CFG)
#define ClockCamera_CLKEN_PTR          ((reg8 *) ClockCamera__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockCamera_CLKSTBY            (* (reg8 *) ClockCamera__PM_STBY_CFG)
#define ClockCamera_CLKSTBY_PTR        ((reg8 *) ClockCamera__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockCamera_DIV_LSB            (* (reg8 *) ClockCamera__CFG0)
#define ClockCamera_DIV_LSB_PTR        ((reg8 *) ClockCamera__CFG0)
#define ClockCamera_DIV_PTR            ((reg16 *) ClockCamera__CFG0)

/* Clock MSB divider configuration register. */
#define ClockCamera_DIV_MSB            (* (reg8 *) ClockCamera__CFG1)
#define ClockCamera_DIV_MSB_PTR        ((reg8 *) ClockCamera__CFG1)

/* Mode and source configuration register */
#define ClockCamera_MOD_SRC            (* (reg8 *) ClockCamera__CFG2)
#define ClockCamera_MOD_SRC_PTR        ((reg8 *) ClockCamera__CFG2)

#if defined(ClockCamera__CFG3)
/* Analog clock phase configuration register */
#define ClockCamera_PHASE              (* (reg8 *) ClockCamera__CFG3)
#define ClockCamera_PHASE_PTR          ((reg8 *) ClockCamera__CFG3)
#endif /* defined(ClockCamera__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockCamera_CLKEN_MASK         ClockCamera__PM_ACT_MSK
#define ClockCamera_CLKSTBY_MASK       ClockCamera__PM_STBY_MSK

/* CFG2 field masks */
#define ClockCamera_SRC_SEL_MSK        ClockCamera__CFG2_SRC_SEL_MASK
#define ClockCamera_MODE_MASK          (~(ClockCamera_SRC_SEL_MSK))

#if defined(ClockCamera__CFG3)
/* CFG3 phase mask */
#define ClockCamera_PHASE_MASK         ClockCamera__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockCamera__CFG3) */

#endif /* CY_CLOCK_ClockCamera_H */


/* [] END OF FILE */
