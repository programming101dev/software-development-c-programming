#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello, World! Welcome to C programming.";
    char *saveptr;
    char *token = strtok_r(str, " ,.!", &saveptr);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok_r(NULL, " ,.!", &saveptr);
    }
    return 0;
}
