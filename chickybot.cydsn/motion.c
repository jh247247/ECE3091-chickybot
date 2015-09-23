#include <project.h>
#include "main.h"
#include "motion.h"

#define POS_BUFFER_ELBOW 5
#define POS_BUFFER_BIG_ELBOW 10
#define STEP_SIZE_ELBOW 60

#define POS_BUFFER_SHOULDER 10
#define POS_BUFFER_BIG_SHOULDER 20
#define STEP_SIZE_SHOULDER 60

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
    int16 currPos = getElbowPos();
    
    if ((currPos > goalPos - POS_BUFFER_BIG_ELBOW) && (currPos < goalPos + POS_BUFFER_BIG_ELBOW)) {
        return 1;
    }
    
    while (1) {
        int16 currPos = getElbowPos();
        
        if ((currPos > goalPos - POS_BUFFER_ELBOW) && (currPos < goalPos + POS_BUFFER_ELBOW)) {
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
    int16 newPos = currPos - STEP_SIZE_ELBOW;
    
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
    int16 newPos = currPos + STEP_SIZE_ELBOW;
    
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(currPos);
    Lcd_Position(0,5);
    Lcd_PrintString("->");
    Lcd_Position(0,8);
    Lcd_PrintDecUint16(newPos);
    
    elbowGoToPos(newPos);
}

void shoulderUpStep() {
    int16 currPos = getShoulderPos();
    int16 newPos = currPos - STEP_SIZE_SHOULDER;
    
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(currPos);
    Lcd_Position(0,5);
    Lcd_PrintString("->");
    Lcd_Position(0,8);
    Lcd_PrintDecUint16(newPos);
    
    shoulderGoToPos(newPos);
}
void shoulderDownStep() {
    int16 currPos = getShoulderPos();
    int16 newPos = currPos + STEP_SIZE_SHOULDER;
    
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16(currPos);
    Lcd_Position(0,5);
    Lcd_PrintString("->");
    Lcd_Position(0,8);
    Lcd_PrintDecUint16(newPos);
    
    shoulderGoToPos(newPos);
}

void shoulderUp() {
    ShoulderPos_Write(0);
    ShoulderNeg_Write(1);
}
void shoulderDown() {
    ShoulderPos_Write(1);
    ShoulderNeg_Write(0);
}
void shoulderStop() {
    ShoulderPos_Write(0);
    ShoulderNeg_Write(0);
}

uint8 shoulderGoToPos(int16 goalPos) {
    int16 currPos = getShoulderPos();
    
    if ((currPos > goalPos - POS_BUFFER_BIG_SHOULDER) && (currPos < goalPos + POS_BUFFER_BIG_SHOULDER)) {
        return 1;
    }
    
    while (1) {
        int16 currPos = getShoulderPos();
        
        if ((currPos > goalPos - POS_BUFFER_SHOULDER) && (currPos < goalPos + POS_BUFFER_SHOULDER)) {
            shoulderStop();
            return 0;
        }
        else if (currPos < goalPos) {
            shoulderUp();
        }
        else if (currPos > goalPos) {
            shoulderDown();
        }
    }
}

void rotateToHome() {
    RotateCCW_Write(1);
    RotateCW_Write(0);
}
void rotateStepCCW(uint16 timeToMove) {
    RotateCCW_Write(1);
    RotateCW_Write(0);
    
    CyDelay(timeToMove);
    
    RotateCCW_Write(0);
    RotateCW_Write(0);
}
void rotateStepCW(uint16 timeToMove) {
    RotateCCW_Write(0);
    RotateCW_Write(1);
    
    CyDelay(timeToMove);
    
    RotateCCW_Write(0);
    RotateCW_Write(0);
}

uint16 * getPosCoords() {
    uint16 * coords[2] = {0, 0};
    return *(coords);
}

int16 elbowAngleToPotPos(uint8 angle) {
    return (int16) (-11.067 * ((float) angle) + 2385);
}
int16 shoulderAngleToPotPos(uint8 angle) { // Need more datapoints to confirm formula
    return (int16) (-3.333 * ((float) angle) + 2400);
}
uint8 elbowPotPosToAngle(int16 potPos) {
    return (uint8) (0.09035 * (2385 - potPos));
}
uint8 shoulderPotPosToAngle(int16 potPos) { // Need more datapoints to confirm formula
    return (uint8) (0.3 * (2400 - potPos));;
}