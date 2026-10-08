# BigInt in C

## Description

BigInt is an arbitrary-precision integer library and calculator
implemented in C.

Normal C integer types such as `int` and `long long` have limited
ranges. This project represents integers using dynamically allocated
arrays so that numbers larger than the normal C integer limits can be
stored and processed.

The project also provides a command-line calculator for performing
different operations on BigInt values.

---

## Goals

The main goals of this project are:

- Understand dynamic memory allocation in C.
- Understand pointers and structures.
- Implement arbitrary-precision integer representation.
- Implement arithmetic operations without relying on built-in
  large integer types.
- Practice modular program design using `.h` and `.c` files.
- Handle memory allocation and deallocation safely.
- Build a test suite for verifying the implementation.
- Use Git and GitHub for project development and version control.

---

## Features

The BigInt library currently supports:

- Creating and freeing BigInt objects
- Converting strings to BigInt
- Printing BigInt values
- Comparing BigInt values
- Addition
- Subtraction
- Multiplication
- Integer division
- Modulo
- Power
- Factorial
- Interactive calculator
- Automated tests

---

## BigInt Representation

A BigInt is represented using the following structure:

```c
typedef struct {
    int *digits;
    int size;
    int capacity;
    int sign;
} BigInt;