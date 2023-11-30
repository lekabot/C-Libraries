#include "s21_sprintf.h"

const char *get_width(const char *format, int *width, va_list *atrgumenst) {
    *width = 0;
    if (*format == '*') {
        *width = va_arg(*atrgumenst, int);
        format++;
    }
    while (format) {
        if ('0' <= *format && *format <= '9') {
            *width *= 10;
            *width += *format - '0';
        } else {
            break;
        }
        format++;
    }
    return format;
}

const char *get_specs(const char *format, Spec * specs) {
    while (format) {
        if (*format == '+')
            specs->plus = 1;
        else if (*format == '-')
            specs->minus = 1;
        else if (*format == '#')
            specs->hash = 1;
        else if (*format == ' ')
            specs->space = 1;
        else if (*format == '0')
            specs->zero = 1;
        else
            break;
        format++;
    }
    specs->space = (specs->space && !specs->plus);
    specs->zero = (specs->zero && !specs->minus);
    return format;
}

const char *set_specs(Spec *specs, const char *format, va_list *atrgumenst) {
    format = get_specs(format, specs);
    format = get_width(format, &specs->width, atrgumenst);
    if (*format == '.') {
        specs->dot = 1;
        specs->zero = 0;
        format += 1;
        format = get_width(format, &specs->accuracy, atrgumenst);
    }
   if (*format == 'L')
        specs->length = 'L';
    else if (*format == 'l')
        specs->length = 'l';
    else if (*format == 'h')
        specs->length = 'h';
    if (specs->length != 0) format += 1;

    if(specs->width < 0) {
        specs->width = -specs->width;
        specs->minus = 1;
    }
}

char *parser(char *str, char *src, const char *format, Spec specs, va_list *arguments) {
    if (*format == 'd' || *format == 'i') {
        str = print_decimal(str, specs, arguments);
    } else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X') {
        specs = set_number_system(specs, *format);
        str = print_u(str, specs, *(format - 1), arguments);
    } else if (*format == 'c') {
        int symbol = va_arg(*arguments, int);
        str = print_c(str, specs, symbol);
    } else if (*format == 's') {
        str = print_s(str, specs, arguments);
    } else if (*format == 'p') {
        str = print_p(str, &specs, arguments);
    } else if (*format == 'n') {
        int *n = va_arg(*arguments, int *);
        *n = (int)(str - src);
    } else if (*format == 'f' || *format == 'F') {
        specs = set_specs_for_double(specs, *format);
        str = print_double(str, specs, *(format - 1), arguments);
    } else if (*format == 'e' || *format == 'E' || *format == 'g' || *format == 'G') {
        specs = set_specs_for_double(specs, *format);
        str = print_e_g(str, specs, *(format - 1), arguments);
    } else if (*format == '%') {
        str = print_c(str, specs, '%');
    } else {
        str = S21_NULL;
    }
    if (!str) *src = '\0';
    return str;
}

char *print_decimal(char *str, Spec specs, va_list *arguments) {
    long int num = 0;
    if (specs.length = 'l') {
        num = (long int)va_arg(*arguments, long int);
    } else if (specs.length == 'h') {
        num = (long int)va_arg(*arguments, short);
    } else {
        num = (int)va_arg(*arguments, int);
    }
    s21_size_t size_to_decimal = get_size_to_decimal(&specs, num);
    char *str_to_num = malloc(sizeof(char) * size_to_decimal);
    if (str_to_num) {
        int i = decimal_to_string(specs, num, str_to_num, size_to_decimal);
        for (int j = i - 1; j >= 0; j--) {
            *str = str_to_num[j];
            str++;
        }
        while (i < specs.width) {
            *str = ' ';
            str++;
        }
    }
    if (str_to_num) free(str_to_num);
    return str;
}

