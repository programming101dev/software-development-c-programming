#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// cppcheck-suppress constParameter
int main(int argc, char *argv[])
{
    int sum = 0;

    for(int i = 1; i < argc; i++)
    {
        // Convert argument to integer and add to sum
        sum += (int)strtoimax(argv[i], NULL, 10);
    }

    printf("Sum: %d\n", sum);

    return EXIT_SUCCESS;
}
