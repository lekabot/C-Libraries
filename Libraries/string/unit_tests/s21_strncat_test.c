#include "s21_string_tests.h"

START_TEST(test_s21_strncat_1) {
    char dest[20] = "Hello, ";
    const char src[] = "World!";
    s21_strncat(dest, src, 5);

    char dest_std[20] = "Hello, ";
    strncat(dest_std, src, 5);

    ck_assert_str_eq(dest, dest_std);
}

START_TEST(test_s21_strncat_2) {
    char dest[20] = "Programming";
    const char src[] = " is fun!";
    s21_strncat(dest, src, 3);

    char dest_std[20] = "Programming";
    strncat(dest_std, src, 3);

    ck_assert_str_eq(dest, dest_std);
}

START_TEST(test_s21_strncat_3) {
    char dest[20] = "123";
    const char src[] = "456789";
    s21_strncat(dest, src, 4);

    char dest_std[20] = "123";
    strncat(dest_std, src, 4);

    ck_assert_str_eq(dest, dest_std);
}

START_TEST(test_s21_strncat_4) {
    char dest[20] = "Test";
    const char src[] = "";
    s21_strncat(dest, src, 2);

    char dest_std[20] = "Test";
    strncat(dest_std, src, 2);

    ck_assert_str_eq(dest, dest_std);
}

START_TEST(test_s21_strncat_5) {
    char dest[20] = "";
    const char src[] = "Concatenate";
    s21_strncat(dest, src, 10);

    char dest_std[20] = "";
    strncat(dest_std, src, 10);

    ck_assert_str_eq(dest, dest_std);
}

Suite *suite_s21_strncat(void) {
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("strncat_tc");
    tcase_add_test(tc, test_s21_strncat_1);
    tcase_add_test(tc, test_s21_strncat_2);
    tcase_add_test(tc, test_s21_strncat_3);
    tcase_add_test(tc, test_s21_strncat_4);
    tcase_add_test(tc, test_s21_strncat_5);

    suite_add_tcase(s, tc);
    return s;
}
