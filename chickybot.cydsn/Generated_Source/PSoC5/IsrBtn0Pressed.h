/*******************************************************************************
* File Name: IsrBtn0Pressed.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_IsrBtn0Pressed_H)
#define CY_ISR_IsrBtn0Pressed_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IsrBtn0Pressed_Start(void);
void IsrBtn0Pressed_StartEx(cyisraddress address);
void IsrBtn0Pressed_Stop(void);

CY_ISR_PROTO(IsrBtn0Pressed_Interrupt);

void IsrBtn0Pressed_SetVector(cyisraddress address);
cyisraddress IsrBtn0Pressed_GetVector(void);

void IsrBtn0Pressed_SetPriority(uint8 priority);
uint8 IsrBtn0Pressed_GetPriority(void);

void IsrBtn0Pressed_Enable(void);
uint8 IsrBtn0Pressed_GetState(void);
void IsrBtn0Pressed_Disable(void);

void IsrBtn0Pressed_SetPending(void);
void IsrBtn0Pressed_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IsrBtn0Pressed ISR. */
#define IsrBtn0Pressed_INTC_VECTOR            ((reg32 *) IsrBtn0Pressed__INTC_VECT)

/* Address of the IsrBtn0Pressed ISR priority. */
#define IsrBtn0Pressed_INTC_PRIOR             ((reg8 *) IsrBtn0Pressed__INTC_PRIOR_REG)

/* Priority of the IsrBtn0Pressed interrupt. */
#define IsrBtn0Pressed_INTC_PRIOR_NUMBER      IsrBtn0Pressed__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IsrBtn0Pressed interrupt. */
#define IsrBtn0Pressed_INTC_SET_EN            ((reg32 *) IsrBtn0Pressed__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IsrBtn0Pressed interrupt. */
#define IsrBtn0Pressed_INTC_CLR_EN            ((reg32 *) IsrBtn0Pressed__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IsrBtn0Pressed interrupt state to pending. */
#define IsrBtn0Pressed_INTC_SET_PD            ((reg32 *) IsrBtn0Pressed__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IsrBtn0Pressed interrupt. */
#define IsrBtn0Pressed_INTC_CLR_PD            ((reg32 *) IsrBtn0Pressed__INTC_CLR_PD_REG)


#endif /* CY_ISR_IsrBtn0Pressed_H */


/* [] END OF FILE */
