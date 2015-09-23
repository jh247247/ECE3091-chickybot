/*******************************************************************************
* File Name: CompIn2Elbow.h  
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

#if !defined(CY_PINS_CompIn2Elbow_H) /* Pins CompIn2Elbow_H */
#define CY_PINS_CompIn2Elbow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CompIn2Elbow_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CompIn2Elbow__PORT == 15 && ((CompIn2Elbow__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CompIn2Elbow_Write(uint8 value) ;
void    CompIn2Elbow_SetDriveMode(uint8 mode) ;
uint8   CompIn2Elbow_ReadDataReg(void) ;
uint8   CompIn2Elbow_Read(void) ;
uint8   CompIn2Elbow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CompIn2Elbow_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CompIn2Elbow_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CompIn2Elbow_DM_RES_UP          PIN_DM_RES_UP
#define CompIn2Elbow_DM_RES_DWN         PIN_DM_RES_DWN
#define CompIn2Elbow_DM_OD_LO           PIN_DM_OD_LO
#define CompIn2Elbow_DM_OD_HI           PIN_DM_OD_HI
#define CompIn2Elbow_DM_STRONG          PIN_DM_STRONG
#define CompIn2Elbow_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CompIn2Elbow_MASK               CompIn2Elbow__MASK
#define CompIn2Elbow_SHIFT              CompIn2Elbow__SHIFT
#define CompIn2Elbow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CompIn2Elbow_PS                     (* (reg8 *) CompIn2Elbow__PS)
/* Data Register */
#define CompIn2Elbow_DR                     (* (reg8 *) CompIn2Elbow__DR)
/* Port Number */
#define CompIn2Elbow_PRT_NUM                (* (reg8 *) CompIn2Elbow__PRT) 
/* Connect to Analog Globals */                                                  
#define CompIn2Elbow_AG                     (* (reg8 *) CompIn2Elbow__AG)                       
/* Analog MUX bux enable */
#define CompIn2Elbow_AMUX                   (* (reg8 *) CompIn2Elbow__AMUX) 
/* Bidirectional Enable */                                                        
#define CompIn2Elbow_BIE                    (* (reg8 *) CompIn2Elbow__BIE)
/* Bit-mask for Aliased Register Access */
#define CompIn2Elbow_BIT_MASK               (* (reg8 *) CompIn2Elbow__BIT_MASK)
/* Bypass Enable */
#define CompIn2Elbow_BYP                    (* (reg8 *) CompIn2Elbow__BYP)
/* Port wide control signals */                                                   
#define CompIn2Elbow_CTL                    (* (reg8 *) CompIn2Elbow__CTL)
/* Drive Modes */
#define CompIn2Elbow_DM0                    (* (reg8 *) CompIn2Elbow__DM0) 
#define CompIn2Elbow_DM1                    (* (reg8 *) CompIn2Elbow__DM1)
#define CompIn2Elbow_DM2                    (* (reg8 *) CompIn2Elbow__DM2) 
/* Input Buffer Disable Override */
#define CompIn2Elbow_INP_DIS                (* (reg8 *) CompIn2Elbow__INP_DIS)
/* LCD Common or Segment Drive */
#define CompIn2Elbow_LCD_COM_SEG            (* (reg8 *) CompIn2Elbow__LCD_COM_SEG)
/* Enable Segment LCD */
#define CompIn2Elbow_LCD_EN                 (* (reg8 *) CompIn2Elbow__LCD_EN)
/* Slew Rate Control */
#define CompIn2Elbow_SLW                    (* (reg8 *) CompIn2Elbow__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CompIn2Elbow_PRTDSI__CAPS_SEL       (* (reg8 *) CompIn2Elbow__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CompIn2Elbow_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CompIn2Elbow__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CompIn2Elbow_PRTDSI__OE_SEL0        (* (reg8 *) CompIn2Elbow__PRTDSI__OE_SEL0) 
#define CompIn2Elbow_PRTDSI__OE_SEL1        (* (reg8 *) CompIn2Elbow__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CompIn2Elbow_PRTDSI__OUT_SEL0       (* (reg8 *) CompIn2Elbow__PRTDSI__OUT_SEL0) 
#define CompIn2Elbow_PRTDSI__OUT_SEL1       (* (reg8 *) CompIn2Elbow__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CompIn2Elbow_PRTDSI__SYNC_OUT       (* (reg8 *) CompIn2Elbow__PRTDSI__SYNC_OUT) 


#if defined(CompIn2Elbow__INTSTAT)  /* Interrupt Registers */

    #define CompIn2Elbow_INTSTAT                (* (reg8 *) CompIn2Elbow__INTSTAT)
    #define CompIn2Elbow_SNAP                   (* (reg8 *) CompIn2Elbow__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CompIn2Elbow_H */


/* [] END OF FILE */
