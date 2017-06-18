#include "buttons.h"

Buttons::Buttons(QWidget *parent) : QPushButton(parent) {
    current_state = NOTPRESSED;
    floor = 0;

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(slotPressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(slotReleased()));
}

void Buttons::set_floor(int new_floor) {
    floor = new_floor;
}

Buttons::~Buttons() {

}