s21_size_t get_size_to_decimal(Spec *specs, long int num) {
    s21_size_t result = 0;
    long int copy_num = num;
    if (copy_num < 0) copy_num = -copy_num;
    while (copy_num > 0) {
        copy_num /= 10;
        result++;
    }
    if (copy_num == 0 && result == 0 && (specs->accuracy || specs->width || specs->space)) {
        result++;
    }
    if ((s21_size_t)specs->width > result) result = specs->width;
    if ((s21_size_t)specs->accuracy > result) result = specs->accuracy;
    if (specs->space || specs->plus || num < 0) {
        specs->flag_to_size = 1;
        result++;
    }
    if (result == 0 && copy_num == 0 && !specs->accuracy && !specs->width && !specs->space && !specs->dot) {
        result++;
    }
    return result;
}

int decimal_to_string(Spec specs, long int num, char *str_to_num, s21_size_t size_to_decimal) {
    int flag = 0;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    int i = 0;
    long int copy_num = num;
    
    if ((copy_num == 0 && (specs.accuracy || specs.width || specs.space)) || 
        (copy_num == 0 && !specs.accuracy && !specs.width && !specs.space && !specs.dot)) {
        char sym = copy_num % specs.number_system + '0';
        str_to_num[i] = sym;
        i++;
        size_to_decimal--;
        copy_num /= 10;
    }

    while (copy_num && str_to_num && size_to_decimal) {
        char sym = get_num_char(copy_num % specs.number_system, specs.upper_case);
        str_to_num[i] = sym;
        i++;
        size_to_decimal--;
        copy_num /= 10;
    }

    if (flag) num = -num;

    if (specs.accuracy - i > 0) {
        specs.accuracy -= i;
        specs.zero = 1;
    } else {
        flag = 1;
    }
    if (size_to_decimal == 1 && specs.zero == 1 && specs.flag_to_size == 1)
        specs.zero = 0;
    // zero
    while (specs.zero && str_to_num && (size_to_decimal - specs.flag_to_size > 0) && (specs.accuracy || flag)) {
        if (size_to_decimal == 1 && specs.flag_to_size == 1)
            break;
        str_to_num[i] = '0';
        i++;
        size_to_decimal--;
        specs.accuracy--;
    }
    // +/-/space
    if (specs.space && num >= 0 && size_to_decimal) {
        str_to_num[i] = ' ';
        i++;
        size_to_decimal--;
    }
    if (num < 0 && size_to_decimal) {
        str_to_num[i] = '-';
        i++;
        size_to_decimal--;
    }
    if (num > 0 && specs.plus && size_to_decimal) {
        str_to_num[i] = '+';
        i++;
        size_to_decimal--;
    }
    // осталось свободное место в строке
    if (size_to_decimal > 0 && specs.minus == 0) {
        while ((size_to_decimal - specs.flag_to_size > 0) && str_to_num) {
            str_to_num[i] = ' ';
            i++;
            size_to_decimal--;
        }
    }
    return i;
}

char get_num_char(int num, int upper_case) {
    char flag = '0';
    switch (num) {
    case 10:
        flag = (char)('a' - upper_case * 32);
        break;
    case 11:
        flag = (char)('b' - upper_case * 32);
        break;
    case 12:
        flag = (char)('c' - upper_case * 32);
        break;
    case 13:
        flag = (char)('d' - upper_case * 32);
        break;
    case 14:
        flag = (char)('e' - upper_case * 32);
        break;
    case 15:
        flag = (char)('f' - upper_case * 32);
        break;
    }
    if ( 0 <= num && num <= 9) flag = (char)(num + 48);
    return flag;
}

Spec set_number_system(Spec specs, char format) {
    if (format == 'o') {
        specs.number_system = 8;
    } else if (format = 'x' || format == 'X') {
        specs.number_system = 16;
    }
    if (format == 'X') specs.upper_case = 1;
    return specs;
}

