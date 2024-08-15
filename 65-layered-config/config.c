#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int string_to_int(const char * restrict str, int base, int *error);

void handle_config(char **message, int **count, int **delay)
{
    FILE *file = fopen(CONFIG_FILE, "r");
    char  line[256];

    if(!file)
    {
        return;
    }

    while(fgets(line, sizeof(line), file))
    {
        if(strncmp(line, "MESSAGE=", 8) == 0 && *message == NULL)
        {
            *message = strdup(line + 8);
            if(*message != NULL)    // Check if strdup succeeded
            {
                (*message)[strcspn(*message, "\n")] = '\0';
            }
        }
        else if(strncmp(line, "COUNT=", 6) == 0 && *count == NULL)
        {
            static int config_count;
            int        error = 0;
            config_count     = string_to_int(line + 6, 10, &error);
            if(error || config_count > MAX_COUNT)
            {
                config_count = DEFAULT_COUNT;
            }
            *count = &config_count;
        }
        else if(strncmp(line, "DELAY=", 6) == 0 && *delay == NULL)
        {
            static int config_delay;
            int        error = 0;
            config_delay     = string_to_int(line + 6, 10, &error);
            if(error || config_delay > MAX_DELAY)
            {
                config_delay = DEFAULT_DELAY;
            }
            *delay = &config_delay;
        }
    }

    fclose(file);
}
