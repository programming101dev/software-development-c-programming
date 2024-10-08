#include <stdio.h>
#include <stdlib.h>

int *get_pointer_to_local(void);

int main(void)
{
    const int *p;

    p = get_pointer_to_local();

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-null-dereference"
#endif
    printf("Dangling pointer value: %d\n", *p);
#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#endif

    return EXIT_SUCCESS;
}

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wreturn-local-addr"
#elif defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wreturn-stack-address"
#endif

int *get_pointer_to_local(void)
{
    int local_var;

    local_var = 42;

    // cppcheck-suppress returnDanglingLifetime
    return &local_var;    // NOLINT(clang-analyzer-core.StackAddressEscape)
}

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#elif defined(__clang__)
    #pragma clang diagnostic pop
#endif
