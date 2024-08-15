#include <stdatomic.h>
#include <stdio.h>

void increment_counter()
{
    atomic_fetch_add(&counter, 1);
}

int main(void)
{
    increment_counter();
    increment_counter();
    printf("Counter value: %d\n", counter);
    return 0;
}
