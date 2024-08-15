#include <errno.h>
#include <fcntl.h>
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
    int       fd           = open("example.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);    // NOLINT (android-cloexec-open)
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

static ssize_t read_fully(int fd, void *buf, size_t count, int *err)
{
    ssize_t bytes_read = 0;

    while(bytes_read < (ssize_t)count)
    {
        ssize_t result;

        result = read(fd, (char *)buf + bytes_read, count - (size_t)bytes_read);

        if(result == 0)
        {
            break;    // EOF reached
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
    }

    return bytes_read;
}

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
