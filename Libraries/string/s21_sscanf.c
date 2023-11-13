#include "s21_string.h"

static int str_to_float(const char* str, float* arg);
static int parse_decimal_float(const char* str, void* arg);

static int parse_decimal_float(const char* str, void* arg) {
   float* result = (float*)arg;
   while (*str && (*str == ' ' || *str == '\t')) {
       str++;
   }
   int sign = 1;
   
   if (*str == '-' || *str == '+') {
       sign = (*str == '-') ? -1:1;
       str++;
   }
   if (*str >= '0' && *str <= '9') {
       float mantissa = 0.0f;
       while (*str >= '0' && *str <= '9') {
           mantissa = (mantissa * 10.0f) + (*str - '0');
           str++;
       }
       
       if (*str == '.') {
           str++;
           float divisor = 10.0f;
           while (*str >= '0' && *str <= '9') {
               mantissa += (*str - '0') / divisor;
               divisor *= 10.0f;
               str++;
           }
       }
       
       mantissa *= sign;
       if (*str == 'e' || *str == 'E') {
           str++;
           int e_sign = 1;
           if (*str == '-' || *str == '+') {
               e_sign = (*str == '-') ? -1:1;
               str++;
           }
           int e_value = 0;
           while (*str >= '0' && *str <= '9') {
               e_value = (e_value * 10) + (*str - '0');
               str++;
           }
           *result = mantissa * powf(10.0f, e_value * e_sign);
       } else {
           *result = mantissa;
       }
       return 1;
   }
   return 0;
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

//static int str_to_uint(const char* str, unsigned int* arg) {
//    while (*str && (*str == ' ' || *str == '\t')) {
//        str++;
//    }
//    if (*str >= '0' && *str <= '9') {
//        *arg = 0;
//        while (*str >= '0' && *str <= '9') {
//            *arg = (*arg * 10) + (*str - '0');
//            str++;
//        }
//        return 1;
//    }
//    return 0;
//}


static int str_to_int_deff_notation(const char* str, int* arg) {
   while (*str && (*str == ' ' || *str == '\t')) {
       str++;
   }
   
   int sign = 1;
   
   if (*str == '-' || *str == '+') {
       sign = (*str == '-') ? -1:1;
       str++;
   }
   
   int base = 10;

   if (*str == '0') {
       str++;
       if (*str == 'x') {
           base = 16;
           str++;
       } else {
           base = 8;
       }
   }

   if ((base == 8 && (*str >= '0' && *str <= '7')) || (base == 10 && (*str >= '0' && *str <= '9')) || ((base == 16) && ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F')))) {
       *arg = 0;
       while (*str) {
           char digit = *str;
           int value = 0;
           if (digit >= '0' && digit <= '9') {
               value = digit - '0';
           } else if (digit >= 'a' && digit <= 'f') {
               value = 10 + (digit - 'a');
           } else if (digit >= 'A' && digit <= 'F') {
               value = 10 + (digit - 'A');
           } else {
               break;
           }
           *arg = (*arg * base) + value;
           str++;
       }
       *arg *= sign;
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
           if (*format == '.') {
               format++;
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
                       int *value = va_arg(args, int*);
                       int sign = 1;
                       
                       if (*str == '-') {
                           sign = -1;
                           str++;
                       }
                       else if (*str == '+') {
                           str++;
                       }
                       
                       if (str_to_int_deff_notation(str, value)) {
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
                   case 'e':
                   case 'E': {
                       float* value = va_arg(args, float*);
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
                   case 'G':
                   case 'g': {
                       float* value = va_arg(args, float*);
                       if (str_to_float(str, value)) {
                           if (*value <= 1e-4 || *value >= 1e+6) {
                               *value = round(*value);
                           } else {
                               if (parse_decimal_float(str, value)) {
                                   while (*str && ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+' || *str == '.' || *str == 'e' || *str == 'E')) {
                                       str++;
                                   }
                               } else {
                                   va_end(args);
                                   return num_converted;
                               }
                           }
                           num_converted++;
                           break;
                       }
                   }
                   case 'o':
                       break;
                   default:
                       va_end(args);
                       return num_converted;
               }
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


//int main(void) {
//    const char* str = "30817264 22.22 V 012 12345.6789 123456789012345678901234567890.1234567890, 100";
//    int check_d = 0;
//    float check_f = 0.0;
//    char check_c = '0';
//    int check_i = 0;
//    float check_e = 0.0;
//    float check_g = 0.0;
//    int check_o = 0;
////    const char* str1 = "0x1A";
////    const char* str2 = "012";
////    const char* str3 = "42";
//    
//    sscanf(str, "%d %f %c %i %E %G %o", &check_d, &check_f, &check_c, &check_i, &check_e, &check_g, &check_o);
//    printf("%d\n", check_d);
//    printf("%f\n", check_f);
//    printf("%c\n", check_c);
//    printf("%d\n", check_i);
//    printf("%E\n", check_e);
//    printf("%G\n", check_g);
//    printf("%d\n", check_o);
//}
