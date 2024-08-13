#include <stdio.h>
#include <time.h>
#include <locale.h>

int main(void) {
    setlocale(LC_TIME, "fr_FR.UTF-8");

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char buffer[80];

    strftime(buffer, 80, "%x %X", tm_info);
    printf("French locale date and time: %s\n", buffer);

    setlocale(LC_TIME, "en_US.UTF-8");
    strftime(buffer, 80, "%x %X", tm_info);
    printf("US locale date and time: %s\n", buffer);

    return 0;
}
