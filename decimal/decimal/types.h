#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct s21_int256 {
  s21_decimal decimals[2];
} s21_int256;

// Общее количество бит в decimal
#define MAX_BITS 128
// Общее количество бит в одном элементе массива
#define MAX_BLOCK_BITS 32
// Биты мантисы
#define MAX_BLOCK_NUMBER 96

typedef union {
  unsigned int i;
  struct {
    uint32_t empty_part_2 : 16;
    uint32_t power : 8;
    uint32_t empty_part_1 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit3;

typedef enum decimal_sign { POSITIVE = 0, NEGATIVE = 1 } s21_decimal_sign;

#endif  //  _TYPES_H_
