#ifndef FOR_MODEL_H
#define FOR_MODEL_H

#include "dot.h"
#include "edge.h"
#include "display.h"

struct model {
     int x;
     int y;

     arrayOfDots dots;
     arrayOfEdges edges;
};

model  &initialiazationModel();
model deleteModel(model &ourModel);

#endif // FOR_MODEL_H
