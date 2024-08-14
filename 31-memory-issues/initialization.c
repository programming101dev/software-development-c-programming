#include <stdio.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(void)
{
    const int *ptr = NULL;    // Initialize the pointer to NULL
    // Now use ptr safely after allocating memory

    return 0;
}

#pragma GCC diagnostic pop
