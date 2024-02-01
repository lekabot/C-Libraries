#ifndef SMART_CALC_START_TESTS_C_H
#define SMART_CALC_START_TESTS_C_H

#include <check.h>
#include <stdio.h>
#include "../stack.h"
#include "../polish_convert.h"

#define ESP 1e-7

Suite *stack_suite(void);
Suite *polish_suite(void);

void run_tests(void);
void run_testcase(Suite* testcase);

#endif //SMART_CALC_START_TESTS_C_H
