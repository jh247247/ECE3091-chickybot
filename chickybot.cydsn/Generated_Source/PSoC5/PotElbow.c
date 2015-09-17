/*******************************************************************************
* File Name: PotElbow.c  
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
#include "PotElbow.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PotElbow__PORT == 15 && ((PotElbow__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PotElbow_Write
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
void PotElbow_Write(uint8 value) 
{
    uint8 staticBits = (PotElbow_DR & (uint8)(~PotElbow_MASK));
    PotElbow_DR = staticBits | ((uint8)(value << PotElbow_SHIFT) & PotElbow_MASK);
}


/*******************************************************************************
* Function Name: PotElbow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PotElbow_DM_STRONG     Strong Drive 
*  PotElbow_DM_OD_HI      Open Drain, Drives High 
*  PotElbow_DM_OD_LO      Open Drain, Drives Low 
*  PotElbow_DM_RES_UP     Resistive Pull Up 
*  PotElbow_DM_RES_DWN    Resistive Pull Down 
*  PotElbow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PotElbow_DM_DIG_HIZ    High Impedance Digital 
*  PotElbow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PotElbow_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PotElbow_0, mode);
}


/*******************************************************************************
* Function Name: PotElbow_Read
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
*  Macro PotElbow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PotElbow_Read(void) 
{
    return (PotElbow_PS & PotElbow_MASK) >> PotElbow_SHIFT;
}


/*******************************************************************************
* Function Name: PotElbow_ReadDataReg
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
uint8 PotElbow_ReadDataReg(void) 
{
    return (PotElbow_DR & PotElbow_MASK) >> PotElbow_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PotElbow_INTSTAT) 

    /*******************************************************************************
    * Function Name: PotElbow_ClearInterrupt
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
    uint8 PotElbow_ClearInterrupt(void) 
    {
        return (PotElbow_INTSTAT & PotElbow_MASK) >> PotElbow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
