#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int  fd;
    char buffer[128];

    // Open a file for reading
    fd = open("input.txt", O_RDONLY);    // NOLINT (android-cloexec-open)
    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Redirect stdin to the file
    if(dup2(fd, STDIN_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        return EXIT_FAILURE;
    }

    // Now stdin is redirected to the file
    if(fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        printf("Read from file: %s", buffer);
    }
    else
    {
        perror("fgets");
    }

    // Close the file descriptor
    close(fd);

    return EXIT_SUCCESS;
}
