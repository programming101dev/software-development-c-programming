#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello, World!";
    char *substr = strstr(str, "World");
    if (substr != NULL) {
        printf("Found substring: %s\n", substr);
    } else {
        printf("Substring not found\n");
    }
    return 0;
}
