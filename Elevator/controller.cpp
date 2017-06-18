#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout;
    this->setLayout(layout);
    for (int i = 0; i < FLOOR_NUMBERS; i++) {
        buttons[i] = new Button;
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
        buttons[i]->setText(QString::number(i));
        buttons[i]->set_floor(i);
        needed_floors[i] = false;
        QObject::connect(buttons[i], SIGNAL(changeFloor(int)), this, SLOT(changeToAddNewFloor(int)));
    }
}

Controller::~CController() {
    for (int i = 0; i < FLOOR_NUMBERS; i++)
        delete buttons[i];

    delete layout;
}

void Controller::changeToCurrentFloor(int floor, motion new_motion) {
    current_floor = floor;
    current_motion = new_motion;
}

void Controller::changeToNeededFloor(int floor, motion new_motion) {
    if (current_state == BUSY) {
        qDebug() << "⏹ Stoped on floor:" << floor << "⏹";
        current_floor = floor;
        current_motion = new_motion;
        needed_floors[floor] = false;
        emit buttons[floor]->resetButton();
        if (getNewNeededFloor(floor))
            emit SendNewNeededFloor(floor);
        else
            current_state = NOTHING;
    }
}

void Controller::changeToAddNewFloor(int floor) {
    current_state = BUSY;
    needed_floors[floor] = true;
    getNewNeededFloor(floor);
    emit SendNewNeededFloor(floor);
}


