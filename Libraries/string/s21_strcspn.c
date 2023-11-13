#include "s21_string.h"

s21_size_t s21_strcspn(const char* str1, const char* str2) {
  uint8_t* __s1 = (uint8_t*)str1;
  uint8_t* __s2;
  s21_size_t length = 0;
  while (*__s1) {
    __s2 = (uint8_t*)str2;
    while (*__s2) {
      if (*__s1 == *__s2) {
        return length;
      }
      __s2++;
    }
    __s1++;
    length++;
  }
  return length;
}