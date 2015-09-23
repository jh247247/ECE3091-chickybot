/*******************************************************************************
* File Name: RotateCCW.h  
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

#if !defined(CY_PINS_RotateCCW_H) /* Pins RotateCCW_H */
#define CY_PINS_RotateCCW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotateCCW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotateCCW__PORT == 15 && ((RotateCCW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotateCCW_Write(uint8 value) ;
void    RotateCCW_SetDriveMode(uint8 mode) ;
uint8   RotateCCW_ReadDataReg(void) ;
uint8   RotateCCW_Read(void) ;
uint8   RotateCCW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotateCCW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotateCCW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotateCCW_DM_RES_UP          PIN_DM_RES_UP
#define RotateCCW_DM_RES_DWN         PIN_DM_RES_DWN
#define RotateCCW_DM_OD_LO           PIN_DM_OD_LO
#define RotateCCW_DM_OD_HI           PIN_DM_OD_HI
#define RotateCCW_DM_STRONG          PIN_DM_STRONG
#define RotateCCW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotateCCW_MASK               RotateCCW__MASK
#define RotateCCW_SHIFT              RotateCCW__SHIFT
#define RotateCCW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotateCCW_PS                     (* (reg8 *) RotateCCW__PS)
/* Data Register */
#define RotateCCW_DR                     (* (reg8 *) RotateCCW__DR)
/* Port Number */
#define RotateCCW_PRT_NUM                (* (reg8 *) RotateCCW__PRT) 
/* Connect to Analog Globals */                                                  
#define RotateCCW_AG                     (* (reg8 *) RotateCCW__AG)                       
/* Analog MUX bux enable */
#define RotateCCW_AMUX                   (* (reg8 *) RotateCCW__AMUX) 
/* Bidirectional Enable */                                                        
#define RotateCCW_BIE                    (* (reg8 *) RotateCCW__BIE)
/* Bit-mask for Aliased Register Access */
#define RotateCCW_BIT_MASK               (* (reg8 *) RotateCCW__BIT_MASK)
/* Bypass Enable */
#define RotateCCW_BYP                    (* (reg8 *) RotateCCW__BYP)
/* Port wide control signals */                                                   
#define RotateCCW_CTL                    (* (reg8 *) RotateCCW__CTL)
/* Drive Modes */
#define RotateCCW_DM0                    (* (reg8 *) RotateCCW__DM0) 
#define RotateCCW_DM1                    (* (reg8 *) RotateCCW__DM1)
#define RotateCCW_DM2                    (* (reg8 *) RotateCCW__DM2) 
/* Input Buffer Disable Override */
#define RotateCCW_INP_DIS                (* (reg8 *) RotateCCW__INP_DIS)
/* LCD Common or Segment Drive */
#define RotateCCW_LCD_COM_SEG            (* (reg8 *) RotateCCW__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotateCCW_LCD_EN                 (* (reg8 *) RotateCCW__LCD_EN)
/* Slew Rate Control */
#define RotateCCW_SLW                    (* (reg8 *) RotateCCW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotateCCW_PRTDSI__CAPS_SEL       (* (reg8 *) RotateCCW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotateCCW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotateCCW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotateCCW_PRTDSI__OE_SEL0        (* (reg8 *) RotateCCW__PRTDSI__OE_SEL0) 
#define RotateCCW_PRTDSI__OE_SEL1        (* (reg8 *) RotateCCW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotateCCW_PRTDSI__OUT_SEL0       (* (reg8 *) RotateCCW__PRTDSI__OUT_SEL0) 
#define RotateCCW_PRTDSI__OUT_SEL1       (* (reg8 *) RotateCCW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotateCCW_PRTDSI__SYNC_OUT       (* (reg8 *) RotateCCW__PRTDSI__SYNC_OUT) 


#if defined(RotateCCW__INTSTAT)  /* Interrupt Registers */

    #define RotateCCW_INTSTAT                (* (reg8 *) RotateCCW__INTSTAT)
    #define RotateCCW_SNAP                   (* (reg8 *) RotateCCW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotateCCW_H */


/* [] END OF FILE */
