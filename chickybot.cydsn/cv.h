#include <project.h>

#define ROWS 3
#define COLS 1
#define IMG_H 144
#define IMG_W 88

// 133, 204, 135
#define THRESHOLD_R 130
#define THRESHOLD_G 150
#define THRESHOLD_B 130

#define MIN_BOX_HEIGHT 5

// TODO: Necessary?
#define MIN_BOX_WIDTH 30
#define MIN_TOTAL_HEIGHT 100

enum Colour {
    NONE=0,
    RED=1,
    GREEN=2,
    BLUE=3
};

uint16 * readPlanWithCamera();

uint16 takePhoto();
uint16 * parsePhoto();