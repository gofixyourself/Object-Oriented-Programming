#ifndef DISPLAY_H
#define DISPLAY_H

#include "display.h"
#include "QGraphicsView"

struct drawingOnDisplay {
    QGraphicsScene *newPicture;
    QPen pen;
};

int initializationImage(drawingOnDisplay &objectForDrawing, QGraphicsView *gV);
void settingOnDisplay(QGraphicsView *gV, drawingOnDisplay &objectForDrawing);
void deletingScene(drawingOnDisplay &objectForDrawing);

#endif // DISPLAY_H
