#include <stdio.h>
#include <stdlib.h>

static void function_one(void);
static void function_two(void);

static int         global_uninitialized_var;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
static int         global_initialized_var = 42;    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
static const char *global_const_string    = "Hello, World!";    // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

int main(void)
{
    const char *main_const_string = "Main String";
    int         main_uninitialized_var;
    int         main_initialized_var;
    int        *main_heap_var;

    main_initialized_var = 100;
    main_heap_var        = malloc(sizeof(int));
    *main_heap_var       = 123;
    printf("Address        | Name                       | Value\n");
    printf("-----------------------------------------------------------\n");
    printf("0x%012lx | global_uninitialized_var   | Uninitialized\n", (unsigned long)&global_uninitialized_var);
    printf("0x%012lx | global_initialized_var     | %d\n", (unsigned long)&global_initialized_var, global_initialized_var);
    printf("0x%012lx | global_const_string        | %s\n", (unsigned long)&global_const_string, global_const_string);
    printf("0x%012lx | main_uninitialized_var     | Uninitialized\n", (unsigned long)&main_uninitialized_var);
    printf("0x%012lx | main_initialized_var       | %d\n", (unsigned long)&main_initialized_var, main_initialized_var);
    printf("0x%012lx | main_const_string          | %s\n", (unsigned long)&main_const_string, main_const_string);
    printf("0x%012lx |                            | %d (Heap)\n", (unsigned long)main_heap_var, *main_heap_var);
    printf("0x%012lx | main function              | \n", (unsigned long)&main);
    printf("0x%012lx | function_one               | \n", (unsigned long)&function_one);
    printf("0x%012lx | function_two               | \n", (unsigned long)&function_two);
    function_one();
    free(main_heap_var);

    return EXIT_SUCCESS;
}

void function_one(void)
{
    const char *func_one_const_string = "One String";
    int         func_one_uninitialized_var;
    int         func_one_initialized_var;
    static int  func_one_static_var = 400;
    int        *func_one_heap_var;

    func_one_initialized_var = 300;
    func_one_heap_var        = malloc(sizeof(int));
    *func_one_heap_var       = 456;
    printf("0x%012lx | func_one_uninitialized_var | Uninitialized\n", (unsigned long)&func_one_uninitialized_var);
    printf("0x%012lx | func_one_initialized_var   | %d\n", (unsigned long)&func_one_initialized_var, func_one_initialized_var);
    printf("0x%012lx | func_one_static_var        | %d\n", (unsigned long)&func_one_static_var, func_one_static_var);
    printf("0x%012lx | func_one_const_string      | %s\n", (unsigned long)&func_one_const_string, func_one_const_string);
    printf("0x%012lx |                            | %d (Heap)\n", (unsigned long)func_one_heap_var, *func_one_heap_var);
    function_two();
    free(func_one_heap_var);
}

void function_two(void)
{
    const char *func_two_const_string = "Two String";
    int         func_two_uninitialized_var;
    int         func_two_initialized_var;
    static int  func_two_static_var = 600;
    int        *func_two_heap_var;

    func_two_initialized_var = 500;
    func_two_heap_var        = malloc(sizeof(int));
    *func_two_heap_var       = 789;
    printf("0x%012lx | func_two_uninitialized_var | Uninitialized\n", (unsigned long)&func_two_uninitialized_var);
    printf("0x%012lx | func_two_initialized_var   | %d\n", (unsigned long)&func_two_initialized_var, func_two_initialized_var);
    printf("0x%012lx | func_two_static_var        | %d\n", (unsigned long)&func_two_static_var, func_two_static_var);
    printf("0x%012lx | func_two_const_string      | %s\n", (unsigned long)&func_two_const_string, func_two_const_string);
    printf("0x%012lx |                            | %d (Heap)\n", (unsigned long)func_two_heap_var, *func_two_heap_var);
    free(func_two_heap_var);
}
