#include <stdio.h>
#include <stdlib.h>

typedef struct    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
} Engine;

typedef struct    // NOLINT(altera-struct-pack-align)
{
    const char *make;
    const char *model;
    Engine     *engine;    // Pointer to an Engine struct
} Car;

int main(void)
{
    Car *car;

    car = malloc(sizeof(Car));    // No need to use 'struct' keyword
    if(car == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    car->make   = "Toyota";
    car->model  = "Camry";
    car->engine = malloc(sizeof(Engine));
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

    return EXIT_SUCCESS;
}
