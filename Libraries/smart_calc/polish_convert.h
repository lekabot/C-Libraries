#ifndef POLISH_CONVERT_H
#define POLISH_CONVERT_H
#define STACK_MAX_SIZE 300
#define MAX_INFIX_LENGTH 300

// Error defined
#define SUF -2   // недостаточно операндов в стеке
#define NCLB -4  // нет закр скобки

#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void convert_to_polish_natation(char* index, char* polish_natation);
int is_operator(char c);
char get_opt_name(char *lexeme);
int get_opt_priority(char opt);
double calculate_answer(char *polish_natation, double x, int *error);

#ifdef __cplusplus
}
#endif

#endif // POLISH_CONVERT_H
