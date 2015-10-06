#include <math.h>
#include "Arduino.h"
#include "Motion.h"

const double pi = 3.14159265359;

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

int Motion::posToElbowAngle(double radius, double height)
{
  return acos(-(pow(height,2)+pow(radius,2)-pow(0.9,2)-1)/1.8);
}

int Motion::potElbowToAngle(int currPosElbow)
{
  return map(currPosElbow, ELBOW_MIN, ELBOW_MAX, ELBOW_MIN_ANGLE, ELBOW_MAX_ANGLE);
}

