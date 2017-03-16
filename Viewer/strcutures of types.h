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

#endif //VIEWER_STRCUTURES_OF_TYPES_H