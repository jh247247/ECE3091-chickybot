/*******************************************************************************
* File Name: LcdDB5.c  
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
#include "LcdDB5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LcdDB5__PORT == 15 && ((LcdDB5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LcdDB5_Write
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
void LcdDB5_Write(uint8 value) 
{
    uint8 staticBits = (LcdDB5_DR & (uint8)(~LcdDB5_MASK));
    LcdDB5_DR = staticBits | ((uint8)(value << LcdDB5_SHIFT) & LcdDB5_MASK);
}


/*******************************************************************************
* Function Name: LcdDB5_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LcdDB5_DM_STRONG     Strong Drive 
*  LcdDB5_DM_OD_HI      Open Drain, Drives High 
*  LcdDB5_DM_OD_LO      Open Drain, Drives Low 
*  LcdDB5_DM_RES_UP     Resistive Pull Up 
*  LcdDB5_DM_RES_DWN    Resistive Pull Down 
*  LcdDB5_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LcdDB5_DM_DIG_HIZ    High Impedance Digital 
*  LcdDB5_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LcdDB5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LcdDB5_0, mode);
}


/*******************************************************************************
* Function Name: LcdDB5_Read
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
*  Macro LcdDB5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LcdDB5_Read(void) 
{
    return (LcdDB5_PS & LcdDB5_MASK) >> LcdDB5_SHIFT;
}


/*******************************************************************************
* Function Name: LcdDB5_ReadDataReg
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
uint8 LcdDB5_ReadDataReg(void) 
{
    return (LcdDB5_DR & LcdDB5_MASK) >> LcdDB5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LcdDB5_INTSTAT) 

    /*******************************************************************************
    * Function Name: LcdDB5_ClearInterrupt
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
    uint8 LcdDB5_ClearInterrupt(void) 
    {
        return (LcdDB5_INTSTAT & LcdDB5_MASK) >> LcdDB5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
