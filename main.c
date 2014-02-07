#include <stdio.h>
#include "definitions.h"
#include "typedefs.h"
#include "getfunctions.h"
#include "calculations.h"

Data_t dataset[] = {
    { WEEKDAY, SPRING, NONE, NONE_r, ONTIME },
    { WEEKDAY, WINTER, NONE, SLIGHT, ONTIME},
    { WEEKDAY, WINTER, NONE, SLIGHT, ONTIME},
    { WEEKDAY, WINTER, HIGH, HEAVY, LATE},
    { SATURDAY, SUMMER, NORMAL, NONE_r, ONTIME},
    { WEEKDAY, AUTUMN, NORMAL, NONE_r, VERYLATE},
    { HOLIDAY, SUMMER, HIGH, SLIGHT, ONTIME},
    { SUNDAY, SUMMER, NORMAL, NONE_r, ONTIME},
    { WEEKDAY, WINTER, HIGH, HEAVY, VERYLATE},
    { WEEKDAY, SUMMER, NONE, SLIGHT, ONTIME},
    { SATURDAY, SPRING, HIGH, HEAVY, CANCELLED},
    { WEEKDAY, SUMMER, HIGH, SLIGHT, ONTIME},
    { SATURDAY, WINTER, NORMAL, NONE_r, LATE},
    { WEEKDAY, SUMMER, HIGH, NONE_r, ONTIME},
    { WEEKDAY, WINTER, NORMAL, HEAVY, VERYLATE},
    { SATURDAY, AUTUMN, HIGH, SLIGHT, ONTIME},
    { WEEKDAY, AUTUMN, NONE, HEAVY, ONTIME},
    { HOLIDAY, SPRING, NORMAL, SLIGHT, ONTIME},
    { WEEKDAY, SPRING, NORMAL, NONE_r, ONTIME},
    { WEEKDAY, SPRING, NORMAL, SLIGHT, ONTIME},
    {FAIL}
};

int main(void)
{
    int ret=SUCCEED;
    double probob = 0.0;
    double minprob = 0.0;

    ret = priorProbability(dataset, (double)DATACOUNT, &probob, DATA_CLASS, ONTIME);
    ret = maxMinorProbability(dataset, &minprob, DATA_CLASS, WEEKDAY, DATA_DAY, ONTIME, SATURDAY);

    printf("ret: %d probob: %f minprob: %f\n", ret, probob, minprob);

    return 0;
}
