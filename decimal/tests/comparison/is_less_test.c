#include "../test_main.h"

START_TEST(s21_s21_is_less1) {
  s21_decimal src1, src2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less2) {
  s21_decimal src1, src2;

  // src1 = -2;
  // src2 = -3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less3) {
  s21_decimal src1, src2;

  // src1 = 2;
  // src2 = -3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less4) {
  s21_decimal src1, src2;

  // src1 = -2;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less5) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less6) {
  s21_decimal src1, src2;

  // src1 = -3;
  // src2 = -2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less7) {
  s21_decimal src1, src2;

  // src1 = 3;
  // src2 = -2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less8) {
  s21_decimal src1, src2;

  // src1 = -3;
  // src2 = 2;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less9) {
  s21_decimal src1, src2;

  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less10) {
  s21_decimal src1, src2;

  // src1 = -3;
  // src2 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less11) {
  s21_decimal src1, src2;

  // src1 = 3;
  // src2 = -3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less12) {
  s21_decimal src1, src2;

  // src1 = -3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less13) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less14) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less15) {
  s21_decimal src1, src2;

  // src1 = 3.2;
  // src2 = 3.3;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000100001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less16) {
  s21_decimal src1, src2;

  // src1 = -3.2;
  // src2 = -3.3;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000100001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less17) {
  s21_decimal src1, src2;

  // src1 = -3.2;
  // src2 = 3.3;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000100001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less18) {
  s21_decimal src1, src2;

  // src1 = 3.2;
  // src2 = -3.3;

  src1.bits[0] = 0b00000000000000000000000000100000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000100001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less19) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less20) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less21) {
  s21_decimal src1, src2;

  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less22) {
  s21_decimal src1, src2;

  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less23) {
  s21_decimal src1, src2;

  // src1 = 79228162514264337593543950335;
  // src2 = 1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less24) {
  s21_decimal src1, src2;

  // src1 = -79228162514264337593543950335;
  // src2 = -1;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less25) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less26) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less27) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less28) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less29) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less30) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less31) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less32) {
  s21_decimal src1, src2;

  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;

  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less33) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less34) {
  s21_decimal src1, src2;

  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less35) {
  s21_decimal src1, src2;

  // src1 = -784515454.7989898652154545652;
  // src2 = -579895323215489956.67897455465;

  src1.bits[0] = 0b10110001001110110100010111110100;
  src1.bits[1] = 0b00111000100000111010110010000001;
  src1.bits[2] = 0b00011001010110010101110000011000;
  src1.bits[3] = 0b10000000000100110000000000000000;

  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less36) {
  s21_decimal src1, src2;

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

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less37) {
  s21_decimal src1, src2;

  // src1 = 1.0;
  // src2 = 0.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less38) {
  s21_decimal src1, src2;

  // src1 = -1.0;
  // src2 = 0.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less39) {
  s21_decimal src1, src2;

  // src1 = 1.0;
  // src2 = 0.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less40) {
  s21_decimal src1, src2;

  // src1 = -1.0;
  // src2 = 0.0;

  src1.bits[0] = 0b00000000000000000000000000001010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less41) {
  s21_decimal src1, src2;

  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less42) {
  s21_decimal src1, src2;

  // src1 = -79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less43) {
  s21_decimal src1, src2;

  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 0;

  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_s21_is_less44) {
  s21_decimal src1, src2;

  // src1 = -79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;

  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;

  int result = s21_is_less(src1, src2);

  int origin = 1;

  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *s21_less_tests(void) {
  Suite *s1 = suite_create("less_test");
  TCase *tc1_1 = tcase_create("less_test");

  tcase_add_test(tc1_1, s21_s21_is_less1);
  tcase_add_test(tc1_1, s21_s21_is_less2);
  tcase_add_test(tc1_1, s21_s21_is_less3);
  tcase_add_test(tc1_1, s21_s21_is_less4);
  tcase_add_test(tc1_1, s21_s21_is_less5);
  tcase_add_test(tc1_1, s21_s21_is_less6);
  tcase_add_test(tc1_1, s21_s21_is_less7);
  tcase_add_test(tc1_1, s21_s21_is_less8);
  tcase_add_test(tc1_1, s21_s21_is_less9);
  tcase_add_test(tc1_1, s21_s21_is_less10);
  tcase_add_test(tc1_1, s21_s21_is_less11);
  tcase_add_test(tc1_1, s21_s21_is_less12);
  tcase_add_test(tc1_1, s21_s21_is_less13);
  tcase_add_test(tc1_1, s21_s21_is_less14);
  tcase_add_test(tc1_1, s21_s21_is_less15);
  tcase_add_test(tc1_1, s21_s21_is_less16);
  tcase_add_test(tc1_1, s21_s21_is_less17);
  tcase_add_test(tc1_1, s21_s21_is_less18);
  tcase_add_test(tc1_1, s21_s21_is_less19);
  tcase_add_test(tc1_1, s21_s21_is_less20);
  tcase_add_test(tc1_1, s21_s21_is_less21);
  tcase_add_test(tc1_1, s21_s21_is_less22);
  tcase_add_test(tc1_1, s21_s21_is_less23);
  tcase_add_test(tc1_1, s21_s21_is_less24);
  tcase_add_test(tc1_1, s21_s21_is_less25);
  tcase_add_test(tc1_1, s21_s21_is_less26);
  tcase_add_test(tc1_1, s21_s21_is_less27);
  tcase_add_test(tc1_1, s21_s21_is_less28);
  tcase_add_test(tc1_1, s21_s21_is_less29);
  tcase_add_test(tc1_1, s21_s21_is_less30);
  tcase_add_test(tc1_1, s21_s21_is_less31);
  tcase_add_test(tc1_1, s21_s21_is_less32);
  tcase_add_test(tc1_1, s21_s21_is_less33);
  tcase_add_test(tc1_1, s21_s21_is_less34);
  tcase_add_test(tc1_1, s21_s21_is_less35);
  tcase_add_test(tc1_1, s21_s21_is_less36);
  tcase_add_test(tc1_1, s21_s21_is_less37);
  tcase_add_test(tc1_1, s21_s21_is_less38);
  tcase_add_test(tc1_1, s21_s21_is_less39);
  tcase_add_test(tc1_1, s21_s21_is_less40);
  tcase_add_test(tc1_1, s21_s21_is_less41);
  tcase_add_test(tc1_1, s21_s21_is_less42);
  tcase_add_test(tc1_1, s21_s21_is_less43);
  tcase_add_test(tc1_1, s21_s21_is_less44);

  suite_add_tcase(s1, tc1_1);

  return s1;
}
