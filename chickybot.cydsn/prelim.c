#include <project.h>
#include <math.h>
#include "main.h"
#include "motion.h"
#include "sensors.h"


//#define FINAL_SHOULDER_ANGLE 160
//#define FINAL_ELBOW_ANGLE 160
#define HOME_ANGLE_S 20
#define HOME_ANGLE_E 45

//arbitrary distance
#define DISTANCE_FROM_GROUND 1

//construction zone limits
#define CZ_BOUND_BOTTOM 40
#define CZ_BOUND_TOP 165
#define CZ_BOUND_L -30
#define CZ_BOUND_R 90
#define CZ_MIDDLE 185

uint8 width[] = {29,76,65,-11,3,64,19,69,59,33,87,-28,65,-8,81,34,20,-4,-16,87}; 
uint8 length[] = {162,131,69,106,46,153,65,156,121,49,154,68,141,59,73,102,128,150,116,78};


uint16 angleToDistanceElbow(int16 E, int16 S){
    uint16 y;
    return y = sin(S)-0.9*sin(180-S-E);
}

uint16 angleToDistanceShoulder(int16 E, int16 S){
    uint16 x;
    x = cos(S)+0.9*cos(180-S-E);
    return x; 
}

uint16 distanceToAngleElbow(int16 x, int16 y){
    uint16 E;
    E = acos(-(pow(y,2)+pow(x,2)-pow(0.9,2)-1)/1.8);
    return E;
}

uint16 distanceToAngleShoulder(int16 x, int16 y){
    uint16 S;
    uint16 E = distanceToAngleElbow(x,y);
    S = asin(0.9*sin(E)/sqrt(pow(y,2)+pow(x,2)))+atan(y/x);
    return S;
}


uint8 prelim()
{
    uint8 state = 0;
    int pucksPicked = 0;
    int i = 0;
    
    uint8 finalShoulderAngle[] = {};
    int finalElbowAngle[] = {};
    int timeLim[] = {};
    
    while (1) {
        switch(state) {
            case 0: //moving to the arena
        // changes depending on how much you move 
        //need to randomise these values
                rotateStepCW(timeLim[i]); // Rotate away from home a bit

                while ((getElbowPos()< finalElbowAngle[i]) || (getShoulderPos() < finalShoulderAngle[i])) { 
                    elbowUpStep(); // Increases elbow "angle" a bit
                    shoulderDownStep(); // Decreases shoulder "angle" a bit  
                } 
                    //CyDelay(500); 
                state++;
            case 1: //move to ground
                while (angleToDistanceElbow(getElbowPos(), getShoulderPos()) < DISTANCE_FROM_GROUND) {
                    elbowDownStep();
                    shoulderDownStep();
                }
                //CyDelay(500); 
                state++;
            case 2: // turn on fan 
               Fan_Write(1); // Fan on
            case 3: // lift
                elbowUpStep();
                shoulderUpStep();
                //CyDelay(500); 
                state++;
            case 4: //retract arm
                elbowGoToPos(HOME_ANGLE_E);
                shoulderGoToPos(HOME_ANGLE_S);
                //CyDelay(500); 
                state++;
            case 5: //move to home
                rotateToHome(); // Rotates until microswitch clicked and in home position
                //CyDelay(500); 
                state++;
            case 6:// drop puck
                while (1) {
                    if (MicroSwitch_Read() == 1) {
                        break;
                    }
                    else {
                        CyDelay(300);
                    }
                }
                Fan_Write(0);
                pucksPicked++;
                if (pucksPicked<20){
                    i++;
                    state = 0;                    
                }
                else {
                    state++;
                }
                //CyDelay(500);
            case 7: 
                while ((getElbowPos() > 0) && (getShoulderPos() > 90)) {
                    shoulderUpStep();
                    elbowDownStep();
                }
                break;
        }
    }
    
    return 0;
}
