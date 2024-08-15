#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;

    // Create a new file with read and write permissions
    fd = creat("newfile.txt", S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        perror("creat");
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
