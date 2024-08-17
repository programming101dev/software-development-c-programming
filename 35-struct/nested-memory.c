#include <stdio.h>
#include <stdlib.h>

struct engine    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
};

struct car    // NOLINT(altera-struct-pack-align)
{
    const char    *make;
    const char    *model;
    struct engine *engine;
};

int main(void)
{
    struct car *car;

    car = malloc(sizeof(struct car));

    if(car == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    car->make   = "Toyota";
    car->model  = "Camry";
    car->engine = malloc(sizeof(struct engine));

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
    free(car->engine);
    free(car);

    return EXIT_SUCCESS;
}
