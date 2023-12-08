#include "stack.h"

stack *init_stack(char op) {
    stack *first;
    first = (stack*)malloc(sizeof(stack));
    first->op = op;
    first->prev = NULL;
    return first;
}

stack *push(struct stack *head, char op) {
    int flag = 0;
    struct stack *temp = NULL;
    if (head == NULL) {
        flag = 1;
    } else {
        temp = (struct stack *)malloc(sizeof(struct stack));
        temp->prev = head;
        temp->op = op;
    }
    return flag ? init_stack(op) : temp;
}

stack *pop(struct stack *head) {
    int flag = 0;
    struct stack *temp;
    if (head == NULL) {
        flag = 1;
    } else {
        temp = head->prev;
        free(head);
    }
    return flag ? NULL : temp;
}

void remove_stack(stack *head) {
    if (head != NULL) {
    stack *curr, *prev;
    curr = head;
    do {
        prev = curr->prev;
        free(curr);
        curr = prev;
        } while (curr != NULL);
    }
}
