#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static ssize_t read_fully(int fd, void *buf, size_t count, int *err);

static ssize_t read_fully(int fd, void *buf, size_t count, int *err)
{
    bool    done;
    ssize_t bytes_read      = 0;
    ssize_t bytes_remaining = (ssize_t)count;

    done = false;

    while(!done)
    {
        ssize_t result = read(fd, (char *)buf + bytes_read, (size_t)bytes_remaining);

        if(result == 0)
        {
            done = true;
            continue;
        }

        if(result == -1)
        {
            if(errno == EINTR)
            {
                continue;    // Interrupted, retry
            }

            *err = errno;
            return -1;    // Error occurred
        }

        bytes_read += result;
        bytes_remaining -= result;

        if(bytes_remaining <= 0)
        {
            done = true;
        }
    }

    return bytes_read;
}

int main(void)
{
    const char *filename = "example.txt";
    int         fd       = open(filename, O_RDONLY);
    char        buffer[256];
    int         err = 0;
    ssize_t     result;

    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    result = read_fully(fd, buffer, sizeof(buffer) - 1, &err);

    if(result == -1)
    {
        perror("read_fully");
        close(fd);
        return EXIT_FAILURE;
    }

    buffer[result] = '\0';    // Null-terminate the buffer
    printf("Read %zd bytes: %s\n", result, buffer);

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
