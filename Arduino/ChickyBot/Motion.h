#ifndef Motion_h
#define Motion_h

#include "Arduino.h"

#define ELBOW_MIN_ANGLE 15
#define ELBOW_MIN 876
#define ELBOW_MAX_ANGLE 90
#define ELBOW_MAX 513

// TODO: Shoulder angles
#define SHOULDER_MIN_ANGLE 0
#define SHOULDER_MIN 800
#define SHOULDER_MAX_ANGLE 0
#define SHOULDER_MAX 900

class Motion
{
  public:
    Motion(int pinElbowPos, int pinElbowNeg, int pinShoulderPos, int pinShoulderNeg);
    void goUpElbow();
    void goDownElbow();
    void goUpElbowSpeed(int speed);
    void goDownElbowSpeed(int speed);
	  void stopMotorElbow();

    void goUpShoulder();
    void goDownShoulder();
    void goUpShoulderSpeed(int speed);
    void goDownShoulderSpeed(int speed);
    void stopMotorShoulder();
    
    double getRadius(int angleElbow, int angleShoulder);
    double getHeight(int angleElbow, int angleShoulder);
    
    double posToElbowAngle(double radius, double height);
    double posToShoulderAngle(double radius, double height);

    int potElbowToAngle(int currPosElbow);
    int angleToPotElbow(int angle);

    int potShoulderToAngle(int currPosShoulder);
    int angleToPotShoulder(int angle);
  private:
    int _pinElbowPos;
	  int _pinElbowNeg;
    int _pinShoulderPos;
    int _pinShoulderNeg;
};


#endif
