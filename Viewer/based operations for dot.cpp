#include <cstdlib>
#include "strcutures of types.h"
#include "errors.h"

// Initializing a point:
void initialization(arrayOfDots &ourArray)
{
    ourArray.array = 0;
    ourArray.amount = 0;
    ourArray.index = 0;
}

// Creating an array (allocating memory for it,
// initializing the index and the number of elements in it):
int createArrayOfDots(arrayOfDots &ourArray, int size)
{
    ourArray.array = (dot*)malloc(size * sizeof(dot));

    if(!ourArray.array)
        return MEMORY_ALLOCATION_ERROR;

    ourArray.amount = size;
    ourArray.index = 0;

    return ALL_IS_WELL;
}

// For adding a point to an array:
int insertDot(arrayOfDots&ourArray, dot ourDot)
{
    ourArray.array[ourArray.index++] = ourDot;

    return ALL_IS_WELL;
}




