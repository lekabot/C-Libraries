#include "s21_string_tests.h"

START_TEST(test_s21_memset_1) {
    char dest[] = "Hello, World!";
    char expected[] = "AAAAAAAAAAAAA";

    void *result_s21 = s21_memset(dest, 'A', sizeof(dest));
    void *result_mem = memset(dest, 'A', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_2) {
    char dest[] = "ABCDE";
    char expected[] = "AAAAA";

    void *result_s21 = s21_memset(dest, 'A', 5);
    void *result_mem = memset(dest, 'A', 5);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, 5);
}

START_TEST(test_s21_memset_3) {
    char dest[10] = "abcdefghij";
    char expected[10] = "ABCDEFGHIJ";

    void *result_s21 = s21_memset(dest, 'A', sizeof(dest));
    void *result_mem = memset(dest, 'A', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_4) {
    char dest[] = "12345";
    char expected[] = "AAAAA";
    s21_size_t size = 0;
    void *result_s21 = s21_memset(dest, 'A', size);
    void *result_mem = memset(dest, 'A', size);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_5) {
    char dest[] = "Testing";
    char expected[] = "TTTTTTT";

    void *result_s21 = s21_memset(dest, 'T', sizeof(dest));
    void *result_mem = memset(dest, 'T', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_6) {
    char dest[5] = "";
    char expected[5] = "AAAA";

    void *result_s21 = s21_memset(dest, 'A', sizeof(dest));
    void *result_mem = memset(dest, 'A', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_7) {
    char dest[5] = "ABCDE";
    char expected[5] = "AAAAE";

    void *result_s21 = s21_memset(dest, 'A', 4);
    void *result_mem = memset(dest, 'A', 4);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, 5);
}

START_TEST(test_s21_memset_8) {
    char dest[3] = "123";
    char expected[3] = "AAA";

    void *result_s21 = s21_memset(dest, 'A', sizeof(dest));
    void *result_mem = memset(dest, 'A', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_9) {
    char dest[10] = "abcdefghij";
    char expected[10] = "AAAAAAAAAA";

    void *result_s21 = s21_memset(dest, 'A', 10);
    void *result_mem = memset(dest, 'A', 10);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

START_TEST(test_s21_memset_10) {
    char dest[] = "Test";
    char expected[] = "AAAA";

    void *result_s21 = s21_memset(dest, 'A', sizeof(dest));
    void *result_mem = memset(dest, 'A', sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, expected, sizeof(dest));
}

Suite *suite_s21_memcpy(void) {
    Suite *s = suite_create("suite_memset");
    TCase *tc = tcase_create("memset_tc");
    tcase_add_test(tc, test_s21_memset_1);
    tcase_add_test(tc, test_s21_memset_2);
    tcase_add_test(tc, test_s21_memset_3);
    tcase_add_test(tc, test_s21_memset_4);
    tcase_add_test(tc, test_s21_memset_5);
    tcase_add_test(tc, test_s21_memset_6);
    tcase_add_test(tc, test_s21_memset_7);
    tcase_add_test(tc, test_s21_memset_8);
    tcase_add_test(tc, test_s21_memset_9);
    tcase_add_test(tc, test_s21_memset_10);

    suite_add_tcase(s, tc);
    return s;
}