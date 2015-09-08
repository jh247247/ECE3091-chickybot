#include <project.h>
#include "cv.h"

int * readPlanWithCamera() {
    int * plan = (int *) malloc(sizeof(int) * ROWS);
    
    plan[0] = 1;
    plan[1] = 2;
    plan[2] = 3;
    
    return plan;
}