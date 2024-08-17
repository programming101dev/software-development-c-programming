#include <errno.h>
#include <float.h>    // For LDBL_MAX and HUGE_VALL
#include <math.h>    // For fabsl
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const long double EPSILON = 1e-9L;
    const char       *str     = "1.61803398875";
    char             *endptr;
    long double       val;

    errno = 0;
    val   = strtold(str, &endptr);

    if((errno == ERANGE && (fabsl(val - HUGE_VALL) < EPSILON || fabsl(val) < EPSILON)) || (errno != 0 && fabsl(val) < EPSILON))
    {
        perror("strtold");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtold() returned %Lf\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
