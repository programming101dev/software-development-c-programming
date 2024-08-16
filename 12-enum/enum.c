#include <stdio.h>
#include <stdlib.h>

enum weekday
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main(void)
{
    printf("SUNDAY: %d\n", SUNDAY);
    printf("MONDAY: %d\n", MONDAY);
    printf("TUESDAY: %d\n", TUESDAY);
    printf("WEDNESDAY: %d\n", WEDNESDAY);
    printf("THURSDAY: %d\n", THURSDAY);
    printf("FRIDAY: %d\n", FRIDAY);
    printf("SATURDAY: %d\n", SATURDAY);

    return EXIT_SUCCESS;
}
