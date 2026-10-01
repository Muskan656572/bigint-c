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
BigInt *bigint_from_string(const char *str);
void bigint_print(const BigInt *num);
#endif