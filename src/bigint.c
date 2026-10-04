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