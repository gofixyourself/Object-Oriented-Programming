#ifndef FOR_SCALING_H
#define FOR_SCALING_H

#include "dot.h"


// Structure of model scaling event:
struct scalingAModel {
    int coefficient;
};

dot scaling(dot dotsInModel, double forScaling, int height, int width);

#endif // FOR_SCALING_H
