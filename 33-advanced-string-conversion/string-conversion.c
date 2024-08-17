#include "string-conversion.h"
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

static intmax_t string_to_intmax(const char * restrict nptr, char ** restrict endptr, int base, int *error, intmax_t min, intmax_t max)
{
    intmax_t result;

    errno  = 0;
    result = strtoimax(nptr, endptr, base);

    if(errno == ERANGE || result > max || result < min)
    {
        *error = ERANGE;
    }
    else if(errno != 0)
    {
        *error = errno;
    }
    else if(*endptr == nptr || **endptr != '\0')
    {
        *error = EINVAL;
    }
    else
    {
        *error = 0;
    }
    return result;
}

static uintmax_t string_to_uintmax(const char * restrict nptr, char ** restrict endptr, int base, int *error, uintmax_t max)
{
    uintmax_t result;

    errno  = 0;
    result = strtoumax(nptr, endptr, base);
    if(errno == ERANGE || result > max)
    {
        *error = ERANGE;
    }
    else if(errno != 0)
    {
        *error = errno;
    }
    else if(*endptr == nptr || **endptr != '\0')
    {
        *error = EINVAL;
    }
    else
    {
        *error = 0;
    }

    return result;
}

int string_to_int(const char * restrict str, int base, int *error)
{
    intmax_t result;
    char    *endptr;

    result = string_to_intmax(str, &endptr, base, error, INT_MIN, INT_MAX);

    if(*error)
    {
        return 0;
    }

    return (int)result;
}

long string_to_long(const char * restrict str, int base, int *error)
{
    intmax_t result;
    char    *endptr;

    result = string_to_intmax(str, &endptr, base, error, LONG_MIN, LONG_MAX);

    if(*error)
    {
        return 0;
    }

    return (long)result;
}

long long string_to_long_long(const char * restrict str, int base, int *error)
{
    intmax_t result;
    char    *endptr;

    result = string_to_intmax(str, &endptr, base, error, LLONG_MIN, LLONG_MAX);

    if(*error)
    {
        return 0;
    }

    return (long long)result;
}

unsigned int string_to_unsigned_int(const char * restrict str, int base, int *error)
{
    uintmax_t result;
    char     *endptr;

    result = string_to_uintmax(str, &endptr, base, error, UINT_MAX);

    if(*error)
    {
        return 0;
    }

    return (unsigned int)result;
}

unsigned long string_to_unsigned_long(const char * restrict str, int base, int *error)
{
    uintmax_t result;
    char     *endptr;

    result = string_to_uintmax(str, &endptr, base, error, ULONG_MAX);

    if(*error)
    {
        return 0;
    }

    return (unsigned long)result;
}

unsigned long long string_to_unsigned_long_long(const char * restrict str, int base, int *error)
{
    uintmax_t result;
    char     *endptr;

    result = string_to_uintmax(str, &endptr, base, error, ULLONG_MAX);

    if(*error)
    {
        return 0;
    }

    return (unsigned long long)result;
}

float string_to_float(const char * restrict str, int *error)
{
    char *endptr;
    float result;

    errno  = 0;
    result = strtof(str, &endptr);

    if(errno == ERANGE || *endptr != '\0')
    {
        *error = ERANGE;
        return 0;
    }
    if(errno == EINVAL)
    {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

double string_to_double(const char * restrict str, int *error)
{
    double result;
    char  *endptr;
    errno  = 0;
    result = strtod(str, &endptr);
    if(errno == ERANGE || *endptr != '\0')
    {
        *error = ERANGE;
        return 0;
    }
    if(errno == EINVAL)
    {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

long double string_to_long_double(const char * restrict str, int *error)
{
    long double result;
    char       *endptr;

    errno  = 0;
    result = strtold(str, &endptr);
    if(errno == ERANGE || *endptr != '\0')
    {
        *error = ERANGE;
        return 0;
    }
    if(errno == EINVAL)
    {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

char string_to_char(const char * restrict str, int base, int *error)
{
    char    *endptr;
    intmax_t result;

    result = string_to_intmax(str, &endptr, base, error, CHAR_MIN, CHAR_MAX);

    if(*error)
    {
        return 0;
    }

    return (char)result;
}

signed char string_to_signed_char(const char * restrict str, int base, int *error)
{
    char    *endptr;
    intmax_t result;

    result = string_to_intmax(str, &endptr, base, error, SCHAR_MIN, SCHAR_MAX);

    if(*error)
    {
        return 0;
    }
    return (signed char)result;
}

unsigned char string_to_unsigned_char(const char * restrict str, int base, int *error)
{
    char     *endptr;
    uintmax_t result;

    result = string_to_uintmax(str, &endptr, base, error, UCHAR_MAX);

    if(*error)
    {
        return 0;
    }
    return (unsigned char)result;
}

short string_to_short(const char * restrict str, int base, int *error)
{
    char    *endptr;
    intmax_t result;

    result = string_to_intmax(str, &endptr, base, error, SHRT_MIN, SHRT_MAX);

    if(*error)
    {
        return 0;
    }
    return (short)result;
}

unsigned short string_to_unsigned_short(const char * restrict str, int base, int *error)
{
    char     *endptr;
    uintmax_t result;

    result = string_to_uintmax(str, &endptr, base, error, USHRT_MAX);

    if(*error)
    {
        return 0;
    }
    return (unsigned short)result;
}
