#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int   number = 10;
    const char *result;

    result = (number > 0) ? "Positive" : "Non-positive";

    printf("The number is %s.\n", result);

    return EXIT_SUCCESS;
}