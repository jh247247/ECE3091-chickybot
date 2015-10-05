#ifndef Motion_h
#define Motion_h

#include "Arduino.h"


class Motion
{
  public:
    Motion(int pinElbowPos, int pinElbowNeg);
    void goUpElbow();
    void goDownElbow();
    void goUpElbowSpeed(int speed);
    void goDownElbowSpeed(int speed);
	  void stopMotorElbow();
  private:
    int _pinElbowPos;
	  int _pinElbowNeg;
};


#endif
