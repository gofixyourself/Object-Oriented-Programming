#include "edges loader.h"

int forLoadingAEdge(arrayOfEdges &ourEdges, arrayOfDots &ourDots, FILE* inputFile)
{
    int forCheck;

    if (!fscanf(inputFile, "%d", &forCheck))
        return FILE_ERROR;

    if (forCheck == 0)
        return FILE_ERROR;

    int checkProcess = 0;

    checkProcess = createArrayOfEdges(ourEdges, forCheck);

    if (checkProcess)
        return checkProcess;

    for (int i = 0; (i < forCheck) && (!checkProcess); i++)
       checkProcess = bundleDots(ourEdges, ourDots, inputFile);

    return checkProcess;
}
