#ifndef VIEWER_STRCUTURES_OF_TYPES_H
#define VIEWER_STRCUTURES_OF_TYPES_H

#include <cstdio>

// File structure:
struct file {
    const char *name;
    FILE *f;
};

// Dot structure:
struct dot {
    double x;
    double y;
    double z;

};

// Edge structure:
struct edge {
    double firstEnd;
    double secondEnd;
};

// Model structure:
struct model {
    dot *dots;

    edge *edges;

    int numberOfDots;
    int numberOfEdges;
};

// Structure of dots array:
struct arrayOfDots {
    dot *array;

    int amount;
    int index;
};

// Structure of edges array:
struct arrayOfEdges{
    edge *array;

    int amount;
    int index;
};

#endif //VIEWER_STRCUTURES_OF_TYPES_H