char *print_u(char *str, Spec specs, char format, va_list *argumets) {
    unsigned long int num = 0;
    if (format == 'l') {
        num = (unsigned long int)va_arg(*argumets, unsigned long int);
    } else if (format == 'h') {
        num = (unsigned short)va_arg(*argumets, unsigned int);
    } else {
        num = (unsigned int)va_arg(*argumets, unsigned int);
    }

    s21_size_t size_to_num = get_buf_size_unsigned_decimal(specs, num);
    char *buffer = (char*)malloc(sizeof(char) * size_to_num);
    if (buffer) {
        int i = unsigned_decimal_to_string(buffer, specs, num, size_to_num);
        for (int j = i - 1; j >= 0; j--) {
            *str = buffer[j];
            str++;
        }
        while ((i < specs.width)) {
            *str = ' ';
            str++;
        }
        
    }
    if (buffer) free(buffer);
    return str;
}

s21_size_t get_buf_size_unsigned_decimal(Spec specs, unsigned long int num) {
        s21_size_t result = 0;
    unsigned long int copy_num = num;

    while (copy_num > 0) {
        copy_num /= 10;
        result++;
    }

    if (copy_num == 0 && result == 0 && (specs.accuracy || specs.width || specs.space)) {
        result++;
    }

    if ((s21_size_t)specs.width > result) result = specs.width;
    if ((s21_size_t)specs.accuracy > result) result = specs.accuracy;

    if (specs.space || specs.plus) {
        specs.flag_to_size = 1;
        result++;
    }

    if (result == 0 && copy_num == 0 && !specs.accuracy && !specs.width && !specs.space && !specs.dot) {
        result++;
    }

    return result;
}

// тут может ломаться
int unsigned_decimal_to_string(char *buffer, Spec specs, unsigned long int num, s21_size_t size_to_num) {
    int i = 0;
    int flag = 0;
    unsigned long int copy_num = num;

    if ((specs.hash && specs.number_system == 8)) {
        specs.flag_to_size = 1;
    } else if (specs.hash && specs.number_system == 16) {
        specs.flag_to_size = 2;
    }

    while (copy_num && buffer && size_to_num) {
        char sym = get_num_char(copy_num % specs.number_system, specs.upper_case);
        buffer[i] = sym;
        i++;
        size_to_num--;
        copy_num /= 10;
    }

    if (flag) num = -num;

    if (specs.accuracy - i > 0) {
        specs.accuracy -= i;
        specs.zero = 1;
    } else {
        flag = 1;
    }
    if (size_to_num == 1 && specs.zero == 1 && specs.flag_to_size == 1)
        specs.zero = 0;

    while (specs.zero && buffer && (size_to_num - specs.flag_to_size > 0) && (specs.accuracy || flag)) {
        if (size_to_num == 1 && specs.flag_to_size == 1)
            break;
        buffer[i] = '0';
        i++;
        size_to_num--;
        specs.accuracy--;
    }

    if (specs.hash && specs.number_system == 8) {
        buffer[i] = '0';
        i++;
        size_to_num--;
    } else if (specs.hash && specs.number_system == 16 && specs.upper_case) {
        buffer[i] = 'X';
        i++;
        size_to_num--;
        buffer[i] = '0';
        i++;
        size_to_num--;
    } else if (specs.hash && specs.number_system == 16 && specs.upper_case) {
        buffer[i] = 'X';
        i++;
        size_to_num--;
        buffer[i] = '0';
        i++;
        size_to_num--;
    }

    if (size_to_num > 0 && specs.minus == 0) {
        while ((size_to_num - specs.flag_to_size > 0) && buffer) {
            buffer[i] = ' ';
            i++;
            size_to_num--;
        }
    }
    return i;
}

char *print_c(char *str, Spec specs, int symbol) {
    char *ptr = S21_NULL;
    int i = 0;
    while (specs.width - 1 > 0 && !specs.minus) {
        *str = ' ';
        str++;
        i++;
        specs.width--;
    }
    if (symbol <= 127) {
        *str = symbol;
        str++;
        i++;
        while (specs.width - 1 > 0 && specs.minus) {
            *str = ' ';
            str++;
            i++;
            specs.width--;
        }
        ptr = str;
    }
    return ptr;
}

