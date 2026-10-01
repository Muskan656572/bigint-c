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

    if ( num->sign == '-' ) {
        printf("-");
    }

    for ( int i = 0; i < num->size; i++ ) {
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