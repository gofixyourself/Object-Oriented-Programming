#ifndef FOR_DRAWING_H
#define FOR_DRAWING_H

#include "for model.h"
#include "for scaling.h"
#include "edge.h"
#include "display.h"

// Structure of model drawing event:
struct drawingAModel {
    QGraphicsView *pen;

    int height;
    int width;
    int scale;
};

int drawing(model &ourModel, drawingAModel &forDrawing);
void drawEdge(drawingOnDisplay &forDrawing, edge &edgeForDrawing, int height, int width, int scale);

#endif // FOR_DRAWING_H
