#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int sum(size_t count, ...)
{
    va_list args;
    int     total;

    total = 0;
    va_start(args, count);

    for(size_t i = 0; i < count; i++)
    {
        total += va_arg(args, int);    // NOLINT(clang-analyzer-valist.Uninitialized)
    }

    va_end(args);

    return total;
}

int main(void)
{
    int result;

    result = sum(3, 1, 2, 3);
    printf("Sum of 1, 2, 3: %d\n", result);
    result = sum(4, 4, 5, 6, 7);
    printf("Sum of 1, 2, 3: %d\n", result);

    return EXIT_SUCCESS;
}
