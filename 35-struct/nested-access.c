#include <stdio.h>
#include <stdlib.h>

struct engine    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
};

struct car    // NOLINT(altera-struct-pack-align)
{
    const char   *make;
    const char   *model;
    struct engine engine;
};

int main(void)
{
    struct car car = {
        "Toyota",
        "Camry",
        {200, 2.5F}
    };

    printf("Car Make: %s, Model: %s\n", car.make, car.model);
    printf("Engine Horsepower: %d, Displacement: %.1fL\n", car.engine.horsepower, (double)car.engine.displacement);

    car.engine.horsepower = 250;
    printf("Updated Engine Horsepower: %d\n", car.engine.horsepower);

    return EXIT_SUCCESS;
}
