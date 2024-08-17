#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(void)
{
    // cppcheck-suppress unreadVariable
    const int *ptr = NULL;    // Initialize the pointer to NULL
    // Now use ptr safely after allocating memory

    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
