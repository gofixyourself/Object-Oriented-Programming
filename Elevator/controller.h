#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include "buttons.h"
#include "times.h"

class Controller : public QWidget {
    Q_OBJECT
    enum controller_state {
        NOTHING,
        BUSY
    };
public:
    explicit Controller(QWidget *parent = 0);
    ~Controller();
signals:
    void SendNewNeededFloor(int new_floor);
public slots:
    void changeToCurrentFloor(int floor, motion motion);
    void slotAchieveFloor(int floor, motion motion);
private slots:
    void changeToAddNewFloor(int new_floor);
private:
    bool getNewNeededFloor(int &new_floor);
    bool         needed_floors[FLOOR_NUMBERS];
    Buttons*     buttons[FLOOR_NUMBERS];
    int          current_floor;
    motion   current_motion;
    QVBoxLayout* layout;
    controller_state current_state;
};

#endif // CONTROLLER_H
