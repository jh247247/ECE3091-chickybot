/*******************************************************************************
* File Name: UsEcho.h  
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

#if !defined(CY_PINS_UsEcho_H) /* Pins UsEcho_H */
#define CY_PINS_UsEcho_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UsEcho_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UsEcho__PORT == 15 && ((UsEcho__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UsEcho_Write(uint8 value) ;
void    UsEcho_SetDriveMode(uint8 mode) ;
uint8   UsEcho_ReadDataReg(void) ;
uint8   UsEcho_Read(void) ;
uint8   UsEcho_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UsEcho_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UsEcho_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UsEcho_DM_RES_UP          PIN_DM_RES_UP
#define UsEcho_DM_RES_DWN         PIN_DM_RES_DWN
#define UsEcho_DM_OD_LO           PIN_DM_OD_LO
#define UsEcho_DM_OD_HI           PIN_DM_OD_HI
#define UsEcho_DM_STRONG          PIN_DM_STRONG
#define UsEcho_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UsEcho_MASK               UsEcho__MASK
#define UsEcho_SHIFT              UsEcho__SHIFT
#define UsEcho_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UsEcho_PS                     (* (reg8 *) UsEcho__PS)
/* Data Register */
#define UsEcho_DR                     (* (reg8 *) UsEcho__DR)
/* Port Number */
#define UsEcho_PRT_NUM                (* (reg8 *) UsEcho__PRT) 
/* Connect to Analog Globals */                                                  
#define UsEcho_AG                     (* (reg8 *) UsEcho__AG)                       
/* Analog MUX bux enable */
#define UsEcho_AMUX                   (* (reg8 *) UsEcho__AMUX) 
/* Bidirectional Enable */                                                        
#define UsEcho_BIE                    (* (reg8 *) UsEcho__BIE)
/* Bit-mask for Aliased Register Access */
#define UsEcho_BIT_MASK               (* (reg8 *) UsEcho__BIT_MASK)
/* Bypass Enable */
#define UsEcho_BYP                    (* (reg8 *) UsEcho__BYP)
/* Port wide control signals */                                                   
#define UsEcho_CTL                    (* (reg8 *) UsEcho__CTL)
/* Drive Modes */
#define UsEcho_DM0                    (* (reg8 *) UsEcho__DM0) 
#define UsEcho_DM1                    (* (reg8 *) UsEcho__DM1)
#define UsEcho_DM2                    (* (reg8 *) UsEcho__DM2) 
/* Input Buffer Disable Override */
#define UsEcho_INP_DIS                (* (reg8 *) UsEcho__INP_DIS)
/* LCD Common or Segment Drive */
#define UsEcho_LCD_COM_SEG            (* (reg8 *) UsEcho__LCD_COM_SEG)
/* Enable Segment LCD */
#define UsEcho_LCD_EN                 (* (reg8 *) UsEcho__LCD_EN)
/* Slew Rate Control */
#define UsEcho_SLW                    (* (reg8 *) UsEcho__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UsEcho_PRTDSI__CAPS_SEL       (* (reg8 *) UsEcho__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UsEcho_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UsEcho__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UsEcho_PRTDSI__OE_SEL0        (* (reg8 *) UsEcho__PRTDSI__OE_SEL0) 
#define UsEcho_PRTDSI__OE_SEL1        (* (reg8 *) UsEcho__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UsEcho_PRTDSI__OUT_SEL0       (* (reg8 *) UsEcho__PRTDSI__OUT_SEL0) 
#define UsEcho_PRTDSI__OUT_SEL1       (* (reg8 *) UsEcho__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UsEcho_PRTDSI__SYNC_OUT       (* (reg8 *) UsEcho__PRTDSI__SYNC_OUT) 


#if defined(UsEcho__INTSTAT)  /* Interrupt Registers */

    #define UsEcho_INTSTAT                (* (reg8 *) UsEcho__INTSTAT)
    #define UsEcho_SNAP                   (* (reg8 *) UsEcho__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UsEcho_H */


/* [] END OF FILE */
