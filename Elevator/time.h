#ifndef TIME_H
#define TIME_H

#include <QTimer>
#include <QDebug>

#define TIME_DOOR         500
#define TIME_DOOR_WAIT    500
#define TIME_MOVING_FLOOR 1500
#define FLOOR_NUMBERS     12

enum motion {
    UP = 1,
    DOWN = -1,
    STOPPED = 0
};

#endif // TIME_H
