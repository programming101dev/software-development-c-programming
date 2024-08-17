#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t num_elements;
    size_t buffer_size;

    num_elements = 10;
    buffer_size  = 256;
    printf("Number of elements: %zu\n", num_elements);
    printf("Buffer size: %zu bytes\n", buffer_size);

    return EXIT_SUCCESS;
}
