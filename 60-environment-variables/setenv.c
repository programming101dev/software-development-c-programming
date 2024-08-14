#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *var_name = "MY_VAR";
    const char *var_value = "HelloWorld";

    if (setenv(var_name, var_value, 1) != 0) {
        perror("setenv");
        return EXIT_FAILURE;
    }

    printf("%s set to %s\n", var_name, getenv(var_name));
    return EXIT_SUCCESS;
}
