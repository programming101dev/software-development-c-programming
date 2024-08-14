#include <errno.h>
#include <float.h>    // For DBL_MAX
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "2.718281828459";
    char       *endptr;
    double      val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtod(str, &endptr);

    // Check for various possible errors
    if((errno == ERANGE && (val == HUGE_VAL || val == 0)) || (errno != 0 && val == 0))
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
