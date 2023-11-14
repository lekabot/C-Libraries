#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include "s21_string.h"
#include <locale.h>

typedef struct {
    bool minus;
    bool plus;
    bool space;
    bool zero;
    bool hash;
    int precision;
    int is_precision_set;
    int width;
    char length;
    char specifier;
} Flags;

int s21_sprintf(char *str, const char *format, ...);

// helper functions
void whole_num_to_string(int64_t val, char *ret, int base);
void unsigned_num_to_string(uint64_t val, char *ret, int base);
bool check_integer_specifier(char c);
bool is_all_zeroes(char *buff);
void to_upper(char *str);
void prepend_ox(char *buff, Flags f);
void double_to_string(long double val, char *ret, Flags f);
void prepend_mantiss(char *str, int pow, char sign);
void remove_trailing_zeroes(char *buff);

// parse format
const char *get_Flags(const char *format, Flags *f);
const char *get_width(const char *format, Flags *f, va_list va);
const char *get_precision(const char *format, Flags *f, va_list va);
const char *get_length(const char *format, Flags *f);

// parse values
void handle_value(Flags f, char *buff, va_list va);
void parse_int(Flags, char *buff, va_list va);
void parse_unsigned(Flags f, char *buff, va_list va);
void parse_octal(Flags f, char *buff, va_list va);
void parse_hex(Flags f, char *buff, va_list va);
void parse_char(Flags f, char *buff, va_list va);
void parse_string(Flags f, char *buff, va_list va);
void parse_pointer(Flags f, char *buff, va_list va);
void parse_float(Flags f, char *buff, va_list va);
void parse_mantiss(Flags f, char *buff, va_list va);
void parse_float_g_G(Flags f, char *buff, va_list va);

// format values
void format_precision(char *buff, Flags f);
void format_Flags(char *buff, Flags f);
void format_gG_precision(char *buff, int precision);
void format_wchar(Flags f, char *buff, wchar_t w_c);
void format_char(Flags f, char *buff, char c);
void format_string(Flags f, char *buff, char *str);
void format_wide_string(Flags f, char *buff, wchar_t *wstr);

int s21_isdigit(char c);

#endif  //  SRC_S21_SPRINTF_H_