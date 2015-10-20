#include <avr/io.h>
#include <avr/interrupt.h>
#include "Ultrasonic.h"
#include "Motion.h"
#include "Sensors.h"

#define SEARCH_HEIGHT 4
#define DROP_HEIGHT 14
#define DROP_ELBOW 780
#define DROP_SHOULDER 210
#define SEARCH_START_ELBOW 600
#define SEARCH_START_SHOULDER 300
#define MIN_RADIUS_ELBOW 710
#define MIN_RADIUS_SHOULDER 260
//#define PACK_UP_ELBOW ELBOW_MIN
//#define PACK_UP_SHOULDER SHOULDER_MAX

#define SEARCH_ROTATION_DURATION 300

#define BUFFER_ELBOW 10
#define BUFFER_ELBOW_DECEL 60

#define BUFFER_SHOULDER 5
#define BUFFER_SHOULDER_DECEL 50

// Pins
#define PIN_MOTOR_ELBOW_POS 5
#define PIN_MOTOR_ELBOW_NEG 6
#define PIN_MOTOR_SHOULDER_POS 12
#define PIN_MOTOR_SHOULDER_NEG 4
#define PIN_MOTOR_ELBOW_POT A0
#define PIN_MOTOR_SHOULDER_POT A1
#define PIN_WAIST_CW 9
#define PIN_WAIST_CCW 10
#define PIN_SEARCH_START_SWITCH 2
#define PIN_SEARCH_END_SWITCH 3

#define PIN_FAN 13
#define PIN_HEAD_SERVO 11
#define PIN_TRIG 8
#define PIN_ECHO 7
#define PIN_PHOTO_DIODE A2
#define PIN_B_LED A3
#define PIN_G_LED A4
#define PIN_R_LED A5

// Unused pins
#define PIN_A6 A6
#define PIN_A7 A7

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);
long heightUS;
Motion motion(PIN_MOTOR_ELBOW_POS, PIN_MOTOR_ELBOW_NEG, PIN_MOTOR_SHOULDER_POS, PIN_MOTOR_SHOULDER_NEG, PIN_WAIST_CW, PIN_WAIST_CCW, PIN_HEAD_SERVO);
Sensors sensors(PIN_PHOTO_DIODE, PIN_R_LED, PIN_G_LED, PIN_B_LED);

// Positioning vars
int currPosElbow;
int goalPosElbow;
int currPosShoulder;
int goalPosShoulder;
int desiredGoal;

int goalReachedElbow = 0;
int goalReachedShoulder = 0;
int firstMoveElbow = 1;
int firstMoveShoulder = 1;

int state;
int puck;

void setup()
{
  Serial.begin(9600);

  // Pins
  pinMode(PIN_SEARCH_START_SWITCH, INPUT);
  pinMode(PIN_SEARCH_END_SWITCH, INPUT);
  pinMode(PIN_FAN, OUTPUT);
  
  // Start Timer1
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  /* 0.050 s timer
   * 1 / (16e6/1024) = 6.4e-5
   * (0.05 s / 6.4e-5) - 1 = 780
   */
  OCR1A = 780;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  sei();

  // Home Switch Interrupt
//  attachInterrupt(0, searchStartSwitchPressed, CHANGE); // 0 = PIN 2
//  attachInterrupt(1, searchEndSwitchPressed, CHANGE); // 1 = PIN 3

  // Set initial position
  goalPosElbow = ELBOW_MIN;
  goalPosShoulder = SHOULDER_MAX;

  motion.headServoUp();
  delay(2000);
  motion.headServoOff();
  //motion.goCCW();

  state = 0;
}
 
