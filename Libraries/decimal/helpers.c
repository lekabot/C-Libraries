#include "helpers.h"

/**
 * @brief Возвращает значение бита в заданной позиции.
 * 
 * Функция возвращает значение бита в заданной позиции у переданного числа.
 * 
 * @param number число.
 * @param position Позиция бита (от 0 до 31).
 * @return 1 или 0 в зависимости от значения бита
 */
int get_bit(int number, int position) {
    int mask = 1 << position;
    return (number & mask) >> position;
}

/**
 * @brief Устанавливает бит в 0 в числе.
 * 
 * Функция изменяет значение бита в переданом числе
 * 
 * @param number число.
 * @param position Позиция бита (от 0 до 31).
 */
int set_bit_to_zero(int* number, int position) {
    *number &= ~(1 << position);
}

/**
 * @brief Устанавливает бит в 1 в числе.
 * 
 * Функция изменяет значение бита в переданом числе
 * 
 * @param number число.
 * @param position Позиция бита (от 0 до 31).
 */
int set_bit_to_one(int* number, int position) {
   *number |= 1 << position;
}

/**
 * @brief Устанавливает бит в 0 по указанной позиции в s21_decimal.
 * 
 * Функция изменяет значение бита в s21_decimal на указанной позиции
 * в зависимости от переданного индекса.
 * 
 * @param decimal Структура s21_decimal.
 * @param position Позиция бита (от 0 до 31).
 * @param index Индекс для выбора части массива bits (0, 1 или 2).
 */
void set_bit_to_zero_in_decimal(s21_decimal* decimal, int position, int index) {
    if (index >= 0 && index < 3) {
        decimal->bits[index] &= ~(1 << position);
    }
}

/**
 * @brief Устанавливает бит в 1 по указанной позиции в s21_decimal.
 * 
 * Функция изменяет значение бита в s21_decimal на указанной позиции
 * в зависимости от переданного индекса.
 * 
 * @param decimal Структура s21_decimal.
 * @param position Позиция бита (от 0 до 31).
 * @param index Индекс для выбора части массива bits (0, 1 или 2).
 */
int set_bit_to_one_in_decimal(s21_decimal* decimal, int position, int index) {
       if (index >= 0 && index < 3) {
        decimal->bits[index] |= 1 << position;
    }
}

