#include "s21_string.h"

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
   s21_size_t __ld = s21_strlen(dest);
   s21_size_t __la = __ld + n;
   char* __a = (char*)malloc(__la + 1);
   if (__a == S21_NULL) {
       return S21_NULL;
   }
   for (s21_size_t i = 0; i < __ld; i++) {
       __a[i] = dest[i];
   }
   for (s21_size_t i = 0; i < n; i++) {
       __a[__ld + i] = src[i];
   }
   __a[__la] = '\0';
   return __a;
}