/*******************************************************************************
* File Name: VDAC_Elbow_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VDAC_Elbow.h"

static VDAC_Elbow_backupStruct VDAC_Elbow_backup;


/*******************************************************************************
* Function Name: VDAC_Elbow_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC_Elbow_SaveConfig(void) 
{
    if (!((VDAC_Elbow_CR1 & VDAC_Elbow_SRC_MASK) == VDAC_Elbow_SRC_UDB))
    {
        VDAC_Elbow_backup.data_value = VDAC_Elbow_Data;
    }
}


/*******************************************************************************
* Function Name: VDAC_Elbow_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC_Elbow_RestoreConfig(void) 
{
    if (!((VDAC_Elbow_CR1 & VDAC_Elbow_SRC_MASK) == VDAC_Elbow_SRC_UDB))
    {
        if((VDAC_Elbow_Strobe & VDAC_Elbow_STRB_MASK) == VDAC_Elbow_STRB_EN)
        {
            VDAC_Elbow_Strobe &= (uint8)(~VDAC_Elbow_STRB_MASK);
            VDAC_Elbow_Data = VDAC_Elbow_backup.data_value;
            VDAC_Elbow_Strobe |= VDAC_Elbow_STRB_EN;
        }
        else
        {
            VDAC_Elbow_Data = VDAC_Elbow_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDAC_Elbow_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  VDAC_Elbow_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDAC_Elbow_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDAC_Elbow_ACT_PWR_EN == (VDAC_Elbow_PWRMGR & VDAC_Elbow_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDAC_Elbow_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDAC_Elbow_backup.enableState = 0u;
    }
    
    VDAC_Elbow_Stop();
    VDAC_Elbow_SaveConfig();
}


/*******************************************************************************
* Function Name: VDAC_Elbow_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  VDAC_Elbow_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDAC_Elbow_Wakeup(void) 
{
    VDAC_Elbow_RestoreConfig();
    
    if(VDAC_Elbow_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDAC_Elbow_Enable();

        /* Restore the data register */
        VDAC_Elbow_SetValue(VDAC_Elbow_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
