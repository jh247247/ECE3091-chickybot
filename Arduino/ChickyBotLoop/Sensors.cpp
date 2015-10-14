#include "Arduino.h"
#include "Sensors.h"

Sensors::Sensors(int pinPhotoDiode, int pinLedRed, int pinLedGreen, int pinLedBlue)
{
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedBlue, OUTPUT);
  _pinPhotoDiode = pinPhotoDiode;
  _pinLedRed = pinLedRed;
  _pinLedGreen = pinLedGreen;
  _pinLedBlue = pinLedBlue;
}

int Sensors::getHeadColour()
{
  return 0;
}
