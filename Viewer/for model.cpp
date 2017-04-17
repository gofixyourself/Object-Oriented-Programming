#include "for model.h"

model  &initialiazationModel()
{
    model ourModel;

    ourModel.x = 0;
    ourModel.y = 0;

    initializationEdge(ourModel.edges);
    initializationDot(ourModel.dots);

    return ourModel;
}

model deleteModel(model &ourModel)
{
    ourModel.x = 0;
    ourModel.y = 0;

    clearingArrayDots(ourModel.dots);
    clearingArrayEdges(ourModel.edges);
}
