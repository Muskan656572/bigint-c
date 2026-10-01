#include <stdio.h>
#include "bigint.h"

int main(void)
{
    // BigInt *number = bigint_create();

    // if (number == NULL) {
    //     printf("Failed to create BigInt\n");
    //     return 1;
    // }

    // printf("BigInt created successfully!\n");
    // printf("Size: %d\n", number->size);
    // printf("Capacity: %d\n", number->capacity);
    // printf("Sign: %d\n", number->sign);
    // printf("First digit: %d\n", number->digits[0]);

    BigInt *number = bigint_from_string("");

    if ( number == NULL ) {
        printf("Invalid number\n");
        return 1;
    }

    printf("Size: %d\n", number->size);
    printf("Capacity: %d\n", number->capacity);
    printf("Sign: %d\n", number->sign);
    printf("Digits: ");

    // for ( int i = 0; i < number->size; i++ ) {
    //     printf("%d ", number->digits[i]);
    // }
    // printf("\n");
    bigint_print(number);
    bigint_free(number);

    return 0;
}