/*******************************************************************************
* File Name: IsrUsEchoFall.h
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
#if !defined(CY_ISR_IsrUsEchoFall_H)
#define CY_ISR_IsrUsEchoFall_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IsrUsEchoFall_Start(void);
void IsrUsEchoFall_StartEx(cyisraddress address);
void IsrUsEchoFall_Stop(void);

CY_ISR_PROTO(IsrUsEchoFall_Interrupt);

void IsrUsEchoFall_SetVector(cyisraddress address);
cyisraddress IsrUsEchoFall_GetVector(void);

void IsrUsEchoFall_SetPriority(uint8 priority);
uint8 IsrUsEchoFall_GetPriority(void);

void IsrUsEchoFall_Enable(void);
uint8 IsrUsEchoFall_GetState(void);
void IsrUsEchoFall_Disable(void);

void IsrUsEchoFall_SetPending(void);
void IsrUsEchoFall_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IsrUsEchoFall ISR. */
#define IsrUsEchoFall_INTC_VECTOR            ((reg32 *) IsrUsEchoFall__INTC_VECT)

/* Address of the IsrUsEchoFall ISR priority. */
#define IsrUsEchoFall_INTC_PRIOR             ((reg8 *) IsrUsEchoFall__INTC_PRIOR_REG)

/* Priority of the IsrUsEchoFall interrupt. */
#define IsrUsEchoFall_INTC_PRIOR_NUMBER      IsrUsEchoFall__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IsrUsEchoFall interrupt. */
#define IsrUsEchoFall_INTC_SET_EN            ((reg32 *) IsrUsEchoFall__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IsrUsEchoFall interrupt. */
#define IsrUsEchoFall_INTC_CLR_EN            ((reg32 *) IsrUsEchoFall__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IsrUsEchoFall interrupt state to pending. */
#define IsrUsEchoFall_INTC_SET_PD            ((reg32 *) IsrUsEchoFall__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IsrUsEchoFall interrupt. */
#define IsrUsEchoFall_INTC_CLR_PD            ((reg32 *) IsrUsEchoFall__INTC_CLR_PD_REG)


#endif /* CY_ISR_IsrUsEchoFall_H */


/* [] END OF FILE */
