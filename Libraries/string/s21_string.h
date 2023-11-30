#ifndef S21_STRING_H
#define S21_STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_sprintf.h"

#define S21_NULL (void*)0
typedef unsigned long s21_size_t;

// Function is used to returns length of string
s21_size_t s21_strlen(const char* str);
// Function is used to search for a specific character in a block of memory.
const void* s21_memchr(const void* str, int c, s21_size_t n);
// Function is used to compares two memory blocks
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
// Function is used to copy memory from src to dest
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
// Function is used to fill a block of memory with a particular value
void* s21_memset(void* str, int c, s21_size_t n);
// Function is used to concatenate a specified number of characters from one
// string to the end of another
char* s21_strncat(char* dest, const char* src, s21_size_t n);
// Function is used to find the first occurrence of a specified character in a
// string
char* s21_strchr(const char* str, int c);
// Function is used to compare a specified number of characters from two
// strings.
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
// Function is used to copy a specified number of characters from one string to
// another.
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
// Function in C is used to find the length of the initial segment of a string
// that consists of characters not in a specified set
s21_size_t s21_strcspn(const char* str1, const char* str2);
// Function is used to obtain a string representation of an error number
char* s21_strerror(int errnum);
// Function is used to locate the first occurrence in a string of any character
// from a specified set of characters
char* s21_strpbrk(const char* str1, const char* str2);
// Function is used to find the last occurrence of a specified character in a
// string
char* s21_strrchr(const char* str, int c);
// Function is used to find the first occurrence of a substring within another
// string
char* s21_strstr(const char* haystack, const char* needle);
// Function is used to tokenize (split) a string into a series of tokens
char* s21_strtok(char* str, const char* delim);
// Function is used to cancatinate two strings
char* s21_strcat(char* dest, const char* src);


// Function is used to write formatted data to a string
int s21_sprintf(char* str, const char* format, ...);


// Function in used to convert each character in the string to uppercase
void* s21_to_upper(const char* str);
// Function in used to convert each character in the string to lowercase
void* s21_to_lower(const char* str);
// Function in used to insert one string into another at a specific index
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
// Function in used to trim characters from a given string
void* s21_trim(const char* src, const char* trim_chars);

#endif  // S21_STRING_H
