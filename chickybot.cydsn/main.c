#include <project.h>
#include "cv.h"

int * plan;

void Btn0Pressed() {
    LedGreen_Write(!LedGreen_Read());
}

void Btn1Pressed() {
    LedBlue_Write(!LedBlue_Read());
}

void displayPlanOnLcd() {
    Lcd_Position(0,0);
    int i;
    for (i = 0; i < ROWS; i++) {
        Lcd_PrintDecUint16(plan[i]);
    }
}

void getPlan() {
    plan = (int *) malloc(sizeof(int) * ROWS);
    plan = readPlanWithCamera();
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
    
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
    getPlan();
    displayPlanOnLcd();

    for(;;)
    {
//        Lcd_Position(0,0);
//        Lcd_PrintString("Hello world!");
        
        CyDelay(1000);
    }
}
