#include <stdio.h>
#include <stdlib.h>

static void *getPointerToInt(int *num);

int main(void)
{
    int         num;
    const void *ptr;

    num = 10;
    ptr = getPointerToInt(&num);
    printf("Value: %d\n", *(int *)ptr);

    return EXIT_SUCCESS;
}

static void *getPointerToInt(int *num)
{
    return (void *)num;
}
