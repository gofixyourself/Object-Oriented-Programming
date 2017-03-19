#ifndef VIEWER_BASED_OPERATIONS_FOR_DOT_H
#define VIEWER_BASED_OPERATIONS_FOR_DOT_H

void initialization(arrayOfDots &ourArray);
int createArrayOfDots(arrayOfDots &ourArray, int size);
int insertDot(arrayOfDots&ourArray, dot ourDot);
int popDot(dot &needfulDot, arrayOfDots &ourArray, int index);
int settingDot(arrayOfDots &ourArray, dot &ourDot, int index);
int isEmpty(arrayOfDots &ourArray);
int clearingArrayDots(arrayOfDots &ourArray);

#endif //VIEWER_BASED_OPERATIONS_FOR_DOT_H
