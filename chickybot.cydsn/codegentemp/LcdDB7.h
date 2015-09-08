/*******************************************************************************
* File Name: LcdDB7.h  
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

#if !defined(CY_PINS_LcdDB7_H) /* Pins LcdDB7_H */
#define CY_PINS_LcdDB7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdDB7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdDB7__PORT == 15 && ((LcdDB7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdDB7_Write(uint8 value) ;
void    LcdDB7_SetDriveMode(uint8 mode) ;
uint8   LcdDB7_ReadDataReg(void) ;
uint8   LcdDB7_Read(void) ;
uint8   LcdDB7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdDB7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdDB7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdDB7_DM_RES_UP          PIN_DM_RES_UP
#define LcdDB7_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdDB7_DM_OD_LO           PIN_DM_OD_LO
#define LcdDB7_DM_OD_HI           PIN_DM_OD_HI
#define LcdDB7_DM_STRONG          PIN_DM_STRONG
#define LcdDB7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdDB7_MASK               LcdDB7__MASK
#define LcdDB7_SHIFT              LcdDB7__SHIFT
#define LcdDB7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdDB7_PS                     (* (reg8 *) LcdDB7__PS)
/* Data Register */
#define LcdDB7_DR                     (* (reg8 *) LcdDB7__DR)
/* Port Number */
#define LcdDB7_PRT_NUM                (* (reg8 *) LcdDB7__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdDB7_AG                     (* (reg8 *) LcdDB7__AG)                       
/* Analog MUX bux enable */
#define LcdDB7_AMUX                   (* (reg8 *) LcdDB7__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdDB7_BIE                    (* (reg8 *) LcdDB7__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdDB7_BIT_MASK               (* (reg8 *) LcdDB7__BIT_MASK)
/* Bypass Enable */
#define LcdDB7_BYP                    (* (reg8 *) LcdDB7__BYP)
/* Port wide control signals */                                                   
#define LcdDB7_CTL                    (* (reg8 *) LcdDB7__CTL)
/* Drive Modes */
#define LcdDB7_DM0                    (* (reg8 *) LcdDB7__DM0) 
#define LcdDB7_DM1                    (* (reg8 *) LcdDB7__DM1)
#define LcdDB7_DM2                    (* (reg8 *) LcdDB7__DM2) 
/* Input Buffer Disable Override */
#define LcdDB7_INP_DIS                (* (reg8 *) LcdDB7__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdDB7_LCD_COM_SEG            (* (reg8 *) LcdDB7__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdDB7_LCD_EN                 (* (reg8 *) LcdDB7__LCD_EN)
/* Slew Rate Control */
#define LcdDB7_SLW                    (* (reg8 *) LcdDB7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdDB7_PRTDSI__CAPS_SEL       (* (reg8 *) LcdDB7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdDB7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdDB7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdDB7_PRTDSI__OE_SEL0        (* (reg8 *) LcdDB7__PRTDSI__OE_SEL0) 
#define LcdDB7_PRTDSI__OE_SEL1        (* (reg8 *) LcdDB7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdDB7_PRTDSI__OUT_SEL0       (* (reg8 *) LcdDB7__PRTDSI__OUT_SEL0) 
#define LcdDB7_PRTDSI__OUT_SEL1       (* (reg8 *) LcdDB7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdDB7_PRTDSI__SYNC_OUT       (* (reg8 *) LcdDB7__PRTDSI__SYNC_OUT) 


#if defined(LcdDB7__INTSTAT)  /* Interrupt Registers */

    #define LcdDB7_INTSTAT                (* (reg8 *) LcdDB7__INTSTAT)
    #define LcdDB7_SNAP                   (* (reg8 *) LcdDB7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdDB7_H */


/* [] END OF FILE */
