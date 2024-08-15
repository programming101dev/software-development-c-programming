#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    do
    {
        int opt;

        opt = getopt(argc, argv, "ab:c");    // NOLINT(concurrency-mt-unsafe)

        if(opt == -1)
        {
            break;
        }

        switch(opt)
        {
            case 'a':
            {
                printf("Option -a\n");
                break;
            }
            case 'b':
            {
                printf("Option -b with value %s\n", optarg);
                break;
            }
            case 'c':
            {
                printf("Option -c\n");
                break;
            }
            default:
            {
                fprintf(stderr, "Usage: %s [-a] [-b value] [-c]\n", argv[0]);
                return EXIT_FAILURE;
            }
        }
    } while(1);

    return EXIT_SUCCESS;
}
