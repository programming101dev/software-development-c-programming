#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_temp_directory(char *buffer) {
    const char *tmp_dir = getenv("TMP");
    if (tmp_dir == NULL) {
        tmp_dir = getenv("TEMP");
    }
    if (tmp_dir == NULL) {
#ifdef _WIN32
        tmp_dir = "C:\\Windows\\Temp";
#else
        tmp_dir = "/tmp";
#endif
    }
    strcpy(buffer, tmp_dir);
}

void get_user_directory(char *buffer) {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        home_dir = getenv("USERPROFILE");
    }
    if (home_dir == NULL) {
#ifdef _WIN32
        home_dir = "C:\\Users\\Default";
#else
        home_dir = "/home/default";
#endif
    }
    strcpy(buffer, home_dir);
}

int main(void) {
    char tmp_dir[256];
    char user_dir[256];

    get_temp_directory(tmp_dir);
    printf("Temporary Directory: %s\n", tmp_dir);

    get_user_directory(user_dir);
    printf("User Directory: %s\n", user_dir);

    return 0;
}
