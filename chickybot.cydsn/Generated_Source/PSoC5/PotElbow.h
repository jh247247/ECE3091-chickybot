/*******************************************************************************
* File Name: PotElbow.h  
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

#if !defined(CY_PINS_PotElbow_H) /* Pins PotElbow_H */
#define CY_PINS_PotElbow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PotElbow_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PotElbow__PORT == 15 && ((PotElbow__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PotElbow_Write(uint8 value) ;
void    PotElbow_SetDriveMode(uint8 mode) ;
uint8   PotElbow_ReadDataReg(void) ;
uint8   PotElbow_Read(void) ;
uint8   PotElbow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PotElbow_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PotElbow_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PotElbow_DM_RES_UP          PIN_DM_RES_UP
#define PotElbow_DM_RES_DWN         PIN_DM_RES_DWN
#define PotElbow_DM_OD_LO           PIN_DM_OD_LO
#define PotElbow_DM_OD_HI           PIN_DM_OD_HI
#define PotElbow_DM_STRONG          PIN_DM_STRONG
#define PotElbow_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PotElbow_MASK               PotElbow__MASK
#define PotElbow_SHIFT              PotElbow__SHIFT
#define PotElbow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PotElbow_PS                     (* (reg8 *) PotElbow__PS)
/* Data Register */
#define PotElbow_DR                     (* (reg8 *) PotElbow__DR)
/* Port Number */
#define PotElbow_PRT_NUM                (* (reg8 *) PotElbow__PRT) 
/* Connect to Analog Globals */                                                  
#define PotElbow_AG                     (* (reg8 *) PotElbow__AG)                       
/* Analog MUX bux enable */
#define PotElbow_AMUX                   (* (reg8 *) PotElbow__AMUX) 
/* Bidirectional Enable */                                                        
#define PotElbow_BIE                    (* (reg8 *) PotElbow__BIE)
/* Bit-mask for Aliased Register Access */
#define PotElbow_BIT_MASK               (* (reg8 *) PotElbow__BIT_MASK)
/* Bypass Enable */
#define PotElbow_BYP                    (* (reg8 *) PotElbow__BYP)
/* Port wide control signals */                                                   
#define PotElbow_CTL                    (* (reg8 *) PotElbow__CTL)
/* Drive Modes */
#define PotElbow_DM0                    (* (reg8 *) PotElbow__DM0) 
#define PotElbow_DM1                    (* (reg8 *) PotElbow__DM1)
#define PotElbow_DM2                    (* (reg8 *) PotElbow__DM2) 
/* Input Buffer Disable Override */
#define PotElbow_INP_DIS                (* (reg8 *) PotElbow__INP_DIS)
/* LCD Common or Segment Drive */
#define PotElbow_LCD_COM_SEG            (* (reg8 *) PotElbow__LCD_COM_SEG)
/* Enable Segment LCD */
#define PotElbow_LCD_EN                 (* (reg8 *) PotElbow__LCD_EN)
/* Slew Rate Control */
#define PotElbow_SLW                    (* (reg8 *) PotElbow__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PotElbow_PRTDSI__CAPS_SEL       (* (reg8 *) PotElbow__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PotElbow_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PotElbow__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PotElbow_PRTDSI__OE_SEL0        (* (reg8 *) PotElbow__PRTDSI__OE_SEL0) 
#define PotElbow_PRTDSI__OE_SEL1        (* (reg8 *) PotElbow__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PotElbow_PRTDSI__OUT_SEL0       (* (reg8 *) PotElbow__PRTDSI__OUT_SEL0) 
#define PotElbow_PRTDSI__OUT_SEL1       (* (reg8 *) PotElbow__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PotElbow_PRTDSI__SYNC_OUT       (* (reg8 *) PotElbow__PRTDSI__SYNC_OUT) 


#if defined(PotElbow__INTSTAT)  /* Interrupt Registers */

    #define PotElbow_INTSTAT                (* (reg8 *) PotElbow__INTSTAT)
    #define PotElbow_SNAP                   (* (reg8 *) PotElbow__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PotElbow_H */


/* [] END OF FILE */
