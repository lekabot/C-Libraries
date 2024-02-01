#include "../test_main.h"

void test_from_decimal_to_int(s21_decimal decimal, int check) {
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, CONVERSION_OK);
}

START_TEST(s21_from_decimal_to_int1) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 2;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int2) {
  s21_decimal src1;
  int res, our_res = 0;

  // src1 = -2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -2;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int3) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 2;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int4) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -2;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int5) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int6) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int7) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int8) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int9) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int10) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int11) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int12) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int13) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int14) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int15) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int16) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int17) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int18) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 3.2;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 3;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int19) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  res = 12345677;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int20) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  res = -12345677;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int21) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  res = 12345677;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int22) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -12345677.987654345678987654346;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  res = -12345677;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int28) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 665464545;

  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 665464545;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int29) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 2.7986531268974139743;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;

  res = 2;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int31) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0.5456465465486476846545465485;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int32) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -0.77545545454546589781;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int35) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -784515454.7989898652154545652;

  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  src1.bits[3] = 0b10000000000100110000000000000000;

  res = -784515454;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int36) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int37) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 1;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int38) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -1;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int39) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  res = 1;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int40) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -1.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  res = -1;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int45) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int46) {
  s21_decimal src1;
  int res, our_res;

  // src1 = -0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000101100000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int47) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int48) {
  s21_decimal src1;
  int res, our_res;

  // src1 = 0.0000000000000000000002;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000101100000000000000000;

  res = 0;

  s21_from_decimal_to_int(src1, &our_res);

  ck_assert_int_eq(res, our_res);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_int_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_ok1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok2) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok3) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok4) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok5) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok6) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok7) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok8) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok9) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok10) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok11) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok12) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok13) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok14) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok15) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok16) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok17) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok18) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok19) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok20) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok21) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok22) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok23) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok24) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok25) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok26) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok27) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok28) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok29) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok30) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok31) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok32) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok33) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok34) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok35) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok36) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok37) {
  // 528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok38) {
  // -528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok39) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok40) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok41) {
  // 528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok42) {
  // -528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok43) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok44) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok45) {
  // 528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok46) {
  // -528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok47) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok48) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok49) {
  // 528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok50) {
  // -528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok51) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok52) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

Suite *s21_decimal_to_int_tests(void) {
  Suite *s1 = suite_create("decimal_to_int");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_from_decimal_to_int1);
  tcase_add_test(tc_core, s21_from_decimal_to_int2);
  tcase_add_test(tc_core, s21_from_decimal_to_int3);
  tcase_add_test(tc_core, s21_from_decimal_to_int4);
  tcase_add_test(tc_core, s21_from_decimal_to_int5);
  tcase_add_test(tc_core, s21_from_decimal_to_int6);
  tcase_add_test(tc_core, s21_from_decimal_to_int7);
  tcase_add_test(tc_core, s21_from_decimal_to_int8);
  tcase_add_test(tc_core, s21_from_decimal_to_int9);
  tcase_add_test(tc_core, s21_from_decimal_to_int10);
  tcase_add_test(tc_core, s21_from_decimal_to_int11);
  tcase_add_test(tc_core, s21_from_decimal_to_int12);
  tcase_add_test(tc_core, s21_from_decimal_to_int13);
  tcase_add_test(tc_core, s21_from_decimal_to_int14);
  tcase_add_test(tc_core, s21_from_decimal_to_int15);
  tcase_add_test(tc_core, s21_from_decimal_to_int16);
  tcase_add_test(tc_core, s21_from_decimal_to_int17);
  tcase_add_test(tc_core, s21_from_decimal_to_int18);
  tcase_add_test(tc_core, s21_from_decimal_to_int19);
  tcase_add_test(tc_core, s21_from_decimal_to_int20);
  tcase_add_test(tc_core, s21_from_decimal_to_int21);
  tcase_add_test(tc_core, s21_from_decimal_to_int22);
  tcase_add_test(tc_core, s21_from_decimal_to_int28);
  tcase_add_test(tc_core, s21_from_decimal_to_int29);
  tcase_add_test(tc_core, s21_from_decimal_to_int31);
  tcase_add_test(tc_core, s21_from_decimal_to_int32);
  tcase_add_test(tc_core, s21_from_decimal_to_int35);
  tcase_add_test(tc_core, s21_from_decimal_to_int36);
  tcase_add_test(tc_core, s21_from_decimal_to_int37);
  tcase_add_test(tc_core, s21_from_decimal_to_int38);
  tcase_add_test(tc_core, s21_from_decimal_to_int39);
  tcase_add_test(tc_core, s21_from_decimal_to_int40);
  tcase_add_test(tc_core, s21_from_decimal_to_int45);
  tcase_add_test(tc_core, s21_from_decimal_to_int46);
  tcase_add_test(tc_core, s21_from_decimal_to_int47);
  tcase_add_test(tc_core, s21_from_decimal_to_int48);

  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual1);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual2);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual3);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual4);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual5);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual6);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual7);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual8);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual9);

  tcase_add_test(tc_core, test_from_decimal_to_int_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok52);

  suite_add_tcase(s1, tc_core);
  return s1;
}