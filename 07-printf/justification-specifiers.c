#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number = 42;

	printf("Justification Specifiers Demonstration:\n");

	// Right-justify (default)
	printf("Right-justify (default): %10d\n", number);

	// Left-justify
	printf("Left-justify: %-10d\n", number);

	return EXIT_SUCCESS;
}
