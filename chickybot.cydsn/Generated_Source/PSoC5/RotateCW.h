/*******************************************************************************
* File Name: RotateCW.h  
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

#if !defined(CY_PINS_RotateCW_H) /* Pins RotateCW_H */
#define CY_PINS_RotateCW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RotateCW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RotateCW__PORT == 15 && ((RotateCW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RotateCW_Write(uint8 value) ;
void    RotateCW_SetDriveMode(uint8 mode) ;
uint8   RotateCW_ReadDataReg(void) ;
uint8   RotateCW_Read(void) ;
uint8   RotateCW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RotateCW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RotateCW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RotateCW_DM_RES_UP          PIN_DM_RES_UP
#define RotateCW_DM_RES_DWN         PIN_DM_RES_DWN
#define RotateCW_DM_OD_LO           PIN_DM_OD_LO
#define RotateCW_DM_OD_HI           PIN_DM_OD_HI
#define RotateCW_DM_STRONG          PIN_DM_STRONG
#define RotateCW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RotateCW_MASK               RotateCW__MASK
#define RotateCW_SHIFT              RotateCW__SHIFT
#define RotateCW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RotateCW_PS                     (* (reg8 *) RotateCW__PS)
/* Data Register */
#define RotateCW_DR                     (* (reg8 *) RotateCW__DR)
/* Port Number */
#define RotateCW_PRT_NUM                (* (reg8 *) RotateCW__PRT) 
/* Connect to Analog Globals */                                                  
#define RotateCW_AG                     (* (reg8 *) RotateCW__AG)                       
/* Analog MUX bux enable */
#define RotateCW_AMUX                   (* (reg8 *) RotateCW__AMUX) 
/* Bidirectional Enable */                                                        
#define RotateCW_BIE                    (* (reg8 *) RotateCW__BIE)
/* Bit-mask for Aliased Register Access */
#define RotateCW_BIT_MASK               (* (reg8 *) RotateCW__BIT_MASK)
/* Bypass Enable */
#define RotateCW_BYP                    (* (reg8 *) RotateCW__BYP)
/* Port wide control signals */                                                   
#define RotateCW_CTL                    (* (reg8 *) RotateCW__CTL)
/* Drive Modes */
#define RotateCW_DM0                    (* (reg8 *) RotateCW__DM0) 
#define RotateCW_DM1                    (* (reg8 *) RotateCW__DM1)
#define RotateCW_DM2                    (* (reg8 *) RotateCW__DM2) 
/* Input Buffer Disable Override */
#define RotateCW_INP_DIS                (* (reg8 *) RotateCW__INP_DIS)
/* LCD Common or Segment Drive */
#define RotateCW_LCD_COM_SEG            (* (reg8 *) RotateCW__LCD_COM_SEG)
/* Enable Segment LCD */
#define RotateCW_LCD_EN                 (* (reg8 *) RotateCW__LCD_EN)
/* Slew Rate Control */
#define RotateCW_SLW                    (* (reg8 *) RotateCW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RotateCW_PRTDSI__CAPS_SEL       (* (reg8 *) RotateCW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RotateCW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RotateCW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RotateCW_PRTDSI__OE_SEL0        (* (reg8 *) RotateCW__PRTDSI__OE_SEL0) 
#define RotateCW_PRTDSI__OE_SEL1        (* (reg8 *) RotateCW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RotateCW_PRTDSI__OUT_SEL0       (* (reg8 *) RotateCW__PRTDSI__OUT_SEL0) 
#define RotateCW_PRTDSI__OUT_SEL1       (* (reg8 *) RotateCW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RotateCW_PRTDSI__SYNC_OUT       (* (reg8 *) RotateCW__PRTDSI__SYNC_OUT) 


#if defined(RotateCW__INTSTAT)  /* Interrupt Registers */

    #define RotateCW_INTSTAT                (* (reg8 *) RotateCW__INTSTAT)
    #define RotateCW_SNAP                   (* (reg8 *) RotateCW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RotateCW_H */


/* [] END OF FILE */
