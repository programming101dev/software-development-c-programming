#include <stdlib.h>

static void buffer_overflow(void);

int main(void)
{
    buffer_overflow();
    return EXIT_SUCCESS;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

static void buffer_overflow(void)
{
    int arr[5];

    for(int i = 0; i <= 5; i++)
    {
        // cppcheck-suppress unreadVariable
        // cppcheck-suppress arrayIndexOutOfBounds
        arr[i] = i;    // Buffer overflow on the last iteration
    }
}

#pragma GCC diagnostic pop
