/*******************************************************************************
* File Name: UsTrig.c  
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
#include "UsTrig.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UsTrig__PORT == 15 && ((UsTrig__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UsTrig_Write
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
void UsTrig_Write(uint8 value) 
{
    uint8 staticBits = (UsTrig_DR & (uint8)(~UsTrig_MASK));
    UsTrig_DR = staticBits | ((uint8)(value << UsTrig_SHIFT) & UsTrig_MASK);
}


/*******************************************************************************
* Function Name: UsTrig_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  UsTrig_DM_STRONG     Strong Drive 
*  UsTrig_DM_OD_HI      Open Drain, Drives High 
*  UsTrig_DM_OD_LO      Open Drain, Drives Low 
*  UsTrig_DM_RES_UP     Resistive Pull Up 
*  UsTrig_DM_RES_DWN    Resistive Pull Down 
*  UsTrig_DM_RES_UPDWN  Resistive Pull Up/Down 
*  UsTrig_DM_DIG_HIZ    High Impedance Digital 
*  UsTrig_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void UsTrig_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UsTrig_0, mode);
}


/*******************************************************************************
* Function Name: UsTrig_Read
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
*  Macro UsTrig_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UsTrig_Read(void) 
{
    return (UsTrig_PS & UsTrig_MASK) >> UsTrig_SHIFT;
}


/*******************************************************************************
* Function Name: UsTrig_ReadDataReg
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
uint8 UsTrig_ReadDataReg(void) 
{
    return (UsTrig_DR & UsTrig_MASK) >> UsTrig_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UsTrig_INTSTAT) 

    /*******************************************************************************
    * Function Name: UsTrig_ClearInterrupt
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
    uint8 UsTrig_ClearInterrupt(void) 
    {
        return (UsTrig_INTSTAT & UsTrig_MASK) >> UsTrig_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
