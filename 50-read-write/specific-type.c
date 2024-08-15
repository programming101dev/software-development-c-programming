#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int     write_int(int fd, int value, int *err);
static int     read_int(int fd, int *value, int *err);
static ssize_t write_fully(int fd, const void *buf, size_t count, int *err);
static ssize_t read_fully(int fd, void *buf, size_t count, int *err);

static int write_int(int fd, int value, int *err)
{
    if(write_fully(fd, &value, sizeof(value), err) != sizeof(value))
    {
        return -1;
    }
    return 0;
}

static int read_int(int fd, int *value, int *err)
{
    if(read_fully(fd, value, sizeof(*value), err) != sizeof(*value))
    {
        return -1;
    }
    return 0;
}

int main(void)
{
    int       fd           = open("example.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    int       err          = 0;
    const int num_to_write = 123456789;
    int       num_read;

    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if(write_int(fd, num_to_write, &err) == -1)
    {
        perror("write_int");
        close(fd);
        return EXIT_FAILURE;
    }

    lseek(fd, 0, SEEK_SET);    // Reset file offset to the beginning

    if(read_int(fd, &num_read, &err) == -1)
    {
        perror("read_int");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Read int: %d\n", num_read);

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

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
