#include <stdio.h>
#include <stdlib.h>

enum error_code
{
    INFO     = 1,
    DEBUG    = 2,
    WARNING  = 4,
    ERROR    = 8,
    CRITICAL = 16,
    FATAL    = 32,
    LAST,
};

int main(void)
{
    printf("INFO: %d\n", INFO);
    printf("DEBUG: %d\n", DEBUG);
    printf("WARNING: %d\n", WARNING);
    printf("ERROR: %d\n", ERROR);
    printf("CRITICAL: %d\n", CRITICAL);
    printf("FATAL: %d\n", FATAL);
    printf("FATAL: %d\n", LAST);

    return EXIT_SUCCESS;
}
