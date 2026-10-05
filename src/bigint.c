#include "bigint.h"
#include <stdlib.h>
#include <stdio.h>

BigInt *bigint_create ( void ) {
    BigInt *num = malloc ( sizeof(BigInt));

    if ( num == NULL ) {
        return NULL;
    }

    num -> capacity = 10;
    num -> size = 1;
    num -> sign = 1;

    num -> digits = malloc ( num->capacity * sizeof(int));

    if(num->digits == NULL){
        free(num);
        return NULL;
    }
    num -> digits[0] = 0;
    return num;
}
void bigint_free ( BigInt *num ) 
{
    if ( num == NULL ) {
        return;
    }

    free(num->digits);
    free(num);
}

BigInt *bigint_from_string(const char *str) {
    
    if ( str == NULL || *str == '\0' ) {
        return NULL;
    }

    BigInt *num = bigint_create();

    if ( num == NULL ) {
        return NULL;
    }
    int start = 0;
    if ( str[0] == '-' ) {
        num->sign = -1;
        start = 1;
    }
    else if ( str[0] == '+' ) {
        start = 1;
    }
    // calculate length of string
    int length = 0;
    while ( str[start + length] != '\0' ) {
        if ( str[start + length] < '0' || str[start + length] > '9') {
            bigint_free(num);
            return NULL;
        }
        length++;
    }

    if ( length == 0 ) {
        bigint_free(num);
        return NULL;
    }

    // realloc the memory if length > num->capacity
    if ( length > num->capacity ) {
        int *new_digits = realloc(num->digits, length * sizeof(int));

        if ( new_digits == NULL ) {
            bigint_free(num);
            return NULL;
        }

        num->digits = new_digits;
        num->capacity = length;
    }

    num->size = length;

    // store actual digts in reverse order
    for ( int i = 0; i < length; i++ ) {
        num->digits[i] = str[start+length-i-1] - '0';
    }
    return num;
}

