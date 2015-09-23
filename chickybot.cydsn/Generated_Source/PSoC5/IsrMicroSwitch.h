/*******************************************************************************
* File Name: IsrMicroSwitch.h
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
#if !defined(CY_ISR_IsrMicroSwitch_H)
#define CY_ISR_IsrMicroSwitch_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IsrMicroSwitch_Start(void);
void IsrMicroSwitch_StartEx(cyisraddress address);
void IsrMicroSwitch_Stop(void);

CY_ISR_PROTO(IsrMicroSwitch_Interrupt);

void IsrMicroSwitch_SetVector(cyisraddress address);
cyisraddress IsrMicroSwitch_GetVector(void);

void IsrMicroSwitch_SetPriority(uint8 priority);
uint8 IsrMicroSwitch_GetPriority(void);

void IsrMicroSwitch_Enable(void);
uint8 IsrMicroSwitch_GetState(void);
void IsrMicroSwitch_Disable(void);

void IsrMicroSwitch_SetPending(void);
void IsrMicroSwitch_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IsrMicroSwitch ISR. */
#define IsrMicroSwitch_INTC_VECTOR            ((reg32 *) IsrMicroSwitch__INTC_VECT)

/* Address of the IsrMicroSwitch ISR priority. */
#define IsrMicroSwitch_INTC_PRIOR             ((reg8 *) IsrMicroSwitch__INTC_PRIOR_REG)

/* Priority of the IsrMicroSwitch interrupt. */
#define IsrMicroSwitch_INTC_PRIOR_NUMBER      IsrMicroSwitch__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IsrMicroSwitch interrupt. */
#define IsrMicroSwitch_INTC_SET_EN            ((reg32 *) IsrMicroSwitch__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IsrMicroSwitch interrupt. */
#define IsrMicroSwitch_INTC_CLR_EN            ((reg32 *) IsrMicroSwitch__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IsrMicroSwitch interrupt state to pending. */
#define IsrMicroSwitch_INTC_SET_PD            ((reg32 *) IsrMicroSwitch__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IsrMicroSwitch interrupt. */
#define IsrMicroSwitch_INTC_CLR_PD            ((reg32 *) IsrMicroSwitch__INTC_CLR_PD_REG)


#endif /* CY_ISR_IsrMicroSwitch_H */


/* [] END OF FILE */
