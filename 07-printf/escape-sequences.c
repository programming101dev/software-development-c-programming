#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Escape Sequences Demonstration:\n");

	// Newline
	printf("This is the first line.\nThis is the second line.\n");

	// Horizontal Tab
	printf("Column1\tColumn2\tColumn3\n");
	printf("Data1\tData2\tData3\n");

	// Backslash
	printf("This is a backslash: \\\n");

	// Double Quote
	printf("She said, \"Hello!\"\n");

	// Single Quote
	printf("It\'s a beautiful day.\n");

	// Carriage Return
	printf("Hello, World!\rGoodbye, World!\n");

	// Alert (Bell)
	printf("Alert sound!\a\n");

	// Backspace
	printf("Text with a backspace\b.\n");

	return EXIT_SUCCESS;
}
