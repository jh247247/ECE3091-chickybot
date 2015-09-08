/*******************************************************************************
* File Name: LedRed.c  
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
#include "LedRed.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LedRed__PORT == 15 && ((LedRed__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LedRed_Write
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
void LedRed_Write(uint8 value) 
{
    uint8 staticBits = (LedRed_DR & (uint8)(~LedRed_MASK));
    LedRed_DR = staticBits | ((uint8)(value << LedRed_SHIFT) & LedRed_MASK);
}


/*******************************************************************************
* Function Name: LedRed_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LedRed_DM_STRONG     Strong Drive 
*  LedRed_DM_OD_HI      Open Drain, Drives High 
*  LedRed_DM_OD_LO      Open Drain, Drives Low 
*  LedRed_DM_RES_UP     Resistive Pull Up 
*  LedRed_DM_RES_DWN    Resistive Pull Down 
*  LedRed_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LedRed_DM_DIG_HIZ    High Impedance Digital 
*  LedRed_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LedRed_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LedRed_0, mode);
}


/*******************************************************************************
* Function Name: LedRed_Read
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
*  Macro LedRed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LedRed_Read(void) 
{
    return (LedRed_PS & LedRed_MASK) >> LedRed_SHIFT;
}


/*******************************************************************************
* Function Name: LedRed_ReadDataReg
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
uint8 LedRed_ReadDataReg(void) 
{
    return (LedRed_DR & LedRed_MASK) >> LedRed_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LedRed_INTSTAT) 

    /*******************************************************************************
    * Function Name: LedRed_ClearInterrupt
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
    uint8 LedRed_ClearInterrupt(void) 
    {
        return (LedRed_INTSTAT & LedRed_MASK) >> LedRed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
