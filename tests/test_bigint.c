#include <stdio.h>
#include "bigint.h"

int tests_passed = 0;
int tests_failed = 0;


void check_result(const char *test_name,
                  BigInt *result,
                  const char *expected)
{
    BigInt *expected_num = bigint_from_string(expected);

    if (result != NULL &&
        expected_num != NULL &&
        bigint_compare(result, expected_num) == 0)
    {
        printf("PASS: %s\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("FAIL: %s\n", test_name);
        tests_failed++;
    }

    bigint_free(result);
    bigint_free(expected_num);
}


int main(void)
{
    printf("========== BigInt Test Suite ==========\n\n");


    /* ==================== ADDITION ==================== */

    BigInt *a = bigint_from_string("123");
    BigInt *b = bigint_from_string("456");

    check_result(
        "123 + 456",
        bigint_add(a, b),
        "579"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("-100");
    b = bigint_from_string("50");

    check_result(
        "-100 + 50",
        bigint_add(a, b),
        "-50"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("999999999999999999");
    b = bigint_from_string("1");

    check_result(
        "Large addition",
        bigint_add(a, b),
        "1000000000000000000"
    );

    bigint_free(a);
    bigint_free(b);


    /* ==================== SUBTRACTION ==================== */

    a = bigint_from_string("1000");
    b = bigint_from_string("1");

    check_result(
        "1000 - 1",
        bigint_substract(a, b),
        "999"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("50");
    b = bigint_from_string("100");

    check_result(
        "50 - 100",
        bigint_substract(a, b),
        "-50"
    );

    bigint_free(a);
    bigint_free(b);


    /* ==================== MULTIPLICATION ==================== */

    a = bigint_from_string("123");
    b = bigint_from_string("10");

    check_result(
        "123 * 10",
        bigint_multiply(a, b),
        "1230"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("-20");
    b = bigint_from_string("5");

    check_result(
        "-20 * 5",
        bigint_multiply(a, b),
        "-100"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("0");
    b = bigint_from_string("12345");

    check_result(
        "0 * 12345",
        bigint_multiply(a, b),
        "0"
    );

    bigint_free(a);
    bigint_free(b);


    /* ==================== DIVISION ==================== */

    a = bigint_from_string("100");
    b = bigint_from_string("7");

    check_result(
        "100 / 7",
        bigint_divide(a, b),
        "14"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("7");
    b = bigint_from_string("100");

    check_result(
        "7 / 100",
        bigint_divide(a, b),
        "0"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("-100");
    b = bigint_from_string("7");

    check_result(
        "-100 / 7",
        bigint_divide(a, b),
        "-14"
    );

    bigint_free(a);
    bigint_free(b);


    /* ==================== MODULO ==================== */

    a = bigint_from_string("100");
    b = bigint_from_string("7");

    check_result(
        "100 % 7",
        bigint_modulo(a, b),
        "2"
    );

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("10");
    b = bigint_from_string("5");

    check_result(
        "10 % 5",
        bigint_modulo(a, b),
        "0"
    );

    bigint_free(a);
    bigint_free(b);


    /* ==================== POWER ==================== */

    a = bigint_from_string("2");

    check_result(
        "2 ^ 10",
        bigint_power(a, 10),
        "1024"
    );

    bigint_free(a);


    a = bigint_from_string("5");

    check_result(
        "5 ^ 0",
        bigint_power(a, 0),
        "1"
    );

    bigint_free(a);


    /* ==================== FACTORIAL ==================== */

    a = bigint_from_string("5");

    check_result(
        "5!",
        bigint_factorial(a),
        "120"
    );

    bigint_free(a);


    a = bigint_from_string("0");

    check_result(
        "0!",
        bigint_factorial(a),
        "1"
    );

    bigint_free(a);


    /* ==================== COMPARISON ==================== */

    a = bigint_from_string("1000");
    b = bigint_from_string("999");

    if (bigint_compare(a, b) > 0)
    {
        printf("PASS: 1000 > 999\n");
        tests_passed++;
    }
    else
    {
        printf("FAIL: 1000 > 999\n");
        tests_failed++;
    }

    bigint_free(a);
    bigint_free(b);


    a = bigint_from_string("100");
    b = bigint_from_string("100");

    if (bigint_compare(a, b) == 0)
    {
        printf("PASS: 100 == 100\n");
        tests_passed++;
    }
    else
    {
        printf("FAIL: 100 == 100\n");
        tests_failed++;
    }

    bigint_free(a);
    bigint_free(b);


    /* ==================== SUMMARY ==================== */

    printf("\n========================================\n");
    printf("Tests passed : %d\n", tests_passed);
    printf("Tests failed : %d\n", tests_failed);
    printf("========================================\n");

    if (tests_failed == 0)
    {
        printf("ALL TESTS PASSED!\n");
        return 0;
    }

    printf("SOME TESTS FAILED!\n");
    return 1;
}