#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    const char *filename = "example.txt";
    int         fd       = open(filename, O_RDWR);
    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Truncate the file to 100 bytes
    if(ftruncate(fd, 100) == -1)
    {
        perror("ftruncate");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("File '%s' has been truncated to 100 bytes.\n", filename);

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
