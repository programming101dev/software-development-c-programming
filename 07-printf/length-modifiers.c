#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short shortInt = 42;
	long longInt = 1234567890L;
	long long longLongInt = 1234567890123456789LL;
	long double longDouble = 3.141592653589793238L;

	printf("Length Modifiers Demonstration:\n");

	// Short integer
	printf("Short integer: %hd\n", shortInt);

	// Long integer
	printf("Long integer: %ld\n", longInt);

	// Long long integer
	printf("Long long integer: %lld\n", longLongInt);

	// Long double
	printf("Long double: %Lf\n", longDouble);

	return EXIT_SUCCESS;
}
