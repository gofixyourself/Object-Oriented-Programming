#include "service structures.h"
#include "strcutures of types.h"
#include "for model.h"
#include "for loading.h"
#include "for drawing.h"
#include "for turning.h"

// Entry point:
int process(action ourAction)
{
    static model ourObject = initialiazationModel();

    int error = 0;

    switch (ourAction.toDo)
    {
        case LOADING:
            error = loading(ourObject, ourAction.load);
            break;

        case DRAWING:
            error = drawing(ourObject, ourAction.draw);
            break;

        case QUIT:
            deleteModel(ourObject);
            break;

        case VERTICAL_ROTATION:
            error = forVerticalRotation(ourObject.dots, ourAction.turn);
            break;

        case HORIZONTAL_ROTATION:
            error = forHorizontalRotation(ourObject.dots, ourAction.turn);
            break;

        default:
            error = INCORRECT_COMMAND;
            break;
    }

    return error;
}



