#include "for model.h"

model  &initialiazationModel()
{
    model ourModel;

    ourModel.x = 0;
    ourModel.y = 0;

    initialiazation(ourModel.edges);
    initialiazation(ob.dots);

    return ourModel;
}

model deleteModel(model &ourModel)
{
    ourModel.x = 0;
    ourModel.y = 0;

    clear(ourModel.dots);
    clear(ourModel.edges);
}
