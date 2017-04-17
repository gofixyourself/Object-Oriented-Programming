#include "model loader.h"

int forLoadingAModel(model &ourModel, FILE *inputFile)
{
    int checkProcess = forLoadingADot(ourModel.dots, inputFile);

    if (!checkProcess)
        checkProcess = forLoadingAEdge(ourModel.edges, ourModel.dots, inputFile);

    return checkProcess;
}
