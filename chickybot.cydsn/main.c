#include <project.h>

void Btn0Pressed() {
    LedGreen_Write(!LedGreen_Read());
}

void Btn1Pressed() {
    LedBlue_Write(!LedBlue_Read());
}

int main()
{
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);

    // Starts
    CsBtns_Start();
    Lcd_Start();
    Camera_Start();

    for(;;)
    {
        Lcd_Position(0,0);
        Lcd_PrintString("Hello world!");
        
        CyDelay(1000);
    }
}
