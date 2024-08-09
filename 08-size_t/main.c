#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    const size_t num_elements = 10;
    const size_t buffer_size = 256;

    printf("Number of elements: %zu\n", num_elements);
    printf("Buffer size: %zu bytes\n", buffer_size);

    return EXIT_SUCCESS;
}
