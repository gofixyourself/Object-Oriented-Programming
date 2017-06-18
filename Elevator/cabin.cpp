#include "cabin.h"

Cabin::Cabin(QObject *parent) {
    current_state = FREE;
    current_floor = 0;
    needed_floor = 0;

    current_motion = STOPPED;
    QObject::connect(&doors, SIGNAL(doorIsClosed()), this, SLOT(changeToMoving()));
    QObject::connect(&timer_for_motion, SIGNAL(timeout()), this, SLOT(changeToMoving()));
    QObject::connect(this, SIGNAL(changeToArrivedAtFloor()), this, SLOT(changeToFree()));
    QObject::connect(this, SIGNAL(changeToMove()), this, SLOT(changeToMoving()));
}
