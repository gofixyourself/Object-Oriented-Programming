#include <cstdlib>
#include "types.h"
#include "errors.h"

// Initializing a point:
void initialization(struct arrayOfDots &ourArray)
{
    ourArray.array = 0;
    ourArray.amount = 0;
    ourArray.index = 0;
}

// Comment
int createArrayOfDots(struct arrayOfDots &ourArray, int size)
{
    ourArray.array = (struct dot*)malloc(size * sizeof(struct dot));

    if(!ourArray.array)
        return MEMORY_ALLOCATION_ERROR;

    ourArray.amount = size;
    ourArray.index = 0;

    return ALL_IS_WELL;
}

// Comment
int insertDot(struct arrayOfDots&ourArray, struct dot ourDot)
{
    ourArray.array[ourArray.index++] = ourDot;

    return ALL_IS_WELL;
}


