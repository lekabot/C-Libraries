//#ifndef s21_decimal_h
//#define s21_decimal_h
//
//#include <stdio.h>
//
//typedef struct
//{
//    unsigned int bits[4];
//} s21_decimal;
//
//int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // +
//int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // -
//int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // *
//int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // /
////The functions return the error code:
////
////0 - OK
////1 - the number is too large or equal to infinity
////2 - the number is too small or equal to negative infinity
////3 - division by 0
////Note on the numbers that do not fit into the mantissa:
////
////When getting numbers that do not fit into the mantissa during arithmetic operations, use bank rounding (for example, 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)
//int s21_is_less(s21_decimal, s21_decimal); // <
//int s21_is_less_or_equal(s21_decimal, s21_decimal); // <=
//int s21_is_greater(s21_decimal, s21_decimal); // >
//int s21_is_greater_or_equal(s21_decimal, s21_decimal); // >=
//int s21_is_equal(s21_decimal, s21_decimal); // ==
//int s21_is_not_equal(s21_decimal, s21_decimal); // !=
////Return value:
////
////0 - FALSE
////1 - TRUE
//int s21_from_int_to_decimal(int src, s21_decimal *dst);
//int s21_from_float_to_decimal(float src, s21_decimal *dst);
//int s21_from_decimal_to_int(s21_decimal src, int *dst);
//int s21_from_decimal_to_float(s21_decimal src, float *dst);
////Return value - code error:
////
////0 - OK
////1 - convertation error
////Note on the conversion of a float type number:
////
////If the numbers are too small (0 < |x| < 1e-28), return an error and value equal to 0
////If the numbers are too large (|x| > 79,228,162,514,264,337,593,543,950,335) or are equal to infinity, return an error
////When processing a number with the float type, convert all the significant decimal digits contained in it. If there are more than 7 such digits, the number is rounded to the closest one that does not have more than 7 significant decimal digits.
////Note on the conversion from decimal type to int:
////
////If there is a fractional part in a decimal number, it should be discarded (for example, 0.9 is converted to 0)
//int s21_floor(s21_decimal value, s21_decimal *result);
//int s21_round(s21_decimal value, s21_decimal *result);
//int s21_truncate(s21_decimal value, s21_decimal *result);
//int s21_negate(s21_decimal value, s21_decimal *result);
////Return value - code error:
////
////0 - OK
////1 - calculation error
//
//#endif /* s21_decimal_h */