void loop()
{
  serialPrint();
  Serial.print("# STATE: ");
  Serial.println(state);

  switch (state) {
    case 0: // Once max upright, Go to search rotation
      if (goalReachedElbow == 1) {
        if (goalReachedShoulder == 1) {
          motion.goCW();
          goalReachedElbow = 0;
          goalReachedShoulder = 0;
          if (digitalRead(PIN_SEARCH_START_SWITCH) == 1) {
            motion.stopWaist();
            delay(500);
            state = 1;
          }
        }
      }
      break;
    
    case 1: // Once at correct rotation, Move E to S_S
      goalPosElbow = SEARCH_START_ELBOW;
      goalReachedElbow = 0;
      goalReachedShoulder = 0;
      state = 2;
      delay(1000);
      break;
    
    case 2: // Once E, S to S_S
      if (goalReachedElbow == 1) {
        goalPosShoulder = SEARCH_START_SHOULDER;
        goalReachedElbow = 0;
        goalReachedShoulder = 0;
        state = 3;
        delay(1000);
      }
      break;

    case 3: // Once S, Next
      if (goalReachedShoulder == 1) {
        sensors.turnAllLightsOn();
        digitalWrite(PIN_FAN, HIGH);
        delay(100);
        state = 5;
      }
      break;
      
    case 4: // Once S, Check puck
      delay(100);
      puck = sensors.checkForPuck();
      if (puck == 0) {
        state = 5;
      }
      else {
        Serial.print("Found puck: ");
        state = 11;
      }
      delay(1000);
      break;

    case 5: // No puck, Move in if possible
      if ((currPosElbow < MIN_RADIUS_ELBOW) || (currPosShoulder > MIN_RADIUS_SHOULDER)) {
        state = 6;
      }
      else {
        state = 9;
      }
      break;

    case 6: // Move in
        desiredGoal = currPosShoulder - BUFFER_SHOULDER - 2;
        if (desiredGoal > MIN_RADIUS_SHOULDER) {
          goalPosShoulder = desiredGoal;
          goalReachedShoulder = 0;
          state = 7;
          delay(1000);
        }
        else {
          state = 9;
        }
      break;

    case 7: // Move E to correct height
        if (goalReachedShoulder == 1) {
          desiredGoal = currPosElbow + BUFFER_ELBOW + 2;
          if (desiredGoal < MIN_RADIUS_ELBOW) {
            goalPosElbow = desiredGoal;
            goalReachedElbow = 0;
            state = 8;
            delay(2000);
          }
          else {
            state = 9;
          }
        }
      break;

    case 8: // Once S, Next
      if (goalReachedElbow == 1) {
        delay(300);
        heightUS = readUltraSonicSensor();
        if (heightUS <= SEARCH_HEIGHT) {
          state = 4;
        }
        else {
          state = 7;
        }
      }
      break;

    case 9: // Rotate
      motion.goCCW();
      delay(SEARCH_ROTATION_DURATION);
      motion.stopWaist();
      delay(2000);
      state = 10;
      break;

    case 10: // Finished rotate
      if (digitalRead(PIN_SEARCH_END_SWITCH) == 1) {
        Serial.println("!!! Reached end of search");
      }
      else {
        state = 1;
      }
      break;

    case 11: // Pick up puck, Move to drop zone
      pickUpPuck();

      goalPosShoulder = DROP_SHOULDER;
      goalReachedElbow = 0;
      goalReachedShoulder = 0;
      state = 12;
      delay(1000);
      break;

    case 12: // Move to drop zone
      if (goalReachedShoulder == 1) {
        goalPosElbow = DROP_ELBOW;
        goalReachedElbow = 0;
        goalReachedShoulder = 0;
        state = 13;
        delay(1000);
      }
      break;

    case 13: // Drop
      if (goalReachedElbow == 1) {
        delay(1000);
        motion.goCW();

        state = 14;
      }
      break;

    case 14: // Drop
      if (digitalRead(PIN_SEARCH_START_SWITCH) == 1) {
        motion.stopWaist();
        delay(1000);

        dropPuck();

        state = 1;
      }
      break;
      
    default:
      Serial.println("Error: Unknown State!");
  }

  //delay(100);
}
 
