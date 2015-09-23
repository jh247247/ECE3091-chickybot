/*******************************************************************************
* File Name: PhotoDiode1.h  
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

#if !defined(CY_PINS_PhotoDiode1_H) /* Pins PhotoDiode1_H */
#define CY_PINS_PhotoDiode1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PhotoDiode1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PhotoDiode1__PORT == 15 && ((PhotoDiode1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PhotoDiode1_Write(uint8 value) ;
void    PhotoDiode1_SetDriveMode(uint8 mode) ;
uint8   PhotoDiode1_ReadDataReg(void) ;
uint8   PhotoDiode1_Read(void) ;
uint8   PhotoDiode1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PhotoDiode1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PhotoDiode1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PhotoDiode1_DM_RES_UP          PIN_DM_RES_UP
#define PhotoDiode1_DM_RES_DWN         PIN_DM_RES_DWN
#define PhotoDiode1_DM_OD_LO           PIN_DM_OD_LO
#define PhotoDiode1_DM_OD_HI           PIN_DM_OD_HI
#define PhotoDiode1_DM_STRONG          PIN_DM_STRONG
#define PhotoDiode1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PhotoDiode1_MASK               PhotoDiode1__MASK
#define PhotoDiode1_SHIFT              PhotoDiode1__SHIFT
#define PhotoDiode1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PhotoDiode1_PS                     (* (reg8 *) PhotoDiode1__PS)
/* Data Register */
#define PhotoDiode1_DR                     (* (reg8 *) PhotoDiode1__DR)
/* Port Number */
#define PhotoDiode1_PRT_NUM                (* (reg8 *) PhotoDiode1__PRT) 
/* Connect to Analog Globals */                                                  
#define PhotoDiode1_AG                     (* (reg8 *) PhotoDiode1__AG)                       
/* Analog MUX bux enable */
#define PhotoDiode1_AMUX                   (* (reg8 *) PhotoDiode1__AMUX) 
/* Bidirectional Enable */                                                        
#define PhotoDiode1_BIE                    (* (reg8 *) PhotoDiode1__BIE)
/* Bit-mask for Aliased Register Access */
#define PhotoDiode1_BIT_MASK               (* (reg8 *) PhotoDiode1__BIT_MASK)
/* Bypass Enable */
#define PhotoDiode1_BYP                    (* (reg8 *) PhotoDiode1__BYP)
/* Port wide control signals */                                                   
#define PhotoDiode1_CTL                    (* (reg8 *) PhotoDiode1__CTL)
/* Drive Modes */
#define PhotoDiode1_DM0                    (* (reg8 *) PhotoDiode1__DM0) 
#define PhotoDiode1_DM1                    (* (reg8 *) PhotoDiode1__DM1)
#define PhotoDiode1_DM2                    (* (reg8 *) PhotoDiode1__DM2) 
/* Input Buffer Disable Override */
#define PhotoDiode1_INP_DIS                (* (reg8 *) PhotoDiode1__INP_DIS)
/* LCD Common or Segment Drive */
#define PhotoDiode1_LCD_COM_SEG            (* (reg8 *) PhotoDiode1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PhotoDiode1_LCD_EN                 (* (reg8 *) PhotoDiode1__LCD_EN)
/* Slew Rate Control */
#define PhotoDiode1_SLW                    (* (reg8 *) PhotoDiode1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PhotoDiode1_PRTDSI__CAPS_SEL       (* (reg8 *) PhotoDiode1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PhotoDiode1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PhotoDiode1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PhotoDiode1_PRTDSI__OE_SEL0        (* (reg8 *) PhotoDiode1__PRTDSI__OE_SEL0) 
#define PhotoDiode1_PRTDSI__OE_SEL1        (* (reg8 *) PhotoDiode1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PhotoDiode1_PRTDSI__OUT_SEL0       (* (reg8 *) PhotoDiode1__PRTDSI__OUT_SEL0) 
#define PhotoDiode1_PRTDSI__OUT_SEL1       (* (reg8 *) PhotoDiode1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PhotoDiode1_PRTDSI__SYNC_OUT       (* (reg8 *) PhotoDiode1__PRTDSI__SYNC_OUT) 


#if defined(PhotoDiode1__INTSTAT)  /* Interrupt Registers */

    #define PhotoDiode1_INTSTAT                (* (reg8 *) PhotoDiode1__INTSTAT)
    #define PhotoDiode1_SNAP                   (* (reg8 *) PhotoDiode1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PhotoDiode1_H */


/* [] END OF FILE */
