#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"


class Sensors
{
  public:
    Sensors(int pinPhotoDiode, int pinLedRed, int pinLedGreen, int pinLedBlue);
    int getHeadColour();
    int checkForPuck();
    void turnAllLightsOn();
    void turnAllLightsOff();
    
  private:
    int _pinPhotoDiode;
	  int _pinLedRed;
	  int _pinLedGreen;
    int _pinLedBlue;

    void setBalance();
    int getHeadColourAux();
    void checkColour();
    float getReading(int times);
};


#endif
