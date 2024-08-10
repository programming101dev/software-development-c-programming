#include "math_operations.h"

int sum_elements(const int *array, size_t size)
{
    int sum = 0;

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
        return 0; // Return 0 if the array is empty
    }

    max = array[0];

    for(size_t i = 1; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}
