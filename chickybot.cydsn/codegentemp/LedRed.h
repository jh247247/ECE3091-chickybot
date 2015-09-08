/*******************************************************************************
* File Name: LedRed.h  
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

#if !defined(CY_PINS_LedRed_H) /* Pins LedRed_H */
#define CY_PINS_LedRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LedRed_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LedRed__PORT == 15 && ((LedRed__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LedRed_Write(uint8 value) ;
void    LedRed_SetDriveMode(uint8 mode) ;
uint8   LedRed_ReadDataReg(void) ;
uint8   LedRed_Read(void) ;
uint8   LedRed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LedRed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LedRed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LedRed_DM_RES_UP          PIN_DM_RES_UP
#define LedRed_DM_RES_DWN         PIN_DM_RES_DWN
#define LedRed_DM_OD_LO           PIN_DM_OD_LO
#define LedRed_DM_OD_HI           PIN_DM_OD_HI
#define LedRed_DM_STRONG          PIN_DM_STRONG
#define LedRed_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LedRed_MASK               LedRed__MASK
#define LedRed_SHIFT              LedRed__SHIFT
#define LedRed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LedRed_PS                     (* (reg8 *) LedRed__PS)
/* Data Register */
#define LedRed_DR                     (* (reg8 *) LedRed__DR)
/* Port Number */
#define LedRed_PRT_NUM                (* (reg8 *) LedRed__PRT) 
/* Connect to Analog Globals */                                                  
#define LedRed_AG                     (* (reg8 *) LedRed__AG)                       
/* Analog MUX bux enable */
#define LedRed_AMUX                   (* (reg8 *) LedRed__AMUX) 
/* Bidirectional Enable */                                                        
#define LedRed_BIE                    (* (reg8 *) LedRed__BIE)
/* Bit-mask for Aliased Register Access */
#define LedRed_BIT_MASK               (* (reg8 *) LedRed__BIT_MASK)
/* Bypass Enable */
#define LedRed_BYP                    (* (reg8 *) LedRed__BYP)
/* Port wide control signals */                                                   
#define LedRed_CTL                    (* (reg8 *) LedRed__CTL)
/* Drive Modes */
#define LedRed_DM0                    (* (reg8 *) LedRed__DM0) 
#define LedRed_DM1                    (* (reg8 *) LedRed__DM1)
#define LedRed_DM2                    (* (reg8 *) LedRed__DM2) 
/* Input Buffer Disable Override */
#define LedRed_INP_DIS                (* (reg8 *) LedRed__INP_DIS)
/* LCD Common or Segment Drive */
#define LedRed_LCD_COM_SEG            (* (reg8 *) LedRed__LCD_COM_SEG)
/* Enable Segment LCD */
#define LedRed_LCD_EN                 (* (reg8 *) LedRed__LCD_EN)
/* Slew Rate Control */
#define LedRed_SLW                    (* (reg8 *) LedRed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LedRed_PRTDSI__CAPS_SEL       (* (reg8 *) LedRed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LedRed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LedRed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LedRed_PRTDSI__OE_SEL0        (* (reg8 *) LedRed__PRTDSI__OE_SEL0) 
#define LedRed_PRTDSI__OE_SEL1        (* (reg8 *) LedRed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LedRed_PRTDSI__OUT_SEL0       (* (reg8 *) LedRed__PRTDSI__OUT_SEL0) 
#define LedRed_PRTDSI__OUT_SEL1       (* (reg8 *) LedRed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LedRed_PRTDSI__SYNC_OUT       (* (reg8 *) LedRed__PRTDSI__SYNC_OUT) 


#if defined(LedRed__INTSTAT)  /* Interrupt Registers */

    #define LedRed_INTSTAT                (* (reg8 *) LedRed__INTSTAT)
    #define LedRed_SNAP                   (* (reg8 *) LedRed__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LedRed_H */


/* [] END OF FILE */
