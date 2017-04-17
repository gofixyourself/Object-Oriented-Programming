#ifndef SERVICE_STRUCTURES_H
#define SERVICE_STRUCTURES_H

#include "errors.h"
#include "QGraphicsView"
#include "for loading.h"
#include "for drawing.h"
#include "for turning.h"
#include "for scaling.h"

// Status list:
enum events {
    OPENING,
    LOADING,
    QUIT,
    DRAWING,
    SCALING,
    VERTICAL_ROTATION,
    HORIZONTAL_ROTATION,
    TURN_UP,
    TURN_DOWN
};

// Correlation of status and action:
struct action {

    events toDo;

    union
    {
        struct loadingAFile load;
        struct drawingAModel draw;
        struct turningAModel turn;
        struct scalingAModel scale;
    };
};

#endif // SERVICE_STRUCTURES_H
