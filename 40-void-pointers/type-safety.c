#include <stdio.h>

void *getPointerToInt(int *num) {
    return (void *)num;
}

int main(void) {
    int num = 10;
    void *ptr = getPointerToInt(&num);
    printf("Value: %d\n", *(int *)ptr);
    return 0;
}
