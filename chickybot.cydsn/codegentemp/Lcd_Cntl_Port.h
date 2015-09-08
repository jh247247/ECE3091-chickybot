/*******************************************************************************
* File Name: Lcd_Cntl_Port.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_Lcd_Cntl_Port_H) /* CY_CONTROL_REG_Lcd_Cntl_Port_H */
#define CY_CONTROL_REG_Lcd_Cntl_Port_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Lcd_Cntl_Port_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Lcd_Cntl_Port_Write(uint8 control) ;
uint8   Lcd_Cntl_Port_Read(void) ;

void Lcd_Cntl_Port_SaveConfig(void) ;
void Lcd_Cntl_Port_RestoreConfig(void) ;
void Lcd_Cntl_Port_Sleep(void) ; 
void Lcd_Cntl_Port_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Lcd_Cntl_Port_Control        (* (reg8 *) Lcd_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )
#define Lcd_Cntl_Port_Control_PTR    (  (reg8 *) Lcd_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Lcd_Cntl_Port_H */


/* [] END OF FILE */
