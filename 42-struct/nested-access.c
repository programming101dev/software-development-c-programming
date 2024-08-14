#include <stdio.h>

struct Engine    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
};

struct Car    // NOLINT(altera-struct-pack-align)
{
    const char   *make;
    const char   *model;
    struct Engine engine;
};

int main(void)
{
    struct Car car = {
        "Toyota",
        "Camry",
        {200, 2.5F}
    };

    printf("Car Make: %s, Model: %s\n", car.make, car.model);
    printf("Engine Horsepower: %d, Displacement: %.1fL\n", car.engine.horsepower, (double)car.engine.displacement);

    // Accessing and modifying nested struct members
    car.engine.horsepower = 250;
    printf("Updated Engine Horsepower: %d\n", car.engine.horsepower);

    return 0;
}
