#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int priorProbability(Data_t *dataset, double datacount, double *retval, int datatype, int value);
int maxMinorProbability(Data_t *dataset, double *retval, int chdatatype, int chdatavalue, int datatype, int dataclass, int maxvalue);

#endif // CALCULATIONS_H
