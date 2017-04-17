#ifndef DOT_H
#define DOT_H

#include "strcutures of types.h"

// Dot structure:
struct dot {
    double x;
    double y;
    double z;

};

// Structure of dots array:
struct arrayOfDots {
    dot *array;

    int amount;
    int index;
};

void initializationDot(arrayOfDots &ourArray);
int createArrayOfDots(arrayOfDots &ourArray, int size);
int insertDot(arrayOfDots&ourArray, dot ourDot);
int popDot(dot &needfulDot, arrayOfDots &ourArray, int index);
int settingDot(arrayOfDots &ourArray, dot &ourDot, int index);
int isEmpty(arrayOfDots &ourArray);
int clearingArrayDots(arrayOfDots &ourArray);

#endif // DOT_H
