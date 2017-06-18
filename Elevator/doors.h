#ifndef DOORS_H
#define DOORS_H

#include <QObject>

#include "time.h"

class Doors : public QObject {
    Q_OBJECT
    enum doors_states {
        OPEN,
        OPENING,
        CLOSE,
        CLOSING
    };
public:
    Doors();
signals:
    void doorIsClosed();
    void doorIsOpening();
public slots:
    void changeToOpen();
    void changeToClose();
private slots:
    void changeToOpening();
    void changeToClosing();
private:
    doors_states current_state;

    QTimer timer_for_open;
    QTimer timer_for_close;
    QTimer timer_for_wait;
};

#endif // DOORS_H
