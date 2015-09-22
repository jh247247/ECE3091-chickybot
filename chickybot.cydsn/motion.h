#include <project.h>

int16 getElbowPos();
void displayElbowPos();

int16 getShoulderPos();
void displayShoulderPos();

uint8 elbowGoToPos(int16);
uint8 shoulderGoToPos(int16);

void elbowUpStep();
void elbowDownStep();
void shoulderUpStep();
void shoulderDownStep();

uint16 * getPosCoords();
void goToPosRHT(uint16, uint16, uint16);

void rotateToHome();
void rotateStepCCW(uint16);
void rotateStepCW(uint16);

uint8 fanOn();
uint8 fanOff();