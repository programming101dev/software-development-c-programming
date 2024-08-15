#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE     *file       = fopen("example.bin", "wb");
    const int buffer[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t    bytesWritten;

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    bytesWritten = fwrite(buffer, sizeof(int), 10, file);
    if(bytesWritten != 10)
    {
        perror("fwrite");
        if(fclose(file) != 0)
        {
            perror("fclose");
        }
        return EXIT_FAILURE;
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
