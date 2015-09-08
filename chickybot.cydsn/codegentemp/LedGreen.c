/*******************************************************************************
* File Name: LedGreen.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LedGreen.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LedGreen__PORT == 15 && ((LedGreen__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LedGreen_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void LedGreen_Write(uint8 value) 
{
    uint8 staticBits = (LedGreen_DR & (uint8)(~LedGreen_MASK));
    LedGreen_DR = staticBits | ((uint8)(value << LedGreen_SHIFT) & LedGreen_MASK);
}


/*******************************************************************************
* Function Name: LedGreen_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LedGreen_DM_STRONG     Strong Drive 
*  LedGreen_DM_OD_HI      Open Drain, Drives High 
*  LedGreen_DM_OD_LO      Open Drain, Drives Low 
*  LedGreen_DM_RES_UP     Resistive Pull Up 
*  LedGreen_DM_RES_DWN    Resistive Pull Down 
*  LedGreen_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LedGreen_DM_DIG_HIZ    High Impedance Digital 
*  LedGreen_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LedGreen_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LedGreen_0, mode);
}


/*******************************************************************************
* Function Name: LedGreen_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro LedGreen_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LedGreen_Read(void) 
{
    return (LedGreen_PS & LedGreen_MASK) >> LedGreen_SHIFT;
}


/*******************************************************************************
* Function Name: LedGreen_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 LedGreen_ReadDataReg(void) 
{
    return (LedGreen_DR & LedGreen_MASK) >> LedGreen_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LedGreen_INTSTAT) 

    /*******************************************************************************
    * Function Name: LedGreen_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 LedGreen_ClearInterrupt(void) 
    {
        return (LedGreen_INTSTAT & LedGreen_MASK) >> LedGreen_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
