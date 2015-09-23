/*******************************************************************************
* File Name: ElbowPos.h  
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

#if !defined(CY_PINS_ElbowPos_H) /* Pins ElbowPos_H */
#define CY_PINS_ElbowPos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ElbowPos_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ElbowPos__PORT == 15 && ((ElbowPos__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ElbowPos_Write(uint8 value) ;
void    ElbowPos_SetDriveMode(uint8 mode) ;
uint8   ElbowPos_ReadDataReg(void) ;
uint8   ElbowPos_Read(void) ;
uint8   ElbowPos_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ElbowPos_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ElbowPos_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ElbowPos_DM_RES_UP          PIN_DM_RES_UP
#define ElbowPos_DM_RES_DWN         PIN_DM_RES_DWN
#define ElbowPos_DM_OD_LO           PIN_DM_OD_LO
#define ElbowPos_DM_OD_HI           PIN_DM_OD_HI
#define ElbowPos_DM_STRONG          PIN_DM_STRONG
#define ElbowPos_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ElbowPos_MASK               ElbowPos__MASK
#define ElbowPos_SHIFT              ElbowPos__SHIFT
#define ElbowPos_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ElbowPos_PS                     (* (reg8 *) ElbowPos__PS)
/* Data Register */
#define ElbowPos_DR                     (* (reg8 *) ElbowPos__DR)
/* Port Number */
#define ElbowPos_PRT_NUM                (* (reg8 *) ElbowPos__PRT) 
/* Connect to Analog Globals */                                                  
#define ElbowPos_AG                     (* (reg8 *) ElbowPos__AG)                       
/* Analog MUX bux enable */
#define ElbowPos_AMUX                   (* (reg8 *) ElbowPos__AMUX) 
/* Bidirectional Enable */                                                        
#define ElbowPos_BIE                    (* (reg8 *) ElbowPos__BIE)
/* Bit-mask for Aliased Register Access */
#define ElbowPos_BIT_MASK               (* (reg8 *) ElbowPos__BIT_MASK)
/* Bypass Enable */
#define ElbowPos_BYP                    (* (reg8 *) ElbowPos__BYP)
/* Port wide control signals */                                                   
#define ElbowPos_CTL                    (* (reg8 *) ElbowPos__CTL)
/* Drive Modes */
#define ElbowPos_DM0                    (* (reg8 *) ElbowPos__DM0) 
#define ElbowPos_DM1                    (* (reg8 *) ElbowPos__DM1)
#define ElbowPos_DM2                    (* (reg8 *) ElbowPos__DM2) 
/* Input Buffer Disable Override */
#define ElbowPos_INP_DIS                (* (reg8 *) ElbowPos__INP_DIS)
/* LCD Common or Segment Drive */
#define ElbowPos_LCD_COM_SEG            (* (reg8 *) ElbowPos__LCD_COM_SEG)
/* Enable Segment LCD */
#define ElbowPos_LCD_EN                 (* (reg8 *) ElbowPos__LCD_EN)
/* Slew Rate Control */
#define ElbowPos_SLW                    (* (reg8 *) ElbowPos__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ElbowPos_PRTDSI__CAPS_SEL       (* (reg8 *) ElbowPos__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ElbowPos_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ElbowPos__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ElbowPos_PRTDSI__OE_SEL0        (* (reg8 *) ElbowPos__PRTDSI__OE_SEL0) 
#define ElbowPos_PRTDSI__OE_SEL1        (* (reg8 *) ElbowPos__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ElbowPos_PRTDSI__OUT_SEL0       (* (reg8 *) ElbowPos__PRTDSI__OUT_SEL0) 
#define ElbowPos_PRTDSI__OUT_SEL1       (* (reg8 *) ElbowPos__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ElbowPos_PRTDSI__SYNC_OUT       (* (reg8 *) ElbowPos__PRTDSI__SYNC_OUT) 


#if defined(ElbowPos__INTSTAT)  /* Interrupt Registers */

    #define ElbowPos_INTSTAT                (* (reg8 *) ElbowPos__INTSTAT)
    #define ElbowPos_SNAP                   (* (reg8 *) ElbowPos__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ElbowPos_H */


/* [] END OF FILE */
