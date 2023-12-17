#include "start_tests.h"

START_TEST(init_stack_test) {
    s21_stack_t s = stack_create();
    for (int i = 0; i < 5; i++) {
        push(&s, i);
    }
    ck_assert_ptr_nonnull(s.value);
    ck_assert_int_eq(s.length, 5);
    stack_free(&s);
}   
END_TEST

START_TEST(push_stack_test) {
    s21_stack_t s = stack_create();
    push(&s, 5.412);
    push(&s, 2.1412412);
    ck_assert_ptr_nonnull(s.value);
    ck_assert_int_eq(s.length, 2);
    ck_assert_double_eq(pop(&s), 2.1412412);
    ck_assert_double_eq(pop(&s), 5.412);
    stack_free(&s);
}   
END_TEST

START_TEST(pop_stack_test_1) {
    s21_stack_t s = stack_create();
    push(&s, 11251251);
    push(&s, 151251.125125);
    ck_assert_ptr_nonnull(s.value);
    ck_assert_int_eq(s.length, 2);
    ck_assert_double_eq(pop(&s), 151251.125125);
    ck_assert_double_eq(pop(&s), 11251251);
    stack_free(&s);
}   
END_TEST

START_TEST(pop_stack_test_2) {
    s21_stack_t s = stack_create();
    ck_assert_double_eq(pop(&s), INT_MIN);
    stack_free(&s);
}   
END_TEST

START_TEST(stack_free_test) {
    s21_stack_t s = stack_create();
    push(&s, 11251251);
    push(&s, 151251.125125);
    ck_assert_ptr_nonnull(s.value);
    ck_assert_int_eq(s.length, 2);
    ck_assert_double_eq(pop(&s), 151251.125125);
    ck_assert_double_eq(pop(&s), 11251251);
    stack_free(&s);
    ck_assert_ptr_null(s.value);
}   
END_TEST

Suite *stack_suite(void) {
    Suite *s = suite_create("Stack check");
    TCase *tc = tcase_create("Stack check");

    tcase_add_test(tc, init_stack_test);
    tcase_add_test(tc, push_stack_test);
    tcase_add_test(tc, pop_stack_test_1);
    tcase_add_test(tc, pop_stack_test_2);
    tcase_add_test(tc, stack_free_test);

    suite_add_tcase(s, tc);
    return s;
}