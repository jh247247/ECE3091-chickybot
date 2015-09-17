/*******************************************************************************
* File Name: UsMicroSecs.c  
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
#include "UsMicroSecs.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UsMicroSecs__PORT == 15 && ((UsMicroSecs__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UsMicroSecs_Write
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
void UsMicroSecs_Write(uint8 value) 
{
    uint8 staticBits = (UsMicroSecs_DR & (uint8)(~UsMicroSecs_MASK));
    UsMicroSecs_DR = staticBits | ((uint8)(value << UsMicroSecs_SHIFT) & UsMicroSecs_MASK);
}


/*******************************************************************************
* Function Name: UsMicroSecs_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  UsMicroSecs_DM_STRONG     Strong Drive 
*  UsMicroSecs_DM_OD_HI      Open Drain, Drives High 
*  UsMicroSecs_DM_OD_LO      Open Drain, Drives Low 
*  UsMicroSecs_DM_RES_UP     Resistive Pull Up 
*  UsMicroSecs_DM_RES_DWN    Resistive Pull Down 
*  UsMicroSecs_DM_RES_UPDWN  Resistive Pull Up/Down 
*  UsMicroSecs_DM_DIG_HIZ    High Impedance Digital 
*  UsMicroSecs_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void UsMicroSecs_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UsMicroSecs_0, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_1, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_2, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_3, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_4, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_5, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_6, mode);
	CyPins_SetPinDriveMode(UsMicroSecs_7, mode);
}


/*******************************************************************************
* Function Name: UsMicroSecs_Read
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
*  Macro UsMicroSecs_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UsMicroSecs_Read(void) 
{
    return (UsMicroSecs_PS & UsMicroSecs_MASK) >> UsMicroSecs_SHIFT;
}


/*******************************************************************************
* Function Name: UsMicroSecs_ReadDataReg
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
uint8 UsMicroSecs_ReadDataReg(void) 
{
    return (UsMicroSecs_DR & UsMicroSecs_MASK) >> UsMicroSecs_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UsMicroSecs_INTSTAT) 

    /*******************************************************************************
    * Function Name: UsMicroSecs_ClearInterrupt
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
    uint8 UsMicroSecs_ClearInterrupt(void) 
    {
        return (UsMicroSecs_INTSTAT & UsMicroSecs_MASK) >> UsMicroSecs_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
