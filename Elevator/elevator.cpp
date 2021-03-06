#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent) {
    QObject::connect(&elevator_cabin, SIGNAL(previousFloor(int, motion)),
                     &control, SLOT(changeToCurrentFloor(int, motion)));
    QObject::connect(&elevator_cabin, SIGNAL(selectedFloor(int, motion)),
                     &control, SLOT(changeToNeededFloor(int,motion)));
    QObject::connect(&control, SIGNAL(SendNewNeededFloor(int)),
                     &elevator_cabin, SLOT(changeToBusy(int)));
}

QWidget *Elevator::GetWidget() {
    return &control;
}
