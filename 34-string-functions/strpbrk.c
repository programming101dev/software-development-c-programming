#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello, World!";
    char keys[] = "oW";
    char *ch = strpbrk(str, keys);
    if (ch != NULL) {
        printf("First occurrence of any character in 'oW': %c\n", *ch);
    } else {
        printf("No characters found\n");
    }
    return 0;
}
