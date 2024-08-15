#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *var_name  = "MY_VAR";
    const char *var_value = "HelloWorld";
    const char *value;

    // Set environment variable using setenv, which is safer than putenv
    if(setenv(var_name, var_value, 1) != 0)    // 1 indicates to overwrite the variable if it exists // NOLINT(concurrency-mt-unsafe)
    {
        perror("setenv");
        return EXIT_FAILURE;
    }

    // Retrieve and print the environment variable
    value = getenv(var_name);    // NOLINT(concurrency-mt-unsafe)
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
