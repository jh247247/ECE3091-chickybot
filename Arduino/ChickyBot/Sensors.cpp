#include "Arduino.h"
#include "Sensors.h"

// Define colour sensor LED pins
int ledArray[3];

Sensors::Sensors(int pinPhotoDiode, int pinLedRed, int pinLedGreen, int pinLedBlue)
{
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedBlue, OUTPUT);
  
  _pinPhotoDiode = pinPhotoDiode;
  _pinLedRed = pinLedRed;
  _pinLedGreen = pinLedGreen;
  _pinLedBlue = pinLedBlue;
  
  ledArray[0] = _pinLedRed;
  ledArray[1] = _pinLedGreen;
  ledArray[2] = _pinLedBlue;
}

int bufferRed[3] = {10, 10, 10};
int bufferGreen[3] = {5, 5, 5};
int bufferBlue[3] = {5, 5, 5};
int expectedRed[3] = {74, 38, 60};
int expectedGreen[3] = {16, 18, 17};
int expectedBlue[3] = {8, 6, 14};

//IF EVERYTHING IS BEING READ AS THE FLOOR, THESE VALUES ARE THE FIRST TO CHANGE
//#define THRESHOLDRG 15
//#define THRESHOLDRB 15
//#define THRESHOLDBG 15

//IF DETECTING INCORRECT COLOUR, CHANGE THESE VALUES
#define RED_FUDGE 1
#define GREEN_FUDGE 4
#define BLUE_FUDGE 10

//floats to hold colour arrays
float colourArray[] = {0, 0, 0}; //no lights on, R, G, B
float ambientLightVal;

// Returns int 0 for floor, 1 for R, 2 for G, 3 for B
int Sensors::getHeadColour() {
  setBalance();
  checkColour();
  return getHeadColourAux();
}

//checks current light setting with no lights on
void Sensors::setBalance() {
  //digitalWrite(2,HIGH);
  delay(10);
  ambientLightVal = getReading(10);
//  Serial.print("ambient light = ");
//DEBUGGING
// Serial.println(ambientLightVal);
// Serial.println();
  delay(100);
}

int Sensors::getHeadColourAux() {
//  if ((abs(colourArray[0] - colourArray[1]) > THRESHOLDRG) &&
//      (abs(colourArray[2] - colourArray[1]) > THRESHOLDBG) &&
//      (abs(colourArray[0] - colourArray[2]) > THRESHOLDRB)) {
//    //red puck
//    if ((colourArray[0] > colourArray[1]) && (colourArray[0] > colourArray[2])) {
//      return 1;
//    }
//    //green puck
//    else if ((colourArray[1] > colourArray[0]) && (colourArray[1] > colourArray[2])) {
//      return 2;
//    }
//    //blue puck
//    else {
//      return 3;
//    }
//  }
//  // the floor
//  return 0;
  // Red
  if ((colourArray[0] > expectedRed[0] - bufferRed[0]) && (colourArray[0] < expectedRed[0] + bufferRed[0])) {
    if ((colourArray[1] > expectedRed[1] - bufferRed[1]) && (colourArray[1] < expectedRed[1] + bufferRed[1])) {
      if ((colourArray[2] > expectedRed[2] - bufferRed[2]) && (colourArray[2] < expectedRed[2] + bufferRed[2])) {
        return 1;
      }
    }
  }

  // Green
  if ((colourArray[0] > expectedGreen[0] - bufferGreen[0]) && (colourArray[0] < expectedGreen[0] + bufferGreen[0])) {
    if ((colourArray[1] > expectedGreen[1] - bufferGreen[1]) && (colourArray[1] < expectedGreen[1] + bufferGreen[1])) {
      if ((colourArray[2] > expectedGreen[2] - bufferGreen[2]) && (colourArray[2] < expectedGreen[2] + bufferGreen[2])) {
        return 2;
      }
    }
  }

  // Blue
  if ((colourArray[0] > expectedBlue[0] - bufferBlue[0]) && (colourArray[0] < expectedBlue[0] + bufferBlue[0])) {
    if ((colourArray[1] > expectedBlue[1] - bufferBlue[1]) && (colourArray[1] < expectedBlue[1] + bufferBlue[1])) {
      if ((colourArray[2] > expectedBlue[2] - bufferBlue[2]) && (colourArray[2] < expectedBlue[2] + bufferBlue[2])) {
        return 3;
      }
    }
  }

  return 0;
}

void Sensors::checkColour() {
  // 0 = ambient, 1 = red, 2 = green, 3 = blue
//  Serial.print("COLOUR_TESTING ");
  for (int i = 0; i < 3; i++) {
    // turn on led we are looking at
    digitalWrite(ledArray[i], HIGH);
    delay(5);
    // sample, read 5 times
    colourArray[i] = abs(getReading(5));
    digitalWrite(ledArray[i], LOW);
    colourArray[i] = abs(ambientLightVal - colourArray[i]);
//    Serial.print(colourArray[i]);
//    Serial.print(" ");
  }
//  Serial.println();

  //multiply raw values by fudge factor depending on how sensitive color is to the led light
  colourArray[0] = RED_FUDGE * colourArray[0] * colourArray[0] / 1000;
  colourArray[1] = GREEN_FUDGE * colourArray[1] * colourArray[0] / 1000;
  colourArray[2] = BLUE_FUDGE * colourArray[2] * colourArray[0] / 1000;

  //THIS IS FOR DEBUGGING PURPOSES
//  Serial.println("COLOUR_TESTING AFTER FUDGE ");
//  Serial.print(colourArray[0]);
//  Serial.print("  ");
//  Serial.print(colourArray[1]);
//  Serial.print("  ");
//  Serial.print(colourArray[2]);
//  Serial.println();

  // difference
//  Serial.println("differencve between colours");
//  Serial.print("RG: ");
//  Serial.print(abs(colourArray[0] - colourArray[1]));
//  Serial.print(" RB: ");
//  Serial.print(abs(colourArray[0] - colourArray[2]));
//  Serial.print(" GB: ");
//  Serial.print(abs(colourArray[1] - colourArray[2]));
}

float Sensors::getReading(int times) {
  // return analogRead(_pinPhotoDiode);
  float avgRead;
  int reading;
  float tally = 0;
  //take the reading however many times was requested and add them up
  for (int i = 0; i < times; i++) {
    reading = analogRead(_pinPhotoDiode);
    tally = reading + tally;
    delay(5);
  }
  //calculate the average and set it
  return avgRead = (tally) / times;
}

