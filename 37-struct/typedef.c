#include <stdio.h>
#include <stdlib.h>

typedef struct    // NOLINT(altera-struct-pack-align)
{
    int   horsepower;
    float displacement;
} engine;

typedef struct    // NOLINT(altera-struct-pack-align)
{
    const char *make;
    const char *model;
    engine     *engine;
} car;

int main(void)
{
    car *c;

    c = malloc(sizeof(car));
    if(c == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    c->make   = "Toyota";
    c->model  = "Camry";
    c->engine = malloc(sizeof(engine));
    if(c->engine == NULL)
    {
        fprintf(stderr, "Memory allocation for engine failed\n");
        free(c);
        return EXIT_FAILURE;
    }

    c->engine->horsepower   = 200;
    c->engine->displacement = 2.5F;

    printf("Car Make: %s, Model: %s\n", c->make, c->model);
    printf("Engine Horsepower: %d, Displacement: %.1fL\n", c->engine->horsepower, (double)c->engine->displacement);

    free(c->engine);
    free(c);

    return EXIT_SUCCESS;
}
