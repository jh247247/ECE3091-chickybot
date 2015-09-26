#include <LiquidCrystal.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int BUFFER = 5;
const int START_POS = 784;
const int END_POS = 860;

long endTime = 300000;

int PIN_MOTOR_POS = 2;
int PIN_MOTOR_NEG = 3;
int PIN_FAN = 4;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(PIN_MOTOR_POS, OUTPUT);
  pinMode(PIN_MOTOR_NEG, OUTPUT);
  pinMode(PIN_FAN, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Hello world!");
}

void loop() {
  int i;
  for (i = 0; i < 1000; i++) {
    lcd.clear();
    lcd.print("Down");
    goToPos(END_POS);

    digitalWrite(PIN_FAN, HIGH);
   
    delay(1000);
  
    lcd.clear();
    lcd.print("Up");
    goToPos(START_POS);

    digitalWrite(PIN_FAN, LOW);
  
    delay(1000);

//    int currPos = analogRead(A0);
//    lcd.clear();
//    lcd.setCursor(0,1);
//    lcd.print(currPos);
//    delay(500);

    if (millis() > endTime) {
      sleepNow();
    }
  }
//  lcd.clear();
//  lcd.setCursor(0,1);
//  int currPos = analogRead(A0);
//  lcd.print(currPos);
//  delay(500);
}

int goToPos(int goalPos) {
  while (1) {
    int currPos = analogRead(A0);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(currPos);
//    delay(100);
    
    if ((currPos > goalPos - BUFFER) && (currPos < goalPos + BUFFER)) {
      stopMotor();
      return 0;
    }
    else if (currPos < goalPos) {
      goDown();
    }
    else if (currPos > goalPos) {
      goUp();
    }
  }
}

void stopMotor() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void goUp() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

void goDown() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void sleepNow(void)
{
    digitalWrite(13, HIGH);
    // Set pin 2 as interrupt and attach handler:
    attachInterrupt(0, pinInterrupt, LOW);
    delay(100);
    //
    // Choose our preferred sleep mode:
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    //
    // Set sleep enable (SE) bit:
    sleep_enable();
    //
    // Put the device to sleep:
    sleep_mode();
    //
    // Upon waking up, sketch continues from this point.
    sleep_disable();
}
void pinInterrupt(void)
{
    detachInterrupt(0);
}

