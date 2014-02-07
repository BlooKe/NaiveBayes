/*  *
 *  *
 *  *
 *  *
 *  */

#include <stdio.h>
#include "definitions.h"
#include "typedefs.h"
#include "getfunctions.h"

int priorProbability(Data_t *dataset, double datacount, double *retval, int datatype, int value)
{
    int ret = SUCCEED;
    double count = 0.0;

    ret = getDataCount(dataset, datatype, &count, value);

    *retval = count / datacount;

    return ret;
}


