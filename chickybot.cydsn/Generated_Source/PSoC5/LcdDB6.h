/*******************************************************************************
* File Name: LcdDB6.h  
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

#if !defined(CY_PINS_LcdDB6_H) /* Pins LcdDB6_H */
#define CY_PINS_LcdDB6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdDB6_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdDB6__PORT == 15 && ((LcdDB6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdDB6_Write(uint8 value) ;
void    LcdDB6_SetDriveMode(uint8 mode) ;
uint8   LcdDB6_ReadDataReg(void) ;
uint8   LcdDB6_Read(void) ;
uint8   LcdDB6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdDB6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdDB6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdDB6_DM_RES_UP          PIN_DM_RES_UP
#define LcdDB6_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdDB6_DM_OD_LO           PIN_DM_OD_LO
#define LcdDB6_DM_OD_HI           PIN_DM_OD_HI
#define LcdDB6_DM_STRONG          PIN_DM_STRONG
#define LcdDB6_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdDB6_MASK               LcdDB6__MASK
#define LcdDB6_SHIFT              LcdDB6__SHIFT
#define LcdDB6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdDB6_PS                     (* (reg8 *) LcdDB6__PS)
/* Data Register */
#define LcdDB6_DR                     (* (reg8 *) LcdDB6__DR)
/* Port Number */
#define LcdDB6_PRT_NUM                (* (reg8 *) LcdDB6__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdDB6_AG                     (* (reg8 *) LcdDB6__AG)                       
/* Analog MUX bux enable */
#define LcdDB6_AMUX                   (* (reg8 *) LcdDB6__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdDB6_BIE                    (* (reg8 *) LcdDB6__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdDB6_BIT_MASK               (* (reg8 *) LcdDB6__BIT_MASK)
/* Bypass Enable */
#define LcdDB6_BYP                    (* (reg8 *) LcdDB6__BYP)
/* Port wide control signals */                                                   
#define LcdDB6_CTL                    (* (reg8 *) LcdDB6__CTL)
/* Drive Modes */
#define LcdDB6_DM0                    (* (reg8 *) LcdDB6__DM0) 
#define LcdDB6_DM1                    (* (reg8 *) LcdDB6__DM1)
#define LcdDB6_DM2                    (* (reg8 *) LcdDB6__DM2) 
/* Input Buffer Disable Override */
#define LcdDB6_INP_DIS                (* (reg8 *) LcdDB6__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdDB6_LCD_COM_SEG            (* (reg8 *) LcdDB6__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdDB6_LCD_EN                 (* (reg8 *) LcdDB6__LCD_EN)
/* Slew Rate Control */
#define LcdDB6_SLW                    (* (reg8 *) LcdDB6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdDB6_PRTDSI__CAPS_SEL       (* (reg8 *) LcdDB6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdDB6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdDB6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdDB6_PRTDSI__OE_SEL0        (* (reg8 *) LcdDB6__PRTDSI__OE_SEL0) 
#define LcdDB6_PRTDSI__OE_SEL1        (* (reg8 *) LcdDB6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdDB6_PRTDSI__OUT_SEL0       (* (reg8 *) LcdDB6__PRTDSI__OUT_SEL0) 
#define LcdDB6_PRTDSI__OUT_SEL1       (* (reg8 *) LcdDB6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdDB6_PRTDSI__SYNC_OUT       (* (reg8 *) LcdDB6__PRTDSI__SYNC_OUT) 


#if defined(LcdDB6__INTSTAT)  /* Interrupt Registers */

    #define LcdDB6_INTSTAT                (* (reg8 *) LcdDB6__INTSTAT)
    #define LcdDB6_SNAP                   (* (reg8 *) LcdDB6__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdDB6_H */


/* [] END OF FILE */
