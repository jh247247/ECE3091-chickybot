/*******************************************************************************
* File Name: MicroSwitch.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MicroSwitch_H) /* Pins MicroSwitch_H */
#define CY_PINS_MicroSwitch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MicroSwitch_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MicroSwitch__PORT == 15 && ((MicroSwitch__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MicroSwitch_Write(uint8 value) ;
void    MicroSwitch_SetDriveMode(uint8 mode) ;
uint8   MicroSwitch_ReadDataReg(void) ;
uint8   MicroSwitch_Read(void) ;
uint8   MicroSwitch_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MicroSwitch_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MicroSwitch_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MicroSwitch_DM_RES_UP          PIN_DM_RES_UP
#define MicroSwitch_DM_RES_DWN         PIN_DM_RES_DWN
#define MicroSwitch_DM_OD_LO           PIN_DM_OD_LO
#define MicroSwitch_DM_OD_HI           PIN_DM_OD_HI
#define MicroSwitch_DM_STRONG          PIN_DM_STRONG
#define MicroSwitch_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MicroSwitch_MASK               MicroSwitch__MASK
#define MicroSwitch_SHIFT              MicroSwitch__SHIFT
#define MicroSwitch_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MicroSwitch_PS                     (* (reg8 *) MicroSwitch__PS)
/* Data Register */
#define MicroSwitch_DR                     (* (reg8 *) MicroSwitch__DR)
/* Port Number */
#define MicroSwitch_PRT_NUM                (* (reg8 *) MicroSwitch__PRT) 
/* Connect to Analog Globals */                                                  
#define MicroSwitch_AG                     (* (reg8 *) MicroSwitch__AG)                       
/* Analog MUX bux enable */
#define MicroSwitch_AMUX                   (* (reg8 *) MicroSwitch__AMUX) 
/* Bidirectional Enable */                                                        
#define MicroSwitch_BIE                    (* (reg8 *) MicroSwitch__BIE)
/* Bit-mask for Aliased Register Access */
#define MicroSwitch_BIT_MASK               (* (reg8 *) MicroSwitch__BIT_MASK)
/* Bypass Enable */
#define MicroSwitch_BYP                    (* (reg8 *) MicroSwitch__BYP)
/* Port wide control signals */                                                   
#define MicroSwitch_CTL                    (* (reg8 *) MicroSwitch__CTL)
/* Drive Modes */
#define MicroSwitch_DM0                    (* (reg8 *) MicroSwitch__DM0) 
#define MicroSwitch_DM1                    (* (reg8 *) MicroSwitch__DM1)
#define MicroSwitch_DM2                    (* (reg8 *) MicroSwitch__DM2) 
/* Input Buffer Disable Override */
#define MicroSwitch_INP_DIS                (* (reg8 *) MicroSwitch__INP_DIS)
/* LCD Common or Segment Drive */
#define MicroSwitch_LCD_COM_SEG            (* (reg8 *) MicroSwitch__LCD_COM_SEG)
/* Enable Segment LCD */
#define MicroSwitch_LCD_EN                 (* (reg8 *) MicroSwitch__LCD_EN)
/* Slew Rate Control */
#define MicroSwitch_SLW                    (* (reg8 *) MicroSwitch__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MicroSwitch_PRTDSI__CAPS_SEL       (* (reg8 *) MicroSwitch__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MicroSwitch_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MicroSwitch__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MicroSwitch_PRTDSI__OE_SEL0        (* (reg8 *) MicroSwitch__PRTDSI__OE_SEL0) 
#define MicroSwitch_PRTDSI__OE_SEL1        (* (reg8 *) MicroSwitch__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MicroSwitch_PRTDSI__OUT_SEL0       (* (reg8 *) MicroSwitch__PRTDSI__OUT_SEL0) 
#define MicroSwitch_PRTDSI__OUT_SEL1       (* (reg8 *) MicroSwitch__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MicroSwitch_PRTDSI__SYNC_OUT       (* (reg8 *) MicroSwitch__PRTDSI__SYNC_OUT) 


#if defined(MicroSwitch__INTSTAT)  /* Interrupt Registers */

    #define MicroSwitch_INTSTAT                (* (reg8 *) MicroSwitch__INTSTAT)
    #define MicroSwitch_SNAP                   (* (reg8 *) MicroSwitch__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MicroSwitch_H */


/* [] END OF FILE */
