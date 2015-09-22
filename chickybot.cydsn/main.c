#include <project.h>
#include <stdlib.h>
#include "main.h"
#include "cv.h"
#include "sensors.h"
#include "motion.h"

uint8 * plan;

void Btn0Pressed() {
    LedGreen_Write(!LedGreen_Read());
    rotateStepCCW(100);
}

void Btn1Pressed() {
    LedBlue_Write(!LedBlue_Read());
    rotateStepCW(100);
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

void MicroSwitchTrigger() {
    LedRed_Write(!LedRed_Read());
    
    RotateCCW_Write(0);
    RotateCW_Write(0);
}



int main()
{
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);
    IsrUsTimer_StartEx(UsSensorTrigger);
    IsrMicroSwitch_StartEx(MicroSwitchTrigger);

    // Starts
    CsBtns_Start();
    Lcd_Start();
//    Camera_Start();
    UsPWM_Start();
    UsTimer_Start();
    ADC_Start();
    ADC_StartConvert();
    AMux_Start();
    
    CyDelay(500); // TODO: Necessary to wait for Camera to start up?
    
//    getPlan();
//    displayPlanOnLcd();
    
//    UsTimer_EnableTrigger();
    
    
    for(;;)
    {
//        // Go to home code
//        if (MicroSwitch_Read() == 0) {
//            rotateToHome();
//        }
        
        
        
//        Lcd_Position(0,0);
//        Lcd_PrintString("Hello world!");
        
        
        
        displayShoulderPos();
        int16 shoulderPos = getShoulderPos();
        
        Lcd_ClearDisplay();
//        Lcd_Position(0,0);
//        Lcd_PrintDecUint16(ADC_CountsTo_mVolts(shoulderPos));
//        Lcd_Position(0,8);
//        Lcd_PrintString("mV");
        Lcd_Position(1,0);
        Lcd_PrintDecUint16(shoulderPos);
        Lcd_Position(1,8);
        Lcd_PrintString("/ 4095");
        
        shoulderGoToPos(2220);
        
//        ElbowPos_Write(0);
//        ElbowNeg_Write(1);
//        CyDelay(1000);
//        ElbowPos_Write(0);
//        ElbowNeg_Write(0);
//        CyDelay(700);
        
//        ElbowPos_Write(1);
//        ElbowNeg_Write(1);
//        ShoulderPos_Write(1);
//        ShoulderNeg_Write(1);
//        elbowGoToPos(ELBOW_30_DEG);
        
        CyDelay(300);
//        UsTimer_EnableTrigger();
    }
}
