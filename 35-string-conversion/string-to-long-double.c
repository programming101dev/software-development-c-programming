#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>  // For LDBL_MAX

int main(void) {
    const char *str = "1.61803398875";
    char *endptr;
    long double val;

    errno = 0;  // To distinguish success/failure after call
    val = strtold(str, &endptr);

    // Check for various possible errors
    if ((errno == ERANGE && (val == HUGE_VALL || val == 0)) || (errno != 0 && val == 0)) {
        perror("strtold");
        return EXIT_FAILURE;
    }

    if (endptr == str) {
        fprintf(stderr, "No digits were found\n");
        return EXIT_FAILURE;
    }

    printf("strtold() returned %Lf\n", val);
    printf("Remaining string: %s\n", endptr);

    return EXIT_SUCCESS;
}
