#ifndef Motion_h
#define Motion_h

#include "Arduino.h"

#define ELBOW_MIN_ANGLE 15
#define ELBOW_MIN 876
#define ELBOW_MAX_ANGLE 90
#define ELBOW_MAX 513

class Motion
{
  public:
    Motion(int pinElbowPos, int pinElbowNeg);
    void goUpElbow();
    void goDownElbow();
    void goUpElbowSpeed(int speed);
    void goDownElbowSpeed(int speed);
	  void stopMotorElbow();
    
    double getRadius(int angleElbow, int angleShoulder);
    double getHeight(int angleElbow, int angleShoulder);
    
    double posToElbowAngle(double radius, double height);
    double posToShoulderAngle(double radius, double height);

    int potElbowToAngle(int currPosElbow);
    int angleToPotElbow(int angle);
  private:
    int _pinElbowPos;
	  int _pinElbowNeg;
};


#endif
