/*******************************************************************************
* File Name: UsOutput.h  
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

#if !defined(CY_PINS_UsOutput_H) /* Pins UsOutput_H */
#define CY_PINS_UsOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UsOutput_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UsOutput__PORT == 15 && ((UsOutput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UsOutput_Write(uint8 value) ;
void    UsOutput_SetDriveMode(uint8 mode) ;
uint8   UsOutput_ReadDataReg(void) ;
uint8   UsOutput_Read(void) ;
uint8   UsOutput_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UsOutput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UsOutput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UsOutput_DM_RES_UP          PIN_DM_RES_UP
#define UsOutput_DM_RES_DWN         PIN_DM_RES_DWN
#define UsOutput_DM_OD_LO           PIN_DM_OD_LO
#define UsOutput_DM_OD_HI           PIN_DM_OD_HI
#define UsOutput_DM_STRONG          PIN_DM_STRONG
#define UsOutput_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UsOutput_MASK               UsOutput__MASK
#define UsOutput_SHIFT              UsOutput__SHIFT
#define UsOutput_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UsOutput_PS                     (* (reg8 *) UsOutput__PS)
/* Data Register */
#define UsOutput_DR                     (* (reg8 *) UsOutput__DR)
/* Port Number */
#define UsOutput_PRT_NUM                (* (reg8 *) UsOutput__PRT) 
/* Connect to Analog Globals */                                                  
#define UsOutput_AG                     (* (reg8 *) UsOutput__AG)                       
/* Analog MUX bux enable */
#define UsOutput_AMUX                   (* (reg8 *) UsOutput__AMUX) 
/* Bidirectional Enable */                                                        
#define UsOutput_BIE                    (* (reg8 *) UsOutput__BIE)
/* Bit-mask for Aliased Register Access */
#define UsOutput_BIT_MASK               (* (reg8 *) UsOutput__BIT_MASK)
/* Bypass Enable */
#define UsOutput_BYP                    (* (reg8 *) UsOutput__BYP)
/* Port wide control signals */                                                   
#define UsOutput_CTL                    (* (reg8 *) UsOutput__CTL)
/* Drive Modes */
#define UsOutput_DM0                    (* (reg8 *) UsOutput__DM0) 
#define UsOutput_DM1                    (* (reg8 *) UsOutput__DM1)
#define UsOutput_DM2                    (* (reg8 *) UsOutput__DM2) 
/* Input Buffer Disable Override */
#define UsOutput_INP_DIS                (* (reg8 *) UsOutput__INP_DIS)
/* LCD Common or Segment Drive */
#define UsOutput_LCD_COM_SEG            (* (reg8 *) UsOutput__LCD_COM_SEG)
/* Enable Segment LCD */
#define UsOutput_LCD_EN                 (* (reg8 *) UsOutput__LCD_EN)
/* Slew Rate Control */
#define UsOutput_SLW                    (* (reg8 *) UsOutput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UsOutput_PRTDSI__CAPS_SEL       (* (reg8 *) UsOutput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UsOutput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UsOutput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UsOutput_PRTDSI__OE_SEL0        (* (reg8 *) UsOutput__PRTDSI__OE_SEL0) 
#define UsOutput_PRTDSI__OE_SEL1        (* (reg8 *) UsOutput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UsOutput_PRTDSI__OUT_SEL0       (* (reg8 *) UsOutput__PRTDSI__OUT_SEL0) 
#define UsOutput_PRTDSI__OUT_SEL1       (* (reg8 *) UsOutput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UsOutput_PRTDSI__SYNC_OUT       (* (reg8 *) UsOutput__PRTDSI__SYNC_OUT) 


#if defined(UsOutput__INTSTAT)  /* Interrupt Registers */

    #define UsOutput_INTSTAT                (* (reg8 *) UsOutput__INTSTAT)
    #define UsOutput_SNAP                   (* (reg8 *) UsOutput__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UsOutput_H */


/* [] END OF FILE */
