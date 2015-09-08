/*******************************************************************************
* File Name: ClockCsBtns.h
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

#if !defined(CY_CLOCK_ClockCsBtns_H)
#define CY_CLOCK_ClockCsBtns_H

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

void ClockCsBtns_Start(void) ;
void ClockCsBtns_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockCsBtns_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockCsBtns_StandbyPower(uint8 state) ;
void ClockCsBtns_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockCsBtns_GetDividerRegister(void) ;
void ClockCsBtns_SetModeRegister(uint8 modeBitMask) ;
void ClockCsBtns_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockCsBtns_GetModeRegister(void) ;
void ClockCsBtns_SetSourceRegister(uint8 clkSource) ;
uint8 ClockCsBtns_GetSourceRegister(void) ;
#if defined(ClockCsBtns__CFG3)
void ClockCsBtns_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockCsBtns_GetPhaseRegister(void) ;
#endif /* defined(ClockCsBtns__CFG3) */

#define ClockCsBtns_Enable()                       ClockCsBtns_Start()
#define ClockCsBtns_Disable()                      ClockCsBtns_Stop()
#define ClockCsBtns_SetDivider(clkDivider)         ClockCsBtns_SetDividerRegister(clkDivider, 1u)
#define ClockCsBtns_SetDividerValue(clkDivider)    ClockCsBtns_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockCsBtns_SetMode(clkMode)               ClockCsBtns_SetModeRegister(clkMode)
#define ClockCsBtns_SetSource(clkSource)           ClockCsBtns_SetSourceRegister(clkSource)
#if defined(ClockCsBtns__CFG3)
#define ClockCsBtns_SetPhase(clkPhase)             ClockCsBtns_SetPhaseRegister(clkPhase)
#define ClockCsBtns_SetPhaseValue(clkPhase)        ClockCsBtns_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockCsBtns__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockCsBtns_CLKEN              (* (reg8 *) ClockCsBtns__PM_ACT_CFG)
#define ClockCsBtns_CLKEN_PTR          ((reg8 *) ClockCsBtns__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockCsBtns_CLKSTBY            (* (reg8 *) ClockCsBtns__PM_STBY_CFG)
#define ClockCsBtns_CLKSTBY_PTR        ((reg8 *) ClockCsBtns__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockCsBtns_DIV_LSB            (* (reg8 *) ClockCsBtns__CFG0)
#define ClockCsBtns_DIV_LSB_PTR        ((reg8 *) ClockCsBtns__CFG0)
#define ClockCsBtns_DIV_PTR            ((reg16 *) ClockCsBtns__CFG0)

/* Clock MSB divider configuration register. */
#define ClockCsBtns_DIV_MSB            (* (reg8 *) ClockCsBtns__CFG1)
#define ClockCsBtns_DIV_MSB_PTR        ((reg8 *) ClockCsBtns__CFG1)

/* Mode and source configuration register */
#define ClockCsBtns_MOD_SRC            (* (reg8 *) ClockCsBtns__CFG2)
#define ClockCsBtns_MOD_SRC_PTR        ((reg8 *) ClockCsBtns__CFG2)

#if defined(ClockCsBtns__CFG3)
/* Analog clock phase configuration register */
#define ClockCsBtns_PHASE              (* (reg8 *) ClockCsBtns__CFG3)
#define ClockCsBtns_PHASE_PTR          ((reg8 *) ClockCsBtns__CFG3)
#endif /* defined(ClockCsBtns__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockCsBtns_CLKEN_MASK         ClockCsBtns__PM_ACT_MSK
#define ClockCsBtns_CLKSTBY_MASK       ClockCsBtns__PM_STBY_MSK

/* CFG2 field masks */
#define ClockCsBtns_SRC_SEL_MSK        ClockCsBtns__CFG2_SRC_SEL_MASK
#define ClockCsBtns_MODE_MASK          (~(ClockCsBtns_SRC_SEL_MSK))

#if defined(ClockCsBtns__CFG3)
/* CFG3 phase mask */
#define ClockCsBtns_PHASE_MASK         ClockCsBtns__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockCsBtns__CFG3) */

#endif /* CY_CLOCK_ClockCsBtns_H */


/* [] END OF FILE */
