/*******************************************************************************
* File Name: UsPWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UsPWM.h"

static UsPWM_backupStruct UsPWM_backup;


/*******************************************************************************
* Function Name: UsPWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UsPWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void UsPWM_SaveConfig(void) 
{

    #if(!UsPWM_UsingFixedFunction)
        #if(!UsPWM_PWMModeIsCenterAligned)
            UsPWM_backup.PWMPeriod = UsPWM_ReadPeriod();
        #endif /* (!UsPWM_PWMModeIsCenterAligned) */
        UsPWM_backup.PWMUdb = UsPWM_ReadCounter();
        #if (UsPWM_UseStatus)
            UsPWM_backup.InterruptMaskValue = UsPWM_STATUS_MASK;
        #endif /* (UsPWM_UseStatus) */

        #if(UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_256_CLOCKS || \
            UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_2_4_CLOCKS)
            UsPWM_backup.PWMdeadBandValue = UsPWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(UsPWM_KillModeMinTime)
             UsPWM_backup.PWMKillCounterPeriod = UsPWM_ReadKillTime();
        #endif /* (UsPWM_KillModeMinTime) */

        #if(UsPWM_UseControl)
            UsPWM_backup.PWMControlRegister = UsPWM_ReadControlRegister();
        #endif /* (UsPWM_UseControl) */
    #endif  /* (!UsPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: UsPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UsPWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void UsPWM_RestoreConfig(void) 
{
        #if(!UsPWM_UsingFixedFunction)
            #if(!UsPWM_PWMModeIsCenterAligned)
                UsPWM_WritePeriod(UsPWM_backup.PWMPeriod);
            #endif /* (!UsPWM_PWMModeIsCenterAligned) */

            UsPWM_WriteCounter(UsPWM_backup.PWMUdb);

            #if (UsPWM_UseStatus)
                UsPWM_STATUS_MASK = UsPWM_backup.InterruptMaskValue;
            #endif /* (UsPWM_UseStatus) */

            #if(UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_256_CLOCKS || \
                UsPWM_DeadBandMode == UsPWM__B_PWM__DBM_2_4_CLOCKS)
                UsPWM_WriteDeadTime(UsPWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(UsPWM_KillModeMinTime)
                UsPWM_WriteKillTime(UsPWM_backup.PWMKillCounterPeriod);
            #endif /* (UsPWM_KillModeMinTime) */

            #if(UsPWM_UseControl)
                UsPWM_WriteControlRegister(UsPWM_backup.PWMControlRegister);
            #endif /* (UsPWM_UseControl) */
        #endif  /* (!UsPWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: UsPWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UsPWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void UsPWM_Sleep(void) 
{
    #if(UsPWM_UseControl)
        if(UsPWM_CTRL_ENABLE == (UsPWM_CONTROL & UsPWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            UsPWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            UsPWM_backup.PWMEnableState = 0u;
        }
    #endif /* (UsPWM_UseControl) */

    /* Stop component */
    UsPWM_Stop();

    /* Save registers configuration */
    UsPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: UsPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UsPWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void UsPWM_Wakeup(void) 
{
     /* Restore registers values */
    UsPWM_RestoreConfig();

    if(UsPWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        UsPWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
