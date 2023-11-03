#include "s21_string.h"

typedef struct {
    float mantissa;
    int exponent;
} DecimalFloatParam;

static bool parse_decimal_float(const char* str, void* arg) {
    DecimalFloatParam* param = (DecimalFloatParam*)arg;
    float* mantissa = &param->mantissa;
    int* exponent = &param->exponent;

    while (*str && (*str == ' ' || *str == '\t')) {
        str++;
    }

    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    if (*str >= '0' && *str <= '9') {
        *mantissa = 0;
        while (*str >= '0' && *str <= '9') {
            *mantissa = (*mantissa * 10) + (*str - '0');
            str++;
        }

        if (*str == '.') {
            str++;
            float divisor = 10.0f;
            while (*str >= '0' && *str <= '9') {
                *mantissa += (*str - '0') / divisor;
                divisor *= 10.0f;
                str++;
            }
        }

        *mantissa *= sign;

        if (*str == 'e' || *str == 'E') {
            str++;
            int eSign = 1;
            if (*str == '-') {
                eSign = -1;
                str++;
            } else if (*str == '+') {
                str++;
            }

            int eValue = 0;
            while (*str >= '0' && *str <= '9') {
                eValue = (eValue * 10) + (*str - '0');
                str++;
            }
            *exponent = eValue * eSign;
        }

        return true;
    }

    return false;
}


static int str_to_float(const char* str, float* arg) {
    while (*str && (*str == ' ' || *str == '\t')) {
        str++;
    }
    
    int sign = 1;
    
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1:1;
        str++;
    }
    
    if (*str >= '0' && *str <= '9') {
        *arg = 0;
        while (*str >= '0' && *str <= '9') {
            *arg = (*arg * 10) + (*str - '0');
            str++;
        }
        if (*str == '.') {
            str++;
            float divisior = 10.0f;
            while (*str >= '0' && *str <= '9') {
                *arg += (*str - '0') / divisior;
                divisior *= 10.0f;
                str++;
            }
        }
        *arg *= sign;
        *arg = roundf(*arg * 100000.0) / 100000.0;
        return 1;
    }
    
    return 0;
}


static int str_to_int(const char* str, int* arg) {
    while (*str && (*str == ' ' || *str == '\t')) {
        str++;
    }
    
    int sign = 1;
    
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1:1;
        str++;
    }
    
    if (*str >= '0' && *str <= '9') {
        *arg = 0;
        while (*str >= '0' && *str <= '9') {
            *arg = (*arg * 10) + (*str - '0');
            str++;
        }
        *arg *= sign;
        return 1;
    }
    return 0;
}

static int str_to_uint(const char* str, unsigned int* arg) {
    while (*str && (*str == ' ' || *str == '\t')) {
        str++;
    }
    if (*str >= '0' && *str <= '9') {
        *arg = 0;
        while (*str >= '0' && *str <= '9') {
            *arg = (*arg * 10) + (*str - '0');
            str++;
        }
        return 1;
    }
    return 0;
}


int s21_sscanf(const char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int num_converted = 0;
    
    while (*format && *str) {
        if (*format != '%') {
            if (*format != *str) {
                va_end(args);
                return num_converted;
            } else {
                str++;
                format++;
            }
        } else {
            format++;
            switch (*format) {
                case 'd': {
                    int *value = va_arg(args, int*);
                    if (str_to_int(str, value)) {
                        num_converted++;
                        while (*str && ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')) {
                            str++;
                        }
                    } else {
                        va_end(args);
                        return num_converted;
                    }
                    break;
                }
                case 'f': {
                    float *value = va_arg(args, float*);
                    if (str_to_float(str, value)) {
                        num_converted++;
                        while (*str && ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+' || *str == '.')) {
                            str++;
                        }
                    } else {
                        va_end(args);
                        return num_converted;
                    }
                    break;
                }
                case 'c': {
                    char *value = va_arg(args, char*);
                    *value = *str;
                    num_converted++;
                    while (*str != ' ') {
                        str++;
                    }
                    break;
                }
                case 'i': {
                    unsigned int *value = va_arg(args, unsigned int*);
                        int sign = 1;

                        if (*str == '-') {
                            sign = -1;
                            str++;
                        }

                        if (str_to_uint(str, value)) {
                            *value *= sign;
                            num_converted++;
                            while (*str && ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')) {
                                str++;
                            }
                        } else {
                            va_end(args);
                            return num_converted;
                        }
                        break;
                }
                case 'e': {
                    DecimalFloatParam* value = va_arg(args, DecimalFloatParam*);
                    if (parse_decimal_float(str, value)) {
                        num_converted++;
                        while (*str && ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+' || *str == '.' || *str == 'e' || *str == 'E')) {
                            str++;
                        }
                        break;
                    } else {
                        va_end(args);
                        return num_converted;
                    }
                }
                default:
                    va_end(args);
                    return num_converted;
            }
            format++;
        }
    }
    va_end(args);
    if (*format != '\0') {
        return 0;
    }
    return num_converted;
}


int main(void) {
    DecimalFloatParam decimalFloatParam;
    const char* str = "30817264 22.22 Vasd 213 1.23e-3";
    int age = 0;
    float IQ = 0.0;
    char a;
    unsigned int i = 0;
    
    s21_sscanf(str, "%d %f %c %i %e", &age, &IQ, &a, &i, &decimalFloatParam);
    printf("%d\n", age);
    printf("%f\n", IQ);
    printf("%c\n", a);
    printf("%u\n", i);
    printf("%f\n", decimalFloatParam.mantissa);
    printf("%d\n", decimalFloatParam.exponent);

}
