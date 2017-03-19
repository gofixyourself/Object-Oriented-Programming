#include "strcutures of types.h"
#include "structures for display status.h"


int drawing(object &ourObject, drawingAModel forDrawing)
{
    struct to_draw objectForDrawing;
    struct inter buf;

    int error = 0;

    error = initialization(a, forDrawing.pen);

    if (error)
        return error;

    for (int i = 0; (i < (ourObject.edges.index)) && (!error); i++) {
        error = elem(buf, ourObject.edges, i);

        if (!error)
            line(objectForDrawing, buf, forDrawing.height, forDrawing.width, forDrawing.scale);
    }

    if (!error)
        set(forDrawing.pen, objectForDrawing);
    else
        del(objectForDrawing);

    return error;
}
