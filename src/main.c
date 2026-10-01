#include <stdio.h>
#include "bigint.h"

int main(void)
{
    BigInt *number = bigint_create();

    if (number == NULL) {
        printf("Failed to create BigInt\n");
        return 1;
    }

    printf("BigInt created successfully!\n");
    printf("Size: %d\n", number->size);
    printf("Capacity: %d\n", number->capacity);
    printf("Sign: %d\n", number->sign);
    printf("First digit: %d\n", number->digits[0]);

    bigint_free(number);

    return 0;
}