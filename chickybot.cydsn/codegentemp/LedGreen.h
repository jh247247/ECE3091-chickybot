/*******************************************************************************
* File Name: LedGreen.h  
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

#if !defined(CY_PINS_LedGreen_H) /* Pins LedGreen_H */
#define CY_PINS_LedGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LedGreen_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LedGreen__PORT == 15 && ((LedGreen__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LedGreen_Write(uint8 value) ;
void    LedGreen_SetDriveMode(uint8 mode) ;
uint8   LedGreen_ReadDataReg(void) ;
uint8   LedGreen_Read(void) ;
uint8   LedGreen_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LedGreen_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LedGreen_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LedGreen_DM_RES_UP          PIN_DM_RES_UP
#define LedGreen_DM_RES_DWN         PIN_DM_RES_DWN
#define LedGreen_DM_OD_LO           PIN_DM_OD_LO
#define LedGreen_DM_OD_HI           PIN_DM_OD_HI
#define LedGreen_DM_STRONG          PIN_DM_STRONG
#define LedGreen_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LedGreen_MASK               LedGreen__MASK
#define LedGreen_SHIFT              LedGreen__SHIFT
#define LedGreen_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LedGreen_PS                     (* (reg8 *) LedGreen__PS)
/* Data Register */
#define LedGreen_DR                     (* (reg8 *) LedGreen__DR)
/* Port Number */
#define LedGreen_PRT_NUM                (* (reg8 *) LedGreen__PRT) 
/* Connect to Analog Globals */                                                  
#define LedGreen_AG                     (* (reg8 *) LedGreen__AG)                       
/* Analog MUX bux enable */
#define LedGreen_AMUX                   (* (reg8 *) LedGreen__AMUX) 
/* Bidirectional Enable */                                                        
#define LedGreen_BIE                    (* (reg8 *) LedGreen__BIE)
/* Bit-mask for Aliased Register Access */
#define LedGreen_BIT_MASK               (* (reg8 *) LedGreen__BIT_MASK)
/* Bypass Enable */
#define LedGreen_BYP                    (* (reg8 *) LedGreen__BYP)
/* Port wide control signals */                                                   
#define LedGreen_CTL                    (* (reg8 *) LedGreen__CTL)
/* Drive Modes */
#define LedGreen_DM0                    (* (reg8 *) LedGreen__DM0) 
#define LedGreen_DM1                    (* (reg8 *) LedGreen__DM1)
#define LedGreen_DM2                    (* (reg8 *) LedGreen__DM2) 
/* Input Buffer Disable Override */
#define LedGreen_INP_DIS                (* (reg8 *) LedGreen__INP_DIS)
/* LCD Common or Segment Drive */
#define LedGreen_LCD_COM_SEG            (* (reg8 *) LedGreen__LCD_COM_SEG)
/* Enable Segment LCD */
#define LedGreen_LCD_EN                 (* (reg8 *) LedGreen__LCD_EN)
/* Slew Rate Control */
#define LedGreen_SLW                    (* (reg8 *) LedGreen__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LedGreen_PRTDSI__CAPS_SEL       (* (reg8 *) LedGreen__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LedGreen_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LedGreen__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LedGreen_PRTDSI__OE_SEL0        (* (reg8 *) LedGreen__PRTDSI__OE_SEL0) 
#define LedGreen_PRTDSI__OE_SEL1        (* (reg8 *) LedGreen__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LedGreen_PRTDSI__OUT_SEL0       (* (reg8 *) LedGreen__PRTDSI__OUT_SEL0) 
#define LedGreen_PRTDSI__OUT_SEL1       (* (reg8 *) LedGreen__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LedGreen_PRTDSI__SYNC_OUT       (* (reg8 *) LedGreen__PRTDSI__SYNC_OUT) 


#if defined(LedGreen__INTSTAT)  /* Interrupt Registers */

    #define LedGreen_INTSTAT                (* (reg8 *) LedGreen__INTSTAT)
    #define LedGreen_SNAP                   (* (reg8 *) LedGreen__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LedGreen_H */


/* [] END OF FILE */
