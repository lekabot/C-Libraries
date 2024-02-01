#include "../test_main.h"

START_TEST(s21_from_int_to_decimal1) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal2) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal3) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal4) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal5) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal6) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal7) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal8) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal9) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal10) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal11) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal12) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal13) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal14) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal15) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal16) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal17) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal18) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal19) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1234567;

  res.bits[0] = 0b00000000000100101101011010000111;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal20) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1234567;

  res.bits[0] = 0b00000000000100101101011010000111;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal21) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1234567;

  res.bits[0] = 0b00000000000100101101011010000111;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal22) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -123456;

  res.bits[0] = 0b00000000000000011110001001000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal23) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 79228162;

  res.bits[0] = 0b00000100101110001110110100000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal24) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -79625142;

  res.bits[0] = 0b00000100101111101111101110110110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal25) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -79228134;

  res.bits[0] = 0b00000100101110001110110011100110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal26) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 79593334;

  res.bits[0] = 0b00000100101111100111111101110110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal27) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 79228395;

  res.bits[0] = 0b00000100101110001110110111101011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal28) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 66546445;

  res.bits[0] = 0b00000011111101110110101100001101;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal29) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 23126397;

  res.bits[0] = 0b00000001011000001110000101111101;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal30) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -979896154;

  res.bits[0] = 0b00111010011010000000011101011010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal31) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 45646565;

  res.bits[0] = 0b00000010101110001000001011100101;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal32) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -454545781;

  res.bits[0] = 0b00011011000101111101000101110101;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal33) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -754390334;

  res.bits[0] = 0b00101100111101110001010100111110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal34) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 323234854;

  res.bits[0] = 0b00010011010001000010110000100110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal35) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -78452154;

  res.bits[0] = 0b00000100101011010001010110111010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal36) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal37) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal38) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal39) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal40) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal41) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 79225335;

  res.bits[0] = 0b00000100101110001110000111110111;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal42) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -79223950;

  res.bits[0] = 0b00000100101110001101110010001110;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal43) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 79859503;

  res.bits[0] = 0b00000100110000101000111100101111;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal44) {
  int src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -79225033;

  res.bits[0] = 0b00000100101110001110000011001001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_int_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal45) {
  int src1 = 2;

  int code = s21_from_int_to_decimal(src1, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *s21_int_to_decimal_tests(void) {
  Suite *s1 = suite_create("int_to_decimal");
  TCase *tc1_1 = tcase_create("int_to_decimal");

  tcase_add_test(tc1_1, s21_from_int_to_decimal1);
  tcase_add_test(tc1_1, s21_from_int_to_decimal2);
  tcase_add_test(tc1_1, s21_from_int_to_decimal3);
  tcase_add_test(tc1_1, s21_from_int_to_decimal4);
  tcase_add_test(tc1_1, s21_from_int_to_decimal5);
  tcase_add_test(tc1_1, s21_from_int_to_decimal6);
  tcase_add_test(tc1_1, s21_from_int_to_decimal7);
  tcase_add_test(tc1_1, s21_from_int_to_decimal8);
  tcase_add_test(tc1_1, s21_from_int_to_decimal9);
  tcase_add_test(tc1_1, s21_from_int_to_decimal10);
  tcase_add_test(tc1_1, s21_from_int_to_decimal11);
  tcase_add_test(tc1_1, s21_from_int_to_decimal12);
  tcase_add_test(tc1_1, s21_from_int_to_decimal13);
  tcase_add_test(tc1_1, s21_from_int_to_decimal14);
  tcase_add_test(tc1_1, s21_from_int_to_decimal15);
  tcase_add_test(tc1_1, s21_from_int_to_decimal16);
  tcase_add_test(tc1_1, s21_from_int_to_decimal17);
  tcase_add_test(tc1_1, s21_from_int_to_decimal18);
  tcase_add_test(tc1_1, s21_from_int_to_decimal19);
  tcase_add_test(tc1_1, s21_from_int_to_decimal20);
  tcase_add_test(tc1_1, s21_from_int_to_decimal21);
  tcase_add_test(tc1_1, s21_from_int_to_decimal22);
  tcase_add_test(tc1_1, s21_from_int_to_decimal23);
  tcase_add_test(tc1_1, s21_from_int_to_decimal24);
  tcase_add_test(tc1_1, s21_from_int_to_decimal25);
  tcase_add_test(tc1_1, s21_from_int_to_decimal26);
  tcase_add_test(tc1_1, s21_from_int_to_decimal27);
  tcase_add_test(tc1_1, s21_from_int_to_decimal28);
  tcase_add_test(tc1_1, s21_from_int_to_decimal29);
  tcase_add_test(tc1_1, s21_from_int_to_decimal30);
  tcase_add_test(tc1_1, s21_from_int_to_decimal31);
  tcase_add_test(tc1_1, s21_from_int_to_decimal32);
  tcase_add_test(tc1_1, s21_from_int_to_decimal33);
  tcase_add_test(tc1_1, s21_from_int_to_decimal34);
  tcase_add_test(tc1_1, s21_from_int_to_decimal35);
  tcase_add_test(tc1_1, s21_from_int_to_decimal36);
  tcase_add_test(tc1_1, s21_from_int_to_decimal37);
  tcase_add_test(tc1_1, s21_from_int_to_decimal38);
  tcase_add_test(tc1_1, s21_from_int_to_decimal39);
  tcase_add_test(tc1_1, s21_from_int_to_decimal40);
  tcase_add_test(tc1_1, s21_from_int_to_decimal41);
  tcase_add_test(tc1_1, s21_from_int_to_decimal42);
  tcase_add_test(tc1_1, s21_from_int_to_decimal43);
  tcase_add_test(tc1_1, s21_from_int_to_decimal44);
  tcase_add_test(tc1_1, s21_from_int_to_decimal45);
  suite_add_tcase(s1, tc1_1);

  return s1;
}