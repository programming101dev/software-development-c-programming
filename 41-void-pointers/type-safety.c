#include <stdio.h>

static void *getPointerToInt(int *num);

static void *getPointerToInt(int *num)
{
    return (void *)num;
}

int main(void)
{
    int         num = 10;
    const void *ptr = getPointerToInt(&num);
    printf("Value: %d\n", *(int *)ptr);
    return 0;
}
