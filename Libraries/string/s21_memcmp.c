#include "s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
   uint8_t* __s1 = (uint8_t*)str1;
   uint8_t* __s2 = (uint8_t*)str2;
   for (s21_size_t i = 0; i < n; i++) {
       if (__s1[i] < __s2[i]) {
           return __s1[i] - __s2[i];
       } else if (__s1[i] > __s2[i]){
           return __s1[i] - __s2[i];
       }
   }
   return 0;
}