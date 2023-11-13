#include "s21_string.h"

void* s21_to_upper(const char* str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t __l = s21_strlen(str);
  char* __a = (char*)malloc(__l + 1);
  if (__a == S21_NULL) {
    return S21_NULL;
  }
  for (s21_size_t i = 0; i < __l; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      __a[i] = str[i] - ('a' - 'A');
    } else {
      __a[i] = str[i];
    }
  }

  __a[__l] = '\0';
  return (void*)__a;
}