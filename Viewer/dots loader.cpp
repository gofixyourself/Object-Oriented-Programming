#include "dots loader.h"

int dotLoader(dot &ourDot, FILE* inputFile)
{
    if (fscanf(inputFile,"%lf %lf %lf",&(ourDot.x), &(ourDot.y), &(ourDot.z)) != 3)
        return FILE_ERROR;

    return ALL_IS_WELL;
}

int forLoadingADot(arrayOfDots &ourDots, FILE* inputFile)
{
    int forCheck;
    dot buffer;

    if (!fscanf(inputFile, "%d", &forCheck))
        return FILE_ERROR;

    if (forCheck <= 0)
        return FILE_ERROR;

    int checkProcess = 0;

    checkProcess = createArrayOfDots(ourDots, forCheck);

    if (checkProcess)
        return checkProcess;

    for (int i = 0; i < forCheck && (!checkProcess); i++) {
       checkProcess = dotLoader(buffer, inputFile);

       if (!checkProcess)
           checkProcess = insertDot(ourDots, buffer);
    }

    return checkProcess;
}
