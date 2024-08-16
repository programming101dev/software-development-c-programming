#include <stdio.h>
#include <stdlib.h>

int *getPointerToLocal(void);

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wreturn-local-addr"
#elif defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wreturn-stack-address"
#endif

int *getPointerToLocal(void)
{
    int localVar = 42;

    // cppcheck-suppress returnDanglingLifetime
    return &localVar;    // Returns address of local variable    // NOLINT(clang-analyzer-core.StackAddressEscape)
}

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#elif defined(__clang__)
    #pragma clang diagnostic pop
#endif

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

    return EXIT_SUCCESS;
}
