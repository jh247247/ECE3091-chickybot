/*******************************************************************************
* File Name: ElbowNeg.c  
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
#include "ElbowNeg.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ElbowNeg__PORT == 15 && ((ElbowNeg__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ElbowNeg_Write
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
void ElbowNeg_Write(uint8 value) 
{
    uint8 staticBits = (ElbowNeg_DR & (uint8)(~ElbowNeg_MASK));
    ElbowNeg_DR = staticBits | ((uint8)(value << ElbowNeg_SHIFT) & ElbowNeg_MASK);
}


/*******************************************************************************
* Function Name: ElbowNeg_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ElbowNeg_DM_STRONG     Strong Drive 
*  ElbowNeg_DM_OD_HI      Open Drain, Drives High 
*  ElbowNeg_DM_OD_LO      Open Drain, Drives Low 
*  ElbowNeg_DM_RES_UP     Resistive Pull Up 
*  ElbowNeg_DM_RES_DWN    Resistive Pull Down 
*  ElbowNeg_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ElbowNeg_DM_DIG_HIZ    High Impedance Digital 
*  ElbowNeg_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ElbowNeg_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ElbowNeg_0, mode);
}


/*******************************************************************************
* Function Name: ElbowNeg_Read
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
*  Macro ElbowNeg_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ElbowNeg_Read(void) 
{
    return (ElbowNeg_PS & ElbowNeg_MASK) >> ElbowNeg_SHIFT;
}


/*******************************************************************************
* Function Name: ElbowNeg_ReadDataReg
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
uint8 ElbowNeg_ReadDataReg(void) 
{
    return (ElbowNeg_DR & ElbowNeg_MASK) >> ElbowNeg_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ElbowNeg_INTSTAT) 

    /*******************************************************************************
    * Function Name: ElbowNeg_ClearInterrupt
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
    uint8 ElbowNeg_ClearInterrupt(void) 
    {
        return (ElbowNeg_INTSTAT & ElbowNeg_MASK) >> ElbowNeg_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
