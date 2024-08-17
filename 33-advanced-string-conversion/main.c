#include "string-conversion.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_int_conversion(const char *str, int base);
static void print_unsigned_conversion(const char *str, int base);
static void print_char_conversion(const char *str, int base);
static void print_short_conversion(const char *str, int base);
static void print_float_conversion(const char *str);
static void print_double_conversion(const char *str);
static void print_long_double_conversion(const char *str);

static void print_conversion_result(const char *str, int base)
{
    print_int_conversion(str, base);
    print_unsigned_conversion(str, base);
    print_char_conversion(str, base);
    print_short_conversion(str, base);
    print_float_conversion(str);
    print_double_conversion(str);
    print_long_double_conversion(str);
}

static void print_int_conversion(const char *str, int base)
{
    int       error;
    int       int_result;
    long      long_result;
    long long long_long_result;

    error      = 0;
    int_result = string_to_int(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to int: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to int: %d\n", str, int_result);
    }

    error       = 0;
    long_result = string_to_long(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to long: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to long: %ld\n", str, long_result);
    }

    error            = 0;
    long_long_result = string_to_long_long(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to long long: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to long long: %lld\n", str, long_long_result);
    }
}

static void print_unsigned_conversion(const char *str, int base)
{
    int                error;
    unsigned int       uint_result;
    unsigned long      ulong_result;
    unsigned long long ulong_long_result;

    error       = 0;
    uint_result = string_to_unsigned_int(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to unsigned int: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to unsigned int: %u\n", str, uint_result);
    }

    error        = 0;
    ulong_result = string_to_unsigned_long(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to unsigned long: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to unsigned long: %lu\n", str, ulong_result);
    }

    error             = 0;
    ulong_long_result = string_to_unsigned_long_long(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to unsigned long long: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to unsigned long long: %llu\n", str, ulong_long_result);
    }
}

static void print_char_conversion(const char *str, int base)
{
    int           error;
    char          char_result;
    signed char   schar_result;
    unsigned char uchar_result;

    error       = 0;
    char_result = string_to_char(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to char: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to char: %c\n", str, char_result);
    }

    error        = 0;
    schar_result = string_to_signed_char(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to signed char: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to signed char: %c\n", str, schar_result);
    }

    error        = 0;
    uchar_result = string_to_unsigned_char(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to unsigned char: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to unsigned char: %c\n", str, uchar_result);
    }
}

static void print_short_conversion(const char *str, int base)
{
    int            error;
    short          short_result;
    unsigned short ushort_result;

    error        = 0;
    short_result = string_to_short(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to short: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to short: %d\n", str, short_result);
    }

    error         = 0;
    ushort_result = string_to_unsigned_short(str, base, &error);

    if(error)
    {
        printf("Error converting \"%s\" to unsigned short: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to unsigned short: %u\n", str, ushort_result);
    }
}

static void print_float_conversion(const char *str)
{
    int   error;
    float float_result;

    error        = 0;
    float_result = string_to_float(str, &error);

    if(error)
    {
        printf("Error converting \"%s\" to float: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to float: %f\n", str, (double)float_result);
    }
}

static void print_double_conversion(const char *str)
{
    int    error;
    double double_result;

    error         = 0;
    double_result = string_to_double(str, &error);

    if(error)
    {
        printf("Error converting \"%s\" to double: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to double: %f\n", str, double_result);
    }
}

static void print_long_double_conversion(const char *str)
{
    int         error;
    long double long_double_result;

    error              = 0;
    long_double_result = string_to_long_double(str, &error);

    if(error)
    {
        printf("Error converting \"%s\" to long double: %d\n", str, error);
    }
    else
    {
        printf("Converted \"%s\" to long double: %Lf\n", str, long_double_result);
    }
}

int main(void)
{
    const char  *test_cases[] = {"", "123", "ABC", "123abc"};
    const size_t size         = sizeof(test_cases) / sizeof(test_cases[0]);

    for(size_t i = 0; i < size; i++)
    {
        print_conversion_result(test_cases[i], 10);
    }

    return EXIT_SUCCESS;
}
