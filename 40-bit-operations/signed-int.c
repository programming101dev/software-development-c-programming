#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int result;

    a = -12;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
    result = (unsigned int)a >> 2;    // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions,hicpp-signed-bitwise)
#pragma GCC diagnostic pop

    printf("Arithmetic Shift Right (Signed): %d\n", result);

    return EXIT_SUCCESS;
}
