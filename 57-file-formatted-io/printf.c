#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int age = 30;
    const char *name = "Alice";
    printf("Name: %s, Age: %d\n", name, age);

    if (fclose(file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
