#include "Arduino.h"
#include "Motion.h"

Motion::Motion(int pinElbowPos, int pinElbowNeg)
{
  pinMode(pinElbowPos, OUTPUT);
  pinMode(pinElbowNeg, OUTPUT);
  _pinElbowPos = pinElbowPos;
  _pinElbowNeg = pinElbowNeg;
}

void Motion::goUpElbow()
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, HIGH);
}

void Motion::goDownElbow()
{
  digitalWrite(_pinElbowPos, HIGH);
  digitalWrite(_pinElbowNeg, LOW);
}

void Motion::stopMotorElbow()
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, LOW);
}
