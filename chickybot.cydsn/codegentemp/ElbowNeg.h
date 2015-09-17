/*******************************************************************************
* File Name: ElbowNeg.h  
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

#if !defined(CY_PINS_ElbowNeg_H) /* Pins ElbowNeg_H */
#define CY_PINS_ElbowNeg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ElbowNeg_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ElbowNeg__PORT == 15 && ((ElbowNeg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ElbowNeg_Write(uint8 value) ;
void    ElbowNeg_SetDriveMode(uint8 mode) ;
uint8   ElbowNeg_ReadDataReg(void) ;
uint8   ElbowNeg_Read(void) ;
uint8   ElbowNeg_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ElbowNeg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ElbowNeg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ElbowNeg_DM_RES_UP          PIN_DM_RES_UP
#define ElbowNeg_DM_RES_DWN         PIN_DM_RES_DWN
#define ElbowNeg_DM_OD_LO           PIN_DM_OD_LO
#define ElbowNeg_DM_OD_HI           PIN_DM_OD_HI
#define ElbowNeg_DM_STRONG          PIN_DM_STRONG
#define ElbowNeg_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ElbowNeg_MASK               ElbowNeg__MASK
#define ElbowNeg_SHIFT              ElbowNeg__SHIFT
#define ElbowNeg_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ElbowNeg_PS                     (* (reg8 *) ElbowNeg__PS)
/* Data Register */
#define ElbowNeg_DR                     (* (reg8 *) ElbowNeg__DR)
/* Port Number */
#define ElbowNeg_PRT_NUM                (* (reg8 *) ElbowNeg__PRT) 
/* Connect to Analog Globals */                                                  
#define ElbowNeg_AG                     (* (reg8 *) ElbowNeg__AG)                       
/* Analog MUX bux enable */
#define ElbowNeg_AMUX                   (* (reg8 *) ElbowNeg__AMUX) 
/* Bidirectional Enable */                                                        
#define ElbowNeg_BIE                    (* (reg8 *) ElbowNeg__BIE)
/* Bit-mask for Aliased Register Access */
#define ElbowNeg_BIT_MASK               (* (reg8 *) ElbowNeg__BIT_MASK)
/* Bypass Enable */
#define ElbowNeg_BYP                    (* (reg8 *) ElbowNeg__BYP)
/* Port wide control signals */                                                   
#define ElbowNeg_CTL                    (* (reg8 *) ElbowNeg__CTL)
/* Drive Modes */
#define ElbowNeg_DM0                    (* (reg8 *) ElbowNeg__DM0) 
#define ElbowNeg_DM1                    (* (reg8 *) ElbowNeg__DM1)
#define ElbowNeg_DM2                    (* (reg8 *) ElbowNeg__DM2) 
/* Input Buffer Disable Override */
#define ElbowNeg_INP_DIS                (* (reg8 *) ElbowNeg__INP_DIS)
/* LCD Common or Segment Drive */
#define ElbowNeg_LCD_COM_SEG            (* (reg8 *) ElbowNeg__LCD_COM_SEG)
/* Enable Segment LCD */
#define ElbowNeg_LCD_EN                 (* (reg8 *) ElbowNeg__LCD_EN)
/* Slew Rate Control */
#define ElbowNeg_SLW                    (* (reg8 *) ElbowNeg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ElbowNeg_PRTDSI__CAPS_SEL       (* (reg8 *) ElbowNeg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ElbowNeg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ElbowNeg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ElbowNeg_PRTDSI__OE_SEL0        (* (reg8 *) ElbowNeg__PRTDSI__OE_SEL0) 
#define ElbowNeg_PRTDSI__OE_SEL1        (* (reg8 *) ElbowNeg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ElbowNeg_PRTDSI__OUT_SEL0       (* (reg8 *) ElbowNeg__PRTDSI__OUT_SEL0) 
#define ElbowNeg_PRTDSI__OUT_SEL1       (* (reg8 *) ElbowNeg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ElbowNeg_PRTDSI__SYNC_OUT       (* (reg8 *) ElbowNeg__PRTDSI__SYNC_OUT) 


#if defined(ElbowNeg__INTSTAT)  /* Interrupt Registers */

    #define ElbowNeg_INTSTAT                (* (reg8 *) ElbowNeg__INTSTAT)
    #define ElbowNeg_SNAP                   (* (reg8 *) ElbowNeg__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ElbowNeg_H */


/* [] END OF FILE */
