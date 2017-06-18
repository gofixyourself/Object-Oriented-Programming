#include "doors.h"

Doors::Doors() {
    current_state = CLOSE;

    QObject::connect(this, SIGNAL(doorIsOpening()), this, SLOT(changeToOpening()));
    QObject::connect(&timer_for_open, SIGNAL(timeout()), this, SLOT(changeToOpen()));
    QObject::connect(&timer_for_close, SIGNAL(timeout()), this, SLOT(changeToClose()));
    QObject::connect(&timer_for_wait, SIGNAL(timeout()), this, SLOT(changeToClosing()));
}
