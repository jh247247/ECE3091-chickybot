#include <avr/io.h>
#include <avr/interrupt.h>
#include "Ultrasonic.h"
#include "LiquidCrystal595.h"
#include "Motion.h"
#include "Sensors.h"

// Arm position values
#define ELBOW_MIN_ANGLE 15
#define ELBOW_MIN 876
#define ELBOW_MAX_ANGLE 90
#define ELBOW_MAX 513

// TODO: Shoulder angles
#define SHOULDER_MIN_ANGLE 0
#define SHOULDER_MIN 800
#define SHOULDER_MAX_ANGLE 90
#define SHOULDER_MAX 910

#define BUFFER_ELBOW 10
#define BUFFER_ELBOW_DECEL 40

#define BUFFER_SHOULDER 10
#define BUFFER_SHOULDER_DECEL 40

// Pins
#define PIN_TRIG 6
#define PIN_ECHO 4
#define PIN_MOTOR_ELBOW_POS 5
#define PIN_MOTOR_ELBOW_NEG 3
#define PIN_MOTOR_SHOULDER_POS 10
#define PIN_MOTOR_SHOULDER_NEG 9
#define PIN_FAN 13
#define PIN_MOTOR_ELBOW_POT A0
#define PIN_MOTOR_SHOULDER_POT A1
#define PIN_HOME_SWITCH 2

// Unused pins
#define PIN_11 11
#define PIN_12 12
#define PIN_A6 A6
#define PIN_A7 A7

//LiquidCrystal lcd(7, 8, A5, A4, A3, A2);
LiquidCrystal595 lcd(A2, A3, A4);
Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long heightUS;
Motion motion(PIN_MOTOR_ELBOW_POS, PIN_MOTOR_ELBOW_NEG, PIN_MOTOR_SHOULDER_POS, PIN_MOTOR_SHOULDER_NEG);

// Positioning vars
int currPosElbow;
int goalPosElbow;
int currPosShoulder;
int goalPosShoulder;

int goalReachedElbow = 0;
int goalElbow1 = ELBOW_MIN;
int goalElbow2 = ELBOW_MAX;

int goalReachedShoulder = 0;
int goalShoulder1 = ELBOW_MIN;
int goalShoulder2 = ELBOW_MAX;

int firstMoveElbow = 1;
int firstMoveShoulder = 1;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Pins
  pinMode(PIN_HOME_SWITCH, INPUT);
  pinMode(PIN_FAN, OUTPUT);
  
  // Start Timer1
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

  // Home Switch Interrupt
  attachInterrupt(0, homeSwitchPressed, CHANGE); // 0 = PIN 2

  // Set initial position
  goalPosElbow = goalElbow1;
  goalPosShoulder = goalShoulder1;
}
 
void loop()
{
  // Update LCD
  lcd.clear();
  
//  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
//  lcd.setCursor(0,0);
//  lcd.print(currPosElbow);
//  
//  int elbowAngle = motion.potElbowToAngle(currPosElbow);
//  lcd.setCursor(0,1);
//  lcd.print(elbowAngle);
//  lcd.print("^");
//  
//  double radius = motion.getRadius(elbowAngle, 90);
//  double height = motion.getHeight(elbowAngle, 90);
//  lcd.setCursor(5,0);
//  lcd.print(radius);
//  lcd.setCursor(5,1);
//  lcd.print(height);
//
//  double calcedElbowAngle = motion.posToElbowAngle(radius, height);
//  double calcedShoulderAngle = motion.posToShoulderAngle(radius, height);
//  lcd.setCursor(11,0);
//  lcd.print(calcedElbowAngle);
//  lcd.setCursor(11,1);
//  lcd.print(calcedShoulderAngle);

  currPosShoulder = analogRead(PIN_MOTOR_SHOULDER_POT);
  lcd.setCursor(0,0);
  lcd.print(currPosShoulder);
  
//  int shoulderAngle = motion.potShoulderToAngle(currPosShoulder);
//  lcd.setCursor(0,1);
//  lcd.print(shoulderAngle);
//  lcd.print("^");
//  
//  double radius = motion.getRadius(elbowAngle, shoulderAngle);
//  double height = motion.getHeight(elbowAngle, shoulderAngle);
//  lcd.setCursor(5,0);
//  lcd.print(radius);
//  lcd.setCursor(5,1);
//  lcd.print(height);
//
//  double calcedElbowAngle = motion.posToElbowAngle(radius, height);
//  double calcedShoulderAngle = motion.posToShoulderAngle(radius, height);
//  lcd.setCursor(11,0);
//  lcd.print(calcedElbowAngle);
//  lcd.setCursor(11,1);
//  lcd.print(calcedShoulderAngle);

  delay(400);

  if (goalReachedShoulder == 1) {
    delay(3000);
    if (goalPosShoulder == goalShoulder1) {
      goalPosShoulder = goalShoulder2;
    }
    else {
      goalPosShoulder = goalShoulder1;
    }
    goalReachedShoulder = 0;
    firstMoveShoulder = 1;
  }
}
 
ISR(TIMER1_COMPA_vect)
{
  // Update sensors
//  heightUS = ultrasonic.Ranging(CM);
  
//  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
//  
//  // Update motors
//  if ((currPosElbow > goalPosElbow - BUFFER_ELBOW) && (currPosElbow < goalPosElbow + BUFFER_ELBOW)) { // Final Dest
//    motion.stopMotorElbow();
//    goalReached = 1;
//  }
//  else if (currPosElbow < goalPosElbow) { // Going down
//    if (firstMove) {
//      motion.goDownElbowSpeed(172); // 172
//      firstMove = 0;
//    }
//    else {
//      motion.goDownElbowSpeed(128); // 128
//    }
//  }
//  else if (currPosElbow > goalPosElbow) { // Going up
//    if (firstMove) {
//      motion.goUpElbow();
//      firstMove = 0;
//    }
//    else {
////      motion.goUpElbowSpeed(255); // 128
//      motion.goUpElbow();
//    }

    currPosShoulder = analogRead(PIN_MOTOR_SHOULDER_POT);
    
    // Update motors
    if ((currPosShoulder > goalPosShoulder - BUFFER_SHOULDER) && (currPosShoulder < goalPosShoulder + BUFFER_SHOULDER)) { // Final Dest
      motion.stopMotorShoulder();
      goalReachedShoulder = 1;
    }
    else if (currPosShoulder < goalPosShoulder) { // Going down
      if (firstMoveShoulder) {
        motion.goDownShoulderSpeed(172); // 172
        firstMoveShoulder = 0;
      }
      else {
        motion.goDownShoulderSpeed(128); // 128
      }
    }
    else if (currPosShoulder > goalPosShoulder) { // Going up
      if (firstMoveShoulder) {
        motion.goUpShoulder();
        firstMoveShoulder = 0;
      }
      else {
  //      motion.goUpShoulderSpeed(255); // 128
        motion.goUpShoulder();
      }

  }

  
}

void homeSwitchPressed() {
  // Debouncing
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    
    // Do stuff
    digitalWrite(PIN_FAN, !digitalRead(PIN_FAN));
    
  }
  last_interrupt_time = interrupt_time;
}

