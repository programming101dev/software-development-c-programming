#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static ssize_t write_fully(int fd, const void *buf, size_t count, int *err);

static ssize_t write_fully(int fd, const void *buf, size_t count, int *err)
{
    ssize_t bytes_written = 0;

    while(bytes_written < (ssize_t)count)
    {
        ssize_t result = write(fd, (const char *)buf + bytes_written, count - (size_t)bytes_written);

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
    }
    return bytes_written;
}

int main(void)
{
    const char *filename = "output.txt";
    int         fd       = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);    // NOLINT (android-cloexec-open)
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
