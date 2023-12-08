#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct stack {
    char op;
    double value;
    struct stack *prev;
};

stack *init_stack(char op);

//Возвращает указатель на добавленный элемент стэка
stack *push(stack *head, char op);

//Возвращает указатель на предыдущий элемент в стэке
stack *pop(stack *head);

//Удаляет стэк
void remove_stack(stack *head);

#endif // STACK_H
