#include "Ultrasonic.h"
#include <LiquidCrystal.h>

const int PIN_TRIG = 6;
const int PIN_ECHO = 5;

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long dist;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  
  lcd.begin(16, 2);
}

void loop() {
  dist = ultrasonic.Ranging(CM);
  
  Serial.print(dist);
  Serial.println(" cm");

  delay(500);
}

