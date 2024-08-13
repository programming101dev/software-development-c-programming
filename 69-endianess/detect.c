#include <stdio.h>

int is_little_endian()
{
    unsigned int x = 1;

    return (int) *((unsigned char*) &x);
}

int main(void)
{
    if(is_little_endian())
    {
        printf("System is little-endian.\n");
    }
    else
    {
        printf("System is big-endian.\n");
    }

    return 0;
}