void bigint_print ( const BigInt *num ) {
    if ( num == NULL ) return;

    if ( num->sign == -1 ) {
        printf("-");
    }

    for ( int i = num->size-1; i >= 0; i-- ) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

int bigint_compare ( const BigInt *num1, const BigInt *num2 ) {

    if ( num1 == NULL || num2 == NULL ) return 0;
    
    // case1: different signs
    if ( num1->sign != num2->sign ) {
        if ( num1->sign == 1 ) return 1;
        else return -1;
    }

    // case2 : same sign (positives)
    if ( num1->sign == 1 ) {
        // firsty check their lengths difference
        if ( num1->size > num2->size ) return 1;
        if ( num1->size < num2->size ) return -1;
    }
    // (negatives)
    else{
        if ( num1->size < num2->size ) return 1;
        if ( num1->size > num2->size) return -1;
    }

    // case3: same lengths
    for ( int i = num1->size-1; i >= 0; i-- ) {
        if ( num1->digits[i] > num2->digits[i] ) {
            if ( num1->sign == 1 ) return 1;
            else return -1;
        }
        if ( num1->digits[i] < num2->digits[i] ) {
            if ( num2->sign == 1) return -1;
            else return 1;
        }
    }
    return 0;
    
}

static BigInt *bigint_add_abs ( const BigInt *num1, const BigInt *num2 ) {

    int maxsize;
    if ( num1->size > num2->size ) {
        maxsize = num1->size;
    }
    else { 
        maxsize = num2->size;
    }

    BigInt *result = bigint_create();
    if ( result == NULL ) return NULL;
    if ( maxsize + 1 > result->capacity ) {
        int *new_digits = realloc(result->digits, (maxsize + 1) * sizeof(int));

        if ( new_digits == NULL ) {
            bigint_free(result);
            return NULL;
        }
        result->digits = new_digits;
        result->capacity = maxsize+1;
    }

    int carry = 0;
    for (int i = 0; i < maxsize; i++) {

        int digit_num1 = 0;
        int digit_num2 = 0;

        if (i < num1->size)
            digit_num1 = num1->digits[i];

        if (i < num2->size)
            digit_num2 = num2->digits[i];

        int sum = digit_num1 + digit_num2 + carry;

        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    result->size = maxsize;
    if( carry > 0 ) {
        result->digits[result->size] = carry;
        result->size++;
    }
    result->sign = 1;
    return result;
}
static BigInt *bigint_sub_abs ( const BigInt *num1, const BigInt *num2 ) {
    
    BigInt *result = bigint_create();
    if ( result == NULL ) return NULL;

    if ( num1->size > result->capacity ) {
        int *new_digits = realloc(result->digits, (num1->size) * sizeof(int));
        if ( new_digits == NULL ) {
            bigint_free(result);
            return NULL;
        }
        result->digits = new_digits;
        result->capacity = num1->size;

    }

    int borrow = 0;
    for ( int i = 0; i < num1->size; i++ ) {
        int digit_num1 = num1->digits[i] - borrow;
        int digit_num2 = 0;
        if ( i < num2->size ) {
            digit_num2 = num2->digits[i];
        }
        if ( digit_num1 < digit_num2 ) {
            digit_num1 += 10;
            borrow = 1;
        }
        else borrow = 0;
        result->digits[i] = digit_num1 - digit_num2;
    }
    
    result->size = num1->size;
    while ( result->size > 1 && result->digits[result->size - 1] == 0 ) {
        result->size--;
    }

    result->sign = 1;
    return result;
}
static int bigint_compare_abs ( const BigInt *num1, const BigInt *num2 ) {
    if ( num1->size > num2->size ) return 1;
    if ( num1->size < num2->size ) return -1;

    for ( int i = num1->size - 1; i  >= 0; i-- ) {
        if ( num1->digits[i] > num2->digits[i]) return 1;
        if ( num1->digits[i] < num2->digits[i] ) return -1;
    }
    return 0;
}
BigInt *bigint_add ( const BigInt *num1, const BigInt *num2 ) {

    if ( num1 == NULL || num2 == NULL ) return NULL;
    
    // case1 : same sign
    if ( num1->sign == num2->sign ) {
        BigInt *result = bigint_add_abs(num1, num2);

        if ( result == NULL ) return NULL;
        result->sign = num1->sign;
        return result;
    }
    
    // case2 : different signs

    int comparison = bigint_compare_abs(num1, num2);

    // equal magnitude
    if ( comparison == 0 ) {
        BigInt *result = bigint_create();
        if( result == NULL ) return NULL;
        result->digits[0] = 0;
        result->size = 1;
        result->sign = 1;
        return result;

    }

    // |num1| > |num2|
    if ( comparison > 0 ) {
        BigInt *result = bigint_sub_abs(num1, num2);
        if ( result == NULL ) return NULL;
        result->sign = num1->sign;
        return result;
    }

    // |num2| > |num1|
    BigInt *result = bigint_sub_abs(num2, num1);
    if ( result == NULL ) return NULL;
    result->sign = num2->sign;
    return result;

}

BigInt *bigint_substract ( const BigInt *num1, const BigInt *num2 ) {
    if ( num1 == NULL || num2 == NULL ) return NULL;

    // case1: Different Signs
    if ( num1->sign != num2->sign ) {
        BigInt *result = bigint_add_abs(num1, num2);
        if ( result == NULL ) {
            return NULL;
        }
        result->sign = num1->sign;
        return result;
    } 

    // case2: Same signs

    int comparison = bigint_compare_abs(num1, num2);
    if ( comparison == 0 ) {
        BigInt *result = bigint_create();
        if ( result == NULL ) return NULL;
        result->digits[0] = 0;
        result->size = 1;
        result->sign = 1;
        return result;
    }

    // |num1| > |num2|

    if ( comparison > 0 ) {
        BigInt *result = bigint_sub_abs(num1, num2);
        if ( result == NULL ) return NULL;
        result->sign = num1->sign;
        return result;
    }

    // |num1| < |num2|
    BigInt *result = bigint_sub_abs(num2, num1);
    if ( result == NULL ) return NULL;
    result->sign = -num1->sign;
    return result;
}

BigInt *bigint_multiply ( const BigInt *num1, const BigInt *num2 ) {

    if ( num1 == NULL || num2 == NULL ) return NULL;
    BigInt *result = bigint_create();
    if ( result == NULL ) return NULL;

    int required_size = num1->size + num2->size;

    if ( required_size > result->capacity ) {
        int *new_digits = realloc(result->digits, required_size * sizeof(int));

        if ( new_digits == NULL ) {
            bigint_free(result);
            return NULL;
        }
        result->digits = new_digits;
        result->capacity = required_size;
    } 

    for ( int i = 0; i < required_size; i++ ) {
        result->digits[i] = 0;
    }

    for ( int i = 0; i < num1->size; i++ ) {
        int carry = 0;
        for ( int  j = 0; j < num2->size; j++ ) {
            int position = i + j ;
            int product = num1->digits[i] * num2->digits[j] + result->digits[position] + carry;
            result->digits[position] = product % 10;
            carry = product / 10;   
        }

        result->digits[i + num2->size] += carry;
    }
    result->size = required_size;

    while ( result->size > 1 && result->digits[result->size - 1] == 0 ) {
        result->size--;
    }

    result->sign = num1->sign * num2->sign;
    return result;

}

static BigInt *bigint_append_digit ( const BigInt *num, int digit ) {
    if ( num == NULL || digit < 0 || digit > 9 ) return NULL;
    BigInt *result = bigint_create();
    if ( result == NULL ) return NULL;

    if ( num->size + 1 > result->capacity ) {
        int new_capacity = num->size + 1;
        int *new_digits = realloc(result->digits, new_capacity * sizeof(int));

        if ( new_digits == NULL ) {
            bigint_free(result);
            return NULL;
        }
        result->digits = new_digits;
        result->capacity = new_capacity;
    }

    for ( int i = num->size - 1; i >= 0; i-- ) {
        result->digits[i + 1] = num->digits[i];
    }
    result->digits[0] = digit;
    result->size = num->size + 1;
    while (result->size > 1 &&
           result->digits[result->size - 1] == 0) {
        result->size--;
    }
    result->sign = num->sign;
    return result;
}

static BigInt *bigint_multiply_by_digit ( const BigInt *num, int digit ) {
    if ( num == NULL || digit < 0 || digit > 9 ) return NULL;
    BigInt *result = bigint_create();
    if ( result == NULL ) return NULL;
    if ( num->size + 1 > result->capacity ) {
        int *new_digits = realloc(result->digits, (num->size + 1) * sizeof(int));
        if ( new_digits == NULL ) {
            bigint_free(result);
            return NULL;
        }
        result->digits = new_digits;
        result->capacity = num->size + 1;
    }
    int carry = 0;
    for ( int i = 0; i < num->size; i++ ) {
        int product = num->digits[i] * digit + carry;
        result->digits[i] = product % 10;
        carry = product / 10;
    }
    result->size = num->size;
    if ( carry > 0 ) {
        result->digits[result->size] = carry;
        result->size++;
    }
    result->sign = num->sign;
    return result;
}


BigInt *bigint_divide( const BigInt *num1, const BigInt *num2 )
{
    if (num1 == NULL || num2 == NULL) {
        return NULL;
    }

    /*
     * Division by zero check
     */
    if (num2->size == 1 &&
        num2->digits[0] == 0) {
        return NULL;
    }

    /*
     * Quotient starts at zero.
     */
    BigInt *quotient =
        bigint_from_string("0");

    if (quotient == NULL) {
        return NULL;
    }

    /*
     * Current remainder starts at zero.
     */
    BigInt *remainder =
        bigint_from_string("0");

    if (remainder == NULL) {
        bigint_free(quotient);
        return NULL;
    }

    /*
     * Make enough space for quotient.
     */
    if (num1->size > quotient->capacity) {

        int *new_digits = realloc(
            quotient->digits,
            num1->size * sizeof(int)
        );

        if (new_digits == NULL) {
            bigint_free(quotient);
            bigint_free(remainder);
            return NULL;
        }

        quotient->digits = new_digits;
        quotient->capacity = num1->size;
    }

    /*
     * Initialize quotient digits.
     */
    quotient->size = num1->size;

    for (int i = 0; i < quotient->size; i++) {
        quotient->digits[i] = 0;
    }

    /*
     * Long division.
     *
     * Process dividend from left to right.
     *
     * Since digits are stored reversed,
     * we go from size - 1 down to 0.
     */
    for (int i = num1->size - 1; i >= 0; i--) {

        /*
         * remainder = remainder * 10
         *             + current digit
         */
        BigInt *new_remainder =
            bigint_append_digit(
                remainder,
                num1->digits[i]
            );

        if (new_remainder == NULL) {
            bigint_free(quotient);
            bigint_free(remainder);
            return NULL;
        }

        bigint_free(remainder);
        remainder = new_remainder;

        /*
         * Find largest digit from 0 to 9
         * such that:
         *
         * num2 * digit <= remainder
         */
        int quotient_digit = 0;

        for (int digit = 9; digit >= 0; digit--) {

            BigInt *product =
                bigint_multiply_by_digit(
                    num2,
                    digit
                );

            if (product == NULL) {
                bigint_free(quotient);
                bigint_free(remainder);
                return NULL;
            }

            int comparison =
                bigint_compare_abs(
                    product,
                    remainder
                );

            if (comparison <= 0) {

                quotient_digit = digit;

                BigInt *new_remainder =
                    bigint_sub_abs(
                        remainder,
                        product
                    );

                bigint_free(product);

                if (new_remainder == NULL) {
                    bigint_free(quotient);
                    bigint_free(remainder);
                    return NULL;
                }

                bigint_free(remainder);
                remainder = new_remainder;

                break;
            }

            bigint_free(product);
        }

        /*
         * Store quotient digit.
         */
        quotient->digits[i] =
            quotient_digit;
    }

    /*
     * Remove leading zeroes.
     */
    while (quotient->size > 1 &&
           quotient->digits[quotient->size - 1] == 0) {
        quotient->size--;
    }

    /*
     * Determine sign.
     */
    quotient->sign =
        num1->sign * num2->sign;

    /*
     * Zero is always positive.
     */
    if (quotient->size == 1 &&
        quotient->digits[0] == 0) {
        quotient->sign = 1;
    }

    bigint_free(remainder);

    return quotient;
}