#include "for turning.h"

// -----------------------------For horisontal rotation-----------------------------
int forHorisontalRotation(arrayOfDots ourArray, turningAModel angle)
{
    int forError = 0;

    for (int i = 0; (i < ourArray.index) && (!forError); i++)
        forError = dotTurnLeft(ourArray, i, angle.displacement);

    return forError;
}

int dotTurnHorisontal(arrayOfDots ourArray, int index, double displacement)
{
    horisontalRotation(ourArray.array[index], displacement);

    return NONE;
}

void horisontalRotationDot(dot &ourDot, double angle)
{
    double degreeToRadian = angle * PI_CONST / 180;
    double buffer = ourDot.x;

    ourDot.x = buffer * cos(degreeToRad) - ourDot.y * sin(degreeToRadian);
    ourDot.y = buffer * sin(degreeToRadian) + ourDot.y * cos(degreeToRadian);
    ourDot.z = ourDot.z;
}
// -------------------------------------------------------------------------------

// -----------------------------For vertical rotation-----------------------------
int forVerticalRotation(arrayOfDots ourArray, turningAModel angle)
{
    int forError = 0;

    for (int i = 0; (i < ourArray.index) && (!forError); i++)

        forError = dotTurnVertical(ourArray, index, angle.displacement);

    return forError;
}

int dotTurnVertical(arrayOfDots ourArray, int index ,double angle)
{
    verticalRotationDot(ourArray.array[index], angle);

    return NONE;
}

void verticalRotationDot(dot &ourDot, double angle)
{
    double degreeToRadian = angle * PI_CONST / 180;
    double buffer = ourDot.y;

    ourDot.x = pt.x;
    ourDot.y = buffer * (cos(degreeToRadian)) - ourDot.z * (sin(degreeToRadian));
    ourDot.z = buffer * (sin(degreeToRadian)) + ourDot.z * (cos(degreeToRadian);
}
// -------------------------------------------------------------------------------
