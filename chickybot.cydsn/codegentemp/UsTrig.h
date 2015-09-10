/*******************************************************************************
* File Name: UsTrig.h  
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

#if !defined(CY_PINS_UsTrig_H) /* Pins UsTrig_H */
#define CY_PINS_UsTrig_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UsTrig_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UsTrig__PORT == 15 && ((UsTrig__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UsTrig_Write(uint8 value) ;
void    UsTrig_SetDriveMode(uint8 mode) ;
uint8   UsTrig_ReadDataReg(void) ;
uint8   UsTrig_Read(void) ;
uint8   UsTrig_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UsTrig_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UsTrig_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UsTrig_DM_RES_UP          PIN_DM_RES_UP
#define UsTrig_DM_RES_DWN         PIN_DM_RES_DWN
#define UsTrig_DM_OD_LO           PIN_DM_OD_LO
#define UsTrig_DM_OD_HI           PIN_DM_OD_HI
#define UsTrig_DM_STRONG          PIN_DM_STRONG
#define UsTrig_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UsTrig_MASK               UsTrig__MASK
#define UsTrig_SHIFT              UsTrig__SHIFT
#define UsTrig_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UsTrig_PS                     (* (reg8 *) UsTrig__PS)
/* Data Register */
#define UsTrig_DR                     (* (reg8 *) UsTrig__DR)
/* Port Number */
#define UsTrig_PRT_NUM                (* (reg8 *) UsTrig__PRT) 
/* Connect to Analog Globals */                                                  
#define UsTrig_AG                     (* (reg8 *) UsTrig__AG)                       
/* Analog MUX bux enable */
#define UsTrig_AMUX                   (* (reg8 *) UsTrig__AMUX) 
/* Bidirectional Enable */                                                        
#define UsTrig_BIE                    (* (reg8 *) UsTrig__BIE)
/* Bit-mask for Aliased Register Access */
#define UsTrig_BIT_MASK               (* (reg8 *) UsTrig__BIT_MASK)
/* Bypass Enable */
#define UsTrig_BYP                    (* (reg8 *) UsTrig__BYP)
/* Port wide control signals */                                                   
#define UsTrig_CTL                    (* (reg8 *) UsTrig__CTL)
/* Drive Modes */
#define UsTrig_DM0                    (* (reg8 *) UsTrig__DM0) 
#define UsTrig_DM1                    (* (reg8 *) UsTrig__DM1)
#define UsTrig_DM2                    (* (reg8 *) UsTrig__DM2) 
/* Input Buffer Disable Override */
#define UsTrig_INP_DIS                (* (reg8 *) UsTrig__INP_DIS)
/* LCD Common or Segment Drive */
#define UsTrig_LCD_COM_SEG            (* (reg8 *) UsTrig__LCD_COM_SEG)
/* Enable Segment LCD */
#define UsTrig_LCD_EN                 (* (reg8 *) UsTrig__LCD_EN)
/* Slew Rate Control */
#define UsTrig_SLW                    (* (reg8 *) UsTrig__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UsTrig_PRTDSI__CAPS_SEL       (* (reg8 *) UsTrig__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UsTrig_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UsTrig__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UsTrig_PRTDSI__OE_SEL0        (* (reg8 *) UsTrig__PRTDSI__OE_SEL0) 
#define UsTrig_PRTDSI__OE_SEL1        (* (reg8 *) UsTrig__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UsTrig_PRTDSI__OUT_SEL0       (* (reg8 *) UsTrig__PRTDSI__OUT_SEL0) 
#define UsTrig_PRTDSI__OUT_SEL1       (* (reg8 *) UsTrig__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UsTrig_PRTDSI__SYNC_OUT       (* (reg8 *) UsTrig__PRTDSI__SYNC_OUT) 


#if defined(UsTrig__INTSTAT)  /* Interrupt Registers */

    #define UsTrig_INTSTAT                (* (reg8 *) UsTrig__INTSTAT)
    #define UsTrig_SNAP                   (* (reg8 *) UsTrig__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UsTrig_H */


/* [] END OF FILE */
