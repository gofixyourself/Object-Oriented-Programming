#ifndef TIMES_H
#define TIMES_H

#include <QTimer>
#include <QDebug>

#define TIME_DOOR         500
#define TIME_DOOR_WAIT    500
#define TIME_MOVING_FLOOR 3000
#define FLOOR_NUMBERS     11

enum motion {
    UP = 1,
    DOWN = -1,
    STOPPED = 0
};

#endif // TIMES_H
