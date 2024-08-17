#include <stdio.h>
#include <stdlib.h>

enum Day
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(void)
{
    enum Day day;

    day = WEDNESDAY;

    switch(day)
    {
        case MONDAY:
        {
            printf("Monday\n");
            break;
        }
        case TUESDAY:
        {
            printf("Tuesday\n");
            break;
        }
        case WEDNESDAY:
        {
            printf("Wednesday\n");
            break;
        }
        case THURSDAY:
        {
            printf("Thursday\n");
            break;
        }
        case FRIDAY:
        {
            printf("Friday\n");
            break;
        }
        case SATURDAY:
        {
            printf("Saturday\n");
            break;
        }
        case SUNDAY:
        {
            printf("Sunday\n");
            break;
        }
        default:
        {
            printf("Invalid day\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
