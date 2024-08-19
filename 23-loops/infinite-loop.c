#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    while(true)
    {
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-infinite-loop"
#endif
        printf("This will print forever.\n");
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#endif
    }

    return EXIT_SUCCESS;
}
