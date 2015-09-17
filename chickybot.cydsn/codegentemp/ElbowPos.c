/*******************************************************************************
* File Name: ElbowPos.c  
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
#include "ElbowPos.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ElbowPos__PORT == 15 && ((ElbowPos__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ElbowPos_Write
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
void ElbowPos_Write(uint8 value) 
{
    uint8 staticBits = (ElbowPos_DR & (uint8)(~ElbowPos_MASK));
    ElbowPos_DR = staticBits | ((uint8)(value << ElbowPos_SHIFT) & ElbowPos_MASK);
}


/*******************************************************************************
* Function Name: ElbowPos_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ElbowPos_DM_STRONG     Strong Drive 
*  ElbowPos_DM_OD_HI      Open Drain, Drives High 
*  ElbowPos_DM_OD_LO      Open Drain, Drives Low 
*  ElbowPos_DM_RES_UP     Resistive Pull Up 
*  ElbowPos_DM_RES_DWN    Resistive Pull Down 
*  ElbowPos_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ElbowPos_DM_DIG_HIZ    High Impedance Digital 
*  ElbowPos_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ElbowPos_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ElbowPos_0, mode);
}


/*******************************************************************************
* Function Name: ElbowPos_Read
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
*  Macro ElbowPos_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ElbowPos_Read(void) 
{
    return (ElbowPos_PS & ElbowPos_MASK) >> ElbowPos_SHIFT;
}


/*******************************************************************************
* Function Name: ElbowPos_ReadDataReg
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
uint8 ElbowPos_ReadDataReg(void) 
{
    return (ElbowPos_DR & ElbowPos_MASK) >> ElbowPos_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ElbowPos_INTSTAT) 

    /*******************************************************************************
    * Function Name: ElbowPos_ClearInterrupt
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
    uint8 ElbowPos_ClearInterrupt(void) 
    {
        return (ElbowPos_INTSTAT & ElbowPos_MASK) >> ElbowPos_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
