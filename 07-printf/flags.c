#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number = 42;
	double floatNum = 3.14159;

	printf("Flags Demonstration:\n");

	// Always show sign
	printf("Always show sign: %+d\n", number);

	// Pad with leading zeros
	printf("Pad with leading zeros: %010d\n", number);

	// Space before positive numbers
	printf("Space before positive numbers: % d\n", number);

	// Alternate form
	printf("Hexadecimal with 0x: %#x\n", number);
	printf("Floating-point with decimal point: %#f\n", floatNum);

	return EXIT_SUCCESS;
}
