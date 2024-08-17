#include <stddef.h>
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
    int          arr[5];
    const size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    for(size_t i = 0; i <= arr_size; i++)
    {
        // cppcheck-suppress unreadVariable
        // cppcheck-suppress arrayIndexOutOfBounds
        arr[i] = (int)i;
    }
}

#pragma GCC diagnostic pop
