#include "structures for display status.h"
#include "strcutures of types.h"
#include "errors.h"
#include "for model.h"
#include "based operations for edge.h"
#include "for scaling.h"


void drawEdge(drawingOnDisplay &forDrawing, edge &edgeForDrawing, int height, int width, int scale)
{
    dot firstDot, secondDot;

    firstDot = scaling(*edgeForDrawing.firstEnd, height, width, scale);
    secondDot = scaling(*edgeForDrawing.secondEnd, height, width, scale);

    forDrawing.newPicture->createEdge(firstDot.x, firstDot.z, secondDot.x, secondDot.z, forDrawing.pen);
}


int drawing(model &ourModel, drawingAModel &forDrawing)
{
    drawingOnDisplay objectForDrawing;
    edge buffer;
    int checkError = 0;

    checkError = initializationImage(objectForDrawing, forDrawing.gV);

    if (checkError)
        return checkError;

    for (int i = 0; (i < (ourModel.edges.index)) && (!checkError); i++)
    {
        checkError = popEdge(buffer, ourModel.edges, index);

        if (!checkError)
            drawEdge(objectForDrawing, buffer, forDrawing.height, forDrawing.width, forDrawing.scale);
    }

    if (!checkError)
        settingOnDisplay(forDrawing.gV, objectForDrawing);
    else
        deletingScene(objectForDrawing);

    return checkError;
}

