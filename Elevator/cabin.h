#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "doors.h"
#include "times.h"

class Cabin : public QObject{
    Q_OBJECT
    enum cabin_states {
        MOVING,
        BUSY,
        FREE
    };
public:
    explicit Cabin(QObject *parent = 0);
signals:
    void previousFloor(int floor, motion new_motion);
    void selectedFloor(int floor, motion new_motion);
public slots:
    void changeToMoving();
    void changeToFree();
    void changeToBusy(int floor);
private:
    int current_floor = 0;
    int needed_floor;
    motion current_motion;
    cabin_states current_state;
    Doors doors;
    QTimer timer_for_motion;
signals:
    void changeToArrivedAtFloor();
    void changeToMove();
};

#endif // CABIN_H
