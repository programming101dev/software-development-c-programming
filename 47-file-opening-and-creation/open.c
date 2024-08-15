#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;

    // Open an existing file for reading
    fd = open("example.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Close the file descriptor
    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
