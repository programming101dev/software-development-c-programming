#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const double EPSILON = 1e-9;
    const char  *str     = "2.718281828459";
    char        *endptr;
    double       val;

    errno = 0;
    val   = strtod(str, &endptr);

    if((errno == ERANGE && (fabs(val - HUGE_VAL) < EPSILON || fabs(val + HUGE_VAL) < EPSILON || fabs(val) < EPSILON)) || (errno != 0 && fabs(val) < DBL_EPSILON))
    {
        perror("strtod");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtod() returned %f\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
