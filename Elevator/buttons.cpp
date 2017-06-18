#include "buttons.h"

Buttons::Buttons(QWidget *parent) : QPushButton(parent) {
    current_state = NOTPRESSED;
    floor = 0;

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(changeToPressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(changeToNotPressed()));
}

void Buttons::set_floor(int new_floor) {
    floor = new_floor;
}

Buttons::~Buttons() {

}

void Buttons::changeToPressed() {
    if (current_state == NOTPRESSED) {
        current_state = PRESSED;
        this->setEnabled(false);
        emit changeFloor(floor);
    }
}

void Buttons::changeToNotPressed() {
    if (current_state == PRESSED) {
        current_state = NOTPRESSED;
        this->setEnabled(true);
   }
}
