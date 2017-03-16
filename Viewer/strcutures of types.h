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
    double first_end;
    double second_end;
};

#endif //VIEWER_STRCUTURES_OF_TYPES_H
