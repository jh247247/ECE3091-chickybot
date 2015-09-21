#include <project.h>
#include "main.h"

#define POS_BUFFER 2
#define STEP_SIZE 30

int16 getElbowPos() {
    AMux_Select(AMUX_ELBOW);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    return ADC_GetResult16();
}

void displayElbowPos() {
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(ADC_CountsTo_mVolts(getElbowPos()));
}


int16 getShoulderPos() {
    AMux_Select(AMUX_SHOULDER);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    return ADC_GetResult16();
}

void displayShoulderPos() {
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(ADC_CountsTo_mVolts(getShoulderPos()));
}

void elbowUp() {
    ElbowPos_Write(0);
    ElbowNeg_Write(1);
}

void elbowDown() {
    ElbowPos_Write(1);
    ElbowNeg_Write(0);
}

void elbowStop() {
    ElbowPos_Write(0);
    ElbowNeg_Write(0);
}

uint8 elbowGoToPos(int16 goalPos) {
    while (1) {
        int16 currPos = getElbowPos();
        
        if ((currPos > goalPos - POS_BUFFER) && (currPos < goalPos + POS_BUFFER)) {
            elbowStop();
            return 0;
        }
        else if (currPos < goalPos) {
            elbowUp();
        }
        else if (currPos > goalPos) {
            elbowDown();
        }
    }
}

void elbowUpStep() {
    int16 currPos = getElbowPos();
    int16 newPos = currPos - STEP_SIZE;
    
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(currPos);
    Lcd_Position(0,5);
    Lcd_PrintString("->");
    Lcd_Position(0,8);
    Lcd_PrintDecUint16(newPos);
    
    elbowGoToPos(newPos);
}

void elbowDownStep() {
    int16 currPos = getElbowPos();
    int16 newPos = currPos + STEP_SIZE;
    
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(currPos);
    Lcd_Position(0,5);
    Lcd_PrintString("->");
    Lcd_Position(0,8);
    Lcd_PrintDecUint16(newPos);
    
    elbowGoToPos(newPos);
}
