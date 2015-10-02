#include "Arduino.h"
#include "Motion.h"

Motion::Motion(int pinElbowPos, int pinElbowNeg)
{
  pinMode(pinElbowPos, OUTPUT);
  pinMode(pinElbowNeg, OUTPUT);
  _pinElbowPos = pinElbowPos;
  _pinElbowNeg = pinElbowNeg;
}

void Motion::goUpElbow(int speed)
{
  digitalWrite(_pinElbowPos, HIGH);
  digitalWrite(_pinElbowNeg, LOW);
}

void Motion::goDownElbow(int speed)
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, HIGH);
}

void Motion::stopMotorElbow()
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, LOW);
}
