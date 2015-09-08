/*******************************************************************************
* File Name: LedBlue.c  
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
#include "LedBlue.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LedBlue__PORT == 15 && ((LedBlue__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LedBlue_Write
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
void LedBlue_Write(uint8 value) 
{
    uint8 staticBits = (LedBlue_DR & (uint8)(~LedBlue_MASK));
    LedBlue_DR = staticBits | ((uint8)(value << LedBlue_SHIFT) & LedBlue_MASK);
}


/*******************************************************************************
* Function Name: LedBlue_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LedBlue_DM_STRONG     Strong Drive 
*  LedBlue_DM_OD_HI      Open Drain, Drives High 
*  LedBlue_DM_OD_LO      Open Drain, Drives Low 
*  LedBlue_DM_RES_UP     Resistive Pull Up 
*  LedBlue_DM_RES_DWN    Resistive Pull Down 
*  LedBlue_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LedBlue_DM_DIG_HIZ    High Impedance Digital 
*  LedBlue_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LedBlue_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LedBlue_0, mode);
}


/*******************************************************************************
* Function Name: LedBlue_Read
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
*  Macro LedBlue_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LedBlue_Read(void) 
{
    return (LedBlue_PS & LedBlue_MASK) >> LedBlue_SHIFT;
}


/*******************************************************************************
* Function Name: LedBlue_ReadDataReg
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
uint8 LedBlue_ReadDataReg(void) 
{
    return (LedBlue_DR & LedBlue_MASK) >> LedBlue_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LedBlue_INTSTAT) 

    /*******************************************************************************
    * Function Name: LedBlue_ClearInterrupt
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
    uint8 LedBlue_ClearInterrupt(void) 
    {
        return (LedBlue_INTSTAT & LedBlue_MASK) >> LedBlue_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
