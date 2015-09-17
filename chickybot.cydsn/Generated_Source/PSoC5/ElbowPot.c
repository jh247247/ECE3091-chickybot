/*******************************************************************************
* File Name: ElbowPot.c  
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
#include "ElbowPot.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ElbowPot__PORT == 15 && ((ElbowPot__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ElbowPot_Write
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
void ElbowPot_Write(uint8 value) 
{
    uint8 staticBits = (ElbowPot_DR & (uint8)(~ElbowPot_MASK));
    ElbowPot_DR = staticBits | ((uint8)(value << ElbowPot_SHIFT) & ElbowPot_MASK);
}


/*******************************************************************************
* Function Name: ElbowPot_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ElbowPot_DM_STRONG     Strong Drive 
*  ElbowPot_DM_OD_HI      Open Drain, Drives High 
*  ElbowPot_DM_OD_LO      Open Drain, Drives Low 
*  ElbowPot_DM_RES_UP     Resistive Pull Up 
*  ElbowPot_DM_RES_DWN    Resistive Pull Down 
*  ElbowPot_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ElbowPot_DM_DIG_HIZ    High Impedance Digital 
*  ElbowPot_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ElbowPot_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ElbowPot_0, mode);
}


/*******************************************************************************
* Function Name: ElbowPot_Read
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
*  Macro ElbowPot_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ElbowPot_Read(void) 
{
    return (ElbowPot_PS & ElbowPot_MASK) >> ElbowPot_SHIFT;
}


/*******************************************************************************
* Function Name: ElbowPot_ReadDataReg
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
uint8 ElbowPot_ReadDataReg(void) 
{
    return (ElbowPot_DR & ElbowPot_MASK) >> ElbowPot_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ElbowPot_INTSTAT) 

    /*******************************************************************************
    * Function Name: ElbowPot_ClearInterrupt
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
    uint8 ElbowPot_ClearInterrupt(void) 
    {
        return (ElbowPot_INTSTAT & ElbowPot_MASK) >> ElbowPot_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
