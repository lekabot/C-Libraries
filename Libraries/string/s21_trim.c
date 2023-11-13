#include "s21_string.h"

static int right_trim(const char* src, const char* trim_chars) {
   int flag = -1;
   s21_size_t i = s21_strlen(src) - 1;
   for (; i >= 0; i--) {
       int same = 0;
       for (int j = 0; trim_chars[j]; j++) {
           if (src[i] == trim_chars[j]) {
               same = 1;
           }
       }
       if (same != 1) {
           flag = (int)i;
           break;
       }
   }
   return flag;
}

static int left_trim(const char* src, const char* trim_chars) {
   int flag = -1;
   for (int i = 0; src[i] != 0; i++) {
       int same = 0;
       for (int j = 0; trim_chars[j]; j++) {
           if (src[i] == trim_chars[j]) {
               same = 1;
           }
       }
       if (same != 1) {
           flag = i;
           break;
       }
   }
   return flag;
}

void* s21_trim(const char* src, const char* trim_chars) {
   int left = left_trim(src, trim_chars);
   int right = right_trim(src, trim_chars);
   char* cut = S21_NULL;
   if (right - left > 0) {
       cut = (char*)calloc(right - left, 1/8);
       if (cut != S21_NULL) {
           for (int k = 0; left <= right; left++, k++) cut[k] = src[left];
       }
   }
   return cut;
}