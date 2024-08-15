#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static ssize_t write_fully(int fd, const void *buf, size_t count, int *err);

static ssize_t write_fully(int fd, const void *buf, size_t count, int *err)
{
    bool    done            = false;
    ssize_t bytes_written   = 0;
    ssize_t bytes_remaining = (ssize_t)count;

    while(!done)
    {
        ssize_t result = write(fd, (const char *)buf + bytes_written, (size_t)bytes_remaining);

        if(result == -1)
        {
            if(errno == EINTR)
            {
                continue;    // Interrupted, retry
            }
            *err = errno;
            return -1;    // Error occurred
        }

        bytes_written += result;
        bytes_remaining -= result;

        if(bytes_remaining <= 0)
        {
            done = true;
        }
    }

    return bytes_written;
}

int main(void)
{
    const char *filename = "output.txt";
    int         fd       = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    const char *message  = "Hello, World! This is a test of the write_fully function.\n";
    int         err;
    ssize_t     result;

    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    err    = 0;
    result = write_fully(fd, message, strlen(message), &err);

    if(result == -1)
    {
        perror("write_fully");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Written %zd bytes to %s\n", result, filename);

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
