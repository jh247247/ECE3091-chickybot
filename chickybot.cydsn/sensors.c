#include <project.h>

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