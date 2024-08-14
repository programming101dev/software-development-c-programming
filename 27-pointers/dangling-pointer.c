#include <stdio.h>

int *getPointerToLocal(void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

int *getPointerToLocal(void)
{
    int localVar = 42;

    // cppcheck-suppress returnDanglingLifetime
    return &localVar;    // Returns address of local variable    // NOLINT(clang-analyzer-core.StackAddressEscape)
}

#pragma GCC diagnostic pop

int main(void)
{
    const int *p = getPointerToLocal();
    // p is now a dangling pointer because localVar is out of scope

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-null-dereference"
#endif
    printf("Dangling pointer value: %d\n", *p);    // Undefined behavior

#if defined(__GNUC__) && !defined(__llvm__)
    #pragma GCC diagnostic pop
#endif

    return 0;
}
