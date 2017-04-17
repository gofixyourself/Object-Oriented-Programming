#include <cstdlib>

#include "dot.h"
#include "errors.h"

// Initializing a dot:
void initializationDot(arrayOfDots &ourArray)
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

// Take the needful dot:
int popDot(dot &needfulDot, arrayOfDots &ourArray, int index)
{
    needfulDot = ourArray.array[index];

    return ALL_IS_WELL;
}

// Setting dot to the desired location in array:
int settingDot(arrayOfDots &ourArray, dot &ourDot, int index)
{
    ourArray.array[index]= ourDot;

    return ALL_IS_WELL;
}

// Check for emptiness:
int isEmpty(arrayOfDots &ourArray)
{
    return (ourArray.index == 0);
}

// For clearing array of dots:
int clearingArrayDots(arrayOfDots &ourArray)
{
    if (ourArray.array)
        free(ourArray.array);

    ourArray.array = 0;
    ourArray.amount = 0;
    ourArray.index = 0;

    return ALL_IS_WELL;
}
