#include <cstdlib>

#include "edge.h"
#include "errors.h"
#include "strcutures of types.h"

// Initializing a edge:
void initializationEdge(arrayOfEdges &ourArray)
{
    ourArray.array = 0;
    ourArray.amount= 0;
    ourArray.index = 0;
}

// Creating an array of edges joints (allocating memory for it,
// initializing the index and the number of elements in it):
int createArrayOfEdges(arrayOfEdges &ourArray, int size)
{
    ourArray.array = (edge*)malloc(size * sizeof(edge));

    if (!ourArray.array)
        return MEMORY_ALLOCATION_ERROR;

    ourArray.index = 0;
    ourArray.amount = size;

    return ALL_IS_WELL;
}

// Writing to an array of edges joints:
int insertEdge(arrayOfEdges &ourArray, edge ourEdge)
{
    ourArray.array[ourArray.index++] = ourEdge;

    return ALL_IS_WELL;
}

// Take the needful edge:
int popEdge(edge &needfulEdge, arrayOfEdges &ourArray, int index)
{
    needfulEdge = ourArray.array[index];

    return ALL_IS_WELL;
}

// Setting edge to the desired location in array:
int settingEdge(arrayOfEdges &ourArray, int index, edge &ourEdge)
{
    ourArray.array[index] = ourEdge;

    return ALL_IS_WELL;
}

// Check for emptiness:
int isEmpty(arrayOfEdges &ourArray)
{
    return (ourArray.index == 0);
}

// For clearing array of edges:
int clearingArrayEdges(arrayOfEdges &ourArray)
{
    if (ourArray.array)
        free(ourArray.array);

    ourArray.array = 0;
    ourArray.amount = 0;
    ourArray.index = 0;

    return ALL_IS_WELL;
}
