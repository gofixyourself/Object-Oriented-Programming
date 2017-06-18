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

void Cabin::changeToMoving() {
    if (current_state == MOVING || current_state == BUSY)  {
        current_state = MOVING;
        qDebug() << "⏩ Elevator moves. ⏪ Current floor: " << current_floor;
        if (current_floor == needed_floor) {
            emit changeToArrivedAtFloor();
        } else {
            timer_for_motion.start(TIME_MOVING_FLOOR);
            emit previousFloor(current_floor, current_motion);
            if (current_floor < needed_floor) {
                current_motion = UP;
                current_floor += 1;
            } else {
                current_motion = DOWN;
                currentFloor -= 1;
            }
        }
    }

}
