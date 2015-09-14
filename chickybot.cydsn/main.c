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
        Lcd_PrintDecUint16(plan[i]);
    }
}

void getPlan() {
    //plan = (uint8 *) malloc(sizeof(int) * ROWS);
    plan = readPlanWithCamera();
    Lcd_PosPrintString(0, 0, "returned");
}

//void UsSensor() {
//    LedRed_Write(!LedRed_Read());
//    
//    
//}
//
void UsSensorTrigger() {
    LedYellow_Write(!LedYellow_Read());
    
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(UsTimer_ReadCapture()); // Possibly losing info here, b/c capture is uint32
    uint32 dist = UsTimer_ReadCapture() * 10 / 58;
}


int main()
{
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);
    IsrUsTimer_StartEx(UsSensorTrigger);

    // Starts
    CsBtns_Start();
    Lcd_Start();
    Camera_Start();
    UsPWM_Start();
    UsTimer_Start();
    
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
//    getPlan();
    
    

    for(;;)
    {
//        displayPlanOnLcd();
        
        
//        Lcd_Position(0,0);
//        Lcd_PrintString("Hello world!");
        
        // UltraSonic Test
//        UsSensor();
//        
//        Lcd_Position(0,0);
//        Lcd_PrintDecUint16(UsTimer_ReadCapture());
        
        CyDelay(500);
    }
}
