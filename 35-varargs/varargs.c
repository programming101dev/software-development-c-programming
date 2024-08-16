#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int sum(int count, ...)
{
    va_list args;
    int     total = 0;

    va_start(args, count);    // Initialize va_list before any conditionals

    if(count > 0)
    {
        for(int i = 0; i < count; i++)
        {
            total += va_arg(args, int);    // Safely access each argument    // NOLINT(clang-analyzer-valist.Uninitialized)
        }
    }

    va_end(args);    // Always ensure va_list is cleaned up

    return total;
}

int main(void)
{
    printf("Sum of 1, 2, 3: %d\n", sum(3, 1, 2, 3));
    printf("Sum of 4, 5, 6, 7: %d\n", sum(4, 4, 5, 6, 7));

    return EXIT_SUCCESS;
}
