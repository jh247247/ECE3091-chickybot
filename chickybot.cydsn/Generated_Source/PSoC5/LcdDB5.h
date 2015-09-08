/*******************************************************************************
* File Name: LcdDB5.h  
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

#if !defined(CY_PINS_LcdDB5_H) /* Pins LcdDB5_H */
#define CY_PINS_LcdDB5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdDB5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdDB5__PORT == 15 && ((LcdDB5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdDB5_Write(uint8 value) ;
void    LcdDB5_SetDriveMode(uint8 mode) ;
uint8   LcdDB5_ReadDataReg(void) ;
uint8   LcdDB5_Read(void) ;
uint8   LcdDB5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdDB5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdDB5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdDB5_DM_RES_UP          PIN_DM_RES_UP
#define LcdDB5_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdDB5_DM_OD_LO           PIN_DM_OD_LO
#define LcdDB5_DM_OD_HI           PIN_DM_OD_HI
#define LcdDB5_DM_STRONG          PIN_DM_STRONG
#define LcdDB5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdDB5_MASK               LcdDB5__MASK
#define LcdDB5_SHIFT              LcdDB5__SHIFT
#define LcdDB5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdDB5_PS                     (* (reg8 *) LcdDB5__PS)
/* Data Register */
#define LcdDB5_DR                     (* (reg8 *) LcdDB5__DR)
/* Port Number */
#define LcdDB5_PRT_NUM                (* (reg8 *) LcdDB5__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdDB5_AG                     (* (reg8 *) LcdDB5__AG)                       
/* Analog MUX bux enable */
#define LcdDB5_AMUX                   (* (reg8 *) LcdDB5__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdDB5_BIE                    (* (reg8 *) LcdDB5__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdDB5_BIT_MASK               (* (reg8 *) LcdDB5__BIT_MASK)
/* Bypass Enable */
#define LcdDB5_BYP                    (* (reg8 *) LcdDB5__BYP)
/* Port wide control signals */                                                   
#define LcdDB5_CTL                    (* (reg8 *) LcdDB5__CTL)
/* Drive Modes */
#define LcdDB5_DM0                    (* (reg8 *) LcdDB5__DM0) 
#define LcdDB5_DM1                    (* (reg8 *) LcdDB5__DM1)
#define LcdDB5_DM2                    (* (reg8 *) LcdDB5__DM2) 
/* Input Buffer Disable Override */
#define LcdDB5_INP_DIS                (* (reg8 *) LcdDB5__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdDB5_LCD_COM_SEG            (* (reg8 *) LcdDB5__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdDB5_LCD_EN                 (* (reg8 *) LcdDB5__LCD_EN)
/* Slew Rate Control */
#define LcdDB5_SLW                    (* (reg8 *) LcdDB5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdDB5_PRTDSI__CAPS_SEL       (* (reg8 *) LcdDB5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdDB5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdDB5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdDB5_PRTDSI__OE_SEL0        (* (reg8 *) LcdDB5__PRTDSI__OE_SEL0) 
#define LcdDB5_PRTDSI__OE_SEL1        (* (reg8 *) LcdDB5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdDB5_PRTDSI__OUT_SEL0       (* (reg8 *) LcdDB5__PRTDSI__OUT_SEL0) 
#define LcdDB5_PRTDSI__OUT_SEL1       (* (reg8 *) LcdDB5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdDB5_PRTDSI__SYNC_OUT       (* (reg8 *) LcdDB5__PRTDSI__SYNC_OUT) 


#if defined(LcdDB5__INTSTAT)  /* Interrupt Registers */

    #define LcdDB5_INTSTAT                (* (reg8 *) LcdDB5__INTSTAT)
    #define LcdDB5_SNAP                   (* (reg8 *) LcdDB5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdDB5_H */


/* [] END OF FILE */
