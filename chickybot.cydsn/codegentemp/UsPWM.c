/*******************************************************************************
* File Name: UsPWM.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "UsPWM.h"

/* Error message for removed <resource> through optimization */
#ifdef UsPWM_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* UsPWM_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 UsPWM_initVar = 0u;


/*******************************************************************************
* Function Name: UsPWM_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UsPWM_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void UsPWM_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(UsPWM_initVar == 0u)
    {
        UsPWM_Init();
        UsPWM_initVar = 1u;
    }
    UsPWM_Enable();

}


/*******************************************************************************
* Function Name: UsPWM_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  UsPWM_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UsPWM_Init(void) 
{
    #if (UsPWM_UsingFixedFunction || UsPWM_UseControl)
        uint8 ctrl;
    #endif /* (UsPWM_UsingFixedFunction || UsPWM_UseControl) */

    #if(!UsPWM_UsingFixedFunction)
        #if(UsPWM_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 UsPWM_interruptState;
        #endif /* (UsPWM_UseStatus) */
    #endif /* (!UsPWM_UsingFixedFunction) */

    #if (UsPWM_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        UsPWM_CONTROL |= UsPWM_CFG0_MODE;
        #if (UsPWM_DeadBand2_4)
            UsPWM_CONTROL |= UsPWM_CFG0_DB;
        #endif /* (UsPWM_DeadBand2_4) */

        ctrl = UsPWM_CONTROL3 & ((uint8 )(~UsPWM_CTRL_CMPMODE1_MASK));
        UsPWM_CONTROL3 = ctrl | UsPWM_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        UsPWM_RT1 &= ((uint8)(~UsPWM_RT1_MASK));
        UsPWM_RT1 |= UsPWM_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        UsPWM_RT1 &= ((uint8)(~UsPWM_SYNCDSI_MASK));
        UsPWM_RT1 |= UsPWM_SYNCDSI_EN;

    #elif (UsPWM_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = UsPWM_CONTROL & ((uint8)(~UsPWM_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~UsPWM_CTRL_CMPMODE1_MASK));
        UsPWM_CONTROL = ctrl | UsPWM_DEFAULT_COMPARE2_MODE |
                                   UsPWM_DEFAULT_COMPARE1_MODE;
    #endif /* (UsPWM_UsingFixedFunction) */

    #if (!UsPWM_UsingFixedFunction)
        #if (UsPWM_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            UsPWM_AUX_CONTROLDP0 |= (UsPWM_AUX_CTRL_FIFO0_CLR);
        #else /* (UsPWM_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            UsPWM_AUX_CONTROLDP0 |= (UsPWM_AUX_CTRL_FIFO0_CLR);
            UsPWM_AUX_CONTROLDP1 |= (UsPWM_AUX_CTRL_FIFO0_CLR);
        #endif /* (UsPWM_Resolution == 8) */

        UsPWM_WriteCounter(UsPWM_INIT_PERIOD_VALUE);
    #endif /* (!UsPWM_UsingFixedFunction) */

    UsPWM_WritePeriod(UsPWM_INIT_PERIOD_VALUE);

        #if (UsPWM_UseOneCompareMode)
            UsPWM_WriteCompare(UsPWM_INIT_COMPARE_VALUE1);
        #else
            UsPWM_WriteCompare1(UsPWM_INIT_COMPARE_VALUE1);
            UsPWM_WriteCompare2(UsPWM_INIT_COMPARE_VALUE2);
        #endif /* (UsPWM_UseOneCompareMode) */

        #if (UsPWM_KillModeMinTime)
            UsPWM_WriteKillTime(UsPWM_MinimumKillTime);
        #endif /* (UsPWM_KillModeMinTime) */

        #if (UsPWM_DeadBandUsed)
            UsPWM_WriteDeadTime(UsPWM_INIT_DEAD_TIME);
        #endif /* (UsPWM_DeadBandUsed) */

    #if (UsPWM_UseStatus || UsPWM_UsingFixedFunction)
        UsPWM_SetInterruptMode(UsPWM_INIT_INTERRUPTS_MODE);
    #endif /* (UsPWM_UseStatus || UsPWM_UsingFixedFunction) */

    #if (UsPWM_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        UsPWM_GLOBAL_ENABLE |= UsPWM_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        UsPWM_CONTROL2 |= UsPWM_CTRL2_IRQ_SEL;
    #else
        #if(UsPWM_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            UsPWM_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            UsPWM_STATUS_AUX_CTRL |= UsPWM_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(UsPWM_interruptState);

            /* Clear the FIFO to enable the UsPWM_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            UsPWM_ClearFIFO();
        #endif /* (UsPWM_UseStatus) */
    #endif /* (UsPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: UsPWM_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void UsPWM_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (UsPWM_UsingFixedFunction)
        UsPWM_GLOBAL_ENABLE |= UsPWM_BLOCK_EN_MASK;
        UsPWM_GLOBAL_STBY_ENABLE |= UsPWM_BLOCK_STBY_EN_MASK;
    #endif /* (UsPWM_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (UsPWM_UseControl || UsPWM_UsingFixedFunction)
        UsPWM_CONTROL |= UsPWM_CTRL_ENABLE;
    #endif /* (UsPWM_UseControl || UsPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: UsPWM_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void UsPWM_Stop(void) 
{
    #if (UsPWM_UseControl || UsPWM_UsingFixedFunction)
        UsPWM_CONTROL &= ((uint8)(~UsPWM_CTRL_ENABLE));
    #endif /* (UsPWM_UseControl || UsPWM_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (UsPWM_UsingFixedFunction)
        UsPWM_GLOBAL_ENABLE &= ((uint8)(~UsPWM_BLOCK_EN_MASK));
        UsPWM_GLOBAL_STBY_ENABLE &= ((uint8)(~UsPWM_BLOCK_STBY_EN_MASK));
    #endif /* (UsPWM_UsingFixedFunction) */
}

