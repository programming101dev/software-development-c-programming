#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    const char *filename = "example.txt";
    int         fd       = open(filename, O_RDWR);

    if(fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Move to the beginning of the file
    if(lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Moved to the beginning of the file.\n");

    // Move to the end of the file
    if(lseek(fd, 0, SEEK_END) == -1)
    {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Moved to the end of the file.\n");

    if(close(fd) == -1)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
