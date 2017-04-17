#ifndef ERRORS_H
#define ERRORS_H

#include "QMessageBox"

enum errors {
    FILE_ERROR,
    INCORRECT_TYPES,
    MEMORY_ALLOCATION_ERROR,
    FILE_NOT_FOUND,
    INCORRECT_COMMAND,
    ALL_IS_WELL
};

void errorMessanger(enum errors ourError);

#endif // ERRORS_H
