#include "for drawing.h"

void drawEdge(drawingOnDisplay &forDrawing, edge &edgeForDrawing, int height, int width, int scale)
{
    dot firstDot = scaling(*edgeForDrawing.firstEnd, height, width, scale);
    dot secondDot = scaling(*edgeForDrawing.secondEnd, height, width, scale);

    forDrawing.newPicture->addLine(firstDot.x, firstDot.z, secondDot.x, secondDot.z, forDrawing.pen);
}

// Function to draw a model:
int drawing(model &ourModel, drawingAModel &forDrawing)
{
    drawingOnDisplay objectForDrawing;
    edge buffer;

    int checkError = initializationImage(objectForDrawing, forDrawing.pen);

    if (checkError)
        return checkError;

    for (int i = 0; (i < (ourModel.edges.index)) && !checkError; i++)
    {
        checkError = popEdge(buffer, ourModel.edges, i);

        if (!checkError)
            drawEdge(objectForDrawing, buffer, forDrawing.height, forDrawing.width, forDrawing.scale);
    }

    if (!checkError)
        settingOnDisplay(forDrawing.pen, objectForDrawing);
    else
        deletingScene(objectForDrawing);

    return checkError;
}

