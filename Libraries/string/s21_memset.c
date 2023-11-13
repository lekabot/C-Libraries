#include "s21_string.h"

void* s21_memset(void* str, int c, s21_size_t n) {
  uint8_t* __s = (uint8_t*)str;
  uint8_t __c = (uint8_t)c;
  for (s21_size_t i = 0; i < n; i++) {
    __s[i] = __c;
  }
  return (void*)__s;
}