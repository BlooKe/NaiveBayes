/*  *
 *  *
 *  *
 *  *
 *  */

#include <stdio.h>
#include "typedefs.h"
#include "definitions.h"

int getDataCount(Data_t *dataset, int data_type, int *count, int value)
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

int getDataCountForClass(Data_t *dataset, int data_type, int *count, int value, int data_class)
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

