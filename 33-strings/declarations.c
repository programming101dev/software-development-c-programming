#include <stdio.h>

int main(void) {
    char str1[13] = "Hello, World!";
    char str2[] = "Hello, World!";
    char str3[10]; // Declaration without initialization
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}
