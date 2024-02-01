#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  s21_size_t lsrc = s21_strlen(src);
  s21_size_t lstr = s21_strlen(str);
  char* res = (char*)malloc(lsrc + lstr + 1);

  for (size_t i = 0; i < start_index; i++) {
    res[i] = src[i];
  }
  for (size_t i = start_index, j = 0; j < lstr; i++, j++) {
    res[i] = str[j];
  }
  for (size_t i = start_index + lstr, j = start_index; j < lsrc; i++, j++) {
    res[i] = src[j];
  }
  res[lsrc + lstr] = '\0';
  return (void*)res;
}
