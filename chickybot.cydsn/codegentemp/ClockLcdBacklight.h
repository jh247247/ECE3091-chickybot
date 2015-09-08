/*******************************************************************************
* File Name: ClockLcdBacklight.h
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

#if !defined(CY_CLOCK_ClockLcdBacklight_H)
#define CY_CLOCK_ClockLcdBacklight_H

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

void ClockLcdBacklight_Start(void) ;
void ClockLcdBacklight_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockLcdBacklight_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockLcdBacklight_StandbyPower(uint8 state) ;
void ClockLcdBacklight_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockLcdBacklight_GetDividerRegister(void) ;
void ClockLcdBacklight_SetModeRegister(uint8 modeBitMask) ;
void ClockLcdBacklight_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockLcdBacklight_GetModeRegister(void) ;
void ClockLcdBacklight_SetSourceRegister(uint8 clkSource) ;
uint8 ClockLcdBacklight_GetSourceRegister(void) ;
#if defined(ClockLcdBacklight__CFG3)
void ClockLcdBacklight_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockLcdBacklight_GetPhaseRegister(void) ;
#endif /* defined(ClockLcdBacklight__CFG3) */

#define ClockLcdBacklight_Enable()                       ClockLcdBacklight_Start()
#define ClockLcdBacklight_Disable()                      ClockLcdBacklight_Stop()
#define ClockLcdBacklight_SetDivider(clkDivider)         ClockLcdBacklight_SetDividerRegister(clkDivider, 1u)
#define ClockLcdBacklight_SetDividerValue(clkDivider)    ClockLcdBacklight_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockLcdBacklight_SetMode(clkMode)               ClockLcdBacklight_SetModeRegister(clkMode)
#define ClockLcdBacklight_SetSource(clkSource)           ClockLcdBacklight_SetSourceRegister(clkSource)
#if defined(ClockLcdBacklight__CFG3)
#define ClockLcdBacklight_SetPhase(clkPhase)             ClockLcdBacklight_SetPhaseRegister(clkPhase)
#define ClockLcdBacklight_SetPhaseValue(clkPhase)        ClockLcdBacklight_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockLcdBacklight__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockLcdBacklight_CLKEN              (* (reg8 *) ClockLcdBacklight__PM_ACT_CFG)
#define ClockLcdBacklight_CLKEN_PTR          ((reg8 *) ClockLcdBacklight__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockLcdBacklight_CLKSTBY            (* (reg8 *) ClockLcdBacklight__PM_STBY_CFG)
#define ClockLcdBacklight_CLKSTBY_PTR        ((reg8 *) ClockLcdBacklight__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockLcdBacklight_DIV_LSB            (* (reg8 *) ClockLcdBacklight__CFG0)
#define ClockLcdBacklight_DIV_LSB_PTR        ((reg8 *) ClockLcdBacklight__CFG0)
#define ClockLcdBacklight_DIV_PTR            ((reg16 *) ClockLcdBacklight__CFG0)

/* Clock MSB divider configuration register. */
#define ClockLcdBacklight_DIV_MSB            (* (reg8 *) ClockLcdBacklight__CFG1)
#define ClockLcdBacklight_DIV_MSB_PTR        ((reg8 *) ClockLcdBacklight__CFG1)

/* Mode and source configuration register */
#define ClockLcdBacklight_MOD_SRC            (* (reg8 *) ClockLcdBacklight__CFG2)
#define ClockLcdBacklight_MOD_SRC_PTR        ((reg8 *) ClockLcdBacklight__CFG2)

#if defined(ClockLcdBacklight__CFG3)
/* Analog clock phase configuration register */
#define ClockLcdBacklight_PHASE              (* (reg8 *) ClockLcdBacklight__CFG3)
#define ClockLcdBacklight_PHASE_PTR          ((reg8 *) ClockLcdBacklight__CFG3)
#endif /* defined(ClockLcdBacklight__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockLcdBacklight_CLKEN_MASK         ClockLcdBacklight__PM_ACT_MSK
#define ClockLcdBacklight_CLKSTBY_MASK       ClockLcdBacklight__PM_STBY_MSK

/* CFG2 field masks */
#define ClockLcdBacklight_SRC_SEL_MSK        ClockLcdBacklight__CFG2_SRC_SEL_MASK
#define ClockLcdBacklight_MODE_MASK          (~(ClockLcdBacklight_SRC_SEL_MSK))

#if defined(ClockLcdBacklight__CFG3)
/* CFG3 phase mask */
#define ClockLcdBacklight_PHASE_MASK         ClockLcdBacklight__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockLcdBacklight__CFG3) */

#endif /* CY_CLOCK_ClockLcdBacklight_H */


/* [] END OF FILE */
