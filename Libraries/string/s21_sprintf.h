#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include "s21_string.h"

typedef struct {
  int minus; //к левому краю
  int plus; // знак
  int space; // +символ под знак
  int hash; // вывод 16 и 8 ричных чисел в формате 0x и 0 соответственно
  int zero; // заполняет свободное простран
  int width; // ширина
  int accuracy; // точность
  char length; // тип переменной (%lf Lf Ld и тд)
  int number_system; // система счисления
  int flag_to_size; // если число отрицательное или есть + или space
  int dot; // наличие точки
  int upper_case; // если спецификатор - буква в верхнем регистре (G E F X)
  int g; // если спецификатор g есть
  int e; // если необходимо записать число в научной натации
}Spec;

const char *get_specs(const char *format, Spec * specs);
const char *get_width(const char *format, int *width, va_list *atrgumenst);
const char *set_specs(Spec *specs, const char *format, va_list *atrgumenst);
int add_sym_to_str(char *str, int *i, char symbol);
long add_space_plus_minus(Spec specs, long double num, int *i, char *str_to_num, int *flag_to_size, long int *size);
int add_buffer_to_string(int width, int *i, char *buffer, char *str);
int invert_num(long int *num_int, long double *num_double);
Spec set_number_system(Spec specs, char format);
char get_num_char(int num, int upper_case);
Spec set_specs_for_double(Spec specs, char format);
int add_zero_to_str(Spec specs, char *str_to_num, s21_size_t size, int *i, int flag);

char *parser(char *str, char *src, const char *format, Spec specs, va_list *arguments);

char *print_decimal(char *str, Spec specs, va_list *arguments);
s21_size_t get_size_to_decimal(Spec *specs, long int num);
int decimal_to_string(Spec specs, long int num, char *str_to_num, s21_size_t size_to_decimal);

char *print_u(char *str, Spec specs, char format, va_list *argumets);
s21_size_t get_buf_size_unsigned_decimal(Spec specs, unsigned long int num);
int unsigned_decimal_to_string(char *buffer, Spec specs, unsigned long int num, s21_size_t size_to_num);

char *print_c(char *str, Spec specs, int symbol);

char *print_s(char *str, Spec specs, va_list *arguments);

char *print_p(char *str, Spec *specs, va_list *arguments);

char *print_double(char *str, Spec specs, char format, va_list *argumets);
int add_sym_from_double_to_str(char *str_to_double, Spec specs, int accuracy, int flag_to_dot, s21_size_t size_to_double, int *i, long double frac, long double integer);
s21_size_t get_size_to_double(Spec *specs, long double num);
s21_size_t is_nan_or_inf(char *str, Spec specs, long double num, s21_size_t size_to_double, int e);
char *print_e_g(char *str, Spec specd, char format, va_list *arguments);
long double normalize(long double *num,  Spec *specs);
Spec cutter(Spec specs, long double num);
s21_size_t get_size_to_e_g(Spec *specs, long double num);
int double_to_string(char *str_to_double, Spec specs, long double num, s21_size_t size_to_double, int e);

#endif