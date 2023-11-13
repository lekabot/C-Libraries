#include "s21_string_tests.h"

START_TEST(test_s21_sscanf_1) {
    const char input[] = "Hello, World!";
    char str[20];
    int result_s21 = s21_sscanf(input, "%s", str);
    int result_std = sscanf(input, "%s", str);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(str, "Hello,");
}

START_TEST(test_s21_sscanf_2) {
    const char input[] = "Value: 42";
    int value_s21, value_std;
    int result_s21 = s21_sscanf(input, "Value: %d", &value_s21);
    int result_std = sscanf(input, "Value: %d", &value_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(value_s21, value_std);
}

START_TEST(test_s21_sscanf_3) {
    const char input[] = "Floating point: 3.14";
    float fp_s21, fp_std;
    int result_s21 = s21_sscanf(input, "Floating point: %f", &fp_s21);
    int result_std = sscanf(input, "Floating point: %f", &fp_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_ldouble_eq_tol(fp_s21, fp_std, 0.01);
}

START_TEST(test_s21_sscanf_4) {
    const char input[] = "Character: X";
    char ch_s21, ch_std;
    int result_s21 = s21_sscanf(input, "Character: %c", &ch_s21);
    int result_std = sscanf(input, "Character: %c", &ch_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(ch_s21, ch_std);
}

START_TEST(test_s21_sscanf_5) {
    const char input[] = "Empty string: ";
    char str[20];
    int result_s21 = s21_sscanf(input, "Empty string: %s", str);
    int result_std = sscanf(input, "Empty string: %s", str);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(str, "");
}

START_TEST(test_s21_sscanf_6) {
    const char input[] = "Hexadecimal: ff";
    int hex_s21, hex_std;
    int result_s21 = s21_sscanf(input, "Hexadecimal: %x", &hex_s21);
    int result_std = sscanf(input, "Hexadecimal: %x", &hex_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(hex_s21, hex_std);
}

START_TEST(test_s21_sscanf_7) {
    const char input[] = "Scientific notation: 1.234568e+04";
    long double sci_s21, sci_std;
    int result_s21 = s21_sscanf(input, "Scientific notation: %Le", &sci_s21);
    int result_std = sscanf(input, "Scientific notation: %Le", &sci_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_ldouble_eq_tol(sci_s21, sci_std, 0.01);
}

START_TEST(test_s21_sscanf_8) {
    const char input[] = "Invalid format: 42 Hello";
    int value_s21, value_std;
    char str[20];
    int result_s21 = s21_sscanf(input, "%d %s", &value_s21, str);
    int result_std = sscanf(input, "%d %s", &value_std, str);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(value_s21, value_std);
    ck_assert_str_eq(str, "Hello");
}

START_TEST(test_s21_sscanf_9) {
    const char input[] = "Multiple arguments: 42 Hello A";
    int value_s21, value_std;
    char str[20], ch_s21, ch_std;
    int result_s21 = s21_sscanf(input, "%d %s %c", &value_s21, str, &ch_s21);
    int result_std = sscanf(input, "%d %s %c", &value_std, str, &ch_std);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(value_s21, value_std);
    ck_assert_str_eq(str, "Hello");
    ck_assert_int_eq(ch_s21, ch_std);
}

START_TEST(test_s21_sscanf_10) {
    const char input[] = "Invalid input";
    int value_s21, value_std;
    char str[20];
    int result_s21 = s21_sscanf(input, "%d %s", &value_s21, str);
    int result_std = sscanf(input, "%d %s", &value_std, str);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_int_eq(value_s21, 0); // No conversion, value should remain 0
    ck_assert_str_eq(str, ""); // No conversion, string should remain empty
}

Suite *suite_s21_sscanf(void) {
    Suite *s = suite_create("suite_sscanf");
    TCase *tc = tcase_create("sscanf_tc");
    tcase_add_test(tc, test_s21_sscanf_1);
    tcase_add_test(tc, test_s21_sscanf_2);
    tcase_add_test(tc, test_s21_sscanf_3);
    tcase_add_test(tc, test_s21_sscanf_4);
    tcase_add_test(tc, test_s21_sscanf_5);
    tcase_add_test(tc, test_s21_sscanf_6);
    tcase_add_test(tc, test_s21_sscanf_7);
    tcase_add_test(tc, test_s21_sscanf_8);
    tcase_add_test(tc, test_s21_sscanf_9);
    tcase_add_test(tc, test_s21_sscanf_10);

    suite_add_tcase(s, tc);
    return s;
}
