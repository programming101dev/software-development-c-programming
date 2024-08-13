#include <stdio.h>

int *getPointerToLocal(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

int *getPointerToLocal(void)
{
    int localVar = 42;
    return &localVar;    // Returns address of local variable
}

#pragma GCC diagnostic pop

int main(void)
{
    int *p = getPointerToLocal();
// p is now a dangling pointer because localVar is out of scope
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wanalyzer-null-dereference"
    printf("Dangling pointer value: %d\n", *p);    // Undefined behavior
#pragma GCC diagnostic pop

    return 0;
}
