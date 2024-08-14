#include <errno.h>
#include <float.h>    // For FLT_MAX
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "3.14159";
    char       *endptr;
    float       val;

    errno = 0;    // To distinguish success/failure after call
    val   = strtof(str, &endptr);

    // Check for various possible errors
    if((errno == ERANGE && (val == HUGE_VALF || val == 0)) || (errno != 0 && val == 0))
    {
        perror("strtof");
        return EXIT_FAILURE;
    }

    if(endptr == str)
    {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtof() returned %f\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
