//#define FINAL_SHOULDER_ANGLE 160
//#define FINAL_ELBOW_ANGLE 160
#define HOME_ANGLE_S 20
#define HOME_ANGLE_E 45
#define DISTANCE_FROM_GROUND 1
#include <project.h>
#include <math.h>;

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
    E = acos(-(y^2+x^2-(0.9^2)-1)/1.8);
    return E;
}

uint16 distanceToAngleShoulder(int16 x, int16 y){
    uint16 S;
    uint16 E=distanceToAngleElbow(x,y);
    S= asin((0.9*sin(E)/sqrt(y^2+x^2))+atan(y/x);
    return S;
}

int main()
{
    int finalShoulderAngle=160;
    int finalElbowAngle = 160;
    CyGlobalIntEnable; /* Enable global interrupts. */
    int caseVar=0;
    //int angleE=0;
    //int angleS=0;
    int pucksPicked=0;
    int timeLim;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    //START
         
    switch(caseVar){
            case 0: //moving to the arena
        // changes depending on how much you move 
        //need to randomise these values
                    rotateStepCW(timeLim); // Rotate away from home a bit

                while(getElbowPos()< finalElbowAngle && getShoulderPos()< finalShoulderAngle){ 
                    elbowUpStep(); // Increases elbow "angle" a bit
                    shoulderDownStep(); // Decreases shoulder "angle" a bit  
                } 
                
                if(finalElbowAngle-20<0 || finalShoulderAngle-20<20){
                    finalShoulderAngle=finalShoulderAngle-20;
                    finalElbowAngle = finalElbowAngle-20;
                }
                else{
                    finalShoulderAngle=finalShoulderAngle+30;
                    finalElbowAngle = finalElbowAngle+30;
                }
                //CyDelay(500); 
                caseVar++;
            case 1: //move to ground
                while(angleToDistanceElbow(getElbowPos(), getShoulderPos())< DISTANCE_FROM_GROUND){
                    elbowDownStep();
                    shoulderDownStep();
                }
                //CyDelay(500); 
                caseVar++;
            case 2: // turn on fan 
               Fan_Write(1); // Fan on
            case 3: // lift
                elbowUpStep();
                shoulderUpStep();
                //CyDelay(500); 
                caseVar++;
            case 4: //retract arm
                elbowGoToPos(HOME_ANGLE_E);
                shoulderGoToPos(HOME_ANGLE_S);
                //CyDelay(500); 
                caseVar++;
            case 5: //move to home
                
                rotateToHome(); // Rotates until microswitch clicked and in home position
                //CyDelay(500); 
                caseVar++;
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
                    timeLim = timeLim+300;
                    caseVar = 0;                    
                }
                else {
                    caseVar++;
                }
                //CyDelay(500);
            case 7: 
                while(getElbowPos>0 && getShoulderPos >90){
                    shoulderUpStep();
                    elbowDownStep();
                }
                break;
    }
    
    

    
    //GO TO MIDDLE OF ARENA
    //first I need to determine where the middle actually is
    //to do this would it be smart to alternate between elbowUpStep() 
    //RANDOM MOVEMENT
    //MOVE TO GROUND
    //TURN ON FAN
    //TURN OFF FAN
    
    // 3 pucks yet?
    //if yes:
    //fold in
    //END
    // if no:
    //repeat movement
    for(;;)
    {
        /* Place your application code here. */
    }
}
