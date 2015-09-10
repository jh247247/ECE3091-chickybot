/*******************************************************************************
* File Name: UsTC.h  
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

#if !defined(CY_PINS_UsTC_H) /* Pins UsTC_H */
#define CY_PINS_UsTC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UsTC_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UsTC__PORT == 15 && ((UsTC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UsTC_Write(uint8 value) ;
void    UsTC_SetDriveMode(uint8 mode) ;
uint8   UsTC_ReadDataReg(void) ;
uint8   UsTC_Read(void) ;
uint8   UsTC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UsTC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UsTC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UsTC_DM_RES_UP          PIN_DM_RES_UP
#define UsTC_DM_RES_DWN         PIN_DM_RES_DWN
#define UsTC_DM_OD_LO           PIN_DM_OD_LO
#define UsTC_DM_OD_HI           PIN_DM_OD_HI
#define UsTC_DM_STRONG          PIN_DM_STRONG
#define UsTC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UsTC_MASK               UsTC__MASK
#define UsTC_SHIFT              UsTC__SHIFT
#define UsTC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UsTC_PS                     (* (reg8 *) UsTC__PS)
/* Data Register */
#define UsTC_DR                     (* (reg8 *) UsTC__DR)
/* Port Number */
#define UsTC_PRT_NUM                (* (reg8 *) UsTC__PRT) 
/* Connect to Analog Globals */                                                  
#define UsTC_AG                     (* (reg8 *) UsTC__AG)                       
/* Analog MUX bux enable */
#define UsTC_AMUX                   (* (reg8 *) UsTC__AMUX) 
/* Bidirectional Enable */                                                        
#define UsTC_BIE                    (* (reg8 *) UsTC__BIE)
/* Bit-mask for Aliased Register Access */
#define UsTC_BIT_MASK               (* (reg8 *) UsTC__BIT_MASK)
/* Bypass Enable */
#define UsTC_BYP                    (* (reg8 *) UsTC__BYP)
/* Port wide control signals */                                                   
#define UsTC_CTL                    (* (reg8 *) UsTC__CTL)
/* Drive Modes */
#define UsTC_DM0                    (* (reg8 *) UsTC__DM0) 
#define UsTC_DM1                    (* (reg8 *) UsTC__DM1)
#define UsTC_DM2                    (* (reg8 *) UsTC__DM2) 
/* Input Buffer Disable Override */
#define UsTC_INP_DIS                (* (reg8 *) UsTC__INP_DIS)
/* LCD Common or Segment Drive */
#define UsTC_LCD_COM_SEG            (* (reg8 *) UsTC__LCD_COM_SEG)
/* Enable Segment LCD */
#define UsTC_LCD_EN                 (* (reg8 *) UsTC__LCD_EN)
/* Slew Rate Control */
#define UsTC_SLW                    (* (reg8 *) UsTC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UsTC_PRTDSI__CAPS_SEL       (* (reg8 *) UsTC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UsTC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UsTC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UsTC_PRTDSI__OE_SEL0        (* (reg8 *) UsTC__PRTDSI__OE_SEL0) 
#define UsTC_PRTDSI__OE_SEL1        (* (reg8 *) UsTC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UsTC_PRTDSI__OUT_SEL0       (* (reg8 *) UsTC__PRTDSI__OUT_SEL0) 
#define UsTC_PRTDSI__OUT_SEL1       (* (reg8 *) UsTC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UsTC_PRTDSI__SYNC_OUT       (* (reg8 *) UsTC__PRTDSI__SYNC_OUT) 


#if defined(UsTC__INTSTAT)  /* Interrupt Registers */

    #define UsTC_INTSTAT                (* (reg8 *) UsTC__INTSTAT)
    #define UsTC_SNAP                   (* (reg8 *) UsTC__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UsTC_H */


/* [] END OF FILE */
