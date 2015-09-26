#include <avr/io.h>
#include <avr/interrupt.h>
#include "Ultrasonic.h"
#include <LiquidCrystal.h>

#define PIN_LED 13
#define PIN_TRIG 6
#define PIN_ECHO 5
#define PIN_MOTOR_ELBOW_POS 2
#define PIN_MOTOR_ELBOW_NEG 3
#define PIN_FAN 4
#define BUFFER_ELBOW 5

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long heightUS;

int currPosElbow;
int goalPosElbow;


void setup()
{
  Serial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_MOTOR_ELBOW_POS, OUTPUT);
  pinMode(PIN_MOTOR_ELBOW_NEG, OUTPUT);
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

  goalPosElbow = 512;
}
 
void loop()
{
  // Update LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("US: ");
  lcd.print(heightUS);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("E: ");
  lcd.print(currPosElbow);

  delay(400);
}
 
ISR(TIMER1_COMPA_vect)
{
  // Update sensors
  digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  heightUS = ultrasonic.Ranging(CM);
  
  currPosElbow = analogRead(A0);
  
  // Update motors
  if ((currPosElbow > goalPosElbow - BUFFER_ELBOW) && (currPosElbow < goalPosElbow + BUFFER_ELBOW)) {
    stopMotorElbow();
  }
  else if (currPosElbow < goalPosElbow) {
    goDownElbow();
  }
  else if (currPosElbow > goalPosElbow) {
    goUpElbow();
  }
}

void stopMotorElbow() {
  digitalWrite(PIN_MOTOR_ELBOW_POS, LOW);
  digitalWrite(PIN_MOTOR_ELBOW_NEG, LOW);
}

void goUpElbow() {
  digitalWrite(PIN_MOTOR_ELBOW_POS, LOW);
  digitalWrite(PIN_MOTOR_ELBOW_NEG, HIGH);
}

void goDownElbow() {
  digitalWrite(PIN_MOTOR_ELBOW_POS, HIGH);
  digitalWrite(PIN_MOTOR_ELBOW_NEG, LOW);
}