#define ABS(x) ((x)>0) ? x : -x
ISR(TIMER1_COMPA_vect)
{
  // Update sensors
  //heightUS = ultrasonic.Ranging(CM);

  // Elbow control
  static int prevPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  
  if ((currPosElbow > goalPosElbow - BUFFER_ELBOW) && (currPosElbow < goalPosElbow + BUFFER_ELBOW)) { // Final Dest
    motion.stopMotorElbow();
    goalReachedElbow = 1;
  }
  else if (currPosElbow < goalPosElbow && currPosElbow > prevPosElbow ) { // Going DOWN, previous position was stationary or moving down
    if (firstMoveElbow) {
      motion.goDownElbowSpeed(200);
      firstMoveElbow = 0;
    }
    else {
      if (currPosElbow > goalPosElbow - BUFFER_ELBOW_DECEL) // Decel Zone
        motion.goDownElbowSpeed(140);
      else // Normal Zone
        motion.goDownElbowSpeed(180);
    }
  }
  else if (currPosElbow > goalPosElbow && currPosElbow < prevPosElbow) { // Going UP
    if (firstMoveElbow) {
      motion.goUpElbow();
      firstMoveElbow = 0;
    }
    else {
      if (currPosElbow < goalPosElbow + BUFFER_ELBOW_DECEL) // Decel Zone
        motion.goUpElbowSpeed(255);
      else // Normal Zone
        motion.goUpElbowSpeed(255);
    }
  }
  // just with this, 
  // save previous position of the elbow
  prevPosElbow = currPosElbow;

  // Shoulder control
  currPosShoulder = analogRead(PIN_MOTOR_SHOULDER_POT);
  
  if ((currPosShoulder > goalPosShoulder - BUFFER_SHOULDER) && (currPosShoulder < goalPosShoulder + BUFFER_SHOULDER)) { // Final Dest
    motion.stopMotorShoulder();
    goalReachedShoulder = 1;
  }
  else if (currPosShoulder < goalPosShoulder) { // Going DOWN
    if (firstMoveShoulder) {
      motion.goDownShoulder();
      firstMoveShoulder = 0;
    }
    else {
      if (currPosShoulder > goalPosShoulder - BUFFER_SHOULDER_DECEL) // Decel Zone
        motion.goDownShoulder();
      else // Normal Zone
        motion.goDownShoulder();
    }
  }
  else if (currPosShoulder > goalPosShoulder) { // Going UP
    if (firstMoveShoulder) {
      motion.goUpShoulder();
      firstMoveShoulder = 0;
    }
    else {
      if (currPosShoulder < goalPosShoulder + BUFFER_SHOULDER_DECEL) // Decel Zone
        motion.goUpShoulder();
      else // Normal Zone
        motion.goUpShoulder();
    }
  }
  
}

void searchStartSwitchPressed() {
  // Debouncing
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    
    if (digitalRead(PIN_SEARCH_START_SWITCH) == 1) {
      Serial.println("Search Start reached!");
    }
    
  }
  last_interrupt_time = interrupt_time;
}

void searchEndSwitchPressed() {
  // Debouncing
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    
    if (digitalRead(PIN_SEARCH_END_SWITCH) == 1) {
      Serial.println("Search End reached!");
    }
    
  }
  last_interrupt_time = interrupt_time;
}

void serialPrint() {
  currPosElbow = analogRead(PIN_MOTOR_ELBOW_POT);
  currPosShoulder = analogRead(PIN_MOTOR_SHOULDER_POT);
  int elbowAngle = motion.potElbowToAngle(currPosElbow);
  int shoulderAngle = motion.potShoulderToAngle(currPosShoulder);
  double radius = motion.getRadius(elbowAngle, shoulderAngle);
  double height = motion.getHeight(elbowAngle, shoulderAngle);

  double calcedElbowAngle = motion.posToElbowAngle(radius, height);
  double calcedShoulderAngle = motion.posToShoulderAngle(radius, height);

  Serial.print("E:  ");
  Serial.print(currPosElbow);
  Serial.print(" -> ");
  Serial.print(goalPosElbow);
  Serial.print("\t\t");
  Serial.print(elbowAngle);
  Serial.print("^\t");
  Serial.print(calcedElbowAngle);
  Serial.print("^");
  Serial.println();
  
  Serial.print("S:  ");
  Serial.print(currPosShoulder);
  Serial.print(" -> ");
  Serial.print(goalPosShoulder);
  Serial.print("\t\t");
  Serial.print(shoulderAngle);
  Serial.print("^\t");
  Serial.print(calcedShoulderAngle);
  Serial.print("^");
  Serial.println();

  Serial.print("(");
  Serial.print(radius);
  Serial.print(", ");
  Serial.print(height);
  Serial.print(")\tUS: ");
  Serial.print(heightUS);
  Serial.print(" cm");
  Serial.println();

  Serial.println();
}

void pickUpPuck() {
  Serial.println("----- Pick up");
  motion.headServoDown();
  delay(2000);
}

void dropPuck() {
  Serial.println("----- Drop");
  motion.headServoUp();
  delay(2000);
  digitalWrite(PIN_FAN, LOW);
  delay(4000);
  motion.headServoOff();
  delay(2000);
}

// Stops not possible readings, Returns 100 if no decent reading
long readUltraSonicSensor() {
  int tries;
  long result;
  
  for (tries = 0; tries < 5; tries++) {
    result = ultrasonic.Ranging(CM);
    if (result < 100)
      return result;

    delay(50);
  }

  return 100;
}

