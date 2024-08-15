#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_FILE "config.txt"
#define DEFAULT_COUNT 1
#define DEFAULT_DELAY 0
#define MAX_COUNT 100
#define MAX_DELAY 10

void handle_config(char **message, int **count, int **delay);

#endif    // CONFIG_H
