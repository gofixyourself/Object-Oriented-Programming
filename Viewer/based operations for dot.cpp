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

int createArrayOfDots(struct arrayOfDots &ourArray, struct dot, int size)
{
    ourArray.array = (struct dot*)malloc(size * sizeof(struct dot));

    if(!ourArray.array) {
        return MEMORY_ALLOCATION_ERROR;
    }

    ourArray.amount = size;
    ourArray.index = 0;

    return ALL_IS_WELL;
}


