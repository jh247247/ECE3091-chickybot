/*******************************************************************************
* File Name: LcdE.c  
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
#include "LcdE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LcdE__PORT == 15 && ((LcdE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LcdE_Write
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
void LcdE_Write(uint8 value) 
{
    uint8 staticBits = (LcdE_DR & (uint8)(~LcdE_MASK));
    LcdE_DR = staticBits | ((uint8)(value << LcdE_SHIFT) & LcdE_MASK);
}


/*******************************************************************************
* Function Name: LcdE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LcdE_DM_STRONG     Strong Drive 
*  LcdE_DM_OD_HI      Open Drain, Drives High 
*  LcdE_DM_OD_LO      Open Drain, Drives Low 
*  LcdE_DM_RES_UP     Resistive Pull Up 
*  LcdE_DM_RES_DWN    Resistive Pull Down 
*  LcdE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LcdE_DM_DIG_HIZ    High Impedance Digital 
*  LcdE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LcdE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LcdE_0, mode);
}


/*******************************************************************************
* Function Name: LcdE_Read
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
*  Macro LcdE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LcdE_Read(void) 
{
    return (LcdE_PS & LcdE_MASK) >> LcdE_SHIFT;
}


/*******************************************************************************
* Function Name: LcdE_ReadDataReg
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
uint8 LcdE_ReadDataReg(void) 
{
    return (LcdE_DR & LcdE_MASK) >> LcdE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LcdE_INTSTAT) 

    /*******************************************************************************
    * Function Name: LcdE_ClearInterrupt
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
    uint8 LcdE_ClearInterrupt(void) 
    {
        return (LcdE_INTSTAT & LcdE_MASK) >> LcdE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
