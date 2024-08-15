#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static int  open_file(const char *filename, int flags, mode_t mode);
static void close_file(int fd);
static int  redirect_stream(int stream_fd, const char *filename, int flags, mode_t mode);
static void handle_error(const char *message, int *exit_code);

int main(void)
{
    int exit_code;

    // File descriptors for redirected streams
    int fd_stdin  = -1;
    int fd_stdout = -1;
    int fd_stderr = -1;

    exit_code = EXIT_FAILURE;    // Default to failure unless successful

    // Redirect stdin to "file1.txt"
    fd_stdin = open_file("file1.txt", O_RDONLY, 0);
    if(fd_stdin == -1 || redirect_stream(STDIN_FILENO, "file1.txt", O_RDONLY, 0) == -1)
    {
        handle_error("redirect stdin", &exit_code);
        goto cleanup;
    }

    // Redirect stdout to "file2.txt"
    fd_stdout = open_file("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd_stdout == -1 || redirect_stream(STDOUT_FILENO, "file2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
        handle_error("redirect stdout", &exit_code);
        goto cleanup;
    }

    // Redirect stderr to "file3.txt"
    fd_stderr = open_file("file3.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd_stderr == -1 || redirect_stream(STDERR_FILENO, "file3.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
        handle_error("redirect stderr", &exit_code);
        goto cleanup;
    }

    // Perform operations with redirected streams
    printf("This will be written to file2.txt\n");
    fprintf(stderr, "This is an error message written to file3.txt\n");

    // Success
    exit_code = EXIT_SUCCESS;

cleanup:
    // Explicitly close the file descriptors
    if(fd_stdin != -1)
    {
        close_file(fd_stdin);
    }

    if(fd_stdout != -1)
    {
        close_file(fd_stdout);

        if(fd_stderr != -1)
        {
            close_file(fd_stderr);
        }

        return exit_code;
    }
}

static int open_file(const char *filename, int flags, mode_t mode)
{
    int fd;

    fd = open(filename, flags, mode);
    if(fd == -1)
    {
        perror("open file");
    }
    return fd;
}

static void close_file(int fd)
{
    if(fd != -1)
    {
        close(fd);
    }
}

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wanalyzer-fd-leak"
#endif

static int redirect_stream(int stream_fd, const char *filename, int flags, mode_t mode)
{
    int fd;
    int result;

    fd = open_file(filename, flags, mode);
    if(fd == -1)
    {
        return -1;
    }

    result = dup2(fd, stream_fd);
    if(result == -1)
    {
        perror("dup2");
        close_file(fd);
        return -1;
    }

    // Close the original fd only if it's not the same as stream_fd
    if(fd != stream_fd)
    {
        close_file(fd);
    }

    return 0;
}

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC diagnostic pop
#endif

static void handle_error(const char *message, int *exit_code)
{
    perror(message);
    *exit_code = EXIT_FAILURE;
}
