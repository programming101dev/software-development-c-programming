#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    int8_t i8 = -128;
    uint8_t u8 = 255;
    int16_t i16 = -32768;
    uint16_t u16 = 65535;
    int32_t i32 = -2147483647;
    uint32_t u32 = 4294967295U;
    int64_t i64 = -9223372036854775807LL;
    uint64_t u64 = 18446744073709551615ULL;

    int_fast8_t f8 = -128;
    uint_fast8_t uf8 = 255;
    int_fast16_t f16 = -32768;
    uint_fast16_t uf16 = 65535;
    int_fast32_t f32 = -2147483647;
    uint_fast32_t uf32 = 4294967295U;
    int_fast64_t f64 = -9223372036854775807LL;
    uint_fast64_t uf64 = 18446744073709551615ULL;

    int_least8_t l8 = -128;
    uint_least8_t ul8 = 255;
    int_least16_t l16 = -32768;
    uint_least16_t ul16 = 65535;
    int_least32_t l32 = -2147483647;
    uint_least32_t ul32 = 4294967295U;
    int_least64_t l64 = -9223372036854775807LL;
    uint_least64_t ul64 = 18446744073709551615ULL;

    intmax_t imax = INTMAX_MAX;
    uintmax_t umax = UINTMAX_MAX;

    intptr_t iptr = (intptr_t)&i32;
    uintptr_t uptr = (uintptr_t)&i32;

    printf("int8_t: %" PRId8 "\n", i8);
    printf("uint8_t: %" PRIu8 "\n", u8);
    printf("int16_t: %" PRId16 "\n", i16);
    printf("uint16_t: %" PRIu16 "\n", u16);
    printf("int32_t: %" PRId32 "\n", i32);
    printf("uint32_t: %" PRIu32 "\n", u32);
    printf("int64_t: %" PRId64 "\n", i64);
    printf("uint64_t: %" PRIu64 "\n", u64);

    printf("int_fast8_t: %" PRIdFAST8 "\n", f8);
    printf("uint_fast8_t: %" PRIuFAST8 "\n", uf8);
    printf("int_fast16_t: %" PRIdFAST16 "\n", f16);
    printf("uint_fast16_t: %" PRIuFAST16 "\n", uf16);
    printf("int_fast32_t: %" PRIdFAST32 "\n", f32);
    printf("uint_fast32_t: %" PRIuFAST32 "\n", uf32);
    printf("int_fast64_t: %" PRIdFAST64 "\n", f64);
    printf("uint_fast64_t: %" PRIuFAST64 "\n", uf64);

    printf("int_least8_t: %" PRIdLEAST8 "\n", l8);
    printf("uint_least8_t: %" PRIuLEAST8 "\n", ul8);
    printf("int_least16_t: %" PRIdLEAST16 "\n", l16);
    printf("uint_least16_t: %" PRIuLEAST16 "\n", ul16);
    printf("int_least32_t: %" PRIdLEAST32 "\n", l32);
    printf("uint_least32_t: %" PRIuLEAST32 "\n", ul32);
    printf("int_least64_t: %" PRIdLEAST64 "\n", l64);
    printf("uint_least64_t: %" PRIuLEAST64 "\n", ul64);

    printf("intmax_t: %" PRIdMAX "\n", imax);
    printf("uintmax_t: %" PRIuMAX "\n", umax);

    printf("intptr_t: %" PRIdPTR "\n", iptr);
    printf("uintptr_t: %" PRIuPTR "\n", uptr);

    return EXIT_SUCCESS;
}
