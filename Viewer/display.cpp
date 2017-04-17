#include "service structures.h"
#include "errors.h"
#include "for model.h"

int initializationImage(drawingOnDisplay &objectForDrawing, QGraphicsView *gV)
{
    objectForDrawing.newPicture = new QGraphicsScene(gV);

    if (!objectForDrawing.newPicture)
        return MEMORY_ALLOCATION_ERROR;

    objectForDrawing.pen = QPen(Qt::blue);

    return ALL_IS_WELL;
}

void settingOnDisplay(QGraphicsView *gV, drawingOnDisplay &objectForDrawing)
{
    QGraphicsScene *latest = gV->scene();

    delete latest;

    gV->setScene(objectForDrawing.newPicture);
}

void deletingScene(drawingOnDisplay &objectForDrawing)
{
    delete objectForDrawing.newPicture;
}
