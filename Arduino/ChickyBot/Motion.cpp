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

double Motion::getRadius(int angleElbow, int angleShoulder)
{
  return 98*cos(angleShoulder*(pi/180))+96*cos((180-angleShoulder-angleElbow)*(pi/180));
}
double Motion::getHeight(int angleElbow, int angleShoulder)
{
  return 98*sin(angleShoulder*(pi/180))-96*sin((180-angleShoulder-angleElbow)*(pi/180));
}

double Motion::posToElbowAngle(double radius, double height)
{
  return acos((pow(height,2)+pow(radius,2)-18820)/-18816)*(180/pi);
}
double Motion::posToShoulderAngle(double radius, double height)
{
  double elbowAngle = posToElbowAngle(radius, height);
  if (elbowAngle > 45)
  {
    return (asin((96*sin(elbowAngle*(pi/180)))/(sqrt(pow(height,2)+pow(radius,2))))*(180/pi) + atan(radius/height)*(180/pi));
  }
  else
  {
    return (asin((96*sin(elbowAngle*(pi/180)))/(sqrt(pow(height,2)+pow(radius,2))))*(180/pi) - atan(radius/height)*(180/pi) + 90);
  }
}

int Motion::potElbowToAngle(int currPosElbow)
{
  return map(currPosElbow, ELBOW_MIN, ELBOW_MAX, ELBOW_MIN_ANGLE, ELBOW_MAX_ANGLE);
}
int Motion::angleToPotElbow(int angle)
{
  return map(angle, ELBOW_MIN_ANGLE, ELBOW_MAX_ANGLE, ELBOW_MIN, ELBOW_MAX);
}

