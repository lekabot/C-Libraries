#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
    char specifiers[] = "diuoxXcsnpfFeEgG%";
    char *src = str;
    va_list argumets;
    va_start(argumets, format);
    
    while (*format) {
        if (*format == '%') {
            format++;
            Spec specs = {0};
            specs.number_system = 10; // устанавливаем по стандарту систему счисления
            format = set_specs(&specs, format, &argumets);
            while (!s21_strchr(specifiers, *format)) format++;
            str = parser(str, src, format, specs, &argumets);
        } else {
            *str = *format;
            str++;
        }
        format++;
    }
    *str = '\0';
    va_end(argumets);
    return (str - src);
}