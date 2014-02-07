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

int maxMinorProbability(Data_t *dataset, double *retval, int chdatatype, int chdatavalue, int datatype, int dataclass, int maxvalue)
{
    int ret = SUCCEED;
    double count = 0.0;
    double countClass = 0.0;
    int value = 0;
    double temp = 0.0;

    ret = getDataCount(dataset, chdatatype, &count, chdatavalue);
    for(value; value <= maxvalue; value++)
    {
        ret = getDataCountForClass(dataset, datatype, &countClass, value, dataclass);

        printf("count: %f, countClass: %f\n", count, countClass);
        temp = countClass / count;
        if(temp > *retval)
        {
            *retval = temp;
        }
    }

    return ret;
}