char *print_s(char *str, Spec specs, va_list *arguments) {
    char *ptr = str;
    char *string = va_arg(*arguments, char *);
    
    if (string) {
        int tmp = specs.width, i = 0;
        if ((s21_size_t)specs.width < s21_strlen(string)) {
            specs.width = s21_strlen(string);
        }
        int blank = specs.width - s21_strlen(string);

        if (specs.accuracy == 0) specs.accuracy = specs.width;

        if (specs.accuracy != 0 && specs.accuracy < tmp) {
            blank = tmp - specs.accuracy;
        }
        while (blank && !specs.minus){
            *str = ' ';
            str++;
            blank--;
        }

        while (*string != '\0') {
            if (!specs.accuracy) break;
            *str = *string;
            str++;
            string++;
            i++;
            specs.accuracy--;
        }
        
        while (blank && specs.minus) {
            *str = ' ';
            str++;
            blank--;
        }
    } else {
        str = s21_memcpy(str, "(null)", 6);
        str += 6;
    }
    if (ptr) ptr = str;
    return ptr;
}

char *print_p(char *str, Spec *specs, va_list *arguments) {
    unsigned long int ptr = (unsigned long int)va_arg(*arguments, unsigned long int);
    specs->number_system = 16;
    specs->hash = 1;
    specs->upper_case = 0;

    s21_size_t size_to_num = get_buf_size_unsigned_decimal(*specs, ptr);
    char *buffer = (char*)malloc(sizeof(char) * size_to_num);
    if (buffer) {
        int i = unsigned_decimal_to_string(buffer, *specs, ptr, size_to_num);
        str += add_buffer_to_string(specs->width, &i, buffer, str);
    }
    if (buffer) free(buffer);
    return str;
}

//тут тоже может ломаться
int add_buffer_to_string(int width, int *i, char *buffer, char *str) {
    int len = *i;
    if (width > len) {
        int padding = width - len;
        while (*str && padding > 0) {
            *str = ' ';
            str++;
            padding--;
        }
        while (*buffer) {
            *str = *buffer;
            str++;
            buffer++;
        }
    } else {
        while (*buffer) {
            *str = *buffer;
            str++;
            buffer++;
        }
    }

    return len + width;
}

Spec set_specs_for_double(Spec specs, char format) {
    if (format == 'g' || format == 'G') {
        specs.g = 1;
    } else if (format == 'e' || format == 'E') {
        specs.e = 1;
    }
    if (format == 'G' || format == 'E' || format == 'F') {
        specs.upper_case = 1;
    }
    return specs;
}

char *print_double(char *str, Spec specs, char format, va_list *argumets) {
    long double num = 0;
    int e = 0;
    if (format == 'L') {
        num = va_arg(*argumets, long double);
    } else {
        num = va_arg(*argumets, double);
    }
    
    s21_size_t size_to_double = get_size_to_double(&specs, num);
    char *str_to_double = malloc(sizeof(char) * size_to_double);
    if (str_to_double) {
        int i = double_to_string(str_to_double, specs, num, size_to_double, e);
        str += add_buffer_to_string(specs.width, &i, str_to_double, str);
    }
    if (str_to_double) free;
    return str;
}

// Может ломаться
s21_size_t get_size_to_double(Spec *specs, long double num) {
    s21_size_t result = 0;
    if (num == 0 && (specs->accuracy || specs->width || specs->space)) {
        result++;
    }

    if (num != 0) {
        long double int_part = fabs((long long)num);

        while (int_part >= 1) {
            int_part /= 10;
            result++;
        }

        if (specs->accuracy > 0) {
            result++;
        }

        long double frac_part = fabs(num - (long long)num);
        while (frac_part > 0 && specs->accuracy > 0) {
            frac_part *= 10;
            frac_part = fmod(frac_part, 1.0);
            result++;
            specs->accuracy--;
        }
    }

    if ((s21_size_t)specs->width > result) {
        result = specs->width;
    }

    if (specs->space || specs->plus) {
        specs->flag_to_size = 1;
        result++;
    }

    if (result == 0 && num == 0 && !specs->accuracy && !specs->width && !specs->space && !specs->dot) {
        result++;
    }

    return result;
}

