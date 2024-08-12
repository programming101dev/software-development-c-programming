#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[50] = "Hello, ";
    char src[] = "World!";
    strcat(dest, src);
    printf("Concatenated string using strcat: %s\n", dest);
    return 0;
}
