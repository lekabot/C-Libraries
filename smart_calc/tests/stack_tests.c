#include "start_tests.h"

START_TEST(init_stack_test) {
    s21_stack_t *exempl = init_stack('a');
    ck_assert_ptr_nonnull(exempl);
    destroy_stack(exempl);
}
END_TEST

START_TEST(push_test_1) {
    s21_stack_t *empty_stack = NULL;
    s21_stack_t *result_empty = push(empty_stack, 'a');
    ck_assert_int_eq(result_empty->op, 'a');
    ck_assert_ptr_eq(result_empty->prev, NULL);
    destroy_stack(result_empty);
}
END_TEST

START_TEST(push_test_2) {
    s21_stack_t *non_empty_stack = init_stack('a');
    non_empty_stack = push(non_empty_stack, 'b');

    s21_stack_t *result = push(non_empty_stack, 'c');

    ck_assert_int_eq(result->op, 'c');
    ck_assert_int_eq(result->prev->op, 'b');
    ck_assert_int_eq(result->prev->prev->op, 'a');
    ck_assert_ptr_eq(result->prev->prev->prev, NULL);
    
    destroy_stack(result);
}
END_TEST

START_TEST(pop_test_1) {
    s21_stack_t *empty_stack = NULL;
    s21_stack_t *res_stack = pop(empty_stack);
    ck_assert_ptr_null(res_stack);
}
END_TEST

START_TEST(pop_test_2) {
    s21_stack_t *non_empty_stack = init_stack('a');
    non_empty_stack = push(non_empty_stack, 'b');
    non_empty_stack = push(non_empty_stack, 'c');
    s21_stack_t *res_stack = pop(non_empty_stack);

    ck_assert_int_eq(res_stack->op, 'b');
    ck_assert_int_eq(res_stack->prev->op, 'a');
    destroy_stack(res_stack);
}
END_TEST

Suite *stack_suite(void) {
    Suite *s = suite_create("Stack check");
    TCase *tc = tcase_create("Stack check");
    tcase_add_test(tc, init_stack_test);
    tcase_add_test(tc, push_test_1);
    tcase_add_test(tc, push_test_2);
    tcase_add_test(tc, pop_test_1);
    tcase_add_test(tc, pop_test_2);
    suite_add_tcase(s, tc);
    return s;
}