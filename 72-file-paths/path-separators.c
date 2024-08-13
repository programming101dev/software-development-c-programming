#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define PATH_SEPARATOR '\\'
#else
    #define PATH_SEPARATOR '/'
#endif

void construct_path(char *buffer, const char *dir, const char *file) {
    snprintf(buffer, 256, "%s%c%s", dir, PATH_SEPARATOR, file);
}

int main(void) {
    char path[256];
    char user_dir[256];

    get_user_directory(user_dir);
    construct_path(path, user_dir, "file.txt");
    printf("Constructed Path: %s\n", path);

    return 0;
}
