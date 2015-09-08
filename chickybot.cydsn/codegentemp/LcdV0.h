/*******************************************************************************
* File Name: LcdV0.h  
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

#if !defined(CY_PINS_LcdV0_H) /* Pins LcdV0_H */
#define CY_PINS_LcdV0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LcdV0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LcdV0__PORT == 15 && ((LcdV0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LcdV0_Write(uint8 value) ;
void    LcdV0_SetDriveMode(uint8 mode) ;
uint8   LcdV0_ReadDataReg(void) ;
uint8   LcdV0_Read(void) ;
uint8   LcdV0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LcdV0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LcdV0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LcdV0_DM_RES_UP          PIN_DM_RES_UP
#define LcdV0_DM_RES_DWN         PIN_DM_RES_DWN
#define LcdV0_DM_OD_LO           PIN_DM_OD_LO
#define LcdV0_DM_OD_HI           PIN_DM_OD_HI
#define LcdV0_DM_STRONG          PIN_DM_STRONG
#define LcdV0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LcdV0_MASK               LcdV0__MASK
#define LcdV0_SHIFT              LcdV0__SHIFT
#define LcdV0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LcdV0_PS                     (* (reg8 *) LcdV0__PS)
/* Data Register */
#define LcdV0_DR                     (* (reg8 *) LcdV0__DR)
/* Port Number */
#define LcdV0_PRT_NUM                (* (reg8 *) LcdV0__PRT) 
/* Connect to Analog Globals */                                                  
#define LcdV0_AG                     (* (reg8 *) LcdV0__AG)                       
/* Analog MUX bux enable */
#define LcdV0_AMUX                   (* (reg8 *) LcdV0__AMUX) 
/* Bidirectional Enable */                                                        
#define LcdV0_BIE                    (* (reg8 *) LcdV0__BIE)
/* Bit-mask for Aliased Register Access */
#define LcdV0_BIT_MASK               (* (reg8 *) LcdV0__BIT_MASK)
/* Bypass Enable */
#define LcdV0_BYP                    (* (reg8 *) LcdV0__BYP)
/* Port wide control signals */                                                   
#define LcdV0_CTL                    (* (reg8 *) LcdV0__CTL)
/* Drive Modes */
#define LcdV0_DM0                    (* (reg8 *) LcdV0__DM0) 
#define LcdV0_DM1                    (* (reg8 *) LcdV0__DM1)
#define LcdV0_DM2                    (* (reg8 *) LcdV0__DM2) 
/* Input Buffer Disable Override */
#define LcdV0_INP_DIS                (* (reg8 *) LcdV0__INP_DIS)
/* LCD Common or Segment Drive */
#define LcdV0_LCD_COM_SEG            (* (reg8 *) LcdV0__LCD_COM_SEG)
/* Enable Segment LCD */
#define LcdV0_LCD_EN                 (* (reg8 *) LcdV0__LCD_EN)
/* Slew Rate Control */
#define LcdV0_SLW                    (* (reg8 *) LcdV0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LcdV0_PRTDSI__CAPS_SEL       (* (reg8 *) LcdV0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LcdV0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LcdV0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LcdV0_PRTDSI__OE_SEL0        (* (reg8 *) LcdV0__PRTDSI__OE_SEL0) 
#define LcdV0_PRTDSI__OE_SEL1        (* (reg8 *) LcdV0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LcdV0_PRTDSI__OUT_SEL0       (* (reg8 *) LcdV0__PRTDSI__OUT_SEL0) 
#define LcdV0_PRTDSI__OUT_SEL1       (* (reg8 *) LcdV0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LcdV0_PRTDSI__SYNC_OUT       (* (reg8 *) LcdV0__PRTDSI__SYNC_OUT) 


#if defined(LcdV0__INTSTAT)  /* Interrupt Registers */

    #define LcdV0_INTSTAT                (* (reg8 *) LcdV0__INTSTAT)
    #define LcdV0_SNAP                   (* (reg8 *) LcdV0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LcdV0_H */


/* [] END OF FILE */
