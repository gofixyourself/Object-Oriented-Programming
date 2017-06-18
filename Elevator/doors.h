#ifndef DOORS_H
#define DOORS_H

#include <QObject>

#include "time.h"

class Doors : public QObject {
    Q_OBJECT
    enum StateDoor {
        OPEN,
        OPENING,
        CLOSE,
        CLOSING
    };
public:
    Doors();
signals:

public slots:

private slots:

private:

};

#endif // DOORS_H
