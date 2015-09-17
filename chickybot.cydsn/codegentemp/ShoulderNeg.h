/*******************************************************************************
* File Name: ShoulderNeg.h  
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

#if !defined(CY_PINS_ShoulderNeg_H) /* Pins ShoulderNeg_H */
#define CY_PINS_ShoulderNeg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ShoulderNeg_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ShoulderNeg__PORT == 15 && ((ShoulderNeg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ShoulderNeg_Write(uint8 value) ;
void    ShoulderNeg_SetDriveMode(uint8 mode) ;
uint8   ShoulderNeg_ReadDataReg(void) ;
uint8   ShoulderNeg_Read(void) ;
uint8   ShoulderNeg_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ShoulderNeg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ShoulderNeg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ShoulderNeg_DM_RES_UP          PIN_DM_RES_UP
#define ShoulderNeg_DM_RES_DWN         PIN_DM_RES_DWN
#define ShoulderNeg_DM_OD_LO           PIN_DM_OD_LO
#define ShoulderNeg_DM_OD_HI           PIN_DM_OD_HI
#define ShoulderNeg_DM_STRONG          PIN_DM_STRONG
#define ShoulderNeg_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ShoulderNeg_MASK               ShoulderNeg__MASK
#define ShoulderNeg_SHIFT              ShoulderNeg__SHIFT
#define ShoulderNeg_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ShoulderNeg_PS                     (* (reg8 *) ShoulderNeg__PS)
/* Data Register */
#define ShoulderNeg_DR                     (* (reg8 *) ShoulderNeg__DR)
/* Port Number */
#define ShoulderNeg_PRT_NUM                (* (reg8 *) ShoulderNeg__PRT) 
/* Connect to Analog Globals */                                                  
#define ShoulderNeg_AG                     (* (reg8 *) ShoulderNeg__AG)                       
/* Analog MUX bux enable */
#define ShoulderNeg_AMUX                   (* (reg8 *) ShoulderNeg__AMUX) 
/* Bidirectional Enable */                                                        
#define ShoulderNeg_BIE                    (* (reg8 *) ShoulderNeg__BIE)
/* Bit-mask for Aliased Register Access */
#define ShoulderNeg_BIT_MASK               (* (reg8 *) ShoulderNeg__BIT_MASK)
/* Bypass Enable */
#define ShoulderNeg_BYP                    (* (reg8 *) ShoulderNeg__BYP)
/* Port wide control signals */                                                   
#define ShoulderNeg_CTL                    (* (reg8 *) ShoulderNeg__CTL)
/* Drive Modes */
#define ShoulderNeg_DM0                    (* (reg8 *) ShoulderNeg__DM0) 
#define ShoulderNeg_DM1                    (* (reg8 *) ShoulderNeg__DM1)
#define ShoulderNeg_DM2                    (* (reg8 *) ShoulderNeg__DM2) 
/* Input Buffer Disable Override */
#define ShoulderNeg_INP_DIS                (* (reg8 *) ShoulderNeg__INP_DIS)
/* LCD Common or Segment Drive */
#define ShoulderNeg_LCD_COM_SEG            (* (reg8 *) ShoulderNeg__LCD_COM_SEG)
/* Enable Segment LCD */
#define ShoulderNeg_LCD_EN                 (* (reg8 *) ShoulderNeg__LCD_EN)
/* Slew Rate Control */
#define ShoulderNeg_SLW                    (* (reg8 *) ShoulderNeg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ShoulderNeg_PRTDSI__CAPS_SEL       (* (reg8 *) ShoulderNeg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ShoulderNeg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ShoulderNeg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ShoulderNeg_PRTDSI__OE_SEL0        (* (reg8 *) ShoulderNeg__PRTDSI__OE_SEL0) 
#define ShoulderNeg_PRTDSI__OE_SEL1        (* (reg8 *) ShoulderNeg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ShoulderNeg_PRTDSI__OUT_SEL0       (* (reg8 *) ShoulderNeg__PRTDSI__OUT_SEL0) 
#define ShoulderNeg_PRTDSI__OUT_SEL1       (* (reg8 *) ShoulderNeg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ShoulderNeg_PRTDSI__SYNC_OUT       (* (reg8 *) ShoulderNeg__PRTDSI__SYNC_OUT) 


#if defined(ShoulderNeg__INTSTAT)  /* Interrupt Registers */

    #define ShoulderNeg_INTSTAT                (* (reg8 *) ShoulderNeg__INTSTAT)
    #define ShoulderNeg_SNAP                   (* (reg8 *) ShoulderNeg__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ShoulderNeg_H */


/* [] END OF FILE */
