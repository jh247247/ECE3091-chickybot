/*******************************************************************************
* File Name: Lcd_Cntl_Port_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Lcd_Cntl_Port.h"

/* Check for removal by optimization */
#if !defined(Lcd_Cntl_Port_Sync_ctrl_reg__REMOVED)

static Lcd_Cntl_Port_BACKUP_STRUCT  Lcd_Cntl_Port_backup = {0u};

    
/*******************************************************************************
* Function Name: Lcd_Cntl_Port_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Lcd_Cntl_Port_SaveConfig(void) 
{
    Lcd_Cntl_Port_backup.controlState = Lcd_Cntl_Port_Control;
}


/*******************************************************************************
* Function Name: Lcd_Cntl_Port_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Lcd_Cntl_Port_RestoreConfig(void) 
{
     Lcd_Cntl_Port_Control = Lcd_Cntl_Port_backup.controlState;
}


/*******************************************************************************
* Function Name: Lcd_Cntl_Port_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Lcd_Cntl_Port_Sleep(void) 
{
    Lcd_Cntl_Port_SaveConfig();
}


/*******************************************************************************
* Function Name: Lcd_Cntl_Port_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Lcd_Cntl_Port_Wakeup(void)  
{
    Lcd_Cntl_Port_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
