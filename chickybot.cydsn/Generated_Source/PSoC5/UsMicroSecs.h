/*******************************************************************************
* File Name: UsMicroSecs.h  
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

#if !defined(CY_PINS_UsMicroSecs_H) /* Pins UsMicroSecs_H */
#define CY_PINS_UsMicroSecs_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UsMicroSecs_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UsMicroSecs__PORT == 15 && ((UsMicroSecs__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UsMicroSecs_Write(uint8 value) ;
void    UsMicroSecs_SetDriveMode(uint8 mode) ;
uint8   UsMicroSecs_ReadDataReg(void) ;
uint8   UsMicroSecs_Read(void) ;
uint8   UsMicroSecs_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UsMicroSecs_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UsMicroSecs_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UsMicroSecs_DM_RES_UP          PIN_DM_RES_UP
#define UsMicroSecs_DM_RES_DWN         PIN_DM_RES_DWN
#define UsMicroSecs_DM_OD_LO           PIN_DM_OD_LO
#define UsMicroSecs_DM_OD_HI           PIN_DM_OD_HI
#define UsMicroSecs_DM_STRONG          PIN_DM_STRONG
#define UsMicroSecs_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UsMicroSecs_MASK               UsMicroSecs__MASK
#define UsMicroSecs_SHIFT              UsMicroSecs__SHIFT
#define UsMicroSecs_WIDTH              8u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UsMicroSecs_PS                     (* (reg8 *) UsMicroSecs__PS)
/* Data Register */
#define UsMicroSecs_DR                     (* (reg8 *) UsMicroSecs__DR)
/* Port Number */
#define UsMicroSecs_PRT_NUM                (* (reg8 *) UsMicroSecs__PRT) 
/* Connect to Analog Globals */                                                  
#define UsMicroSecs_AG                     (* (reg8 *) UsMicroSecs__AG)                       
/* Analog MUX bux enable */
#define UsMicroSecs_AMUX                   (* (reg8 *) UsMicroSecs__AMUX) 
/* Bidirectional Enable */                                                        
#define UsMicroSecs_BIE                    (* (reg8 *) UsMicroSecs__BIE)
/* Bit-mask for Aliased Register Access */
#define UsMicroSecs_BIT_MASK               (* (reg8 *) UsMicroSecs__BIT_MASK)
/* Bypass Enable */
#define UsMicroSecs_BYP                    (* (reg8 *) UsMicroSecs__BYP)
/* Port wide control signals */                                                   
#define UsMicroSecs_CTL                    (* (reg8 *) UsMicroSecs__CTL)
/* Drive Modes */
#define UsMicroSecs_DM0                    (* (reg8 *) UsMicroSecs__DM0) 
#define UsMicroSecs_DM1                    (* (reg8 *) UsMicroSecs__DM1)
#define UsMicroSecs_DM2                    (* (reg8 *) UsMicroSecs__DM2) 
/* Input Buffer Disable Override */
#define UsMicroSecs_INP_DIS                (* (reg8 *) UsMicroSecs__INP_DIS)
/* LCD Common or Segment Drive */
#define UsMicroSecs_LCD_COM_SEG            (* (reg8 *) UsMicroSecs__LCD_COM_SEG)
/* Enable Segment LCD */
#define UsMicroSecs_LCD_EN                 (* (reg8 *) UsMicroSecs__LCD_EN)
/* Slew Rate Control */
#define UsMicroSecs_SLW                    (* (reg8 *) UsMicroSecs__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UsMicroSecs_PRTDSI__CAPS_SEL       (* (reg8 *) UsMicroSecs__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UsMicroSecs_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UsMicroSecs__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UsMicroSecs_PRTDSI__OE_SEL0        (* (reg8 *) UsMicroSecs__PRTDSI__OE_SEL0) 
#define UsMicroSecs_PRTDSI__OE_SEL1        (* (reg8 *) UsMicroSecs__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UsMicroSecs_PRTDSI__OUT_SEL0       (* (reg8 *) UsMicroSecs__PRTDSI__OUT_SEL0) 
#define UsMicroSecs_PRTDSI__OUT_SEL1       (* (reg8 *) UsMicroSecs__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UsMicroSecs_PRTDSI__SYNC_OUT       (* (reg8 *) UsMicroSecs__PRTDSI__SYNC_OUT) 


#if defined(UsMicroSecs__INTSTAT)  /* Interrupt Registers */

    #define UsMicroSecs_INTSTAT                (* (reg8 *) UsMicroSecs__INTSTAT)
    #define UsMicroSecs_SNAP                   (* (reg8 *) UsMicroSecs__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UsMicroSecs_H */


/* [] END OF FILE */
