#include "../test_main.h"

START_TEST(decimal_get_inf_test) {
  s21_decimal tmp = decimal_get_zero();
  tmp = decimal_get_inf();
  s21_decimal answer = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};
  int result = s21_is_equal(tmp, answer);
  ck_assert_int_eq(result, 1);
}
END_TEST;

START_TEST(decimal_even_test) {
  s21_decimal tmp = decimal_get_zero();
  // 3
  tmp.bits[0] = 0b00000000000000000000000000000011;
  tmp.bits[1] = 0b00000000000000000000000000000000;
  tmp.bits[2] = 0b00000000000000000000000000000000;
  tmp.bits[3] = 0b00000000000000000000000000000000;
  int result = decimal_is_even(tmp);
  ck_assert_int_eq(result, 0);
}
END_TEST;

Suite *s21_help_tests(void) {
  Suite *s1 = suite_create("help_tests");
  TCase *tc1_1 = tcase_create("help_tests");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, decimal_get_inf_test);
  tcase_add_test(tc1_1, decimal_even_test);

  return s1;
}