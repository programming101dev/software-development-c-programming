#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[50] = "Hello, ";
    char src[] = "C Programming!";
    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
    printf("Concatenated string using strncat: %s\n", dest);
    return 0;
}
