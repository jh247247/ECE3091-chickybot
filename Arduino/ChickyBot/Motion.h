#ifndef Motion_h
#define Motion_h

#include "Arduino.h"

// TODO: Add angle for MIN
#define ELBOW_MIN_ANGLE 0
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
    int posToElbowAngle(double radius, double height);
    int posToShoulderAngle(double radius, double height);
    int potElbowToAngle(int currPosElbow);
  private:
    int _pinElbowPos;
	  int _pinElbowNeg;
};


#endif
