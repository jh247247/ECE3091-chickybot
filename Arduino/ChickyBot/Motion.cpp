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
  digitalWrite(_pinElbowPos, HIGH);
  digitalWrite(_pinElbowNeg, LOW);
}

void Motion::goDownElbow()
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, HIGH);
}

void Motion::goUpElbowSpeed(int speed)
{
  analogWrite(_pinElbowPos, speed);
  analogWrite(_pinElbowNeg, 0);
}

void Motion::goDownElbowSpeed(int speed)
{
  analogWrite(_pinElbowPos, 0);
  analogWrite(_pinElbowNeg, speed);
}


void Motion::stopMotorElbow()
{
  digitalWrite(_pinElbowPos, LOW);
  digitalWrite(_pinElbowNeg, LOW);
}
