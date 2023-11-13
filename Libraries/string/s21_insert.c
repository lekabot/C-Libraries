#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
   s21_size_t __lsrc = s21_strlen(src);
   s21_size_t __lstr = s21_strlen(str);
   char* __a = (char*)malloc(__lsrc + __lstr + 1);

   for (size_t i = 0; i < start_index; i++) {
       __a[i] = src[i];
   }
   for (size_t i = start_index, j = 0; j < __lstr; i++, j++) {
       __a[i] = str[j];
   }
   for (size_t i = start_index + __lstr, j = start_index; j < __lsrc; i++, j++) {
       __a[i] = src[j];
   }
   __a[__lsrc + __lstr] = '\0';
   return (void*)__a;
}