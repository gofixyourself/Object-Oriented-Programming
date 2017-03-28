#ifndef STRUCTURES_FOR_DISPLAY_STATUS_H
#define STRUCTURES_FOR_DISPLAY_STATUS_H

// Function for checking actions:
int checkProcess(struct action ourAction);


// Status list:
enum events {
    OPENING,
    LOADING,
    QUIT,
    DRAWING,
    SCALING,
    TURN_LEFT,
    TURN_RIGHT,
    TURN_UP,
    TURN_DOWN
};

// Structure of file loading event:
struct loadingAFile {
    const char *name;
};

// Structure of model drawing event:
struct drawingAModel {
    QGraphicsView *pen;

    int height;
    int width;
    int scale;
};

// Structure of model move event:
struct moveAModel {
    int coefficient;
};

// Structure of model turning event:
struct turningAModel {
    int coefficient;
};

// Structure of model scaling event:
struct scalingAModel {
    int coefficient;
};

struct drawingOnDisplay {
    QGraphicsScene* newPicture;
    QPen pen;
};

// Correlation of status and action:
struct action {

    events toDo;

    union
    {
        struct loadingAFile load;
        struct drawingAModel draw;
        struct moveAModel move;
        struct turningAModel turn;
        struct scalingAModel scale;
    };
};

#endif // STRUCTURES_FOR_DISPLAY_STATUS_H
