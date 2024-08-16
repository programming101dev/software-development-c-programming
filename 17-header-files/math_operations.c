#include "math_operations.h"

int sum_elements(const int *array, size_t size)
{
    int sum;

    sum = 0;

    for(size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int max_element(const int *array, size_t size)
{
    int max;

    if(size == 0)
    {
        max = 0;
    }
    else
    {
        max = array[0];

        for(size_t i = 1; i < size; i++)
        {
            if(array[i] > max)
            {
                max = array[i];
            }
        }
    }

    return max;
}
