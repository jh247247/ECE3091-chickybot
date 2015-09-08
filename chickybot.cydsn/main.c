/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

void Btn0Pressed() {
    LedGreen_Write(!LedGreen_Read());
}

void Btn1Pressed() {
    LedBlue_Write(!LedBlue_Read());
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CsBtns_Start();
    Lcd_Start();

    for(;;)
    {
        /* Place your application code here. */
        Lcd_Position(0,0);
        Lcd_PrintString("Hello world!");
        
        CyDelay(1000);
    }
}

/* [] END OF FILE */
