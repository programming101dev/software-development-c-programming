#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *var_name = "MY_VAR";

    if(unsetenv(var_name) != 0)    // NOLINT(concurrency-mt-unsafe)
    {
        perror("unsetenv");
        return EXIT_FAILURE;
    }

    printf("%s unset\n", var_name);
    return EXIT_SUCCESS;
}
