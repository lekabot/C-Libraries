#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
   static char* saveptr;
   char* token = str;
   if (str != S21_NULL) {
       while (*str && s21_strchr(delim, *str)) {
           str++;
       }
       token = str;
   } else {
       str = saveptr;
       if (str == S21_NULL) {
           return S21_NULL;
       }
       while (*str && s21_strchr(delim, *str)) {
           str++;
       }
   }
   token = str;
   while (*str && !s21_strchr(delim, *str)) {
       str++;
   }
   if (*str) {
       *str = '\0';
       saveptr = str + 1;
   } else {
       saveptr = S21_NULL;
   }
   return token;
}