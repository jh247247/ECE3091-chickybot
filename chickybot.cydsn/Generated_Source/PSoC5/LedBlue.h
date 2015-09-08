/*******************************************************************************
* File Name: LedBlue.h  
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

#if !defined(CY_PINS_LedBlue_H) /* Pins LedBlue_H */
#define CY_PINS_LedBlue_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LedBlue_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LedBlue__PORT == 15 && ((LedBlue__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LedBlue_Write(uint8 value) ;
void    LedBlue_SetDriveMode(uint8 mode) ;
uint8   LedBlue_ReadDataReg(void) ;
uint8   LedBlue_Read(void) ;
uint8   LedBlue_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LedBlue_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LedBlue_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LedBlue_DM_RES_UP          PIN_DM_RES_UP
#define LedBlue_DM_RES_DWN         PIN_DM_RES_DWN
#define LedBlue_DM_OD_LO           PIN_DM_OD_LO
#define LedBlue_DM_OD_HI           PIN_DM_OD_HI
#define LedBlue_DM_STRONG          PIN_DM_STRONG
#define LedBlue_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LedBlue_MASK               LedBlue__MASK
#define LedBlue_SHIFT              LedBlue__SHIFT
#define LedBlue_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LedBlue_PS                     (* (reg8 *) LedBlue__PS)
/* Data Register */
#define LedBlue_DR                     (* (reg8 *) LedBlue__DR)
/* Port Number */
#define LedBlue_PRT_NUM                (* (reg8 *) LedBlue__PRT) 
/* Connect to Analog Globals */                                                  
#define LedBlue_AG                     (* (reg8 *) LedBlue__AG)                       
/* Analog MUX bux enable */
#define LedBlue_AMUX                   (* (reg8 *) LedBlue__AMUX) 
/* Bidirectional Enable */                                                        
#define LedBlue_BIE                    (* (reg8 *) LedBlue__BIE)
/* Bit-mask for Aliased Register Access */
#define LedBlue_BIT_MASK               (* (reg8 *) LedBlue__BIT_MASK)
/* Bypass Enable */
#define LedBlue_BYP                    (* (reg8 *) LedBlue__BYP)
/* Port wide control signals */                                                   
#define LedBlue_CTL                    (* (reg8 *) LedBlue__CTL)
/* Drive Modes */
#define LedBlue_DM0                    (* (reg8 *) LedBlue__DM0) 
#define LedBlue_DM1                    (* (reg8 *) LedBlue__DM1)
#define LedBlue_DM2                    (* (reg8 *) LedBlue__DM2) 
/* Input Buffer Disable Override */
#define LedBlue_INP_DIS                (* (reg8 *) LedBlue__INP_DIS)
/* LCD Common or Segment Drive */
#define LedBlue_LCD_COM_SEG            (* (reg8 *) LedBlue__LCD_COM_SEG)
/* Enable Segment LCD */
#define LedBlue_LCD_EN                 (* (reg8 *) LedBlue__LCD_EN)
/* Slew Rate Control */
#define LedBlue_SLW                    (* (reg8 *) LedBlue__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LedBlue_PRTDSI__CAPS_SEL       (* (reg8 *) LedBlue__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LedBlue_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LedBlue__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LedBlue_PRTDSI__OE_SEL0        (* (reg8 *) LedBlue__PRTDSI__OE_SEL0) 
#define LedBlue_PRTDSI__OE_SEL1        (* (reg8 *) LedBlue__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LedBlue_PRTDSI__OUT_SEL0       (* (reg8 *) LedBlue__PRTDSI__OUT_SEL0) 
#define LedBlue_PRTDSI__OUT_SEL1       (* (reg8 *) LedBlue__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LedBlue_PRTDSI__SYNC_OUT       (* (reg8 *) LedBlue__PRTDSI__SYNC_OUT) 


#if defined(LedBlue__INTSTAT)  /* Interrupt Registers */

    #define LedBlue_INTSTAT                (* (reg8 *) LedBlue__INTSTAT)
    #define LedBlue_SNAP                   (* (reg8 *) LedBlue__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LedBlue_H */


/* [] END OF FILE */
