#include "Arduino.h"
#include "Sensors.h"

Sensors::Sensors(int pinPhotoDiode, int pinLedRed, int pinLedGreen)
{
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  _pinPhotoDiode = pinPhotoDiode;
  _pinLedRed = pinLedRed;
  _pinLedGreen = pinLedGreen;
}

int Sensors::getHeadColour()
{
  return 0;
}
