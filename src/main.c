#include <stdio.h>
#include "bigint.h"

int main(void)
{

    //  memory allocation to BigInt structure in heap

    // BigInt *number = bigint_create();

    // if (number == NULL) {
    //     printf("Failed to create BigInt\n");
    //     return 1;
    // }

    // printf("BigInt created successfully!\n");
    // printf("Size: %d\n", number->size);
    // printf("Capacity: %d\n", number->capacity);
    // printf("Sign: %d\n", number->sign);
    // printf("First digit: %d\n", number->digits[0]);.

// ----------------------------------------------------------------------

    // create BigInt from string and also free the space of that

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

// --------------------------------------------------------------------------------

    //  Compare 2 BigInt numbers

    // BigInt *number1 = bigint_from_string("-100");
    // BigInt *number2 = bigint_from_string("20");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // int result = bigint_compare(number1, number2);
    // if ( result > 0 ) {
    //     printf ( "number1 is greater than number2\n");
    // }
    // else if (result < 0) {
    //     printf("number1 is less than number2\n");
    // } else {
    //     printf("number1 is equal to number2\n");
    // }
    // bigint_free(number1);
    // bigint_free(number2);

// --------------------------------------------------------------------------------------------

    // .Addition of 2 BigInt Numbers:

    // BigInt *number1 = bigint_from_string("999999999999999999999999");
    // BigInt *number2 = bigint_from_string("1");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // BigInt *result = bigint_add(number1, number2);
    // if ( result == NULL ) {
    //     printf("Addition failed\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // printf("Number1 = ");
    // bigint_print(number1);
    // printf("\nNumber2 = ");
    // bigint_print(number2);
    // printf("\nNumber1 + number2 = ");
    // bigint_print(result);
    // printf("\n");
    // return 0;

// -------------------------------------------------------------------------------------------------------

    // Ṣubstraction of 2 BigInt Numbers:

    // BigInt *number1 = bigint_from_string("23");
    // BigInt *number2 = bigint_from_string("123");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // BigInt *result = bigint_substract(number1, number2);
    // if ( result == NULL ) {
    //     printf("Substraction failed\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // printf("Number1 = ");
    // bigint_print(number1);
    // printf("\nNumber2 = ");
    // bigint_print(number2);
    // printf("\nNumber1 - number2 = ");
    // bigint_print(result);
    // printf("\n");
    // return 0;

// Multiplication of 2 BigInt Numbers: 

    // BigInt *number1 = bigint_from_string("0");
    // BigInt *number2 = bigint_from_string("45");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // BigInt *result = bigint_multiply(number1, number2);
    // if ( result == NULL ) {
    //     printf("Multiplication failed\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // printf("Number1 = ");
    // bigint_print(number1);
    // printf("\nNumber2 = ");
    // bigint_print(number2);
    // printf("\nNumber1 * number2 = ");
    // bigint_print(result);
    // printf("\n");
    // return 0;

// ----------------------------------------------------------------------------------------------------------

    // Division of 2 BigInt Numbers:

    // BigInt *number1 = bigint_from_string("-100");
    // BigInt *number2 = bigint_from_string("7");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // BigInt *result = bigint_divide(number1, number2);
    // if ( result == NULL ) {
    //     printf("Division failed\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // printf("Number1 = ");
    // bigint_print(number1);
    // printf("\nNumber2 = ");
    // bigint_print(number2);
    // printf("\nNumber1 / number2 = ");
    // bigint_print(result);

// ----------------------------------------------------------------------------------------------------------------

    // Modulo of 2 BigInt Numbers:

    // BigInt *number1 = bigint_from_string("123456789123456789");
    // BigInt *number2 = bigint_from_string("12345");

    // if ( number1 == NULL || number2 == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // BigInt *result = bigint_modulo(number1, number2);
    // if ( result == NULL ) {
    //     printf("Modulo failed\n");
    //     bigint_free(number1);
    //     bigint_free(number2);
    //     return 1;
    // }

    // printf("Number1 = ");
    // bigint_print(number1);
    // printf("\nNumber2 = ");
    // bigint_print(number2);
    // printf("\nNumber1 %% Number2 = ");
    // bigint_print(result);

// -----------------------------------------------------------------------------------------------------------------

    // Power of a BigInt number:

    // BigInt *base = bigint_from_string("3");
    // if ( base == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     return 1;
    // }

    // BigInt *result = bigint_power(base, 0);

    // if ( result == NULL ) {
    //     printf("Power calculation failed\n");
    //     bigint_free(base);
    //     return 1;
    // }

    // printf("Base= ");
    // bigint_print(base);
    // printf("\nExponent= %d", 0);
    // printf("\nPower= ");
    // bigint_print(result);
    // printf("\n");

// ------------------------------------------------------------------------------------------------------------------

    // Factorial of a BigInt number:

    // BigInt *number = bigint_from_string("1");

    // if ( number == NULL ) {
    //     printf("Failed to create BigInt\n");
    //     return 1;
    // }
    // BigInt *factorial_output = bigint_factorial(number);

    // if ( factorial_output == NULL ) {
    //     printf("Factorial calculation failed\n");
    //     bigint_free(number);
    //     return 1;
    // }

    // printf("Number= ");
    // bigint_print(number);
    // printf("Factorial= ");
    // bigint_print(factorial_output);
    // printf("\n");
    // return 0;



//  complete menu

    int choice;

    while (1)
    {
        printf("\n========== BigInt Calculator ==========\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Modulo\n");
        printf("6. Power\n");
        printf("7. Factorial\n");
        printf("8. Compare\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char input1[100];
                char input2[100];

                printf("Enter first number: ");
                scanf("%99s", input1);

                printf("Enter second number: ");
                scanf("%99s", input2);

                BigInt *num1 = bigint_from_string(input1);
                BigInt *num2 = bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                BigInt *result = bigint_add(num1, num2);

                if (result == NULL)
                {
                    printf("Addition failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 2:
            {
                char input1[100];
                char input2[100];

                printf("Enter first number: ");
                scanf("%99s", input1);

                printf("Enter second number: ");
                scanf("%99s", input2);

                BigInt *num1 = bigint_from_string(input1);
                BigInt *num2 = bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                BigInt *result =
                    bigint_substract(num1, num2);

                if (result == NULL)
                {
                    printf("Subtraction failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 3:
            {
                char input1[100];
                char input2[100];

                printf("Enter first number: ");
                scanf("%99s", input1);

                printf("Enter second number: ");
                scanf("%99s", input2);

                BigInt *num1 = bigint_from_string(input1);
                BigInt *num2 = bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                BigInt *result =
                    bigint_multiply(num1, num2);

                if (result == NULL)
                {
                    printf("Multiplication failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 4:
            {
                char input1[100];
                char input2[100];

                printf("Enter dividend: ");
                scanf("%99s", input1);

                printf("Enter divisor: ");
                scanf("%99s", input2);

                BigInt *num1 = bigint_from_string(input1);
                BigInt *num2 = bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                BigInt *result =
                    bigint_divide(num1, num2);

                if (result == NULL)
                {
                    printf("Division failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 5:
            {
                char input1[100];
                char input2[100];

                printf("Enter first number: ");
                scanf("%99s", input1);

                printf("Enter second number: ");
                scanf("%99s", input2);

                BigInt *num1 = bigint_from_string(input1);
                BigInt *num2 = bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                BigInt *result =
                    bigint_modulo(num1, num2);

                if (result == NULL)
                {
                    printf("Modulo failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 6:
            {
                char input[100];
                int exponent;

                printf("Enter base: ");
                scanf("%99s", input);

                printf("Enter exponent: ");
                scanf("%d", &exponent);

                BigInt *base =
                    bigint_from_string(input);

                if (base == NULL)
                {
                    printf("Invalid base.\n");
                    break;
                }

                BigInt *result =
                    bigint_power(base, exponent);

                if (result == NULL)
                {
                    printf("Power failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(base);

                break;
            }

            case 7:
            {
                char input[100];

                printf("Enter number: ");
                scanf("%99s", input);

                BigInt *num =
                    bigint_from_string(input);

                if (num == NULL)
                {
                    printf("Invalid number.\n");
                    break;
                }

                BigInt *result =
                    bigint_factorial(num);

                if (result == NULL)
                {
                    printf("Factorial failed.\n");
                }
                else
                {
                    printf("Result = ");
                    bigint_print(result);
                    bigint_free(result);
                }

                bigint_free(num);

                break;
            }

            case 8:
            {
                char input1[100];
                char input2[100];

                printf("Enter first number: ");
                scanf("%99s", input1);

                printf("Enter second number: ");
                scanf("%99s", input2);

                BigInt *num1 =
                    bigint_from_string(input1);

                BigInt *num2 =
                    bigint_from_string(input2);

                if (num1 == NULL || num2 == NULL)
                {
                    printf("Invalid number.\n");
                    bigint_free(num1);
                    bigint_free(num2);
                    break;
                }

                int comparison =
                    bigint_compare(num1, num2);

                if (comparison > 0)
                {
                    printf("First number is greater.\n");
                }
                else if (comparison < 0)
                {
                    printf("Second number is greater.\n");
                }
                else
                {
                    printf("Both numbers are equal.\n");
                }

                bigint_free(num1);
                bigint_free(num2);

                break;
            }

            case 9:
            {
                printf("Goodbye!\n");
                return 0;
            }

            default:
            {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
