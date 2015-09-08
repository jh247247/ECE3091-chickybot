/*******************************************************************************
* File Name: Lcd.c
* Version 1.2
*
* Description:
*  This file provides source code for the Character LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "Lcd.h"


static void Lcd_WrDatNib(uint8 nibble) ;
static void Lcd_WrCntrlNib(uint8 nibble) ;

/* Stores the state of conponent. Indicates wherewer component is 
* in enable state or not.
*/
uint8 Lcd_enableState = 0u;

uint8 Lcd_initVar = 0u;


/*******************************************************************************
* Function Name: Lcd_Init
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Lcd_Init(void) 
{
    /* INIT CODE */
    CyDelay(40u);                                                        /* Delay 40 ms */
    Lcd_WrCntrlNib(Lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */
    Lcd_WrCntrlNib(Lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(15u);                                                        /* Delay 15 ms */
    Lcd_WrCntrlNib(Lcd_DISPLAY_8_BIT_INIT);   /* Selects 8-bit mode */
    CyDelay(1u);                                                         /* Delay 1 ms */
    Lcd_WrCntrlNib(Lcd_DISPLAY_4_BIT_INIT);   /* Selects 4-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */

    Lcd_WriteControl(Lcd_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    Lcd_WriteControl(Lcd_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    Lcd_WriteControl(Lcd_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    Lcd_WriteControl(Lcd_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    Lcd_WriteControl(Lcd_CLEAR_DISPLAY);          /* Clear LCD Screen */
    Lcd_WriteControl(Lcd_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    Lcd_WriteControl(Lcd_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(5u);

    #if(Lcd_CUSTOM_CHAR_SET != Lcd_NONE)
        Lcd_LoadCustomFonts(Lcd_customFonts);
    #endif /* Lcd_CUSTOM_CHAR_SET != Lcd_NONE */
}


/*******************************************************************************
* Function Name: Lcd_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Theory:
*  This finction has no effect when it called first time as
*  Lcd_Init() turns on the LCD.
*
*******************************************************************************/
void Lcd_Enable(void) 
{
    Lcd_DisplayOn();
    Lcd_enableState = 1u;
}


/*******************************************************************************
* Function Name: Lcd_Start
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*  If it was not the first call in this project then it just turns on the
*  display
*
*
* Parameters:
*  Lcd_initVar - global variable.
*
* Return:
*  Lcd_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Lcd_Start(void) 
{
    /* If not initialized then perform initialization */
    if(Lcd_initVar == 0u)
    {
        Lcd_Init();
        Lcd_initVar = 1u;
    }

    /* Turn on the LCD */
    Lcd_Enable();
}


/*******************************************************************************
* Function Name: Lcd_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Lcd_Stop(void) 
{
    /* Calls LCD Off Macro */
    Lcd_DisplayOff();
    Lcd_enableState = 0u;
}


/*******************************************************************************
*  Function Name: Lcd_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Specific row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays which use the 2X40 address mode.
*  This results in Row 2 offset from row one by 0x28.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void Lcd_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            Lcd_WriteControl(Lcd_ROW_0_START + column);
            break;
        case (uint8) 1:
            Lcd_WriteControl(Lcd_ROW_1_START + column);
            break;
        case (uint8) 2:
            Lcd_WriteControl(Lcd_ROW_2_START + column);
            break;
        case (uint8) 3:
            Lcd_WriteControl(Lcd_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: Lcd_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string:  pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        Lcd_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: Lcd_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character:  character to be written to the LCD
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_PutChar(char8 character) 
{
    Lcd_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: Lcd_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the LCD module's Data Display RAM.
*
* Parameters:
*  dByte:  byte to be written to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_WriteData(uint8 dByte) 
{
    uint8 nibble;

    /* Write high nibble */
	nibble = dByte >> Lcd_NIBBLE_SHIFT;
    Lcd_WrDatNib(nibble);

     CyDelayUs(Lcd_NIB_DELAY_US);
	 
    /* Write low nibble */
	nibble = dByte & Lcd_NIBBLE_MASK;
    Lcd_WrDatNib(nibble);
	
	CyDelayUs(Lcd_DATA_DELAY_US);

}


/*******************************************************************************
*  Function Name: Lcd_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module.
*
* Parameters:
*  cByte:   byte to be written to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
void Lcd_WriteControl(uint8 cByte) 
{
    uint8 nibble;

    /* WrCntrlNib(High Nibble) */
	 nibble = cByte >> Lcd_NIBBLE_SHIFT;
    Lcd_WrCntrlNib(nibble);

    CyDelayUs(Lcd_NIB_DELAY_US);
	
    /* WrCntrlNib(Low Nibble) */
	nibble = cByte & Lcd_NIBBLE_MASK;
    Lcd_WrCntrlNib(nibble);

     CyDelayUs(Lcd_CMD_DELAY_US);
}


/*******************************************************************************
* Function Name: Lcd_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes pins to High-Z.
*
*******************************************************************************/
void Lcd_IsReady(void) 
{
   
	CyDelay(1u);
	
}


/*******************************************************************************
*  Function Name: Lcd_WrDatNib
********************************************************************************
*
* Summary:
*  Writes a data nibble to the LCD module.
*
* Parameters:
*  nibble:  byte containing nibble in least significant nibble to be written
*           to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void Lcd_WrDatNib(uint8 nibble) 
{

    /* RS shoul be low to select data register */
    Lcd_CNTL_REG |= Lcd_RS;
    /* Reset RW for write operation */
    Lcd_CNTL_REG &= ~Lcd_RW;

    /* Two following lines of code will provide us with 40ns delay */
    /* Clear data pins */
    Lcd_CNTL_REG &= ~Lcd_DATA_MASK;

    /* Write in data, bring E high*/
    Lcd_CNTL_REG |= (Lcd_E | nibble);

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    Lcd_CNTL_REG &= ~Lcd_E;
	
}


/*******************************************************************************
*  Function Name: Lcd_WrCntrlNib
********************************************************************************
*
* Summary:
*  Writes a control nibble to the LCD module.
*
* Parameters:
*  nibble:  byte containing nibble in least significant nibble to be written
*           to LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void Lcd_WrCntrlNib(uint8 nibble) 
{
	
	/* RS and RW shoul be low to select instruction register and  write operation respectively */
    Lcd_CNTL_REG &= ~(Lcd_RS | Lcd_RW);

    /* Two following lines of code will give provide ua with 40ns delay */
    /* Clear data pins */
    Lcd_CNTL_REG &= ~Lcd_DATA_MASK;

    /* Write control data and set enable signal */
    Lcd_CNTL_REG |= (Lcd_E | nibble);

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    Lcd_CNTL_REG &= ~Lcd_E;
}


#if(Lcd_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: Lcd_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Lcd_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE Lcd_hex[16u] = "0123456789ABCDEF";
        
        Lcd_PutChar((char8) Lcd_hex[value >> Lcd_BYTE_UPPER_NIBBLE_SHIFT]);
        Lcd_PutChar((char8) Lcd_hex[value & Lcd_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: Lcd_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value:   The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Lcd_PrintInt16(uint16 value) 
    {
        Lcd_PrintInt8((uint8)(value >> Lcd_U16_UPPER_BYTE_SHIFT));
        Lcd_PrintInt8((uint8)(value & Lcd_U16_LOWER_BYTE_MASK));
    }


    /*******************************************************************************
    *  Function Name: Lcd_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Lcd_PrintNumber(uint16 value) 
    {

        char8 number[Lcd_NUMBER_OF_REMAINDERS];
        char8 temp[Lcd_NUMBER_OF_REMAINDERS];

        uint8 digIndex = 0u;
        uint8 numDigits;

        /* Load these in reverse order */
        while(value >= Lcd_TEN)
        {
            temp[digIndex] = (value % Lcd_TEN) + '0';
            value /= Lcd_TEN;
            digIndex++;
        }

        temp[digIndex] = (value % Lcd_TEN) + '0';
        numDigits = digIndex;

        /* While index is greater than or equal to zero copy number
        * from temporary array to number[].
        */
        while (digIndex != 0u)
        {
            number[numDigits - digIndex] = temp[digIndex];
            digIndex--;
        }
        
        /* Copy last digit */
        number[numDigits] = temp[0u];

        /* Null Termination */
        number[numDigits + 1u] = (char8) '\0';

        /* Print out number */
        Lcd_PrintString(&number[0u]);
    }

#endif /* Lcd_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
