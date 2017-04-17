#ifndef FOR_TURNING_H
#define FOR_TURNING_H

#define PI_CONST 3.141592653589793238462643

#include "math.h"
#include "dot.h"
#include "errors.h"

// Structure of model turning event:
struct turningAModel {
    int coefficient;
};

int forHorizontalRotation(arrayOfDots ourArray, turningAModel angle);
int dotTurnHorizontal(arrayOfDots ourArray, int index, double displacement);
void horizontalRotationDot(dot &ourDot, double angle);

int forVerticalRotation(arrayOfDots ourArray, turningAModel angle);
int dotTurnVertical(arrayOfDots ourArray, int index, double angle);
void verticalRotationDot(dot &ourDot, double angle);

#endif // FOR_TURNING_H
