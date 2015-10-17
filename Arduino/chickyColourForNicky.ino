//DISCLAIMER: Does not auto-calibrate...

// return int 0 for floor, 1 for R, 2 for G, 3 for B
//getHeadColour

//IF EVERYTHING IS BEING READ AS THE FLOOR, THESE VALUES ARE THE FIRST TO CHANGE
#define THRESHOLDRG 10
#define THRESHOLDRB 10
#define THRESHOLDBG 10

//IF DETECTING INCORRECT COLOUR, CHANGE THESE VALUES
#define RED_FUDGE 1
#define GREEN_FUDGE 1
#define BLUE_FUDGE 1.2

// Define colour sensor LED pins
int ledArray[] = {3, 4, 5};

//floats to hold colour arrays
float colourArray[] = {0, 0, 0}; //no lights on, R, G, B
float ambientLightVal;


void setup() {
  // put your setup code here, to run once:
  //setup the outputs for the colour sensor
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  //begin serial communication
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //MAKE SURE YOU CALL THESE TOGETHER IN THIS ORDER!
  setBalance();
  checkColour();
  getHeadColour();
}

//checks current light setting with no lights on
void setBalance() {
  //digitalWrite(2,HIGH);
  delay(10);
  ambientLightVal = getReading(10);
  Serial.print("ambient light = ");
 //DEBUGGING
 // Serial.println(ambientLightVal);
 // Serial.println();
  delay(100);
}

int getHeadColour() {
  if ((abs(colourArray[0] - colourArray[1]) > THRESHOLDRG) &&
      (abs(colourArray[2] - colourArray[1]) > THRESHOLDBG) &&
      (abs(colourArray[0] - colourArray[2]) > THRESHOLDRB)) {
    //red puck
    if ((colourArray[0] > colourArray[1]) && (colourArray[0] > colourArray[2])) {
      return 1;
    }
    //green puck
    else if ((colourArray[1] > colourArray[0]) && (colourArray[1] > colourArray[2])) {
      return 2;
    }
    //blue puck
    else {
      return 3;
    }
  }
  // the floor
  return 0;
}

void checkColour() {
  // 0 = ambient, 1 = red, 2 = green, 3 = blue
  Serial.print("COLOUR_TESTING ");
  for (int i = 0; i < 3; i++) {
    // turn on led we are looking at
    digitalWrite(ledArray[i], HIGH);
    delay(5);
    // sample, read 5 times
    colourArray[i] = abs(getReading(5));
    digitalWrite(ledArray[i], LOW);
    colourArray[i] = abs(ambientLightVal - colourArray[i]);
    Serial.print(colourArray[i]);
    Serial.print(" ");
  } Serial.println();

  //multiply raw values by fudge factor depending on how sensitive color is to the led light
  colourArray[0] = RED_FUDGE * colourArray[0] * colourArray[0] / 1000;
  colourArray[1] = GREEN_FUDGE * colourArray[1] * colourArray[0] / 1000;
  colourArray[2] = BLUE_FUDGE * colourArray[2] * colourArray[0] / 1000;

  //THIS IS FOR DEBUGGING PURPOSES
  /*Serial.println("COLOUR_TESTING AFTER FUDGE ");
  Serial.print(colourArray[0]);
  Serial.print("  ");
  Serial.print(colourArray[1]);
  Serial.print("  ");
  Serial.print(colourArray[2]);
  Serial.println();*/
}

float getReading(int times) {
  // return analogRead(A4);
  float avgRead;
  int reading;
  float tally = 0;
  //take the reading however many times was requested and add them up
  for (int i = 0; i < times; i++) {
    reading = analogRead(A4);
    tally = reading + tally;
    delay(5);
  }
  //calculate the average and set it
  return avgRead = (tally) / times;
}
