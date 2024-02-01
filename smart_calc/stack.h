#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <string.h>
#include <stdlib.h>

typedef struct stack {
  char op;
  double value;
  struct stack *prev;
} s21_stack_t;

/**
 * @brief Инициализация стэка, выделение памяти.
 * @param op - символ
 * @return Возвращает указатель на первый элемент стэка
 */
s21_stack_t *init_stack(char op);

/**
 * @brief добавляем элемент в стэк
 * переменная a возвpащает указатель на последний элемент стека
 * @param head - стек
 * @param op - символ
 * @return Возвращает указатель на добавленный элемент стэка
 */
s21_stack_t *push(s21_stack_t *head, char op);

/**
 * @brief Удаляет последний символ стека.
 * Возвpащает удаляемый символ.
 * Изменяет указатель на веpшину стека
 * @param head - стек
 * @param a - символ с веpшины стека
 * @return Возвращает указатель на предыдущий элемент в стэке
 */
s21_stack_t *pop(s21_stack_t *head);

/**
 * @brief Удаляет стэк. Чистит память.
 * @param head - стек
 * @param a - символ с веpшины стека
 */
void destroy_stack(s21_stack_t *root);

#endif  // SRC_STACK_H_
