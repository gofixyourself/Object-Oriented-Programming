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
