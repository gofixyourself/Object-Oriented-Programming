#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QObject>

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
    void changeToPressed();
    void changeToNotPressed();
signals:
    void resetButton();
    void changeFloor(int floor);
private:
    states current_state;
    int floor;
};

#endif // BUTTONS_H
