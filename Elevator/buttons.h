#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QObject>
#include <QDebug>

class Buttons : public QPushButton  {
    Q_OBJECT
    enum ButtonStates {
        NOTPRESSED,
        PRESSED
    };

public:
    Buttons();
};

#endif // BUTTONS_H
