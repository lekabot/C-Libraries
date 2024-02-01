#include "../test_main.h"

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, OK);
}

START_TEST(s21_add_1) {
#line 5
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_2) {
#line 26
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_3) {
#line 47
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_4) {
#line 68
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_5) {
#line 89
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_6) {
#line 110
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_7) {
#line 131
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000010011101100000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_8) {
#line 152
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000101110100011001110100011111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_9) {
#line 173
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000011111010011101111100100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_10) {
#line 194
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000001011001000011001011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_11) {
#line 215
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11111101101100110001110000110010;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_12) {
#line 236
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b01001100110100101000000111001000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_13) {
#line 257
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b10001001111010000000000000000000;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_14) {
#line 278
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_15) {
#line 299
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00111111011101000111010111001010;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000001010;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_16) {
#line 320
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -545454512454545.35265454545645;
  // src2 =  54564654;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);

  origin.bits[0] = 0b01110001001010101101101011101101;
  origin.bits[1] = 0b00101110001111001110000111111000;
  origin.bits[2] = 0b10110000001111101110111101101101;
  origin.bits[3] = 0b10000000000011100000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_17) {
#line 341
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b10110110001010011011010111011010;
  origin.bits[1] = 0b11111001111010100000110001111111;
  origin.bits[2] = 0b10110000001111101111000010010100;
  origin.bits[3] = 0b10000000000011100000000000000000;

  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_18) {
#line 362
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_19) {
#line 383
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b00000000000100010000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_22) {
#line 446
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11010010000011011110010110111111;
  origin.bits[1] = 0b10100111010011100111001000100001;
  origin.bits[2] = 0b00011100010100111001110111101101;
  origin.bits[3] = 0b10000000000100010000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_23) {
#line 467
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_24) {
#line 488
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_25) {
#line 509
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_26) {
#line 530
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_27) {
#line 551
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b01100010111100011011000010101001;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_28) {
#line 572
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00110111111111010001010100111010;
  origin.bits[1] = 0b00000000000111110100000111110010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_29) {
#line 593
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b10011010010111001101001011101010;
  origin.bits[1] = 0b10111110010100100100110100010011;
  origin.bits[2] = 0b00000000000010101001000111100111;
  origin.bits[3] = 0b00000000000110000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_30) {
#line 614
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;
  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11010101111011100000000010001100;
  origin.bits[1] = 0b01111000000001011001100110101101;
  origin.bits[2] = 0b00011111101010011000001000100010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_31) {
#line 635
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b01110000110111010100000010001101;
  origin.bits[1] = 0b01011010100111011110001100001010;
  origin.bits[2] = 0b00100111111010111100110001011010;
  origin.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_33) {
#line 677
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b11111111111111111111111111111110;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_36) {
#line 740
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b10000000000011000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_49) {
#line 761
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0.0;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_50) {
#line 782
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 1;
  // src2 = 0.0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_51) {
#line 803
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_52) {
#line 824
  s21_decimal src1, src2, origin;
  int code = 0;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {0};
  code = s21_add(src1, src2, &result);
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_equal(origin, result);
  ck_assert_int_eq(1, check);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(s21_add_53) {
  s21_decimal src1 = decimal_get_zero();
  s21_decimal src2 = decimal_get_zero();

  int code = 0;
  code = s21_add(src1, src2, NULL);
  ck_assert_int_eq(4, code);
}
END_TEST

START_TEST(s21_add_54) {
  s21_decimal src1 = decimal_get_zero();
  s21_decimal src2 = decimal_get_zero();
  s21_decimal src3 = decimal_get_zero();
  decimal_set_power(&src1, 30);
  int code = s21_add(src1, src2, &src3);
  ck_assert_int_eq(4, code);
}
END_TEST

START_TEST(s21_add_55) {
  s21_decimal src1 = decimal_get_inf();
  s21_decimal src2 = decimal_get_inf();
  s21_decimal src3 = decimal_get_zero();
  decimal_set_sign(&src1, NEGATIVE);
  int code = s21_add(src1, src2, &src3);
  ck_assert_int_eq(4, code);
}
END_TEST

START_TEST(s21_add_56) {
  s21_decimal src1 = decimal_get_inf();
  s21_decimal src2 = decimal_get_inf();
  s21_decimal src3 = decimal_get_zero();
  decimal_set_sign(&src1, NEGATIVE);
  int code = s21_add(src2, src2, &src3);
  ck_assert_int_eq(4, code);
}
END_TEST

START_TEST(test_add_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_add(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, OK);
}

START_TEST(test_add_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_manual17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_manual1) {
  // 7.922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 11.884224377139650639031592551
  s21_decimal check = {{0x66666667, 0x66666666, 0x26666666, 0x1B0000}};

  test_add(decimal1, decimal2, check);
}

Suite *s21_add_tests(void) {
  Suite *s1 = suite_create("add_test");
  TCase *tc_core = tcase_create("add_test");

  suite_add_tcase(s1, tc_core);
  tcase_add_test(tc_core, s21_add_1);
  tcase_add_test(tc_core, s21_add_2);
  tcase_add_test(tc_core, s21_add_3);
  tcase_add_test(tc_core, s21_add_4);
  tcase_add_test(tc_core, s21_add_5);
  tcase_add_test(tc_core, s21_add_6);
  tcase_add_test(tc_core, s21_add_7);
  tcase_add_test(tc_core, s21_add_8);
  tcase_add_test(tc_core, s21_add_9);
  tcase_add_test(tc_core, s21_add_10);
  tcase_add_test(tc_core, s21_add_11);
  tcase_add_test(tc_core, s21_add_12);
  tcase_add_test(tc_core, s21_add_13);
  tcase_add_test(tc_core, s21_add_14);
  tcase_add_test(tc_core, s21_add_15);
  tcase_add_test(tc_core, s21_add_16);
  tcase_add_test(tc_core, s21_add_17);
  tcase_add_test(tc_core, s21_add_18);
  tcase_add_test(tc_core, s21_add_19);
  tcase_add_test(tc_core, s21_add_22);
  tcase_add_test(tc_core, s21_add_23);
  tcase_add_test(tc_core, s21_add_24);
  tcase_add_test(tc_core, s21_add_25);
  tcase_add_test(tc_core, s21_add_26);
  tcase_add_test(tc_core, s21_add_27);
  tcase_add_test(tc_core, s21_add_28);
  tcase_add_test(tc_core, s21_add_29);
  tcase_add_test(tc_core, s21_add_30);
  tcase_add_test(tc_core, s21_add_31);
  tcase_add_test(tc_core, s21_add_33);
  tcase_add_test(tc_core, s21_add_36);
  tcase_add_test(tc_core, s21_add_49);
  tcase_add_test(tc_core, s21_add_50);
  tcase_add_test(tc_core, s21_add_51);
  tcase_add_test(tc_core, s21_add_52);
  tcase_add_test(tc_core, s21_add_53);
  tcase_add_test(tc_core, s21_add_54);
  tcase_add_test(tc_core, s21_add_55);
  tcase_add_test(tc_core, s21_add_56);

  tcase_add_test(tc_core, test_add_fail_manual1);
  tcase_add_test(tc_core, test_add_fail_manual2);
  tcase_add_test(tc_core, test_add_fail_manual3);
  tcase_add_test(tc_core, test_add_fail_manual4);
  tcase_add_test(tc_core, test_add_fail_manual5);
  tcase_add_test(tc_core, test_add_fail_manual6);
  tcase_add_test(tc_core, test_add_fail_manual7);
  tcase_add_test(tc_core, test_add_fail_manual8);
  tcase_add_test(tc_core, test_add_fail_manual9);
  tcase_add_test(tc_core, test_add_fail_manual10);
  tcase_add_test(tc_core, test_add_fail_manual11);
  tcase_add_test(tc_core, test_add_fail_manual12);
  tcase_add_test(tc_core, test_add_fail_manual13);
  tcase_add_test(tc_core, test_add_fail_manual14);
  tcase_add_test(tc_core, test_add_fail_manual15);
  tcase_add_test(tc_core, test_add_fail_manual16);
  tcase_add_test(tc_core, test_add_fail_manual17);

  tcase_add_test(tc_core, test_add_manual1);

  return s1;
}
