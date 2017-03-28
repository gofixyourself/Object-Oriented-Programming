#ifndef VIEWER_STRUCTURES_FOR_DISPLAY_STATUS_H
#define VIEWER_STRUCTURES_FOR_DISPLAY_STATUS_H

// Status list:
enum events {
    LOADING,
    L_TURN,
    V_TURN,
    DRAW,
    INIT,
    SET_SCALE,
    L_SHIFT,
    V_SHIFT,
    QUIT
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

// Function for checking actions:
int checkProcess(struct action ourAction);

#endif //VIEWER_STRUCTURES_FOR_DISPLAY_STATUS_H
