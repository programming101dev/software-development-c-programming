#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	fprintf(stdout, "This is standard output.\n");
	fprintf(stderr, "This is an error message.\n");

	return EXIT_SUCCESS;
}
