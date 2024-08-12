#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char str[] = "Hello, World!";
    char *duplicate = strdup(str);

    if (duplicate == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Duplicated string: %s\n", duplicate);
    free(duplicate);  // Free the allocated memory
    return 0;
}
