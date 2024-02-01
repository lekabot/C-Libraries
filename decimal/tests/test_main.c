#include "test_main.h"

#include <check.h>

void run_tests(void) {
  Suite *list_cases[] = {s21_int_to_decimal_tests(),
                         s21_decimal_to_int_tests(),
                         s21_from_float_to_decimal_tests(),
                         s21_from_decimal_to_float_tests(),
                         s21_less_tests(),
                         s21_is_less_or_equal_tests(),
                         s21_is_equal_tests(),
                         s21_is_greater_tests(),
                         s21_is_greater_or_equal_tests(),
                         s21_not_equal_tests(),
                         s21_div_tests(),
                         s21_add_tests(),
                         s21_mul_tests(),
                         s21_sub_tests(),
                         s21_help_tests(),
                         s21_floor_tests(),
                         s21_negate_tests(),
                         s21_round_tests(),
                         s21_truncate_tests(),
                         NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 0;
  if (counter_testcase > 0) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

int main(void) {
  run_tests();
  return 0;
}