#include <stdio.h>

int main(void) {
    char str[] = "Hello, World!";
    for (int i = 0; str[i] != '\0'; i++) {
        printf("Index %d: %c\n", i, str[i]);
    }
    return 0;
}
