/*******************************************************************************
* File Name: CsBtns_PWM_PM.c
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

#include "CsBtns_PWM.h"

static CsBtns_PWM_backupStruct CsBtns_PWM_backup;


/*******************************************************************************
* Function Name: CsBtns_PWM_SaveConfig
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
*  CsBtns_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void CsBtns_PWM_SaveConfig(void) 
{

    #if(!CsBtns_PWM_UsingFixedFunction)
        #if(!CsBtns_PWM_PWMModeIsCenterAligned)
            CsBtns_PWM_backup.PWMPeriod = CsBtns_PWM_ReadPeriod();
        #endif /* (!CsBtns_PWM_PWMModeIsCenterAligned) */
        CsBtns_PWM_backup.PWMUdb = CsBtns_PWM_ReadCounter();
        #if (CsBtns_PWM_UseStatus)
            CsBtns_PWM_backup.InterruptMaskValue = CsBtns_PWM_STATUS_MASK;
        #endif /* (CsBtns_PWM_UseStatus) */

        #if(CsBtns_PWM_DeadBandMode == CsBtns_PWM__B_PWM__DBM_256_CLOCKS || \
            CsBtns_PWM_DeadBandMode == CsBtns_PWM__B_PWM__DBM_2_4_CLOCKS)
            CsBtns_PWM_backup.PWMdeadBandValue = CsBtns_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(CsBtns_PWM_KillModeMinTime)
             CsBtns_PWM_backup.PWMKillCounterPeriod = CsBtns_PWM_ReadKillTime();
        #endif /* (CsBtns_PWM_KillModeMinTime) */

        #if(CsBtns_PWM_UseControl)
            CsBtns_PWM_backup.PWMControlRegister = CsBtns_PWM_ReadControlRegister();
        #endif /* (CsBtns_PWM_UseControl) */
    #endif  /* (!CsBtns_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CsBtns_PWM_RestoreConfig
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
*  CsBtns_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CsBtns_PWM_RestoreConfig(void) 
{
        #if(!CsBtns_PWM_UsingFixedFunction)
            #if(!CsBtns_PWM_PWMModeIsCenterAligned)
                CsBtns_PWM_WritePeriod(CsBtns_PWM_backup.PWMPeriod);
            #endif /* (!CsBtns_PWM_PWMModeIsCenterAligned) */

            CsBtns_PWM_WriteCounter(CsBtns_PWM_backup.PWMUdb);

            #if (CsBtns_PWM_UseStatus)
                CsBtns_PWM_STATUS_MASK = CsBtns_PWM_backup.InterruptMaskValue;
            #endif /* (CsBtns_PWM_UseStatus) */

            #if(CsBtns_PWM_DeadBandMode == CsBtns_PWM__B_PWM__DBM_256_CLOCKS || \
                CsBtns_PWM_DeadBandMode == CsBtns_PWM__B_PWM__DBM_2_4_CLOCKS)
                CsBtns_PWM_WriteDeadTime(CsBtns_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(CsBtns_PWM_KillModeMinTime)
                CsBtns_PWM_WriteKillTime(CsBtns_PWM_backup.PWMKillCounterPeriod);
            #endif /* (CsBtns_PWM_KillModeMinTime) */

            #if(CsBtns_PWM_UseControl)
                CsBtns_PWM_WriteControlRegister(CsBtns_PWM_backup.PWMControlRegister);
            #endif /* (CsBtns_PWM_UseControl) */
        #endif  /* (!CsBtns_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: CsBtns_PWM_Sleep
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
*  CsBtns_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void CsBtns_PWM_Sleep(void) 
{
    #if(CsBtns_PWM_UseControl)
        if(CsBtns_PWM_CTRL_ENABLE == (CsBtns_PWM_CONTROL & CsBtns_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            CsBtns_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            CsBtns_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (CsBtns_PWM_UseControl) */

    /* Stop component */
    CsBtns_PWM_Stop();

    /* Save registers configuration */
    CsBtns_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: CsBtns_PWM_Wakeup
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
*  CsBtns_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CsBtns_PWM_Wakeup(void) 
{
     /* Restore registers values */
    CsBtns_PWM_RestoreConfig();

    if(CsBtns_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        CsBtns_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
