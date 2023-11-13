#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
   s21_size_t __lh = s21_strlen(haystack);
   s21_size_t __ln = s21_strlen(needle);
   for (int i = 0; i < __lh; i++) {
       s21_size_t j;
       for (j = 0; j < __ln; j++) {
           if (haystack[i + j] != needle[j]) {
               break;
           }
       }
       if (j == __ln) {
           return (char*)(haystack + i);
       }
   }
   return S21_NULL;
}