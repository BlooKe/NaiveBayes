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

int getDataCount(int data_type, int *count, int value, int data_class)
{
    int ret = SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].data_day!=FAIL; i++)
    {
        switch (data_type)
        {
            case DATA_DAY:
            {
                if((signed)dataset[i].data_day==value && (signed)dataset[i].data_class==data_class)
                {
                    (*count)++;
                }
            } break;
            case DATA_SEASON:
            {
                if((signed)dataset[i].data_season==value && (signed)dataset[i].data_class==data_class)
                {
                    (*count)++;
                }
            } break;
            case DATA_WIND:
            {
                if((signed)dataset[i].data_wind==value && (signed)dataset[i].data_class==data_class)
                {
                    (*count)++;
                }
            } break;
            case DATA_RAIN:
            {
                if((signed)dataset[i].data_rain==value && (signed)dataset[i].data_class==data_class)
                {
                    (*count)++;
                }
            } break;
            case DATA_CLASS:
            {
                if((signed)dataset[i].data_class==value && (signed)dataset[i].data_class==data_class)
                {
                    (*count)++;
                }
            } break;
        }
    }
    return ret;
}

int main(void)
{
    int ret=SUCCEED;
    int count = 0;

    ret = getDataCount(DATA_RAIN, &count, HEAVY, ONTIME);

    printf("%d", count);
    return 0;
}
