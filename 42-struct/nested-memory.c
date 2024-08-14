#include <stdio.h>
#include <stdlib.h>

struct Engine    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
};

struct Car    // NOLINT(altera-struct-pack-align)
{
    const char    *make;
    const char    *model;
    struct Engine *engine;    // Pointer to an Engine struct
};

int main(void)
{
    struct Car *car;

    car = malloc(sizeof(struct Car));

    if(car == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    car->make   = "Toyota";
    car->model  = "Camry";
    car->engine = malloc(sizeof(struct Engine));

    if(car->engine == NULL)
    {
        fprintf(stderr, "Memory allocation for engine failed\n");
        free(car);
        return EXIT_FAILURE;
    }

    car->engine->horsepower   = 200;
    car->engine->displacement = 2.5F;

    printf("Car Make: %s, Model: %s\n", car->make, car->model);
    printf("Engine Horsepower: %d, Displacement: %.1fL\n", car->engine->horsepower, (double)car->engine->displacement);

    // Free allocated memory
    free(car->engine);
    free(car);

    return 0;
}
