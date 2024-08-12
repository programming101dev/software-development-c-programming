#include "string_conversions.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>  // For strtoimax and strtoumax

// Centralized conversion functions for signed and unsigned types
static intmax_t string_to_intmax(const char *restrict nptr, char **restrict endptr, int base, int *error, intmax_t min, intmax_t max) {
    errno = 0;
    intmax_t result = strtoimax(nptr, endptr, base);
    if (errno == ERANGE || result > max || result < min) {
        *error = ERANGE;
    } else if (errno != 0) {
        *error = errno;
    } else if (*endptr == nptr || **endptr != '\0') {
        *error = EINVAL;
    } else {
        *error = 0;
    }
    return result;
}

static uintmax_t string_to_uintmax(const char *restrict nptr, char **restrict endptr, int base, int *error, uintmax_t max) {
    errno = 0;
    uintmax_t result = strtoumax(nptr, endptr, base);
    if (errno == ERANGE || result > max) {
        *error = ERANGE;
    } else if (errno != 0) {
        *error = errno;
    } else if (*endptr == nptr || **endptr != '\0') {
        *error = EINVAL;
    } else {
        *error = 0;
    }
    return result;
}

// Conversion functions for standard types
int string_to_int(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, INT_MIN, INT_MAX);
    if (*error) {
        return 0;
    }
    return (int)result;
}

long string_to_long(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, LONG_MIN, LONG_MAX);
    if (*error) {
        return 0;
    }
    return (long)result;
}

long long string_to_long_long(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, LLONG_MIN, LLONG_MAX);
    if (*error) {
        return 0;
    }
    return (long long)result;
}

unsigned int string_to_unsigned_int(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UINT_MAX);
    if (*error) {
        return 0;
    }
    return (unsigned int)result;
}

unsigned long string_to_unsigned_long(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, ULONG_MAX);
    if (*error) {
        return 0;
    }
    return (unsigned long)result;
}

unsigned long long string_to_unsigned_long_long(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, ULLONG_MAX);
    if (*error) {
        return 0;
    }
    return (unsigned long long)result;
}

float string_to_float(const char *restrict str, int *error) {
    char *endptr;
    errno = 0;
    float result = strtof(str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        *error = ERANGE;
        return 0;
    }
    if (errno == EINVAL) {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

double string_to_double(const char *restrict str, int *error) {
    char *endptr;
    errno = 0;
    double result = strtod(str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        *error = ERANGE;
        return 0;
    }
    if (errno == EINVAL) {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

long double string_to_long_double(const char *restrict str, int *error) {
    char *endptr;
    errno = 0;
    long double result = strtold(str, &endptr);
    if (errno == ERANGE || *endptr != '\0') {
        *error = ERANGE;
        return 0;
    }
    if (errno == EINVAL) {
        *error = EINVAL;
        return 0;
    }
    *error = 0;
    return result;
}

// Conversion functions for char types
char string_to_char(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, CHAR_MIN, CHAR_MAX);
    if (*error) {
        return 0;
    }
    return (char)result;
}

signed char string_to_signed_char(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, SCHAR_MIN, SCHAR_MAX);
    if (*error) {
        return 0;
    }
    return (signed char)result;
}

unsigned char string_to_unsigned_char(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UCHAR_MAX);
    if (*error) {
        return 0;
    }
    return (unsigned char)result;
}

// Conversion functions for short types
short string_to_short(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, SHRT_MIN, SHRT_MAX);
    if (*error) {
        return 0;
    }
    return (short)result;
}

unsigned short string_to_unsigned_short(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, USHRT_MAX);
    if (*error) {
        return 0;
    }
    return (unsigned short)result;
}

// Conversion functions for fixed-width integer types
int8_t string_to_int8(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, INT8_MIN, INT8_MAX);
    if (*error) {
        return 0;
    }
    return (int8_t)result;
}

uint8_t string_to_uint8(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UINT8_MAX);
    if (*error) {
        return 0;
    }
    return (uint8_t)result;
}

int16_t string_to_int16(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, INT16_MIN, INT16_MAX);
    if (*error) {
        return 0;
    }
    return (int16_t)result;
}

uint16_t string_to_uint16(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UINT16_MAX);
    if (*error) {
        return 0;
    }
    return (uint16_t)result;
}

int32_t string_to_int32(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, INT32_MIN, INT32_MAX);
    if (*error) {
        return 0;
    }
    return (int32_t)result;
}

uint32_t string_to_uint32(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UINT32_MAX);
    if (*error) {
        return 0;
    }
    return (uint32_t)result;
}

int64_t string_to_int64(const char *restrict str, int base, int *error) {
    char *endptr;
    intmax_t result = string_to_intmax(str, &endptr, base, error, INT64_MIN, INT64_MAX);
    if (*error) {
        return 0;
    }
    return (int64_t)result;
}

uint64_t string_to_uint64(const char *restrict str, int base, int *error) {
    char *endptr;
    uintmax_t result = string_to_uintmax(str, &endptr, base, error, UINT64_MAX);
    if (*error) {
        return 0;
    }
    return (uint64_t)result;
}
