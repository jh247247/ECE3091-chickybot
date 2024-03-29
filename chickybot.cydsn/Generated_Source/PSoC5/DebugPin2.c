/*******************************************************************************
* File Name: DebugPin2.c  
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
#include "DebugPin2.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 DebugPin2__PORT == 15 && ((DebugPin2__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: DebugPin2_Write
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
void DebugPin2_Write(uint8 value) 
{
    uint8 staticBits = (DebugPin2_DR & (uint8)(~DebugPin2_MASK));
    DebugPin2_DR = staticBits | ((uint8)(value << DebugPin2_SHIFT) & DebugPin2_MASK);
}


/*******************************************************************************
* Function Name: DebugPin2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  DebugPin2_DM_STRONG     Strong Drive 
*  DebugPin2_DM_OD_HI      Open Drain, Drives High 
*  DebugPin2_DM_OD_LO      Open Drain, Drives Low 
*  DebugPin2_DM_RES_UP     Resistive Pull Up 
*  DebugPin2_DM_RES_DWN    Resistive Pull Down 
*  DebugPin2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  DebugPin2_DM_DIG_HIZ    High Impedance Digital 
*  DebugPin2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void DebugPin2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DebugPin2_0, mode);
}


/*******************************************************************************
* Function Name: DebugPin2_Read
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
*  Macro DebugPin2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DebugPin2_Read(void) 
{
    return (DebugPin2_PS & DebugPin2_MASK) >> DebugPin2_SHIFT;
}


/*******************************************************************************
* Function Name: DebugPin2_ReadDataReg
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
uint8 DebugPin2_ReadDataReg(void) 
{
    return (DebugPin2_DR & DebugPin2_MASK) >> DebugPin2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DebugPin2_INTSTAT) 

    /*******************************************************************************
    * Function Name: DebugPin2_ClearInterrupt
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
    uint8 DebugPin2_ClearInterrupt(void) 
    {
        return (DebugPin2_INTSTAT & DebugPin2_MASK) >> DebugPin2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
