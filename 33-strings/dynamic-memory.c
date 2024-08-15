#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = (char *)malloc(14 * sizeof(char));    // Allocate memory for 13 characters + null terminator

    if(str == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    str[0]  = 'H';
    str[1]  = 'e';
    str[2]  = 'l';
    str[3]  = 'l';
    str[4]  = 'o';
    str[5]  = ',';
    str[6]  = ' ';
    str[7]  = 'W';
    str[8]  = 'o';
    str[9]  = 'r';
    str[10] = 'l';
    str[11] = 'd';
    str[12] = '!';
    str[13] = '\0';    // Null terminator

    printf("%s\n", str);

    free(str);    // Free the allocated memory
    return EXIT_SUCCESS;
}
