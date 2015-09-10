/*******************************************************************************
* File Name: UsOutput.c  
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
#include "UsOutput.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UsOutput__PORT == 15 && ((UsOutput__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UsOutput_Write
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
void UsOutput_Write(uint8 value) 
{
    uint8 staticBits = (UsOutput_DR & (uint8)(~UsOutput_MASK));
    UsOutput_DR = staticBits | ((uint8)(value << UsOutput_SHIFT) & UsOutput_MASK);
}


/*******************************************************************************
* Function Name: UsOutput_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  UsOutput_DM_STRONG     Strong Drive 
*  UsOutput_DM_OD_HI      Open Drain, Drives High 
*  UsOutput_DM_OD_LO      Open Drain, Drives Low 
*  UsOutput_DM_RES_UP     Resistive Pull Up 
*  UsOutput_DM_RES_DWN    Resistive Pull Down 
*  UsOutput_DM_RES_UPDWN  Resistive Pull Up/Down 
*  UsOutput_DM_DIG_HIZ    High Impedance Digital 
*  UsOutput_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void UsOutput_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UsOutput_0, mode);
}


/*******************************************************************************
* Function Name: UsOutput_Read
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
*  Macro UsOutput_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UsOutput_Read(void) 
{
    return (UsOutput_PS & UsOutput_MASK) >> UsOutput_SHIFT;
}


/*******************************************************************************
* Function Name: UsOutput_ReadDataReg
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
uint8 UsOutput_ReadDataReg(void) 
{
    return (UsOutput_DR & UsOutput_MASK) >> UsOutput_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UsOutput_INTSTAT) 

    /*******************************************************************************
    * Function Name: UsOutput_ClearInterrupt
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
    uint8 UsOutput_ClearInterrupt(void) 
    {
        return (UsOutput_INTSTAT & UsOutput_MASK) >> UsOutput_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
