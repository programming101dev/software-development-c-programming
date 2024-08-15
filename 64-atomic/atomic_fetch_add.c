#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

static atomic_int counter = 0;    // Initialize the atomic counter // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

static void increment_counter(void);

static void increment_counter(void)
{
    atomic_fetch_add(&counter, 1);
}

int main(void)
{
    increment_counter();
    increment_counter();
    printf("Counter value: %d\n", atomic_load(&counter));

    return EXIT_SUCCESS;
}
