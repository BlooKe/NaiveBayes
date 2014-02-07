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

int minorProbability(Data_t *dataset, double *retval, int chdatatype, int chdatavalue, int datatype, int value)
{
    int ret = SUCCEED;
    double count = 0.0;
    double countClass = 0.0;

    ret = getDataCount(dataset, chdatatype, &count, chdatavalue);
    ret = getDataCountForClass(dataset, datatype, &countClass, value, chdatavalue);

    *retval = countClass / count;

    return ret;
}
double classification (Data_t *dataset, int chdatatype, int chdatavalue, Data_t values)
{
    int ret = SUCCEED;
    double result = 0.0;
    double priprob = 0.0;
    double minday = 0.0;
    double minseason = 0.0;
    double minwind = 0.0;
    double minrain = 0.0;

    ret = priorProbability(dataset, (double)DATACOUNT, &priprob, chdatatype, chdatavalue);
    ret = minorProbability(dataset, &minday, chdatatype, chdatavalue, DATA_DAY, values.data_day);
    ret = minorProbability(dataset, &minseason, chdatatype, chdatavalue, DATA_SEASON, values.data_season);
    ret = minorProbability(dataset, &minwind, chdatatype, chdatavalue, DATA_WIND, values.data_wind);
    ret = minorProbability(dataset, &minrain, chdatatype, chdatavalue, DATA_RAIN, values.data_rain);

    result = priprob * minday * minseason * minwind * minrain;

    return result;
}

int naiveBayes(Data_t *dataset, int day, int season, int wind, int rain, Results_t *results)
{
    int ret = SUCCEED;
    Data_t values = { day, season, wind, rain, FAIL };


    results->ontime = classification(dataset, DATA_CLASS, ONTIME, values);
    results->late = classification(dataset, DATA_CLASS, LATE, values);
    results->verylate = classification(dataset, DATA_CLASS, VERYLATE, values);
    results->cancelled = classification(dataset, DATA_CLASS, CANCELLED, values);

    return ret;
}

