#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int write_int(int fd, int value, int *err) {
    if (write_fully(fd, &value, sizeof(value), err) != sizeof(value)) {
        return -1;
    }
    return 0;
}

int read_int(int fd, int *value, int *err) {
    if (read_fully(fd, value, sizeof(*value), err) != sizeof(*value)) {
        return -1;
    }
    return 0;
}

int main(void) {
    int fd = open("example.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    int err = 0;
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int num_to_write = 123456789;
    if (write_int(fd, num_to_write, &err) == -1) {
        perror("write_int");
        close(fd);
        return EXIT_FAILURE;
    }

    lseek(fd, 0, SEEK_SET); // Reset file offset to the beginning

    int num_read;
    if (read_int(fd, &num_read, &err) == -1) {
        perror("read_int");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Read int: %d\n", num_read);

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
