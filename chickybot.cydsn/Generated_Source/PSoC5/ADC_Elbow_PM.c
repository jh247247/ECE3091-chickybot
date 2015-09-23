/*******************************************************************************
* File Name: ADC_Elbow_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Elbow.h"


/***************************************
* Local data allocation
***************************************/

static ADC_Elbow_BACKUP_STRUCT  ADC_Elbow_backup =
{
    ADC_Elbow_DISABLED
};


/*******************************************************************************
* Function Name: ADC_Elbow_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Elbow_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Elbow_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Elbow_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Elbow_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_Elbow_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Elbow_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_Elbow_Sleep(void)
{
    if((ADC_Elbow_PWRMGR_SAR_REG  & ADC_Elbow_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_Elbow_SAR_CSR0_REG & ADC_Elbow_SAR_SOF_START_CONV) != 0u)
        {
            ADC_Elbow_backup.enableState = ADC_Elbow_ENABLED | ADC_Elbow_STARTED;
        }
        else
        {
            ADC_Elbow_backup.enableState = ADC_Elbow_ENABLED;
        }
        ADC_Elbow_Stop();
    }
    else
    {
        ADC_Elbow_backup.enableState = ADC_Elbow_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_Elbow_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_Elbow_Sleep() was called. If the component was enabled before the
*  ADC_Elbow_Sleep() function was called, the
*  ADC_Elbow_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Elbow_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_Elbow_Wakeup(void)
{
    if(ADC_Elbow_backup.enableState != ADC_Elbow_DISABLED)
    {
        ADC_Elbow_Enable();
        #if(ADC_Elbow_DEFAULT_CONV_MODE != ADC_Elbow__HARDWARE_TRIGGER)
            if((ADC_Elbow_backup.enableState & ADC_Elbow_STARTED) != 0u)
            {
                ADC_Elbow_StartConvert();
            }
        #endif /* End ADC_Elbow_DEFAULT_CONV_MODE != ADC_Elbow__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
