#include "bundle.h"

int bundleDots(arrayOfEdges &ourEdges, arrayOfDots ourDots, FILE* inputFile)
{
    edge buffer;
    int forFirstEnd, forSecondEnd;

    if (fscanf(inputFile, "%d %d", &forFirstEnd, &forSecondEnd) != 2)
       return FILE_ERROR;

    if ((forFirstEnd >= ourDots.index) || (forSecondEnd >= ourDots.index))
        return FILE_ERROR;

    buffer.firstEnd = ourDots.array + forFirstEnd;
    buffer.secondEnd = ourDots.array + forSecondEnd;

    if (insertEdge(ourEdges, buffer))
        return FILE_ERROR;

    return ALL_IS_WELL;
}
