#include "stack.h"

s21_stack_t stack_create(){
  s21_stack_t s = {
    .value = NULL,
    .length = 0,
    .capacity = 0
  };
  return s;
}

void push(s21_stack_t *s, double value) {
  if (s->value == NULL || s->length == s->capacity) {
    s->capacity = (s->capacity + 1) * 2;
    s->value = (double*)realloc(s->value, sizeof(double) * s->capacity);
  }
  s->value[s->length] = value;
  s->length += 1;
}

double pop(s21_stack_t *s) {
  if (s->length == 0) {
    return INT_MIN;
  }
  s->length -= 1;
  return s->value[s->length];
}

void stack_free(s21_stack_t *s) {
  if (s->value != NULL) {
    free(s->value);
    s->value = NULL;
  }
  s->length = 0;
  s->capacity = 0;
}
