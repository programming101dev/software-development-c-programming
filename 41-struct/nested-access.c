#include <stdio.h>

struct Engine {
    int horsepower;
    float displacement;
};

struct Car {
    char *make;
    char *model;
    struct Engine engine;
};

int main(void) {
    struct Car car = {"Toyota", "Camry", {200, 2.5}};

    printf("Car Make: %s, Model: %s\n", car.make, car.model);
    printf("Engine Horsepower: %d, Displacement: %.1fL\n", car.engine.horsepower, car.engine.displacement);

    // Accessing and modifying nested struct members
    car.engine.horsepower = 250;
    printf("Updated Engine Horsepower: %d\n", car.engine.horsepower);

    return 0;
}
