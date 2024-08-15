#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int         fd;
    int         fd_dup;
    ssize_t     bytes_written;
    const char *message = "Hello, World!\n";

    // Open a file to write output
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Duplicate the file descriptor
    fd_dup = dup(fd);
    if(fd_dup == -1)
    {
        perror("Failed to duplicate file descriptor");
        close(fd);
        return EXIT_FAILURE;
    }

    // Write to the original file descriptor
    bytes_written = write(fd, message, 14);
    if(bytes_written == -1)
    {
        perror("Failed to write to original file descriptor");
    }

    // Write to the duplicated file descriptor
    bytes_written = write(fd_dup, "Duplicate FD\n", 13);
    if(bytes_written == -1)
    {
        perror("Failed to write to duplicate file descriptor");
    }

    // Close file descriptors
    close(fd);
    close(fd_dup);

    return EXIT_SUCCESS;
}
