#include <avr/io.h>
#include <avr/interrupt.h>
#include "Ultrasonic.h"
#include "LiquidCrystal.h"
#include "Motion.h"
#include "Sensors.h"


#define PIN_LED 13
#define PIN_TRIG 6
#define PIN_ECHO 5
#define PIN_MOTOR_ELBOW_POS 2
#define PIN_MOTOR_ELBOW_NEG 3
#define PIN_FAN 4
#define BUFFER_ELBOW 10

#define PIN_MOTOR_ELBOW_POT A0

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long heightUS;

Motion motion(PIN_MOTOR_ELBOW_POS, PIN_MOTOR_ELBOW_NEG);

int currPosElbow;
int goalPosElbow;


void setup()
{
  Serial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_FAN, OUTPUT);

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

  goalPosElbow = 750;
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

  delay(400);
}
 
ISR(TIMER1_COMPA_vect)
{
  // Update sensors
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
//  heightUS = ultrasonic.Ranging(CM);
  
  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  
  // Update motors
  if ((currPosElbow > goalPosElbow - BUFFER_ELBOW) && (currPosElbow < goalPosElbow + BUFFER_ELBOW)) {
    motion.stopMotorElbow();
  }
  else if (currPosElbow < goalPosElbow) {
    motion.goDownElbow(255);
  }
  else if (currPosElbow > goalPosElbow) {
    motion.goUpElbow(255);
  }
}

