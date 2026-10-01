#include "bigint.h"
#include <stdlib.h>

BigInt *bigint_create(void) {
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
void bigint_free(BigInt *num)
{
    if (num == NULL) {
        return;
    }

    free(num->digits);
    free(num);
}