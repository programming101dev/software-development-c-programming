#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    int result;

    // Open a file to write output
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Replace stdout with the file descriptor
    result = dup2(fd, STDOUT_FILENO);
    if(result == -1)
    {
        perror("Failed to redirect stdout");
        close(fd);
        return EXIT_FAILURE;
    }

    // Now, this will be written to the file instead of the terminal
    printf("This message is redirected to output.txt\n");

    // Close the file descriptor
    close(fd);

    return EXIT_SUCCESS;
}
