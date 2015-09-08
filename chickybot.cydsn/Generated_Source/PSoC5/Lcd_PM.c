/*******************************************************************************
* File Name: Lcd_PM.c
* Version 1.2
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Lcd.h"


static Lcd_BACKUP_STRUCT Lcd_backup;


/*******************************************************************************
* Function Name: Lcd_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: Lcd_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: Lcd_Sleep
********************************************************************************
*
* Summary:
*  Prepares component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Lcd_Sleep(void) 
{
    Lcd_backup.enableState = Lcd_enableState;
    Lcd_SaveConfig();
    Lcd_Stop();
}


/*******************************************************************************
* Function Name: Lcd_Wakeup
********************************************************************************
*
* Summary:
*  Wakes component from sleep mode. Configures DMA and enables the component for
*  normal operation.
*
* Parameters:
*  Lcd_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Lcd_Wakeup(void) 
{
    Lcd_RestoreConfig();

    if(Lcd_backup.enableState == 1u)
    {
        Lcd_Enable();
    }
}


/* [] END OF FILE */
