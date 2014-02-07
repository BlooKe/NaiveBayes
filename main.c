#include <stdio.h>
#include "definitions.h"

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

int getDataCountForClass(int data_type, int *count, int value, int data_class)
{
    int ret = SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].data_day!=FAIL; i++)
    {
        switch (data_type)
        {
            case DATA_DAY:
            {
                if(ISEAQUALFORCLASS(dataset[i].data_day, value, dataset[i].data_class, data_class))
                {
                    (*count)++;
                }
            } break;
            case DATA_SEASON:
            {
                if(ISEAQUALFORCLASS(dataset[i].data_season, value, dataset[i].data_class, data_class))
                {
                    (*count)++;
                }
            } break;
            case DATA_WIND:
            {
                if(ISEAQUALFORCLASS(dataset[i].data_wind, value, dataset[i].data_class, data_class))
                {
                    (*count)++;
                }
            } break;
            case DATA_RAIN:
            {
                if(ISEAQUALFORCLASS(dataset[i].data_rain, value, dataset[i].data_class, data_class))
                {
                    (*count)++;
                }
            } break;
            case DATA_CLASS:
            {
                if(ISEAQUALFORCLASS(dataset[i].data_class, value, dataset[i].data_class, data_class))
                {
                    (*count)++;
                }
            } break;
            default:
            {
                printf("Wrong data type - return FAIL!");
                ret=FAIL;
            }break;
        }
    }
    return ret;
}

int getDataCount(int data_type, int *count, int value)
{
    int ret = SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].data_day!=FAIL; i++)
    {
        switch (data_type)
        {
            case DATA_DAY:
            {
                if(ISEAQUAL(dataset[i].data_day, value))
                {
                    (*count)++;
                }
            } break;
            case DATA_SEASON:
            {
                if(ISEAQUAL(dataset[i].data_season, value))
                {
                    (*count)++;
                }
            } break;
            case DATA_WIND:
            {
                if(ISEAQUAL(dataset[i].data_wind, value))
                {
                    (*count)++;
                }
            } break;
            case DATA_RAIN:
            {
                if(ISEAQUAL(dataset[i].data_rain, value))
                {
                    (*count)++;
                }
            } break;
            case DATA_CLASS:
            {
                if(ISEAQUAL(dataset[i].data_class, value))
                {
                    (*count)++;
                }
            } break;
            default:
            {
                printf("Wrong data type - return FAIL!");
                ret=FAIL;
            }break;
        }
    }
    return ret;
}

int main(void)
{
    int ret=SUCCEED;
    int count = 0;
    int count2 = 0;

    ret = getDataCountForClass(DATA_RAIN, &count, HEAVY, ONTIME);
    ret = getDataCount(DATA_DAY, &count2, WEEKDAY);

    printf("ret: %d for class: %d data count: %d\n", ret, count, count2);
    return 0;
}
