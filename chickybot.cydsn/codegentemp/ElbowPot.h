/*******************************************************************************
* File Name: ElbowPot.h  
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

#if !defined(CY_PINS_ElbowPot_H) /* Pins ElbowPot_H */
#define CY_PINS_ElbowPot_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ElbowPot_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ElbowPot__PORT == 15 && ((ElbowPot__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ElbowPot_Write(uint8 value) ;
void    ElbowPot_SetDriveMode(uint8 mode) ;
uint8   ElbowPot_ReadDataReg(void) ;
uint8   ElbowPot_Read(void) ;
uint8   ElbowPot_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ElbowPot_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ElbowPot_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ElbowPot_DM_RES_UP          PIN_DM_RES_UP
#define ElbowPot_DM_RES_DWN         PIN_DM_RES_DWN
#define ElbowPot_DM_OD_LO           PIN_DM_OD_LO
#define ElbowPot_DM_OD_HI           PIN_DM_OD_HI
#define ElbowPot_DM_STRONG          PIN_DM_STRONG
#define ElbowPot_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ElbowPot_MASK               ElbowPot__MASK
#define ElbowPot_SHIFT              ElbowPot__SHIFT
#define ElbowPot_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ElbowPot_PS                     (* (reg8 *) ElbowPot__PS)
/* Data Register */
#define ElbowPot_DR                     (* (reg8 *) ElbowPot__DR)
/* Port Number */
#define ElbowPot_PRT_NUM                (* (reg8 *) ElbowPot__PRT) 
/* Connect to Analog Globals */                                                  
#define ElbowPot_AG                     (* (reg8 *) ElbowPot__AG)                       
/* Analog MUX bux enable */
#define ElbowPot_AMUX                   (* (reg8 *) ElbowPot__AMUX) 
/* Bidirectional Enable */                                                        
#define ElbowPot_BIE                    (* (reg8 *) ElbowPot__BIE)
/* Bit-mask for Aliased Register Access */
#define ElbowPot_BIT_MASK               (* (reg8 *) ElbowPot__BIT_MASK)
/* Bypass Enable */
#define ElbowPot_BYP                    (* (reg8 *) ElbowPot__BYP)
/* Port wide control signals */                                                   
#define ElbowPot_CTL                    (* (reg8 *) ElbowPot__CTL)
/* Drive Modes */
#define ElbowPot_DM0                    (* (reg8 *) ElbowPot__DM0) 
#define ElbowPot_DM1                    (* (reg8 *) ElbowPot__DM1)
#define ElbowPot_DM2                    (* (reg8 *) ElbowPot__DM2) 
/* Input Buffer Disable Override */
#define ElbowPot_INP_DIS                (* (reg8 *) ElbowPot__INP_DIS)
/* LCD Common or Segment Drive */
#define ElbowPot_LCD_COM_SEG            (* (reg8 *) ElbowPot__LCD_COM_SEG)
/* Enable Segment LCD */
#define ElbowPot_LCD_EN                 (* (reg8 *) ElbowPot__LCD_EN)
/* Slew Rate Control */
#define ElbowPot_SLW                    (* (reg8 *) ElbowPot__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ElbowPot_PRTDSI__CAPS_SEL       (* (reg8 *) ElbowPot__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ElbowPot_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ElbowPot__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ElbowPot_PRTDSI__OE_SEL0        (* (reg8 *) ElbowPot__PRTDSI__OE_SEL0) 
#define ElbowPot_PRTDSI__OE_SEL1        (* (reg8 *) ElbowPot__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ElbowPot_PRTDSI__OUT_SEL0       (* (reg8 *) ElbowPot__PRTDSI__OUT_SEL0) 
#define ElbowPot_PRTDSI__OUT_SEL1       (* (reg8 *) ElbowPot__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ElbowPot_PRTDSI__SYNC_OUT       (* (reg8 *) ElbowPot__PRTDSI__SYNC_OUT) 


#if defined(ElbowPot__INTSTAT)  /* Interrupt Registers */

    #define ElbowPot_INTSTAT                (* (reg8 *) ElbowPot__INTSTAT)
    #define ElbowPot_SNAP                   (* (reg8 *) ElbowPot__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ElbowPot_H */


/* [] END OF FILE */
