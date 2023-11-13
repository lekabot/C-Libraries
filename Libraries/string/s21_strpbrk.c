#include "s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  for (const char* __s1 = str1; *__s1 != '\0'; __s1++) {
    for (const char* __s2 = str2; *__s2 != '\0'; __s2++) {
      if (*__s1 == *__s2) {
        return (char*)__s1;
      }
    }
  }
  return S21_NULL;
}