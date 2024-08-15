#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *var_name = "HOME";
    const char *value    = getenv(var_name);    // NOLINT(concurrency-mt-unsafe)

    if(value != NULL)
    {
        printf("The value of %s is %s\n", var_name, value);
    }
    else
    {
        printf("%s is not set\n", var_name);
    }

    return EXIT_SUCCESS;
}
