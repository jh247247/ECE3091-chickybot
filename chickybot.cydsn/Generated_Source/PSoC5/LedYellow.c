/*******************************************************************************
* File Name: LedYellow.c  
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
#include "LedYellow.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LedYellow__PORT == 15 && ((LedYellow__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LedYellow_Write
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
void LedYellow_Write(uint8 value) 
{
    uint8 staticBits = (LedYellow_DR & (uint8)(~LedYellow_MASK));
    LedYellow_DR = staticBits | ((uint8)(value << LedYellow_SHIFT) & LedYellow_MASK);
}


/*******************************************************************************
* Function Name: LedYellow_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LedYellow_DM_STRONG     Strong Drive 
*  LedYellow_DM_OD_HI      Open Drain, Drives High 
*  LedYellow_DM_OD_LO      Open Drain, Drives Low 
*  LedYellow_DM_RES_UP     Resistive Pull Up 
*  LedYellow_DM_RES_DWN    Resistive Pull Down 
*  LedYellow_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LedYellow_DM_DIG_HIZ    High Impedance Digital 
*  LedYellow_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LedYellow_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LedYellow_0, mode);
}


/*******************************************************************************
* Function Name: LedYellow_Read
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
*  Macro LedYellow_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LedYellow_Read(void) 
{
    return (LedYellow_PS & LedYellow_MASK) >> LedYellow_SHIFT;
}


/*******************************************************************************
* Function Name: LedYellow_ReadDataReg
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
uint8 LedYellow_ReadDataReg(void) 
{
    return (LedYellow_DR & LedYellow_MASK) >> LedYellow_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LedYellow_INTSTAT) 

    /*******************************************************************************
    * Function Name: LedYellow_ClearInterrupt
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
    uint8 LedYellow_ClearInterrupt(void) 
    {
        return (LedYellow_INTSTAT & LedYellow_MASK) >> LedYellow_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
