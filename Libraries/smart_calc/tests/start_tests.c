#include "start_tests.h"

void run_tests(void) {
    Suite *list_cases[] = {
        stack_suite(), polish_suite(),
             NULL
    };
    for (Suite **current_testcase = list_cases; *current_testcase != NULL; current_testcase++) {
        run_testcase(*current_testcase);
    }
}

void run_testcase(Suite* testcase) {
    static int counter_testcase = 0;
    if (counter_testcase > 0) putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;
    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}

int main(void) {
    run_tests();
    return 0;
}