#ifndef _HELPERS_H_
#define _HELPERS_H_

#include "../binary/binary.h"
#include "../types.h"
// constructor.c

void decimal_clear(s21_decimal *decimal);
s21_decimal decimal_get_zero(void);
s21_decimal decimal_create_from_array(int data_1, int data_2, int data_3,
                                      int data_4);
// s21_decimal decimal_create_from_date(int sign, int power, int data_1, int
// data_2, int data_3); s21_decimal decimal_create_from_strings(char* str_1,
// char* str_2, char* str_3, char* str_4);
int decimal_set_bits_according_to_string(int *bits, char *str);
s21_decimal decimal_get_inf(void);
void decimal_clear_service_bits(s21_decimal *decimal);
s21_decimal decimal_get_one(void);
s21_decimal decimal_get_ten(void);
s21_decimal decimal_get_point_five(void);
s21_decimal int128_get_ten_pow(int pow);
s21_decimal decimal_get_min(void);
s21_decimal decimal_get_max(void);
s21_decimal decimal_get_int_max(void);
s21_decimal decimal_get_int_min(void);
s21_int256 int256_create_from_decimal(s21_decimal value_1);

// helpers.c

int decimal_is_correct(s21_decimal decimal);
void decimal_set_sign(s21_decimal *decimal, int sign);
void decimal_set_power(s21_decimal *decimal, int power);
int decimal_get_empty1_in_service_bits(s21_decimal decimal);
int decimal_get_empty2_in_service_bits(s21_decimal decimal);
int decimal_get_power(s21_decimal decimal);
int decimal_get_sign(s21_decimal decimal);
int decimal_is_even(s21_decimal decimal);

static const s21_decimal all_ten_pows[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

#endif  // _HELPERS_H_
