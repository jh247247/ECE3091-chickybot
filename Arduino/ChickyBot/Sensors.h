#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"


class Sensors
{
  public:
    Sensors(int pinPhotoDiode, int pinLedRed, int pinLedGreen);
    int getHeadColour();
  private:
    int _pinPhotoDiode;
	  int _pinLedRed;
	  int _pinLedGreen;
};


#endif
