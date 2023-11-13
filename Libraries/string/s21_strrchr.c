#include "s21_string.h"

char* s21_strrchr(const char* str, int c) {
   s21_size_t __ls = s21_strlen(str);
   s21_size_t __lr = 0;
   for (s21_size_t i = __ls; i >= 0; i--) {
       if (str[i] == c) {
           __lr = i;
           break;
       }
   }
   if (__lr == 0) {
       return S21_NULL;
   }
   char* __a = (char*)malloc(__ls - __lr + 1);
   if (__a == S21_NULL) {
       return S21_NULL;
   }
   for (s21_size_t i = 0; i < __ls - __lr; i++) {
       __a[i] = str[__lr + i];
   }
   __a[__ls - __lr] = '\0';
   return __a;
}