#include <stdio.h>

int main(void) {
    int num = 10;
    float f = 3.14;
    char str[] = "Hello";

    void *ptr;

    ptr = &num;
    printf("Integer: %d\n", *(int *)ptr);

    ptr = &f;
    printf("Float: %.2f\n", *(float *)ptr);

    ptr = str;
    printf("String: %s\n", (char *)ptr);

    return 0;
}
