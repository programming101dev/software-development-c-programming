#include <stdio.h>
#include <stdlib.h>

static void *get_pointer_to_int(int *num);

int main(void)
{
    int         num;
    const void *ptr;

    num = 10;
    ptr = get_pointer_to_int(&num);
    printf("Value: %d\n", *(int *)ptr);

    return EXIT_SUCCESS;
}

static void *get_pointer_to_int(int *num)
{
    return (void *)num;
}
