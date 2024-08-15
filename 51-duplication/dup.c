#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    int saved_stdout;

    // Open a file to write output
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // NOLINT (android-cloexec-open)
    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Save the current stdout file descriptor
    saved_stdout = dup(STDOUT_FILENO);
    if(saved_stdout == -1)
    {
        perror("dup");
        close(fd);
        return EXIT_FAILURE;
    }

    // Redirect stdout to the file
    if(dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        close(saved_stdout);
        return EXIT_FAILURE;
    }

    // Now stdout is redirected to the file
    printf("This will be written to the file.\n");

    // Restore the original stdout
    if(dup2(saved_stdout, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        close(saved_stdout);
        return EXIT_FAILURE;
    }

    // Close file descriptors
    close(fd);
    close(saved_stdout);

    // Normal output to terminal
    printf("This will be printed to the terminal.\n");

    return EXIT_SUCCESS;
}
