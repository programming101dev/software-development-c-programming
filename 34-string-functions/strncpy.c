#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char src[] = "Hello, C Programming!";
    char       dest[10];
    // sizeof(dest) - 1 is used to ensure there is space for the null terminator
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';    // Ensure null termination
    printf("Copied string using strncpy: %s\n", dest);

    return EXIT_SUCCESS;
}
