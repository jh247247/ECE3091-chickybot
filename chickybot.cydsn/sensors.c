#include <project.h>
#include "main.h"

uint32 rc;
uint32 dist;

void UsSensorTrigger() {
    UsTimer_DisableTrigger();
    UsTimer_ReadStatusRegister();
    rc = UsTimer_ReadCapture();
    dist = (38000 - rc) * 10 / 58;
    
    LedYellow_Write(!LedYellow_Read());
    
//    CyDelay(500);
    
    UsTimer_ClearFIFO();
    UsTimer_WritePeriod(UsTimer_INIT_PERIOD);
    UsTimer_WriteCounter(UsTimer_INIT_PERIOD);
    UsTimer_EnableTrigger();
}

uint16 getDist() {
    return dist;
}

void drawDistToLcd() {
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintDecUint16((uint16) rc);
    Lcd_Position(1,0);
    Lcd_PrintDecUint16((uint16) dist);
}


void getColour() {
    ADC_Start();
    ADC_StartConvert();
    AMux_Select(AMUX_COLOUR_1);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    
    int16 result = ADC_GetResult16();
    
    //this is if the result matches up with ambient lighting
    if(result == 0){
        Lcd_ClearDisplay();
        Lcd_WriteControl(Lcd_CLEAR_DISPLAY);
        Lcd_Position(0,0);
        Lcd_PrintDecUint16(result);
        Lcd_PosPrintString(1,0, "AMBIENT");
    }
    //this is if the result matches up with picking up red light
    else if(result == 0){
        Lcd_ClearDisplay();
        Lcd_WriteControl(Lcd_CLEAR_DISPLAY);
        Lcd_Position(0,0);
        Lcd_PrintDecUint16(result);
        Lcd_PosPrintString(1,0, "RED");
    }
    
    //this is if the result matches up with picking up blue light
    else if(result == 0){
        Lcd_ClearDisplay();
        Lcd_WriteControl(Lcd_CLEAR_DISPLAY);
        Lcd_Position(0,0);
        Lcd_PrintDecUint16(result);
        Lcd_PosPrintString(1,0, "BLUE");
    }
    
    //this is if the result matches up with picking up green light
    else if(result == 0){
        Lcd_ClearDisplay();
        Lcd_WriteControl(Lcd_CLEAR_DISPLAY);
        Lcd_Position(0,0);
        Lcd_PrintDecUint16(result);
        Lcd_PosPrintString(1,0, "GREEN");
    }
    //this is a case that has not been explained
    else {
        Lcd_ClearDisplay();
        Lcd_WriteControl(Lcd_CLEAR_DISPLAY);
        Lcd_Position(0,0);
        Lcd_PrintDecUint16(result);
        Lcd_PosPrintString(1,0, "UMMM....");
    }
}