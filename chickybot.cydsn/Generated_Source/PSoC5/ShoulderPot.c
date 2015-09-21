/*******************************************************************************
* File Name: ShoulderPot.c  
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
#include "ShoulderPot.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ShoulderPot__PORT == 15 && ((ShoulderPot__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ShoulderPot_Write
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
void ShoulderPot_Write(uint8 value) 
{
    uint8 staticBits = (ShoulderPot_DR & (uint8)(~ShoulderPot_MASK));
    ShoulderPot_DR = staticBits | ((uint8)(value << ShoulderPot_SHIFT) & ShoulderPot_MASK);
}


/*******************************************************************************
* Function Name: ShoulderPot_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ShoulderPot_DM_STRONG     Strong Drive 
*  ShoulderPot_DM_OD_HI      Open Drain, Drives High 
*  ShoulderPot_DM_OD_LO      Open Drain, Drives Low 
*  ShoulderPot_DM_RES_UP     Resistive Pull Up 
*  ShoulderPot_DM_RES_DWN    Resistive Pull Down 
*  ShoulderPot_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ShoulderPot_DM_DIG_HIZ    High Impedance Digital 
*  ShoulderPot_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ShoulderPot_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ShoulderPot_0, mode);
}


/*******************************************************************************
* Function Name: ShoulderPot_Read
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
*  Macro ShoulderPot_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ShoulderPot_Read(void) 
{
    return (ShoulderPot_PS & ShoulderPot_MASK) >> ShoulderPot_SHIFT;
}


/*******************************************************************************
* Function Name: ShoulderPot_ReadDataReg
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
uint8 ShoulderPot_ReadDataReg(void) 
{
    return (ShoulderPot_DR & ShoulderPot_MASK) >> ShoulderPot_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ShoulderPot_INTSTAT) 

    /*******************************************************************************
    * Function Name: ShoulderPot_ClearInterrupt
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
    uint8 ShoulderPot_ClearInterrupt(void) 
    {
        return (ShoulderPot_INTSTAT & ShoulderPot_MASK) >> ShoulderPot_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
