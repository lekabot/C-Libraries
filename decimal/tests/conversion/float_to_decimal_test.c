#include "../test_main.h"

START_TEST(s21_from_float_to_decimal1) {
#line 2

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal2) {
#line 19

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal3) {
#line 36

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal4) {
#line 53

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -2;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal5) {
#line 70

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal6) {
#line 87

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal7) {
#line 104

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal8) {
#line 121

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal9) {
#line 138

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal10) {
#line 155

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal11) {
#line 172

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal12) {
#line 189

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3;

  res.bits[0] = 0b00000000000000000000000000000011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal13) {
#line 206

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal14) {
#line 223

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal15) {
#line 240

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3.2;

  res.bits[0] = 0b00000000000000000000000000100000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000010000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal16) {
#line 257

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3.2;

  res.bits[0] = 0b00000000000000000000000000100000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000010000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal17) {
#line 274

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -3.2;

  res.bits[0] = 0b00000000000000000000000000100000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000010000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal18) {
#line 291

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3.2;

  res.bits[0] = 0b00000000000000000000000000100000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000010000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal19) {
#line 308

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1.234568E+07;

  res.bits[0] = 0b00000000101111000110000101010000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal20) {
#line 325

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1.234568E+07;

  res.bits[0] = 0b00000000101111000110000101010000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal21) {
#line 342

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1.234568E+07;

  res.bits[0] = 0b00000000101111000110000101010000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal22) {
#line 359

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1.234568E+07;

  res.bits[0] = 0b00000000101111000110000101010000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal23) {
#line 376

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 7.922816E+07;

  res.bits[0] = 0b00000100101110001110110100000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal24) {
#line 393

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.922816E+11;

  res.bits[0] = 0b01110111101010011101000000000000;
  res.bits[1] = 0b00000000000000000000000010111000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal25) {
#line 410

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.922817E+10;

  res.bits[0] = 0b01110010010111011110111100010000;
  res.bits[1] = 0b00000000000000000000000000010010;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal26) {
#line 427

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 7.95935E+09;

  res.bits[0] = 0b11011010011010100000101011110000;
  res.bits[1] = 0b00000000000000000000000000000001;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal27) {
#line 444

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 7.922817E+10;

  res.bits[0] = 0b01110010010111011110111100010000;
  res.bits[1] = 0b00000000000000000000000000010010;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal28) {
#line 461

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 6.654646E+08;

  res.bits[0] = 0b00100111101010100010111100011000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal29) {
#line 478

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2.798653;

  res.bits[0] = 0b00000000001010101011010000111101;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000001100000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal30) {
#line 495

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -9.798956E+15;

  res.bits[0] = 0b00111011100011001011100000000000;
  res.bits[1] = 0b00000000001000101101000000011001;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal32) {
#line 529

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -0.7754555;

  res.bits[0] = 0b00000000011101100101001100111011;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000001110000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal33) {
#line 546

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.92282E+16;

  res.bits[0] = 0b11001101001100011001000000000000;
  res.bits[1] = 0b00000001000110010111100110100000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal34) {
#line 563

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 3.232347E+16;

  res.bits[0] = 0b01010011010000100000110000000000;
  res.bits[1] = 0b00000000011100101101011000000110;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal35) {
#line 580

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.845155E+08;

  res.bits[0] = 0b00101110110000101100000110101100;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal36) {
#line 597

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 0;

  res.bits[0] = 0b00000000000000000000000000000000;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal37) {
#line 614

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal38) {
#line 631

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal39) {
#line 648

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal40) {
#line 665

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -1;

  res.bits[0] = 0b00000000000000000000000000000001;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal41) {
#line 682

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 7.922544E+12;

  res.bits[0] = 0b10011100011010111011110000000000;
  res.bits[1] = 0b00000000000000000000011100110100;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal42) {
#line 699

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.922354E+13;

  res.bits[0] = 0b10101010111101011010010100000000;
  res.bits[1] = 0b00000000000000000100100000001101;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal43) {
#line 716

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 7.922854E+11;

  res.bits[0] = 0b01110111111000111100101111000000;
  res.bits[1] = 0b00000000000000000000000010111000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal44) {
#line 733

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -7.922544E+11;

  res.bits[0] = 0b01110110000010101100011000000000;
  res.bits[1] = 0b00000000000000000000000010111000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000000000000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal45) {
#line 750

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2E-22;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000101100000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal46) {
#line 767

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = -2E-22;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b10000000000101100000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal47) {
#line 784

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2E-22;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000101100000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal48) {
#line 801

  float src1;
  s21_decimal res;
  s21_decimal our_res;

  src1 = 2E-22;

  res.bits[0] = 0b00000000000000000000000000000010;
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000101100000000000000000;

  s21_from_float_to_decimal(src1, &our_res);

  ck_assert_int_eq(s21_is_equal(res, our_res), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal2) {
  float f = -0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  int code = s21_from_float_to_decimal(f, &result);

  int sign_check = decimal_get_sign(check);
  int sign_result = decimal_get_sign(result);

  ck_assert_int_eq(code, CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal7) {
  float f = MIN_FLOAT_TO_CONVERT / 100000000;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal8) {
  float f = 2.2;
  int code = s21_from_float_to_decimal(f, NULL);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal9) {
  float f = MAX_FLOAT_TO_CONVERT * 100000000;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal10) {
  float f = 0.00000000000000000000000000000000001;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, CONVERSION_ERROR);
}
END_TEST

Suite *s21_from_float_to_decimal_tests(void) {
  Suite *s1 = suite_create("from_float_to_decimal_test");
  TCase *tc_core = tcase_create("from_float_to_decimal_test");

  suite_add_tcase(s1, tc_core);
  tcase_add_test(tc_core, s21_from_float_to_decimal1);
  tcase_add_test(tc_core, s21_from_float_to_decimal2);
  tcase_add_test(tc_core, s21_from_float_to_decimal3);
  tcase_add_test(tc_core, s21_from_float_to_decimal4);
  tcase_add_test(tc_core, s21_from_float_to_decimal5);
  tcase_add_test(tc_core, s21_from_float_to_decimal6);
  tcase_add_test(tc_core, s21_from_float_to_decimal7);
  tcase_add_test(tc_core, s21_from_float_to_decimal8);
  tcase_add_test(tc_core, s21_from_float_to_decimal9);
  tcase_add_test(tc_core, s21_from_float_to_decimal10);
  tcase_add_test(tc_core, s21_from_float_to_decimal11);
  tcase_add_test(tc_core, s21_from_float_to_decimal12);
  tcase_add_test(tc_core, s21_from_float_to_decimal13);
  tcase_add_test(tc_core, s21_from_float_to_decimal14);
  tcase_add_test(tc_core, s21_from_float_to_decimal15);
  tcase_add_test(tc_core, s21_from_float_to_decimal16);
  tcase_add_test(tc_core, s21_from_float_to_decimal17);
  tcase_add_test(tc_core, s21_from_float_to_decimal18);
  tcase_add_test(tc_core, s21_from_float_to_decimal19);
  tcase_add_test(tc_core, s21_from_float_to_decimal20);
  tcase_add_test(tc_core, s21_from_float_to_decimal21);
  tcase_add_test(tc_core, s21_from_float_to_decimal22);
  tcase_add_test(tc_core, s21_from_float_to_decimal23);
  tcase_add_test(tc_core, s21_from_float_to_decimal24);
  tcase_add_test(tc_core, s21_from_float_to_decimal25);
  tcase_add_test(tc_core, s21_from_float_to_decimal26);
  tcase_add_test(tc_core, s21_from_float_to_decimal27);
  tcase_add_test(tc_core, s21_from_float_to_decimal28);
  tcase_add_test(tc_core, s21_from_float_to_decimal29);
  tcase_add_test(tc_core, s21_from_float_to_decimal30);
  tcase_add_test(tc_core, s21_from_float_to_decimal32);
  tcase_add_test(tc_core, s21_from_float_to_decimal33);
  tcase_add_test(tc_core, s21_from_float_to_decimal34);
  tcase_add_test(tc_core, s21_from_float_to_decimal35);
  tcase_add_test(tc_core, s21_from_float_to_decimal36);
  tcase_add_test(tc_core, s21_from_float_to_decimal37);
  tcase_add_test(tc_core, s21_from_float_to_decimal38);
  tcase_add_test(tc_core, s21_from_float_to_decimal39);
  tcase_add_test(tc_core, s21_from_float_to_decimal40);
  tcase_add_test(tc_core, s21_from_float_to_decimal41);
  tcase_add_test(tc_core, s21_from_float_to_decimal42);
  tcase_add_test(tc_core, s21_from_float_to_decimal43);
  tcase_add_test(tc_core, s21_from_float_to_decimal44);
  tcase_add_test(tc_core, s21_from_float_to_decimal45);
  tcase_add_test(tc_core, s21_from_float_to_decimal46);
  tcase_add_test(tc_core, s21_from_float_to_decimal47);
  tcase_add_test(tc_core, s21_from_float_to_decimal48);

  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal2);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal6);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal7);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal8);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal9);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal10);

  return s1;
}
