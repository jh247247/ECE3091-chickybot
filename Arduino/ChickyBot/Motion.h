#ifndef Motion_h
#define Motion_h

#include "Arduino.h"

// Elbow angles
#define ELBOW_MIN_ANGLE 15
#define ELBOW_MIN 750
#define ELBOW_MAX_ANGLE 90
#define ELBOW_MAX 510

// Shoulder angles
#define SHOULDER_MIN_ANGLE 18
#define SHOULDER_MIN 400
#define SHOULDER_MAX_ANGLE 67
#define SHOULDER_MAX 200

// Head Servo
#define HEAD_SERVO_UP_POS 420
#define HEAD_SERVO_DOWN_POS 320

class Motion
{
  public:
    Motion(int pinElbowPos, int pinElbowNeg, int pinShoulderPos, int pinShoulderNeg, int pinWaistCW, int pinWaistCCW, int pinHeadServo);
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

    void goCW();
    void goCCW();
    void stopWaist();

    void headServoUp();
    void headServoDown();
    
  private:
    int _pinElbowPos;
	  int _pinElbowNeg;
    int _pinShoulderPos;
    int _pinShoulderNeg;
    int _pinWaistCW;
    int _pinWaistCCW;
    int _pinHeadServo;
};


#endif