int double_to_string(char *str_to_double, Spec specs, long double num, s21_size_t size_to_double, int e) {
    //Додумать
    int i = is_nan_or_inf(str_to_double, num, specs);
    if (!i) {
        if (specs.e) print_e(e, &size_to_double, str_to_double, specs, &i);
        int flag = 0;
        if (num < 0) {
            flag = 1;
            num = -num;
        }
    }

    long double integer = 0;
    long double frac = modfl(num, &integer);

    int accuracy = specs.accuracy;

    long double copy_frac = frac;
}

s21_size_t is_nan_or_inf(char *str, Spec specs, long double num, s21_size_t size_to_double, int e) {

}


char *print_e_g(char *str, Spec specs, char format, va_list *arguments) {
    
    long double num = 0;
    int e = 0;
    if (format == 'L') {
        num = va_arg(*arguments, long double);
    } else {
        num = va_arg(*arguments, double);
    }

    s21_size_t size = 0;
    if (specs.g) {
        specs = cutter(specs, num);
    }
    if (specs.e) {
        e = normalize(&num, &specs);
        if (e < 100)
            size += 2;
        else
            size += 3;
    }

    size += get_size_to_e_g(&specs, num);
    if ((int)size < specs.accuracy) size = specs.accuracy;
    if ((int)size < specs.width) size = specs.width;
    char *str_to_double = malloc(sizeof(char)*size);

    if (str_to_double) {
        int i = double_to_string(str_to_double, specs, num, size, e);
        str += add_buffer_to_string(specs.width, &i, str_to_double, str);
    }
    if (str_to_double) free;
    return str;
}

long double normalize(long double *num,  Spec *specs) {
    int i = 0;
    if (fabsl(*num) > 1) {
        while (fabsl(*num) > 10) {
            *num /= 10;
            i++;
            specs->e = 2;
        }
    } else {
        while (fabsl(*num) < 0.999999) {
            if (*num == 0) {
                specs->e = 2;
                break;
            }
            *num *= 10;
            i++;
            specs->e = 1;
        }
    }
    return i; 
}

//Приведения числа к крачайшей записи
Spec cutter(Spec specs, long double num) {
    Spec copy_specs = specs;
    long double copy_num = num;
    int e = normalize(&copy_num, &copy_specs);
    if (copy_specs.accuracy = 0 && !copy_specs.dot) copy_specs.accuracy = 6;
    if ((e <= 4 && copy_specs.e == 1) || (copy_specs.e == 2 && e < 6)) {
        copy_specs.e = 0;
    }
    return copy_specs;
}

// Может ломаться
s21_size_t get_size_to_e_g(Spec *specs, long double num) {
    s21_size_t result = 0;

    if (num == 0 && (specs->accuracy || specs->width || specs->space)) {
        result++;
    }

    if (num != 0) {
        long double int_part = fabs((long long)log10l(fabs(num)));

        while (int_part >= 1) {
            int_part /= 10;
            result++;
        }

        if (specs->accuracy > 0 || specs->hash) {
            result++;
        }

        long double frac_part = fabs(num - (long long)num);
        while (frac_part > 0 && specs->accuracy > 0) {
            frac_part *= 10;
            frac_part = fmodl(frac_part, 1.0);
            result++;
            specs->accuracy--;
        }

        int exponent = (int)log10l(fabs(num));
        if (num < 1 && num > -1) {
            exponent--;
        }

        long double exp_part = fabs(exponent);
        while (exp_part >= 1) {
            exp_part /= 10;
            result++;
        }

        result++;

        if (exponent < 0 || specs->plus) {
            result++;
        }
    }

    if ((s21_size_t)specs->width > result) {
        result = specs->width;
    }

    if (specs->space || specs->plus) {
        specs->flag_to_size = 1;
        result++;
    }

    if (result == 0 && num == 0 && !specs->accuracy && !specs->width && !specs->space && !specs->dot) {
        result++;
    }

    return result;
}
