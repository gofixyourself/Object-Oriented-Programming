#include "for turning.h"

// -----------------------------For horizontal rotation-----------------------------
int forHorizontalRotation(arrayOfDots ourArray, turningAModel angle)
{
    int forError = 0;

    for (int i = 0; (i < ourArray.index) && (!forError); i++)
        forError = dotTurnHorizontal(ourArray, i, angle.coefficient);

    return forError;
}

int dotTurnHorizontal(arrayOfDots ourArray, int index, double displacement)
{
    horizontalRotationDot(ourArray.array[index], displacement);

    return ALL_IS_WELL;
}

void horizontalRotationDot(dot &ourDot, double angle)
{
    double degreeToRadian = angle * PI_CONST / 180;
    double buffer = ourDot.x;

    ourDot.x = buffer * cos(degreeToRadian) - ourDot.y * sin(degreeToRadian);
    ourDot.y = buffer * sin(degreeToRadian) + ourDot.y * cos(degreeToRadian);
    ourDot.z = ourDot.z;
}
// -------------------------------------------------------------------------------

// -----------------------------For vertical rotation-----------------------------
int forVerticalRotation(arrayOfDots ourArray, turningAModel angle)
{
    int forError = 0;

    for (int i = 0; (i < ourArray.index) && (!forError); i++)
        forError = dotTurnVertical(ourArray, i, angle.coefficient);

    return forError;
}

int dotTurnVertical(arrayOfDots ourArray, int index, double angle)
{
    verticalRotationDot(ourArray.array[index], angle);

    return ALL_IS_WELL;
}

void verticalRotationDot(dot &ourDot, double angle)
{
    double degreeToRadian = angle * PI_CONST / 180;
    double buffer = ourDot.y;

    ourDot.x = ourDot.x;
    ourDot.y = buffer * (cos(degreeToRadian)) - ourDot.z * (sin(degreeToRadian));
    ourDot.z = buffer * (sin(degreeToRadian)) + ourDot.z * (cos(degreeToRadian));
}
// -------------------------------------------------------------------------------
