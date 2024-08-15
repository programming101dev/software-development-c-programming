#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char var_assignment[] = "MY_VAR=HelloWorld";

    if(putenv(var_assignment) != 0)    // NOLINT(concurrency-mt-unsafe)
    {
        perror("putenv");
        return EXIT_FAILURE;
    }

    printf("MY_VAR set to %s\n", getenv("MY_VAR"));    // NOLINT(concurrency-mt-unsafe)
    return EXIT_SUCCESS;
}
