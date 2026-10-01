#ifndef BIGINT_H
#define BIGINT_H

typedef struct { 
    int *digits;
    int size;
    int capacity;
    int sign;
} BigInt;

BigInt *bigint_create(void);
void bigint_free(BigInt *num);
#endif