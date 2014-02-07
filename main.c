#include <stdio.h>
#include "definitions.h"
#include "getfunctions.h"
#include "typedefs.h"

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
    int count = 0;
    int count2 = 0;

    ret = getDataCountForClass(dataset, DATA_RAIN, &count, HEAVY, ONTIME);
    ret = getDataCount(dataset, DATA_DAY, &count2, WEEKDAY);

    printf("ret: %d for class: %d data count: %d\n", ret, count, count2);
    return 0;
}
