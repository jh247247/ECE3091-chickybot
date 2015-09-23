/*******************************************************************************
* File Name: IsrUsTimer.h
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
#if !defined(CY_ISR_IsrUsTimer_H)
#define CY_ISR_IsrUsTimer_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IsrUsTimer_Start(void);
void IsrUsTimer_StartEx(cyisraddress address);
void IsrUsTimer_Stop(void);

CY_ISR_PROTO(IsrUsTimer_Interrupt);

void IsrUsTimer_SetVector(cyisraddress address);
cyisraddress IsrUsTimer_GetVector(void);

void IsrUsTimer_SetPriority(uint8 priority);
uint8 IsrUsTimer_GetPriority(void);

void IsrUsTimer_Enable(void);
uint8 IsrUsTimer_GetState(void);
void IsrUsTimer_Disable(void);

void IsrUsTimer_SetPending(void);
void IsrUsTimer_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IsrUsTimer ISR. */
#define IsrUsTimer_INTC_VECTOR            ((reg32 *) IsrUsTimer__INTC_VECT)

/* Address of the IsrUsTimer ISR priority. */
#define IsrUsTimer_INTC_PRIOR             ((reg8 *) IsrUsTimer__INTC_PRIOR_REG)

/* Priority of the IsrUsTimer interrupt. */
#define IsrUsTimer_INTC_PRIOR_NUMBER      IsrUsTimer__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IsrUsTimer interrupt. */
#define IsrUsTimer_INTC_SET_EN            ((reg32 *) IsrUsTimer__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IsrUsTimer interrupt. */
#define IsrUsTimer_INTC_CLR_EN            ((reg32 *) IsrUsTimer__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IsrUsTimer interrupt state to pending. */
#define IsrUsTimer_INTC_SET_PD            ((reg32 *) IsrUsTimer__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IsrUsTimer interrupt. */
#define IsrUsTimer_INTC_CLR_PD            ((reg32 *) IsrUsTimer__INTC_CLR_PD_REG)


#endif /* CY_ISR_IsrUsTimer_H */


/* [] END OF FILE */
