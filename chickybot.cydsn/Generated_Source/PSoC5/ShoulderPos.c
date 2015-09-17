/*******************************************************************************
* File Name: ShoulderPos.c  
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
#include "ShoulderPos.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ShoulderPos__PORT == 15 && ((ShoulderPos__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ShoulderPos_Write
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
void ShoulderPos_Write(uint8 value) 
{
    uint8 staticBits = (ShoulderPos_DR & (uint8)(~ShoulderPos_MASK));
    ShoulderPos_DR = staticBits | ((uint8)(value << ShoulderPos_SHIFT) & ShoulderPos_MASK);
}


/*******************************************************************************
* Function Name: ShoulderPos_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ShoulderPos_DM_STRONG     Strong Drive 
*  ShoulderPos_DM_OD_HI      Open Drain, Drives High 
*  ShoulderPos_DM_OD_LO      Open Drain, Drives Low 
*  ShoulderPos_DM_RES_UP     Resistive Pull Up 
*  ShoulderPos_DM_RES_DWN    Resistive Pull Down 
*  ShoulderPos_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ShoulderPos_DM_DIG_HIZ    High Impedance Digital 
*  ShoulderPos_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ShoulderPos_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ShoulderPos_0, mode);
}


/*******************************************************************************
* Function Name: ShoulderPos_Read
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
*  Macro ShoulderPos_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ShoulderPos_Read(void) 
{
    return (ShoulderPos_PS & ShoulderPos_MASK) >> ShoulderPos_SHIFT;
}


/*******************************************************************************
* Function Name: ShoulderPos_ReadDataReg
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
uint8 ShoulderPos_ReadDataReg(void) 
{
    return (ShoulderPos_DR & ShoulderPos_MASK) >> ShoulderPos_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ShoulderPos_INTSTAT) 

    /*******************************************************************************
    * Function Name: ShoulderPos_ClearInterrupt
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
    uint8 ShoulderPos_ClearInterrupt(void) 
    {
        return (ShoulderPos_INTSTAT & ShoulderPos_MASK) >> ShoulderPos_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
