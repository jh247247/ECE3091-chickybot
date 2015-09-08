/*******************************************************************************
* File Name: LcdE.h  
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

#if !defined(CY_PINS_LcdE_H) /* Pins LcdE_H */
#define CY_PINS_LcdE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdE__PORT == 15 && ((LcdE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdE_Write(uint8 value) ;
void    LcdE_SetDriveMode(uint8 mode) ;
uint8   LcdE_ReadDataReg(void) ;
uint8   LcdE_Read(void) ;
uint8   LcdE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdE_DM_RES_UP          PIN_DM_RES_UP
#define LcdE_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdE_DM_OD_LO           PIN_DM_OD_LO
#define LcdE_DM_OD_HI           PIN_DM_OD_HI
#define LcdE_DM_STRONG          PIN_DM_STRONG
#define LcdE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdE_MASK               LcdE__MASK
#define LcdE_SHIFT              LcdE__SHIFT
#define LcdE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdE_PS                     (* (reg8 *) LcdE__PS)
/* Data Register */
#define LcdE_DR                     (* (reg8 *) LcdE__DR)
/* Port Number */
#define LcdE_PRT_NUM                (* (reg8 *) LcdE__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdE_AG                     (* (reg8 *) LcdE__AG)                       
/* Analog MUX bux enable */
#define LcdE_AMUX                   (* (reg8 *) LcdE__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdE_BIE                    (* (reg8 *) LcdE__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdE_BIT_MASK               (* (reg8 *) LcdE__BIT_MASK)
/* Bypass Enable */
#define LcdE_BYP                    (* (reg8 *) LcdE__BYP)
/* Port wide control signals */                                                   
#define LcdE_CTL                    (* (reg8 *) LcdE__CTL)
/* Drive Modes */
#define LcdE_DM0                    (* (reg8 *) LcdE__DM0) 
#define LcdE_DM1                    (* (reg8 *) LcdE__DM1)
#define LcdE_DM2                    (* (reg8 *) LcdE__DM2) 
/* Input Buffer Disable Override */
#define LcdE_INP_DIS                (* (reg8 *) LcdE__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdE_LCD_COM_SEG            (* (reg8 *) LcdE__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdE_LCD_EN                 (* (reg8 *) LcdE__LCD_EN)
/* Slew Rate Control */
#define LcdE_SLW                    (* (reg8 *) LcdE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdE_PRTDSI__CAPS_SEL       (* (reg8 *) LcdE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdE_PRTDSI__OE_SEL0        (* (reg8 *) LcdE__PRTDSI__OE_SEL0) 
#define LcdE_PRTDSI__OE_SEL1        (* (reg8 *) LcdE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdE_PRTDSI__OUT_SEL0       (* (reg8 *) LcdE__PRTDSI__OUT_SEL0) 
#define LcdE_PRTDSI__OUT_SEL1       (* (reg8 *) LcdE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdE_PRTDSI__SYNC_OUT       (* (reg8 *) LcdE__PRTDSI__SYNC_OUT) 


#if defined(LcdE__INTSTAT)  /* Interrupt Registers */

    #define LcdE_INTSTAT                (* (reg8 *) LcdE__INTSTAT)
    #define LcdE_SNAP                   (* (reg8 *) LcdE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdE_H */


/* [] END OF FILE */
