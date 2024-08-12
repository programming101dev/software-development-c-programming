#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello, World!";
    char *ch2 = strrchr(str, 'o');
    if (ch2 != NULL) {
        printf("Last occurrence of 'o': %c\n", *ch2);
    } else {
        printf("Character not found\n");
    }
    return 0;
}
