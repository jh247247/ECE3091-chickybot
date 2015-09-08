/*******************************************************************************
* File Name: LcdDB7.c  
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
#include "LcdDB7.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LcdDB7__PORT == 15 && ((LcdDB7__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LcdDB7_Write
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
void LcdDB7_Write(uint8 value) 
{
    uint8 staticBits = (LcdDB7_DR & (uint8)(~LcdDB7_MASK));
    LcdDB7_DR = staticBits | ((uint8)(value << LcdDB7_SHIFT) & LcdDB7_MASK);
}


/*******************************************************************************
* Function Name: LcdDB7_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LcdDB7_DM_STRONG     Strong Drive 
*  LcdDB7_DM_OD_HI      Open Drain, Drives High 
*  LcdDB7_DM_OD_LO      Open Drain, Drives Low 
*  LcdDB7_DM_RES_UP     Resistive Pull Up 
*  LcdDB7_DM_RES_DWN    Resistive Pull Down 
*  LcdDB7_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LcdDB7_DM_DIG_HIZ    High Impedance Digital 
*  LcdDB7_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LcdDB7_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LcdDB7_0, mode);
}


/*******************************************************************************
* Function Name: LcdDB7_Read
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
*  Macro LcdDB7_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LcdDB7_Read(void) 
{
    return (LcdDB7_PS & LcdDB7_MASK) >> LcdDB7_SHIFT;
}


/*******************************************************************************
* Function Name: LcdDB7_ReadDataReg
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
uint8 LcdDB7_ReadDataReg(void) 
{
    return (LcdDB7_DR & LcdDB7_MASK) >> LcdDB7_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LcdDB7_INTSTAT) 

    /*******************************************************************************
    * Function Name: LcdDB7_ClearInterrupt
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
    uint8 LcdDB7_ClearInterrupt(void) 
    {
        return (LcdDB7_INTSTAT & LcdDB7_MASK) >> LcdDB7_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
