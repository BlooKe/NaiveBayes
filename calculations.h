#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int priorProbability(Data_t *dataset, double datacount, double *retval, int datatype, int value);
int minorProbability(Data_t *dataset, double *retval, int chdatatype, int chdatavalue, int datatype, int value);
double classification (Data_t *dataset, int chdatatype, int chdatavalue, Data_t values);
int naiveBayes(Data_t *dataset, int day, int season, int wind, int rain, Results_t *results);

#endif // CALCULATIONS_H
