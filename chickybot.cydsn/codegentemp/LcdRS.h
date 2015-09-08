/*******************************************************************************
* File Name: LcdRS.h  
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

#if !defined(CY_PINS_LcdRS_H) /* Pins LcdRS_H */
#define CY_PINS_LcdRS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdRS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdRS__PORT == 15 && ((LcdRS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdRS_Write(uint8 value) ;
void    LcdRS_SetDriveMode(uint8 mode) ;
uint8   LcdRS_ReadDataReg(void) ;
uint8   LcdRS_Read(void) ;
uint8   LcdRS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdRS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdRS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdRS_DM_RES_UP          PIN_DM_RES_UP
#define LcdRS_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdRS_DM_OD_LO           PIN_DM_OD_LO
#define LcdRS_DM_OD_HI           PIN_DM_OD_HI
#define LcdRS_DM_STRONG          PIN_DM_STRONG
#define LcdRS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdRS_MASK               LcdRS__MASK
#define LcdRS_SHIFT              LcdRS__SHIFT
#define LcdRS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdRS_PS                     (* (reg8 *) LcdRS__PS)
/* Data Register */
#define LcdRS_DR                     (* (reg8 *) LcdRS__DR)
/* Port Number */
#define LcdRS_PRT_NUM                (* (reg8 *) LcdRS__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdRS_AG                     (* (reg8 *) LcdRS__AG)                       
/* Analog MUX bux enable */
#define LcdRS_AMUX                   (* (reg8 *) LcdRS__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdRS_BIE                    (* (reg8 *) LcdRS__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdRS_BIT_MASK               (* (reg8 *) LcdRS__BIT_MASK)
/* Bypass Enable */
#define LcdRS_BYP                    (* (reg8 *) LcdRS__BYP)
/* Port wide control signals */                                                   
#define LcdRS_CTL                    (* (reg8 *) LcdRS__CTL)
/* Drive Modes */
#define LcdRS_DM0                    (* (reg8 *) LcdRS__DM0) 
#define LcdRS_DM1                    (* (reg8 *) LcdRS__DM1)
#define LcdRS_DM2                    (* (reg8 *) LcdRS__DM2) 
/* Input Buffer Disable Override */
#define LcdRS_INP_DIS                (* (reg8 *) LcdRS__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdRS_LCD_COM_SEG            (* (reg8 *) LcdRS__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdRS_LCD_EN                 (* (reg8 *) LcdRS__LCD_EN)
/* Slew Rate Control */
#define LcdRS_SLW                    (* (reg8 *) LcdRS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdRS_PRTDSI__CAPS_SEL       (* (reg8 *) LcdRS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdRS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdRS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdRS_PRTDSI__OE_SEL0        (* (reg8 *) LcdRS__PRTDSI__OE_SEL0) 
#define LcdRS_PRTDSI__OE_SEL1        (* (reg8 *) LcdRS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdRS_PRTDSI__OUT_SEL0       (* (reg8 *) LcdRS__PRTDSI__OUT_SEL0) 
#define LcdRS_PRTDSI__OUT_SEL1       (* (reg8 *) LcdRS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdRS_PRTDSI__SYNC_OUT       (* (reg8 *) LcdRS__PRTDSI__SYNC_OUT) 


#if defined(LcdRS__INTSTAT)  /* Interrupt Registers */

    #define LcdRS_INTSTAT                (* (reg8 *) LcdRS__INTSTAT)
    #define LcdRS_SNAP                   (* (reg8 *) LcdRS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdRS_H */


/* [] END OF FILE */
