#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#define STACK_MAX_SIZE 500

typedef struct {
  double *value;
  int length;
  int capacity;
} s21_stack_t;

s21_stack_t stack_create();
void push(s21_stack_t *s, double value);
double pop(s21_stack_t *s);
void stack_free(s21_stack_t *s);

#endif // STACK_H
