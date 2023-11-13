#include "s21_string.h"

const void* s21_memchr(const void* str, int c, s21_size_t n) {
  uint8_t* char_str = (uint8_t*)str;
  uint8_t uc = (uint8_t)c;
  for (s21_size_t i = 0; i < n; i++) {
    if (char_str[i] == uc) {
      return (void*)(char_str + i);
    }
  }
  return S21_NULL;
}