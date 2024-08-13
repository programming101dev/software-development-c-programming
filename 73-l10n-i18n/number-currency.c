#include <stdio.h>
#include <locale.h>

void print_amount(double amount) {
    struct lconv *loc;
    char formatted_amount[50];

    // Set the locale to the user's default
    setlocale(LC_ALL, "");

    // Get the locale information
    loc = localeconv();

    // Format the amount according to the current locale
    snprintf(formatted_amount, sizeof(formatted_amount), "%.*f", loc->frac_digits, amount);

    // Print the currency symbol and formatted amount
    printf("Amount: %s%s\n", loc->currency_symbol, formatted_amount);
}

int main(void) {
    double amount = 12345.67;

    // Example: Print amount in the default locale
    print_amount(amount);

    // Example: Print amount in the French locale
    setlocale(LC_ALL, "fr_FR.UTF-8");
    print_amount(amount);

    // Example: Print amount in the German locale
    setlocale(LC_ALL, "de_DE.UTF-8");
    print_amount(amount);

    // Example: Print amount in the US locale
    setlocale(LC_ALL, "en_US.UTF-8");
    print_amount(amount);

    return 0;
}
