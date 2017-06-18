#ifndef TIMES_H
#define TIMES_H

#include <QTimer>
#include <QDebug>

#define TIME_DOOR         1000
#define TIME_DOOR_WAIT    3000
#define TIME_MOVING_FLOOR 1500
#define FLOOR_NUMBERS     12

enum motion {
    UP = 1,
    DOWN = -1,
    STOPPED = 0
};

#endif // TIMES_H
