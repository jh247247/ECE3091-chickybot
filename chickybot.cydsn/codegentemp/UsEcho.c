/*******************************************************************************
* File Name: UsEcho.c  
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
#include "UsEcho.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UsEcho__PORT == 15 && ((UsEcho__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UsEcho_Write
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
void UsEcho_Write(uint8 value) 
{
    uint8 staticBits = (UsEcho_DR & (uint8)(~UsEcho_MASK));
    UsEcho_DR = staticBits | ((uint8)(value << UsEcho_SHIFT) & UsEcho_MASK);
}


/*******************************************************************************
* Function Name: UsEcho_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  UsEcho_DM_STRONG     Strong Drive 
*  UsEcho_DM_OD_HI      Open Drain, Drives High 
*  UsEcho_DM_OD_LO      Open Drain, Drives Low 
*  UsEcho_DM_RES_UP     Resistive Pull Up 
*  UsEcho_DM_RES_DWN    Resistive Pull Down 
*  UsEcho_DM_RES_UPDWN  Resistive Pull Up/Down 
*  UsEcho_DM_DIG_HIZ    High Impedance Digital 
*  UsEcho_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void UsEcho_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UsEcho_0, mode);
}


/*******************************************************************************
* Function Name: UsEcho_Read
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
*  Macro UsEcho_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UsEcho_Read(void) 
{
    return (UsEcho_PS & UsEcho_MASK) >> UsEcho_SHIFT;
}


/*******************************************************************************
* Function Name: UsEcho_ReadDataReg
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
uint8 UsEcho_ReadDataReg(void) 
{
    return (UsEcho_DR & UsEcho_MASK) >> UsEcho_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UsEcho_INTSTAT) 

    /*******************************************************************************
    * Function Name: UsEcho_ClearInterrupt
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
    uint8 UsEcho_ClearInterrupt(void) 
    {
        return (UsEcho_INTSTAT & UsEcho_MASK) >> UsEcho_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
