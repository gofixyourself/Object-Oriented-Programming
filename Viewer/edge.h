#ifndef EDGE_H
#define EDGE_H

#include "dot.h"

// Edge structure:
struct edge {
    dot *firstEnd;
    dot *secondEnd;
};

// Structure of edges array:
struct arrayOfEdges {
    edge *array;

    int amount;
    int index;
};

void initializationEdge(arrayOfEdges &ourArray);
int createArrayOfEdges(arrayOfEdges &ourArray, int size);
int insertEdge(arrayOfEdges &ourArray, edge ourEdge);
int popEdge(edge &needfulEdge, arrayOfEdges &ourArray, int index);
int settingEdge(arrayOfEdges &ourArray, int index, edge &ourEdge);
int isEmpty(arrayOfEdges &ourArray);
int clearingArrayEdges(arrayOfEdges &ourArray);

#endif // EDGE_H
