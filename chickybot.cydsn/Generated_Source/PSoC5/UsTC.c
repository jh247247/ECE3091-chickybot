/*******************************************************************************
* File Name: UsTC.c  
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
#include "UsTC.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UsTC__PORT == 15 && ((UsTC__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UsTC_Write
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
void UsTC_Write(uint8 value) 
{
    uint8 staticBits = (UsTC_DR & (uint8)(~UsTC_MASK));
    UsTC_DR = staticBits | ((uint8)(value << UsTC_SHIFT) & UsTC_MASK);
}


/*******************************************************************************
* Function Name: UsTC_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  UsTC_DM_STRONG     Strong Drive 
*  UsTC_DM_OD_HI      Open Drain, Drives High 
*  UsTC_DM_OD_LO      Open Drain, Drives Low 
*  UsTC_DM_RES_UP     Resistive Pull Up 
*  UsTC_DM_RES_DWN    Resistive Pull Down 
*  UsTC_DM_RES_UPDWN  Resistive Pull Up/Down 
*  UsTC_DM_DIG_HIZ    High Impedance Digital 
*  UsTC_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void UsTC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UsTC_0, mode);
}


/*******************************************************************************
* Function Name: UsTC_Read
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
*  Macro UsTC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UsTC_Read(void) 
{
    return (UsTC_PS & UsTC_MASK) >> UsTC_SHIFT;
}


/*******************************************************************************
* Function Name: UsTC_ReadDataReg
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
uint8 UsTC_ReadDataReg(void) 
{
    return (UsTC_DR & UsTC_MASK) >> UsTC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UsTC_INTSTAT) 

    /*******************************************************************************
    * Function Name: UsTC_ClearInterrupt
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
    uint8 UsTC_ClearInterrupt(void) 
    {
        return (UsTC_INTSTAT & UsTC_MASK) >> UsTC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
