/*******************************************************************************
* File Name: LedYellow.h  
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

#if !defined(CY_PINS_LedYellow_H) /* Pins LedYellow_H */
#define CY_PINS_LedYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LedYellow_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LedYellow__PORT == 15 && ((LedYellow__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LedYellow_Write(uint8 value) ;
void    LedYellow_SetDriveMode(uint8 mode) ;
uint8   LedYellow_ReadDataReg(void) ;
uint8   LedYellow_Read(void) ;
uint8   LedYellow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LedYellow_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LedYellow_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LedYellow_DM_RES_UP          PIN_DM_RES_UP
#define LedYellow_DM_RES_DWN         PIN_DM_RES_DWN
#define LedYellow_DM_OD_LO           PIN_DM_OD_LO
#define LedYellow_DM_OD_HI           PIN_DM_OD_HI
#define LedYellow_DM_STRONG          PIN_DM_STRONG
#define LedYellow_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LedYellow_MASK               LedYellow__MASK
#define LedYellow_SHIFT              LedYellow__SHIFT
#define LedYellow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LedYellow_PS                     (* (reg8 *) LedYellow__PS)
/* Data Register */
#define LedYellow_DR                     (* (reg8 *) LedYellow__DR)
/* Port Number */
#define LedYellow_PRT_NUM                (* (reg8 *) LedYellow__PRT) 
/* Connect to Analog Globals */                                                  
#define LedYellow_AG                     (* (reg8 *) LedYellow__AG)                       
/* Analog MUX bux enable */
#define LedYellow_AMUX                   (* (reg8 *) LedYellow__AMUX) 
/* Bidirectional Enable */                                                        
#define LedYellow_BIE                    (* (reg8 *) LedYellow__BIE)
/* Bit-mask for Aliased Register Access */
#define LedYellow_BIT_MASK               (* (reg8 *) LedYellow__BIT_MASK)
/* Bypass Enable */
#define LedYellow_BYP                    (* (reg8 *) LedYellow__BYP)
/* Port wide control signals */                                                   
#define LedYellow_CTL                    (* (reg8 *) LedYellow__CTL)
/* Drive Modes */
#define LedYellow_DM0                    (* (reg8 *) LedYellow__DM0) 
#define LedYellow_DM1                    (* (reg8 *) LedYellow__DM1)
#define LedYellow_DM2                    (* (reg8 *) LedYellow__DM2) 
/* Input Buffer Disable Override */
#define LedYellow_INP_DIS                (* (reg8 *) LedYellow__INP_DIS)
/* LCD Common or Segment Drive */
#define LedYellow_LCD_COM_SEG            (* (reg8 *) LedYellow__LCD_COM_SEG)
/* Enable Segment LCD */
#define LedYellow_LCD_EN                 (* (reg8 *) LedYellow__LCD_EN)
/* Slew Rate Control */
#define LedYellow_SLW                    (* (reg8 *) LedYellow__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LedYellow_PRTDSI__CAPS_SEL       (* (reg8 *) LedYellow__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LedYellow_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LedYellow__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LedYellow_PRTDSI__OE_SEL0        (* (reg8 *) LedYellow__PRTDSI__OE_SEL0) 
#define LedYellow_PRTDSI__OE_SEL1        (* (reg8 *) LedYellow__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LedYellow_PRTDSI__OUT_SEL0       (* (reg8 *) LedYellow__PRTDSI__OUT_SEL0) 
#define LedYellow_PRTDSI__OUT_SEL1       (* (reg8 *) LedYellow__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LedYellow_PRTDSI__SYNC_OUT       (* (reg8 *) LedYellow__PRTDSI__SYNC_OUT) 


#if defined(LedYellow__INTSTAT)  /* Interrupt Registers */

    #define LedYellow_INTSTAT                (* (reg8 *) LedYellow__INTSTAT)
    #define LedYellow_SNAP                   (* (reg8 *) LedYellow__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LedYellow_H */


/* [] END OF FILE */
