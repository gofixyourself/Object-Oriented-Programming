#ifndef VIEWER_ERRORS_H
#define VIEWER_ERRORS_H

enum errors{
    FILE_ERROR,
    INCORRECT_TYPES,
    MEMORY_ALLOCATION_ERROR,
    FILE_NOT_FOUND,
    WRONG_COMMAND,
    ALL_IS_WELL
};

void errorMessage(enum errors err);

#endif //VIEWER_ERRORS_H
