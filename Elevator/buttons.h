#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QObject>
#include <QDebug>

class Buttons : public QPushButton  {
    Q_OBJECT
    // Button states:
    enum states {
        NOTPRESSED,
        PRESSED
    };

public:
    explicit Buttons(QWidget *parent = 0);
    virtual ~Buttons();

    void set_floor(int new_floor);
public slots:

signals:

private:
    states current_state;
    int floor;
};

#endif // BUTTONS_H
