#include <project.h>
#include <stdlib.h>
#include "cv.h"
#include "sensors.h"

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



//void ADC_Elbow_EOC() {
//    int16 result = ADC_Elbow_GetResult16();
//}


int main()
{
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);
    IsrUsTimer_StartEx(UsSensorTrigger);
//    IsrADC_Elbow_EOC_StartEx(ADC_Elbow_EOC);

    // Starts
    CsBtns_Start();
    Lcd_Start();
    Camera_Start();
    UsPWM_Start();
    UsTimer_Start();
    ADC_Elbow_Start();
    ADC_Elbow_StartConvert();
    
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
//    getPlan();
//    displayPlanOnLcd();
    
//    UsTimer_EnableTrigger();

    for(;;)
    {
//        displayPlanOnLcd();
        
        
//        Lcd_Position(0,0);
//        Lcd_PrintString("Hello world!");
        
        // UltraSonic Test
//        UsSensor();
//        
        drawDistToLcd();
        
//        ADC_Elbow_IsEndConversion(ADC_Elbow_WAIT_FOR_RESULT);
//        Lcd_Position(0,0);
//        Lcd_PrintDecUint16(ADC_Elbow_GetResult16());
        
        CyDelay(500);
//        UsTimer_EnableTrigger();
    }
}
