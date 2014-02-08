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
#include "typedefs.h"
#include "definitions.h"

int getDataCount(Data_t *dataset, int data_type, double *count, int value)
{
    int ret = SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].classname!=FAIL; i++)
    {
        switch (data_type)
        {
            case CLASSNAME:
            {
                if(ISEAQUAL(dataset[i].classname, value))
                {
                    (*count)++;
                }
            } break;
            case LWEIGHT:
            {
                if(ISEAQUAL(dataset[i].lweight, value))
                {
                    (*count)++;
                }
            } break;
            case LDISTANCE:
            {
                if(ISEAQUAL(dataset[i].ldistance, value))
                {
                    (*count)++;
                }
            } break;
            case RWEIGHT:
            {
                if(ISEAQUAL(dataset[i].rweight, value))
                {
                    (*count)++;
                }
            } break;
            case RDISTANCE:
            {
                if(ISEAQUAL(dataset[i].rdistance, value))
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

int getDataCountForClass(Data_t *dataset, int data_type, double *count, int value, int data_class)
{
    int ret = SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].classname!=FAIL; i++)
    {
        switch (data_type)
        {
            case CLASSNAME:
            {
                if(ISEAQUALFORCLASS(dataset[i].classname, value, dataset[i].classname, data_class))
                {
                    (*count)++;
                }
            } break;
            case LWEIGHT:
            {
                if(ISEAQUALFORCLASS(dataset[i].lweight, value, dataset[i].classname, data_class))
                {
                    (*count)++;
                }
            } break;
            case LDISTANCE:
            {
                if(ISEAQUALFORCLASS(dataset[i].ldistance, value, dataset[i].classname, data_class))
                {
                    (*count)++;
                }
            } break;
            case RWEIGHT:
            {
                if(ISEAQUALFORCLASS(dataset[i].rweight, value, dataset[i].classname, data_class))
                {
                    (*count)++;
                }
            } break;
            case RDISTANCE:
            {
                if(ISEAQUALFORCLASS(dataset[i].rdistance, value, dataset[i].classname, data_class))
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

