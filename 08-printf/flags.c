#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int    number;
    double floatNum;

    number   = 42;
    floatNum = 3.14159;
    printf("Flags Demonstration:\n");
    printf("Always show sign: %+d\n", number);
    printf("Pad with leading zeros: %010d\n", number);
    printf("Space before positive numbers: % d\n", number);
    printf("Hexadecimal with 0x: %#x\n", number);
    printf("Floating-point with decimal point: %#f\n", floatNum);

    return EXIT_SUCCESS;
}
