#include "s21_string.h"

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  uint8_t* __d = (uint8_t*)dest;
  uint8_t* __s = (uint8_t*)src;
  for (size_t i = 0; i < n; i++) {
    __d[i] = __s[i];
  }
  return __d;
}