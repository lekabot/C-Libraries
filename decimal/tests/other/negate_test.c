#include "../test_main.h"

void test_negate(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_negate(decimal, &result);
  int sign_check = decimal_get_sign(decimal_check);
  int sign_result = decimal_get_sign(result);
  ck_assert_int_eq(code, OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_negate_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_negate(decimal, NULL);

  ck_assert_int_eq(code, OTHER_ERROR);
}

START_TEST(test_negate_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // -792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // 792281625142643375935439503.35
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // -79228162514264337593543950.335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // 79228162514264337593543950.335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // -7922816251426433759354395.0335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // 7922816251426433759354395.0335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // -792281625142643375935439.50335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // 792281625142643375935439.50335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // -79228162514264337593543.950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // 79228162514264337593543.950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // -7922816251426433759354.3950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

Suite *s21_negate_tests(void) {
  Suite *suit;
  TCase *tc_core;

  suit = suite_create("negate_tests");
  tc_core = tcase_create("negate_tests");

  tcase_add_test(tc_core, test_negate_fail1);
  tcase_add_test(tc_core, test_negate_fail2);
  tcase_add_test(tc_core, test_negate_fail3);
  tcase_add_test(tc_core, test_negate_fail4);
  tcase_add_test(tc_core, test_negate_fail5);
  tcase_add_test(tc_core, test_negate_fail6);
  tcase_add_test(tc_core, test_negate_fail7);
  tcase_add_test(tc_core, test_negate_fail8);
  tcase_add_test(tc_core, test_negate_fail9);

  tcase_add_test(tc_core, test_negate_ok1);
  tcase_add_test(tc_core, test_negate_ok2);
  tcase_add_test(tc_core, test_negate_ok3);
  tcase_add_test(tc_core, test_negate_ok4);
  tcase_add_test(tc_core, test_negate_ok5);
  tcase_add_test(tc_core, test_negate_ok6);
  tcase_add_test(tc_core, test_negate_ok7);
  tcase_add_test(tc_core, test_negate_ok8);
  tcase_add_test(tc_core, test_negate_ok9);
  tcase_add_test(tc_core, test_negate_ok10);
  tcase_add_test(tc_core, test_negate_ok11);
  tcase_add_test(tc_core, test_negate_ok12);
  tcase_add_test(tc_core, test_negate_ok13);
  tcase_add_test(tc_core, test_negate_ok14);
  tcase_add_test(tc_core, test_negate_ok15);
  suite_add_tcase(suit, tc_core);

  return suit;
}