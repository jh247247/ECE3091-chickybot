#include <avr/io.h>
#include <avr/interrupt.h>
#include "Ultrasonic.h"
#include "LiquidCrystal.h"
#include "Motion.h"
#include "Sensors.h"

// TODO: Add angle for MIN
#define ELBOW_MIN_ANGLE 0
#define ELBOW_MIN 876
#define ELBOW_MAX_ANGLE 90
#define ELBOW_MAX 513

#define BUFFER_ELBOW 10
#define BUFFER_ELBOW_DECEL 40

#define PIN_LED 13
#define PIN_TRIG 6
#define PIN_ECHO 4
#define PIN_MOTOR_ELBOW_POS 5
#define PIN_MOTOR_ELBOW_NEG 3
#define PIN_FAN 2
#define PIN_MOTOR_ELBOW_POT A0

LiquidCrystal lcd(7, 8, A5, A4, A3, A2);

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long heightUS;

Motion motion(PIN_MOTOR_ELBOW_POS, PIN_MOTOR_ELBOW_NEG);

int currPosElbow;
int goalPosElbow;

int goalReached = 0;
int goal1 = ELBOW_MIN;
int goal2 = ELBOW_MAX;

int firstMove = 1;

void setup()
{
  Serial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Hello world!");
  
  // Init Timer1
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  /* 0.1 s timer
   * 1 / (16e6/1024) = 6.4e-5
   * (0.1 s / 6.4e-5) - 1 = 1562
   */
  OCR1A = 1562;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  sei();

  goalPosElbow = goal1;
}
 
void loop()
{
  // Update LCD
  lcd.clear();
  lcd.setCursor(0,0);
//  lcd.print("US: ");
//  lcd.print(heightUS);
//  lcd.print(" cm");
//  lcd.setCursor(0,1);
  lcd.print("E: ");
  lcd.print(currPosElbow);

  lcd.setCursor(0,1);
  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  int angle = motion.potElbowToAngle(currPosElbow);
  lcd.print(angle);

  delay(400);

  if (goalReached == 1) {
    delay(3000);
    if (goalPosElbow == goal1) {
      goalPosElbow = goal2;
    }
    else {
      goalPosElbow = goal1;
    }
    goalReached = 0;
    firstMove = 1;
  }
  
}
 
ISR(TIMER1_COMPA_vect)
{
  // Update sensors
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
//  heightUS = ultrasonic.Ranging(CM);
  
  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  
  // Update motors
  if ((currPosElbow > goalPosElbow - BUFFER_ELBOW) && (currPosElbow < goalPosElbow + BUFFER_ELBOW)) { // Final Dest
    motion.stopMotorElbow();
    goalReached = 1;
  }
  else if (currPosElbow < goalPosElbow) { // Going down
    if (firstMove) {
      motion.goDownElbowSpeed(172); // 172
      firstMove = 0;
    }
    else {
//      if (currPosElbow < goalPosElbow + BUFFER_ELBOW_DECEL) { // Bigger buffer
//        motion.goDownElbowSpeed(128); // 128
//      }
//      else
//      {
//        motion.goDownElbowSpeed(128); // 128
//      }
      motion.goDownElbowSpeed(128); // 128
    }
  }
  else if (currPosElbow > goalPosElbow) { // Going up
    if (firstMove) {
      motion.goUpElbow();
      firstMove = 0;
    }
    else {
//      if (currPosElbow > goalPosElbow - BUFFER_ELBOW_DECEL) { // Bigger buffer
//        motion.goUpElbowSpeed(255); // 128
//      }
//      else
//      {
//        motion.goUpElbowSpeed(255); // 128
//      }
      motion.goUpElbowSpeed(255); // 128
    }
  }
}

