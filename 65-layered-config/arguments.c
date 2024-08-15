#include "arguments.h"
#include "config.h"
#include "string-conversion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int handle_arguments(int argc, char *argv[], char **message, int **count, int **delay)
{
    do
    {
        int opt;

        opt = getopt(argc, argv, "hn:d:");    // NOLINT(concurrency-mt-unsafe)

        if(opt == -1)
        {
            break;
        }

        switch(opt)
        {
            case 'h':
                return 1;    // Return 1 to indicate that help should be displayed
            case 'n':
            {
                static int arg_count;
                int        error = 0;
                arg_count        = string_to_int(optarg, 10, &error);
                if(error || arg_count > MAX_COUNT)
                {
                    arg_count = DEFAULT_COUNT;
                }
                *count = &arg_count;
                break;
            }
            case 'd':
            {
                static int arg_delay;
                int        error = 0;
                arg_delay        = string_to_int(optarg, 10, &error);
                if(error || arg_delay > MAX_DELAY)
                {
                    arg_delay = DEFAULT_DELAY;
                }
                *delay = &arg_delay;
                break;
            }
            default:
                return -1;    // Return -1 to indicate an error in argument parsing
        }
    } while(1);

    if(optind < argc)
    {
        if(*message == NULL)
        {
            *message = strdup(argv[optind]);
        }
        else
        {
            return -2;    // Return -2 to indicate a conflict in message specification
        }
    }

    if(optind + 1 < argc)
    {
        return -3;    // Return -3 to indicate too many arguments
    }

    return 0;    // Return 0 to indicate success
}
