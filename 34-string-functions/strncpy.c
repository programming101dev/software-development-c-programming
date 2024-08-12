#include <stdio.h>
#include <string.h>

void example_strncpy(void) {
    char src[] = "Hello, C Programming!";
    char dest[10];
    // sizeof(dest) - 1 is used to ensure there is space for the null terminator
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';  // Ensure null termination
    printf("Copied string using strncpy: %s\n", dest);
}

int main(void) {
    example_strncpy();
    return 0;
}
