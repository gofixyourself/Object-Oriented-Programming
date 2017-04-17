#ifndef FOR_LOADING_H
#define FOR_LOADING_H

#include "for model.h"
#include "read.h"

// File structure:
struct file {
    const char *name;
    FILE *f;
};

// Structure of file loading event:
struct loadingAFile {
    const char *name;
};

int loading(model &ourModel, loadingAFile &inputFile);
int loadFromFile(model &ourModel, loadingAFile inputFile);


#endif // FOR_LOADING_H
