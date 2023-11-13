#include "s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  s21_size_t __l = n;
  while (__l--) {
    if (*str1 != *str2) {
      return (int)(unsigned char)(*str1) - (int)(unsigned char)(*str2);
    }
    if (*str1 == '\0') {
      break;
    }
  }
  return 0;
}