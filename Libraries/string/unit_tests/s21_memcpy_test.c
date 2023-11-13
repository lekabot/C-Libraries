#include "s21_string_tests.h"

START_TEST(test_s21_memcpy_1) {
    const char src[] = "Hello, World!";
    char dest[sizeof(src)] = "";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}

START_TEST(test_s21_memcpy_2) {
    const char src[] = "Copy me!";
    char dest[sizeof(src)] = "";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}

START_TEST(test_s21_memcpy_3) {
    const char src[] = "12345";
    char dest[sizeof(src)] = "abcde";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}

START_TEST(test_s21_memcpy_4) {
    const char src[] = "Programming";
    char dest[sizeof(src)] = "123456789012";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}

START_TEST(test_s21_memcpy_5) {
    const char src[] = "";
    char dest[10] = "abcdefghij";

    void *result_s21 = s21_memcpy(dest, src, 0);
    void *result_mem = memcpy(dest, src, 0);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, "abcdefghij", 10);
}

START_TEST(test_s21_memcpy_6) {
    const char src[] = "ABCDE";
    char dest[sizeof(src)] = "12345";

    void *result_s21 = s21_memcpy(dest, src, 3);
    void *result_mem = memcpy(dest, src, 3);

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, "ABC45", 5);
}

START_TEST(test_s21_memcpy_7) {
    const char src[] = "123";
    char dest[10] = "abcdefghij";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}

START_TEST(test_s21_memcpy_8) {
    const char src[] = "Copy";
    char dest[3] = "12";

    void *result_s21 = s21_memcpy(dest, src, sizeof(dest));
    void *result_mem = memcpy(dest, src, sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, "Cop", sizeof(dest));
}

START_TEST(test_s21_memcpy_9) {
    const char src[] = "Testing";
    char dest[sizeof(src) - 1] = "";

    void *result_s21 = s21_memcpy(dest, src, sizeof(dest));
    void *result_mem = memcpy(dest, src, sizeof(dest));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(dest));
}

START_TEST(test_s21_memcpy_10) {
    const char src[] = "12345";
    char dest[sizeof(src) + 2] = "abcde";

    void *result_s21 = s21_memcpy(dest, src, sizeof(src));
    void *result_mem = memcpy(dest, src, sizeof(src));

    ck_assert_ptr_eq(result_s21, result_mem);
    ck_assert_mem_eq(dest, src, sizeof(src));
}


Suite *suite_s21_memcpy(void) {
    Suite *s = suite_create("suite_memcpy");
    TCase *tc = tcase_create("memcpy_tc");
    tcase_add_test(tc, test_s21_memcpy_1);
    tcase_add_test(tc, test_s21_memcpy_2);
    tcase_add_test(tc, test_s21_memcpy_3);
    tcase_add_test(tc, test_s21_memcpy_4);
    tcase_add_test(tc, test_s21_memcpy_5);
    tcase_add_test(tc, test_s21_memcpy_6);
    tcase_add_test(tc, test_s21_memcpy_7);
    tcase_add_test(tc, test_s21_memcpy_8);
    tcase_add_test(tc, test_s21_memcpy_9);
    tcase_add_test(tc, test_s21_memcpy_10);

    suite_add_tcase(s, tc);
    return s;
}