#ifndef SMART_CALC_START_TESTS_C_H
#define SMART_CALC_START_TESTS_C_H

#include <check.h>
#include "../stack.h"

Suite *stack_suite(void);

void run_tests(void);
void run_testcase(Suite* testcase);

#endif //SMART_CALC_START_TESTS_C_H
