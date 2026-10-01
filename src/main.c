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

    // BigInt *number = bigint_from_string("");

    // if ( number == NULL ) {
    //     printf("Invalid number\n");
    //     return 1;
    // }

    // printf("Size: %d\n", number->size);
    // printf("Capacity: %d\n", number->capacity);
    // printf("Sign: %d\n", number->sign);
    // printf("Digits: ");

    // for ( int i = 0; i < number->size; i++ ) {
    //     printf("%d ", number->digits[i]);
    // }
    // printf("\n");
    // bigint_print(number);
    // bigint_free(number);

    BigInt *number1 = bigint_from_string("-100");
    BigInt *number2 = bigint_from_string("20");

    if ( number1 == NULL || number2 == NULL ) {
        printf("Failed to create BigInt\n");
        bigint_free(number1);
        bigint_free(number2);
        return 1;
    }

    int result = bigint_compare(number1, number2);
    if ( result > 0 ) {
        printf ( "number1 is greater than number2\n");
    }
    else if (result < 0) {
        printf("number1 is less than number2\n");
    } else {
        printf("number1 is equal to number2\n");
    }
    bigint_free(number1);
    bigint_free(number2);
    return 0;
}