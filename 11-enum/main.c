#include <stdio.h>
#include <stdlib.h>

enum TrafficLight
{
    RED,
    YELLOW,
    GREEN
};

int main(void)
{
    enum TrafficLight light = YELLOW;

    switch (light) {
        case RED:
            printf("Stop\n");
        break;
        case YELLOW:
            printf("Caution\n");
        break;
        case GREEN:
            printf("Go\n");
        break;
        default:
            printf("Invalid light\n");
    }

    return EXIT_SUCCESS;
}
