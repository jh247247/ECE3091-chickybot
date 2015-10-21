#include <project.h>
#include <stdlib.h>
#include "cv.h"

uint16 * plan;
#define MAX_TRIES 3
uint8 tries = 0;

void Btn0Pressed() {
    LedGreen_Write(!LedGreen_Read());
}

void Btn1Pressed() {
    LedBlue_Write(!LedBlue_Read());
}

void displayPlanOnLcd() {
//    Lcd_ClearDisplay();
    
    int i;
    for (i = 0; i < ROWS; i++) {
        Lcd_Position(1, 5*i);
        Lcd_PrintDecUint16(plan[i]);
//        Lcd_PrintInt8(plan[i]);
    }
}

uint8 getPlan() {
    uint8 tries;
    for (tries = 1; tries <= MAX_TRIES; tries++) {
        plan = readPlanWithCamera();
        
        int i;
        for (i = 0; i < ROWS; i++) {
            if (plan[i] != NONE) {
//                Lcd_PosPrintNumber(1,15, tries);
                return 0;
            }
        }
    }
//    Lcd_PosPrintNumber(1,15, --tries);
    return 1;
//    Lcd_PosPrintString(1, 0, "returned");
}



int main()
{
    CyDelay(1000); // TODO: Necessary to wait for Camera to start up?
    
    // Interrupts
    CyGlobalIntEnable; /* Enable global interrupts. */
    IsrBtn0Pressed_StartEx(Btn0Pressed);
    IsrBtn1Pressed_StartEx(Btn1Pressed);
    
    // Starts
    USB_Start(0,USB_DWR_VDDD_OPERATION);
	while(!USB_GetConfiguration());
    
    CsBtns_Start();
    Lcd_Start();
    Camera_Start();
    
    USB_CDC_Init(); //enable receiving data from USB host
	while(!USB_DataIsReady()); //wait until data is received on USB for synchronisation
    
    CyDelay(1000); // TODO: Necessary to wait for Camera to start up?
    
    getPlan();
    displayPlanOnLcd();
    
    
    for(;;)
    {
//        Lcd_Position(0,0);
//        Lcd_PrintString("Hello world!");
        
        CyDelay(500);
    }
}
