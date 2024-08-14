#include <stdlib.h>

void buffer_overflow(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

void buffer_overflow(void)
{
    int arr[5];

    for(int i = 0; i <= 5; i++)
    {
        arr[i] = i;    // Buffer overflow on the last iteration
    }
}

#pragma GCC diagnostic pop

int main(void)
{
    buffer_overflow();
    return EXIT_SUCCESS;
}
