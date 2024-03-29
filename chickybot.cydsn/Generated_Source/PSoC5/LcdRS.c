/*******************************************************************************
* File Name: LcdRS.c  
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
#include "LcdRS.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LcdRS__PORT == 15 && ((LcdRS__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LcdRS_Write
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
void LcdRS_Write(uint8 value) 
{
    uint8 staticBits = (LcdRS_DR & (uint8)(~LcdRS_MASK));
    LcdRS_DR = staticBits | ((uint8)(value << LcdRS_SHIFT) & LcdRS_MASK);
}


/*******************************************************************************
* Function Name: LcdRS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LcdRS_DM_STRONG     Strong Drive 
*  LcdRS_DM_OD_HI      Open Drain, Drives High 
*  LcdRS_DM_OD_LO      Open Drain, Drives Low 
*  LcdRS_DM_RES_UP     Resistive Pull Up 
*  LcdRS_DM_RES_DWN    Resistive Pull Down 
*  LcdRS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LcdRS_DM_DIG_HIZ    High Impedance Digital 
*  LcdRS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LcdRS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LcdRS_0, mode);
}


/*******************************************************************************
* Function Name: LcdRS_Read
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
*  Macro LcdRS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LcdRS_Read(void) 
{
    return (LcdRS_PS & LcdRS_MASK) >> LcdRS_SHIFT;
}


/*******************************************************************************
* Function Name: LcdRS_ReadDataReg
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
uint8 LcdRS_ReadDataReg(void) 
{
    return (LcdRS_DR & LcdRS_MASK) >> LcdRS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LcdRS_INTSTAT) 

    /*******************************************************************************
    * Function Name: LcdRS_ClearInterrupt
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
    uint8 LcdRS_ClearInterrupt(void) 
    {
        return (LcdRS_INTSTAT & LcdRS_MASK) >> LcdRS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
