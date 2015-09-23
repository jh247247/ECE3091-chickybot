#include <project.h>
#include <stdlib.h>
#include "cv.h"

uint8 * plan;

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
        Lcd_Position(0, 4*i);
        Lcd_PrintDecUint16(plan[i]);
    }
}

void getPlan() {
    //plan = (uint8 *) malloc(sizeof(int) * ROWS);
    plan = readPlanWithCamera();
    Lcd_PosPrintString(1, 0, "returned");
}



int main()
{
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);

    // Starts
    CsBtns_Start();
    Lcd_Start();
//    Camera_Start();
    
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
//    getPlan();
//    displayPlanOnLcd();
    
    
    for(;;)
    {
        Lcd_Position(0,0);
        Lcd_PrintString("Hello world!");
        
        CyDelay(500);
    }
}
