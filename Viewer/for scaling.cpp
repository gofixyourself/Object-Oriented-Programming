#include "for scaling.h"

dot scaling(dot dotsInModel, double forScaling, int height, int width)
{
    dot model;

    model.x = dotsInModel.x * forScaling + width / 2;
    model.z = dotsInModel.z * forScaling + height / 2;

    return model;
}
