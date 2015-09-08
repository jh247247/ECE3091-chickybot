/*******************************************************************************
* File Name: Lcd.h
* Version 1.2
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_Lcd_H)
#define CY_CHARLCD_Lcd_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Lcd_CONVERSION_ROUTINES     (1u)
#define Lcd_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define Lcd_NONE                     (0u)    /* No Custom Fonts      */
#define Lcd_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define Lcd_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define Lcd_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Lcd_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void Lcd_Init(void) ;
void Lcd_Enable(void) ;
void Lcd_Start(void) ;
void Lcd_Stop(void) ;
void Lcd_WriteControl(uint8 cByte) ;
void Lcd_WriteData(uint8 dByte) ;
void Lcd_PrintString(char8 const string[]) ;
void Lcd_Position(uint8 row, uint8 column) ;
void Lcd_PutChar(char8 character) ;
void Lcd_IsReady(void) ;
void Lcd_SaveConfig(void) ;
void Lcd_RestoreConfig(void) ;
void Lcd_Sleep(void) ;
void Lcd_Wakeup(void) ;

#define Lcd_PosPrintString(row, col, string) Lcd_Position(row, col); Lcd_PrintString(string); 
#define Lcd_PosPutChar(row, col, character) Lcd_Position(row, col); Lcd_PutChar(character); 

#if((Lcd_CUSTOM_CHAR_SET == Lcd_VERTICAL_BG) || \
                (Lcd_CUSTOM_CHAR_SET == Lcd_HORIZONTAL_BG))

    void  Lcd_LoadCustomFonts(uint8 const customData[])
                        ;

    void  Lcd_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void Lcd_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((Lcd_CUSTOM_CHAR_SET == Lcd_VERTICAL_BG) */

#if(Lcd_CUSTOM_CHAR_SET == Lcd_USER_DEFINED)

    void Lcd_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((Lcd_CUSTOM_CHAR_SET == Lcd_USER_DEFINED) */

#if(Lcd_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void Lcd_PrintInt8(uint8 value) ;
    void Lcd_PrintInt16(uint16 value) ;
    void Lcd_PrintNumber(uint16 value) ; 
	
	#define Lcd_PosPrintInt8(row, col, value) Lcd_Position(row, col); Lcd_PrintInt8(value); 
	#define Lcd_PosPrintInt16(row, col, value) Lcd_Position(row, col); Lcd_PrintInt16(value);
	#define Lcd_PosPrintNumber(row, col, value) Lcd_Position(row, col); Lcd_PrintNumber(value);

#endif /* Lcd_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define Lcd_ClearDisplay() Lcd_WriteControl(Lcd_CLEAR_DISPLAY)

/* Off Macro */
#define Lcd_DisplayOff() Lcd_WriteControl(Lcd_DISPLAY_CURSOR_OFF)

/* On Macro */
#define Lcd_DisplayOn() Lcd_WriteControl(Lcd_DISPLAY_ON_CURSOR_OFF)


/***************************************
*           Global Variables
***************************************/

extern uint8 Lcd_initVar;
extern uint8 Lcd_enableState;
extern uint8 const CYCODE Lcd_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define Lcd_DISPLAY_8_BIT_INIT       (0x03u)
#define Lcd_DISPLAY_4_BIT_INIT       (0x02u)
#define Lcd_DISPLAY_CURSOR_OFF       (0x08u)
#define Lcd_CLEAR_DISPLAY            (0x01u)
#define Lcd_CURSOR_AUTO_INCR_ON      (0x06u)
#define Lcd_DISPLAY_CURSOR_ON        (0x0Eu)
#define Lcd_DISPLAY_2_LINES_5x10     (0x2Cu)
#define Lcd_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define Lcd_RESET_CURSOR_POSITION    (0x03u)
#define Lcd_CURSOR_WINK              (0x0Du)
#define Lcd_CURSOR_BLINK             (0x0Fu)
#define Lcd_CURSOR_SH_LEFT           (0x10u)
#define Lcd_CURSOR_SH_RIGHT          (0x14u)
#define Lcd_CURSOR_HOME              (0x02u)
#define Lcd_CURSOR_LEFT              (0x04u)
#define Lcd_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define Lcd_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define Lcd_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define Lcd_CHARACTER_WIDTH          (0x05u)
#define Lcd_CHARACTER_HEIGHT         (0x08u)

#if(Lcd_CONVERSION_ROUTINES == 1u)
    #define Lcd_NUMBER_OF_REMAINDERS (0x05u)
    #define Lcd_TEN                  (0x0Au)
#endif /* Lcd_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define Lcd_NIBBLE_SHIFT             (0x04u)
#define Lcd_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define Lcd_ROW_0_START              (0x80u)
#define Lcd_ROW_1_START              (0xC0u)
#define Lcd_ROW_2_START              (0x94u)
#define Lcd_ROW_3_START              (0xD4u)

/* Custom Character References */
#define Lcd_CUSTOM_0                 (0x00u)
#define Lcd_CUSTOM_1                 (0x01u)
#define Lcd_CUSTOM_2                 (0x02u)
#define Lcd_CUSTOM_3                 (0x03u)
#define Lcd_CUSTOM_4                 (0x04u)
#define Lcd_CUSTOM_5                 (0x05u)
#define Lcd_CUSTOM_6                 (0x06u)
#define Lcd_CUSTOM_7                 (0x07u)

/* Other constants */
#define Lcd_BYTE_UPPER_NIBBLE_SHIFT   (0x04u)
#define Lcd_BYTE_LOWER_NIBBLE_MASK    (0x0Fu)
#define Lcd_U16_UPPER_BYTE_SHIFT      (0x08u)
#define Lcd_U16_LOWER_BYTE_MASK       (0xFFu)
#define Lcd_CUSTOM_CHAR_SET_LEN       (0x40u)

#define Lcd_CMD_DELAY_US              (2500u)
#define Lcd_DATA_DELAY_US              (150u)
#define Lcd_NIB_DELAY_US               (100u)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC5A)
#define Lcd_CNTL_REG        (* (reg8 *) Lcd_Cntl_Port_Async_ctrl_reg__CONTROL_REG )
#define Lcd_CNTL_PTR        (  (reg8 *) Lcd_Cntl_Port_Async_ctrl_reg__CONTROL_REG )
#else
#define Lcd_CNTL_REG        (* (reg8 *) Lcd_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )
#define Lcd_CNTL_PTR        (  (reg8 *) Lcd_Cntl_Port_Sync_ctrl_reg__CONTROL_REG )
#endif /* CY_PSoC5A */

/***************************************
 *       Register Constants
 ***************************************/
                                                  
/* Pin Masks */
#define Lcd_E                        ((uint8) 0x10u)
#define Lcd_RS                       ((uint8) 0x20u)
#define Lcd_RW                       ((uint8) 0x40u)
#define Lcd_READY_BIT                ((uint8) 0x08u)
#define Lcd_DATA_MASK                ((uint8) 0x0Fu)


/***************************************
*       Obsolete function names
***************************************/
#if(Lcd_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete an they will be removed in future 
    * revisions of component.
    */
    #define Lcd_PrintDecUint16(x)   Lcd_PrintNumber(x)  
    #define Lcd_PrintHexUint8(x)    Lcd_PrintInt8(x)
    #define Lcd_PrintHexUint16(x)   Lcd_PrintInt16(x)        

#endif /* Lcd_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_Lcd_H */


/* [] END OF FILE */
