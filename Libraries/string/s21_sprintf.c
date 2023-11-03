#include "s21_string.h"


static int int_to_str(char* str, int value) {
    int written_chars = 0;
    int temp = value;
    int num_digits = 0;
    if (temp == 0) {
        str[written_chars++] = '0';
        return 1;
    }
    if (temp < 0) {
        str[written_chars++] = '-';
        temp = -temp;
    }
    while (temp > 0) {
        num_digits++;
        temp /= 10;
    }
    for (int i = written_chars + num_digits - 1; i >= written_chars; i--) {
        str[i] = '0' + (value % 10);
        value /= 10;
    }
    written_chars += num_digits;
    return written_chars;
}


static int double_to_str(char* buffer, double value, int precision) {
    if (buffer == S21_NULL || precision < 0) {
        return S21_NULL;
    }
    if (value < 0) {
        *buffer++ = '-';
        value = -value;
    }
    int int_part = (int)value;
    int int_length = 0;
    do {
        buffer[int_length++] = '0' + int_part % 10;
        int_part /= 10;
    } while (int_part > 0);
    for (int i = 0; i < int_length / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[int_length - i - 1];
        buffer[int_length - i - 1] = temp;
    }
    if (precision > 0) {
        buffer[int_length++] = '.';
    }
    value -= (int)value;
    int digit = 0;
    for (int i = 0; i < precision; i++) {
        value *= 10;
        digit = (int)value;

        buffer[int_length++] = '0' + digit;
        value -= digit;
    }
    buffer[int_length] = '\0';

    return int_length;
}


static int uint_to_str(char* str, unsigned int value) {
    int written_chars = 0;
    int temp = value;
    int num_digits = 0;
    if (temp == 0) {
        str[written_chars++] = '0';
        return 1;
    }
    while (temp > 0) {
        num_digits++;
        temp /= 10;
    }
    for (int i = written_chars + num_digits - 1; i >= written_chars; i--) {
        str[i] = '0' + (value % 10);
        value /= 10;
    }
    written_chars += num_digits;
    return written_chars;
}

//static void format_double_exponential(char* str, double value, int precision, int* written_chars) {
//
//}

int s21_sprintf(char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);

    int written_chars = 0;

    while (*format) {
        if (*format != '%') {
            str[written_chars++] = *format;
        }
        else {
            format++;
            if (*format == '.') {
                format++;
                int precision = 0;
                while (*format >= '0' && *format <= '9') {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
                switch (*format) {
                    case 'f': {
                        double value = va_arg(args, double);
                        written_chars += double_to_str(str + written_chars, value, precision);
                        break;
                    }
 /*                   case 'e': {
                        double value = va_arg(args, double);
                        format_double_exponential(str + written_chars, value, precision, &written_chars);
                        break;
                    }*/
                    default:
                        str[written_chars++] = '%';
                        str[written_chars++] = '.';
                        while (precision > 0) {
                            int digit = precision % 10;
                            str[written_chars++] = '0' + digit;
                            precision /= 10;
                        }
                        str[written_chars++] = *format;
                        break;
                    }
            }
            else {
                switch (*format) {
                case 'c': {
                    char value = va_arg(args, int);
                    str[written_chars++] = value;
                    break;
                }
                case 'd': {
                    int value = va_arg(args, int);
                    written_chars += int_to_str(str + written_chars, value);
                    break;
                }
                case 'f': {
                    double value = va_arg(args, double);
                    written_chars += double_to_str(str + written_chars, value, 6);
                    break;
                }
                case 's': {
                    const char* value = va_arg(args, const char*);
                    while (*value) {
                        str[written_chars++] = *value;
                        value++;
                    }
                    break;
                }
                case 'u': {
                    unsigned int value = va_arg(args, unsigned int);
                    written_chars += uint_to_str(str + written_chars, value);
                    break;
                }
                case '%': {
                    str[written_chars++] = '%';
                    break;
                }
                //case 'e': {
                //    double value = va_arg(args, double);
                //    int precision = 6;
                //    format_double_exponential(str + written_chars, value, precision, &written_chars);
                //    break;
                //}
                //case 'g': {
                //    double value = va_arg(args, double);

                //}
                default: {
                    str[written_chars++] = '%';
                    str[written_chars++] = *format;
                    break;
                }
                }
            }
        }
        format++;
    }

    va_end(args);
    str[written_chars] = '\0';
    return written_chars;
}
