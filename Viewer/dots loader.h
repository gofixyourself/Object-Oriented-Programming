#ifndef DOTS_LOADER_H
#define DOTS_LOADER_H

#include "strcutures of types.h"
#include "errors.h"
#include "dot.h"

int dotLoader(dot &ourDot, FILE* inputFile);
int forLoadingADot(arrayOfDots &ourDots, FILE* inputFile);

#endif // DOTS_LOADER_H
