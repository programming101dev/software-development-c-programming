#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const float EPSILON = 1e-7F;
    const char *str     = "3.14159";
    char       *endptr;
    float       val;

    errno = 0;
    val   = strtof(str, &endptr);

    if((errno == ERANGE && (fabsf(val - HUGE_VALF) < EPSILON || fabsf(val) < EPSILON)) || (errno != 0 && fabsf(val) < EPSILON))
    {
        perror("strtof");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtof() returned %.7f\n", (double)val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