#if (UsPWM_UseOneCompareMode)
    #if (UsPWM_CompareMode1SW)


        /*******************************************************************************
        * Function Name: UsPWM_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void UsPWM_SetCompareMode(uint8 comparemode) 
        {
            #if(UsPWM_UsingFixedFunction)

                #if(0 != UsPWM_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << UsPWM_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != UsPWM_CTRL_CMPMODE1_SHIFT) */

                UsPWM_CONTROL3 &= ((uint8)(~UsPWM_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                UsPWM_CONTROL3 |= comparemodemasked;

            #elif (UsPWM_UseControl)

                #if(0 != UsPWM_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << UsPWM_CTRL_CMPMODE1_SHIFT)) &
                                                UsPWM_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & UsPWM_CTRL_CMPMODE1_MASK;
                #endif /* (0 != UsPWM_CTRL_CMPMODE1_SHIFT) */

                #if(0 != UsPWM_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << UsPWM_CTRL_CMPMODE2_SHIFT)) &
                                               UsPWM_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & UsPWM_CTRL_CMPMODE2_MASK;
                #endif /* (0 != UsPWM_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                UsPWM_CONTROL &= ((uint8)(~(UsPWM_CTRL_CMPMODE1_MASK |
                                            UsPWM_CTRL_CMPMODE2_MASK)));
                UsPWM_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (UsPWM_UsingFixedFunction) */
        }
    #endif /* UsPWM_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (UsPWM_CompareMode1SW)


        /*******************************************************************************
        * Function Name: UsPWM_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void UsPWM_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != UsPWM_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << UsPWM_CTRL_CMPMODE1_SHIFT)) &
                                           UsPWM_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & UsPWM_CTRL_CMPMODE1_MASK;
            #endif /* (0 != UsPWM_CTRL_CMPMODE1_SHIFT) */

            #if (UsPWM_UseControl)
                UsPWM_CONTROL &= ((uint8)(~UsPWM_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                UsPWM_CONTROL |= comparemodemasked;
            #endif /* (UsPWM_UseControl) */
        }
    #endif /* UsPWM_CompareMode1SW */

#if (UsPWM_CompareMode2SW)


    /*******************************************************************************
    * Function Name: UsPWM_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != UsPWM_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << UsPWM_CTRL_CMPMODE2_SHIFT)) &
                                                 UsPWM_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & UsPWM_CTRL_CMPMODE2_MASK;
        #endif /* (0 != UsPWM_CTRL_CMPMODE2_SHIFT) */

        #if (UsPWM_UseControl)
            UsPWM_CONTROL &= ((uint8)(~UsPWM_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            UsPWM_CONTROL |= comparemodemasked;
        #endif /* (UsPWM_UseControl) */
    }
    #endif /*UsPWM_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!UsPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: UsPWM_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void UsPWM_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(UsPWM_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: UsPWM_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 UsPWM_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(UsPWM_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(UsPWM_CAPTURE_LSB_PTR));
    }

    #if (UsPWM_UseStatus)


        /*******************************************************************************
        * Function Name: UsPWM_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void UsPWM_ClearFIFO(void) 
        {
            while(0u != (UsPWM_ReadStatusRegister() & UsPWM_STATUS_FIFONEMPTY))
            {
                (void)UsPWM_ReadCapture();
            }
        }

    #endif /* UsPWM_UseStatus */

#endif /* !UsPWM_UsingFixedFunction */


/*******************************************************************************
* Function Name: UsPWM_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void UsPWM_WritePeriod(uint16 period) 
{
    #if(UsPWM_UsingFixedFunction)
        CY_SET_REG16(UsPWM_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(UsPWM_PERIOD_LSB_PTR, period);
    #endif /* (UsPWM_UsingFixedFunction) */
}

