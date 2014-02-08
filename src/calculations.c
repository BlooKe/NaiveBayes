/****************************************************************************
 * Copyright (c) 2014 Lauris Radzevics                                      *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining    *
 * a copy of this software and associated documentation files (the          *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, sublicense, and/or sell copies of the Software, and to       *
 * permit persons to whom the Software is furnished to do so, subject to    *
 * the following conditions:                                                *
 *                                                                          *
 * The above copyright notice and this permission notice shall be           *
 * included in all copies or substantial portions of the Software.          *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                    *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE   *
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION   *
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION    *
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.          *
 ****************************************************************************/

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
double classification (Data_t *dataset, int chdatatype, int chdatavalue, Data_t values, int datacount)
{
    int ret = SUCCEED;
    double result = 0.0;
    double priprob = 0.0;
    double minlweight = 0.0;
    double minldist = 0.0;
    double minrweight = 0.0;
    double minrdist = 0.0;

    ret = priorProbability(dataset, datacount, &priprob, chdatatype, chdatavalue);
    ret = minorProbability(dataset, &minlweight, chdatatype, chdatavalue, LWEIGHT, values.lweight);
    ret = minorProbability(dataset, &minldist, chdatatype, chdatavalue, LDISTANCE, values.ldistance);
    ret = minorProbability(dataset, &minrweight, chdatatype, chdatavalue, RWEIGHT, values.rweight);
    ret = minorProbability(dataset, &minrdist, chdatatype, chdatavalue, RDISTANCE, values.rdistance);

    result = priprob * minlweight * minldist * minrweight * minrdist;

    return result;
}

int naiveBayes(Data_t *dataset, int lweight, int ldistance, int rweight, int rdistance, Results_t *results, int datacount)
{
    int ret = SUCCEED;
    Data_t values = { FAIL, lweight, ldistance, rweight, rdistance};


    results->left = classification(dataset, CLASSNAME, LEFT, values, datacount);
    results->balance = classification(dataset, CLASSNAME, BALANCE, values, datacount);
    results->right = classification(dataset, CLASSNAME, RIGHT, values, datacount);

    return ret;
}

