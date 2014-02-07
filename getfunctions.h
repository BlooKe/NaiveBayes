#ifndef GETFUNCTIONS_H
#define GETFUNCTIONS_H

#include "definitions.h"
#include "typedefs.h"

int getDataCount(Data_t *dataset, int data_type, int *count, int value);
int getDataCountForClass(Data_t *dataset, int data_type, int *count, int value, int data_class);

#endif // GETFUNCTIONS_H
