/*******************************************************************************
* File Name: DebugPin2.h  
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

#if !defined(CY_PINS_DebugPin2_H) /* Pins DebugPin2_H */
#define CY_PINS_DebugPin2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DebugPin2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DebugPin2__PORT == 15 && ((DebugPin2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    DebugPin2_Write(uint8 value) ;
void    DebugPin2_SetDriveMode(uint8 mode) ;
uint8   DebugPin2_ReadDataReg(void) ;
uint8   DebugPin2_Read(void) ;
uint8   DebugPin2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DebugPin2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DebugPin2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DebugPin2_DM_RES_UP          PIN_DM_RES_UP
#define DebugPin2_DM_RES_DWN         PIN_DM_RES_DWN
#define DebugPin2_DM_OD_LO           PIN_DM_OD_LO
#define DebugPin2_DM_OD_HI           PIN_DM_OD_HI
#define DebugPin2_DM_STRONG          PIN_DM_STRONG
#define DebugPin2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DebugPin2_MASK               DebugPin2__MASK
#define DebugPin2_SHIFT              DebugPin2__SHIFT
#define DebugPin2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DebugPin2_PS                     (* (reg8 *) DebugPin2__PS)
/* Data Register */
#define DebugPin2_DR                     (* (reg8 *) DebugPin2__DR)
/* Port Number */
#define DebugPin2_PRT_NUM                (* (reg8 *) DebugPin2__PRT) 
/* Connect to Analog Globals */                                                  
#define DebugPin2_AG                     (* (reg8 *) DebugPin2__AG)                       
/* Analog MUX bux enable */
#define DebugPin2_AMUX                   (* (reg8 *) DebugPin2__AMUX) 
/* Bidirectional Enable */                                                        
#define DebugPin2_BIE                    (* (reg8 *) DebugPin2__BIE)
/* Bit-mask for Aliased Register Access */
#define DebugPin2_BIT_MASK               (* (reg8 *) DebugPin2__BIT_MASK)
/* Bypass Enable */
#define DebugPin2_BYP                    (* (reg8 *) DebugPin2__BYP)
/* Port wide control signals */                                                   
#define DebugPin2_CTL                    (* (reg8 *) DebugPin2__CTL)
/* Drive Modes */
#define DebugPin2_DM0                    (* (reg8 *) DebugPin2__DM0) 
#define DebugPin2_DM1                    (* (reg8 *) DebugPin2__DM1)
#define DebugPin2_DM2                    (* (reg8 *) DebugPin2__DM2) 
/* Input Buffer Disable Override */
#define DebugPin2_INP_DIS                (* (reg8 *) DebugPin2__INP_DIS)
/* LCD Common or Segment Drive */
#define DebugPin2_LCD_COM_SEG            (* (reg8 *) DebugPin2__LCD_COM_SEG)
/* Enable Segment LCD */
#define DebugPin2_LCD_EN                 (* (reg8 *) DebugPin2__LCD_EN)
/* Slew Rate Control */
#define DebugPin2_SLW                    (* (reg8 *) DebugPin2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DebugPin2_PRTDSI__CAPS_SEL       (* (reg8 *) DebugPin2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DebugPin2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DebugPin2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DebugPin2_PRTDSI__OE_SEL0        (* (reg8 *) DebugPin2__PRTDSI__OE_SEL0) 
#define DebugPin2_PRTDSI__OE_SEL1        (* (reg8 *) DebugPin2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DebugPin2_PRTDSI__OUT_SEL0       (* (reg8 *) DebugPin2__PRTDSI__OUT_SEL0) 
#define DebugPin2_PRTDSI__OUT_SEL1       (* (reg8 *) DebugPin2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DebugPin2_PRTDSI__SYNC_OUT       (* (reg8 *) DebugPin2__PRTDSI__SYNC_OUT) 


#if defined(DebugPin2__INTSTAT)  /* Interrupt Registers */

    #define DebugPin2_INTSTAT                (* (reg8 *) DebugPin2__INTSTAT)
    #define DebugPin2_SNAP                   (* (reg8 *) DebugPin2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DebugPin2_H */


/* [] END OF FILE */
