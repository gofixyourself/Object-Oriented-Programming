#include "doors.h"

Doors::Doors() {
    current_state = CLOSE;

    QObject::connect(this, SIGNAL(doorIsOpening()), this, SLOT(changeToOpening()));
    QObject::connect(&timer_for_open, SIGNAL(timeout()), this, SLOT(changeToOpen()));
    QObject::connect(&timer_for_close, SIGNAL(timeout()), this, SLOT(changeToClose()));
    QObject::connect(&timer_for_wait, SIGNAL(timeout()), this, SLOT(changeToClosing()));
}

void Doors::changeToOpen() {
    if (current_state == OPENING) {
        current_state = OPEN;
        qDebug() << "✨ Doors opened! I ask to go inside the elevator! ✨";
        timer_for_wait.start(TIME_DOOR_WAIT);
    }
}

void Doors::changeToOpening() {
    if (current_state == CLOSE) {
        state = OPENING;
        qDebug() << "✨ Doors is opening! Wait a bit! ✨";
        timer_for_open.start(TIME_DOOR);
    }

    if (current_state == CLOSING) {
        current_state = OPENING;
        qDebug() << "✨ Doors is opening! Wait a bit! ✨";
        int time = timer_for_close.remainingTime();
        timer_for_close.stop();
        timer_for_open.start(TIME_DOOR - time);
    }
}

void Doors::changeToClose() {
    if(state == CLOSING) {
        state = CLOSE;
        qDebug() << "doors closed";
        emit DoorIsClosed();
    }
}

