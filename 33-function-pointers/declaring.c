#include <stdio.h>
#include <stdlib.h>

static void func(int num);

int main(void)
{
    void (*func_ptr)(int);

    func_ptr = &func;
    func_ptr(10);

    return EXIT_SUCCESS;
}

static void func(int num)
{
    printf("Number: %d\n", num);
}
