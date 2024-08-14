#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    const char *data = "Hello, World!";
    if (write(fd, data, 13) != 13) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    // Synchronize the file's data to disk
    if (fdatasync(fd) == -1) {
        perror("fdatasync");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Data synchronized to disk successfully.\n");

    close(fd);
    return EXIT_SUCCESS;
}
