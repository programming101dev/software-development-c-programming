#include <stdio.h>

int main(void)
{
    int a = -12;    // 11111111 11111111 11111111 11110100 in binary (32-bit)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
    int result = (unsigned int)a >> 2;    // Cast to unsigned before shifting // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions,hicpp-signed-bitwise)
#pragma GCC diagnostic pop

    printf("Arithmetic Shift Right (Signed): %d\n", result);    // Output: -3
    return 0;
}
