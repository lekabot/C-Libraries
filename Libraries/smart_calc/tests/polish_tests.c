#include "start_tests.h"

START_TEST(polish_notation_sin_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "-sin(-2-3*1.55)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double b = -2 - 3 * 1.55;
  double a = -sin(b);
  ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_asin_test) {
    char input[STACK_MAX_SIZE];
    char output[STACK_MAX_SIZE];
    double x = 0;
    int error = 0;
    strcpy(input, "-asin(0.75)");
    convert_to_polish_record(input, output);
    double end = calculate_value(output, x, &error);
    double b = 0.75;
    double a = -asin(b);
    ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_cos_test) {
    char input[STACK_MAX_SIZE];
    char output[STACK_MAX_SIZE];
    double x = 2.1;
    int error = 0;
    strcpy(input, "cos(x*2.1)");
    convert_to_polish_record(input, output);
    double end = calculate_value(output, x, &error);
    ck_assert_ldouble_eq_tol(end, cos(2.1 * 2.1), ESP);
}
END_TEST

START_TEST(polish_notation_acos_test) {
    char input[STACK_MAX_SIZE];
    char output[STACK_MAX_SIZE];
    double x = 0;
    int error = 0;
    strcpy(input, "acos(0.5)");
    convert_to_polish_record(input, output);
    double end = calculate_value(output, x, &error);
    double b = 0.5;
    double a = acos(b);
    ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_tan_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "tan(2.1)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double b = 2.1;
  double a = tan(b);
  ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_atan_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "atan(2.1)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double b = 2.1;
  ck_assert_ldouble_eq_tol(end, atan(b), ESP);
}
END_TEST

START_TEST(polish_notation_sqrt_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "sqrt(21)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double b = 21;
  ck_assert_ldouble_eq_tol(end, sqrt(b), ESP);
}
END_TEST

START_TEST(polish_notation_log_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "log(2.1)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double a = log10f(2.1);
  ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_ln_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "ln(2.1)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  double a = log(2.1);
  ck_assert_ldouble_eq_tol(end, a, ESP);
}
END_TEST

START_TEST(polish_notation_mod_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "10m3+2");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  ck_assert_ldouble_eq_tol(end, 3.0, ESP);
}
END_TEST

START_TEST(polish_notation_pow_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "2^(3^4)");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  ck_assert_ldouble_eq_tol(end, pow(2, pow(3, 4)), ESP);
}
END_TEST

START_TEST(polish_notation_error_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "2*/+-0");
  convert_to_polish_record(input, output);
  calculate_value(output, x, &error);
  ck_assert_int_eq(error, SUF);
}
END_TEST

START_TEST(polish_notation_div_on_zero_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input, "2/0");
  convert_to_polish_record(input, output);
  double res = calculate_value(output, x, &error);
  ck_assert_double_eq(res, 1.0 / 0.0);
}
END_TEST

START_TEST(polish_notation_algorithm_test) {
  char input[STACK_MAX_SIZE];
  char output[STACK_MAX_SIZE];
  double x = 0;
  int error = 0;
  strcpy(input,
         "15/(7-(1 + "
         "1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
         "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))");
  convert_to_polish_record(input, output);
  double end = calculate_value(output, x, &error);
  ck_assert_ldouble_eq_tol(end, -30.0721649484536082, ESP);
}
END_TEST

START_TEST(convert_to_polish_simple_tests) {
    char infix_record1[] = "3 + 5 * 2";
    char polish_record1[MAX_INFIX_LENGTH * 2];
    convert_to_polish_record(infix_record1, polish_record1);
    ck_assert_str_eq(polish_record1, "3 5 2 * + ");

    char infix_record2[] = "( 8 - 2 ) / ( 4 + 1 )";
    char polish_record2[MAX_INFIX_LENGTH * 2];
    convert_to_polish_record(infix_record2, polish_record2);
    ck_assert_str_eq(polish_record2, "8 2 - 4 1 + / ");
}
END_TEST

START_TEST(is_operator_tests) {
    ck_assert_int_eq(is_operator('('), 1);
    ck_assert_int_eq(is_operator('3'), 0);
    ck_assert_int_eq(is_operator('s'), 0);
}
END_TEST

START_TEST(get_op_name_tests) {
    ck_assert_int_eq(get_op_name("sin"), 's');
    ck_assert_int_eq(get_op_name("^"), '^');
    ck_assert_int_eq(get_op_name("acos"), 'C');
}
END_TEST

START_TEST(get_op_priority_tests) {
    ck_assert_int_eq(get_op_priority('S'), 6);
    ck_assert_int_eq(get_op_priority('+'), 2);
    ck_assert_int_eq(get_op_priority('m'), 4);
    ck_assert_int_eq(get_op_priority('*'), 5);
    ck_assert_int_eq(get_op_priority('^'), 10);
}
END_TEST

START_TEST(calculate_value_simple_tests) {
    int error = 0;

    char polish_record1[] = "3 5 2 * + ";
    double result1 = calculate_value(polish_record1, 0, &error);
    ck_assert_int_eq(error, 0);
    ck_assert_ldouble_eq_tol(result1, 13, ESP);

    char polish_record2[] = "x 2 ^ 3 * x + ";
    double result2 = calculate_value(polish_record2, 2, &error);
    ck_assert_int_eq(error, 0);
    ck_assert_ldouble_eq_tol(result2, 14, ESP);

    char polish_record3[] = "3 + * 5";
    calculate_value(polish_record3, 0, &error);
    ck_assert_int_eq(error, SUF);

    char polish_record4[] = "asga3";
    calculate_value(polish_record4, 0, &error);
    ck_assert_int_eq(error, SUF);
}
END_TEST

Suite *polish_suite(void) {
    Suite *s = suite_create("Polish check");
    TCase *tc = tcase_create("Polish check");

    tcase_add_test(tc, convert_to_polish_simple_tests);
    tcase_add_test(tc, is_operator_tests);
    tcase_add_test(tc, get_op_name_tests);
    tcase_add_test(tc, get_op_priority_tests);
    tcase_add_test(tc, calculate_value_simple_tests);
    tcase_add_test(tc, polish_notation_sin_test);
    tcase_add_test(tc, polish_notation_asin_test);
    tcase_add_test(tc, polish_notation_cos_test);
    tcase_add_test(tc, polish_notation_acos_test);
    tcase_add_test(tc, polish_notation_tan_test);
    tcase_add_test(tc, polish_notation_atan_test);
    tcase_add_test(tc, polish_notation_sqrt_test);
    tcase_add_test(tc, polish_notation_log_test);
    tcase_add_test(tc, polish_notation_ln_test);
    tcase_add_test(tc, polish_notation_mod_test);
    tcase_add_test(tc, polish_notation_pow_test);
    tcase_add_test(tc, polish_notation_error_test);
    tcase_add_test(tc, polish_notation_div_on_zero_test);
    tcase_add_test(tc, polish_notation_algorithm_test);
    tcase_add_test(tc, convert_to_polish_simple_tests);

    suite_add_tcase(s, tc);
    return s;
}