#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    const char *mb_str = "こんにちは"; // "Hello" in Japanese (UTF-8)
    wchar_t wc_str[100];
    mbstowcs(wc_str, mb_str, 100);

    wprintf(L"Wide character string: %ls\n", wc_str);

    char mb_str2[100];
    wcstombs(mb_str2, wc_str, 100);

    printf("Multibyte character string: %s\n", mb_str2);

    return 0;
}
