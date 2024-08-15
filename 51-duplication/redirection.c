#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int  in_fd  = -1;
    int  out_fd = -1;
    int  err_fd = -1;
    char buffer[128];

    // Open files for redirection
    in_fd = open("in.txt", O_RDONLY);    // NOLINT (android-cloexec-open)

    if(in_fd == -1)
    {
        perror("open in.txt");
        goto error;
    }

    out_fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // NOLINT (android-cloexec-open)

    if(out_fd == -1)
    {
        perror("open out.txt");
        goto error;
    }

    err_fd = open("err.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // NOLINT (android-cloexec-open)

    if(err_fd == -1)
    {
        perror("open err.txt");
        goto error;
    }

    // Redirect stdin, stdout, and stderr
    if(dup2(in_fd, STDIN_FILENO) == -1)
    {
        perror("dup2 stdin");
        goto error;
    }

    if(dup2(out_fd, STDOUT_FILENO) == -1)
    {
        perror("dup2 stdout");
        goto error;
    }

    if(dup2(err_fd, STDERR_FILENO) == -1)
    {
        perror("dup2 stderr");
        goto error;
    }

    // Close original file descriptors
    close(in_fd);
    close(out_fd);
    close(err_fd);

    // Example operations
    if(fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        printf("Read from stdin: %s", buffer);    // This goes to out.txt
    }
    else
    {
        perror("fgets");
    }

    fprintf(stderr, "This is an error message.\n");    // This goes to err.txt

    return EXIT_SUCCESS;

error:
    // Clean up resources if an error occurs
    if(in_fd != -1)
    {
        close(in_fd);
    }

    if(out_fd != -1)
    {
        close(out_fd);
    }

    if(err_fd != -1)
    {
        close(err_fd);
    }

    return EXIT_FAILURE;
}