#if (UsPWM_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: UsPWM_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void UsPWM_WriteCompare(uint16 compare) \
                                       
    {
        #if(UsPWM_UsingFixedFunction)
            CY_SET_REG16(UsPWM_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(UsPWM_COMPARE1_LSB_PTR, compare);
        #endif /* (UsPWM_UsingFixedFunction) */

        #if (UsPWM_PWMMode == UsPWM__B_PWM__DITHER)
            #if(UsPWM_UsingFixedFunction)
                CY_SET_REG16(UsPWM_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(UsPWM_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (UsPWM_UsingFixedFunction) */
        #endif /* (UsPWM_PWMMode == UsPWM__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: UsPWM_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_WriteCompare1(uint16 compare) \
                                        
    {
        #if(UsPWM_UsingFixedFunction)
            CY_SET_REG16(UsPWM_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(UsPWM_COMPARE1_LSB_PTR, compare);
        #endif /* (UsPWM_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: UsPWM_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_WriteCompare2(uint16 compare) \
                                        
    {
        #if(UsPWM_UsingFixedFunction)
            CY_SET_REG16(UsPWM_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(UsPWM_COMPARE2_LSB_PTR, compare);
        #endif /* (UsPWM_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (UsPWM_DeadBandUsed)


    /*******************************************************************************
    * Function Name: UsPWM_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!UsPWM_DeadBand2_4)
            CY_SET_REG8(UsPWM_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            UsPWM_DEADBAND_COUNT &= ((uint8)(~UsPWM_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(UsPWM_DEADBAND_COUNT_SHIFT)
                UsPWM_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << UsPWM_DEADBAND_COUNT_SHIFT)) &
                                                    UsPWM_DEADBAND_COUNT_MASK;
            #else
                UsPWM_DEADBAND_COUNT |= deadtime & UsPWM_DEADBAND_COUNT_MASK;
            #endif /* (UsPWM_DEADBAND_COUNT_SHIFT) */

        #endif /* (!UsPWM_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: UsPWM_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 UsPWM_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!UsPWM_DeadBand2_4)
            return (CY_GET_REG8(UsPWM_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(UsPWM_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(UsPWM_DEADBAND_COUNT & UsPWM_DEADBAND_COUNT_MASK)) >>
                                                                           UsPWM_DEADBAND_COUNT_SHIFT));
            #else
                return (UsPWM_DEADBAND_COUNT & UsPWM_DEADBAND_COUNT_MASK);
            #endif /* (UsPWM_DEADBAND_COUNT_SHIFT) */
        #endif /* (!UsPWM_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (UsPWM_UseStatus || UsPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: UsPWM_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(UsPWM_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: UsPWM_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 UsPWM_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(UsPWM_STATUS_PTR));
    }

#endif /* (UsPWM_UseStatus || UsPWM_UsingFixedFunction) */


#if (UsPWM_UseControl)


    /*******************************************************************************
    * Function Name: UsPWM_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 UsPWM_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(UsPWM_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: UsPWM_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(UsPWM_CONTROL_PTR, control);
    }

#endif /* (UsPWM_UseControl) */


#if (!UsPWM_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: UsPWM_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 UsPWM_ReadCapture(void) 
    {
        return (CY_GET_REG16(UsPWM_CAPTURE_LSB_PTR));
    }

#endif /* (!UsPWM_UsingFixedFunction) */


#if (UsPWM_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: UsPWM_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 UsPWM_ReadCompare(void) 
    {
        #if(UsPWM_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(UsPWM_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(UsPWM_COMPARE1_LSB_PTR));
        #endif /* (UsPWM_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: UsPWM_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 UsPWM_ReadCompare1(void) 
    {
        return (CY_GET_REG16(UsPWM_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: UsPWM_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 UsPWM_ReadCompare2(void) 
    {
        return (CY_GET_REG16(UsPWM_COMPARE2_LSB_PTR));
    }

#endif /* (UsPWM_UseOneCompareMode) */


/*******************************************************************************
* Function Name: UsPWM_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 UsPWM_ReadPeriod(void) 
{
    #if(UsPWM_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(UsPWM_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(UsPWM_PERIOD_LSB_PTR));
    #endif /* (UsPWM_UsingFixedFunction) */
}

#if ( UsPWM_KillModeMinTime)


    /*******************************************************************************
    * Function Name: UsPWM_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UsPWM_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(UsPWM_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: UsPWM_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 UsPWM_ReadKillTime(void) 
    {
        return (CY_GET_REG8(UsPWM_KILLMODEMINTIME_PTR));
    }

#endif /* ( UsPWM_KillModeMinTime) */

/* [] END OF FILE */
